// DlgMsg4624_TLVAG.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624_TLVAG.h"
#include ".\dlgmsg4624_tlvag.h"
#include "DlgSpravKdr.h"

// CDlgMsg4624_TLVAG dialog

extern int g_iUpDownArrowsStandart;

IMPLEMENT_DYNAMIC(CDlgMsg4624_TLVAG, CDlgWithAccelerators)
CDlgMsg4624_TLVAG::CDlgMsg4624_TLVAG(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg4624_TLVAG::IDD, pParent)
{
}

CDlgMsg4624_TLVAG::~CDlgMsg4624_TLVAG()
{
}

void CDlgMsg4624_TLVAG::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LAB1, m_Lab1);
	DDX_Control(pDX, IDC_LAB2, m_Lab2);
	DDX_Control(pDX, IDC_LAB3, m_Lab3);
	DDX_Control(pDX, IDC_L1, m_pL[0]);
	DDX_Control(pDX, IDC_L2, m_pL[1]);
	DDX_Control(pDX, IDC_L3, m_pL[2]);
	DDX_Control(pDX, IDC_L4, m_pL[3]);
	DDX_Control(pDX, IDC_L5, m_pL[4]);
	DDX_Control(pDX, IDC_L6, m_pL[5]);
	DDX_Control(pDX, IDC_L7, m_pL[6]);
	DDX_Control(pDX, IDC_L8, m_pL[7]);

	DDX_Control(pDX, IDC_EDIT4, m_EdFIO1_LDTL);
	DDX_Control(pDX, IDC_EDIT120, m_EdFIO2_LDTL);

	DDX_Control(pDX, IDC_A00, m_p[0][0]);
	DDX_Control(pDX, IDC_A20, m_p[1][0]);
	DDX_Control(pDX, IDC_A30, m_p[2][0]);
	DDX_Control(pDX, IDC_A40, m_p[3][0]);
	DDX_Control(pDX, IDC_A50, m_p[4][0]);
	DDX_Control(pDX, IDC_A60, m_p[5][0]);
	DDX_Control(pDX, IDC_A70, m_p[6][0]);
	DDX_Control(pDX, IDC_A80, m_p[7][0]);

	DDX_Control(pDX, IDC_A01, m_p[0][1]);
	DDX_Control(pDX, IDC_A21, m_p[1][1]);
	DDX_Control(pDX, IDC_A31, m_p[2][1]);
	DDX_Control(pDX, IDC_A41, m_p[3][1]);
	DDX_Control(pDX, IDC_A51, m_p[4][1]);
	DDX_Control(pDX, IDC_A61, m_p[5][1]);
	DDX_Control(pDX, IDC_A71, m_p[6][1]);
	DDX_Control(pDX, IDC_A81, m_p[7][1]);

	DDX_Control(pDX, IDC_A02, m_p[0][2]);
	DDX_Control(pDX, IDC_A22, m_p[1][2]);
	DDX_Control(pDX, IDC_A32, m_p[2][2]);
	DDX_Control(pDX, IDC_A42, m_p[3][2]);
	DDX_Control(pDX, IDC_A52, m_p[4][2]);
	DDX_Control(pDX, IDC_A62, m_p[5][2]);
	DDX_Control(pDX, IDC_A72, m_p[6][2]);
	DDX_Control(pDX, IDC_A82, m_p[7][2]);

	DDX_Control(pDX, IDC_A03, m_p[0][3]);
	DDX_Control(pDX, IDC_A23, m_p[1][3]);
	DDX_Control(pDX, IDC_A33, m_p[2][3]);
	DDX_Control(pDX, IDC_A43, m_p[3][3]);
	DDX_Control(pDX, IDC_A53, m_p[4][3]);
	DDX_Control(pDX, IDC_A63, m_p[5][3]);
	DDX_Control(pDX, IDC_A73, m_p[6][3]);
	DDX_Control(pDX, IDC_A83, m_p[7][3]);

// here we go with new edits

	DDX_Control(pDX, IDC_A04, m_p[0][4]);
	DDX_Control(pDX, IDC_A24, m_p[1][4]);
	DDX_Control(pDX, IDC_A34, m_p[2][4]);
	DDX_Control(pDX, IDC_A44, m_p[3][4]);
	DDX_Control(pDX, IDC_A54, m_p[4][4]);
	DDX_Control(pDX, IDC_A64, m_p[5][4]);
	DDX_Control(pDX, IDC_A74, m_p[6][4]);
	DDX_Control(pDX, IDC_A84, m_p[7][4]);

	DDX_Control(pDX, IDC_A05, m_p[0][5]);
	DDX_Control(pDX, IDC_A25, m_p[1][5]);
	DDX_Control(pDX, IDC_A35, m_p[2][5]);
	DDX_Control(pDX, IDC_A45, m_p[3][5]);
	DDX_Control(pDX, IDC_A55, m_p[4][5]);
	DDX_Control(pDX, IDC_A65, m_p[5][5]);
	DDX_Control(pDX, IDC_A75, m_p[6][5]);
	DDX_Control(pDX, IDC_A85, m_p[7][5]);

	DDX_Control(pDX, IDC_A06, m_p[0][6]);
	DDX_Control(pDX, IDC_A26, m_p[1][6]);
	DDX_Control(pDX, IDC_A36, m_p[2][6]);
	DDX_Control(pDX, IDC_A46, m_p[3][6]);
	DDX_Control(pDX, IDC_A56, m_p[4][6]);
	DDX_Control(pDX, IDC_A66, m_p[5][6]);
	DDX_Control(pDX, IDC_A76, m_p[6][6]);
	DDX_Control(pDX, IDC_A86, m_p[7][6]);

	DDX_Control(pDX, IDC_A07, m_p[0][7]);
	DDX_Control(pDX, IDC_A27, m_p[1][7]);
	DDX_Control(pDX, IDC_A37, m_p[2][7]);
	DDX_Control(pDX, IDC_A47, m_p[3][7]);
	DDX_Control(pDX, IDC_A57, m_p[4][7]);
	DDX_Control(pDX, IDC_A67, m_p[5][7]);
	DDX_Control(pDX, IDC_A77, m_p[6][7]);
	DDX_Control(pDX, IDC_A87, m_p[7][7]);


	DDX_Control(pDX, IDC_BUTTON2, m_bnFio1);
	DDX_Control(pDX, IDC_BUTTON3, m_bnFio2);
}



BEGIN_MESSAGE_MAP(CDlgMsg4624_TLVAG, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton_FIO1)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton_FIO2)
	ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
	ON_COMMAND(ID_ARROW_UP, OnArrowUp)
END_MESSAGE_MAP()


// CDlgMsg4624_TLVAG message handlers

void CDlgMsg4624_TLVAG::OnOK()
{
//	CDlgWithAccelerators::OnOK();
}

void CDlgMsg4624_TLVAG::OnCancel()
{
//	CDlgWithAccelerators::OnCancel();
}

BOOL CDlgMsg4624_TLVAG::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_EdFIO1_LDTL.SetMode(5);
	DBW.FillEmplArray(m_EdFIO1_LDTL.lpEmpl, 17);

	m_EdFIO2_LDTL.SetMode(5);
	DBW.FillEmplArray(m_EdFIO2_LDTL.lpEmpl, 38);
	m_EdFIO1_LDTL.bColored = 1;
	m_EdFIO2_LDTL.bColored = 1;

	for( int i=0; i < 8; i++ )
	{		
			m_p[1][i].SetMode(0, 1, 3);
			m_p[2][i].SetMode(0, 1, 3);
			m_p[3][i].QInit(20,1);
			m_p[4][i].QInit(20,1);
			m_p[5][i].QInit(20,1);
			m_p[6][i].QInit(20,1);
			m_p[7][i].QInit(20,1);

	}
	for( int i=0; i < 8; i++ )
	{
		m_p[i][0].dwFlags |= ME_FIRST_ROW;
		m_p[i][7].dwFlags |= ME_LAST_ROW;
	}
	m_p[0][0].SetWindowText("Левая");
	m_p[0][2].SetWindowText("Левая");
	m_p[0][4].SetWindowText("Левая");
	m_p[0][6].SetWindowText("Левая");

//	m_p[0][4].SetWindowText("Левая");

	m_p[0][1].SetWindowText("Правая");
	m_p[0][3].SetWindowText("Правая");
	m_p[0][5].SetWindowText("Правая");
	m_p[0][7].SetWindowText("Правая");

	for( int i=0; i < 8; i++ )
	{
		m_p[0][i].ModifyStyle(0, WS_DISABLED, 0);
		m_pL[i].QInit(10,1);
	}
	m_pL[0].dwFlags = ME_FIRST_ROW;
	m_pL[8].dwFlags = ME_LAST_ROW;
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg4624_TLVAG::OnBnClickedButton_FIO1()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 17;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_EdFIO1_LDTL.SetData(Dlg.dwFio);
	m_EdFIO1_LDTL.SetWindowText(Dlg.cFio);
}

void CDlgMsg4624_TLVAG::OnBnClickedButton_FIO2()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 38;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_EdFIO2_LDTL.SetData(Dlg.dwFio);
	m_EdFIO2_LDTL.SetWindowText(Dlg.cFio);
}

void CDlgMsg4624_TLVAG::OnArrowDown()
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

void CDlgMsg4624_TLVAG::OnArrowUp()
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
