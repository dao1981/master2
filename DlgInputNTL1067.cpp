// DlgInputNTL1067.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputNTL1067.h"
#include ".\dlginputntl1067.h"


// CDlgInputNTL1067 dialog

IMPLEMENT_DYNAMIC(CDlgInputNTL1067, CDialog)
CDlgInputNTL1067::CDlgInputNTL1067(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputNTL1067::IDD, pParent)
	, m_strNTL(_T(""))
{
}

CDlgInputNTL1067::~CDlgInputNTL1067()
{
}

void CDlgInputNTL1067::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}


BEGIN_MESSAGE_MAP(CDlgInputNTL1067, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInputNTL1067 message handlers

BOOL CDlgInputNTL1067::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Edit.QInit(100,1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInputNTL1067::OnBnClickedOk()
{
	m_Edit.GetWindowText(m_strNTL);
	if( !m_strNTL.GetLength() )
	{
		AfxMessageBox("Необходимо указать номер тележки!");
		m_Edit.SetFocus();
		return;
	}
	OnOK();
}
