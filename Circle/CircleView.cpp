
// CircleView.cpp : реализация класса CCircleView
//

#include "stdafx.h"
// SHARED_HANDLERS можно определить в обработчиках фильтров просмотра реализации проекта ATL, эскизов
// и поиска; позволяет совместно использовать код документа в данным проекте.
#ifndef SHARED_HANDLERS
#include "Circle.h"
#endif

#include "CircleDoc.h"
#include "CircleView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCircleView

IMPLEMENT_DYNCREATE(CCircleView, CView)

BEGIN_MESSAGE_MAP(CCircleView, CView)
	// Стандартные команды печати
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()

// создание/уничтожение CCircleView

CCircleView::CCircleView()
{
	// TODO: добавьте код создания

}

CCircleView::~CCircleView()
{
}

BOOL CCircleView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: изменить класс Window или стили посредством изменения
	//  CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// рисование CCircleView

void CCircleView::OnDraw(CDC* pDC)
{
	CCircleDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: добавьте здесь код отрисовки для собственных данных

	// Задать границы описывающего прямоугольника, 
	// в котором будет нарисован круг
	CRect rect;
	rect.left = m_PosX - 20;
	rect.top = m_PosY - 20;
	rect.right = m_PosX + 20;
	rect.bottom = m_PosY + 20;

	// Нарисовать круг на контексте устройства
	pDC->Ellipse(&rect);

	// Вывод текста в центре клиентской области окна-рамки
	GetWindowRect(&rect); // определение размеров клиентской области
	CSize size = pDC->GetTextExtent(pDoc->m_strText); // размеры текста
	int width = rect.right - rect.left; // ширина клиентской области
	int height = rect.bottom - rect.top;// высота клиентской области
	int x = (width - size.cx) / 2; // позиция вывода по ширине
	int y = (height - size.cy) / 2; // позиция вывода по высоте

	pDC->TextOut(x, y, pDoc->m_strText); // вывод строки с текстом
}


// печать CCircleView

BOOL CCircleView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// подготовка по умолчанию
	return DoPreparePrinting(pInfo);
}

void CCircleView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте дополнительную инициализацию перед печатью
}

void CCircleView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: добавьте очистку после печати
}


// диагностика CCircleView

#ifdef _DEBUG
void CCircleView::AssertValid() const
{
	CView::AssertValid();
}

void CCircleView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCircleDoc* CCircleView::GetDocument() const // встроена неотлаженная версия
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCircleDoc)));

	return (CCircleDoc*)m_pDocument;
}
#endif //_DEBUG


// обработчики сообщений CCircleView


void CCircleView::OnInitialUpdate()
{
	CView::OnInitialUpdate();

	m_PosX = GetDocument()->m_PosX;
	m_PosY = GetDocument()->m_PosY;
}


void CCircleView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: добавьте свой код обработчика сообщений или вызов стандартного

	// Обновить координаты центра круга
	// координатами места щелчка курсора 
	m_PosX = point.x;
	m_PosY = point.y;

	// Инициировать перерисовку экрана вызовом функции OnDraw()
	Invalidate();

	// Передать новые координаты щелчка в класс CCircleDoc 
	CCircleDoc* pDoc = GetDocument();
	pDoc->m_PosX = m_PosX;			// Через промежуточный указатель
	GetDocument()->m_PosY = m_PosY; // Напрямую

	// Установить флажок изменения Документа
	pDoc->SetModifiedFlag(TRUE);

	CView::OnLButtonDown(nFlags, point);
}
