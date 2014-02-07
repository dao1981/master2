// DlgRashodTl.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRashodTl.h"
#include ".\dlgrashodtl.h"


// CDlgRashodTl dialog

//HACCEL CDlgWithAccelerators::m_hAccel; // accelerator table

IMPLEMENT_DYNAMIC(CDlgRashodTl, CDlgWithAccelerators)
CDlgRashodTl::CDlgRashodTl(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgRashodTl::IDD, pParent)
{
	iNeedBalka = 0;
}

CDlgRashodTl::~CDlgRashodTl()
{
}

void CDlgRashodTl::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LAB1, m_Lab1);
	DDX_Control(pDX, IDC_LAB2, m_Lab2);
	DDX_Control(pDX, IDC_LAB3, m_Lab3);
	DDX_Control(pDX, IDC_LAB4, m_Lab4);
	DDX_Control(pDX, IDC_LAB5, m_Lab5);
	DDX_Control(pDX, IDC_LAB6, m_Lab6);
	DDX_Control(pDX, IDC_LAB7, m_Lab7);
	DDX_Control(pDX, IDC_LAB8, m_Lab8);
	/*	DDX_Control(pDX, IDC_LAB9, m_Lab9);
	DDX_Control(pDX, IDC_LAB10, m_Lab10);
	DDX_Control(pDX, IDC_LAB11, m_Lab11);*/
	DDX_Control(pDX, IDC_LAB12, m_Lab12);
	DDX_Control(pDX, IDC_LAB13, m_Lab13);
	DDX_Control(pDX, IDC_LAB14, m_Lab14);
	/*	DDX_Control(pDX, IDC_LAB15, m_Lab15);
	DDX_Control(pDX, IDC_LAB16, m_Lab16);
	DDX_Control(pDX, IDC_LAB17, m_Lab17);*/
	DDX_Control(pDX, IDC_LAB18, m_Lab18);
	DDX_Control(pDX, IDC_LAB19, m_Lab19);
	DDX_Control(pDX, IDC_LAB20, m_Lab20);
	DDX_Control(pDX, IDC_LAB21, m_Lab21);
	DDX_Control(pDX, IDC_LAB22, m_Lab22);
	DDX_Control(pDX, IDC_LAB23, m_Lab23);
	DDX_Control(pDX, IDC_LAB24, m_Lab24);
	DDX_Control(pDX, IDC_LAB25, m_Lab25);

	/*	DDX_Control(pDX, IDC_N1, m_n1);
	DDX_Control(pDX, IDC_N2, m_n2);
	DDX_Control(pDX, IDC_N3, m_n3);
	DDX_Control(pDX, IDC_N4, m_n4);*/
	DDX_Control(pDX, IDC_STAT1, m_bevel1);
	//	DDX_Control(pDX, IDC_STAT2, m_bevel2);
	DDX_Control(pDX, IDC_EDIT142, m_Edb1);
	DDX_Control(pDX, IDC_EDIT143, m_Edb2);
	DDX_Control(pDX, IDC_EDIT144, m_Edb3);
	DDX_Control(pDX, IDC_EDIT145, m_Edb4);
	DDX_Control(pDX, IDC_ED1, m_EdBR1[0]);
	DDX_Control(pDX, IDC_ED2, m_EdBR1[1]);
	DDX_Control(pDX, IDC_ED3, m_EdBR1[2]);
	DDX_Control(pDX, IDC_ED4, m_EdBR1[3]);
	DDX_Control(pDX, IDC_ED5, m_EdBR1[4]);
	DDX_Control(pDX, IDC_ED6, m_EdBR1[5]);
	DDX_Control(pDX, IDC_ED7, m_EdBR1[6]);
	DDX_Control(pDX, IDC_ED8, m_EdBR1[7]);
	DDX_Control(pDX, IDC_ED9, m_EdBR1[8]);
	DDX_Control(pDX, IDC_ED10, m_EdBR1[9]);
	DDX_Control(pDX, IDC_ED11, m_EdBR1[10]);
	DDX_Control(pDX, IDC_ED12, m_EdBR1[11]);
	DDX_Control(pDX, IDC_ED13, m_EdBR1[12]);
	DDX_Control(pDX, IDC_ED14, m_EdBR1[13]);
	DDX_Control(pDX, IDC_ED15, m_EdBR1[14]);
	DDX_Control(pDX, IDC_ED16, m_EdBR1[15]);
	DDX_Control(pDX, IDC_EDNB1, m_EdNB1[0]);
	DDX_Control(pDX, IDC_EDNB2, m_EdNB1[1]);
	DDX_Control(pDX, IDC_EDNB3, m_EdNB1[2]);
	DDX_Control(pDX, IDC_EDNB4, m_EdNB1[3]);
	DDX_Control(pDX, IDC_EDNB5, m_EdNB1[4]);
	DDX_Control(pDX, IDC_EDNB6, m_EdNB1[5]);
	DDX_Control(pDX, IDC_EDNB7, m_EdNB1[6]);
	DDX_Control(pDX, IDC_EDNB8, m_EdNB1[7]);
	DDX_Control(pDX, IDC_EDNB9, m_EdNB1[8]);
	DDX_Control(pDX, IDC_EDTV1, m_EdTV1[0]);
	DDX_Control(pDX, IDC_EDTV2, m_EdTV1[1]);
	DDX_Control(pDX, IDC_EDTV3, m_EdTV1[2]);
	DDX_Control(pDX, IDC_EDTV4, m_EdTV1[3]);
	DDX_Control(pDX, IDC_EDTV5, m_EdTV1[4]);
	DDX_Control(pDX, IDC_EDTV6, m_EdTV1[5]);
	DDX_Control(pDX, IDC_EDTV7, m_EdTV1[6]);
	DDX_Control(pDX, IDC_EDTV8, m_EdTV1[7]);
	DDX_Control(pDX, IDC_EDTV9, m_EdTV1[8]);
	DDX_Control(pDX, IDC_EDTV10, m_EdTV1[9]);
	DDX_Control(pDX, IDC_EDTV11, m_EdTV1[10]);
	DDX_Control(pDX, IDC_EDTV12, m_EdTV1[11]);
	DDX_Control(pDX, IDC_EDTV13, m_EdTV1[12]);
	DDX_Control(pDX, IDC_EDTV14, m_EdTV1[13]);

	DDX_Control(pDX, IDC_ED18, m_EdBR2[0]);
	DDX_Control(pDX, IDC_ED23, m_EdBR2[1]);
	DDX_Control(pDX, IDC_ED20, m_EdBR2[2]);
	DDX_Control(pDX, IDC_ED27, m_EdBR2[3]);
	DDX_Control(pDX, IDC_ED39, m_EdBR2[4]);
	DDX_Control(pDX, IDC_ED59, m_EdBR2[5]);
	DDX_Control(pDX, IDC_ED50, m_EdBR2[6]);
	DDX_Control(pDX, IDC_ED60, m_EdBR2[7]);
	DDX_Control(pDX, IDC_ED61, m_EdBR2[8]);
	DDX_Control(pDX, IDC_ED69, m_EdBR2[9]);
	DDX_Control(pDX, IDC_ED78, m_EdBR2[10]);
	DDX_Control(pDX, IDC_ED79, m_EdBR2[11]);
	DDX_Control(pDX, IDC_ED88, m_EdBR2[12]);
	DDX_Control(pDX, IDC_ED89, m_EdBR2[13]);
	DDX_Control(pDX, IDC_ED98, m_EdBR2[14]);
	DDX_Control(pDX, IDC_ED99, m_EdBR2[15]);
	DDX_Control(pDX, IDC_EDNB10, m_EdNB2[0]);
	DDX_Control(pDX, IDC_EDNB11, m_EdNB2[1]);
	DDX_Control(pDX, IDC_EDNB12, m_EdNB2[2]);
	DDX_Control(pDX, IDC_EDNB13, m_EdNB2[3]);
	DDX_Control(pDX, IDC_EDNB14, m_EdNB2[4]);
	DDX_Control(pDX, IDC_EDNB15, m_EdNB2[5]);
	DDX_Control(pDX, IDC_EDNB16, m_EdNB2[6]);
	DDX_Control(pDX, IDC_EDNB17, m_EdNB2[7]);
	DDX_Control(pDX, IDC_EDNB18, m_EdNB2[8]);

	DDX_Control(pDX, IDC_EDTV15, m_EdTV2[0]);
	DDX_Control(pDX, IDC_EDTV16, m_EdTV2[1]);
	DDX_Control(pDX, IDC_EDTV17, m_EdTV2[2]);
	DDX_Control(pDX, IDC_EDTV18, m_EdTV2[3]);
	DDX_Control(pDX, IDC_EDTV19, m_EdTV2[4]);
	DDX_Control(pDX, IDC_EDTV20, m_EdTV2[5]);
	DDX_Control(pDX, IDC_EDTV21, m_EdTV2[6]);
	DDX_Control(pDX, IDC_EDTV22, m_EdTV2[7]);
	DDX_Control(pDX, IDC_EDTV23, m_EdTV2[8]);
	DDX_Control(pDX, IDC_EDTV24, m_EdTV2[9]);
	DDX_Control(pDX, IDC_EDTV25, m_EdTV2[10]);
	DDX_Control(pDX, IDC_EDTV26, m_EdTV2[11]);
	DDX_Control(pDX, IDC_EDTV27, m_EdTV2[12]);
	DDX_Control(pDX, IDC_EDTV28, m_EdTV2[13]);
	DDX_Control(pDX, IDC_EDIT8, m_EdNum1);
	DDX_Control(pDX, IDC_EDIT9, m_EdNum2);
}


BEGIN_MESSAGE_MAP(CDlgRashodTl, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_STN_CLICKED(IDC_LAB21, OnStnClickedLab21)
//	ON_EN_KILLFOCUS(IDC_ED1, OnEnKillfocusEd1)
//	ON_EN_SETFOCUS(IDC_ED1, OnEnSetfocusEd1)
ON_WM_SYSCHAR()
ON_WM_KEYDOWN()
ON_COMMAND(ID_MY_ENTER, OnMyEnter)
END_MESSAGE_MAP()


// CDlgRashodTl message handlers

void CDlgRashodTl::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CDlgRashodTl::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

//	CDialog::OnCancel();
}

void CDlgRashodTl::OnOK()
{
	// TODO: Add your specialized code here and/or call the base class

//	CDialog::OnOK();
}

void CDlgRashodTl::SetBalkaState(int Visible)
{
	int x = SW_HIDE;
	if( Visible == 1 ) x = SW_SHOW;
	m_Lab22.ShowWindow(x);
	m_Lab23.ShowWindow(x);
	m_Lab24.ShowWindow(x);
	m_Lab25.ShowWindow(x);
	m_bevel1.ShowWindow(x);
//	m_bevel2.ShowWindow(SW_HIDE);
/*	m_n1.ShowWindow(SW_HIDE);
	m_n2.ShowWindow(SW_HIDE);
	m_n3.ShowWindow(SW_HIDE);
	m_n4.ShowWindow(SW_HIDE);*/
	m_Edb1.ShowWindow(x);
	m_Edb2.ShowWindow(x);
	m_Edb3.ShowWindow(x);
	m_Edb4.ShowWindow(x);

}

BOOL CDlgRashodTl::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	if( !iNeedBalka )
	{
		SetBalkaState(0);
	}
	m_EdNum1.QInit(10, 1);
	m_EdNum2.QInit(10, 1);

	m_EdBR1[0].QInit(100, 1);
	m_EdBR1[1].QInit(40, 1);
	m_EdBR1[2].QInit(40, 1);
	m_EdBR1[3].QInit(40, 1);
	m_EdBR1[4].QInit(10, 1);
	m_EdBR1[5].QInit(10, 1);
	m_EdBR1[6].QInit(40, 1);
	m_EdBR1[7].QInit(40, 1);

	m_EdBR1[8].QInit(100, 1);
	m_EdBR1[9].QInit(40, 1);
	m_EdBR1[10].QInit(40, 1);
	m_EdBR1[11].QInit(40, 1);
	m_EdBR1[12].QInit(10, 1);
	m_EdBR1[13].QInit(10, 1);
	m_EdBR1[14].QInit(40, 1);
	m_EdBR1[15].QInit(40, 1);

	m_EdNB1[0].QInit(100, 1);
	m_EdNB1[1].QInit(40, 1);
	m_EdNB1[2].QInit(40, 1);
	m_EdNB1[3].QInit(21, 1);
	m_EdNB1[4].QInit(31, 1);
	m_EdNB1[5].QInit(10, 1);
	m_EdNB1[6].QInit(10, 1);
	m_EdNB1[7].QInit(40, 1);
	m_EdNB1[8].QInit(40, 1);

	m_EdTV1[0].SetMode(0, 1, 3);
	m_EdTV1[1].SetMode(0, 1, 3);
	m_EdTV1[2].QInit(20, 1);
	m_EdTV1[3].QInit(20, 1);
	m_EdTV1[4].QInit(20, 1);
	m_EdTV1[5].QInit(20, 1);
	m_EdTV1[6].QInit(20, 1);
	
	m_EdTV1[7].SetMode(0, 1, 3);
	m_EdTV1[8].SetMode(0, 1, 3);
	m_EdTV1[9].QInit(20, 1);
	m_EdTV1[10].QInit(20, 1);
	m_EdTV1[11].QInit(20, 1);
	m_EdTV1[12].QInit(20, 1);
	m_EdTV1[13].QInit(20, 1);
	
	//ppppppppp

	m_EdBR2[0].QInit(100, 1);
	m_EdBR2[1].QInit(40, 1);
	m_EdBR2[2].QInit(40, 1);
	m_EdBR2[3].QInit(40, 1);
	m_EdBR2[4].QInit(10, 1);
	m_EdBR2[5].QInit(10, 1);
	m_EdBR2[6].QInit(40, 1);
	m_EdBR2[7].QInit(40, 1);

	m_EdBR2[8].QInit(100, 1);
	m_EdBR2[9].QInit(40, 1);
	m_EdBR2[10].QInit(40, 1);
	m_EdBR2[11].QInit(40, 1);
	m_EdBR2[12].QInit(10, 1);
	m_EdBR2[13].QInit(10, 1);
	m_EdBR2[14].QInit(40, 1);
	m_EdBR2[15].QInit(40, 1);

	m_EdNB2[0].QInit(100, 1);
	m_EdNB2[1].QInit(40, 1);
	m_EdNB2[2].QInit(40, 1);
	m_EdNB2[3].QInit(21, 1);
	m_EdNB2[4].QInit(31, 1);
	m_EdNB2[5].QInit(10, 1);
	m_EdNB2[6].QInit(10, 1);
	m_EdNB2[7].QInit(40, 1);
	m_EdNB2[8].QInit(40, 1);

	m_EdTV2[0].SetMode(0, 1, 3);
	m_EdTV2[1].SetMode(0, 1, 3);
	m_EdTV2[2].QInit(20, 1);
	m_EdTV2[3].QInit(20, 1);
	m_EdTV2[4].QInit(20, 1);
	m_EdTV2[5].QInit(20, 1);
	m_EdTV2[6].QInit(20, 1);
	
	m_EdTV2[7].SetMode(0, 1, 3);
	m_EdTV2[8].SetMode(0, 1, 3);
	m_EdTV2[9].QInit(20, 1);
	m_EdTV2[10].QInit(20, 1);
	m_EdTV2[11].QInit(20, 1);
	m_EdTV2[12].QInit(20, 1);
	m_EdTV2[13].QInit(20, 1);
	

	m_Edb1.QInit(100, 1);
	m_Edb2.QInit(40, 1);
	m_Edb3.QInit(40, 1);
	m_Edb4.QInit(30, 1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgRashodTl::OnStnClickedLab21()
{
	
}


void CDlgRashodTl::OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
//	AfxMessageBox("ffff");

	CDlgWithAccelerators::OnSysChar(nChar, nRepCnt, nFlags);
}

void CDlgRashodTl::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
//	AfxMessageBox("ffffag");

	CDlgWithAccelerators::OnKeyDown(nChar, nRepCnt, nFlags);
}

int CDlgRashodTl::FillTLDataByNum(CString strNumTL, int iPos)
{
	if( strNumTL == "" ) return -1;
	char cQ[128] = "";
	char cText[64] = "";
	long Ind = 0;
	int iPrDet = 0;
	CMaskEdit *m;
	DWORD dwNum = 0;
	if( iPos == 3 || iPos == 6 ) iPrDet = 1;

	switch( iPos )
	{
	case 1: m = &m_EdBR1[0]; break;
	case 2: m = &m_EdBR1[8]; break;
	case 3: m = &m_EdNB1[0]; break;

	case 4: m = &m_EdBR2[0]; break;
	case 5: m = &m_EdBR2[8]; break;
	case 6: m = &m_EdNB2[0]; break;
	}

	sprintf( cQ, "pTov_TLgetRashodStrByNDet %d, '%s', %d", g_iDep, strNumTL, iPrDet );
	DBW.ExecSQL( cQ );
	g_sqlret = DBW.Fetch();
	if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
	{
		DBW.CloseCursor();
		return 0;
	}
	// IPR
	DBW.GetData( 1, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		m[1].SetData(dwNum);
	}
	// KlPr
	DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 )
	{
		m[1].SetWindowText(cText);
	}
	// Dat_Izg
	DBW.GetData( 3, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 )
	{
		m[2].SetWindowText(cText);
	}
	// GlubPodp
	DBW.GetData( 4, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 && iPrDet )
	{
		m[5].SetWindowText(cText);
	}
	// DiamPodp
	DBW.GetData( 5, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 && iPrDet )
	{
		m[6].SetWindowText(cText);
	}
	// VosstPodp
	DBW.GetData( 6, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 && iPrDet )
	{
		m[7].SetWindowText(cText);
	}
	// Prizn_Prodl
	DBW.GetData( 7, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 )
	{
		m[8].SetWindowText(cText);
	}
	// God_Prodl
	DBW.GetData( 8, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 )
	{
		m[9].SetWindowText(cText);
	}
	// IPr_Prodl
	DBW.GetData( 9, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		m[10].SetData(dwNum);
	}
	// Kl_Prodl
	DBW.GetData( 10, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 )
	{
		m[10].SetWindowText(cText);
	}
//	DBW.GetData
	DBW.CloseCursor();
	return 1;
}

void CDlgRashodTl::OnMyEnter()
{
	if( m_EdBR1[0].iActive )
	{
		if( FillTLDataByNum(m_EdBR1[0].GetAsString(), 1) > 0)
		{
			m_EdBR1[3].SetFocus();
			return;
		}
	} else
	if( m_EdBR1[8].iActive )
	{
		if( FillTLDataByNum(m_EdBR1[8].GetAsString(), 2) > 0)
		{
			m_EdBR1[11].SetFocus();
			return;
		}
	} else
	if( m_EdNB1[0].iActive )
	{
		if( FillTLDataByNum(m_EdNB1[0].GetAsString(), 3) > 0)
		{
			m_EdNB1[3].SetFocus();
			return;
		}
	} else

	if( m_EdBR2[0].iActive )
	{
		if( FillTLDataByNum(m_EdBR2[0].GetAsString(), 4) > 0)
		{
			m_EdBR2[3].SetFocus();
			return;
		}
	} else
	if( m_EdBR2[8].iActive )
	{
		if( FillTLDataByNum(m_EdBR2[8].GetAsString(), 5) > 0)
		{
			m_EdBR2[11].SetFocus();
			return;
		}
	} else
	if( m_EdNB2[0].iActive )
	{
		if( FillTLDataByNum(m_EdNB2[0].GetAsString(), 6) > 0)
		{
			m_EdBR2[3].SetFocus();
			return;
		}
	} else
	if( m_EdBR1[5].iActive && m_EdBR1[5].GetAsDWord() < 1 )
	{
		m_EdBR1[8].SetFocus();
		return;
	} else
	if( m_EdBR1[13].iActive && m_EdBR1[13].GetAsDWord() < 1 )
	{
		m_EdNB1[0].SetFocus();
		return;
	} else
	if( m_EdNB1[6].iActive && m_EdBR1[6].GetAsDWord() < 1 )
	{
		m_EdBR2[0].SetFocus();
		return;
	} else
	if( m_EdBR2[5].iActive && m_EdBR2[5].GetAsDWord() < 1 )
	{
		m_EdBR1[8].SetFocus();
		return;
	} else
	if( m_EdBR2[13].iActive && m_EdBR2[13].GetAsDWord() < 1 )
	{
		m_EdNB2[0].SetFocus();
		return;
	} else
	if( m_EdNB2[6].iActive && m_EdBR2[6].GetAsDWord() < 1 )
	{
		m_EdTV1[0].SetFocus();
		return;
	}


	CDlgWithAccelerators::OnMyEnter();	
}
