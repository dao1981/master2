// DlgInputRpt2956.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputRpt2956.h"
#include ".\dlginputrpt2956.h"


// CDlgInputRpt2956 dialog

IMPLEMENT_DYNAMIC(CDlgInputRpt2956, CDialog)
CDlgInputRpt2956::CDlgInputRpt2956(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputRpt2956::IDD, pParent)
{
}

CDlgInputRpt2956::~CDlgInputRpt2956()
{
}

void CDlgInputRpt2956::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
}


BEGIN_MESSAGE_MAP(CDlgInputRpt2956, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInputRpt2956 message handlers

BOOL CDlgInputRpt2956::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Dat.SetMode(3, 0);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInputRpt2956::OnBnClickedOk()
{
	char cQ[128] = "";
	sprintf(cQ, "pTov_mkcRepHtmS2956 %d, %s, %d", g_iDep, m_Dat.GetSQLDate(), m_Check1.GetCheck());
	DBW.DisplayHtmlReport(cQ);

	OnOK();
}
