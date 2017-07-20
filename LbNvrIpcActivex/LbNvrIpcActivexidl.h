

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 8.01.0622 */
/* at Tue Jan 19 11:14:07 2038
 */
/* Compiler settings for LbNvrIpcActivex.idl:
    Oicf, W1, Zp8, env=Win32 (32b run), target_arch=X86 8.01.0622 
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
/* @@MIDL_FILE_HEADING(  ) */

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif /* __RPCNDR_H_VERSION__ */


#ifndef __LbNvrIpcActivexidl_h__
#define __LbNvrIpcActivexidl_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef ___DLbNvrIpcActivex_FWD_DEFINED__
#define ___DLbNvrIpcActivex_FWD_DEFINED__
typedef interface _DLbNvrIpcActivex _DLbNvrIpcActivex;

#endif 	/* ___DLbNvrIpcActivex_FWD_DEFINED__ */


#ifndef ___DLbNvrIpcActivexEvents_FWD_DEFINED__
#define ___DLbNvrIpcActivexEvents_FWD_DEFINED__
typedef interface _DLbNvrIpcActivexEvents _DLbNvrIpcActivexEvents;

#endif 	/* ___DLbNvrIpcActivexEvents_FWD_DEFINED__ */


#ifndef __LbNvrIpcActivex_FWD_DEFINED__
#define __LbNvrIpcActivex_FWD_DEFINED__

#ifdef __cplusplus
typedef class LbNvrIpcActivex LbNvrIpcActivex;
#else
typedef struct LbNvrIpcActivex LbNvrIpcActivex;
#endif /* __cplusplus */

#endif 	/* __LbNvrIpcActivex_FWD_DEFINED__ */


#ifdef __cplusplus
extern "C"{
#endif 


/* interface __MIDL_itf_LbNvrIpcActivex_0000_0000 */
/* [local] */ 

#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(push)
#pragma warning(disable:4001) 
#pragma once
#pragma warning(pop)
#pragma warning(pop)
#pragma region Desktop Family
#pragma endregion


extern RPC_IF_HANDLE __MIDL_itf_LbNvrIpcActivex_0000_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_LbNvrIpcActivex_0000_0000_v0_0_s_ifspec;


#ifndef __LbNvrIpcActivexLib_LIBRARY_DEFINED__
#define __LbNvrIpcActivexLib_LIBRARY_DEFINED__

/* library LbNvrIpcActivexLib */
/* [control][version][uuid] */ 


EXTERN_C const IID LIBID_LbNvrIpcActivexLib;

#ifndef ___DLbNvrIpcActivex_DISPINTERFACE_DEFINED__
#define ___DLbNvrIpcActivex_DISPINTERFACE_DEFINED__

/* dispinterface _DLbNvrIpcActivex */
/* [uuid] */ 


EXTERN_C const IID DIID__DLbNvrIpcActivex;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("A918B667-BDC0-4520-B635-AC17FB92C498")
    _DLbNvrIpcActivex : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DLbNvrIpcActivexVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DLbNvrIpcActivex * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DLbNvrIpcActivex * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DLbNvrIpcActivex * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DLbNvrIpcActivex * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DLbNvrIpcActivex * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DLbNvrIpcActivex * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DLbNvrIpcActivex * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DLbNvrIpcActivexVtbl;

    interface _DLbNvrIpcActivex
    {
        CONST_VTBL struct _DLbNvrIpcActivexVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DLbNvrIpcActivex_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DLbNvrIpcActivex_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DLbNvrIpcActivex_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DLbNvrIpcActivex_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DLbNvrIpcActivex_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DLbNvrIpcActivex_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DLbNvrIpcActivex_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DLbNvrIpcActivex_DISPINTERFACE_DEFINED__ */


#ifndef ___DLbNvrIpcActivexEvents_DISPINTERFACE_DEFINED__
#define ___DLbNvrIpcActivexEvents_DISPINTERFACE_DEFINED__

/* dispinterface _DLbNvrIpcActivexEvents */
/* [uuid] */ 


EXTERN_C const IID DIID__DLbNvrIpcActivexEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("00C2F5AD-67FF-4B20-9E97-CFAC6A8947D3")
    _DLbNvrIpcActivexEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _DLbNvrIpcActivexEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE *QueryInterface )( 
            _DLbNvrIpcActivexEvents * This,
            /* [in] */ REFIID riid,
            /* [annotation][iid_is][out] */ 
            _COM_Outptr_  void **ppvObject);
        
        ULONG ( STDMETHODCALLTYPE *AddRef )( 
            _DLbNvrIpcActivexEvents * This);
        
        ULONG ( STDMETHODCALLTYPE *Release )( 
            _DLbNvrIpcActivexEvents * This);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfoCount )( 
            _DLbNvrIpcActivexEvents * This,
            /* [out] */ UINT *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetTypeInfo )( 
            _DLbNvrIpcActivexEvents * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo **ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE *GetIDsOfNames )( 
            _DLbNvrIpcActivexEvents * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR *rgszNames,
            /* [range][in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE *Invoke )( 
            _DLbNvrIpcActivexEvents * This,
            /* [annotation][in] */ 
            _In_  DISPID dispIdMember,
            /* [annotation][in] */ 
            _In_  REFIID riid,
            /* [annotation][in] */ 
            _In_  LCID lcid,
            /* [annotation][in] */ 
            _In_  WORD wFlags,
            /* [annotation][out][in] */ 
            _In_  DISPPARAMS *pDispParams,
            /* [annotation][out] */ 
            _Out_opt_  VARIANT *pVarResult,
            /* [annotation][out] */ 
            _Out_opt_  EXCEPINFO *pExcepInfo,
            /* [annotation][out] */ 
            _Out_opt_  UINT *puArgErr);
        
        END_INTERFACE
    } _DLbNvrIpcActivexEventsVtbl;

    interface _DLbNvrIpcActivexEvents
    {
        CONST_VTBL struct _DLbNvrIpcActivexEventsVtbl *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _DLbNvrIpcActivexEvents_QueryInterface(This,riid,ppvObject)	\
    ( (This)->lpVtbl -> QueryInterface(This,riid,ppvObject) ) 

#define _DLbNvrIpcActivexEvents_AddRef(This)	\
    ( (This)->lpVtbl -> AddRef(This) ) 

#define _DLbNvrIpcActivexEvents_Release(This)	\
    ( (This)->lpVtbl -> Release(This) ) 


#define _DLbNvrIpcActivexEvents_GetTypeInfoCount(This,pctinfo)	\
    ( (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo) ) 

#define _DLbNvrIpcActivexEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    ( (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo) ) 

#define _DLbNvrIpcActivexEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    ( (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId) ) 

#define _DLbNvrIpcActivexEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    ( (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr) ) 

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___DLbNvrIpcActivexEvents_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_LbNvrIpcActivex;

#ifdef __cplusplus

class DECLSPEC_UUID("6F2D723E-6928-4E2C-92A2-F8135A496F65")
LbNvrIpcActivex;
#endif
#endif /* __LbNvrIpcActivexLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


