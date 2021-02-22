#pragma once


// Диалоговое окно Triangle

class Triangle : public CDialogEx
{
	DECLARE_DYNAMIC(Triangle)

public:
	Triangle(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~Triangle();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	// //Поле ответа.
	CEdit answer;
	// Значение поля ответа.
	CString answerString;
	// Значение поля угла.
	CString angleString;
	// Значение второй стороны.
	CString secondSideString;
	// Значение первой стороны.
	CString firstSideString;
	double firstSideDouble;
	double secondSideDouble;
	double angleDouble;
	// Поле первого значения.
	CEdit firstSideEdit;
	// Поле угла.
	CEdit angleEdit;
	// Поле второй стороны.
	CEdit secondSideEdit;
};
