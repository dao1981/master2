// DlgSelectOS.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSelectOS.h"
#include "DlgSprav1.h"
#include "DlgBDSelectRez.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSelectOS dialog


CDlgSelectOS::CDlgSelectOS(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgSelectOS::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSelectOS)
	//}}AFX_DATA_INIT
    m_Dat1.SetMode(1);
    m_Dat2.SetMode(1);
    m_Dat3.SetMode(1);
    m_Dat4.SetMode(1);
    m_Dat5.SetMode(1);
    m_Dat6.SetMode(1);
    m_Dat7.SetMode(3);
    m_Dat8.SetMode(3);
    dwPrIzg = 0;
    dwPrPeres = 0;
}


void CDlgSelectOS::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSelectOS)
	DDX_Control(pDX, IDC_CHECK10, m_c10);
	DDX_Control(pDX, IDC_BUTTON2, m_But2);
	DDX_Control(pDX, IDC_BUTTON1, m_But1);
	DDX_Control(pDX, IDC_CHECK6, m_c6);
	DDX_Control(pDX, IDC_CHECK9, m_c9);
	DDX_Control(pDX, IDC_CHECK8, m_c8);
	DDX_Control(pDX, IDC_CHECK7, m_c7);
	DDX_Control(pDX, IDC_CHECK5, m_c5);
	DDX_Control(pDX, IDC_CHECK4, m_c4);
	DDX_Control(pDX, IDC_CHECK3, m_c3);
	DDX_Control(pDX, IDC_CHECK2, m_c2);
	DDX_Control(pDX, IDC_CHECK1, m_c1);
	DDX_Control(pDX, IDC_EDIT71, m_EdMask);
	DDX_Control(pDX, IDC_EDIT69, m_Dat8);
	DDX_Control(pDX, IDC_EDIT70, m_Dat7);
	DDX_Control(pDX, IDC_EDIT10, m_EdIzgPrName);
	DDX_Control(pDX, IDC_EDIT9, m_EdIzgKl);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_EDIT8, m_EdPeresPrName);
	DDX_Control(pDX, IDC_EDIT3, m_EdPeresKl);
	DDX_Control(pDX, IDC_EDIT4, m_Dat6);
	DDX_Control(pDX, IDC_EDIT6, m_Dat5);
	DDX_Control(pDX, IDC_EDIT5, m_Dat4);
	DDX_Control(pDX, IDC_EDIT7, m_Dat3);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSelectOS, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgSelectOS)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck6)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck7)
	ON_BN_CLICKED(IDC_CHECK8, OnCheck8)
	ON_BN_CLICKED(IDC_CHECK9, OnCheck9)
	ON_BN_CLICKED(IDC_CHECK10, OnCheck10)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_EN_KILLFOCUS(IDC_EDIT3, OnKillfocusEdit3)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck5)
	ON_EN_KILLFOCUS(IDC_EDIT9, OnKillfocusEdit9)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSelectOS message handlers

BOOL CDlgSelectOS::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();

/*    m_EdPeresPrName.ModifyStyle(0, WS_DISABLED, 0);
    m_EdIzgPrName.ModifyStyle(0, WS_DISABLED, 0);*/
    this->SetWindowText(CString("Выборка из базы данных осей ") + g_strDepoSName);
	
    DBW.FillComboWithTKP(&m_Combo1);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSelectOS::OnCheck1() 
{
    if( m_c1.GetCheck() )
    {
        m_Dat1.EnableWindow();
        m_Dat2.EnableWindow();
        m_Dat1.SetFocus();
    } else
    {
        m_Dat1.EnableWindow(FALSE);
        m_Dat2.EnableWindow(FALSE);
    }
}

void CDlgSelectOS::OnCheck2() 
{
    if( m_c2.GetCheck() )
    {
        m_c5.SetCheck(0);
        OnCheck5();
        m_Dat3.EnableWindow();
        m_Dat4.EnableWindow();
        m_Dat3.SetFocus();
    } else
    {
        m_Dat3.EnableWindow(FALSE);
        m_Dat4.EnableWindow(FALSE);
    }
	
}

void CDlgSelectOS::OnCheck3() 
{
    if( m_c3.GetCheck() )
    {
        m_Dat5.EnableWindow();
        m_Dat6.EnableWindow();
        m_c4.SetCheck(0);
        m_Dat5.SetFocus();
//        m_c5.SetCheck(0);
    } else
    {
        m_Dat5.EnableWindow(FALSE);
        m_Dat6.EnableWindow(FALSE);
    }
}

void CDlgSelectOS::OnCheck4() 
{
    if( m_c4.GetCheck() )
    {
        m_c3.SetCheck(0);
        m_c6.SetCheck(0);
        OnCheck3();
        OnCheck6();
    } else
    {
/*        m_Dat5.EnableWindow(FALSE);
        m_Dat6.EnableWindow(FALSE);*/
    }
}

void CDlgSelectOS::OnCheck5()
{
    if( m_c5.GetCheck() )
    {
        m_c2.SetCheck(0);
        OnCheck2();
    } else
    {
/*        m_Dat5.EnableWindow(FALSE);
        m_Dat6.EnableWindow(FALSE);*/
    }

}

void CDlgSelectOS::OnCheck6() 
{
    if( m_c6.GetCheck() )
    {
        m_EdPeresKl.EnableWindow();
        m_EdPeresPrName.EnableWindow();
        m_EdPeresPrName.ModifyStyle(0, WS_DISABLED);
        m_But1.EnableWindow();
        m_c4.SetCheck(0);
        m_EdPeresKl.SetFocus();
//        m_c5.SetCheck(0);
    } else
    {
        m_EdPeresKl.EnableWindow(FALSE);
        m_EdPeresPrName.ModifyStyle(WS_DISABLED, 0);
        m_EdPeresPrName.EnableWindow(FALSE);
        m_But1.EnableWindow(FALSE);
    }
}

void CDlgSelectOS::OnCheck7() 
{
    if( m_c7.GetCheck() )
    {
        m_Combo1.EnableWindow();
        m_Combo1.SetFocus();
    }
    else
    {
        m_Combo1.EnableWindow(FALSE);
    }
}

void CDlgSelectOS::OnCheck8() 
{
    if( m_c8.GetCheck() )
    {
        m_EdIzgKl.EnableWindow();
        m_EdIzgPrName.EnableWindow();
        m_EdIzgPrName.ModifyStyle(0, WS_DISABLED, 0);
        m_But2.EnableWindow();
        m_EdIzgKl.SetFocus();
    }
    else
    {
        m_EdIzgKl.EnableWindow(FALSE);
        m_EdIzgPrName.ModifyStyle(WS_DISABLED, 0);
        m_EdIzgPrName.EnableWindow(FALSE);
        m_But2.EnableWindow(FALSE);
    }    	
}

void CDlgSelectOS::OnCheck9() 
{
    if( m_c9.GetCheck() )
    {
        m_Dat7.EnableWindow();
        m_Dat8.EnableWindow();
        m_Dat7.SetFocus();
    } else
    {
        m_Dat7.EnableWindow(FALSE);
        m_Dat8.EnableWindow(FALSE);
    }

}

void CDlgSelectOS::OnCheck10() 
{
	if( m_c10.GetCheck() )
    {
        m_EdMask.EnableWindow();
        m_EdMask.SetFocus();
    } else
    {
        m_EdMask.EnableWindow(FALSE);
    }

}

void CDlgSelectOS::OnButton1() 
{
	CDlgSprav1 Dlg;
    
    Dlg.iDlgKind = 1;
    Dlg.iDlgMode = 0;
    if( Dlg.DoModal() == IDCANCEL ) return;

    dwPrPeres = Dlg.ret_dwIPR;
    m_EdPeresKl.SetWindowText(Dlg.cKodPr);
    m_EdPeresPrName.SetWindowText(Dlg.cPrName);

}

void CDlgSelectOS::OnButton2() 
{
	CDlgSprav1 Dlg;
    
    Dlg.iDlgKind = 4;
    Dlg.iDlgMode = 0;
    if( Dlg.DoModal() == IDCANCEL ) return;

    dwPrIzg = Dlg.ret_dwIPR;
    m_EdIzgKl.SetWindowText(Dlg.cKodPr);
    m_EdIzgPrName.SetWindowText(Dlg.cPrName);
	
}


void CDlgSelectOS::OnOK() 
{
    char cMask[64] = "";
    m_EdMask.GetWindowText(cMask, 64);
    CString cQ;
    CString strNoRash, strNoFor;

    if( m_c1.GetCheck() && m_Dat1.isNull() && m_Dat2.isNull() )
    {
        AfxMessageBox("Необходимо указать хотя бы одну границу даты прихода оси!");
        return;
    }
    if( m_c8.GetCheck() && !dwPrIzg )
    {
        AfxMessageBox("Не указано предприятие изготовления оси!");
        return;
    }
    if( m_c7.GetCheck() && m_Combo1.GetCurSel() < 0 )
    {
        AfxMessageBox("Необходимо указать тип КП!");
        return;
    }
    if( m_c9.GetCheck() && m_Dat7.isNull() && m_Dat8.isNull() )
    {
        AfxMessageBox("Необходимо указать хотя бы одну границу даты изготовления оси!");
        return;
    }
    if( m_c10.GetCheck() && !m_EdMask.GetWindowTextLength() )
    {
        AfxMessageBox("Не указана маска номера оси!");
        return;
    }
    if( m_c2.GetCheck() )
    {
        strNoFor = "1";
    } else
    if( m_c5.GetCheck() )
    {
       strNoFor = "0";
    } else
        strNoFor = "NULL";


    if( m_c3.GetCheck() || m_c6.GetCheck()) strNoRash = "1";
    else
    if( m_c4.GetCheck() ) strNoRash = "0";
    else
        strNoRash = "NULL";

    cQ.Format("pTov_BDOsSelect %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
                g_iDep,
                isAble(m_c1.GetCheck(), m_Dat1.GetSQLDate()),
                isAble(m_c1.GetCheck(), m_Dat2.GetSQLDate()),
                isAble(m_c2.GetCheck(), m_Dat3.GetSQLDate()),
                isAble(m_c2.GetCheck(), m_Dat4.GetSQLDate()),
                isAble(m_c3.GetCheck(), m_Dat5.GetSQLDate()),
                isAble(m_c3.GetCheck(), m_Dat6.GetSQLDate()),
                strNoRash,
                strNoFor,
                isNull(isAble(m_c7.GetCheck(), m_Combo1.GetItemData(m_Combo1.GetCurSel()))),
                isNull(isAble(m_c8.GetCheck(), dwPrIzg)),
                isAble(m_c9.GetCheck(), m_Dat7.GetSQLDate()),
                isAble(m_c9.GetCheck(), m_Dat8.GetSQLDate()),
                isAble(m_c10.GetCheck(), isNull(cMask)),
                isAble(m_c6.GetCheck(), isNull(dwPrPeres)));
    //AfxMessageBox(cQ);
    CDlgBDSelectRez Dlg;
    sprintf(Dlg.cQ, "%s", cQ);
    Dlg.iMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
/*
    CPrintableDlg Dlg;
    sprintf(Dlg.cQ, cQ);
    if( Dlg.DoModal() == IDCANCEL ) return;*/
	CDlgWithAccelerators::OnOK();
}

void CDlgSelectOS::OnKillfocusEdit3() 
{
    CString str;
    m_EdPeresKl.GetWindowText(str);
    if( str == "" )
    {
        dwPrPeres = 0;
        return;
    }
    char cText[255] = "";
    char cQ[128] = "";
    long Ind = 0;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwPrPeres, 4, &Ind);
    DBW.GetData( 7, SQL_C_CHAR, cText, 254, &Ind);
/*    DBW.GetData( 4, SQL_C_BIT, &lbCanForm, 1, &Ind);*/
    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        MessageBox("Введено некорректное клеймо предприятия!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdPeresKl.SetWindowText("");
        m_EdPeresPrName.SetWindowText("");
		m_EdPeresKl.SetFocus();
        return;
    }
    m_EdPeresPrName.SetWindowText(cText);		
}

void CDlgSelectOS::OnKillfocusEdit9() 
{
    CString str;
    m_EdIzgKl.GetWindowText(str);
    if( str == "" )
    {
        dwPrIzg = 0;
        return;
    }
    char cText[255] = "";
    char cQ[128] = "";
    long Ind = 0;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwPrIzg, 4, &Ind);
    DBW.GetData( 7, SQL_C_CHAR, cText, 254, &Ind);
/*    DBW.GetData( 4, SQL_C_BIT, &lbCanForm, 1, &Ind);*/
    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        MessageBox("Введено некорректное клеймо предприятия изготовления оси!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdIzgKl.SetWindowText("");
        m_EdIzgPrName.SetWindowText("");
		m_EdIzgKl.SetFocus();
        return;
    }
    m_EdIzgPrName.SetWindowText(cText);		
}
