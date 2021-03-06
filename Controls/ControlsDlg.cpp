
// ControlsDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Controls.h"
#include "ControlsDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// диалоговое окно CControlsDlg



CControlsDlg::CControlsDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CONTROLS_DIALOG, pParent)
	, m_strMessage(_T(""))
	, m_strRun(_T(""))
	, m_bEnableMsg(FALSE)
	, m_bEnableProgram(FALSE)
	, m_bShowsMsg(FALSE)
	, m_bShowsProgram(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CControlsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_MSG, m_strMessage);
	DDX_CBString(pDX, IDC_COMBO_RUN, m_strRun);
	DDX_Check(pDX, IDC_ENABLE_MSG, m_bEnableMsg);
	DDX_Check(pDX, IDC_ENABLE_PROGRAM, m_bEnableProgram);
	DDX_Check(pDX, IDC_SHOWS_MSG, m_bShowsMsg);
	DDX_Check(pDX, IDC_SHOWS_PROGRAM, m_bShowsProgram);
	DDX_Control(pDX, IDC_COMBO_RUN, m_lstCombo);
}

BEGIN_MESSAGE_MAP(CControlsDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CControlsDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_SHOW_MSG, &CControlsDlg::OnBnClickedShowMsg)
	ON_BN_CLICKED(IDC_CLEAR_MSG, &CControlsDlg::OnBnClickedClearMsg)
	ON_BN_CLICKED(IDC_DEFAULT_MSG, &CControlsDlg::OnBnClickedDefaultMsg)
	ON_BN_CLICKED(IDC_ENABLE_MSG, &CControlsDlg::OnBnClickedEnableMsg)
	ON_BN_CLICKED(IDC_ENABLE_PROGRAM, &CControlsDlg::OnBnClickedEnableProgram)
	ON_BN_CLICKED(IDC_SHOWS_MSG, &CControlsDlg::OnBnClickedShowsMsg)
	ON_BN_CLICKED(IDC_SHOWS_PROGRAM, &CControlsDlg::OnBnClickedShowsProgram)
	ON_BN_CLICKED(IDC_RUN, &CControlsDlg::OnBnClickedRun)
END_MESSAGE_MAP()


// обработчики сообщений CControlsDlg

BOOL CControlsDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	// Установить список в начало
	m_lstCombo.SetCurSel(0);
	UpdateData(TRUE);  // скачать из списка в переменную m_strRun

	// Поместить заданное по умолчанию значение
	// в поле редактирования Edit Control
	m_strMessage = L"Привет студентам!!!";

	// Установить все флажки
	m_bEnableMsg = TRUE;
	m_bEnableProgram = TRUE;
	m_bShowsMsg = TRUE;
	m_bShowsProgram = TRUE;

	// FALSE - передать значения из переменных в элементы управления
	// TRUE - передать значения из элементов управления в переменные
	UpdateData(FALSE);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CControlsDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CControlsDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CControlsDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CControlsDlg::OnBnClickedExit()
{
	OnOK();
}


void CControlsDlg::OnBnClickedShowMsg()
{
	// Передать видимое на экране значение поля ввода в переменную
	UpdateData(TRUE);

	// Отобразить сообщение для пользователя
	MessageBox(m_strMessage, L"Сообщение от пользователя", 
		MB_OK | MB_ICONINFORMATION);
}


void CControlsDlg::OnBnClickedClearMsg()
{
	// Очистить сообщение
	m_strMessage = "";

	// Обновить экран
	UpdateData(FALSE);
}


void CControlsDlg::OnBnClickedDefaultMsg()
{
	// Задать сообщение по умолчанию
	m_strMessage = L"Привет студентам!!!";

	// Обновить экран
	UpdateData(FALSE);
}


void CControlsDlg::OnBnClickedEnableMsg()
{
	// Получить текущие значения от экрана
	UpdateData(TRUE);

	if (m_bEnableMsg == TRUE) { // Флажок "Разрешить сообщение" установлен
								// Включить все элементы управления,
								// имеющие отношение к отображению сообщений
		GetDlgItem(IDC_STATIC_MSG)->EnableWindow(TRUE);  // надпись "Ввести сообщение"
		GetDlgItem(IDC_MSG)->EnableWindow(TRUE);    // поле ввода
		GetDlgItem(IDC_SHOW_MSG)->EnableWindow(TRUE);  // кнопка "Отобразить сообщение"
		GetDlgItem(IDC_DEFAULT_MSG)->EnableWindow(TRUE);// кнопка "Сообщение по умолчанию"
		GetDlgItem(IDC_CLEAR_MSG)->EnableWindow(TRUE);  // кнопка "Очистить сообщение"
	}
	else {
		// Выключить все элементы управления,
		// имеющие отношение к отображению сообщений
		CWnd *pWnd;  // Указатель на оконный базовый класс MFC
					 // Переменная-указатель локальный внутри блока кода else

		pWnd = GetDlgItem(IDC_STATIC_MSG);
		pWnd->EnableWindow(FALSE);  // надпись "Ввести сообщение"

		pWnd = GetDlgItem(IDC_MSG);
		pWnd->EnableWindow(FALSE);  // поле ввода

		pWnd = GetDlgItem(IDC_SHOW_MSG);
		pWnd->EnableWindow(FALSE);  // кнопка "Отобразить сообщение"

		pWnd = GetDlgItem(IDC_DEFAULT_MSG);
		pWnd->EnableWindow(FALSE);  // кнопка "Сообщение по умолчанию"

		pWnd = GetDlgItem(IDC_CLEAR_MSG);
		pWnd->EnableWindow(FALSE);  // кнопка "Очистить сообщение"
	}
}


void CControlsDlg::OnBnClickedEnableProgram()
{
	// Получить текущие значения от экрана
	UpdateData(TRUE);
	CWnd *pWnd;  // Указатель на оконный базовый класс MFC
				 // Переменная-указатель локальный внутри функции

	if (m_bEnableProgram == TRUE) { // Флажок "Разрешить выполнение" установлен
									// Включить все элементы управления,
									// имеющие отношение к отображению выполнений
		pWnd = GetDlgItem(IDC_STATIC_PROGRAM);
		pWnd->EnableWindow(TRUE);  // надпись "Запустить программу"

		pWnd = GetDlgItem(IDC_COMBO_RUN);
		pWnd->EnableWindow(TRUE);  // раскрывающийся список

		pWnd = GetDlgItem(IDC_RUN);
		pWnd->EnableWindow(TRUE);  // кнопка "Выполнить"
	}
	else {
		// Выключить все элементы управления,
		// имеющие отношение к отображению выполнений
		GetDlgItem(IDC_STATIC_PROGRAM)->EnableWindow(0);// надпись "Запустить программу"
		GetDlgItem(IDC_COMBO_RUN)->EnableWindow(0);  // раскрывающийся список
		GetDlgItem(IDC_RUN)->EnableWindow(0);    // кнопка "Выполнить"
	}
}


void CControlsDlg::OnBnClickedShowsMsg()
{
	// Получить текущие значения от экрана
	UpdateData(TRUE);

	if (m_bShowsMsg == TRUE) { // Флажок "Отображать сообщения" установлен
							   // Нарисовать все элементы управления,
							   // имеющие отношение к отображению сообщений
		GetDlgItem(IDC_STATIC_MSG)->ShowWindow(TRUE);  // надпись "Ввести сообщение"
		GetDlgItem(IDC_MSG)->ShowWindow(TRUE);    // поле ввода
		GetDlgItem(IDC_SHOW_MSG)->ShowWindow(TRUE);  // кнопка "Отобразить сообщение"
		GetDlgItem(IDC_DEFAULT_MSG)->ShowWindow(TRUE);  // кнопка "Сообщение по умолчанию"
		GetDlgItem(IDC_CLEAR_MSG)->ShowWindow(TRUE);  // кнопка "Очистить сообщение"
	}
	else {
		// Скрыть все элементы управления,
		// имеющие отношение к отображению сообщений
		GetDlgItem(IDC_STATIC_MSG)->ShowWindow(FALSE);  // надпись "Ввести сообщение"
		GetDlgItem(IDC_MSG)->ShowWindow(FALSE);    // поле ввода
		GetDlgItem(IDC_SHOW_MSG)->ShowWindow(FALSE);  // кнопка "Отобразить сообщение"
		GetDlgItem(IDC_DEFAULT_MSG)->ShowWindow(FALSE);  // кнопка "Сообщение по умолчанию"
		GetDlgItem(IDC_CLEAR_MSG)->ShowWindow(FALSE);  // кнопка "Очистить сообщение"
	}
}


void CControlsDlg::OnBnClickedShowsProgram()
{
	// Получить текущие значения от экрана
	UpdateData(TRUE);

	if (m_bShowsProgram == TRUE) { // Флажок "Отображать выполнение" установлен
								   // Нарисовать все элементы управления,
								   // имеющие отношение к отображению выполнений
		GetDlgItem(IDC_STATIC_PROGRAM)->ShowWindow(TRUE);  // надпись "Запустить программу"
		GetDlgItem(IDC_COMBO_RUN)->ShowWindow(TRUE);    // раскрывающийся список
		GetDlgItem(IDC_RUN)->ShowWindow(TRUE);      // кнопка "Выполнить"
	}
	else {
		// Скрыть все элементы управления,
		// имеющие отношение к отображению выполнений
		GetDlgItem(IDC_STATIC_PROGRAM)->ShowWindow(FALSE);  // надпись "Запустить программу"
		GetDlgItem(IDC_COMBO_RUN)->ShowWindow(FALSE);    // раскрывающийся список
		GetDlgItem(IDC_RUN)->ShowWindow(FALSE);      // кнопка "Выполнить"
	}
}


void CControlsDlg::OnBnClickedRun()
{
	// Передать текущие значения элементов управления в переменные
	UpdateData(TRUE);
	// Объявить локальную переменную для хранения названия программы
	CString strName;
	// Копировать текущее поле списка в локальную переменную
	strName = m_strRun;
	// Перевести название программы в верхний регистр
	strName.MakeUpper();
	
	LPCSTR nameProgram = (LPCSTR)strName.GetBuffer();

	
	int error = WinExec(nameProgram, SW_RESTORE);
	switch (error) {
	case 0:
		MessageBox(L"Не хватает памяти или ресурсов!",
			L"Ошибка!", MB_OK | MB_ICONINFORMATION);
		break;

	case ERROR_BAD_FORMAT:
		MessageBox(L"Ошибочный файл!",
			L"Ошибка!", MB_OK | MB_ICONINFORMATION);
		break;

	case ERROR_FILE_NOT_FOUND:
		MessageBox(L"Файл не найден!",
			L"Ошибка!", MB_OK | MB_ICONINFORMATION);
		break;

	case ERROR_PATH_NOT_FOUND:
		MessageBox(L"Путь не найден!",
			L"Ошибка!", MB_OK | MB_ICONINFORMATION);
	}
	
}
