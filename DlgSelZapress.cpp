// DlgSelZapress.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSelZapress.h"
#include "DlgSpravKdr.h"
#include "DlgSprav1.h"
#include "DlgBDSelectRez.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgSelZapress dialog


CDlgSelZapress::CDlgSelZapress(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgSelZapress::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSelZapress)
	//}}AFX_DATA_INIT
    m_Dat1.SetMode(1);
    m_Dat2.SetMode(1);
    m_Dat3.SetMode(1);
    m_Dat4.SetMode(1);
    m_Dat5.SetMode(1);
    m_Dat6.SetMode(1);
    m_Dat7.SetMode(1);
    m_Dat8.SetMode(1);
    m_EdFam.SetMode(5);
    dwIPR = 0;

}


void CDlgSelZapress::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSelZapress)
	DDX_Control(pDX, IDC_BUTTON4, m_But2);
	DDX_Control(pDX, IDC_BUTTON1, m_But1);
	DDX_Control(pDX, IDC_EDIT14, m_EdMask);
	DDX_Control(pDX, IDC_CHECK43, m_c10);
	DDX_Control(pDX, IDC_CHECK32, m_c9);
	DDX_Control(pDX, IDC_CHECK42, m_c8);
	DDX_Control(pDX, IDC_CHECK41, m_c7);
	DDX_Control(pDX, IDC_CHECK35, m_c6);
	DDX_Control(pDX, IDC_CHECK38, m_c5);
	DDX_Control(pDX, IDC_CHECK40, m_c4);
	DDX_Control(pDX, IDC_CHECK39, m_c3);
	DDX_Control(pDX, IDC_CHECK31, m_c2);
	DDX_Control(pDX, IDC_CHECK1, m_c1);
	DDX_Control(pDX, IDC_EDIT13, m_EdPrName);
	DDX_Control(pDX, IDC_EDIT3, m_EdKl);
	DDX_Control(pDX, IDC_EDIT15, m_EdFam);
	DDX_Control(pDX, IDC_EDIT70, m_Dat8);
	DDX_Control(pDX, IDC_EDIT94, m_Dat7);
	DDX_Control(pDX, IDC_EDIT4, m_Dat6);
	DDX_Control(pDX, IDC_EDIT6, m_Dat5);
	DDX_Control(pDX, IDC_EDIT5, m_Dat4);
	DDX_Control(pDX, IDC_EDIT7, m_Dat3);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_COMBO1, m_Cb1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSelZapress, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgSelZapress)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton_FAM)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton_PR)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK31, OnCheck2)
	ON_BN_CLICKED(IDC_CHECK40, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK38, OnCheck5)
	ON_BN_CLICKED(IDC_CHECK35, OnCheck6)
	ON_BN_CLICKED(IDC_CHECK41, OnCheck7)
	ON_BN_CLICKED(IDC_CHECK42, OnCheck8)
	ON_BN_CLICKED(IDC_CHECK32, OnCheck9)
	ON_BN_CLICKED(IDC_CHECK43, OnCheck10)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSelZapress message handlers

BOOL CDlgSelZapress::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
    DBW.FillComboWithTKP(&m_Cb1);
    DBW.FillEmplArray(m_EdFam.lpEmpl, 11);
    m_EdPrName.ModifyStyle(0, WS_DISABLED);
    this->SetWindowText(CString("Выборка из журнала запрессовки ") + g_strDepoSName);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSelZapress::OnButton_FAM() 
{
    CDlgSpravKdr Dlg;
    Dlg.iFilter = 11;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdFam.SetData(Dlg.dwFio);
    m_EdFam.SetWindowText(Dlg.cFio);
}

void CDlgSelZapress::OnButton_PR() 
{
    CDlgSprav1 Dlg;
    Dlg.iDlgMode = 0;
    Dlg.iDlgKind = 4;
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwIPR = Dlg.ret_dwIPR;
    m_EdPrName.SetWindowText(Dlg.cPrName);
    m_EdKl.SetWindowText(Dlg.cKodPr);
}

void CDlgSelZapress::OnCheck1() 
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

void CDlgSelZapress::OnCheck2() 
{
    if( m_c2.GetCheck() )
    {
        m_Dat3.EnableWindow();
        m_Dat4.EnableWindow();
        m_Dat3.SetFocus();
    } else
    {
        m_Dat3.EnableWindow(FALSE);
        m_Dat4.EnableWindow(FALSE);
    }	
}

void CDlgSelZapress::OnCheck4() 
{
    if( m_c4.GetCheck() )
    {
        m_Dat5.EnableWindow();
        m_Dat6.EnableWindow();
        m_c5.SetCheck(0);
        OnCheck5();
        m_Dat5.SetFocus();
    } else
    {
        m_Dat5.EnableWindow(FALSE);
        m_Dat6.EnableWindow(FALSE);
    }	
}

void CDlgSelZapress::OnCheck5() 
{
    if( m_c5.GetCheck() )
    {
        m_c4.SetCheck(0);
        OnCheck4();
    }
}

void CDlgSelZapress::OnCheck6() 
{
    if( m_c6.GetCheck() )
    {
        m_Cb1.EnableWindow();
        m_Cb1.SetFocus();
    } else
    {
        m_Cb1.EnableWindow(FALSE);
    }
}

void CDlgSelZapress::OnCheck7() 
{
    if( m_c7.GetCheck() )
    {
        m_EdKl.EnableWindow();
        m_EdPrName.EnableWindow();
        m_But1.EnableWindow();
        m_EdKl.SetFocus();
    } else
    {
        m_EdKl.EnableWindow(FALSE);
        m_EdPrName.EnableWindow(FALSE);
        m_But1.EnableWindow(FALSE);
    }	
}

void CDlgSelZapress::OnCheck8() 
{
    if( m_c8.GetCheck() )
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

void CDlgSelZapress::OnCheck9() 
{
    if( m_c9.GetCheck() )
    {
        m_EdMask.EnableWindow();
        m_EdMask.SetFocus();
    } else
    {
        m_EdMask.EnableWindow(FALSE);
    }    	
}

void CDlgSelZapress::OnCheck10() 
{
    if( m_c10.GetCheck() )
    {
        m_EdFam.EnableWindow();
        m_But2.EnableWindow();
        m_EdFam.SetFocus();
    } else
    {
        m_EdFam.EnableWindow(FALSE);
        m_But2.EnableWindow(FALSE);
    }    	
}

void CDlgSelZapress::OnOK() 
{
    CString cQ = "";

    if( m_c1.GetCheck() && m_Dat1.isNull() && m_Dat2.isNull() )
    {
        AfxMessageBox("Необходимо указать хотя бы одну границу даты прихода оси!");
        return;
    }
    if( m_c7.GetCheck() && !dwIPR )
    {
        AfxMessageBox("Не указано предприятие изготовления оси!");
        return;
    }
    if( m_c8.GetCheck() && m_Dat7.isNull() && m_Dat8.isNull() )
    {
        AfxMessageBox("Необходимо указать хотя бы одну границу даты изготовления оси!");
        return;
    }
    if( m_c9.GetCheck() && !m_EdMask.GetWindowTextLength() )
    {
        AfxMessageBox("Не указана маска номера оси!");
        return;
    }


    if( m_c6.GetCheck() && m_Cb1.GetCurSel() < 0 )
    {
        AfxMessageBox("Необходимо указать тип КП!");
        return;
    }
    CString strRash, strFor, strMask;
    if( m_c2.GetCheck() ) strFor = "1";
    else
    if( m_c3.GetCheck() ) strFor = "0";
    else strFor = "NULL";

    if( m_c4.GetCheck() ) strRash = "1";
    else
    if( m_c5.GetCheck() ) strRash = "0";
    else strRash = "NULL";

    m_EdMask.GetWindowText(strMask);

    cQ.Format("pTov_BDZapresSelect %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
        g_iDep,
        isAble(m_c1.GetCheck(), m_Dat1.GetSQLDate()),
        isAble(m_c1.GetCheck(), m_Dat2.GetSQLDate()),
        isAble(m_c2.GetCheck(), m_Dat3.GetSQLDate()),
        isAble(m_c2.GetCheck(), m_Dat4.GetSQLDate()),
        isAble(m_c4.GetCheck(), m_Dat5.GetSQLDate()),
        isAble(m_c4.GetCheck(), m_Dat6.GetSQLDate()),
        strRash,
        strFor,
        isNull(isAble(m_c6.GetCheck(), m_Cb1.GetItemData(m_Cb1.GetCurSel()))),
        isNull(isAble(m_c7.GetCheck(), dwIPR)),
        isAble(m_c8.GetCheck(), m_Dat7.GetSQLDate()),
        isAble(m_c8.GetCheck(), m_Dat8.GetSQLDate()),
        isAble(m_c9.GetCheck(), isNull(strMask)),
        isNull(isAble(m_c10.GetCheck(), m_EdFam.GetData())));

    CDlgBDSelectRez Dlg;
    sprintf(Dlg.cQ, "%s", cQ);
    Dlg.iMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;

	CDlgWithAccelerators::OnOK();
}
