/*** Autogenerated by WIDL 1.4.1 from perhist.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __perhist_h__
#define __perhist_h__

/* Forward declarations */

#ifndef __IPersistHistory_FWD_DEFINED__
#define __IPersistHistory_FWD_DEFINED__
typedef interface IPersistHistory IPersistHistory;
#endif

/* Headers for imported files */

#include <objidl.h>
#include <oleidl.h>

#ifdef __cplusplus
extern "C" {
#endif

/*****************************************************************************
 * IPersistHistory interface
 */
#ifndef __IPersistHistory_INTERFACE_DEFINED__
#define __IPersistHistory_INTERFACE_DEFINED__

typedef IPersistHistory *LPPERSISTHISTORY;
DEFINE_GUID(IID_IPersistHistory, 0x91a565c1, 0xe38f, 0x11d0, 0x94,0xbf, 0x00,0xa0,0xc9,0x05,0x5c,0xbf);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("91a565c1-e38f-11d0-94bf-00a0c9055cbf")
IPersistHistory : public IPersist
{
    virtual HRESULT STDMETHODCALLTYPE LoadHistory(
        IStream *pStream,
        IBindCtx *pbc) = 0;

    virtual HRESULT STDMETHODCALLTYPE SaveHistory(
        IStream *pStream) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetPositionCookie(
        DWORD dwPositioncookie) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetPositionCookie(
        DWORD *pdwPositioncookie) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IPersistHistory, 0x91a565c1, 0xe38f, 0x11d0, 0x94,0xbf, 0x00,0xa0,0xc9,0x05,0x5c,0xbf)
#endif
#else
typedef struct IPersistHistoryVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IPersistHistory* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IPersistHistory* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IPersistHistory* This);

    /*** IPersist methods ***/
    HRESULT (STDMETHODCALLTYPE *GetClassID)(
        IPersistHistory* This,
        CLSID *pClassID);

    /*** IPersistHistory methods ***/
    HRESULT (STDMETHODCALLTYPE *LoadHistory)(
        IPersistHistory* This,
        IStream *pStream,
        IBindCtx *pbc);

    HRESULT (STDMETHODCALLTYPE *SaveHistory)(
        IPersistHistory* This,
        IStream *pStream);

    HRESULT (STDMETHODCALLTYPE *SetPositionCookie)(
        IPersistHistory* This,
        DWORD dwPositioncookie);

    HRESULT (STDMETHODCALLTYPE *GetPositionCookie)(
        IPersistHistory* This,
        DWORD *pdwPositioncookie);

    END_INTERFACE
} IPersistHistoryVtbl;
interface IPersistHistory {
    CONST_VTBL IPersistHistoryVtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define IPersistHistory_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IPersistHistory_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IPersistHistory_Release(This) (This)->lpVtbl->Release(This)
/*** IPersist methods ***/
#define IPersistHistory_GetClassID(This,pClassID) (This)->lpVtbl->GetClassID(This,pClassID)
/*** IPersistHistory methods ***/
#define IPersistHistory_LoadHistory(This,pStream,pbc) (This)->lpVtbl->LoadHistory(This,pStream,pbc)
#define IPersistHistory_SaveHistory(This,pStream) (This)->lpVtbl->SaveHistory(This,pStream)
#define IPersistHistory_SetPositionCookie(This,dwPositioncookie) (This)->lpVtbl->SetPositionCookie(This,dwPositioncookie)
#define IPersistHistory_GetPositionCookie(This,pdwPositioncookie) (This)->lpVtbl->GetPositionCookie(This,pdwPositioncookie)
#endif

#endif

HRESULT STDMETHODCALLTYPE IPersistHistory_LoadHistory_Proxy(
    IPersistHistory* This,
    IStream *pStream,
    IBindCtx *pbc);
void __RPC_STUB IPersistHistory_LoadHistory_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IPersistHistory_SaveHistory_Proxy(
    IPersistHistory* This,
    IStream *pStream);
void __RPC_STUB IPersistHistory_SaveHistory_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IPersistHistory_SetPositionCookie_Proxy(
    IPersistHistory* This,
    DWORD dwPositioncookie);
void __RPC_STUB IPersistHistory_SetPositionCookie_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IPersistHistory_GetPositionCookie_Proxy(
    IPersistHistory* This,
    DWORD *pdwPositioncookie);
void __RPC_STUB IPersistHistory_GetPositionCookie_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IPersistHistory_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __perhist_h__ */
