#pragma once
#include "dhconfigsdk.h"
#include "dhnetsdk.h"
#include "avglobal.h"

// LbNvrIpcActivexCtrl.h : CLbNvrIpcActivexCtrl ActiveX 控件类的声明。


// CLbNvrIpcActivexCtrl : 有关实现的信息，请参阅 LbNvrIpcActivexCtrl.cpp。

class CLbNvrIpcActivexCtrl : public COleControl
{
	DECLARE_DYNCREATE(CLbNvrIpcActivexCtrl)

// 构造函数
public:
	CLbNvrIpcActivexCtrl();

// 重写
public:
//	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CLbNvrIpcActivexCtrl();

	DECLARE_OLECREATE_EX(CLbNvrIpcActivexCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CLbNvrIpcActivexCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CLbNvrIpcActivexCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CLbNvrIpcActivexCtrl)		// 类型名称和杂项状态

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();
	//****************************************************************
	//外部调用的函数
	afx_msg BSTR LbLogin(LPCTSTR ip, SHORT port, LPCTSTR userName, LPCTSTR password);

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		dispidLbLogin = 1L
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);


	//类变量
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
	//类函数
	//初始化sdk
	bool InitNetSDK();

	//友元回调函数
	//*********************************************************************************
	// 常用回调集合声明
	// 设备断线回调函数
	// 不建议在该回调函数中调用 SDK 接口
	// 通过 CLIENT_Init 设置该回调函数，当设备出现断线时，SDK 会调用该函数
	friend void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort,
		DWORD dwUser);
	// 断线重连成功回调函数
	// 不建议在该回调函数中调用 SDK 接口
	// 通过 CLIENT_SetAutoReconnect 设置该回调函数，当已断线的设备重连成功时，SDK 会调用该函数
	friend  void CALLBACK HaveReConnect(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort,
		LDWORD dwUser);

	
};