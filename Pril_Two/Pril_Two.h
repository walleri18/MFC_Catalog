
// Pril_Two.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CPril_TwoApp:
// О реализации данного класса см. Pril_Two.cpp
//

class CPril_TwoApp : public CWinApp
{
public:
	CPril_TwoApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CPril_TwoApp theApp;