// RTDProxy.h : Declaration of the CRTDProxy

#pragma once
#include "resource.h"       // main symbols

#include "MyRTDShim.h"


// CRTDProxy

class ATL_NO_VTABLE CRTDProxy : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRTDProxy, &CLSID_RTDProxy>,
	public IDispatchImpl<Excel::IRtdServer, &Excel::IID_IRtdServer, &Excel::LIBID_Excel, 1, 5>
{
public:
	CRTDProxy()
		: m_pConnect(NULL)
	{
	}

	DECLARE_REGISTRY_RESOURCEID(IDR_RTDPROXY)

	BEGIN_COM_MAP(CRTDProxy)
		COM_INTERFACE_ENTRY2(IDispatch, Excel::IRtdServer)
		COM_INTERFACE_ENTRY(Excel::IRtdServer)
	END_COM_MAP()


	DECLARE_PROTECT_FINAL_CONSTRUCT()

	HRESULT FinalConstruct();
	void FinalRelease();

public:
	//IRtdServer implementation:
	STDMETHOD(ServerStart)(Excel::IRTDUpdateEvent* CallbackObject, long* pfRes)
    {
        return m_pConnect->ServerStart(CallbackObject, pfRes);
    }
	STDMETHOD(ConnectData)(long TopicID, SAFEARRAY **Strings, VARIANT_BOOL* GetNewValues, VARIANT* pvarOut)
    {
        return m_pConnect->ConnectData(TopicID, Strings, GetNewValues, pvarOut);
    }
	STDMETHOD(RefreshData)(long* TopicCount, SAFEARRAY** parrayOut)
    {
        return m_pConnect->RefreshData(TopicCount, parrayOut);
    }
	STDMETHOD(DisconnectData)(long TopicID)
    {
        return m_pConnect->DisconnectData(TopicID);
    }
	STDMETHOD(Heartbeat)(long* pfRes)
    {
        return m_pConnect->Heartbeat(pfRes);
    }
	STDMETHOD(ServerTerminate)()
    {
        return m_pConnect->ServerTerminate();
    }

protected:
	// caches pointer to managed RTD component
	Excel::IRtdServer *m_pConnect;
};

OBJECT_ENTRY_AUTO(__uuidof(RTDProxy), CRTDProxy)


















