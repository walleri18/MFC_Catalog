
// Pril_One.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CPril_OneApp:
// О реализации данного класса см. Pril_One.cpp
//

class CPril_OneApp : public CWinApp
{
public:
	CPril_OneApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CPril_OneApp theApp;