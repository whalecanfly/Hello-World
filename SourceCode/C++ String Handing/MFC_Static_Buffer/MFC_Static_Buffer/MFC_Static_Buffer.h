
// MFC_Static_Buffer.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_Static_BufferApp:
// �йش����ʵ�֣������ MFC_Static_Buffer.cpp
//

class CMFC_Static_BufferApp : public CWinApp
{
public:
	CMFC_Static_BufferApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_Static_BufferApp theApp;