// DlgInput2956.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInput2956.h"
#include "DlgMsg2956.h"
#include ".\dlginput2956.h"


// CDlgInput2956 dialog

IMPLEMENT_DYNAMIC(CDlgInput2956, CDialog)
CDlgInput2956::CDlgInput2956(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInput2956::IDD, pParent)
{
}

CDlgInput2956::~CDlgInput2956()
{
}

void CDlgInput2956::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat);
	DDX_Control(pDX, IDC_CHECK1, m_Check);
}


BEGIN_MESSAGE_MAP(CDlgInput2956, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInput2956 message handlers

BOOL CDlgInput2956::OnInitDialog()
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

void CDlgInput2956::OnBnClickedOk()
{
	CDlgMsg2956 Dlg;
	m_Dat.GetTime(&Dlg.stDate);
	
	Dlg.iFromKpBase = m_Check.GetCheck();
	Dlg.DoModal();
	OnOK();
}
