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

	////��¼����//�ĸ������ֱ����DVRip��ַ��DVR�˿ںţ���¼������¼���롣
	//����ֵMaxChannelCount���ͨ������isSuccess�Ƿ�ɹ�-2��δ֪��δ���ã�-1��ʧ�ܣ�0���ɹ���,error������
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
	afx_msg BSTR LbPtzCommand(LONG command, USHORT param1, USHORT param2, USHORT param3, USHORT isStop);
    //����ͨ����
	afx_msg BSTR LbSetChannel(USHORT channel);
// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
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
	WORD channel;
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

	
protected:
	
	

	
	

	
};