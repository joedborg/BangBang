/*** Autogenerated by WIDL 1.4.1 from ctxtcall.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __ctxtcall_h__
#define __ctxtcall_h__

/* Forward declarations */

#ifndef __IContextCallback_FWD_DEFINED__
#define __IContextCallback_FWD_DEFINED__
typedef interface IContextCallback IContextCallback;
#endif

/* Headers for imported files */

#include <wtypes.h>
#include <objidl.h>
#include <unknwn.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct tagComCallData {
    DWORD dwDispid;
    DWORD dwReserved;
    void *pUserDefined;
} ComCallData;
/*****************************************************************************
 * IContextCallback interface
 */
#ifndef __IContextCallback_INTERFACE_DEFINED__
#define __IContextCallback_INTERFACE_DEFINED__

typedef HRESULT (__stdcall *PFNCONTEXTCALL)(ComCallData *pParam);
DEFINE_GUID(IID_IContextCallback, 0x000001da, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("000001da-0000-0000-c000-000000000046")
IContextCallback : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE ContextCallback(
        HRESULT (__stdcall * pCallback)(ComCallData *pParam),
        ComCallData *pParam,
        REFIID riid,
        int iMethod,
        IUnknown *pUnk) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IContextCallback, 0x000001da, 0x0000, 0x0000, 0xc0,0x00, 0x00,0x00,0x00,0x00,0x00,0x46)
#endif
#else
typedef struct IContextCallbackVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IContextCallback* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IContextCallback* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IContextCallback* This);

    /*** IContextCallback methods ***/
    HRESULT (STDMETHODCALLTYPE *ContextCallback)(
        IContextCallback* This,
        HRESULT (__stdcall * pCallback)(ComCallData *pParam),
        ComCallData *pParam,
        REFIID riid,
        int iMethod,
        IUnknown *pUnk);

    END_INTERFACE
} IContextCallbackVtbl;
interface IContextCallback {
    CONST_VTBL IContextCallbackVtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define IContextCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IContextCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IContextCallback_Release(This) (This)->lpVtbl->Release(This)
/*** IContextCallback methods ***/
#define IContextCallback_ContextCallback(This,pCallback,pParam,riid,iMethod,pUnk) (This)->lpVtbl->ContextCallback(This,pCallback,pParam,riid,iMethod,pUnk)
#endif

#endif

HRESULT STDMETHODCALLTYPE IContextCallback_ContextCallback_Proxy(
    IContextCallback* This,
    HRESULT (__stdcall * pCallback)(ComCallData *pParam),
    ComCallData *pParam,
    REFIID riid,
    int iMethod,
    IUnknown *pUnk);
void __RPC_STUB IContextCallback_ContextCallback_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IContextCallback_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __ctxtcall_h__ */
