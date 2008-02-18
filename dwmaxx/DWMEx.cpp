// DWMEx.cpp : Implementation of CDWMEx

#include "stdafx.h"
#include "DWMEx.h"
#include <conio.h>
#include <vector>
#include <time.h>
#include "CVisual.h"
#include "CWindowData.h"
#include "udwm.h"
#include "CSecondaryWindowRepresentation.h"
#include <d3d9.h>
#include <d3dx9.h>


#define MEMBER_OFFSET(member, object)	(((unsigned int)&(member)) - ((unsigned int)object))

// CDWMEx

STDMETHODIMP CDWMEx::OpenConsole(void)
{
	return (AllocConsole() == TRUE ? S_OK : E_FAIL);
}

STDMETHODIMP CDWMEx::CloseConsole(void)
{
	return (FreeConsole() == TRUE ? S_OK : E_FAIL);
}

STDMETHODIMP CDWMEx::SetWindowScale(LONG hWnd, FLOAT ScaleX, FLOAT ScaleY)
{
	EnterCriticalSection(GetDWMCriticalSection());

	CWindowData	*pWindowData = LookupWindow((HWND)hWnd);

	if (pWindowData != NULL)
	{
		CTopLevelWindow *window = pWindowData->TopLevelWindow;

		window->AddRef();
		window->SetScale(ScaleX, ScaleY);
		window->Relase();
	}

	LeaveCriticalSection(GetDWMCriticalSection());

	return S_OK;
}

STDMETHODIMP CDWMEx::SetWindowOffset(LONG hWnd, FLOAT X, FLOAT Y)
{
	EnterCriticalSection(GetDWMCriticalSection());

	CWindowData	*pWindowData = LookupWindow((HWND)hWnd);
	if (pWindowData != NULL)
	{
		CTopLevelWindow *window = pWindowData->TopLevelWindow;

		window->AddRef();
		window->MILSetOffset((double)X, (double)Y);
		window->Relase();
	}

	LeaveCriticalSection(GetDWMCriticalSection());

	return S_OK;
}

STDMETHODIMP CDWMEx::ExecuteBatch(LONG batchId)
{
	EnterCriticalSection(GetDWMCriticalSection());

	LeaveCriticalSection(GetDWMCriticalSection());

	return S_OK;
}

STDMETHODIMP CDWMEx::BatchSetWindowMatrix(LONG hWnd, FLOAT X, FLOAT Y, FLOAT SX, FLOAT SY, FLOAT RZ)
{
	t_Command newCommand;

	newCommand.hWnd = hWnd;
	newCommand.X = X;
	newCommand.Y = Y;
	newCommand.SX = SX;
	newCommand.SY = SY;
	newCommand.RZ = RZ;

	_commands.push_back(newCommand);

	return S_OK;
}

STDMETHODIMP CDWMEx::GetRenderOptions(LONG hWnd, LONG* Options)
{
	HRESULT	ret = E_INVALIDARG;
	EnterCriticalSection(GetDWMCriticalSection());

	CWindowData	*pWindowData = LookupWindow((HWND)hWnd);
	if (pWindowData != NULL)
		ret = S_OK;
	else
		ret = E_FAIL;

	LeaveCriticalSection(GetDWMCriticalSection());

	return ret;
}

STDMETHODIMP CDWMEx::SetRenderOptions(LONG hWnd, LONG Options)
{
	TCHAR	buf[512];
	EnterCriticalSection(GetDWMCriticalSection());

	CWindowData	*pWindowData = LookupWindow((HWND)hWnd);
	if (pWindowData != NULL)
	{
		CTopLevelWindow *window = pWindowData->TopLevelWindow;

		window->AddRef();
		window->RenderFlags = Options;
		window->UpdateRenderOptions();
		window->Relase();
	}

	LeaveCriticalSection(GetDWMCriticalSection());

	return S_OK;
}

STDMETHODIMP CDWMEx::SetWindowMatrix(LONG hWnd, FLOAT X, FLOAT Y, FLOAT SX, FLOAT SY, FLOAT RZ)
{
	EnterCriticalSection(GetDWMCriticalSection());

	CWindowData	*pWindowData = LookupWindow((HWND)hWnd);
	if (pWindowData != NULL)
	{
		CTopLevelWindow *window = pWindowData->TopLevelWindow;
		window->AddRef();
		window->MILSetTransform(X, Y, SX, SY, RZ);
		window->Relase();
	}
	else
	{
		LeaveCriticalSection(GetDWMCriticalSection());
		return (E_FAIL);
	}

	LeaveCriticalSection(GetDWMCriticalSection());

	return S_OK;
}

STDMETHODIMP CDWMEx::LockRendering(void)
{
	EnterCriticalSection(GetDWMCriticalSection());

	return S_OK;
}

STDMETHODIMP CDWMEx::UnlockRendering(void)
{
	LeaveCriticalSection(GetDWMCriticalSection());

	return S_OK;
}

STDMETHODIMP CDWMEx::Test(LONG hWnd)
{
	TCHAR	buf[512];
	EnterCriticalSection(GetDWMCriticalSection());

	CWindowData	*pWindowData = LookupWindow((HWND)hWnd);
	if (pWindowData != NULL)
	{
		CTopLevelWindow *window = pWindowData->TopLevelWindow;
		CTopLevelWindow3D *window3D = pWindowData->TopLevelWindow3D;
		window->AddRef();
		window3D->AddRef();

		wsprintf(buf, _T("AT LINE: %u"), __LINE__);
		OutputDebugString(buf);

		//window->ShowWindow(false);

		wsprintf(buf, _T("AT LINE: %u"), __LINE__);
		OutputDebugString(buf);

		OutputDebugString(_T("<BEFORE>"));
		wsprintf(buf, _T("window3D->SecondaryWindowRepresentation = 0x%X"), window3D->SecondaryWindowRepresentation);
		OutputDebugString(buf);
		wsprintf(buf, _T("window3D->CameraResource = 0x%X"), window3D->CameraResource);
		OutputDebugString(buf);
		OutputDebugString(_T("</BEFORE>"));


		CSecondaryWindowRepresentation::Create(0xB8, window3D, pWindowData, &(window3D->SecondaryWindowRepresentation));


		OutputDebugString(_T("<AFTER>"));
		window3D->UpdateCameraResource(window3D->Resource->MilChannel); // create camera
		wsprintf(buf, _T("window3D->SecondaryWindowRepresentation = 0x%X"), window3D->SecondaryWindowRepresentation);
		OutputDebugString(buf);
		wsprintf(buf, _T("window3D->CameraResource = 0x%X"), window3D->CameraResource);
		OutputDebugString(buf);
		OutputDebugString(_T("</AFTER>"));

		window3D->UpdateScene3DResource(window3D->Resource->MilChannel);
		window3D->UpdateAnimatedResources();

		//CResource	*sceneResource = NULL;
		//CResource::Create(TYPE_SCENE3D, window3D->Resource->MilChannel, &(window3D->Scene3DResource));

		wsprintf(buf, _T("window3D->Scene3DResource = 0x%X"), window3D->Scene3DResource);
		OutputDebugString(buf);

		//CResource	*windowModel = NULL;
		//window3D->SecondaryWindowRepresentation->GetModel3D(&windowModel);

		//wsprintf(buf, _T("windowModel = 0x%X"), windowModel);
		//OutputDebugString(buf);

		//MILCMD_SCENE3D	sceneCommand;
		//sceneCommand.Type = MilCmdScene3D;
		//sceneCommand.ViewportRectangle.X = 200.0;
		//sceneCommand.ViewportRectangle.Y = 200.0;
		//sceneCommand.ViewportRectangle.Width = 200.0;
		//sceneCommand.ViewportRectangle.Height = 200.0;
		//sceneCommand.Handle = window3D->Scene3DResource->ResourceHandle;
		//sceneCommand.hModels = windowModel->ResourceHandle;
		//sceneCommand.hCamera = window3D->CameraResource->ResourceHandle;
		//sceneCommand.hViewportAnimations = NULL;
		//window3D->Scene3DResource->Send(&sceneCommand, sizeof(MILCMD_SCENE3D));
	
		window3D->SecondaryWindowRepresentation->SetOpacity(1.0);

		D3DXMATRIX	idMatrix;
		D3DXMatrixIdentity(&idMatrix);
		D3DXMatrixTranslation(&idMatrix, 0.0f, 0.0f, 2.0f);
		window3D->SecondaryWindowRepresentation->SetTransform3D(&idMatrix);

		window3D->OnZOrderUpdated(false);
		window3D->SetDirtyFlags(IsConnectedToParent);

		window3D->Relase();
		window->Relase();
	}

	LeaveCriticalSection(GetDWMCriticalSection());

	return S_OK;
}
