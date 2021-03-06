
// MouseDlg.cpp : файл реализации
//

#include "stdafx.h"
#include "Mouse.h"
#include "MouseDlg.h"
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


// диалоговое окно CMouseDlg



CMouseDlg::CMouseDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MOUSE_DIALOG, pParent)
	, m_iPrevX(0)
	, m_iPrevY(0)
	, m_bMyCursor(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMouseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMouseDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_KEYDOWN()
	ON_WM_SETCURSOR()
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()


// обработчики сообщений CMouseDlg

BOOL CMouseDlg::OnInitDialog()
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
	// Инициализировать курсор по умолчанию
	m_bMyCursor = false;

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMouseDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMouseDlg::OnPaint()
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
HCURSOR CMouseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMouseDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// Выяснить, нажата ли левая кнопка мыши
	if ((nFlags & MK_LBUTTON) == MK_LBUTTON) {
		// Создать объект контекста устройства
		CClientDC dc(this);

		// Создать новое перо (solid, 10 pixels, red)
		CPen newPen(PS_SOLID,
			10,
			RGB(255, 0, 0));
		// Установить новое перо текущим
		dc.SelectObject(&newPen);

		// Нарисовать точку в текущей позиции курсора
		//	dc.SetPixel(point.x, 
		//				point.y, 
		//				RGB(0, 0, 0));

		// Провести линию от предыдущей точки до текущей
		dc.MoveTo(m_iPrevX, m_iPrevY); // поместить графический курсор
		dc.LineTo(point.x, point.y); // рисовать до текущей
	}
	else if ((nFlags & MK_RBUTTON) == MK_RBUTTON) {
		// Создать объект контекста устройства
		CClientDC dc(this);

		// Создать новое перо (solid, 10 pixels, red)
		CPen newPen(PS_SOLID,
			10,
			RGB(0, 0, 255));
		// Установить новое перо текущим
		dc.SelectObject(&newPen);

		// Нарисовать точку в текущей позиции курсора
		//	dc.SetPixel(point.x, 
		//				point.y, 
		//				RGB(0, 0, 0));

		// Провести линию от предыдущей точки до текущей
		dc.MoveTo(m_iPrevX, m_iPrevY); // поместить графический курсор
		dc.LineTo(point.x, point.y); // рисовать до текущей
	}
		// Обновить предыдущую точку для нового кванта времени
		m_iPrevX = point.x;
		m_iPrevY = point.y;
	

	CDialogEx::OnMouseMove(nFlags, point);
}


void CMouseDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// Установить текущую точку в качестве исходной
	m_iPrevX = point.x;
	m_iPrevY = point.y;

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CMouseDlg::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	char ch; // текущий нажимаемый символ
	HCURSOR hCursor = 0; // дескриптор курсора, который будет отображен
	HCURSOR hPrevCursor = 0; // дескриптор предыдущего курсора

	// Преобразовать нажатую клавишу в символ
	ch = char(nChar); // символ
	bool endFlag = false; // Выход	

	switch (ch) {
		// Курсор в виде стрелки
	case 'A': // латинская заглавная
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		break;

		// Курсор в виде текстового указателя
	case 'B': // латинская заглавная
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_IBEAM);
		break;

		// Курсор в форме песочных часов
	case 'C': // латинская заглавная
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_WAIT);
		break;

		// Курсор в форме прицела
	case 'D':
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_CROSS);
		break;

		// Курсор в форме стрелки вверх
	case 'G':
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_UPARROW);
		break;

		// Курсор в форме для перемещения окна
	case 'H':
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_SIZEALL);
		break;

		// Курсор в форме для растягивания в лево-вверх
	case 'J':
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_SIZENWSE);
		break;

		// Курсор в форме для растягивания в право-вверх
	case 'K':
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_SIZENESW);
		break;

		// Курсор в форме для растягивания по бокам
	case 'L':
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_SIZEWE);
		break;

		// Курсор в форме для растягивания по верхам
	case 'O':
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_SIZENS);
		break;

		// Курсор в форме запрещающего знака
	case 'P':
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_NO);
		break;

		// Курсор в форме начало загрузки
	case 'I':
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_APPSTARTING);
		break;

		// Курсор в форме знака вопроса
	case 'U':
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_HELP);
		break;

		// Восстановить курсор в виде стрелки
	case 'E': // латинская заглавная
		hCursor = AfxGetApp()->LoadStandardCursor(IDC_ARROW);
		endFlag = true;
	}

	hPrevCursor = hCursor ? SetCursor(hCursor) : 0;
	if (hCursor) {// Уничтожить предыдущий курсор для освобождения ресурсов
		DestroyCursor(hPrevCursor);
		hCursor = 0;
		m_bMyCursor = true; // Курсор изменили
	}

	if (endFlag)
		OnOK();

	CDialogEx::OnKeyDown(nChar, nRepCnt, nFlags);
}


BOOL CMouseDlg::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message)
{
	if (m_bMyCursor)
		return TRUE; // Выйти без выполнения нижнего кода

	return CDialogEx::OnSetCursor(pWnd, nHitTest, message);
}


void CMouseDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// Установить текущую точку в качестве исходной
	m_iPrevX = point.x;
	m_iPrevY = point.y;

	CDialogEx::OnRButtonDown(nFlags, point);
}
