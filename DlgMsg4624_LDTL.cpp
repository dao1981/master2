// DlgMsg4624_LDTL.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624_LDTL.h"
#include ".\dlgmsg4624_ldtl.h"
#include "DlgAccel1.h"
#include "DlgSpravKdr.h"
#include "MaskEdit.h"
#include "DlgMsg4624_Main.h"
// CDlgMsg4624_LDTL dialog

extern int g_iUpDownArrowsStandart;
CDlgMsg4624_Main *mn = NULL;
CLDTLFormBuffer::CLDTLFormBuffer()
{
	p_strNum[0] = p_strNum[1] = p_strNum[2] = p_strNum[3] = "";
	for( int i=0; i < 14; i++ )
	{
		for( int j=0; j < 12; j++ )
		{
			str_p[i][j] = "";
		}
	}
	iScreenPage = 0;
	for( int i=0; i < 12; i++ )
	{
		p_iComboIndex[i] = 0;
	}
}

IMPLEMENT_DYNAMIC(CDlgMsg4624_LDTL, CDlgWithAccelerators)
CDlgMsg4624_LDTL::CDlgMsg4624_LDTL(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg4624_LDTL::IDD, pParent)
{
}

CDlgMsg4624_LDTL::~CDlgMsg4624_LDTL()
{
}

void CDlgMsg4624_LDTL::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);


	DDX_Control(pDX, IDC_BUTTON3, m_8OsButton);
	DDX_Control(pDX, IDC_EDIT202, m_FIO1);
	DDX_Control(pDX, IDC_EDIT204, m_FIO2);


	DDX_Control(pDX, IDC_LABS1, m_Lab1);
	DDX_Control(pDX, IDC_LABS2, m_Lab2);
	DDX_Control(pDX, IDC_LABS3, m_Lab3);
	DDX_Control(pDX, IDC_LABS5, m_Lab5);

	DDX_Control(pDX, IDC_BUTTON4, m_ButIz1);
	DDX_Control(pDX, IDC_BUTTON6, m_ButIz2);
	DDX_Control(pDX, IDC_BUTTON7, m_ButIz3);
	DDX_Control(pDX, IDC_BUTTON67, m_ButIz4);
	DDX_Control(pDX, IDC_BUTTON9, m_ButIz5);
	DDX_Control(pDX, IDC_BUTTON25, m_ButIz6);

	DDX_Control(pDX, IDC_E00, m_Num[0]);
	DDX_Control(pDX, IDC_E10, m_p[1][0]);
	DDX_Control(pDX, IDC_E20, m_p[2][0]);
	DDX_Control(pDX, IDC_E30, m_p[3][0]);
	DDX_Control(pDX, IDC_E40, m_p[4][0]);
	DDX_Control(pDX, IDC_E50, m_p[5][0]);
	DDX_Control(pDX, IDC_E60, m_p[6][0]);
	DDX_Control(pDX, IDC_E70, m_p[7][0]);
	DDX_Control(pDX, IDC_E80, m_p[8][0]);
	DDX_Control(pDX, IDC_E90, m_p[9][0]);
	DDX_Control(pDX, IDC_E10_0, m_p[10][0]);
	DDX_Control(pDX, IDC_E11_0, m_p[11][0]);
	DDX_Control(pDX, IDC_E12_0, m_p[12][0]);
	DDX_Control(pDX, IDC_E13_0, m_p[13][0]);

	DDX_Control(pDX, IDC_E11, m_p[1][1]);
	DDX_Control(pDX, IDC_E21, m_p[2][1]);
	DDX_Control(pDX, IDC_E31, m_p[3][1]);
	DDX_Control(pDX, IDC_E41, m_p[4][1]);
	DDX_Control(pDX, IDC_E51, m_p[5][1]);
	DDX_Control(pDX, IDC_E61, m_p[6][1]);
	DDX_Control(pDX, IDC_E71, m_p[7][1]);
	DDX_Control(pDX, IDC_E81, m_p[8][1]);
	DDX_Control(pDX, IDC_E91, m_p[9][1]);
	DDX_Control(pDX, IDC_E10_1, m_p[10][1]);
	DDX_Control(pDX, IDC_E11_1, m_p[11][1]);
	DDX_Control(pDX, IDC_E12_1, m_p[12][1]);
	DDX_Control(pDX, IDC_E13_1, m_p[13][1]);

	DDX_Control(pDX, IDC_E12, m_p[1][2]);
	DDX_Control(pDX, IDC_E22, m_p[2][2]);
	DDX_Control(pDX, IDC_E32, m_p[3][2]);
	DDX_Control(pDX, IDC_E42, m_p[4][2]);
	DDX_Control(pDX, IDC_E52, m_p[5][2]);
	DDX_Control(pDX, IDC_E62, m_p[6][2]);
	DDX_Control(pDX, IDC_E72, m_p[7][2]);
	DDX_Control(pDX, IDC_E82, m_p[8][2]);
	DDX_Control(pDX, IDC_E92, m_p[9][2]);
	DDX_Control(pDX, IDC_E10_2, m_p[10][2]);
	DDX_Control(pDX, IDC_E11_2, m_p[11][2]);
	DDX_Control(pDX, IDC_E12_2, m_p[12][2]);
	DDX_Control(pDX, IDC_E13_2, m_p[13][2]);

	DDX_Control(pDX, IDC_E03, m_Num[1]);
	DDX_Control(pDX, IDC_E13, m_p[1][3]);
	DDX_Control(pDX, IDC_E23, m_p[2][3]);
	DDX_Control(pDX, IDC_E33, m_p[3][3]);
	DDX_Control(pDX, IDC_E43, m_p[4][3]);
	DDX_Control(pDX, IDC_E53, m_p[5][3]);
	DDX_Control(pDX, IDC_E63, m_p[6][3]);
	DDX_Control(pDX, IDC_E73, m_p[7][3]);
	DDX_Control(pDX, IDC_E83, m_p[8][3]);
	DDX_Control(pDX, IDC_E93, m_p[9][3]);
	DDX_Control(pDX, IDC_E10_3, m_p[10][3]);
	DDX_Control(pDX, IDC_E11_3, m_p[11][3]);
	DDX_Control(pDX, IDC_E12_3, m_p[12][3]);
	DDX_Control(pDX, IDC_E13_3, m_p[13][3]);

	DDX_Control(pDX, IDC_E14, m_p[1][4]);
	DDX_Control(pDX, IDC_E24, m_p[2][4]);
	DDX_Control(pDX, IDC_E34, m_p[3][4]);
	DDX_Control(pDX, IDC_E44, m_p[4][4]);
	DDX_Control(pDX, IDC_E54, m_p[5][4]);
	DDX_Control(pDX, IDC_E64, m_p[6][4]);
	DDX_Control(pDX, IDC_E74, m_p[7][4]);
	DDX_Control(pDX, IDC_E84, m_p[8][4]);
	DDX_Control(pDX, IDC_E94, m_p[9][4]);
	DDX_Control(pDX, IDC_E10_4, m_p[10][4]);
	DDX_Control(pDX, IDC_E11_4, m_p[11][4]);
	DDX_Control(pDX, IDC_E12_4, m_p[12][4]);
	DDX_Control(pDX, IDC_E13_4, m_p[13][4]);

	DDX_Control(pDX, IDC_E15, m_p[1][5]);
	DDX_Control(pDX, IDC_E25, m_p[2][5]);
	DDX_Control(pDX, IDC_E35, m_p[3][5]);
	DDX_Control(pDX, IDC_E45, m_p[4][5]);
	DDX_Control(pDX, IDC_E55, m_p[5][5]);
	DDX_Control(pDX, IDC_E65, m_p[6][5]);
	DDX_Control(pDX, IDC_E75, m_p[7][5]);
	DDX_Control(pDX, IDC_E85, m_p[8][5]);
	DDX_Control(pDX, IDC_E95, m_p[9][5]);
	DDX_Control(pDX, IDC_E10_5, m_p[10][5]);
	DDX_Control(pDX, IDC_E11_5, m_p[11][5]);
	DDX_Control(pDX, IDC_E12_5, m_p[12][5]);
	DDX_Control(pDX, IDC_E13_5, m_p[13][5]);

	DDX_Control(pDX, IDC_COMBO1, m_c[0]);
	DDX_Control(pDX, IDC_COMBO21, m_c[1]);
	DDX_Control(pDX, IDC_COMBO20, m_c[2]);
	DDX_Control(pDX, IDC_COMBO23, m_c[3]);
	DDX_Control(pDX, IDC_COMBO25, m_c[4]);
	DDX_Control(pDX, IDC_COMBO26, m_c[5]);

	DDX_Control(pDX, IDC_BUTTON29, m_bnFio1);
	DDX_Control(pDX, IDC_BUTTON31, m_bnFio2);
}


BEGIN_MESSAGE_MAP(CDlgMsg4624_LDTL, CDlgWithAccelerators)
	ON_STN_CLICKED(IDC_LABS1, OnStnClickedLabs1)
	ON_CBN_SELCHANGE(IDC_COMBO23, OnCbnSelchangeCombo23)
	ON_BN_CLICKED(IDC_BUTTON29, OnBnClickedButton29)
	ON_CBN_SELCHANGE(IDC_COMBO21, OnCbnSelchangeCombo_1)
	ON_CBN_SELCHANGE(IDC_COMBO20, OnCbnSelchangeCombo_2)
	ON_CBN_SELCHANGE(IDC_COMBO25, OnCbnSelchangeCombo_4)
	ON_CBN_SELCHANGE(IDC_COMBO26, OnCbnSelchangeCombo_5)
	ON_BN_CLICKED(IDC_BUTTON31, OnBnClickedButton31)
	ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
	ON_COMMAND(ID_ARROW_UP, OnArrowUp)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgMsg4624_LDTL::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlgMsg4624_LDTL::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlgMsg4624_LDTL::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON67, &CDlgMsg4624_LDTL::OnBnClickedButton67)
	ON_BN_CLICKED(IDC_BUTTON9, &CDlgMsg4624_LDTL::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON25, &CDlgMsg4624_LDTL::OnBnClickedButton25)
	ON_EN_CHANGE(IDC_E13_0, &CDlgMsg4624_LDTL::OnEnChangeE130)
END_MESSAGE_MAP()


// CDlgMsg4624_LDTL message handlers

void CDlgMsg4624_LDTL::OnStnClickedLabs1()
{
	// TODO: Add your control notification handler code here
}

BOOL CDlgMsg4624_LDTL::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	// TODO:  Add extra initialization here
	for( int j=0; j < 6; j++ )
	{
		m_p[2][j].QInit(20, 1);
		m_p[3][j].QInit(40, 1);
		m_p[4][j].QInit(100, 1);
		m_p[5][j].QInit(40, 1);
		m_p[6][j].QInit(40, 1);
		m_p[7][j].QInit(10, 1);
		m_p[8][j].QInit(20, 1);
		m_p[9][j].QInit(40, 1);
		m_p[10][j].QInit(10, 1);
		m_p[11][j].QInit(40, 1);
		m_p[12][j].QInit(40, 1);
		m_p[13][j].QInit(10, 1);		
//			m_p[i][j].bColored = TRUE;
	}
	for( int i = 0; i < 4; i++ )
	{
		m_Num[i].QInit(10,1);
	}
	m_Num[0].dwFlags = ME_FIRST_ROW;
	m_Num[1].dwFlags = ME_LAST_ROW;

	for( int i=2; i < 14; i++ )
	{
		m_p[i][0].dwFlags = ME_FIRST_ROW;
		m_p[i][5].dwFlags = ME_LAST_ROW;
	}

	for( int i = 1; i < 6; i++ )
	{
		if( i == 3 ) continue;
		m_c[i].AddString("Ëåâ.");
		m_c[i].AddString("Ïðàâ.");
		m_c[i].SetItemData(0, 0);
		m_c[i].SetItemData(1, 1);
	}
	m_p[1][0].SetWindowText("ÍÁ");
	m_p[1][1].SetWindowText("ÁÐ");
	m_p[1][2].SetWindowText("ÁÐ");

	m_p[1][3].SetWindowText("ÍÁ");
	m_p[1][4].SetWindowText("ÁÐ");
	m_p[1][5].SetWindowText("ÁÐ");

	m_p[1][0].ModifyStyle(0, WS_DISABLED);
	m_p[1][1].ModifyStyle(0, WS_DISABLED);
	m_p[1][2].ModifyStyle(0, WS_DISABLED);
	m_p[1][3].ModifyStyle(0, WS_DISABLED);
	m_p[1][4].ModifyStyle(0, WS_DISABLED);
	m_p[1][5].ModifyStyle(0, WS_DISABLED);

	m_FIO1.SetMode(5, 1);
	DBW.FillEmplArray(m_FIO1.lpEmpl, 17);
	m_FIO2.SetMode(5, 1);
	DBW.FillEmplArray(m_FIO2.lpEmpl, 38);

	m_BackBuffer.p_iComboIndex[1] = m_BackBuffer.p_iComboIndex[4] = 0;
	m_BackBuffer.p_iComboIndex[7] = m_BackBuffer.p_iComboIndex[10]= 0;
	m_BackBuffer.p_iComboIndex[2] = m_BackBuffer.p_iComboIndex[5] = 1;
	m_BackBuffer.p_iComboIndex[8] = m_BackBuffer.p_iComboIndex[11]= 1;

	m_c[1].SetCurSel(1);
	m_c[4].SetCurSel(1);
	m_c[2].SetCurSel(0);
	m_c[5].SetCurSel(0);

	m_FIO1.dwFlags = ME_SCROLL_NORMAL;
	m_FIO2.dwFlags = ME_SCROLL_NORMAL;

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg4624_LDTL::OnCancel()
{
	return;
//	CDlgWithAccelerators::OnCancel();
}

void CDlgMsg4624_LDTL::OnCbnSelchangeCombo23()
{
	// TODO: Add your control notification handler code here
}

void CDlgMsg4624_LDTL::OnBnClickedButton29()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 17;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_FIO1.SetData(Dlg.dwFio);
	m_FIO1.SetWindowText(Dlg.cFio);
}

void CDlgMsg4624_LDTL::OnCbnSelchangeCombo_1()
{
	m_c[2].SetCurSel(!m_c[1].GetCurSel());
}

void CDlgMsg4624_LDTL::OnCbnSelchangeCombo_2()
{
	m_c[1].SetCurSel(!m_c[2].GetCurSel());
}

void CDlgMsg4624_LDTL::OnCbnSelchangeCombo_4()
{
	m_c[5].SetCurSel(!m_c[4].GetCurSel());
}

void CDlgMsg4624_LDTL::OnCbnSelchangeCombo_5()
{
	m_c[4].SetCurSel(!m_c[5].GetCurSel());
}

void CDlgMsg4624_LDTL::OnBnClickedButton31()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 38;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_FIO2.SetData(Dlg.dwFio);
	m_FIO2.SetWindowText(Dlg.cFio);
}

void CDlgMsg4624_LDTL::OnArrowDown()
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

void CDlgMsg4624_LDTL::OnArrowUp()
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

void CDlgMsg4624_LDTL::OnBnClickedButton3()
{
	//SWAP Buffers
	int shift = 6 * m_BackBuffer.iScreenPage;
	m_BackBuffer.p_strNum[2* m_BackBuffer.iScreenPage ] = m_Num[0].GetText();
	m_BackBuffer.p_strNum[1 + 2* m_BackBuffer.iScreenPage ] = m_Num[1].GetText();

	for( int i=1; i < 14; i++ )
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

	mn->SetErrorEdit(mn->dwVkladka, mn->dwErrX, mn->dwErrY );

	m_Num[0].SetWindowText(m_BackBuffer.p_strNum[2* m_BackBuffer.iScreenPage]);
	m_Num[1].SetWindowText(m_BackBuffer.p_strNum[1 + 2* m_BackBuffer.iScreenPage]);

	for( int i=2; i < 14; i++ )
	{
		for( int j=0; j < 6; j++ )
		{
			m_p[i][j].SetWindowText(m_BackBuffer.str_p[i][j + shift]);
		}
	}

	for( int i=0; i < 6; i++ )
		m_c[i].SetCurSel(m_BackBuffer.p_iComboIndex[i + shift]);	
}

void CDlgMsg4624_LDTL::StoreValues(void)
{
	int shift = 6 * m_BackBuffer.iScreenPage;
	m_BackBuffer.p_strNum[2* m_BackBuffer.iScreenPage ] = m_Num[0].GetText();
	m_BackBuffer.p_strNum[1 + 2* m_BackBuffer.iScreenPage ] = m_Num[1].GetText();

	CString sss = "";
	m_p[13][0].GetWindowText(sss);
	sss;
	
	for( int i=1; i < 14; i++ )
	{
		for( int j=0; j < 6; j++ )
		{
			m_BackBuffer.str_p[i][j + shift] = m_p[i][j].GetText();
		}
	}

	for( int i=0; i < 6; i++ )
	{
		m_BackBuffer.p_iComboIndex[i + shift] = m_c[i].GetCurSel();
	}
}

void CDlgMsg4624_LDTL::DrawBuffer(int page)
{
	int shift = 6 * page;

	m_Num[0].SetWindowText(m_BackBuffer.p_strNum[2 * page]);
	m_Num[1].SetWindowText(m_BackBuffer.p_strNum[1 + 2 * page]);

	for( int i=2; i < 14; i++ )
	{
		for( int j=0; j < 6; j++ )
		{
			m_p[i][j].SetWindowText(m_BackBuffer.str_p[i][j + shift]);
		}
	}

	for( int i=0; i < 6; i++ )
		m_c[i].SetCurSel(m_BackBuffer.p_iComboIndex[i + shift]);
}

void CDlgMsg4624_LDTL::OnBnClickedButton4()
{
	mn->PerenosKPtoZamenDTL(0 + 6 * m_BackBuffer.iScreenPage);
	m_ButIz1.EnableWindow(FALSE);
//	m_lpButIz[0].EnableWindow(FALSE);
}

void CDlgMsg4624_LDTL::OnBnClickedButton6()
{
	mn->PerenosKPtoZamenDTL(1 + 6 * m_BackBuffer.iScreenPage);
	m_ButIz2.EnableWindow(FALSE);
}

void CDlgMsg4624_LDTL::OnBnClickedButton7()
{
	mn->PerenosKPtoZamenDTL(2 + 6 * m_BackBuffer.iScreenPage);
	m_ButIz3.EnableWindow(FALSE);
}

void CDlgMsg4624_LDTL::OnBnClickedButton67()
{
	mn->PerenosKPtoZamenDTL(3 + 6 * m_BackBuffer.iScreenPage);
	m_ButIz4.EnableWindow(FALSE);
}

void CDlgMsg4624_LDTL::OnBnClickedButton9()
{
	mn->PerenosKPtoZamenDTL(4 + 6 * m_BackBuffer.iScreenPage);
	m_ButIz5.EnableWindow(FALSE);
}

void CDlgMsg4624_LDTL::OnBnClickedButton25()
{
	mn->PerenosKPtoZamenDTL(5 + 6 * m_BackBuffer.iScreenPage);
	m_ButIz6.EnableWindow(FALSE);
}

void CDlgMsg4624_LDTL::OnEnChangeE130()
{
	if( !mn ) return;

	if( mn->m_EdVRem.GetAsDWord() == 1 ||
		mn->m_EdVRem.GetAsDWord() == 2 )
	{
		CString str = "";
		m_p[13][0].GetWindowText( str );
		for( int i=1; i < 6; i++ )
		{
			m_p[13][i].SetWindowText( str );
			m_BackBuffer.str_p[13][i] = str;
			if( mn->i8os ) m_BackBuffer.str_p[13][i + 6] = str;
		}
		CString sss = "";
		m_p[13][0].GetWindowText(sss);
		sss;
		if( mn->m_pDlgTLVag )
		{
			mn->m_pDlgTLVag->m_pL[1].SetWindowText( str );
			mn->m_pDlgTLVag->m_pL[3].SetWindowText( str );
			if( mn->i8os ) mn->m_pDlgTLVag->m_pL[5].SetWindowText( str );
			if( mn->i8os ) mn->m_pDlgTLVag->m_pL[7].SetWindowText( str );
		}		
	}
//	AfxMessageBox( mn->m_pDlgTLVag->m_pL[1].GetAsString() );
}
