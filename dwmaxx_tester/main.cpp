#include <windows.h>
#include <tchar.h>
#include <tlhelp32.h>
#include <stdio.h>

#include <atlbase.h>
#include <atlcom.h>

using namespace ATL;

#include "..\\dwmaxx\\dwmaxx.h"
//#include "C:\\Program Files\\Microsoft SDKs\\Windows\\v6.0A\\Include\\dwmapi.h"
//
//#pragma comment (lib, "C:\\Program Files\\Microsoft SDKs\\Windows\\v6.0A\\Lib\\dwmapi.lib")


#pragma comment (lib, "..\\dwmaxx\\Debug\\dwmaxx.lib")

//typedef IDWMEx*	(*INJECTPROC)();

//#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
//        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}
//
//MIDL_DEFINE_GUID(IID, IID_IDWMEx,0x9C797EE5,0x8465,0x4980,0xB0,0x28,0x42,0x44,0xCB,0x77,0x40,0xB2);
//MIDL_DEFINE_GUID(IID, LIBID_dwmaxxLib,0xC42006C4,0x4EAF,0x402F,0x89,0xC6,0x09,0xD1,0x67,0xE7,0x5A,0xEC);
//MIDL_DEFINE_GUID(CLSID, CLSID_DWMEx,0x3B83AC72,0xFD69,0x456A,0xAF,0x52,0xD0,0x9F,0xA1,0x58,0xBF,0xFD);

int		main(int argc, char **argv)
{
	//HWND	hNotepad = FindWindow(_T("MediaPlayerClassicW"), NULL);
	HWND	hNotepad = FindWindow(_T("Notepad"), NULL);

	CoInitialize(NULL);

	CComPtr<IDWMInjector>	injector;

	injector.CoCreateInstance(CLSID_DWMInjector);

	VARIANT_BOOL	injected;
	injector->get_IsInjected(&injected);
	if (injected == VARIANT_FALSE)
	{
		injector->Inject();
	}

	LONG	opts = 0;

	opts = 1;


	IDWMEx	*dwmObject = NULL;
	injector->GetDWMExObject(&dwmObject);

	dwmObject->OpenConsole();
	dwmObject->Test((LONG)hNotepad);
	

	//DWM_PRESENT_PARAMETERS params;
	//params.cbSize = sizeof(params);
	//params.fQueue = TRUE;
	//params.cBuffer = 2;
	//params.fUseSourceRate = TRUE;

	//UNSIGNED_RATIO	p;
	//p.uiNumerator = 50;
	//p.uiDenominator = 1;

	//params.rateSource = p;
	//params.eSampling = DWM_SOURCE_FRAME_SAMPLING_POINT;
	//HRESULT hRes = DwmSetDxFrameDuration(hNotepad, 1);

	//float Angle = 0.0f;
 //	while (true)
	//{
	//	HRESULT res = dwmObject->SetWindowMatrix((LONG)hNotepad, 100.0f, 100.0f, 1.0f, 1.0f, Angle * 3.1416 / 180.0f);
	//	DwmFlush();
	//	Angle += 0.1f;
	//	
	//	if (res == E_FAIL)
	//	{
	//		printf("pouet!\n");
	//	}
	//	Sleep(10);
	//}

	return (0);
}