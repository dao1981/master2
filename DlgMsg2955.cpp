// DlgMsg2955.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg2955.h"
#include ".\dlgmsg2955.h"
#include "printabledlg.h"
//#include "colorbtn.h"
// CDlgMsg2955 dialog

extern int g_iMessageNumber;
extern int g_iMessageReturnResult;
extern CMasterApp theApp;
extern COLORREF p_crColors[6];

IMPLEMENT_DYNAMIC(CDlgMsg2955, CDlgWithAccelerators)
CDlgMsg2955::CDlgMsg2955(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg2955::IDD, pParent)
{
	ZeroMemory(&stRptDate, sizeof(stRptDate));
	qwIDS = 0;
	iDataFromBD = 0;
}

CDlgMsg2955::~CDlgMsg2955()
{
}

void CDlgMsg2955::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ED1, m_Ed1);
	DDX_Control(pDX, IDC_ED2, m_Ed2);
	DDX_Control(pDX, IDC_ED3, m_Ed3);
	DDX_Control(pDX, IDC_ED4, m_Ed4);
	DDX_Control(pDX, IDC_ED5, m_Ed5);
	DDX_Control(pDX, IDC_ED6, m_Ed6);
	DDX_Control(pDX, IDC_ED7, m_Ed7);
	DDX_Control(pDX, IDC_ED8, m_Ed8);
	DDX_Control(pDX, IDC_ED9, m_Ed9);
	DDX_Control(pDX, IDC_ED10, m_Ed10);
	DDX_Control(pDX, IDC_ED11, m_Ed11);
	DDX_Control(pDX, IDC_ED12, m_Ed12);
	DDX_Control(pDX, IDC_ED13, m_Ed13);
	DDX_Control(pDX, IDC_ED14, m_Ed14);
	DDX_Control(pDX, IDC_ED15, m_Ed15);
	DDX_Control(pDX, IDC_ED16, m_Ed16);
	DDX_Control(pDX, IDC_ED17, m_Ed17);
	DDX_Control(pDX, IDC_ED18, m_Ed18);
	DDX_Control(pDX, IDC_ED19, m_Ed19);
	DDX_Control(pDX, IDC_ED20, m_Ed20);

	DDX_Control(pDX, IDC_ED21, m_Ed21);
	DDX_Control(pDX, IDC_ED22, m_Ed22);
	DDX_Control(pDX, IDC_ED36, m_Ed23);
	DDX_Control(pDX, IDC_ED24, m_Ed24);
	DDX_Control(pDX, IDC_ED25, m_Ed25);
	DDX_Control(pDX, IDC_ED26, m_Ed26);

	DDX_Control(pDX, IDC_ED104, m_Ed27);
	DDX_Control(pDX, IDC_ED28, m_Ed28);
	DDX_Control(pDX, IDC_ED29, m_Ed29);
	DDX_Control(pDX, IDC_ED37, m_Ed30);

	DDX_Control(pDX, IDC_ED31, m_Ed31);
	DDX_Control(pDX, IDC_ED32, m_Ed32);
	DDX_Control(pDX, IDC_ED33, m_Ed33);
	DDX_Control(pDX, IDC_ED34, m_Ed34);
	DDX_Control(pDX, IDC_ED35, m_Ed35);

	DDX_Control(pDX, IDC_ED98, m_Ed36);
	DDX_Control(pDX, IDC_ED99, m_Ed37);
	DDX_Control(pDX, IDC_ED38, m_Ed38);

	DDX_Control(pDX, IDC_ED39, m_Ed39);
	DDX_Control(pDX, IDC_ED27, m_Ed40);

	DDX_Control(pDX, IDC_EDIT2, m_Dat);
	DDX_Control(pDX, IDC_EDIT1, m_Vkm);
	DDX_Control(pDX, IDC_BUTTON1, m_bnSost);
	DDX_Control(pDX, IDC_CHECK2, m_Check1);


}


BEGIN_MESSAGE_MAP(CDlgMsg2955, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON10, OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedPrint)
	ON_BN_CLICKED(IDC_CHECK2, &CDlgMsg2955::OnBnClickedCheck2)
END_MESSAGE_MAP()


// CDlgMsg2955 message handlers

BOOL CDlgMsg2955::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

/*	SetIcon(m_hIcon, FALSE);		// Set small icon
    SetIcon(m_hIcon, TRUE);*/

	m_Ed1.QInit(60, 1);
	m_Ed2.QInit(60, 1);
	m_Ed3.QInit(60, 1);
	m_Ed4.QInit(60, 1);
	m_Ed5.QInit(60, 1);
	m_Ed6.QInit(60, 1);
	m_Ed7.QInit(60, 1);
	m_Ed8.QInit(60, 1);
	m_Ed9.QInit(60, 1);
	m_Ed19.QInit(60, 1);

	m_Ed20.QInit(60, 1);
	m_Ed21.QInit(60, 1);
	m_Ed22.QInit(60, 1);
	m_Ed23.QInit(60, 1);
	m_Ed24.QInit(60, 1);
	m_Ed25.QInit(60, 1);
	m_Ed26.QInit(60, 1);
	m_Ed27.QInit(60, 1);
	m_Ed28.QInit(60, 1);
	m_Ed29.QInit(60, 1);
	m_Ed30.QInit(60, 1);

	m_Ed10.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed11.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed12.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed13.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed14.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed15.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed16.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed17.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed18.ModifyStyle(0, WS_DISABLED, 0);
//	m_Ed19.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed20.ModifyStyle(0, WS_DISABLED, 0);

	m_Ed31.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed32.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed33.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed34.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed35.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed36.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed37.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed38.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed39.ModifyStyle(0, WS_DISABLED, 0);
	m_Ed40.ModifyStyle(0, WS_DISABLED, 0);

	m_Dat.SetTime(&stRptDate);
	m_Dat.ModifyStyle(0, WS_DISABLED, 0);
//	m_Vkm.ModifyStyle(0, WS_DISABLED, 0);

	char cQ[512] = "";
	char cText[64] = "";
	long Ind = 0;
	sprintf(cQ, "pTov_S2955Sel %d, %s, %d", g_iDep, m_Dat.GetSQLDate(), iDataFromBD);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_ULONG, &qwIDS, 8, &Ind);
	if( Ind == -1 ) 
	{
/*		DBW.CloseCursor();
		return TRUE;*/
	}
	DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Vkm.SetWindowText(cText);
	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(st));
	mgSQLGetSysDate(3, &st, &Ind);
	if( Ind != -1 ) m_Dat.SetTime(&st);
	
	DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed1.SetWindowText(cText);
	DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed2.SetWindowText(cText);
	DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed3.SetWindowText(cText);
	DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed4.SetWindowText(cText);
	DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed5.SetWindowText(cText);
	DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed6.SetWindowText(cText);
	DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed7.SetWindowText(cText);
	DBW.GetData(11, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed8.SetWindowText(cText);
	DBW.GetData(12, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed9.SetWindowText(cText);
	
	DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed19.SetWindowText(cText);

	DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed10.SetWindowText(cText);
	DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed11.SetWindowText(cText);
	DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed12.SetWindowText(cText);
	DBW.GetData(17, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed13.SetWindowText(cText);
	DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed14.SetWindowText(cText);
	DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed15.SetWindowText(cText);
	DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed16.SetWindowText(cText);
	DBW.GetData(21, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed17.SetWindowText(cText);
	DBW.GetData(22, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed18.SetWindowText(cText);

	DBW.GetData(23, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed20.SetWindowText(cText);

	DBW.GetData(24, SQL_C_CHAR, cText, 64, &Ind );
	DWORD dwNum = 0;
	if( Ind != -1 ) 
	{
		m_bnSost.SetWindowText(cText);
	}
	DBW.GetData(25, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 && dwNum)
	{
		m_bnSost.SetBkColor(p_crColors[dwNum]);
	}

	//Нарастающий итог

	DBW.GetData(26, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 && dwNum)
	{
		m_Check1.SetCheck(1);
	
		DBW.GetData(27, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Ed21.SetWindowText(cText);
		DBW.GetData(28, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Ed22.SetWindowText(cText);
		DBW.GetData(29, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Ed23.SetWindowText(cText);
		DBW.GetData(30, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Ed24.SetWindowText(cText);
		DBW.GetData(31, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Ed25.SetWindowText(cText);
		DBW.GetData(32, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Ed26.SetWindowText(cText);
		DBW.GetData(33, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Ed27.SetWindowText(cText);
		DBW.GetData(34, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Ed28.SetWindowText(cText);
		DBW.GetData(35, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Ed29.SetWindowText(cText);

		DBW.GetData(36, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Ed30.SetWindowText(cText);
	}
	DBW.GetData(37, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed31.SetWindowText(cText);
	DBW.GetData(38, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed32.SetWindowText(cText);
	DBW.GetData(39, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed33.SetWindowText(cText);
	DBW.GetData(40, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed34.SetWindowText(cText);
	DBW.GetData(41, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed35.SetWindowText(cText);
	DBW.GetData(42, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed36.SetWindowText(cText);
	DBW.GetData(43, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed37.SetWindowText(cText);
	DBW.GetData(44, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed38.SetWindowText(cText);
	DBW.GetData(45, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed39.SetWindowText(cText);
	DBW.GetData(46, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_Ed40.SetWindowText(cText);


	DBW.CloseCursor();
	OnBnClickedCheck2();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg2955::OnBnClickedOk() //сохранить
{
	if( StoreMsgToBase() == -1 ) return;
	g_iMessageReturnResult = 1;
	OnOK();
}

void CDlgMsg2955::OnBnClickedButton10()
{
	char cQ[255] = "";
	CPrintableDlg Dlg;

	if( StoreMsgToBase() == -1 ) return;
	
	long Ind = 0;
	char cText[812] = "";

	sprintf(cQ, "pTov_S29xxSend %s", isNull(qwIDS));
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();

	sprintf(cQ, "pTov_S2955Form %s", isNull(qwIDS));
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cText, 812, &Ind);
	if( g_iMessageNumber )
	{
		if( Ind != -1 )
		{
			DBW.SendMessageToTov(cText);
		}
	} else
	if( Ind != -1 )
	{
		theApp.SendTeleMessage(cText, "msg2955_");
	}
	DBW.CloseCursor();

/*	if( !g_iMessageNumber )
	{
		sprintf(Dlg.cQ, "pTov_S2955Form %s", isNull(qwIDS));
		Dlg.DoModal();
	}
*/
	g_iMessageReturnResult = 1;
	OnOK();
}

int CDlgMsg2955::StoreMsgToBase(void)
{
	char cQ[512] = "";
	char cText[640] = "";
	m_Vkm.GetWindowText(cText, 64);

	if( m_Ed19.GetAsDWord() > m_Ed2.GetAsDWord() )
	{
		AfxMessageBox("Количество отремонтированных КП с повышенной твердостью обода не может быть больше фактически отремонтированных КП!");
		return -1;
	}
	int iEna = m_Check1.GetCheck();
	sprintf(cQ, "pTov_S2955Ins %s, %d, '%s', %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
		isNull(qwIDS),
		g_iDep,
		cText,
		m_Dat.GetSQLDate(),
		m_Ed1.GetString(1),
		m_Ed2.GetString(1),
		m_Ed3.GetString(1),
		m_Ed4.GetString(1),
		m_Ed5.GetString(1),
		m_Ed6.GetString(1),
		m_Ed7.GetString(1),
		m_Ed8.GetString(1),
		m_Ed9.GetString(1),
		m_Ed19.GetString(1),
		g_iFam,
		isAble(iEna, m_Ed21.GetString(1)),
		isAble(iEna, m_Ed22.GetString(1)),
		isAble(iEna, m_Ed23.GetString(1)),
		isAble(iEna, m_Ed24.GetString(1)),
		isAble(iEna, m_Ed25.GetString(1)),
		isAble(iEna, m_Ed26.GetString(1)),
		isAble(iEna, m_Ed27.GetString(1)),
		isAble(iEna, m_Ed28.GetString(1)),
		isAble(iEna, m_Ed29.GetString(1)),
		isAble(iEna, m_Ed30.GetString(1))
 		);
	__int64 qwNum = 0;
	long Ind = 0;
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SLONG, &qwNum, 8, &Ind);
	if( qwNum == -1 )
	{
		DBW.GetData(2, SQL_C_CHAR, cText, 640, &Ind);
		AfxMessageBox(cText);
	} else
	{
		qwIDS = qwNum;
	}
	DBW.CloseCursor();
	return 0;
}

void CDlgMsg2955::OnBnClickedButton1()
{
	CPrintableDlg Dlg;
	if( !qwIDS )
	{
		if( AfxMessageBox("Невозможно посмотреть текст сообщения, так как оно ещё не записано в базу. Записать?", MB_YESNO) == IDNO )
		{
			return;
		}
		if( StoreMsgToBase() == -1 ) return;
	}
	sprintf(Dlg.cQ, "pTov_S29xxInf %s, 2955", isNull(qwIDS));
	Dlg.DoModal();
}

void CDlgMsg2955::OnBnClickedCancel()
{
	g_iMessageReturnResult = 0;
	OnCancel();
}

void CDlgMsg2955::OnBnClickedPrint()
{
		char cQ[128] = "";
		long Ind = 0;
		FILE *f = fopen("html\\tmp.html", "w");
		if( !f ) 
		{
			AfxMessageBox("Невозможно открыть файл для сохранения отчета");
			return;
		}
		char ccc[5120] = "";
		int err = 0;
		sprintf(cQ, "pTov_mkcRepHtmS2955 %d, %s", g_iDep, m_Dat.GetSQLDate());
		DBW.ExecSQL(cQ);
		if( g_sqlret != SQL_ERROR )
		{
			for( int i = 0; i < 256 && (g_sqlret = DBW.Fetch())!= SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
			{
				DBW.GetData(1, SQL_C_CHAR, ccc, 5120, &Ind);
				fprintf(f, "%s\n", ccc);
			}
		} else
		{
			err = 1;
		}
		DBW.CloseCursor();
		fclose(f);
		if( !err ) ShellExecute(NULL, "open", "html\\tmp.html", NULL, NULL, SW_SHOWNORMAL);
}

void CDlgMsg2955::OnBnClickedCheck2()
{
//	m_Check1.GetCheck();

	m_Ed21.EnableWindow(m_Check1.GetCheck());
	m_Ed22.EnableWindow(m_Check1.GetCheck());
	m_Ed23.EnableWindow(m_Check1.GetCheck());
	m_Ed24.EnableWindow(m_Check1.GetCheck());
	m_Ed25.EnableWindow(m_Check1.GetCheck());
	m_Ed26.EnableWindow(m_Check1.GetCheck());
	m_Ed27.EnableWindow(m_Check1.GetCheck());
	m_Ed28.EnableWindow(m_Check1.GetCheck());
	m_Ed29.EnableWindow(m_Check1.GetCheck());
	m_Ed30.EnableWindow(m_Check1.GetCheck());

}
