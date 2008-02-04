#pragma once

#include "stdafx.h"
#include "udwm_rva.h"

typedef enum
{
	EAX,
	EBX,
	ECX,
	EDI,
	EDX,
	ESI,
} ThisPtrRegister;

class CBaseObject
{
public:
	static HMODULE	hUDwm;
	unsigned int	ReferenceCount;

	CBaseObject();
	virtual ~CBaseObject();

	void	AddRef();
	void	Relase();

	static DWORD			UDWM_CallFunction(UDWM_RVAs funcRva, ...);
	static DWORD			UDWM_CallMethod(void *thisObj, UDWM_RVAs methodRva, ...);
	static DWORD			UDWM_CallMethodEAX(void *thisObj, UDWM_RVAs methodRva, ...);
	static DWORD			UDWM_CallMethodEBX(void *thisObj, UDWM_RVAs methodRva, ...);
	static DWORD			UDWM_CallMethodEDX(void *thisObj, UDWM_RVAs methodRva, ...);
	static DWORD			UDWM_CallMethodEDI(void *thisObj, UDWM_RVAs methodRva, ...);
	static DWORD			UDWM_CallMethodESI(void *thisObj, UDWM_RVAs methodRva, ...);
	static void				*UDWM_GetMethodAddr(UDWM_RVAs methodRva);
};