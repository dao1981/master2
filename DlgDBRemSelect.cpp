// DlgDBRemSelect.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgDBRemSelect.h"
#include "DlgSpravSmp.h"
#include "DlgBDSelectRez.h"
#include "DlgSprav1.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDBRemSelect dialog

extern CMasterApp theApp;
CDlgDBRemSelect::CDlgDBRemSelect(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgDBRemSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDBRemSelect)
	//}}AFX_DATA_INIT
    dwPRPost_ID = 0;
    dwPRRash_ID = 0;
    dwNeisp = 0;
}


void CDlgDBRemSelect::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDBRemSelect)
	DDX_Control(pDX, IDC_COMBO19, m_Combo7);
	DDX_Control(pDX, IDC_COMBO7, m_Combo6);
	DDX_Control(pDX, IDC_CHECK10, m_Check15);
	DDX_Control(pDX, IDC_CHECK9, m_Check14);
	DDX_Control(pDX, IDC_BUTTON8, m_ButPr2);
	DDX_Control(pDX, IDC_CHECK8, m_Check13);
	DDX_Control(pDX, IDC_EDIT11, m_EdPrName2);
	DDX_Control(pDX, IDC_EDIT78, m_EdPrKl2);
	DDX_Control(pDX, IDC_BUTTON2, m_ButPr);
	DDX_Control(pDX, IDC_CHECK7, m_Check12);
	DDX_Control(pDX, IDC_EDIT10, m_EdPrName);
	DDX_Control(pDX, IDC_EDIT8, m_EdPrKl);
	DDX_Control(pDX, IDC_EDIT93, m_Dt6);
	DDX_Control(pDX, IDC_EDIT4, m_Dt5);
	DDX_Control(pDX, IDC_EDIT117, m_Dt4);
	DDX_Control(pDX, IDC_EDIT5, m_Dt3);
	DDX_Control(pDX, IDC_EDIT7, m_Dt2);
	DDX_Control(pDX, IDC_EDIT1, m_Dt1);
	DDX_Control(pDX, IDC_EDIT71, m_Edit4);
	DDX_Control(pDX, IDC_EDIT70, m_Edit3);
	DDX_Control(pDX, IDC_CHECK2, m_Check4);
	DDX_Control(pDX, IDC_BUTTON4, m_Button1);
	DDX_Control(pDX, IDC_COMBO10, m_Combo5);
	DDX_Control(pDX, IDC_COMBO8, m_Combo4);
	DDX_Control(pDX, IDC_COMBO6, m_Combo3);
	DDX_Control(pDX, IDC_COMBO3, m_Combo2);
	DDX_Control(pDX, IDC_EDIT3, m_Edit2);
	DDX_Control(pDX, IDC_EDIT2, m_Edit1);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_CHECK13, m_Check11);
	DDX_Control(pDX, IDC_CHECK12, m_Check10);
	DDX_Control(pDX, IDC_CHECK11, m_Check9);
	DDX_Control(pDX, IDC_CHECK4, m_Check8);
	DDX_Control(pDX, IDC_CHECK3, m_Check7);
	DDX_Control(pDX, IDC_CHECK6, m_Check6);
	DDX_Control(pDX, IDC_CHECK5, m_Check5);
	DDX_Control(pDX, IDC_CHECK38, m_Check3);
	DDX_Control(pDX, IDC_CHECK31, m_Check2);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDBRemSelect, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgDBRemSelect)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK31, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK38, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck6)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck7)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck8)
	ON_BN_CLICKED(IDC_CHECK11, OnCheck9)
	ON_BN_CLICKED(IDC_CHECK12, OnCheck10)
	ON_BN_CLICKED(IDC_CHECK13, OnCheck11)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonPr)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck12)
	ON_EN_KILLFOCUS(IDC_EDIT8, OnKillfocusEditKlPr)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_EN_KILLFOCUS(IDC_EDIT78, OnKillfocusEditPr2)
	ON_BN_CLICKED(IDC_CHECK8, OnCheck13)
	ON_BN_CLICKED(IDC_CHECK9, OnCheck14)
	ON_BN_CLICKED(IDC_CHECK10, OnCheck15)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CDlgDBRemSelect::EnableCtrls(BOOL State)
{
    m_Dt1.EnableWindow(State);
    m_Dt2.EnableWindow(State);
    m_Dt3.EnableWindow(State);
    m_Dt4.EnableWindow(State);
    m_Dt5.EnableWindow(State);
    m_Dt6.EnableWindow(State);
    m_Combo1.EnableWindow(State);
    m_Combo2.EnableWindow(State);
    m_Edit1.EnableWindow(State);
    m_Edit2.EnableWindow(State);
    m_Edit3.EnableWindow(State);
    m_Edit4.EnableWindow(State);
    m_Edit3.ModifyStyle(0, WS_DISABLED);
    m_Edit4.ModifyStyle(0, WS_DISABLED);
    
    m_Button1.EnableWindow(FALSE);
    m_Combo3.EnableWindow(FALSE);
    m_Combo4.EnableWindow(FALSE);
    m_Combo5.EnableWindow(FALSE);
    m_EdPrKl.EnableWindow(State);
    m_EdPrName.EnableWindow(State);
    m_EdPrName.ModifyStyle(0, WS_DISABLED);
    m_ButPr.EnableWindow(State);
    m_EdPrKl2.EnableWindow(State);
    m_EdPrName2.EnableWindow(State);
    m_EdPrName2.ModifyStyle(0, WS_DISABLED);
    m_ButPr2.EnableWindow(State);
    m_Combo6.EnableWindow(State);
    m_Combo7.EnableWindow(State);

//    m_Edit8.EnableWindow(State);
    
}
/////////////////////////////////////////////////////////////////////////////
// CDlgDBRemSelect message handlers


BOOL CDlgDBRemSelect::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
    char cText[64] = "";
    long Ind = 0;
    DWORD dwNum = 0;
    DBW.ExecSQL("pTov_GetTKP");
    for(WORD i=0; (g_sqlret = DBW.Fetch())!= SQL_NO_DATA &&
          g_sqlret != SQL_ERROR; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwTKP[i], 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Combo1.AddString(cText);
        m_Combo1.SetItemData(i, dwTKP[i]);
    }
    DBW.CloseCursor();

    DBW.ExecSQL("pTov_GetRemKP");
    for(WORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 255; i++)
    {
        DBW.GetData( 1, SQL_C_ULONG, &dwNum, 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        if( Ind != -1 ) 
        {
            m_Combo3.AddString(cText);
            m_Combo3.SetItemData(i, dwNum);
            dwRemKP[i] = dwNum;
        }
    }
    DBW.CloseCursor();
    EnableCtrls(FALSE);
    m_Dt1.InitDate();
    m_Dt2.InitDate();
    m_Dt3.InitDate();
    m_Dt4.InitDate();
    m_Dt5.InitDate();
    m_Dt6.InitDate();

    m_Combo4.SetItemData(0, 1);
    m_Combo4.SetItemData(1, 0);
    m_Combo2.SetItemData(0, 1);
    m_Combo2.SetItemData(1, 0);
    m_Combo6.SetItemData(0, 1);
    m_Combo6.SetItemData(1, 0);
    
    m_Combo2.SetCurSel(0);
    m_Combo3.SetCurSel(0);
    m_Combo4.SetCurSel(0);    
    m_Combo6.SetCurSel(0);   
    DBW.FillComboWithOsRezRepairs(&m_Combo5);
    DBW.FillComboWithSmazkaType(&m_Combo7);
    m_Combo5.SetCurSel(1);
    m_Combo7.SetCurSel(0);

    SetWindowText((CString)"Выборка из базы данных ремонта КП " + g_strDepoName);
	return TRUE;  
}


void CDlgDBRemSelect::OnButton4() 
{
	CDlgSpravSmp Dlg;
    Dlg.DlgMode = 111;
    Dlg.Style = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwNeisp = Dlg.dwRet;
    m_Edit3.SetWindowText(Dlg.cRet);
    m_Edit4.SetWindowText(Dlg.c_retText3);	
}

void CDlgDBRemSelect::OnCheck1() 
{
    if( m_Check1.GetCheck() ) 
    {
        m_Dt1.EnableWindow(TRUE);
        m_Dt2.EnableWindow(TRUE);
        m_Dt1.SetFocus();
    }
    else 
    {
        m_Dt1.EnableWindow(FALSE);
        m_Dt2.EnableWindow(FALSE);
    }	
}

void CDlgDBRemSelect::OnCheck2() 
{
    if( m_Check2.GetCheck() ) 
    {
        m_Dt3.EnableWindow(TRUE);
        m_Dt4.EnableWindow(TRUE);
        m_Dt3.SetFocus();
    }
    else 
    {
        m_Dt3.EnableWindow(FALSE);
        m_Dt4.EnableWindow(FALSE);
    }	
}

void CDlgDBRemSelect::OnCheck3() 
{
    if( m_Check3.GetCheck() ) 
    {
        m_Dt5.EnableWindow(TRUE);
        m_Dt6.EnableWindow(TRUE);
        m_Dt5.SetFocus();
    }
    else 
    {
        m_Dt5.EnableWindow(FALSE);
        m_Dt6.EnableWindow(FALSE);
    }	
}

void CDlgDBRemSelect::OnCheck4() 
{
    if( m_Check4.GetCheck() ) 
    {
        m_Combo1.EnableWindow(TRUE);
        m_Combo1.SetFocus();
    }
    else 
        m_Combo1.EnableWindow(FALSE);
}

void CDlgDBRemSelect::OnCheck5() 
{
    if( m_Check5.GetCheck() ) 
    {
        m_Edit1.EnableWindow(TRUE);
        m_Edit1.SetFocus();
        m_Check12.SetCheck(0);
        OnCheck12();
    }
    else 
        m_Edit1.EnableWindow(FALSE);

}

void CDlgDBRemSelect::OnCheck6() 
{
    if( m_Check6.GetCheck() )
    {
        m_Edit2.EnableWindow(TRUE);
        m_Edit2.SetFocus();
        m_Check13.SetCheck(0);
        OnCheck13();
    }
    else 
        m_Edit2.EnableWindow(FALSE);	
}

void CDlgDBRemSelect::OnCheck7() 
{
    if( m_Check7.GetCheck() )
    {
        m_Combo2.EnableWindow(TRUE);
        m_Combo2.SetFocus();
    }
    else 
        m_Combo2.EnableWindow(FALSE);	
}

void CDlgDBRemSelect::OnCheck8() 
{
    if( m_Check8.GetCheck() ) 
    {
        m_Combo3.EnableWindow(TRUE);
        m_Combo3.SetFocus();
    }
    else 
        m_Combo3.EnableWindow(FALSE);
}

void CDlgDBRemSelect::OnCheck9() 
{
    if( m_Check9.GetCheck() ) 
    {
        m_Button1.EnableWindow(TRUE);
        m_Edit3.EnableWindow();
        m_Edit4.EnableWindow();
        m_Edit3.ModifyStyle(0, WS_DISABLED);
        m_Edit4.ModifyStyle(0, WS_DISABLED);
        m_Button1.SetFocus();
    }
    else 
    {
        m_Edit3.ModifyStyle(WS_DISABLED, 0);
        m_Edit4.ModifyStyle(WS_DISABLED, 0);
        m_Edit3.EnableWindow(FALSE);
        m_Edit4.EnableWindow(FALSE);
        m_Button1.EnableWindow(FALSE);
        m_Edit3.SetWindowText("");
        m_Edit4.SetWindowText("");
        dwNeisp = 0;
    }	
}

void CDlgDBRemSelect::OnCheck10() 
{
	if( m_Check10.GetCheck() )
    {
        m_Combo4.EnableWindow(TRUE);
        m_Combo4.SetFocus();
    }
    else 
        m_Combo4.EnableWindow(FALSE);
}

void CDlgDBRemSelect::OnCheck11() 
{
    if( m_Check11.GetCheck() ) 
    {
        m_Combo5.EnableWindow(TRUE);
        m_Combo5.SetFocus();
    }
    else 
        m_Combo5.EnableWindow(FALSE);		
}

void CDlgDBRemSelect::OnOK() 
{
    char cFilter[1024] = "";
    char cQ[1024] = "";
    SYSTEMTIME st1, st2;
    char cText[64] = "";
    ZeroMemory(&st1, sizeof(st1));
    ZeroMemory(&st2, sizeof(st2));
    // Проверка условия по приходу
    sprintf(cFilter, "WHERE tovPRIHOD_KP.IDEP=%u ", g_iDep);
	if( m_Check1.GetCheck() )
    {
        m_Dt1.GetTime(&st1);
        m_Dt2.GetTime(&st2);
        sprintf(cFilter, "%s AND tovPRIHOD_KP.DAT_POST >= ''%.4d%.2d%.2d'' AND tovPRIHOD_KP.DAT_POST <=''%.4d%.2d%.2d'' ",
                cFilter, st1.wYear, st1.wMonth, st1.wDay, st2.wYear, st2.wMonth, st2.wDay);
    }
    // Проверка условия по ремонту
    if( m_Check2.GetCheck() )
    {
        m_Dt3.GetTime(&st1);
        m_Dt4.GetTime(&st2);
        sprintf(cFilter, "%sAND tovREM_KP.DAT_REM >= ''%.4d%.2d%.2d'' AND tovREM_KP.DAT_REM <=''%.4d%.2d%.2d'' ",
                cFilter, st1.wYear, st1.wMonth, st1.wDay, st2.wYear, st2.wMonth, st2.wDay);
    }
    // Проверка условия по расходу
    if( m_Check3.GetCheck() )
    {
        m_Dt5.GetTime(&st1);
        m_Dt6.GetTime(&st2);
        sprintf(cFilter, "%sAND tovPRIHOD_KP.RASH_DAT >= ''%.4d%.2d%.2d'' AND tovPRIHOD_KP.RASH_DAT <=''%.4d%.2d%.2d'' ",
                cFilter, st1.wYear, st1.wMonth, st1.wDay, st2.wYear, st2.wMonth, st2.wDay);
    }
    // Проверка выкатки из-под вагона    
/*
    if( m_Check5.GetCheck() )
    {
        if( !m_Edit1.GetWindowText(cText, 64) || !atoi(cText) )
        {
            MessageBox("Некорректно указан номер вагона!", "Внимание", MB_OK);
            return;
        } else
            sprintf(cFilter, "%sAND (VAG=''%s'') ", cFilter, cText);
    }
*/
    // Проверка подкатки под вагон
/*
    if( m_Check6.GetCheck() )
    {
        if( !m_Edit2.GetWindowText(cText, 64) || !atoi(cText) )
        {
            MessageBox("Некорректно указан номер вагона!", "Внимание", MB_OK);
            return;
        } else
            sprintf(cFilter, "%sAND (RASH_VAG=''%s'') ", cFilter, cText);
    }
*/
    // Проверка кода неисправности
    if( m_Check9.GetCheck() )
    {
        if( !dwNeisp ) 
        {
            MessageBox("Не указан код неисправности!", "Внимание", MB_OK );
            return;
        } else
            sprintf(cFilter, "%sAND (tovREM_KP.KOD_NEISP_OBT=%d OR tovREM_KP.KOD_NEISP_PR=%d)", 
                    cFilter, dwNeisp, dwNeisp);
    }
    //Проверка типов КП
    if( m_Check4.GetCheck() )
    {
        if( m_Combo1.GetCurSel() < 0 ) 
        {
            MessageBox("Некорректно указан тип КП!", "Внимание", MB_OK );
            return;
        }
        sprintf(cFilter, "%sAND tovPASP_KP.ITKP=%d", cFilter, dwTKP[m_Combo1.GetCurSel()]);
    }
    //Контроль требуемого ремонта

    if( m_Check8.GetCheck() )
    {
        if( m_Combo3.GetCurSel() < 0 ) 
        {
            MessageBox("Не указан вид ремонта КП!", "Внимание", MB_OK );
            return;
        }
        sprintf(cFilter, "%sAND tovREM_KP.KOD_REM=%d", cFilter, dwRemKP[m_Combo3.GetCurSel()]);
    }

    // База данных ремонта КП

    CDlgBDSelectRez Dlg;
    CString Ed1, Ed2;
    char Pr1[12] = "", Pr2[12] = "";
    m_Edit1.GetWindowText(Ed1);
    m_Edit2.GetWindowText(Ed2);
    Ed1.Replace("*", "%");
    Ed2.Replace("*", "%");
    if( Ed1 == "" ) Ed1 = " ";
    if( Ed2 == "" ) Ed2 = " ";
    
    if( m_Check12.GetCheck() )
    {
        if( !dwPRPost_ID )
        {
            strcpy(Pr1,"0");
        } else
            ultoa(dwPRPost_ID, Pr1, 10);
    } else 
        strcpy(Pr1, "NULL");


    if( m_Check13.GetCheck() )
    {
        if( !dwPRRash_ID )
        {
            strcpy(Pr2,"0");
        } else
            ultoa(dwPRRash_ID, Pr2, 10);
    } else 
        strcpy(Pr2, "NULL");

//    sprintf(Dlg.cQ, "pTov_BDRemSelect '%s'", cFilter);
    sprintf(Dlg.cQ, "pTov_BDRemSelect %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
            g_iDep,
            isAble(m_Check1.GetCheck(), m_Dt1.GetSQLDate()),
            isAble(m_Check1.GetCheck(), m_Dt2.GetSQLDate()),
            isAble(m_Check2.GetCheck(), m_Dt3.GetSQLDate()),
            isAble(m_Check2.GetCheck(), m_Dt4.GetSQLDate()),
            isAble(m_Check3.GetCheck(), m_Dt5.GetSQLDate()),
            isAble(m_Check3.GetCheck(), m_Dt6.GetSQLDate()),

            isAble(m_Check4.GetCheck(), isNull(m_Combo1.GetItemData(m_Combo1.GetCurSel()))), //Тип КП
            isAble(m_Check5.GetCheck(), isNull(Ed1)), // Выкачены из-под
            isAble(m_Check6.GetCheck(), isNull(Ed2)), // Подкачены под
            Pr1, // Получены от
            Pr2, // Отправлены на
            isAble(m_Check8.GetCheck(),  ultoa(m_Combo3.GetItemData(m_Combo3.GetCurSel()), cText, 10)), /*выполненый ремонт*/
            isAble(m_Check9.GetCheck(), isNull(dwNeisp)), /*код неисправности */
            isAble(m_Check10.GetCheck(), ultoa(m_Combo4.GetItemData(m_Combo4.GetCurSel()), cText, 10)), /*признак обточки*/
            isAble(m_Check14.GetCheck(), ultoa(m_Combo6.GetItemData(m_Combo6.GetCurSel()), cText, 10)), // Признак наплавки гребня
            isAble(m_Check11.GetCheck(), ultoa(m_Combo5.GetItemData(m_Combo5.GetCurSel()), cText, 10)), /*восст. резьбы*/
            isAble(m_Check7.GetCheck(),  ultoa(m_Combo2.GetItemData(m_Combo2.GetCurSel()), cText, 10)), /*п/а сепаратор*/
            isAble(m_Check15.GetCheck(), isNull(m_Combo7.GetItemData(m_Combo7.GetCurSel()))) // Идентификатор типа смазки
            );
    Dlg.iMode = 1;
//    AfxMessageBox(Dlg.cQ);
    if( Dlg.DoModal() == IDCANCEL ) return;
	CDlgWithAccelerators::OnOK();
}

void CDlgDBRemSelect::OnButtonPr() 
{
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdPrKl.SetWindowText(Dlg.cKodPr);	
    m_EdPrName.SetWindowText(Dlg.cPrName);
    dwPRPost_ID = Dlg.ret_dwIPR;
	
}

void CDlgDBRemSelect::OnCheck12() 
{
    if( m_Check12.GetCheck() )
    {
        m_EdPrKl.EnableWindow();
        m_EdPrName.EnableWindow();
        m_ButPr.EnableWindow();
        m_EdPrName.ModifyStyle(0, WS_DISABLED);
        m_EdPrKl.SetFocus();
        m_Check5.SetCheck(0);
        OnCheck5();
    }
    else
    {
        m_EdPrKl.EnableWindow(FALSE);
        m_EdPrName.ModifyStyle(WS_DISABLED, 0);
        m_EdPrName.EnableWindow(FALSE);
        m_ButPr.EnableWindow(FALSE);
    }
}

void CDlgDBRemSelect::OnKillfocusEditKlPr() 
{
    CString str;
    m_EdPrKl.GetWindowText(str);
    if( str == "" )
    {
        dwPRPost_ID = 0;
        return;
    }
    char cText[32] = "";
    char cQ[128] = "";
    long Ind = 0;

    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();

    bool lbCanIzgOs = false;

    DBW.GetData( 1, SQL_C_ULONG, &dwPRPost_ID, 4, &Ind);
    DBW.GetData( 2, SQL_C_CHAR, cText, 32, &Ind);
//    DBW.GetData( 3, SQL_C_BIT, &lbCanIzgOs, 1, &Ind);

    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        MessageBox("Введено некорректное клеймо предприятия!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdPrKl.SetWindowText("");
        m_EdPrName.SetWindowText("");
		m_EdPrKl.SetFocus();
        return;
    }
    m_EdPrName.SetWindowText(cText);
}

void CDlgDBRemSelect::OnButton8() 
{
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdPrKl2.SetWindowText(Dlg.cKodPr);	
    m_EdPrName2.SetWindowText(Dlg.cPrName);
    dwPRRash_ID = Dlg.ret_dwIPR;
}

void CDlgDBRemSelect::OnKillfocusEditPr2() 
{
    CString str;
    m_EdPrKl2.GetWindowText(str);
    if( str == "" )
    {
        dwPRRash_ID = 0;
        return;
    }
    char cText[32] = "";
    char cQ[128] = "";
    long Ind = 0;

    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();

    bool lbCanIzgOs = false;

    DBW.GetData( 1, SQL_C_ULONG, &dwPRRash_ID, 4, &Ind);
    DBW.GetData( 2, SQL_C_CHAR, cText, 32, &Ind);
//    DBW.GetData( 3, SQL_C_BIT, &lbCanIzgOs, 1, &Ind);

    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        MessageBox("Введено некорректное клеймо предприятия!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdPrKl2.SetWindowText("");
        m_EdPrName2.SetWindowText("");
		m_EdPrKl2.SetFocus();
        return;
    }
    m_EdPrName2.SetWindowText(cText);
}

void CDlgDBRemSelect::OnCheck13() 
{
    if( m_Check13.GetCheck() )
    {
        m_EdPrKl2.EnableWindow();
        m_EdPrName2.EnableWindow();
        m_ButPr2.EnableWindow();
        m_EdPrName2.ModifyStyle(0, WS_DISABLED);
        m_EdPrKl2.SetFocus();
        m_Check6.SetCheck(0);
        OnCheck6();
    }
    else
    {
        m_EdPrKl2.EnableWindow(FALSE);
        m_EdPrName2.ModifyStyle(WS_DISABLED, 0);
        m_EdPrName2.EnableWindow(FALSE);
        m_ButPr2.EnableWindow(FALSE);
    }

}

void CDlgDBRemSelect::OnCheck14() 
{
    if( m_Check14.GetCheck() ) 
    {
        m_Combo6.EnableWindow(TRUE);
        m_Combo6.SetFocus();
    }
    else 
        m_Combo6.EnableWindow(FALSE);		

}

void CDlgDBRemSelect::OnCheck15() 
{
    if( m_Check15.GetCheck() ) 
    {
        m_Combo7.EnableWindow(TRUE);
        m_Combo7.SetFocus();
    }
    else 
        m_Combo7.EnableWindow(FALSE);
}
