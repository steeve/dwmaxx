

/* this ALWAYS GENERATED file contains the IIDs and CLSIDs */

/* link this file in with the server and any clients */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Mon Feb 04 20:05:28 2008
 */
/* Compiler settings for .\dwmaxx.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


#ifdef __cplusplus
extern "C"{
#endif 


#include <rpc.h>
#include <rpcndr.h>

#ifdef _MIDL_USE_GUIDDEF_

#ifndef INITGUID
#define INITGUID
#include <guiddef.h>
#undef INITGUID
#else
#include <guiddef.h>
#endif

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8)

#else // !_MIDL_USE_GUIDDEF_

#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

#define MIDL_DEFINE_GUID(type,name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) \
        const type name = {l,w1,w2,{b1,b2,b3,b4,b5,b6,b7,b8}}

#endif !_MIDL_USE_GUIDDEF_

MIDL_DEFINE_GUID(IID, IID_IDWMEx,0x9C797EE5,0x8465,0x4980,0xB0,0x28,0x42,0x44,0xCB,0x77,0x40,0xB2);


MIDL_DEFINE_GUID(IID, IID_IDWMInjector,0xCB3A50A3,0x0FF3,0x4582,0x96,0xCF,0xF2,0xEF,0x08,0xF6,0xDB,0xDA);


MIDL_DEFINE_GUID(IID, LIBID_dwmaxxLib,0xC42006C4,0x4EAF,0x402F,0x89,0xC6,0x09,0xD1,0x67,0xE7,0x5A,0xEC);


MIDL_DEFINE_GUID(CLSID, CLSID_DWMEx,0x3B83AC72,0xFD69,0x456A,0xAF,0x52,0xD0,0x9F,0xA1,0x58,0xBF,0xFD);


MIDL_DEFINE_GUID(CLSID, CLSID_DWMInjector,0x0A6807C4,0x1DE7,0x45D9,0xB1,0xB3,0x4B,0x62,0x19,0xFC,0x27,0xF4);

#undef MIDL_DEFINE_GUID

#ifdef __cplusplus
}
#endif



