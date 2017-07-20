// LbNvrIpcActivex.cpp : CLbNvrIpcActivexApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "LbNvrIpcActivex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CLbNvrIpcActivexApp theApp;

const GUID CDECL _tlid = { 0x9E9BEC79, 0xE603, 0x4BC2, { 0xB0, 0xDD, 0xC5, 0x4E, 0xA6, 0x72, 0xDF, 0xBF } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CLbNvrIpcActivexApp::InitInstance - DLL 初始化

BOOL CLbNvrIpcActivexApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CLbNvrIpcActivexApp::ExitInstance - DLL 终止

int CLbNvrIpcActivexApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
