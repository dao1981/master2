// DlgASNeispKp.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgASNeispKp.h"
#include "DlgSpravSmp.h"
#include "PrintableDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgASNeispKp dialog


CDlgASNeispKp::CDlgASNeispKp(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgASNeispKp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgASNeispKp)
	//}}AFX_DATA_INIT
    m_Dat1.SetMode(1);
    m_Dat2.SetMode(1);
}


void CDlgASNeispKp::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgASNeispKp)
	DDX_Control(pDX, IDC_EDIT16, m_Dat2);
	DDX_Control(pDX, IDC_EDIT3, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_EdNeisp);
	DDX_Control(pDX, IDC_EDIT1, m_EdKNeisp);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgASNeispKp, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgASNeispKp)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgASNeispKp message handlers

void CDlgASNeispKp::OnButton1() 
{
	CDlgSpravSmp Dlg;
    Dlg.DlgMode = 111;
    Dlg.Style = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    
    dwKNeisp = Dlg.dwRet;
    m_EdKNeisp.SetWindowText(Dlg.cRet);
//    m_EdNeisp.SetWindowText(Dlg.c_retText2);
}

BOOL CDlgASNeispKp::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
	m_EdNeisp.ModifyStyle(0, WS_DISABLED);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgASNeispKp::OnOK() 
{
    CString Q;
    Q.Format("pTov_mkcReportNeispKP %u, %u, %s, %s",
             g_iDep,
             dwKNeisp,
             m_Dat1.GetSQLDate(),
             m_Dat2.GetSQLDate());
    CPrintableDlg Dlg;
    strcpy(Dlg.cQ, Q);
    if( Dlg.DoModal() == IDCANCEL ) return;

	CDlgWithAccelerators::OnOK();
}

void CDlgASNeispKp::OnChangeEdit1() 
{
    char cQ[64]="";
    char cText[64]="";
    m_EdKNeisp.GetWindowText(cText, 64);
    m_EdNeisp.SetWindowText("");
    sprintf( cQ, "pTov_GetTKP 2, '%s'", cText );
    DBW.ExecSQL(cQ);
    if( (g_sqlret=DBW.Fetch()) == SQL_NO_DATA &&
         g_sqlret == SQL_ERROR ) 
    {
        DBW.CloseCursor();
        return;
    }
    long Ind = 0;
    cText[0] = 0;
    DBW.GetData( 1, SQL_C_CHAR, cText, 64, &Ind);
    DBW.GetData( 2, SQL_C_SLONG, &dwKNeisp, 4, &Ind);
    m_EdNeisp.SetWindowText(cText);
    DBW.CloseCursor();
}
