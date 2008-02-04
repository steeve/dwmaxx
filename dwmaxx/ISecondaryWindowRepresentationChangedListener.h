#ifndef __ISECONDARYWINDOWREPRESENTATIONCHANGEDLISTENER_H__
#define __ISECONDARYWINDOWREPRESENTATIONCHANGEDLISTENER_H__

#include "stdafx.h"
#include "CSecondaryWindowRepresentation.h"

class ISecondaryWindowRepresentationChangedListener
{
	virtual void	OnSizeChanged(CSecondaryWindowRepresentation *secondaryWindowRepresentation) = 0;
	virtual void	OnMouseLeftButton(bool state) = 0;
};

#else
class ISecondaryWindowRepresentationChangedListener;
#endif