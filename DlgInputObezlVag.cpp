// DlgInputObezlVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputObezlVag.h"
#include ".\dlginputobezlvag.h"
#include "PrintableDlg.h"


// CDlgInputObezlVag dialog

IMPLEMENT_DYNAMIC(CDlgInputObezlVag, CDialog)
CDlgInputObezlVag::CDlgInputObezlVag(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputObezlVag::IDD, pParent)
{
}

CDlgInputObezlVag::~CDlgInputObezlVag()
{
}

void CDlgInputObezlVag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_Cb1);
	DDX_Control(pDX, IDC_CHECK31, m_Cb2);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT2, m_Dat1);
	DDX_Control(pDX, IDC_EDIT7, m_Dat2);
	DDX_Control(pDX, IDC_RADIO4, m_C1);
	DDX_Control(pDX, IDC_RADIO5, m_C2);
}


BEGIN_MESSAGE_MAP(CDlgInputObezlVag, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO4, OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO5, OnBnClickedRadio5)
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK31, OnBnClickedCheck31)
END_MESSAGE_MAP()


// CDlgInputObezlVag message handlers

void CDlgInputObezlVag::OnBnClickedOk()
{
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_mkcReportPptObezlVag %d, %s, %s, %s, %d",
			g_iDep,
			m_EdNVag.GetString(1),
			m_Dat1.GetSQLDate(),
			m_Dat2.GetSQLDate(),
			m_C2.GetCheck());
	Dlg.DoModal();
	OnOK();
}

BOOL CDlgInputObezlVag::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdNVag.SetMode(0, 1, 8);
	m_Dat1.SetMode(1, 1);
	m_Dat2.SetMode(1, 1);

	m_C1.SetCheck(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInputObezlVag::OnBnClickedRadio4()
{
	m_C1.SetCheck(1);
	m_C2.SetCheck(0);
}

void CDlgInputObezlVag::OnBnClickedRadio5()
{
	m_C1.SetCheck(0);
	m_C2.SetCheck(1);
}

void CDlgInputObezlVag::OnBnClickedCheck1()
{
	m_EdNVag.EnableWindow(m_Cb1.GetCheck());
	m_EdNVag.SetWindowText("");
}

void CDlgInputObezlVag::OnBnClickedCheck31()
{
	m_Dat1.EnableWindow(m_Cb2.GetCheck());
	m_Dat2.EnableWindow(m_Cb2.GetCheck());
	m_Dat1.SetWindowText("");
	m_Dat2.SetWindowText("");
}
