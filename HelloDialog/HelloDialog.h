
// HelloDialog.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CHelloDialogApp:
// О реализации данного класса см. HelloDialog.cpp
//

class CHelloDialogApp : public CWinApp
{
public:
	CHelloDialogApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CHelloDialogApp theApp;