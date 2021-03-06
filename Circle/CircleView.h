
// CircleView.h : интерфейс класса CCircleView
//

#pragma once


class CCircleView : public CView
{
protected: // создать только из сериализации
	CCircleView();
	DECLARE_DYNCREATE(CCircleView)

// Атрибуты
public:
	CCircleDoc* GetDocument() const;
	int m_PosX; // координата x (по горизонтали) центра круга
	int m_PosY; // координата y (по вертикали) центра круга

// Операции
public:

// Переопределение
public:
	virtual void OnDraw(CDC* pDC);  // переопределено для отрисовки этого представления
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Реализация
public:
	virtual ~CCircleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Созданные функции схемы сообщений
protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // отладочная версия в CircleView.cpp
inline CCircleDoc* CCircleView::GetDocument() const
   { return reinterpret_cast<CCircleDoc*>(m_pDocument); }
#endif

