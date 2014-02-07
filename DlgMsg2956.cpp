// DlgMsg2956.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg2956.h"
#include ".\dlgmsg2956.h"
#include "PrintableDlg.h"

extern CMasterApp theApp;
extern int g_iMessageNumber;
extern COLORREF p_crColors[6];
// CDlgMsg2956 dialog

IMPLEMENT_DYNAMIC(CDlgMsg2956, CDlgWithAccelerators)
CDlgMsg2956::CDlgMsg2956(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg2956::IDD, pParent)
{
	iFromKpBase = 0;
	ZeroMemory(&stDate, sizeof(stDate));
	qwIDS = 0;
}

CDlgMsg2956::~CDlgMsg2956()
{
}

void CDlgMsg2956::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ED2, m_Ed[0]);
	DDX_Control(pDX, IDC_ED3, m_Ed[1]);
	DDX_Control(pDX, IDC_ED4, m_Ed[2]);
	DDX_Control(pDX, IDC_ED5, m_Ed[3]);
	DDX_Control(pDX, IDC_ED6, m_Ed[4]);
	DDX_Control(pDX, IDC_ED7, m_Ed[5]);
	DDX_Control(pDX, IDC_ED8, m_Ed[6]);
	DDX_Control(pDX, IDC_ED9, m_Ed[7]);
	DDX_Control(pDX, IDC_ED10, m_Ed[8]);
	DDX_Control(pDX, IDC_ED11, m_Ed[9]);
	DDX_Control(pDX, IDC_ED12, m_Ed[10]);
	DDX_Control(pDX, IDC_ED13, m_Ed[11]);
	DDX_Control(pDX, IDC_ED14, m_Ed[12]);

	DDX_Control(pDX, IDC_E1, m_Ed2[0]);
	DDX_Control(pDX, IDC_E2, m_Ed2[1]);
	DDX_Control(pDX, IDC_E3, m_Ed2[2]);
	DDX_Control(pDX, IDC_E4, m_Ed2[3]);
	DDX_Control(pDX, IDC_E5, m_Ed2[4]);
	DDX_Control(pDX, IDC_E6, m_Ed2[5]);
	DDX_Control(pDX, IDC_E7, m_Ed2[6]);
	DDX_Control(pDX, IDC_E8, m_Ed2[7]);
	DDX_Control(pDX, IDC_E9, m_Ed2[8]);
	DDX_Control(pDX, IDC_E10, m_Ed2[9]);
	DDX_Control(pDX, IDC_E11, m_Ed2[10]);
	DDX_Control(pDX, IDC_E12, m_Ed2[11]);
	DDX_Control(pDX, IDC_E13, m_Ed2[12]);

	DDX_Control(pDX, IDC_ED15, m_Edt[0]);
	DDX_Control(pDX, IDC_ED16, m_Edt[1]);
	DDX_Control(pDX, IDC_ED17, m_Edt[2]);
	DDX_Control(pDX, IDC_ED18, m_Edt[3]);

	DDX_Control(pDX, IDC_E15, m_Edt2[0]);
	DDX_Control(pDX, IDC_E16, m_Edt2[1]);
	DDX_Control(pDX, IDC_E17, m_Edt2[2]);
	DDX_Control(pDX, IDC_E18, m_Edt2[3]);

	DDX_Control(pDX, IDC_EDIT2, m_Dat);
	DDX_Control(pDX, IDC_EDIT1, m_EdVKM);
	DDX_Control(pDX, IDC_BUTTON1, m_But);
}


BEGIN_MESSAGE_MAP(CDlgMsg2956, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButtonReport)
END_MESSAGE_MAP()


// CDlgMsg2956 message handlers

BOOL CDlgMsg2956::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_Dat.ModifyStyle(0, WS_DISABLED);
	for( int i=0; i < 3; i++ )
	{
		m_Ed[i].QInit(70, 1);
	}
	for( int i=3; i < 13; i++ )
	{
		m_Ed[i].QInit(60, 1);
	}
	for( int i=0; i < 4; i++ )
	{
		m_Edt[i].QInit(60, 1);
	}
	m_Dat.SetMode(3, 1);
	m_Dat.SetTime(&stDate);
	m_EdVKM.QInit(40,1);
	char cQ[128] = "";
	char cText[64] = "";
	long Ind = 0;

	sprintf(cQ, "pTov_S2956Sel %u, %s, %d",
				g_iDep,
				m_Dat.GetSQLDate(),
				iFromKpBase);

	//AfxMessageBox( cQ );

	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SBIGINT, &qwIDS, 8, &Ind);
	DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 )
	{
		m_EdVKM.SetWindowText(cText);
	}
	for( int i=0; i < 13; i++ )
	{
		DBW.GetData(4 + i, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 )
			m_Ed[i].SetWindowText(cText);
	}
	for( int i=0; i < 13; i++ )
	{
		DBW.GetData(17 + i, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 )
			m_Ed2[i].SetWindowText(cText); //30
	}

	for( int i=0; i < 4; i++ )
	{
		DBW.GetData(30 + i, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 )
			m_Edt[i].SetWindowText(cText);
	}
	for( int i=0; i < 4; i++ )
	{
		DBW.GetData(34 + i, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 )
			m_Edt2[i].SetWindowText(cText);
	}
	DBW.GetData(38, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 )
	{
		m_But.SetWindowText(cText);
	}
	DWORD dwNum = 0;
	DBW.GetData(39, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 && dwNum)
	{
		m_But.SetBkColor(p_crColors[dwNum]);
	}
	DBW.CloseCursor();
/*
	sprintf(cQ, "pTov_S2956Inf %I64u", qwIDS);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_But.SetWindowText(cText);
	DBW.CloseCursor();*/
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg2956::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here

	WriteMessageToBase();	
	OnOK();
}

void CDlgMsg2956::OnBnClickedButton2()
{
	char cQ[128] = "";
	char cText[4000] = "";
	long Ind = 0;
	if( WriteMessageToBase() == 0 )
	{
		sprintf(cQ, "pTov_S29xxSend %s", isNull(qwIDS));
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();

		sprintf(cQ, "pTov_S2956Form %I64u", qwIDS );
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cText, 4000, &Ind);
		DBW.CloseCursor();

		if( g_iMessageNumber )
		{	
			if( Ind != -1 )
			{
				DBW.SendMessageToTov(cText);
			}
		} else
			theApp.SendTeleMessage(cText, "S2956");
	}

	OnOK();
}

int CDlgMsg2956::WriteMessageToBase(void)
{
	char cQ[512] = "";
	long Ind = 0;
	char cText[512] = "";
	m_EdVKM.GetWindowText(cText, 10);

	sprintf( cQ, "pTov_S2956Ins %s, %d, '%s', %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d",
		isNull(qwIDS),
		g_iDep,
		cText,
		m_Dat.GetSQLDate(),

		m_Ed[0].GetString(1),
		m_Ed[1].GetString(1),
		m_Ed[2].GetString(1),
		m_Ed[3].GetString(1),
		m_Ed[4].GetString(1),

		m_Ed[5].GetString(1),
		m_Ed[6].GetString(1),
		m_Ed[7].GetString(1),
		m_Ed[8].GetString(1),
		m_Ed[9].GetString(1),

		m_Ed[10].GetString(1),
		m_Ed[11].GetString(1),
		m_Ed[12].GetString(1),

		m_Edt[0].GetString(1),
		m_Edt[1].GetString(1),
		m_Edt[2].GetString(1),
		m_Edt[3].GetString(1),

		g_iFam
		);
	__int64 qwNum = 0;
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SBIGINT, &qwNum, 8, &Ind );
	if( qwNum == -1 )
	{
		DBW.GetData(2, SQL_C_CHAR, cText, 512, &Ind );
		AfxMessageBox(cText);
		DBW.CloseCursor();
		return -1;
	} else
		qwIDS = qwNum;
	DBW.CloseCursor();
	return 0;
}

void CDlgMsg2956::OnBnClickedButton1()
{
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_S29xxInf %I64u, 2956", qwIDS);
	Dlg.DoModal();
}

void CDlgMsg2956::OnBnClickedButtonReport()
{
	char cQ[128] = "";
	sprintf(cQ, "pTov_mkcRepHtmS2956 %d, %s, %d", g_iDep, m_Dat.GetSQLDate(), iFromKpBase);
	DBW.DisplayHtmlReport(cQ);
}
