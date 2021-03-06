
// Pril_OneDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Pril_One.h"
#include "Pril_OneDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CPril_OneDlg



CPril_OneDlg::CPril_OneDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRIL_ONE_DIALOG, pParent)
	, m_GR_EDIT_POLE(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPril_OneDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT, m_GR_EDIT_POLE);
}

BEGIN_MESSAGE_MAP(CPril_OneDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_EXIT, &CPril_OneDlg::OnBnClickedBtnExit)
	ON_BN_CLICKED(IDC_BTN_RADIAN, &CPril_OneDlg::OnBnClickedBtnRadian)
	ON_BN_CLICKED(IDC_BTN_SAVE_FILE, &CPril_OneDlg::OnBnClickedBtnSaveFile)
END_MESSAGE_MAP()


// обработчики сообщений CPril_OneDlg

BOOL CPril_OneDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	m_message = L"";

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CPril_OneDlg::OnPaint()
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
HCURSOR CPril_OneDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPril_OneDlg::OnBnClickedBtnExit()
{
	if (MessageBox(L"Хотите выйти?", L"Сообщение", 
		MB_YESNO | MB_ICONQUESTION) == IDYES)
		exit(0);
}


void CPril_OneDlg::OnBnClickedBtnRadian()
{
	UpdateData(TRUE);

	double gr = m_GR_EDIT_POLE;

	m_GR_EDIT_POLE = 0;

	UpdateData(FALSE);

	double rad = gr * 3.14 / 180;

	CString gr_s;
	CString rad_s;

	gr_s.Format(_T("%f"), gr);
	rad_s.Format(_T("%f"), rad);

	CString message = L"Результат: " + gr_s + L" градусов равно " + rad_s + L" радиан.";

	m_message = message;

	MessageBox((CString)(message), L"Результат", 
		MB_OK | MB_ICONINFORMATION);
}


void CPril_OneDlg::OnBnClickedBtnSaveFile()
{
	if (m_message == L"") {
		MessageBox(L"Не выполнено расчётов", L"Ошибка", MB_OK | MB_ICONERROR);
	}
	else {
		CFile file;

		file.Open(L"Результаты перевода.txt", CFile::modeWrite | CFile::modeCreate);

		file.Write(m_message, m_message.GetLength()*2);

		file.Close();
	}
}
