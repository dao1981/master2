// DlgRemDefektBR.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRemDefektBR.h"
#include ".\dlgremdefektbr.h"


// CDlgRemDefektBR dialog

IMPLEMENT_DYNAMIC(CDlgRemDefektBR, CDialog)
CDlgRemDefektBR::CDlgRemDefektBR(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRemDefektBR::IDD, pParent)
{
}

CDlgRemDefektBR::~CDlgRemDefektBR()
{
}

void CDlgRemDefektBR::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgRemDefektBR, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgRemDefektBR message handlers

void CDlgRemDefektBR::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
