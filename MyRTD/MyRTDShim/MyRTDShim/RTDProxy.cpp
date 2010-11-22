// RTDProxy.cpp : Implementation of CRTDProxy

#include "stdafx.h"
#include "RTDProxy.h"
#include "CLRLoader.h"
#include "ShimConfig.h"

using namespace ShimConfig;

// CRTDProxy

HRESULT CRTDProxy::FinalConstruct()
{
    HRESULT hr = S_OK;

	// Create an instance of a managed RTD component
	// and fetch the interface pointer
    CCLRLoader *pCLRLoader = CCLRLoader::TheInstance();
    IfNullGo(pCLRLoader);
    IfFailGo(pCLRLoader->CreateInstance(AssemblyName(), ConnectClassName(),
		__uuidof(Excel::IRtdServer), (void **)&m_pConnect));

Error:
    return hr;
}

void CRTDProxy::FinalRelease() 
{
    if (m_pConnect)
        m_pConnect->Release();
}


