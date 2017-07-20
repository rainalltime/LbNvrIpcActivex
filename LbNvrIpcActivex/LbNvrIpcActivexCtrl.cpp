// LbNvrIpcActivexCtrl.cpp : CLbNvrIpcActivexCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "LbNvrIpcActivex.h"
#include "LbNvrIpcActivexCtrl.h"
#include "LbNvrIpcActivexPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CLbNvrIpcActivexCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CLbNvrIpcActivexCtrl, COleControl)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_LBUTTONDBLCLK()
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CLbNvrIpcActivexCtrl, COleControl)
	DISP_FUNCTION_ID(CLbNvrIpcActivexCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
	DISP_FUNCTION_ID(CLbNvrIpcActivexCtrl, "LbLogin", dispidLbLogin, LbLogin, VT_BSTR, VTS_BSTR VTS_I2 VTS_BSTR VTS_BSTR)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CLbNvrIpcActivexCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO: 根据需要添加更多属性页。请记住增加计数!
BEGIN_PROPPAGEIDS(CLbNvrIpcActivexCtrl, 1)
	PROPPAGEID(CLbNvrIpcActivexPropPage::guid)
END_PROPPAGEIDS(CLbNvrIpcActivexCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CLbNvrIpcActivexCtrl, "LBNVRIPCACTIVEX.LbNvrIpcActivexCtrl.1",
	0x6f2d723e, 0x6928, 0x4e2c, 0x92, 0xa2, 0xf8, 0x13, 0x5a, 0x49, 0x6f, 0x65)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CLbNvrIpcActivexCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DLbNvrIpcActivex = { 0xA918B667, 0xBDC0, 0x4520, { 0xB6, 0x35, 0xAC, 0x17, 0xFB, 0x92, 0xC4, 0x98 } };
const IID IID_DLbNvrIpcActivexEvents = { 0xC2F5AD, 0x67FF, 0x4B20, { 0x9E, 0x97, 0xCF, 0xAC, 0x6A, 0x89, 0x47, 0xD3 } };

// 控件类型信息

static const DWORD _dwLbNvrIpcActivexOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CLbNvrIpcActivexCtrl, IDS_LBNVRIPCACTIVEX, _dwLbNvrIpcActivexOleMisc)

// CLbNvrIpcActivexCtrl::CLbNvrIpcActivexCtrlFactory::UpdateRegistry -
// 添加或移除 CLbNvrIpcActivexCtrl 的系统注册表项

BOOL CLbNvrIpcActivexCtrl::CLbNvrIpcActivexCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

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


// CLbNvrIpcActivexCtrl::CLbNvrIpcActivexCtrl - 构造函数

CLbNvrIpcActivexCtrl::CLbNvrIpcActivexCtrl()
{
	InitializeIIDs(&IID_DLbNvrIpcActivex, &IID_DLbNvrIpcActivexEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CLbNvrIpcActivexCtrl::~CLbNvrIpcActivexCtrl - 析构函数

CLbNvrIpcActivexCtrl::~CLbNvrIpcActivexCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CLbNvrIpcActivexCtrl::OnDraw - 绘图函数

//void CLbNvrIpcActivexCtrl::OnDraw(
//			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
//{
//	if (!pdc)
//		return;
//
//	// TODO:  用您自己的绘图代码替换下面的代码。
//	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
//	pdc->Ellipse(rcBounds);
//}

// CLbNvrIpcActivexCtrl::DoPropExchange - 持久性支持

void CLbNvrIpcActivexCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: 为每个持久的自定义属性调用 PX_ 函数。
}


// CLbNvrIpcActivexCtrl::OnResetState - 将控件重置为默认状态

void CLbNvrIpcActivexCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CLbNvrIpcActivexCtrl::AboutBox - 向用户显示“关于”框

void CLbNvrIpcActivexCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_LBNVRIPCACTIVEX);
	dlgAbout.DoModal();
}


// CLbNvrIpcActivexCtrl 消息处理程序


int CLbNvrIpcActivexCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  在此添加您专用的创建代码


	InitNetSDK();
	return 0;
}


void CLbNvrIpcActivexCtrl::OnDestroy()
{
	COleControl::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}
void CLbNvrIpcActivexCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	MessageBox("db","");
	COleControl::OnLButtonDblClk(nFlags, point);
}


BOOL CLbNvrIpcActivexCtrl::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	static CString aaaaaaa;
	if (pMsg->message == WM_KEYUP) {
		aaaaaaa.AppendFormat("ss:%d\n", pMsg->wParam);
		if ('1' == pMsg->wParam)
			MessageBox(aaaaaaa, "aa");
	}
	return COleControl::PreTranslateMessage(pMsg);
}

bool CLbNvrIpcActivexCtrl::InitNetSDK()
{
	// 初始化 SDK
	g_bNetSDKInitFlag = CLIENT_Init(DisConnectFunc, 0);
	if (FALSE == g_bNetSDKInitFlag)
	{
		printf("Initialize client SDK fail; \n");
		return false;
	}
	else
	{
		printf("Initialize client SDK done; \n");
	}
	//// 获取 SDK 版本信息
	//// 此操作为可选操作
	//DWORD dwNetSdkVersion = CLIENT_GetSDKVersion();
	//printf("NetSDK version is [%d]\n", dwNetSdkVersion);
	// 设置断线重连回调接口，设置过断线重连成功回调函数后，当设备出现断线情况，SDK	内部会自动进行重连操作
	// 此操作为可选操作，但建议用户进行设置
	CLIENT_SetAutoReconnect(&HaveReConnect, 0);
	// 设置登录超时时间和尝试次数
	// 此操作为可选操作
	int nWaitTime = 5000; // 登录请求响应超时时间设置为 5s
	int nTryTimes = 3; // 登录时尝试建立链接 3 次
	CLIENT_SetConnectTime(nWaitTime, nTryTimes);
	
}
//Callback function when device disconnected
void CALLBACK DisConnectFunc(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort,
	DWORD dwUser)
{

}
void CALLBACK HaveReConnect(LLONG lLoginID, char *pchDVRIP, LONG nDVRPort,
	LDWORD dwUser)
{

}

BSTR CLbNvrIpcActivexCtrl::LbLogin(LPCTSTR ip, SHORT port, LPCTSTR userName, LPCTSTR password)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: 在此添加调度处理程序代码
	// 设置更多网络参数，NET_PARAM 的 nWaittime，nConnectTryNum 成员与	CLIENT_SetConnectTime 接口设置的登录设备超时时间和尝试次数意义相同
	// 此操作为可选操作
	NET_PARAM stuNetParm = { 0 };
	stuNetParm.nConnectTime = 2000; // 登录时尝试建立链接的超时时间
	CLIENT_SetNetworkParam(&stuNetParm);
	NET_DEVICEINFO_Ex stDevInfoEx = { 0 };
	int nError = 0;
	while (0 == g_lLoginHandle)
	{
		// 登录设备
		g_lLoginHandle = CLIENT_LoginEx2(ip, port, userName,
			password, EM_LOGIN_SPEC_CAP_TCP, NULL, &stDevInfoEx, &nError);
		if (0 == g_lLoginHandle)
		{
			strResult.AppendFormat("{\"isSuccess\":\"%s\",\"error\":\"%d\"}","fail", nError);
		}
		else
		{
			strResult.AppendFormat("{\"isSuccess\":\"%s\",\"error\":\"%d\"}", "success", nError);
		}
		// 用户初次登录设备，需要初始化一些数据才能正常实现业务功能，建议登录后等待一小段时间，具体等待时间因设备而异
	}

	return strResult.AllocSysString();
}
