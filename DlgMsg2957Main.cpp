// DlgMsg2957Main.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg2957Main.h"
#include ".\dlgmsg2957main.h"
#include "PrintableDlg.h"

// CDlgMsg2957Main dialog

extern CMasterApp theApp;
extern int g_iMessageNumber;
extern CDlgMsg2957Main *mainw;
extern COLORREF p_crColors[6];

IMPLEMENT_DYNAMIC(CDlgMsg2957Main, CDialog)
CDlgMsg2957Main::CDlgMsg2957Main(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMsg2957Main::IDD, pParent)
{
	iFromKpBase = 0;
	ZeroMemory(&stDate, sizeof(stDate));
	qwIDS = 0;
	mainw = this;
}

CDlgMsg2957Main::~CDlgMsg2957Main()
{
}

void CDlgMsg2957Main::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	DDX_Control(pDX, IDC_EDIT1, m_Dat);
	DDX_Control(pDX, IDC_EDIT2, m_EdPr);
	DDX_Control(pDX, IDC_BUTTON1, m_BnSost);
}


BEGIN_MESSAGE_MAP(CDlgMsg2957Main, CDialog)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
END_MESSAGE_MAP()


// CDlgMsg2957Main message handlers

BOOL CDlgMsg2957Main::OnInitDialog()
{
	CDialog::OnInitDialog();

	TCITEM ti;

    ti.mask = TCIF_TEXT;
    ti.pszText = _T("Ю1 – Поступление и ремонт КП");
    ti.lParam = (LPARAM)&Tab1;
	VERIFY(Tab1.Create(CDlgMsg2957_1::IDD, &m_Tab));
    m_Tab.InsertItem(0, &ti);
    Tab1.SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

    ti.mask = TCIF_TEXT;
    ti.pszText = _T("Ю2 - Расход и остаток КП");
    ti.lParam = (LPARAM)&Tab2;
	VERIFY(Tab2.Create(CDlgMsg2957_2::IDD, &m_Tab));
    m_Tab.InsertItem(1, &ti);
    Tab2.SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	CurWnd = &Tab1;
	Tab1.m_Ed[1][1].SetFocus();
	Tab1.ShowWindow(SW_SHOW);

	m_Dat.SetMode(3, 1);
	m_Dat.SetTime(&stDate);
	m_Dat.ModifyStyle(0, WS_DISABLED);
	m_EdPr.QInit(40,1);
	
	Tab1.m_Ed[0][0].SetWindowText("101 - Всего");
	Tab1.m_Ed[0][1].SetWindowText("102 - Пас. РУ1-950мм");
	Tab1.m_Ed[0][2].SetWindowText("103 - Пас. РУ1Ш-950мм");
	Tab1.m_Ed[0][3].SetWindowText("104 - Пас. с ред.");
	Tab1.m_Ed[0][4].SetWindowText("105 - Груз. РУ1-950мм");
	Tab1.m_Ed[0][5].SetWindowText("106 - Груз. РУ-950мм");
	Tab1.m_Ed[0][6].SetWindowText("107 - Груз. РУ1Ш-950мм");

	Tab2.m_Ed[0][0].SetWindowText("201 - Всего");
	Tab2.m_Ed[0][1].SetWindowText("202 - Пас. РУ1-950мм");
	Tab2.m_Ed[0][2].SetWindowText("203 - Пас. РУ1Ш-950мм");
	Tab2.m_Ed[0][3].SetWindowText("204 - Пас. с ред.");
	Tab2.m_Ed[0][4].SetWindowText("205 - Груз. РУ1-950мм");
	Tab2.m_Ed[0][5].SetWindowText("206 - Груз. РУ-950мм");
	Tab2.m_Ed[0][6].SetWindowText("207 - Груз. РУ1Ш-950мм");

	for( int i=0; i < 7; i++ ) 
	{
		Tab1.m_Ed[0][i].ModifyStyle(0, WS_DISABLED);
		Tab2.m_Ed[0][i].ModifyStyle(0, WS_DISABLED);
	}
	for( int i=0; i < 10; i++ )
		Tab1.m_Ed[i][0].ModifyStyle(0, WS_DISABLED);
	for( int i=0; i < 13; i++ )
		Tab2.m_Ed[i][0].ModifyStyle(0, WS_DISABLED);

	for( int i=0; i < 7; i++ )
	{
		Tab1.m_EdRas[0][i].ModifyStyle(0, WS_DISABLED);
		Tab1.m_EdRas[1][i].ModifyStyle(0, WS_DISABLED);
	}

	FillForm();
	Tab1.SetFocus();
	Tab1.m_Ed[1][1].SetFocus();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg2957Main::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	CurWnd->ShowWindow(SW_HIDE);
	switch(m_Tab.GetCurSel() )
	{
	case 0:
		CurWnd=&Tab1;
		Tab1.m_Ed[1][1].SetFocus();
		break;
	case 1:
		Tab2.m_Ed[1][1].SetFocus();
		CurWnd=&Tab2;
		break;
	}
	
	CurWnd->ShowWindow(SW_SHOW);

	*pResult = 0;
}

void CDlgMsg2957Main::FillForm(void)
{
	char cQ[512] = "";
	char cText[264] = "";
	long Ind = 0;
	sprintf(cQ, "pTov_S2957SelSL %d, %s", g_iDep, m_Dat.GetSQLDate());
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_UBIGINT, &qwIDS, 8, &Ind );
	DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 )
	{
		m_EdPr.SetWindowText(cText);
	}
	DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 )
		m_BnSost.SetWindowText(cText);
	DWORD dwNum = 0;
	DBW.GetData(4, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 && dwNum)
	{
		m_BnSost.SetBkColor(p_crColors[dwNum]);
	}
	DBW.CloseCursor();
/*
	if( !qwIDS )
	{
		AfxMessageBox("Ошибка выборки
	}
*/
	sprintf( cQ, "pTov_S2957SelOst %d, %s", g_iDep, m_Dat.GetSQLDate());
	DBW.ExecSQL(cQ);
	for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 7; i++ )
	{
		DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) Tab1.m_EdRas[0][i].SetWindowText(cText);
		DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) Tab1.m_EdRas[1][i].SetWindowText(cText);
	}
	DBW.CloseCursor();

	if( !qwIDS && !iFromKpBase) 
	{
		DBW.WriteLog("IDS = NULL");

		for( int i=1; i < 10; i++ )
		{
			for( int j=0; j < 7; j++ )			
				Tab1.m_Ed[i][j].SetWindowText("0");
		}
		for( int i=1; i < 13; i++ )
		{
			for( int j=0; j < 7; j++ )			
				Tab2.m_Ed[i][j].SetWindowText("0");
		}
		return;
	}

	if( !iFromKpBase)
	{
		sprintf(cQ, "pTov_S2957SelInf1 %s", isNull(qwIDS));
	} else
	{
		sprintf(cQ, "pTov_S2957SelBD1 %s, %s", isNull(g_iDep), m_Dat.GetSQLDate());
	}
		int nField = 1;
//		sprintf(cQ, "pTov_S2957SelInf1 %s", isNull(qwIDS));
		DBW.ExecSQL(cQ);
		for( int i=1; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 7; i++ )
		{
			nField = 1;
			for( int j=1; j < 10; j++ )
			{
				DBW.GetData(nField, SQL_C_CHAR, cText, 64, &Ind);
				if( Ind != -1 )
				{
					Tab1.m_Ed[j][i].SetWindowText(cText);
				}
				nField++;
			}
		}		
		DBW.CloseCursor();


	if( !iFromKpBase)
	{
		sprintf(cQ, "pTov_S2957SelInf2 %s", isNull(qwIDS));		
	} else
	{
		sprintf(cQ, "pTov_S2957SelBD2 %s, %s", isNull(g_iDep), m_Dat.GetSQLDate());
	}

//		sprintf(cQ, "pTov_S2957SelInf2 %s", isNull(qwIDS));
		DBW.ExecSQL(cQ);
		for( int i=1; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 7; i++ )
		{
			nField = 1;
			for( int j=1; j < 13; j++ )
			{
				DBW.GetData(nField, SQL_C_CHAR, cText, 64, &Ind);
				if( Ind != -1 )
				{
					Tab2.m_Ed[j][i].SetWindowText(cText);
				}
				nField++;
			}
		}
		DBW.CloseCursor();
//	}
}

void CDlgMsg2957Main::OnBnClickedOk() //save
{
	StoreMessageToBase();
	OnOK();
}

void CDlgMsg2957Main::StoreMessageToBase(void)
{
	char cQ[512] = "";
	long Ind = 0;
	sprintf(cQ, "pTov_S2957InsSL %s, %d, %s, %s, %d", 
			isNull(qwIDS),
			g_iDep,
			m_EdPr.GetString(1),
			m_Dat.GetSQLDate(),
			g_iFam);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_ULONG, &qwIDS, 8, &Ind );
	DBW.CloseCursor();

	CString strScript = "begin tran\n";
	char cText[512] = "";
	int nFrase = 1;
	for( int i=0; i < 7; i++ )
	{
		sprintf( cText, "\nexec pTov_S2957InsInf %s, 1, %d, '%.3s', %s, %s, %s, %s, %s, %s, %s, %s, %s",
				isNull(qwIDS),
				nFrase, 
				Tab1.m_Ed[0][i].GetAsString(),
				Tab1.m_Ed[1][i].GetString(1),
				Tab1.m_Ed[2][i].GetString(1),
				Tab1.m_Ed[3][i].GetString(1),
				Tab1.m_Ed[4][i].GetString(1),
				Tab1.m_Ed[5][i].GetString(1),
				Tab1.m_Ed[6][i].GetString(1),
				Tab1.m_Ed[7][i].GetString(1),
				Tab1.m_Ed[8][i].GetString(1),
				Tab1.m_Ed[9][i].GetString(1));
		strScript += cText;
		nFrase++;
	}
	strScript += "\n\n";
	for( int i=0; i < 7; i++ )
	{
		sprintf( cText, "\nexec pTov_S2957InsInf %s, 2, %d, '%.3s', %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
				isNull(qwIDS),
				nFrase, 
				Tab2.m_Ed[0][i].GetAsString(),
				Tab2.m_Ed[1][i].GetString(1),
				Tab2.m_Ed[2][i].GetString(1),
				Tab2.m_Ed[3][i].GetString(1),
				Tab2.m_Ed[4][i].GetString(1),
				Tab2.m_Ed[5][i].GetString(1),
				Tab2.m_Ed[6][i].GetString(1),
				Tab2.m_Ed[7][i].GetString(1),
				Tab2.m_Ed[8][i].GetString(1),
				Tab2.m_Ed[9][i].GetString(1),
				Tab2.m_Ed[10][i].GetString(1),
				Tab2.m_Ed[11][i].GetString(1),
				Tab2.m_Ed[12][i].GetString(1));
		strScript += cText;
		nFrase++;
	}	

	strScript += "\ncommit tran";
	DBW.ExecSQL(strScript);
	DBW.CloseCursor();
	DBW.ReallocHandle();


//	AfxMessageBox(strScript);	
}

void CDlgMsg2957Main::OnBnClickedButton2() //send
{
	StoreMessageToBase();
	char cQ[512] = "";
	char cMess[2048] = "";
	long Ind = 0;

	sprintf(cQ, "pTov_S29xxSend %s", isNull(qwIDS));
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	sprintf(cQ, "pTov_S2957Form %s", isNull(qwIDS));
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cMess, 2048, &Ind);
	DBW.CloseCursor();
	
	if( g_iMessageNumber )
	{	
		if( Ind != -1 )
		{
			DBW.SendMessageToTov(cMess);
		}
	} else
		theApp.SendTeleMessage(cMess, "S2957");
	OnOK();
//	AfxMessageBox(cMess);

}

void CDlgMsg2957Main::OnBnClickedButton1() //sost
{
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_S29xxInf %s, 2957", isNull(qwIDS));
	Dlg.DoModal();
}

void CDlgMsg2957Main::OnBnClickedButton3() //report
{
	char cQ[512] = "";
	sprintf(cQ, "pTov_mkcRepHtmVO7 %d, %s, %d", g_iDep,	m_Dat.GetSQLDate(), iFromKpBase);	
	DBW.DisplayHtmlReport(cQ);
}

void CDlgMsg2957Main::CalcSum(void)
{
	for( int i=1; i < 10; i++ )
	{
		Tab1.m_Ed[i][0].SetValue(Tab1.m_Ed[i][1].GetAsDWord() +
						  Tab1.m_Ed[i][2].GetAsDWord() +
						  Tab1.m_Ed[i][3].GetAsDWord() +
						  Tab1.m_Ed[i][4].GetAsDWord() +
						  Tab1.m_Ed[i][5].GetAsDWord() +
						  Tab1.m_Ed[i][6].GetAsDWord());
	}

	for( int i=1; i < 13; i++ )
	{
		Tab2.m_Ed[i][0].SetValue(Tab2.m_Ed[i][1].GetAsDWord() +
						  Tab2.m_Ed[i][2].GetAsDWord() +
						  Tab2.m_Ed[i][3].GetAsDWord() +
						  Tab2.m_Ed[i][4].GetAsDWord() +
						  Tab2.m_Ed[i][5].GetAsDWord() +
						  Tab2.m_Ed[i][6].GetAsDWord());
	}

}
