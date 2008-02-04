#pragma once

#include "stdafx.h"
#include "dwmaxx.h"

#define DLL_NAME				"dwmaxx.dll"
#define DWM_CLASS_NAME			"Dwm"

#ifdef UNICODE
#define LOAD_LIBRARY_EXPORT	"LoadLibraryW"
#else
#define LOAD_LIBRARY_EXPORT	"LoadLibraryA"
#endif // !UNICODE
#define FREE_LIBRARY_EXPORT	"FreeLibrary"

bool	DWMaxxIsRunningInsideDWM();
bool	DWMaxxInject();
bool	DWMaxxUnload();
void	DWMaxxStart();
void	DWMaxxStart2();
bool	DWMaxxIsInjected();
CComPtr<IDWMEx> DWMaxxGetObject();