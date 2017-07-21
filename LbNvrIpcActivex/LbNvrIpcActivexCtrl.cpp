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
	DISP_FUNCTION_ID(CLbNvrIpcActivexCtrl, "LbLogin", dispidLbLogin, LbLogin, VT_BSTR, VTS_BSTR VTS_UI2 VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CLbNvrIpcActivexCtrl, "LbPlay", dispidLbPlay, LbPlay, VT_BSTR, VTS_I2 VTS_I2)
	DISP_FUNCTION_ID(CLbNvrIpcActivexCtrl, "LbPtzCommand", dispidLbPtzCommand, LbPtzCommand, VT_BSTR, VTS_I4 VTS_UI2 VTS_UI2 VTS_UI2 VTS_UI2)
	DISP_FUNCTION_ID(CLbNvrIpcActivexCtrl, "LbSetChannel", dispidLbSetChannel, LbSetChannel, VT_BSTR, VTS_UI2)
	DISP_FUNCTION_ID(CLbNvrIpcActivexCtrl, "LbPlayBack", dispidLbPlayBack, LbPlayBack, VT_BSTR, VTS_I2 VTS_BSTR VTS_BSTR)
	DISP_FUNCTION_ID(CLbNvrIpcActivexCtrl, "LbPlayBackContrl", dispidLbPlayBackContrl, LbPlayBackContrl, VT_BSTR, VTS_I2)
	DISP_FUNCTION_ID(CLbNvrIpcActivexCtrl, "LbPlayTime", dispidLbPlayTime, LbPlayTime, VT_BSTR, VTS_UI4)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CLbNvrIpcActivexCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO: ������Ҫ��Ӹ�������ҳ�����ס���Ӽ���!
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
// ��ӻ��Ƴ� CLbNvrIpcActivexCtrl ��ϵͳע�����

BOOL CLbNvrIpcActivexCtrl::CLbNvrIpcActivexCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
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
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
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


// CLbNvrIpcActivexCtrl ��Ϣ�������


int CLbNvrIpcActivexCtrl::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (COleControl::OnCreate(lpCreateStruct) == -1)
		return -1;

	// TODO:  �ڴ������ר�õĴ�������


	InitNetSDK();
	return 0;
}


void CLbNvrIpcActivexCtrl::OnDestroy()
{
	COleControl::OnDestroy();

	// TODO: �ڴ˴������Ϣ����������
}
void CLbNvrIpcActivexCtrl::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	SetFullScreen(!isFullScreen);
	COleControl::OnLButtonDblClk(nFlags, point);
}


BOOL CLbNvrIpcActivexCtrl::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	static CString aaaaaaa;
	if (pMsg->message == WM_KEYUP) {
		SetFullScreen(isFullScreen);
		aaaaaaa.AppendFormat("ss:%d\n", pMsg->wParam);
		if ('1' == pMsg->wParam)
			MessageBox(aaaaaaa, "aa");
	}
	return COleControl::PreTranslateMessage(pMsg);
}

bool CLbNvrIpcActivexCtrl::InitNetSDK()
{
	// ��ʼ�� SDK
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
	//// ��ȡ SDK �汾��Ϣ
	//// �˲���Ϊ��ѡ����
	//DWORD dwNetSdkVersion = CLIENT_GetSDKVersion();
	//printf("NetSDK version is [%d]\n", dwNetSdkVersion);
	// ���ö��������ص��ӿڣ����ù����������ɹ��ص������󣬵��豸���ֶ��������SDK	�ڲ����Զ�������������
	// �˲���Ϊ��ѡ�������������û���������
	CLIENT_SetAutoReconnect(&HaveReConnect, 0);
	// ���õ�¼��ʱʱ��ͳ��Դ���
	// �˲���Ϊ��ѡ����
	int nWaitTime = 5000; // ��¼������Ӧ��ʱʱ������Ϊ 5s
	int nTryTimes = 3; // ��¼ʱ���Խ������� 3 ��
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

BSTR CLbNvrIpcActivexCtrl::LbLogin(LPCTSTR ip, USHORT port, LPCTSTR userName, LPCTSTR password)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
	CString strResult;
	strResult.Append("{");

	// TODO: �ڴ���ӵ��ȴ���������
	// ���ø������������NET_PARAM �� nWaittime��nConnectTryNum ��Ա��	CLIENT_SetConnectTime �ӿ����õĵ�¼�豸��ʱʱ��ͳ��Դ���������ͬ
	// �˲���Ϊ��ѡ����
	NET_PARAM stuNetParm = { 0 };
	stuNetParm.nConnectTime = 2000; // ��¼ʱ���Խ������ӵĳ�ʱʱ��
	CLIENT_SetNetworkParam(&stuNetParm);
	NET_DEVICEINFO_Ex stDevInfoEx = { 0 };
	int nError = 0;
	if (FALSE != g_bNetSDKInitFlag) {
		// ��¼�豸
		g_lLoginHandle = CLIENT_LoginEx2(ip, port, userName, password, EM_LOGIN_SPEC_CAP_TCP, NULL, &stDevInfoEx, &nError);
		if (0 == g_lLoginHandle)
		{
			strResult.AppendFormat("\"isSuccess\":\"%s\",", "fail");
			strResult.AppendFormat("\"error\":\"%d\",", nError);
		}
		else
		{
			strResult.AppendFormat("\"isSuccess\":\"%s\",\"error\":\"%d\",", "success", nError);
			strResult.AppendFormat("\"MaxChannelCount\":\"%d\",", stDevInfoEx.nChanNum>1? stDevInfoEx.nChanNum:1);
		}
		// �û����ε�¼�豸����Ҫ��ʼ��һЩ���ݲ�������ʵ��ҵ���ܣ������¼��ȴ�һС��ʱ�䣬����ȴ�ʱ�����豸����
	}
	strResult.Append("\"\":\"\"}");
	return strResult.AllocSysString();
}
BSTR CLbNvrIpcActivexCtrl::LbPlay(SHORT channelSelected, SHORT playMode)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	// �ж��Ƿ��¼�豸
	if (0 != g_lLoginHandle)
	{
		// ʵ��ʵʱ���ӹ���ҵ��
		// ��ȡ���ھ��
		HWND hWnd = GetSafeHwnd();
		//����ʵʱ����
		channel = channelSelected;
		g_lRealHandle = CLIENT_RealPlayEx(g_lLoginHandle, channel, hWnd,
			(DH_RealPlayType)playMode);
		if (0 == g_lRealHandle)
		{
			strResult.AppendFormat("\"error\": \"%x\"",
				CLIENT_GetLastError());
			strResult.AppendFormat("\"isSuccess\": \"%s\"", "fail");
		}
		else {
			strResult.AppendFormat("\"isSuccess\": \"%s\"", "success");
		}
	}
	return strResult.AllocSysString();
}
BSTR CLbNvrIpcActivexCtrl::LbPtzCommand(LONG command, USHORT param1, USHORT param2, USHORT param3, USHORT isStop)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;
	// TODO: �ڴ���ӵ��ȴ���������
	if (channel >= 0) {//���ͨ����Ч
		strResult.AppendFormat("\"isSuccess\": \"%s\"", CLIENT_DHPTZControlEx2(g_lLoginHandle, channel, command, param1, param2, param3, isStop)? "success": "fail");
	}
	else {
		strResult.AppendFormat("\"isSuccess\": \"%s\"","fail");
		strResult.AppendFormat("\"error\": \"%s\"", "ͨ����С��0");
	}
	return strResult.AllocSysString();
}

BSTR CLbNvrIpcActivexCtrl::LbSetChannel(USHORT channel)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	this->channel = channel;
	strResult.AppendFormat("\"isSuccess\": \"%s\"", this->channel == channel? "success" : "fail");
	return strResult.AllocSysString();
}


BSTR CLbNvrIpcActivexCtrl::LbPlayBack(SHORT channel, LPCTSTR startTime, LPCTSTR stopTime)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;



	// TODO: �ڴ���ӵ��ȴ���������

	if (0 != g_lLoginHandle)
	{

		// ¼��طŹ���
		// ��ȡ����̨���ھ��
		HWND hWnd = GetSafeHwnd();
		// ���ûط�ʱ����������
		int nStreamType = 0; // 0-��������,1-������,2-������
		CLIENT_SetDeviceMode(g_lLoginHandle, DH_RECORD_STREAM_TYPE,
			&nStreamType);
		// ���ûط�ʱ��¼���ļ�����
		NET_RECORD_TYPE emFileType = NET_RECORD_TYPE_ALL; // ����¼��
		CLIENT_SetDeviceMode(g_lLoginHandle, DH_RECORD_TYPE, &emFileType);
		//����¼��ط�
		int nChannelID = channel; // ͨ����
		NET_TIME stuStartTime = { 0 };
		NET_TIME stuStopTime = { 0 };
		if (sscanf(startTime, "%d-%d-%d   %d:%d:%d", &stuStartTime.dwYear, &stuStartTime.dwMonth, &stuStartTime.dwDay, &stuStartTime.dwHour, &stuStartTime.dwMinute, &stuStartTime.dwMinute) > 0
			&& sscanf(stopTime, "%d-%d-%d   %d:%d:%d", &stuStopTime.dwYear, &stuStopTime.dwMonth, &stuStopTime.dwDay, &stuStopTime.dwHour, &stuStopTime.dwMinute, &stuStopTime.dwMinute) > 0)
		{
			g_lPlayBackHandle = CLIENT_PlayBackByTimeEx(g_lLoginHandle, nChannelID, &stuStartTime, &stuStopTime, hWnd, NULL, NULL, NULL, NULL);
			if (0 == g_lPlayBackHandle)
			{
				strResult.AppendFormat("\"isSuccess\": \"%s\"", "fail");
				strResult.AppendFormat("\"error\": \"%s\"", "����ʧ��");
			}
			else {
				strResult.AppendFormat("\"isSuccess\": \"%s\"", "success");
			}
		}
		else
		{
			strResult.AppendFormat("\"isSuccess\": \"%s\"", "fail");
			strResult.AppendFormat("\"error\": \"%s\"", "ʱ���ʽ����");
		}
	}
	return strResult.AllocSysString();
}


BSTR CLbNvrIpcActivexCtrl::LbPlayBackContrl(SHORT command)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	if (0 != g_lPlayBackHandle) {
		switch (command)
		{
			//����
			case 1:strResult.AppendFormat("\"isSuccess\": \"%s\"", CLIENT_SlowPlayBack(g_lPlayBackHandle)? "success" : "fail"); break;
			//���
			case 2:strResult.AppendFormat("\"isSuccess\": \"%s\"", CLIENT_FastPlayBack(g_lPlayBackHandle) ? "success" : "fail"); break;
			//��������
			case 3:strResult.AppendFormat("\"isSuccess\": \"%s\"", CLIENT_NormalPlayBack(g_lPlayBackHandle) ? "success" : "fail"); break;
			//��ͣ/����
			case 4:strResult.AppendFormat("\"isSuccess\": \"%s\"", CLIENT_PausePlayBack(g_lPlayBackHandle,isPause= !isPause) ? "success" : "fail"); 
				strResult.AppendFormat("\"isPause\": \"%s\"", isPause ? "Pause" : "Play");
				break;
		default:strResult.AppendFormat("\"isSuccess\": \"%s\"",  "fail");
			break;
		}
	}
	else {
		strResult.AppendFormat("\"isSuccess\": \"%s\"", "fail");
	}
	return strResult.AllocSysString();
}


BSTR CLbNvrIpcActivexCtrl::LbPlayTime(ULONG startSecond)
{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	CString strResult;

	// TODO: �ڴ���ӵ��ȴ���������
	if (0 != g_lPlayBackHandle) {
		strResult.AppendFormat("\"isSuccess\": \"%s\"", CLIENT_SeekPlayBack(g_lPlayBackHandle, startSecond, 0)? "success" : "fail");
	}
	else
		strResult.AppendFormat("\"isSuccess\": \"%s\"", "fail");
	return strResult.AllocSysString();

	
}


void CLbNvrIpcActivexCtrl::SetFullScreen(bool isFull)
{	
	if (isFullScreen)
	{
		//Full screen 
		//Get displayer resolution 
		int cx = GetSystemMetrics(SM_CXSCREEN);
		int cy = GetSystemMetrics(SM_CYSCREEN);
		//Save position information 
		GetWindowPlacement(&_temppl);
		//Modify style 
		ModifyStyle(WS_CHILD, WS_POPUP);
		//Modify main-window 
		_tempparent = SetParent(NULL);
		_tempparent->ShowWindow(SW_HIDE);
		//Move window 
		MoveWindow(0, 0, cx, cy);
		//	SetWindowPos(&wndTopMost,0,0,cx,cy,NULL);
	}
	else
	{//Restore
	 //Restore main window 
		_tempparent->ShowWindow(SW_SHOW);
		SetParent(_tempparent);
		//Restore style 
		ModifyStyle(WS_POPUP, WS_CHILD);
		//Restore position 
		SetWindowPlacement(&_temppl);
	}
}
