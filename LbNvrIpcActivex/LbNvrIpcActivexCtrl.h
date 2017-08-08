#pragma once
#include "dhconfigsdk.h"
#include "dhnetsdk.h"
#include "avglobal.h"
#include <MsHTML.h>  
CString tempLog;
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
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��//������#include <MsHTML.h>  
//m_WebBrowser��һ��WebBrowser��Activex�ؼ�����  
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

	////��¼����//�ĸ������ֱ����DVRip��ַ��DVR�˿ںţ���¼������¼���롣
	//����ֵMaxChannelCount���ͨ������isSuccess�Ƿ�ɹ�,error������
	afx_msg BSTR LbLogin(LPCTSTR ip, USHORT port, LPCTSTR userName, LPCTSTR password);
	////���ź�����channelSelectedʵʱ����ͨ���ţ����rTypeΪRType_Multiplay�ò�����������rTypeΪRType_Multiplay_1~RType_Multiplay_16ʱ��nChannelID������Ԥ���Ļ��棬
	////�統RType_Multiplay_4ʱ��nChannelIDΪ4��5��6��7����һ��ֵ��ʾԤ����5����7ͨ�����Ļ���Ԥ�� 
	////DH_RealPlayType�������ͣ����ִ����������¡�һ����Ϊ0
	/*
		0	// ʵʱԤ��
		1	// �໭��Ԥ��
		2	// ʵʱ����-������,��ͬ��DH_RType_Realplay
		3	// ʵʱ����-������1
		4	// ʵʱ����-������2
		5	// ʵʱ����-������3
		6	// �໭��Ԥ����1����
		7	// �໭��Ԥ����4����
		8	// �໭��Ԥ����8����
		9	// �໭��Ԥ����9����
		10	// �໭��Ԥ����16����
		11	// �໭��Ԥ����6����
		12	// �໭��Ԥ����12����
		13	// �໭��Ԥ����25����
		14	// �໭��Ԥ����36����
		*/
	afx_msg BSTR LbPlay(SHORT channelSelected, SHORT playMode);
	//��̨����
	/*************command��ϸ˵��
	����//����
	0	// ��
	1	// ��
	2	// ��
	3	// ��
	4	// �䱶+
	5	// �䱶-
	6	// ����+
	7	// ����-
	8	// ��Ȧ+
	9	// ��Ȧ-
	10	// ת��Ԥ�õ�
	11	// ����
	12	// ɾ��
	13	// ���Ѳ��
	14	// �ƹ���ˢ

	32	// ����
	33	// ����
	34	// ����
	35	// ����
	36	// ����Ԥ�õ㵽Ѳ�� Ѳ����· Ԥ�õ�ֵ
	37	// ɾ��Ѳ����Ԥ�õ� Ѳ����· Ԥ�õ�ֵ
	38	// ���Ѳ�� Ѳ����·
	39	// ��ʼˮƽ��ת
	40	// ֹͣˮƽ��ת
	41	// ������߽�
	42	// �����ұ߽�
	43	// ��ʼ��ɨ
	44	// ֹͣ��ɨ
	45	// ����ģʽ��ʼ    ģʽ��·
	46	// ����ģʽ����    ģʽ��·
	47	// ����ģʽ    ģʽ��·
	48	// ֹͣģʽ    ģʽ��·
	49	// ���ģʽ    ģʽ��·
	50	// ��ת����
	51	// ���ٶ�λ ˮƽ����(8192) ��ֱ����(8192) �䱶(4)
	52	// �������ؿ� ������(param4��Ӧ PTZ_CONTROL_AUXILIARY,param1��param2��param3��Ч,dwStop����ΪFALSE)
	53	// �������ع� ������(param4��Ӧ PTZ_CONTROL_AUXILIARY,param1��param2��param3��Ч,dwStop����ΪFALSE)
	54	// ������˵�
	55	// �رղ˵�
	56	// �˵�ȷ��
	57	// �˵�ȡ��
	58	// �˵���
	59	// �˵���
	60	// �˵���
	61	// �˵���

	64	// ����������̨ parm1����������ͨ����parm2��������������1-Ԥ�õ�2-��ɨ3-Ѳ����parm3������ֵ,��Ԥ�õ��
	65	// �����л� parm1����������(��Ƶ�����)��parm2����Ƶ����ţ�parm3�������
	66	// �ƹ������
	67	// ��ά��ȷ��λ parm1��ˮƽ�Ƕ�(0~3600)��parm2����ֱ����(0~900)��parm3���䱶(1~128)
	68	// ��ά��λ������λ
	69	// �����ƶ���������,param4��Ӧ�ṹ PTZ_CONTROL_ABSOLUTELY
	70	// �����ƶ���������,param4��Ӧ�ṹ PTZ_CONTROL_CONTINUOUSLY
	71	// ��̨��������,��һ���ٶ�ת��Ԥ��λ��,parm4��Ӧ�ṹPTZ_CONTROL_GOTOPRESET

	73	// ���ÿ�����(param4��Ӧ�ṹ PTZ_VIEW_RANGE_INFO)
	74	// ���Ծ۽�(param4��Ӧ�ṹPTZ_FOCUS_ABSOLUTELY)
	75	// ˮƽ��ɨ(param4��ӦPTZ_CONTROL_SECTORSCAN,param1��param2��param3��Ч)
	76	// ��ֱ��ɨ(param4��ӦPTZ_CONTROL_SECTORSCAN,param1��param2��param3��Ч)
	77	// �趨���Խ��ࡢ�۽�ֵ,param1Ϊ����,��Χ:[0,255],param2Ϊ�۽�,��Χ:[0,255],param3��param4��Ч
	78	// �������۵�����̨,param4��Ӧ�ṹ PTZ_CONTROL_SET_FISHEYE_EPTZ
	79	// �������ʼ����(param4��Ӧ�ṹ��Ϊ PTZ_CONTROL_SET_TRACK_CONTROL,dwStop��FALSE, param1��param2��param3��Ч)
	80	// �����ֹͣ����(param4��Ӧ�ṹ��Ϊ PTZ_CONTROL_SET_TRACK_CONTROL,dwStop��FALSE,param1��param2��param3��Ч)
	81	// ��̨��������(param1��param2��param3 param4 ����Ч,dwStop����ΪFALSE)
	82	// ��̨�����ƶ�,ǹ������ר��,param4��Ӧ�ṹ PTZ_CONTROL_INTELLI_TRACKMOVE
	83	// ��������۽�����(param4��Ӧ�ṹ��ΪPTZ_CONTROL_SET_FOCUS_REGION,dwStop��FALSE,param1��param2��param3��Ч)
	84	// ��ͣ��ɨ(param1��param2��param3param4����Ч��dwStop����ΪFALSE)

	112	// �� + TELE param1=�ٶ�(1-8),��ͬ
	113	// �� + TELE
	114	// �� + TELE
	115	// �� + TELE
	116	// ���� + TELE
	117	// ���� + TELE
	118	// ���� + TELE
	119	// ���� + TELE
	120	// �� + WIDE param1=�ٶ�(1-8),��ͬ
	121	// �� + WIDE
	122	// �� + WIDE
	123	// �� + WIDE
	124	// ���� + WIDE
	125	// ���� + WIDE
	126	// ���� + WIDE
	127	// ���� + WIDE
	128	// �������ֵ
	*/
	afx_msg BSTR LbPtzCommand(LONG command, USHORT param1, USHORT param2, USHORT param3, USHORT isStop);
    //����ͨ���ţ��໭��Ԥ��ʱ����Ҫ���Ƶ�ͨ��
	afx_msg BSTR LbSetChannel(USHORT channel);
	//��ý������Ƶ������ֻ��ʵʱ�����Ч������ֵ��
	//isSuccess�Ƿ�ɹ�
	//nBrightness ����������ָ��(0 - 255)
	//	nContrast��	//	���ضԱȶ�ָ��(0 - 255)
	//	nHue��	//	����ɫ��ָ��(0 - 255)
	//nSaturation��	//	���ر��Ͷ�ָ��(0 - 255)
	BSTR LbGetVideoEffect();
	//���ý������Ƶ������ֻ��ʵʱ�����Ч��������
	//nBrightness ����������ָ��(0 - 255)
	//	nContrast��	//	���öԱȶ�ָ��(0 - 255)
	//	nHue��	//	����ɫ��ָ��(0 - 255)
	//nSaturation��	//	���ñ��Ͷ�ָ��(0 - 255)
	//����ֵ��isSuccess�Ƿ�ɹ�
	BSTR LbSetVideoEffect(SHORT nBrightness, SHORT nContrast, SHORT nHue, SHORT nSaturation);
	//�طŲ���channel��ͨ������ʼʱ�䣬����ʱ��,��ʽ��yyyy-mm-dd hh:mm��ss������ 2017-7-23 10:10:13 ����ֵisSuccess�Ƿ�ɹ�
	afx_msg BSTR LbPlayBack(SHORT channel, LPCTSTR startTime, LPCTSTR stopTime);
	//�طſ���,����command(ָ��)��������,����ֵisSuccess�Ƿ�ɹ�
	/*�������壺
	1  ��ǰ�����ٶȼ���
	2  ��ǰ�����ٶȷ���
	3  �ָ����������ٶ�
	4  ��ͣ/����
	*/
	afx_msg BSTR LbPlayBackContrl(SHORT command);
	//��ת��ָ����ʱ�䲥�ţ���λ�룬��������ʼ����ʱ��Ϊ10��10��00 ����LbPlayTime(2*60*60) ����12��10��00���� ����ֵisSuccess�Ƿ�ɹ�
	afx_msg BSTR LbPlayTime(ULONG startSecond);
	//ֹͣʵʱ���� ����ֵisSuccess�Ƿ�ɹ�
	afx_msg BSTR LbStopPlay();
	//ֹͣ�طŲ��� ����ֵisSuccess�Ƿ�ɹ�
	afx_msg BSTR LbStopBackPlay();
	//�������ʱ��
	afx_msg BSTR getLastClickTime();
	//��ʼ�Խ�
	afx_msg BSTR LbTalkStart();
	//ֹͣ�Խ�
	BSTR LbTalkStop();
// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
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


	//�����
	//enum RetIsSuccess {
	//retUnknown=-2,
	//retFail=-1,
	//retSuccess=0
	//}retIsSuccess= retUnknown;
	//CString retJson;
	CString lastClickTime="δ���";//���һ�ε�����ʱ��
	BOOL g_bNetSDKInitFlag = FALSE;
	LLONG g_lLoginHandle = 0L;
	LLONG g_lRealHandle = 0;
	LLONG g_lPlayBackHandle = 0;
	LLONG g_lTalkHandle = 0;
	int playCount = 0;
	bool isPause=false;
	CString LogInf;
	WORD channel;
	//����ȫ��
	bool isFullScreen=false;
	//	Save original window message when in full screen to restore window.
	WINDOWPLACEMENT _temppl;		//window's placement
	CWnd *			_tempparent;	//window's parent
	//****************************
	//�ຯ��
	//��ʼ��sdk
	bool InitNetSDK();
	//
	void endSdk();
	//
	void SetFullScreen(bool isFull);

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
	//�ص����������Խ�
	friend void _stdcall AudioDataCallBack(LONG lTalkHandle, char *pDataBuf, DWORD dwBufSize, BYTE byAudioFlag, DWORD dwUser);
};