// DlgMsg2957_1.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg2957_1.h"
#include ".\dlgmsg2957_1.h"
#include "DlgMsg2957Main.h"

// CDlgMsg2957_1 dialog
CDlgMsg2957Main *mainw;

extern int g_iUpDownArrowsStandart;

IMPLEMENT_DYNAMIC(CDlgMsg2957_1, CDlgWithAccelerators)
CDlgMsg2957_1::CDlgMsg2957_1(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg2957_1::IDD, pParent)
{
}

CDlgMsg2957_1::~CDlgMsg2957_1()
{
}

void CDlgMsg2957_1::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RR00, m_EdRas[0][0]);
	DDX_Control(pDX, IDC_RR01, m_EdRas[0][1]);
	DDX_Control(pDX, IDC_RR02, m_EdRas[0][2]);
	DDX_Control(pDX, IDC_RR03, m_EdRas[0][3]);
	DDX_Control(pDX, IDC_RR04, m_EdRas[0][4]);
	DDX_Control(pDX, IDC_RR05, m_EdRas[0][5]);
	DDX_Control(pDX, IDC_RR06, m_EdRas[0][6]);

	DDX_Control(pDX, IDC_RR10, m_EdRas[1][0]);
	DDX_Control(pDX, IDC_RR11, m_EdRas[1][1]);
	DDX_Control(pDX, IDC_RR12, m_EdRas[1][2]);
	DDX_Control(pDX, IDC_RR13, m_EdRas[1][3]);
	DDX_Control(pDX, IDC_RR14, m_EdRas[1][4]);
	DDX_Control(pDX, IDC_RR15, m_EdRas[1][5]);
	DDX_Control(pDX, IDC_RR16, m_EdRas[1][6]);

	DDX_Control(pDX, IDC_R00, m_Ed[0][0]);
	DDX_Control(pDX, IDC_R10, m_Ed[1][0]);
	DDX_Control(pDX, IDC_R20, m_Ed[2][0]);
	DDX_Control(pDX, IDC_R30, m_Ed[3][0]);
	DDX_Control(pDX, IDC_R40, m_Ed[4][0]);
	DDX_Control(pDX, IDC_R50, m_Ed[5][0]);
	DDX_Control(pDX, IDC_R60, m_Ed[6][0]);
	DDX_Control(pDX, IDC_R70, m_Ed[7][0]);
	DDX_Control(pDX, IDC_R80, m_Ed[8][0]);
	DDX_Control(pDX, IDC_R90, m_Ed[9][0]);
	
	DDX_Control(pDX, IDC_R01, m_Ed[0][1]);
	DDX_Control(pDX, IDC_R11, m_Ed[1][1]);
	DDX_Control(pDX, IDC_R21, m_Ed[2][1]);
	DDX_Control(pDX, IDC_R31, m_Ed[3][1]);
	DDX_Control(pDX, IDC_R41, m_Ed[4][1]);
	DDX_Control(pDX, IDC_R51, m_Ed[5][1]);
	DDX_Control(pDX, IDC_R61, m_Ed[6][1]);
	DDX_Control(pDX, IDC_R71, m_Ed[7][1]);
	DDX_Control(pDX, IDC_R81, m_Ed[8][1]);
	DDX_Control(pDX, IDC_R91, m_Ed[9][1]);

	DDX_Control(pDX, IDC_R02, m_Ed[0][2]);
	DDX_Control(pDX, IDC_R12, m_Ed[1][2]);
	DDX_Control(pDX, IDC_R22, m_Ed[2][2]);
	DDX_Control(pDX, IDC_R32, m_Ed[3][2]);
	DDX_Control(pDX, IDC_R42, m_Ed[4][2]);
	DDX_Control(pDX, IDC_R52, m_Ed[5][2]);
	DDX_Control(pDX, IDC_R62, m_Ed[6][2]);
	DDX_Control(pDX, IDC_R72, m_Ed[7][2]);
	DDX_Control(pDX, IDC_R82, m_Ed[8][2]);
	DDX_Control(pDX, IDC_R92, m_Ed[9][2]);

	DDX_Control(pDX, IDC_R03, m_Ed[0][3]);
	DDX_Control(pDX, IDC_R13, m_Ed[1][3]);
	DDX_Control(pDX, IDC_R23, m_Ed[2][3]);
	DDX_Control(pDX, IDC_R33, m_Ed[3][3]);
	DDX_Control(pDX, IDC_R43, m_Ed[4][3]);
	DDX_Control(pDX, IDC_R53, m_Ed[5][3]);
	DDX_Control(pDX, IDC_R63, m_Ed[6][3]);
	DDX_Control(pDX, IDC_R73, m_Ed[7][3]);
	DDX_Control(pDX, IDC_R83, m_Ed[8][3]);
	DDX_Control(pDX, IDC_R93, m_Ed[9][3]);

	DDX_Control(pDX, IDC_R04, m_Ed[0][4]);
	DDX_Control(pDX, IDC_R14, m_Ed[1][4]);
	DDX_Control(pDX, IDC_R24, m_Ed[2][4]);
	DDX_Control(pDX, IDC_R34, m_Ed[3][4]);
	DDX_Control(pDX, IDC_R44, m_Ed[4][4]);
	DDX_Control(pDX, IDC_R54, m_Ed[5][4]);
	DDX_Control(pDX, IDC_R64, m_Ed[6][4]);
	DDX_Control(pDX, IDC_R74, m_Ed[7][4]);
	DDX_Control(pDX, IDC_R84, m_Ed[8][4]);
	DDX_Control(pDX, IDC_R94, m_Ed[9][4]);

	DDX_Control(pDX, IDC_R05, m_Ed[0][5]);
	DDX_Control(pDX, IDC_R15, m_Ed[1][5]);
	DDX_Control(pDX, IDC_R25, m_Ed[2][5]);
	DDX_Control(pDX, IDC_R35, m_Ed[3][5]);
	DDX_Control(pDX, IDC_R45, m_Ed[4][5]);
	DDX_Control(pDX, IDC_R55, m_Ed[5][5]);
	DDX_Control(pDX, IDC_R65, m_Ed[6][5]);
	DDX_Control(pDX, IDC_R75, m_Ed[7][5]);
	DDX_Control(pDX, IDC_R85, m_Ed[8][5]);
	DDX_Control(pDX, IDC_R95, m_Ed[9][5]);

	DDX_Control(pDX, IDC_R06, m_Ed[0][6]);
	DDX_Control(pDX, IDC_R16, m_Ed[1][6]);
	DDX_Control(pDX, IDC_R26, m_Ed[2][6]);
	DDX_Control(pDX, IDC_R36, m_Ed[3][6]);
	DDX_Control(pDX, IDC_R46, m_Ed[4][6]);
	DDX_Control(pDX, IDC_R56, m_Ed[5][6]);
	DDX_Control(pDX, IDC_R66, m_Ed[6][6]);
	DDX_Control(pDX, IDC_R76, m_Ed[7][6]);
	DDX_Control(pDX, IDC_R86, m_Ed[8][6]);
	DDX_Control(pDX, IDC_R96, m_Ed[9][6]);

}


BEGIN_MESSAGE_MAP(CDlgMsg2957_1, CDlgWithAccelerators)
	ON_EN_CHANGE(IDC_R11, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R21, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R31, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R41, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R51, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R61, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R71, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R81, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R91, OnEnChangeSomeEdit)

	ON_EN_CHANGE(IDC_R12, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R22, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R32, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R42, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R52, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R62, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R72, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R82, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R92, OnEnChangeSomeEdit)

	ON_EN_CHANGE(IDC_R13, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R23, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R33, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R43, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R53, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R63, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R73, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R83, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R93, OnEnChangeSomeEdit)

	ON_EN_CHANGE(IDC_R14, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R24, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R34, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R44, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R54, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R64, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R74, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R84, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R94, OnEnChangeSomeEdit)

	ON_EN_CHANGE(IDC_R15, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R25, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R35, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R45, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R55, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R65, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R75, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R85, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R95, OnEnChangeSomeEdit)

	ON_EN_CHANGE(IDC_R16, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R26, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R36, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R46, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R56, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R66, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R76, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R86, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_R96, OnEnChangeSomeEdit)


	ON_COMMAND(ID_ARROW_UP, OnArrowUp)
	ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
END_MESSAGE_MAP()


// CDlgMsg2957_1 message handlers

BOOL CDlgMsg2957_1::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	for( int i=0; i < 7; i++ )
	{
		m_Ed[0][i].SetMode(0, 1);
		m_Ed[1][i].QInit(70, 1);
		m_Ed[2][i].QInit(70, 1);
		m_Ed[3][i].QInit(70, 1);
		m_Ed[4][i].QInit(60, 1);
		m_Ed[5][i].QInit(70, 1);
		m_Ed[6][i].QInit(70, 1);
		m_Ed[7][i].QInit(40, 1);
		m_Ed[8][i].QInit(70, 1);
		m_Ed[9][i].QInit(70, 1);

	}
	for( int i=0; i < 10; i++ )
	{
		m_Ed[i][1].dwFlags = ME_FIRST_ROW;
		m_Ed[i][6].dwFlags = ME_LAST_ROW;
	}
//	Tab1.SetFocus();
	this->SetFocus();
	m_Ed[1][1].SetFocus();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg2957_1::OnOK()
{
//	CDialog::OnOK();
}

void CDlgMsg2957_1::OnCancel()
{	
//	CDialog::OnCancel();
}

void CDlgMsg2957_1::OnEnChangeSomeEdit()
{
	if( mainw ) mainw->CalcSum();
}

void CDlgMsg2957_1::OnArrowUp()
{
	if( g_iUpDownArrowsStandart )
	{
		CDlgWithAccelerators::OnArrowUp();
		return;
	}
	CMaskEdit *m = (CMaskEdit *)GetFocus();
	CRuntimeClass *c = m->GetRuntimeClass();
//	if( !strcmp(c->m_lpszClassName, "CEdit") ) return;
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

void CDlgMsg2957_1::OnArrowDown()
{
	if( g_iUpDownArrowsStandart )
	{
		CDlgWithAccelerators::OnArrowDown();
		return;
	}
	CMaskEdit *m = (CMaskEdit *)GetFocus();
	CRuntimeClass *c = m->GetRuntimeClass();
//	if( strcmp(c->m_lpszClassName, "CEdit") ) return;
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
