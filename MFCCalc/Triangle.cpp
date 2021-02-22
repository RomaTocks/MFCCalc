// Triangle.cpp: файл реализации
//

#include "pch.h"
#include "MFCCalc.h"
#include "Triangle.h"
#include "afxdialogex.h"


// Диалоговое окно Triangle

IMPLEMENT_DYNAMIC(Triangle, CDialogEx)

Triangle::Triangle(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, answerString(_T(""))
	, angleString(_T(""))
	, secondSideString(_T(""))
	, firstSideString(_T(""))
{

}

Triangle::~Triangle()
{
}

void Triangle::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT4, answer);
	DDX_Text(pDX, IDC_EDIT4, answerString);
	DDX_Text(pDX, IDC_EDIT3, angleString);
	DDX_Text(pDX, IDC_EDIT2, secondSideString);
	DDX_Text(pDX, IDC_EDIT1, firstSideString);
	DDX_Control(pDX, IDC_EDIT1, firstSideEdit);
	DDX_Control(pDX, IDC_EDIT3, angleEdit);
	DDX_Control(pDX, IDC_EDIT2, secondSideEdit);
}


BEGIN_MESSAGE_MAP(Triangle, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Triangle::OnBnClickedButton1)
END_MESSAGE_MAP()


// Обработчики сообщений Triangle


void Triangle::OnBnClickedButton1() // Посчитать площадь треугольника.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstSideEdit.GetWindowTextW(firstSideString);
	secondSideEdit.GetWindowTextW(secondSideString);
	angleEdit.GetWindowTextW(angleString);
	firstSideDouble = _wtof(firstSideString);
	secondSideDouble = _wtof(secondSideString);
	angleDouble = _wtof(angleString);
	double danswer = 0.5 * firstSideDouble * secondSideDouble * sin(angleDouble * 3.141592653589793 / 180);
	answerString.Format(L"%g", danswer);
	answer.SetWindowTextW(answerString);
}
