// DlgVvodRP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgVvodRP.h"
#include <sqlext.h>
#include "DlgSpravSmp.h"
#include "DlgSpravKdr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp   theApp;
extern BYTE gs_DateFmt;
extern CTime g_CurrentDate;

extern DWORD g_iDep;
/////////////////////////////////////////////////////////////////////////////
// CDlgVvodRP dialog


CDlgVvodRP::CDlgVvodRP(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgVvodRP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgVvodRP)
	//}}AFX_DATA_INIT
     dwIFamOsm = 0;
     dwIFamRem = 0;
     dwIFamMas = 0;
     dwIFamRol = 0;
     dwIFamSep = 0;
     dwIFamKol = 0;
     dwIFamOsv = 0;

     dwKN1 = 0;
     dwKN2 = 0;
     dwKN3 = 0;
     dwKN4 = 0;

     qwIZAP = 0;
     cVR[0] = 0;
     dwIPodsh = 0;
     dwIPR = 0;
     dwPType = 0;
     cDat[0] = 0;
}


void CDlgVvodRP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgVvodRP)
	DDX_Control(pDX, IDC_BUTTON16, m_ButtonReady);
	DDX_Control(pDX, IDOK, m_ButtonOK);
	DDX_Control(pDX, IDC_BUTTON15, m_ButtonFIO7);
	DDX_Control(pDX, IDC_BUTTON14, m_ButtonFIO6);
	DDX_Control(pDX, IDC_BUTTON13, m_ButtonFIO5);
	DDX_Control(pDX, IDC_BUTTON12, m_ButtonFIO4);
	DDX_Control(pDX, IDC_BUTTON11, m_ButtonFIO3);
	DDX_Control(pDX, IDC_BUTTON10, m_ButtonFIO2);
	DDX_Control(pDX, IDC_BUTTON1, m_ButtonFIO1);
	DDX_Control(pDX, IDC_BUTTON9, m_ButtonNK4);
	DDX_Control(pDX, IDC_BUTTON4, m_ButtonNK3);
	DDX_Control(pDX, IDC_BUTTON6, m_ButtonNK2);
	DDX_Control(pDX, IDC_BUTTON2, m_ButtonNK1);
	DDX_Control(pDX, IDC_COMBO3, m_Combo3);
	DDX_Control(pDX, IDC_EDIT77, m_EditFIO7);
	DDX_Control(pDX, IDC_EDIT76, m_EditFIO6);
	DDX_Control(pDX, IDC_EDIT75, m_EditFIO5);
	DDX_Control(pDX, IDC_EDIT13, m_EditFIO4);
	DDX_Control(pDX, IDC_EDIT11, m_EditFIO3);
	DDX_Control(pDX, IDC_EDIT9, m_EditFIO2);
	DDX_Control(pDX, IDC_EDIT3, m_EditFIO1);
	DDX_Control(pDX, IDC_EDIT74, m_EditNN4);
	DDX_Control(pDX, IDC_EDIT6, m_EditNN3);
	DDX_Control(pDX, IDC_EDIT72, m_EditNN2);
	DDX_Control(pDX, IDC_EDIT5, m_EditNN1);
	DDX_Control(pDX, IDC_EDIT73, m_EditKN4);
	DDX_Control(pDX, IDC_EDIT70, m_EditKN3);
	DDX_Control(pDX, IDC_EDIT71, m_EditKN2);
	DDX_Control(pDX, IDC_EDIT4, m_EditKN1);
	DDX_Control(pDX, IDC_DATETIMEPICKER14, m_Date3);
	DDX_Control(pDX, IDC_DATETIMEPICKER4, m_Date2);
	DDX_Control(pDX, IDC_DATETIMEPICKER3, m_Date1);
	DDX_Control(pDX, IDC_EDIT7, m_sdatCtr);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgVvodRP, CDialog)
	//{{AFX_MSG_MAP(CDlgVvodRP)
	ON_BN_CLICKED(IDC_BUTTON16, OnReady)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonNK1)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON9, OnButton9)
	ON_EN_CHANGE(IDC_EDIT4, OnChangeEditKN1)
	ON_EN_CHANGE(IDC_EDIT71, OnChangeEditKN2)
	ON_EN_CHANGE(IDC_EDIT70, OnChangeEditKN3)
	ON_EN_CHANGE(IDC_EDIT73, OnChangeEditKN4)
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonFIO1)
	ON_BN_CLICKED(IDC_BUTTON10, OnButtonFIO2)
	ON_BN_CLICKED(IDC_BUTTON11, OnButtonFIO3)
	ON_BN_CLICKED(IDC_BUTTON12, OnButtonFIO4)
	ON_BN_CLICKED(IDC_BUTTON13, OnButtonFIO5)
	ON_BN_CLICKED(IDC_BUTTON14, OnButtonFIO6)
	ON_BN_CLICKED(IDC_BUTTON15, OnButtonFIO7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgVvodRP message handlers

BOOL CDlgVvodRP::OnInitDialog() 
{
	CDialog::OnInitDialog();
	char    cQ[255] = "pTov_GetPrPodsh";    
    char    cText[64] = "";
    long    Ind = 0;
    DBW.ExecSQL(cQ);
    for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA &&
            g_sqlret != SQL_ERROR && i < 512; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwIPRPodsh[i], 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Combo1.AddString(cText);
    }
    DBW.CloseCursor();
    m_Combo1.SetCurSel(0);
    strncpy(cQ, "pTov_GetTypesRP", 32);
    DBW.ExecSQL(cQ);
    for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA &&
            g_sqlret != SQL_ERROR && i < 512; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwIPType[i], 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Combo2.AddString(cText);
    }
    DBW.CloseCursor();
    m_Combo2.SetCurSel(0);
    DisableCtrls();
	return TRUE;
}

void CDlgVvodRP::EnableCtrls()
{
    m_Date1.ModifyStyle(WS_DISABLED, 0);
    m_Date2.ModifyStyle(WS_DISABLED, 0);
    m_Date3.ModifyStyle(WS_DISABLED, 0);
    m_ButtonFIO1.ModifyStyle(WS_DISABLED, 0);
    m_ButtonFIO2.ModifyStyle(WS_DISABLED, 0);
    m_ButtonFIO3.ModifyStyle(WS_DISABLED, 0);
    m_ButtonFIO4.ModifyStyle(WS_DISABLED, 0);
    m_ButtonFIO5.ModifyStyle(WS_DISABLED, 0);
    m_ButtonFIO6.ModifyStyle(WS_DISABLED, 0);
    m_ButtonFIO7.ModifyStyle(WS_DISABLED, 0);
    m_ButtonFIO1.RedrawWindow();
    m_ButtonFIO2.RedrawWindow();
    m_ButtonFIO3.RedrawWindow();
    m_ButtonFIO4.RedrawWindow();
    m_ButtonFIO5.RedrawWindow();
    m_ButtonFIO6.RedrawWindow();
    m_ButtonFIO7.RedrawWindow();
/*    m_EditFIO1.ModifyStyle(WS_DISABLED, 0);
    m_EditFIO2.ModifyStyle(WS_DISABLED, 0);
    m_EditFIO3.ModifyStyle(WS_DISABLED, 0);
    m_EditFIO4.ModifyStyle(WS_DISABLED, 0);
    m_EditFIO5.ModifyStyle(WS_DISABLED, 0);
    m_EditFIO6.ModifyStyle(WS_DISABLED, 0);
    m_EditFIO7.ModifyStyle(WS_DISABLED, 0);*/
    m_EditKN1.ModifyStyle(WS_DISABLED, 0);
    m_EditKN2.ModifyStyle(WS_DISABLED, 0);
    m_EditKN3.ModifyStyle(WS_DISABLED, 0);
    m_EditKN4.ModifyStyle(WS_DISABLED, 0);
/*    m_EditNN1.ModifyStyle(WS_DISABLED, 0);
    m_EditNN2.ModifyStyle(WS_DISABLED, 0);
    m_EditNN3.ModifyStyle(WS_DISABLED, 0);
    m_EditNN4.ModifyStyle(WS_DISABLED, 0);*/
    m_ButtonNK1.ModifyStyle(WS_DISABLED, 0);
    m_ButtonNK2.ModifyStyle(WS_DISABLED, 0);
    m_ButtonNK3.ModifyStyle(WS_DISABLED, 0);
    m_ButtonNK4.ModifyStyle(WS_DISABLED, 0);
    m_ButtonNK1.RedrawWindow();
    m_ButtonNK2.RedrawWindow();
    m_ButtonNK3.RedrawWindow();
    m_ButtonNK4.RedrawWindow();
    m_Combo3.ModifyStyle(WS_DISABLED, 0);
    m_ButtonOK.ModifyStyle(WS_DISABLED, 0);
    m_ButtonOK.RedrawWindow();
}

void CDlgVvodRP::DisableCtrls()
{
    m_Date1.ModifyStyle(0, WS_DISABLED);
    m_Date2.ModifyStyle(0, WS_DISABLED);
    m_Date3.ModifyStyle(0, WS_DISABLED);
    m_ButtonFIO1.ModifyStyle(0, WS_DISABLED);
    m_ButtonFIO2.ModifyStyle(0, WS_DISABLED);
    m_ButtonFIO3.ModifyStyle(0, WS_DISABLED);
    m_ButtonFIO4.ModifyStyle(0, WS_DISABLED);
    m_ButtonFIO5.ModifyStyle(0, WS_DISABLED);
    m_ButtonFIO6.ModifyStyle(0, WS_DISABLED);
    m_ButtonFIO7.ModifyStyle(0, WS_DISABLED);
    m_ButtonFIO1.RedrawWindow();
    m_ButtonFIO2.RedrawWindow();
    m_ButtonFIO3.RedrawWindow();
    m_ButtonFIO4.RedrawWindow();
    m_ButtonFIO5.RedrawWindow();
    m_ButtonFIO6.RedrawWindow();
    m_ButtonFIO7.RedrawWindow();
    m_EditFIO1.ModifyStyle(0, WS_DISABLED);
    m_EditFIO2.ModifyStyle(0, WS_DISABLED);
    m_EditFIO3.ModifyStyle(0, WS_DISABLED);
    m_EditFIO4.ModifyStyle(0, WS_DISABLED);
    m_EditFIO5.ModifyStyle(0, WS_DISABLED);
    m_EditFIO6.ModifyStyle(0, WS_DISABLED);
    m_EditFIO7.ModifyStyle(0, WS_DISABLED);
    m_EditKN1.ModifyStyle(0, WS_DISABLED);
    m_EditKN2.ModifyStyle(0, WS_DISABLED);
    m_EditKN3.ModifyStyle(0, WS_DISABLED);
    m_EditKN4.ModifyStyle(0, WS_DISABLED);
    m_EditNN1.ModifyStyle(0, WS_DISABLED);
    m_EditNN2.ModifyStyle(0, WS_DISABLED);
    m_EditNN3.ModifyStyle(0, WS_DISABLED);
    m_EditNN4.ModifyStyle(0, WS_DISABLED);
    m_ButtonNK1.ModifyStyle(0, WS_DISABLED);
    m_ButtonNK2.ModifyStyle(0, WS_DISABLED);
    m_ButtonNK3.ModifyStyle(0, WS_DISABLED);
    m_ButtonNK4.ModifyStyle(0, WS_DISABLED);
    m_ButtonNK1.RedrawWindow();
    m_ButtonNK2.RedrawWindow();
    m_ButtonNK3.RedrawWindow();
    m_ButtonNK4.RedrawWindow();
    m_Combo3.ModifyStyle(0, WS_DISABLED);
    m_ButtonOK.ModifyStyle(0, WS_DISABLED);
    m_ButtonOK.RedrawWindow();
}

void CDlgVvodRP::OnReady() 
{
    Init = TRUE;
    char    cText[64] = "";
    char    cQ[512] = "";
    DWORD   dwNum = 0;
    m_Edit1.GetWindowText(cText, 64);
    if( cText[0] == 0 )
    {
        AfxMessageBox("Не указан номер подшипника.");
        return;
    }
    if( atoi(cText) == 0 )
    {
        AfxMessageBox("Некорректно указан номер подшипника.");
        return;
    }
    char sdat[16] = "";
    m_sdatCtr.GetWindowText(sdat, 5);
    int idx1 = m_Combo1.GetCurSel();
    int idx2 = m_Combo2.GetCurSel();
    if( idx1 == -1 )
    {
        AfxMessageBox("Не указано предприятие изготовления подшипника.");
        return;
    }
    if( idx2 == -1 )
    {
        AfxMessageBox("Некорректно указан тип подшипника!");
        return;
    }
    sprintf(cQ, "pTov_GetIPodsh %u, %u, '%s', '%s'",
            dwIPType[idx2],
            dwIPRPodsh[idx1],
            cText,
            sdat);
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch()) == SQL_ERROR )
    {
        AfxMessageBox("Ошибка SQL!");
        return;
    }
    if( g_sqlret != SQL_NO_DATA )
    {
        long    Ind = 0;
        DBW.GetData( 1, SQL_C_SLONG, &dwIPodsh, 4, &Ind);
        DBW.CloseCursor();
        sprintf(cQ, "pTov_GetPodshByID %u, %u", dwIPodsh, g_iDep);
        DBW.ExecSQL(cQ);
        g_sqlret = DBW.Fetch();
        if( g_sqlret != SQL_NO_DATA && g_sqlret != SQL_ERROR )
        {            
            SQL_DATE_STRUCT     sql_date;
            SYSTEMTIME          st;
            char                cText[64] = "";
            DWORD               dwNum = 0;

            DBW.GetData( 1, SQL_C_SBIGINT, &qwIZAP, 8, &Ind);
            memset(&st, 0, sizeof(st));
            DBW.GetData( 2, SQL_C_TYPE_DATE, &sql_date, 4, &Ind);
            if( Ind != -1 )
            {
                st.wDay = sql_date.day;
                st.wMonth = sql_date.month;
                st.wYear = sql_date.year;
                m_Date1.SetTime(&st);
            }
            memset(&st, 0, sizeof(st));
            DBW.GetData( 3, SQL_C_TYPE_DATE, &sql_date, 4, &Ind);
            if( Ind != -1 )
            {
                st.wDay = sql_date.day;
                st.wMonth = sql_date.month;
                st.wYear = sql_date.year;
                m_Date2.SetTime(&st);
            }
            memset(&st, 0, sizeof(st));
            DBW.GetData( 4, SQL_C_TYPE_DATE, &sql_date, 4, &Ind);
            if( Ind != -1 )
            {
                st.wDay = sql_date.day;
                st.wMonth = sql_date.month;
                st.wYear = sql_date.year;
                m_Date3.SetTime(&st);
            }

            DBW.GetData( 5, SQL_C_SLONG, &dwKN1, 4, &Ind);
            if( Ind != -1 )
            {
                itoa(dwKN1, cText, 10);
                m_EditKN1.SetWindowText(cText);
                DBW.GetData( 6, SQL_C_CHAR, &cText, 64, &Ind);
                if( Ind != -1 )m_EditNN1.SetWindowText(cText);
            }

            DBW.GetData( 7, SQL_C_SLONG, &dwKN2, 4, &Ind);
            if( Ind != -1 )
            {
                itoa(dwKN2, cText, 10);
                m_EditKN2.SetWindowText(cText);
                DBW.GetData( 8, SQL_C_CHAR, &cText, 64, &Ind);
                if( Ind != -1 )m_EditNN2.SetWindowText(cText);
            }

            DBW.GetData( 9, SQL_C_SLONG, &dwKN3, 4, &Ind);
            if( Ind != -1 )
            {
                itoa(dwKN3, cText, 10);
                m_EditKN3.SetWindowText(cText);
                DBW.GetData( 10, SQL_C_CHAR, &cText, 64, &Ind);
                if( Ind != -1 ) m_EditNN3.SetWindowText(cText);
            }

            DBW.GetData( 11, SQL_C_SLONG, &dwKN4, 4, &Ind);
            if( Ind != -1 )
            {
                itoa(dwKN4, cText, 10);
                m_EditKN4.SetWindowText(cText);
                DBW.GetData( 12, SQL_C_CHAR, &cText, 64, &Ind);
                if( Ind != -1 ) m_EditNN4.SetWindowText(cText);
            }
            
            DBW.GetData( 13, SQL_C_CHAR, &cText, 64, &Ind);
            if( Ind != -1 ) m_EditFIO1.SetWindowText(cText);
            DBW.GetData( 14, SQL_C_CHAR, &cText, 64, &Ind);
            if( Ind != -1 ) m_EditFIO2.SetWindowText(cText);
            DBW.GetData( 15, SQL_C_CHAR, &cText, 64, &Ind);
            if( Ind != -1 ) m_EditFIO3.SetWindowText(cText);
            DBW.GetData( 16, SQL_C_CHAR, &cText, 64, &Ind);
            if( Ind != -1 ) m_EditFIO4.SetWindowText(cText);
            DBW.GetData( 17, SQL_C_CHAR, &cText, 64, &Ind);
            if( Ind != -1 ) m_EditFIO5.SetWindowText(cText);
            DBW.GetData( 18, SQL_C_CHAR, &cText, 64, &Ind);
            if( Ind != -1 ) m_EditFIO6.SetWindowText(cText);
            DBW.GetData( 19, SQL_C_CHAR, &cText, 64, &Ind);
            if( Ind != -1 ) m_EditFIO7.SetWindowText(cText);
            DBW.GetData( 20, SQL_C_SLONG, &dwNum, 4, &Ind);
            if( Ind != -1 ) m_Combo3.SetCurSel(dwNum);

            DBW.GetData( 21, SQL_C_SLONG, &dwIFamOsm, 4, &Ind);
            DBW.GetData( 22, SQL_C_SLONG, &dwIFamRem, 4, &Ind);
            DBW.GetData( 23, SQL_C_SLONG, &dwIFamMas, 4, &Ind);
            DBW.GetData( 24, SQL_C_SLONG, &dwIFamRol, 4, &Ind);
            DBW.GetData( 25, SQL_C_SLONG, &dwIFamSep, 4, &Ind);
            DBW.GetData( 26, SQL_C_SLONG, &dwIFamKol, 4, &Ind);
            DBW.GetData( 27, SQL_C_SLONG, &dwIFamOsv, 4, &Ind);
        }
    }
    DBW.CloseCursor();
    EnableCtrls();
    dwIPR = dwIPRPodsh[idx1];
    dwPType = dwIPType[idx2];
    m_Edit1.GetWindowText(cPNum, 32);
    m_sdatCtr.GetWindowText(cDat, 32);

    m_Combo1.ModifyStyle(0, WS_DISABLED);
    m_Combo2.ModifyStyle(0, WS_DISABLED);
    m_Edit1.ModifyStyle(0, WS_DISABLED);
    m_sdatCtr.ModifyStyle(0, WS_DISABLED);
    m_ButtonReady.ModifyStyle(0, WS_DISABLED);
    m_ButtonReady.RedrawWindow();
    Init = FALSE;
}

void CDlgVvodRP::OnButtonNK1() 
{
    ButtonKN(1);
}

void CDlgVvodRP::OnButton6() 
{
    ButtonKN(2);
}

void CDlgVvodRP::OnButton4() 
{
    ButtonKN(3);
}

void CDlgVvodRP::OnButton9() 
{
    ButtonKN(4);
}

void CDlgVvodRP::OnChangeEditKN1() 
{
    EditKNChng(1);
}

void CDlgVvodRP::OnChangeEditKN2() 
{
    EditKNChng(2);
}

void CDlgVvodRP::OnChangeEditKN3() 
{
    EditKNChng(3);
}

void CDlgVvodRP::OnChangeEditKN4() 
{
    EditKNChng(4);
}

void CDlgVvodRP::ButtonKN(int Num)
{
    CDlgSpravSmp Dlg;
    Dlg.Style = 1;
    Dlg.DlgMode = 114;
    if( Dlg.DoModal() == IDCANCEL ) return;
    switch (Num)
    {
    case 1: m_EditKN1.SetWindowText(Dlg.cRet); dwKN1 = Dlg.dwRet; break;
    case 2: m_EditKN2.SetWindowText(Dlg.cRet); dwKN2 = Dlg.dwRet; break;
    case 3: m_EditKN3.SetWindowText(Dlg.cRet); dwKN3 = Dlg.dwRet; break;
    case 4: m_EditKN4.SetWindowText(Dlg.cRet); dwKN4 = Dlg.dwRet; break;
    }
}

void CDlgVvodRP::EditKNChng(int Num)
{
    if( Init ) return;
    char cQ[64] = "";
    long Ind = 0;
    char cText[64] = "";
    switch (Num)
    {
    case 1: m_EditNN1.SetWindowText("");
            m_EditKN1.GetWindowText(cText, 64);
            break;
    case 2: m_EditNN2.SetWindowText("");
            m_EditKN2.GetWindowText(cText, 64);
            break;
    case 3: m_EditNN3.SetWindowText("");
            m_EditKN3.GetWindowText(cText, 64);
            break;
    case 4: m_EditNN4.SetWindowText("");
            m_EditKN4.GetWindowText(cText, 64);
            break;
    }
    if( atoi(cText) == 0 ) return;
    sprintf(cQ, "pTov_GetTypeRemPodsh %s", cText);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    if( g_sqlret == SQL_NO_DATA ||
        g_sqlret == SQL_ERROR ) 
    {
        DBW.CloseCursor();
        return;
    }
    DBW.GetData( 1, SQL_C_CHAR, &cText, 64, &Ind);
    if( Ind != -1 )
    {
        switch (Num)
        {
        case 1: m_EditNN1.SetWindowText(cText); break;
        case 2: m_EditNN2.SetWindowText(cText); break;
        case 3: m_EditNN3.SetWindowText(cText); break;
        case 4: m_EditNN4.SetWindowText(cText); break;
        }
    }
    DBW.CloseCursor();
}
void CDlgVvodRP::GetKadr(int Num)
{
    CDlgSpravKdr Dlg;
    Dlg.DlgMode = 1;
    switch( Num )
    {
    case 1: 
    case 7: Dlg.iFilter = 13; break;
    case 2: Dlg.iFilter = 14; break;
    case 3: Dlg.iFilter = 15; break;
    case 4: Dlg.iFilter = 29; break;
    case 5: Dlg.iFilter = 30; break;
    case 6: Dlg.iFilter = 31; break;
    }
    if( Dlg.DoModal() == IDCANCEL ) return;
    switch( Num )
    {
    case 1: m_EditFIO1.SetWindowText(Dlg.cFio); dwIFamOsm = Dlg.dwFio; break;
    case 2: m_EditFIO2.SetWindowText(Dlg.cFio); dwIFamRem = Dlg.dwFio; break;
    case 3: m_EditFIO3.SetWindowText(Dlg.cFio); dwIFamMas = Dlg.dwFio; break;
    case 4: m_EditFIO4.SetWindowText(Dlg.cFio); dwIFamRol = Dlg.dwFio; break;
    case 5: m_EditFIO5.SetWindowText(Dlg.cFio); dwIFamSep = Dlg.dwFio; break;
    case 6: m_EditFIO6.SetWindowText(Dlg.cFio); dwIFamKol = Dlg.dwFio; break;
    case 7: m_EditFIO7.SetWindowText(Dlg.cFio); dwIFamOsv = Dlg.dwFio; break;
    }
    
}

void CDlgVvodRP::OnButtonFIO1() 
{
    GetKadr(1);
}

void CDlgVvodRP::OnButtonFIO2() 
{
    GetKadr(2);
}

void CDlgVvodRP::OnButtonFIO3() 
{
    GetKadr(3);
}

void CDlgVvodRP::OnButtonFIO4() 
{
    GetKadr(4);
}

void CDlgVvodRP::OnButtonFIO5() 
{
    GetKadr(5);
}

void CDlgVvodRP::OnButtonFIO6() 
{
    GetKadr(6);
}

void CDlgVvodRP::OnButtonFIO7() 
{
    GetKadr(7);
}

void CDlgVvodRP::OnOK() 
{
    CTime ct, ct1;
//    memset(&st, 0, sizeof(st));
    char cDate[12]="";
    char cText[64]="";
    char cText1[64]="", cText2[64]="";
    m_Date1.GetTime(ct);
    time_t tTime;
    time(&tTime);
    CTime l_CurrentDate = tTime;
    if( ct > l_CurrentDate )
    {
        AfxMessageBox("Указанная дата осмотра еще не наступила!");
        return;
    }
    m_Date2.GetTime(ct1);
    if( ct1 > l_CurrentDate )
    {
        AfxMessageBox("Указанная дата ремонта еще не наступила!");
        return;
    }
    if( ct1 < ct )
    {
        AfxMessageBox("Дата ремонта не может быть раньше даты осмотра!");
        return;
    }
    if( dwIFamOsm == 0 && dwIFamRem == 0 )
    {
        AfxMessageBox("Следует указать Ф.И.О. производившего осмотр или ремонт подшипника.");
        return;
    }
    
    if( dwIFamRem == 0 ) // нет ремонта
    {
        if( dwIFamMas != 0 || 
            dwIFamRol != 0 || 
            dwIFamSep != 0 || 
            dwIFamKol != 0 ||
            m_Combo3.GetCurSel() > -1)
        {
            AfxMessageBox("Не указана фамилия производившего ремонт!");
            return;
        }
        strncpy(cVR, "NULL", 5);
    }
    else
    {
        if(m_Combo3.GetCurSel() == -1)
        {
            AfxMessageBox("Не указан вид ремонта!");
            return;
        }
        sprintf(cVR, "%u", m_Combo3.GetCurSel());
    }
/*    if( dwIFamOsv != 0 ) // есть повторный осмотр
    {
        
    }
*/

// Код неисправности
    if( dwKN1 == 0 && dwKN2 == 0 && dwKN3 == 0 && dwKN4 == 0 )
    {
        AfxMessageBox("Не указан код неисправности!");
        return;
    }
    char cQ[512] = "";
    char cD1[16]="", cD2[16]="", cD3[16]="";
    SYSTEMTIME st1, st2, st3;
    memset(&st1, 0, sizeof(st1));
    memset(&st2, 0, sizeof(st1));
    memset(&st3, 0, sizeof(st1));
    m_Date1.GetTime(&st1);
    m_Date2.GetTime(&st2);
    m_Date3.GetTime(&st3);
    if( gs_DateFmt == 1 )
    {
        sprintf( cD1, "'%.2d-%.2d-%.4d'", st1.wMonth, st1.wDay, st1.wYear );
        if( dwIFamRem ) sprintf( cD2, "'%.2d-%.2d-%.4d'", st2.wMonth, st2.wDay, st2.wYear );
        else strncpy(cD2, "NULL", 5);
        if( dwIFamOsv ) sprintf( cD3, "'%.2d-%.2d-%.4d'", st3.wMonth, st3.wDay, st3.wYear );
        else strncpy(cD3, "NULL", 5);
    } else
    if( gs_DateFmt == 0 )
    {
        sprintf( cD1, "'%.2d-%.2d-%.4d'", st1.wDay, st1.wMonth, st1.wYear );
        if( dwIFamRem ) sprintf( cD2, "'%.2d-%.2d-%.4d'", st2.wDay, st2.wMonth, st2.wYear );
        else strncpy(cD2, "NULL", 5);
        if( dwIFamOsv ) sprintf( cD3, "'%.2d-%.2d-%.4d'", st3.wDay, st3.wMonth, st3.wYear );
        else strncpy(cD3, "NULL", 5);
    }
    if( qwIZAP == 0 )
    {
        sprintf(cQ, "pTov_InsertPodsh %u, %s, %u, %s, %u, %u, %u, %u, %u, %s, %s, %u, %u, %u, %u, %u, %u, %u, '%s', '%s'", 
            g_iDep,
            cD1,
            dwIFamOsm,
            cD3,
            dwIFamOsv,
            dwKN1,
            dwKN2,
            dwKN3,
            dwKN4,
            cVR,
            cD2,
            dwIFamRem,
            dwIFamMas,
            dwIFamRol,
            dwIFamSep,
            dwIFamKol,
            dwPType,
            dwIPR,
            cPNum,
            cDat
            );
        DBW.ExecSQL(cQ);
        DBW.CloseCursor();
        DBW.ReallocHandle();
    }
    else
    {
        sprintf(cQ, "pTov_UpdatePodsh %u, %u, %s, %u, %s, %u, %u, %u, %u, %u, %s, %s, %u, %u, %u, %u, %u, %I64u", 
            g_iDep,
            dwIPodsh,
            cD1,
            dwIFamOsm,
            cD3,
            dwIFamOsv,
            dwKN1,
            dwKN2,
            dwKN3,
            dwKN4,
            cVR,
            cD2,
            dwIFamRem,
            dwIFamMas,
            dwIFamRol,
            dwIFamSep,
            dwIFamKol,
            qwIZAP);
        DBW.ExecSQL(cQ);        
        DBW.CloseCursor();
        DBW.ReallocHandle();

        // Insert some SQL CALLS here too...
    }
	CDialog::OnOK();
}
