
// Joke_scholarship.h : главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить stdafx.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CJoke_scholarshipApp:
// О реализации данного класса см. Joke_scholarship.cpp
//

class CJoke_scholarshipApp : public CWinApp
{
public:
	CJoke_scholarshipApp();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CJoke_scholarshipApp theApp;