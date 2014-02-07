// DlgSelRP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSelRP.h"
#include "DlgSpravSmp.h"
#include <sqlext.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp   theApp;
extern SQLRETURN    g_sqlret;
/////////////////////////////////////////////////////////////////////////////
// CDlgSelRP dialog


CDlgSelRP::CDlgSelRP(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSelRP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSelRP)
	m_c1 = FALSE;
	m_c2 = FALSE;
	m_c3 = FALSE;
	m_c4 = FALSE;
	m_c5 = FALSE;
	m_c6 = FALSE;
	m_d1 = 0;
	m_d2 = 0;
	m_d3 = 0;
	m_d4 = 0;
	m_cb0 = -1;
	m_ed1 = _T("");
	m_ed2 = _T("");
	m_cb1 = -1;
	m_cb2 = -1;
	//}}AFX_DATA_INIT
}


void CDlgSelRP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSelRP)
	DDX_Control(pDX, IDC_BUTTON3, m_Button1);
	DDX_Control(pDX, IDC_EDIT69, m_Edit2);
	DDX_Control(pDX, IDC_EDIT46, m_Edit1);
	DDX_Control(pDX, IDC_DATETIMEPICKER8, m_dt4);
	DDX_Control(pDX, IDC_COMBO1, m_Combo0);
	DDX_Control(pDX, IDC_DATETIMEPICKER7, m_dt3);
	DDX_Control(pDX, IDC_DATETIMEPICKER6, m_dt2);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_dt1);
	DDX_Control(pDX, IDC_CHECK11, m_Check4);
	DDX_Control(pDX, IDC_CHECK2, m_Check3);
	DDX_Control(pDX, IDC_CHECK31, m_Check2);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_CHECK4, m_Check6);
	DDX_Control(pDX, IDC_CHECK3, m_Check5);
	DDX_Control(pDX, IDC_COMBO6, m_Combo2);
	DDX_Control(pDX, IDC_COMBO3, m_Combo1);
	DDX_Check(pDX, IDC_CHECK1, m_c1);
	DDX_Check(pDX, IDC_CHECK31, m_c2);
	DDX_Check(pDX, IDC_CHECK2, m_c3);
	DDX_Check(pDX, IDC_CHECK11, m_c4);
	DDX_Check(pDX, IDC_CHECK3, m_c5);
	DDX_Check(pDX, IDC_CHECK4, m_c6);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER1, m_d1);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER6, m_d2);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER7, m_d3);
	DDX_DateTimeCtrl(pDX, IDC_DATETIMEPICKER8, m_d4);
	DDX_CBIndex(pDX, IDC_COMBO1, m_cb0);
	DDX_Text(pDX, IDC_EDIT46, m_ed1);
	DDX_Text(pDX, IDC_EDIT69, m_ed2);
	DDX_CBIndex(pDX, IDC_COMBO3, m_cb1);
	DDX_CBIndex(pDX, IDC_COMBO6, m_cb2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSelRP, CDialog)
	//{{AFX_MSG_MAP(CDlgSelRP)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK31, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK11, OnCheck11)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck21)
	ON_EN_CHANGE(IDC_EDIT46, OnChangeEdit46)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSelRP message handlers

BOOL CDlgSelRP::OnInitDialog() 
{
	CDialog::OnInitDialog();
    char cQ[64] = "pTov_GetPrPodsh";
    char cText[64] = "";
    long Ind = 0;
    DBW.ExecSQL(cQ);
    for( DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA &&
            g_sqlret != SQL_ERROR && i < 256; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwIdPr[i], 4, &Ind);
        if( Ind == -1 ) dwIdPr[i] = 0;
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        if( Ind != -1 ) m_Combo1.AddString(cText);
    }
    DBW.CloseCursor();
    m_Combo1.SetCurSel(0);
//теперь типы
    strncpy(cQ, "pTov_GetTypesRP", 32);
    DBW.ExecSQL(cQ);
    for( DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA &&
            g_sqlret != SQL_ERROR && i < 256; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwIdPr[i], 4, &Ind);
        if( Ind == -1 ) dwIdTypeRP[i] = 0;
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        if( Ind != -1 ) m_Combo2.AddString(cText);
    }
    DBW.CloseCursor();
    m_Combo2.SetCurSel(0);

    m_Combo0.ModifyStyle(0, WS_DISABLED, 0);
    m_Combo1.ModifyStyle(0, WS_DISABLED, 0);
    m_Combo2.ModifyStyle(0, WS_DISABLED, 0);
    m_dt1.ModifyStyle(0, WS_DISABLED);
    m_dt2.ModifyStyle(0, WS_DISABLED);
    m_dt3.ModifyStyle(0, WS_DISABLED);
    m_dt4.ModifyStyle(0, WS_DISABLED);
    m_Edit1.ModifyStyle(0, WS_DISABLED);
    m_Edit2.ModifyStyle(0, WS_DISABLED);
    m_Button1.ModifyStyle(0, WS_DISABLED);
	return TRUE;
}

void CDlgSelRP::OnCheck3() 
{
    if( m_Check5.GetCheck() )
    {
        m_Combo1.ModifyStyle(WS_DISABLED, 0);
    }
    else
        m_Combo1.ModifyStyle(0, WS_DISABLED);
}

void CDlgSelRP::OnCheck4() 
{
    if( m_Check6.GetCheck() )
    {
        m_Combo2.ModifyStyle(WS_DISABLED, 0);
    }
    else
        m_Combo2.ModifyStyle(0, WS_DISABLED);	
}

void CDlgSelRP::OnCheck1() 
{
    if( m_Check1.GetCheck() )
    {
        m_dt1.ModifyStyle(WS_DISABLED, 0);
        m_dt2.ModifyStyle(WS_DISABLED, 0);
    }
    else
    {
        m_dt1.ModifyStyle(0, WS_DISABLED);
        m_dt2.ModifyStyle(0, WS_DISABLED);
    }
}

void CDlgSelRP::OnCheck2() 
{
	if( m_Check2.GetCheck() )
    {
        m_dt3.ModifyStyle(WS_DISABLED, 0);
        m_dt4.ModifyStyle(WS_DISABLED, 0);
    }
    else
    {
        m_dt3.ModifyStyle(0, WS_DISABLED);
        m_dt4.ModifyStyle(0, WS_DISABLED);
    }
}

void CDlgSelRP::OnCheck11() 
{
    if( m_Check4.GetCheck() )
    {
        m_Edit1.ModifyStyle(WS_DISABLED, 0);
        m_Edit2.ModifyStyle(WS_DISABLED, 0);
        m_Button1.ModifyStyle(WS_DISABLED, 0);
    }
    else
    {
        m_Edit1.ModifyStyle(0, WS_DISABLED);
        m_Edit2.ModifyStyle(0, WS_DISABLED);
        m_Button1.ModifyStyle(0, WS_DISABLED);
    }
    m_Button1.RedrawWindow();
}

void CDlgSelRP::OnCheck21() 
{
    if( m_Check3.GetCheck() )
    {
        m_Combo0.ModifyStyle(WS_DISABLED, 0);
    }
    else
        m_Combo0.ModifyStyle(0, WS_DISABLED);    	
}

void CDlgSelRP::OnOK() 
{
    if( m_Check4.GetCheck() )
    {
        char cText[64] = "";
        m_Edit1.GetWindowText(cText, 64);
        if( cText[0] == 0 )
        {
            AfxMessageBox("Не введен код неисправности!");
            return;
        }
    }
	CDialog::OnOK();
}

void CDlgSelRP::OnButton3() 
{
    CDlgSpravSmp Dlg;
    Dlg.DlgMode = 112;
    Dlg.Style = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_Edit1.SetWindowText(Dlg.cRet);
}

void CDlgSelRP::OnChangeEdit46() 
{    
    char cText[64] = "";
    char cQ[64] = "pTov_GetPodshNeisp ";
    m_Edit1.GetWindowText(cText, 64);
    m_Edit2.SetWindowText("");
    if( cText[0] == 0 ) return;
    sprintf(cQ, "pTov_GetPodshNeisp %s", cText);
    long Ind=0;
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch()) == SQL_NO_DATA ||
         g_sqlret == SQL_ERROR )
    {
        DBW.CloseCursor();
        return;
    }
    DBW.GetData( 1, SQL_C_CHAR, cText, 64, &Ind);
    m_Edit2.SetWindowText(cText);
    DBW.CloseCursor();
}
