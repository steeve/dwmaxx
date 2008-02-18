#include "stdafx.h"
#include "CVisual.h"
#include <conio.h>

#include "patch.h"
#include "udwm_rva.h"
#include "udwm.h"

#include <d3d9.h>
#include <d3dx9.h>
#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")


CVisual::CVisual()
{
}

CVisual::~CVisual()
{
}

int	CVisual::SetOpacity(double opacity)
{
	return ((int)UDWM_CallMethodESI(this, rva_CVisual_SetOpacity, opacity));
}

int CVisual::SetVisible(bool visible)
{
	void	*addrFunc = UDWM_GetMethodAddr(rva_CVisual_SetIsVisible);
	int		retValue = 0;

	__asm
	{
		pushad

		mov  eax, this
		mov  dl, visible
		call addrFunc
		mov	 retValue, eax

		popad
	}

	return (retValue);
}

void CVisual::SetDirtyFlags(VisualProxyFlags flags)
{
	UDWM_CallMethodEAX(this, rva_CVisual_SetDirtyFlags, flags);
}

int	CVisual::SetScale(double scaleX, double scaleY)
{
	return ((int)UDWM_CallMethodESI(this, rva_CVisual_SetScale, scaleX, scaleY));
}

void	CVisual::SetOffset(POINT offset)
{
	this->Offset = offset;
	this->SetDirtyFlags(IsContentDirty);
}

long	CVisual::UpdateTransform()
{
	return ((long)UDWM_CallMethodEAX(this, rva_CVisual_UpdateTransform));
}

long	CVisual::UpdateRenderOptions()
{
	return ((long)UDWM_CallMethodEDX(this, rva_CVisual_UpdateRenderOptions));
}

int	CVisual::MILSetOpacity(double opacity)
{
	MILCMD_VISUAL_SETALPHA	newCmd;

	newCmd.Type = MilCmdVisualSetAlpha;
	//newCmd.Handle = this->Resource->ResourceHandle;
	newCmd.Alpha = opacity;

	OutputDebugString(TEXT("1"));

	return (this->Resource->Send(&newCmd, sizeof(newCmd)));
}

int CVisual::MILSetOffset(double x, double y)
{
	MILCMD_VISUAL_SETOFFSET newCmd;

	newCmd.Type = MilCmdVisualSetOffset;
	//newCmd.Handle = this->Resource->ResourceHandle;
	newCmd.offsetX = x;
	newCmd.offsetY = y;

	return (this->Resource->Send(&newCmd, sizeof(newCmd)));
}

int CVisual::MILSetTransform(float x, float y, float scaleX, float scaleY, float rotationZ)
{
	D3DXMATRIX	endMatrix;
	D3DXMATRIX	tmpMatrix;

	D3DXMatrixIdentity(&endMatrix);

	D3DXMatrixScaling(&tmpMatrix, scaleX, scaleY, 1.0f);
	D3DXMatrixMultiply(&endMatrix, &endMatrix, &tmpMatrix);

	POINTF	rotationCenter;
	rotationCenter.x = (this->Size.cx / 2.0f * scaleX);
	rotationCenter.y = (this->Size.cy / 2.0f * scaleY);
	D3DXMatrixTranslation(&tmpMatrix, -rotationCenter.x, -rotationCenter.y, 0.0f);
	D3DXMatrixMultiply(&endMatrix, &endMatrix, &tmpMatrix);
	D3DXMatrixRotationZ(&tmpMatrix, rotationZ);
	D3DXMatrixMultiply(&endMatrix, &endMatrix, &tmpMatrix);
	D3DXMatrixTranslation(&tmpMatrix, rotationCenter.x, rotationCenter.y, 0.0f);
	D3DXMatrixMultiply(&endMatrix, &endMatrix, &tmpMatrix);

	D3DXMatrixTranslation(&tmpMatrix, x, y, 0.0f);
	D3DXMatrixMultiply(&endMatrix, &endMatrix, &tmpMatrix);

	if (this->MatrixResource == NULL)
		CResource::Create(TYPE_MATRIXTRANSFORM, this->Resource->MilChannel, &(this->MatrixResource));
	MILCMD_MATRIXTRANSFORM	matrixCmd;
	matrixCmd.Type = MilCmdMatrixTransform;
	//matrixCmd.Handle = this->MatrixResource->ResourceHandle;
	matrixCmd.Matrix.S_11 = endMatrix._11;
	matrixCmd.Matrix.S_12 = endMatrix._12;
	matrixCmd.Matrix.S_21 = endMatrix._21;
	matrixCmd.Matrix.S_22 = endMatrix._22;
	matrixCmd.Matrix.DX = endMatrix._41;
	matrixCmd.Matrix.DY = endMatrix._42;
	matrixCmd.hMatrixAnimations = NULL;
	this->MatrixResource->Send(&matrixCmd, sizeof(matrixCmd));

	MILCMD_VISUAL_SETTRANSFORM	newTransCmd;
	newTransCmd.Type = MilCmdVisualSetTransform;
	//newTransCmd.Handle = this->Resource->ResourceHandle;
	newTransCmd.hTransform = this->MatrixResource->ResourceHandle;
	return (this->Resource->Send(&newTransCmd, sizeof(newTransCmd)));
}

int		CVisual::MILSetRenderOptions()
{
	MILCMD_VISUAL_SETRENDEROPTIONS	newCmd;

	MILRenderOptions newOptions;

	newOptions.BitmapScalingMode = BitmapScalingModes::HighQuality;
	newOptions.EdgeMode = EdgeModes::Aliased;
	newOptions.Flags = (MILRenderOptionFlags)(MILRenderOptionFlags::BitmapScalingMode | MILRenderOptionFlags::EdgeMode);

	newCmd.Type = MilCmdVisualSetRenderOptions;
	//newCmd.Handle = this->Resource->ResourceHandle;
	newCmd.RenderOptions = newOptions;

	return (this->Resource->Send(&newCmd, sizeof(newCmd)));
}