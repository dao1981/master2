// DlgRashodTl_Main.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRashodTl_Main.h"
#include ".\dlgrashodtl_main.h"
#include "DlgSpravKdr.h"
#include ".\telecom\teleI.h"

extern cd_TeleI *tele;
extern CString g_strAsldTeleName;
extern int g_iEnableTelecom;
// CDlgRashodTl_Main dialog

IMPLEMENT_DYNAMIC(CDlgRashodTl_Main, CDlgWithAccelerators)
CDlgRashodTl_Main::CDlgRashodTl_Main(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgRashodTl_Main::IDD, pParent)
{
	qwILK = 0;
	qwIDS = 0;
	i8Os = 0;
	dwVRem4624 = 0;
	ZeroMemory( &stDatPostRem, sizeof(stDatPostRem) );
	iLoaded = 0;
}

CDlgRashodTl_Main::~CDlgRashodTl_Main()
{
}

void CDlgRashodTl_Main::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
//	DDX_Control(pDX, IDC_COMBO1, m_Cb1);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT2, m_EdYrVag);
	DDX_Control(pDX, IDC_EDIT6, m_DatRem1);
/*	DDX_Control(pDX, IDC_EDIT4, m_EdHHRem1);
	DDX_Control(pDX, IDC_EDIT93, m_EdMMRem1);*/
	DDX_Control(pDX, IDC_EDIT94, m_DatRem2);
/*	DDX_Control(pDX, IDC_EDIT70, m_EdHHRem2);
	DDX_Control(pDX, IDC_EDIT129, m_EdMMRem2);*/
	DDX_Control(pDX, IDC_EDIT71, m_DatPodk);
	DDX_Control(pDX, IDC_EDIT127, m_EdFam);
	DDX_Control(pDX, IDC_EDIT130, m_EdVRem);

	DDX_Control(pDX, IDC_EDIT139, m_EdFam1);
	DDX_Control(pDX, IDC_EDIT154, m_EdFam2);
	DDX_Control(pDX, IDC_EDIT155, m_EdFam3);
	DDX_Control(pDX, IDC_EDIT156, m_EdFam4);

	DDX_Control(pDX, IDC_BUTTON1, m_bnSendToAsld);
}


BEGIN_MESSAGE_MAP(CDlgRashodTl_Main, CDlgWithAccelerators)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnTcnSelchangeTab)
	ON_EN_CHANGE(IDC_EDIT71, OnEnChangeEdit71)
	ON_BN_CLICKED(IDC_BUTTON7, OnBnClickedFam)
	ON_BN_CLICKED(IDC_BUTTON8, OnBnClickedButtonFillFrom4624)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, OnSendToASUV)
END_MESSAGE_MAP()


// CDlgRashodTl_Main message handlers

BOOL CDlgRashodTl_Main::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	TCITEM ti;

    ti.mask = TCIF_TEXT;
    ti.pszText = _T("Тележка 1-2");
	ti.lParam = (LPARAM)&m_RashodTab[0];
	VERIFY(m_RashodTab[0].Create(CDlgRashodTl::IDD, &m_Tab));
    m_Tab.InsertItem(0, &ti);
    m_RashodTab[0].SetWindowPos(NULL, 5, 22, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	m_RashodTab[0].ShowWindow(SW_SHOW);

	m_RashodTab[1].iNeedBalka = 1;
    ti.mask = TCIF_TEXT;
    ti.pszText = _T("Тележка 3-4");
	ti.lParam = (LPARAM)&m_RashodTab[1];
	VERIFY(m_RashodTab[1].Create(CDlgRashodTl::IDD, &m_Tab));
    m_Tab.InsertItem(1, &ti);
    m_RashodTab[1].SetWindowPos(NULL, 5, 22, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	
//	m_RashodTab2.ShowWindow(SW_SHOW);
/*
    ti.mask = TCIF_TEXT;
    ti.pszText = _T("Тележка 3");
	ti.lParam = (LPARAM)&m_RashodTab[2];
	VERIFY(m_RashodTab[2].Create(CDlgRashodTl::IDD, &m_Tab));
    m_Tab.InsertItem(2, &ti);
    m_RashodTab[2].SetWindowPos(NULL, 5, 22, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
//	m_RashodTab3.ShowWindow(SW_SHOW);

	m_RashodTab[3].iNeedBalka = 1;
    ti.mask = TCIF_TEXT;
    ti.pszText = _T("Тележка 4");
	ti.lParam = (LPARAM)&m_RashodTab[3];
	VERIFY(m_RashodTab[3].Create(CDlgRashodTl::IDD, &m_Tab));
    m_Tab.InsertItem(3, &ti);
    m_RashodTab[3].SetWindowPos(NULL, 5, 22, 0, 0, SWP_NOSIZE | SWP_NOZORDER);	
//	m_RashodTab4.ShowWindow(SW_SHOW);
*/
	CurWnd = &m_RashodTab[0];

//	DBW.FillComboWithTRemVag(&m_Cb1);

	m_EdNVag.QInit(100, 1);
	m_EdYrVag.QInit(40, 1);
	m_DatPodk.SetMode(1, 1);
/*	m_EdHHRem1.QInit(20, 1);
	m_EdHHRem2.QInit(20, 1);
	m_EdMMRem1.QInit(20, 1);
	m_EdMMRem2.QInit(20, 1);*/

	m_EdFam.SetMode(5, 1);
	m_EdFam1.SetMode(5, 1);
	m_EdFam2.SetMode(5, 1);
	m_EdFam3.SetMode(5, 1);
	m_EdFam4.SetMode(5, 1);

	DBW.FillEmplArray(m_EdFam.lpEmpl, 17);

	FillForm();
	if( i8Os )
	{
		m_RashodTab[0].SetBalkaState(1);
		m_RashodTab[1].SetBalkaState(1);

	}
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgRashodTl_Main::OnTcnSelchangeTab(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	CurWnd->ShowWindow(SW_HIDE);
	switch(m_Tab.GetCurSel())
	{
	case 0:
		m_RashodTab[0].ShowWindow(SW_SHOW);
		CurWnd = &m_RashodTab[0];
		break;
	case 1:
		m_RashodTab[1].ShowWindow(SW_SHOW);
		CurWnd = &m_RashodTab[1];
		break;
/*	case 2:
		m_RashodTab[2].ShowWindow(SW_SHOW);
		CurWnd = &m_RashodTab[2];
		break;
	case 3:
		m_RashodTab[3].ShowWindow(SW_SHOW);
		CurWnd = &m_RashodTab[3];
		break;
*/
	}
	*pResult = 0;
}

void CDlgRashodTl_Main::OnEnChangeEdit71()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CDlgRashodTl_Main::OnBnClickedFam()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 17;
	Dlg.DlgMode = 1;

	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFam.SetWindowText(Dlg.cFio);
	m_EdFam.SetData(Dlg.dwFio);
}

void CDlgRashodTl_Main::OnBnClickedButtonFillFrom4624()
{
	char cText[64] = "";
	char cQ[200] = "";
	int i=0;
	long Ind  = 0;
	if( qwIDS )
	{ 
//		sprintf( cQ, "pTov_S4624SelTL %I64u, %d, %I64u", qwIDS, 4, qwILK);
		sprintf( cQ, "pTov_S4624SelTL %I64u, %d, %I64u", qwIDS, m_EdVRem.GetData(), qwILK);
		DBW.ExecSQL(cQ);
		for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && ((i < 2 && i8Os) || i < 1 ); i++ )
		{
			DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNum1.SetWindowText(cText);

			DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB1[1].SetWindowText(cText);
			DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB1[0].SetWindowText(cText);
			DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB1[2].SetWindowText(cText);
			DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB1[3].SetWindowText(cText);
			DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB1[4].SetWindowText(cText);
			DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB1[5].SetWindowText(cText);
			DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB1[7].SetWindowText(cText);
			DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB1[8].SetWindowText(cText);	

			DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[9].SetWindowText(cText);
			DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[8].SetWindowText(cText);
			DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[10].SetWindowText(cText);
			DBW.GetData(17, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[11].SetWindowText(cText);
			DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[12].SetWindowText(cText);
	/*		DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[13].SetWindowText(cText);*/
			DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[14].SetWindowText(cText);
			DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[15].SetWindowText(cText);
			
			DBW.GetData(24, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[1].SetWindowText(cText);
			DBW.GetData(25, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[0].SetWindowText(cText);
			DBW.GetData(26, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[2].SetWindowText(cText);
			DBW.GetData(27, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[3].SetWindowText(cText);
			DBW.GetData(28, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[4].SetWindowText(cText);
	/*		DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[5].SetWindowText(cText);*/
			DBW.GetData(29, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[6].SetWindowText(cText);
			DBW.GetData(30, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR1[7].SetWindowText(cText);
			
			DBW.Fetch();
			// Тележка номер 2
			DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNum2.SetWindowText(cText);
			DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB2[1].SetWindowText(cText);
			DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB2[0].SetWindowText(cText);
			DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB2[2].SetWindowText(cText);
			DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB2[3].SetWindowText(cText);
			DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB2[4].SetWindowText(cText);
			DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB2[5].SetWindowText(cText);
			DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB2[7].SetWindowText(cText);
			DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdNB2[8].SetWindowText(cText);

			DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[9].SetWindowText(cText);
			DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[8].SetWindowText(cText);
			DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[10].SetWindowText(cText);
			DBW.GetData(17, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[11].SetWindowText(cText);
			DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[12].SetWindowText(cText);
	/*		DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[13].SetWindowText(cText);*/
			DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[14].SetWindowText(cText);
			DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[15].SetWindowText(cText);
			
			DBW.GetData(24, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[1].SetWindowText(cText);
			DBW.GetData(25, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[0].SetWindowText(cText);
			DBW.GetData(26, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[2].SetWindowText(cText);
			DBW.GetData(27, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[3].SetWindowText(cText);
			DBW.GetData(28, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[4].SetWindowText(cText);
	/*		DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[5].SetWindowText(cText);*/
			DBW.GetData(29, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[6].SetWindowText(cText);
			DBW.GetData(30, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdBR2[7].SetWindowText(cText);
		}
		DBW.CloseCursor();
		
//		sprintf(cQ, "pTov_S4624SelTLVag %I64u, %d, %I64u", qwIDS, 4, qwILK);
		sprintf(cQ, "pTov_S4624SelTLVag %I64u, %d, %I64u", qwIDS, m_EdVRem.GetData(), qwILK);
		DBW.ExecSQL( cQ );			
		for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && ((i < 2 && i8Os) || i < 1 ); i++ )
		{			

			DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[0].SetWindowText(cText);

			DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[1].SetWindowText(cText);

			DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[2].SetWindowText(cText);

			DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[3].SetWindowText(cText);

			DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[4].SetWindowText(cText);

			DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[5].SetWindowText(cText);

			DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[6].SetWindowText(cText);

			// правая
			DBW.GetData(12, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[7].SetWindowText(cText);

			DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[8].SetWindowText(cText);

			DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[9].SetWindowText(cText);

			DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[10].SetWindowText(cText);

			DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[11].SetWindowText(cText);

			DBW.GetData(17, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[12].SetWindowText(cText);

			DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV1[13].SetWindowText(cText);
			
			// Тележка 2
			DBW.Fetch();
			DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[0].SetWindowText(cText);

			DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[1].SetWindowText(cText);

			DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[2].SetWindowText(cText);

			DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[3].SetWindowText(cText);

			DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[4].SetWindowText(cText);

			DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[5].SetWindowText(cText);

			DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[6].SetWindowText(cText);

			// правая
			DBW.GetData(12, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[7].SetWindowText(cText);

			DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[8].SetWindowText(cText);

			DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[9].SetWindowText(cText);

			DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[10].SetWindowText(cText);

			DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[11].SetWindowText(cText);

			DBW.GetData(17, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[12].SetWindowText(cText);

			DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_RashodTab[i].m_EdTV2[13].SetWindowText(cText);

		}		

		DBW.CloseCursor();
	}
}

void CDlgRashodTl_Main::FillForm(void)
{
	char cQ[128] = "";
	char cText[64] = "";
	long Ind = 0;
	DWORD dwNum = 0;
	SYSTEMTIME st;

// ЗАГОЛОВОК
	sprintf( cQ, "pTov_TLgetVagRashod %I64u", qwILK );
	DBW.ExecSQL( cQ );
	DBW.Fetch();

	DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdNVag.SetWindowText(cText);

	DBW.GetData(2, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_EdVRem.SetData(dwNum);

	DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdVRem.SetWindowText(cText);

	DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdYrVag.SetWindowText(cText);
/*	mgSQLGetSysDate(4, &st, &Ind );
	if( Ind != -1 ) m_DatRem1.SetTime(&st);*/

	mgSQLGetSysDate(5, &stDatPostRem, &Ind );
	if( Ind != -1 ) m_DatRem1.SetTime(&stDatPostRem);

	mgSQLGetSysDate(6, &st, &Ind );
	if( Ind != -1 ) m_DatRem2.SetTime(&st);

	mgSQLGetSysDate(7, &st, &Ind );
	if( Ind != -1 ) m_DatPodk.SetTime(&st);


	DBW.GetData(8, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_EdFam.SetData(dwNum);
	DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdFam.SetWindowText(cText);

	DBW.GetData(10, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_EdFam1.SetData(dwNum);
	DBW.GetData(11, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdFam1.SetWindowText(cText);

	DBW.GetData(12, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_EdFam2.SetData(dwNum);
	DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdFam2.SetWindowText(cText);

	DBW.GetData(14, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_EdFam3.SetData(dwNum);
	DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdFam3.SetWindowText(cText);

	DBW.GetData(16, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_EdFam4.SetData(dwNum);
	DBW.GetData(17, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdFam4.SetWindowText(cText);

	DBW.GetData(18, SQL_C_ULONG, &i8Os, 4, &Ind );
	DBW.GetData(19, SQL_C_UBIGINT, &qwIDS, 8, &Ind );

	DBW.GetData(20, SQL_C_ULONG, &dwVRem4624, 4, &Ind );

	DBW.CloseCursor();

	if( !i8Os ) 
	{
		m_Tab.DeleteItem(1);
//		m_Tab.DeleteItem(2);
	}
	int iCol = 1;
	cText[0] = 0;
	sprintf(cQ, "pTov_TLgetVagRashodInf %I64u", qwILK);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdNum1.SetWindowText(cText);
	iCol++;
	// Левая БР - ЛДТл
	//Номер
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR1[0].SetWindowText(cText);
	//завод ИПР
	iCol++;
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR1[1].SetData(dwNum);
	iCol++;
	for( int x = 1; x < 7; x++ )
	{
		DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_RashodTab[0].m_EdBR1[x].SetWindowText(cText);
		iCol++;
	}
	//продление ИПР
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR1[7].SetData(dwNum);
	iCol++;
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR1[7].SetWindowText(cText);
	iCol++;
	// Правая БР
	//Номер
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR1[8].SetWindowText(cText);
	//завод ИПР
	iCol++;
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR1[9].SetData(dwNum);
	iCol++;
	
	for( int x = 9; x < 15; x++ )
	{
		DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_RashodTab[0].m_EdBR1[x].SetWindowText(cText);
		iCol++;
	}
	//продление ИПР
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR1[15].SetData(dwNum);
	iCol++;
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR1[15].SetWindowText(cText);
	iCol++;
	// Надр балка
	//Номер
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdNB1[0].SetWindowText(cText);
	//завод ИПР
	iCol++;
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdNB1[1].SetData(dwNum);
	iCol++;
	
	for( int x = 1; x < 8; x++ )
	{
		DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_RashodTab[0].m_EdNB1[x].SetWindowText(cText);
		iCol++;
	}
	//продление ИПР
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdNB1[8].SetData(dwNum);
	iCol++;
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdNB1[8].SetWindowText(cText);
	iCol++;
	
	// Левая БР - Под Вагон
	for( int x = 0; x < 14; x++ )
	{
		DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_RashodTab[0].m_EdTV1[x].SetWindowText(cText);
		iCol++;
	}
// теперь тот же фокус со второй полофиной формы
	iCol=1;
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdNum2.SetWindowText(cText);
	iCol++;
	// Левая БР - ЛДТл
	//Номер
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR2[0].SetWindowText(cText);
	//завод ИПР
	iCol++;
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR2[1].SetData(dwNum);
	iCol++;
	for( int x = 1; x < 7; x++ )
	{
		DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_RashodTab[0].m_EdBR2[x].SetWindowText(cText);
		iCol++;
	}
	//продление ИПР
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR2[7].SetData(dwNum);
	iCol++;
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR2[7].SetWindowText(cText);
	iCol++;
	// Правая БР
	//Номер
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR2[8].SetWindowText(cText);
	//завод ИПР
	iCol++;
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR2[9].SetData(dwNum);
	iCol++;
	
	for( int x = 9; x < 15; x++ )
	{
		DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_RashodTab[0].m_EdBR2[x].SetWindowText(cText);
		iCol++;
	}
	//продление ИПР
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR2[15].SetData(dwNum);
	iCol++;
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdBR2[15].SetWindowText(cText);
	iCol++;
	// Надр балка
	//Номер
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdNB2[0].SetWindowText(cText);
	//завод ИПР
	iCol++;
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdNB2[1].SetData(dwNum);
	iCol++;
	
	for( int x = 1; x < 8; x++ )
	{
		DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_RashodTab[0].m_EdNB2[x].SetWindowText(cText);
		iCol++;
	}
	//продление ИПР
	DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdNB2[8].SetData(dwNum);
	iCol++;
	DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_RashodTab[0].m_EdNB2[8].SetWindowText(cText);
	iCol++;
	
	// Левая БР - Под Вагон
	for( int x = 0; x < 14; x++ )
	{
		DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_RashodTab[0].m_EdTV2[x].SetWindowText(cText);
		iCol++;
	}
	DBW.CloseCursor();
	
}



void CDlgRashodTl_Main::GetIPR( CMaskEdit *m )
{
	char cQ[128] = "";
	long Ind = 0;
	DWORD dwNum = 0;

	sprintf(cQ, "pTov_GetPrByKl '%s'", m->GetString());
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 && m ) m->SetData(dwNum);
	DBW.CloseCursor();
}

int CDlgRashodTl_Main::SaveData()
{
	char cScriptDeclare[1512] = "";
	char cProc1[512] = "";
	char cProc2[512] = "";
	char cScript[5000] = "";
	
	GetIPR( &m_RashodTab[0].m_EdBR1[1] );
	GetIPR( &m_RashodTab[0].m_EdBR1[9] );
	GetIPR( &m_RashodTab[0].m_EdNB1[1] );

	GetIPR( &m_RashodTab[0].m_EdBR2[1] );
	GetIPR( &m_RashodTab[0].m_EdBR2[9] );
	GetIPR( &m_RashodTab[0].m_EdNB2[1] );

	GetIPR( &m_RashodTab[0].m_EdBR1[7] );
	GetIPR( &m_RashodTab[0].m_EdBR1[15] );
	GetIPR( &m_RashodTab[0].m_EdNB1[8] );

	GetIPR( &m_RashodTab[0].m_EdBR2[7] );
	GetIPR( &m_RashodTab[0].m_EdBR2[15] );
	GetIPR( &m_RashodTab[0].m_EdNB2[8] );

	if( m_RashodTab[0].m_EdBR1[	5].GetAsDWord() == 1 )
	{
		if( m_RashodTab[0].m_EdBR1[6].isNull() )
		{
			AfxMessageBox("Необходимо указать год окончания нового срока службы!");
			m_RashodTab[0].m_EdBR1[6].SetFocus();
			return -1;
		}
		if( m_RashodTab[0].m_EdBR1[7].isNull() )
		{
			AfxMessageBox("Необходимо указать клеймо предприятия продления срока службы!");
			m_RashodTab[0].m_EdBR1[7].SetFocus();
			return -1;
		}
	}
	
	if( m_RashodTab[0].m_EdBR1[13].GetAsDWord() == 1 )
	{
		if( m_RashodTab[0].m_EdBR1[14].isNull() )
		{
			AfxMessageBox("Необходимо указать год окончания нового срока службы!");
			m_RashodTab[0].m_EdBR1[14].SetFocus();
			return -1;
		}
		if( m_RashodTab[0].m_EdBR1[15].isNull() )
		{
			AfxMessageBox("Необходимо указать клеймо предприятия продления срока службы!");
			m_RashodTab[0].m_EdBR1[15].SetFocus();
			return -1;
		}
	}

	if( m_RashodTab[0].m_EdNB1[6].GetAsDWord() == 1 )
	{
		if( m_RashodTab[0].m_EdBR1[7].isNull() )
		{
			AfxMessageBox("Необходимо указать год окончания нового срока службы!");
			m_RashodTab[0].m_EdBR1[7].SetFocus();
			return -1;
		}
		if( m_RashodTab[0].m_EdBR1[8].isNull() )
		{
			AfxMessageBox("Необходимо указать клеймо предприятия продления срока службы!");
			m_RashodTab[0].m_EdBR1[8].SetFocus();
			return -1;
		}
	}

	if( m_RashodTab[0].m_EdBR2[5].GetAsDWord() == 1 )
	{
		if( m_RashodTab[0].m_EdBR2[6].isNull() )
		{
			AfxMessageBox("Необходимо указать год окончания нового срока службы!");
			m_RashodTab[0].m_EdBR2[6].SetFocus();
			return -1;
		}
		if( m_RashodTab[0].m_EdBR2[7].isNull() )
		{
			AfxMessageBox("Необходимо указать клеймо предприятия продления срока службы!");
			m_RashodTab[0].m_EdBR2[7].SetFocus();
			return -1;
		}
	}
	
	if( m_RashodTab[0].m_EdBR2[13].GetAsDWord() == 1 )
	{
		if( m_RashodTab[0].m_EdBR2[14].isNull() )
		{
			AfxMessageBox("Необходимо указать год окончания нового срока службы!");
			m_RashodTab[0].m_EdBR2[14].SetFocus();
			return -1;
		}
		if( m_RashodTab[0].m_EdBR2[15].isNull() )
		{
			AfxMessageBox("Необходимо указать клеймо предприятия продления срока службы!");
			m_RashodTab[0].m_EdBR1[15].SetFocus();
			return -1;
		}
	}

	if( m_RashodTab[0].m_EdNB2[6].GetAsDWord() == 1 )
	{
		if( m_RashodTab[0].m_EdBR2[7].isNull() )
		{
			AfxMessageBox("Необходимо указать год окончания нового срока службы!");
			m_RashodTab[0].m_EdBR2[7].SetFocus();
			return -1;
		}
		if( m_RashodTab[0].m_EdBR2[8].isNull() )
		{
			AfxMessageBox("Необходимо указать клеймо предприятия продления срока службы!");
			m_RashodTab[0].m_EdBR2[8].SetFocus();
			return -1;
		}
	}


	sprintf(cScriptDeclare, "\tdeclare @IDep int,@NVag varchar(8),@IdRem int,@Dat datetime\n\
\tset @IDep=%d set @NVag=%s set @IdRem=%d set @Dat=%s\n\n\
set nocount on\n\
begin tran\n\
  \tcreate table #reslt ( ILK bigint, IZapTL1 bigint, IZapTL2 bigint, IZapTL3 bigint, IZapTL4 bigint)\n\
  \tcreate table #KodReslt ( Kod int, StringRez varchar(2000))\n\
  \tdeclare @ILK bigint,\n\
        \t\t@IZapTL1 bigint, @IZapTL2 bigint, @IZapTL3 bigint, @IZapTL4 bigint\n\
  \tinsert into #reslt\n\
 \texecute pTov_GetILKbyNVag @IDep, @NVag, @IdRem, @Dat, 1 --для расхода в конце 1\n\
  \tselect @ILK = ILK,\n\
 \t@IZapTL1=IZapTL1, @IZapTL2=IZapTL2, @IZapTL3=IZapTL3, @IZapTL4=IZapTL4\n\
 \tfrom #reslt\n\
  \tif( @ILK > 0 )\n\
  \tbegin\n\
 \t--print '@ILK='+ isnull(Str (@ILK, 7), 'null')\n\
        \t\t--для расхода pTov_TLRashodToVag вместо pTov_TLPrihodFromVag\n\
 insert into #KodReslt\n",
		g_iDep,
		m_EdNVag.GetString(1),
		m_EdVRem.GetData(),
		DateToSQL(stDatPostRem));


	sprintf(cProc1, "exec pTov_TLRashodToVag @ILK, @IDep, @IZapTL1, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
		// ILK
		// IDEP
		// IZAP_TL1
		m_DatRem1.GetSQLDate(),
		m_RashodTab[0].m_EdNum1.GetString(),
		isNull(m_EdFam.GetData()),
		// Левая боковая рама
		m_RashodTab[0].m_EdBR1[0].GetString(),
		isNull(m_RashodTab[0].m_EdBR1[1].GetData()),
		m_RashodTab[0].m_EdBR1[2].GetString(),
		m_RashodTab[0].m_EdBR1[3].GetString(),
		m_RashodTab[0].m_EdBR1[4].GetString(),
		m_RashodTab[0].m_EdBR1[5].GetString(),
		isNull(m_RashodTab[0].m_EdBR1[6].GetAsDWord()),
		isNull(m_RashodTab[0].m_EdBR1[7].GetData()),

		// Правая боковая рама
		m_RashodTab[0].m_EdBR1[8].GetString(),
		isNull(m_RashodTab[0].m_EdBR1[9].GetData()),
		m_RashodTab[0].m_EdBR1[10].GetString(),
		m_RashodTab[0].m_EdBR1[11].GetString(),
		m_RashodTab[0].m_EdBR1[12].GetString(),
		m_RashodTab[0].m_EdBR1[13].GetString(),
		isNull(m_RashodTab[0].m_EdBR1[14].GetAsDWord()),
		isNull(m_RashodTab[0].m_EdBR1[15].GetData()),

		// Надрессорная балка
		m_RashodTab[0].m_EdNB1[0].GetString(),
		isNull(m_RashodTab[0].m_EdNB1[1].GetData()),
		m_RashodTab[0].m_EdNB1[2].GetString(),
		m_RashodTab[0].m_EdNB1[3].GetString(),
		m_RashodTab[0].m_EdNB1[4].GetString(),
		m_RashodTab[0].m_EdNB1[5].GetString(),
		m_RashodTab[0].m_EdNB1[6].GetString(),
		isNull(m_RashodTab[0].m_EdNB1[7].GetAsDWord()),
		isNull(m_RashodTab[0].m_EdNB1[8].GetData()),

		// Левая сторона тележки
		m_RashodTab[0].m_EdTV1[0].GetString(),
		m_RashodTab[0].m_EdTV1[1].GetString(),
		m_RashodTab[0].m_EdTV1[2].GetString(),
		m_RashodTab[0].m_EdTV1[3].GetString(),
		m_RashodTab[0].m_EdTV1[4].GetString(),
		m_RashodTab[0].m_EdTV1[5].GetString(),
		m_RashodTab[0].m_EdTV1[6].GetString(),
		// Правая сторона тележки	
		m_RashodTab[0].m_EdTV1[7].GetString(),
		m_RashodTab[0].m_EdTV1[8].GetString(),
		m_RashodTab[0].m_EdTV1[9].GetString(),
		m_RashodTab[0].m_EdTV1[10].GetString(),
		m_RashodTab[0].m_EdTV1[11].GetString(),
		m_RashodTab[0].m_EdTV1[12].GetString(),
		m_RashodTab[0].m_EdTV1[13].GetString());


	sprintf(cProc2, "exec pTov_TLRashodToVag @ILK, @IDep, @IZapTL2, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
		m_DatRem1.GetSQLDate(),
		m_RashodTab[0].m_EdNum2.GetString(),
		isNull( m_EdFam.GetData() ),
				
		// Левая боковая рама
		m_RashodTab[0].m_EdBR2[0].GetString(),
		isNull(m_RashodTab[0].m_EdBR2[1].GetData()),
		m_RashodTab[0].m_EdBR2[2].GetString(),
		m_RashodTab[0].m_EdBR2[3].GetString(),
		m_RashodTab[0].m_EdBR2[4].GetString(),
		m_RashodTab[0].m_EdBR2[5].GetString(),
		isNull(m_RashodTab[0].m_EdBR2[6].GetAsDWord()),
		isNull(m_RashodTab[0].m_EdBR2[7].GetData()),
		// Правая боковая рама
		m_RashodTab[0].m_EdBR2[8].GetString(),
		isNull(m_RashodTab[0].m_EdBR2[9].GetData()),
		m_RashodTab[0].m_EdBR2[10].GetString(),
		m_RashodTab[0].m_EdBR2[11].GetString(),
		m_RashodTab[0].m_EdBR2[12].GetString(),
		m_RashodTab[0].m_EdBR2[13].GetString(),
		isNull(m_RashodTab[0].m_EdBR2[14].GetAsDWord()),
		isNull(m_RashodTab[0].m_EdBR2[15].GetData()),
		// Надрессорная балка
		m_RashodTab[0].m_EdNB2[0].GetString(),
		isNull(m_RashodTab[0].m_EdNB2[1].GetData()),
		m_RashodTab[0].m_EdNB2[2].GetString(),
		m_RashodTab[0].m_EdNB2[3].GetString(),
		m_RashodTab[0].m_EdNB2[4].GetString(),
		m_RashodTab[0].m_EdNB2[5].GetString(),
		m_RashodTab[0].m_EdNB2[6].GetString(),
		isNull(m_RashodTab[0].m_EdNB2[7].GetAsDWord()),
		isNull(m_RashodTab[0].m_EdNB2[8].GetData()),
		// Левая сторона тележки
		m_RashodTab[0].m_EdTV2[0].GetString(),
		m_RashodTab[0].m_EdTV2[1].GetString(),
		m_RashodTab[0].m_EdTV2[2].GetString(),
		m_RashodTab[0].m_EdTV2[3].GetString(),
		m_RashodTab[0].m_EdTV2[4].GetString(),
		m_RashodTab[0].m_EdTV2[5].GetString(),
		m_RashodTab[0].m_EdTV2[6].GetString(),
		// Правая сторона тележки
		m_RashodTab[0].m_EdTV2[7].GetString(),
		m_RashodTab[0].m_EdTV2[8].GetString(),
		m_RashodTab[0].m_EdTV2[9].GetString(),
		m_RashodTab[0].m_EdTV2[10].GetString(),
		m_RashodTab[0].m_EdTV2[11].GetString(),
		m_RashodTab[0].m_EdTV2[12].GetString(),
		m_RashodTab[0].m_EdTV2[13].GetString());

	sprintf(cScript, "%s %s\n\tinsert into #KodReslt\n\t%s\n\
\tif exists (select Kod from #KodReslt where Kod<0)\n\
        \tbegin\n\
        \t\tselect -1, StringRez from #KodReslt where Kod<0\n\
        \t\tdrop table #reslt\n\
        \t\tdrop table #KodReslt\n\
        \t\trollback\n\
        \t\treturn\n\
        \tend\n\
  \tend\n\
 drop table #reslt\n\
 drop table #KodReslt\n\
  COMMIT TRAN\n\
  select 0\n", cScriptDeclare, cProc1, cProc2);

	int iRet = 0;
	char cMess[1024] = "";
	long Ind = 0;
	DBW.WriteLog(cScript);

	DBW.ExecSQL(cScript);
	DBW.Fetch();
	DBW.GetData( 1, SQL_C_SLONG, &iRet, 4, &Ind );
	if( iRet == -1 )
	{
		DBW.GetData( 2, SQL_C_CHAR, cMess, 1024, &Ind );
		AfxMessageBox(cMess);
		DBW.CloseCursor();
		DBW.ReallocHandle();
		return -1;
	}
	DBW.CloseCursor();
	DBW.ReallocHandle();
	return 0;
}

void CDlgRashodTl_Main::OnBnClickedOk()
{
	if( !SaveData() ) OnOK();

}



void CDlgRashodTl_Main::OnSendToASUV()
{
	if( SaveData() ) return;
	

	if( g_iEnableTelecom && g_strAsldTeleName )
	{
		
		DWORD dwRet = 0;
		char cText[2255] = "";
			char cQ[128] = "";
			char msg[200] = "";
				sprintf( cQ, "pTov_TL_SendToASUV_NB %s", isNull(qwILK) );		
				DBW.ExecSQL( cQ );
				DBW.Fetch();
				DBW.GetData(1, SQL_C_CHAR, cText, 2255, &Ind);
				if( strcmp( cText, "-1" ) == 0 )
				{
					DBW.GetData(2, SQL_C_CHAR, cText, 2255, &Ind);
					DBW.CloseCursor();
					AfxMessageBox( cText );
					return;
				}			
				DBW.CloseCursor();
						
				sprintf(msg, "Отправка данных в АС ЛД (%s)", g_strAsldTeleName ) ;
				DBW.WriteLog((char *)msg);
				CString snd = (CString)"<tov><asld docid=\"1\">\n" + cText + (CString) "\n</asld></tov>";
				//DBW.SendMessageToDst( snd, "mkc", g_strAisldTeleName );
				if( tele ) 
				{
							tele->SendMessageDst(snd, &g_strAsldTeleName);	
							//AfxMessageBox("Данные отправлены в АСЛД!");
							m_bnSendToAsld.EnableWindow(0);
				}

				sprintf( cQ, "pTov_TL_SendToASUV_BR %s", isNull(qwILK) );		
				DBW.ExecSQL( cQ );
				DBW.Fetch();
				DBW.GetData(1, SQL_C_CHAR, cText, 2255, &Ind);
				if( strcmp( cText, "-1" ) == 0 )
				{
					DBW.GetData(2, SQL_C_CHAR, cText, 2255, &Ind);
					DBW.CloseCursor();
					AfxMessageBox( cText );
					return;
				}			
				DBW.CloseCursor();
				
				sprintf(msg, "Отправка данных в АС ЛД (%s)", g_strAsldTeleName ) ;
				DBW.WriteLog((char *)msg);
				snd = (CString)"<tov><asld docid=\"1\">\n" + cText + (CString) "\n</asld></tov>";
				//DBW.SendMessageToDst( snd, "mkc", g_strAisldTeleName );
				if( tele ) 
				{
							tele->SendMessageDst(snd, &g_strAsldTeleName);	
							AfxMessageBox("Данные отправлены в АСЛД!");
							m_bnSendToAsld.EnableWindow(0);
				}
	} else
	{
		AfxMessageBox("Невозможно отправить в АСЛД из-за некорректных настроек телеобработки!");
	}
	
}
