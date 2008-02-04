#include "stdafx.h"
#include "CResource.h"

#include "patch.h"
#include "udwm_rva.h"

CResource::CResource()
{
}

CResource::~CResource()
{
}

int	CResource::AppendCommandData(void *pbCommandData, unsigned int cbSize)
{
	return (UDWM_CallMethodEAX(this, rva_CResource_AppendCommandData, pbCommandData, cbSize));
}

int CResource::BeginCommand(void *pbCommandData, unsigned int cbSize, unsigned int cbExtra)
{
	return (-1);
}

int CResource::EndCommand()
{
	return (UDWM_CallMethodEAX(this, rva_CResource_EndCommand));
}

int CResource::Send(void *pbCommandData, unsigned int cbSize)
{
	void	*addrFunc = UDWM_GetMethodAddr(rva_CResource_Send);
	int		retValue = 0;

	__asm
	{
		pushad

		mov  eax, this
		mov  ecx, pbCommandData
		push cbSize
		call addrFunc
		mov	 retValue, eax

		popad
	}

	return (retValue);
}

int CResource::SendWithData(void *pbCommandData, unsigned int cbSize, void *pbData, unsigned int cbDataSize)
{
	return (UDWM_CallMethodEAX(this, rva_CResource_SendWithData, pbCommandData, cbSize, pbData, cbDataSize));
}

int CResource::Initialize(MIL_RESOURCE_TYPE type, MIL_CHANNEL channel)
{
	return (UDWM_CallMethodEAX(this, rva_CResource_Initialize, type, channel));
}

long CResource::WrapExistingResource(MIL_CHANNEL channel, unsigned int unknown, CResource **resourceOut)
{
	return (UDWM_CallFunction(rva_CResource_WrapExistingResource, channel, unknown, resourceOut));
}

long CResource::Create(MIL_RESOURCE_TYPE type, MIL_CHANNEL channel, CResource **resourceOut)
{
	return (UDWM_CallFunction(rva_CResource_Create, type, channel, resourceOut));
}
