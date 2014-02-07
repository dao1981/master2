// DlgPrihodTL.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPrihodTL.h"
#include ".\dlgprihodtl.h"
#include "dlgsprav1.h"


// CDlgPrihodTL dialog

IMPLEMENT_DYNAMIC(CDlgPrihodTL, CDialog)
CDlgPrihodTL::CDlgPrihodTL(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPrihodTL::IDD, pParent)
{
	dwRamaLeft_IPR = 0;
	dwRamaRight_IPR = 0;
	dwBalka_IPR = 0;

	dwDefect_RL = 0;
	dwDefect_RR = 0;
	dwDefect_B = 0;
}

CDlgPrihodTL::~CDlgPrihodTL()
{
}

void CDlgPrihodTL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT16, m_EdKl1);
	DDX_Control(pDX, IDC_EDIT4, m_EdPrName1);
	DDX_Control(pDX, IDC_EDIT3, m_EdRL_Num);
	DDX_Control(pDX, IDC_EDIT116, m_EdRR_Num);
	DDX_Control(pDX, IDC_EDIT5, m_EdRL_Year);
	DDX_Control(pDX, IDC_EDIT6, m_EdRR_Year);
	DDX_Control(pDX, IDC_COMBO20, m_CbRL_Rem);
	DDX_Control(pDX, IDC_COMBO22, m_CbRR_Rem);
	DDX_Control(pDX, IDC_EDIT14, m_EdB_Num);
	DDX_Control(pDX, IDC_EDIT84, m_EdB_Year);
	DDX_Control(pDX, IDC_COMBO24, m_CbB_Rem);
	DDX_Control(pDX, IDC_EDIT7, m_EdPos1);
	DDX_Control(pDX, IDC_EDIT72, m_EdPos2);
	DDX_Control(pDX, IDC_EDIT73, m_EdUslNum);
	DDX_Control(pDX, IDC_EDIT74, m_EdKl2);
	DDX_Control(pDX, IDC_EDIT69, m_EdPrName2);
	DDX_Control(pDX, IDC_EDIT76, m_EdKl3);
	DDX_Control(pDX, IDC_EDIT83, m_EdPrName3);
	DDX_Control(pDX, IDC_COMBO3, m_CbL);
	DDX_Control(pDX, IDC_COMBO6, m_CbR);
}


BEGIN_MESSAGE_MAP(CDlgPrihodTL, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton_PrRamaRight)
	ON_BN_CLICKED(IDC_BUTTON15, OnBnClickedButton_PrBalka)
	ON_BN_CLICKED(IDC_BUTTON5, OnBnClickedButton_DefectRL)
	ON_BN_CLICKED(IDC_BUTTON26, OnBnClickedButton_DefectRR)
	ON_BN_CLICKED(IDC_BUTTON23, OnBnClickedButton_DefectB)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnCbnSelchangeComboL)
	ON_CBN_SELCHANGE(IDC_COMBO6, OnCbnSelchangeComboR)
END_MESSAGE_MAP()


// CDlgPrihodTL message handlers

BOOL CDlgPrihodTL::OnInitDialog()
{
	CDialog::OnInitDialog();

	InitComponents();

	
	return TRUE;  
	
}

void CDlgPrihodTL::InitComponents(void)
{
	m_CbL.AddString("Левая");
	m_CbL.AddString("Правая");
	m_CbL.SetItemData(0,0);
	m_CbL.SetItemData(1,1);

	m_CbR.AddString("Левая");
	m_CbR.AddString("Правая");
	m_CbR.SetItemData(0,0);
	m_CbR.SetItemData(1,1);

	m_CbL.SetCurSel(0);
	m_CbR.SetCurSel(1);

}

void CDlgPrihodTL::OnBnClickedButton1()
{
	CDlgSprav1 Dlg;
	Dlg.iDlgKind = 8;
	if( Dlg.DoModal() == IDCANCEL ) return;

	dwRamaLeft_IPR = Dlg.ret_dwIPR;
	m_EdKl1.SetWindowText(Dlg.cKodPr);
	m_EdPrName1.SetWindowText(Dlg.cPrName);
}

void CDlgPrihodTL::OnBnClickedOk()
{
	char cText[64] = "";

	m_EdRL_Num.GetWindowText(PrihodTl.cRL_Num32, 32);
	if( !PrihodTl.cRL_Num32[0] )
	{
		AfxMessageBox("Не указан номер левой боковой рамы!");
		m_EdRL_Num.SetFocus();
		return;
	}
	if( !dwRamaLeft_IPR )
	{
		AfxMessageBox("Не указано предприятие изготовитель левой боковой рамы!");
		m_EdKl1.SetFocus();
		return;
	}

	m_EdRL_Year.GetWindowText(cText, 64);
	PrihodTl.dwRL_Year = atoi(cText);
	if( !PrihodTl.dwRL_Year )
	{
		AfxMessageBox("Не указан год изготовления левой боковой рамы!");
		m_EdRL_Year.SetFocus();
		return;
	}
	if( PrihodTl.dwRL_Year > 4000 || PrihodTl.dwRL_Year < 1900 )
	{
		AfxMessageBox("Год изготовления левой боковой рамы указан неверно!");
		m_EdRL_Year.SetFocus();
		return;
	}
//	PrihodTl.dwRL_Defect = m_CbRL_Defect.GetItemData(m_CbRL_Defect.GetCurSel());


	if( m_CbRL_Rem.GetCurSel() != -1 )
		PrihodTl.dwRL_VRem = m_CbRL_Rem.GetItemData(m_CbRL_Rem.GetCurSel());

	m_EdRR_Num.GetWindowText(PrihodTl.cRR_Num32, 32);
	if( !PrihodTl.cRR_Num32[0] )
	{
		AfxMessageBox("Не указан номер правой боковой рамы!");
		m_EdRR_Num.SetFocus();
		return;
	}
	if( !dwRamaRight_IPR )
	{
		AfxMessageBox("Не указано предприятие изготовитель правой боковой рамы!");
		m_EdKl2.SetFocus();
		return;
	}

	m_EdRR_Year.GetWindowText(cText, 64);
	PrihodTl.dwRR_Year = atoi(cText);
	if( !PrihodTl.dwRR_Year )
	{
		AfxMessageBox("Не указан год изготовления правой боковой рамы!");
		m_EdRR_Year.SetFocus();
		return;
	}
	if( PrihodTl.dwRR_Year > 3000 || PrihodTl.dwRR_Year < 1900)
	{
		AfxMessageBox("Год изготовления правой боковой рамы указан неверно!");
		m_EdRR_Year.SetFocus();
		return;
	}
//	PrihodTl.dwRR_Defect = m_CbRR_Defect.GetItemData(m_CbRR_Defect.GetCurSel());
	if( m_CbRR_Rem.GetCurSel() != -1)
		PrihodTl.dwRR_VRem = m_CbRR_Rem.GetItemData(m_CbRR_Rem.GetCurSel());

	m_EdB_Num.GetWindowText(PrihodTl.cB_Num32, 32);
	if( !PrihodTl.cRR_Num32[0] )
	{
		AfxMessageBox("Не указан номер надрессорной балки!");
		m_EdB_Num.SetFocus();
		return;
	}
	if( !dwBalka_IPR )
	{
		AfxMessageBox("Не указано предприятие изготовитель надрессорной балки!");
		m_EdKl3.SetFocus();
		return;
	}
	m_EdB_Year.GetWindowText(cText, 64);
	PrihodTl.dwB_Year = atoi(cText);
	if( !PrihodTl.dwB_Year )
	{
		AfxMessageBox("Не указан год изготовления надрессорной балки!");
		m_EdB_Year.SetFocus();
		return;
	}
	if( PrihodTl.dwB_Year > 3000 || PrihodTl.dwB_Year < 1900)
	{
		AfxMessageBox("Год изготовления надрессорной балки указан неверно!");
		m_EdB_Year.SetFocus();
		return;
	}

//	PrihodTl.dwB_Defect = m_CbB_Defect.GetItemData(m_CbB_Defect.GetCurSel());
	if( m_CbB_Rem.GetCurSel() != -1 )
		PrihodTl.dwB_VRem = m_CbB_Rem.GetItemData(m_CbB_Rem.GetCurSel());

	PrihodTl.dwB_IPR = dwBalka_IPR;
	PrihodTl.dwRL_IPR = dwRamaLeft_IPR;
	PrihodTl.dwRR_IPR = dwRamaRight_IPR;

	m_EdPos1.GetWindowText(cText, 64);
	PrihodTl.dwPosition1 = atoi(cText);
	
	m_EdPos2.GetWindowText(cText, 64);
	PrihodTl.dwPosition2 = atoi(cText);

	m_EdUslNum.GetWindowText(PrihodTl.cUslNum32, 32);

	PrihodTl.dwRightGoesFirst = m_CbL.GetItemData(m_CbR.GetCurSel());

	OnOK();
}

void CDlgPrihodTL::OnBnClickedButton_PrRamaRight()
{
	CDlgSprav1 Dlg;
	Dlg.iDlgKind = 8;
	
	if( Dlg.DoModal() == IDCANCEL ) return;

	dwRamaRight_IPR = Dlg.ret_dwIPR;
	m_EdKl2.SetWindowText(Dlg.cKodPr);
	m_EdPrName2.SetWindowText(Dlg.cPrName);
}

void CDlgPrihodTL::OnBnClickedButton_PrBalka()
{
	CDlgSprav1 Dlg;
	Dlg.iDlgKind = 8;

	if( Dlg.DoModal() == IDCANCEL ) return;

	dwBalka_IPR = Dlg.ret_dwIPR;
	m_EdKl3.SetWindowText(Dlg.cKodPr);
	m_EdPrName3.SetWindowText(Dlg.cPrName);
}

void CDlgPrihodTL::OnBnClickedButton_DefectRL()
{
	// TODO: Add your control notification handler code here
}

void CDlgPrihodTL::OnBnClickedButton_DefectRR()
{
	// TODO: Add your control notification handler code here
}

void CDlgPrihodTL::OnBnClickedButton_DefectB()
{
	// TODO: Add your control notification handler code here
}

void CDlgPrihodTL::OnCbnSelchangeComboL()
{
	if( m_CbL.GetItemData(m_CbL.GetCurSel()) )
	{
		m_CbR.SetCurSel(0);
	} else
	{
		m_CbR.SetCurSel(1);
	}
}

void CDlgPrihodTL::OnCbnSelchangeComboR()
{
	if( m_CbR.GetItemData(m_CbR.GetCurSel()) )
	{
		m_CbL.SetCurSel(0);
	} else
	{
		m_CbL.SetCurSel(1);
	}
}
