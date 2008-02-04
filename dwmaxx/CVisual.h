#pragma once

#include "stdafx.h"
#include "milcore.h"
#include "CResource.h"

class CVisual : public CBaseObject
{
public:
	CResource	*Resource;
	CVisual		*Parent;
	char		CVisualUnkown1[28];
	int			Flags;				// 0x2C
	char		CVisualUnkown2[4];
	CResource	*MatrixResource;	// 0x34
	POINT		Offset;				// 0x38
	SIZE		Size;				// 0x40
	char		CVisualUnkown3[24];
	double		ScaleX;				// 0x60
	double		ScaleY;				// 0x68
	char		CVisualUnkown4[8];
	long		RenderFlags;
	char		CVisualUnkown5[60]; // sizeof(CVisual) == 0xB8

	CVisual();
	virtual ~CVisual();

	int		SetOpacity(double opacity);
	int		SetScale(double ScaleX, double ScaleY);
	void	SetOffset(POINT offset);
	int		SetVisible(bool visible);
	void	SetDirtyFlags(VisualProxyFlags flags);
	long	UpdateTransform();
	long	UpdateRenderOptions();

	int		MILSetOpacity(double opacity);
	int		MILSetOffset(double x, double y);
	int		MILSetTransform(float x, float y, float scaleX, float scaleY, float rotationZ);
	int		MILSetRenderOptions();
};
