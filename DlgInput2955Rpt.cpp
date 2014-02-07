// DlgInput2955Rpt.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInput2955Rpt.h"
#include ".\dlginput2955rpt.h"


// CDlgInput2955Rpt dialog

IMPLEMENT_DYNAMIC(CDlgInput2955Rpt, CDlgWithAccelerators)
CDlgInput2955Rpt::CDlgInput2955Rpt(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgInput2955Rpt::IDD, pParent)
{
}

CDlgInput2955Rpt::~CDlgInput2955Rpt()
{
}

void CDlgInput2955Rpt::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_CHECK1, m_Check);
}


BEGIN_MESSAGE_MAP(CDlgInput2955Rpt, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInput2955Rpt message handlers

BOOL CDlgInput2955Rpt::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_Check.SetCheck(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInput2955Rpt::OnBnClickedOk()
{
	char cQ[512] = "";
	sprintf(cQ, "pTov_mkcRepHtmS2955P %d, %s, %s, %d",
			g_iDep,
			m_Dat1.GetSQLDate(),
			m_Dat2.GetSQLDate(),
			m_Check.GetCheck());
	DBW.DisplayHtmlReport(cQ);
	OnOK();
}
