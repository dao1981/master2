// DlgInputTrafVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgInputTrafVag.h"
#include ".\dlginputtrafvag.h"
#include "PrintableDlg.h"

// CDlgInputTrafVag dialog

IMPLEMENT_DYNAMIC(CDlgInputTrafVag, CDialog)
CDlgInputTrafVag::CDlgInputTrafVag(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInputTrafVag::IDD, pParent)
{
}

CDlgInputTrafVag::~CDlgInputTrafVag()
{
}

void CDlgInputTrafVag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_CHECK31, m_Check2);
	DDX_Control(pDX, IDC_CHECK39, m_Check3);
	DDX_Control(pDX, IDC_CHECK40, m_Check4);
	DDX_Control(pDX, IDC_CHECK41, m_Check5);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT2, m_Dat1);
	DDX_Control(pDX, IDC_EDIT7, m_Dat2);
	DDX_Control(pDX, IDC_EDIT5, m_EdESR1);
	DDX_Control(pDX, IDC_EDIT4, m_EdStan1);
	DDX_Control(pDX, IDC_EDIT120, m_EdESR2);
	DDX_Control(pDX, IDC_EDIT70, m_EdStan2);
	DDX_Control(pDX, IDC_RADIO1, m_Radio1);
	DDX_Control(pDX, IDC_RADIO4, m_Radio3);
	DDX_Control(pDX, IDC_RADIO5, m_Radio4);
	DDX_Control(pDX, IDC_RADIO6, m_Radio5);
	DDX_Control(pDX, IDC_BUTTON1, m_But1);
	DDX_Control(pDX, IDC_BUTTON2, m_But2);
	DDX_Control(pDX, IDC_RADIO2, m_Radio2);
}


BEGIN_MESSAGE_MAP(CDlgInputTrafVag, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_CHECK31, OnBnClickedCheck31)
	ON_BN_CLICKED(IDC_CHECK39, OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK40, OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK41, OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_RADIO1, OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_RADIO4, OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO5, OnBnClickedRadio4)
	ON_BN_CLICKED(IDC_RADIO6, OnBnClickedRadio5)
END_MESSAGE_MAP()

extern CString toStr(DWORD);
// CDlgInputTrafVag message handlers

void CDlgInputTrafVag::OnBnClickedOk()
{
	CPrintableDlg Dlg;
	
	int sort = 0;

	if(m_Radio3.GetCheck()) sort = 0;
	else
	if(m_Radio4.GetCheck()) sort = 1;
	else
	if(m_Radio5.GetCheck()) sort = 2;

	CString par7 = "";
	if( m_Check5.GetCheck() )
	{
		if( m_Radio1.GetCheck() )
		{
			par7 = "1";
		} else
		{
			par7 = "0";
		}
	} else
	{
		par7 = "NULL";
	}
	sprintf(Dlg.cQ, "pTov_mkcReportPptTrafVag %u, %s, %s, %s, %s, %s, %s, %d",
		g_iDep,
		isAble(m_Check1.GetCheck(), m_EdNVag.GetString(1)),
		isAble(m_Check2.GetCheck(), m_Dat1.GetSQLDate()),
		isAble(m_Check2.GetCheck(), m_Dat2.GetSQLDate()),
		isAble(m_Check3.GetCheck(), m_EdESR1.GetString(1)),
		isAble(m_Check4.GetCheck(), m_EdESR2.GetString(1)),
		par7,
		sort		
		);

	if( Dlg.DoModal() == IDCANCEL ) return;

	OnOK();
}

BOOL CDlgInputTrafVag::OnInitDialog()
{
	CDialog::OnInitDialog();

//	m_EdNVag.QInit(80, 1);
	m_EdNVag.SetMode(0,1,8);
	m_Dat1.SetMode(1, 1);
	m_Dat2.SetMode(1, 1);
	m_EdESR1.QInit(60,1);
	m_EdESR2.QInit(60,1);
	m_EdStan1.SetMode(0,1);
	m_EdStan1.SetMode(0,2);

	m_Radio1.SetCheck(1);
	m_Radio3.SetCheck(1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgInputTrafVag::OnBnClickedCheck1()
{
	m_EdNVag.EnableWindow(m_Check1.GetCheck());
	if( m_Check1.GetCheck() ) m_EdNVag.SetFocus();
}

void CDlgInputTrafVag::OnBnClickedCheck31()
{
	m_Dat1.EnableWindow(m_Check2.GetCheck());
	m_Dat2.EnableWindow(m_Check2.GetCheck());
	if(m_Check2.GetCheck()) m_Dat1.SetFocus();
}

void CDlgInputTrafVag::OnBnClickedCheck3()
{
	m_EdESR1.EnableWindow(m_Check3.GetCheck());
	m_But1.EnableWindow(m_Check3.GetCheck());
	m_EdStan1.EnableWindow(m_Check3.GetCheck());
	if( m_Check3.GetCheck() )
	{
		m_EdESR1.SetFocus();
	}
}

void CDlgInputTrafVag::OnBnClickedCheck4()
{
	m_EdESR2.EnableWindow(m_Check4.GetCheck());
	m_But2.EnableWindow(m_Check4.GetCheck());
	m_EdStan2.EnableWindow(m_Check4.GetCheck());
	if( m_Check4.GetCheck() )
	{
		m_EdESR2.SetFocus();
	}
}

void CDlgInputTrafVag::OnBnClickedCheck5()
{
	m_Radio1.EnableWindow(m_Check5.GetCheck());
	m_Radio2.EnableWindow(m_Check5.GetCheck());
}

void CDlgInputTrafVag::OnBnClickedRadio1()
{
	m_Radio1.SetCheck(1);
	m_Radio2.SetCheck(0);
}

void CDlgInputTrafVag::OnBnClickedRadio2()
{
	m_Radio1.SetCheck(0);
	m_Radio2.SetCheck(1);
}

void CDlgInputTrafVag::OnBnClickedRadio3()
{
	m_Radio3.SetCheck(1);
	m_Radio4.SetCheck(0);
	m_Radio5.SetCheck(0);
}

void CDlgInputTrafVag::OnBnClickedRadio4()
{
	m_Radio3.SetCheck(0);
	m_Radio4.SetCheck(1);
	m_Radio5.SetCheck(0);
}

void CDlgInputTrafVag::OnBnClickedRadio5()
{
	m_Radio3.SetCheck(0);
	m_Radio4.SetCheck(0);
	m_Radio5.SetCheck(1);
}
