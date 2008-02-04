#pragma once

#define PE_RvaToVa(handle, rva)				((void *)((DWORD)handle + (DWORD)rva))

DWORD	CallFunction(void *funcAddr, ...);
DWORD	CallMethod(void *thisObj, void *methodAddr, ...);
DWORD	CallMethodEAX(void *thisObj, void *methodAddr, ...);
DWORD	CallMethodEBX(void *thisObj, void *methodAddr, ...);
DWORD	CallMethodEDX(void *thisObj, void *methodAddr, ...);
DWORD	CallMethodEDI(void *thisObj, void *methodAddr, ...);
DWORD	CallMethodESI(void *thisObj, void *methodAddr, ...);
void	*IATPatchSub(char *imageName, char *importImageName, char *oldImport, void *newProc);
void	*HotPatchSub(void *oldProc, void *newProc);
void	*HookSub(void *oldProc, void *newProc);
void	UnHookSub(void *oldProc);