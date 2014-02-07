// DlgInput2956Svod.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInput2956Svod.h"
#include ".\dlginput2956svod.h"


// CDlgInput2956Svod dialog

IMPLEMENT_DYNAMIC(CDlgInput2956Svod, CDialog)
CDlgInput2956Svod::CDlgInput2956Svod(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInput2956Svod::IDD, pParent)
{
}

CDlgInput2956Svod::~CDlgInput2956Svod()
{
}

void CDlgInput2956Svod::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdMonth);
	DDX_Control(pDX, IDC_RADIO1, m_Cb1);
	DDX_Control(pDX, IDC_RADIO2, m_Cb2);
}


BEGIN_MESSAGE_MAP(CDlgInput2956Svod, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnBnClickedRadio2)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInput2956Svod message handlers

BOOL CDlgInput2956Svod::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdMonth.SetMode(3, 1);
	m_Cb1.SetCheck(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInput2956Svod::OnBnClickedRadio1()
{
	m_Cb1.SetCheck(1);
	m_Cb2.SetCheck(0);
}

void CDlgInput2956Svod::OnBnClickedRadio2()
{
	m_Cb1.SetCheck(0);
	m_Cb2.SetCheck(1);
}

void CDlgInput2956Svod::OnBnClickedOk()
{
	char cQ[128] = "";
	sprintf(cQ, "pTov_mkcRepHtmS2956Dor %s, %d", m_EdMonth.GetSQLDate(), m_Cb2.GetCheck());
//	sprintf(cQ, "pTov_mkcRepSel2956DorBD %s", m_EdMonth.GetSQLDate());
	DBW.DisplayHtmlReport(cQ);
	OnOK();
}
