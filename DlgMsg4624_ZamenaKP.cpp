// DlgMsg4624_ZamenaKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624_ZamenaKP.h"
#include ".\dlgmsg4624_zamenakp.h"
#include "DlgSpravKdr.h"

extern int g_iUpDownArrowsStandart;
// CDlgMsg4624_ZamenaKP dialog

IMPLEMENT_DYNAMIC(CDlgMsg4624_ZamenaKP, CDlgWithAccelerators)
CDlgMsg4624_ZamenaKP::CDlgMsg4624_ZamenaKP(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg4624_ZamenaKP::IDD, pParent)
{
}

CDlgMsg4624_ZamenaKP::~CDlgMsg4624_ZamenaKP()
{
}

void CDlgMsg4624_ZamenaKP::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_STAT1, m_Lab1);
	DDX_Control(pDX, IDC_LAB2, m_Lab2);
	DDX_Control(pDX, IDC_LAB4, m_Lab3);
	DDX_Control(pDX, IDC_LAB6, m_Lab4);
	DDX_Control(pDX, IDC_LAB7, m_Lab6);
	DDX_Control(pDX, IDC_LAB8, m_Lab7);
	DDX_Control(pDX, IDC_LAB9, m_Lab8);
	DDX_Control(pDX, IDC_LAB10, m_Lab9);
	DDX_Control(pDX, IDC_LAB11, m_Lab10);
	DDX_Control(pDX, IDC_LAB12, m_Lab11);
	DDX_Control(pDX, IDC_LAB13, m_Lab12);
	DDX_Control(pDX, IDC_LAB15, m_Lab13);

	DDX_Control(pDX, IDC_00, m_p[0][0]);
	DDX_Control(pDX, IDC_10, m_p[1][0]);
	DDX_Control(pDX, IDC_20, m_p[2][0]);
	DDX_Control(pDX, IDC_30, m_p[3][0]);
	DDX_Control(pDX, IDC_40, m_p[4][0]);
	DDX_Control(pDX, IDC_50, m_p[5][0]);
	DDX_Control(pDX, IDC_60, m_p[6][0]);
	DDX_Control(pDX, IDC_70, m_p[7][0]);
	DDX_Control(pDX, IDC_80, m_p[8][0]);
	DDX_Control(pDX, IDC_90, m_p[9][0]);
	DDX_Control(pDX, IDC_10_0, m_p[10][0]);
	DDX_Control(pDX, IDC_11_0, m_p[11][0]);
	DDX_Control(pDX, IDC_12_0, m_p[12][0]);
	DDX_Control(pDX, IDC_13_0, m_p[13][0]);

	
	DDX_Control(pDX, IDC_01, m_p[0][1]);
	DDX_Control(pDX, IDC_11, m_p[1][1]);
	DDX_Control(pDX, IDC_21, m_p[2][1]);
	DDX_Control(pDX, IDC_31, m_p[3][1]);
	DDX_Control(pDX, IDC_41, m_p[4][1]);
	DDX_Control(pDX, IDC_51, m_p[5][1]);
	DDX_Control(pDX, IDC_61, m_p[6][1]);
	DDX_Control(pDX, IDC_71, m_p[7][1]);
	DDX_Control(pDX, IDC_81, m_p[8][1]);
	DDX_Control(pDX, IDC_91, m_p[9][1]);
	DDX_Control(pDX, IDC_10_1, m_p[10][1]);
	DDX_Control(pDX, IDC_11_1, m_p[11][1]);
	DDX_Control(pDX, IDC_12_1, m_p[12][1]);
	DDX_Control(pDX, IDC_13_1, m_p[13][1]);

	DDX_Control(pDX, IDC_02, m_p[0][2]);
	DDX_Control(pDX, IDC_12, m_p[1][2]);
	DDX_Control(pDX, IDC_22, m_p[2][2]);
	DDX_Control(pDX, IDC_32, m_p[3][2]);
	DDX_Control(pDX, IDC_42, m_p[4][2]);
	DDX_Control(pDX, IDC_52, m_p[5][2]);
	DDX_Control(pDX, IDC_62, m_p[6][2]);
	DDX_Control(pDX, IDC_72, m_p[7][2]);
	DDX_Control(pDX, IDC_82, m_p[8][2]);
	DDX_Control(pDX, IDC_92, m_p[9][2]);
	DDX_Control(pDX, IDC_10_2, m_p[10][2]);
	DDX_Control(pDX, IDC_11_2, m_p[11][2]);
	DDX_Control(pDX, IDC_12_2, m_p[12][2]);
	DDX_Control(pDX, IDC_13_2, m_p[13][2]);

	DDX_Control(pDX, IDC_03, m_p[0][3]);
	DDX_Control(pDX, IDC_13, m_p[1][3]);
	DDX_Control(pDX, IDC_23, m_p[2][3]);
	DDX_Control(pDX, IDC_33, m_p[3][3]);
	DDX_Control(pDX, IDC_43, m_p[4][3]);
	DDX_Control(pDX, IDC_53, m_p[5][3]);
	DDX_Control(pDX, IDC_63, m_p[6][3]);
	DDX_Control(pDX, IDC_73, m_p[7][3]);
	DDX_Control(pDX, IDC_83, m_p[8][3]);
	DDX_Control(pDX, IDC_93, m_p[9][3]);
	DDX_Control(pDX, IDC_10_3, m_p[10][3]);
	DDX_Control(pDX, IDC_11_3, m_p[11][3]);
	DDX_Control(pDX, IDC_12_3, m_p[12][3]);
	DDX_Control(pDX, IDC_13_3, m_p[13][3]);

	DDX_Control(pDX, IDC_04, m_p[0][4]);
	DDX_Control(pDX, IDC_14, m_p[1][4]);
	DDX_Control(pDX, IDC_24, m_p[2][4]);
	DDX_Control(pDX, IDC_34, m_p[3][4]);
	DDX_Control(pDX, IDC_44, m_p[4][4]);
	DDX_Control(pDX, IDC_54, m_p[5][4]);
	DDX_Control(pDX, IDC_64, m_p[6][4]);
	DDX_Control(pDX, IDC_74, m_p[7][4]);
	DDX_Control(pDX, IDC_84, m_p[8][4]);
	DDX_Control(pDX, IDC_94, m_p[9][4]);
	DDX_Control(pDX, IDC_10_4, m_p[10][4]);
	DDX_Control(pDX, IDC_11_4, m_p[11][4]);
	DDX_Control(pDX, IDC_12_4, m_p[12][4]);
	DDX_Control(pDX, IDC_13_4, m_p[13][4]);

	DDX_Control(pDX, IDC_05, m_p[0][5]);
	DDX_Control(pDX, IDC_15, m_p[1][5]);
	DDX_Control(pDX, IDC_25, m_p[2][5]);
	DDX_Control(pDX, IDC_35, m_p[3][5]);
	DDX_Control(pDX, IDC_45, m_p[4][5]);
	DDX_Control(pDX, IDC_55, m_p[5][5]);
	DDX_Control(pDX, IDC_65, m_p[6][5]);
	DDX_Control(pDX, IDC_75, m_p[7][5]);
	DDX_Control(pDX, IDC_85, m_p[8][5]);
	DDX_Control(pDX, IDC_95, m_p[9][5]);
	DDX_Control(pDX, IDC_10_5, m_p[10][5]);
	DDX_Control(pDX, IDC_11_5, m_p[11][5]);
	DDX_Control(pDX, IDC_12_5, m_p[12][5]);
	DDX_Control(pDX, IDC_13_5, m_p[13][5]);

	DDX_Control(pDX, IDC_06, m_p[0][6]);
	DDX_Control(pDX, IDC_16, m_p[1][6]);
	DDX_Control(pDX, IDC_26, m_p[2][6]);
	DDX_Control(pDX, IDC_36, m_p[3][6]);
	DDX_Control(pDX, IDC_46, m_p[4][6]);
	DDX_Control(pDX, IDC_56, m_p[5][6]);
	DDX_Control(pDX, IDC_66, m_p[6][6]);
	DDX_Control(pDX, IDC_76, m_p[7][6]);
	DDX_Control(pDX, IDC_86, m_p[8][6]);
	DDX_Control(pDX, IDC_96, m_p[9][6]);
	DDX_Control(pDX, IDC_10_6, m_p[10][6]);
	DDX_Control(pDX, IDC_11_6, m_p[11][6]);
	DDX_Control(pDX, IDC_12_6, m_p[12][6]);
	DDX_Control(pDX, IDC_13_6, m_p[13][6]);

	DDX_Control(pDX, IDC_07, m_p[0][7]);
	DDX_Control(pDX, IDC_17, m_p[1][7]);
	DDX_Control(pDX, IDC_27, m_p[2][7]);
	DDX_Control(pDX, IDC_37, m_p[3][7]);
	DDX_Control(pDX, IDC_47, m_p[4][7]);
	DDX_Control(pDX, IDC_57, m_p[5][7]);
	DDX_Control(pDX, IDC_67, m_p[6][7]);
	DDX_Control(pDX, IDC_77, m_p[7][7]);
	DDX_Control(pDX, IDC_87, m_p[8][7]);
	DDX_Control(pDX, IDC_97, m_p[9][7]);
	DDX_Control(pDX, IDC_10_7, m_p[10][7]);
	DDX_Control(pDX, IDC_11_7, m_p[11][7]);
	DDX_Control(pDX, IDC_12_7, m_p[12][7]);
	DDX_Control(pDX, IDC_13_7, m_p[13][7]);

	DDX_Control(pDX, IDC_COMBO2, m_pTKP[0]);
	DDX_Control(pDX, IDC_COMBO3, m_pTKP[1]);
	DDX_Control(pDX, IDC_COMBO7, m_pTKP[2]);
	DDX_Control(pDX, IDC_COMBO19, m_pTKP[3]);
	DDX_Control(pDX, IDC_COMBO51, m_pTKP[4]);
	DDX_Control(pDX, IDC_COMBO52, m_pTKP[5]);
	DDX_Control(pDX, IDC_COMBO53, m_pTKP[6]);
	DDX_Control(pDX, IDC_COMBO54, m_pTKP[7]);

	DDX_Control(pDX, IDC_EDIT202, m_FIO1);
	DDX_Control(pDX, IDC_BUTTON29, m_bnFio);
}


BEGIN_MESSAGE_MAP(CDlgMsg4624_ZamenaKP, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_BUTTON29, OnBnClickedButton_FIO1)
	ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
	ON_COMMAND(ID_ARROW_UP, OnArrowUp)
END_MESSAGE_MAP()


// CDlgMsg4624_ZamenaKP message handlers

BOOL CDlgMsg4624_ZamenaKP::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

		for( int i=0; i < 8; i++ )
	{
		m_p[0][i].QInit(10,1);
		m_p[1][i].QInit(20,1);
		m_p[2][i].QInit(40,1);
		m_p[3][i].QInit(40,1);
		m_p[4][i].QInit(40,1);
		m_p[5][i].QInit(100,1);
		m_p[6][i].QInit(40,1);
		m_p[7][i].QInit(30,1);
		m_p[8][i].QInit(30,1);
		m_p[9][i].QInit(20,1);
		m_p[10][i].QInit(30,1);
		m_p[11][i].QInit(30,1);
		m_p[12][i].QInit(20,1);
		m_p[13][i].QInit(30,1);
	}
	for( int i=0; i < 14; i++ )
	{
		m_p[i][0].dwFlags = ME_FIRST_ROW;
		m_p[i][7].dwFlags = ME_LAST_ROW;
	}
	m_FIO1.dwFlags = ME_SCROLL_NORMAL;
	m_FIO1.SetMode(5, 1);
	DBW.FillEmplArray(m_FIO1.lpEmpl, 1); // раньше было 10

	for( int i=0; i < 8; i++ )
	{
		DBW.FillComboWithTKP( &m_pTKP[i] );
		SetComboBoxItemByID( &m_pTKP[i], 100 );
	}
/*
	for( int i=0; i < 8; i++ )
		for( int j=7; j < 13; j++ )
		{
			m_p[j][i].QInit(120, 1);
		}
*/

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg4624_ZamenaKP::OnOK()
{
//	CDialog::OnOK();
}

void CDlgMsg4624_ZamenaKP::OnCancel()
{
//	CDialog::OnCancel();
}

void CDlgMsg4624_ZamenaKP::OnBnClickedButton_FIO1()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 1; // раньше был фильтр 10
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_FIO1.SetData(Dlg.dwFio);
	m_FIO1.SetWindowText(Dlg.cFio);
}

void CDlgMsg4624_ZamenaKP::OnArrowDown()
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

void CDlgMsg4624_ZamenaKP::OnArrowUp()
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
