
// Circle.h : главный файл заголовка для приложения Circle
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CCircleApp:
// О реализации данного класса см. Circle.cpp
//

class CCircleApp : public CWinApp
{
public:
	CCircleApp();


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCircleApp theApp;
