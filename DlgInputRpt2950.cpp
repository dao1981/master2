// DlgInputRpt2950.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputRpt2950.h"
#include ".\dlginputrpt2950.h"


// CDlgInputRpt2950 dialog

IMPLEMENT_DYNAMIC(CDlgInputRpt2950, CDialog)
CDlgInputRpt2950::CDlgInputRpt2950(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputRpt2950::IDD, pParent)
{
}

CDlgInputRpt2950::~CDlgInputRpt2950()
{
}

void CDlgInputRpt2950::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, m_Cb1);
	DDX_Control(pDX, IDC_RADIO2, m_Cb2);
	DDX_Control(pDX, IDC_EDIT1, m_Dat);
}


BEGIN_MESSAGE_MAP(CDlgInputRpt2950, CDialog)
	ON_BN_CLICKED(IDC_RADIO1, OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnBnClickedRadio2)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInputRpt2950 message handlers

BOOL CDlgInputRpt2950::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Dat.SetMode(3, 1);
	m_Cb1.SetCheck(1);

	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(st));
	GetLocalTime(&st);
	st.wMonth--;
	if( (signed)st.wMonth <= 0 )
	{
		st.wMonth = 12;
		st.wYear--;
	}
	m_Dat.SetTime(&st);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInputRpt2950::OnBnClickedRadio1()
{
	m_Cb1.SetCheck(1);
	m_Cb2.SetCheck(0);
}

void CDlgInputRpt2950::OnBnClickedRadio2()
{
	m_Cb1.SetCheck(0);
	m_Cb2.SetCheck(1);
}

void CDlgInputRpt2950::OnBnClickedOk()
{
	char cQ[128] = "";
	sprintf(cQ, "pTov_mkcRepHtmS2950 %d, %s, %d",
			g_iDep,
			m_Dat.GetSQLDate(),
			m_Cb2.GetCheck());
	DBW.DisplayHtmlReport(cQ);

	OnOK();
}
