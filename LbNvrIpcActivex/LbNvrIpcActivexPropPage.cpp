// LbNvrIpcActivexPropPage.cpp : CLbNvrIpcActivexPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "LbNvrIpcActivex.h"
#include "LbNvrIpcActivexPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CLbNvrIpcActivexPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CLbNvrIpcActivexPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CLbNvrIpcActivexPropPage, "LBNVRIPCACTIVE.LbNvrIpcActivePropPage.1",
	0x611174d4, 0x26b0, 0x4599, 0x8a, 0x5f, 0xb9, 0x82, 0xae, 0x9d, 0x4a, 0xbe)

// CLbNvrIpcActivexPropPage::CLbNvrIpcActivexPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CLbNvrIpcActivexPropPage ��ϵͳע�����

BOOL CLbNvrIpcActivexPropPage::CLbNvrIpcActivexPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_LBNVRIPCACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CLbNvrIpcActivexPropPage::CLbNvrIpcActivexPropPage - ���캯��

CLbNvrIpcActivexPropPage::CLbNvrIpcActivexPropPage() :
	COlePropertyPage(IDD, IDS_LBNVRIPCACTIVEX_PPG_CAPTION)
{
}

// CLbNvrIpcActivexPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CLbNvrIpcActivexPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CLbNvrIpcActivexPropPage ��Ϣ�������
