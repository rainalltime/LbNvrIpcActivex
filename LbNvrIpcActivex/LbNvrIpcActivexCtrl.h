#pragma once

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

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

