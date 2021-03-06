
// Pril_TwoDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Pril_Two.h"
#include "Pril_TwoDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// диалоговое окно CPril_TwoDlg



CPril_TwoDlg::CPril_TwoDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_PRIL_TWO_DIALOG, pParent)
	, m_EditA(0)
	, m_EditB(0)
	, m_EditC(0)
	, m_message(FALSE)
	, m_Result(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPril_TwoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_A_EDIT_POLE, m_EditA);
	DDX_Text(pDX, IDC_B_EDIT_POLE, m_EditB);
	DDX_Text(pDX, IDC_C_EDIT_POLE, m_EditC);
	DDX_Check(pDX, IDC_OUT_FILE, m_message);
	DDX_Text(pDX, IDC_RESULT_STATIC, m_Result);
	DDX_Control(pDX, IDC_KVADRAT, m_Kvadrat);
	DDX_Control(pDX, IDC_BIKVADRAT, m_Bkvadrat);
}

BEGIN_MESSAGE_MAP(CPril_TwoDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_EXIT, &CPril_TwoDlg::OnBnClickedExit)
	ON_BN_CLICKED(IDC_RESHIT, &CPril_TwoDlg::OnBnClickedReshit)
	ON_BN_CLICKED(IDC_KVADRAT, &CPril_TwoDlg::OnBnClickedKvadrat)
	ON_BN_CLICKED(IDC_BIKVADRAT, &CPril_TwoDlg::OnBnClickedBikvadrat)
	ON_BN_CLICKED(IDC_OUT_FILE, &CPril_TwoDlg::OnBnClickedOutFile)
END_MESSAGE_MAP()


// обработчики сообщений CPril_TwoDlg

BOOL CPril_TwoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	m_EditA = 2;
	m_EditB = 3;
	m_EditC = -1;
	m_Kvadrat.SetCheck(1);
	m_Bkvadrat.SetCheck(0);
	UpdateData(FALSE);

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CPril_TwoDlg::OnPaint()
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
HCURSOR CPril_TwoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPril_TwoDlg::OnBnClickedExit()
{
	if (MessageBox(L"Хотите выйти?", L"Сообщение", 
		MB_YESNO | MB_ICONQUESTION) == IDYES) 
		exit(0);
}

void CPril_TwoDlg::OnBnClickedReshit()
{
	CString S = L"Корней нет";
	CString x1_s, x2_s, y1_s, y2_s, y3_s, y4_s;

	CFile file;

	double a, b, c, d, x1, x2, y1, y2, y3, y4;

	UpdateData(TRUE);

	//считываем значения a,b,c из полей редактирования
	a = m_EditA;
	b = m_EditB;
	c = m_EditC;

	//вычисляем дискриминант
	d = b*b - 4 * a*c;

	//Функция (метод) GetCheck() проверяет, выбрана ли радиокнопка,
	//в данном случае выбрана m_Kvadrat
	if (m_Kvadrat.GetCheck())
		if (d < 0)
			S = L"Корней нет\0";
		else {

			x1 = (-b + sqrt(d)) / 2 / a;
			x2 = (-b - sqrt(d)) / (2 * a);

			x1_s.Format(_T("%g"), x1);
			x2_s.Format(_T("%g"), x2);

			S = L"x1 = " + x1_s + L" x2 = " + x2_s + L"\0";

		}
	else {

		if (d<0)
			S = L"Корней нет\0";
		else {

			x1 = (-b + sqrt(d)) / 2 / a;
			x2 = (-b - sqrt(d)) / (2 * a);

			if ((x1<0) && (x2<0))
				S = L"Корней нет";

			else if ((x1 >= 0) && (x2 >= 0)) {

				y1 = sqrt(x1);
				y2 = -y1;
				y3 = sqrt(x2);
				y4 = -y3;

				y1_s.Format(_T("%g"), y1);
				y2_s.Format(_T("%g"), y2);
				y3_s.Format(_T("%g"), y3);
				y4_s.Format(_T("%g"), y4);

				S = L"Четыре корня: y1 = " + y1_s + L"\ty2 = " + y2_s + L"\ty3 = " + y3_s + L"\ty4 = " + y4_s + L"\0";
			
			}
			else if (x1 >= 0) {

				y1 = sqrt(x1);
				y2 = -y1;

				y1_s.Format(_T("%g"), y1);
				y2_s.Format(_T("%g"), y2);

				S = L"Два корня: y1 = " + y1_s + L"\ty2 = " + y2_s + L"\0";
			
			}
			else {

				y1 = sqrt(x2);
				y2 = -y1;

				y1_s.Format(_T("%g"), y1);
				y2_s.Format(_T("%g"), y2);

				S = L"Два корня: y1 = " + y1_s + L"\ty2 = " + y2_s + L"\0";
			
			}
		}
	}
	//в зависимости от флажка message
	if (m_message) {

		file.Open(L"Результаты.txt", CFile::modeWrite | CFile::modeCreate);

		file.Write(S, S.GetLength()*2);

		file.Close();
	}
	else {

		m_Result = S;
		UpdateData(FALSE);
	
	}
}

void CPril_TwoDlg::OnBnClickedKvadrat()
{
	m_Kvadrat.SetCheck(1);
	m_Bkvadrat.SetCheck(0);
}

void CPril_TwoDlg::OnBnClickedBikvadrat()
{
	m_Kvadrat.SetCheck(0);
	m_Bkvadrat.SetCheck(1);
}


void CPril_TwoDlg::OnBnClickedOutFile()
{
	UpdateData(TRUE);

	if (m_message == TRUE)
		if (MessageBox(L"Вы уверены, что хотите сохранять результат в файл?", L"Сообщение", MB_YESNO | MB_ICONQUESTION) == IDYES)
			m_message = TRUE;
		else
			m_message = FALSE;

	UpdateData(FALSE);
}
