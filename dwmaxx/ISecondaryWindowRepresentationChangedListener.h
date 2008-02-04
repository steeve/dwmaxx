#pragma once

#include "stdafx.h"

class CSecondaryWindowRepresentation;

class ISecondaryWindowRepresentationChangedListener
{
	virtual void	OnSizeChanged(CSecondaryWindowRepresentation *secondaryWindowRepresentation) = 0;
	virtual void	OnMouseLeftButton(bool state) = 0;
};