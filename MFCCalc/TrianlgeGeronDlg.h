#pragma once


// Диалоговое окно TrianlgeGeronDlg

class TrianlgeGeronDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TrianlgeGeronDlg)

public:
	TrianlgeGeronDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~TrianlgeGeronDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// Поле первой стороны.
	CEdit firstSideEdit;
	// Поле второй стороны.
	CEdit secondSideEdit;
	// Поле третьей стороны.
	CEdit thirdSideEdit;
	// Значение первой стороны.
	CString firstSideString;
	// Значение второй стороны.
	CString secondSideString;
	// Значение третьей стороны.
	CString thirdSideString;
	// Поле ответа.
	CEdit answer;
	// Значение ответа.
	CString answerString;
	double firstSideDouble;
	double secondSideDouble;
	double thirdSideDouble;
	afx_msg void OnBnClickedButton1();
};
