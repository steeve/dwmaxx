// DWMInjector.cpp : Implementation of CDWMInjector

#include "stdafx.h"
#include "DWMInjector.h"
#include "injector.h"

// CDWMInjector


STDMETHODIMP CDWMInjector::Inject(void)
{
	return (DWMaxxInject() == true ? S_OK : E_FAIL);
}

STDMETHODIMP CDWMInjector::GetDWMExObject(IDWMEx** dwmExOut)
{
	*dwmExOut = DWMaxxGetObject().Detach();
	return S_OK;
}

STDMETHODIMP CDWMInjector::get_IsInjected(VARIANT_BOOL* pVal)
{
	*pVal = (DWMaxxIsInjected() == true ? VARIANT_TRUE : VARIANT_FALSE);
	return S_OK;
}

STDMETHODIMP CDWMInjector::Unload(void)
{
	return (DWMaxxUnload() == true ? S_OK : E_FAIL);
}
