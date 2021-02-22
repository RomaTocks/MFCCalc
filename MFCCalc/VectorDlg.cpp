// VectorDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFCCalc.h"
#include "VectorDlg.h"
#include "afxdialogex.h"


// Диалоговое окно VectorDlg

IMPLEMENT_DYNAMIC(VectorDlg, CDialogEx)

VectorDlg::VectorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, editXString(_T(""))
	, editYString(_T(""))
	, AnswerEditString(_T(""))
{

}

VectorDlg::~VectorDlg()
{
}

void VectorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, editX);
	DDX_Control(pDX, IDC_EDIT2, editY);
	DDX_Text(pDX, IDC_EDIT1, editXString);
	DDX_Text(pDX, IDC_EDIT2, editYString);
	DDX_Control(pDX, IDC_EDIT3, editAnswer);
	DDX_Text(pDX, IDC_EDIT3, AnswerEditString);
}


BEGIN_MESSAGE_MAP(VectorDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &VectorDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений VectorDlg


void VectorDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	editX.GetWindowTextW(editXString);
	editY.GetWindowTextW(editYString);
	firstNumber = _wtof(editXString);
	secondNumber = _wtof(editYString);
	double answer = abs(sqrt(pow(firstNumber, 2) + pow(secondNumber, 2)));
	AnswerEditString.Format(L"%g", answer);
	editAnswer.SetWindowTextW(AnswerEditString);
}
