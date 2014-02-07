// DlgInput_VO7.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInput_VO7.h"
#include ".\dlginput_vo7.h"


// CDlgInput_VO7 dialog

IMPLEMENT_DYNAMIC(CDlgInput_VO7, CDialog)
CDlgInput_VO7::CDlgInput_VO7(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInput_VO7::IDD, pParent)
{
}

CDlgInput_VO7::~CDlgInput_VO7()
{
}

void CDlgInput_VO7::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat);
	DDX_Control(pDX, IDC_RADIO1, m_Cb1);
	DDX_Control(pDX, IDC_RADIO2, m_Cb2);
}


BEGIN_MESSAGE_MAP(CDlgInput_VO7, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_RADIO1, OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnBnClickedRadio2)
END_MESSAGE_MAP()


// CDlgInput_VO7 message handlers

BOOL CDlgInput_VO7::OnInitDialog()
{
	CDialog::OnInitDialog();
		m_Dat.SetMode(3, 1);

	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(st));

	GetLocalTime(&st);

	if( st.wMonth <= 6 ) 
	{
		st.wMonth = 12;
		st.wYear--;
	} else
		st.wMonth = 6;
	m_Dat.SetTime(&st);

	m_Cb1.SetCheck(1);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInput_VO7::OnBnClickedOk()
{
	SYSTEMTIME stDate;
	m_Dat.GetTime(&stDate);

	if( stDate.wMonth != 6 && stDate.wMonth != 12 )
	{
		AfxMessageBox("ќтчетным мес€цем могут быть только июнь и декабрь");
		m_Dat.SetFocus();
		return;
	}

	char cQ[512] = "";
	sprintf(cQ, "pTov_mkcRepHtmVO7 %d, %s, %d", g_iDep, m_Dat.GetSQLDate(), m_Cb2.GetCheck());

	DBW.DisplayHtmlReport(cQ);

	OnOK();
}

void CDlgInput_VO7::OnBnClickedRadio1()
{
	m_Cb1.SetCheck(1);
	m_Cb2.SetCheck(0);
}

void CDlgInput_VO7::OnBnClickedRadio2()
{
	m_Cb1.SetCheck(0);
	m_Cb2.SetCheck(1);

}
