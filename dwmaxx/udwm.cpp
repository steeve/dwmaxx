#include "stdafx.h"
#include "udwm.h"
#include "patch.h"
#include <conio.h>

static HMODULE	g_hDWM;

#include <d3d9.h>
#include <d3dx9.h>

#pragma comment (lib, "d3d9.lib")
#pragma comment (lib, "d3dx9.lib")

#define	CHECK_UDWM_HANDLE()		if (g_hDWM == NULL) InituDWM();

void	InituDWM()
{
	g_hDWM = GetModuleHandle(_T("uDWM.dll"));
	_cprintf("called\n");
}

LPCRITICAL_SECTION	GetDWMCriticalSection()
{
	CHECK_UDWM_HANDLE();
	return (((LPCRITICAL_SECTION)PE_RvaToVa(g_hDWM, rva_CDesktopManager__s_csDwmInstance)));
}

CWindowData	*LookupWindow(HWND hWnd)
{
	CHECK_UDWM_HANDLE();

	CWindowData* (__stdcall *LookupWindowProc)(HWND hWnd) = (CWindowData* (__stdcall *)(HWND))PE_RvaToVa(g_hDWM, rva_LookupWindow);

	return (LookupWindowProc(hWnd));
}

//void	CBaseObject_AddRef(CBaseObject *Object)
//{
//	CallMethodEAX(Object, PE_RvaToVa(g_hDWM, rva_CBaseObject_AddRef));
//}
//
//void	CBaseObject_Release(CBaseObject *Object)
//{
//	CallMethod(Object, PE_RvaToVa(g_hDWM, rva_CBaseObject_Release));
//}
//
//int		CVisual_SetOpacity(CVisual *CVisualObj, double value)
//{
//	CHECK_UDWM_HANDLE();
//	
//	MILCMD_VISUAL_SETALPHA	newCmd;
//	newCmd.Type = MilCmdVisualSetAlpha;
//	newCmd.Handle = CVisualObj->CResourceObj->ResourceHandle;
//	newCmd.Alpha = value;
//
//	return (MilResource_SendCommand(&newCmd, sizeof(newCmd), CVisualObj->CResourceObj->MilChannel));
//
//	//return ((int)CallMethodESI(CVisualObj, PE_RvaToVa(g_hDWM, rva_CVisual_SetOpacity), value));
//}
//
//int		CVisual_SetVisible(CVisual *CVisualObj, bool visible)
//{
//	CHECK_UDWM_HANDLE();
//
//	void	*addrFunc = PE_RvaToVa(g_hDWM, rva_CVisual_SetIsVisible);
//	int		retValue = 0;
//
//	__asm
//	{
//		pushad
//
//		mov  eax, CVisualObj
//		xor  edx, edx
//		mov  dl, visible
//		call addrFunc
//		mov	 retValue, eax
//
//		popad
//	}
//
//	return (retValue);
//}
//
//int		CTopLevelWindow_ShowWindow(CTopLevelWindow *CTopLevelWindowObj, bool visible)
//{
//	CHECK_UDWM_HANDLE();
//
//	void	*addrFunc = PE_RvaToVa(g_hDWM, rva_CTopLevelWindow_ShowWindow);
//	int		retValue = 0;
//
//	__asm
//	{
//		pushad
//
//		mov  eax, CTopLevelWindowObj
//		xor  edx, edx
//		mov  dl, visible
//		call addrFunc
//		mov	 retValue, eax
//
//		popad
//	}
//
//	return (retValue);
//}
//
//void	CVisual_SetDirtyFlags(CVisual *CVisualObj, unsigned long flags)
//{
//	CHECK_UDWM_HANDLE();
//
//	CallMethodEAX(CVisualObj, PE_RvaToVa(g_hDWM, rva_CVisual_SetDirtyFlags), flags);
//}
//
int		CVisual_SetScale(CVisual_old *CVisualObj, double ScaleX, double ScaleY)
{
	CHECK_UDWM_HANDLE();

	return ((int)CallMethodESI(CVisualObj, PE_RvaToVa(g_hDWM, rva_CVisual_SetScale), ScaleX, ScaleY));
}
//
//int		CVisual_SetOffset(CVisual *CVisualObj, POINT *point)
//{
//	CHECK_UDWM_HANDLE();
//	void	*addrFunc = PE_RvaToVa(g_hDWM, rva_CVisual_SetOffset);
//	int		retValue = 0;
//
//	__asm
//	{
//		pushad
//
//		mov  eax, CVisualObj
//		mov  ecx, point
//		call addrFunc
//		mov	 retValue, eax
//
//		popad
//	}
//
//	return (retValue);
//}
//
//void	CTopLevelWindow_UpdateWindowScale(CTopLevelWindow *CTopLevelWindowObj)
//{
//	CHECK_UDWM_HANDLE();
//	CallMethodEAX(CTopLevelWindowObj, PE_RvaToVa(g_hDWM, rva_CTopLevelWindow_UpdateWindowScale));
//}
//
//int CResource_Send(void *thisObj, void *buffer, unsigned int sizeBuf)
//{
//	CHECK_UDWM_HANDLE();
//	void	*addrFunc = PE_RvaToVa(g_hDWM, 0x58CE);
//	int		retValue = 0;
//
//	__asm
//	{
//		pushad
//
//		mov  eax, thisObj
//		mov  ecx, buffer
//		push sizeBuf
//		call addrFunc
//		mov	 retValue, eax
//
//		popad
//	}
//
//	return (retValue);	
//}
//
//typedef int (*MilResource_SendCommandProc)(void* pbData, unsigned int cbSize, MIL_CHANNEL pChannel);
//
//int		CVisual_SetOffsetFloat(CVisual *CVisualObj, float X, float Y)
//{
//	CHECK_UDWM_HANDLE();
//
//	MILCMD_VISUAL_SETOFFSET newCmd;
//
//	newCmd.Type = MilCmdVisualSetOffset;
//	newCmd.Handle = CVisualObj->CResourceObj->ResourceHandle;
//	newCmd.offsetX = X;
//	newCmd.offsetY = Y;
//
////	return (CResource_Send(CVisualObj->CResourceObj, &newCmd, sizeof(newCmd)));
//
//	return (MilResource_SendCommand(&newCmd, sizeof(newCmd), CVisualObj->CResourceObj->MilChannel));
//}
//
//long	CVisual_UpdateTransform(CVisual *CVisualObj)
//{
//	CHECK_UDWM_HANDLE();
//	return (CallMethodEAX(CVisualObj, PE_RvaToVa(g_hDWM, rva_CVisual_UpdateTransform)));
//}
//
//long		CVisual_UpdateRenderOptions(CVisual *CVisualObj)
//{
//	CHECK_UDWM_HANDLE();
//	return (CallMethodEDX(CVisualObj, PE_RvaToVa(g_hDWM, rva_CVisual_UpdateRenderOptions)));
//}
//
//long	CVisual_SetTransform(CVisual *CVisualObj, FLOAT X, FLOAT Y, FLOAT SX, FLOAT SY, FLOAT RZ)
//{
//	CHECK_UDWM_HANDLE();
//
//	D3DXMATRIX	endMatrix;
//	D3DXMATRIX	tmpMatrix;
//
//	D3DXMatrixIdentity(&endMatrix);
//
//	D3DXMatrixScaling(&tmpMatrix, SX, SY, 1.0f);
//	D3DXMatrixMultiply(&endMatrix, &endMatrix, &tmpMatrix);
//
//	D3DXMatrixRotationZ(&tmpMatrix, RZ);
//	D3DXMatrixMultiply(&endMatrix, &endMatrix, &tmpMatrix);
//
//	POINTF	rotationVector;
//	rotationVector.x = (CVisualObj->Size.cx / 2.0f * SX);
//	rotationVector.y = (CVisualObj->Size.cy / 2.0f * SY);
//
//	float	Norme = sqrtf(rotationVector.x * rotationVector.x +  rotationVector.y * rotationVector.y);
//	float	Angle = atanf(rotationVector.y / rotationVector.x);
//
//	if (rotationVector.x > 0.0f && rotationVector.y < 0.0f)
//		Angle += 2 * 3.1416;
//	else if (rotationVector.x < 0.0f)
//		Angle += 3.1416;
//	Angle += RZ;
//
//	POINTF	newVector;
//	newVector.x = Norme * cosf(Angle);
//	newVector.y = Norme * sinf(Angle);
//
//	POINTF	transVector;
//	transVector.x = rotationVector.x - newVector.x;
//	transVector.y = rotationVector.y - newVector.y;
//
//	D3DXMatrixTranslation(&tmpMatrix, X - (FLOAT)CVisualObj->Offset.x + transVector.x, Y - (FLOAT)CVisualObj->Offset.y + transVector.y, 0.0f);
//	D3DXMatrixMultiply(&endMatrix, &endMatrix, &tmpMatrix);
//
//	if (CVisualObj->MatrixResource == NULL)
//		CResource_Create(TYPE_MATRIXTRANSFORM, CVisualObj->CResourceObj->MilChannel, &(CVisualObj->MatrixResource));
//		
//	MILCMD_MATRIXTRANSFORM	matrixCmd;
//	matrixCmd.Type = MilCmdMatrixTransform;
//	matrixCmd.Handle = CVisualObj->MatrixResource->ResourceHandle;
//	matrixCmd.Matrix.S_11 = endMatrix._11;
//	matrixCmd.Matrix.S_12 = endMatrix._12;
//	matrixCmd.Matrix.S_21 = endMatrix._21;
//	matrixCmd.Matrix.S_22 = endMatrix._22;
//	matrixCmd.Matrix.DX = endMatrix._41;
//	matrixCmd.Matrix.DY = endMatrix._42;
//	matrixCmd.hMatrixAnimations = NULL;
//	MilResource_SendCommand(&matrixCmd, sizeof(matrixCmd), CVisualObj->MatrixResource->MilChannel);
//
//	MILCMD_VISUAL_SETTRANSFORM	newTransCmd;
//	newTransCmd.Type = MilCmdVisualSetTransform;
//	newTransCmd.Handle = CVisualObj->CResourceObj->ResourceHandle;
//	newTransCmd.hTransform = CVisualObj->MatrixResource->ResourceHandle;
//
//	return (MilResource_SendCommand(&newTransCmd, sizeof(newTransCmd), CVisualObj->CResourceObj->MilChannel));
//}
//
//long		CResource_Create(MIL_RESOURCE_TYPE Type, MIL_CHANNEL Channel, CResource** Resource)
//{
//	return (CallFunction(PE_RvaToVa(g_hDWM, rva_CResource_Create), Type, Channel, Resource));
//}