#pragma once

// LbNvrIpcActivexPropPage.h : CLbNvrIpcActivexPropPage ����ҳ���������


// CLbNvrIpcActivexPropPage : �й�ʵ�ֵ���Ϣ������� LbNvrIpcActivexPropPage.cpp��

class CLbNvrIpcActivexPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CLbNvrIpcActivexPropPage)
	DECLARE_OLECREATE_EX(CLbNvrIpcActivexPropPage)

// ���캯��
public:
	CLbNvrIpcActivexPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_LBNVRIPCACTIVEX };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

