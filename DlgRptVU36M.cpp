// DlgRptVU36M.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRptVU36M.h"
#include "PrintableDlg.h"
#include ".\dlgrptvu36m.h"
#include "PrintableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DlgRptVU36M dialog


DlgRptVU36M::DlgRptVU36M(CWnd* pParent /*=NULL*/)
	: CDialog(DlgRptVU36M::IDD, pParent)
{
	//{{AFX_DATA_INIT(DlgRptVU36M)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void DlgRptVU36M::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(DlgRptVU36M)
	DDX_Control(pDX, IDC_EDIT1, m_Ed);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_CHECK1, m_Check);
	DDX_Control(pDX, IDC_RADIO2, m_Radio1);
}


BEGIN_MESSAGE_MAP(DlgRptVU36M, CDialog)
	//{{AFX_MSG_MAP(DlgRptVU36M)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// DlgRptVU36M message handlers

void DlgRptVU36M::OnOK() 
{    
    CString cNVag;
    m_Ed.GetWindowText(cNVag);
    if( cNVag == "" )
    {
        AfxMessageBox("Необходимо указать номер вагона!", MB_OK);
        return;
    }
/*
    CString cQ;
    cQ.Format("pTov_LK_GetByNVag '%s'", cNVag);
    DBW.ExecSQL(cQ);
    if( DBW.Fetch() == SQL_NO_DATA )
    {
        DBW.CloseCursor();
        AfxMessageBox("Номер вагона указан неверно!", MB_OK);
        return;
    }
    __int64 qwILK = 0;
    long Ind = 0;
    char cText[64] = "";
    DBW.GetData(1, SQL_C_UBIGINT, &qwILK, 8, &Ind);
    DBW.CloseCursor();

    cQ.Format("pTov_LK_CheckComplete %I64u", qwILK);
    DBW.ExecSQL(cQ);
    if( DBW.Fetch() != SQL_NO_DATA )
    {
        DBW.GetData(1, SQL_C_CHAR, cText, 255, &Ind);
        if( cText[0] != 0 )
        {
            DBW.CloseCursor();
            AfxMessageBox(cText, MB_OK);
            return;
        }
    }
    DBW.CloseCursor();
*/
    CPrintableDlg Dlg;
//  pTov_GetVU36ByNVag
//    sprintf(Dlg.cQ, "pTov_mkcReportVU36MP %I64u", qwILK);
//	sprintf(Dlg.cQ, "pTov_mkcReportVU36MP '%s', %d", cNVag, m_Check.GetCheck() );
	sprintf(Dlg.cQ, "pTov_GetVU36ByNVag '%s', %d, %d", cNVag, m_Check.GetCheck(), !m_Radio1.GetCheck() );
	if( m_Radio1.GetCheck() )
	{		
		if( Dlg.DoModal() == IDCANCEL ) return;
	} else
	{
		char cQ[128]= "";
		strcpy(cQ, Dlg.cQ);
		DBW.DisplayHtmlReport(cQ);
	}
    
	CDialog::OnOK();
}

BOOL DlgRptVU36M::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Radio1.SetCheck(1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void DlgRptVU36M::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
