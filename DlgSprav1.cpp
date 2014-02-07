// DlgSprav1.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSprav1.h"
#include "DlgAddPr.h"
#include "DlgEdRsn.h"
//#include <sql.h>
#include <sqlext.h>
//#include <sqltypes.h>
//#include <odbcss.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp   theApp;
extern DWORD        g_iFam;
WORD   rState = 0;
extern WORD g_iRang;
char cQuery[1024] = "";

/////////////////////////////////////////////////////////////////////////////
// CDlgSprav1 dialog


CDlgSprav1::CDlgSprav1(CWnd* pParent /*= NULL*/)
        : CDialog(CDlgSprav1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSprav1)
	m_Edit1Text = _T("");
	m_Combo2Index = -1;
	m_RecCount = _T("");
	//}}AFX_DATA_INIT
    iDlgMode = 0;
    iDlgKind = 0;
    cOldText[0] = 0;
    cKodPr[0] = 0;
    cTypePr[0] = 0;
    cPrName[0] = 0;
}


void CDlgSprav1::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSprav1)
	DDX_Control(pDX, IDC_LIST2, m_List);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1Text);
	DDX_CBIndex(pDX, IDC_COMBO2, m_Combo2Index);
	DDX_Text(pDX, IDC_EDIT2, m_RecCount);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDOK, m_Lab);
	DDX_Control(pDX, IDC_BUTTON1, m_But1);
	DDX_Control(pDX, IDC_BUTTON2, m_But2);
	DDX_Control(pDX, IDC_BUTTON3, m_But3);
	DDX_Control(pDX, IDC_STATICXX, m_Labb);
}


BEGIN_MESSAGE_MAP(CDlgSprav1, CDialog)
	//{{AFX_MSG_MAP(CDlgSprav1)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnSelchangeCombo2)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST2, OnDblclkList2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_NOTIFY(HDN_ITEMCLICK, 0, OnListItemHeaderClick)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSprav1 message handlers

BOOL CDlgSprav1::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

    m_List.InsertColumn(0, "Тип", LVCFMT_LEFT,  50, -1);
    m_List.InsertColumn(1, "Клеймо", LVCFMT_LEFT,  50, -1);
    m_List.InsertColumn(2, "Наименование", LVCFMT_LEFT,  200, -1);
    m_List.InsertColumn(3, "Код", LVCFMT_LEFT,  40, -1);
    m_List.InsertColumn(4, "ЕСР", LVCFMT_LEFT,  50, -1);
    m_List.InsertColumn(5, "Станция", LVCFMT_LEFT,  110, -1);
    m_List.InsertColumn(6, "Дорога", LVCFMT_LEFT,  50, -1);
    m_List.InsertColumn(7, "Сокр. наим.", LVCFMT_LEFT,  80, -1);
//    m_List.SetColumnWidth(2, 200);
//    char cQuery[512] = "";
    sprintf(cQuery, "pTov_GetAllPred %d, 0, ''", iDlgKind);
    DBW.ExecSQL(cQuery);
    UpdateListByHandle();
    char cQuery1[128]="";
    DWORD dwNum = 0;
//    strcpy(cQuery1, "SELECT DISTINCT nsTovPR_FOROSV.TPR FROM nsTovPR_FOROSV");
    DBW.FillComboWithTPR(&m_Combo2);
    if( iDlgMode )
    {
        CButton *b = (CButton *)GetDlgItem(IDOK);
        b->ModifyStyle(WS_VISIBLE, 0);
    }

    switch (iDlgKind)
    {
    case 3: SetWindowText("Справочник по предприятиям освидетельствования КП"); break;
    case 4: SetWindowText("Справочник по предприятиям изготовления оси"); break;
    case 5: SetWindowText("Справочник по предприятиям формирования КП"); break;
    case 6: SetWindowText("Справочник по предприятиям изготовления тележек"); break;
    }

	if( g_iRang < 3 )
	{
//		m_Labb.ModifyStyle(WS_VISIBLE, 0);
		m_But1.ModifyStyle(WS_VISIBLE, 0);
//		m_But2.ModifyStyle(WS_VISIBLE, 0);
		m_But3.ModifyStyle(WS_VISIBLE, 0);
	}

	return TRUE;
}

void CDlgSprav1::UpdateListByHandle()
{
//    m_List.DeleteAllItems();
    char    cText[512]="";
    DWORD   dwNum = 0;
    long    Ind;
    DWORD dwNewRecCount = 0;
    DWORD dwTick = GetTickCount();

    DWORD dwWasRecCount = m_List.GetItemCount();

	DWORD i;
    for(i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 1024; i++ )
    {
        DBW.GetData( 1, SQL_C_CHAR, cText, 10, &Ind);
//        if(dwWasRecCount < i + 1) m_List.InsertItem(LVIF_TEXT | LVIF_STATE, i, cText, 0, LVIS_SELECTED, 0, 0);
        if(dwWasRecCount < i + 1) m_List.InsertItem(i, cText);
        else m_List.SetItemText(i, 0, cText);
        
        DBW.GetData( 2, SQL_C_CHAR, cText, 8, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 1, cText);
        else m_List.SetItemText(i, 1, "");

        DBW.GetData( 3, SQL_C_CHAR, cText, 30, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 2, cText);
        else m_List.SetItemText(i, 2, "");

        DBW.GetData( 4, SQL_C_SLONG, &dwNum, 4, &Ind);
        itoa(dwNum, cText, 10);
        if( Ind != -1 ) m_List.SetItemText(i, 3, cText);
        else m_List.SetItemText(i, 3, "");

        DBW.GetData( 5, SQL_C_CHAR, cText, 30, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 4, cText);
        else m_List.SetItemText(i, 4, "");

        DBW.GetData( 6, SQL_C_CHAR, cText, 20, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 5, cText);
        else m_List.SetItemText(i, 5, "");

        DBW.GetData( 7, SQL_C_CHAR, cText, 20, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 6, cText);
        else m_List.SetItemText(i, 6, "");

        DBW.GetData( 8, SQL_C_CHAR, cText, 20, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 7, cText);
        else m_List.SetItemText(i, 7, "");

        DBW.GetData( 9, SQL_C_SLONG, &dwNum, 4, &Ind);
        m_List.SetItemData(i, dwNum);
        dwNewRecCount++;
    }

    for(i++ ; i < dwWasRecCount + 1; i++ )
    {
        m_List.DeleteItem(dwNewRecCount);
//        m_List.SetItemText(i, 0, "YO");
    }
    itoa(GetTickCount() - dwTick, cText, 10);
//    AfxMessageBox(cText);
    CString cRecCount;
    cRecCount.Format("Количество записей: %d", m_List.GetItemCount());
    CEdit *ed = (CEdit *)GetDlgItem(IDC_EDIT2);
    ed->SetWindowText(cRecCount);    
	DBW.CloseCursor();
}

void CDlgSprav1::OnRadio1() 
{
    m_Edit1.EnableWindow();
    m_Combo1.ModifyStyle(0, WS_DISABLED);
    m_Combo2.ModifyStyle(0, WS_DISABLED);
    m_Edit1.SetWindowText("");
    m_Combo1.SetCurSel(-1);
    if(rState == 3)
    {
        rState = 1;
        OnChangeEdit1();
    } else
    if( rState == 4 )
    {
        sprintf(cQuery, "pTov_GetAllPred %d, 0, NULL", iDlgKind, (LPCSTR)m_Edit1Text);
        DBW.ExecSQL(cQuery);
        UpdateListByHandle();
    }
    rState = 1;
    m_Edit1.SetFocus();
}

void CDlgSprav1::OnRadio2() 
{
	m_Edit1.EnableWindow();
    m_Combo1.SetCurSel(-1);
    m_Combo1.ModifyStyle(0, WS_DISABLED);
    m_Combo2.ModifyStyle(0, WS_DISABLED);
    m_Edit1.SetWindowText("");
    if( rState == 4 )
    {
        sprintf(cQuery, "pTov_GetAllPred %d, 0, NULL", iDlgKind, (LPCSTR)m_Edit1Text);
        DBW.ExecSQL(cQuery);
        UpdateListByHandle();
    }
    rState = 2;
    m_Edit1.SetFocus();
}

void CDlgSprav1::OnRadio3() 
{
    m_Edit1.EnableWindow(FALSE);
    m_Combo1.ModifyStyle(WS_DISABLED, 0);
    m_Combo2.ModifyStyle(0, WS_DISABLED);
    m_Edit1.SetWindowText("");
    rState = 3;
}

void CDlgSprav1::OnRadio4() 
{
//    m_Edit1.ModifyStyle(0, WS_DISABLED);
    m_Edit1.EnableWindow(FALSE);
    m_Combo1.ModifyStyle(0, WS_DISABLED);
    m_Combo2.ModifyStyle(WS_DISABLED, 0);
    m_Edit1.SetWindowText("");
    if( m_Combo2.GetCurSel() > -1 )
    {
        sprintf(cQuery, "pTov_GetAllPred %d, 2, '%s'", iDlgKind, (LPCSTR)m_Edit1Text);
        DBW.ExecSQL(cQuery);
        UpdateListByHandle();
    }
    rState = 4;
}

void CDlgSprav1::OnChangeEdit1() 
{
    char cText[255]="";
//    char cQuery[1024] = "";
    CEdit *ed = (CEdit *)GetDlgItem(IDC_EDIT1);
    ed->GetWindowText(m_Edit1Text);
    if( rState == 1 && m_Edit1Text != cOldText)
    {
        sprintf(cQuery, "pTov_GetAllPred %d, 1, '%s'", iDlgKind, (LPCSTR)m_Edit1Text);        
        DBW.ExecSQL(cQuery);
        UpdateListByHandle();
    }
    if( rState == 2 && m_Edit1Text != cOldText)
    {
        sprintf(cQuery, "pTov_GetAllPred %d, 2, '%s'", iDlgKind, (LPCSTR)m_Edit1Text);
        DBW.ExecSQL(cQuery);
        UpdateListByHandle();
    }
    strcpy(cOldText, m_Edit1Text);
}

void CDlgSprav1::OnSelchangeCombo2() 
{
//    char cQuery[512] = "";
//    char cText[16];
//    m_Combo2.GetLBText(m_Combo2.GetCurSel(), cText);
    sprintf(cQuery, "pTov_GetAllPred %d, 3, NULL, %u", iDlgKind, m_Combo2.GetItemData(m_Combo2.GetCurSel()));
    DBW.ExecSQL(cQuery);
    if( g_sqlret == -1 ) AfxMessageBox("!@");
    UpdateListByHandle();
    strcpy(cOldText, "XXX^XXX^XXX");
}

void CDlgSprav1::OnOK() 
{
	int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
    m_List.GetItemText(idx, 1, cKodPr, 32);
    m_List.GetItemText(idx, 2, cPrName, 64);
    ret_dwIPR = m_List.GetItemData(idx);
    m_List.GetItemText(idx, 0, cTypePr, 32);
	m_List.GetItemText(idx, 7, cPrSName, 64);

	CDialog::OnOK();
}

void CDlgSprav1::OnDblclkList2(NMHDR* pNMHDR, LRESULT* pResult) 
{
    if( iDlgMode ) return;
/*	int idx = m_List.GetSelectionMark();
    m_List.GetItemText(idx, 1, KodPr, 32);
	CDialog::OnOK();*/
    OnOK();
    *pResult = 0;
}

void CDlgSprav1::OnButton1() 
{
    CDlgAddPr Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;
    char cQ[1024] = "";
    if( Dlg.m_Edit1Text == "" ) Dlg.m_Edit1Text = "NULL";
    else Dlg.m_Edit1Text = "'" + Dlg.m_Edit1Text + "'";
    if( Dlg.m_Edit2Text == "" ) Dlg.m_Edit2Text = "NULL";
    else Dlg.m_Edit2Text = "'" + Dlg.m_Edit2Text + "'";
    if( Dlg.m_Edit5Text == "" ) Dlg.m_Edit5Text = "NULL";
    else Dlg.m_Edit5Text = "'" + Dlg.m_Edit5Text + "'";

    if( Dlg.m_Edit8Text == "" ) Dlg.m_Edit8Text = "NULL";
    else Dlg.m_Edit8Text = "'" + Dlg.m_Edit8Text + "'";


    sprintf(cQ, "pTov_AddPredpr %d, %s, %s, %s, %s, '%s', '%s', %d, %d", 
                Dlg.dwTypePr,
                Dlg.m_Edit5Text,
                Dlg.m_Edit8Text, 
                Dlg.m_Edit1Text, 
                Dlg.m_Edit2Text, 
                Dlg.m_Edit4text, 
                Dlg.m_Edit3Text,
                Dlg.m_bCheck1,
				Dlg.m_bCheck2);
    DBW.ExecSQL(cQ);
    DBW.CloseCursor();
	DBW.ReallocHandle();

    DBW.ExecSQL(cQuery);
    UpdateListByHandle();
}

//корректировка записи
void CDlgSprav1::OnButton2() 
{
	CDlgAddPr Dlg;
    char cQ[512]="";
    char cText[80] = "";
    int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
    Dlg.dwID = m_List.GetItemData(idx);
    Dlg.iMode = 1;
    sprintf(cQ, "pTov_GetCompletePredpr %d", m_List.GetItemData(idx));
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        DBW.CloseCursor();
        return;
    }
    long Ind = 0;
    DWORD dwNum = 0;
    DBW.GetData( 1, SQL_C_ULONG, &Dlg.dwTypePr, 4, &Ind);
    DBW.GetData( 2, SQL_C_CHAR, cText, 10, &Ind);
    if( Ind != -1 ) Dlg.m_Edit1Text = cText;
    DBW.GetData( 3, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( Ind != -1 )
    {
        itoa(dwNum, cText, 10);
        Dlg.m_Edit2Text = cText;
    }
    DBW.GetData( 4, SQL_C_CHAR, cText, 60, &Ind);
    if( Ind != -1 ) Dlg.m_Edit3Text = cText;
    DBW.GetData( 5, SQL_C_CHAR, cText, 16, &Ind);
    if( Ind != -1 ) Dlg.m_Edit4text = cText;
    DBW.GetData( 6, SQL_C_CHAR, cText, 7, &Ind);
    if( Ind != -1 ) Dlg.m_Edit8Text = cText; //ESR
    DBW.GetData( 7, SQL_C_CHAR, cText, 30, &Ind);
    if( Ind != -1 ) Dlg.m_Edit9Text = cText; //NAME_ST
//    DBW.GetData( 9, SQL_C_CHAR, cText, 30, &Ind);
//    if( Ind != -1 ) Dlg.m_Edit10Text = cText;
    DBW.GetData( 8, SQL_C_CHAR, cText, 16, &Ind);
    if( Ind != -1 ) Dlg.m_Edit5Text = cText;
    DBW.GetData( 9, SQL_C_CHAR, cText, 30, &Ind);
    if( Ind != -1 ) Dlg.m_Edit6Text = cText;
    DBW.GetData( 10, SQL_C_CHAR, cText, 30, &Ind);
    if( Ind != -1 ) Dlg.m_Edit7Text = cText;
    DBW.GetData( 11, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( Ind != -1 && dwNum) Dlg.m_bCheck1 = TRUE;
	DBW.GetData( 12, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( Ind != -1 && dwNum) Dlg.m_bCheck2 = TRUE;
    DBW.CloseCursor();


    if( Dlg.DoModal() == IDCANCEL ) return;

    if( Dlg.m_Edit1Text == "" ) Dlg.m_Edit1Text = "NULL";
    else Dlg.m_Edit1Text = "'" + Dlg.m_Edit1Text + "'";
    if( Dlg.m_Edit2Text == "" ) Dlg.m_Edit2Text = "NULL";
    else Dlg.m_Edit2Text = "'" + Dlg.m_Edit2Text + "'";
    if( Dlg.m_Edit5Text == "" ) Dlg.m_Edit5Text = "NULL";
    else Dlg.m_Edit5Text = "'" + Dlg.m_Edit5Text + "'";
    if( Dlg.m_Edit8Text == "" ) Dlg.m_Edit8Text = "NULL";
    else Dlg.m_Edit8Text = "'" + Dlg.m_Edit8Text + "'";

    sprintf(cQ, "pTov_AlterPredpr %d, %u,%s, %s, %s, %s, '%s', '%s', %d, %d", 
                Dlg.dwID,
                Dlg.dwTypePr,
                Dlg.m_Edit5Text,
                Dlg.m_Edit8Text,
                Dlg.m_Edit1Text,
                Dlg.m_Edit2Text,
                Dlg.m_Edit4text,
                Dlg.m_Edit3Text,
                Dlg.m_bCheck1,
				Dlg.m_bCheck2);
    DBW.ExecSQL(cQ);
    DBW.CloseCursor();

    DBW.ExecSQL(cQuery);
    UpdateListByHandle();
    
}

void CDlgSprav1::OnButton3() 
{
    CDlgEdRsn Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;
    char cQ[1280] = "";
    int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
    sprintf(cQ, "exec pTov_DelPredpr %u, %u, '%s'", g_iFam, m_List.GetItemData(idx), Dlg.m_Text);
    DBW.ExecSQL(cQ);
    DBW.CloseCursor();
    DBW.ReallocHandle();
    DBW.ExecSQL(cQuery);
    UpdateListByHandle();
}

void CDlgSprav1::OnListItemHeaderClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	m_List.OnHeaderClicked(pNMHDR, pResult);
	*pResult = 0;
}
