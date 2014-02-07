// InputNVagObezl4624.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "InputNVagObezl4624.h"
#include ".\inputnvagobezl4624.h"


// CInputNVagObezl4624 dialog

IMPLEMENT_DYNAMIC(CInputNVagObezl4624, CDialog)
CInputNVagObezl4624::CInputNVagObezl4624(CWnd* pParent /*=NULL*/)
	: CDialog(CInputNVagObezl4624::IDD, pParent)
{
	bDatFromPasp = 0;
}

CInputNVagObezl4624::~CInputNVagObezl4624()
{
}

void CInputNVagObezl4624::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_CHECK1, m_Check);
}


BEGIN_MESSAGE_MAP(CInputNVagObezl4624, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CInputNVagObezl4624 message handlers

BOOL CInputNVagObezl4624::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdNVag.QInit(80,1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CInputNVagObezl4624::OnBnClickedOk()
{
	bDatFromPasp = m_Check.GetCheck();
	m_EdNVag.GetWindowText(cNVag32, 32);
	OnOK();
}
