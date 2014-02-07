// DlgMsg4624_BlTl.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624_BlTl.h"
#include ".\dlgmsg4624_bltl.h"
#include "DlgSpravKdr.h"

// CDlgMsg4624_BlTl dialog
extern int g_iUpDownArrowsStandart;

IMPLEMENT_DYNAMIC(CDlgMsg4624_BlTl, CDlgWithAccelerators)
CDlgMsg4624_BlTl::CDlgMsg4624_BlTl(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg4624_BlTl::IDD, pParent)
{
}

CDlgMsg4624_BlTl::~CDlgMsg4624_BlTl()
{
}

void CDlgMsg4624_BlTl::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_E00, m_pEd[0][0]);
	DDX_Control(pDX, IDC_E10, m_pEd[1][0]);
	DDX_Control(pDX, IDC_E20, m_pEd[2][0]);
	DDX_Control(pDX, IDC_E30, m_pEd[3][0]);
	DDX_Control(pDX, IDC_E40, m_pEd[4][0]);

	DDX_Control(pDX, IDC_E01, m_pEd[0][1]);
	DDX_Control(pDX, IDC_E11, m_pEd[1][1]);
	DDX_Control(pDX, IDC_E21, m_pEd[2][1]);
	DDX_Control(pDX, IDC_E31, m_pEd[3][1]);
	DDX_Control(pDX, IDC_E41, m_pEd[4][1]);
	DDX_Control(pDX, IDC_EDIT3, m_EdFIO1_BLTL);
	DDX_Control(pDX, IDC_EDIT204, m_EdFIO2_BLTL);

	DDX_Control(pDX, IDC_BUTTON5, m_bnFio1);
	DDX_Control(pDX, IDC_BUTTON31, m_bnFio2);


}


BEGIN_MESSAGE_MAP(CDlgMsg4624_BlTl, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_BUTTON5, OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON31, OnBnClickedButton31)
	ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
	ON_COMMAND(ID_ARROW_UP, OnArrowUp)
END_MESSAGE_MAP()


// CDlgMsg4624_BlTl message handlers

BOOL CDlgMsg4624_BlTl::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_pEd[0][0].QInit(10, 1);
	m_pEd[0][1].QInit(10, 1);

	m_pEd[1][0].QInit(40, 1);
	m_pEd[1][1].QInit(40, 1);

	m_pEd[2][0].QInit(100, 1);
	m_pEd[2][1].QInit(100, 1);

	m_pEd[3][0].QInit(40, 1);
	m_pEd[3][1].QInit(40, 1);

	m_pEd[4][0].QInit(30, 1);
	m_pEd[4][1].QInit(30, 1);

	m_EdFIO1_BLTL.SetMode(5, 1);
	m_EdFIO2_BLTL.SetMode(5, 1);
	m_EdFIO1_BLTL.dwFlags = ME_SCROLL_NORMAL;
	m_EdFIO2_BLTL.dwFlags = ME_SCROLL_NORMAL;

	for( int i=0; i < 5; i++ )
	{
		m_pEd[i][0].dwFlags |= ME_FIRST_ROW;
		m_pEd[i][1].dwFlags |= ME_LAST_ROW;
	}

	DBW.FillEmplArray(m_EdFIO1_BLTL.lpEmpl, 0);
	DBW.FillEmplArray(m_EdFIO2_BLTL.lpEmpl, 0);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg4624_BlTl::OnCancel()
{
//	CDialog::OnCancel();
}

void CDlgMsg4624_BlTl::OnOK()
{
//	CDialog::OnOK();
}

void CDlgMsg4624_BlTl::OnBnClickedButton5()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 0;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_EdFIO1_BLTL.SetData(Dlg.dwFio);
	m_EdFIO1_BLTL.SetWindowText(Dlg.cFio);
}

void CDlgMsg4624_BlTl::OnBnClickedButton31()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 0;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_EdFIO2_BLTL.SetData(Dlg.dwFio);
	m_EdFIO2_BLTL.SetWindowText(Dlg.cFio);
}

void CDlgMsg4624_BlTl::OnArrowDown()
{
	if( g_iUpDownArrowsStandart )
	{
		CDlgWithAccelerators::OnArrowDown();
		return;
	}
	CMaskEdit *m = (CMaskEdit *)GetFocus();
	CRuntimeClass *c = m->GetRuntimeClass();
	if( !strcmp(c->m_lpszClassName, "CComboBox") ) return;
	if( strcmp(c->m_lpszClassName, "CEdit") || 
		m->dwFlags & ME_SCROLL_NORMAL ) 
	{
		CDlgWithAccelerators::OnArrowDown();
		return;
	}
	if( m->dwFlags & ME_LAST_ROW ) return;	
	m+=1;
	while( (m->GetStyle() & WS_DISABLED) && !(m->dwFlags & ME_LAST_ROW )) m+=1;
	m->SetFocus();
}

void CDlgMsg4624_BlTl::OnArrowUp()
{
	if( g_iUpDownArrowsStandart )
	{
		CDlgWithAccelerators::OnArrowUp();
		return;
	}
	CMaskEdit *m = (CMaskEdit *)GetFocus();
	CRuntimeClass *c = m->GetRuntimeClass();
	if( !strcmp(c->m_lpszClassName, "CComboBox") ) return;
	if( strcmp(c->m_lpszClassName, "CEdit") || 
		m->dwFlags & ME_SCROLL_NORMAL ) 
	{
		CDlgWithAccelerators::OnArrowUp();
		return;
	}
	if( m->dwFlags & ME_FIRST_ROW ) return;
	m-=1;
	while( (m->GetStyle() & WS_DISABLED) && !(m->dwFlags & ME_FIRST_ROW )) m-=1;
	m->SetFocus();
}
