

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Mon Nov 01 06:22:35 2010
 */
/* Compiler settings for .\MyRTDShim.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __MyRTDShim_h__
#define __MyRTDShim_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

/* Forward Declarations */ 

#ifndef __RTDProxy_FWD_DEFINED__
#define __RTDProxy_FWD_DEFINED__

#ifdef __cplusplus
typedef class RTDProxy RTDProxy;
#else
typedef struct RTDProxy RTDProxy;
#endif /* __cplusplus */

#endif 	/* __RTDProxy_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

#ifdef __cplusplus
extern "C"{
#endif 



#ifndef __MyRTDShimLib_LIBRARY_DEFINED__
#define __MyRTDShimLib_LIBRARY_DEFINED__

/* library MyRTDShimLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_MyRTDShimLib;

EXTERN_C const CLSID CLSID_RTDProxy;

#ifdef __cplusplus

class DECLSPEC_UUID("8b8172ac-ea72-4111-ac8c-b891f1f944a1")
RTDProxy;
#endif
#endif /* __MyRTDShimLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


