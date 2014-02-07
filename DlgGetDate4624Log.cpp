// DlgGetDate4624Log.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgGetDate4624Log.h"
#include ".\dlggetdate4624log.h"


// CDlgGetDate4624Log dialog

IMPLEMENT_DYNAMIC(CDlgGetDate4624Log, CDialog)
CDlgGetDate4624Log::CDlgGetDate4624Log(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgGetDate4624Log::IDD, pParent)
{
	m_Dat1.SetMode(1, 1);
}

CDlgGetDate4624Log::~CDlgGetDate4624Log()
{
}

void CDlgGetDate4624Log::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
}


BEGIN_MESSAGE_MAP(CDlgGetDate4624Log, CDialog)
END_MESSAGE_MAP()


// CDlgGetDate4624Log message handlers

BOOL CDlgGetDate4624Log::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Dat1.InitDate();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgGetDate4624Log::OnOK()
{
	strcpy(cSQLDatRet, m_Dat1.GetSQLDate());

	CDialog::OnOK();
}
