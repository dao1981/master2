// DlgRazmGroup.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRazmGroup.h"
#include "PrintableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

int x = 0;
/////////////////////////////////////////////////////////////////////////////
// CDlgRazmGroup dialog


CDlgRazmGroup::CDlgRazmGroup(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRazmGroup::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRazmGroup)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgRazmGroup::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRazmGroup)
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT4, m_EdD2);
	DDX_Control(pDX, IDC_EDIT3, m_EdD1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRazmGroup, CDialog)
	//{{AFX_MSG_MAP(CDlgRazmGroup)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_RADIO4, OnRadio4)
	ON_BN_CLICKED(IDC_RADIO5, OnRadio5)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRazmGroup message handlers

BOOL CDlgRazmGroup::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	CButton *b = (CButton*)GetDlgItem(IDC_RADIO1);
	ASSERT(b);
	b->SetCheck(1);

	m_EdD1.QInit(20);
	m_EdD2.QInit(20);

	b = (CButton*)GetDlgItem(IDC_RADIO3);

	b->SetCheck(1);
	
	m_Dat1.SetMode(1);
	m_Dat2.SetMode(1);

	x = 1;

	m_EdD1.EnableWindow(FALSE);
	m_EdD2.EnableWindow(FALSE);

//	b->

	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgRazmGroup::OnRadio1() 
{
	m_EdD1.EnableWindow(FALSE);
	m_EdD2.EnableWindow(FALSE);
	m_EdD1.SetWindowText("");
	m_EdD2.SetWindowText("");
}

void CDlgRazmGroup::OnRadio2() 
{
	m_EdD1.EnableWindow(TRUE);
	m_EdD2.EnableWindow(TRUE);
	m_EdD1.SetWindowText("");
	m_EdD2.SetWindowText("");
}

void CDlgRazmGroup::OnRadio3() 
{
/*	CButton *b = (CButton*)GetDlgItem(IDC_RADIO3);
	ASSERT(b);
	if( b->GetCheck() ) return;*/
	m_EdD1.SetWindowText("");
	m_EdD2.SetWindowText("");
	m_EdD1.QInit(20);
	m_EdD2.QInit(20);
	x = 1;
}

void CDlgRazmGroup::OnRadio4() 
{
/*	CButton *b = (CButton*)GetDlgItem(IDC_RADIO4);
	ASSERT(b);
	if( b->GetCheck() ) return;*/
	m_EdD1.SetWindowText("");
	m_EdD2.SetWindowText("");
	m_EdD1.QInit(20);
	m_EdD2.QInit(20);
	x = 2;
}

void CDlgRazmGroup::OnRadio5() 
{
/*	CButton *b = (CButton*)GetDlgItem(IDC_RADIO5);
	ASSERT(b);
	if( b->GetCheck() ) return;*/
	m_EdD1.SetWindowText("");
	m_EdD2.SetWindowText("");
	m_EdD1.QInit(31);
	m_EdD2.QInit(31);
	x = 3;
}

void CDlgRazmGroup::OnOK() 
{
	CPrintableDlg Dlg;

	CButton *b = (CButton*)GetDlgItem(IDC_RADIO1);
	CString s;
	if( b->GetCheck() )
	{
		switch (x)
		{
		case 1:
			s = "pTov_mkcReportStatRazmGr ";
			break;
		case 2:
			s = "pTov_mkcReportStatRazmObod ";
			break;
		default:
			s = "pTov_mkcReportStatRazmDisk ";
			break;
		}
		sprintf(Dlg.cQ, "%s %u, %s, %s",
				s,
				g_iDep,
				m_Dat1.GetSQLDate(), 
				m_Dat2.GetSQLDate());
	} else
	{
		sprintf(Dlg.cQ, "pTov_mkcReportNPKPRazm %u, %s, %s, %u, %s, %s",
				g_iDep,
				m_Dat1.GetSQLDate(), 
				m_Dat2.GetSQLDate(),
				x,
				m_EdD1.GetString(),
				m_EdD2.GetString());
	}

	if( Dlg.DoModal() == IDCANCEL ) return;
	CDialog::OnOK();
}
