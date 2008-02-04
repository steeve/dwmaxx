#include "stdafx.h"
#include "patch.h"
#include <DbgHelp.h>

#pragma comment (lib, "dbghelp.lib")

#pragma warning( push )
#pragma warning( disable : 4311 4312 )

DWORD CallFunction(void *funcAddr, ...)
{
   DWORD retVal;

   __asm
   {
	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 4				// don't count funcAddr
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [funcAddr + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       call funcAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD CallMethod(void *thisObj, void *methodAddr, ...)
{
   DWORD retVal;

   __asm
   {
	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodAddr + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  ecx, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD CallMethodEAX(void *thisObj, void *methodAddr, ...)
{
   DWORD retVal;

   __asm
   {
	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodAddr + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  eax, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD CallMethodEBX(void *thisObj, void *methodAddr, ...)
{
   DWORD retVal;

   __asm
   {
	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodAddr + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  ebx, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD CallMethodEDI(void *thisObj, void *methodAddr, ...)
{
   DWORD retVal;

   __asm
   {
   	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodAddr + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  edi, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

DWORD CallMethodESI(void *thisObj, void *methodAddr, ...)
{
   DWORD retVal;

   __asm
   {
   	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodAddr + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  esi, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}


DWORD CallMethodEDX(void *thisObj, void *methodAddr, ...)
{
   DWORD retVal;

   __asm
   {
	   pushad

	   mov  eax, [ebp + 4]		// get current ret addr
	   xor  ecx, ecx			// clear ecx
	   mov  cl, [eax + 2]		// read the add opcode parameter (which is actually the number of args * 4)
	   sub  cl, 8				// don't count thisptr and address
       sub  esp, ecx			// reserve the new stack frame
       shr  ecx, 2				// set the counter to the correct number of params
       lea  esi, [methodAddr + 4]	// set the source (the var args)
       mov  edi, esp			// set the destination (the newly created stack frame)
       rep  movsd				// copy
       mov  edx, thisObj		// mov this
       call methodAddr
       mov  retVal, eax

	   popad
    }

   return (retVal);
}

void	*IATPatchSub(TCHAR *imageName, char *importImageName, char *oldImport, void *newProc)
{
	HANDLE	hDll = NULL;

	hDll = GetModuleHandle(imageName);

	void *oldProcAddr = NULL;

	IMAGE_NT_HEADERS			*header = NULL;
	IMAGE_DATA_DIRECTORY		*importsDirectoryEntry = NULL;
	IMAGE_IMPORT_DESCRIPTOR		*imageImports = NULL;

	header = ImageNtHeader((void *)hDll);

	// First, unprotect the assembly.
	DWORD	oldProtect = 0;

	importsDirectoryEntry = (IMAGE_DATA_DIRECTORY *)&header->OptionalHeader.DataDirectory[IMAGE_DIRECTORY_ENTRY_IMPORT];
	imageImports = (IMAGE_IMPORT_DESCRIPTOR *)PE_RvaToVa(hDll, importsDirectoryEntry->VirtualAddress);

	while (imageImports->Name != 0)
	{
		char *currentModule = (char *)PE_RvaToVa(hDll, imageImports->Name);

		if (strcmp(currentModule, importImageName) == 0)
		{
			PIMAGE_THUNK_DATA pOriginalThunks = NULL;
			PIMAGE_THUNK_DATA pThunks = NULL;
			pOriginalThunks = (PIMAGE_THUNK_DATA)PE_RvaToVa(hDll, imageImports->OriginalFirstThunk);
			pThunks = (PIMAGE_THUNK_DATA)PE_RvaToVa(hDll, imageImports->FirstThunk);

			for (int i = 0; pOriginalThunks[i].u1.AddressOfData != 0; i++)
			{
				IMAGE_IMPORT_BY_NAME	*name = (IMAGE_IMPORT_BY_NAME *)PE_RvaToVa(hDll, pOriginalThunks[i].u1.AddressOfData);
				char *currentProc = (char *)&(name->Name);

				if (strcmp(currentProc, oldImport) == 0)
				{
					oldProcAddr = (void *)pThunks[i].u1.Function;

					VirtualProtect((void *)&pThunks[i], sizeof(pThunks[i]), PAGE_READWRITE, &oldProtect);
					pThunks[i].u1.Function = (DWORD)newProc;
					VirtualProtect((void *)&pThunks[i], sizeof(pThunks[i]), oldProtect, &oldProtect);

					FlushInstructionCache(GetCurrentProcess(), NULL, 0);
					
					return (oldProcAddr);
				}
			}
		}
		imageImports++;
	}

	return (NULL);
}

// !TODO: Add auto alloc for missing stub
void	*HookSub(void *oldProc, void *newProc)
{
	void *jmpAddr = (void *)((char *)newProc - (char *)oldProc - 5);

	// patch
	DWORD	oldProtect = NULL;
	VirtualProtect(oldProc, 5, PAGE_EXECUTE_WRITECOPY, &oldProtect);
	__asm
	{
		push eax
		push ebx

		mov eax, oldProc
		mov ebx, jmpAddr

		mov byte  ptr [eax], 0xE9	// long jmp
		mov dword ptr [eax + 1], ebx

		pop ebx
		pop eax
	}
	VirtualProtect(oldProc, 5, oldProtect, &oldProtect);

	FlushInstructionCache(GetCurrentProcess(), oldProc, 5);

	return ((void *)((char *)oldProc + 5));
}

void	*HotPatchSub(void *oldProc, void *newProc)
{
	void *hotPatchAddr = (void *)((char *)oldProc - 5);
	void *jmpAddr = (void *)((char *)newProc - (char *)oldProc);

	// patch
	DWORD	oldProtect = NULL;
	VirtualProtect(hotPatchAddr, 7, PAGE_EXECUTE_READWRITE, &oldProtect);
	__asm
	{
		push eax
		push ebx

		mov eax, oldProc
		mov ebx, jmpAddr

		mov byte  ptr [eax - 5], 0xE9	// long jmp
		mov dword ptr [eax - 4], ebx
		mov word  ptr [eax], 0xF9EB		// EB F9 = jmp - 7

		pop ebx
		pop eax
	}
	VirtualProtect(hotPatchAddr, 7, oldProtect, &oldProtect);

	FlushInstructionCache(GetCurrentProcess(), hotPatchAddr, 7);

	return ((void *)((char *)oldProc + 2));
}

void	UnHookSub(void *oldProc)
{
	DWORD	oldProtect = NULL;
	VirtualProtect(oldProc, 5, PAGE_EXECUTE_READWRITE, &oldProtect);
	__asm
	{
		push eax

		mov eax, oldProc

		mov dword ptr [eax], 0x8B55FF8B	// long jmp
		mov byte  ptr [eax + 4], 0xEC

		pop eax
	}
	VirtualProtect(oldProc, 5, oldProtect, &oldProtect);

	FlushInstructionCache(GetCurrentProcess(), oldProc, 5);
}

#pragma warning( pop )
