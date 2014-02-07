// DlgBD_TL1069.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgBD_TL1069.h"
#include ".\dlgbd_tl1069.h"
#include "DlgBDSelectRezTL.h"


// CDlgBD_TL1069 dialog

IMPLEMENT_DYNAMIC(CDlgBD_TL1069, CDlgWithAccelerators)
CDlgBD_TL1069::CDlgBD_TL1069(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgBD_TL1069::IDD, pParent)
{
}

CDlgBD_TL1069::~CDlgBD_TL1069()
{
}

void CDlgBD_TL1069::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_CHECK31, m_Check2);
	DDX_Control(pDX, IDC_CHECK39, m_Check3);
	DDX_Control(pDX, IDC_CHECK40, m_Check4);
	DDX_Control(pDX, IDC_CHECK38, m_Check5);
	DDX_Control(pDX, IDC_CHECK35, m_Check6);
	DDX_Control(pDX, IDC_CHECK41, m_Check7);
	DDX_Control(pDX, IDC_CHECK42, m_Check8);
	DDX_Control(pDX, IDC_CHECK3, m_Check9);
	DDX_Control(pDX, IDC_CHECK2, m_Check10);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_EDIT5, m_Dat3);
	DDX_Control(pDX, IDC_EDIT6, m_Dat4);
	DDX_Control(pDX, IDC_EDIT4, m_Dat5);
	DDX_Control(pDX, IDC_EDIT120, m_Dat6);
	DDX_Control(pDX, IDC_EDIT70, m_EdVag1);
	DDX_Control(pDX, IDC_EDIT69, m_EdVag2);
	DDX_Control(pDX, IDC_EDIT71, m_EdInvNum);
	DDX_Control(pDX, IDC_EDIT93, m_EdProbeg1);
	DDX_Control(pDX, IDC_EDIT94, m_EdProbeg2);
	DDX_Control(pDX, IDC_EDIT3, m_EdBokRamNum);
	DDX_Control(pDX, IDC_EDIT7, m_EdNadrBalkNum);
}


BEGIN_MESSAGE_MAP(CDlgBD_TL1069, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK39, OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK40, OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK38, OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK35, OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK41, OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_CHECK42, OnBnClickedCheck8)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK3, &CDlgBD_TL1069::OnBnClickedCheck32)
	ON_BN_CLICKED(IDC_CHECK2, &CDlgBD_TL1069::OnBnClickedCheck2)
END_MESSAGE_MAP()


// CDlgBD_TL1069 message handlers

BOOL CDlgBD_TL1069::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();
	m_Dat1.SetMode(1);
	m_Dat2.SetMode(1);
	m_Dat3.SetMode(1);
	m_Dat4.SetMode(1);
	m_Dat5.SetMode(1);
	m_Dat6.SetMode(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgBD_TL1069::OnBnClickedCheck1()
{
	m_Dat1.EnableWindow(m_Check1.GetCheck());
	m_Dat2.EnableWindow(m_Check1.GetCheck());
	if( m_Check1.GetCheck() )
	{
		m_Dat1.SetFocus();
	} else
	{
		m_Dat1.SetWindowText("");
		m_Dat2.SetWindowText("");
	}
}

void CDlgBD_TL1069::OnBnClickedCheck3()
{
	m_Dat3.EnableWindow(m_Check3.GetCheck());
	m_Dat4.EnableWindow(m_Check3.GetCheck());
	if( m_Check3.GetCheck() )
	{
		m_Dat3.SetFocus();
	} else
	{
		m_Dat3.SetWindowText("");
		m_Dat4.SetWindowText("");
	}
}

void CDlgBD_TL1069::OnBnClickedCheck4()
{
	m_EdVag1.EnableWindow(m_Check4.GetCheck());
	if( m_Check4.GetCheck() )
	{
		m_EdVag1.SetFocus();
	} else
	{
		m_EdVag1.SetWindowText("");
	}
}

void CDlgBD_TL1069::OnBnClickedCheck5()
{
	m_Dat5.EnableWindow(m_Check5.GetCheck());
	m_Dat6.EnableWindow(m_Check5.GetCheck());
	if( m_Check5.GetCheck() )
	{
		m_Dat5.SetFocus();
	} else
	{
		m_Dat5.SetWindowText("");
		m_Dat6.SetWindowText("");
	}

}

void CDlgBD_TL1069::OnBnClickedCheck6()
{
	m_EdVag2.EnableWindow(m_Check6.GetCheck());
	if( m_Check6.GetCheck() )
	{
		m_EdVag2.SetFocus();
	} else
	{
		m_EdVag2.SetWindowText("");
	}

}

void CDlgBD_TL1069::OnBnClickedCheck7()
{
	m_EdInvNum.EnableWindow(m_Check7.GetCheck());
	if( m_Check7.GetCheck() )
	{
		m_EdInvNum.SetFocus();
	} else
	{
		m_EdInvNum.SetWindowText("");
	}

}

void CDlgBD_TL1069::OnBnClickedCheck8()
{
	m_EdProbeg1.EnableWindow(m_Check8.GetCheck());
	m_EdProbeg2.EnableWindow(m_Check8.GetCheck());
	if( m_Check8.GetCheck() )
	{
		m_EdProbeg1.SetFocus();
	} else
	{
		m_EdProbeg1.SetWindowText("");
		m_EdProbeg2.SetWindowText("");
	}
}

void CDlgBD_TL1069::OnBnClickedOk()
{
	char cQ[1024] = "";
	char cVag1[32] = "";
	char cVag2[32] = "";
	char cNTL[32] = "";
	char cPrb1[32] = "", cPrb2[32] = "", cNadrBalk[32] = "", cBokRam[32] = "";
	m_EdVag1.GetWindowText(cVag1, 32);
	m_EdVag2.GetWindowText(cVag2, 32);
	m_EdInvNum.GetWindowText(cNTL, 32);
	m_EdProbeg1.GetWindowText(cPrb1, 32);
	m_EdProbeg2.GetWindowText(cPrb2, 32);
	m_EdNadrBalkNum.GetWindowText(cNadrBalk, 32);
	m_EdBokRamNum.GetWindowText(cBokRam, 32);

	sprintf(cQ, "pTov_BDTL1067Select %u, %s, %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
		g_iDep,
		isAble(m_Check1.GetCheck(), m_Dat1.GetSQLDate()),
		isAble(m_Check1.GetCheck(), m_Dat2.GetSQLDate()),
		m_Check2.GetCheck(),
		isAble(m_Check3.GetCheck(), m_Dat3.GetSQLDate()),
		isAble(m_Check3.GetCheck(), m_Dat4.GetSQLDate()),
		isAble(m_Check4.GetCheck(), isNull(cVag1)),
		isAble(m_Check5.GetCheck(), m_Dat5.GetSQLDate()),
		isAble(m_Check5.GetCheck(), m_Dat6.GetSQLDate()),
		isAble(m_Check6.GetCheck(), isNull(cVag2)),
		isAble(m_Check7.GetCheck(), isNull(cNTL)),
		isAble(m_Check8.GetCheck(), isNull(cPrb1)),
		isAble(m_Check8.GetCheck(), isNull(cPrb2)),
		isAble(m_Check9.GetCheck(), isNull(cNadrBalk)),
		isAble(m_Check10.GetCheck(), isNull(cBokRam)));
	CDlgBDSelectRezTL Dlg;
	
	strcpy(Dlg.cQ, cQ);
	if( Dlg.DoModal() == IDCANCEL ) return;
	OnOK();
}

void CDlgBD_TL1069::OnBnClickedCheck2()
{
	m_EdBokRamNum.EnableWindow(m_Check10.GetCheck());
	if( m_Check10.GetCheck() )
	{
		m_EdBokRamNum.SetFocus();
	} else
	{
		m_EdBokRamNum.SetWindowText("");
	}
}

void CDlgBD_TL1069::OnBnClickedCheck32()
{
	m_EdNadrBalkNum.EnableWindow(m_Check9.GetCheck());
	if( m_Check9.GetCheck() )
	{
		m_EdNadrBalkNum.SetFocus();
	} else
	{
		m_EdNadrBalkNum.SetWindowText("");
	}
}
