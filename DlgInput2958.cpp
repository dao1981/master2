// DlgInput2958.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInput2958.h"
#include ".\dlginput2958.h"
#include "DlgMsg2958.h"

// CDlgInput2958 dialog

IMPLEMENT_DYNAMIC(CDlgInput2958, CDialog)
CDlgInput2958::CDlgInput2958(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInput2958::IDD, pParent)
{
}

CDlgInput2958::~CDlgInput2958()
{
}

void CDlgInput2958::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat);
	DDX_Control(pDX, IDC_CHECK1, m_Check);
}


BEGIN_MESSAGE_MAP(CDlgInput2958, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInput2958 message handlers

void CDlgInput2958::OnBnClickedOk()
{
	CDlgMsg2958 Dlg;
	m_Dat.GetTime(&Dlg.stDat);
	Dlg.m_iShowKP = m_Check.GetCheck();

	Dlg.DoModal();
	OnOK();
}

BOOL CDlgInput2958::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Dat.SetMode(3, 1);

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
