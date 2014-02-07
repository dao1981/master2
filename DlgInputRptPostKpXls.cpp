// DlgInputRptPostKpXls.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputRptPostKpXls.h"
#include "afxdialogex.h"


// CDlgInputRptPostKpXls dialog

IMPLEMENT_DYNAMIC(CDlgInputRptPostKpXls, CDialog)

CDlgInputRptPostKpXls::CDlgInputRptPostKpXls(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputRptPostKpXls::IDD, pParent)
{

}

CDlgInputRptPostKpXls::~CDlgInputRptPostKpXls()
{
}

void CDlgInputRptPostKpXls::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdDat);
}


BEGIN_MESSAGE_MAP(CDlgInputRptPostKpXls, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgInputRptPostKpXls::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgInputRptPostKpXls message handlers


BOOL CDlgInputRptPostKpXls::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_EdDat.SetMode(3,1);
	m_EdDat.InitDate();
	m_EdDat.SetFocus();
	ZeroMemory(cDat, 15);
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}


void CDlgInputRptPostKpXls::OnBnClickedOk()
{
	if( m_EdDat.isNull() )
	{
		AfxMessageBox("Необходимо указать месяц и год");
		m_EdDat.SetFocus();
	}
	strncpy(cDat, m_EdDat.GetSQLDate(), 12);
	if( !m_EdDat.isNull() )
	{
		int i=1;
		for(; cDat[i] && cDat[i]!= '\''; i++ ) cDat[i - 1] = cDat[i];
		cDat[i-1] = 0;
	}

	char cQ[255] = "";
	DWORD dwNum = 0;
	long Ind = 0;
	sprintf(cQ, "pTov_mkcReportPostKPCount %d, %s", g_iDep, m_EdDat.GetSQLDate());
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind );
	DBW.CloseCursor();
	if( !dwNum ) 
	{
		AfxMessageBox("За указанный период данные отсутствуют!");
		return;
	}

	CDialog::OnOK();
}
