
// Mouse.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CMouseApp:
// О реализации данного класса см. Mouse.cpp
//

class CMouseApp : public CWinApp
{
public:
	CMouseApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CMouseApp theApp;