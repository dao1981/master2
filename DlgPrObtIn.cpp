// DlgPrObtIn.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPrObtIn.h"
#include "PrintableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPrObtIn dialog


CDlgPrObtIn::CDlgPrObtIn(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPrObtIn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPrObtIn)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgPrObtIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPrObtIn)
	DDX_Control(pDX, IDC_EDIT2, m_Date2);
	DDX_Control(pDX, IDC_EDIT1, m_Date1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPrObtIn, CDialog)
	//{{AFX_MSG_MAP(CDlgPrObtIn)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPrObtIn message handlers

BOOL CDlgPrObtIn::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_Date1.SetMode(1);
    m_Date2.SetMode(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgPrObtIn::OnOK() 
{
    CPrintableDlg Dlg;    
    char c1[16], c2[16];
    m_Date1.GetAsString(c1);
    m_Date2.GetAsString(c2);
    sprintf( Dlg.cQ, "pTov_mkcReportPrObt %u, %s, %s", 
                g_iDep,
                m_Date1.GetSQLDate(), 
                m_Date2.GetSQLDate());
//    AfxMessageBox(Dlg.cQ);
    if( Dlg.DoModal() == IDCANCEL ) return;
	CDialog::OnOK();
}
