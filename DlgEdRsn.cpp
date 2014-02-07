// DlgEdRsn.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgEdRsn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgEdRsn dialog


CDlgEdRsn::CDlgEdRsn(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEdRsn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgEdRsn)
	m_Text = _T("");
	m_osnTitle = _T("");
	//}}AFX_DATA_INIT
}


void CDlgEdRsn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEdRsn)
	DDX_Control(pDX, IDC_MESSAGE, m_nText);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	DDX_Text(pDX, IDC_EDIT1, m_Text);
	DDX_Text(pDX, IDC_MESSAGE, m_osnTitle);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgEdRsn, CDialog)
	//{{AFX_MSG_MAP(CDlgEdRsn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEdRsn message handlers

void CDlgEdRsn::OnOK() 
{
    char cText[512] = "";
    m_Edit.GetWindowText(cText, 512);	
    if( cText[0] == 0 )
    {
        AfxMessageBox("Не указано основание для корректировки!");
        return;
    }
	CDialog::OnOK();
}

BOOL CDlgEdRsn::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
    // Введите причину удаления КП после расхода
    
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
