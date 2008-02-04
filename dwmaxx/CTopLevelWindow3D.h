#ifndef __CTOPLEVELWINDOW3D_H__
#define __CTOPLEVELWINDOW3D_H__

#include "stdafx.h"
#include "milcore.h"
#include "CVisual.h"
#include "ISecondaryWindowRepresentationChangedListener.h"
#include "CSecondaryWindowRepresentation.h"
#include "CWindowData.h"

class	CTopLevelWindow3D : public CVisual, public ISecondaryWindowRepresentationChangedListener
{
public: // 0xB8
	char								unkown[0xD8 - 0xB8 - 4];			// 0xB8 - 0xD8
	CWindowData							*WindowData;						// 0xD8 - 0xDC
	CResource							*Scene3DResource;					// 0xDC - 0xE0
	CResource							*CameraResource;					// 0xE0 - 0xE4
	CSecondaryWindowRepresentation		*SecondaryWindowRepresentation;		// 0xE4 - 0xE8
	void								*Timeline;							// 0xE8 - 0xEC

	CTopLevelWindow3D();
	~CTopLevelWindow3D();

	long ShowWindow(bool visible, bool showTransition);
	long UpdateCameraResource(MIL_CHANNEL channel);
	long UpdateScene3DResource(MIL_CHANNEL channel);
	long CTopLevelWindow3D::UpdateAnimatedResources();

	long OnZOrderUpdated(bool param1);
};

#else
class	CTopLevelWindow3D;
#endif