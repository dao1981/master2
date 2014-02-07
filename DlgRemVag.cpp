// DlgRemVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRemVag.h"

#include "DlgAddRemVag.h"
#include "DlgWheelsToVan.h"
#include "DlgMakeLK.h"
#include "DlgMakeLK_Send.h"
#include "PrintableDlg.h"
#include "DlgTLFromVag.h"
#include "DlgAddVansToRem.h"
#include ".\dlgremvag.h"
#include "DlgMsg4624_Main.h"
#include ".\dlgrashodtl_main.h"
#include "DlgPrihodTL2.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgRemVag dialog
bool bGotHeader = false;
extern int g_iStandAlone;
CDlgRemVag::CDlgRemVag(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRemVag::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRemVag)
	//}}AFX_DATA_INIT
    strNVagMask = "NULL";
    strZakr = "NULL";
    m_Dat1.iMode = 1;
    m_Dat2.iMode = 1;
    m_Dat3.iMode = 1;
    m_Dat4.iMode = 1;
}


void CDlgRemVag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRemVag)
	DDX_Control(pDX, IDC_CHECK7, m_Check7);
	DDX_Control(pDX, IDC_EDIT6, m_EdVagCount);
	DDX_Control(pDX, IDC_COMBO1, m_Cb);
	DDX_Control(pDX, IDC_CHECK6, m_Check6);
	DDX_Control(pDX, IDC_EDIT5, m_EdCount);
	DDX_Control(pDX, IDC_EDIT4, m_EdMaskVan);
	DDX_Control(pDX, IDC_BUTTON4, m_BnSelect);
	DDX_Control(pDX, IDC_CHECK5, m_Check5);
	DDX_Control(pDX, IDC_CHECK4, m_Check4);
	DDX_Control(pDX, IDC_CHECK3, m_Check3);
	DDX_Control(pDX, IDC_CHECK2, m_Check2);
	DDX_Control(pDX, IDC_EDIT116, m_Dat4);
	DDX_Control(pDX, IDC_EDIT7, m_Dat3);
	DDX_Control(pDX, IDC_EDIT3, m_Dat2);
	DDX_Control(pDX, IDC_EDIT2, m_Dat1);
	DDX_Control(pDX, IDC_EDIT1, m_EditNVag);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_BUTTON14, m_ButVagInRem);
	DDX_Control(pDX, IDC_BUTTON48, m_ButNeispVag);
	DDX_Control(pDX, IDC_BUTTON1, m_ButAddVag);
	DDX_Control(pDX, IDC_BUTTON5, m_ButDelVag);
}


BEGIN_MESSAGE_MAP(CDlgRemVag, CDialog)
	//{{AFX_MSG_MAP(CDlgRemVag)
	ON_BN_CLICKED(IDC_BUTTON1, OnAddVanClick)
	ON_BN_CLICKED(IDC_BUTTON2, OnWheelsButton)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_NOTIFY(HDN_ITEMCLICK, 0, OnItemclickList1)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEditNVag)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT7, OnChangeEdit7)
	ON_EN_CHANGE(IDC_EDIT116, OnChangeEdit116)
	ON_EN_CHANGE(IDC_EDIT4, OnChangeEditFind)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck6)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnEditchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_COMMAND(ID_MENUITEM_REMOVE_VAG, OnRemoveVag)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton_Rashod)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton_PrintLK)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnItemchangedList1)
	ON_NOTIFY(LVN_ODSTATECHANGED, IDC_LIST1, OnOdstatechangedList)
	ON_BN_CLICKED(IDC_BUTTON10, OnButton_VanSprav)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck7)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton_PrihodTL)
	ON_COMMAND(ID_MENUITEM_EDIT_VAG, EditSelectedVan)
	ON_BN_CLICKED(IDC_BUTTON12, OnButton_TL_Rashod)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON14, OnBnClickedButton_VagInRem)
	ON_BN_CLICKED(IDC_BUTTON32, OnBnClickedButton_4624)
	ON_BN_CLICKED(IDC_BUTTON38, OnBnClickedButtonVU36_sokr)
	ON_BN_CLICKED(IDC_BUTTON48, OnBnClickedButton48)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRemVag message handlers

void CDlgRemVag::OnAddVanClick() 
{
/*	if( g_iStandAlone )
	{*/
		CDlgAddRemVag Dlg;
		if( Dlg.DoModal() == IDCANCEL ) return;
/*	} else
	{
		CDlgAddVansToRem Dlg;
		if( Dlg.DoModal() == IDCANCEL ) return;
	}*/
	if( Dlg.m_retKPOut == "" ) Dlg.m_retKPOut = "0";
	if( Dlg.m_retKPIn == "" ) Dlg.m_retKPIn = "0";


	m_List.InsertItem(0, Dlg.m_retNVag);
	m_List.SetItemText(0, 1, Dlg.m_retVRem);
	m_List.SetItemText(0, 2, Dlg.m_retDatNachRem);	
	m_List.SetItemText(0, 3, Dlg.m_retKPOut);
	m_List.SetItemText(0, 4, Dlg.m_retKPIn);
	m_List.SetItemText(0, 5, Dlg.m_retDatRem);
	m_List.SetItemText(0, 6, Dlg.m_retNLK);
	m_List.SetItemText(0, 7, Dlg.m_retClose);

	m_List.qwSetItemData(0, Dlg.m_retILK);
	m_List.SetItemColor(0, 0, RGB(255,255,200));

	//    RefreshList();
}

int CDlgRemVag::RefreshList()
{
/*
    DWORD nCol = 0;
    SYSTEMTIME st;
    ZeroMemory(&st, sizeof(st));
    char dt[16] = "";
    m_Dat1.GetTime(&st);
    DateToSql(st, dt);
    CString str;
    str.Format("pTov_GetAllRemVans %u, %s", g_iDep, m_Dat1.GetSQLDate());
    DBW.ExecSQL(str);
    if( !bGotHeader )
    {
        bGotHeader = true;
        DBW.SetListHeader(&m_List);
    }
    DBW.UpdateListByHandle(&m_List, &nCol);
    DBW.CloseCursor();
    char cText[32] = ""; //Добавляют вагон, а установлен фильтр по которому он не виден
    itoa(m_List.GetItemCount(), cText, 10);
    m_EdCount.SetWindowText(cText);
*/
    OnButton4();
    return 0;
}


extern int g_iMessageNumber;
BOOL CDlgRemVag::OnInitDialog() 
{
	CDialog::OnInitDialog();

    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );    

    m_EdCount.ModifyStyle(0, WS_DISABLED);
/*
    m_Check1.EnableWindow(FALSE);
    m_Check2.EnableWindow(FALSE);
    m_Check3.EnableWindow(FALSE);
    m_Check4.EnableWindow(FALSE);
    m_Check5.EnableWindow(FALSE);
*/
    m_Dat1.EnableWindow(FALSE);
    m_Dat2.EnableWindow(FALSE);
    m_Dat3.EnableWindow(FALSE);
    m_Dat4.EnableWindow(FALSE);
    m_Cb.EnableWindow(FALSE);
    m_EditNVag.EnableWindow(FALSE);

    DBW.FillComboWithTRemVag(&m_Cb);

	if( g_iMessageNumber )
	{
		m_ButAddVag.ModifyStyle(WS_VISIBLE, 0);
		m_ButDelVag.ModifyStyle(WS_VISIBLE, 0);
	}

    CButton *b1, *b2;
    b1 = (CButton *)GetDlgItem(IDC_RADIO1);
    b2 = (CButton *)GetDlgItem(IDC_RADIO2);
    b1->SetCheck(1);
    b1->EnableWindow(FALSE);
    b2->EnableWindow(FALSE);
	if( g_iStandAlone ) 
	{
		m_ButVagInRem.ModifyStyle(WS_VISIBLE, 0);
		m_ButNeispVag.ModifyStyle(WS_VISIBLE, 0);
	}

    bGotHeader = false;

    m_Menu = new CMenu;
//    m_Menu->CreatePopupMenu();
    m_Menu->LoadMenu(IDR_MENU_VAG);
//    ASSERT(m_Menu->m_hMenu);    
//    m_Menu->AppendMenu(MF_STRING, 0, "asd");
    SYSTEMTIME st;
    GetLocalTime(&st);
	if( st.wDay > 10 )
	{
		st.wDay-=10;
	} else
	{
		int tttt = 10 - st.wDay;
		st.wMonth--;
		if( st.wMonth == 0 )
		{
			st.wMonth = 12;
			st.wYear--;
		}
		st.wDay = 30 - tttt;
	}
/*
    if( st.wMonth == 1 )
    {
        st.wMonth = 12;
        st.wYear--;
    } else
        st.wMonth--;
*/
	if( st.wDay == 31 || st.wDay == 30 ) 
	{
		st.wDay = 1; 
		st.wMonth++;
		if( st.wMonth > 12 ) {st.wMonth = 1; st.wYear++;}
	}
	if( st.wDay > 28 && st.wMonth == 2 ) st.wDay = 28;
    m_Dat1.SetTime(&st);
    m_Dat2.InitDate();
    m_Check2.SetCheck(1);
    OnCheck2();

    RefreshList();


/*    DWORD nCol = 0;
    SYSTEMTIME st;
    ZeroMemory(&st, sizeof(st));
    char dt[16] = "";
    m_Dat1.GetTime(&st);
    DateToSql(st, dt);
    CString str;
    str.Format("pTov_GetAllRemVans %u, %s", g_iDep, dt);
    DBW.ExecSQL(str);
    DBW.SetListHeader(&m_List);
    DBW.UpdateListByHandle(&m_List, &nCol);
    DBW.CloseCursor();
*/
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgRemVag::OnWheelsButton() 
{
    CDlgWheelsToVan	Dlg;
    int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
    Dlg.m_nVag = m_List.GetItemText(idx, 0);
    Dlg.m_vRem = m_List.GetItemText(idx, 1);
    Dlg.qwLKID = m_List.qwGetItemData(idx); ///fixin
    m_List.GetItemText(idx, 2, Dlg.cVagDate, 16);
    m_List.GetItemText(idx, 5, Dlg.cVagDatRem, 16);
	Dlg.m_DatRemInStr = m_List.GetItemText(idx, 2);
//    Dlg.stVagDate = 
//    Dlg.strNKP = Dlg.m_nVag;
	Dlg.qwILK = m_List.qwGetItemData(idx);
    Dlg.iMode = 0;
    if( Dlg.DoModal() == IDCANCEL ) return;
    RefreshList();
    m_List.EnsureVisible(idx, TRUE);
    m_List.SetSelectionMark(idx);
}

void CDlgRemVag::OnCheck1() 
{    
    CButton *b1, *b2;
    b1 = (CButton *)GetDlgItem(IDC_RADIO1);
    b2 = (CButton *)GetDlgItem(IDC_RADIO2);

    if( m_Check1.GetCheck() )
    {
        b1->EnableWindow();
        b2->EnableWindow();
        strZakr = "NULL";
        if( b2->GetCheck() )
        {
            m_Check3.EnableWindow(FALSE);
            m_Check3.SetCheck(0);
            OnCheck3();
            m_Check4.SetCheck(0);
            OnCheck4();
            m_Check4.EnableWindow(FALSE);
        }
    }
    else
    {
        b1->EnableWindow(FALSE);
        b2->EnableWindow(FALSE);
        m_Check3.EnableWindow();
        m_Check4.EnableWindow();

        strZakr = "1";
    }

    m_BnSelect.EnableWindow();
//    RefreshVagList();
}

void CDlgRemVag::OnItemclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;
	m_List.OnHeaderClicked(pNMHDR, pResult);
	*pResult = 0;
}

void CDlgRemVag::OnChangeEditNVag() 
{
    CString str;
    m_EditNVag.GetWindowText(str);
    if( str == "" )
    {
        strNVagMask = "NULL";
//        RefreshVagList();
        return;
    }

    str.Replace('*', '%');
    strNVagMask = "'" + str + "'";
//    RefreshVagList();
    m_BnSelect.EnableWindow();
}

int CDlgRemVag::RefreshVagList(CString cQ)
{
    DWORD nCol = 0;
    DBW.ExecSQL(cQ);
    if( !bGotHeader )
    {
        bGotHeader = true;
        DBW.SetListHeader(&m_List);
		m_List.SetColumnWidth(0, 80);
		m_List.SetColumnWidth(2, 75);
		m_List.SetColumnWidth(3, 80);
		m_List.SetColumnWidth(4, 85);
		m_List.SetColumnWidth(5, 70);
		m_List.SetColumnWidth(6, 65);
		m_List.SetColumnWidth(7, 70);

    }
	DBW.WriteLog("bf");
    DBW.UpdateListByHandle(&m_List, &nCol, true, true);
	DBW.WriteLog("af");
    DBW.CloseCursor();
	DBW.WriteLog("cl");
    char cText[32] = "";
    itoa(m_List.GetItemCount(), cText, 10);
    m_EdCount.SetWindowText(cText);
    return 0;
}

void CDlgRemVag::OnCheck2() 
{
    if( m_Check2.GetCheck() )
    {
        m_Dat1.EnableWindow();
        m_Dat2.EnableWindow();
        m_Dat1.SetFocus();
    } else
    {
        m_Dat1.EnableWindow(FALSE);
        m_Dat2.EnableWindow(FALSE);
    }
    m_BnSelect.EnableWindow();
}

void CDlgRemVag::OnCheck4() 
{
    if( m_Check4.GetCheck() )
    {
        m_Dat3.EnableWindow();
        m_Dat4.EnableWindow();
        m_Check3.SetCheck(0);
        OnCheck3();
        m_Dat3.SetFocus();
    } else
    {
        m_Dat3.EnableWindow(FALSE);
        m_Dat4.EnableWindow(FALSE);
    }
    m_BnSelect.EnableWindow();
}

void CDlgRemVag::OnCheck5() 
{
    if( m_Check5.GetCheck() )
    {
        m_EditNVag.EnableWindow();
        m_EditNVag.SetFocus();
    } else
    {
        m_EditNVag.EnableWindow(FALSE);
    }
    m_BnSelect.EnableWindow();
}

void CDlgRemVag::OnButton4() //Select
{
    CString str;
    if( m_Check2.GetCheck() ) //2, 3
    {
        str += (CString)m_Dat1.GetSQLDate() + ", " + (CString)m_Dat2.GetSQLDate() + ", ";
    } else
        str += "NULL, NULL, ";
    
    
    if( m_Check1.GetCheck() ) //4
    {
        CButton *b1, *b2;
        b1 = (CButton *)GetDlgItem(IDC_RADIO1);
        b2 = (CButton *)GetDlgItem(IDC_RADIO2);
        if( b1->GetCheck() )
        {
            str += "1, ";
        }
        else
        if( b2->GetCheck() )
        {
            str += "0, ";
        }
        else
        {
            str += "NULL, ";
        }
    }
    else
    {
        str += "NULL, ";
    }
    if( m_Check3.GetCheck() ) //5
    {
        str += "0, ";
    }
    else
    if( m_Check4.GetCheck() )
    {
        str += "1, ";
    }
    else
        str += "NULL, ";

    if( m_Check4.GetCheck() ) //6, 7
    {
        str += (CString)m_Dat3.GetSQLDate() + ", " + (CString)m_Dat4.GetSQLDate() + ", ";
    } else
        str += "NULL, NULL, ";
    
    char cText[64]="";
    if( m_Check5.GetCheck() && m_EditNVag.GetWindowTextLength() ) // 7
    {        
        m_EditNVag.GetWindowText(cText, 64);
        str += CString("'") + cText + "', ";
    } else
        str += "NULL, ";

    if( m_Check6.GetCheck() )
    {
        ltoa(m_Cb.GetItemData(m_Cb.GetCurSel()), cText, 10);
        if( m_Cb.GetItemData(m_Cb.GetCurSel()) == -1 )
        {
            strcpy(cText, "NULL");
        }
        str += cText;
    } else
    {
        str += "NULL";
    }

    CString q;
    q.Format("pTov_GetAllRemVans %u, %s", g_iDep, str);
    RefreshVagList(q);
	m_BnSelect.EnableWindow(FALSE);
}

void CDlgRemVag::OnRadio1() 
{
    m_BnSelect.EnableWindow();
    m_Check3.EnableWindow();
    m_Check4.EnableWindow();
}

void CDlgRemVag::OnRadio2() 
{
    m_BnSelect.EnableWindow();	
    m_Check3.EnableWindow(FALSE);
    m_Check3.SetCheck(0);
    OnCheck3();
    m_Check4.SetCheck(0);
    OnCheck4();
    m_Check4.EnableWindow(FALSE);
}

void CDlgRemVag::OnCheck3() 
{
    if( m_Check3.GetCheck() )
    {
        m_Check4.SetCheck(0);
        OnCheck4();
    }
    m_BnSelect.EnableWindow();
}

void CDlgRemVag::OnChangeEdit2() 
{
    m_BnSelect.EnableWindow();
}

void CDlgRemVag::OnChangeEdit3() 
{
    m_BnSelect.EnableWindow();
}

void CDlgRemVag::OnChangeEdit7() 
{
    m_BnSelect.EnableWindow();
}

void CDlgRemVag::OnChangeEdit116() 
{
    m_BnSelect.EnableWindow();
}

CString sOldText;

void CDlgRemVag::OnChangeEditFind() 
{
    CString s1;
    CString s2;
    m_EdMaskVan.GetWindowText(s1);
    if( s1.GetLength() <= 0 )
    {
        m_List.ClearMark();
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
//            m_List.SetHotCursor(i);
            m_List.EnsureVisible(i, TRUE);
            m_List.RedrawWindow();
            sOldText = s1;
            return;
        }
    }
    m_EdMaskVan.GetWindowText(sOldText);
}

void CDlgRemVag::OnCheck6() 
{
    if( m_Check6.GetCheck() )
    {
        m_Cb.EnableWindow();
    }
    else
    {
        m_Cb.EnableWindow(FALSE);
    }
    m_BnSelect.EnableWindow();
}

void CDlgRemVag::OnEditchangeCombo1() 
{
    m_BnSelect.EnableWindow();
}

void CDlgRemVag::OnSelchangeCombo1() 
{
    m_BnSelect.EnableWindow();
}

void CDlgRemVag::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 0;
    EditSelectedVan();
}

void CDlgRemVag::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{    
	*pResult = 0;
    CPoint p;
    GetCursorPos(&p);
    CRect r;
    r.left = p.x;
    r.right = p.x + 100;
    r.top = p.y;
    r.bottom = p.y + 400;
    m_Menu->GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, p.x, p.y, this);
}

void CDlgRemVag::OnClose() 
{
    delete(m_Menu);
	CDialog::OnClose();
}

void CDlgRemVag::OnButton5() // Удалить вагон
{
//    m_List.EnableItem(3, FALSE);
    OnRemoveVag();
}

void CDlgRemVag::EditSelectedVan()
{
    int iIndex = m_List.GetSelectionMark();
    __int64 qwVagID = m_List.qwGetItemData(iIndex);
    long Ind = 0;
    CString cQ;
    CDlgAddRemVag Dlg;
    DWORD dwNum = 0;

    cQ.Format("pTov_GetVagByLKVagID %I64u", qwVagID);
    char cText[64] = "";
    DBW.ExecSQL(cQ);
    DBW.Fetch();
    
    DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )
    {
        Dlg.m_strNVag = cText;
    }
    DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( Ind != -1 && dwNum )
    {
        Dlg.m_bCheck = TRUE;
    } else
        Dlg.m_bCheck = FALSE;

    DBW.GetData(4, SQL_C_ULONG, &dwNum, 4, &Ind);
    if( Ind != -1 )
    {
        Dlg.m_TypeIndex = dwNum;
    }
   
    SQL_DATE_STRUCT  sqlDat;
    SYSTEMTIME st;
// Дата перечисления в неисправные
    DBW.GetData(5, SQL_C_DATE, &sqlDat, sizeof(sqlDat), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &st);
        Dlg.m_stDatPerechNeisp = st;
        Dlg.bSetDatPerechNeisp = TRUE;
    }
	DBW.GetData(6, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		Dlg.m_stDatPerechNeisp.wHour = (WORD)dwNum;
	}

	DBW.GetData(7, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		Dlg.m_stDatPerechNeisp.wMinute = (WORD)dwNum;
	}

// Дата начала ремонта
    DBW.GetData(8, SQL_C_DATE, &sqlDat, sizeof(sqlDat), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &st);
        Dlg.m_stDateNachRem = st;
        Dlg.bSetDateNachRem = TRUE;
     }
	DBW.GetData(9, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		Dlg.m_stDateNachRem.wHour = (WORD)dwNum;
	}
	DBW.GetData(10, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		Dlg.m_stDateNachRem.wMinute = (WORD)dwNum;
	}

// Дата сборки
    DBW.GetData(11, SQL_C_DATE, &sqlDat, sizeof(sqlDat), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &st);
        Dlg.m_stDatSbor = st;
        Dlg.bSetDatSbor = TRUE;
    }
	DBW.GetData(12, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		Dlg.m_stDatSbor.wHour = (WORD)dwNum;
	}
	DBW.GetData(13, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		Dlg.m_stDatSbor.wMinute = (WORD)dwNum;
	}

//Дата 4624
    DBW.GetData(14, SQL_C_DATE, &sqlDat, sizeof(sqlDat), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &st);
        Dlg.m_stDat4624 = st;
        Dlg.bSetDat4624 = TRUE;
    }
	DBW.GetData(15, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		Dlg.m_stDat4624.wHour = (WORD)dwNum;
	}

	DBW.GetData(16, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		Dlg.m_stDat4624.wMinute = (WORD)dwNum;
	}

	DBW.GetData(17, SQL_C_CHAR, &cText, 64, &Ind );
	if( Ind != -1 )
	{
		Dlg.m_strNLK = cText;
	}

	
	DBW.GetData(18, SQL_C_CHAR, &Dlg.m_cVktTel, 4, &Ind );
	DBW.GetData(19, SQL_C_CHAR, &Dlg.m_cVktKP, 4, &Ind );
	DBW.GetData(20, SQL_C_CHAR, &Dlg.m_cPdkTel, 4, &Ind );
	DBW.GetData(21, SQL_C_CHAR, &Dlg.m_cPdkKP, 4, &Ind );

	DBW.GetData(22, SQL_C_CHAR, cText, 4, &Ind );
	if( Ind != -1 ) Dlg.m_strKodSobst = cText;

	DBW.GetData(23, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) Dlg.m_strNameSobst = cText;
	// фамилии

	DBW.GetData(24, SQL_C_ULONG, &Dlg.m_dwIFam1, 4, &Ind );
	if( Ind != -1 )
	{
		DBW.GetData(25, SQL_C_CHAR, cText, 32, &Ind );
		Dlg.m_strFam1 = cText;
	}

	DBW.GetData(26, SQL_C_ULONG, &Dlg.m_dwIFam2, 4, &Ind );
	if( Ind != -1 )
	{
		DBW.GetData(27, SQL_C_CHAR, cText, 32, &Ind );
		Dlg.m_strFam2 = cText;
	}

	DBW.GetData(28, SQL_C_ULONG, &Dlg.m_dwIFam3, 4, &Ind );
	if( Ind != -1 )
	{
		DBW.GetData(29, SQL_C_CHAR, cText, 32, &Ind );
		Dlg.m_strFam3 = cText;
	}

	DBW.GetData(30, SQL_C_ULONG, &Dlg.m_dwIFam4, 4, &Ind );
	if( Ind != -1 )
	{
		DBW.GetData(31, SQL_C_CHAR, cText, 32, &Ind );
		Dlg.m_strFam4 = cText;
	}

	DBW.GetData(32, SQL_C_ULONG, &Dlg.m_dwIFam5, 4, &Ind );
	if( Ind != -1 )
	{
		DBW.GetData(33, SQL_C_CHAR, cText, 32, &Ind );
		Dlg.m_strFam5 = cText;
	}


    DBW.CloseCursor();
    Dlg.m_qwILKVag = qwVagID; //fixin
    Dlg.bIsEdit = true;
    if(Dlg.DoModal() == IDCANCEL ) return;
    RefreshList();
}

void CDlgRemVag::OnRemoveVag() 
{
    bool q = FALSE;
    int iIndex = m_List.GetSelectionMark();
    if( atol(m_List.GetItemText(iIndex, 3)) > 0 )
    {
        if( MessageBox("Из-под этого вагона были выкачены КП. Продолжить удаление?", 
                   "Предупреждение",
                   MB_YESNO | MB_ICONINFORMATION) == IDNO ) 
             return;
        q = TRUE;
    }

    __int64 qwVagID = m_List.qwGetItemData(iIndex);
    if( !q )
    if( MessageBox("Вы действительно хотите удалить этот вагон?", 
                   "Предупреждение", 
                   MB_YESNO | MB_ICONINFORMATION) == IDNO ) return;
    CString cQ;
    cQ.Format("pTov_DeleteLKVag %I64u, %u", m_List.qwGetItemData(m_List.GetSelectionMark()), g_iFam);
    DBW.ExecSQL(cQ);
    DBW.CloseCursor();
    DBW.ReallocHandle();
//    RefreshList();
	m_List.DeleteItem(iIndex);
}

void CDlgRemVag::OnButton_Rashod() 
{
    CDlgWheelsToVan	Dlg;
    int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
    Dlg.m_nVag = m_List.GetItemText(idx, 0);
    Dlg.m_vRem = m_List.GetItemText(idx, 1);
    Dlg.qwLKID = m_List.qwGetItemData(idx); ///fixin
    m_List.GetItemText(idx, 2, Dlg.cVagDate, 16);
    m_List.GetItemText(idx, 5, Dlg.cVagDatRem, 16);
	Dlg.m_DatRemInStr = m_List.GetItemText(idx, 2);
//    Dlg.stVagDate = 
//    Dlg.strNKP = Dlg.m_nVag;
	Dlg.qwILK = m_List.qwGetItemData(idx);
    Dlg.iMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    RefreshList();
    m_List.EnsureVisible(idx, TRUE);
    m_List.SetSelectionMark(idx);
}

void CDlgRemVag::OnButton6() //Сформировать ЛУК
{
    if( m_List.GetSelectionMark() < 0 ) return;
	CPrintableDlg Dlg;
//    CDlgMakeLK Dlg;    
	Dlg.m_bCheck1 = true;
    Dlg.m_bCheck2 = true;
sprintf(Dlg.cQ, "pTov_mkcReportVU36MP %I64u, 1", m_List.qwGetItemData(m_List.GetSelectionMark()));
    Dlg.DoModal();


}
/*
void CDlgRemVag::OnButton_Message() 
{
	CDlgMakeLK_Send Dlg;
    int index = m_List.GetSelectionMark();
    if( index < 0 ) return;
    Dlg.m_VagNum = m_List.GetItemText(index, 0);
    Dlg.m_LNum = m_List.GetItemText(index, 6);
    Dlg.m_Oper = DBW.GetFIOByID(g_iFam);
    Dlg.qwILK = m_List.qwGetItemData(m_List.GetSelectionMark());
    if( Dlg.DoModal() == IDCANCEL ) return;
}
*/
void CDlgRemVag::OnButton_PrintLK() 
{
    if( m_List.GetSelectionMark() < 0 ) return;	
    CPrintableDlg Dlg;
/*
    CString cQ = "";
    char cText[255] = "";
    long Ind = 0;

    cQ.Format("pTov_LK_CheckComplete %u", m_List.GetItemData(m_List.GetSelectionMark()));
    DBW.ExecSQL(cQ);
    DBW.Fetch();
    DBW.GetData(1, SQL_C_CHAR, &cText, 255, &Ind);
    DBW.CloseCursor();

    if( Ind != -1 ) 
    {
        DBW.CloseCursor();
        AfxMessageBox(cText, MB_OK);
        return;
    }
*/
	Dlg.m_bCheck1 = true;
    Dlg.m_bCheck2 = false;
    sprintf(Dlg.cQ, "pTov_mkcReportVU36MP %I64u", m_List.qwGetItemData(m_List.GetSelectionMark()));
    Dlg.DoModal();
}

void CDlgRemVag::OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
    int iItemCount = m_List.GetItemCount();
    int iCount = 0;
    for( int i =0; i < iItemCount; i++ )
        if( m_List.GetCheck(i) ) iCount++;

    char cText[64] = "";
    itoa(iCount, cText, 10);
    m_EdVagCount.SetWindowText(cText);
    
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;
	*pResult = 0;
}

void CDlgRemVag::OnOdstatechangedList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NMLVODSTATECHANGE* pStateChanged = (NMLVODSTATECHANGE*)pNMHDR;
    *pResult = 0;
}

void CDlgRemVag::OnButton_VanSprav() 
{
    CString cQ = "";
    cQ = "pTov_mkcReportVagCrTabILK";
    DBW.ExecSQL(cQ);
    DBW.Fetch();
    DBW.CloseCursor();
    for(int i=0; i < m_List.GetItemCount(); i++ )
    {
        if( m_List.GetCheck(i) )
        {
            cQ.Format("pTov_mkcReportVagInsILK %I64u", m_List.qwGetItemData(i));
            DBW.ExecSQL(cQ);
            DBW.CloseCursor();
        }
    }
    CPrintableDlg Dlg;
    sprintf(Dlg.cQ, "pTov_mkcReportVagSob");
    Dlg.DoModal();
}

void CDlgRemVag::OnCheck7() 
{
    int iState = m_Check7.GetCheck();
    int ic = m_List.GetItemCount();
    for( int i=0; i < ic; i++ )
    {
        m_List.SetCheck(i, iState);
    }
}

void CDlgRemVag::OnButton_PrihodTL() 
{
	
//	AfxMessageBox("Внимание! Следующая форма предназначена для просмотра одним глазом. Во избежании травмы заклейте правый глаз пластырем!");
	CDlgPrihodTL2 Dlg;
	
	int idx = m_List.GetSelectionMark();
	if( idx < 0 ) return;

/**	m_List.GetItemText(idx, 0, Dlg.m_cNVag, 32);
	m_List.GetItemText(idx, 1, Dlg.m_cVRem, 32);
	m_List.GetItemText(idx, 2, Dlg.m_cDatRemIn, 16);
	m_List.GetItemText(idx, 5, Dlg.m_cDatRemOut, 16);*/

	Dlg.qwILK = m_List.qwGetItemData(idx);
    Dlg.DoModal();

}

void CDlgRemVag::OnButton_TL_Rashod() 
{
	if( m_List.GetSelectionMark() == -1 ) return;
	CDlgRashodTl_Main Dlg;
	Dlg.qwILK = m_List.qwGetItemData(m_List.GetSelectionMark());
    Dlg.DoModal();
}

void CDlgRemVag::OnBnClickedButton_VagInRem()
{
		CDlgAddVansToRem Dlg;
		if( Dlg.DoModal() == IDCANCEL ) return;
		RefreshList();
}

void CDlgRemVag::OnBnClickedButton_4624()
{
	if( m_List.GetSelectionMark() == -1 ) return;
	CDlgMsg4624_Main Dlg;
	char cText[64] = "";
/*
	if( !m_List.GetItemText(m_List.GetSelectionMark(), 7, cText, 64) )
		if( !m_List.GetItemText(m_List.GetSelectionMark(), 5, cText, 64) )
			m_List.GetItemText(m_List.GetSelectionMark(), 2, cText, 64);
*/
	char cQ[128] = "";
	sprintf(cQ, "pTov_GetDate4624 %I64u", m_List.qwGetItemData(m_List.GetSelectionMark()));
	
	SQL_DATE_STRUCT date;
	SQL_TIME_STRUCT time;

	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(st));
	long Ind = 0;

	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_TYPE_DATE, &date, sizeof(SQL_DATE_STRUCT), &Ind);
	DBW.GetData(2, SQL_C_TYPE_TIME, &time, sizeof(SQL_TIME_STRUCT), &Ind);
	DBW.CloseCursor();
//	Dlg.stRemDat = RusDateToSysDate(cText); //very old comment

//	Dlg.stDat4624 = RusDateToSysDate(cText);
	Dlg.stDat4624.wDay = date.day;
	Dlg.stDat4624.wMonth = date.month;
	Dlg.stDat4624.wYear = date.year;
	Dlg.stDat4624.wHour = time.hour;
	Dlg.stDat4624.wMinute = time.minute;
	Dlg.stDat4624.wSecond = time.second;
	Dlg.stDat4624.wMilliseconds = 1;
	m_List.GetItemText(m_List.GetSelectionMark(), 0, Dlg.cVagNum32, 32);
	Dlg.DoModal();
}

void CDlgRemVag::OnBnClickedButtonVU36_sokr()
{
	if( m_List.GetSelectionMark() < 0 ) return;
	char cQ[128] = "";
	sprintf(cQ, " pTov_mkcRepHtmVU36MPS %I64u", m_List.qwGetItemData(m_List.GetSelectionMark()));
	DBW.DisplayHtmlReport(cQ);
}

void CDlgRemVag::OnBnClickedButton48()
{
		CDlgAddVansToRem Dlg;
		Dlg.iNeisp = 1;
		if( Dlg.DoModal() == IDCANCEL ) return;
		RefreshList();
}
