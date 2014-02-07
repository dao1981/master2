// DlgPPT_InpBDVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPPT_InpBDVag.h"
#include "DlgSpravKdr.h"

// CDlgPPT_InpBDVag dialog

IMPLEMENT_DYNAMIC(CDlgPPT_InpBDVag, CDialog)

CDlgPPT_InpBDVag::CDlgPPT_InpBDVag(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPPT_InpBDVag::IDD, pParent)
{

}

CDlgPPT_InpBDVag::~CDlgPPT_InpBDVag()
{
}

void CDlgPPT_InpBDVag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT2, m_EdNTL);
	DDX_Control(pDX, IDC_EDIT7, m_EdDat1067);
	DDX_Control(pDX, IDC_EDIT5, m_EdDat1520);
	DDX_Control(pDX, IDC_CHECK1, m_cbNVag);
	DDX_Control(pDX, IDC_CHECK2, m_cbNTL);
	DDX_Control(pDX, IDC_CHECK3, m_cbDat1067);
	DDX_Control(pDX, IDC_CHECK4, m_cbDat1520);
	DDX_Control(pDX, IDC_EDIT117, m_EdDat1067_2);
	DDX_Control(pDX, IDC_EDIT130, m_EdDat1520_2);
	DDX_Control(pDX, IDC_EDIT3, m_EdFIO_Sles);
	DDX_Control(pDX, IDC_BUTTON1, m_ButSles);
	DDX_Control(pDX, IDC_CHECK5, m_CheckSles);
}


BEGIN_MESSAGE_MAP(CDlgPPT_InpBDVag, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgPPT_InpBDVag::OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, &CDlgPPT_InpBDVag::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK2, &CDlgPPT_InpBDVag::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &CDlgPPT_InpBDVag::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &CDlgPPT_InpBDVag::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &CDlgPPT_InpBDVag::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgPPT_InpBDVag::OnBnClickedButton_FioSles)
END_MESSAGE_MAP()


// CDlgPPT_InpBDVag message handlers

BOOL CDlgPPT_InpBDVag::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdNVag.SetMode(0, 1, 80);
	m_EdNTL.QInit(100, 1);
	m_EdDat1067.SetMode(1, 1);
	m_EdDat1520.SetMode(1, 1);
	m_EdDat1067_2.SetMode(1, 1);
	m_EdDat1520_2.SetMode(1, 1);
	m_EdFIO_Sles.SetMode(5);
	DBW.FillEmplArray(m_EdFIO_Sles.lpEmpl, 0);


	OnBnClickedCheck1();
	OnBnClickedCheck2();
	OnBnClickedCheck3();
	OnBnClickedCheck4();
	OnBnClickedCheck5();

	return TRUE;  
}

void CDlgPPT_InpBDVag::OnBnClickedOk()
{
	
	CDlgPPT_BDVagRez Dlg;	

	sprintf(Dlg.cQ, "pTov_ppt_SelVag %u, %s, %s, %s, %s, %s, %s, %s",
		g_iDep,
		isAble( m_cbNVag.GetCheck(), m_EdNVag.GetString(1)),
		isAble( m_cbNTL.GetCheck(), m_EdNTL.GetString(1)),
		isAble( m_cbDat1067.GetCheck(), m_EdDat1067.GetSQLDate()),
		isAble( m_cbDat1067.GetCheck(), m_EdDat1067_2.GetSQLDate()),
		isAble( m_cbDat1520.GetCheck(), m_EdDat1520.GetSQLDate()),
		isAble( m_cbDat1520.GetCheck(), m_EdDat1520_2.GetSQLDate()),
		isAble( m_CheckSles.GetCheck(), isNull(m_EdFIO_Sles.GetData())));

	sprintf(Dlg.cQReport, "pTov_ppt_Report_SelVag %u, %s, %s, %s, %s, %s, %s, %s",
		g_iDep,
		isAble( m_cbNVag.GetCheck(), m_EdNVag.GetString(1)),
		isAble( m_cbNTL.GetCheck(), m_EdNTL.GetString(1)),
		isAble( m_cbDat1067.GetCheck(), m_EdDat1067.GetSQLDate()),
		isAble( m_cbDat1067.GetCheck(), m_EdDat1067_2.GetSQLDate()),
		isAble( m_cbDat1520.GetCheck(), m_EdDat1520.GetSQLDate()),
		isAble( m_cbDat1520.GetCheck(), m_EdDat1520_2.GetSQLDate()),
		isAble( m_CheckSles.GetCheck(), isNull(m_EdFIO_Sles.GetData())));
	
	Dlg.DoModal();
}

void CDlgPPT_InpBDVag::OnBnClickedCheck1()
{
	m_EdNVag.EnableWindow(m_cbNVag.GetCheck());
	m_EdNVag.SetFocus();
}

void CDlgPPT_InpBDVag::OnBnClickedCheck2()
{
	m_EdNTL.EnableWindow(m_cbNTL.GetCheck());
	m_EdNTL.SetFocus();
}

void CDlgPPT_InpBDVag::OnBnClickedCheck3()
{
	m_EdDat1067.EnableWindow(m_cbDat1067.GetCheck());
	m_EdDat1067_2.EnableWindow(m_cbDat1067.GetCheck());
	m_EdDat1067.SetFocus();
}

void CDlgPPT_InpBDVag::OnBnClickedCheck4()
{
	m_EdDat1520.EnableWindow(m_cbDat1520.GetCheck());
	m_EdDat1520_2.EnableWindow(m_cbDat1520.GetCheck());
	m_EdDat1520.SetFocus();
}

void CDlgPPT_InpBDVag::OnBnClickedCheck5()
{
	m_EdFIO_Sles.EnableWindow(m_CheckSles.GetCheck());
	m_ButSles.EnableWindow(m_CheckSles.GetCheck());
	m_EdFIO_Sles.SetFocus();
}

void CDlgPPT_InpBDVag::OnBnClickedButton_FioSles()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 0;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFIO_Sles.SetData(Dlg.dwFio);
	m_EdFIO_Sles.SetWindowText(Dlg.cFio);}
