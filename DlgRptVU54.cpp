// DlgRptVU54.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRptVU54.h"
#include "PrintableDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgRptVU54 dialog


CDlgRptVU54::CDlgRptVU54(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRptVU54::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRptVU54)
	//}}AFX_DATA_INIT
    iMode = 0;
}


void CDlgRptVU54::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRptVU54)
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRptVU54, CDialog)
	//{{AFX_MSG_MAP(CDlgRptVU54)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRptVU54 message handlers

BOOL CDlgRptVU54::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_Dat1.SetMode(1);	
    m_Dat2.SetMode(1);
    if( iMode == 1 )
    {
        SetWindowText("Отчет о подкатке КП");
    }
/*	if( iMode == 2 )
    {
        SetWindowText("Отчет о подкатке КП");
	}*/
	return TRUE;  
}

void CDlgRptVU54::OnOK() 
{
    CPrintableDlg Dlg;
    if( iMode == 0 )
    {
        sprintf(Dlg.cQ, "pTov_mkcReportVU54 %u, %s, %s",
                g_iDep,
                m_Dat1.GetSQLDate(),
                m_Dat2.GetSQLDate());        
    } else
    if( iMode == 1 )
    {
        sprintf(Dlg.cQ, "pTov_mkcReportPodkatKP %u, %s, %s",
                g_iDep,
                m_Dat1.GetSQLDate(),
                m_Dat2.GetSQLDate());        
    }
	if( iMode == 2 )
    {
        sprintf(Dlg.cQ, "pTov_MkcReportVU54Podr %u, %s, %s",
                g_iDep,
                m_Dat1.GetSQLDate(),
                m_Dat2.GetSQLDate());        
    }

	Dlg.m_bCheck1 = true;
    if( Dlg.DoModal() == IDCANCEL ) return;

	CDialog::OnOK();
}
