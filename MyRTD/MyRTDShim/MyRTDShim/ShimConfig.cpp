#include "stdafx.h"
#include "ShimConfig.h"

// These strings are specific to the managed assembly that this shim will load.
static LPCWSTR szRTDAssemblyName = 
	L"MyRTD, PublicKeyToken=4795dea101d50609";
static LPCWSTR szConnectClassName = 
	L"MyRTD.RTD";


// Functions that return the above values

LPCWSTR ShimConfig::AssemblyName()
{
    return szRTDAssemblyName;
}


LPCWSTR ShimConfig::ConnectClassName()
{
    return szConnectClassName;
}
