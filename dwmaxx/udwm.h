#pragma once

#include "stdafx.h"
#include "udwm_rva.h"
#include "milcore.h"
#include "CWindowData.h"

typedef struct
{
	char		vtable[8];
	MIL_CHANNEL	MilChannel;
	char		unkown_[684];
	HANDLE		hMessageLoopThread;
} CDesktopManager;

typedef struct
{
	char				unknown[8];
	MIL_CHANNEL			MilChannel;
	MIL_RESOURCE_HANDLE	ResourceHandle;
} CResource_old;
//
typedef struct
{
	void			*vftable;
	unsigned int	ReferenceCount;
} CBaseObject_old;

typedef struct s_CVisual
{
	CBaseObject_old	BaseObject;
	CResource_old	*CResourceObj;	// 0x8
	struct s_CVisual		*Parent;
	char		unkown__[28];
	int			Flags;			// 0x2C
	char		unknown____[4];
	CResource	*MatrixResource;	// 0x34
	POINT		Offset;				// 0x38
	SIZE		Size;				// 0x40
	char		unkown_____[24];
	double		ScaleX;				// 0x60
	double		ScaleY;				// 0x68
	char		unkown____[8];
	long		RenderFlags;
} CVisual_old;
//
typedef struct
{
	CVisual_old	CVisualObj;
} CTopLevelWindow_old;
//
//typedef struct
//{
//	CVisual	CVisualObj;
//	char	unkown2[168];
//	void	*CWindowData;
//	char	unkown3[8];
//	void	*SecondaryWindowRepresentation;
//} CTopLevelWindow3D;
//
//typedef struct
//{
//	char				unkown[16];
//	HWND				hWnd;
//	char				unkown2[700];
//	CTopLevelWindow		*TopLevelWindow;
//	CTopLevelWindow3D	*TopLevelWindow3D;
//} CWindowData;


void		InituDWM();
CWindowData	*LookupWindow(HWND hWnd);
//int			CTopLevelWindow_ShowWindow(CTopLevelWindow *CTopLevelWindowObj, bool visible);
//int			CVisual_SetOpacity(CVisual *CVisualObj, double value);
//int			CVisual_SetVisible(CVisual *CVisualObj, bool visible);
//void		CVisual_SetDirtyFlags(CVisual *CVisualObj, unsigned long flags);
int			CVisual_SetScale(CVisual_old *CVisualObj, double ScaleX, double ScaleY);
//int			CVisual_SetOffset(CVisual *CVisualObj, POINT *point);
LPCRITICAL_SECTION	GetDWMCriticalSection();
//void		CTopLevelWindow_UpdateWindowScale(CTopLevelWindow *CTopLevelWindowObj);
//int			CVisual_SetOffsetFloat(CVisual *CVisualObj, float X, float Y);
//long		CVisual_UpdateTransform(CVisual *CVisualObj);
//long		CVisual_UpdateRenderOptions(CVisual *CVisualObj);
//long		CVisual_SetTransform(CVisual *CVisualObj, FLOAT X, FLOAT Y, FLOAT SX, FLOAT SY, FLOAT RZ);
//long		CResource_Create(MIL_RESOURCE_TYPE Type, MIL_CHANNEL Channel, CResource** Resource);
//void		CBaseObject_AddRef(CBaseObject *Object);
//void		CBaseObject_Release(CBaseObject *Object);
