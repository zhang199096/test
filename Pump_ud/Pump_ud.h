
// Pump_ud.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CPump_udApp: 
// �йش����ʵ�֣������ Pump_ud.cpp
//

class CPump_udApp : public CWinApp
{
public:
	CPump_udApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CPump_udApp theApp;