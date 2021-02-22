// TrianlgeGeronDlg.cpp: файл реализации
//

#include "pch.h"
#include "MFCCalc.h"
#include "TrianlgeGeronDlg.h"
#include "afxdialogex.h"


// Диалоговое окно TrianlgeGeronDlg

IMPLEMENT_DYNAMIC(TrianlgeGeronDlg, CDialogEx)

TrianlgeGeronDlg::TrianlgeGeronDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, firstSideString(_T(""))
	, secondSideString(_T(""))
	, thirdSideString(_T(""))
	, answerString(_T(""))
{

}

TrianlgeGeronDlg::~TrianlgeGeronDlg()
{
}

void TrianlgeGeronDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, firstSideEdit);
	DDX_Control(pDX, IDC_EDIT2, secondSideEdit);
	DDX_Control(pDX, IDC_EDIT3, thirdSideEdit);
	DDX_Text(pDX, IDC_EDIT1, firstSideString);
	DDX_Text(pDX, IDC_EDIT2, secondSideString);
	DDX_Text(pDX, IDC_EDIT3, thirdSideString);
	DDX_Control(pDX, IDC_EDIT4, answer);
	DDX_Text(pDX, IDC_EDIT4, answerString);
}


BEGIN_MESSAGE_MAP(TrianlgeGeronDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TrianlgeGeronDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений TrianlgeGeronDlg


void TrianlgeGeronDlg::OnBnClickedButton1()
{
	// TODO: добавьте свой код обработчика уведомлений
	firstSideEdit.GetWindowTextW(firstSideString);
	secondSideEdit.GetWindowTextW(secondSideString);
	thirdSideEdit.GetWindowTextW(thirdSideString);

	firstSideDouble = _wtof(firstSideString);
	secondSideDouble = _wtof(secondSideString);
	thirdSideDouble = _wtof(thirdSideString);

	double p = 0.5 * (firstSideDouble + secondSideDouble + thirdSideDouble);
	double danswer = sqrt(p * (p - firstSideDouble) * (p - secondSideDouble) * (p - thirdSideDouble));

	answerString.Format(L"%g", danswer);
	answer.SetWindowTextW(answerString);
}
