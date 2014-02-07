// DlgMsg4624_Main.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624_Main.h"
#include ".\dlgmsg4624_main.h"
#include "DlgMsg4624_Header.h"
#include "DlgMsg4624_LDTL.h"
#include "DlgMsg4624_VagDateInput.h"
#include "PrintableDlg.h"
#include ".\telecom\teleI.h"
// CDlgMsg4624_Main dialog

extern cd_TeleI teleObj;	
extern cd_TeleI *tele;	
extern CString g_strASOUPTeleName;
extern int g_iAutoPrihodKP;

extern int g_iStandAlone;
extern int g_iEnableTelecom;
extern int g_iMessageNumber;
//extern int g_iMsg4624Only;
extern CString g_strTelecomServer;
extern int g_iMsg4624ShowHeader;
extern CMasterApp theApp;
//extern int g_i4624Result;
extern int	g_iMessageReturnResult;
extern bool g_bDosCodePage;
extern int g_iNoHideRemVag4624;

extern CString g_strRoadServer;
extern CString g_strReserveServer;
extern int g_iNoSendButtonOn4624;
extern int g_iNoPPT;
extern int g_iSend4624AsoupDirect;
/*
IMPLEMENT_DYNAMIC(CDlgMsg4624_Main, CDlgWithAccelerators)
CDlgMsg4624_Main::CDlgMsg4624_Main(CWnd* pParent)
	: CDlgWithAccelerators(CDlgMsg4624_Main::IDD, pParent)*/
COLORREF crErrorColor = RGB(255, 192, 192);

	char cScript[30000] = "";

	char cProc1[1024] = "";
	char cProc2[1024] = "";
	char cProc3[1024] = "";
	char cProc4[1024] = "";

	char cProcIDS[512] = "";

	char cProcZamKP1[1024] = "";
	char cProcZamKP2[1024] = "";
	char cProcZamKP3[1024] = "";
	char cProcZamKP4[1024] = "";
	char cProcZamKP5[1024] = "";
	char cProcZamKP6[1024] = "";
	char cProcZamKP7[1024] = "";
	char cProcZamKP8[1024] = "";
	char cProcZamLDTL1[1024] = "";
	char cProcZamLDTL2[1024] = "";
	char cProcZamLDTL3[1024] = "";
	char cProcZamLDTL4[1024] = "";
	char cProcZamBLTL1[1024] = "";
	char cProcZamBLTL2[1024] = "";


CDlgMsg4624_Main::CDlgMsg4624_Main(CWnd* pParent)
	: CDlgWithAccelerators(CDlgMsg4624_Main::IDD, pParent)
{
	qwIDS = 0;
	qwILK = 0;
	dwVRem = 0;
	dwVRem7 = 0;
//	dwOsCount = 0;
	i8os = 0;

	dw_nPhrase = 1;	
	iTabCount = 0;
	iBlIdx = 4;
	iZmKP_Idx = 5;
	iZmLDTL_Idx = 6;
	iZmBl_Idx = 7;

	iZamena = 0;

	iInfoFromVagPasp = 0;
	iPaspPPT = 0;
	iHidden = 0;
	dwVkladka = 0, dwErrX = 0, dwErrY = 0;

	i2730Pushed = 0;
	m_pDlgBlTl = NULL;
}

CDlgMsg4624_Main::~CDlgMsg4624_Main()
{
}

void CDlgMsg4624_Main::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_Tab);
	DDX_Control(pDX, IDC_EDIT1, m_EdNLK);
	DDX_Control(pDX, IDC_EDIT2, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT16, m_EdVRem);
	DDX_Control(pDX, IDC_EDIT8, m_EdVRemName);
//	DDX_Control(pDX, IDC_MSG_STATE, m_MsgState);
	DDX_Control(pDX, IDC_CHECK3, m_bnZamena);
	DDX_Control(pDX, IDC_BUTTON1, m_bnSend);
	DDX_Control(pDX, IDC_CHECK2, m_8OsCheck);
	DDX_Control(pDX, IDC_BUTTON4, m_ButMsgText);
	DDX_Control(pDX, IDC_EDIT128, m_DatNeisp);
	DDX_Control(pDX, IDC_EDIT73, m_Hour1);
	DDX_Control(pDX, IDC_EDIT116, m_Min1);
	DDX_Control(pDX, IDC_CHECK4, m_ZeroDataCheck);
	DDX_Control(pDX, IDC_BUTTON6, m_But2730);
	DDX_Control(pDX, IDOK, m_ButStore);
	DDX_Control(pDX, IDC_BUTTON37, m_ButVU36);

}


BEGIN_MESSAGE_MAP(CDlgMsg4624_Main, CDlgWithAccelerators)
//	ON_WM_CLOSE()
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, OnTcnSelchangeTab1)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton_NextTab)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton_PrevTab)
	ON_WM_CLOSE()
//	ON_COMMAND(ID_ARROW_DOWN, OnArrowDown)
ON_EN_KILLFOCUS(IDC_EDIT1, OnEnKillfocusEdit1)
ON_WM_DESTROY()
ON_EN_CHANGE(IDC_EDIT16, OnEnChangeEdit_VRem)
ON_BN_CLICKED(IDC_CHECK3, OnBnClicked_ZamenaCheck)
ON_BN_CLICKED(IDC_CHECK2, OnBnClickedCheck_8Os)
ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton_LvtText)
ON_BN_CLICKED(IDC_BUTTON37, OnBnClickedVU36)
ON_BN_CLICKED(IDC_BUTTON6, OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON7, &CDlgMsg4624_Main::OnBnClickedTEXT4624)
END_MESSAGE_MAP()

// CDlgMsg4624_Main message handlers

void CDlgMsg4624_Main::InitTabOrderIndex(void)
{
	iTabCount = 0;
	if( g_iMsg4624ShowHeader )
	{
		p_iTabOrderIndex[0] = 0;
		iTabCount++;
	}
	for( int i=1; i < 4; i++ )
	{
		p_iTabOrderIndex[iTabCount] = i;
		iTabCount++;		
	}
//	if(dwOsCount == 8)
	if( i8os )
	{
		p_iTabOrderIndex[iTabCount] = 4;
		iTabCount++;
	}
	if( dwVRem == 39 || dwVRem == 49 )
	{
		p_iTabOrderIndex[iTabCount] = 5;
		p_iTabOrderIndex[iTabCount + 1] = 6;
		iTabCount+=2;
	}
//	if(dwOsCount == 8)
	if( i8os )
	{
		p_iTabOrderIndex[iTabCount] = 7;
		iTabCount++;
	}
}


void CDlgMsg4624_Main::SetTabsByOrderIndex(void)
{
	TCITEM ti;

    ti.mask = TCIF_TEXT;
    ti.pszText = _T("Заголовок");
    ti.lParam = (LPARAM)m_pDlg_Header;
	VERIFY(m_pDlg_Header->Create(CDlgMsg4624_Header::IDD, &m_Tab));
    m_Tab.InsertItem(0, &ti);
    m_pDlg_Header->SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

    ti.pszText = _T("1. КП");
    ti.lParam = (LPARAM)m_pDlg_Header;
	VERIFY(m_pDlg_KP->Create(CDlgMsg4624_KP::IDD, &m_Tab));
    m_Tab.InsertItem(1, &ti);
    m_pDlg_KP->SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	
    ti.pszText = _T("2. Детали тележки");
    ti.lParam = (LPARAM)m_pDlg_LDTL;
	VERIFY(m_pDlg_LDTL->Create(CDlgMsg4624_LDTL::IDD, &m_Tab));
    m_Tab.InsertItem(2, &ti);
    m_pDlg_LDTL->SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

    ti.pszText = _T("3. Характеристика тележек");
    ti.lParam = (LPARAM)m_pDlgTLVag;
	VERIFY(m_pDlgTLVag->Create(CDlgMsg4624_TLVAG::IDD, &m_Tab));
    m_Tab.InsertItem(3, &ti);
    m_pDlgTLVag->SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

    ti.pszText = _T("4. Соед. балки");
    ti.lParam = (LPARAM)m_pDlgBlTl;
	VERIFY(m_pDlgBlTl->Create(CDlgMsg4624_BlTl::IDD, &m_Tab));
	m_Tab.InsertItem(4, &ti);
	m_pDlgBlTl->SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	iBlIdx = 4;
	int iZamenaIdx = 4;
	if( !g_iMsg4624ShowHeader )
	{
		m_Tab.DeleteItem(0);
		m_pWndTab[0] = m_pDlg_KP;
		m_pWndTab[1] = m_pDlg_LDTL;
		m_pWndTab[2] = m_pDlgTLVag;
		m_pWndTab[3] = m_pDlgBlTl;
//		iZamenaIdx = 5;
		iZmKP_Idx = 4;
		iZmLDTL_Idx = 5;
		iZmBl_Idx = 6;
		iBlIdx = 3;
	}
	
//	if( dwOsCount != 8 )

	CurWnd = m_pWndTab[0];
	CurWnd->ShowWindow(SW_SHOW);
	m_Tab.SetCurSel(0);
	
	return;
}

CString toStr(DWORD dwNum)
{
	char cText[46] = "";
	return ultoa(dwNum, cText, 10 );
}

extern CDlgMsg4624_Main *mn;
extern int g_i2730ReqMessage; 
extern DWORD g_dwTDep;

BOOL CDlgMsg4624_Main::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();
	
	SetIcon(m_hIcon, FALSE);		// Set small icon
    SetIcon(m_hIcon, TRUE);
	
	m_DatNeisp.bColored = 1;
	m_Hour1.QInit(20, 1);
	m_Min1.QInit(20, 1);

	InitComp();
	bStarted = FALSE;
	m_pDlg_Header = new CDlgMsg4624_Header;
	m_pDlg_KP = new CDlgMsg4624_KP;
	m_pDlg_LDTL = new CDlgMsg4624_LDTL;
	m_pDlgTLVag = new CDlgMsg4624_TLVAG;
	m_pDlgBlTl = new CDlgMsg4624_BlTl;
	
	m_pWndTab[0] = m_pDlg_Header;
	m_pWndTab[1] = m_pDlg_KP;
	m_pWndTab[2] = m_pDlg_LDTL;
	m_pWndTab[3] = m_pDlgTLVag;
	m_pWndTab[4] = m_pDlgBlTl;

	m_pDlgZamenaBlTl = new CDlgMsg4624_ZamenaBlTl;
	m_pDlgZamenaKP = new CDlgMsg4624_ZamenaKP;
	m_pDlgZamenaLDTL = new CDlgMsg4624_ZamenaLDTL;
	mn = this;
	m_pWndTab[5] = m_pDlgZamenaKP;
	m_pWndTab[6] = m_pDlgZamenaLDTL;
	m_pWndTab[7] = m_pDlgZamenaBlTl;

	
//	m_pDlg_Header->m_pTab = &m_Tab;
	m_pDlg_Header->m_pMainTabWnd = this;
	
//	m_pDlg_Header->m_pWnd2 = this;

	InitTabOrderIndex();
	SetTabsByOrderIndex();
	
	cKodSobst[0] = 0;

	char cQ[512] = "";

	char cText[1024] = "";
	DWORD dwNum = 0;
	long Ind = 0;
	SYSTEMTIME tm;
	char cDat[32] = "";
	int iSelSl= 0;

	ZeroMemory( qwIzapRashKP, sizeof(__int64) * 9);
	
	SetIzNalButtons();

	if( g_iMessageNumber && g_iNoSendButtonOn4624 ) m_bnSend.EnableWindow(FALSE);

	if( iPaspPPT )
	{
		sprintf( cQ, "pTov_S4624SelPaspPPT %u, %s, %s", g_iDep, isNull(cVagNum32), DateToSQL(stDat4624));
	} else
	if( iInfoFromVagPasp )
	{
		sprintf( cQ, "pTov_S4624SelPasp %u, %s, %s", g_iDep, isNull(cVagNum32), DateToSQL(stDat4624));
	} else
	{
		sprintf( cQ, "pTov_S4624SelSL %u, %s, %s", g_iDep, isNull(cVagNum32), DateToSQL(stDat4624));
		iSelSl = 1;
	}

	char cMess[512] = "";
	strncpy(cProcIDS, cQ, 511);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	sprintf(cScript, "begin tran\ncreate table #reslt ( ids bigint, ilk varchar(300),\
p1 varchar(30),\
p2 varchar(30),\
p3 varchar(30),\
p4 varchar(30),\
p5 varchar(30),\
p6 varchar(30),\
p7 varchar(30),\
p8 varchar(30),\
p9 varchar(30),\
p10 varchar(30),\
p11 varchar(30),\
p12 varchar(30),\
p13 varchar(30),\
p14 varchar(30),\
p15 varchar(30),\
p16 varchar(30),\
p17 varchar(30),\
p18 varchar(30),\
p19 varchar(30),\
p20 varchar(30),\
p21 varchar(30),\
p22 varchar(30),\
p23 varchar(30),\
p24 varchar(30),\
p25 varchar(30),\
p26 varchar(30),\
p27 varchar(30),\
p28 varchar(30),\
p29 varchar(30),\
p30 varchar(30),\
p31 varchar(30)\
)\ndeclare @IDS bigint, @ILK bigint, @msg varchar(500)\ninsert into #reslt\nexec %s\nselect @IDS = ids, @msg = ilk from #reslt\n\
if( @IDS < 0 ) begin\nselect '-1' as vn, @msg as text, NULL as receiver\nreturn\nend\n\nselect @ILK = ilk from #reslt\n", cQ);
	DBW.GetData(1, SQL_C_SBIGINT, &qwIDS, 8, &Ind);
	if( qwIDS == -1 )
	{
		if( iSelSl )
		{
			DBW.GetData(2, SQL_C_CHAR, cMess, 512, &Ind);
			AfxMessageBox(cMess);
			DBW.CloseCursor();
			CDlgWithAccelerators::OnCancel();
			return FALSE;
		}
		char cVag2[64] = "";
		DBW.GetData(2, SQL_C_CHAR, cMess, 512, &Ind);
		if( iPaspPPT )
		{
			DBW.GetData(3, SQL_C_CHAR, cVag2, 64, &Ind);
		}
		DBW.CloseCursor();
		if( iInfoFromVagPasp )
		{
			if( MessageBox(cMess, "Паспорт не найден!", MB_YESNO ) == IDYES )
			{
				if( g_i2730ReqMessage == 4618) theApp.SendTeleMessage(CString("(: 4618 2730: ") + (CString)cVagNum32 + ":)", CString("2730_") + cVagNum32);
				else theApp.SendTeleMessage(CString("(: 4628 2730: ") + (CString)cVagNum32 + ":)", CString("2730_") + cVagNum32);
				int x = g_conf_MessageOnCancel;
				g_conf_MessageOnCancel = 0;
				OnCancel();
				g_conf_MessageOnCancel = x;
				return FALSE;
			}
			m_EdNVag.SetWindowText(cVagNum32);
			return TRUE;
		} else
		if( iPaspPPT )
		{
			if( MessageBox(cMess, "Паспорт не найден!", MB_YESNO ) == IDYES )
			{
				if( g_i2730ReqMessage == 4618) theApp.SendTeleMessage(CString("(: 4618 2730: ") + (CString)cVag2 + ":)", CString("2730_") + cVag2);
				else theApp.SendTeleMessage(CString("(: 4628 2730: ") + (CString)cVag2 + ":)", CString("2730_") + cVag2);
				int x = g_conf_MessageOnCancel;
				g_conf_MessageOnCancel = 0;
				OnCancel();
				g_conf_MessageOnCancel = x;
				return FALSE;
			}
			m_EdNVag.SetWindowText(cVagNum32);
			return TRUE;
		} else
		{
			AfxMessageBox(cMess);
			int x = g_conf_MessageOnCancel;
			g_conf_MessageOnCancel = 0;
			OnCancel();
			g_conf_MessageOnCancel = x;
			return FALSE;
		}
	}
	DBW.GetData(2, SQL_C_UBIGINT, &qwILK, 8, &Ind);
	char cccc[512] = "";
	sprintf(cccc, "ILK = %I64u", qwILK);
	DBW.WriteLog(cccc);
	sprintf(cccc, "IDS = %I64u", qwIDS);
	DBW.WriteLog(cccc);

	char cmess[100] = "";
		DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdNLK.SetWindowText(cText);
		DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_pDlg_Header->m_EdKPZ.SetWindowText(cText);
		DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_pDlg_Header->m_EdVidKorr.SetWindowText(cText);
		DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_pDlg_Header->m_EdRemPR.SetWindowText(cText);
		DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 )
		{
			m_EdVRem.SetWindowText(cText);
			dwVRem7 = atoi(cText);
			
			sprintf(cmess, "Вид ремонта (7) = %d", dwVRem7);			
		} else
		{
			sprintf(cmess, "Вид ремонта (7) = NULL");
		}
		DBW.WriteLog(cmess);
		mgSQLGetSysDate(8, &tm, &Ind);
		if( Ind != -1 ) 
		{
			m_DatNeisp.SetTime(&tm);
			m_Hour1.SetWindowText(toStr(tm.wHour));
			m_Min1.SetWindowText(toStr(tm.wMinute));
		} else
		{
			m_DatNeisp.SetTime(&stDat4624);
			m_Hour1.SetWindowText(toStr(stDat4624.wHour));
			m_Min1.SetWindowText(toStr(stDat4624.wMinute));
		}
		DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_pDlg_Header->m_EdPTO.SetWindowText(cText);
		DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_pDlg_Header->m_EdReply.SetWindowText(cText);

		DBW.GetData(11, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			DBW.GetData(12, SQL_C_CHAR, cText, 64, &Ind);
		}

		DBW.GetData(13, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			m_pDlg_Header->m_EdOperFIO.SetData(dwNum);
			DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_pDlg_Header->m_EdOperFIO.SetWindowText(cText);
		}
		DBW.GetData(15, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			m_pDlg_KP->m_EdFIO1.SetData(dwNum);
			DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_pDlg_KP->m_EdFIO1.SetWindowText(cText);
		}
		DBW.GetData(17, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			m_pDlg_LDTL->m_FIO1.SetData(dwNum);
			m_pDlgTLVag->m_EdFIO1_LDTL.SetData(dwNum);
			DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) 
			{
				m_pDlg_LDTL->m_FIO1.SetWindowText(cText);
				m_pDlgTLVag->m_EdFIO1_LDTL.SetWindowText(cText);
			}
		}
		DBW.GetData(19, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{ 
			m_pDlgBlTl->m_EdFIO1_BLTL.SetData(dwNum);
			DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_pDlgBlTl->m_EdFIO1_BLTL.SetWindowText(cText);
		}
		DBW.GetData(21, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			m_pDlg_KP->m_EdFIO2.SetData(dwNum);
			m_pDlg_LDTL->m_FIO2.SetData(dwNum);
			m_pDlgTLVag->m_EdFIO2_LDTL.SetData(dwNum);
			DBW.GetData(22, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 )
			{
				m_pDlg_KP->m_EdFIO2.SetWindowText(cText);
				m_pDlg_LDTL->m_FIO2.SetWindowText(cText);
				m_pDlgTLVag->m_EdFIO2_LDTL.SetWindowText(cText);
			}
		}

		DBW.GetData(23, SQL_C_ULONG, &i8os, sizeof(int), &Ind);
		mgSQLGetSysDate(24, &tm, &Ind);

		if( Ind != -1 ) 
		{
			SYSTEMTIME tt;
			ZeroMemory(&tt, sizeof(tt));
			GetLocalTime(&tt);
			if(  SysDateCmp(tm, tt) > 0)
			{
				m_pDlg_Header->m_DatRem.InitDate();
				m_pDlg_Header->m_Hour2.SetWindowText(toStr(tt.wHour));
				m_pDlg_Header->m_Min2.SetWindowText(toStr(tt.wMinute));
			} else
			{
				m_pDlg_Header->m_DatRem.SetTime(&tm);
				m_pDlg_Header->m_Hour2.SetWindowText(toStr(tm.wHour));
				m_pDlg_Header->m_Min2.SetWindowText(toStr(tm.wMinute));
			}
		}
		else 
		{
			SYSTEMTIME tt;
			ZeroMemory(&tt, sizeof(tt));
			m_pDlg_Header->m_DatRem.InitDate();
			GetLocalTime(&tt);
			m_pDlg_Header->m_Hour2.SetWindowText(toStr(tt.wHour));
			m_pDlg_Header->m_Min2.SetWindowText(toStr(tt.wMinute));
		}
		m_pDlg_Header->m_DatRem.GetTime(&m_pDlg_Header->stDateRem);

		DBW.GetData(25, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) 
		{
			m_ButMsgText.SetWindowText(cText);
//			theApp.Dos2Win((unsigned char *)cText, Ind);
		}
		DBW.GetData(26, SQL_C_CHAR, cKodSobst, 4, &Ind);
		dwNum = 0;
		DBW.GetData(27, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 ) m_ZeroDataCheck.SetCheck(dwNum);
		else m_ZeroDataCheck.SetCheck(0);
		dwVkladka = 0, dwErrX = 0, dwErrY = 0;
		DBW.GetData(28, SQL_C_ULONG, &dwVkladka, 4, &Ind);
		if( Ind != -1 )
		{
			DBW.GetData(29, SQL_C_ULONG, &dwErrX, 4, &Ind);
			DBW.GetData(30, SQL_C_ULONG, &dwErrY, 4, &Ind);
		}
		long lHideSendButton = 0;

		DBW.GetData(31, SQL_C_ULONG, &lHideSendButton, 4, &Ind);
		if( Ind != -1 && lHideSendButton == 1 )
		{
			m_bnSend.EnableWindow(FALSE);
			m_ButStore.EnableWindow(FALSE);
			iHidden = 1;
		}
		lHideSendButton = 1;
		DBW.GetData(32, SQL_C_ULONG, &lHideSendButton, 4, &Ind);
		if( Ind != -1 && !lHideSendButton )
		{
			m_But2730.EnableWindow(FALSE); //2730
		}
		DBW.GetData(33, SQL_C_CHAR, cText, 4, &Ind);
		if( Ind != -1 && dwVRem != 72)
		{
			m_EdVRem.SetWindowText(cText);
			DWORD dwVRem = atoi(cText);
			iZamena = 0;
			if( dwVRem == 39 || dwVRem == 49 ) 
			{
				m_bnZamena.SetCheck(1);
				iZamena = 1;
			}
			else
				if( dwVRem != 3 && dwVRem != 4 ) m_bnZamena.EnableWindow(FALSE);			
			sprintf(cmess, "Вид ремонта (33) = %d", dwVRem);			
		} else
		{
			sprintf(cmess, "Вид ремонта (33) = NULL (или 72)");
		}
		if( dwVRem == 72 )
		{
			SetEnabledItemsOfRemCode(3);
			m_EdVRem.SetWindowText("72");
			m_EdVRemName.SetWindowText(m_pVRem[8]);
		}
		DBW.WriteLog(cmess);
		DBW.GetData(34, SQL_C_SLONG, &g_iAutoPrihodKP, 4, &Ind);
		
//	}
	DBW.CloseCursor();
	DBW.ReallocHandle();

	if( !qwIDS )//&& cKodSobst[0])
	{
		int tt = 4;
		if( i8os ) 
		{
			tt = 8;
		}
		for( int i=0; i < tt; i++ )
			m_pDlg_KP->m_p[1][i].SetWindowText(cKodSobst);
		for( int i=0; i < 6; i++ )
			m_pDlg_LDTL->m_p[2][i].SetWindowText(cKodSobst);
	}

	if( dwVRem == 39 || dwVRem == 49 )
	{
		InsertZamenaTabs();
	}	
	SetErrorEdit(dwVkladka, dwErrX, dwErrY);

	m_EdNVag.SetWindowText(cVagNum32);
	if( cVagNum32[0] ) m_EdNVag.ModifyStyle(0, WS_DISABLED);


	if( m_pDlg_Header->m_DatRem.isNull() )
	{
		SYSTEMTIME tt;
		ZeroMemory(&tt, sizeof(tt));
		m_pDlg_Header->m_DatRem.InitDate();
		GetLocalTime(&tt);
		m_pDlg_Header->m_Hour2.SetWindowText(toStr(tt.wHour));
		m_pDlg_Header->m_Min2.SetWindowText(toStr(tt.wMinute));
		m_pDlg_Header->m_DatRem.GetTime(&m_pDlg_Header->stDateRem);
	}
	if( m_DatNeisp.isNull() )
	{
		SYSTEMTIME sst;
		ZeroMemory(&sst, sizeof(sst));
		GetLocalTime(&sst);
		m_DatNeisp.SetTime(&sst);
		m_pDlg_Header->stDate4624 = sst;
		m_pDlg_Header->m_Hour2.SetWindowText(toStr(sst.wHour));
		m_pDlg_Header->m_Min2.SetWindowText(toStr(sst.wMinute));
	}
	if( qwILK || qwIDS ) 
	{
		FillForms();
		DBW.WriteLog("Z1");
		if( dwVRem == 39 || dwVRem == 49 )
			FillZamenaTabs();
		DBW.WriteLog("Z2");
	}
	bStarted = TRUE;
	if( g_iMessageNumber )
	{
//		m_bnSend.EnableWindow(FALSE);
	}
	m_8OsCheck.SetCheck(i8os);
	DBW.WriteLog("Z3");
	if( !g_iStandAlone || g_iMessageNumber )
	{
		m_8OsCheck.EnableWindow(0);
		if( !g_iNoHideRemVag4624 ) 
			m_EdVRem.ModifyStyle(WS_VISIBLE, 0);

		m_pDlg_KP->m_EdFIO1.EnableWindow(0);
		m_pDlg_KP->m_EdFIO2.EnableWindow(0);
		m_pDlg_KP->m_bnFio1.EnableWindow(0);
		m_pDlg_KP->m_bnFio2.EnableWindow(0);

		m_pDlg_LDTL->m_FIO1.EnableWindow(0);
		m_pDlg_LDTL->m_FIO2.EnableWindow(0);
		m_pDlg_LDTL->m_bnFio1.EnableWindow(0);
		m_pDlg_LDTL->m_bnFio2.EnableWindow(0);

		m_pDlgBlTl->m_EdFIO1_BLTL.EnableWindow(0);
		m_pDlgBlTl->m_EdFIO2_BLTL.EnableWindow(0);
		m_pDlgBlTl->m_bnFio1.EnableWindow(0);
		m_pDlgBlTl->m_bnFio2.EnableWindow(0);

		m_pDlgTLVag->m_EdFIO1_LDTL.EnableWindow(0);
		m_pDlgTLVag->m_EdFIO2_LDTL.EnableWindow(0);
		m_pDlgTLVag->m_bnFio1.EnableWindow(0);
		m_pDlgTLVag->m_bnFio2.EnableWindow(0);

		if( m_pDlgZamenaBlTl && m_pDlgZamenaBlTl->m_hWnd )
		{
			m_pDlgZamenaBlTl->m_FIO.EnableWindow(0);
			m_pDlgZamenaBlTl->m_bnFio.EnableWindow(0);
		}
		/*
		if( m_pDlgZamenaKP && m_pDlgZamenaKP->m_hWnd )
		{
			m_pDlgZamenaKP->m_FIO1.EnableWindow(0);
			m_pDlgZamenaKP->m_bnFio.EnableWindow(0);
		}
		*/
		if( m_pDlgZamenaLDTL && m_pDlgZamenaLDTL->m_hWnd )
		{
			m_pDlgZamenaLDTL->m_FIO.EnableWindow(0);
			m_pDlgZamenaLDTL->m_bnFio.EnableWindow(0);
		}
	}
	DBW.WriteLog("Z4");
	if( i8os )
	{
		DBW.WriteLog("Z5");
		m_pDlg_LDTL->m_8OsButton.EnableWindow(1);
		if( iZamena )
		{
			m_pDlgZamenaLDTL->m_bn8Os.EnableWindow(1);
		} 
	} else
	{
			DBW.WriteLog("Z6");
			m_Tab.DeleteItem(iBlIdx);
			iZmKP_Idx = iBlIdx;
			iZmLDTL_Idx = iBlIdx + 1;
			iZmBl_Idx = iBlIdx + 2;

			m_pWndTab[iBlIdx] = m_pDlgZamenaKP;
			m_pWndTab[iBlIdx+1] = m_pDlgZamenaLDTL;
//			m_pWndTab[iBlIdx + 2] = m_pDlgZamenaBlTl;

	}
	DBW.WriteLog("Z7");
	SetEnabledBy8Os(i8os);
	DBW.WriteLog("Z8");
	SetEnabledItemsOfRemCode(dwVRem);	
	DBW.WriteLog("Z9");

	__int64 qwIds1 = 0;

	// Было сделано для сахалина, но эта часть ремит кнопку из 2730 в питере
	
	if( !g_iNoPPT )
	{
		sprintf(cQ, "pTov_S2730CheckExistsPpt %s", cVagNum32);
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cNVagTl, 30, &Ind);
		DBW.GetData(2, SQL_C_UBIGINT, &qwIds1, 8, &Ind);
		DBW.CloseCursor();

		if( qwIds1 > 0 ) 
		{
			m_But2730.EnableWindow(1);
			sprintf(cText, "из 2730 по %s", cNVagTl);
			m_But2730.SetWindowText(cText);
		}
		else 
			m_But2730.EnableWindow(0);
	}

	SetIzNalButtons();
	return TRUE;
}

void CDlgMsg4624_Main::OnClose()
{	
	CDlgWithAccelerators::OnClose();
}

void CDlgMsg4624_Main::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	CurWnd->ShowWindow(SW_HIDE);
	m_pWndTab[m_Tab.GetCurSel()]->ShowWindow(SW_SHOW);
	CurWnd = m_pWndTab[m_Tab.GetCurSel()];

	*pResult = 0;
}

void CDlgMsg4624_Main::InitComp(void)
{
	m_EdNLK.QInit(30);
	m_EdNLK.bColored = 1;
	m_EdNVag.QInit(100);
	m_EdNVag.bColored = 1;
	m_EdVRem.QInit(20,1);

	m_pVRem[1] = "Деповский ремонт";
	m_pVRem[2] = "Капитальный ремонт";
	m_pVRem[3] = "Текущий ремонт ТР1 без замены деталей";
	m_pVRem[4] = "Текущий ремонт ТР2 без замены деталей";
	m_pVRem[5] = "Постройка";
	m_pVRem[6] = "Текущий ремонт ТР1 с заменой деталей";
	m_pVRem[7] = "Текущий ремонт ТР2 с заменой деталей";
	m_pVRem[8] = "Подкатка тележек на ППТ";

}

void CDlgMsg4624_Main::FillForms(void)
{
	char cQ[512] = "";
	char cText[64] = "";
	long Ind = 0;
	DWORD dwNum = 0;
	sprintf(cQ, "pTov_S4624SelKP %s, %s, %s",
			isNull(qwIDS),	
			isNull(dwVRem7),
			isNull(qwILK));
	DBW.ExecSQL(cQ);
	for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 8; i++ )
	{
		for( int j=0; j < 13; j++ )
		{			
			DBW.GetData(j+1, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) 
			{
				m_pDlg_KP->m_p[j][i].SetWindowText(cText);
				if( j == 0 && atoi(cText) < 9 ) qwIzapRashKP[ atoi(cText) ] = 1;
			}
		}
	}
	DBW.CloseCursor();

	sprintf(cQ, "pTov_S4624SelTL %s, %s, %s",
			isNull(qwIDS),
			isNull(dwVRem7),
			isNull(qwILK));
	DBW.ExecSQL(cQ);
	DWORD dwOldNum = 0;
	int iCol = 2;
	int iY = 0;
	for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 4; i++ )
	{
		iCol = 2;

		// Номер
		DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 && dwNum != dwOldNum && dwNum < 5 )
		{
			dwOldNum = dwNum;
			itoa(dwNum, cText, 10);
//			m_pDlg_LDTL->m_Num[dwNum - 1].SetWindowText(cText);
			m_pDlg_LDTL->m_BackBuffer.p_strNum[dwNum - 1] = cText;
		}
		
		//Первая строка
		for( int j=1; j < 5; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) 
			{
//				m_pDlg_LDTL->m_p[j+1][i+iY].SetWindowText(cText);
				m_pDlg_LDTL->m_BackBuffer.str_p[j + 1][i + iY] = cText;
			}
			iCol++;
		}
		for( int j=8; j < 14; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) 
			{
//				m_pDlg_LDTL->m_p[j][i+iY].SetWindowText(cText);
				m_pDlg_LDTL->m_BackBuffer.str_p[j][i+iY] = cText;
			}
			iCol++;
		}
		// Первая боковая рама
		DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 64, &Ind); //левая/правая
		if( Ind != -1 )
		{
//			m_pDlg_LDTL->m_c[i+1+iY].SetCurSel(dwNum);
			m_pDlg_LDTL->m_BackBuffer.p_iComboIndex[i+1+iY] = dwNum;
		}
		iCol++;

		for( int j=2; j < 8; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) 
			{
//				m_pDlg_LDTL->m_p[j][i+1+iY].SetWindowText(cText);
				m_pDlg_LDTL->m_BackBuffer.str_p[j][i+1+iY] = cText;
			}
			iCol++;
		}
		for( int j=11; j < 14; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) 
			{
//				m_pDlg_LDTL->m_p[j][i+1+iY].SetWindowText(cText);
				m_pDlg_LDTL->m_BackBuffer.str_p[j][i+1+iY] = cText;
			}
			iCol++;
		}
		// Вторая боковая рама
		DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 64, &Ind); //левая/правая
		if( Ind != -1 ) 
		{
//			m_pDlg_LDTL->m_c[i+2+iY].SetCurSel(dwNum);
			m_pDlg_LDTL->m_BackBuffer.p_iComboIndex[i+2+iY] = dwNum;
		}
		iCol++;

		for( int j=2; j < 8; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) 
			{
//				m_pDlg_LDTL->m_p[j][i+2+iY].SetWindowText(cText);
				m_pDlg_LDTL->m_BackBuffer.str_p[j][i+2+iY] = cText;
			}
			iCol++;
		}
		for( int j=11; j < 14; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) 
			{
//				m_pDlg_LDTL->m_p[j][i+2+iY].SetWindowText(cText);
				m_pDlg_LDTL->m_BackBuffer.str_p[j][i+2+iY] = cText;
			}
			iCol++;
		}
		iY+=2;
	}
	DBW.CloseCursor();


	m_pDlg_LDTL->m_BackBuffer.iScreenPage = 0;
	m_pDlg_LDTL->DrawBuffer(0);
//Тележки под вагоном
	sprintf(cQ, "pTov_S4624SelTLVag %s, %s, %s",
			isNull(qwIDS),
			isNull(dwVRem7),
			isNull(qwILK));
	DBW.ExecSQL(cQ);

	for( int i=0; (g_sqlret = DBW.Fetch())!=SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 4; i++ )
	{		
		DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_pDlgTLVag->m_pL[i+1*i].SetWindowText(cText);
		DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_pDlgTLVag->m_pL[i+1*i+1].SetWindowText(cText);

		DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			if( !dwNum ) m_pDlgTLVag->m_p[0][i*2].SetWindowText("Левая");
			else m_pDlgTLVag->m_p[0][i*2].SetWindowText("Правая");
		}
		iCol = 4;

		for( int j=1; j < 8; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_pDlgTLVag->m_p[j][i*2].SetWindowText(cText);
			iCol++;
		}

		DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			if( !dwNum ) m_pDlgTLVag->m_p[0][i*2+1].SetWindowText("Левая");
			else m_pDlgTLVag->m_p[0][i*2+1].SetWindowText("Правая");
		}
		iCol++;
		for( int j=1; j < 8; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_pDlgTLVag->m_p[j][i*2+1].SetWindowText(cText);
			iCol++;
		}
	}
	DBW.CloseCursor();
// Балки
	if( i8os )
	{
		sprintf(cQ, "pTov_S4624SelSB %s, %s, %s",
				isNull(qwIDS),
				isNull(dwVRem7),
				isNull(qwILK));
		DBW.ExecSQL(cQ);
	//	i8os = i8os;
		for( int i=0; (g_sqlret = DBW.Fetch())!=SQL_NO_DATA && 
					g_sqlret != SQL_ERROR 
					&& i < 4
					&& m_pDlgBlTl; i++ )
		{
			for( int j=0; j < 5; j++ )
			{
				DBW.GetData(j+1, SQL_C_CHAR, cText, 64, &Ind);
				if( Ind != -1 ) m_pDlgBlTl->m_pEd[j][i].SetWindowText(cText);
			}
		}
		DBW.CloseCursor();
	}
	DBW.WriteLog("z");
}

void CDlgMsg4624_Main::OnOK()
{
//	CDialog::OnOK();
}

/***
* Кодировка
*/
void Shuffle(char* pcSeq)
{
 char* pc = pcSeq;
 char* pcR = strdup(pcSeq);
 char* pcB = pcR;
 char* pcE = pcR + strlen(pcR) - 1;
 int iB,iE;

 iE = 4; iB = 0;
 while (*pc != 0)
 {
  if (iB == 0)
  {
   *pc++ = *pcE--;
   if (--iE == 0)
    iB = 4;
  }
  else
  {
   if ((pcB + --iB) > pcE)
    iB = pcE - pcB;
   *pc++ = *(pcB + iB);
   if (iB == 0)
    pcB += (iE = 4);
  }
 }
 free(pcR);
}

/***
* Раскодирование
*/
void Unshuffle(char* pcSeq)
{
 char* pcR = strdup(pcSeq);
 char* pc = pcR;
 char* pcB = pcSeq;
 char* pcE = pcSeq + strlen(pcSeq) - 1;
 int iB,iE;

 iB = 0; iE = 4;
 while (*pc != 0)
 {
  if (iB == 0)
  {
   *pcE-- = *pc++;
   if (--iE == 0)
    iB = 4;
  }
  else
  {
   if ((pcB + --iB) > pcE)
    iB = pcE - pcB;
   *(pcB + iB) = *pc++;
   if (iB == 0)
    pcB += (iE = 4);
  }
 }
 free(pcR);
}
/*
int CDlgMsg4624_Main::StoreMsgToBase(void)
{
	char cProcSL[1024] = "";
	

	SYSTEMTIME tcur, tm;
	ZeroMemory(&tcur, sizeof(tcur));
	ZeroMemory(&tm, sizeof(tm));
	GetLocalTime(&tcur);

	m_pDlg_Header->m_DatRem.GetTime(&tm);
	tm.wHour = (WORD)m_pDlg_Header->m_Hour2.GetAsDWord();
	tm.wMinute = (WORD)m_pDlg_Header->m_Min2.GetAsDWord();
	
	if( SysDateCmp(tcur, tm) < 0 )
	{
		AfxMessageBox("Некорректно указана дата или время отправки сообщения!");
		m_pDlg_Header->m_DatRem.SetFocus();
		return -1;
	}
	if( m_DatNeisp.isNull() || !m_DatNeisp.isValid() )
	{
		AfxMessageBox("Некорректно указана дата перечисления в неисправные!");
		m_DatNeisp.SetFocus();
		return -1;
	}

	char cQ[1024] = "";
	long Ind = 0;
//	dwVRem = atoi(m_pDlg_Header->m_EdVRem.GetAsString());
	dwVRem = atoi(m_EdVRem.GetAsString());
	dw_nPhrase = 1;
	CString stDat1;
	char cTextDat1[128] = "";
	sprintf(cTextDat1, "%s%.2d:%.2d:%.2d'", 
		m_DatNeisp.GetSQLDate(),
		m_Hour1.GetAsDWord(),
		m_Min1.GetAsDWord(),
		0);
	cTextDat1[9] = ' ';

	char cTextDat2[128] = "";
	sprintf(cTextDat2, "%s%.2d:%.2d:%.2d'", 
		m_pDlg_Header->m_DatRem.GetSQLDate(),
		m_pDlg_Header->m_Hour2.GetAsDWord(),
		m_pDlg_Header->m_Min2.GetAsDWord(),
		0);
	cTextDat2[9] = ' ';

	if( iInfoFromVagPasp ) qwIDS = 0;

	sprintf( cQ, "pTov_S4624InsSL  %s, %u, %s , %u, %s, %s, %s, %s, %s, %s, %s,  %s, %s, %s, %s, %s, %s, %s, %s, %s, %d, %s, %d",
			isNull(qwIDS),
			g_iDep,
			isNull(qwILK),

			g_iFam, //Ид. фамилии оператора, который давит на кнопки
			isNull(m_pDlg_KP->m_EdFIO1.GetData()), //Мастер колесно-роликового участка
			isNull(m_pDlg_LDTL->m_FIO1.GetData()), //Мастер тележечного участка
			isNull(m_pDlgBlTl->m_EdFIO1_BLTL.GetData()), //Мастер ремонта соединительных балок
			isNull(m_pDlg_KP->m_EdFIO2.GetData()), //Бригадир участка текущего ремонта
			isNull(DWORD(0)), //приемщик вагонов
			m_EdNLK.GetAsString(),
			isNull(m_EdNVag.GetAsString()),
			m_pDlg_Header->m_EdRemPR.GetAsString(),
			m_pDlg_Header->m_EdPTO.GetAsString(),
			m_EdVRem.GetAsString(),
			cTextDat2,
			cTextDat1,
			m_pDlg_Header->m_EdKodSobst.GetAsString(),
			isNull(m_pDlg_Header->m_EdKPZ.GetAsString()),
			m_pDlg_Header->m_EdVidKorr.GetAsString(),
			isNull(m_pDlg_Header->m_EdReply.GetAsString()),
			i8os,
			isNull(cKodSobst),
			m_ZeroDataCheck.GetCheck()
			);

//	ShowMsg(cQ);
//	qwIDS = 0;
	__int64 qwRet = 0;
	char cText[640] = "";
	DBW.ExecSQL(cQ);
	DBW.Fetch();

	DBW.GetData(1, SQL_C_SBIGINT, &qwRet, 8, &Ind);
	sprintf(cText, "Процедура вернула: %I64u, %I64d", qwRet, qwRet);
	DBW.WriteLog(cText);
	if( qwRet == -1 )
	{
		DBW.GetData(2, SQL_C_CHAR, cText, 640, &Ind );	
		AfxMessageBox(cText);
		DBW.WriteLog(cText);
		DBW.CloseCursor();
		return -1;
	} else
	if(qwRet == -2){
		DBW.GetData(2, SQL_C_CHAR, cText, 640, &Ind );	
		DBW.WriteLog(cText);
		DBW.CloseCursor();
		if(AfxMessageBox(cText, MB_YESNO) == IDNO)
		{
			return -1;
		}
	}
	DBW.CloseCursor();
	sprintf(cScript, "%s\n\ncreate table #reslt1 ( rez bigint, msg varchar(8000) )\ninsert into #reslt1", cScript);
	sprintf(cProcSL, "%s\nselect @IDS = rez from #reslt1 where msg='+++'\n\nif( @IDS > 0 )\nbegin\n", cQ);
	

	if( qwRet == 0 ) 
	{
		AfxMessageBox("Ошибка записи сообщения!");
		return -1;
	}
	if( qwRet > 0 )
	{
		qwIDS = qwRet;
	} else
	if(qwRet == -2 )
	{
		strcat(cQ, ", 1");
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();
	}
	
	sprintf(cText, "IDS = %I64u", qwIDS);
	DBW.WriteLog(cText);

	if( qwIDS && !WriteMsgLine(0) )
	{
		WriteMsgLine(1);
		sprintf(cScript, "%s\n\texec %s\n\tinsert into #reslt1 exec %s\n\tinsert into #reslt1 exec %s\n",cScript, cProcSL, cProc1, cProc2);
		
		if( i8os )
		{
			WriteMsgLine(2);
			WriteMsgLine(3);
			sprintf(cScript, "%s\n\tinsert into #reslt1 exec %s\n\tinsert into #reslt1 exec %s\n", cScript, cProc3, cProc4);
		}

		if( dwVRem == 39 || dwVRem == 49 )
		{
			for( int i=0; i < 4; i++ )
			{
				WriteMsgZamenaKP(i);
			}
//			DBW.WriteLog("замена LDTL 4");
			WriteMsgZamenaLDTL(0);
			WriteMsgZamenaLDTL(1);
//			DBW.WriteLog("замена LDTL 4 - ok");
//			sprintf( cScript, "%s\n\texec %s\n\texec %s\n\texec %s\n\texec %s\n\n\texec %s\n\texec %s\n", cScript, cProcZam1, cProcZam2,cProcZam3, cProcZam4, cProcZam5, cProcZam6);
			if( i8os )
			{
//				DBW.WriteLog("замена KP 8");
				for( int i=4; i < 8; i++ )
				{
					WriteMsgZamenaKP(i);
				}
//				DBW.WriteLog("замена KP 8 - ok");

//				DBW.WriteLog("замена LDTL 8");
				WriteMsgZamenaLDTL(2);
				WriteMsgZamenaLDTL(3);
//				DBW.WriteLog("замена LDTL 8 - ok");

//				DBW.WriteLog("замена BLTL 8");
				WriteMsgZamenaBlTl(0);
				WriteMsgZamenaBlTl(1);
//				DBW.WriteLog("замена BLTL 8 - ok");
			}
		}
	}	

	
	sprintf(cScript, "%s\nend\ndrop table #reslt\ndrop table #reslt1\nselect '%s' as vn, NULL as text, NULL as receiver\nCOMMIT TRAN", cScript, cVagNum32);
	CString str = cScript;
	char cIDS[24] = "";
	char cILK[24] = "";
	if( qwILK )
		sprintf(cILK, ", %I64u ,", qwILK);
	else
		sprintf(cILK, ", NULL ,");

	if( qwIDS )
		sprintf(cIDS, "  %I64u,", qwIDS);
	else
		sprintf(cIDS, "  NULL,");


	str.Replace(cILK, ", @ILK,");
	str.Replace(cIDS, " @IDS,");	

	sprintf(cQ, "pTov_GetOption 'SAVE_RAZMER'");
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cText, 640, &Ind);
	DBW.CloseCursor();

	if( Ind != -1 && cText[0] != '0')
	{
		CString razmerScript = GetRazmerScript ();
		DBW.ExecSQL(razmerScript);
		DBW.CloseCursor();
		DBW.ReallocHandle ();

		str += "\n" + razmerScript;
	}

	strcpy(cScript, str);

	DBW.WriteLog((char*)(CString("Скрипт для резервного/дорожного: ") + cScript).GetString());

	CString s1;
	Shuffle(cScript);
	s1.Format("(:4936 0 4624\r\n[%s]:)", cScript );
	
	if (g_iMessageNumber)//запуск из командной строки
	{
		DBW.WriteLog("go tov client script send");

		sprintf(cQ, "pTov_GetOption 'RESERVE_SERVER'", qwIDS );

		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cText, 640, &Ind);
		

		if( Ind != -1 && cText)
		{
			DBW.SendMessageToDst(s1, "", cText);
			//DBW.SendMessageToTov(s1);
		}
	}
	else
	{
		if( tele ) 
		{
			DBW.WriteLog("go tele");
		
			if( g_strReserveServer != "" ) 
			{
				DBW.WriteLog("Ушло на резервный");
				tele->SendMessageDst(s1, &g_strReserveServer);
			}
			if( g_strRoadServer != "" ) 
			{
				DBW.WriteLog("Ушло на дорожный");
				tele->SendMessageDst(s1, &g_strRoadServer);
			}
		}
	}

	DBW.CloseCursor();
		
	return 0;
}
*/
extern int g_iKP4624IzapReq;
int CDlgMsg4624_Main::StoreMsgToBase(void)
{
	char cProcSL[1024] = "";
	
	for( int i = 0; i < 7; i++ )
	{
		for( int j=i + 1; j < 8; j++ )
			if( m_pDlg_KP->m_p[5][i].GetString() == m_pDlg_KP->m_p[5][j].GetString() 
				&& !m_pDlg_KP->m_p[5][i].isNull())
			{
				if( MessageBox("В занесенной информации по КП найдены одинаковые номера! Продолжить отправку сообщения?", "", MB_YESNO ) == IDNO ) return -1;
				else { i=8; j=9; }
			}
	}
	int rr = 0, zz = 0;
	if( m_pDlgZamenaKP && g_iKP4624IzapReq )
	{
			for( int i = 0; i < 8; i++ )
			{
				rr = m_pDlg_KP->m_p[0][i].GetAsDWord();
				for( int j = 0; j < 8; j++ )
				{
					zz = m_pDlgZamenaKP->m_p[0][j].GetAsDWord();
					if(  !m_pDlg_KP->m_p[5][i].isNull() &&  m_pDlg_KP->m_p[0][i].GetAsDWord() == m_pDlgZamenaKP->m_p[0][j].GetAsDWord() 
							&& qwIzapRashKP[i] == 0 )
					{
						AfxMessageBox("Для отправки сообщения необходимо выбрать КП из наличия!");
						return -1;
					}
				}
			}
	}
	/*
	AfxMessageBox(m_pDlg_LDTL->m_p[4][0].GetString());
	AfxMessageBox(m_pDlg_LDTL->m_p[4][2].GetString());
	*/
	// Обязательно 2 раза чтобы данные сохранились в буфере и вернулись на экран
	m_pDlg_LDTL->OnBnClickedButton3();
	m_pDlg_LDTL->OnBnClickedButton3();

	for( int i = 0; i < 11; i++ )
	{
		for( int j=i + 1; j < 12; j++ )
			if( m_pDlg_LDTL->m_BackBuffer.str_p[4][i] == m_pDlg_LDTL->m_BackBuffer.str_p[4][j]
				&& m_pDlg_LDTL->m_BackBuffer.str_p[4][i] != "")
			{
				if( MessageBox("В занесенной информации по деталям тележки найдены одинаковые номера! Продолжить отправку сообщения?", "", MB_YESNO ) == IDNO )
				{	
					/*
					DBW.WriteLog("compare");
					char cText[64];
					strcpy(cText, m_pDlg_LDTL->m_BackBuffer.str_p[4][i].GetString());
					DBW.WriteLog(cText);
					strcpy(cText, m_pDlg_LDTL->m_BackBuffer.str_p[4][j].GetString());
					DBW.WriteLog(cText);*/
					return -1;
				}
				else { i=11; j=12; }
			}
	}

	if( m_pDlgZamenaKP && iZamena )
	{
		for( int i=0; i < 7; i++ )
		{
			if( m_pDlg_KP->m_p[5][i].GetString() == m_pDlgZamenaKP->m_p[5][i].GetString()
				&& !m_pDlg_KP->m_p[5][i].isNull())
			{
				if( MessageBox("В занесенной информации по изъятым и покаченным КП найдены одинаковые номера! Продолжить отправку сообщения?", "", MB_YESNO ) == IDNO ) return -1;
				else { i=7; }
			}
			if( !m_pDlgZamenaKP->m_p[6][i].isNull() &&
				(m_pDlgZamenaKP->m_p[6][i].GetAsDWord() < 1900 || 
				m_pDlgZamenaKP->m_p[6][i].GetAsDWord() > 2015) )
			{
				char cMsg[128] = "";
				sprintf( cMsg, "Год изготовления оси замененной КП №%d указан неверно (%s)",
						i + 1, m_pDlgZamenaKP->m_p[6][i].GetAsString());
				AfxMessageBox( cMsg );
				m_pDlgZamenaKP->m_p[6][i].SetFocus();
				return -1;
			}

		}
	}
	/*
	if( m_pDlgZamenaLDTL )
	{
		for( int i=0; i < 7; i++ )
		{
			if( m_pDlg_LDTL->m_p[4][i].GetString() == m_pDlgZamenaLDTL->m_p[4][i].GetString()
				&& !m_pDlg_LDTL->m_p[4][i].isNull())
			{
				if( MessageBox("В занесенной информации по изъятым и покаченным деталям тележки найдены одинаковые номера! Продолжить отправку сообщения?", "", MB_YESNO ) == IDNO ) return -1;
				else { i=7; }
			}

		}
	}
	*/


	SYSTEMTIME tcur, tm;
	ZeroMemory(&tcur, sizeof(tcur));
	ZeroMemory(&tm, sizeof(tm));
	GetLocalTime(&tcur);

	m_pDlg_Header->m_DatRem.GetTime(&tm);
	tm.wHour = (WORD)m_pDlg_Header->m_Hour2.GetAsDWord();
	tm.wMinute = (WORD)m_pDlg_Header->m_Min2.GetAsDWord();
	
	if( SysDateCmp(tcur, tm) < 0 )
	{
		AfxMessageBox("Некорректно указана дата или время отправки сообщения!");
		m_pDlg_Header->m_DatRem.SetFocus();
		return -1;
	}
	if( m_DatNeisp.isNull() || !m_DatNeisp.isValid() )
	{
		AfxMessageBox("Некорректно указана дата перечисления в неисправные!");
		m_DatNeisp.SetFocus();
		return -1;
	}

	char cQ[1024] = "";
	char cQ2[1024] = "";
	long Ind = 0;
//	dwVRem = atoi(m_pDlg_Header->m_EdVRem.GetAsString());
	dwVRem = atoi(m_EdVRem.GetAsString());
	dw_nPhrase = 1;
	CString stDat1;
	char cTextDat1[128] = "";
	sprintf(cTextDat1, "%s%.2d:%.2d:%.2d'", 
		m_DatNeisp.GetSQLDate(),
		m_Hour1.GetAsDWord(),
		m_Min1.GetAsDWord(),
		0);
	cTextDat1[9] = ' ';

	char cTextDat2[128] = "";
	sprintf(cTextDat2, "%s%.2d:%.2d:%.2d'", 
		m_pDlg_Header->m_DatRem.GetSQLDate(),
		m_pDlg_Header->m_Hour2.GetAsDWord(),
		m_pDlg_Header->m_Min2.GetAsDWord(),
		0);
	cTextDat2[9] = ' ';

	if( iInfoFromVagPasp ) qwIDS = 0;

	sprintf( cQ, "pTov_S4624InsSL  %s, %u, %s , %u, %s, %s, %s, %s, %s, %s, %s,  %s, %s, %s, %s, %s, %s, %s, %s, %s, %d, %s, %d",
			isNull(qwIDS),
			g_iDep,
			isNull(qwILK),

			g_iFam, //Ид. фамилии оператора, который давит на кнопки
//			isNull(m_pDlg_KP->m_EdFIO1.GetData()), //Мастер колесно-роликового участка
			isNull(m_pDlgZamenaKP->m_FIO1.GetData()),
			isNull(m_pDlg_LDTL->m_FIO1.GetData()), //Мастер тележечного участка
			isNull(m_pDlgBlTl->m_EdFIO1_BLTL.GetData()), //Мастер ремонта соединительных балок
			isNull(m_pDlg_KP->m_EdFIO2.GetData()), //Бригадир участка текущего ремонта
			isNull(DWORD(0)), //приемщик вагонов
			m_EdNLK.GetAsString(),
			isNull(m_EdNVag.GetAsString()),
			m_pDlg_Header->m_EdRemPR.GetAsString(),
			m_pDlg_Header->m_EdPTO.GetAsString(),
			m_EdVRem.GetAsString(),
			cTextDat2,
			cTextDat1,
			m_pDlg_Header->m_EdKodSobst.GetAsString(),
			isNull(m_pDlg_Header->m_EdKPZ.GetAsString()),
			m_pDlg_Header->m_EdVidKorr.GetAsString(),
			isNull(m_pDlg_Header->m_EdReply.GetAsString()),
			i8os,
			isNull(cKodSobst),
			m_ZeroDataCheck.GetCheck()
			);

//	ShowMsg(cQ);
//	qwIDS = 0;
	__int64 qwRet = 0;
	char cText[640] = "";
	DBW.ExecSQL(cQ);
	DBW.Fetch();

	DBW.GetData(1, SQL_C_SBIGINT, &qwRet, 8, &Ind);
	sprintf(cText, "Процедура вернула: %I64u, %I64d", qwRet, qwRet);
	DBW.WriteLog(cText);
	if( qwRet == -1 )
	{
		DBW.GetData(2, SQL_C_CHAR, cText, 640, &Ind );	
		AfxMessageBox(cText);
		DBW.WriteLog(cText);
		DBW.CloseCursor();
		return -1;
	} else
	if(qwRet == -2){
		DBW.GetData(2, SQL_C_CHAR, cText, 640, &Ind );	
		DBW.WriteLog(cText);
		DBW.CloseCursor();
		if(AfxMessageBox(cText, MB_YESNO) == IDNO)
		{
			return -1;
		}
	}
	DBW.CloseCursor();


	////////////////////////
	if( iPaspPPT )
	{
		sprintf( cQ2, "pTov_S4624SelPaspPPT %u, %s", g_iDep, isNull(cVagNum32));
	} else
	if( iInfoFromVagPasp )
	{
		sprintf( cQ2, "pTov_S4624SelPasp %u, %s", g_iDep, isNull(cVagNum32));
	} else
	{
		sprintf( cQ2, "pTov_S4624SelSL %u, %s", g_iDep, isNull(cVagNum32));
	}

	sprintf(cScript, "begin tran\ncreate table #reslt ( ids bigint, ilk varchar(300),\
p1 varchar(30),\
p2 varchar(30),\
p3 varchar(30),\
p4 varchar(30),\
p5 varchar(30),\
p6 varchar(30),\
p7 varchar(30),\
p8 varchar(30),\
p9 varchar(30),\
p10 varchar(30),\
p11 varchar(30),\
p12 varchar(30),\
p13 varchar(30),\
p14 varchar(30),\
p15 varchar(30),\
p16 varchar(30),\
p17 varchar(30),\
p18 varchar(30),\
p19 varchar(30),\
p20 varchar(30),\
p21 varchar(30),\
p22 varchar(30),\
p23 varchar(30),\
p24 varchar(30),\
p25 varchar(30),\
p26 varchar(30),\
p27 varchar(30),\
p28 varchar(30),\
p29 varchar(30),\
p30 varchar(30),\
p31 varchar(30)\
)\ndeclare @IDS bigint, @ILK bigint, @msg varchar(500)\ninsert into #reslt\nexec %s, %s\nselect @IDS = ids, @msg = ilk from #reslt\n\
if( @IDS < 0 ) begin\ndelete from #reslt\ninsert into #reslt exec %s, %s\nselect @IDS = ids, @msg = ilk from #reslt\nif( @IDS < 0 )\nbegin\nselect '-1' as vn, @msg as text, NULL as receiver\ndrop table #reslt\ngoto comm_\nend\nend\n\n\nselect @ILK = ilk from #reslt\n", cQ2, DateToSQL(stDat4624), cQ2, cTextDat1);
/////////////////////////////////

	sprintf(cScript, "%s\n\ncreate table #reslt1 ( rez bigint, msg varchar(8000) )\ninsert into #reslt1", cScript);
	sprintf(cProcSL, "%s\nselect @IDS = rez from #reslt1 where msg='+++'\n\nif( @IDS > 0 )\nbegin\n", cQ);
	

	if( qwRet == 0 ) 
	{
		AfxMessageBox("Ошибка записи сообщения!");
		return -1;
	}
	if( qwRet > 0 )
	{
		qwIDS = qwRet;
	} else
	if(qwRet == -2 )
	{
		strcat(cQ, ", 1");
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();
	}
	
	sprintf(cText, "IDS = %I64u", qwIDS);
	DBW.WriteLog(cText);

	if( qwIDS && !WriteMsgLine(0) )
	{
		WriteMsgLine(1);
		sprintf(cScript, "%s\n\texec %s\n\tinsert into #reslt1 exec %s\n\tinsert into #reslt1 exec %s\n",cScript, cProcSL, cProc1, cProc2);
		
		if( i8os )
		{
			WriteMsgLine(2);
			WriteMsgLine(3);
			sprintf(cScript, "%s\n\tinsert into #reslt1 exec %s\n\tinsert into #reslt1 exec %s\n", cScript, cProc3, cProc4);
		}

		if( dwVRem == 39 || dwVRem == 49 )
		{
			for( int i=0; i < 4; i++ )
			{
				WriteMsgZamenaKP(i);
			}
//			DBW.WriteLog("замена LDTL 4");
			WriteMsgZamenaLDTL(0);
			WriteMsgZamenaLDTL(1);
//			DBW.WriteLog("замена LDTL 4 - ok");
//			sprintf( cScript, "%s\n\texec %s\n\texec %s\n\texec %s\n\texec %s\n\n\texec %s\n\texec %s\n", cScript, cProcZam1, cProcZam2,cProcZam3, cProcZam4, cProcZam5, cProcZam6);
			if( i8os )
			{
//				DBW.WriteLog("замена KP 8");
				for( int i=4; i < 8; i++ )
				{
					WriteMsgZamenaKP(i);
				}
//				DBW.WriteLog("замена KP 8 - ok");

//				DBW.WriteLog("замена LDTL 8");
				WriteMsgZamenaLDTL(2);
				WriteMsgZamenaLDTL(3);
//				DBW.WriteLog("замена LDTL 8 - ok");

//				DBW.WriteLog("замена BLTL 8");
				WriteMsgZamenaBlTl(0);
				WriteMsgZamenaBlTl(1);
//				DBW.WriteLog("замена BLTL 8 - ok");
			}
		}
	}	

	
	sprintf(cScript, "%s\nend\ndrop table #reslt\ndrop table #reslt1\nselect '%s' as vn, NULL as text, NULL as receiver\ncomm_: commit tran\ngoto end_\nroll_: rollback tran\nend_:\n", cScript, cVagNum32);
	CString str = cScript;
	char cIDS[24] = "";
	char cILK[24] = "";
	if( qwILK )
		sprintf(cILK, ", %I64u ,", qwILK);
	else
		sprintf(cILK, ", NULL ,");

	if( qwIDS )
		sprintf(cIDS, "  %I64u,", qwIDS);
	else
		sprintf(cIDS, "  NULL,");


	str.Replace(cILK, ", @ILK,");
	str.Replace(cIDS, " @IDS,");	

	sprintf(cQ, "pTov_GetOption 'SAVE_RAZMER'");
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cText, 640, &Ind);
	DBW.CloseCursor();

	if( Ind != -1 && cText[0] != '0')
	{
		CString razmerScript = GetRazmerScript ();
		DBW.ExecSQL(razmerScript);
		DBW.CloseCursor();
		DBW.ReallocHandle ();

		str += "\nGO\n" + razmerScript;
	}

	strncpy(cScript, str, 30000);

	DBW.WriteLog((char*)(CString("Скрипт для резервного/дорожного: ") + cScript).GetString());

	CString s1;
	Shuffle(cScript);
	s1.Format("(:4936 %d 4624\r\n[%s]:)", g_iFam, cScript );
	
	if (g_iMessageNumber)//запуск из командной строки
	{
		DBW.WriteLog("go tov client script send");

		sprintf(cQ, "pTov_GetOption 'RESERVE_SERVER'", qwIDS );

		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cText, 640, &Ind);
		

		if( Ind != -1 && cText)
		{
			DBW.SendMessageToDst(s1, "", cText);
			//DBW.SendMessageToTov(s1);
		}
	}
	else
	{
		if( tele ) 
		{
			DBW.WriteLog("go tele");
		
			if( g_strReserveServer != "" ) 
			{
				DBW.WriteLog("Ушло на резервный");
				tele->SendMessageDst(s1, &g_strReserveServer);
			}
			if( g_strRoadServer != "" ) 
			{
				DBW.WriteLog("Ушло на дорожный");
				tele->SendMessageDst(s1, &g_strRoadServer);
			}
		}
	}

	DBW.CloseCursor();
		
	return 0;
}


CString CDlgMsg4624_Main::GetRazmerScript ()
{
	char cQ[16384] = "";

	//5, 8, 9, 4
	int ID = m_pDlg_KP->m_EdFIO1.GetData();
	if (ID == 0)
	{
		ID = m_pDlg_KP->m_EdFIO2.GetData();
		if (ID == 0)
			ID = g_iFam;
	}
	

	if( i8os )
	{
		sprintf( cQ, "set nocount on\n\
set dateformat dmy\n\
declare @error int\n\
set @error = 0\n\
begin tran\n\
create table #VagonArxTovPairs (\n\
 VagID       int,\n\
 D_Test      datetime, --\n\
 Side        tinyint,    -- Сторона 0 - левая, 1 - правая\n\
 IsDevice    tinyint,    -- 4 - c.2730, 5 - c.4624\n\
 ID_Who      int,    -- Для ID_Device = 5, ID_Employee (пароль на входе)\n\
 Axle        tinyint,    -- Номер оси\n\
 Thickness   smallint,    -- толщина гребня\n\
 RimThickness smallint,    -- толщина обода\n\
 RimWidth    smallint,    -- ширина обода - нет\n\
 Roll        smallint,    -- Прокат    \n\
 Diameter    smallint,    -- Диаметр колеса - нет\n\
 Jag		 int,	\n\
 Flat		 int, \n\
 Welding	 int\n\
)\n\
declare @VagID bigint\n\
select @VagID=VagId from dbo.Vagon where Nom_Vag='%s'\n\
if @VagID is null goto roll_\n\
--Сюда вставлять данные:\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
---------------------\n\
exec @error = dbo.pTovPos4936m5_75 2\n\
if @@error != 0 or @error != 0 goto roll_\n\
drop table #VagonArxTovPairs\n\
commit tran\n\
goto ok_\n\
roll_: rollback tran\n\
ok_:",
		m_EdNVag.GetAsString (),
		ID, m_pDlg_KP->m_p[0][0].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][0].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][0].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][0].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][0].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][0].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][0].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][0].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][1].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][1].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][1].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][1].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][1].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][1].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][1].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][1].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][2].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][2].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][2].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][2].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][2].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][2].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][2].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][2].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][3].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][3].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][3].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][3].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][3].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][3].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][3].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][3].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][4].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][4].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][4].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][4].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][4].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][4].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][4].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][4].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][5].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][5].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][5].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][5].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][5].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][5].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][5].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][5].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][6].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][6].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][6].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][6].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][6].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][6].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][6].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][6].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][7].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][7].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][7].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][7].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][7].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][7].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][7].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][7].GetAsString ()/*Roll*/);
	}
	else
	{
		sprintf( cQ, "set nocount on\n\
set dateformat dmy\n\
declare @error int\n\
set @error = 0\n\
begin tran\n\
create table #VagonArxTovPairs (\n\
 VagID       int,\n\
 D_Test      datetime, --\n\
 Side        tinyint,    -- Сторона 0 - левая, 1 - правая\n\
 IsDevice    tinyint,    -- 4 - c.2730, 5 - c.4624\n\
 ID_Who      int,    -- Для ID_Device = 5, ID_Employee (пароль на входе)\n\
 Axle        tinyint,    -- Номер оси\n\
 Thickness   smallint,    -- толщина гребня\n\
 RimThickness smallint,    -- толщина обода\n\
 RimWidth    smallint,    -- ширина обода - нет\n\
 Roll        smallint,    -- Прокат    \n\
 Diameter    smallint,    -- Диаметр колеса - нет\n\
 Jag		 int,	\n\
 Flat		 int, \n\
 Welding	 int\n\
)\n\
declare @VagID bigint\n\
select @VagID=VagId from dbo.Vagon where Nom_Vag='%s'\n\
if @VagID is null goto roll_\n\
--Сюда вставлять данные:\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),0,5,%u,%s,%s,%s,null,%s,null)\n\
insert into #VagonArxTovPairs (VagID,D_Test,Side,IsDevice,ID_Who,Axle,Thickness,RimThickness,RimWidth,Roll,Diameter) values (@VagID,getdate(),1,5,%u,%s,%s,%s,null,%s,null)\n\
---------------------\n\
exec @error = dbo.pTovPos4936m5_75 2\n\
if @@error != 0 or @error != 0 goto roll_\n\
drop table #VagonArxTovPairs\n\
commit tran\n\
goto ok_\n\
roll_: rollback tran\n\
ok_:",
		m_EdNVag.GetAsString (),
		ID, m_pDlg_KP->m_p[0][0].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][0].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][0].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][0].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][0].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][0].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][0].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][0].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][1].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][1].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][1].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][1].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][1].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][1].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][1].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][1].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][2].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][2].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][2].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][2].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][2].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][2].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][2].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][2].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][3].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[11][3].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[10][3].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[12][3].GetAsString (),/*Roll*/
		ID, m_pDlg_KP->m_p[0][3].GetAsString (),/*Axle*/ m_pDlg_KP->m_p[ 8][3].GetAsString (),/*Thickness*/ m_pDlg_KP->m_p[ 7][3].GetAsString (),/*RimThickness*/ m_pDlg_KP->m_p[ 9][3].GetAsString ()/*Roll*/);
	}

	return CString (cQ);
}



void CDlgMsg4624_Main::OnBnClickedOk()
{
	
	if( !m_EdVRem.GetWindowTextLength() )
	{
		AfxMessageBox("Необходимо указать вид ремонта вагона!");
		return;
	}
	if( !m_EdVRemName.GetWindowTextLength() )
	{
		AfxMessageBox("Вид ремонта вагона указан неверно!");
		return;
	}
	SYSTEMTIME tm1, tm2, tm3;
	ZeroMemory(&tm1, sizeof(tm1));
	ZeroMemory(&tm2, sizeof(tm2));
	ZeroMemory(&tm3, sizeof(tm3));

	m_DatNeisp.GetTime(&tm1);
	m_pDlg_Header->m_DatRem.GetTime(&tm2);
	GetLocalTime(&tm3);
	if( SysDateCmp(tm1, tm3) > 0 )
	{
		AfxMessageBox("Дата перечисления в неисправные введена некорректно!");
		return;
	}

	if( SysDateCmp(tm1, tm2) > 0 )
	{
		AfxMessageBox("Дата отправки сообщения 4624 не может быть меньше даты перечисления в неисправные!");
		return;
	}

	if( StoreMsgToBase() == -1 ) return;
	if( g_iMessageNumber )
	{
		g_iMessageReturnResult = 1;
	}
	CDialog::OnOK();
}

void SortIndex(int *pValues, int *pDestIdx, int Length)
{
	int values[20];
	BOOL flag = 0;
	int iCount = 0;
	int min = 88;
	int min_idx = 0;
	for( int i=0; i < Length; i++ )
	{
		if( !pValues[i] )
			values[i] = 88;
		else
			values[i] = pValues[i];
	}

	for( int j=0; j < Length; j++ )
	{
		min = 100;
		for( int i=0; i < Length; i++ )
		{
			if( values[i] < min ) 
			{
				flag = 0;
				for( int x=0; x < iCount; x++ ) 
					if( pDestIdx[x] == i ) flag = 1;
				if( !flag )
				{
					min = values[i];
					min_idx = i;
				}
			}
		}
		pDestIdx[iCount] = min_idx;
		iCount++;
	}

}

int CDlgMsg4624_Main::WriteMsgLine(int idx)
{
	char cQ[1024] = "";
	long Ind = 0;
//	dwVRem = atoi(m_pDlg_Header->m_EdVRem.GetAsString());
	dwVRem = atoi(m_EdVRem.GetAsString());
	int iBalIdx = 0;
	if( idx == 0 || idx == 1 )
	{
		iBalIdx = 0;
	} else
		iBalIdx = 1;

	int values[8];
	int pKP_order[8] = {88, 88, 88, 88, 88, 88, 88, 88};
	int pLDTL_order[4] = {88, 88, 88, 88};

	int iLDTL_Count = 2;
	if( i8os ) iLDTL_Count = 4;

	CString sss = "";
	m_pDlg_LDTL->m_p[13][0].GetWindowText(sss);
	sss;
	m_pDlg_LDTL->StoreValues();

	for( int i=0; i < 8; i++ )
		values[i] = (int)m_pDlg_KP->m_p[0][i].GetAsDouble();
	SortIndex(values, pKP_order, 8);

	for( int i=0; i < iLDTL_Count; i++ )
		values[i] = atoi(m_pDlg_LDTL->m_BackBuffer.p_strNum[i]);
	SortIndex(values, pLDTL_order, iLDTL_Count);
	

	int p_iLDTLMdf[8] = {2, 2, 2, 2, 2, 2, 2, 2};

//	if( m_pDlg_LDTL->m_c[1].GetItemData(m_pDlg_LDTL->m_c[1].GetCurSel()))
	if( m_pDlg_LDTL->m_BackBuffer.p_iComboIndex[1])
	{
		p_iLDTLMdf[0] = 1;
	} else
		p_iLDTLMdf[1] = 1;
	if( m_pDlg_LDTL->m_BackBuffer.p_iComboIndex[4])
	{
		p_iLDTLMdf[2] = 1;
	} else
		p_iLDTLMdf[3] = 1;

	if( i8os )
	{
		if( m_pDlg_LDTL->m_BackBuffer.p_iComboIndex[7])
		{
			p_iLDTLMdf[4] = 1;
		} else
			p_iLDTLMdf[5] = 1;
		if( m_pDlg_LDTL->m_BackBuffer.p_iComboIndex[10])
		{
			p_iLDTLMdf[6] = 1;
		} else
			p_iLDTLMdf[7] = 1;
	}
	
	int p_iTlVagOrder[4] = {88, 88, 88, 88};
	
	values[0] = (int)m_pDlgTLVag->m_pL[0].GetAsDouble();
	values[1] = (int)m_pDlgTLVag->m_pL[1].GetAsDouble(); //was 2
	values[2] = (int)m_pDlgTLVag->m_pL[2].GetAsDouble();
	values[3] = (int)m_pDlgTLVag->m_pL[3].GetAsDouble();

	if( i8os )
		SortIndex(values, p_iTlVagOrder, 4);
	else
		SortIndex(values, p_iTlVagOrder, 2);

	int iLDTL_Br1_idx = 3*pLDTL_order[idx] + p_iLDTLMdf[2*pLDTL_order[idx]];
	int iLDTL_Br2_idx = 3*pLDTL_order[idx] + p_iLDTLMdf[2*pLDTL_order[idx]+1];
	
	char cText[64] = "";
	char msg[1024] = "pKP_order\t";	
	for( int i=0; i < 8; i++ )
	{
		strcat(msg, "[");
		strcat(msg, itoa(pKP_order[i], cText, 10));
		strcat(msg, "]");
	}
	DBW.WriteLog(msg);

	strcpy(msg, "pLDTL_order\t");
	for( int i=0; i < 4; i++ )
	{
		strcat(msg, "[");
		strcat(msg, itoa(pLDTL_order[i], cText, 10));
		strcat(msg, "]");
	}
	DBW.WriteLog(msg);
	strcpy(msg, "p_iLDTLMdf\t");
	for( int i=0; i < 4; i++ )
	{
		strcat(msg, "[");
		strcat(msg, itoa(p_iLDTLMdf[i], cText, 10));
		strcat(msg, "]");
	}
	DBW.WriteLog(msg);
	strcpy(msg, "p_iTlVagOrder\t");
	for( int i=0; i < 2; i++ )
	{
		strcat(msg, "[");
		strcat(msg, itoa(p_iTlVagOrder[i], cText, 10));
		strcat(msg, "]");
	}
	DBW.WriteLog(msg);
	sprintf(msg, "iLDTL_Br1_idx [%d] iLDTL_Br2_idx [%d]", 
			iLDTL_Br1_idx,
			iLDTL_Br2_idx);
	DBW.WriteLog(msg);

	/*
	CString sss = m_pDlgTLVag->m_pL[p_iTlVagOrder[idx]*2+1].GetAsString();
	sss = m_pDlgBlTl->m_pEd[1][iBalIdx].GetAsString();*/

	sprintf( cQ, "pTov_S4624InsInf  %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, \
%s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s",
				 isNull(qwIDS),
				 isNull(dwVRem),
				 isNull(dw_nPhrase),

				 isNull(m_pDlg_KP->m_p[1][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[2][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[3][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[4][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[5][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[6][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[7][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[8][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[9][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[10][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[11][pKP_order[2*idx]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[12][pKP_order[2*idx]].GetAsString()), //15

				 isNull(m_pDlg_KP->m_p[1][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[2][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[3][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[4][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[5][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[6][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[7][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[8][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[9][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[10][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[11][pKP_order[2*idx + 1]].GetAsString()),
				 isNull(m_pDlg_KP->m_p[12][pKP_order[2*idx + 1]].GetAsString()), //27
//		Надрессорная балка
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[2][3*pLDTL_order[idx]]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[3][3*pLDTL_order[idx]]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[4][3*pLDTL_order[idx]]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[5][3*pLDTL_order[idx]]),
//				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[6][3*pLDTL_order[idx]]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[8][3*pLDTL_order[idx]]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[9][3*pLDTL_order[idx]]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[10][3*pLDTL_order[idx]]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[11][3*pLDTL_order[idx]]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[12][3*pLDTL_order[idx]]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[13][3*pLDTL_order[idx]]),

//		первая боковая рама
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[2][iLDTL_Br1_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[3][iLDTL_Br1_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[4][iLDTL_Br1_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[5][iLDTL_Br1_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[6][iLDTL_Br1_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[7][iLDTL_Br1_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[11][iLDTL_Br1_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[12][iLDTL_Br1_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[13][iLDTL_Br1_idx]), //46
//		вторая боковая рама
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[2][iLDTL_Br2_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[3][iLDTL_Br2_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[4][iLDTL_Br2_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[5][iLDTL_Br2_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[6][iLDTL_Br2_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[7][iLDTL_Br2_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[11][iLDTL_Br2_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[12][iLDTL_Br2_idx]),
				 isNull(m_pDlg_LDTL->m_BackBuffer.str_p[13][iLDTL_Br2_idx]), //55

//		Характеристика тележек под вагоном 
				 isNull(m_pDlgTLVag->m_pL[p_iTlVagOrder[idx]*2+1].GetAsString()),

//		правая сторона тележки
				 isNull(m_pDlgTLVag->m_p[1][p_iTlVagOrder[idx]*2 + 1].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[2][p_iTlVagOrder[idx]*2 + 1].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[3][p_iTlVagOrder[idx]*2 + 1].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[4][p_iTlVagOrder[idx]*2 + 1].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[5][p_iTlVagOrder[idx]*2 + 1].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[6][p_iTlVagOrder[idx]*2 + 1].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[7][p_iTlVagOrder[idx]*2 + 1].GetAsString()), //63
//		левая сторона тележки
				 isNull(m_pDlgTLVag->m_p[1][p_iTlVagOrder[idx]*2].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[2][p_iTlVagOrder[idx]*2].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[3][p_iTlVagOrder[idx]*2].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[4][p_iTlVagOrder[idx]*2].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[5][p_iTlVagOrder[idx]*2].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[6][p_iTlVagOrder[idx]*2].GetAsString()),
				 isNull(m_pDlgTLVag->m_p[7][p_iTlVagOrder[idx]*2].GetAsString()), //70
				 
//		Соединительная балка
				 isNull(m_pDlgBlTl->m_pEd[1][iBalIdx].GetAsString()),
				 isNull(m_pDlgBlTl->m_pEd[2][iBalIdx].GetAsString()),
				 isNull(m_pDlgBlTl->m_pEd[3][iBalIdx].GetAsString()),
				 isNull(m_pDlgBlTl->m_pEd[4][iBalIdx].GetAsString()));
	dw_nPhrase++;
//	ShowMsg(cQ);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	long lNum = -1;
	DBW.GetData(1, SQL_C_SLONG, &lNum, 4, &Ind);
	DBW.CloseCursor();
	if( lNum ) 
	{
		ShowMsg("pTov_S4624InsInf failed!");
		DBW.WriteLog("pTov_S4624InsInf failed!");
	}
	switch(idx)
	{
	case 0:
		strncpy( cProc1, cQ, 1023);
		break;
	case 1:
		strncpy( cProc2, cQ, 1023);
		break;
	case 2:
		strncpy( cProc3, cQ, 1023);
		break;
	case 3:
		strncpy( cProc4, cQ, 1023);
		break;
	}
	return lNum;
}

void CDlgMsg4624_Main::OnBnClickedButton1()
{
	if( m_EdVRem.isNull() )
	{
		AfxMessageBox("Необходимо указать вид ремонта вагона!");
		m_EdVRem.SetFocus();
		return;
	}
	if( !m_EdVRemName.GetWindowTextLength() )
	{
		AfxMessageBox("Вид ремонта вагона указан неверно!");
		m_EdVRemName.SetFocus();
		return;
	}
	if( StoreMsgToBase() == -1 ) return;
	CPrintableDlg Dlg;
//	Dlg.bDosCodePage = 1;
	if( !g_iMessageNumber )
	{
		sprintf(Dlg.cQ, "pTov_S4624Form %s", isNull(qwIDS));
		Dlg.DoModal();
	}
	char cQ[64] = "";
	if (!g_iStandAlone && g_iMessageNumber)
	{
		SYSTEMTIME curtime;
		GetLocalTime (&curtime);
		CString s1;
		s1.Format("(:4936 1 4\r\n11A %s/%d# %d%02d%02d%02d%02d:)", m_EdNVag.GetAsString(), g_iDep, curtime.wYear, curtime.wMonth, curtime.wDay, curtime.wHour, curtime.wMinute );
		DBW.SendMessageToDst(s1, "", g_strTelecomServer);

	}
	char cText[4196] = "";
	long Ind = 0;
	if( dwVRem == 72 || g_iSend4624AsoupDirect == 1)
	{
		if( !g_iEnableTelecom || !tele )
		{
			AfxMessageBox("Для отправки данного сообщения нобходимо включить телеобработку!");
			return;
		}
//        char cText[4196] = "";
//        long Ind = 0;
		long lNum = 0;

        sprintf(cQ, "pTov_S4624Form %s", isNull(qwIDS));
        DBW.ExecSQL(cQ);
        DBW.Fetch();
        DBW.GetData(1, SQL_C_CHAR, cText, 4196, &Ind);
		DBW.GetData(2, SQL_C_SLONG, &lNum, 4, &Ind);
        DBW.CloseCursor();

		if( lNum )
        {
            AfxMessageBox("Сообщение не сформировано!", MB_OK);
            DBW.WriteLog("Сообщение не сформировано!");
            return;
        }
		if( g_strASOUPTeleName != "" && tele ) tele->SendMessageDst(cText, &g_strASOUPTeleName);

	} else
	if( !g_iStandAlone && g_iEnableTelecom && !g_iMessageNumber )
	{
		SYSTEMTIME st;
		ZeroMemory(&st, sizeof(st));
//		m_pDlg_Header->m_DatNeisp.GetTime(&st);
		m_pDlg_Header->m_DatRem.GetTime(&st);
		CString s1;
		s1.Format("(:4936 %d 4\r\n11A %.8s %.4d%.2d%.2d%.2d%.2d :)", g_iFam,
					cVagNum32, 
					st.wYear, 
					st.wMonth, 
					st.wDay, 
					m_pDlg_Header->m_Hour2.GetAsDWord(),
					m_pDlg_Header->m_Min2.GetAsDWord());
		char mess[512] = "";
		sprintf(mess, "message text: %s", s1);
		DBW.WriteLog(mess);
		if( g_strTelecomServer != "" && tele ) tele->SendMessageDst(s1, &g_strTelecomServer);
	} else
	if( g_conf_strMessagePath != "" && !g_iMessageNumber)
    {        
//        char cText[4196] = "";
//        long Ind = 0;
		long lNum = 0;

        sprintf(cQ, "pTov_S4624Form %s", isNull(qwIDS));
        DBW.ExecSQL(cQ);
        DBW.Fetch();
        DBW.GetData(1, SQL_C_CHAR, cText, 4196, &Ind);
		DBW.GetData(2, SQL_C_SLONG, &lNum, 4, &Ind);
        DBW.CloseCursor();

        if( lNum )
        {
            AfxMessageBox("Сообщение не сформировано!", MB_OK);
            DBW.WriteLog("Сообщение не сформировано!");
            return;
        }
        CString strN;
        SYSTEMTIME st;
		ZeroMemory(&st, sizeof(st));
        GetLocalTime(&st);
        strN.Format("%s%.2d%.2d_%s.txt", 
                    g_conf_strMessagePath,
                    st.wMonth,
                    st.wDay,
                    cVagNum32);
        char sl[64] = "";
        sprintf(sl, "Msg: %s", strN);
        DBW.WriteLog((LPTSTR)sl, 3);
        FILE *f = fopen(strN, "wb");
        if( !f )
        {
            AfxMessageBox("Невозможно открыть файл!", MB_OK);
            return;
        }
		if( g_bDosCodePage )
			theApp.Win2Dos(cText, strlen(cText));
        fwrite(cText, strlen(cText), 1, f);
        fclose(f);
		if( g_bDosCodePage )
			theApp.Dos2Win((unsigned char *)cText, strlen(cText));
		//		theApp.Dos2Win((unsigned char *)cText, strlen(cText));
		if( g_strASOUPTeleName != "" && tele ) tele->SendMessageDst(cText, &g_strASOUPTeleName);
	}
	char cmess[512] = "";
	long iret = 0;
//	long Ind = 0;
	sprintf(cQ, "pTov_S4624Del497 %s", isNull(qwIDS));
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SLONG, &iret, sizeof(long), &Ind);
	char sssss[100] = "";
	sprintf(sssss, "Первое поле которое вернула процедура pTov_S4624Del497: %d", iret);
	if( Ind != -1 && iret == 1 )
	{
		DBW.GetData(2, SQL_C_CHAR, &cmess, 512, &Ind);
		if( Ind != -1 && AfxMessageBox(cmess, MB_YESNO) == IDYES )
		{
			DBW.CloseCursor();
			sprintf(cQ, "pTov_S4624Del497 %s, 1", isNull(qwIDS));
			DBW.ExecSQL(cQ);
		}
	}
	DBW.CloseCursor();
	DBW.WriteLog("Здесь присваеваем код возврата = 2");
	g_iMessageReturnResult = 2;
	CDialog::OnOK();
}
/*
void CDlgMsg4624_Main::OnEnKillfocusEdit_VRem()
{
	char cText[64] = "";
	m_pDlg_Header->m_EdVRem.GetWindowText(cText, 64);
	if( (atoi(cText) != 39 || atoi(cText) != 49) && m_Tab.GetItemCount() > 4 )
	{
		m_Tab.DeleteItem(5);
		m_Tab.DeleteItem(6);
		m_Tab.DeleteItem(7);
	} else
	{
		InsertZamenaTabs();
	}
}
*/

void CDlgMsg4624_Main::InsertZamenaTabs(void)
{
	if( m_Tab.GetItemCount() > 5 ) return;

	iZamena = 1;

	delete m_pDlgZamenaBlTl;
	delete m_pDlgZamenaKP;
	delete m_pDlgZamenaLDTL;

	m_pDlgZamenaBlTl = new CDlgMsg4624_ZamenaBlTl;
	m_pDlgZamenaKP = new CDlgMsg4624_ZamenaKP;
	m_pDlgZamenaLDTL = new CDlgMsg4624_ZamenaLDTL;

	m_pWndTab[iZmKP_Idx] = m_pDlgZamenaKP;
	m_pWndTab[iZmLDTL_Idx] = m_pDlgZamenaLDTL;
	m_pWndTab[iZmBl_Idx] = m_pDlgZamenaBlTl;

	TCITEM ti;

	ti.mask = TCIF_TEXT;
	ti.pszText = _T("5. Замен. КП");
	ti.lParam = (LPARAM)m_pDlgZamenaKP;
	VERIFY(m_pDlgZamenaKP->Create(CDlgMsg4624_ZamenaKP::IDD, &m_Tab));
	m_Tab.InsertItem(5, &ti);
	m_pDlgZamenaKP->SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	ti.pszText = _T("6. Замен. дет. тел.");
	ti.lParam = (LPARAM)m_pDlgZamenaLDTL;
	VERIFY(m_pDlgZamenaLDTL->Create(CDlgMsg4624_ZamenaLDTL::IDD, &m_Tab));
	m_Tab.InsertItem(6, &ti);
	m_pDlgZamenaLDTL->SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	ti.pszText = _T("7. Замен. соед. балки");
	ti.lParam = (LPARAM)m_pDlgZamenaBlTl;
	VERIFY(m_pDlgZamenaBlTl->Create(CDlgMsg4624_ZamenaBlTl::IDD, &m_Tab));
//	if( dwOsCount == 8 )
	if( i8os )
	{
		m_Tab.InsertItem(7, &ti);
		m_pDlgZamenaBlTl->SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
	}

	if( !g_iStandAlone || g_iMessageNumber )
	{
		m_pDlgZamenaBlTl->m_FIO.EnableWindow(0);
		m_pDlgZamenaBlTl->m_bnFio.EnableWindow(0);
		/*
		m_pDlgZamenaKP->m_FIO1.EnableWindow(0);
		m_pDlgZamenaKP->m_bnFio.EnableWindow(0);
		*/
		m_pDlgZamenaLDTL->m_FIO.EnableWindow(0);
		m_pDlgZamenaLDTL->m_bnFio.EnableWindow(0);
	}
	if( !g_iAutoPrihodKP )
	{
		for( int i=0; i < 8; i++ )
			m_pDlgZamenaKP->m_pTKP[i].EnableWindow(0);
	}

	SetEnabledBy8Os(i8os);
	SetIzNalButtons();
}

void CDlgMsg4624_Main::WriteMsgZamenaKP(int idx)
{
	int iFilled = 0;
	for( int i=2; i < 14; i++ )
	{
		if( !m_pDlgZamenaKP->m_p[i][idx].isNull() )
		{
			iFilled = 1;
			break;
		}
	}
	if( !iFilled ) return;
	char cQ[512] = "";
	sprintf(cQ, "pTov_S4624InsInfZamenKP  %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d, %s",
			isNull(qwIDS),
			dw_nPhrase,
			m_pDlgZamenaKP->m_p[0][idx].GetAsString(),
			isNull(m_pDlgZamenaKP->m_p[1][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[2][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[3][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[4][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[5][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[6][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[7][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[8][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[9][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[10][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[11][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[12][idx].GetAsString()),
			isNull(m_pDlgZamenaKP->m_p[13][idx].GetAsString()),
			m_pDlgZamenaKP->m_pTKP[idx].GetCurSel() == -1 ? 100 : m_pDlgZamenaKP->m_pTKP[idx].GetItemData( m_pDlgZamenaKP->m_pTKP[idx].GetCurSel() ),
			isNull( m_pDlgZamenaKP->m_FIO1.GetData() )
			);
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	dw_nPhrase++;
	sprintf(cScript, "%s\n\texec %s",cScript, cQ);
}

void CDlgMsg4624_Main::WriteMsgZamenaLDTL(int idx)
{
	m_pDlgZamenaLDTL->StoreValues();

	int iFilled = 0;
	for( int i=2; i < 10; i++ )
	{
		if( !m_pDlgZamenaLDTL->m_BackBuffer.str_p[i][idx * 3].IsEmpty() )
		{
			iFilled = 1;
			break;
		}
	}
	char cQ[512] = "";
	if( iFilled )
	{
		sprintf(cQ, "pTov_S4624InsInfZamenTL  %s, %u, %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
				isNull(qwIDS),
				dw_nPhrase,
	//			m_pDlgZamenaLDTL->m_Num[idx].GetAsString(),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.p_strNum[idx]),
				0,
				"NULL",

				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[2][idx * 3]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[3][idx * 3]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][idx * 3]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[5][idx * 3]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[6][idx * 3]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[7][idx * 3]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[8][idx * 3]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[9][idx * 3]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[10][idx * 3])
				);
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();
		dw_nPhrase++;
		sprintf(cScript, "%s\n\texec %s",cScript, cQ);
	}
	iFilled = 0;
	for( int i=2; i < 10; i++ )
	{
		if( !m_pDlgZamenaLDTL->m_BackBuffer.str_p[i][idx * 3 + 1].IsEmpty() )
		{
			iFilled = 1;
			break;
		}
	}
	if( iFilled )
	{
		sprintf(cQ, "pTov_S4624InsInfZamenTL  %s, %u, %s, %u, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s",
				isNull(qwIDS),
				dw_nPhrase,
	//			isNull(m_pDlgZamenaLDTL->m_Num[idx].GetAsString()),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.p_strNum[idx]),
				1,
				m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[idx*3+1],
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[2][idx*3 + 1]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[3][idx*3 + 1]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][idx*3 + 1]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[5][idx*3 + 1]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[6][idx*3 + 1]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[7][idx*3 + 1]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[8][idx*3 + 1]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[9][idx*3 + 1]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[10][idx*3 + 1])
				);
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();
		dw_nPhrase++;
		sprintf(cScript, "%s\n\tinsert into #reslt exec %s",cScript, cQ);
	}
	iFilled = 0;
	for( int i=2; i < 10; i++ )
	{
		if( !m_pDlgZamenaLDTL->m_BackBuffer.str_p[i][idx * 3 + 2].IsEmpty() )
		{
			iFilled = 1;
			break;
		}
	}
	if( iFilled )
	{
		sprintf(cQ, "pTov_S4624InsInfZamenTL  %s, %u, %s, %u, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s",
				isNull(qwIDS),
				dw_nPhrase,
	//			isNull(m_pDlgZamenaLDTL->m_Num[idx].GetAsString()),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.p_strNum[idx]),
				1,
				m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[idx*3+2],
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[2][idx*3 + 2]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[3][idx*3 + 2]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][idx*3 + 2]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[5][idx*3 + 2]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[6][idx*3 + 2]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[7][idx*3 + 2]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[8][idx*3 + 2]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[9][idx*3 + 2]),
				isNull(m_pDlgZamenaLDTL->m_BackBuffer.str_p[10][idx*3 + 2])
				);
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();
		dw_nPhrase++;
		sprintf(cScript, "%s\n\tinsert into #reslt1 exec %s",cScript, cQ);
	}
}

void CDlgMsg4624_Main::FillZamenaTabs(void)
{
	char cQ[128] = "";
	char cText[64] = "";
	long Ind = 0;
	int	 iCol = 1;
	DWORD dwNum = 0;
	sprintf(cQ, "pTov_S4624SelZamenKP %s, %s",
		isNull(qwIDS),
		isNull(qwILK));
	DBW.ExecSQL(cQ);
	for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 8; i++ )
	{
/*		DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
		m_pDlgZamenaKP->m_p[0]*/
		iCol = 1;
		for( int j=0; j < 14; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_pDlgZamenaKP->m_p[j][i].SetWindowText(cText);
			iCol++;
		}
		DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1) SetComboBoxItemByID( &m_pDlgZamenaKP->m_pTKP[i], dwNum );
		// сюда выбор типа
	}
	DBW.CloseCursor();

// Литые детали тележки
	dwNum = 0;
	sprintf(cQ, "pTov_S4624SelZamenTL %s, %s",
		isNull(qwIDS),
		isNull(qwILK));
	DBW.ExecSQL(cQ);
	for( int idx = 0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && idx < 4; idx++)
	{
// Номер
		DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) 
		{
//			m_pDlgZamenaLDTL->m_Num[idx].SetWindowText(cText);
			m_pDlgZamenaLDTL->m_BackBuffer.p_strNum[idx] = cText;
		}
		iCol = 2;
// Рама
		for( int i=0; i < 9; i++ )
		{
			if(i == 4) continue;
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 )
			{
//				m_pDlgZamenaLDTL->m_p[i + 2][idx * 3].SetWindowText(cText);
				m_pDlgZamenaLDTL->m_BackBuffer.str_p[i + 2][idx * 3] = cText;
			}
			iCol++;
		}
// Балка 1
		DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
//		m_pDlgZamenaLDTL->m_c[idx * 3 + 1].SetCurSel(dwNum);
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[idx * 3 + 1] = dwNum;
		iCol++;

		for( int i=0; i < 9; i++ )
		{			
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 )
			{
//				m_pDlgZamenaLDTL->m_p[i + 2][idx*3 + 1].SetWindowText(cText);
				m_pDlgZamenaLDTL->m_BackBuffer.str_p[i + 2][idx * 3 + 1] = cText;
			}
			iCol++;
		}
// Балка 2
		DBW.GetData(iCol, SQL_C_ULONG, &dwNum, 4, &Ind );
//		m_pDlgZamenaLDTL->m_c[idx * 3 + 2].SetCurSel(dwNum);
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[idx * 3 + 2] = dwNum;					

		iCol++;
		for( int i=0; i < 9; i++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 )
			{
//				m_pDlgZamenaLDTL->m_p[i + 2][idx*3 + 2].SetWindowText(cText);
				m_pDlgZamenaLDTL->m_BackBuffer.str_p[i + 2][idx * 3 + 2] = cText;
			}
			iCol++;
		}

	}
	DBW.CloseCursor();
	
	if( m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[1] ==
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[2] )
	{
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[1] = 1;
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[2] = 0;
	}

	if( m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[4] ==
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[5] )
	{
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[4] = 1;
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[5] = 0;
	}

	if( m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[7] ==
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[8] )
	{
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[7] = 1;
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[8] = 0;
	}

	if( m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[10] ==
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[11] )
	{
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[10] = 1;
		m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[11] = 0;
	}



	m_pDlgZamenaLDTL->DrawBuffer(0);
	sprintf(cQ, "pTov_S4624SelZamenSB %s, %s",
			isNull(qwIDS),
			isNull(qwILK));
	DBW.ExecSQL(cQ);
	for( int i=0; i < 2 && (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
	{
		iCol = 1;
		for( int x = 0; x < 5; x++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_pDlgZamenaBlTl->m_pEd[x][i].SetWindowText(cText);
			iCol++;
		}
	}
	DBW.CloseCursor();
}

void CDlgMsg4624_Main::WriteMsgZamenaBlTl(int idx)
{
	char cQ[256] = "";
	int iFilled = 0;
	for( int i=1; i < 10; i++ )
	{
		if( !m_pDlgZamenaBlTl->m_pEd[i][idx].isNull() )
		{
			iFilled = 1;
			break;
		}
	}
	if( !iFilled ) return;
	sprintf( cQ, "pTov_S4624InsInfZamenSB  %s, %u, %s, %s, %s, %s, %s",
			isNull(qwIDS),
			dw_nPhrase,
			m_pDlgZamenaBlTl->m_pEd[0][idx].GetAsString(),
			isNull(m_pDlgZamenaBlTl->m_pEd[1][idx].GetAsString()),
			isNull(m_pDlgZamenaBlTl->m_pEd[2][idx].GetAsString()),
			m_pDlgZamenaBlTl->m_pEd[3][idx].GetAsString(),
			m_pDlgZamenaBlTl->m_pEd[4][idx].GetAsString());
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	dw_nPhrase++;
	sprintf(cScript, "%s\n\texec %s",cScript, cQ);
}

void CDlgMsg4624_Main::SetEnabledItemsOfRemCode(DWORD VRem)
{

	int iOs = 4;
	if( i8os ) iOs = 8;

	for(int i=0; i < iOs; i++ )
	{
			m_pDlg_KP->m_p[8][i].EnableWindow(TRUE);
			m_pDlg_KP->m_p[9][i].EnableWindow(TRUE);
			m_pDlg_KP->m_p[11][i].EnableWindow(TRUE);
			m_pDlg_KP->m_p[12][i].EnableWindow(TRUE);
	}

	for( int i=0; i < 6; i++ )
	{	
		if( i != 0 && i != 3 ) 
		{
			m_pDlg_LDTL->m_p[6][i].EnableWindow(TRUE);
			m_pDlg_LDTL->m_p[7][i].EnableWindow(TRUE);
		}
		if( i == 0 || i == 3 )
		{
			m_pDlg_LDTL->m_p[8][i].EnableWindow(TRUE);
			m_pDlg_LDTL->m_p[9][i].EnableWindow(TRUE);
			m_pDlg_LDTL->m_p[10][i].EnableWindow(TRUE);
		}
		m_pDlg_LDTL->m_p[11][i].EnableWindow(TRUE);
		m_pDlg_LDTL->m_p[12][i].EnableWindow(TRUE);
		m_pDlg_LDTL->m_p[13][i].EnableWindow(TRUE);
	}

	for( int i=0; i < iOs; i++ )
	{
		m_pDlgTLVag->m_p[3][i].EnableWindow(TRUE);
		m_pDlgTLVag->m_p[4][i].EnableWindow(TRUE);
		m_pDlgTLVag->m_p[5][i].EnableWindow(TRUE);
		m_pDlgTLVag->m_p[6][i].EnableWindow(TRUE);
	}
	m_pDlgBlTl->m_pEd[4][0].EnableWindow(TRUE);
	m_pDlgBlTl->m_pEd[4][1].EnableWindow(TRUE);
	
	switch( VRem )
	{
	case 3:
	case 72:
	case 4:
	case 39:
	case 49:
		for( int i=0; i < 6; i++ )
		{
			m_pDlg_LDTL->m_p[7][i].EnableWindow(FALSE);
			m_pDlg_LDTL->m_p[8][i].EnableWindow(FALSE);
			m_pDlg_LDTL->m_p[9][i].EnableWindow(FALSE);
			m_pDlg_LDTL->m_p[10][i].EnableWindow(FALSE);
		}
		for( int i=0; i < 8; i++ )
		{
			m_pDlgTLVag->m_p[3][i].EnableWindow(FALSE);
			m_pDlgTLVag->m_p[4][i].EnableWindow(FALSE);
			m_pDlgTLVag->m_p[5][i].EnableWindow(FALSE);
			m_pDlgTLVag->m_p[6][i].EnableWindow(FALSE);
		}
		m_pDlgBlTl->m_pEd[4][0].EnableWindow(FALSE);
		m_pDlgBlTl->m_pEd[4][1].EnableWindow(FALSE);
		break;
	case 5:
		for(int i=0; i < 8; i++ )
		{
			m_pDlg_KP->m_p[8][i].EnableWindow(FALSE);
			m_pDlg_KP->m_p[9][i].EnableWindow(FALSE);
			m_pDlg_KP->m_p[11][i].EnableWindow(FALSE);
			m_pDlg_KP->m_p[12][i].EnableWindow(FALSE);
		}
		for( int i=0; i < 6; i++ )
		{	
			m_pDlg_LDTL->m_p[6][i].EnableWindow(FALSE);
			m_pDlg_LDTL->m_p[7][i].EnableWindow(FALSE);
			m_pDlg_LDTL->m_p[8][i].EnableWindow(FALSE);
			m_pDlg_LDTL->m_p[9][i].EnableWindow(FALSE);
			m_pDlg_LDTL->m_p[10][i].EnableWindow(FALSE);
			m_pDlg_LDTL->m_p[11][i].EnableWindow(FALSE);
			m_pDlg_LDTL->m_p[12][i].EnableWindow(FALSE);
			m_pDlg_LDTL->m_p[13][i].EnableWindow(FALSE);
		}
		m_pDlgBlTl->m_pEd[4][0].EnableWindow(FALSE);
		m_pDlgBlTl->m_pEd[4][1].EnableWindow(FALSE);
	}
//	if( dwOsCount != 8 )
	for( int i = 0; i < 8; i++ )
		m_pDlg_KP->m_lpButIz[i].EnableWindow(FALSE);
	
	m_pDlg_LDTL->m_ButIz1.EnableWindow(FALSE);
	m_pDlg_LDTL->m_ButIz2.EnableWindow(FALSE);
	m_pDlg_LDTL->m_ButIz3.EnableWindow(FALSE);
	m_pDlg_LDTL->m_ButIz4.EnableWindow(FALSE);
	m_pDlg_LDTL->m_ButIz5.EnableWindow(FALSE);
	m_pDlg_LDTL->m_ButIz6.EnableWindow(FALSE);

	if(dwVRem == 39 || dwVRem == 49 )
	{
		m_pDlg_LDTL->m_ButIz1.EnableWindow();
		m_pDlg_LDTL->m_ButIz2.EnableWindow();
		m_pDlg_LDTL->m_ButIz3.EnableWindow();
		m_pDlg_LDTL->m_ButIz4.EnableWindow();
		m_pDlg_LDTL->m_ButIz5.EnableWindow();
		m_pDlg_LDTL->m_ButIz6.EnableWindow();

		if( i8os )
			for( int i = 0; i < 8; i++ )
					m_pDlg_KP->m_lpButIz[i].EnableWindow();

	}
	if( !i8os )
	{
		for( int i=0; i < 13; i++ )
			for( int j=4; j < 8; j++ )
			{
				m_pDlg_KP->m_p[i][j].EnableWindow(FALSE);
				if( dwVRem == 39 || dwVRem == 49 ) m_pDlgZamenaKP->m_p[i][j].EnableWindow(FALSE);
			}
		if( dwVRem == 39 || dwVRem == 49 )
		{
			for( int i=4; i < 8; i++ )
				m_pDlgZamenaKP->m_p[13][i].EnableWindow(FALSE);
			for( int i = 0; i < 4; i++ )
				m_pDlg_KP->m_lpButIz[i].EnableWindow();
		}
	}

	if( VRem == 72 )
	{
		m_pDlg_LDTL->m_p[6][1].EnableWindow(0);
		m_pDlg_LDTL->m_p[6][2].EnableWindow(0);

		m_pDlg_LDTL->m_p[6][4].EnableWindow(0);
		m_pDlg_LDTL->m_p[6][5].EnableWindow(0);
	}
}

void CDlgMsg4624_Main::OnBnClickedButton_NextTab()
{
	int iCurTab = m_Tab.GetCurSel();
	int i_nTabs = m_Tab.GetItemCount();

	CurWnd->ShowWindow(SW_HIDE);
	iCurTab++;
	if( iCurTab >= i_nTabs ) iCurTab = 0;

	m_Tab.SetCurSel(iCurTab);
	m_pWndTab[iCurTab]->ShowWindow(SW_SHOW);
	CurWnd = m_pWndTab[iCurTab];
}

void CDlgMsg4624_Main::OnBnClickedButton_PrevTab()
{
	int iCurTab = m_Tab.GetCurSel();
	int i_nTabs = m_Tab.GetItemCount();

	CurWnd->ShowWindow(SW_HIDE);

	if( iCurTab == 0 ) iCurTab = i_nTabs - 1;
	else iCurTab--;

	m_Tab.SetCurSel(iCurTab);
	m_pWndTab[iCurTab]->ShowWindow(SW_SHOW);
	CurWnd = m_pWndTab[iCurTab];
}


void CDlgMsg4624_Main::OnCancel()
{
	if( !iHidden && (!g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Внимание!", MB_YESNO) == IDNO)) 
	{
		return;
	}

	CDlgWithAccelerators::OnCancel();
}
void CDlgMsg4624_Main::OnEnKillfocusEdit1()
{
//	m_pWndTab[m_Tab.GetCurSel()]->SetFocus();
	m_pDlg_Header->m_EdRemPR.SetFocus();
}

void CDlgMsg4624_Main::OnDestroy()
{
	if (m_pDlg_Header)	delete m_pDlg_Header;
	if (m_pDlg_KP)		delete m_pDlg_KP;
	if (m_pDlg_LDTL)	delete m_pDlg_LDTL;
	if (m_pDlgTLVag)	delete m_pDlgTLVag;
	if (m_pDlgZamenaBlTl)	delete m_pDlgZamenaBlTl;
	if (m_pDlgZamenaKP)		delete m_pDlgZamenaKP;
	if (m_pDlgZamenaLDTL)	delete m_pDlgZamenaLDTL;
	if (m_pDlgBlTl)		delete m_pDlgBlTl;
}

void CDlgMsg4624_Main::OnEnChangeEdit_VRem()
{
	char cText[64] = "";
	m_EdVRem.GetWindowText(cText, 64);
	int index = 0;
	int r = 0;
	DWORD dwOldVRem = dwVRem;
	index = atoi(cText);

	if( index == 3 || index == 4 )
	{
		m_ButVU36.SetWindowText("ВУ-36 (сокр.)");
	} else
		m_ButVU36.SetWindowText("ВУ-36 (полн.)");

	if( index != 39 && index != 49 && index != 72 && index > 5 ) 
	{
		m_EdVRemName.SetWindowText("");
		return;
	}
	r = index;
	if( index == 39 ) index = 6;
	if( index == 49 ) index = 7;
	if( index == 72 ) index = 8;
	m_EdVRemName.SetWindowText(m_pVRem[index]);
/*
	CDlgMsg4624_Main *dlg = (CDlgMsg4624_Main *)m_pMainTabWnd;
	if( !dlg->bStarted ) return;*/
	dwVRem = r;
	if( !bStarted ) return;
	if( index == 6 || index == 7 )
	{
		m_bnZamena.SetCheck(1);
		InsertZamenaTabs();
	}
	else
	{
		iZamena = 0;
		if( dwOldVRem == 39 || dwOldVRem == 49 )
		{
			if( iZmKP_Idx == m_Tab.GetCurSel() )
			{
				m_Tab.SetCurSel(iZmKP_Idx - 1);
				CurWnd->ShowWindow(SW_HIDE);
				CurWnd = m_pWndTab[iZmKP_Idx - 1];
				CurWnd->ShowWindow(SW_SHOW);
			}
			m_Tab.DeleteItem(iZmKP_Idx);
			m_Tab.DeleteItem(iZmKP_Idx);
			m_Tab.DeleteItem(iZmKP_Idx);
		}
		m_bnZamena.SetCheck(0);

	}
	if( index != 3 && index != 4 && index != 6 && index != 7) m_bnZamena.EnableWindow(FALSE);
	else m_bnZamena.EnableWindow();
	SetEnabledItemsOfRemCode(dwVRem);
//	dlg->RedrawWindow();
	m_EdVRem.SetFocus();
	SetIzNalButtons();
	m_Tab.RedrawWindow();
	

/*	if( (index == 6 || index == 7) m_pWnd2->m_Tab.GetItemCount() < 5 ) 
		m_pWnd2->InsertZamenaTabs();*/
	
}

void CDlgMsg4624_Main::OnBnClicked_ZamenaCheck()
{
	char cText[64] = "";
	m_EdVRem.GetWindowText(cText, 64);
	if( m_bnZamena.GetCheck() && (cText[0] == '3' || cText[0] == '4' ))
	{
		cText[1] = '9';	
	} else
	{
		cText[1] = 0;
	}
	iZamena = m_bnZamena.GetCheck();
	m_EdVRem.SetWindowText(cText);
}

void CDlgMsg4624_Main::OnBnClickedCheck_8Os()
{
	if( m_8OsCheck.GetCheck() )
	{
		m_pDlg_LDTL->m_8OsButton.EnableWindow();		
		i8os = 1;

//		if( m_Tab.GetItemCount() > 5 )
//		{
			if (m_pDlgBlTl) delete m_pDlgBlTl;
			m_pDlgBlTl = new CDlgMsg4624_BlTl;
			TCITEM ti;
			ti.mask = TCIF_TEXT;
			ti.pszText = _T("4. Соед. балки");
			ti.lParam = (LPARAM)m_pDlgBlTl;
			VERIFY(m_pDlgBlTl->Create(CDlgMsg4624_BlTl::IDD, &m_Tab));
			m_Tab.InsertItem(iZmKP_Idx, &ti);
			m_pDlgBlTl->SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

			m_pWndTab[iZmKP_Idx] = m_pDlgBlTl;
			iZmKP_Idx++;
			iZmLDTL_Idx++;
			iZmBl_Idx++;
			m_pWndTab[iZmKP_Idx] = m_pDlgZamenaKP;
			m_pWndTab[iZmLDTL_Idx] = m_pDlgZamenaLDTL;

			if( i8os && iZamena )
			{
				if(m_pDlgZamenaBlTl) delete m_pDlgZamenaBlTl;
				m_pDlgZamenaBlTl = new CDlgMsg4624_ZamenaBlTl;
				
				ti.pszText = _T("7. Замен. соед. балки");
				ti.lParam = (LPARAM)m_pDlgZamenaBlTl;
				VERIFY(m_pDlgZamenaBlTl->Create(CDlgMsg4624_ZamenaBlTl::IDD, &m_Tab));
				m_Tab.InsertItem(iZmBl_Idx, &ti);
				m_pDlgZamenaBlTl->SetWindowPos(NULL, 5, 25, 0, 0, SWP_NOSIZE | SWP_NOZORDER);
				m_pDlgZamenaLDTL->m_bn8Os.EnableWindow();
				m_pWndTab[iZmBl_Idx] = m_pDlgZamenaBlTl;
			}

	}
	else
	{
/*		for( int i = 0; i < 8; i++ )
			for( int j=0; j < 8; j++ )
			{
				m_pDlgTLVag->m_p[i][j].SetWindowText("Yo");
			}*/
//		m_pDlg_LDTL->m_8OsButton.EnableWindow(0);
		if( iZamena )m_pDlgZamenaLDTL->m_bn8Os.EnableWindow(0);
		i8os = 0;
		m_Tab.DeleteItem(iZmBl_Idx);
		m_Tab.DeleteItem(iZmKP_Idx - 1);
		iZmKP_Idx--;
		iZmLDTL_Idx--;
		iZmBl_Idx--;
		m_pWndTab[iZmKP_Idx] = m_pDlgZamenaKP;
		m_pWndTab[iZmLDTL_Idx] = m_pDlgZamenaLDTL;
		m_pWndTab[iZmBl_Idx] = m_pDlgZamenaBlTl;
	}
	SetEnabledBy8Os(i8os);
	SetEnabledItemsOfRemCode(dwVRem);
	m_Tab.SetCurSel(0);

	CurWnd->ShowWindow(SW_HIDE);
	m_pWndTab[0]->ShowWindow(SW_SHOW);
	CurWnd = m_pWndTab[0];

	m_Tab.RedrawWindow();
}

void CDlgMsg4624_Main::OnBnClickedButton_LvtText()
{
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_MkcGetText497 %s", isNull(qwIDS));
	Dlg.DoModal();
}

void CDlgMsg4624_Main::SetEnabledBy8Os(int i8Os)
{
//	m_pDlgZamenaKP = NULL;
	for( int i=0; i < 13; i++ )
	{
		for( int j = 4; j < 8; j++ )
		{
			m_pDlg_KP->m_p[i][j].EnableWindow(i8Os);
			if( !i8Os ) 
			{
				m_pDlg_KP->m_p[i][j].ModifyStyle(WS_VISIBLE, WS_DISABLED);
				m_pDlg_KP->m_lpButIz[j].ModifyStyle(WS_VISIBLE, WS_DISABLED);
				//m_pDlg_KP->m_lpButIzNal[j].ModifyStyle(WS_VISIBLE, 0);
			}
			else  
			{
				m_pDlg_KP->m_p[i][j].ModifyStyle( WS_DISABLED, WS_VISIBLE);
				m_pDlg_KP->m_lpButIz[j].ModifyStyle(WS_DISABLED, WS_VISIBLE);
				//m_pDlg_KP->m_lpButIzNal[j].ModifyStyle(0, WS_VISIBLE);
			}
			if( m_pDlgZamenaKP && m_pDlgZamenaKP->m_hWnd ) 
			{
				m_pDlgZamenaKP->m_p[i][j].EnableWindow(i8Os);
				if( !i8Os ) 
				{
					m_pDlgZamenaKP->m_p[i][j].ModifyStyle(WS_VISIBLE   , WS_DISABLED);
				}
				else  
				{
					m_pDlgZamenaKP->m_p[i][j].ModifyStyle( WS_DISABLED, WS_VISIBLE);
				}

			}
		}
		m_pDlg_KP->RedrawWindow();
	}
	if( m_pDlgZamenaKP && m_pDlgZamenaKP->m_hWnd)
	{
		if( i8Os )
		for( int i=4; i < 8; i++ ) 
		{
			m_pDlgZamenaKP->m_p[13][i].ModifyStyle( WS_DISABLED, WS_VISIBLE );
			m_pDlgZamenaKP->m_pTKP[i].ModifyStyle( WS_DISABLED, WS_VISIBLE );
		} 
		else
		for( int i=4; i < 8; i++ ) 
		{		
			m_pDlgZamenaKP->m_pTKP[i].ModifyStyle( WS_VISIBLE, 0 );
			m_pDlgZamenaKP->m_p[13][i].ModifyStyle( WS_VISIBLE, 0 );
		} 
	}

	if( m_pDlgZamenaKP && m_pDlgZamenaKP->m_hWnd)
		for( int i=4; i < 8; i++ )
		{
			m_pDlgZamenaKP->m_p[13][i].EnableWindow(i8Os);
		}
	m_pDlg_LDTL->m_8OsButton.EnableWindow(i8Os);
	if( m_pDlgZamenaLDTL && m_pDlgZamenaKP->m_hWnd) m_pDlgZamenaLDTL->m_bn8Os.EnableWindow(i8Os);


	for( int i=0; i < 8; i++ )
	{
		for( int j=4; j < 8; j++ )
		{
			m_pDlgTLVag->m_p[i][j].EnableWindow(i8Os);
		}
	}
	for( int i = 4; i < 8; i++ )
	{
		m_pDlgTLVag->m_pL[i].EnableWindow(i8Os);
	}
}

void CDlgMsg4624_Main::SetErrorEdit(DWORD dwVkladka, DWORD dwErrX, DWORD dwErrY)
{
	int vl[2][4] = {0,2,4,6,1,3,5,7};
	static DWORD oldX = 0, oldY = 0;
	switch(dwVkladka)
	{
	case 1:
		if(dwErrX > 13 || dwErrY > 8 )
		{
			AfxMessageBox("Ошибочно передано положение ошибки!");
			return;
		}

		if( !m_pDlg_KP ) return;		
		m_pDlg_KP->m_p[dwErrX - 1][dwErrY - 1].SetBkColor(crErrorColor);

	break;
	case 2:
		if((dwErrX > 15 || dwErrY > 12) || (dwErrX == 1 && dwErrY > 2) )
		{
			AfxMessageBox("Ошибочно передано положение ошибки!");
			return;
		}
		if( !m_pDlg_LDTL ) return;
		if( oldY > 6 ) oldY -= 6;
		if( oldX > 0 )
		{
			if( oldX == 1 )
			{
				m_pDlg_LDTL->m_Num[oldY - 1].SetBkColor(RGB(255,255,255));
			} else
				m_pDlg_LDTL->m_p[oldX - 2][oldY - 1].SetBkColor(RGB(255,255,255));
		}	
		if( (m_pDlg_LDTL->m_BackBuffer.iScreenPage == 0 && dwErrY < 7)
			||(m_pDlg_LDTL->m_BackBuffer.iScreenPage == 1 && dwErrY > 6)
			)
		{
			if( dwErrY > 6 ) dwErrY -= 6;
			if( dwErrX == 1 )
			{
				m_pDlg_LDTL->m_Num[dwErrY - 1].SetBkColor(crErrorColor);
			} else
				m_pDlg_LDTL->m_p[dwErrX - 2][dwErrY - 1].SetBkColor(crErrorColor);			
		}
	break;	
	case 3:
		if( dwErrX > 10 || dwErrY > 8 || (dwErrX < 3 && dwErrY > 4))
		{
			AfxMessageBox("Ошибочно передано положение ошибки!");
			return;
		}
		if( !m_pDlgTLVag ) return;		
		if( dwErrX < 3 )
		{
			m_pDlgTLVag->m_pL[vl[dwErrX - 1][dwErrY - 1]].SetBkColor(crErrorColor);
		} else
		{
			m_pDlgTLVag->m_p[dwErrX - 3][dwErrY - 1].SetBkColor(crErrorColor);
		}
	break;
	case 5:
		if(dwErrX > 14 || dwErrY > 8 )
		{
			AfxMessageBox("Ошибочно передано положение ошибки!");
			return;
		}
		if( !m_pDlgZamenaKP ) return;
		m_pDlgZamenaKP->m_p[dwErrX - 1][dwErrY - 1].SetBkColor(crErrorColor);
	break;
	case 6:
		if((dwErrX > 12 || dwErrY > 6) || (dwErrX == 1 && dwErrY > 2) )
		{
			AfxMessageBox("Ошибочно передано положение ошибки!");
			return;
		}
		if( !m_pDlgZamenaLDTL ) return;
		if( dwErrX == 1 )
		{
			m_pDlgZamenaLDTL->m_Num[dwErrY - 1].SetBkColor(crErrorColor);
		} else
			m_pDlgZamenaLDTL->m_p[dwErrX - 2][dwErrY - 1].SetBkColor(crErrorColor);
	break;
	case 4:
		if((dwErrX > 5 || dwErrY > 2))
		{
			AfxMessageBox("Ошибочно передано положение ошибки!");
			return;
		}
		if(!m_pDlgBlTl) return;
		m_pDlgBlTl->m_pEd[dwErrX - 1][dwErrY - 1].SetBkColor(crErrorColor);
	break;
	case 7:
		if((dwErrX > 5 || dwErrY > 2))
		{
			AfxMessageBox("Ошибочно передано положение ошибки!");
			return;
		}
		if( !m_pDlgZamenaBlTl ) return;
		m_pDlgZamenaBlTl->m_pEd[dwErrX - 1][dwErrY - 1].SetBkColor(crErrorColor);

	break;
	}
	oldX = dwErrX;
	oldY = dwErrY;
}

void CDlgMsg4624_Main::OnBnClickedVU36()
{
//	CPrintableDlg Dlg;
	if( !iHidden && AfxMessageBox("Записать 4624?", MB_YESNO) == IDYES )
	{
		if( !m_EdVRem.GetWindowTextLength() )
			{
				AfxMessageBox("Необходимо указать вид ремонта вагона!");
				return;
			}
			if( !m_EdVRemName.GetWindowTextLength() )
			{
				AfxMessageBox("Вид ремонта вагона указан неверно!");
				return;
			}
			if( StoreMsgToBase() == -1 ) return;
	}
	if( i8os || m_EdVRem.GetAsDWord() == 1 || m_EdVRem.GetAsDWord() == 2 || m_EdVRem.GetAsDWord() == 39 || m_EdVRem.GetAsDWord() == 49)
	{
		CPrintableDlg Dlg;		
		sprintf(Dlg.cQ, "pTov_GetVU36ByNVag '%s', 0, %d", m_EdNVag.GetString(), 0 );
		Dlg.m_bCheck1 = 1;
		Dlg.m_bCheck2 = 0;
		Dlg.DoModal();
	} else
	{	
		char cQ[128] = "";
		sprintf(cQ, "pTov_GetVU36ByNVag '%s', 0, %d", m_EdNVag.GetString(),  1 );
		DBW.DisplayHtmlReport(cQ);
	}
}

void CDlgMsg4624_Main::FillFrom2730(void)
{
	char cQ[512] = "";

	char cText[1024] = "";
	DWORD dwNum = 0;
	long Ind = 0;
	SYSTEMTIME tm;
	char cDat[32] = "";
	__int64 qwIDSKeeper = qwIDS;	
	if( dwVRem == 72 )
		sprintf( cQ, "pTov_S4624SelPasp %u, %s, %s", g_iDep, isNull(cNVagTl), DateToSQL(stDat4624));
	else
		sprintf( cQ, "pTov_S4624SelPasp %u, %s, %s", g_iDep, isNull(cVagNum32), DateToSQL(stDat4624));

	char cMess[512] = "";
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SBIGINT, &qwIDS, 8, &Ind);
	if( qwIDS == -1 )
	{
		char cVag2[64] = "";
		DBW.GetData(2, SQL_C_CHAR, cMess, 510, &Ind);
		DBW.CloseCursor();
		{
			if( MessageBox(cMess, "", MB_YESNO ) == IDNO ) return;
			if( g_i2730ReqMessage == 4618) theApp.SendTeleMessage(CString("(: 4618 2730: ") + (CString)cVagNum32 + ":)", CString("2730_") + cVagNum32);
			else theApp.SendTeleMessage(CString("(: 4628 2730: ") + (CString)cVagNum32 + ":)", CString("2730_") + cVagNum32);

			int x = g_conf_MessageOnCancel;
			g_conf_MessageOnCancel = 0;
			OnCancel();
			g_conf_MessageOnCancel = x;
			return ;
		}
	}
		DWORD dwOldVRem = dwVRem7;
		DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 )
		{
			dwVRem7 = atoi(cText);
		}
		DBW.GetData(15, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			m_pDlg_KP->m_EdFIO1.SetData(dwNum);
			DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_pDlg_KP->m_EdFIO1.SetWindowText(cText);
		}
		DBW.GetData(17, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			m_pDlg_LDTL->m_FIO1.SetData(dwNum);
			m_pDlgTLVag->m_EdFIO1_LDTL.SetData(dwNum);
			DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) 
			{
				m_pDlg_LDTL->m_FIO1.SetWindowText(cText);
				m_pDlgTLVag->m_EdFIO1_LDTL.SetWindowText(cText);
			}
		}
		DBW.GetData(19, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{ 
			m_pDlgBlTl->m_EdFIO1_BLTL.SetData(dwNum);
			DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_pDlgBlTl->m_EdFIO1_BLTL.SetWindowText(cText);
		}
		DBW.GetData(21, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			m_pDlg_KP->m_EdFIO2.SetData(dwNum);
			m_pDlg_LDTL->m_FIO2.SetData(dwNum);
			m_pDlgTLVag->m_EdFIO2_LDTL.SetData(dwNum);
			DBW.GetData(22, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 )
			{
				m_pDlg_KP->m_EdFIO2.SetWindowText(cText);
				m_pDlg_LDTL->m_FIO2.SetWindowText(cText);
				m_pDlgTLVag->m_EdFIO2_LDTL.SetWindowText(cText);
			}
		}

		DBW.GetData(23, SQL_C_ULONG, &i8os, sizeof(int), &Ind);
		mgSQLGetSysDate(24, &tm, &Ind);
		if( Ind != -1 ) 
		{
			SYSTEMTIME tt;
			ZeroMemory(&tt, sizeof(tt));
			GetLocalTime(&tt);
			if(  SysDateCmp(tm, tt) > 0)
			{
				m_pDlg_Header->m_DatRem.InitDate();
				m_pDlg_Header->m_Hour2.SetWindowText(toStr(tt.wHour));
				m_pDlg_Header->m_Min2.SetWindowText(toStr(tt.wMinute));
			} else
			{
				m_pDlg_Header->m_DatRem.SetTime(&tm);
				m_pDlg_Header->m_Hour2.SetWindowText(toStr(tm.wHour));
				m_pDlg_Header->m_Min2.SetWindowText(toStr(tm.wMinute));
			}
		}
		else 
		{
			SYSTEMTIME tt;
			ZeroMemory(&tt, sizeof(tt));
			m_pDlg_Header->m_DatRem.InitDate();
			GetLocalTime(&tt);
			m_pDlg_Header->m_Hour2.SetWindowText(toStr(tt.wHour));
			m_pDlg_Header->m_Min2.SetWindowText(toStr(tt.wMinute));
		}
		m_pDlg_Header->m_DatRem.GetTime(&m_pDlg_Header->stDateRem);
		DBW.GetData(26, SQL_C_CHAR, cKodSobst, 4, &Ind);
		dwNum = 0;
	DBW.CloseCursor();
	DBW.ReallocHandle();

	dwVRem7 = 2; // эту строчку возможно надо убрать
	FillForms();
	qwIDS = qwIDSKeeper;
	dwVRem7 = dwOldVRem;
}

void CDlgMsg4624_Main::OnBnClickedButton6()
{
	i2730Pushed = 1;
	if( dwVRem == 39 || dwVRem == 49 )
		for( int i=0; (i < 4 && !i8os) || (i < 8 && i8os ); i++)
			m_pDlg_KP->m_lpButIz[i].EnableWindow(TRUE);
	FillFrom2730();
}

void CDlgMsg4624_Main::PerenosKPtoZamenKP(int iKpOrder)
{
	if( (dwVRem != 39 && dwVRem !=49) || !m_pDlgZamenaKP ) return;

	CString str = "";
	CString str2 = "";

	int index = 0;
	int got = 0;
	m_pDlg_KP->m_p[0][iKpOrder].GetWindowText(str);

	for( int j=0; (j < 4 && !i8os) || (j < 8 && i8os); j++ )
	{
		m_pDlgZamenaKP->m_p[5][j].GetWindowText(str2);
		if( str2 == "" && !got ) 
		{
			index = j;
			got = 1;
//			break;
		}
		m_pDlgZamenaKP->m_p[0][j].GetWindowText(str2);
		if( str2 == str )
		{
			int rz = AfxMessageBox((CString)"В списке изъятых КП уже существует КП с номером " + str + "!\nЗаписать поверх?", MB_YESNO);
			if( rz == IDNO ) return;

			index = j;
			got = 1;
			break;
		}
		
	}
	
	if( !got ) return;

	for( int i=0; i < 13; i++ )
	{
		m_pDlg_KP->m_p[i][iKpOrder].GetWindowText(str);
		m_pDlgZamenaKP->m_p[i][index].SetWindowText(str);
		if( i > 1 ) m_pDlg_KP->m_p[i][iKpOrder].SetWindowText("");
	}
}

void CDlgMsg4624_Main::OnBnClickedCancel()
{
	OnCancel();
}
void CDlgMsg4624_Main::OnBnClickedTEXT4624()
{
	if( !qwIDS )
	{
		AfxMessageBox("Для просмора текста необходимо сохранить сообщение!");
		return;
	}

	CPrintableDlg Dlg;	
	sprintf(Dlg.cQ, "pTov_S4624Form %I64u, 1", qwIDS);
	Dlg.DoModal();
}

void CDlgMsg4624_Main::PerenosKPtoZamenDTL(int iDTLOrder ) // порядок детали передается с учетом буфера
{
	if( (dwVRem != 39 && dwVRem !=49) || !m_pDlgZamenaKP  ) return;
	m_pDlg_LDTL->StoreValues();
/*
	int index = 0;
	int got = 0;
	int exist = 0;
	
//	AfxMessageBox(m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]);
// В зависимости от детали - нужно поискать свободное место (для БР, НБ)
// Потом найти первое нужное пустое место и поискать нет ли этой детали уже заполенной в замененных
	
	if( iDTLOrder == 0 || iDTLOrder == 3 || iDTLOrder == 6 || iDTLOrder == 9 ) // НБ
	{   // поищем свободные места для НБ
		
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][0] == "" ) {index = 0; got = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][3] == "" && !got ) {index = 3; got = 1;}
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][6] == "" && !got ) {index = 6; got = 1;}
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][9] == "" && !got ) {index = 9; got = 1;}

		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][0] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 0; got = 1; exist = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][3] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 3; got = 1; exist = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][6] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 6; got = 1; exist = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][9] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 9; got = 1; exist = 1;} 
		

		if( exist )
		{
			int rz = AfxMessageBox((CString)"В списке изъятых деталей уже существует НБ с номером " + m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder] + "!\nЗаписать поверх?", MB_YESNO);
			if( rz == IDNO ) return;
		}


	} else
	{
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][1] == "" ) {index = 1; got = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][2] == "" && !got ) {index = 2; got = 1;}
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][4] == "" && !got ) {index = 4; got = 1;}
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][5] == "" && !got ) {index = 5; got = 1;}
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][7] == "" && !got ) {index = 7; got = 1;}
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][8] == "" && !got ) {index = 8; got = 1;}
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][10]== "" && !got ) {index = 10; got = 1;}
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][11]== "" && !got ) {index = 11; got = 1;}

		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][1] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 1; got = 1; exist = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][2] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 2; got = 1; exist = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][4] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 4; got = 1; exist = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][5] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 5; got = 1; exist = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][6] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 6; got = 1; exist = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][8] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 7; got = 1; exist = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][10]== m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 10; got = 1; exist = 1;} 
		if( m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][11]== m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]) {index = 11; got = 1; exist = 1;} 

		if( exist )
		{
			int rz = AfxMessageBox((CString)"В списке изъятых деталей уже существует БР с номером " + m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder] + "!\nЗаписать поверх?", MB_YESNO);
			if( rz == IDNO ) return;
		}

	}
	

	if( !got ) return;


	for( int i=0; i < 7; i++ )
	{
		m_pDlgZamenaLDTL->m_BackBuffer.str_p[i][index] = m_pDlg_LDTL->m_BackBuffer.str_p[i][iDTLOrder];
		m_pDlg_LDTL->m_BackBuffer.str_p[i][iDTLOrder] = "";
	}
	m_pDlgZamenaLDTL->m_BackBuffer.str_p[7][index] =  m_pDlg_LDTL->m_BackBuffer.str_p[11][iDTLOrder];
	m_pDlgZamenaLDTL->m_BackBuffer.str_p[8][index] =  m_pDlg_LDTL->m_BackBuffer.str_p[12][iDTLOrder];
	m_pDlgZamenaLDTL->m_BackBuffer.str_p[9][index] =  m_pDlg_LDTL->m_BackBuffer.str_p[13][iDTLOrder];

	m_pDlg_LDTL->m_BackBuffer.str_p[7][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[8][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[9][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[10][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[11][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[12][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[13][iDTLOrder] = "";


	m_pDlgZamenaLDTL->m_BackBuffer.p_strNum[index / 3] = m_pDlg_LDTL->m_BackBuffer.p_strNum[iDTLOrder/3];
*/
	
//m_pDlgZamenaLDTL->m_BackBuffer.str_p[4][0] == m_pDlg_LDTL->m_BackBuffer.str_p[4][iDTLOrder]

	for( int i=0; i < 7; i++ )
	{
		m_pDlgZamenaLDTL->m_BackBuffer.str_p[i][iDTLOrder] = m_pDlg_LDTL->m_BackBuffer.str_p[i][iDTLOrder];
		if( i != 2 ) m_pDlg_LDTL->m_BackBuffer.str_p[i][iDTLOrder] = "";
	}
	m_pDlgZamenaLDTL->m_BackBuffer.str_p[7][iDTLOrder] =  m_pDlg_LDTL->m_BackBuffer.str_p[11][iDTLOrder];
	m_pDlgZamenaLDTL->m_BackBuffer.str_p[8][iDTLOrder] =  m_pDlg_LDTL->m_BackBuffer.str_p[12][iDTLOrder];
	m_pDlgZamenaLDTL->m_BackBuffer.str_p[9][iDTLOrder] =  m_pDlg_LDTL->m_BackBuffer.str_p[13][iDTLOrder];

	m_pDlg_LDTL->m_BackBuffer.str_p[7][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[8][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[9][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[10][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[11][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[12][iDTLOrder] = "";
	m_pDlg_LDTL->m_BackBuffer.str_p[13][iDTLOrder] = "";

	m_pDlgZamenaLDTL->m_BackBuffer.p_strNum[iDTLOrder / 3] = m_pDlg_LDTL->m_BackBuffer.p_strNum[iDTLOrder/3];
//	m_pDlg_LDTL->m_BackBuffer.p_strNum[iDTLOrder / 3] = "";

	m_pDlgZamenaLDTL->m_BackBuffer.p_iComboIndex[iDTLOrder] = m_pDlg_LDTL->m_BackBuffer.p_iComboIndex[iDTLOrder];

//	m_pDlg_LDTL->StoreValues();
	m_pDlg_LDTL->DrawBuffer(m_pDlg_LDTL->m_BackBuffer.iScreenPage);

	m_pDlgZamenaLDTL->DrawBuffer(0);

	
}

void CDlgMsg4624_Main::SetIzNalButtons(void)
{
		if( !m_pDlg_KP ) return;
		for( int i = 0; i < 8; i++ )
		{
			if( iZamena ) m_pDlg_KP->m_lpButIzNal[i].ModifyStyle(WS_DISABLED, WS_VISIBLE);
			else m_pDlg_KP->m_lpButIzNal[i].ModifyStyle(WS_VISIBLE, WS_DISABLED);
			if( !i8os && i > 3 )  m_pDlg_KP->m_lpButIzNal[i].ModifyStyle(WS_VISIBLE, WS_DISABLED);
		}
	

}
