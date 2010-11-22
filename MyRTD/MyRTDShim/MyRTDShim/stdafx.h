// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif

// Modify the following defines if you have to target a platform prior to the ones specified below.
// Refer to MSDN for the latest info on corresponding values for different platforms.
#ifndef WINVER				// Allow use of features specific to Windows 95 and Windows NT 4 or later.
#define WINVER 0x0400		// Change this to the appropriate value to target Windows 98 and Windows 2000 or later.
#endif

#ifndef _WIN32_WINNT		// Allow use of features specific to Windows NT 4 or later.
#define _WIN32_WINNT 0x0400	// Change this to the appropriate value to target Windows 2000 or later.
#endif						

#ifndef _WIN32_WINDOWS		// Allow use of features specific to Windows 98 or later.
#define _WIN32_WINDOWS 0x0410 // Change this to the appropriate value to target Windows Me or later.
#endif

#ifndef _WIN32_IE			// Allow use of features specific to IE 4.0 or later.
#define _WIN32_IE 0x0400	// Change this to the appropriate value to target IE 5.0 or later.
#endif

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

// turns off ATL's hiding of some common and often safely ignored warning messages
#define _ATL_ALL_WARNINGS

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>

#pragma warning( disable : 4278 )
#pragma warning( disable : 4146 )

// for _AppDomain.  Used to communicate with the default app domain from unmanaged code
#import <mscorlib.tlb> raw_interfaces_only high_property_prefixes("_get","_put","_putref")


///////////////////////////////////////////////////////////////////////////////
#pragma warning (disable: 4192)

// The three #import lines below import the type libraries for:
// Microsoft Office 11 Object Library v2.3 (MSO.dll)
// Microsoft Visual Basic for Applications Extensibility v5.3 (Vbe6Ext.olb)
// Microsoft Excel 11.0 Object Library v1.5 (Excel.exe)
// These are required for the definitions of the IRtdServer and IRTDUpdateEvent interfaces.
// For Excel 2003 (v11), the version numbers should be: 2.3, 5.3, 1.5
// For Excel 2002 (XP, v10), the version numbers should be: 2.2, 5.3, 1.4
#import "libid:2df8d04c-5bfa-101b-bde5-00aa0044de52" 
#import "libid:0002e157-0000-0000-c000-000000000046"
#import "libid:00020813-0000-0000-C000-000000000046" \
	raw_interfaces_only named_guids \
	rename("DialogBox", "XLDialogBox") \
	rename("RGB", "XLRGB")
#pragma warning( default : 4192 )
///////////////////////////////////////////////////////////////////////////////


#pragma warning( default : 4146 )
#pragma warning( default : 4278 )

using namespace ATL;

// for CorBindToRuntimeEx and ICorRuntimeHost
#include <mscoree.h>

#define IfFailGo(x) { hr=(x); if (FAILED(hr)) goto Error; }
#define IfNullGo(p) { if(!p) {hr = E_FAIL; goto Error; } }
#define IfFailGoCheck(x, p) { hr=(x); if (FAILED(hr)) goto Error; if(!p) {hr = E_FAIL; goto Error; } }


#include <windows.h>
#include <assert.h>






















