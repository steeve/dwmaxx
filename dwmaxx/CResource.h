#pragma once

#include "stdafx.h"
#include "milcore.h"
#include "CBaseObject.h"

class CResource : public CBaseObject
{
public:
	MIL_CHANNEL			MilChannel;
	MIL_RESOURCE_HANDLE	ResourceHandle;

	CResource();
	~CResource();

	int AppendCommandData(void *pbCommandData, unsigned int cbSize);
	int BeginCommand(void *pbCommandData, unsigned int cbSize, unsigned int cbExtra);
	int EndCommand();

	int Send(void *pbCommandData, unsigned int cbSize);
	int SendWithData(void *pbCommandData, unsigned int cbSize, void *pbData, unsigned int cbDataSize);

	int Initialize(MIL_RESOURCE_TYPE type, MIL_CHANNEL channel);
	
	static long Create(MIL_RESOURCE_TYPE type, MIL_CHANNEL channel, CResource **resourceOut);
	static long WrapExistingResource(MIL_CHANNEL channel, unsigned int unknown, CResource **resourceOut);
};
