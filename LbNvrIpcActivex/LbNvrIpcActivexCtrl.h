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

	////登录函数//四个参数分别代表DVRip地址，DVR端口号，登录名，登录密码。
	//返回值MaxChannelCount最大通道数，isSuccess是否成功-2（未知、未调用）-1（失败）0（成功）,error错误编号
	afx_msg BSTR LbLogin(LPCTSTR ip, USHORT port, LPCTSTR userName, LPCTSTR password);
	////播放函数，channelSelected实时监视通道号，如果rType为RType_Multiplay该参数保留。当rType为RType_Multiplay_1~RType_Multiplay_16时，nChannelID决定了预览的画面，
	////如当RType_Multiplay_4时，nChannelID为4、5、6、7其中一个值表示预览第5到第7通道的四画面预览 
	////DH_RealPlayType播放类型，数字代表意义如下。一般设为0
	/*
		0	// 实时预览
		1	// 多画面预览
		2	// 实时监视-主码流,等同于DH_RType_Realplay
		3	// 实时监视-从码流1
		4	// 实时监视-从码流2
		5	// 实时监视-从码流3
		6	// 多画面预览－1画面
		7	// 多画面预览－4画面
		8	// 多画面预览－8画面
		9	// 多画面预览－9画面
		10	// 多画面预览－16画面
		11	// 多画面预览－6画面
		12	// 多画面预览－12画面
		13	// 多画面预览－25画面
		14	// 多画面预览－36画面
		*/
	afx_msg BSTR LbPlay(SHORT channelSelected, SHORT playMode);
	//云台控制
	afx_msg BSTR LbPtzCommand(LONG command, USHORT param1, USHORT param2, USHORT param3, USHORT isStop);
    //设置通道号
	afx_msg BSTR LbSetChannel(USHORT channel);
// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		dispidLbSetChannel = 4L,
		dispidLbPtzCommand = 3L,
		dispidLbPlay = 2L,
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
	WORD channel;
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

	
protected:
	
	

	
	

	
};