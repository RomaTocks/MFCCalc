
// MFCCalcDlg.cpp: файл реализации
//

#include "pch.h"
#include "framework.h"
#include "MFCCalc.h"
#include "MFCCalcDlg.h"
#include "Triangle.h"
#include "TrianlgeGeronDlg.h"
#include "VectorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Диалоговое окно CAboutDlg используется для описания сведений о приложении

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Данные диалогового окна
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

// Реализация
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Диалоговое окно CMFCCalcDlg



CMFCCalcDlg::CMFCCalcDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCALC_DIALOG, pParent)
	, editString(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, edit);
	DDX_Text(pDX, IDC_EDIT1, editString);
	DDX_Control(pDX, IDC_BUTTON15, equal);
}

BEGIN_MESSAGE_MAP(CMFCCalcDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCCalcDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCCalcDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCCalcDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCCalcDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCCalcDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCCalcDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCCalcDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCCalcDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCCalcDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCCalcDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCCalcDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON15, &CMFCCalcDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCCalcDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCCalcDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON13, &CMFCCalcDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON16, &CMFCCalcDlg::OnBnClickedButton16)
	ON_BN_CLICKED(IDC_BUTTON17, &CMFCCalcDlg::OnBnClickedButton17)
	ON_BN_CLICKED(IDC_BUTTON18, &CMFCCalcDlg::OnBnClickedButton18)
	ON_BN_CLICKED(IDC_BUTTON19, &CMFCCalcDlg::OnBnClickedButton19)
	ON_BN_CLICKED(IDC_BUTTON20, &CMFCCalcDlg::OnBnClickedButton20)
	ON_BN_CLICKED(IDC_BUTTON21, &CMFCCalcDlg::OnBnClickedButton21)
	ON_BN_CLICKED(IDC_BUTTON22, &CMFCCalcDlg::OnBnClickedButton22)
	ON_BN_CLICKED(IDC_BUTTON23, &CMFCCalcDlg::OnBnClickedButton23)
	ON_BN_CLICKED(IDC_BUTTON28, &CMFCCalcDlg::OnBnClickedButton28)
	ON_BN_CLICKED(IDC_BUTTON29, &CMFCCalcDlg::OnBnClickedButton29)
	ON_BN_CLICKED(IDC_BUTTON24, &CMFCCalcDlg::OnBnClickedButton24)
	ON_BN_CLICKED(IDC_BUTTON25, &CMFCCalcDlg::OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON26, &CMFCCalcDlg::OnBnClickedButton26)
	ON_BN_CLICKED(IDC_BUTTON27, &CMFCCalcDlg::OnBnClickedButton27)
	ON_BN_CLICKED(IDC_BUTTON30, &CMFCCalcDlg::OnBnClickedButton30)
	ON_ACN_START(IDC_ANIMATE1, &CMFCCalcDlg::OnAcnStartAnimate1)
	ON_COMMAND(ID_32771, &CMFCCalcDlg::On32771)
	ON_COMMAND(ID_32773, &CMFCCalcDlg::On32773)
	ON_COMMAND(ID_32777, &CMFCCalcDlg::On32777)
END_MESSAGE_MAP()


// Обработчики сообщений CMFCCalcDlg

BOOL CMFCCalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Добавление пункта "О программе..." в системное меню.

	// IDM_ABOUTBOX должен быть в пределах системной команды.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Задает значок для этого диалогового окна.  Среда делает это автоматически,
	//  если главное окно приложения не является диалоговым
	SetIcon(m_hIcon, TRUE);			// Крупный значок
	SetIcon(m_hIcon, FALSE);		// Мелкий значок

	// TODO: добавьте дополнительную инициализацию

	return TRUE;  // возврат значения TRUE, если фокус не передан элементу управления
}

void CMFCCalcDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// При добавлении кнопки свертывания в диалоговое окно нужно воспользоваться приведенным ниже кодом,
//  чтобы нарисовать значок.  Для приложений MFC, использующих модель документов или представлений,
//  это автоматически выполняется рабочей областью.

void CMFCCalcDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // контекст устройства для рисования

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Выравнивание значка по центру клиентского прямоугольника
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Нарисуйте значок
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Система вызывает эту функцию для получения отображения курсора при перемещении
//  свернутого окна.
HCURSOR CMFCCalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCCalcDlg::OnBnClickedButton14() // Очистить.
{
	firstNumber = 0;
	secondNumber = 0;
	editString.SetString(L"");
	edit.SetWindowTextW(editString);
	equal.SetWindowTextW(L"=");
}


void CMFCCalcDlg::OnBnClickedButton1() // 1
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L"1");
	edit.SetWindowTextW(editString);
}


void CMFCCalcDlg::OnBnClickedButton2() // 2
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L"2");
	edit.SetWindowTextW(editString);
}


void CMFCCalcDlg::OnBnClickedButton3() // 3
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L"3");
	edit.SetWindowTextW(editString); 
}


void CMFCCalcDlg::OnBnClickedButton4() // 4
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L"4");
	edit.SetWindowTextW(editString);
}


void CMFCCalcDlg::OnBnClickedButton5() // 5
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L"5");
	edit.SetWindowTextW(editString);
}


void CMFCCalcDlg::OnBnClickedButton6() // 6
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L"6");
	edit.SetWindowTextW(editString);
}


void CMFCCalcDlg::OnBnClickedButton7() // 7
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L"7");
	edit.SetWindowTextW(editString);
}


void CMFCCalcDlg::OnBnClickedButton8() // 8
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L"8");
	edit.SetWindowTextW(editString);
}


void CMFCCalcDlg::OnBnClickedButton9() // 9
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L"9");
	edit.SetWindowTextW(editString);
}

void CMFCCalcDlg::OnBnClickedButton16() // 0
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L"0");
	edit.SetWindowTextW(editString);
}

void CMFCCalcDlg::OnBnClickedButton17() //.
{
	// TODO: добавьте свой код обработчика уведомлений
	editString.Append(L".");
	edit.SetWindowTextW(editString);
}

void CMFCCalcDlg::OnBnClickedButton10() // Сложить.
{
	// TODO: добавьте свой код обработчика уведомлений
	if (firstNumber != 0)
	{
		if (editString == L"inf")
		{
			editString.SetString(L"0");
		}
		else
		{
			secondNumber = _wtof(editString);
		}
		firstNumber += secondNumber;
		editString.Format(L"%g", firstNumber);
		edit.SetWindowTextW(editString);
		firstNumber = 0;
		secondNumber = 0;
	}
	else
	{
		if (editString == L"inf")
		{
			editString.SetString(L"0");
		}
		else
		{
			firstNumber = _wtof(editString);
		}
		editString.SetString(L"");
		edit.SetWindowTextW(editString);
		enumerate = plus;
	}

}

void CMFCCalcDlg::OnBnClickedButton11() // Минус.
{
	// TODO: добавьте свой код обработчика уведомлений
		// TODO: добавьте свой код обработчика уведомлений
	if (firstNumber != 0)
	{
		if (editString == L"inf")
		{
			editString.SetString(L"0");
		}
		else
		{
			secondNumber = _wtof(editString);
		}
		firstNumber -= secondNumber;
		editString.Format(L"%g", firstNumber);
		edit.SetWindowTextW(editString);
		firstNumber = 0;
		secondNumber = 0;
	}
	else
	{
		if (editString == L"inf")
		{
			editString.SetString(L"0");
		}
		else
		{
			firstNumber = _wtof(editString);
		}
		editString.SetString(L"");
		edit.SetWindowTextW(editString);
		enumerate = minus;
	}
}

void CMFCCalcDlg::OnBnClickedButton12() // Умножение.
{
	// TODO: добавьте свой код обработчика уведомлений
	if (firstNumber != 0)
	{
		if (editString == L"inf")
		{
			editString.SetString(L"0");
		}
		else
		{
			secondNumber = _wtof(editString);
		}
		firstNumber *= secondNumber;
		editString.Format(L"%g", firstNumber);
		edit.SetWindowTextW(editString);
		firstNumber = 0;
		secondNumber = 0;
	}
	else
	{
		if (editString == L"inf")
		{
			editString.SetString(L"0");
		}
		else
		{
			firstNumber = _wtof(editString);
		}
		editString.SetString(L"");
		edit.SetWindowTextW(editString);
		enumerate = multiply;
	}
}

void CMFCCalcDlg::OnBnClickedButton13() // Деление.
{
	// TODO: добавьте свой код обработчика уведомлений
	if (firstNumber != 0)
	{
		if (editString == L"inf")
		{
			editString.SetString(L"0");
		}
		else
		{
			secondNumber = _wtof(editString);
		}
		firstNumber /= secondNumber;
		editString.Format(L"%g", firstNumber);
		edit.SetWindowTextW(editString);
		firstNumber = 0;
		secondNumber = 0;
	}
	else
	{
		firstNumber = _wtof(editString);
		editString.SetString(L"");
		edit.SetWindowTextW(editString);
		enumerate = divide;
	}
}

void CMFCCalcDlg::OnBnClickedButton15() // Равно.
{
	// TODO: добавьте свой код обработчика уведомлений
	if (editString == L"inf")
	{
		editString.SetString(L"0");
	}
	else
	{
		secondNumber = _wtof(editString);
	}
	if (enumerate == plus)
	{
		firstNumber += secondNumber;
		if (firstNumber == 300)
		{
			equal.SetWindowTextW(L"Я не люблю MFC.");
		}
		editString.Format(L"%g", firstNumber);
		edit.SetWindowTextW(editString);
		firstNumber = 0;
		secondNumber = 0;
	}
	if (enumerate == minus)
	{
		firstNumber -= secondNumber;
		editString.Format(L"%g", firstNumber);
		edit.SetWindowTextW(editString);
		firstNumber = 0;
		secondNumber = 0;
	}
	if (enumerate == multiply)
	{
		firstNumber *= secondNumber;
		editString.Format(L"%g", firstNumber);
		edit.SetWindowTextW(editString);
		firstNumber = 0;
		secondNumber = 0;
	}
	if (enumerate == divide)
	{
		firstNumber /= secondNumber;
		editString.Format(L"%g", firstNumber);
		edit.SetWindowTextW(editString);
		firstNumber = 0;
		secondNumber = 0;
	}
	if (enumerate == power)
	{
		firstNumber = pow(firstNumber, secondNumber);
		editString.Format(L"%g", firstNumber);
		edit.SetWindowTextW(editString);
		firstNumber = 0;
		secondNumber = 0;
	}
}

void CMFCCalcDlg::OnBnClickedButton18() // sin.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", sin(firstNumber * 3.141592653589793 / 180));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton19() // cos.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", cos(firstNumber * 3.141592653589793 / 180));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton20() // tg.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", tan(firstNumber * 3.141592653589793 / 180));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton21() // ctg.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", sin(firstNumber * 3.141592653589793 / 180)/ cos(firstNumber * 3.141592653589793 / 180));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton22() // Корень.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", sqrt(firstNumber));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton23() // Возведение в степень.
{
	// TODO: добавьте свой код обработчика уведомлений
	if (firstNumber != 0)
	{
		if (editString == L"inf")
		{
			editString.SetString(L"0");
		}
		else
		{
			secondNumber = _wtof(editString);
		}
		firstNumber = pow(firstNumber, secondNumber);
		editString.Format(L"%g", firstNumber);
		edit.SetWindowTextW(editString);
		firstNumber = 0;
		secondNumber = 0;
	}
	else
	{
		if (editString == L"inf")
		{
			editString.SetString(L"0");
		}
		else
		{
			firstNumber = _wtof(editString);
		}
		editString.SetString(L"");
		edit.SetWindowTextW(editString);
		enumerate = power;
	}
}


void CMFCCalcDlg::OnBnClickedButton28() // log.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", log(firstNumber));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton29() // ln.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", log10(firstNumber));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton24() //arcsin.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", asin(firstNumber));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton25() //arccos.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", acos(firstNumber));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton26() //arctan.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", atan(firstNumber));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton27() //arcctg.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", atan(1/firstNumber));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnBnClickedButton30() // exp.
{
	// TODO: добавьте свой код обработчика уведомлений
	firstNumber = _wtof(editString);
	editString.Format(L"%g", exp(firstNumber));
	edit.SetWindowTextW(editString);
	firstNumber = 0;
}


void CMFCCalcDlg::OnAcnStartAnimate1()
{
	// TODO: добавьте свой код обработчика уведомлений
}


void CMFCCalcDlg::On32771() // Форма площадь паралеллограма и треугольника.
{
	// TODO: добавьте свой код обработчика команд
	Triangle triangle;
	triangle.DoModal();
}


void CMFCCalcDlg::On32773() // Форма площадь треугольника по Герону.
{
	// TODO: добавьте свой код обработчика команд
	TrianlgeGeronDlg triangle;
	triangle.DoModal();
}


void CMFCCalcDlg::On32777()
{
	// TODO: добавьте свой код обработчика команд
	VectorDlg vector;
	vector.DoModal();

}
