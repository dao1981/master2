// DlgBD_TL.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgBD_TL.h"
#include ".\dlgbd_tl.h"
#include "dlgbdselectrez.h"

// CDlgBD_TL dialog

IMPLEMENT_DYNAMIC(CDlgBD_TL, CDialog)
CDlgBD_TL::CDlgBD_TL(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBD_TL::IDD, pParent)
{
}

CDlgBD_TL::~CDlgBD_TL()
{
}

void CDlgBD_TL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_CHECK1, m_Cb1);
	DDX_Control(pDX, IDC_CHECK31, m_Cb2);
	DDX_Control(pDX, IDC_CHECK39, m_Cb3);
	DDX_Control(pDX, IDC_CHECK40, m_Cb4);
	DDX_Control(pDX, IDC_CHECK38, m_Cb5);
	DDX_Control(pDX, IDC_CHECK35, m_Cb6);
	DDX_Control(pDX, IDC_CHECK42, m_Cb7);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_COMBO21, m_Combo2);
	DDX_Control(pDX, IDC_EDIT7, m_VagNum1);
	DDX_Control(pDX, IDC_EDIT5, m_VagNum2);
	DDX_Control(pDX, IDC_CHECK41, m_Cb8);
	DDX_Control(pDX, IDC_EDIT6, m_EdUslNum);
	DDX_Control(pDX, IDC_EDIT4, m_Dat11);
	DDX_Control(pDX, IDC_EDIT94, m_Dat22);
}


BEGIN_MESSAGE_MAP(CDlgBD_TL, CDialog)
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK31, OnBnClickedCheck31)
	ON_BN_CLICKED(IDC_CHECK39, OnBnClickedCheck39)
	ON_BN_CLICKED(IDC_CHECK40, OnBnClickedCheck40)
	ON_BN_CLICKED(IDC_CHECK38, OnBnClickedCheck38)
	ON_BN_CLICKED(IDC_CHECK35, OnBnClickedCheck35)
	ON_BN_CLICKED(IDC_CHECK42, OnBnClickedCheck42)
	ON_BN_CLICKED(IDC_CHECK41, OnBnClickedCheck41)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgBD_TL message handlers

BOOL CDlgBD_TL::OnInitDialog()
{
	CDialog::OnInitDialog();

	DBW.FillComboWithTRemVag(&m_Combo1);
	DBW.FillComboWithTRemVag(&m_Combo2);
	m_Dat1.SetMode(1);
	m_Dat2.SetMode(1);
	m_Dat11.SetMode(1);
	m_Dat22.SetMode(1);

	m_Combo1.SetCurSel(0);
	m_Combo2.SetCurSel(0);

	return TRUE;
	
}

void CDlgBD_TL::OnBnClickedCheck1()
{
	if( m_Cb1.GetCheck() )
	{
		m_Dat1.EnableWindow();
		m_Dat11.EnableWindow();

	} else
	{
		m_Dat1.EnableWindow(FALSE);
		m_Dat11.EnableWindow(FALSE);
	}
}

void CDlgBD_TL::OnBnClickedCheck31()
{
	if( m_Cb2.GetCheck() )
	{
		m_Dat2.EnableWindow();
		m_Dat22.EnableWindow();
		m_Cb3.SetCheck(FALSE);
	} else
	{
		m_Dat2.EnableWindow(FALSE);
		m_Dat22.EnableWindow(FALSE);
	}

}

void CDlgBD_TL::OnBnClickedCheck39()
{
	if( m_Cb3.GetCheck() )
	{
		m_Cb2.SetCheck(0);
		OnBnClickedCheck31();
	}
		
}

void CDlgBD_TL::OnBnClickedCheck40()
{
	m_VagNum1.EnableWindow(m_Cb4.GetCheck());
	m_Cb5.EnableWindow(m_Cb4.GetCheck());
	m_Combo1.EnableWindow(m_Cb4.GetCheck());
//	OnBnClickedCheck38();
}

void CDlgBD_TL::OnBnClickedCheck38()
{
	m_Combo1.EnableWindow(m_Cb5.GetCheck());
}

void CDlgBD_TL::OnBnClickedCheck35()
{
	m_VagNum2.EnableWindow(m_Cb6.GetCheck());
	m_Cb7.EnableWindow(m_Cb6.GetCheck());
	m_Combo2.EnableWindow(m_Cb6.GetCheck());
//	OnBnClickedCheck42();

}

void CDlgBD_TL::OnBnClickedCheck42()
{
	m_Combo2.EnableWindow(m_Cb7.GetCheck());

}

void CDlgBD_TL::OnBnClickedCheck41()
{
	m_EdUslNum.EnableWindow(m_Cb8.GetCheck());
}

void CDlgBD_TL::OnBnClickedOk()
{

	CDlgBDSelectRez Dlg;
	char cRash[32] = "NULL";
	char cUslNum[64] = "";
	char cVagPrih[32] = "", cVagRash[32] = "";
	if( m_Cb3.GetCheck() || m_Cb2.GetCheck() )
	{
		itoa(m_Cb3.GetCheck(), cRash, 10);
	}
	if( !m_VagNum1.GetWindowText(cVagPrih, 32))
		strcpy(cVagPrih, "");
	if( !m_VagNum2.GetWindowText(cVagRash, 32))
		strcpy(cVagRash, "");
	if( !m_EdUslNum.GetWindowText(cUslNum, 64))
	{
		cUslNum[0] = 0;
	}


	sprintf(Dlg.cQ, "pTov_BDTLSelect %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
			g_iDep,
			isAble(m_Cb1.GetCheck(), m_Dat1.GetSQLDate()),
			isAble(m_Cb1.GetCheck(), m_Dat11.GetSQLDate()),
			isAble(m_Cb2.GetCheck(), m_Dat2.GetSQLDate()),
			isAble(m_Cb2.GetCheck(), m_Dat22.GetSQLDate()),
			cRash,
			isAble(m_Cb4.GetCheck(), isNull(cVagPrih)),
			isAble(m_Cb4.GetCheck() && m_Cb5.GetCheck(), isNull(m_Combo1.GetItemData(m_Combo1.GetCurSel()))),
			isAble(m_Cb6.GetCheck(), isNull(cVagRash)),
			isAble(m_Cb6.GetCheck() && m_Cb7.GetCheck(), isNull(m_Combo2.GetItemData(m_Combo2.GetCurSel()))),
			isNull(cUslNum));
	Dlg.iMode = 3;
	if( Dlg.DoModal() == IDCANCEL ) return;

	OnOK();
}
