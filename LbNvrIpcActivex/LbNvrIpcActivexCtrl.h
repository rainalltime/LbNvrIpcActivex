#pragma once
#include "dhconfigsdk.h"
#include "dhnetsdk.h"
#include "avglobal.h"
#include <MsHTML.h>  
CString tempLog;
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
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现//别忘了#include <MsHTML.h>  
//m_WebBrowser是一个WebBrowser的Activex控件对象。  
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
	//返回值MaxChannelCount最大通道数，isSuccess是否成功,error错误编号
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
	/*************command详细说明
	参数//意义
	0	// 上
	1	// 下
	2	// 左
	3	// 右
	4	// 变倍+
	5	// 变倍-
	6	// 调焦+
	7	// 调焦-
	8	// 光圈+
	9	// 光圈-
	10	// 转至预置点
	11	// 设置
	12	// 删除
	13	// 点间巡航
	14	// 灯光雨刷

	32	// 左上
	33	// 右上
	34	// 左下
	35	// 右下
	36	// 加入预置点到巡航 巡航线路 预置点值
	37	// 删除巡航中预置点 巡航线路 预置点值
	38	// 清除巡航 巡航线路
	39	// 开始水平旋转
	40	// 停止水平旋转
	41	// 设置左边界
	42	// 设置右边界
	43	// 开始线扫
	44	// 停止线扫
	45	// 设置模式开始    模式线路
	46	// 设置模式结束    模式线路
	47	// 运行模式    模式线路
	48	// 停止模式    模式线路
	49	// 清除模式    模式线路
	50	// 翻转命令
	51	// 快速定位 水平坐标(8192) 垂直坐标(8192) 变倍(4)
	52	// 辅助开关开 辅助点(param4对应 PTZ_CONTROL_AUXILIARY,param1、param2、param3无效,dwStop设置为FALSE)
	53	// 辅助开关关 辅助点(param4对应 PTZ_CONTROL_AUXILIARY,param1、param2、param3无效,dwStop设置为FALSE)
	54	// 打开球机菜单
	55	// 关闭菜单
	56	// 菜单确定
	57	// 菜单取消
	58	// 菜单上
	59	// 菜单下
	60	// 菜单左
	61	// 菜单右

	64	// 报警联动云台 parm1：报警输入通道；parm2：报警联动类型1-预置点2-线扫3-巡航；parm3：联动值,如预置点号
	65	// 矩阵切换 parm1：监视器号(视频输出号)；parm2：视频输入号；parm3：矩阵号
	66	// 灯光控制器
	67	// 三维精确定位 parm1：水平角度(0~3600)；parm2：垂直坐标(0~900)；parm3：变倍(1~128)
	68	// 三维定位重设零位
	69	// 绝对移动控制命令,param4对应结构 PTZ_CONTROL_ABSOLUTELY
	70	// 持续移动控制命令,param4对应结构 PTZ_CONTROL_CONTINUOUSLY
	71	// 云台控制命令,以一定速度转到预置位点,parm4对应结构PTZ_CONTROL_GOTOPRESET

	73	// 设置可视域(param4对应结构 PTZ_VIEW_RANGE_INFO)
	74	// 绝对聚焦(param4对应结构PTZ_FOCUS_ABSOLUTELY)
	75	// 水平扇扫(param4对应PTZ_CONTROL_SECTORSCAN,param1、param2、param3无效)
	76	// 垂直扇扫(param4对应PTZ_CONTROL_SECTORSCAN,param1、param2、param3无效)
	77	// 设定绝对焦距、聚焦值,param1为焦距,范围:[0,255],param2为聚焦,范围:[0,255],param3、param4无效
	78	// 控制鱼眼电子云台,param4对应结构 PTZ_CONTROL_SET_FISHEYE_EPTZ
	79	// 轨道机开始控制(param4对应结构体为 PTZ_CONTROL_SET_TRACK_CONTROL,dwStop传FALSE, param1、param2、param3无效)
	80	// 轨道机停止控制(param4对应结构体为 PTZ_CONTROL_SET_TRACK_CONTROL,dwStop传FALSE,param1、param2、param3无效)
	81	// 云台重启命令(param1、param2、param3 param4 均无效,dwStop设置为FALSE)
	82	// 云台连续移动,枪球联动专用,param4对应结构 PTZ_CONTROL_INTELLI_TRACKMOVE
	83	// 设置区域聚焦参数(param4对应结构体为PTZ_CONTROL_SET_FOCUS_REGION,dwStop传FALSE,param1、param2、param3无效)
	84	// 暂停线扫(param1、param2、param3param4均无效，dwStop设置为FALSE)

	112	// 上 + TELE param1=速度(1-8),下同
	113	// 下 + TELE
	114	// 左 + TELE
	115	// 右 + TELE
	116	// 左上 + TELE
	117	// 左下 + TELE
	118	// 右上 + TELE
	119	// 右下 + TELE
	120	// 上 + WIDE param1=速度(1-8),下同
	121	// 下 + WIDE
	122	// 左 + WIDE
	123	// 右 + WIDE
	124	// 左上 + WIDE
	125	// 左下 + WIDE
	126	// 右上 + WIDE
	127	// 右下 + WIDE
	128	// 最大命令值
	*/
	afx_msg BSTR LbPtzCommand(LONG command, USHORT param1, USHORT param2, USHORT param3, USHORT isStop);
    //设置通道号，多画面预览时设置要控制的通道
	afx_msg BSTR LbSetChannel(USHORT channel);
	//获得解码库视频参数，只对实时监控有效。返回值：
	//isSuccess是否成功
	//nBrightness ：返回亮度指针(0 - 255)
	//	nContrast：	//	返回对比度指针(0 - 255)
	//	nHue：	//	返回色度指针(0 - 255)
	//nSaturation：	//	返回饱和度指针(0 - 255)
	BSTR LbGetVideoEffect();
	//设置解码库视频参数，只对实时监控有效。参数：
	//nBrightness ：设置亮度指针(0 - 255)
	//	nContrast：	//	设置对比度指针(0 - 255)
	//	nHue：	//	设置色度指针(0 - 255)
	//nSaturation：	//	设置饱和度指针(0 - 255)
	//返回值：isSuccess是否成功
	BSTR LbSetVideoEffect(SHORT nBrightness, SHORT nContrast, SHORT nHue, SHORT nSaturation);
	//回放参数channel（通道）开始时间，结束时间,格式“yyyy-mm-dd hh:mm：ss”比如 2017-7-23 10:10:13 返回值isSuccess是否成功
	afx_msg BSTR LbPlayBack(SHORT channel, LPCTSTR startTime, LPCTSTR stopTime);
	//回放控制,参数command(指令)意义如下,返回值isSuccess是否成功
	/*参数意义：
	1  当前播放速度减半
	2  当前播放速度翻倍
	3  恢复正常播放速度
	4  暂停/播放
	*/
	afx_msg BSTR LbPlayBackContrl(SHORT command);
	//跳转到指定的时间播放，单位秒，例：若开始播放时间为10：10：00 调用LbPlayTime(2*60*60) 则会从12：10：00播放 返回值isSuccess是否成功
	afx_msg BSTR LbPlayTime(ULONG startSecond);
	//停止实时播放 返回值isSuccess是否成功
	afx_msg BSTR LbStopPlay();
	//停止回放播放 返回值isSuccess是否成功
	afx_msg BSTR LbStopBackPlay();
	//最后点击的时间
	afx_msg BSTR getLastClickTime();
	//开始对讲
	afx_msg BSTR LbTalkStart();
	//停止对讲
	BSTR LbTalkStop();
// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
		dispidLbTalkStop = 14L,
		dispidLbTalkStart = 13L,
		dispidLbSetVideoEffect = 12L,
		dispidLbGetVideoEffect = 11L,
		dispidgetLastClickTime = 10L,
		dispidLbStopBackPlay = 9L,
		dispidLbStopPlay = 8L,
		dispidLbPlayTime = 7L,
		dispidLbPlayBackContrl = 6L,
		dispidLbPlayBack = 5L,
		dispidLbSetChannel = 4L,
		dispidLbPtzCommand = 3L,
		dispidLbPlay = 2L,
		dispidLbLogin = 1L
	};
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	virtual BOOL PreTranslateMessage(MSG* pMsg);


	//类变量
	//enum RetIsSuccess {
	//retUnknown=-2,
	//retFail=-1,
	//retSuccess=0
	//}retIsSuccess= retUnknown;
	//CString retJson;
	CString lastClickTime="未点击";//最后一次单击的时间
	BOOL g_bNetSDKInitFlag = FALSE;
	LLONG g_lLoginHandle = 0L;
	LLONG g_lRealHandle = 0;
	LLONG g_lPlayBackHandle = 0;
	LLONG g_lTalkHandle = 0;
	int playCount = 0;
	bool isPause=false;
	CString LogInf;
	WORD channel;
	//用于全屏
	bool isFullScreen=false;
	//	Save original window message when in full screen to restore window.
	WINDOWPLACEMENT _temppl;		//window's placement
	CWnd *			_tempparent;	//window's parent
	//****************************
	//类函数
	//初始化sdk
	bool InitNetSDK();
	//
	void endSdk();
	//
	void SetFullScreen(bool isFull);

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
	//回调函数语音对讲
	friend void _stdcall AudioDataCallBack(LONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser);
};