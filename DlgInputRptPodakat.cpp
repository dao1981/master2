// DlgInputRptPodakat.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputRptPodakat.h"
#include ".\dlginputrptpodakat.h"
#include "PrintableDlg.h"

// CDlgInputRptPodakat dialog

IMPLEMENT_DYNAMIC(CDlgInputRptPodakat, CDialog)
CDlgInputRptPodakat::CDlgInputRptPodakat(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputRptPodakat::IDD, pParent)
{
}

CDlgInputRptPodakat::~CDlgInputRptPodakat()
{
}

void CDlgInputRptPodakat::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdKPNum);
	DDX_Control(pDX, IDC_EDIT2, m_EdDat);
	DDX_Control(pDX, IDC_RADIO1, m_Rad1);
	DDX_Control(pDX, IDC_RADIO2, m_Rad2);
}


BEGIN_MESSAGE_MAP(CDlgInputRptPodakat, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnBnClickedRadio2)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInputRptPodakat message handlers

BOOL CDlgInputRptPodakat::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdKPNum.QInit(100, 1);
	m_EdDat.SetMode(1, 1);

	m_Rad1.SetCheck(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInputRptPodakat::OnBnClickedRadio1()
{
	m_Rad1.SetCheck(1);
	m_Rad2.SetCheck(0);

	m_EdDat.EnableWindow(0);
}

void CDlgInputRptPodakat::OnBnClickedRadio2()
{
	m_Rad1.SetCheck(0);
	m_Rad2.SetCheck(1);

	m_EdDat.EnableWindow(1);
}

void CDlgInputRptPodakat::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_mkcReportKPfrom4624 %s, %s", m_EdKPNum.GetString(1), isAble(m_Rad2.GetCheck(), m_EdDat.GetSQLDate()));
	if( Dlg.DoModal() == IDCANCEL ) return;
	OnOK();
}
