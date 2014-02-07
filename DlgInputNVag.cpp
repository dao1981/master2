// DlgInputNVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputNVag.h"
#include ".\dlginputnvag.h"


// CDlgInputNVag dialog

IMPLEMENT_DYNAMIC(CDlgInputNVag, CDialog)
CDlgInputNVag::CDlgInputNVag(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputNVag::IDD, pParent)
{
}

CDlgInputNVag::~CDlgInputNVag()
{
}

void CDlgInputNVag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
}


BEGIN_MESSAGE_MAP(CDlgInputNVag, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInputNVag message handlers

BOOL CDlgInputNVag::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdNVag.QInit(80, 1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInputNVag::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	m_EdNVag.GetWindowText(strNVag);
	if( strNVag == "" )
	{
		AfxMessageBox("Необходимо указать номер вагона");
		return;
	}	
	OnOK();
}
