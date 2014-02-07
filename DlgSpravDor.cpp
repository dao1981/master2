// DlgSpravDor.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSpravDor.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "odbcss.h"

extern SQLRETURN    g_sqlret;
extern CMasterApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgSpravDor dialog


CDlgSpravDor::CDlgSpravDor(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSpravDor::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSpravDor)
	//}}AFX_DATA_INIT
    DlgMode = 0;
    SelMode = 0;
    c_cDor[0] = 0;
    c_cKodDor[0] = 0;
    c_cFullName[0] = 0;
    c_cShortName[0] = 0;
}


void CDlgSpravDor::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSpravDor)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDOK, m_ButOK);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSpravDor, CDialog)
	//{{AFX_MSG_MAP(CDlgSpravDor)
	ON_NOTIFY(HDN_ITEMCLICK, 0, OnItemclickList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSpravDor message handlers

BOOL CDlgSpravDor::OnInitDialog() 
{
	CDialog::OnInitDialog();
    char cQuery[512]="";
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );
    m_List.InsertColumn(0, "Код", LVCFMT_LEFT,  80, -1);
    m_List.InsertColumn(1, "Наименование", LVCFMT_LEFT,  150, -1);
    m_List.InsertColumn(2, "Обозначение", LVCFMT_LEFT,  100, -1); 
    if( DlgMode == 1 )
    {
        sprintf(cQuery, "pTov_GetAllStanc '%s'", c_cDor);
//        m_List.InsertColumn(3, "IST", LVCFMT_LEFT,  40, -1);
        m_List.DeleteColumn(2);
        SetWindowText("Справочник по станциям");
    }
    else 
    {
        strncpy(cQuery, "SELECT DOROGAID, NAME, MNKD FROM nsDOROGA", 255);
    }
    DBW.ExecSQL(cQuery);
    char    cText[512]="";
    DWORD   dwNum = 0;
    long    Ind = 0;
    for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 1024; i++ )
    {
        DBW.GetData( 1, SQL_C_CHAR, cText, 20, &Ind);
//        if( Ind != -1 ) m_List.InsertItem(LVIF_TEXT | LVIF_STATE, i, cText, 0, LVIS_SELECTED, 0, 0);
        if( Ind != -1 ) m_List.InsertItem(i, cText);
        else m_List.InsertItem(i, "");
//        else m_List.InsertItem(LVIF_TEXT | LVIF_STATE, i, "", 0, LVIS_SELECTED, 0, 0);

        DBW.GetData( 2, SQL_C_CHAR, cText, 20, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 1, cText);

        if( !DlgMode )
        {
            DBW.GetData( 3, SQL_C_CHAR, cText, 30, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 2, cText);
        }

/*        DBW.GetData( 4, SQL_C_ULONG, &dwNum, 5, &Ind);
        itoa(dwNum, cText, 10);
        if( Ind != -1 ) m_List.SetItemText(i, 3, cText);*/
    }
    DBW.CloseCursor();
    if( m_List.GetItemCount() == 0 )
    {
        AfxMessageBox("В справочнике нет ни одной записи!");
        return FALSE;
    }
    m_List.SetSelectionMark(0);
	return TRUE;
}

void CDlgSpravDor::OnOK() 
{
    int idx = m_List.GetSelectionMark();
    m_List.GetItemText(idx, 0, c_cKodDor, 32);
    m_List.GetItemText(idx, 1, c_cFullName, 32);
    m_List.GetItemText(idx, 2, c_cShortName, 32);
    strcpy(c_cDor, c_cKodDor);

	CDialog::OnOK();
}

void CDlgSpravDor::OnItemclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
    m_List.OnHeaderClicked(pNMHDR, pResult);
	*pResult = 0;
}

void CDlgSpravDor::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 0;
    OnOK();
}
