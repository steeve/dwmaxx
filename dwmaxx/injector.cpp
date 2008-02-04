#include "stdafx.h"
#include "injector.h"
#include "dwmaxx.h"
#include <tlhelp32.h>
#include <conio.h>
#include "uDWM.h"
#include "patch.h"

#pragma warning( push )
#pragma warning( disable : 4311 4312 )

HMODULE	RemoteGetModuleHandle(DWORD dwPID, LPCTSTR szDllName)
{
	HANDLE hModuleSnap = INVALID_HANDLE_VALUE;
	MODULEENTRY32 me32;

	// Take a snapshot of all modules in the specified process.
	hModuleSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, dwPID);
	if (hModuleSnap == INVALID_HANDLE_VALUE)
		return (NULL);

	// Set the size of the structure before using it.
	me32.dwSize = sizeof(MODULEENTRY32);

	// Retrieve information about the first module,
	// and exit if unsuccessful
	if (Module32First(hModuleSnap, &me32) == FALSE)
	{
		CloseHandle(hModuleSnap);           // clean the snapshot object
		return (NULL);
	}

	// Now walk the module list of the process,
	// and display information about each module
	do
	{
		if (_tcscmp(szDllName, me32.szExePath) == 0)
			return ((HMODULE)me32.modBaseAddr);
	} while (Module32Next(hModuleSnap, &me32) == TRUE);

	CloseHandle(hModuleSnap);

	return (NULL);
}

bool	DWMaxxIsRunningInsideDWM()
{
	return (GetModuleHandle(_T("notepad.exe")) != NULL);
}

bool	DWMaxxIsInjected()
{
	DWORD	dwmPid = NULL;
	HWND	hDwmWindow = NULL;
	TCHAR	modulePath[512];

	if (GetModuleFileName(GetModuleHandle(_T(DLL_NAME)), modulePath, sizeof(modulePath)) == 0)
		return (false);

	if ((hDwmWindow = FindWindow(_T(DWM_CLASS_NAME), NULL)) == NULL)
		return (false);

	if (GetWindowThreadProcessId(hDwmWindow, &dwmPid) == 0)
		return (false);

	return (RemoteGetModuleHandle(dwmPid, modulePath) != NULL);
}

bool	DWMaxxInject()
{
	DWORD	dwmPid = NULL;
	HWND	hDwmWindow = NULL;
	HANDLE	hDwmProcess = NULL;
	TCHAR	modulePath[512];
	bool	result = false;
	IDWMEx	*retObject = NULL;

	if (GetModuleFileName(GetModuleHandle(_T(DLL_NAME)), modulePath, sizeof(modulePath)) == 0)
		return (false);

	int		dllNameSizeInBytes = (_tcslen(modulePath) + 1) * sizeof(TCHAR);
	void	*LoadLibraryAddress = (void *)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), LOAD_LIBRARY_EXPORT);
	if (LoadLibraryAddress == NULL)
		return (false);

	if ((hDwmWindow = FindWindow(_T(DWM_CLASS_NAME), NULL)) == NULL)
		return (false);

	if (GetWindowThreadProcessId(hDwmWindow, &dwmPid) == 0)
		return (false);

	if ((hDwmProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwmPid)) == NULL)
		return (false);

	TCHAR	*remoteDllName = (TCHAR *)VirtualAllocEx(hDwmProcess, NULL, dllNameSizeInBytes, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
	if (remoteDllName == NULL)
	{
		CloseHandle(hDwmProcess);
		return (false);
	}

	if (WriteProcessMemory(hDwmProcess, (LPVOID)remoteDllName, (LPCVOID)modulePath, dllNameSizeInBytes, NULL) == TRUE)
	{
		HANDLE	remoteThreadHandle = CreateRemoteThread(hDwmProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)LoadLibraryAddress, (LPVOID)remoteDllName, NULL, NULL);
		if (remoteThreadHandle != NULL)
		{
			WaitForSingleObject(remoteThreadHandle, INFINITE);
			result = true;
		}
	}

	VirtualFreeEx(hDwmProcess, remoteDllName, dllNameSizeInBytes, MEM_DECOMMIT);

	CoInitialize(NULL);

	HMODULE hRemoteModule = RemoteGetModuleHandle(dwmPid, modulePath);

	void	*remoteDWMaxxStart = (void *)((DWORD)hRemoteModule + ((DWORD)DWMaxxStart - (DWORD)GetModuleHandle(_T(DLL_NAME))));
	HANDLE	remoteThreadHandle = CreateRemoteThread(hDwmProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)remoteDWMaxxStart, NULL, NULL, NULL);
	if (remoteThreadHandle != NULL)
	{
		WaitForSingleObject(remoteThreadHandle, INFINITE);
		result = true;
	}

	CloseHandle(hDwmProcess);

	return (result);
}

bool	DWMaxxUnload()
{
	DWORD	dwmPid = NULL;
	HWND	hDwmWindow = NULL;
	TCHAR	modulePath[512];
	HANDLE	hDwmProcess = NULL;
	HMODULE	hRemoteModule = NULL;

	if (GetModuleFileName(GetModuleHandle(_T(DLL_NAME)), modulePath, sizeof(modulePath)) == 0)
		return (false);

	if ((hDwmWindow = FindWindow(_T(DWM_CLASS_NAME), NULL)) == NULL)
		return (false);

	if (GetWindowThreadProcessId(hDwmWindow, &dwmPid) == 0)
		return (false);

	hRemoteModule = RemoteGetModuleHandle(dwmPid, modulePath);

	void	*FreeLibraryAddress = (void *)GetProcAddress(GetModuleHandle(_T("kernel32.dll")), FREE_LIBRARY_EXPORT);
	if (FreeLibraryAddress == NULL)
		return (false);

	if ((hDwmProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwmPid)) == NULL)
		return (false);

	DWORD	threadRetValue = FALSE;
	do
	{
		HANDLE	remoteThreadHandle = CreateRemoteThread(hDwmProcess, NULL, NULL, (LPTHREAD_START_ROUTINE)FreeLibraryAddress, (LPVOID)hRemoteModule, NULL, NULL);
		if (remoteThreadHandle != NULL)
			WaitForSingleObject(remoteThreadHandle, INFINITE);
		GetExitCodeThread(remoteThreadHandle, &threadRetValue);
	} while (threadRetValue == TRUE);

	CloseHandle(hDwmProcess);

	return (RemoteGetModuleHandle(dwmPid, modulePath) == NULL);
}

CComPtr<IDWMEx> DWMaxxGetObject()
{
	CComPtr<IUnknown>	unknownObject;
	HRESULT hRes = GetActiveObject(CLSID_DWMEx, NULL, &unknownObject);
	return (CComQIPtr<IDWMEx>(unknownObject));
}


HANDLE	g_hObjectCreatedEvent = NULL;

void __declspec(naked) CDesktopManager_HandleThreadMessage_Hook(unsigned int, unsigned int, long)
{
	__asm
	{
		pushad
	}

	{
		IDWMEx	*newObj = NULL;
		DWORD	handle = NULL;
		HRESULT	hRes = S_OK;

		CoInitialize(NULL);
		hRes = CoCreateInstance(CLSID_DWMEx, NULL, CLSCTX_ALL, IID_IDWMEx, (LPVOID *)&newObj);
		hRes = RegisterActiveObject(newObj, CLSID_DWMEx, ACTIVEOBJECT_STRONG, &handle);
	}

	SetEvent(g_hObjectCreatedEvent);
	SuspendThread(GetCurrentThread());

	__asm
	{
		popad
		retn
	}
}

void	DWMaxxStart()
{
	HANDLE	hUDWM = GetModuleHandle(_T("udwm.dll"));
	CDesktopManager	*pdm = *(CDesktopManager **)PE_RvaToVa(hUDWM, rva_CDesktopManager__s_pDesktopManagerInstance);

	g_hObjectCreatedEvent = CreateEvent(NULL, FALSE, FALSE, NULL);

	SuspendThread(pdm->hMessageLoopThread);
	void *oldProcAddr = HookSub(PE_RvaToVa(hUDWM, rva_CDesktopManager_HandleThreadMessage), CDesktopManager_HandleThreadMessage_Hook);
	ResumeThread(pdm->hMessageLoopThread);

	PostThreadMessage(GetThreadId(pdm->hMessageLoopThread), WM_NULL, 0, 0);
	WaitForSingleObject(g_hObjectCreatedEvent, INFINITE);
	CloseHandle(g_hObjectCreatedEvent);

	UnHookSub(PE_RvaToVa(hUDWM, rva_CDesktopManager_HandleThreadMessage));
	ResumeThread(pdm->hMessageLoopThread);
}

#pragma warning( pop )
