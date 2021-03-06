
// Joke_scholarshipDlg.h : файл заголовка
//

#pragma once
#include "afxwin.h"
#include <cmath>
#include <ctime>
using namespace std;

// диалоговое окно CJoke_scholarshipDlg
class CJoke_scholarshipDlg : public CDialogEx
{
// Создание
public:
	CJoke_scholarshipDlg(CWnd* pParent = NULL);	// стандартный конструктор

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JOKE_SCHOLARSHIP_DIALOG };
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
	// Имя студента ННГУ им. Н. И. Лобачевского
	CString m_Name_Student;
	afx_msg void OnBnClickedBtnExit();
	afx_msg void OnEnKillfocusEditNameStudent();
	// Переменная для контроля поля для ввода
	CEdit m_EDIT_NAME_STUDENT_CONTROL;
	// Имя студента ННГУ им. Н. И. Лобачевского
	CString m_Name_Student_NNGU;
	// Переменная контроля надписи вопроса
	CStatic m_Vopros_Control;
	// Переменная контроля видимости имени студента в поле
	CStatic m_Name_Student_NNGU_Control;
	// Контролируящая переменная кнопки нет
	CButton m_BTN_NO_Control;
	// Контроль над кнопкой да
	CButton m_BTN_YES_Control;
	afx_msg void OnBnClickedBtnNo();
	afx_msg void OnBnClickedBtnYes();
};
int randPosX();
int randPosY();