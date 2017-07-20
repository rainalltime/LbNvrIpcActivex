#pragma once

// LbNvrIpcActivexPropPage.h : CLbNvrIpcActivexPropPage 属性页类的声明。


// CLbNvrIpcActivexPropPage : 有关实现的信息，请参阅 LbNvrIpcActivexPropPage.cpp。

class CLbNvrIpcActivexPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CLbNvrIpcActivexPropPage)
	DECLARE_OLECREATE_EX(CLbNvrIpcActivexPropPage)

// 构造函数
public:
	CLbNvrIpcActivexPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_LBNVRIPCACTIVEX };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

