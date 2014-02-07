// DlgSpravKdr.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSpravKdr.h"
#include "DlgSotrEd.h"
#include "DlgEdRsn.h"
#include "DlgEditEmployee.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <sqlext.h>
#include ".\dlgspravkdr.h"

extern CMasterApp   theApp;
extern DWORD        g_iFam;
extern DWORD        g_iDep;
extern WORD			g_iRang;
/////////////////////////////////////////////////////////////////////////////
// CDlgSpravKdr dialog
extern int	g_NewEmployeeDlg;

CDlgSpravKdr::CDlgSpravKdr(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSpravKdr::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSpravKdr)
	//}}AFX_DATA_INIT
    SearchMode = 0;
    DlgMode = 0;
    iFilter = 0;
    nSortedCol = -1;
    bSortAscending = TRUE;
    cFio[0] = 0;
    dwFio = 0;
}


void CDlgSpravKdr::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSpravKdr)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDOK, m_OK);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_BUTTON1, m_bn1);
	DDX_Control(pDX, IDC_BUTTON3, m_bn2);
	DDX_Control(pDX, IDC_BUTTON2, m_bn3);
	DDX_Control(pDX, IDC_STATIC_X, m_Lab);
}


BEGIN_MESSAGE_MAP(CDlgSpravKdr, CDialog)
	//{{AFX_MSG_MAP(CDlgSpravKdr)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_NOTIFY(HDN_ITEMCLICK, 0, OnListHeaderClick)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSpravKdr message handlers

BOOL CDlgSpravKdr::OnInitDialog() 
{
	CDialog::OnInitDialog();
    if( !DlgMode )
    {
        m_OK.ModifyStyle(WS_VISIBLE, 0);
    }
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );
    m_List.InsertColumn(0, "ФИО", LVCFMT_LEFT,  200, -1);
    m_List.InsertColumn(1, "Таб. номер", LVCFMT_LEFT,  100, -1);
    m_List.InsertColumn(2, "Должность", LVCFMT_LEFT,  150, -1);

    if( !iFilter ) sprintf(cQuery, "pTov_GetAllEmployee 0, '', 0, %u", g_iDep);
    else
    if( iFilter ) sprintf(cQuery, "pTov_GetAllEmployee 0, '', %d, %u", iFilter, g_iDep);
    char cText[255] = "";
    long Ind = 0;
    DWORD dwNum = 0;
    DBW.ExecSQL(cQuery);
    UpdateListByQuery();
	DBW.CloseCursor();

	if( g_iRang < 3 )
	{
		m_bn1.ModifyStyle(WS_VISIBLE, 0);
		m_bn2.ModifyStyle(WS_VISIBLE, 0);
		m_bn3.ModifyStyle(WS_VISIBLE, 0);
		m_Lab.ModifyStyle(WS_VISIBLE, 0);
	}
//    m_List.ModifyStyle(0, LVS_SORTASCENDING, 0);
	return TRUE;
}

void CDlgSpravKdr::OnChangeEdit1() 
{
    if( SearchMode <= 0) return;
    CString cText;
    m_Edit.GetWindowText(cText);
/*    if( SearchMode == 4 )
    {
        DWORD d = atoi(cText);
        if( d == 0 ) return;
    }
*/
    sprintf(cQuery, "pTov_GetAllEmployee %u, '%s', %u, %u", SearchMode, cText, iFilter, g_iDep);
    DBW.ExecSQL(cQuery);
    UpdateListByQuery();
//    m_List.SortList();
    DBW.CloseCursor();
}

void CDlgSpravKdr::OnRadio1() 
{
    m_Edit.SetWindowText("");
    SearchMode=1;
}

void CDlgSpravKdr::OnRadio3() 
{
    m_Edit.SetWindowText("");
    SearchMode=2;
}

void CDlgSpravKdr::OnRadio4() 
{
    m_Edit.SetWindowText("");
    SearchMode=3;
}

void CDlgSpravKdr::OnRadio5() 
{
    m_Edit.SetWindowText("");
    SearchMode=4;	
}

void CDlgSpravKdr::UpdateListByQuery()
{
    char cText[255] = "";
    long Ind = 0;
    DWORD dwNum = 0;
    m_List.DeleteAllItems();

    for( DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && i < 40000; i++ )
    {
        DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
        DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
        m_List.InsertItem(i, cText);
        if( Ind != -1 ) m_List.SetItemData(i, dwNum);
        DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 1, cText);
        DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 2, cText);

    }

/*
    for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 1024; i++ )
    {
        DBW.GetData( 1, SQL_C_ULONG, &dwFam[i], 4, &Ind);
        m_List.InsertItem(i, "field");
        if( Ind != -1 ) 
        {            
            m_List.SetItemData(i, dwFam[i]);
        }

        DBW.GetData( 2, SQL_C_CHAR, cText, 20, &Ind);
//        if( Ind != -1 ) m_List.InsertItem(LVIF_TEXT | LVIF_STATE, i, cText, 0, LVIS_SELECTED, 0, 0);
        m_List.SetItemText(i, 0, cText);
//        else m_List.SetItemText(i, 0, "N/A");

//        if( Ind != -1 ) m_List.SetItemText(i, 0, cText);
//        else m_List.SetItemText(i, 0, "N/A");

        DBW.GetData( 3, SQL_C_CHAR, cText, 20, &Ind);
        m_List.SetItemText(i, 1, "1");
//        if( Ind != -1 ) m_List.SetItemText(i, 1, cText);

        DBW.GetData( 4, SQL_C_CHAR, cText, 20, &Ind);
        m_List.SetItemText(i, 2, "2");
        if( Ind != -1 ) m_List.SetItemText(i, 2, cText);

    }	
*/    
}

void CDlgSpravKdr::OnButton1() 
{
    CDlgSotrEd Dlg;	

	if( g_NewEmployeeDlg )
	{
		CDlgEditEmployee Dlg1;
		Dlg1.iMode = 0;
		Dlg1.dwID = 0;
		if( Dlg1.DoModal() == IDCANCEL ) return;
		DBW.ExecSQL(cQuery);
		UpdateListByQuery();
		DBW.CloseCursor();
		return;
	}


    if( Dlg.DoModal() == IDCANCEL) return;
    char cQ[2048] = "";
    char FIO[64] = "";

//    sprintf(FIO, "%s %c.%c.", Dlg.m_Edit1Text, Dlg.m_Edit2Text[0], Dlg.m_Edit3Text[0]);

	strcpy(FIO, Dlg.m_Edit1Text);
/*
	sprintf(cQ, "pTov_AddEmployer %u, %u, '%s', '%s', '%s', '%s', %d, "\
        "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %s",
        g_iDep,
        Dlg.id,
        Dlg.m_Edit1Text,
        Dlg.m_Edit4Text,
        Dlg.m_Edit5Text,
        Dlg.mcPass,
        Dlg.miRang,
        Dlg.m_cbPRKP,
        Dlg.m_cbPZMKP,
        Dlg.m_cbPDSH,
        Dlg.m_cbPDPO,
        Dlg.m_cbPDVK,
        Dlg.m_cbPDSO,
        Dlg.m_cbPDSP,
        Dlg.m_cbPDD,
        Dlg.m_cbPDO,
        Dlg.m_cbPDG,
        Dlg.m_cbPDROL,
        Dlg.m_cbPDSEP,
        Dlg.m_cbPDNK,
        Dlg.m_cbPOSV,
        Dlg.m_cbPMB,
        Dlg.m_cbSL1,
        Dlg.m_cbSL2,
        Dlg.m_cbPOTK,
        Dlg.m_cbPOP,
        Dlg.m_cbPRP,
        Dlg.m_cbPKP,
        Dlg.m_cbOTP,
        Dlg.m_cbPVPV,
        Dlg.m_cbMRP,
        Dlg.m_cbORED,
        Dlg.m_cbRRED,
        Dlg.m_cbMRED,
        Dlg.m_cbZKP,
        Dlg.m_cbBZKP,
        isNull(Dlg.ret_dwProfID)
        );
    DBW.ExecSQL(cQ);
    if( g_sqlret == SQL_SUCCESS || g_sqlret == SQL_SUCCESS_WITH_INFO )
    {
        AfxMessageBox("Запись успешно добавлена!");
    }
    DBW.CloseCursor();
    DBW.ReallocHandle();

    DBW.ExecSQL(cQuery);
    UpdateListByQuery();
    DBW.CloseCursor();*/
}

// Корректировка записи
void CDlgSpravKdr::OnButton3() 
{
    CDlgSotrEd Dlg;	
    char cText[64] = "";
    int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
    long Ind=0;
/*
	if( g_NewEmployeeDlg )
	{*/
		CDlgEditEmployee Dlg1;
		Dlg1.iMode = 1;
		Dlg1.dwID = m_List.GetItemData(idx);
		if( Dlg1.DoModal() == IDCANCEL ) return;
		DBW.ExecSQL(cQuery);
		UpdateListByQuery();
		DBW.CloseCursor();
		return;
//	}
/*
	char cQ[255] = "";
    DWORD dwNum = 0;

    sprintf(cQ, "pTov_GetEmplInfo %d", m_List.GetItemData(idx));
    DBW.ExecSQL(cQ);
    if( DBW.Fetch()== SQL_NO_DATA) 
    {
        AfxMessageBox("SQL!");
        return;
    }
//    Dlg.id = dwFam[idx];
    Dlg.id = m_List.GetItemData(idx);
    DBW.GetData( 2, SQL_C_CHAR, cText, 20, &Ind);
    if( Ind != -1 ) Dlg.m_Edit1Text = cText;

    DBW.GetData( 3, SQL_C_ULONG, &dwNum, 5, &Ind);
    itoa(dwNum, cText, 10);
    Dlg.m_Edit4Text = cText;
    DBW.GetData( 4, SQL_C_CHAR, cText, 20, &Ind);
    Dlg.m_Edit5Text = cText;
    DBW.GetData( 5, SQL_C_CHAR, Dlg.mcPass, 20, &Ind);

    DBW.GetData( 6, SQL_C_SSHORT, &Dlg.miRang, 4, &Ind);
    DBW.GetData( 7, SQL_C_BIT, &Dlg.m_cbPRKP, 1, &Ind);
    DBW.GetData( 8, SQL_C_BIT, &Dlg.m_cbPZMKP , 1, &Ind);
    DBW.GetData( 9, SQL_C_BIT, &Dlg.m_cbPDSH , 1, &Ind);
    DBW.GetData( 10, SQL_C_BIT, &Dlg.m_cbPDPO , 1, &Ind);
    DBW.GetData( 11, SQL_C_BIT, &Dlg.m_cbPDVK , 1, &Ind);
    DBW.GetData( 12, SQL_C_BIT, &Dlg.m_cbPDSO , 1, &Ind);
    DBW.GetData( 13, SQL_C_BIT, &Dlg.m_cbPDSP , 1, &Ind);
    DBW.GetData( 14, SQL_C_BIT, &Dlg.m_cbPDD , 1, &Ind);
    DBW.GetData( 15, SQL_C_BIT, &Dlg.m_cbPDO , 1, &Ind);
    DBW.GetData( 16, SQL_C_BIT, &Dlg.m_cbPDG , 1, &Ind);
    DBW.GetData( 17, SQL_C_BIT, &Dlg.m_cbPDROL , 1, &Ind);
    DBW.GetData( 18, SQL_C_BIT, &Dlg.m_cbPDSEP , 1, &Ind);
    DBW.GetData( 19, SQL_C_BIT, &Dlg.m_cbPDNK , 1, &Ind);
    DBW.GetData( 20, SQL_C_BIT, &Dlg.m_cbPOSV , 1, &Ind);
    DBW.GetData( 21, SQL_C_BIT, &Dlg.m_cbPMB , 1, &Ind);
    DBW.GetData( 22, SQL_C_BIT, &Dlg.m_cbSL1 , 1, &Ind);
    DBW.GetData( 23, SQL_C_BIT, &Dlg.m_cbSL2 , 1, &Ind);
    DBW.GetData( 24, SQL_C_BIT, &Dlg.m_cbPOTK , 1, &Ind);
    DBW.GetData( 25, SQL_C_BIT, &Dlg.m_cbPOP , 1, &Ind);
    DBW.GetData( 26, SQL_C_BIT, &Dlg.m_cbPRP , 1, &Ind);
    DBW.GetData( 27, SQL_C_BIT, &Dlg.m_cbPKP , 1, &Ind);
    DBW.GetData( 28, SQL_C_BIT, &Dlg.m_cbOTP , 1, &Ind);
    DBW.GetData( 29, SQL_C_BIT, &Dlg.m_cbPVPV , 1, &Ind);
    DBW.GetData( 30, SQL_C_BIT, &Dlg.m_cbMRP , 1, &Ind);
    DBW.GetData( 31, SQL_C_BIT, &Dlg.m_cbORED , 1, &Ind);
    DBW.GetData( 32, SQL_C_BIT, &Dlg.m_cbRRED , 1, &Ind);
    DBW.GetData( 33, SQL_C_BIT, &Dlg.m_cbMRED , 1, &Ind);
    DBW.GetData( 34, SQL_C_BIT, &Dlg.m_cbZKP , 1, &Ind);
    DBW.GetData( 35, SQL_C_BIT, &Dlg.m_cbBZKP , 1, &Ind);
    DBW.GetData( 36, SQL_C_ULONG, &Dlg.ret_dwProfID, 4, &Ind);
    char s[32]="";
    itoa(Ind, s, 10);

    DBW.CloseCursor();
    DBW.ReallocHandle();
    Dlg.Mode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;

    char FIO[64] = "";
//    sprintf(FIO, "%s %c.%c.", Dlg.m_Edit1Text, Dlg.m_Edit2Text[0], Dlg.m_Edit3Text[0]);
    sprintf(cQ, "exec pTov_AlterEmployer %u, %u, '%s', %s, '%s', '%s', %u, "\
        "%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %s",
        m_List.GetItemData(idx),
        g_iDep,
        Dlg.m_Edit1Text,
        Dlg.m_Edit4Text,
        Dlg.m_Edit5Text,
        Dlg.mcPass,
        Dlg.miRang,
        Dlg.m_cbPRKP,
        Dlg.m_cbPZMKP,
        Dlg.m_cbPDSH,
        Dlg.m_cbPDPO,
        Dlg.m_cbPDVK,
        Dlg.m_cbPDSO,
        Dlg.m_cbPDSP,
        Dlg.m_cbPDD,
        Dlg.m_cbPDO,
        Dlg.m_cbPDG,
        Dlg.m_cbPDROL,
        Dlg.m_cbPDSEP,
        Dlg.m_cbPDNK,
        Dlg.m_cbPOSV,
        Dlg.m_cbPMB,
        Dlg.m_cbSL1,
        Dlg.m_cbSL2,
        Dlg.m_cbPOTK,
        Dlg.m_cbPOP,
        Dlg.m_cbPRP,
        Dlg.m_cbPKP,
        Dlg.m_cbOTP,
        Dlg.m_cbPVPV,
        Dlg.m_cbMRP,
        Dlg.m_cbORED,
        Dlg.m_cbRRED,
        Dlg.m_cbMRED,
        Dlg.m_cbZKP,
        Dlg.m_cbBZKP,
        isNull(Dlg.ret_dwProfID)
        );
    DBW.ExecSQL(cQ);
    DBW.CloseCursor();
    DBW.ReallocHandle();
    DBW.ExecSQL(cQuery);
    UpdateListByQuery();
    DBW.CloseCursor();*/
}

void CDlgSpravKdr::OnButton2() 
{
    CDlgEdRsn Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;
    char cQ[1280] = "";
    int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
    sprintf(cQ, "exec pTov_DelEmployer %u, %u, '%s'", g_iFam, m_List.GetItemData(idx), Dlg.m_Text);
    DBW.ExecSQL(cQ);
    DBW.ReallocHandle();
    DBW.ExecSQL(cQuery);
    UpdateListByQuery();
    DBW.CloseCursor();
}

void CDlgSpravKdr::OnOK() 
{
    if( !DlgMode ) return;
    
    int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
    char cText[32] = "";
    char cText1[32] = "";
    char cText2[32] = "";
    m_List.GetItemText(idx, 0, cText2, 32);
    m_List.GetItemText(idx, 1, cText, 32);
    m_List.GetItemText(idx, 2, cText1, 32);
//    sprintf(cFio, "%s %c.%c.", cText2, cText[0], cText1[0]);
    strcpy(cFio, cText2);
    dwFio = m_List.GetItemData(idx);
	CDialog::OnOK();
}

void CDlgSpravKdr::OnListHeaderClick(NMHDR* pNMHDR, LRESULT* pResult)
{
    m_List.OnHeaderClicked(pNMHDR, pResult);
}

void CDlgSpravKdr::OnClickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{

	*pResult = 0;
}

void CDlgSpravKdr::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{    
	*pResult = 0;
    OnOK();
}

void CDlgSpravKdr::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
