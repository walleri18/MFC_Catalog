
// Pril_TwoDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"

// диалоговое окно CPril_TwoDlg
class CPril_TwoDlg : public CDialogEx
{
// Создание
public:
	CPril_TwoDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRIL_TWO_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedExit();
	// Коэффициент A
	float m_EditA;
	// Коэффициент B
	float m_EditB;
	// Коэффициент C
	float m_EditC;
	// Для согласия переправки результата в файл
	BOOL m_message;
	// Переменная результата решения
	CString m_Result;
	afx_msg void OnBnClickedReshit();
	// Радиокнопка для выбора уравнения квадрата
	CButton m_Kvadrat;
	// Радиокнопка для выбора биквадратного уравнения
	CButton m_Bkvadrat;
	afx_msg void OnBnClickedKvadrat();
	afx_msg void OnBnClickedBikvadrat();
	afx_msg void OnBnClickedOutFile();
};
