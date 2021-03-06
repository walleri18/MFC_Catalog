
// Pril_OneDlg.h : файл заголовка
//

#pragma once


// диалоговое окно CPril_OneDlg
class CPril_OneDlg : public CDialogEx
{
// Создание
public:
	CPril_OneDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PRIL_ONE_DIALOG };
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
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnBnClickedBtnRadian();
	// Переменная для принятия градусов, для их перевода в радианы
	double m_GR_EDIT_POLE;
	// Переменная для передачи данных для сохранения в файл
	CString m_message;
	afx_msg void OnBnClickedBtnSaveFile();
};
