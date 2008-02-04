#include "stdafx.h"
#include "CTopLevelWindow.h"
#include "patch.h"
#include "udwm_rva.h"

CTopLevelWindow::CTopLevelWindow()
{
}

CTopLevelWindow::~CTopLevelWindow()
{
}

long	CTopLevelWindow::ShowWindow(bool show)
{
	void	*addrFunc =  UDWM_GetMethodAddr(rva_CTopLevelWindow_ShowWindow);
	long	retValue = 0;

	__asm
	{
		pushad

		mov  eax, this
		mov  dl, show
		call addrFunc
		mov	 retValue, eax

		popad
	}

	return (retValue);
}