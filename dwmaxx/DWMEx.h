// DWMEx.h : Declaration of the CDWMEx

#pragma once
#include "resource.h"       // main symbols

#include "dwmaxx.h"
#include <vector>


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif

enum
{
	CMD_OFFSET,
	CMD_SCALE,
};

typedef struct
{
	LONG	hWnd;
	FLOAT	X;
	FLOAT	Y;
	FLOAT	SX;
	FLOAT	SY;
	FLOAT	RZ;
} t_Command;

// CDWMEx

class ATL_NO_VTABLE CDWMEx :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDWMEx, &CLSID_DWMEx>,
	public IDispatchImpl<IDWMEx, &IID_IDWMEx, &LIBID_dwmaxxLib, /*wMajor =*/ 1, /*wMinor =*/ 0>
{
public:
	CDWMEx()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DWMEX)


BEGIN_COM_MAP(CDWMEx)
	COM_INTERFACE_ENTRY(IDWMEx)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()



	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct()
	{
		return S_OK;
	}

	void FinalRelease()
	{
	}

	std::vector<t_Command>	_commands;

public:

public:
	STDMETHOD(OpenConsole)(void);
public:
	STDMETHOD(CloseConsole)(void);
public:
	STDMETHOD(SetWindowScale)(LONG hWnd, FLOAT ScaleX, FLOAT ScaleY);
public:
	STDMETHOD(SetWindowOffset)(LONG hWnd, FLOAT X, FLOAT Y);
public:
	STDMETHOD(ExecuteBatch)(LONG batchId);
public:
	STDMETHOD(BatchSetWindowMatrix)(LONG hWnd, FLOAT X, FLOAT Y, FLOAT SX, FLOAT SY, FLOAT RZ);
public:
	STDMETHOD(GetRenderOptions)(LONG hWnd, LONG* Options);
public:
	STDMETHOD(SetRenderOptions)(LONG hWnd, LONG Options);
public:
	STDMETHOD(SetWindowMatrix)(LONG hWnd, FLOAT X, FLOAT Y, FLOAT SX, FLOAT SY, FLOAT RZ);
public:
	STDMETHOD(LockRendering)(void);
public:
	STDMETHOD(UnlockRendering)(void);
public:
	STDMETHOD(Test)(LONG hWnd);
};

OBJECT_ENTRY_AUTO(__uuidof(DWMEx), CDWMEx)
