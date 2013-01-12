/*** Autogenerated by WIDL 1.4.1 from commoncontrols.idl - Do not edit ***/

#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include <rpc.h>
#include <rpcndr.h>

#ifndef COM_NO_WINDOWS_H
#include <windows.h>
#include <ole2.h>
#endif

#ifndef __commoncontrols_h__
#define __commoncontrols_h__

/* Forward declarations */

#ifndef __IImageList_FWD_DEFINED__
#define __IImageList_FWD_DEFINED__
typedef interface IImageList IImageList;
#endif

#ifndef __ImageList_FWD_DEFINED__
#define __ImageList_FWD_DEFINED__
typedef struct ImageList ImageList;
#endif /* defined __ImageList_FWD_DEFINED__ */

/* Headers for imported files */

#include <oaidl.h>
#include <ocidl.h>

#ifdef __cplusplus
extern "C" {
#endif

#if 0
typedef DWORD RGBQUAD;
typedef IUnknown *HIMAGELIST;
typedef struct __WIDL_commoncontrols_generated_name_00000000 {
    HBITMAP hbmImage;
    HBITMAP hbmMask;
    int Unused1;
    int Unused2;
    RECT rcImage;
} IMAGEINFO;
typedef IMAGEINFO *LPIMAGEINFO;
typedef struct __WIDL_commoncontrols_generated_name_00000001 {
    DWORD cbSize;
    HIMAGELIST himl;
    int i;
    HDC hdcDst;
    int x;
    int y;
    int cx;
    int cy;
    int xBitmap;
    int yBitmap;
    COLORREF rgbBk;
    COLORREF rgbFg;
    UINT fStyle;
    DWORD dwRop;
    DWORD fState;
    DWORD Frame;
    COLORREF crEffect;
} IMAGELISTDRAWPARAMS;
typedef IMAGELISTDRAWPARAMS *LPIMAGELISTDRAWPARAMS;
#endif
HRESULT WINAPI ImageList_CoCreateInstance(REFCLSID,const IUnknown *, REFIID,void **);
#define ILIF_ALPHA (1)

/*****************************************************************************
 * IImageList interface
 */
#ifndef __IImageList_INTERFACE_DEFINED__
#define __IImageList_INTERFACE_DEFINED__

DEFINE_GUID(IID_IImageList, 0x46eb5926, 0x582e, 0x4017, 0x9f,0xdf, 0xe8,0x99,0x8d,0xaa,0x09,0x50);
#if defined(__cplusplus) && !defined(CINTERFACE)
MIDL_INTERFACE("46eb5926-582e-4017-9fdf-e8998daa0950")
IImageList : public IUnknown
{
    virtual HRESULT STDMETHODCALLTYPE Add(
        HBITMAP hbmImage,
        HBITMAP hbmMask,
        int *pi) = 0;

    virtual HRESULT STDMETHODCALLTYPE ReplaceIcon(
        int i,
        HICON hicon,
        int *pi) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetOverlayImage(
        int iImage,
        int iOverlay) = 0;

    virtual HRESULT STDMETHODCALLTYPE Replace(
        int i,
        HBITMAP hbmImage,
        HBITMAP hbmMask) = 0;

    virtual HRESULT STDMETHODCALLTYPE AddMasked(
        HBITMAP hbmImage,
        COLORREF crMask,
        int *pi) = 0;

    virtual HRESULT STDMETHODCALLTYPE Draw(
        IMAGELISTDRAWPARAMS *pimldp) = 0;

    virtual HRESULT STDMETHODCALLTYPE Remove(
        int i) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetIcon(
        int i,
        UINT flags,
        HICON *picon) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetImageInfo(
        int i,
        IMAGEINFO *pImageInfo) = 0;

    virtual HRESULT STDMETHODCALLTYPE Copy(
        int iDst,
        IUnknown *punkSrc,
        int iSrc,
        UINT uFlags) = 0;

    virtual HRESULT STDMETHODCALLTYPE Merge(
        int i1,
        IUnknown *punk2,
        int i2,
        int dx,
        int dy,
        REFIID riid,
        PVOID *ppv) = 0;

    virtual HRESULT STDMETHODCALLTYPE Clone(
        REFIID riid,
        PVOID *ppv) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetImageRect(
        int i,
        RECT *prc) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetIconSize(
        int *cx,
        int *cy) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetIconSize(
        int cx,
        int cy) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetImageCount(
        int *pi) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetImageCount(
        UINT uNewCount) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetBkColor(
        COLORREF clrBk,
        COLORREF *pclr) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetBkColor(
        COLORREF *pclr) = 0;

    virtual HRESULT STDMETHODCALLTYPE BeginDrag(
        int iTrack,
        int dxHotspot,
        int dyHotspot) = 0;

    virtual HRESULT STDMETHODCALLTYPE EndDrag(
        ) = 0;

    virtual HRESULT STDMETHODCALLTYPE DragEnter(
        HWND hwndLock,
        int x,
        int y) = 0;

    virtual HRESULT STDMETHODCALLTYPE DragLeave(
        HWND hwndLock) = 0;

    virtual HRESULT STDMETHODCALLTYPE DragMove(
        int x,
        int y) = 0;

    virtual HRESULT STDMETHODCALLTYPE SetDragCursorImage(
        IUnknown *punk,
        int iDrag,
        int dxHotspot,
        int dyHotspot) = 0;

    virtual HRESULT STDMETHODCALLTYPE DragShowNolock(
        BOOL fShow) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetDragImage(
        POINT *ppt,
        POINT *pptHotspot,
        REFIID riid,
        PVOID *ppv) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetItemFlags(
        int i,
        DWORD *dwFlags) = 0;

    virtual HRESULT STDMETHODCALLTYPE GetOverlayImage(
        int iOverlay,
        int *piIndex) = 0;

};
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(IImageList, 0x46eb5926, 0x582e, 0x4017, 0x9f,0xdf, 0xe8,0x99,0x8d,0xaa,0x09,0x50)
#endif
#else
typedef struct IImageListVtbl {
    BEGIN_INTERFACE

    /*** IUnknown methods ***/
    HRESULT (STDMETHODCALLTYPE *QueryInterface)(
        IImageList* This,
        REFIID riid,
        void **ppvObject);

    ULONG (STDMETHODCALLTYPE *AddRef)(
        IImageList* This);

    ULONG (STDMETHODCALLTYPE *Release)(
        IImageList* This);

    /*** IImageList methods ***/
    HRESULT (STDMETHODCALLTYPE *Add)(
        IImageList* This,
        HBITMAP hbmImage,
        HBITMAP hbmMask,
        int *pi);

    HRESULT (STDMETHODCALLTYPE *ReplaceIcon)(
        IImageList* This,
        int i,
        HICON hicon,
        int *pi);

    HRESULT (STDMETHODCALLTYPE *SetOverlayImage)(
        IImageList* This,
        int iImage,
        int iOverlay);

    HRESULT (STDMETHODCALLTYPE *Replace)(
        IImageList* This,
        int i,
        HBITMAP hbmImage,
        HBITMAP hbmMask);

    HRESULT (STDMETHODCALLTYPE *AddMasked)(
        IImageList* This,
        HBITMAP hbmImage,
        COLORREF crMask,
        int *pi);

    HRESULT (STDMETHODCALLTYPE *Draw)(
        IImageList* This,
        IMAGELISTDRAWPARAMS *pimldp);

    HRESULT (STDMETHODCALLTYPE *Remove)(
        IImageList* This,
        int i);

    HRESULT (STDMETHODCALLTYPE *GetIcon)(
        IImageList* This,
        int i,
        UINT flags,
        HICON *picon);

    HRESULT (STDMETHODCALLTYPE *GetImageInfo)(
        IImageList* This,
        int i,
        IMAGEINFO *pImageInfo);

    HRESULT (STDMETHODCALLTYPE *Copy)(
        IImageList* This,
        int iDst,
        IUnknown *punkSrc,
        int iSrc,
        UINT uFlags);

    HRESULT (STDMETHODCALLTYPE *Merge)(
        IImageList* This,
        int i1,
        IUnknown *punk2,
        int i2,
        int dx,
        int dy,
        REFIID riid,
        PVOID *ppv);

    HRESULT (STDMETHODCALLTYPE *Clone)(
        IImageList* This,
        REFIID riid,
        PVOID *ppv);

    HRESULT (STDMETHODCALLTYPE *GetImageRect)(
        IImageList* This,
        int i,
        RECT *prc);

    HRESULT (STDMETHODCALLTYPE *GetIconSize)(
        IImageList* This,
        int *cx,
        int *cy);

    HRESULT (STDMETHODCALLTYPE *SetIconSize)(
        IImageList* This,
        int cx,
        int cy);

    HRESULT (STDMETHODCALLTYPE *GetImageCount)(
        IImageList* This,
        int *pi);

    HRESULT (STDMETHODCALLTYPE *SetImageCount)(
        IImageList* This,
        UINT uNewCount);

    HRESULT (STDMETHODCALLTYPE *SetBkColor)(
        IImageList* This,
        COLORREF clrBk,
        COLORREF *pclr);

    HRESULT (STDMETHODCALLTYPE *GetBkColor)(
        IImageList* This,
        COLORREF *pclr);

    HRESULT (STDMETHODCALLTYPE *BeginDrag)(
        IImageList* This,
        int iTrack,
        int dxHotspot,
        int dyHotspot);

    HRESULT (STDMETHODCALLTYPE *EndDrag)(
        IImageList* This);

    HRESULT (STDMETHODCALLTYPE *DragEnter)(
        IImageList* This,
        HWND hwndLock,
        int x,
        int y);

    HRESULT (STDMETHODCALLTYPE *DragLeave)(
        IImageList* This,
        HWND hwndLock);

    HRESULT (STDMETHODCALLTYPE *DragMove)(
        IImageList* This,
        int x,
        int y);

    HRESULT (STDMETHODCALLTYPE *SetDragCursorImage)(
        IImageList* This,
        IUnknown *punk,
        int iDrag,
        int dxHotspot,
        int dyHotspot);

    HRESULT (STDMETHODCALLTYPE *DragShowNolock)(
        IImageList* This,
        BOOL fShow);

    HRESULT (STDMETHODCALLTYPE *GetDragImage)(
        IImageList* This,
        POINT *ppt,
        POINT *pptHotspot,
        REFIID riid,
        PVOID *ppv);

    HRESULT (STDMETHODCALLTYPE *GetItemFlags)(
        IImageList* This,
        int i,
        DWORD *dwFlags);

    HRESULT (STDMETHODCALLTYPE *GetOverlayImage)(
        IImageList* This,
        int iOverlay,
        int *piIndex);

    END_INTERFACE
} IImageListVtbl;
interface IImageList {
    CONST_VTBL IImageListVtbl* lpVtbl;
};

#ifdef COBJMACROS
/*** IUnknown methods ***/
#define IImageList_QueryInterface(This,riid,ppvObject) (This)->lpVtbl->QueryInterface(This,riid,ppvObject)
#define IImageList_AddRef(This) (This)->lpVtbl->AddRef(This)
#define IImageList_Release(This) (This)->lpVtbl->Release(This)
/*** IImageList methods ***/
#define IImageList_Add(This,hbmImage,hbmMask,pi) (This)->lpVtbl->Add(This,hbmImage,hbmMask,pi)
#define IImageList_ReplaceIcon(This,i,hicon,pi) (This)->lpVtbl->ReplaceIcon(This,i,hicon,pi)
#define IImageList_SetOverlayImage(This,iImage,iOverlay) (This)->lpVtbl->SetOverlayImage(This,iImage,iOverlay)
#define IImageList_Replace(This,i,hbmImage,hbmMask) (This)->lpVtbl->Replace(This,i,hbmImage,hbmMask)
#define IImageList_AddMasked(This,hbmImage,crMask,pi) (This)->lpVtbl->AddMasked(This,hbmImage,crMask,pi)
#define IImageList_Draw(This,pimldp) (This)->lpVtbl->Draw(This,pimldp)
#define IImageList_Remove(This,i) (This)->lpVtbl->Remove(This,i)
#define IImageList_GetIcon(This,i,flags,picon) (This)->lpVtbl->GetIcon(This,i,flags,picon)
#define IImageList_GetImageInfo(This,i,pImageInfo) (This)->lpVtbl->GetImageInfo(This,i,pImageInfo)
#define IImageList_Copy(This,iDst,punkSrc,iSrc,uFlags) (This)->lpVtbl->Copy(This,iDst,punkSrc,iSrc,uFlags)
#define IImageList_Merge(This,i1,punk2,i2,dx,dy,riid,ppv) (This)->lpVtbl->Merge(This,i1,punk2,i2,dx,dy,riid,ppv)
#define IImageList_Clone(This,riid,ppv) (This)->lpVtbl->Clone(This,riid,ppv)
#define IImageList_GetImageRect(This,i,prc) (This)->lpVtbl->GetImageRect(This,i,prc)
#define IImageList_GetIconSize(This,cx,cy) (This)->lpVtbl->GetIconSize(This,cx,cy)
#define IImageList_SetIconSize(This,cx,cy) (This)->lpVtbl->SetIconSize(This,cx,cy)
#define IImageList_GetImageCount(This,pi) (This)->lpVtbl->GetImageCount(This,pi)
#define IImageList_SetImageCount(This,uNewCount) (This)->lpVtbl->SetImageCount(This,uNewCount)
#define IImageList_SetBkColor(This,clrBk,pclr) (This)->lpVtbl->SetBkColor(This,clrBk,pclr)
#define IImageList_GetBkColor(This,pclr) (This)->lpVtbl->GetBkColor(This,pclr)
#define IImageList_BeginDrag(This,iTrack,dxHotspot,dyHotspot) (This)->lpVtbl->BeginDrag(This,iTrack,dxHotspot,dyHotspot)
#define IImageList_EndDrag(This) (This)->lpVtbl->EndDrag(This)
#define IImageList_DragEnter(This,hwndLock,x,y) (This)->lpVtbl->DragEnter(This,hwndLock,x,y)
#define IImageList_DragLeave(This,hwndLock) (This)->lpVtbl->DragLeave(This,hwndLock)
#define IImageList_DragMove(This,x,y) (This)->lpVtbl->DragMove(This,x,y)
#define IImageList_SetDragCursorImage(This,punk,iDrag,dxHotspot,dyHotspot) (This)->lpVtbl->SetDragCursorImage(This,punk,iDrag,dxHotspot,dyHotspot)
#define IImageList_DragShowNolock(This,fShow) (This)->lpVtbl->DragShowNolock(This,fShow)
#define IImageList_GetDragImage(This,ppt,pptHotspot,riid,ppv) (This)->lpVtbl->GetDragImage(This,ppt,pptHotspot,riid,ppv)
#define IImageList_GetItemFlags(This,i,dwFlags) (This)->lpVtbl->GetItemFlags(This,i,dwFlags)
#define IImageList_GetOverlayImage(This,iOverlay,piIndex) (This)->lpVtbl->GetOverlayImage(This,iOverlay,piIndex)
#endif

#endif

HRESULT STDMETHODCALLTYPE IImageList_Add_Proxy(
    IImageList* This,
    HBITMAP hbmImage,
    HBITMAP hbmMask,
    int *pi);
void __RPC_STUB IImageList_Add_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_ReplaceIcon_Proxy(
    IImageList* This,
    int i,
    HICON hicon,
    int *pi);
void __RPC_STUB IImageList_ReplaceIcon_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_SetOverlayImage_Proxy(
    IImageList* This,
    int iImage,
    int iOverlay);
void __RPC_STUB IImageList_SetOverlayImage_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_Replace_Proxy(
    IImageList* This,
    int i,
    HBITMAP hbmImage,
    HBITMAP hbmMask);
void __RPC_STUB IImageList_Replace_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_AddMasked_Proxy(
    IImageList* This,
    HBITMAP hbmImage,
    COLORREF crMask,
    int *pi);
void __RPC_STUB IImageList_AddMasked_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_Draw_Proxy(
    IImageList* This,
    IMAGELISTDRAWPARAMS *pimldp);
void __RPC_STUB IImageList_Draw_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_Remove_Proxy(
    IImageList* This,
    int i);
void __RPC_STUB IImageList_Remove_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_GetIcon_Proxy(
    IImageList* This,
    int i,
    UINT flags,
    HICON *picon);
void __RPC_STUB IImageList_GetIcon_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_GetImageInfo_Proxy(
    IImageList* This,
    int i,
    IMAGEINFO *pImageInfo);
void __RPC_STUB IImageList_GetImageInfo_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_Copy_Proxy(
    IImageList* This,
    int iDst,
    IUnknown *punkSrc,
    int iSrc,
    UINT uFlags);
void __RPC_STUB IImageList_Copy_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_Merge_Proxy(
    IImageList* This,
    int i1,
    IUnknown *punk2,
    int i2,
    int dx,
    int dy,
    REFIID riid,
    PVOID *ppv);
void __RPC_STUB IImageList_Merge_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_Clone_Proxy(
    IImageList* This,
    REFIID riid,
    PVOID *ppv);
void __RPC_STUB IImageList_Clone_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_GetImageRect_Proxy(
    IImageList* This,
    int i,
    RECT *prc);
void __RPC_STUB IImageList_GetImageRect_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_GetIconSize_Proxy(
    IImageList* This,
    int *cx,
    int *cy);
void __RPC_STUB IImageList_GetIconSize_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_SetIconSize_Proxy(
    IImageList* This,
    int cx,
    int cy);
void __RPC_STUB IImageList_SetIconSize_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_GetImageCount_Proxy(
    IImageList* This,
    int *pi);
void __RPC_STUB IImageList_GetImageCount_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_SetImageCount_Proxy(
    IImageList* This,
    UINT uNewCount);
void __RPC_STUB IImageList_SetImageCount_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_SetBkColor_Proxy(
    IImageList* This,
    COLORREF clrBk,
    COLORREF *pclr);
void __RPC_STUB IImageList_SetBkColor_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_GetBkColor_Proxy(
    IImageList* This,
    COLORREF *pclr);
void __RPC_STUB IImageList_GetBkColor_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_BeginDrag_Proxy(
    IImageList* This,
    int iTrack,
    int dxHotspot,
    int dyHotspot);
void __RPC_STUB IImageList_BeginDrag_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_EndDrag_Proxy(
    IImageList* This);
void __RPC_STUB IImageList_EndDrag_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_DragEnter_Proxy(
    IImageList* This,
    HWND hwndLock,
    int x,
    int y);
void __RPC_STUB IImageList_DragEnter_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_DragLeave_Proxy(
    IImageList* This,
    HWND hwndLock);
void __RPC_STUB IImageList_DragLeave_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_DragMove_Proxy(
    IImageList* This,
    int x,
    int y);
void __RPC_STUB IImageList_DragMove_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_SetDragCursorImage_Proxy(
    IImageList* This,
    IUnknown *punk,
    int iDrag,
    int dxHotspot,
    int dyHotspot);
void __RPC_STUB IImageList_SetDragCursorImage_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_DragShowNolock_Proxy(
    IImageList* This,
    BOOL fShow);
void __RPC_STUB IImageList_DragShowNolock_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_GetDragImage_Proxy(
    IImageList* This,
    POINT *ppt,
    POINT *pptHotspot,
    REFIID riid,
    PVOID *ppv);
void __RPC_STUB IImageList_GetDragImage_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_GetItemFlags_Proxy(
    IImageList* This,
    int i,
    DWORD *dwFlags);
void __RPC_STUB IImageList_GetItemFlags_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);
HRESULT STDMETHODCALLTYPE IImageList_GetOverlayImage_Proxy(
    IImageList* This,
    int iOverlay,
    int *piIndex);
void __RPC_STUB IImageList_GetOverlayImage_Stub(
    IRpcStubBuffer* This,
    IRpcChannelBuffer* pRpcChannelBuffer,
    PRPC_MESSAGE pRpcMessage,
    DWORD* pdwStubPhase);

#endif  /* __IImageList_INTERFACE_DEFINED__ */


DEFINE_GUID(LIBID_CommonControlObjects, 0xbcada15b, 0xb428, 0x420c, 0x8d,0x28, 0x02,0x35,0x90,0x92,0x4c,0x9f);

/*****************************************************************************
 * ImageList coclass
 */

DEFINE_GUID(CLSID_ImageList, 0x7c476ba2, 0x02b1, 0x48f4, 0x80,0x48, 0xb2,0x46,0x19,0xdd,0xc0,0x58);

#ifdef __cplusplus
class DECLSPEC_UUID("7c476ba2-02b1-48f4-8048-b24619ddc058") ImageList;
#ifdef __CRT_UUID_DECL
__CRT_UUID_DECL(ImageList, 0x7c476ba2, 0x02b1, 0x48f4, 0x80,0x48, 0xb2,0x46,0x19,0xdd,0xc0,0x58)
#endif
#endif

/* Begin additional prototypes for all interfaces */


/* End additional prototypes */

#ifdef __cplusplus
}
#endif

#endif /* __commoncontrols_h__ */
