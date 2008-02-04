#include "stdafx.h"
#include "CBaseObject.h"

#include "patch.h"
#include "udwm_rva.h"

HMODULE	CBaseObject::hUDwm = GetModuleHandle(_T("uDWM.dll"));

CBaseObject::CBaseObject()
{
	//if (CBaseObject::hUDwm == NULL)
	//	InitUDWM();
}

CBaseObject::~CBaseObject()
{
}

void CBaseObject::AddRef()
{
//	CallMethodEAX(this, PE_RvaToVa(hUDwm, rva_CBaseObject_AddRef));
	UDWM_CallMethodEAX(this, rva_CBaseObject_AddRef);
}

void CBaseObject::Relase()
{
	//CallMethod(this, PE_RvaToVa(hUDwm, rva_CBaseObject_Release));
	UDWM_CallMethod(this, rva_CBaseObject_Release);
}

void	*CBaseObject::UDWM_GetMethodAddr(UDWM_RVAs methodRva)
{
	// we know what we are doing
#pragma warning( push )
#pragma warning( disable : 4311 4312 )
	return ((void *)((unsigned int)CBaseObject::hUDwm + (unsigned int)methodRva));
#pragma warning( pop )
}

DWORD	CBaseObject::UDWM_CallFunction(UDWM_RVAs funcRva, ...)
{
   DWORD retVal;
   void	*funcAddr = UDWM_GetMethodAddr(funcRva);

   __asm
   {
	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 4				// don't count funcRva
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [funcRva + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       call funcAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD	CBaseObject::UDWM_CallMethod(void *thisObj, UDWM_RVAs methodRva, ...)
{
   DWORD retVal;
   void	*methodAddr = CBaseObject::UDWM_GetMethodAddr(methodRva);

   __asm
   {
	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodRva + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  ecx, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD	CBaseObject::UDWM_CallMethodEAX(void *thisObj, UDWM_RVAs methodRva, ...)
{
   DWORD retVal;
   void	*methodAddr = CBaseObject::UDWM_GetMethodAddr(methodRva);

   __asm
   {
	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodRva + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  eax, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD	CBaseObject::UDWM_CallMethodEBX(void *thisObj, UDWM_RVAs methodRva, ...)
{
   DWORD retVal;
   void	*methodAddr = CBaseObject::UDWM_GetMethodAddr(methodRva);

   __asm
   {
	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodRva + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  ebx, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD	CBaseObject::UDWM_CallMethodEDX(void *thisObj, UDWM_RVAs methodRva, ...)
{
   DWORD retVal;
   void	*methodAddr = CBaseObject::UDWM_GetMethodAddr(methodRva);

   __asm
   {
	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodRva + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  edx, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD	CBaseObject::UDWM_CallMethodEDI(void *thisObj, UDWM_RVAs methodRva, ...)
{
   DWORD retVal;
   void	*methodAddr = CBaseObject::UDWM_GetMethodAddr(methodRva);

   __asm
   {
   	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodRva + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  edi, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD	CBaseObject::UDWM_CallMethodESI(void *thisObj, UDWM_RVAs methodRva, ...)
{
   DWORD retVal;
   void	*methodAddr = CBaseObject::UDWM_GetMethodAddr(methodRva);

   __asm
   {
   	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodRva + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  esi, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}
