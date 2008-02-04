#pragma once

#include "stdafx.h"
#include "milcore.h"
#include "CBaseObject.h"
#include "CResource.h"
#include "ISecondaryWindowRepresentationChangedListener.h"
#include <d3d9.h>
#include <d3dx9.h>

class CWindowData;

class	CSecondaryWindowRepresentation : public CBaseObject
{
public:
	int SetOpacity(double newValue);
	long SetTransform3D(D3DXMATRIX *matrix);

	long GetModel3D(CResource **resource);

	static long Create(int Flags /* = 0xB8 */, ISecondaryWindowRepresentationChangedListener *listener, CWindowData *windowData, CSecondaryWindowRepresentation **windowRepresentation);
};