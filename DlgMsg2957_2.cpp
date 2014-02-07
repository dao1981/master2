// DlgMsg2957_2.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg2957_2.h"
#include ".\dlgmsg2957_2.h"
#include "DlgMsg2957Main.h"

// CDlgMsg2957_2 dialog
extern CDlgMsg2957Main *mainw;
extern int g_iUpDownArrowsStandart;

IMPLEMENT_DYNAMIC(CDlgMsg2957_2, CDlgWithAccelerators)
CDlgMsg2957_2::CDlgMsg2957_2(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg2957_2::IDD, pParent)
{
}

CDlgMsg2957_2::~CDlgMsg2957_2()
{
}

void CDlgMsg2957_2::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_S00, m_Ed[0][0]);
	DDX_Control(pDX, IDC_S10, m_Ed[1][0]);
	DDX_Control(pDX, IDC_S20, m_Ed[2][0]);
	DDX_Control(pDX, IDC_S30, m_Ed[3][0]);
	DDX_Control(pDX, IDC_S40, m_Ed[4][0]);
	DDX_Control(pDX, IDC_S50, m_Ed[5][0]);
	DDX_Control(pDX, IDC_S60, m_Ed[6][0]);
	DDX_Control(pDX, IDC_S70, m_Ed[7][0]);
	DDX_Control(pDX, IDC_S80, m_Ed[8][0]);
	DDX_Control(pDX, IDC_S90, m_Ed[9][0]);
	DDX_Control(pDX, IDC_S10_0, m_Ed[10][0]);
	DDX_Control(pDX, IDC_S11__0, m_Ed[11][0]);
	DDX_Control(pDX, IDC_S12_0, m_Ed[12][0]);

	DDX_Control(pDX, IDC_S01, m_Ed[0][1]);
	DDX_Control(pDX, IDC_S11, m_Ed[1][1]);
	DDX_Control(pDX, IDC_S21, m_Ed[2][1]);
	DDX_Control(pDX, IDC_S31, m_Ed[3][1]);
	DDX_Control(pDX, IDC_S41, m_Ed[4][1]);
	DDX_Control(pDX, IDC_S51, m_Ed[5][1]);
	DDX_Control(pDX, IDC_S61, m_Ed[6][1]);
	DDX_Control(pDX, IDC_S71, m_Ed[7][1]);
	DDX_Control(pDX, IDC_S81, m_Ed[8][1]);
	DDX_Control(pDX, IDC_S91, m_Ed[9][1]);
	DDX_Control(pDX, IDC_S10_1, m_Ed[10][1]);
	DDX_Control(pDX, IDC_S11__1, m_Ed[11][1]);
	DDX_Control(pDX, IDC_S12_1, m_Ed[12][1]);

	DDX_Control(pDX, IDC_S02, m_Ed[0][2]);
	DDX_Control(pDX, IDC_S12, m_Ed[1][2]);
	DDX_Control(pDX, IDC_S22, m_Ed[2][2]);
	DDX_Control(pDX, IDC_S32, m_Ed[3][2]);
	DDX_Control(pDX, IDC_S42, m_Ed[4][2]);
	DDX_Control(pDX, IDC_S52, m_Ed[5][2]);
	DDX_Control(pDX, IDC_S62, m_Ed[6][2]);
	DDX_Control(pDX, IDC_S72, m_Ed[7][2]);
	DDX_Control(pDX, IDC_S82, m_Ed[8][2]);
	DDX_Control(pDX, IDC_S92, m_Ed[9][2]);
	DDX_Control(pDX, IDC_S10_2, m_Ed[10][2]);
	DDX_Control(pDX, IDC_S11__2, m_Ed[11][2]);
	DDX_Control(pDX, IDC_S12_2, m_Ed[12][2]);

	DDX_Control(pDX, IDC_S03, m_Ed[0][3]);
	DDX_Control(pDX, IDC_S13, m_Ed[1][3]);
	DDX_Control(pDX, IDC_S23, m_Ed[2][3]);
	DDX_Control(pDX, IDC_S33, m_Ed[3][3]);
	DDX_Control(pDX, IDC_S43, m_Ed[4][3]);
	DDX_Control(pDX, IDC_S53, m_Ed[5][3]);
	DDX_Control(pDX, IDC_S63, m_Ed[6][3]);
	DDX_Control(pDX, IDC_S73, m_Ed[7][3]);
	DDX_Control(pDX, IDC_S83, m_Ed[8][3]);
	DDX_Control(pDX, IDC_S93, m_Ed[9][3]);
	DDX_Control(pDX, IDC_S10_3, m_Ed[10][3]);
	DDX_Control(pDX, IDC_S11__3, m_Ed[11][3]);
	DDX_Control(pDX, IDC_S12_3, m_Ed[12][3]);

	DDX_Control(pDX, IDC_S04, m_Ed[0][4]);
	DDX_Control(pDX, IDC_S14, m_Ed[1][4]);
	DDX_Control(pDX, IDC_S24, m_Ed[2][4]);
	DDX_Control(pDX, IDC_S34, m_Ed[3][4]);
	DDX_Control(pDX, IDC_S44, m_Ed[4][4]);
	DDX_Control(pDX, IDC_S54, m_Ed[5][4]);
	DDX_Control(pDX, IDC_S64, m_Ed[6][4]);
	DDX_Control(pDX, IDC_S74, m_Ed[7][4]);
	DDX_Control(pDX, IDC_S84, m_Ed[8][4]);
	DDX_Control(pDX, IDC_S94, m_Ed[9][4]);
	DDX_Control(pDX, IDC_S10_4, m_Ed[10][4]);
	DDX_Control(pDX, IDC_S11__4, m_Ed[11][4]);
	DDX_Control(pDX, IDC_S12_4, m_Ed[12][4]);

	DDX_Control(pDX, IDC_S05, m_Ed[0][5]);
	DDX_Control(pDX, IDC_S15, m_Ed[1][5]);
	DDX_Control(pDX, IDC_S25, m_Ed[2][5]);
	DDX_Control(pDX, IDC_S35, m_Ed[3][5]);
	DDX_Control(pDX, IDC_S45, m_Ed[4][5]);
	DDX_Control(pDX, IDC_S55, m_Ed[5][5]);
	DDX_Control(pDX, IDC_S65, m_Ed[6][5]);
	DDX_Control(pDX, IDC_S75, m_Ed[7][5]);
	DDX_Control(pDX, IDC_S85, m_Ed[8][5]);
	DDX_Control(pDX, IDC_S95, m_Ed[9][5]);
	DDX_Control(pDX, IDC_S10_5, m_Ed[10][5]);
	DDX_Control(pDX, IDC_S11__5, m_Ed[11][5]);
	DDX_Control(pDX, IDC_S12_5, m_Ed[12][5]);

	DDX_Control(pDX, IDC_S06, m_Ed[0][6]);
	DDX_Control(pDX, IDC_S16, m_Ed[1][6]);
	DDX_Control(pDX, IDC_S26, m_Ed[2][6]);
	DDX_Control(pDX, IDC_S36, m_Ed[3][6]);
	DDX_Control(pDX, IDC_S46, m_Ed[4][6]);
	DDX_Control(pDX, IDC_S56, m_Ed[5][6]);
	DDX_Control(pDX, IDC_S66, m_Ed[6][6]);
	DDX_Control(pDX, IDC_S76, m_Ed[7][6]);
	DDX_Control(pDX, IDC_S86, m_Ed[8][6]);
	DDX_Control(pDX, IDC_S96, m_Ed[9][6]);
	DDX_Control(pDX, IDC_S10_6, m_Ed[10][6]);
	DDX_Control(pDX, IDC_S11__6, m_Ed[11][6]);
	DDX_Control(pDX, IDC_S12_6, m_Ed[12][6]);


}


BEGIN_MESSAGE_MAP(CDlgMsg2957_2, CDlgWithAccelerators)
	ON_EN_CHANGE(IDC_S11, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S21, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S31, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S41, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S51, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S61, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S71, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S81, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S91, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S10_1, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S11__1, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S12_1, OnEnChangeSomeEdit)

	ON_EN_CHANGE(IDC_S12, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S22, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S32, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S42, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S52, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S62, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S72, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S82, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S92, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S10_2, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S11__2, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S12_2, OnEnChangeSomeEdit)

	ON_EN_CHANGE(IDC_S13, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S23, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S33, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S43, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S53, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S63, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S73, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S83, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S93, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S10_3, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S11__3, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S12_3, OnEnChangeSomeEdit)

	ON_EN_CHANGE(IDC_S14, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S24, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S34, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S44, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S54, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S64, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S74, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S84, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S94, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S10_4, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S11__4, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S12_4, OnEnChangeSomeEdit)

	ON_EN_CHANGE(IDC_S15, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S25, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S35, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S45, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S55, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S65, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S75, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S85, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S95, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S10_5, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S11__5, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S12_5, OnEnChangeSomeEdit)

	ON_EN_CHANGE(IDC_S16, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S26, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S36, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S46, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S56, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S66, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S76, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S86, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S96, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S10_6, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S11__6, OnEnChangeSomeEdit)
	ON_EN_CHANGE(IDC_S12_6, OnEnChangeSomeEdit)

	ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
	ON_COMMAND(ID_ARROW_UP, OnArrowUp)
END_MESSAGE_MAP()


// CDlgMsg2957_2 message handlers

BOOL CDlgMsg2957_2::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	for( int i=0; i < 7; i++ )
	{
		m_Ed[0][i].SetMode(0, 1, 10);
		m_Ed[1][i].QInit(70, 1);
		m_Ed[2][i].QInit(60, 1);
		m_Ed[3][i].QInit(70, 1);
		m_Ed[4][i].QInit(50, 1);
		m_Ed[5][i].QInit(60, 1);
		m_Ed[6][i].QInit(50, 1);
		m_Ed[7][i].QInit(50, 1);
		m_Ed[8][i].QInit(50, 1);
		m_Ed[9][i].QInit(50, 1);
		m_Ed[10][i].QInit(50, 1);
		m_Ed[11][i].QInit(50, 1);
		m_Ed[12][i].QInit(70, 1);

	}
	for( int i=0; i < 13; i++ )
	{
		m_Ed[i][1].dwFlags = ME_FIRST_ROW;
		m_Ed[i][6].dwFlags = ME_LAST_ROW;
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg2957_2::OnOK()
{
//	CDialog::OnOK();
}

void CDlgMsg2957_2::OnCancel()
{
//	CDialog::OnCancel();
}

void CDlgMsg2957_2::OnEnChangeSomeEdit()
{
	if( mainw ) mainw->CalcSum();
}

void CDlgMsg2957_2::OnArrowDown()
{
	if( g_iUpDownArrowsStandart )
	{
		CDlgWithAccelerators::OnArrowDown();
		return;
	}
	CMaskEdit *m = (CMaskEdit *)GetFocus();
	CRuntimeClass *c = m->GetRuntimeClass();
//	if( !strcmp(c->m_lpszClassName, "CEdit") ) return;
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

void CDlgMsg2957_2::OnArrowUp()
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
