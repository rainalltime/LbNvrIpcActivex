// LbNvrIpcActivexPropPage.cpp : CLbNvrIpcActivexPropPage 属性页类的实现。

#include "stdafx.h"
#include "LbNvrIpcActivex.h"
#include "LbNvrIpcActivexPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CLbNvrIpcActivexPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CLbNvrIpcActivexPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CLbNvrIpcActivexPropPage, "LBNVRIPCACTIVE.LbNvrIpcActivePropPage.1",
	0x611174d4, 0x26b0, 0x4599, 0x8a, 0x5f, 0xb9, 0x82, 0xae, 0x9d, 0x4a, 0xbe)

// CLbNvrIpcActivexPropPage::CLbNvrIpcActivexPropPageFactory::UpdateRegistry -
// 添加或移除 CLbNvrIpcActivexPropPage 的系统注册表项

BOOL CLbNvrIpcActivexPropPage::CLbNvrIpcActivexPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_LBNVRIPCACTIVEX_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CLbNvrIpcActivexPropPage::CLbNvrIpcActivexPropPage - 构造函数

CLbNvrIpcActivexPropPage::CLbNvrIpcActivexPropPage() :
	COlePropertyPage(IDD, IDS_LBNVRIPCACTIVEX_PPG_CAPTION)
{
}

// CLbNvrIpcActivexPropPage::DoDataExchange - 在页和属性间移动数据

void CLbNvrIpcActivexPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CLbNvrIpcActivexPropPage 消息处理程序
