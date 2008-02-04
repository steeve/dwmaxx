#pragma once

#include "stdafx.h"
#include "milcore.h"
#include "CVisual.h"

class CWindowData;

class	CTopLevelWindow : public CVisual
{
public: // 0xB8
	char	unkown[0x1A0 - 0xB8];
	CWindowData	*WindowData;

	CTopLevelWindow();
	~CTopLevelWindow();

	long	ShowWindow(bool show);
};