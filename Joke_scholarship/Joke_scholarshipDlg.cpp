
// Joke_scholarshipDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Joke_scholarship.h"
#include "Joke_scholarshipDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// диалоговое окно CJoke_scholarshipDlg


CJoke_scholarshipDlg::CJoke_scholarshipDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_JOKE_SCHOLARSHIP_DIALOG, pParent)
	, m_Name_Student(_T(""))
	, m_Name_Student_NNGU(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CJoke_scholarshipDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_NAME_STUDENT, m_Name_Student);
	DDV_MaxChars(pDX, m_Name_Student, 20);
	DDX_Control(pDX, IDC_EDIT_NAME_STUDENT, m_EDIT_NAME_STUDENT_CONTROL);
	DDX_Text(pDX, IDC_STATIC_NAME_STUDENT, m_Name_Student_NNGU);
	DDV_MaxChars(pDX, m_Name_Student_NNGU, 20);
	DDX_Control(pDX, IDC_STATIC_Vopros, m_Vopros_Control);
	DDX_Control(pDX, IDC_STATIC_NAME_STUDENT, m_Name_Student_NNGU_Control);
	DDX_Control(pDX, IDC_BTN_NO, m_BTN_NO_Control);
	DDX_Control(pDX, IDC_BTN_YES, m_BTN_YES_Control);
}

BEGIN_MESSAGE_MAP(CJoke_scholarshipDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_EXIT, &CJoke_scholarshipDlg::OnBnClickedBtnExit)
	ON_EN_KILLFOCUS(IDC_EDIT_NAME_STUDENT, &CJoke_scholarshipDlg::OnEnKillfocusEditNameStudent)
	ON_BN_CLICKED(IDC_BTN_NO, &CJoke_scholarshipDlg::OnBnClickedBtnNo)
	ON_BN_CLICKED(IDC_BTN_YES, &CJoke_scholarshipDlg::OnBnClickedBtnYes)
END_MESSAGE_MAP()


// обработчики сообщений CJoke_scholarshipDlg

BOOL CJoke_scholarshipDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию
	m_Name_Student = L"Введите ваше имя в Именительном падеже в это поле и нажмите Tab";

	UpdateData(FALSE);
	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CJoke_scholarshipDlg::OnPaint()
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
HCURSOR CJoke_scholarshipDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CJoke_scholarshipDlg::OnBnClickedBtnExit()
{
	if (MessageBox(L"Вы хотите выйти?", L"Выход из приложения",
		MB_YESNO | MB_ICONQUESTION) == IDYES)
		exit(0);
}


void CJoke_scholarshipDlg::OnEnKillfocusEditNameStudent()
{
	UpdateData(TRUE);

	if (m_Name_Student == L"") {
		MessageBox(L"Вы не ввели своего имени. Попробуте ещё раз", L"Предупреждение",
			MB_OK | MB_ICONWARNING);

		m_Name_Student = L"Введите ваше имя в Именительном падеже в это поле и нажмите Tab";

		UpdateData(FALSE);
	}

	else {
		if (MessageBox(L"Ваше имя: " + m_Name_Student + L" ?", L"Проверка", MB_YESNO | MB_ICONQUESTION) == IDYES) {
			
			m_EDIT_NAME_STUDENT_CONTROL.SetReadOnly();
			m_EDIT_NAME_STUDENT_CONTROL.ShowWindow(SW_HIDE);

			m_Name_Student_NNGU = m_Name_Student + L",";

			UpdateData(FALSE);

			m_Name_Student_NNGU_Control.ShowWindow(SW_SHOW);
			m_Vopros_Control.ShowWindow(SW_SHOW);

			m_BTN_NO_Control.ShowWindow(SW_SHOW);
			m_BTN_YES_Control.ShowWindow(SW_SHOW);

		}
		else {

			m_Name_Student = L"Введите ваше имя в Именительном падеже в это поле и нажмите Tab";

			UpdateData(FALSE);

		}
	}
}

void CJoke_scholarshipDlg::OnBnClickedBtnNo()
{
	m_BTN_NO_Control.MoveWindow(randPosX(), randPosY(), 50, 50, 1);
}

int randPosX()
{
	srand(time(NULL));

	int result = rand() % (320 - 0 + 1) - 0;

	return result;
}

int randPosY()
{
	srand(time(NULL));

	int result = rand() % (200 - 0 + 1) - 0;

	return result;
}

void CJoke_scholarshipDlg::OnBnClickedBtnYes()
{
	MessageBox(L"Мы так и думали)", L"Бухгалтерия", MB_OK | MB_ICONINFORMATION);
}
