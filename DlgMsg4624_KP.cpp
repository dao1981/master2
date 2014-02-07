// DlgMsg4624_KP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624_KP.h"
#include ".\dlgmsg4624_kp.h"
#include "DlgAccel1.h"
#include "DlgSpravKdr.h"
#include "DlgMsg4624_Main.h"
#include "DlgPrihKpList.h"

// CDlgMsg4624_KP dialog

extern int g_iUpDownArrowsStandart;

IMPLEMENT_DYNAMIC(CDlgMsg4624_KP, CDlgWithAccelerators)
CDlgMsg4624_KP::CDlgMsg4624_KP(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg4624_KP::IDD, pParent)
{
}

CDlgMsg4624_KP::~CDlgMsg4624_KP()
{
}

void CDlgMsg4624_KP::DoDataExchange(CDataExchange* pDX)
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

	DDX_Control(pDX, IDC_EDIT202, m_EdFIO1);
	DDX_Control(pDX, IDC_EDIT203, m_EdFIO2);

	DDX_Control(pDX, IDC_BUTTON29, m_bnFio1);
	DDX_Control(pDX, IDC_BUTTON30, m_bnFio2);

	DDX_Control(pDX, IDC_BUTTON7, m_lpButIz[0]);
	DDX_Control(pDX, IDC_BUTTON8, m_lpButIz[1]);
	DDX_Control(pDX, IDC_BUTTON36, m_lpButIz[2]);
	DDX_Control(pDX, IDC_BUTTON40, m_lpButIz[3]);
	DDX_Control(pDX, IDC_BUTTON19, m_lpButIz[4]);
	DDX_Control(pDX, IDC_BUTTON13, m_lpButIz[5]);
	DDX_Control(pDX, IDC_BUTTON41, m_lpButIz[6]);
	DDX_Control(pDX, IDC_BUTTON42, m_lpButIz[7]);

	DDX_Control(pDX, IDC_BUTTON24, m_lpButIzNal[0]);
	DDX_Control(pDX, IDC_BUTTON26, m_lpButIzNal[1]);
	DDX_Control(pDX, IDC_BUTTON27, m_lpButIzNal[2]);
	DDX_Control(pDX, IDC_BUTTON68, m_lpButIzNal[3]);
	DDX_Control(pDX, IDC_BUTTON52, m_lpButIzNal[4]);
	DDX_Control(pDX, IDC_BUTTON69, m_lpButIzNal[5]);
	DDX_Control(pDX, IDC_BUTTON70, m_lpButIzNal[6]);
	DDX_Control(pDX, IDC_BUTTON71, m_lpButIzNal[7]);
}


BEGIN_MESSAGE_MAP(CDlgMsg4624_KP, CDlgWithAccelerators)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON29, OnBnClickedButton_FIO1)
	ON_BN_CLICKED(IDC_BUTTON30, OnBnClickedButton30)
	ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
	ON_COMMAND(ID_ARROW_UP, OnArrowUp)
	ON_BN_CLICKED(IDC_BUTTON7, OnBnClickedButtonIZ1)
	ON_BN_CLICKED(IDC_BUTTON8, OnBnClickedButtonIZ2)
	ON_BN_CLICKED(IDC_BUTTON36, OnBnClickedButtonIZ3)
	ON_BN_CLICKED(IDC_BUTTON40, OnBnClickedButtonIZ4)
	ON_BN_CLICKED(IDC_BUTTON19, OnBnClickedButtonIZ5)
	ON_BN_CLICKED(IDC_BUTTON13, OnBnClickedButtonIZ6)
	ON_BN_CLICKED(IDC_BUTTON41, OnBnClickedButtonIZ7)
	ON_BN_CLICKED(IDC_BUTTON42, OnBnClickedButtonIZ8)
	ON_BN_CLICKED(IDC_BUTTON24, &CDlgMsg4624_KP::OnBnClickedButtonIzNal1)
	ON_BN_CLICKED(IDC_BUTTON26, &CDlgMsg4624_KP::OnBnClickedButtonIzNal2)
	ON_BN_CLICKED(IDC_BUTTON27, &CDlgMsg4624_KP::OnBnClickedButtonIzNal3)
	ON_BN_CLICKED(IDC_BUTTON68, &CDlgMsg4624_KP::OnBnClickedButtonIzNal4)
	ON_BN_CLICKED(IDC_BUTTON52, &CDlgMsg4624_KP::OnBnClickedButtonIzNal5)
	ON_BN_CLICKED(IDC_BUTTON69, &CDlgMsg4624_KP::OnBnClickedButtonIzNal6)
	ON_BN_CLICKED(IDC_BUTTON70, &CDlgMsg4624_KP::OnBnClickedButtonIzNal7)
	ON_BN_CLICKED(IDC_BUTTON71, &CDlgMsg4624_KP::OnBnClickedButtonIzNal8)
	ON_EN_KILLFOCUS(IDC_70, &CDlgMsg4624_KP::OnEnKillfocus70)
	ON_EN_CHANGE(IDC_70, &CDlgMsg4624_KP::OnEnChange70)
	ON_EN_CHANGE(IDC_71, &CDlgMsg4624_KP::OnEnChange71)
	ON_EN_CHANGE(IDC_72, &CDlgMsg4624_KP::OnEnChange72)
	ON_EN_CHANGE(IDC_73, &CDlgMsg4624_KP::OnEnChange73)
	ON_EN_CHANGE(IDC_74, &CDlgMsg4624_KP::OnEnChange74)
	ON_EN_CHANGE(IDC_75, &CDlgMsg4624_KP::OnEnChange75)
	ON_EN_CHANGE(IDC_76, &CDlgMsg4624_KP::OnEnChange76)
	ON_EN_CHANGE(IDC_77, &CDlgMsg4624_KP::OnEnChange77)
	ON_EN_CHANGE(IDC_80, &CDlgMsg4624_KP::OnEnChange80)
END_MESSAGE_MAP()


// CDlgMsg4624_KP message handlers

void CDlgMsg4624_KP::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CDlgMsg4624_KP::OnCancel(void)
{
}

void CDlgMsg4624_KP::OnBnClickedButton_FIO1()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 10;
	Dlg.DlgMode = 1;
	if ( Dlg.DoModal() == IDCANCEL ) return;
	m_EdFIO1.SetData(Dlg.dwFio);
	m_EdFIO1.SetWindowText(Dlg.cFio);

}

void CDlgMsg4624_KP::OnBnClickedButton30()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 38;
	Dlg.DlgMode = 1;
	if ( Dlg.DoModal() == IDCANCEL ) return;
	m_EdFIO2.SetData(Dlg.dwFio);
	m_EdFIO2.SetWindowText(Dlg.cFio);

}

extern int g_iAutoRashodKP;
BOOL CDlgMsg4624_KP::OnInitDialog()
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
	}
	for( int i=0; i < 13; i++ )
	{
		m_p[i][0].dwFlags = ME_FIRST_ROW;
		m_p[i][7].dwFlags = ME_LAST_ROW;
	}
/*
	for( int i=0; i < 8; i++ )
		for( int j=7; j < 13; j++ )
		{
			m_p[j][i].QInit(120, 1);
		}
*/
	m_EdFIO1.SetMode(5, 1);
	DBW.FillEmplArray(m_EdFIO1.lpEmpl, 10);
	m_EdFIO2.SetMode(5, 1);
	DBW.FillEmplArray(m_EdFIO2.lpEmpl, 38);

	for( int i=0; i < 8; i++ ) m_lpButIzNal[i].EnableWindow( g_iAutoRashodKP );

	m_EdFIO1.dwFlags = ME_SCROLL_NORMAL;
	m_EdFIO2.dwFlags = ME_SCROLL_NORMAL;
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg4624_KP::OnArrowDown()
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

void CDlgMsg4624_KP::OnArrowUp()
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

extern CDlgMsg4624_Main *mn;
void CDlgMsg4624_KP::OnBnClickedButtonIZ1()
{
	mn->PerenosKPtoZamenKP(0);
	m_lpButIz[0].EnableWindow(FALSE);
}

void CDlgMsg4624_KP::OnBnClickedButtonIZ2()
{
	mn->PerenosKPtoZamenKP(1);
	m_lpButIz[1].EnableWindow(FALSE);
}

void CDlgMsg4624_KP::OnBnClickedButtonIZ3()
{
	mn->PerenosKPtoZamenKP(2);
	m_lpButIz[2].EnableWindow(FALSE);
}

void CDlgMsg4624_KP::OnBnClickedButtonIZ4()
{
	mn->PerenosKPtoZamenKP(3);
	m_lpButIz[3].EnableWindow(FALSE);
}

void CDlgMsg4624_KP::OnBnClickedButtonIZ5()
{
	mn->PerenosKPtoZamenKP(4);
	m_lpButIz[4].EnableWindow(FALSE);
}

void CDlgMsg4624_KP::OnBnClickedButtonIZ6()
{
	mn->PerenosKPtoZamenKP(5);
	m_lpButIz[5].EnableWindow(FALSE);
}

void CDlgMsg4624_KP::OnBnClickedButtonIZ7()
{
	mn->PerenosKPtoZamenKP(6);
	m_lpButIz[6].EnableWindow(FALSE);
}

void CDlgMsg4624_KP::OnBnClickedButtonIZ8()
{
	mn->PerenosKPtoZamenKP(7);
	m_lpButIz[7].EnableWindow(FALSE);
}

void CDlgMsg4624_KP::OnBnClickedButtonIzNal1()
{
	SetIzNal(0);
}

void CDlgMsg4624_KP::OnBnClickedButtonIzNal2()
{
	SetIzNal(1);
}

void CDlgMsg4624_KP::OnBnClickedButtonIzNal3()
{
	SetIzNal(2);
}

void CDlgMsg4624_KP::OnBnClickedButtonIzNal4()
{
	SetIzNal(3);
}

void CDlgMsg4624_KP::OnBnClickedButtonIzNal5()
{
	SetIzNal(4);
}

void CDlgMsg4624_KP::OnBnClickedButtonIzNal6()
{
	SetIzNal(5);
}

void CDlgMsg4624_KP::OnBnClickedButtonIzNal7()
{
	SetIzNal(6);
}

void CDlgMsg4624_KP::OnBnClickedButtonIzNal8()
{
	SetIzNal(7);
}

void CDlgMsg4624_KP::SetIzNal( int idx )
{
	char cQ[128] = "";
	long Ind = 0;
	char cText[64] = "";
	CDlgPrihKpList Dlg;
	if( Dlg.DoModal() == IDCANCEL || !Dlg.qwRetIZap )
	{
			mn->qwIzapRashKP[ idx ];
			return;
	}

	sprintf(cQ, "pTov_S4624SelFormNal %I64u, %d", Dlg.qwRetIZap, g_iDep);
	DBW.ExecSQL(cQ);
	DBW.Fetch();

	DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[1][idx].SetWindowText( cText );
	DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[2][idx].SetWindowText( cText );
	DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[3][idx].SetWindowText( cText );
	DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[4][idx].SetWindowText( cText );
	DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[5][idx].SetWindowText( cText );
	DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[6][idx].SetWindowText( cText );
	DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[7][idx].SetWindowText( cText );
	DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[8][idx].SetWindowText( cText );
	DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[9][idx].SetWindowText( cText );
	DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[10][idx].SetWindowText( cText );
	DBW.GetData(11, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[11][idx].SetWindowText( cText );
	DBW.GetData(12, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_p[12][idx].SetWindowText( cText );
	DBW.CloseCursor();

	mn->qwIzapRashKP[ idx ] = Dlg.qwRetIZap;

}
void CDlgMsg4624_KP::OnEnKillfocus70()
{
//	AfxMessageBox("YO");
}

void CDlgMsg4624_KP::OnEnChange70()
{
	SetObod( 0 );
}

void CDlgMsg4624_KP::SetObod( int idx )
{
	if( !mn ) return;

	if( mn->m_EdVRem.GetAsDWord() == 1 ||
		mn->m_EdVRem.GetAsDWord() == 2 )
	{
		CString str = "";
		m_p[7][idx].GetWindowText( str );
		m_p[10][idx].SetWindowText( str );
	}
}

void CDlgMsg4624_KP::SetGreb( int idx )
{
	if( !mn ) return;

	if( mn->m_EdVRem.GetAsDWord() == 1 ||
		mn->m_EdVRem.GetAsDWord() == 2 )
	{
		CString str = "";
		m_p[8][idx].GetWindowText( str );
		for( int i=0; i < 8; i++ )
		{
			m_p[8][i].SetWindowText( str );
			m_p[11][i].SetWindowText( str );
		}
	}
}

void CDlgMsg4624_KP::OnEnChange71()
{
	SetObod( 1 );
}

void CDlgMsg4624_KP::OnEnChange72()
{
	SetObod( 2 );
}

void CDlgMsg4624_KP::OnEnChange73()
{
	SetObod( 3 );
}

void CDlgMsg4624_KP::OnEnChange74()
{
	SetObod( 4 );
}

void CDlgMsg4624_KP::OnEnChange75()
{
	SetObod( 5 );
}

void CDlgMsg4624_KP::OnEnChange76()
{
	SetObod( 6 );
}

void CDlgMsg4624_KP::OnEnChange77()
{
	SetObod( 7 );
}

void CDlgMsg4624_KP::OnEnChange80()
{
	SetGreb( 0 );
}
