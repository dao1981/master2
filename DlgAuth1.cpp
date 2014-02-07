// DlgAuth1.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgAuth1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAuth1 dialog


CDlgAuth1::CDlgAuth1(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgAuth1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAuth1)
	m_strName = _T("");
	m_strPass = _T("");
	//}}AFX_DATA_INIT
}


void CDlgAuth1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAuth1)
	DDX_Text(pDX, IDC_EDIT1, m_strName);
	DDX_Text(pDX, IDC_EDIT2, m_strPass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAuth1, CDialog)
	//{{AFX_MSG_MAP(CDlgAuth1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAuth1 message handlers

BOOL CDlgAuth1::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
    if( g_iAutoOK ) CDialog::OnOK();	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
