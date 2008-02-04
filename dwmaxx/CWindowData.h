#pragma once

#include "stdafx.h"
#include "milcore.h"
#include "CTopLevelWindow.h"
#include "CTopLevelWindow3D.h"

class	CWindowData
{
public:
	char				unkown[0x10];			// 0x00 - 0x10
	HWND				hWnd;					// 0x10	- 0x14
	char				unkown2[0x2D0 - 0x14];	// 0x14 - 0x2D0
	CTopLevelWindow		*TopLevelWindow;		// 0x2D0 - 0x2D4
	CTopLevelWindow3D	*TopLevelWindow3D;		// 0x2D4 - 0x2D8

	CWindowData();
	~CWindowData();
};