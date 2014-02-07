// DlgAddPr.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgAddPr.h"
#include "DlgSpravDor.h"
#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "odbcss.h"
#include ".\dlgaddpr.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern SQLRETURN    g_sqlret;

extern CMasterApp   theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgAddPr dialog


CDlgAddPr::CDlgAddPr(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgAddPr::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAddPr)
	m_Edit1Text = _T("");
	m_Edit2Text = _T("");
	m_Edit3Text = _T("");
	m_Edit4text = _T("");
	m_Edit5Text = _T("");
	m_Edit6Text = _T("");
	m_Edit8Text = _T("");
	m_Edit9Text = _T("");
	m_Edit7Text = _T("");
	m_bCheck1 = FALSE;
	//}}AFX_DATA_INIT
    dwDor = 0;
//    strcpy(cType, "ВЧД");
    iMode = 0;
    dwID = 0;

    bNeedStamp = false;
    bNeedCode = false;
    bNeedDoroga = false;
    bNeedStan = false;
}


void CDlgAddPr::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_CHECK2, m_Check2);
	DDX_Control(pDX, IDC_EDIT4, m_Edit4);
	DDX_Control(pDX, IDC_EDIT3, m_Edit3);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Control(pDX, IDC_BUTTON3, m_Button3);
	DDX_Control(pDX, IDC_EDIT9, m_Edit9);
	DDX_Control(pDX, IDC_EDIT8, m_Edit8);
	DDX_Control(pDX, IDC_EDIT7, m_Edit7);
	DDX_Control(pDX, IDC_EDIT6, m_Edit6);
	DDX_Control(pDX, IDC_EDIT5, m_Edit5);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1Text);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2Text);
	DDX_Text(pDX, IDC_EDIT3, m_Edit3Text);
	DDX_Text(pDX, IDC_EDIT4, m_Edit4text);
	DDX_Text(pDX, IDC_EDIT5, m_Edit5Text);
	DDX_Text(pDX, IDC_EDIT6, m_Edit6Text);
	DDX_Text(pDX, IDC_EDIT8, m_Edit8Text);
	DDX_Text(pDX, IDC_EDIT9, m_Edit9Text);
	DDX_Text(pDX, IDC_EDIT7, m_Edit7Text);
	DDX_Check(pDX, IDC_CHECK1, m_bCheck1);
	DDX_Check(pDX, IDC_CHECK2, m_bCheck2);
	DDX_Control(pDX, IDOK, m_bOK);
	
}


BEGIN_MESSAGE_MAP(CDlgAddPr, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgAddPr)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_EN_CHANGE(IDC_EDIT5, OnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT8, OnChangeEdit8)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnChangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAddPr message handlers

void CDlgAddPr::OnButton2() 
{
    CDlgSpravDor Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;

    m_Edit5.SetWindowText(Dlg.c_cKodDor);
    m_Edit6.SetWindowText(Dlg.c_cFullName);
    m_Edit7.SetWindowText(Dlg.c_cShortName);
//    dwDor = Dlg.c_dwIdDor;

    m_Edit8.SetWindowText("");
    m_Edit9.SetWindowText("");
    m_Button3.EnableWindow(TRUE);
}

void CDlgAddPr::OnButton3() 
{
    CDlgSpravDor Dlg;
    Dlg.DlgMode = 1;
    m_Edit5.GetWindowText(Dlg.c_cDor, 4);
    if( Dlg.DoModal() == IDCANCEL ) return;

    m_Edit8.SetWindowText(Dlg.c_cKodDor);
    m_Edit9.SetWindowText(Dlg.c_cFullName);
//    m_Edit10.SetWindowText(Dlg.c_cShortName);
}
extern WORD g_iRang; 
BOOL CDlgAddPr::OnInitDialog() 
{    
	CDlgWithAccelerators::OnInitDialog();
    m_Button3.EnableWindow(FALSE);
    m_Combo.SetCurSel(0);
    char cQ[128] = "pTov_GetAllTypesPR";
    DWORD   dwNum = 0;
    char    cText[32] = "";
    long    Ind = 0;
    DBW.ExecSQL(cQ);
    for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 512; i++ )
    {
        DBW.GetData( 1, SQL_C_ULONG, &dwNum, 4, &Ind);        
        DBW.GetData( 2, SQL_C_CHAR, cText, 15, &Ind);
        if( Ind != -1 ) m_Combo.AddString(cText);
        m_Combo.SetItemData(i, dwNum);
        if( iMode && dwNum == dwTypePr ) m_Combo.SetCurSel(i);
    }
    DBW.CloseCursor();
    if(iMode && dwDor)
    {
        m_Edit8.EnableWindow();
        m_Button3.EnableWindow();
        char cText[64] = "";
    }
    else
    {
        m_Edit8.EnableWindow(FALSE);
    }
    if( m_Edit6.GetWindowTextLength() )
    {
        m_Button3.EnableWindow();
        m_Edit8.EnableWindow();
    }
	if( g_iRang < 3 ) m_bOK.EnableWindow(FALSE);
	return TRUE;
}

void CDlgAddPr::OnOK() 
{
	char cText[512] = "";
    char cQuery[1024] = "";
    DWORD dwNum = 0;
    long Ind=0;
    bool    lbNeedStamp = false;
    bool    lbNeedCode = false;
    bool    lbNeedDoroga = false;
    bool    lbNeedStan = false;
    sprintf(cQuery, "pTov_GetTypePrParams %u", dwTypePr);
    DBW.ExecSQL(cQuery);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_BIT, &lbNeedStamp, 1, &Ind);
    DBW.GetData( 2, SQL_C_BIT, &lbNeedCode, 1, &Ind);
    DBW.GetData( 3, SQL_C_BIT, &lbNeedDoroga, 1, &Ind);
    DBW.GetData( 4, SQL_C_BIT, &lbNeedStan, 1, &Ind);
    DBW.CloseCursor();

    m_Edit1.GetWindowText(cText, 64);
	if( lbNeedStamp && cText[0] == 0 )
    {
        AfxMessageBox("Не указано клеймо предприятия!");
        return;
    }
    if( cText[0] != 0 )
    {
        sprintf(cQuery, "SELECT IPR, SNAME FROM nsTovPR_FOROSV WHERE (KLPR='%s') AND (IKORR IS NULL)", cText);
        DBW.ExecSQL(cQuery);
        if( DBW.Fetch() != SQL_NO_DATA )
        {
            DBW.GetData( 1, SQL_C_ULONG, &dwNum, 5, &Ind);
            DBW.GetData( 2, SQL_C_CHAR, cText, 20, &Ind);
            if( dwNum != dwID )
            {
                char msg[128] = "";
                sprintf(msg, "Указанное клеймо не может быть использовано, т.к. уже относится к %s!", cText);
                AfxMessageBox(msg);
                DBW.CloseCursor();
                return;
            }
        }
        DBW.CloseCursor();
    }
    m_Edit2.GetWindowText(cText, 64);
    if( lbNeedCode && cText[0] == 0 )
    {
        AfxMessageBox("Не указан код предприятия!");
        return;
    }
    if( cText[0] != 0 )
    {
        sprintf(cQuery, "SELECT IPR, SNAME FROM nsTovPR_FOROSV WHERE (KODPR='%s') AND (IKORR IS NULL)", cText);
        DBW.ExecSQL(cQuery);
        if( DBW.Fetch() != SQL_NO_DATA )
        {
            DBW.GetData( 1, SQL_C_ULONG, &dwNum, 5, &Ind);
            DBW.GetData( 2, SQL_C_CHAR, cText, 20, &Ind);
            if( dwNum != dwID )
            {
                char msg[128] = "";
                sprintf(msg, "Указаный код не может быть использован, т.к. уже относится к %s!", cText);
                AfxMessageBox(msg);
                DBW.CloseCursor();
                return;
            }
        }
        DBW.CloseCursor();
    }
    m_Edit4.GetWindowText(cText, 64);
    if( cText[0] == 0 )
    {
        AfxMessageBox("Не указано сокращенное наименование предприятия!");
        return;
    }
    if( strlen(cText) > 16 )
    {
        AfxMessageBox("Сокращенное наименование должно содержать не более 16-ти символов!");
        return;
    }
    sprintf(cQuery, "SELECT IPR, SNAME FROM nsTovPR_FOROSV WHERE (UPPER(SNAME)=UPPER('%s')) AND (IKORR IS NULL)", cText);
    DBW.ExecSQL(cQuery);
    if( DBW.Fetch() != SQL_NO_DATA )
    {
        DBW.GetData( 1, SQL_C_ULONG, &dwNum, 5, &Ind);
        if( dwNum != dwID )
        {
            char msg[128] = "";
            sprintf(msg, "Указанное сокращенное наименование предприятия уже задействовано!");
            AfxMessageBox(msg);
            DBW.CloseCursor();
            return;
        }
    }
    DBW.CloseCursor();

//полн. наименование
    m_Edit3.GetWindowText(cText, 64);
    if( cText[0] == 0 )
    {
        AfxMessageBox("Не указано полное наименование предприятия!");
        return;
    }
    if( strlen(cText) > 50 )
    {
        AfxMessageBox("Наименование предприятия должно содержать не более 50-ти символов!");
        return;
    }
    sprintf(cQuery, "SELECT IPR, NAME FROM nsTovPR_FOROSV WHERE (UPPER(NAME)=UPPER('%s')) AND (IKORR IS NULL)", cText);
    DBW.ExecSQL(cQuery);
    if( DBW.Fetch() != SQL_NO_DATA )
    {
        DBW.GetData( 1, SQL_C_ULONG, &dwNum, 5, &Ind);
        if( dwNum != dwID )
        {
            char msg[128] = "";
            sprintf(msg, "Указанное наименование предприятия уже задействовано!");
            AfxMessageBox(msg);
            DBW.CloseCursor();
            return;
        }
    }
    DBW.CloseCursor();

//Код дороги

    m_Edit5.GetWindowText(cText, 64);
    if( lbNeedDoroga && cText[0] == 0 )
    {
        ::MessageBox(NULL, "Не указан код дороги.\nДля уточнения данных воспользуйтесь кнопкой \"Выбрать...\"","Внимание", MB_OK | MB_ICONINFORMATION);
        return; 
    }
    if( cText[0] != 0 )
    {
        sprintf(cQuery, "pTov_GetRoadByCode '%s'", cText);
        DBW.ExecSQL(cQuery);
        if( (g_sqlret = DBW.Fetch()) == SQL_NO_DATA ||
            g_sqlret == SQL_ERROR )
        {
            AfxMessageBox("Указан не верный код дороги.\nДля уточнения данных воспользуйтесь кнопкой \"Выбрать...\"");
            DBW.CloseCursor();
            return;
        }
        DBW.CloseCursor();
    }
    if( lbNeedStan && !m_Edit9.GetWindowTextLength() )
    {
        ::MessageBox(NULL, "Код станции указан не верно.\nДля уточнения данных воспользуйтесь кнопкой \"Выбрать...\"","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    CDlgWithAccelerators::OnOK();
}

//Edit KOD_DOR
void CDlgAddPr::OnChangeEdit5() 
{
    char cText[32] = "";
    char cQ[64] = "";
    long Ind = 0;
    m_Edit5.GetWindowText(cText, 32);
    if( atoi(cText) == 0 ) strncpy(cText, "0", 2);
    sprintf(cQ, "pTov_GetRoadByCode '%s'", cText);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();

    m_Edit6.SetWindowText("");
    m_Edit7.SetWindowText("");
    DWORD d = 0;
    if( g_sqlret != SQL_NO_DATA )
    {
        DBW.GetData( 1, SQL_C_ULONG, &dwDor, 5, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 20, &Ind);
        if( Ind != -1 ) m_Edit6.SetWindowText(cText);
        DBW.GetData( 3, SQL_C_CHAR, cText, 20, &Ind);
        if( Ind != -1 ) m_Edit7.SetWindowText(cText);
        DBW.CloseCursor();
//        m_Edit8.ModifyStyle(ES_READONLY, 0);
        m_Edit8.EnableWindow();
        m_Edit8.SetWindowText("");
        m_Edit9.SetWindowText("");
//        m_Edit10.SetWindowText("");
        m_Edit8.ModifyStyle(ES_READONLY | WS_DISABLED, 0);
        m_Button3.EnableWindow(TRUE);
        return;
    }
    DBW.CloseCursor();
    m_Edit8.ModifyStyle(0, ES_READONLY);
    m_Edit8.SetWindowText("");
    m_Edit9.SetWindowText("");
//    m_Edit10.SetWindowText("");
    m_Edit8.ModifyStyle(0, ES_READONLY | WS_DISABLED);
    m_Button3.EnableWindow(FALSE);
}

//KODST
void CDlgAddPr::OnChangeEdit8() 
{
    char cText[32] = "";
    char cText2[32] = "";
    char cQ[64] = "";
    long Ind = 0;
    m_Edit8.GetWindowText(cText, 32);
    m_Edit5.GetWindowText(cText2, 32);
//    if( atoi(cText) == 0 ) strncpy(cText, "0", 2);
    if( cText2[0] )
        sprintf(cQ, "pTov_GetStanByCode '%s', '%s'", cText, cText2);
    else
        sprintf(cQ, "pTov_GetStanByCode '%s', NULL", cText, cText2);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();

    m_Edit9.SetWindowText("");
//    m_Edit10.SetWindowText("");

    if( g_sqlret != SQL_NO_DATA )
    {
//        DBW.GetData( 1, SQL_C_ULONG, &dwStan, 5, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 20, &Ind);
        if( Ind != -1 ) m_Edit9.SetWindowText(cText);
/*        DBW.GetData( 3, SQL_C_CHAR, cText, 20, &Ind);
        if( Ind != -1 ) m_Edit10.SetWindowText(cText);*/
        DBW.CloseCursor();
        return;
    }
    DBW.CloseCursor();
    m_Edit9.SetWindowText("");
//    m_Edit10.SetWindowText("");
}

void CDlgAddPr::OnChangeCombo1() 
{
    dwTypePr = m_Combo.GetItemData(m_Combo.GetCurSel());	
}

void CDlgAddPr::OnSelchangeCombo1() 
{
    dwTypePr = m_Combo.GetItemData(m_Combo.GetCurSel());		
}

void CDlgAddPr::OnBnClickedOk()
{
	OnOK();
}
