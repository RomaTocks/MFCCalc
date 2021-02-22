#pragma once


// Диалоговое окно VectorDlg

class VectorDlg : public CDialogEx
{
	DECLARE_DYNAMIC(VectorDlg)

public:
	VectorDlg(CWnd* pParent = nullptr);   // стандартный конструктор
	virtual ~VectorDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	// X
	CEdit editX;
	// Y
	CEdit editY;
	// X String.
	CString editXString;
	// Y String
	CString editYString;
	double firstNumber;
	double secondNumber;
	afx_msg void OnBnClickedButton1();
	// Answer Edit.
	CEdit editAnswer;
	// Answer String.
	CString AnswerEditString;
};
