
// ControlsDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"


// диалоговое окно CControlsDlg
class CControlsDlg : public CDialogEx
{
// Создание
public:
	CControlsDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CONTROLS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// поддержка DDX/DDV


// Реализация
protected:
	HICON m_hIcon;

	// Созданные функции схемы сообщений
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	// Простое поле редактирования для ввода сообщений
	CString m_strMessage;
	// Список программ запуска
	CString m_strRun;
	// Поле ввода сообщений доступно
	BOOL m_bEnableMsg;
	// Список выполнения программ доступен
	BOOL m_bEnableProgram;
	// Поле ввода сообщений видно
	BOOL m_bShowsMsg;
	// Список выполнения программ виден
	BOOL m_bShowsProgram;
	afx_msg void OnBnClickedExit();
	afx_msg void OnBnClickedShowMsg();
	afx_msg void OnBnClickedClearMsg();
	afx_msg void OnBnClickedDefaultMsg();
	afx_msg void OnBnClickedEnableMsg();
	afx_msg void OnBnClickedEnableProgram();
	afx_msg void OnBnClickedShowsMsg();
	afx_msg void OnBnClickedShowsProgram();
	// Переменная для управления раскрывающимся списком
	CComboBox m_lstCombo;
	afx_msg void OnBnClickedRun();
};
