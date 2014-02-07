// DlgInput2955.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInput2955.h"
#include ".\dlginput2955.h"
#include "dlgmsg2955.h"
#include "DlgMsg2956.h"

// CDlgInput2955 dialog

IMPLEMENT_DYNAMIC(CDlgInput2955, CDialog)
CDlgInput2955::CDlgInput2955(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInput2955::IDD, pParent)
{
}

CDlgInput2955::~CDlgInput2955()
{
}

void CDlgInput2955::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat);
	DDX_Control(pDX, IDC_CHECK1, m_Check);
}


BEGIN_MESSAGE_MAP(CDlgInput2955, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInput2955 message handlers

void CDlgInput2955::OnBnClickedOk()
{
	CDlgMsg2955 Dlg;
	Dlg.iDataFromBD = m_Check.GetCheck();
	m_Dat.GetTime(&Dlg.stRptDate);
	Dlg.DoModal();
	OnOK();
}

BOOL CDlgInput2955::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Dat.InitDate();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
