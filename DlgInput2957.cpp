// DlgInput2957.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInput2957.h"
#include ".\dlginput2957.h"
#include "DlgMsg2957Main.h"

// CDlgInput2957 dialog

IMPLEMENT_DYNAMIC(CDlgInput2957, CDialog)
CDlgInput2957::CDlgInput2957(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInput2957::IDD, pParent)
{
}

CDlgInput2957::~CDlgInput2957()
{
}

void CDlgInput2957::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat);
	DDX_Control(pDX, IDC_CHECK1, m_Check);
}


BEGIN_MESSAGE_MAP(CDlgInput2957, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInput2957 message handlers

void CDlgInput2957::OnBnClickedOk()
{
	CDlgMsg2957Main Dlg;
	m_Dat.GetTime(&Dlg.stDate);

	if( Dlg.stDate.wMonth != 6 && Dlg.stDate.wMonth != 12 )
	{
		AfxMessageBox("ќтчетным мес€цем могут быть только июнь и декабрь");
		m_Dat.SetFocus();
		return;
	}

	Dlg.iFromKpBase = m_Check.GetCheck();	

	Dlg.DoModal();
	OnOK();
}

BOOL CDlgInput2957::OnInitDialog()
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

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
