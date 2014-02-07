// DlgInputDate.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputDate.h"


// CDlgInputDate dialog

IMPLEMENT_DYNAMIC(CDlgInputDate, CDialog)

CDlgInputDate::CDlgInputDate(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputDate::IDD, pParent)
{
	ZeroMemory(&stDate, sizeof(stDate));
	cSQLDate[0] = 0;
}

CDlgInputDate::~CDlgInputDate()
{
}

void CDlgInputDate::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdDate);
}


BEGIN_MESSAGE_MAP(CDlgInputDate, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgInputDate::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInputDate message handlers

void CDlgInputDate::OnBnClickedOk()
{
	m_EdDate.GetTime(&stDate);
	strncpy(cSQLDate, m_EdDate.GetSQLDate(), 26);
	OnOK();
}

BOOL CDlgInputDate::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdDate.InitDate();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}
