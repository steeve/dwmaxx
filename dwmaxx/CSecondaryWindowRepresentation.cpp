#include "stdafx.h"
#include "CSecondaryWindowRepresentation.h"
#include "patch.h"
#include "udwm_rva.h"

int CSecondaryWindowRepresentation::SetOpacity(double newValue)
{
	return ((int)UDWM_CallMethodEBX(this, rva_CSecondaryWindowRepresentation_SetOpacity, newValue));
}

long CSecondaryWindowRepresentation::SetTransform3D(D3DXMATRIX *matrix)
{
	return ((int)UDWM_CallMethodEAX(this, rva_CSecondaryWindowRepresentation_SetTransform3D, matrix));
}

long	CSecondaryWindowRepresentation::Create(int Flags, ISecondaryWindowRepresentationChangedListener *listener, CWindowData *windowData, CSecondaryWindowRepresentation **windowRepresentation)
{
	return ((long)UDWM_CallFunction(rva_CSecondaryWindowRepresentation_Create, Flags, listener, windowData, windowRepresentation));
}

long CSecondaryWindowRepresentation::GetModel3D(CResource **resource)
{
	return ((long)UDWM_CallMethodEDI(this, rva_CSecondaryWindowRepresentation_GetModel3D, resource));
}