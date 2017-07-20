// LbNvrIpcActivexCtrl.cpp : CLbNvrIpcActivexCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "LbNvrIpcActivex.h"
#include "LbNvrIpcActivexCtrl.h"
#include "LbNvrIpcActivexPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CLbNvrIpcActivexCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CLbNvrIpcActivexCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CLbNvrIpcActivexCtrl, COleControl)
	DISP_FUNCTION_ID(CLbNvrIpcActivexCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CLbNvrIpcActivexCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO: ������Ҫ���Ӹ�������ҳ�����ס���Ӽ���!
BEGIN_PROPPAGEIDS(CLbNvrIpcActivexCtrl, 1)
	PROPPAGEID(CLbNvrIpcActivexPropPage::guid)
END_PROPPAGEIDS(CLbNvrIpcActivexCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CLbNvrIpcActivexCtrl, "LBNVRIPCACTIVEX.LbNvrIpcActivexCtrl.1",
	0x6f2d723e, 0x6928, 0x4e2c, 0x92, 0xa2, 0xf8, 0x13, 0x5a, 0x49, 0x6f, 0x65)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CLbNvrIpcActivexCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DLbNvrIpcActivex = { 0xA918B667, 0xBDC0, 0x4520, { 0xB6, 0x35, 0xAC, 0x17, 0xFB, 0x92, 0xC4, 0x98 } };
const IID IID_DLbNvrIpcActivexEvents = { 0xC2F5AD, 0x67FF, 0x4B20, { 0x9E, 0x97, 0xCF, 0xAC, 0x6A, 0x89, 0x47, 0xD3 } };

// �ؼ�������Ϣ

static const DWORD _dwLbNvrIpcActivexOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CLbNvrIpcActivexCtrl, IDS_LBNVRIPCACTIVEX, _dwLbNvrIpcActivexOleMisc)

// CLbNvrIpcActivexCtrl::CLbNvrIpcActivexCtrlFactory::UpdateRegistry -
// ���ӻ��Ƴ� CLbNvrIpcActivexCtrl ��ϵͳע�����

BOOL CLbNvrIpcActivexCtrl::CLbNvrIpcActivexCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳�������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_LBNVRIPCACTIVEX,
			IDB_LBNVRIPCACTIVEX,
			afxRegApartmentThreading,
			_dwLbNvrIpcActivexOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CLbNvrIpcActivexCtrl::CLbNvrIpcActivexCtrl - ���캯��

CLbNvrIpcActivexCtrl::CLbNvrIpcActivexCtrl()
{
	InitializeIIDs(&IID_DLbNvrIpcActivex, &IID_DLbNvrIpcActivexEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CLbNvrIpcActivexCtrl::~CLbNvrIpcActivexCtrl - ��������

CLbNvrIpcActivexCtrl::~CLbNvrIpcActivexCtrl()
{
	// TODO:  �ڴ������ؼ���ʵ�����ݡ�
}

// CLbNvrIpcActivexCtrl::OnDraw - ��ͼ����

//void CLbNvrIpcActivexCtrl::OnDraw(
//			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
//{
//	if (!pdc)
//		return;
//
//	// TODO:  �����Լ��Ļ�ͼ�����滻����Ĵ��롣
//	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
//	pdc->Ellipse(rcBounds);
//}

// CLbNvrIpcActivexCtrl::DoPropExchange - �־���֧��

void CLbNvrIpcActivexCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CLbNvrIpcActivexCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CLbNvrIpcActivexCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CLbNvrIpcActivexCtrl::AboutBox - ���û���ʾ�����ڡ���

void CLbNvrIpcActivexCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_LBNVRIPCACTIVEX);
	dlgAbout.DoModal();
}


// CLbNvrIpcActivexCtrl ��Ϣ��������


int CLbNvrIpcActivexCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ�������ר�õĴ�������

	return 0;
}


void CLbNvrIpcActivexCtrl::OnDestroy()
{
	COleControl::OnDestroy();

	// TODO: �ڴ˴�������Ϣ�����������
}
void CLbNvrIpcActivexCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ�������Ϣ������������/�����Ĭ��ֵ
	MessageBox("db","");
	COleControl::OnLButtonDblClk(nFlags, point);
}


BOOL CLbNvrIpcActivexCtrl::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ�����ר�ô����/����û���
	CString aaaaaaa="esc";
	if (pMsg->message == WM_KEYDOWN) if(27==pMsg->wParam) MessageBox(aaaaaaa, ""); 
	return COleControl::PreTranslateMessage(pMsg);
}