// LbNvrIpcActivex.cpp : CLbNvrIpcActivexApp �� DLL ע���ʵ�֡�

#include "stdafx.h"
#include "LbNvrIpcActivex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CLbNvrIpcActivexApp theApp;

const GUID CDECL _tlid = { 0x9E9BEC79, 0xE603, 0x4BC2, { 0xB0, 0xDD, 0xC5, 0x4E, 0xA6, 0x72, 0xDF, 0xBF } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CLbNvrIpcActivexApp::InitInstance - DLL ��ʼ��

BOOL CLbNvrIpcActivexApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  �ڴ�������Լ���ģ���ʼ�����롣
	}

	return bInit;
}



// CLbNvrIpcActivexApp::ExitInstance - DLL ��ֹ

int CLbNvrIpcActivexApp::ExitInstance()
{
	// TODO:  �ڴ�������Լ���ģ����ֹ���롣

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - ������ӵ�ϵͳע���

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - �����ϵͳע������Ƴ�

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
