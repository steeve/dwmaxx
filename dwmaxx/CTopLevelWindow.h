#ifndef __CTOPLEVELWINDOW_H__
#define __CTOPLEVELWINDOW_H__

#include "stdafx.h"
#include "milcore.h"
#include "CVisual.h"
#include "CWindowData.h"

class	CTopLevelWindow : public CVisual
{
public: // 0xB8
	char	unkown[0x1A0 - 0xB8];
	CWindowData	*WindowData;

	CTopLevelWindow();
	~CTopLevelWindow();

	long	ShowWindow(bool show);
};

#else
class	CTopLevelWindow;
#endif
