// DlgSpravSmp.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSpravSmp.h"
#include <sqlext.h>
#include ".\dlgspravsmp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern SQLRETURN    g_sqlret;
extern CMasterApp   theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgSpravSmp dialog


CDlgSpravSmp::CDlgSpravSmp(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSpravSmp::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSpravSmp)
	//}}AFX_DATA_INIT
    DlgMode = 0;
    Style = 0;
    cRet[0] = 0;
    dwRet = 0;
    c_retText[0] = 0;
    c_retText2[0] = 0;
    c_retText3[0] = 0;
	iGridMark = -1;
}


void CDlgSpravSmp::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSpravSmp)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDOK, m_bOK);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_EDIT1, m_EdFind);
	DDX_Control(pDX, IDC_STATICc, m_Lab1);
}


BEGIN_MESSAGE_MAP(CDlgSpravSmp, CDialog)
	//{{AFX_MSG_MAP(CDlgSpravSmp)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	ON_NOTIFY(HDN_ITEMCLICK, 0, OnListItemclick)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT1, &CDlgSpravSmp::OnEnChangeEditFind)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSpravSmp message handlers
extern CString sOldText;
BOOL CDlgSpravSmp::OnInitDialog() 
{    
	CDialog::OnInitDialog();
	sOldText = "";
	m_EdFind.QInit(80, 1);
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );
    if( !Style ) m_bOK.ModifyStyle(WS_VISIBLE, 0);
    cQuery[0] = 0;
    DWORD dwCount = 0;
    char cName[64] = "";
    if( DlgMode == 110 )
        strcpy(cQuery, "pTov_GetNeispKP 1");
    if( DlgMode == 111 )
	    strncpy(cQuery, "pTov_GetTKP 1", 64);
    else
    if( DlgMode == 112 )
        strncpy(cQuery, "pTov_GetPodshNeisp", 64);
    else
    if( DlgMode == 113 )
        strncpy(cQuery, "pTov_GetTypeRemKP", 64);
    else
    if( DlgMode == 114 )
        strncpy(cQuery, "pTov_GetTypeRemPodsh",64);
	else
	if( DlgMode == 200 )
	{
		strcpy(cQuery, "pTov_GetOperVag");
		m_bOK.ModifyStyle(WS_VISIBLE, 0);
		SetWindowText("Операции с вагонами");
	} else
	if( DlgMode == 201 )
	{
		strcpy(cQuery, "pTov_GetKodErr");
		m_bOK.ModifyStyle(WS_VISIBLE, 0);
		SetWindowText("Коды ошибок АСОУП");
	} else
	if( DlgMode == 300 )
	{
		strcpy(cQuery, "pTov_GetCountryList");
//		m_bOK.ModifyStyle(WS_VISIBLE, 0);
		SetWindowText("Страны");
	} else
	if( DlgMode == 400 )
	{
		strcpy(cQuery, "pTov_GetSobstPr");
		m_bOK.ModifyStyle(0, WS_VISIBLE);
		Style = 1;
		SetWindowText("Предприятия собственники");
	} else
	if( DlgMode == 401 )
	{
		strcpy(cQuery, "pTov_GetAllClients");
		m_bOK.ModifyStyle(0, WS_VISIBLE);
		Style = 1;
		m_Lab1.ModifyStyle(0, WS_VISIBLE);
		m_EdFind.ModifyStyle(0, WS_VISIBLE);
		SetWindowText("Предприятия собственники");
	}

    DBW.ExecSQL(cQuery);
    DBW.SetListHeader(&m_List);
    UpdateListByQuery();
    DBW.CloseCursor();
	return TRUE;
}

extern long strtohextoval(SQL_NUMERIC_STRUCT scNum);

void CDlgSpravSmp::UpdateListByQuery()
{
    DBW.UpdateListByHandle(&m_List);
    /*
    DWORD dwCount = 0;
    SQL_NUMERIC_STRUCT nsNum;
    SQLHDESC h_desc = NULL;
    char  cText[512] = "";
    DWORD  dwNum = 0;
    long  Ind = 0;
    long a, b;
    char  cRez[512] = "";
    m_List.DeleteAllItems();
    SQLColAttribute(g_hsqlstmt, 0, SQL_DESC_COUNT, NULL, 0, NULL, &dwCount);
    int iCW[128];
    memset(&iCW, 0, sizeof(int)* 128);
    int iSW = 0;
    for(DWORD j=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && j < 1024; j++ )
    {
        for( WORD i=0; i < dwCount; i++ )
        {
            SQLColAttribute(g_hsqlstmt, i + 1, SQL_DESC_TYPE_NAME, cRez, 64, NULL, NULL);
            SQLColAttribute(g_hsqlstmt, i + 1, SQL_DESC_TYPE, NULL, 0, NULL, &dwNum);
            sprintf(cText, "%s (%d)", cRez, dwNum);
            if( dwNum == 12 ) //varchar
            {
                DBW.GetData( i + 1, SQL_C_CHAR, cText, 128, &Ind);                
            } else
            if( dwNum == 4 )
            {
                DBW.GetData( i + 1, SQL_C_SLONG, &dwNum, 4, &Ind);
                if( i == 4 )
                {
                    dwID[j] = dwNum;
                }
                itoa(dwNum, cText, 10);
            } else
            if( dwNum == 2 ) // numeric
            {
                SQLGetStmtAttr(g_hsqlstmt, SQL_ATTR_APP_ROW_DESC,&h_desc, 0, NULL);
                SQLSetDescField (h_desc,i + 1,SQL_DESC_TYPE,(VOID*)SQL_C_NUMERIC,0);
                SQLSetDescField (h_desc,i + 1,SQL_DESC_PRECISION,(VOID*) 6,0);
                SQLSetDescField (h_desc,i + 1,SQL_DESC_SCALE,(VOID*) 3,0);
                a=b=sizeof(nsNum);
                memset(nsNum.val, 0, 16);
                DBW.GetData( i + 1, SQL_ARD_TYPE, &nsNum, 19, &Ind);
                Ind = sizeof(nsNum);
                long lVal = 0;
                double rez = 0;
                int divisor = 1;
                lVal = strtohextoval(nsNum);
                if( nsNum.scale > 0 )
                    for(int x=0; x < nsNum.scale; x++ )
                        divisor *= 10;
                rez = (double)lVal/(double)divisor;
                if( !nsNum.sign ) rez = -rez;

                if( nsNum.scale > 1 )
                {
                    sprintf(cText, "%f", rez);
                }
                else
                    itoa(lVal, cText, 10);
            }
            if( Ind != -1 ) 
            {
                if( i == 0 )
                    m_List.InsertItem(LVIF_TEXT | LVIF_STATE, j, cText, 0, LVIS_SELECTED, 0, 0);
                else
                    m_List.SetItemText(j, i, cText);
                if(iCW[i] < (iSW = m_List.GetStringWidth(cText))) iCW[i]=iSW;
            }

        }
    }
    for(WORD i=0; i < dwCount; i++ ) 
    {
        if( iCW[i] == 0 ) continue;
        m_List.SetColumnWidth(i, iCW[i]+15);
    }
    */
}

void CDlgSpravSmp::OnOK() 
{
    char cText[64] = "";
    if( !Style ) return;
    int idx = m_List.GetSelectionMark();
	if( idx == -1 ) idx = iGridMark;
	if( idx == -1 ) return;
	

    dwRet = m_List.GetItemData(idx);
    if( DlgMode == 111 || DlgMode == 110 )
    {
        m_List.GetItemText(idx, 0, cRet, 64);
        m_List.GetItemText(idx, 1, c_retText2, 64);
        m_List.GetItemText(idx, 2, c_retText, 64);
		m_List.GetItemText(idx, 3, c_retText3, 64);

        m_List.GetItemText(idx, 4, cText, 64);
        dwRet = atoi(cText);
    } else
    if( DlgMode == 112 )
    {
        m_List.GetItemText(idx, 0, cRet, 64);
    } else
    if( DlgMode == 114 )
    {
        m_List.GetItemText(idx, 0, cRet, 64);
        dwRet = atoi(cRet);
    } 
    if( DlgMode == 400 )
    {
        m_List.GetItemText(idx, 0, cRet, 64);
        m_List.GetItemText(idx, 1, c_retText, 64);
		m_List.GetItemText(idx, 2, c_retText2, 64);
	} else
    if( DlgMode == 401 )
    {
        m_List.GetItemText(idx, 0, cRet, 64);
        m_List.GetItemText(idx, 1, c_retText, 64);
		m_List.GetItemText(idx, 2, c_retText2, 64);
	} 	

	else
	{
        m_List.GetItemText(idx, 0, cRet, 64);
        m_List.GetItemText(idx, 1, c_retText, 64);
	} 
	CDialog::OnOK();
}

void CDlgSpravSmp::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{    
	*pResult = 0;
    OnOK();
}

void CDlgSpravSmp::OnListItemclick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
    m_List.OnHeaderClicked(	pNMHDR, pResult );
	*pResult = 0;
}

void CDlgSpravSmp::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CDlgSpravSmp::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CDlgSpravSmp::OnEnChangeEditFind()
{
	CString s1;
    CString s2;
    m_EdFind.GetWindowText(s1);
	s1.TrimRight();
    if( s1.GetLength() <= 0 )
    {
        m_List.ClearMark();
		iGridMark = -1;
        return;
    }

    for( int i=0; i < m_List.GetItemCount(); i++ )
    {
        s2 = m_List.GetItemText(i, 0);
        if( s2.Left(s1.GetLength()) == s1 )
        {
//            int x = m_List.SetSelectionMark(i);
			m_List.ClearMark();
            m_List.SetMarkedItem(i);
			iGridMark = i;
//            m_List.SetHotCursor(i);
            m_List.EnsureVisible(i, TRUE);
            m_List.RedrawWindow();
            sOldText = s1;
            return;
        }
    }
    m_EdFind.SetWindowText(sOldText);
}
