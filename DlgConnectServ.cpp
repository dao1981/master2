// DlgConnectServ.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgConnectServ.h"
#include ".\dlgconnectserv.h"


// CDlgConnectServ dialog

IMPLEMENT_DYNAMIC(CDlgConnectServ, CDialog)
CDlgConnectServ::CDlgConnectServ(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgConnectServ::IDD, pParent)
{
	dwAttemptCount = 1;
	iConnectFlag = 0;
}

CDlgConnectServ::~CDlgConnectServ()
{
}

void CDlgConnectServ::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LAB_ATT, m_LabAtt);
}

CDlgConnectServ *pDlg = NULL;

VOID CALLBACK TimerReconnect( 
    HWND hwnd,        // handle to window for timer messages 
    UINT message,     // WM_TIMER message 
    UINT idTimer,     // timer identifier 
    DWORD dwTime) 
{
	if( DBW.iConnecting ) return;
	if( DBW.Connect(DBW.strConnStr) == 0 )
	{
//		AfxMessageBox("reconnected!");
//		::KillTimer(pDlg->m_hWnd, 14);
		pDlg->Connected();
	} else
	{
		pDlg->dwAttemptCount++;
		char cText[64] ="";
		itoa(pDlg->dwAttemptCount, cText, 10);
		pDlg->m_LabAtt.SetWindowText(cText);
	}
}

BEGIN_MESSAGE_MAP(CDlgConnectServ, CDialog)
END_MESSAGE_MAP()


// CDlgConnectServ message handlers

BOOL CDlgConnectServ::OnInitDialog()
{
	CDialog::OnInitDialog();
	pDlg = this;
	::SetTimer(this->m_hWnd, 14, 1000, TimerReconnect); // was 60003

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

int CDlgConnectServ::Connected()
{	
	::KillTimer(pDlg->m_hWnd, 14);
	OnOK();
	return 0;
}
void CDlgConnectServ::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::OnOK();
}
