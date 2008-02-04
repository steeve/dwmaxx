#include "stdafx.h"
#include "CTopLevelWindow3D.h"
#include "patch.h"
#include "udwm_rva.h"

CTopLevelWindow3D::CTopLevelWindow3D()
{
}

CTopLevelWindow3D::~CTopLevelWindow3D()
{
}

long CTopLevelWindow3D::ShowWindow(bool visible, bool showTransition)
{
	return ((long)UDWM_CallMethodESI(this, rva_CTopLevelWindow3D_ShowWindow, visible, showTransition));
}

long CTopLevelWindow3D::UpdateCameraResource(MIL_CHANNEL channel)
{
	return ((long)UDWM_CallMethodEAX(this, rva_CTopLevelWindow3D_UpdateCameraResource, channel));
}

long CTopLevelWindow3D::UpdateScene3DResource(MIL_CHANNEL channel)
{
	return ((long)UDWM_CallMethodEAX(this, rva_CTopLevelWindow3D_UpdateScene3DResource, channel));	
}

long CTopLevelWindow3D::OnZOrderUpdated(bool param1)
{
	return ((long)UDWM_CallMethodEDX(this, rva_CTopLevelWindow3D_OnZOrderUpdated, param1));
}

long CTopLevelWindow3D::UpdateAnimatedResources()
{
	return ((long)UDWM_CallMethodEAX(this, rva_CTopLevelWindow3D_UpdateAnimatedResources));
}