// DlgInputRptPrihodTL.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputRptPrihodTL.h"
#include ".\dlginputrptprihodtl.h"


// CDlgInputRptPrihodTL dialog

IMPLEMENT_DYNAMIC(CDlgInputRptPrihodTL, CDialog)
CDlgInputRptPrihodTL::CDlgInputRptPrihodTL(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputRptPrihodTL::IDD, pParent)
{
}

CDlgInputRptPrihodTL::~CDlgInputRptPrihodTL()
{
}

void CDlgInputRptPrihodTL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_EDIT7, m_EdNVag);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_CHECK2, m_Check2);
}


BEGIN_MESSAGE_MAP(CDlgInputRptPrihodTL, CDialog)
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnBnClickedCheck2)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInputRptPrihodTL message handlers

BOOL CDlgInputRptPrihodTL::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Dat1.bColored = 1;
	m_Dat2.bColored = 1;
	m_EdNVag.QInit(80, 1);

	m_Dat1.EnableWindow(0);
	m_Dat2.EnableWindow(0);
	m_EdNVag.EnableWindow(0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInputRptPrihodTL::OnBnClickedCheck1()
{
	m_Dat1.EnableWindow(m_Check1.GetCheck());
	m_Dat2.EnableWindow(m_Check1.GetCheck());
}

void CDlgInputRptPrihodTL::OnBnClickedCheck2()
{
	m_EdNVag.EnableWindow(m_Check2.GetCheck());
}

void CDlgInputRptPrihodTL::OnBnClickedOk()
{

	char cQ[256] = "";
	sprintf(cQ, "pTov_mkcRepHtmPrihTL %d, %s, %s, %s",
		g_iDep,
		isAble(m_Check2.GetCheck(), m_EdNVag.GetString(1)),
		isAble(m_Check1.GetCheck(), m_Dat1.GetSQLDate()),
		isAble(m_Check1.GetCheck(), m_Dat2.GetSQLDate()));
	DBW.DisplayHtmlReport(cQ);

	OnOK();
}
