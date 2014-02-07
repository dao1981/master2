// DlgDBOsSelect.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgDBOsSelect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgDBOsSelect dialog


CDlgDBOsSelect::CDlgDBOsSelect(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDBOsSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDBOsSelect)
	//}}AFX_DATA_INIT
}


void CDlgDBOsSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDBOsSelect)
	DDX_Control(pDX, IDC_BUTTON1, m_Bn2);
	DDX_Control(pDX, IDC_EDIT2, m_Ed4);
	DDX_Control(pDX, IDC_EDIT1, m_Ed3);
	DDX_Control(pDX, IDC_EDIT69, m_Ed2);
	DDX_Control(pDX, IDC_BUTTON3, m_Bn1);
	DDX_Control(pDX, IDC_EDIT46, m_Ed1);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_CHECK11, m_Chk4);
	DDX_Control(pDX, IDC_CHECK4, m_Chk7);
	DDX_Control(pDX, IDC_CHECK3, m_Chk6);
	DDX_Control(pDX, IDC_CHECK31, m_Chk5);
	DDX_Control(pDX, IDC_CHECK2, m_Chk3);
	DDX_Control(pDX, IDC_CHECK32, m_Chk2);
	DDX_Control(pDX, IDC_CHECK1, m_Chk1);
	DDX_Control(pDX, IDC_DATETIMEPICKER7, m_Dt7);
	DDX_Control(pDX, IDC_DATETIMEPICKER8, m_Dt8);
	DDX_Control(pDX, IDC_DATETIMEPICKER10, m_Dt6);
	DDX_Control(pDX, IDC_DATETIMEPICKER9, m_Dt5);
	DDX_Control(pDX, IDC_DATETIMEPICKER11, m_Dt4);
	DDX_Control(pDX, IDC_DATETIMEPICKER3, m_Dt3);
	DDX_Control(pDX, IDC_DATETIMEPICKER6, m_Dt2);
	DDX_Control(pDX, IDC_DATETIMEPICKER1, m_Dt1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDBOsSelect, CDialog)
	//{{AFX_MSG_MAP(CDlgDBOsSelect)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK32, OnCheck2)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK11, OnCheck4)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_CHECK31, OnCheck5)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck6)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDBOsSelect message handlers

void CDlgDBOsSelect::OnCheck1() 
{
    if( m_Chk1.GetCheck() )
    {
        m_Dt1.EnableWindow();
        m_Dt2.EnableWindow();
    }
    else
    {
        m_Dt1.EnableWindow(FALSE);
        m_Dt2.EnableWindow(FALSE);        
    }
}

void CDlgDBOsSelect::OnCheck2() 
{
    if( m_Chk2.GetCheck() )
    {
        m_Dt3.EnableWindow();
        m_Dt4.EnableWindow();
    }
    else
    {
        m_Dt3.EnableWindow(FALSE);
        m_Dt4.EnableWindow(FALSE);        
    }
}

BOOL CDlgDBOsSelect::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgDBOsSelect::OnRadio1() 
{
    CButton *bn1 = (CButton *)GetDlgItem(IDC_RADIO1);
    CButton *bn2 = (CButton *)GetDlgItem(IDC_RADIO2);
    CButton *bn3 = (CButton *)GetDlgItem(IDC_RADIO3);
    bn1->SetCheck(1);
    bn2->SetCheck(0);
    bn3->SetCheck(0);
    m_Dt5.EnableWindow();
    m_Dt6.EnableWindow();
}

void CDlgDBOsSelect::OnRadio2() 
{
    CButton *bn1 = (CButton *)GetDlgItem(IDC_RADIO1);
    CButton *bn2 = (CButton *)GetDlgItem(IDC_RADIO2);
    CButton *bn3 = (CButton *)GetDlgItem(IDC_RADIO3);
    bn1->SetCheck(0);
    bn2->SetCheck(1);
    bn3->SetCheck(0);
    m_Dt5.EnableWindow(FALSE);
    m_Dt6.EnableWindow(FALSE);
}

void CDlgDBOsSelect::OnRadio3() 
{
    CButton *bn1 = (CButton *)GetDlgItem(IDC_RADIO1);
    CButton *bn2 = (CButton *)GetDlgItem(IDC_RADIO2);
    CButton *bn3 = (CButton *)GetDlgItem(IDC_RADIO3);
    bn1->SetCheck(0);
    bn2->SetCheck(0);
    bn3->SetCheck(1);
    m_Dt5.EnableWindow(FALSE);
    m_Dt6.EnableWindow(FALSE);
}

void CDlgDBOsSelect::OnCheck3() 
{
    if( m_Chk3.GetCheck() )
        m_Combo1.EnableWindow();
    else
        m_Combo1.EnableWindow(FALSE);
}

void CDlgDBOsSelect::OnCheck4() 
{
    if( m_Chk4.GetCheck() )
    {
//        m_Ed1.EnableWindow();
        m_Bn1.EnableWindow();
//        m_Ed2.EnableWindow();
    }
    else
    {
//        m_Ed1.EnableWindow(FALSE);
        m_Bn1.EnableWindow(FALSE);
//        m_Ed2.EnableWindow(FALSE);
    }
}

void CDlgDBOsSelect::OnButton3() 
{

}

void CDlgDBOsSelect::OnCheck5() 
{
    if( m_Chk5.GetCheck() )
    {
        m_Dt7.EnableWindow();
        m_Dt8.EnableWindow();
    }
    else
    {
        m_Dt7.EnableWindow(FALSE);
        m_Dt8.EnableWindow(FALSE);        
    }	
}

void CDlgDBOsSelect::OnButton1() 
{

}

void CDlgDBOsSelect::OnCheck6() 
{
    if( m_Chk6.GetCheck() )
        m_Ed3.EnableWindow();
    else
        m_Ed3.EnableWindow(FALSE);    	
}

void CDlgDBOsSelect::OnCheck7() 
{
    if( m_Chk7.GetCheck() )
    {
//        m_Ed4.EnableWindow();
        m_Bn2.EnableWindow();
    }
    else
    {
//        m_Ed4.EnableWindow(FALSE);
        m_Bn2.EnableWindow(FALSE);
    }	
}
