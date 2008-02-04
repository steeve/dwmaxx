// DWMInjector.h : Declaration of the CDWMInjector

#pragma once
#include "resource.h"       // main symbols

#include "dwmaxx.h"


#if defined(_WIN32_WCE) && !defined(_CE_DCOM) && !defined(_CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA)
#error "Single-threaded COM objects are not properly supported on Windows CE platform, such as the Windows Mobile platforms that do not include full DCOM support. Define _CE_ALLOW_SINGLE_THREADED_OBJECTS_IN_MTA to force ATL to support creating single-thread COM object's and allow use of it's single-threaded COM object implementations. The threading model in your rgs file was set to 'Free' as that is the only threading model supported in non DCOM Windows CE platforms."
#endif



// CDWMInjector

class ATL_NO_VTABLE CDWMInjector :
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CDWMInjector, &CLSID_DWMInjector>,
	public IDispatchImpl<IDWMInjector, &IID_IDWMInjector, &LIBID_dwmaxxLib, /*wMajor =*/ 0, /*wMinor =*/ 1>
{
public:
	CDWMInjector()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_DWMINJECTOR)


BEGIN_COM_MAP(CDWMInjector)
	COM_INTERFACE_ENTRY(IDWMInjector)
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

public:

public:
	STDMETHOD(Inject)(void);
public:
	STDMETHOD(GetDWMExObject)(IDWMEx** dwmExOut);
public:
	STDMETHOD(get_IsInjected)(VARIANT_BOOL* pVal);
public:
	STDMETHOD(Unload)(void);
};

OBJECT_ENTRY_AUTO(__uuidof(DWMInjector), CDWMInjector)
