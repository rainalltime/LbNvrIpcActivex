#pragma once
#include "dhconfigsdk.h"
#include "dhnetsdk.h"
#include "avglobal.h"

// LbNvrIpcActivexCtrl.h : CLbNvrIpcActivexCtrl ActiveX �ؼ����������


// CLbNvrIpcActivexCtrl : �й�ʵ�ֵ���Ϣ������� LbNvrIpcActivexCtrl.cpp��

class CLbNvrIpcActivexCtrl : public COleControl
{
	DECLARE_DYNCREATE(CLbNvrIpcActivexCtrl)

// ���캯��
public:
	CLbNvrIpcActivexCtrl();

// ��д
public:
//	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CLbNvrIpcActivexCtrl();

	DECLARE_OLECREATE_EX(CLbNvrIpcActivexCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CLbNvrIpcActivexCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CLbNvrIpcActivexCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CLbNvrIpcActivexCtrl)		// �������ƺ�����״̬

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	//****************************************************************
	//�ⲿ���õĺ���
	afx_msg BSTR LbLogin(LPCTSTR ip, SHORT port, LPCTSTR userName, LPCTSTR password);

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
		dispidLbLogin = 1L
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);


	//�����
	//enum RetIsSuccess {
	//retUnknown=-2,
	//retFail=-1,
	//retSuccess=0
	//}retIsSuccess= retUnknown;
	//CString retJson;
	BOOL g_bNetSDKInitFlag = FALSE;
	LLONG g_lLoginHandle = 0L;
	LLONG g_lRealHandle = 0;
	//****************************
	//�ຯ��
	//��ʼ��sdk
	bool InitNetSDK();

	//��Ԫ�ص�����
	//*********************************************************************************
	// ���ûص���������
	// �豸���߻ص�����
	// �������ڸûص������е��� SDK �ӿ�
	// ͨ�� CLIENT_Init ���øûص����������豸���ֶ���ʱ��SDK ����øú���
	friend void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort,
		DWORD dwUser);
	// ���������ɹ��ص�����
	// �������ڸûص������е��� SDK �ӿ�
	// ͨ�� CLIENT_SetAutoReconnect ���øûص����������Ѷ��ߵ��豸�����ɹ�ʱ��SDK ����øú���
	friend  void CALLBACK HaveReConnect(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort,
		LDWORD dwUser);

	
};