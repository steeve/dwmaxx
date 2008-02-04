#include "milcore.h"

extern "C" __declspec(dllexport) int __stdcall MilChannel_AppendCommandData(MIL_CHANNEL pChannel, void* pbData, unsigned int cbSize) { return (0); }
extern "C" __declspec(dllexport) int __stdcall MilChannel_BeginCommand(MIL_CHANNEL pChannel, void* pbData, unsigned int cbSize, unsigned int cbExtra) { return (0); }
extern "C" __declspec(dllexport) int __stdcall MilChannel_EndCommand(MIL_CHANNEL pChannel) { return (0); }
extern "C" __declspec(dllexport) int __stdcall MilChannel_SetNotificationWindow(MIL_CHANNEL pChannel, HWND hwnd, int message) { return (0); }
extern "C" __declspec(dllexport) int __stdcall MilChannel_CommitChannel(MIL_CHANNEL channelHandle) { return (0); }
extern "C" __declspec(dllexport) int __stdcall MilConnection_CreateChannel(MIL_CHANNEL pTransport, MIL_CHANNEL hChannel, MIL_CHANNEL** channelHandle) { return (0); }
extern "C" __declspec(dllexport) int __stdcall MilConnection_DestroyChannel(MIL_CHANNEL channelHandle) { return (0); }
extern "C" __declspec(dllexport) int __stdcall MilResource_CreateOrAddRefOnChannel(MIL_CHANNEL pChannel, RESOURCE_TYPE resourceType, RESOURCE_HANDLE** hResource) { return (0); }
extern "C" __declspec(dllexport) int __stdcall MilResource_DuplicateHandle(MIL_CHANNEL pSourceChannel, RESOURCE_HANDLE original, MIL_CHANNEL pTargetChannel, RESOURCE_HANDLE** duplicate) { return (0); }
extern "C" __declspec(dllexport) int __stdcall MilResource_ReleaseOnChannel(MIL_CHANNEL pChannel, RESOURCE_HANDLE hResource, BOOL** deleted) { return (0); }
extern "C" __declspec(dllexport) int __stdcall MilResource_SendCommand(void* pbData, unsigned int cbSize, MIL_CHANNEL pChannel) { return (0); }
