// DlgMsg4624_ZamenaLDTL.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624_ZamenaLDTL.h"
#include ".\dlgmsg4624_zamenaldtl.h"
#include "DlgSpravKdr.h"

// CDlgMsg4624_ZamenaLDTL dialog
extern int g_iUpDownArrowsStandart;

IMPLEMENT_DYNAMIC(CDlgMsg4624_ZamenaLDTL, CDlgWithAccelerators)
CDlgMsg4624_ZamenaLDTL::CDlgMsg4624_ZamenaLDTL(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg4624_ZamenaLDTL::IDD, pParent)
	, rrr(0)
{
}

CDlgMsg4624_ZamenaLDTL::~CDlgMsg4624_ZamenaLDTL()
{
}

void CDlgMsg4624_ZamenaLDTL::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LABS1, m_Lab1);
	DDX_Control(pDX, IDC_LABS2, m_Lab2);
	DDX_Control(pDX, IDC_LABS3, m_Lab3);
	DDX_Control(pDX, IDC_LABS4, m_Lab4);
	//	DDX_Control(pDX, IDC_E10, m_p);

	DDX_Control(pDX, IDC_E00, m_Num[0]);
	DDX_Control(pDX, IDC_E03, m_Num[1]);

	DDX_Control(pDX, IDC_E10, m_p[1][0]);
	DDX_Control(pDX, IDC_E20, m_p[2][0]);
	DDX_Control(pDX, IDC_E30, m_p[3][0]);
	DDX_Control(pDX, IDC_E40, m_p[4][0]);
	DDX_Control(pDX, IDC_E50, m_p[5][0]);
	DDX_Control(pDX, IDC_E60, m_p[6][0]);
	DDX_Control(pDX, IDC_E11_0, m_p[7][0]);
	DDX_Control(pDX, IDC_E12_0, m_p[8][0]);
	DDX_Control(pDX, IDC_E13_0, m_p[9][0]);
	DDX_Control(pDX, IDC_E14_0, m_p[10][0]);

	DDX_Control(pDX, IDC_E11, m_p[1][1]);
	DDX_Control(pDX, IDC_E21, m_p[2][1]);
	DDX_Control(pDX, IDC_E31, m_p[3][1]);
	DDX_Control(pDX, IDC_E41, m_p[4][1]);
	DDX_Control(pDX, IDC_E51, m_p[5][1]);
	DDX_Control(pDX, IDC_E61, m_p[6][1]);
	DDX_Control(pDX, IDC_E11_1, m_p[7][1]);
	DDX_Control(pDX, IDC_E12_1, m_p[8][1]);
	DDX_Control(pDX, IDC_E13_1, m_p[9][1]);
	DDX_Control(pDX, IDC_E14_1, m_p[10][1]);

	DDX_Control(pDX, IDC_E12, m_p[1][2]);
	DDX_Control(pDX, IDC_E22, m_p[2][2]);
	DDX_Control(pDX, IDC_E32, m_p[3][2]);
	DDX_Control(pDX, IDC_E42, m_p[4][2]);
	DDX_Control(pDX, IDC_E52, m_p[5][2]);
	DDX_Control(pDX, IDC_E62, m_p[6][2]);
	DDX_Control(pDX, IDC_E11_2, m_p[7][2]);
	DDX_Control(pDX, IDC_E12_2, m_p[8][2]);
	DDX_Control(pDX, IDC_E13_2, m_p[9][2]);
	DDX_Control(pDX, IDC_E14_2, m_p[10][2]);

	DDX_Control(pDX, IDC_E13, m_p[1][3]);
	DDX_Control(pDX, IDC_E23, m_p[2][3]);
	DDX_Control(pDX, IDC_E33, m_p[3][3]);
	DDX_Control(pDX, IDC_E43, m_p[4][3]);
	DDX_Control(pDX, IDC_E53, m_p[5][3]);
	DDX_Control(pDX, IDC_E63, m_p[6][3]);
	DDX_Control(pDX, IDC_E11_3, m_p[7][3]);
	DDX_Control(pDX, IDC_E12_3, m_p[8][3]);
	DDX_Control(pDX, IDC_E13_3, m_p[9][3]);
	DDX_Control(pDX, IDC_E14_3, m_p[10][3]);

	DDX_Control(pDX, IDC_E14, m_p[1][4]);
	DDX_Control(pDX, IDC_E24, m_p[2][4]);
	DDX_Control(pDX, IDC_E34, m_p[3][4]);
	DDX_Control(pDX, IDC_E44, m_p[4][4]);
	DDX_Control(pDX, IDC_E54, m_p[5][4]);
	DDX_Control(pDX, IDC_E64, m_p[6][4]);
	DDX_Control(pDX, IDC_E11_4, m_p[7][4]);
	DDX_Control(pDX, IDC_E12_4, m_p[8][4]);
	DDX_Control(pDX, IDC_E13_4, m_p[9][4]);
	DDX_Control(pDX, IDC_E14_4, m_p[10][4]);

	DDX_Control(pDX, IDC_E15, m_p[1][5]);
	DDX_Control(pDX, IDC_E25, m_p[2][5]);
	DDX_Control(pDX, IDC_E35, m_p[3][5]);
	DDX_Control(pDX, IDC_E45, m_p[4][5]);
	DDX_Control(pDX, IDC_E55, m_p[5][5]);
	DDX_Control(pDX, IDC_E65, m_p[6][5]);
	DDX_Control(pDX, IDC_E11_5, m_p[7][5]);
	DDX_Control(pDX, IDC_E12_5, m_p[8][5]);
	DDX_Control(pDX, IDC_E13_5, m_p[9][5]);
	DDX_Control(pDX, IDC_E14_5, m_p[10][5]);

	DDX_Control(pDX, IDC_COMBO1, m_c[0]);
	DDX_Control(pDX, IDC_COMBO2, m_c[1]);
	DDX_Control(pDX, IDC_COMBO20, m_c[2]);
	DDX_Control(pDX, IDC_COMBO23, m_c[3]);
	DDX_Control(pDX, IDC_COMBO25, m_c[4]);
	DDX_Control(pDX, IDC_COMBO26, m_c[5]);
	DDX_Control(pDX, IDC_EDIT202, m_FIO);
	DDX_Control(pDX, IDC_BUTTON3, m_bn8Os);
	DDX_Control(pDX, IDC_BUTTON29, m_bnFio);
}


BEGIN_MESSAGE_MAP(CDlgMsg4624_ZamenaLDTL, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_BUTTON29, OnBnClickedButton_FIO)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnCbnSelchangeCombo_1)
	ON_CBN_SELCHANGE(IDC_COMBO20, OnCbnSelchangeCombo_2)
	ON_CBN_SELCHANGE(IDC_COMBO25, OnCbnSelchangeCombo_4)
	ON_CBN_SELCHANGE(IDC_COMBO26, OnCbnSelchangeCombo_5)
	ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
	ON_COMMAND(ID_ARROW_UP, OnArrowUp)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton_8OS)
END_MESSAGE_MAP()


// CDlgMsg4624_ZamenaLDTL message handlers

void CDlgMsg4624_ZamenaLDTL::OnOK()
{
//	CDlgWithAccelerators::OnOK();
}

void CDlgMsg4624_ZamenaLDTL::OnCancel()
{
//	CDlgWithAccelerators::OnCancel();
}

BOOL CDlgMsg4624_ZamenaLDTL::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();


	for( int j=0; j < 6; j++ )
	{
		m_p[2][j].QInit(20, 1);
		m_p[3][j].QInit(40, 1);
		m_p[4][j].QInit(100, 1);
		m_p[5][j].QInit(40, 1);
		m_p[6][j].QInit(40, 1);
		m_p[7][j].QInit(40, 1);
		m_p[8][j].QInit(40, 1);
		m_p[9][j].QInit(10, 1);
		m_p[10][j].QInit(30, 1);
//			m_p[i][j].bColored = TRUE;
	}
	m_Num[0].QInit(10,1);
	m_Num[1].QInit(10,1);

	m_p[1][0].SetWindowText("Надр. балка");
	m_p[1][1].SetWindowText("Бок. рама");
	m_p[1][2].SetWindowText("Бок. рама");

	m_p[1][3].SetWindowText("Надр. балка");
	m_p[1][4].SetWindowText("Бок. рама");
	m_p[1][5].SetWindowText("Бок. рама");

	m_p[1][0].ModifyStyle(0, WS_DISABLED);
	m_p[1][1].ModifyStyle(0, WS_DISABLED);
	m_p[1][2].ModifyStyle(0, WS_DISABLED);
	m_p[1][3].ModifyStyle(0, WS_DISABLED);
	m_p[1][4].ModifyStyle(0, WS_DISABLED);
	m_p[1][5].ModifyStyle(0, WS_DISABLED);

	for(int i = 1; i < 6; i++ )
	{
		if( i == 3 ) continue;
		m_c[i].AddString("Лев.");
		m_c[i].AddString("Прав.");
		m_c[i].SetItemData(0, 0);
		m_c[i].SetItemData(1, 1);		
	}

	m_c[1].SetCurSel(1);
	m_c[2].SetCurSel(0);
	m_c[4].SetCurSel(1);
	m_c[5].SetCurSel(0);

	m_Num[0].dwFlags = ME_FIRST_ROW;
	m_Num[1].dwFlags = ME_LAST_ROW;

	for( int i=2; i < 11; i++ )
	{
		m_p[i][0].dwFlags = ME_FIRST_ROW;
		m_p[i][5].dwFlags = ME_LAST_ROW;
	}

	m_FIO.SetMode(5, 1);
	DBW.FillEmplArray(m_FIO.lpEmpl, 38);
	m_FIO.dwFlags = ME_SCROLL_NORMAL;
	
	m_Num[0].dwFlags = ME_FIRST_ROW;
	m_Num[1].dwFlags = ME_LAST_ROW;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg4624_ZamenaLDTL::OnBnClickedButton_FIO()
{
	CDlgSpravKdr Dlg;
	Dlg.DlgMode = 1;
	Dlg.iFilter = 38;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_FIO.SetData(Dlg.dwFio);
	m_FIO.SetWindowText(Dlg.cFio);
}

void CDlgMsg4624_ZamenaLDTL::OnCbnSelchangeCombo_1()
{
	m_c[2].SetCurSel(!m_c[1].GetCurSel());
}

void CDlgMsg4624_ZamenaLDTL::OnCbnSelchangeCombo_2()
{
	m_c[1].SetCurSel(!m_c[2].GetCurSel());
}

void CDlgMsg4624_ZamenaLDTL::OnCbnSelchangeCombo_4()
{
	m_c[5].SetCurSel(!m_c[4].GetCurSel());
}

void CDlgMsg4624_ZamenaLDTL::OnCbnSelchangeCombo_5()
{
	m_c[4].SetCurSel(!m_c[5].GetCurSel());
}

void CDlgMsg4624_ZamenaLDTL::OnArrowDown()
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

void CDlgMsg4624_ZamenaLDTL::OnArrowUp()
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

void CDlgMsg4624_ZamenaLDTL::OnBnClickedButton_8OS()
{
	//SWAP Buffers
	int shift = 6 * m_BackBuffer.iScreenPage;
	m_BackBuffer.p_strNum[2* m_BackBuffer.iScreenPage ] = m_Num[0].GetText();
	m_BackBuffer.p_strNum[1 + 2* m_BackBuffer.iScreenPage ] = m_Num[1].GetText();

	for( int i=1; i < 11; i++ )
	{
		for( int j=0; j < 6; j++ )
		{
			m_BackBuffer.str_p[i][j + shift] = m_p[i][j].GetText();
		}
	}
	for( int i=0; i < 6; i++ )
		m_BackBuffer.p_iComboIndex[i + shift] = m_c[i].GetCurSel();
 
	m_BackBuffer.iScreenPage = !m_BackBuffer.iScreenPage;
	shift = 6 * m_BackBuffer.iScreenPage;


	m_Num[0].SetWindowText(m_BackBuffer.p_strNum[2* m_BackBuffer.iScreenPage]);
	m_Num[1].SetWindowText(m_BackBuffer.p_strNum[1 + 2* m_BackBuffer.iScreenPage]);

	for( int i=2; i < 11; i++ )
	{
		for( int j=0; j < 6; j++ )
		{
			m_p[i][j].SetWindowText(m_BackBuffer.str_p[i][j + shift]);
		}
	}

	for( int i=0; i < 6; i++ )
		m_c[i].SetCurSel(m_BackBuffer.p_iComboIndex[i + shift]);
}

void CDlgMsg4624_ZamenaLDTL::StoreValues(void)
{
	int shift = 6 * m_BackBuffer.iScreenPage;
	m_BackBuffer.p_strNum[2* m_BackBuffer.iScreenPage ] = m_Num[0].GetText();
	m_BackBuffer.p_strNum[1 + 2* m_BackBuffer.iScreenPage ] = m_Num[1].GetText();

	for( int i=0; i < 6; i++ )
		m_BackBuffer.p_iComboIndex[i + shift] = m_c[i].GetCurSel();

	for( int i=1; i < 11; i++ )
	{
		for( int j=0; j < 6; j++ )
		{
			m_BackBuffer.str_p[i][j + shift] = m_p[i][j].GetText();
		}
	}
}

void CDlgMsg4624_ZamenaLDTL::DrawBuffer(int page)
{
	int shift = 6 * page;

	m_Num[0].SetWindowText(m_BackBuffer.p_strNum[2* page]);
	m_Num[1].SetWindowText(m_BackBuffer.p_strNum[1 + 2* page]);

	for( int i=2; i < 11; i++ )
	{
		for( int j=0; j < 6; j++ )
		{
			m_p[i][j].SetWindowText(m_BackBuffer.str_p[i][j + shift]);
		}
	}

	for( int i=0; i < 6; i++ )
		m_c[i].SetCurSel(m_BackBuffer.p_iComboIndex[i + shift]);
}
