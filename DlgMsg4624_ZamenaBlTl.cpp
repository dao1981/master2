// DlgMsg4624_ZamenaBlTl.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624_ZamenaBlTl.h"
#include ".\dlgmsg4624_zamenabltl.h"
#include "DlgSpravKdr.h"

// CDlgMsg4624_ZamenaBlTl dialog
extern int g_iUpDownArrowsStandart;

IMPLEMENT_DYNAMIC(CDlgMsg4624_ZamenaBlTl, CDlgWithAccelerators)
CDlgMsg4624_ZamenaBlTl::CDlgMsg4624_ZamenaBlTl(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg4624_ZamenaBlTl::IDD, pParent)
{
}

CDlgMsg4624_ZamenaBlTl::~CDlgMsg4624_ZamenaBlTl()
{
}

void CDlgMsg4624_ZamenaBlTl::DoDataExchange(CDataExchange* pDX)
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

	DDX_Control(pDX, IDC_EDIT3, m_FIO);
	DDX_Control(pDX, IDC_BUTTON5, m_bnFio);
}


BEGIN_MESSAGE_MAP(CDlgMsg4624_ZamenaBlTl, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_BUTTON5, OnBnClickedButton_FIO)
	ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
	ON_COMMAND(ID_ARROW_UP, OnArrowUp)
END_MESSAGE_MAP()


// CDlgMsg4624_ZamenaBlTl message handlers

BOOL CDlgMsg4624_ZamenaBlTl::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_pEd[0][0].QInit(10, 1);
	m_pEd[0][1].QInit(10, 1);

	m_pEd[1][0].QInit(50, 1);
	m_pEd[1][1].QInit(50, 1);

	m_pEd[2][0].QInit(140, 1);
	m_pEd[2][1].QInit(140, 1);

	m_pEd[3][0].QInit(40, 1);
	m_pEd[3][1].QInit(40, 1);

	m_pEd[4][0].QInit(50, 1);
	m_pEd[4][1].QInit(50, 1);

	m_FIO.dwFlags = ME_SCROLL_NORMAL;
	for( int i=0; i < 5; i++ )
	{
		m_pEd[i][0].dwFlags |= ME_FIRST_ROW;
		m_pEd[i][1].dwFlags |= ME_LAST_ROW;
	}

	m_FIO.SetMode(5, 1);
	DBW.FillEmplArray(m_FIO.lpEmpl, 38);
	return TRUE;  
}

void CDlgMsg4624_ZamenaBlTl::OnOK()
{
//	CDlgWithAccelerators::OnOK();
}

void CDlgMsg4624_ZamenaBlTl::OnCancel()
{
//	CDlgWithAccelerators::OnCancel();
}

void CDlgMsg4624_ZamenaBlTl::OnBnClickedButton_FIO()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 38;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_FIO.SetData(Dlg.dwFio);
	m_FIO.SetWindowText(Dlg.cFio);
}

void CDlgMsg4624_ZamenaBlTl::OnArrowDown()
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

void CDlgMsg4624_ZamenaBlTl::OnArrowUp()
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
