// AuthDlg.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "AuthDlg.h"
#include ".\authdlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAuthDlg dialog


CAuthDlg::CAuthDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAuthDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAuthDlg)
	m_UserName = _T("");
	m_Pass = _T("");
	//}}AFX_DATA_INIT
}


void CAuthDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAuthDlg)
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT1, m_UserName);
	DDX_Text(pDX, IDC_EDIT2, m_Pass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAuthDlg, CDialog)
	//{{AFX_MSG_MAP(CAuthDlg)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEdit1)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAuthDlg message handlers
extern CMasterApp theApp;

BOOL CAuthDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
    SetIcon(m_hIcon, FALSE);		// Set small icon
    SetIcon(m_hIcon, TRUE);			// Set big icon
	m_Edit1.SetFocus();
	theApp.m_pMainWnd = NULL;
    if( g_iAutoOK ) CDialog::OnOK();
	return TRUE;
}

void CAuthDlg::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CAuthDlg::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}
