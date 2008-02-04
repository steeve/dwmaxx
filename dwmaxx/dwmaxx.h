

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 6.00.0366 */
/* at Tue Jan 29 02:19:40 2008
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


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __dwmaxx_h__
#define __dwmaxx_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __IDWMEx_FWD_DEFINED__
#define __IDWMEx_FWD_DEFINED__
typedef interface IDWMEx IDWMEx;
#endif 	/* __IDWMEx_FWD_DEFINED__ */


#ifndef __IDWMInjector_FWD_DEFINED__
#define __IDWMInjector_FWD_DEFINED__
typedef interface IDWMInjector IDWMInjector;
#endif 	/* __IDWMInjector_FWD_DEFINED__ */


#ifndef __DWMEx_FWD_DEFINED__
#define __DWMEx_FWD_DEFINED__

#ifdef __cplusplus
typedef class DWMEx DWMEx;
#else
typedef struct DWMEx DWMEx;
#endif /* __cplusplus */

#endif 	/* __DWMEx_FWD_DEFINED__ */


#ifndef __DWMInjector_FWD_DEFINED__
#define __DWMInjector_FWD_DEFINED__

#ifdef __cplusplus
typedef class DWMInjector DWMInjector;
#else
typedef struct DWMInjector DWMInjector;
#endif /* __cplusplus */

#endif 	/* __DWMInjector_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 

void * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void * ); 

#ifndef __IDWMEx_INTERFACE_DEFINED__
#define __IDWMEx_INTERFACE_DEFINED__

/* interface IDWMEx */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDWMEx;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("9C797EE5-8465-4980-B028-4244CB7740B2")
    IDWMEx : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OpenConsole( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CloseConsole( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindowScale( 
            LONG hWnd,
            FLOAT ScaleX,
            FLOAT ScaleY) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindowOffset( 
            LONG hWnd,
            FLOAT X,
            FLOAT Y) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ExecuteBatch( 
            LONG batchId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BatchSetWindowMatrix( 
            LONG hWnd,
            FLOAT X,
            FLOAT Y,
            FLOAT SX,
            FLOAT SY,
            FLOAT RZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRenderOptions( 
            LONG hWnd,
            LONG *Options) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRenderOptions( 
            LONG hWnd,
            LONG Options) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetWindowMatrix( 
            LONG hWnd,
            FLOAT X,
            FLOAT Y,
            FLOAT SX,
            FLOAT SY,
            FLOAT RZ) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE LockRendering( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE UnlockRendering( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDWMExVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDWMEx * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDWMEx * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDWMEx * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDWMEx * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDWMEx * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDWMEx * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDWMEx * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *OpenConsole )( 
            IDWMEx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *CloseConsole )( 
            IDWMEx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindowScale )( 
            IDWMEx * This,
            LONG hWnd,
            FLOAT ScaleX,
            FLOAT ScaleY);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindowOffset )( 
            IDWMEx * This,
            LONG hWnd,
            FLOAT X,
            FLOAT Y);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *ExecuteBatch )( 
            IDWMEx * This,
            LONG batchId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *BatchSetWindowMatrix )( 
            IDWMEx * This,
            LONG hWnd,
            FLOAT X,
            FLOAT Y,
            FLOAT SX,
            FLOAT SY,
            FLOAT RZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetRenderOptions )( 
            IDWMEx * This,
            LONG hWnd,
            LONG *Options);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetRenderOptions )( 
            IDWMEx * This,
            LONG hWnd,
            LONG Options);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *SetWindowMatrix )( 
            IDWMEx * This,
            LONG hWnd,
            FLOAT X,
            FLOAT Y,
            FLOAT SX,
            FLOAT SY,
            FLOAT RZ);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *LockRendering )( 
            IDWMEx * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *UnlockRendering )( 
            IDWMEx * This);
        
        END_INTERFACE
    } IDWMExVtbl;

    interface IDWMEx
    {
        CONST_VTBL struct IDWMExVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDWMEx_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDWMEx_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDWMEx_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDWMEx_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDWMEx_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDWMEx_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDWMEx_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDWMEx_OpenConsole(This)	\
    (This)->lpVtbl -> OpenConsole(This)

#define IDWMEx_CloseConsole(This)	\
    (This)->lpVtbl -> CloseConsole(This)

#define IDWMEx_SetWindowScale(This,hWnd,ScaleX,ScaleY)	\
    (This)->lpVtbl -> SetWindowScale(This,hWnd,ScaleX,ScaleY)

#define IDWMEx_SetWindowOffset(This,hWnd,X,Y)	\
    (This)->lpVtbl -> SetWindowOffset(This,hWnd,X,Y)

#define IDWMEx_ExecuteBatch(This,batchId)	\
    (This)->lpVtbl -> ExecuteBatch(This,batchId)

#define IDWMEx_BatchSetWindowMatrix(This,hWnd,X,Y,SX,SY,RZ)	\
    (This)->lpVtbl -> BatchSetWindowMatrix(This,hWnd,X,Y,SX,SY,RZ)

#define IDWMEx_GetRenderOptions(This,hWnd,Options)	\
    (This)->lpVtbl -> GetRenderOptions(This,hWnd,Options)

#define IDWMEx_SetRenderOptions(This,hWnd,Options)	\
    (This)->lpVtbl -> SetRenderOptions(This,hWnd,Options)

#define IDWMEx_SetWindowMatrix(This,hWnd,X,Y,SX,SY,RZ)	\
    (This)->lpVtbl -> SetWindowMatrix(This,hWnd,X,Y,SX,SY,RZ)

#define IDWMEx_LockRendering(This)	\
    (This)->lpVtbl -> LockRendering(This)

#define IDWMEx_UnlockRendering(This)	\
    (This)->lpVtbl -> UnlockRendering(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_OpenConsole_Proxy( 
    IDWMEx * This);


void __RPC_STUB IDWMEx_OpenConsole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_CloseConsole_Proxy( 
    IDWMEx * This);


void __RPC_STUB IDWMEx_CloseConsole_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_SetWindowScale_Proxy( 
    IDWMEx * This,
    LONG hWnd,
    FLOAT ScaleX,
    FLOAT ScaleY);


void __RPC_STUB IDWMEx_SetWindowScale_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_SetWindowOffset_Proxy( 
    IDWMEx * This,
    LONG hWnd,
    FLOAT X,
    FLOAT Y);


void __RPC_STUB IDWMEx_SetWindowOffset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_ExecuteBatch_Proxy( 
    IDWMEx * This,
    LONG batchId);


void __RPC_STUB IDWMEx_ExecuteBatch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_BatchSetWindowMatrix_Proxy( 
    IDWMEx * This,
    LONG hWnd,
    FLOAT X,
    FLOAT Y,
    FLOAT SX,
    FLOAT SY,
    FLOAT RZ);


void __RPC_STUB IDWMEx_BatchSetWindowMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_GetRenderOptions_Proxy( 
    IDWMEx * This,
    LONG hWnd,
    LONG *Options);


void __RPC_STUB IDWMEx_GetRenderOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_SetRenderOptions_Proxy( 
    IDWMEx * This,
    LONG hWnd,
    LONG Options);


void __RPC_STUB IDWMEx_SetRenderOptions_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_SetWindowMatrix_Proxy( 
    IDWMEx * This,
    LONG hWnd,
    FLOAT X,
    FLOAT Y,
    FLOAT SX,
    FLOAT SY,
    FLOAT RZ);


void __RPC_STUB IDWMEx_SetWindowMatrix_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_LockRendering_Proxy( 
    IDWMEx * This);


void __RPC_STUB IDWMEx_LockRendering_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMEx_UnlockRendering_Proxy( 
    IDWMEx * This);


void __RPC_STUB IDWMEx_UnlockRendering_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDWMEx_INTERFACE_DEFINED__ */


#ifndef __IDWMInjector_INTERFACE_DEFINED__
#define __IDWMInjector_INTERFACE_DEFINED__

/* interface IDWMInjector */
/* [unique][helpstring][nonextensible][dual][uuid][object] */ 


EXTERN_C const IID IID_IDWMInjector;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CB3A50A3-0FF3-4582-96CF-F2EF08F6DBDA")
    IDWMInjector : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Inject( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDWMExObject( 
            /* [out] */ IDWMEx **dwmExOut) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IsInjected( 
            /* [retval][out] */ VARIANT_BOOL *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Unload( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IDWMInjectorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            IDWMInjector * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            IDWMInjector * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            IDWMInjector * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            IDWMInjector * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            IDWMInjector * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            IDWMInjector * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            IDWMInjector * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS *pDispParams,
            /* [out] */ VARIANT *pVarResult,
            /* [out] */ EXCEPINFO *pExcepInfo,
            /* [out] */ UINT *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Inject )( 
            IDWMInjector * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *GetDWMExObject )( 
            IDWMInjector * This,
            /* [out] */ IDWMEx **dwmExOut);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE *get_IsInjected )( 
            IDWMInjector * This,
            /* [retval][out] */ VARIANT_BOOL *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE *Unload )( 
            IDWMInjector * This);
        
        END_INTERFACE
    } IDWMInjectorVtbl;

    interface IDWMInjector
    {
        CONST_VTBL struct IDWMInjectorVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IDWMInjector_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IDWMInjector_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IDWMInjector_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IDWMInjector_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IDWMInjector_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IDWMInjector_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IDWMInjector_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IDWMInjector_Inject(This)	\
    (This)->lpVtbl -> Inject(This)

#define IDWMInjector_GetDWMExObject(This,dwmExOut)	\
    (This)->lpVtbl -> GetDWMExObject(This,dwmExOut)

#define IDWMInjector_get_IsInjected(This,pVal)	\
    (This)->lpVtbl -> get_IsInjected(This,pVal)

#define IDWMInjector_Unload(This)	\
    (This)->lpVtbl -> Unload(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMInjector_Inject_Proxy( 
    IDWMInjector * This);


void __RPC_STUB IDWMInjector_Inject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMInjector_GetDWMExObject_Proxy( 
    IDWMInjector * This,
    /* [out] */ IDWMEx **dwmExOut);


void __RPC_STUB IDWMInjector_GetDWMExObject_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IDWMInjector_get_IsInjected_Proxy( 
    IDWMInjector * This,
    /* [retval][out] */ VARIANT_BOOL *pVal);


void __RPC_STUB IDWMInjector_get_IsInjected_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IDWMInjector_Unload_Proxy( 
    IDWMInjector * This);


void __RPC_STUB IDWMInjector_Unload_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IDWMInjector_INTERFACE_DEFINED__ */



#ifndef __dwmaxxLib_LIBRARY_DEFINED__
#define __dwmaxxLib_LIBRARY_DEFINED__

/* library dwmaxxLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_dwmaxxLib;

EXTERN_C const CLSID CLSID_DWMEx;

#ifdef __cplusplus

class DECLSPEC_UUID("3B83AC72-FD69-456A-AF52-D09FA158BFFD")
DWMEx;
#endif

EXTERN_C const CLSID CLSID_DWMInjector;

#ifdef __cplusplus

class DECLSPEC_UUID("0A6807C4-1DE7-45D9-B1B3-4B6219FC27F4")
DWMInjector;
#endif
#endif /* __dwmaxxLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


