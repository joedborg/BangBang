/*** Autogenerated by WIDL 1.4.1 from wia_lh.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __wia_lh_h__
#define __wia_lh_h__

/* Forward declarations */

#ifndef __IWiaDevMgr_FWD_DEFINED__
#define __IWiaDevMgr_FWD_DEFINED__
typedef interface IWiaDevMgr IWiaDevMgr;
#endif

#ifndef __IEnumWIA_DEV_INFO_FWD_DEFINED__
#define __IEnumWIA_DEV_INFO_FWD_DEFINED__
typedef interface IEnumWIA_DEV_INFO IEnumWIA_DEV_INFO;
#endif

#ifndef __IWiaItem_FWD_DEFINED__
#define __IWiaItem_FWD_DEFINED__
typedef interface IWiaItem IWiaItem;
#endif

#ifndef __IWiaEventCallback_FWD_DEFINED__
#define __IWiaEventCallback_FWD_DEFINED__
typedef interface IWiaEventCallback IWiaEventCallback;
#endif

/* Headers for imported files */

#include <unknwn.h>
#include <oaidl.h>
#include <propidl.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef __IEnumWIA_DEV_INFO_FWD_DEFINED__
#define __IEnumWIA_DEV_INFO_FWD_DEFINED__
typedef interface IEnumWIA_DEV_INFO IEnumWIA_DEV_INFO;
#endif

#ifndef __IWiaItem_FWD_DEFINED__
#define __IWiaItem_FWD_DEFINED__
typedef interface IWiaItem IWiaItem;
#endif

#ifndef __IWiaEventCallback_FWD_DEFINED__
#define __IWiaEventCallback_FWD_DEFINED__
typedef interface IWiaEventCallback IWiaEventCallback;
#endif

DEFINE_GUID(CLSID_WiaDevMgr, 0xa1f4e726,0x8cf1,0x11d1,0xbf,0x92,0x00,0x60,0x08,0x1e,0xd8,0x11);
/*****************************************************************************
 * IWiaDevMgr interface
 */
#ifndef __IWiaDevMgr_INTERFACE_DEFINED__
#define __IWiaDevMgr_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWiaDevMgr, 0x5eb2502a, 0x8cf1, 0x11d1, 0xbf,0x92, 0x00,0x60,0x08,0x1e,0xd8,0x11);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("5eb2502a-8cf1-11d1-bf92-0060081ed811")
IWiaDevMgr : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE EnumDeviceInfo(
        LONG lFlag,
        IEnumWIA_DEV_INFO **ppIEnum) = 0;

    virtual HRESULT STDMETHODCALLTYPE CreateDevice(
        BSTR bstrDeviceID,
        IWiaItem **ppWiaItemRoot) = 0;

    virtual HRESULT STDMETHODCALLTYPE SelectDeviceDlg(
        HWND hwndParent,
        LONG lDeviceType,
        LONG lFlags,
        BSTR *pbstrDeviceID,
        IWiaItem **ppItemRoot) = 0;

    virtual HRESULT STDMETHODCALLTYPE SelectDeviceDlgID(
        HWND hwndParent,
        LONG lDeviceType,
        LONG lFlags,
        BSTR *pbstrDeviceID) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetImageDlg(
        HWND hwndParent,
        LONG lDeviceType,
        LONG lFlags,
        LONG lIntent,
        IWiaItem *pItemRoot,
        BSTR bstrFilename,
        GUID *pguidFormat) = 0;

    virtual HRESULT STDMETHODCALLTYPE RegisterEventCallbackProgram(
        LONG lFlags,
        BSTR bstrDeviceID,
        const GUID *pEventGUID,
        BSTR bstrCommandline,
        BSTR bstrName,
        BSTR bstrDescription,
        BSTR bstrIcon) = 0;

    virtual HRESULT STDMETHODCALLTYPE RegisterEventCallbackInterface(
        LONG lFlags,
        BSTR bstrDeviceID,
        const GUID *pEventGUID,
        IWiaEventCallback *pIWiaEventCallback,
        IUnknown **pEventObject) = 0;

    virtual HRESULT STDMETHODCALLTYPE RegisterEventCallbackCLSID(
        LONG lFlags,
        BSTR bstrDeviceID,
        const GUID *pEventGUID,
        const GUID *pClsID,
        BSTR bstrName,
        BSTR bstrDescription,
        BSTR bstrIcon) = 0;

    virtual HRESULT STDMETHODCALLTYPE AddDeviceDlg(
        HWND hwndParent,
        LONG lFlags) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWiaDevMgr, 0x5eb2502a, 0x8cf1, 0x11d1, 0xbf,0x92, 0x00,0x60,0x08,0x1e,0xd8,0x11)
#endif
#else
typedef struct IWiaDevMgrVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWiaDevMgr* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWiaDevMgr* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWiaDevMgr* This);

    /*** IWiaDevMgr methods ***/
    HRESULT (STDMETHODCALLTYPE *EnumDeviceInfo)(
        IWiaDevMgr* This,
        LONG lFlag,
        IEnumWIA_DEV_INFO **ppIEnum);

    HRESULT (STDMETHODCALLTYPE *CreateDevice)(
        IWiaDevMgr* This,
        BSTR bstrDeviceID,
        IWiaItem **ppWiaItemRoot);

    HRESULT (STDMETHODCALLTYPE *SelectDeviceDlg)(
        IWiaDevMgr* This,
        HWND hwndParent,
        LONG lDeviceType,
        LONG lFlags,
        BSTR *pbstrDeviceID,
        IWiaItem **ppItemRoot);

    HRESULT (STDMETHODCALLTYPE *SelectDeviceDlgID)(
        IWiaDevMgr* This,
        HWND hwndParent,
        LONG lDeviceType,
        LONG lFlags,
        BSTR *pbstrDeviceID);

    HRESULT (STDMETHODCALLTYPE *GetImageDlg)(
        IWiaDevMgr* This,
        HWND hwndParent,
        LONG lDeviceType,
        LONG lFlags,
        LONG lIntent,
        IWiaItem *pItemRoot,
        BSTR bstrFilename,
        GUID *pguidFormat);

    HRESULT (STDMETHODCALLTYPE *RegisterEventCallbackProgram)(
        IWiaDevMgr* This,
        LONG lFlags,
        BSTR bstrDeviceID,
        const GUID *pEventGUID,
        BSTR bstrCommandline,
        BSTR bstrName,
        BSTR bstrDescription,
        BSTR bstrIcon);

    HRESULT (STDMETHODCALLTYPE *RegisterEventCallbackInterface)(
        IWiaDevMgr* This,
        LONG lFlags,
        BSTR bstrDeviceID,
        const GUID *pEventGUID,
        IWiaEventCallback *pIWiaEventCallback,
        IUnknown **pEventObject);

    HRESULT (STDMETHODCALLTYPE *RegisterEventCallbackCLSID)(
        IWiaDevMgr* This,
        LONG lFlags,
        BSTR bstrDeviceID,
        const GUID *pEventGUID,
        const GUID *pClsID,
        BSTR bstrName,
        BSTR bstrDescription,
        BSTR bstrIcon);

    HRESULT (STDMETHODCALLTYPE *AddDeviceDlg)(
        IWiaDevMgr* This,
        HWND hwndParent,
        LONG lFlags);

    END_INTERFACE
} IWiaDevMgrVtbl;
interface IWiaDevMgr {
    CONST_VTBL IWiaDevMgrVtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define IWiaDevMgr_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWiaDevMgr_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWiaDevMgr_Release(This) (This)->lpVtbl->Release(This)
/*** IWiaDevMgr methods ***/
#define IWiaDevMgr_EnumDeviceInfo(This,lFlag,ppIEnum) (This)->lpVtbl->EnumDeviceInfo(This,lFlag,ppIEnum)
#define IWiaDevMgr_CreateDevice(This,bstrDeviceID,ppWiaItemRoot) (This)->lpVtbl->CreateDevice(This,bstrDeviceID,ppWiaItemRoot)
#define IWiaDevMgr_SelectDeviceDlg(This,hwndParent,lDeviceType,lFlags,pbstrDeviceID,ppItemRoot) (This)->lpVtbl->SelectDeviceDlg(This,hwndParent,lDeviceType,lFlags,pbstrDeviceID,ppItemRoot)
#define IWiaDevMgr_SelectDeviceDlgID(This,hwndParent,lDeviceType,lFlags,pbstrDeviceID) (This)->lpVtbl->SelectDeviceDlgID(This,hwndParent,lDeviceType,lFlags,pbstrDeviceID)
#define IWiaDevMgr_GetImageDlg(This,hwndParent,lDeviceType,lFlags,lIntent,pItemRoot,bstrFilename,pguidFormat) (This)->lpVtbl->GetImageDlg(This,hwndParent,lDeviceType,lFlags,lIntent,pItemRoot,bstrFilename,pguidFormat)
#define IWiaDevMgr_RegisterEventCallbackProgram(This,lFlags,bstrDeviceID,pEventGUID,bstrCommandline,bstrName,bstrDescription,bstrIcon) (This)->lpVtbl->RegisterEventCallbackProgram(This,lFlags,bstrDeviceID,pEventGUID,bstrCommandline,bstrName,bstrDescription,bstrIcon)
#define IWiaDevMgr_RegisterEventCallbackInterface(This,lFlags,bstrDeviceID,pEventGUID,pIWiaEventCallback,pEventObject) (This)->lpVtbl->RegisterEventCallbackInterface(This,lFlags,bstrDeviceID,pEventGUID,pIWiaEventCallback,pEventObject)
#define IWiaDevMgr_RegisterEventCallbackCLSID(This,lFlags,bstrDeviceID,pEventGUID,pClsID,bstrName,bstrDescription,bstrIcon) (This)->lpVtbl->RegisterEventCallbackCLSID(This,lFlags,bstrDeviceID,pEventGUID,pClsID,bstrName,bstrDescription,bstrIcon)
#define IWiaDevMgr_AddDeviceDlg(This,hwndParent,lFlags) (This)->lpVtbl->AddDeviceDlg(This,hwndParent,lFlags)
#endif

#endif

HRESULT STDMETHODCALLTYPE IWiaDevMgr_EnumDeviceInfo_Proxy(
    IWiaDevMgr* This,
    LONG lFlag,
    IEnumWIA_DEV_INFO **ppIEnum);
void __RPC_STUB IWiaDevMgr_EnumDeviceInfo_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IWiaDevMgr_CreateDevice_Proxy(
    IWiaDevMgr* This,
    BSTR bstrDeviceID,
    IWiaItem **ppWiaItemRoot);
void __RPC_STUB IWiaDevMgr_CreateDevice_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IWiaDevMgr_SelectDeviceDlg_Proxy(
    IWiaDevMgr* This,
    HWND hwndParent,
    LONG lDeviceType,
    LONG lFlags,
    BSTR *pbstrDeviceID,
    IWiaItem **ppItemRoot);
void __RPC_STUB IWiaDevMgr_SelectDeviceDlg_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IWiaDevMgr_SelectDeviceDlgID_Proxy(
    IWiaDevMgr* This,
    HWND hwndParent,
    LONG lDeviceType,
    LONG lFlags,
    BSTR *pbstrDeviceID);
void __RPC_STUB IWiaDevMgr_SelectDeviceDlgID_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IWiaDevMgr_GetImageDlg_Proxy(
    IWiaDevMgr* This,
    HWND hwndParent,
    LONG lDeviceType,
    LONG lFlags,
    LONG lIntent,
    IWiaItem *pItemRoot,
    BSTR bstrFilename,
    GUID *pguidFormat);
void __RPC_STUB IWiaDevMgr_GetImageDlg_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IWiaDevMgr_RegisterEventCallbackProgram_Proxy(
    IWiaDevMgr* This,
    LONG lFlags,
    BSTR bstrDeviceID,
    const GUID *pEventGUID,
    BSTR bstrCommandline,
    BSTR bstrName,
    BSTR bstrDescription,
    BSTR bstrIcon);
void __RPC_STUB IWiaDevMgr_RegisterEventCallbackProgram_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IWiaDevMgr_RegisterEventCallbackInterface_Proxy(
    IWiaDevMgr* This,
    LONG lFlags,
    BSTR bstrDeviceID,
    const GUID *pEventGUID,
    IWiaEventCallback *pIWiaEventCallback,
    IUnknown **pEventObject);
void __RPC_STUB IWiaDevMgr_RegisterEventCallbackInterface_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IWiaDevMgr_RegisterEventCallbackCLSID_Proxy(
    IWiaDevMgr* This,
    LONG lFlags,
    BSTR bstrDeviceID,
    const GUID *pEventGUID,
    const GUID *pClsID,
    BSTR bstrName,
    BSTR bstrDescription,
    BSTR bstrIcon);
void __RPC_STUB IWiaDevMgr_RegisterEventCallbackCLSID_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IWiaDevMgr_AddDeviceDlg_Proxy(
    IWiaDevMgr* This,
    HWND hwndParent,
    LONG lFlags);
void __RPC_STUB IWiaDevMgr_AddDeviceDlg_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IWiaDevMgr_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IEnumWIA_DEV_INFO interface
 */
#ifndef __IEnumWIA_DEV_INFO_INTERFACE_DEFINED__
#define __IEnumWIA_DEV_INFO_INTERFACE_DEFINED__

DEFINE_GUID(IID_IEnumWIA_DEV_INFO, 0x5e38b83c, 0x8cf1, 0x11d1, 0xbf,0x92, 0x00,0x60,0x08,0x1e,0xd8,0x11);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("5e38b83c-8cf1-11d1-bf92-0060081ed811")
IEnumWIA_DEV_INFO : public IUnknown
{
};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IEnumWIA_DEV_INFO, 0x5e38b83c, 0x8cf1, 0x11d1, 0xbf,0x92, 0x00,0x60,0x08,0x1e,0xd8,0x11)
#endif
#else
typedef struct IEnumWIA_DEV_INFOVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IEnumWIA_DEV_INFO* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IEnumWIA_DEV_INFO* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IEnumWIA_DEV_INFO* This);

    END_INTERFACE
} IEnumWIA_DEV_INFOVtbl;
interface IEnumWIA_DEV_INFO {
    CONST_VTBL IEnumWIA_DEV_INFOVtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define IEnumWIA_DEV_INFO_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IEnumWIA_DEV_INFO_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IEnumWIA_DEV_INFO_Release(This) (This)->lpVtbl->Release(This)
#endif

#endif


#endif  /* __IEnumWIA_DEV_INFO_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IWiaItem interface
 */
#ifndef __IWiaItem_INTERFACE_DEFINED__
#define __IWiaItem_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWiaItem, 0x4db1ad10, 0x3391, 0x11d2, 0x9a,0x33, 0x00,0xc0,0x4f,0xa3,0x61,0x45);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("4db1ad10-3391-11d2-9a33-00c04fa36145")
IWiaItem : public IUnknown
{
};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWiaItem, 0x4db1ad10, 0x3391, 0x11d2, 0x9a,0x33, 0x00,0xc0,0x4f,0xa3,0x61,0x45)
#endif
#else
typedef struct IWiaItemVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWiaItem* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWiaItem* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWiaItem* This);

    END_INTERFACE
} IWiaItemVtbl;
interface IWiaItem {
    CONST_VTBL IWiaItemVtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define IWiaItem_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWiaItem_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWiaItem_Release(This) (This)->lpVtbl->Release(This)
#endif

#endif


#endif  /* __IWiaItem_INTERFACE_DEFINED__ */

/*****************************************************************************
 * IWiaEventCallback interface
 */
#ifndef __IWiaEventCallback_INTERFACE_DEFINED__
#define __IWiaEventCallback_INTERFACE_DEFINED__

DEFINE_GUID(IID_IWiaEventCallback, 0xae6287b0, 0x0084, 0x11d2, 0x97,0x3b, 0x00,0xa0,0xc9,0x06,0x8f,0x2e);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("ae6287b0-0084-11d2-973b-00a0c9068f2e")
IWiaEventCallback : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE ImageEventCallback(
        const GUID *pEventGUID,
        BSTR bstrEventDescription,
        BSTR bstrDeviceID,
        BSTR bstrDeviceDescription,
        DWORD dwDeviceType,
        BSTR bstrFullItemName,
        ULONG *pulEventType,
        ULONG ulReserved) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IWiaEventCallback, 0xae6287b0, 0x0084, 0x11d2, 0x97,0x3b, 0x00,0xa0,0xc9,0x06,0x8f,0x2e)
#endif
#else
typedef struct IWiaEventCallbackVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IWiaEventCallback* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IWiaEventCallback* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IWiaEventCallback* This);

    /*** IWiaEventCallback methods ***/
    HRESULT (STDMETHODCALLTYPE *ImageEventCallback)(
        IWiaEventCallback* This,
        const GUID *pEventGUID,
        BSTR bstrEventDescription,
        BSTR bstrDeviceID,
        BSTR bstrDeviceDescription,
        DWORD dwDeviceType,
        BSTR bstrFullItemName,
        ULONG *pulEventType,
        ULONG ulReserved);

    END_INTERFACE
} IWiaEventCallbackVtbl;
interface IWiaEventCallback {
    CONST_VTBL IWiaEventCallbackVtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define IWiaEventCallback_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IWiaEventCallback_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IWiaEventCallback_Release(This) (This)->lpVtbl->Release(This)
/*** IWiaEventCallback methods ***/
#define IWiaEventCallback_ImageEventCallback(This,pEventGUID,bstrEventDescription,bstrDeviceID,bstrDeviceDescription,dwDeviceType,bstrFullItemName,pulEventType,ulReserved) (This)->lpVtbl->ImageEventCallback(This,pEventGUID,bstrEventDescription,bstrDeviceID,bstrDeviceDescription,dwDeviceType,bstrFullItemName,pulEventType,ulReserved)
#endif

#endif

HRESULT STDMETHODCALLTYPE IWiaEventCallback_ImageEventCallback_Proxy(
    IWiaEventCallback* This,
    const GUID *pEventGUID,
    BSTR bstrEventDescription,
    BSTR bstrDeviceID,
    BSTR bstrDeviceDescription,
    DWORD dwDeviceType,
    BSTR bstrFullItemName,
    ULONG *pulEventType,
    ULONG ulReserved);
void __RPC_STUB IWiaEventCallback_ImageEventCallback_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IWiaEventCallback_INTERFACE_DEFINED__ */

/* Begin additional prototypes for all interfaces */

ULONG           __RPC_USER BSTR_UserSize     (ULONG *, ULONG, BSTR *);
unsigned char * __RPC_USER BSTR_UserMarshal  (ULONG *, unsigned char *, BSTR *);
unsigned char * __RPC_USER BSTR_UserUnmarshal(ULONG *, unsigned char *, BSTR *);
void            __RPC_USER BSTR_UserFree     (ULONG *, BSTR *);
ULONG           __RPC_USER HWND_UserSize     (ULONG *, ULONG, HWND *);
unsigned char * __RPC_USER HWND_UserMarshal  (ULONG *, unsigned char *, HWND *);
unsigned char * __RPC_USER HWND_UserUnmarshal(ULONG *, unsigned char *, HWND *);
void            __RPC_USER HWND_UserFree     (ULONG *, HWND *);

/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __wia_lh_h__ */
