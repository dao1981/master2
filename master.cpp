// master.cpp : Defines the class behaviors for the application.
//
#include "stdafx.h"
#include "master.h"

#include <sql.h>
#include <sqlext.h> 
#include <sqltypes.h>
#include "odbcss.h"
#include <stdio.h>
#include <process.h>

#include "MainFrm.h"
//#include "masterDoc.h"
//#include "masterView.h"
#include "DlgSprPrSobstv.h"
#include "AuthDlg.h"
#include "DlgEditPass.h"
//#include "DlgKPin.h"
#include "DlgPeresTlLog.h"
#include "DlgSprav1.h"
#include "DlgSpravDor.h"
#include "DlgSpravKdr.h"
#include "DlgSpravTKP.h"
#include "DlgSpravSmp.h"
#include "DlgPeresKP.h"
#include "DlgSelRP.h"
#include "DlgDisplRP.h"
#include "DlgVvodRP.h"
#include "DlgKpVvod1.h"
#include "DlgDBKPSelect.h"
#include "DlgDBRemSelect.h"
#include "DlgRptVU53.h"
#include "DlgDBOsSelect.h"
#include "DlgCreateAdm.h"
#include "DlgDepSelect.h"
#include "PrintableDlg.h"
#include "MainForm.h"
#include "DlgRptVU90.h"
#include "DlgPrObtIn.h"
#include "DlgKpHisoryInp.h"
#include "DlgRemVag.h"
#include "DlgCreateIni.h"
#include "DlgASNeispKP.h"
#include "DlgRazmGroup.h"
#include "DlgRptVU36M.h"
#include "DlgRptVU54.h"
#include "DlgSelectOS.h"
#include "DlgAuth1.h"
#include "DlgSelZapress.h"
#include "DlgListVCHD.h"
#include "DlgBD_TL.h"
#include "DlgRegisterTL.h"
#include "DlgBD_TL1069.h"
#include "DlgProkatTL1069.h"
#include "DlgPodkatTL1520.h"
#include "DlgMsg4624_Main.h"
#include "DlgEditDepo.h"
#include "DlgMsg4624_VagDateInput.h"
#include "ErrorDisplay.h"
#include "DlgGetDate4624Log.h"
#include "DlgMsg4624Log.h"
#include "DlgPPTSendToRem.h"
#include "DlgInputNTL1067.h"
#include "DlgNaryadNaVag.h"
#include "m_EdInputVO2.h"
#include "dlginput2955.h"
#include "DlgInput2958.h"
//#include "dlgmsg2956.h"
#include "DlgInput2956.h"
#include "DlgMsg2957Main.h"
#include "DlgInput2955Rpt.h"
#include "DlgRaspressKP.h"
#include "DlgSetupTO.h"
#include "DlgInputRpt2950.h"

#include "DlgRemDefektBR.h"
#include "DlgRemDefektNB.h"
#include "DlgRemDefektSB.h"
#include "DlgInputArchive.h"
#include "dspm4624.h"
//#include "Msg4624Dispatcher.h"
//#include "d:\develop\dsp4624\Msg4624Dispatcher.h"

#include "dlgvagon1067.h"
#include "inputnvagobezl4624.h"
#include "DlgPerestRept.h"
#include "dlginputnvag.h"
#include "DlgInputTrafVag.h"
#include "DlgZapressLog.h"
#include "DlgReq2730ListVag.h"
#include "DlgInput2956Svod.h"
#include "DlgInputRpt2956.h"
#include "DlgInput2957.h"
#include "DlgInput_VO7.h"
#include "DlgInputObezlVag.h"
#include "DlgSetupCommon.h"
#include "DlgInputRptPodakat.h"
#include "DlgRptInputZhurnKompl.h"
#include "DlgBDTl2.h"
#include "DlgInputRptPrihodTL.h"
#include "DlgPPT_InpBDVag.h"
#include "DlgInputDate.h"
#include "DlgInputRptPostKpXls.h"

//#include "..\configure\config.h"

#include ".\master.h"
#include ".\telecom\teleI.h"
#include "afxwin.h"
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define PTO_KP_ED_ID 30001
#define PTO_KP_ED_RASH_ID 30002
#define ER_PR_ID 30003
#define PTO_PRIH_VED 30004
#define PTO_RASH_VED 30005
#define PTO_REM_VAG 30006
#define PZK_MSG_PROCESS 50001

//CConfig		cfg;
int			g_iDisplaySQLErrors = 1;
int			iOCV = 1;
int         g_iVersion = 72;
int			g_iBuild = 0;
int			g_iIPr_VCHDE = 0;
int			g_iTimerRate = 3000;
int			g_iCanPush = 0;
int			g_iAutoPrihodKP = 0;
int			g_iAutoRashodKP = 0;
int			g_iKP4624IzapReq = 0;
CString g_strServerName = "MPS63-REZ";
char gs_UserName[64] = "mkc";
char gs_Password[64] = "mkc";

int  gs_EnableServerDebug = 0;
long Ind = 0;

SYSTEMTIME g_CurrentDate;

CDBWire DBW;
CDspm4624 Dsp;

BOOL    g_bAdm = 0;

BYTE gs_DateFmt = 1; // 0 - dd.mm.yyyy, 1 - mm.dd.yyyy

DWORD   g_dwCurDlg = 0;
HWND    g_hDlgWnd;
CPrintableDlg *g_pPrnDlg = NULL;

SQLRETURN    g_sqlret;

SQLCHAR      g_ConnStrIn[1024] =
             "DRIVER={SQL Server};SERVER=10.63.197.6;"
             "UID=mkc;PWD=mkc123;DATABASE=mkc;";
char g_cDelphiConnStr[1024] = "";
SQLCHAR      g_ConnStrOut[MAXBUFLEN];
SQLSMALLINT  g_cbConnStrOut = 0;

// для второго коннекта на резервный
CDBWire		 DBWrez;
SQLCHAR		 g_ConnStrInRez[MAXBUFLEN];
int			 g_iGotRezervDBW = 0;



int			g_iSuperVersion = 6;
/*int         g_iSubVersion = 0;
int         g_iBuildVersion = 0;*/

char        g_cFam[21] = "";
DWORD       g_iFam = 0;
DWORD       g_IDArm = 0;
DWORD       g_iDep = 0;
char		g_cDepESR[16] = "";
DWORD       g_dwTDep = 0;
WORD        g_iRang = 0;
bool        g_Auth = true;
bool        g_LogEnabled = true;
DWORD       g_dwTypeDep = 0;
DWORD       g_dwDepoGruzPas = 0; // 1 - Грузовое, 2 - Пассажирское
BOOL        g_bSecret;
CString     g_strDepoName;
CString     g_strDepoSName;
CString     g_strDepoKl;
DWORD		g_dwPrID;
int			g_NewEmployeeDlg;
int			g_iStandAlone = 0;
int			g_iStandAloneIni = 0;
int			g_iEnableTelecom = 1;
SYSTEMTIME  g_stMessage2955Date;
SYSTEMTIME  g_stMessage2956Date;
SYSTEMTIME  g_stMessage2957Date;

char		g_cVagNum[10];

//int			g_iMsg4624Only = 0;
int			g_iMessageNumber = 0;

CString     strDefUserName = "";
CString     strDefUserPass = "";
CString		g_strTelecomServer = "tov";
CString		g_strRoadServer = "";
CString		g_strReserveServer = "";
CString		g_strAsldTeleName = "";

CString		g_strASOUPTeleName = "";
int			g_iSend4624AsoupDirect = 0;


char cConfigFileName[]="./master.ini";

int			g_conf_TOV_Installed = 0;
int			g_conf_User_Name_On_Login = 0;
CString     g_conf_strMessagePath = "";
CString		g_conf_strMessageReturnPath = "";
CString		g_conf_strMessageUnprocessedPath = "";
int         g_iAutoOK = 0;
int         g_conf_WriteEventTime = 1;
int         g_conf_MessageOnCancel = 1;

int         g_iReportGridFontSize = 12;
char        g_cReportGridFontFace[64] = "Courier New";
bool		g_bDosCodePage = 0;
int			g_iSuperUser = 0;
int			g_iUpDownArrowsStandart = 0;
int			g_iMsg4624ShowHeader = 0;
char		g_c4624DefNVag[32] = "";
char		g_c4624DefDate[12] = "";
int			g_iNoSendButtonOn4624 = 0;

char		g_conf_cLogDir[64] = "";

int			g_iNoHideRemVag4624 = 0;

//int			g_i4624Result = 0;
int			g_iMessageReturnResult = 0;
int			g_iNoPPT = 1;
int			g_iDisplayMnu2730Req = 0;

int			g_iDispatchInProgress = 0;
int			g_iSqlLogByDay = 0;
int			g_iLogClearDays = 0;
CString		g_strDBVersion = "";

int			g_iNeedSetupPath = 0;
int			g_iSQLClientVersion = 0;
int			g_iUpdateByHttp = 0;

CString		g_strArmTitle = "";
int			g_iArmTitleFromINI = 0;

int			g_iMessageLogOnly = -1;
int			g_EnableObiedDvButton = 0;
int			g_iEnableReserve = 0;
int			g_iCanChangeDpt = 0;
DWORD		g_dwLoginParentDpt = 0;
int			g_iShowVerInHeader = 0;
int			g_i2730ReqMessage = 4628;

int			g_iDefaultTypeKP = 1;


int g_iDisplayServerMessage = 1; // показывать сообщения от сервера при загрузке программы
// если -1 то берем из процедуры, 0, 1 то из инишника

int			g_iShowServerNameInWindowHeader = 0;

cd_TeleI teleObj;	
cd_TeleI *tele;	


/////////////////////////////////////////////////////////////////////////////
// CMasterApp

BEGIN_MESSAGE_MAP(CMasterApp, CWinApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_MENUITEM32792, OnMenuitemAlterPass)
	ON_COMMAND(ID_MENUITEM32771, OnMenuitemInpKP)
	ON_COMMAND(ID_MENUITEM32786, OnMenuitem32786)
	ON_COMMAND(ID_MENUITEM32793, OnMenuitem32793)
	ON_COMMAND(ID_MENUITEM32789, OnMenuitem32789)
	ON_COMMAND(ID_MENUITEM32787, OnMenuitem32787)
	ON_COMMAND(ID_MENUITEM32785, OnMenuitem32785)
	ON_COMMAND(ID_MENUITEM32794, OnMenuitem32794)
	ON_COMMAND(ID_MENUITEM32795, OnMenuitem32795)
	ON_COMMAND(ID_MENUITEM32788, OnMenuitem32788)
	ON_COMMAND(ID_MENUITEM32775, OnMenuitem32775)
	ON_COMMAND(ID_MENUITEM32778, OnMenuitem32778)
	ON_COMMAND(ID_MENUITEM32772, OnMenuitem32772)
	ON_COMMAND(ID_MENUITEM32796, OnMenuitem32796)
	ON_COMMAND(ID_MENUITEM32779, OnMenuitem32779)
	ON_COMMAND(ID_MENUITEM32780, OnMenuitem32780)
	ON_COMMAND(ID___53, OnVU53)
	ON_COMMAND(ID_MENUITEM32782, OnMenuitem32782)
	ON_COMMAND(ID___93, OnVU93)
	ON_COMMAND(ID___90, OnMenuVU90)
	ON_COMMAND(ID_MENUITEM32802, OnMenuitem32802)
	ON_COMMAND(ID_MENUITEM32781, OnMenuitem32781)
	ON_COMMAND(ID_MENUITEM32803, OnMenuitemMkPaspByNKP)
	ON_COMMAND(ID_MENUITEM32776, OnSendVagClick)
	ON_COMMAND(ID_MENUITEM_AS_NEISP, OnMenuitemAnalitSprav_NeispKP)
	ON_COMMAND(ID_MENUITEM_RAZM_GRP, OnMenuitemRazmGrp)
	ON_COMMAND(ID_MENUITEM_HISTORY_KP1, OnMenuitemHistoryKp1)
	ON_COMMAND(ID_MENUITEM_VU36, OnMenuitemVu36)
	ON_COMMAND(ID_MENUITEM_VU54, OnMenuitemVU54)
	ON_COMMAND(ID_MENUITEM_SELECT_OS, OnMenuitemSelectOs)
	ON_COMMAND(ID_MENUITEM_PODKAT_REPORT, OnMenuitemPodkatReport)
	ON_COMMAND(ID_MENUITEM32783, OnMenuitem_ZapressLog)
	ON_COMMAND(ID_MENUITEM_PR_ALL, OnMenuitemPr_AllList)
	ON_COMMAND(ID_MENUITEM_PR_OSV, OnMenuitem_PrOsv)
	ON_COMMAND(ID_MENUITEM_PR_TL, OnMenuitem_PrTl)
	ON_COMMAND(ID_MENU_POLUCHENIE_KP, OnMenu_PoluchenieKp)

	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
	ON_COMMAND(ID_MENU_SELECT_DEPO, OnMenuSelectDepo)
//	ON_COMMAND(ID_MENU_BD_TL, OnMenuBdTl) // !!!!!!!!!!!!!!!!
	ON_COMMAND(ID_MENU_REG_TL, OnMenuRegTl)
	ON_COMMAND(ID_MENU_BD_TL1089, OnMenuBdTl1089)
	ON_COMMAND(ID_MENU_PODKAT1069, OnMenu_Podkat1069)
	ON_COMMAND(ID_MENU_PODKAT1520, OnMenu_Podkat1520)
	ON_COMMAND(ID_MNU_MSG4624, OnMnu_Msg4624)
	ON_COMMAND(ID_MNU_ED_PASP_DEPO, OnMnuEdPaspDepo)
	ON_COMMAND(ID_4624_SEND_LOG, On4624SendLog)
	ON_COMMAND(ID_MNU_PPR_SEND_TO_REM, OnMnuPprSendToRem)
	ON_COMMAND(ID_MNU_NALTL, OnMnuNaltl)
	ON_COMMAND(ID_MNU_PASPTL, OnMnuPasptl)
	ON_COMMAND(ID_MENU_PODACHA_VAG, OnMenuPodachaVag)
	ON_COMMAND(ID_MNU_NALTL1520, OnMnuNaltl1520)
	ON_COMMAND(ID_MENU_TRFR_VANS, OnMenuTrfrVans)
	ON_COMMAND(ID_MNU_SPR_OPERVAG, OnMnuSprOpervag)
	ON_COMMAND(ID_VAGON_NA_KOLEE1067, OnVagonNaKolee1067)
	ON_COMMAND(ID_MNU_ASOUP_ERR, OnMnuAsoupErr)
	ON_COMMAND(ID_MNU_PPT_4624, OnMnuPpt4624)
	ON_COMMAND(ID_MNU_PPT_SPRAV_PEREST, OnMnuPptSpravPerest)
	ON_COMMAND(ID_ARH_OPER_VAG, OnArhOperVag)
	ON_COMMAND(ID_MNU_VO2, OnMnuVo2)
	ON_COMMAND(ID_MNU2955, OnMnu2955)
	ON_COMMAND(ID_MNU_MSG2958, OnMnuMsg2958)
	ON_COMMAND(ID_MNU_MSG_2956, OnMnuMsg2956)
	ON_COMMAND(ID_MNU_MSG2957, OnMnuMsg2957)
	ON_COMMAND(ID_MNU_RPT_2955, OnMnuRpt2955)
	ON_COMMAND(ID_MNU_REM_DEFEKT_BR, OnMnuRemDefektBr)
	ON_COMMAND(ID_MNU_REM_DEFEKT_NB, OnMnuRemDefektNb)
	ON_COMMAND(ID_MNU_REM_DEFEKT_SB, OnMnuRemDefektSb)
	ON_COMMAND(ID_MNU_RASPRESS, OnMnuRaspress)
	ON_COMMAND(ID_MNU_RASPRESS_LOG, OnMnuRaspressLog)
	ON_COMMAND(ID_MNU_QUERY2730, OnMnuQuery2730)
	ON_COMMAND(ID_MNU_2956_SVOD, OnMnu2956Svod)
	ON_COMMAND(ID_MNU_SETUP_MESS, OnMnuSetupMess)
	ON_COMMAND(ID_MNU_RPT2950, OnMnuRpt2950)
	ON_COMMAND(ID_MNU_RPT_2956, OnMnuRpt2956)
	ON_COMMAND(ID_MNU_RPT_VO7, OnMnuRptVo7)
	ON_COMMAND(ID_MNU_OBEZL_VAG, OnMnuObezlVag)
	ON_COMMAND(ID_MNU_SETUP_COMMON, OnMnuSetupCommon)
	ON_COMMAND(ID_MNU_SPR_PODKAT, OnMnuSprPodkat)
	ON_COMMAND(ID_MNU_ZHURN_KOMPLEKT, OnMnuZhurnKomplekt)
	ON_COMMAND(ID_DB_BR, OnMnuDbBr)
	ON_COMMAND(ID_DB_NB, OnMnuDbNb)
	ON_COMMAND(ID_OBNOVLENIE, OnMenuObnovlenie)
	ON_COMMAND(ID_MNU_RPT_PRIH_TL, OnMnuRptPrihTl)
	ON_COMMAND(ID_MNU_PERES_TL_RVC, &CMasterApp::OnMnuPeresTlRcv)
	ON_COMMAND(ID_MNU_VU54_PODR, &CMasterApp::OnMnuVu54Podr)
	ON_COMMAND(ID_MENU_PPT_BD_VAG, &CMasterApp::OnMenuPptBdVag)
	ON_COMMAND(ID_MNU_PPT_PEREST_VAG_1520, &CMasterApp::OnMnuPptPerestVag1520)
	ON_COMMAND(ID_33001, &CMasterApp::OnMnuExport_PaspKP)
	ON_COMMAND(ID_MNU_SPR_SOBSTV, &CMasterApp::OnMnuSprSobstv)
	ON_COMMAND(ID_MNU_SPRAV_ZAM_DET, &CMasterApp::OnMnuSpravZamDet)
	ON_COMMAND(ID_33009, &CMasterApp::OnMnuSprPostKpXls)
	ON_COMMAND(32863, &CMasterApp::OnMnuArchive)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMasterApp construction

COLORREF p_crColors[6];

CMasterApp::CMasterApp()
{
/*    m_pTemplate=NULL;
    m_bPrintPreview=FALSE;*/
	p_crColors[0] = RGB(255, 255, 255);
	p_crColors[1] = RGB(255, 203, 202);
	p_crColors[2] = RGB(248, 249, 208);
	p_crColors[3] = RGB(210, 247, 213);
	p_crColors[4] = RGB(220, 220, 220);
	p_crColors[5] = RGB(25, 25, 255);
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMasterApp object

CMasterApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CMasterApp initialization

VOID CALLBACK MyTimerProc( 
    HWND hwnd,        // handle to window for timer messages 
    UINT message,     // WM_TIMER message 
    UINT idTimer,     // timer identifier 
    DWORD dwTime)     // current system time 
{ 
//	ShowMsg("ZUMA!");
	theApp.LoadMsgAnswerFromFile();
}

int CheckDirExists(CString strPath)
{
	DWORD dwAttrib = GetFileAttributes(strPath);

	return (dwAttrib != INVALID_FILE_ATTRIBUTES && 
           (dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
	/*
	FILE *f = fopen(strPath + "\\1.vvv", "w");
	if( !f )
	{		
		return -1;
	} else
	{
		fclose(f);
		DeleteFile(strPath + "\\1.vvv");
	}
	return 0;
	*/
}

int _stdcall TeleGetMessage( char *p ,long size ,CString src ,CString dst )
{
	char cMess[1024] = "";
	DBW.WriteLog("TeleGetMessage");
	sprintf(cMess, "p[%.255s]\n\nsize [%d]\nsrc[%s]\ndst[%s]", p, size, src, dst);
	DBW.WriteLog(cMess);

	// Передать поступившее сообщение документу
	char cc[20024] = "";
/*	sprintf(cc, "Telcom message: %s", src);*/
	strncpy(cc, p, 20024);
	DBW.WriteLog("1");
	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(st));
	p[size] = 0;
	int i;
	for( i=0; i < size; i++ )
		if( cc[i] == 0 ) p[i] = ' ';
	cc[i] = 0;
	DBW.WriteLog("2");
	DBW.WriteLog(cc);
	if( theApp.ProcessMsgAnswer(p) == -1 )
	{
		DBW.WriteLog("3");
		GetLocalTime(&st);
		char cFile[128] = "";
		if( g_conf_strMessageUnprocessedPath[0] != 0 )
		{
			DBW.WriteLog("4");
			sprintf(cFile, "%s%.2d%.2d%.2d%.2d%.2d", g_conf_strMessageUnprocessedPath,
					st.wMonth, st.wDay, st.wHour, st.wMinute, st.wSecond);
			FILE *f = fopen(cFile, "w");
			if( f )
			{
				fwrite(p, size, 1, f);
				fclose(f);
			} else
			{
				DBW.WriteLog("bad unprocessed path or file cannot be opened");
				sprintf(cMess, g_conf_strMessageUnprocessedPath);
				DBW.WriteLog(cMess);
			}
		} else
		{
			DBW.WriteLog("Сообщение не обработано");
		}
	}
	DBW.WriteLog("processed");
//	DBW.WriteLog(cc);
  return 0;
}

BOOL CMasterApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization

#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

    char msg[255] = "";

	/*
	DWORD dwNum1 = 0;
	dwNum1 = atoi("77000001");
	char ss[128] = "";
	sprintf(ss, "%d", dwNum1);
	AfxMessageBox(ss);
	*/

	char *tok = NULL, cCmdLine[1024];
	strcpy( cCmdLine, m_lpCmdLine );
	tok = strtok(cCmdLine, " ");
	if( !tok ) 
	{
		if( LoadMasterIni() == FALSE )
		{
			return FALSE;
		}
		if( CheckDirExists(g_conf_cLogDir) == -1 &&
			CheckDirExists(CString(".\\") + g_conf_cLogDir) == -1 )
		{
			CreateDirectory(".\\log\\", NULL );
			strcpy(g_conf_cLogDir, ".\\log\\");
			WritePrivateProfileString("ARM", "LogDir", g_conf_cLogDir, cConfigFileName);
		}
		SYSTEMTIME st;
		ZeroMemory(&st, sizeof(st));
		GetLocalTime(&st);
		sprintf(msg, "\n\n+++ Started at %.2d.%.2d.%.4d [%.2d:%.2d:%.2d] - [6.%u.%u]", st.wDay, st.wMonth, st.wYear, st.wHour, st.wMinute, st.wSecond, g_iVersion, g_iBuild);
		WriteLog(msg, 0 ,0);
	}
	// Change the registry key under which our settings are stored.
	SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	LoadStdProfileSettings(1);  // Load standard INI file options (including MRU)
	/*
	CDlgMsg4624_Main Dlg5;
	m_pMainWnd = &Dlg5;
    Dlg5.DoModal();
	return TRUE;
*/
	DBW.initTovSendMessage();

    //g_bSecret = false;
    CMainForm Dlg2;
    CAuthDlg Dlg;
    CDlgAuth1 Dlg1;
//    m_pMainWnd = &Dlg;
    
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    Dlg.m_hIcon = m_hIcon;

    GetLocalTime(&g_CurrentDate);

	strcpy( cCmdLine, m_lpCmdLine );
	tok = strtok(cCmdLine, " ");
	if( tok ) 
	{
		g_iMessageNumber = atoi(tok);
//		AfxMessageBox(CString("Message number: ") + tok);
		if( g_iMessageNumber < 100 && g_iMessageNumber > 50) g_iMessageNumber = 4624;
		tok = strtok(NULL, " ");
		
		__int64 t64 = 0;
		//if( tok )g_iDep = atoi(tok);
		if( tok ) 
			g_iDep = (DWORD)_atoi64(tok);


/*		if( g_iMessageNumber != PZK_MSG_PROCESS && !g_iDep )
		{
			MessageBox(NULL, "Идентификатор предприятия передан некорректно!", "master.exe", MB_OK);
			return FALSE;
		}
*/
//		CDlgMsg4624_Main Dlg4624;
		tok = strtok(NULL, " ");
		if( g_iMessageNumber == PTO_REM_VAG )
		{
			if( tok )
			{
				int i;
				for( i=strlen(m_lpCmdLine); i > 0 && m_lpCmdLine[i] != ' '; i-- );
				sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", m_lpCmdLine + i );
			}
		} else
		if( g_iMessageNumber == PTO_KP_ED_ID || g_iMessageNumber == PTO_KP_ED_RASH_ID )
		{
			if( tok )
			{
				strncpy(g_cVagNum, tok, 8);
				int i;
				for( i=strlen(m_lpCmdLine); i > 0 && m_lpCmdLine[i] != ' '; i-- );
				sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", m_lpCmdLine + i );
			}
		} else
		if( g_iMessageNumber == ER_PR_ID )
		{
			int i;
			for( i=strlen(m_lpCmdLine); i > 0 && m_lpCmdLine[i] != ' '; i-- );
			sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", m_lpCmdLine + i);
		} else
		if( g_iMessageNumber == PTO_PRIH_VED )
		{
			if( tok )
			{
				char cText[64] = "";
				strncpy(cText, tok, 8);
				g_iDep = atoi(cText);
				int i;
				for( i=strlen(m_lpCmdLine); i > 0 && m_lpCmdLine[i] != ' '; i-- );
				sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", m_lpCmdLine + i );
			}
		} else
		if( g_iMessageNumber == PTO_RASH_VED )
		{
			if( tok )
			{
				char cText[64] = "";
				strncpy(cText, tok, 8);
				int i;
				for( i=strlen(m_lpCmdLine); i > 0 && m_lpCmdLine[i] != ' '; i-- );
				sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", m_lpCmdLine + i );
			}
		} else
		if( g_iMessageNumber == 4624 )
		{
			char cStr[255] = "";
			int xx= 0;
			int i = 0;
			if( tok )
			{
				strcpy(Dlg2.cVagNum32, tok);
				tok = strtok(NULL, " ");
				if( tok ) 
				{
					Dlg2.stRemDat = RusDateToSysDate(tok);
					if( !Dlg2.stRemDat.wHour && 
						!Dlg2.stRemDat.wMinute && 
						!Dlg2.stRemDat.wSecond )
						ZeroMemory(&Dlg2.stRemDat, sizeof(SYSTEMTIME));
						
//					ZeroMemory(&Dlg2.stRemDat, sizeof(Dlg2.stRemDat)); //разремить для тестов
										
//					for( i=strlen(m_lpCmdLine); i > 0 && m_lpCmdLine[i] != ' '; i-- );
//					tok = strtok(NULL, " ");
//					sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", m_lpCmdLine + i );
//					sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", tok );
					
					if( strlen(m_lpCmdLine) > strcspn(m_lpCmdLine, "SERVER") )
					{						
						for( i = 0, xx = strcspn(m_lpCmdLine, "SERVER"); xx < strlen(m_lpCmdLine) && m_lpCmdLine[xx] != ' '; xx++, i++)
						{
							cStr[i] = m_lpCmdLine[xx];
						}
						cStr[i] = 0;						
						sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", cStr );
					}
					tok = strtok(NULL, " ");
/*					if( tok ) 
					{
//						strcpy((char *)g_ConnStrIn, tok);
						sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", tok);
					}*/
				}
//				tok = strtok(NULL, " ");
				xx++;
				for( i = 0; xx < strlen(m_lpCmdLine) && m_lpCmdLine[xx] != ' '; xx++, i++)
				{
					cStr[i] = m_lpCmdLine[xx];
				}
				cStr[i] = 0;
				if( cStr[0] ) 
				{
					if( strcmp("1", cStr) == 0 ) g_iNoSendButtonOn4624 = 1;
				}
			}
		} else
		if( g_iMessageNumber == 2955 )
		{
			if( tok )
			{
				g_stMessage2955Date =  RusDateToSysDate(tok);
				int i;
				for( i=strlen(m_lpCmdLine); i > 0 && m_lpCmdLine[i] != ' '; i-- );
				sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", m_lpCmdLine + i );
			}
		} else
		if( g_iMessageNumber == 2956 )
		{
			if( tok )
			{
				g_stMessage2956Date =  RusDateToSysDate(tok);
				int i;
				for( i=strlen(m_lpCmdLine); i > 0 && m_lpCmdLine[i] != ' '; i-- );
				sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", m_lpCmdLine + i );
			}
		} else
		if( g_iMessageNumber == 2957 )
		{
			if( tok )
			{
				g_stMessage2957Date =  RusDateToSysDate(tok);
				int i;
				for( i=strlen(m_lpCmdLine); i > 0 && m_lpCmdLine[i] != ' '; i-- );
				sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", m_lpCmdLine + i );
			}
		}
		if( g_iMessageNumber == 2958 )
		{
			if( tok )
			{
				g_stMessage2957Date =  RusDateToSysDate(tok);
				int i;
				for( i=strlen(m_lpCmdLine); i > 0 && m_lpCmdLine[i] != ' '; i-- );
				sprintf( (char *)g_ConnStrIn, "DRIVER={SQL Server};NETWORK=dbmssocn;%s", m_lpCmdLine + i );
			}
		}
		

//		g_iMsg4624Only = 1;
		m_pMainWnd = &Dlg2;
		
		if( g_iMessageNumber != PZK_MSG_PROCESS )
		{
			if( ConnectDB() )
			{
				AfxMessageBox("Ошибка подключения к серверу БД!");
				return FALSE;
			}
			DBW.GetDepoName(g_iDep, g_strDepoName, g_strDepoSName, g_dwTDep, g_dwDepoGruzPas);

			Dlg2.bMsg4624Only = 1;
			Dlg2.DoModal();
			DisconnectDB();
			return TRUE;
		}
	}
	/*
	if( LoadMasterIni() == FALSE )
	{
	    return FALSE;
	}
	*/
	RotateLog();
	if( g_iMessageNumber == PZK_MSG_PROCESS )
	{		
		LoadMasterIni();
		WriteLog("Start PZK");
		ConnectDB();
		LoadSQLGlobalConfig();
		if( g_iEnableTelecom ) // запустим телеобработку для резервирования
		{		
			tele = &teleObj;
			tele->Start( TeleGetMessage );
		}
		char cMess[123] = "";
		strcpy(cMess, g_strReserveServer);
		DBW.WriteLog("Запуск на обработку сообщений АИС ПЗК");
		DBW.WriteLog(cMess);
		LoadMsgAnswerFromFile();
		DWORD x = GetTickCount();
		while( GetTickCount() < x + 60000 );
		DBW.WriteLog("Обработка сообщений АИС ПЗК завершена");
		DisconnectDB();
		m_pMainWnd = NULL;
		if( g_iEnableTelecom ) tele->Stop();
		return FALSE;
	}


    if( ConnectDB() )
    {
        AfxMessageBox("Ошибка подключения к серверу БД!");
        return FALSE;
    }
	if( !LoadSQLGlobalConfig() ) return FALSE;
	if( g_iMessageLogOnly == 1 ) Dlg2.bMsg4624Only = 1;
	if( CheckClientUpdate() ) return FALSE;
	
	int iRet1 = CheckFirstStart();
	if(iRet1)
	{
		AfxMessageBox("CheckKadrFill() != 0");
		return TRUE;		
	} else
	{
		WriteLog("CheckFirstStart() = 0");
	}
/*
    if( !g_Auth ) 
    {
        strcpy(g_cFam, "a");
        g_iFam = 1;
        g_iDep = 1;
        g_iRang = 3;
        return TRUE;
    }
*/
	LoadKeyboardLayout("00000419", KLF_ACTIVATE);
	int iOCVTimer = 0;
	if( iOCV ) 
	{
		m_pMainWnd = &Dlg;
		iOCVTimer = 1;
		SetTimer(m_pMainWnd->m_hWnd, 11, g_iTimerRate, MyTimerProc);
	}

    // Checking Auth
    CString strName, strPass;
    if( !g_bAdm )
        do
        {
            if( !g_conf_User_Name_On_Login )
            {
                if( g_iAutoOK )
                {
                    strName = strDefUserName;
                    strPass = strDefUserPass;
                } else
                {
                    if( Dlg.DoModal() == IDCANCEL ) 
                    {
                        return FALSE;
                    }					
                    Dlg.m_UserName.TrimLeft(' ');
                    Dlg.m_Pass.TrimLeft(' ');
                    Dlg.m_UserName.TrimRight(' ');
                    Dlg.m_Pass.TrimRight(' ');
                    strName = Dlg.m_UserName;
                    strPass = Dlg.m_Pass;
                }
            } else
            {
                if( g_iAutoOK )
                {
                    strName = strDefUserName;
                    strPass = strDefUserPass;
                } else
                {
                    if( Dlg1.DoModal() == IDCANCEL ) return FALSE;
                    Dlg1.m_strName.TrimLeft(' ');
                    Dlg1.m_strPass.TrimLeft(' ');
                    Dlg1.m_strName.TrimRight(' ');
                    Dlg1.m_strPass.TrimRight(' ');
                    strName = Dlg1.m_strName;
                    strPass = Dlg1.m_strPass;
                }
            }
        }
        while( theApp.CheckAuth((LPCSTR)strName, (LPCSTR)strPass) );

    DBW.GetDepoName(g_iDep, g_strDepoName, g_strDepoSName, g_dwTDep, g_dwDepoGruzPas);


    if( g_dwTypeDep == 3)
    {
        CDlgListVCHD Dlg3;
		g_iSuperUser = 1;
        if( Dlg3.DoModal() == IDCANCEL ) return FALSE;
    }

	if( g_iMessageLogOnly == 1 ) Dlg2.bMsg4624Only = 1;
    m_pMainWnd = &Dlg2;

	if( !iOCV ) SetTimer(m_pMainWnd->m_hWnd, 11, g_iTimerRate, MyTimerProc);

	if( /*!g_iStandAlone && */g_iEnableTelecom && !g_iMessageNumber )
	{
		tele = &teleObj;
		tele->Start( TeleGetMessage );
	}
	Dlg2.DoModal();
	if( /*!g_iStandAlone && */g_iEnableTelecom && !g_iMessageNumber) tele->Stop();
    WriteLog("Shutdown");
    DisconnectDB();
	return TRUE;

}

int CMasterApp::CheckFirstStart()
{
    DWORD dwNum = 0;
    long  Ind = 0;
    DBW.ExecSQL("pTov_CheckKadrFill");
    g_sqlret = DBW.Fetch();
    if( g_sqlret == SQL_ERROR ) 
	{
		WriteLog("SQL Error on FETCH 'pTov_CheckKadrFill'!");
		return -1;
	}
    DBW.GetData( 1, SQL_C_SLONG, &dwNum, 4, &Ind);
    DBW.CloseCursor();
    if( !dwNum )
    {
        CDlgCreateAdm Dlg;
        while( Dlg.m_EdPass == "" )
        {
            if( Dlg.DoModal() == IDCANCEL ) return -1;
            if( Dlg.m_EdPass == "" )
                MessageBox(NULL, "Пароль администратора не может быть пустым!", "Внимание", MB_OK);
        }
        char cQ[128] = "";
        sprintf(cQ, "pTov_AddMKCAdmin '%.32s'", Dlg.m_EdPass );
        DBW.ExecSQL(cQ);
        DBW.CloseCursor();
        g_Auth = false;
        CDlgDepSelect D;
        if( D.DoModal() == IDCANCEL )
        {
            g_iDep = 1;
        }
        else
            g_iDep = D.wDep;

        g_bAdm = 1;
    }
	WriteLog("Return from CheckFirstStart()");
    return 0;

}

int LoadConfigIntParameter(char *Section, char *ParamName, int &Dest)
{
    char cRez[64] = "";
    int rez = GetPrivateProfileString(
                        Section,
                        ParamName,
                        NULL,
                        cRez,
                        64,
                        cConfigFileName);
    if( rez ) Dest = atoi(cRez);
    return rez;

}

int LoadConfigStringParameter(char *Section, char *ParamName, char *Dest)
{
    int rez = GetPrivateProfileString(
                        Section,
                        ParamName,
                        NULL,
                        Dest,
                        64,
                        cConfigFileName);
    
    return rez;

}

BOOL CMasterApp::LoadMasterIni()
{
/*    SQLCHAR      g_ConnStrIn[MAXBUFLEN] =
             "DRIVER={SQL Server};SERVER=10.63.197.6;"
             "UID=mkc;PWD=mkc123;DATABASE=mkc;";
*/
    char cText[64] = "";
    HANDLE hFile = CreateFile(cConfigFileName, 
                                GENERIC_READ, 
                                FILE_SHARE_READ, 
                                NULL, 
                                OPEN_EXISTING, 
                                FILE_ATTRIBUTE_NORMAL, 
                                NULL);
    if( hFile == INVALID_HANDLE_VALUE )
    {
        CloseHandle(hFile);

        CDlgCreateIni Dlg;
        if( Dlg.DoModal() == IDCANCEL ) return FALSE;
        WritePrivateProfileString("SERVER", "HostName", Dlg.m_strServerName, cConfigFileName);
        WritePrivateProfileString("SERVER", "UserName", Dlg.m_strLogin, cConfigFileName);
        WritePrivateProfileString("SERVER", "PassWord", Dlg.m_strPassword, cConfigFileName);
/*
        AfxMessageBox("Отсутствует файл конфигурации! Продолжение работы невозможно!");
        CloseHandle(hFile);
        return FALSE;
*/
    }
    CloseHandle(hFile);
    char cServerName[64] = "";
	char cServerNameRez[64] = "";
    char cUserName[64] = "";
    char cPassword[64] = "";
    char cDatabase[64] = "kcmod";
    char cNetworkLib[64] = "NETWORK=dbmssocn;";
    int rez = GetPrivateProfileString(
                        "Server",
                        "HostName",
                        NULL,
                        cServerName,
                        64,
                        cConfigFileName);
    if( rez == 0 )
    {
        AfxMessageBox("В файле конфигурации отсутствует имя сервера (\"HostName\").\nПродолжение работы невозможно!");
        return FALSE;
    }

	rez = GetPrivateProfileString(
                        "Server",
                        "HostNameRez",
                        NULL,
                        cServerNameRez,
                        64,
                        cConfigFileName);
	
	g_strServerName = cServerName;
    rez = GetPrivateProfileString(
                        "Server",
                        "UserName",
                        NULL,
                        cUserName,
                        64,
                        cConfigFileName);
    if( rez == 0 )
    {
/*        AfxMessageBox("В файле конфигурации отсутствует имя пользователя для подключения к серверу БД (\"UserName\").\nПродолжение работы невозможно!");
        return FALSE;*/
        strcpy(cUserName, "");
    }
    rez = GetPrivateProfileString(
                        "Server",
                        "Password",
                        NULL,
                        cPassword,
                        64,
                        cConfigFileName);
    if( rez == 0 )
    {
        cPassword[0] = 0;
/*
        AfxMessageBox("В файле конфигурации отсутствует пароль доступа к серверу БД (\"Password\").\nПродолжение работы невозможно!");
        return FALSE;
*/
    }
    rez = GetPrivateProfileString(
                        "Server",
                        "Database",
                        NULL,
                        cDatabase,
                        64,
                        cConfigFileName);
    if( cDatabase[0] == 0 )
    {
        strcpy(cDatabase, "kcmod");
    }

    rez = GetPrivateProfileString(
                        "NETWORK",
                        "Library",
                        NULL,
                        cText,
                        64,
                        cConfigFileName);
    strupr(cText);
    if( rez )
    {
        if( strcmp(cText, "PIPES") == 0 )
        {
            strcpy(cNetworkLib, "NETWORK=dbnmpntw;");
        } else
        if( strcmp(cText, "TCP") == 0 )
        {
            strcpy(cNetworkLib, "NETWORK=dbmssocn;");
        } else
        if( strcmp(cText, "OS_DETECT") == 0 )
        {
            cNetworkLib[0] = 0;
        }
    } else
    {
        strcpy(cNetworkLib, "NETWORK=dbmssocn;");        
    }


    sprintf((char *)g_ConnStrIn, "DRIVER={SQL Server};%sSERVER=%.64s;"\
             "UID=%.64s;PWD=%.64s;DATABASE=%s;",
			  cNetworkLib,
              cServerName,
              cUserName,
              cPassword,
              cDatabase);

	sprintf(g_cDelphiConnStr, "Database=%s;User_Name=%s;Password=%s;Server=%s",
			cDatabase, cUserName, cPassword, cServerName);
	if( cServerNameRez[0] )
	{
		sprintf((char *)g_ConnStrInRez, "DRIVER={SQL Server};SERVER=%.64s;%s"\
             "UID=%.64s;PWD=%.64s;DATABASE=%s;",
              cServerNameRez,
              cNetworkLib,
              cUserName,
              cPassword,
              cDatabase);
		g_iGotRezervDBW = 2;
	} else
		g_iGotRezervDBW = 0;



    rez = GetPrivateProfileString(
                        "DEBUG",
                        "EnableSqlLog",
                        NULL,
                        cText,
                        64,
                        cConfigFileName);
    if( strcmp(cText, "1") && stricmp(cText, "yes") )
    {
        g_LogEnabled = false;
    }
    else
    {
        g_LogEnabled = true;
//        AfxMessageBox("Log Enabled");        
    }

    rez = GetPrivateProfileString(
                        "DEBUG",
                        "DisableAuth",
                        NULL,
                        cText,
                        64,
                        cConfigFileName);
    if( !stricmp(cText, "yes") )
    {
        g_Auth = false;
//        AfxMessageBox("Auth Disable");
    }
    else
    {
        g_Auth = true;
    }
    char cID_Arm[64] = "";
    rez = GetPrivateProfileString(
                        "ARM",
                        "ID_ARM",
                        NULL,
                        cID_Arm,
                        64,
                        cConfigFileName);
    if( rez == 0 )
    {
/*        AfxMessageBox("В файле конфигурации отсутствует идентификатор АРМа (\"ID_ARM\").\nПродолжение работы невозможно!");
        return FALSE;*/
		g_IDArm = 0;
    } else
		g_IDArm = atol(cID_Arm);

    rez = GetPrivateProfileString(
                        "ARM",
                        "DefUserName",
                        NULL,
                        cText,
                        64,
                        cConfigFileName);
    if( rez )
        strDefUserName = cText;

    rez = GetPrivateProfileString(
                        "ARM",
                        "DefUserPass",
                        NULL,
                        cText,
                        64,
                        cConfigFileName);
    if( rez )
        strDefUserPass = cText;

    
    rez = GetPrivateProfileString(
                        "ARM",
                        "MsgPath",
                        NULL,
                        cText,
                        64,
                        cConfigFileName);
    if( rez )
        g_conf_strMessagePath = cText;


    g_iAutoOK = GetPrivateProfileString(
                        "ARM",
                        "AutoOK",
                        NULL,
                        cText,
                        64,
                        cConfigFileName);

    rez = GetPrivateProfileString(
                        "ARM",
                        "SilentCancel",
                        NULL,
                        cText,
                        64,
                        cConfigFileName);


    if( rez ) g_conf_MessageOnCancel = 0;

    if( !LoadConfigIntParameter("LOOK", "ReportGridFontSize", g_iReportGridFontSize ) )
        g_iReportGridFontSize = 14;
    if( !LoadConfigStringParameter("LOOK", "ReportGridFontFace", g_cReportGridFontFace) )
        strcpy(g_cReportGridFontFace, "Courier New");

	g_iStandAloneIni = LoadConfigIntParameter("DEBUG", "StandAlone", g_iStandAlone );
	
	int et = 0;
	if( LoadConfigIntParameter("ARM", "DisableTelecom", et ) )
	{
		g_iEnableTelecom = !et;
	}
	
	g_NewEmployeeDlg = 1;//1LoadConfigStringParameter("DEBUG", "NewEmployeeDlg", cText);        

	if( LoadConfigStringParameter("ARM", "MsgReturnPath", cText) )
		g_conf_strMessageReturnPath = cText;
	if( LoadConfigStringParameter("ARM", "BadMsgPath", cText) )
		g_conf_strMessageUnprocessedPath = cText;

	LoadConfigIntParameter("ARM", "ArrowsMoveHrz", g_iUpDownArrowsStandart);
	LoadConfigIntParameter("ARM", "Show4624Header", g_iMsg4624ShowHeader);
	LoadConfigStringParameter("DEBUG", "Def4624NVag", g_c4624DefNVag);
	LoadConfigStringParameter("DEBUG", "Def4624Date", g_c4624DefDate);
	LoadConfigStringParameter("ARM", "LogDir", g_conf_cLogDir);
	
	if( LoadConfigStringParameter("ARM", "RoadServer", cText) )
			g_strRoadServer = cText;

	if( LoadConfigStringParameter("ARM", "ReserveServer", cText) )
			g_strReserveServer = cText;

	if( LoadConfigStringParameter("ARM", "TeleServer", cText) )
			g_strTelecomServer = cText;
	
	if( LoadConfigStringParameter("ARM", "MessageCodePage", cText) )
	{
		if( !stricmp(cText, "DOS") )
		{
			g_bDosCodePage = 1;
		} else
			g_bDosCodePage = 0;
	}
	LoadConfigIntParameter("ARM", "NoPPT", g_iNoPPT);
	LoadConfigIntParameter("ARM", "NoHideRemVag4624", g_iNoHideRemVag4624);
	LoadConfigIntParameter("ARM", "SqlLogByDay", g_iSqlLogByDay);
	LoadConfigIntParameter("ARM", "EnableUpdateByHttp", g_iUpdateByHttp);
	cText[0] = 0;
	LoadConfigStringParameter("ARM", "ASOUPTeleName", cText);
	g_strASOUPTeleName = cText;
	LoadConfigIntParameter("ARM", "LogClearDays", g_iLogClearDays);
	LoadConfigIntParameter("ARM", "ServerNameInHeader", g_iShowServerNameInWindowHeader);
	LoadConfigIntParameter("ARM", "MessageLogOnly", g_iMessageLogOnly);
	LoadConfigIntParameter("ARM", "DisplayServerAlerts", g_iDisplayServerMessage);
	LoadConfigIntParameter("ARM", "DisableShowSQLErrorMessages", g_iDisplaySQLErrors);
	g_iDisplaySQLErrors = !g_iDisplaySQLErrors;
	if( !g_iDisplaySQLErrors ) g_bSecret = 1;
	LoadConfigIntParameter("ARM", "RcvMsgIPr", g_iIPr_VCHDE);
	LoadConfigIntParameter("ARM", "MsgCheckRate", g_iTimerRate);
	LoadConfigIntParameter("ARM", "CanPush", g_iCanPush);
	LoadConfigIntParameter("ARM", "EnableReserve", g_iEnableReserve);

	if( LoadConfigStringParameter("ARM", "ArmTitle", cText) )
	{
		g_iArmTitleFromINI = 1;
		g_strArmTitle = cText;
	}
	LoadConfigIntParameter("ARM", "ShowVerInHeader", g_iShowVerInHeader);
	LoadConfigIntParameter("ARM", "Req2730Message", g_i2730ReqMessage );

	
	LoadConfigIntParameter("ARM", "DefaultTypeKP", g_iDefaultTypeKP );
	LoadConfigIntParameter("ARM", "Send4624AsoupDirect",g_iSend4624AsoupDirect );

	if( LoadConfigStringParameter("ARM", "AsldTeleName", cText) )
	{
		g_strAsldTeleName = cText;
	} else g_strAsldTeleName = "";

//	g_cINIArmTitle
	//	char s[128] = "";	

    return TRUE;
}

BOOL CMasterApp::LoadSQLGlobalConfig()
{
	DBW.GetGlobalOption("VERSION", &g_strDBVersion);
    DBW.GetGlobalOption("USER_NAME_ON_LOGIN", &g_conf_User_Name_On_Login);
    DBW.GetGlobalOption("ENABLE_SERVER_SQL_DEBUG", &gs_EnableServerDebug);
	if( !g_iStandAloneIni )
	{
		DBW.GetGlobalOption("STAND_ALONE", &g_iStandAlone);
	}

	if( CheckDirExists(g_conf_strMessagePath) == -1 )
	{
		AfxMessageBox("Путь для отправки сообщений сообщений указан неверно!\n(MsgPath)");
		return FALSE;
//		g_iNeedSetupPath = 1;
	}
	if( CheckDirExists(g_conf_strMessageReturnPath) == -1 )
	{
		AfxMessageBox("Путь для входящих сообщений указан неверно!\n(MsgReturnPath)");
		return FALSE;
//		g_iNeedSetupPath = 1;
	}
	if( CheckDirExists(g_conf_strMessageUnprocessedPath) == -1 )
	{
		AfxMessageBox("Путь для необработанных сообщений сообщений указан неверно!\n(BadMsgPath)");
		return FALSE;
//		g_iNeedSetupPath = 1;
	}
	DBW.GetGlobalOption("CLIENT_VERSION", &g_iSQLClientVersion);
	DBW.GetGlobalOption("ROAD_SERVER", &g_strRoadServer);
	DBW.GetGlobalOption("RESERVE_SERVER", &g_strReserveServer);
	
    return TRUE;
}
/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:	
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
		// No message handlers
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CStatic m_Ver;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();	
	CStatic m_VerDLL;
	CStatic m_VerBase;
public:
	afx_msg void OnBnClickedButtonOK2();
public:
	CButton m_bnOK2;
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_STATIC_VERS, m_Ver);
	DDX_Control(pDX, IDC_STATIC_VERS2, m_VerDLL);
	DDX_Control(pDX, IDC_STATIC_BASE_VER, m_VerBase);
	DDX_Control(pDX, IDC_BUTTON1, m_bnOK2);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CAboutDlg::OnBnClickedButtonOK2)
END_MESSAGE_MAP()

// App command to run the dialog
void CMasterApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

/////////////////////////////////////////////////////////////////////////////
// CMasterApp message handlers
void CMasterApp::WriteLog(char *s, int Level, int WriteDate/* = 1*/)
{
    if( !g_LogEnabled /* || g_bSecret*/) return;
    // Level
    // 0 - write normal
    // 1 - Success
    // 2 - Failed
    SYSTEMTIME st;
    ZeroMemory(&st, sizeof(st));
    GetLocalTime(&st);
	char cFileName[512] ="";
	if( g_iSqlLogByDay )
		sprintf(cFileName, "%s\\%.4d%.2d%.2d sql.log", g_conf_cLogDir, st.wYear, st.wMonth, st.wDay);
	else
		sprintf(cFileName, "%s\\sql.dbg", g_conf_cLogDir);

	

    FILE *f = fopen(cFileName, "a+");
	if( !f ) return;
    if( !g_conf_WriteEventTime || !WriteDate)
        fprintf(f, "%s\n", s);
    else
        fprintf(f, "%.2d:%.2d:%.2d %s\n", st.wHour, st.wMinute, st.wSecond, s);
    fclose(f);
}

CString CalcPassword(CString esr)
{
        CString Password;
        int x[] = { 4,3,5,1,0,2,-1 };
        int* ix = &x[0];
        while (*ix >= 0)
                Password += char((int)esr[*ix] + (int)esr[5 - *ix] - 2 * int('0') + int('A') + (*ix++ * 2));
        return Password;
}


int CMasterApp::ConnectDB()
{
	int i;
	SQLCHAR ConnStrKeep[255] = "";
	strncpy((char *)ConnStrKeep, (char *)g_ConnStrIn, 254);
	if (i = DBW.Connect(g_ConnStrIn))
	{
		return i;
	}

	char *start = strstr ((char*)g_ConnStrIn, ";UID=");
	if( !start ) return -1;
	start += sizeof (";UID=") - 1;
	char *end = strstr ((char*)g_ConnStrIn, ";PWD=");
	if( !end ) return -1;
	char uin[128];
	memcpy (uin, start, end - start);
	uin[end-start] = 0;

	end = strstr ((char*)g_ConnStrIn, ";DATABASE=");
	end += sizeof (";DATABASE=") - 1;

	*start = 0;

	if (strcmp (uin, "ks") == 0)
	{

		char cText[1025] = "";
		long Ind = 0;

		DBW.ExecSQL("select EsrSP from dbo.nvSpks");
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cText, 1024, &Ind);
		DBW.CloseCursor();
		if( Ind != -1)
		{
			CString newconstr = CString (g_ConnStrIn) + "spks;PWD="+CalcPassword(CString(cText))+";DATABASE="+(const char*)end;
			strcpy ((char*)g_ConnStrIn, newconstr);
			DBW.Disconnect();
			
			if( g_iGotRezervDBW )
			{
				char *start1 = strstr ((char*)g_ConnStrInRez, ";UID=");
				if( !start1 ) return -1;
				start1 += sizeof (";UID=") - 1;
				char *end1 = strstr ((char*)g_ConnStrInRez, ";PWD=");
				if( !end1 ) return -1;
				char uin1[128];
				memcpy (uin1, start1, end1 - start1);
				uin1[end1-start1] = 0;
				end1 = strstr ((char*)g_ConnStrInRez, ";DATABASE=");
				end1 += sizeof (";DATABASE=") - 1;
				*start1 = 0;
				CString newconstr1 = CString (g_ConnStrInRez) + "spks;PWD="+CalcPassword(CString(cText))+";DATABASE="+(const char*)end1;
				strcpy ((char*)g_ConnStrInRez, newconstr1);
				DBWrez.Connect(g_ConnStrInRez);
			}

			return DBW.Connect(g_ConnStrIn);
		}
		else
		{
			AfxMessageBox ("Ошибка получения пароля spks");
			return 1;
		}
	} else
	{
		strncpy((char *)g_ConnStrIn, (char *)ConnStrKeep, 254);
		if( !DBWrez.Connect(g_ConnStrInRez) ) g_iGotRezervDBW = 1;
		else g_iGotRezervDBW = 0;
/*		char cText[64] = "";
		DBWrez.ExecSQL("select CharValue from nstov_MkcConfig where Parameter = 'Admin'");
		DBWrez.Fetch();
		DBWrez.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
		DBWrez.CloseCursor();*/
	}
	return i;
}

int CMasterApp::CheckAuth(const char *UserName, const char *Password)
{
    char cQuery[2048] = "";
    char Pass[12] = "";
    long Ind = 0;
       
	char cText255[255] = "";
    int iArmType = 0;
	DWORD dwDepSelect = 0;
	sprintf( cQuery, "pTov_EmplAuth '%s', '%s', %d", UserName, Password, g_conf_User_Name_On_Login);
    DBW.ExecSQL( cQuery );
	g_sqlret = DBW.Fetch();
    if( g_sqlret != SQL_NO_DATA )
    {
        DBW.GetData( 1, SQL_C_ULONG, &g_iDep, 4, &Ind);
        DBW.GetData( 2, SQL_C_ULONG, &g_iFam, 4, &Ind);
        DBW.GetData( 3, SQL_C_USHORT,&g_iRang, 2, &Ind);
        DBW.GetData( 4, SQL_C_ULONG, &g_dwTypeDep, 4, &Ind);
		DBW.GetData( 5, SQL_C_CHAR, &cText255, 255, &Ind);
		DBW.GetData( 6, SQL_C_SLONG, &iArmType, 4, &Ind);
		DBW.GetData( 7, SQL_C_SLONG, &g_EnableObiedDvButton, 4, &Ind );
		DBW.GetData( 8, SQL_C_ULONG, &dwDepSelect, 4, &Ind);

		if( g_iMessageLogOnly == -1 && Ind != -1 && iArmType == 4 )
		{
			g_iMessageLogOnly = 1;
//			bMsg4624Only = true;
		}
        DBW.CloseCursor();
		if( g_strArmTitle.IsEmpty() ) g_strArmTitle = cText255;
        if( !g_iFam && !g_iDep ) 
        {
			DBW.WriteLog("Администратор!");
			g_iSuperUser = 1;
            CDlgDepSelect D;
            if( D.DoModal() == IDCANCEL )
            {
//                g_iDep = 1;
                return -1;
            }
            else
			{
                g_iDep = D.wDep;
				char cMess[128] = "";
				sprintf(cMess, "Выбрали депо. [IDep = %u]", g_iDep);
				DBW.WriteLog(cMess);
			}
        }            
    } else
    {
        MessageBox(NULL, "Неправильное имя пользователя или пароль!", "Регистрация в системе", MB_OK | MB_ICONINFORMATION );
        DBW.CloseCursor();
        return -1;
    }
	if( dwDepSelect )
	{
		g_iCanChangeDpt = 1;
		CDlgDepSelect D;
		D.iMode = 1;
		D.dwMainDep = g_iDep;
		g_dwLoginParentDpt = g_iDep;
        if( D.DoModal() == IDCANCEL )
        {
            g_iDep = 1;
        }
        else
            g_iDep = D.wDep;

	}
    if( g_iRang > 0 )
    {
        strncpy(g_cFam, UserName, 20);
//        DBW.GetData( 5, SQL_C_ULONG, &g_iFam, 20, &Ind);
    } else
    {
        AfxMessageBox("Данный пользователь не имеет прав для работы с программой!");        
        return -1;
    }    
/*
    char s[128] = "";
    itoa(g_iDep, s, 10);
    AfxMessageBox(s );
*/
    return 0;
}

int CMasterApp::DisconnectDB()
{
    DBW.Disconnect();
//	if( g_iGotRezervDBW ) DBW.Disconnect();
   return 0;
}

long CMasterApp::DisplaySQLError(SQLHSTMT h_cst)
{
    return DBW.DisplaySQLError();
}

void CMasterApp::SetListHeaderByGlobalHandle(CListCtrl *m_List)
{
    DBW.SetListHeader(m_List);
}

extern long strtohextoval(SQL_NUMERIC_STRUCT scNum);

/*
DWORD CMasterApp::UpdateListByGlobalHandle(CListCtrl *m_List )
{
	return DBW.UpdateListByHandle(m_List);
}
*/


void CMasterApp::OnMenuitemAlterPass() 
{
	CDlgEditPass Dlg;
    Dlg.m_cUser = g_cFam;
    Dlg.m_iRang = g_iRang;
    if( Dlg.DoModal() == IDCANCEL ) return;

    char cQuery[1024] = "";
    sprintf(cQuery, "pTov_AlterPass %u, '%s'",
                    g_iFam, Dlg.m_cPass1);
    DBW.ExecSQL(cQuery);
    DBW.CloseCursor();
    DBW.ReallocHandle();
}

void CMasterApp::OnMenuitemInpKP() 
{
//    CDlgKPin Dlg;
    CDlgKpVvod1 Dlg;
    Dlg.DoModal();
}

void CMasterApp::OnMenuitem32786() // Предприятия изготовления оси
{
    CDlgSprav1	Dlg;
    Dlg.iDlgMode = 1;
    Dlg.iDlgKind = 4;
    Dlg.DoModal();
}

void CMasterApp::OnMenuitem32793() 
{
	CDlgSpravDor Dlg;
    Dlg.DoModal();
}

//справочник->кадры
void CMasterApp::OnMenuitem32789() 
{
    CDlgSpravKdr Dlg;
    Dlg.DoModal();
}
//справ->форм и осв. КП
void CMasterApp::OnMenuitem32787() //Предприятия формирования КП
{
    CDlgSprav1	Dlg;
    Dlg.iDlgMode = 1;
    Dlg.iDlgKind = 5;
    Dlg.DoModal();
}

//spr KP Types
void CMasterApp::OnMenuitem32785() 
{
    CDlgSpravTKP Dlg;
    Dlg.DoModal();
}

void CMasterApp::OnMenuitem32794() 
{
    CDlgSpravSmp Dlg;
    Dlg.DlgMode = 111;
    Dlg.DoModal();
}

void CMasterApp::OnMenuitem32795()
{
    CDlgSpravSmp Dlg;
    Dlg.DlgMode = 112;
    Dlg.DoModal();	
}

void CMasterApp::OnMenuitem32788() 
{
    CDlgSpravSmp Dlg;
    Dlg.DlgMode = 113;
    Dlg.DoModal();
}

void CMasterApp::OnMenuitem32775() 
{
    CDlgPeresKP Dlg;
    if( Dlg.DoModal() == IDCANCEL) return;
}

void CMasterApp::OnMenuitem32778() 
{
    CDlgSelRP Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;

    char cQ[2048]="";
    char cText[512]="";
    sprintf(cText, " AND tovPODSHIP.DAT_OSM >='%.4d%.2d%.2d' AND tovPODSHIP.DAT_OSM <='%.4d%.2d%.2d'",
                Dlg.m_d1.GetYear(),
                Dlg.m_d1.GetMonth(),
                Dlg.m_d1.GetDay(),
                Dlg.m_d1.GetYear(),
                Dlg.m_d1.GetMonth(),
                Dlg.m_d1.GetDay());
    strncat(cQ, cText, 1024);

    if( Dlg.m_c3 )
    {
        sprintf(cText, " AND tovPODSHIP.KOD_REM=%d ", Dlg.m_cb0);
        strncat(cQ, cText, 1024);
    }
    if( Dlg.m_c4 )
    {
        sprintf(cText, " AND (tovPODSHIP.KOD_NEISP1='%s'"\
                    "OR tovPODSHIP.KOD_NEISP2='%s'"\
                    "OR tovPODSHIP.KOD_NEISP3='%s'"\
                    "OR tovPODSHIP.KOD_NEISP4='%s')",
                    Dlg.m_ed1, Dlg.m_ed1, Dlg.m_ed1, Dlg.m_ed1);
        strncat(cQ, cText, 1024);
    }
    if( Dlg.m_c5 )
    {
        sprintf(cText, " AND tovPASP_PODSH.IPR=%d", Dlg.dwIdPr[Dlg.m_cb1]);
        strncat(cQ, cText, 1024);
    }
    if( Dlg.m_c6 )
    {
        sprintf(cText, " AND tovPASP_PODSH.ITPODSH=%d", Dlg.dwIdTypeRP[Dlg.m_cb2]);
        strncat(cQ, cText, 1024);
    }

//    AfxMessageBox(cQ);
    CDlgDisplRP Dlg1;
    if( Dlg1.DoModal() == IDCANCEL ) return;

}

//Input RP
void CMasterApp::OnMenuitem32772() 
{
    CDlgVvodRP Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;

}

void CMasterApp::OnMenuitem32796() 
{
    CDlgSpravSmp Dlg;
    Dlg.DlgMode = 114;
    Dlg.DoModal();	
}

//Выборка из БД Прихода КП
void CMasterApp::OnMenuitem32779()
{
    CDlgDBKPSelect Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;
}

void CMasterApp::OnMenuitem32780() 
{
    CDlgDBRemSelect Dlg;
    Dlg.DoModal();
}

void CMasterApp::OnVU53() 
{
    CDlgRptVU53	Dlg;
    if(Dlg.DoModal() == IDCANCEL) return;
}

//ВБД Наличие осей
void CMasterApp::OnMenuitem32782() 
{
/*    CDlgDBOsSelect Dlg;
    if(Dlg.DoModal() == IDCANCEL) return;*/
    CDlgSelectOS Dlg;
    Dlg.DoModal();
}

void CMasterApp::ReallocHandle()
{
    DBW.ReallocHandle();
}

void CMasterApp::SetPrintOrientation(int mode)
{
    switch (mode)
    {
    case DMORIENT_PORTRAIT :
                {
                // portrait mode
                PRINTDLG pd;
                pd.lStructSize = (DWORD)sizeof(PRINTDLG) ;
                BOOL bRet = GetPrinterDeviceDefaults(&pd) ;
                if (bRet)
                    {
                    // protect memory handle with ::GlobalLock and ::GlobalUnlock
                    DEVMODE *pDevMode = (DEVMODE*)::GlobalLock(m_hDevMode) ;
                    // set orientation to portrait
                    pDevMode->dmOrientation = DMORIENT_PORTRAIT ;
                    ::GlobalUnlock(m_hDevMode) ;
                    }
                }
                break ;
    case DMORIENT_LANDSCAPE :
                {
                // landscape mode
                PRINTDLG pd;
                pd.lStructSize = (DWORD)sizeof(PRINTDLG) ;
                BOOL bRet = GetPrinterDeviceDefaults(&pd) ;
                if (bRet)
                    {
                    // protect memory handle with ::GlobalLock and ::GlobalUnlock
                    DEVMODE *pDevMode = (DEVMODE*)::GlobalLock(m_hDevMode) ;
                    // set orientation to landscape
                    pDevMode->dmOrientation = DMORIENT_LANDSCAPE ;
                    ::GlobalUnlock(m_hDevMode) ;
                    }
                }
                break ;
    default :   ASSERT(FALSE) ;        // invalid parameter
    }
}

void CMasterApp::OnVU93() 
{
	
}

void CMasterApp::OnMenuVU90() 
{
    CDlgRptVU90 Dlg;
    Dlg.DoModal();
}

// Аналитические справки -> Причины обточки КП
void CMasterApp::OnMenuitem32802() 
{
	CDlgPrObtIn Dlg;
    Dlg.DoModal();
}

// История КП
void CMasterApp::OnMenuitem32781() 
{
    CDlgKpHisoryInp Dlg;
    Dlg.DoModal();
}

//Паспорт из "Выдача отчетности"
void CMasterApp::OnMenuitemMkPaspByNKP() 
{
    CDlgKpHisoryInp Dlg;
    Dlg.iMode = 1;
    Dlg.DoModal();	
}

void CMasterApp::OnSendVagClick() 
{
    CDlgRemVag Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;
}

void CMasterApp::OnMenuitemAnalitSprav_NeispKP() 
{
    CDlgASNeispKp Dlg;
    Dlg.DoModal();
}

void CMasterApp::OnMenuitemRazmGrp() 
{
	CDlgRazmGroup Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMenuitemHistoryKp1() 
{
	CDlgKpHisoryInp Dlg;
	Dlg.iMode = 2;
	Dlg.DoModal();
}

void CMasterApp::OnMenuitemVu36() 
{
	DlgRptVU36M Dlg;
    Dlg.DoModal();
	
}

void CMasterApp::OnMenuitemVU54() 
{
	CDlgRptVU54 Dlg;
    Dlg.DoModal();

}

void CMasterApp::OnMenuitemSelectOs() 
{
    CDlgSelectOS Dlg;
    Dlg.DoModal();
}

void CMasterApp::OnMenuitemPodkatReport() 
{
	CDlgRptVU54 Dlg;
    Dlg.iMode = 1;
    Dlg.DoModal();
}

void CMasterApp::OnMenuitem_ZapressLog() 
{
	CDlgSelZapress Dlg;
    Dlg.DoModal();
	
}

void CMasterApp::OnMenuitemPr_AllList() 
{
    CDlgSprav1	Dlg;
    Dlg.iDlgMode = 1;
    Dlg.DoModal();
}

void CMasterApp::OnMenuitem_PrOsv() 
{
    CDlgSprav1	Dlg;
    Dlg.iDlgMode = 1;
    Dlg.iDlgKind = 3;
    Dlg.DoModal();

}

void CMasterApp::OnMenuitem_PrTl() 
{
    CDlgSprav1	Dlg;
    Dlg.iDlgMode = 1;
    Dlg.iDlgKind = 6;
    Dlg.DoModal();

}

void CMasterApp::OnMenu_PoluchenieKp() 
{
	CDlgPeresKP Dlg;
    Dlg.iRecieveMode = 1;
    if( Dlg.DoModal() == IDCANCEL) return;

}

void CMasterApp::OnMenuSelectDepo()
{
	if( g_iCanChangeDpt )
	{
		CDlgDepSelect D;
		D.iMode = 1;
		D.dwMainDep = g_dwLoginParentDpt;
        while( D.DoModal() == IDCANCEL );
        g_iDep = D.wDep;
		return;
	}
    if( !g_iSuperUser )
	{
		AfxMessageBox("У вас не достаточно привилегий для выбора депо!");
		return;
	} else
	{
		CDlgListVCHD Dlg3;
		if( Dlg3.DoModal() == IDCANCEL ) return;
		this->m_pMainWnd->SetWindowText(CString("Мастер Колесного Цеха - ") + g_strDepoName);
	}
}

void CMasterApp::OnMenuBdTl()
{
	CDlgBD_TL Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMenuRegTl()
{
	CDlgRegisterTL Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMenuBdTl1089()
{
	CDlgBD_TL1069 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMenu_Podkat1069()
{
	CDlgProkatTL1069 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMenu_Podkat1520()
{
	CDlgPodkatTL1520 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnu_Msg4624()
{
	CDlgMsg4624_VagDateInput Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

	CDlgMsg4624_Main Dlg1;
	Dlg1.iInfoFromVagPasp = Dlg.m_iCheck;
	Dlg1.m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(Dlg1.cVagNum32, Dlg.cNVag32);
//	Dlg1.stRemDat = Dlg.stDat;
	Dlg1.stDat4624 = Dlg.stDat;
	Dlg1.DoModal();
}

void CMasterApp::OnMnuEdPaspDepo()
{
	CDlgEditDepo Dlg;
	Dlg.DoModal();
}

void ShowMsg( CString s )
{
	CErrorDisplay Dlg;
//	Dlg.m_Edit.SetWindowText(s);
	Dlg.m_MsgText = s;
	Dlg.DoModal();
}

int CMasterApp::ProcessMsgAnswer(char * strAnswer)
{
	if( g_iDispatchInProgress ) return -999;
	g_iDispatchInProgress = 1;
	CString strAwr = strAnswer;
	char cU = 0x9E;
	if( !g_bDosCodePage )
	{
		cU = 'Ю';
	}
	cU = 'Ю';
//	AfxMessageBox(strAwr);
	if( g_bDosCodePage )
	{
		Dos2Win((unsigned char*)strAnswer, strlen(strAnswer));
	}
	strAwr = strAnswer;
	char cText[40196] = "";	
	long Ind = 0;
	int ddd = 0;
	DBW.WriteLog("Пришел файл");
	DBW.WriteLog(strAnswer);
//	AfxMessageBox(strAwr);
	/* обработаем 4624 или 4623 или 4635*/
//	if( ddd = strAwr.Find("MAKET 4623") != -1 || strAwr.Find("MAKET 4624") != -1 )
	
	DBW.WriteLog("3");
	if( ddd = strAwr.Find("CПPABKA 2730") != -1 || strAwr.Find("Справка 2730") != -1 ||
		strAwr.Find("Cправка 2730") != -1 )
	{
		ddd = strAwr.Find("MAKET 4623");
		if( ddd != -1 || strAwr.Find("MAKET 4624") != -1 
			|| strAwr.Find("ИHФOPMAЦИЯ HOMEP 1") != -1
			|| strAwr.Find("MAKET 4635") != -1
			|| strAwr.Find("МАКЕТ 4635") != -1
			|| strAwr.Find("МАКЕТ 4624") != -1
			|| strAwr.Find("МАКЕТ 4623") != -1)
		{
			DBW.WriteLog("Пришел паспорт вагона!");
			char *lpcAnswer = new char[strAwr.GetLength() + 2];
			strcpy(lpcAnswer, strAwr);
			DBW.WriteLog("4");
			Dsp.Dispatch(lpcAnswer, strAwr.GetLength() + 1);
			DBW.WriteLog("5");
			char cScript[30000] = "";
			Dsp.dGetInsSlString(cScript);
			DBW.WriteLog("6");
			DBW.ExecSQL(cScript);
			DBW.CloseCursor();
			DBW.ReallocHandle();
			delete lpcAnswer;
			DBW.WriteLog("7");

			g_iDispatchInProgress = 0;
			return 0;
		}
	}
	DBW.WriteLog("8");
	if( strAwr.Find("CПPABKA 2612") != -1 ||
		strAwr.Find("СПРАВКА 2612") != -1 )
	{
/*
		typedef int (CALLBACK* dspInit_)(char*);
		typedef int (CALLBACK* dspDispatch_)(char*, int);
		typedef int (CALLBACK* dspSetWinCodepage_)(int);
		typedef int (CALLBACK* dspStop_)();
		typedef int (CALLBACK* dspSetLogPath_)(char*);
*/
		typedef int (__cdecl* _dspInit)(char * conn_str);
		typedef int (__cdecl* _dspDispatch)(char * msg, int iLen);
		typedef int (__cdecl* _dspStop)();
		typedef int (__cdecl* _dspSetWinCodepage)(int iWin);
		typedef int (__cdecl* _dspSetLogPath)(char * cPath);
/*
		_dspInit dspInit;
		_dspDispatch dspDispatch;
		_dspSetWinCodepage dspSetWinCodepage;
		_dspStop dspStop;
		_dspSetLogPath dspSetLogPath;
*/
		HMODULE hModule = LoadLibrary ("tnr2612.dll");
		//if ( !hModule ) return -1;

		_dspInit dspInit=(_dspInit)GetProcAddress(hModule,(LPCTSTR)0x0002);
		_dspDispatch dspDispatch=(_dspDispatch)GetProcAddress(hModule,(LPCTSTR)0x0001);
		_dspStop dspStop=(_dspStop)GetProcAddress(hModule,(LPCTSTR)0x0004);
		_dspSetWinCodepage dspSetWinCodepage=(_dspSetWinCodepage)GetProcAddress(hModule,(LPCTSTR)0x0003);
		_dspSetLogPath dspSetLogPath=(_dspSetLogPath)GetProcAddress(hModule,(LPCTSTR)0x0005);

/*
		dspInit = (dspInit_)GetProcAddress (hm, "dspInit");
		dspDispatch = (dspDispatch_)GetProcAddress (hm, "dspDispatch");
		dspSetWinCodepage = (dspSetWinCodepage_)GetProcAddress (hm, "dspSetWinCodepage");
		dspStop = (dspStop_)GetProcAddress (hm, "dspStop");
		dspSetLogPath = (dspSetLogPath_)GetProcAddress (hm, "dspSetLogPath");
*/

		WriteLog("Dispatch to tnr2612.dll");
		if ( dspInit )
		{
			if( dspStop ) dspStop();

			char cConnStr[512] = "";
			strncpy( cConnStr, (char *)g_ConnStrIn, 512);			
			dspInit (cConnStr );
			WriteLog("dspInit - ok");
			if( dspSetWinCodepage ) dspSetWinCodepage( !g_bDosCodePage );
			WriteLog("dspSetWinCodepage - ok");

			if( dspSetLogPath ) dspSetLogPath(g_conf_cLogDir);
			WriteLog("dspSetLogPath - ok");
			if( dspDispatch ) dspDispatch(strAnswer, strnlen(strAnswer, 2000));
			WriteLog("dspDispatch - ok");
			if( dspStop ) dspStop();
			WriteLog("dspStop - ok");
		} else
		{
			FreeLibrary (hModule);
			g_iDispatchInProgress = 0;
			return -1;
		}
		g_iDispatchInProgress = 0;
		FreeLibrary (hModule);
		return 0;
	}
	WriteLog("Dispatch to tnr2612");

	ddd = strAwr.Find("(:", 0);
	if( ddd == -1 )
	{
		sprintf(cText, "Non message File. \"(:\" not found. text [%s]", strAnswer);
		DBW.WriteLog(cText);
		g_iDispatchInProgress = 0;
		return -1;
	}
/*
	if( (strAnswer[2] != '(' && strAnswer[3] != ':') || 
		(strAnswer[0] != '(' && strAnswer[1] != ':') )
	{
		sprintf(cText, "Non message File. \"(:\" not found. text [%s]", strAnswer);
		DBW.WriteLog(cText);
		return -1;
	}
*/
// А наша ли это квитанция?
	int d = strAwr.Find((CString )"Ю" + "1", 0);
	if( d == -1 ) d = strAwr.Find((CString )"OБPAБOTKA 4624 B ГBЦ", 0);
	if( d == -1 ) d = strAwr.Find((CString )"(: 4936 0 403", 0); // Ведомость от ОЦВ
	if( d == -1 ) d = strAwr.Find((CString )"(: 4936 0 404", 0); // Смена статуса ПВ при отправке на ОЦВ

	if( d == -1 )
	{
		DBW.WriteLog("Ю1 - not found");
		g_iDispatchInProgress = 0;
		return -1;
	}
	
	if( strncmp(strAnswer, "(: 4936 0 403", 13) == 0 )
	{
		if( DispatchPeresVedMsg(strAnswer) == -1 )
		{
			g_iDispatchInProgress = 0;
			return -1;
		}

	} else
	if( strncmp(strAnswer, "(: 4936 0 404", 13) == 0 )
	{
		if( DispatchSetPeresVedStatus(strAnswer) == -1 )
		{
			g_iDispatchInProgress = 0;
			return -1;
		}

	} else
	if( strncmp(strAnswer + d + 8, "4624", 4) == 0)
	{
		char cNVag[32] = "";
		char cRetCode[32] = "";
		char cErrorCode[4196] = "";
		int iTry = 0;
		int idx = strAwr.Find((CString)"Ю" + "1 ", 0);
		idx += 3;
		int i;
		for( i=0; i < 10 && strAnswer[idx + i] >= '0' && strAnswer[idx + i] <='9'; i++ )
		{
			cRetCode[i] = strAnswer[idx + i];
		}
		cRetCode[i] = 0;
		if( i >= strlen(strAnswer))
		{
			g_iDispatchInProgress = 0;
			return -1;
		}
		//Первый плюс
		for( i=0; i < strlen(strAnswer) && strAnswer[i] != '+'; i++ );
		if( i >= strlen(strAnswer)) 
		{
			g_iDispatchInProgress = 0;
			return -1;
		}
		i++;	
		// Второй
		for( ; i < strlen(strAnswer) && strAnswer[i] != '+'; i++ );
		if( i >= strlen(strAnswer)) 
		{
			g_iDispatchInProgress = 0;
			return -1;
		}
		i++;
		int x;
		for( x = 0; x < 32 && strAnswer[i] >= '0' && strAnswer[i] <='9' && i < strlen(strAnswer); x++, i++ )
			cNVag[x] = strAnswer[i];
		cNVag[x] = 0;
		if( i >= strlen(strAnswer)) 
		{
			g_iDispatchInProgress = 0;
			return -1;
		}
		if( atoi(cRetCode) )
		{
			idx = strAwr.Find((CString )cU + "2 ", idx);
			strcpy(cErrorCode, strAnswer + idx );
		}
		char cMess[10000] = "";
	/*	sprintf(cMess, "Parced: [%s][%s][%s]", cNVag, cRetCode, cErrorCode );
		DBW.WriteLog(cMess);*/
		for( i=0; cErrorCode[i] && i < 4196; i++ )
			if(cErrorCode[i] == '\'') cErrorCode[i] = '"';
		
		strAwr = strAnswer;
		strAwr.Replace("'", "''");
		DBW.WriteLog("1");
hell:
		sprintf( cMess, "pTov_S4624Ins497 %u, %s, %s, %s",
				g_iDep,
				isNull(cNVag),
				isNull(cRetCode),
				isNull(strAwr));
		DBW.ExecSQL(cMess);
		long ret = 0;
		char msgg[512] = "";
		DBW.Fetch();
		DBW.GetData(1, SQL_C_SLONG, &ret, sizeof(long), &Ind);
		char sssss[100] = "";
		sprintf(sssss, "Первое поле которое вернула процедура: %d", ret);
		DBW.WriteLog(sssss);
		if( Ind != -1 && ret == -1 )
		{
			DBW.GetData(2, SQL_C_CHAR, msgg, 512, &Ind );
			if( Ind != -1 ) AfxMessageBox(msgg);
			DBW.CloseCursor();
			DBW.WriteLog("Ветка которая обрабатывает -1");			
			// теперь попробуем поискать номер вагона после первого плюса
			if( !iTry ) //если конечно уже не пробовали
			{
				i = strAwr.Find('+', 0);
				i++;
				for( x = 0; x < 32 && strAnswer[i] >= '0' && strAnswer[i] <='9' && i < strlen(strAnswer); x++, i++ )
					cNVag[x] = strAnswer[i];
				cNVag[x] = 0;
				iTry = 1;
				goto hell; // эта строчка говорит о моем отношении
						   // к людям которые хотят поумничать и
						   // сказать о вредности goto
			}
		} else
		if( Ind != -1 && ret == 1 )
		{
			DBW.WriteLog("Ветка которая обрабатывает 1");
			DBW.GetData(2, SQL_C_CHAR, msgg, 512, &Ind );
			DBW.CloseCursor();
			if( Ind != -1 && AfxMessageBox(msgg, MB_YESNO) == IDYES )
			{				
				sprintf( cMess, "pTov_S4624Ins497 %u, %s, %s, %s, 1",
				g_iDep,
				isNull(cNVag),
				isNull(cRetCode),
				isNull(strAwr));
				DBW.ExecSQL(cMess);
			}
		}
		DBW.CloseCursor();
		DBW.WriteLog("3");
	} else
	if( strncmp(strAnswer + d + 8, "2955", 4) == 0)
	{
		DBW.WriteLog("Пришел ответ на 2955");
		char cQ[512] = "";
		char pr[16] = "";
		char KodErr[16] = "";
		long iRet = 0;
		long Ind = 0;

		strncpy(KodErr, strAnswer + d + 3, 4);
		KodErr[4] = 0;

		//strncpy(pr, strAnswer + d + 21, 3);
		int x;
		for (x = 0; x < 4 && strAnswer[d + 21 + x] != '+' && strAnswer[d + 21 + x] != ':'; x++)
			pr[x] = strAnswer[d + 21 + x];
		pr[x] = 0;

		sprintf(cQ, "pTov_S2955Ins497 '%s', '%s', '%s'",
			pr,
			KodErr,
			strAnswer);

		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_SLONG, &iRet, 4, &Ind);
		DBW.CloseCursor();
		if( Ind == -1 || iRet == -1 )
		{
			g_iDispatchInProgress = 0;
			return -1;
		}		
	}else
	if( strncmp(strAnswer + d + 8, "2956", 4) == 0)
	{
		DBW.WriteLog("Пришел ответ на 2956");
		char cQ[512] = "";
		char pr[16] = "";
		char KodErr[16] = "";
		char Dat[16] = "";
		char sqlDat[16] = "";
		int  iRet = 0;
		strncpy(KodErr, strAnswer + d + 3, 4);
		KodErr[4] = 0;
		int i;
		for( i=0; i < 6 && strAnswer[/*strAnswer + */d + 21 + i] != '+'; i++ )
		{
			pr[i] = strAnswer[/*strAnswer + */d + 21 + i];
		}
		pr[i] = 0;
		i++;
		strncpy(Dat, strAnswer + d + 21 + i, 4);
		sprintf(sqlDat, "20%.2s%.2s01", Dat + 2, Dat);
		CString aw = strAnswer;
		aw.Replace("'","''");
		sprintf(cQ, "pTov_S2956Ins497 '%s', '%s', '%s', '%s'",
				pr, sqlDat, KodErr, aw);
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_SLONG, &iRet, 4, &Ind);
		DBW.CloseCursor();
		if( Ind == -1 || iRet == -1 )
		{
			g_iDispatchInProgress = 0;
			return -1;
		}
	} else
	if( strncmp(strAnswer + d + 8, "2950", 4) == 0 ||
		strncmp(strAnswer + d + 8, "2958", 4) == 0 )
	{
		DBW.WriteLog("Пришел ответ на 2950(58)");
		char cQ[512] = "";
		char pr[16] = "";
		char KodErr[16] = "";
		char Dat[16] = "";
		char sqlDat[16] = "";
		int  iRet = 0;
		strncpy(KodErr, strAnswer + d + 3, 4);
		KodErr[4] = 0;
		int i;
		for( i=0; i < 6 && strAnswer[d + 21 + i] >= '0' && strAnswer[d + 21 + i] <= '9'; i++ )
		{
			pr[i] = strAnswer[d + 21 + i];
		}
		pr[i] = 0;
		i++;

		CString aw = strAnswer;
		int x = aw.Find("+", d);
		if( x != -1 && strncmp(strAnswer + d + 8, "2958", 4) == 0)
		{
			strncpy(Dat, strAnswer + x + 1, 4);
			sprintf(sqlDat, "20%.2s%.2s01", Dat + 2, Dat);
		} else
			strcpy( sqlDat, "NULL" );

		aw.Replace("'","''");
		sprintf(cQ, "pTov_S2950Ins497  '%s', %s, '%s', '%s'",
				pr, sqlDat, KodErr, aw);
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_SLONG, &iRet, 4, &Ind);
		DBW.CloseCursor();
		if( Ind == -1 || iRet == -1 )
		{
			g_iDispatchInProgress = 0;
			return -1;
		}
	} else
	if( strncmp(strAnswer + d + 8, "2957", 4) == 0)
	{
		DBW.WriteLog("Пришел ответ на 2957");
		char cQ[512] = "";
		char pr[16] = "";
		char KodErr[16] = "";
		char Dat[16] = "";
		char sqlDat[16] = "";
		int  iRet = 0;
		strncpy(KodErr, strAnswer + d + 3, 4);
		KodErr[4] = 0;
		int i;
		for( i=0; i < 6 && strAnswer[/*strAnswer + */d + 21 + i] != '+'; i++ )
		{
			pr[i] = strAnswer[/*strAnswer + */d + 21 + i];
		}
		pr[i] = 0;
		i++;
		strncpy(Dat, strAnswer + d + 21 + i, 4);
		sprintf(sqlDat, "20%.2s%.2s01", Dat + 2, Dat);
		CString aw = strAnswer;
		aw.Replace("'","''");
		sprintf(cQ, "pTov_S2957Ins497 '%s', '%s', '%s', '%s'",
				pr, sqlDat, KodErr, aw);
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_SLONG, &iRet, 4, &Ind);
		DBW.CloseCursor();
		if( Ind == -1 || iRet == -1 )
		{
			g_iDispatchInProgress = 0;
			return -1;
		}
	} else
	if( strstr(strAnswer, "OБPAБOTKA 4624 B ГBЦ") &&
		(strstr(strAnswer, "C O O Б Щ E H И E   П P И H Я T O") || 
		strstr(strAnswer, "COOБЩEHИE ПPИHЯTO") ||
		strstr(strAnswer, "COOБЩEНИE ПPИНЯTO"))
		)
	{
//		AfxMessageBox("yes");
		DBW.WriteLog("Положительная квитанция ГВЦ");
		g_iDispatchInProgress = 0;
		return 0;
	} else
	if( strstr(strAnswer, "OБPAБOTKA 4624 B ГBЦ") &&
		(strstr(strAnswer, "C O O Б Щ E H И E   О Т В Е Р Г Н У Т О") ||
		strstr(strAnswer, "COOБЩEHИE ОТВЕРГНУТО") ||
		strstr(strAnswer, "COOБЩEНИE OTBEPГНУTO"))
	  )
	{
		char cQ[512] = "";
		char *rz = NULL;
		int iRet = 0;
		char cVag[12] = "";		
		rz = strstr(strAnswer, "(:");
		if( rz )
		{
			int i,j;
			for( i=0, j=0; i < 5 && rz[j] != 0; j++ ) 
			{
				if( rz[j] == ' ') i++;
			}
			rz = rz + j;
			strncpy(cVag, rz, 8);
			sprintf(cText, "Отрицательная квитанция ГВЦ для вагона %s", cVag);
			DBW.WriteLog(cText);
			sprintf(cQ, "pTov_S4624Reject '%.8s', '%s', %d", cVag, strAnswer, g_iDep);
			DBW.ExecSQL(cQ);
			DBW.Fetch();
			DBW.GetData(1, SQL_C_SLONG, &iRet, 4, &Ind);
			cQ[0] = 0;
			DBW.GetData(2, SQL_C_CHAR, &cQ, 512, &Ind);
			DBW.CloseCursor();
			if( Ind == -1 || iRet == -1 )
			{
				AfxMessageBox(cQ);
				DBW.WriteLog(cQ);
				g_iDispatchInProgress = 0;
				return -1;
			}		
		}
	}
	/*
	char *sss = 0;
	sss = strstr(strAnswer, "OБPAБOTKA 4624 B ГBЦ");
	sss = strstr(strAnswer, "COOБЩEHИE ОТВЕРГНУТО");
*/

	g_iDispatchInProgress = 0;
	return 0;

}

void CMasterApp::LoadMsgAnswerFromFile(void)
{
	if( !g_conf_strMessageReturnPath.GetLength() ) return;
	if( g_iDispatchInProgress ) return;
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	char cText[40196] = "";
	CString cPath = g_conf_strMessageReturnPath + "*";
	hFind = FindFirstFile(cPath, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE) 
	{
		return;
	}

	int iPmg_ret = 0;
	if(!( FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ))
	{		
		FILE *f = fopen(FindFileData.cFileName, "rb");
		if( f )
		{
			fread(cText, FindFileData.nFileSizeLow, 1, f);
			cText[FindFileData.nFileSizeLow + 1] = 0;
			fclose(f);
			
			if( (iPmg_ret = ProcessMsgAnswer(cText)) != 0 && iPmg_ret != -999 )
				CopyFile(g_conf_strMessageReturnPath + FindFileData.cFileName, g_conf_strMessageUnprocessedPath + FindFileData.cFileName, 0);
			if( iPmg_ret != -999 ) DeleteFile(g_conf_strMessageReturnPath + FindFileData.cFileName);				
			else return;
		}
	}
	while( FindNextFile(hFind, &FindFileData) )
	{
		if(!( FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY ))
		{
			cPath = g_conf_strMessageReturnPath + FindFileData.cFileName;
			FILE *f = fopen(cPath, "rb");
			if( f )
			{
				fread(cText, 40196, 1, f);
				fclose(f);
//				ProcessMsgAnswer(cText);
				if( (iPmg_ret = ProcessMsgAnswer(cText)) != 0 && iPmg_ret != -999) 
					CopyFile(g_conf_strMessageReturnPath + FindFileData.cFileName, g_conf_strMessageUnprocessedPath + FindFileData.cFileName, 0);
				if( iPmg_ret != -999 ) DeleteFile(g_conf_strMessageReturnPath + FindFileData.cFileName);
				else return;
			}
		}		
	}
}

void CMasterApp::On4624SendLog()
{
	/*
	CDlgGetDate4624Log Dlg;
	if(Dlg.DoModal() == IDCANCEL ) return;
	*/
	CDlgMsg4624Log Dlg1;
//	strcpy( Dlg1.cDat1, Dlg.cSQLDatRet);
	Dlg1.DoModal();
}

void CMasterApp::OnMnuPprSendToRem()
{
	CDlgPPTSendToRem Dlg;
	Dlg.DoModal();
}


void CMasterApp::Dos2Win(unsigned char * cLine, int len)
{
 for (;*cLine;cLine++)    {
        if (*cLine>=0x80 && *cLine<=0xAF){
                *cLine+=(0xC0-0x80);
        }
        else
            if (*cLine>=0xE0 && *cLine<=0xEF){
                *cLine+=(0xF0-0xE0);
            }
    }
	/*
   int i=0;
    for(;cLine[i]!='\0' && i < len;i++)
    {
        if((cLine[i]>'a')&&(cLine[i]<='п'))
            cLine[i]=cLine[i+192];
            
        else if((cLine[i]>='p')&&(cLine[i]<='я'))
           cLine[i]=cLine[i]+240;
        else
            cLine[i]=cLine[i];
    }
    cLine[i]='\0';
	*/
//    return str2;

/*
	for( int i=0; cLine[i] && i < len; i++ )
	{
		if( cLine[i] >= 0x80 && 
			cLine[i] <= 0xEF )
		{
			cLine[i] += 64;
		}
	}
*/
}

void CMasterApp::Win2Dos(char * cLine, int len)
{
//	if( !g_bDosCodePage ) return;

	for( int i=0; cLine[i] && i < len; i++ )
	{
/*		if( cLine[i] == 'Ю' )
		{
			cLine[i] = 0x9E;
		}*/
		if( cLine[i] >= 'А' && cLine[i] <= 'я' )
		{
			cLine[i] -= 64;
		}
	}
}


int CMasterApp::ExitInstance()
{
	if( g_iMessageNumber )
	{
		return g_iMessageReturnResult;
	}
	return CWinApp::ExitInstance();
}

void CMasterApp::OnMnuNaltl()
{
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_mkcReportNalTL1067 %u", g_iDep);
	Dlg.DoModal();
}

void CMasterApp::OnMnuPasptl()
{
	CPrintableDlg Dlg;
	CDlgInputNTL1067 Dlg1;

	Dlg1.DoModal();

	sprintf(Dlg.cQ, "pTov_GetPaspTL1067 %u, %s", g_iDep, Dlg1.m_strNTL);
	Dlg.DoModal();
}

void CMasterApp::SendTeleMessage(CString strMess, CString strPref)
{
	char cT[32] = "";
	itoa(g_iStandAlone, cT, 10);
	WriteLog("cT");
//	WriteLog(g_conf_strMessagePath);
	if( g_iStandAlone ) //сообщение в файл
	{
		if( !g_conf_strMessagePath.GetLength() ) return;

		char cText[16000] = "";
		strcpy(cText, strMess);

		CString strN;
        SYSTEMTIME st;
		ZeroMemory(&st, sizeof(st));
        GetLocalTime(&st);
        strN.Format("%s%.2d%.2d_%s.txt", 
                    g_conf_strMessagePath,
                    st.wMonth,
                    st.wDay,
					strPref);
        char sl[64];
        sprintf(sl, "Msg: %s", strN);
        DBW.WriteLog((LPTSTR)sl, 3);
        FILE *f = fopen(strN, "wb");
        if( !f )
        {
            AfxMessageBox("Невозможно открыть файл для отправки сообщения!", MB_OK);
            return;
        }
		if( g_bDosCodePage )
		{
			Win2Dos(cText, strlen(cText));
		}		
        fwrite(cText, strlen(cText), 1, f);
        fclose(f);
		if( g_bDosCodePage )
		{
			Dos2Win((unsigned char *)cText, strlen(cText));
		}
		if( g_strASOUPTeleName != "" && tele )
			tele->SendMessageDst(strMess, &g_strASOUPTeleName);
	} else
	{
//		tele->SendMessageDst(strMess, &g_strTelecomServer);
		if( g_strASOUPTeleName != "" && tele)
			tele->SendMessageDst(strMess, &g_strASOUPTeleName);
	}
}

void CAboutDlg::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

BOOL CAboutDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	char cText[64] = "";
	sprintf(cText, "%d.%d.%d", g_iSuperVersion, g_iVersion, g_iBuild);
	m_Ver.SetWindowText(cText);
	itoa(Dsp.GetVersion(), cText, 10);
	m_VerDLL.SetWindowText(cText);
/*	itoa(g_iDBVersion, cText, 10);
	if( g_iDBVersion > 100 )
	{
		cText[3] = cText[2];
		cText[2] = '.';
		cText[4] = 0;
	}*/
	m_VerBase.SetWindowText(g_strDBVersion);
	m_bnOK2.ModifyStyle(WS_VISIBLE, 0);
	if( g_iCanPush == 1 ) m_bnOK2.ModifyStyle(0, WS_VISIBLE);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CMasterApp::OnMenuPodachaVag()
{
	CDlgNaryadNaVag Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuNaltl1520()
{
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_mkcReportNalTL1520 %u", g_iDep);
	Dlg.DoModal();
}

void CMasterApp::OnMenuTrfrVans()
{
	CDlgInputTrafVag Dlg;

/*
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_mkcReportPptTrafVag %u", g_iDep);*/
	Dlg.DoModal();
}

void CMasterApp::OnMnuSprOpervag()
{
	CDlgSpravSmp Dlg;
	Dlg.DlgMode = 200;
	Dlg.DoModal();
}

void CMasterApp::OnVagonNaKolee1067()
{
	CDlgVagOn1067 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuAsoupErr()
{
	CDlgSpravSmp Dlg;
	Dlg.DlgMode = 201;
	Dlg.DoModal();
}


void CMasterApp::OnMnuPpt4624()
{
	CInputNVagObezl4624 Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

	CDlgMsg4624_Main Dlg1;
	Dlg1.iPaspPPT = Dlg.bDatFromPasp;
	Dlg1.m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(Dlg1.cVagNum32, Dlg.cNVag32);
	Dlg1.DoModal();
}

void CMasterApp::OnMnuPptSpravPerest()
{
	CDlgPerestRept Dlg1;
	if( Dlg1.DoModal() == IDCANCEL ) return;

	CPrintableDlg Dlg;
	
	sprintf(Dlg.cQ, "pTov_mkcReportPptPerest %u, %s, %s, %d", g_iDep, Dlg1.d1, Dlg1.d2, Dlg1.iCheck);
	Dlg.DoModal();
}

void CMasterApp::OnArhOperVag()
{
	CDlgInputNVag Dlg1;
	if( Dlg1.DoModal() == IDCANCEL ) return;
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_mkcReportPptArxOper '%s'", Dlg1.strNVag );
	Dlg.DoModal();
}

void CMasterApp::OnMnuVo2()
{
	m_EdInputVO2 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnu2955()
{	
//	CDlgMsg2955 Dlg;
	CDlgInput2955 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuMsg2958()
{
	CDlgInput2958 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuMsg2956()
{
	CDlgInput2956 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuMsg2957()
{
	CDlgInput2957 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuRpt2955()
{
	CDlgInput2955Rpt Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuRemDefektBr()
{
	CDlgRemDefektBR Dlg;
	Dlg.DoModal();
}
void CMasterApp::OnMnuRemDefektNb()
{
	CDlgremDefektNB Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuRemDefektSb()
{
	CDlgRemDefektSB Dlg;
	Dlg.DoModal();
}
void CMasterApp::OnMnuRaspress()
{
	CDlgRaspressKP Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuRaspressLog()
{
	CDlgZapressLog Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuQuery2730()
{
	CDlgReq2730ListVag Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnu2956Svod()
{
	CDlgInput2956Svod Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuSetupMess()
{
	CDlgSetupTO Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuRpt2950()
{
	CDlgInputRpt2950	Dlg;
	Dlg.DoModal();	
}

void CMasterApp::OnMnuRpt2956()
{
	CDlgInputRpt2956 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuRptVo7()
{
	CDlgInput_VO7 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuObezlVag()
{
	CDlgInputObezlVag Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuSetupCommon()
{
	CDlgSetupCommon Dlg;
	Dlg.DoModal();

	if( Dlg.m_iNeedDowngrade )
	{
		MoveFile((CString)theApp.m_pszExeName + ".exe", "master.ex_");
		char cCurDir[256] = "";
		GetCurrentDirectory(256, cCurDir);	
		execl("upgrd.exe old", 0);
		exit(0);
	}
}

void CMasterApp::RotateLog(void)
{
	if( !g_iLogClearDays || !g_iSqlLogByDay ) return;
	int iDays = g_iLogClearDays;

	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(st));
	GetSystemTime(&st);

	time_t  tc;
	time(&tc);
	__int64 lDays = g_iLogClearDays;

	tc -= lDays * 86400;

	tm *t;
	t = localtime(&tc);
	char cText[64] = "";
//	sprintf(cText, "%.4d%.2d%.2d", st.wYear, st.wMonth, st.wDay);
	sprintf(cText, "%.4d%.2d%.2d", t->tm_year + 1900, t->tm_mon + 1, t->tm_mday);
	DBW.WriteLog("kdate");
	DBW.WriteLog(cText);
	long lLastPoint = atol(cText);
//	AfxMessageBox(cText);
	WIN32_FIND_DATA FindFileData;
	HANDLE hFind;
	CString cPath = (CString)g_conf_cLogDir + "\\*.log";
	hFind = FindFirstFile(cPath, &FindFileData);
	if (hFind == INVALID_HANDLE_VALUE) 
	{
		return;
	}
	do
	{
		char cFName[260] = "";
		char cMess[512] = "";
		strncpy(cFName, FindFileData.cFileName, 8);
		cFName[8] = 0;
		long lFName = atol(cFName);
		if( lLastPoint > lFName )
		{
			sprintf(cMess, "Del %s", FindFileData.cFileName);
			WriteLog(cMess);
			if( DeleteFile(CString(g_conf_cLogDir) + CString("\\") + FindFileData.cFileName) )
				WriteLog("ok");
			else
				WriteLog("failed");
		}
	} while( FindNextFile(hFind, &FindFileData) );
}

void CMasterApp::OnMnuSprPodkat()
{
	CDlgInputRptPodakat Dlg;
	Dlg.DoModal();
}

int CMasterApp::CheckClientUpdate(void)
{
	if( !g_iUpdateByHttp ) return 0;
	if( g_iSQLClientVersion > (g_iVersion * 10 + g_iBuild) &&
	   AfxMessageBox("Обнаружена новая версия! Произвести обновление?", MB_YESNO ) == IDYES)
	{
		DeleteFile((CString)m_pszExeName + ".ex_");
		MoveFile((CString)m_pszExeName + ".exe", "master.ex_");
		char cCurDir[256] = "";
		GetCurrentDirectory(256, cCurDir);
		char msg[255] = "";		
//		_execl("upgrd.exe", 0);
//		CreateProcess("upgrd.exe", NULL, NULL, NULL, FALSE, 0, NULL, cCurDir, NULL, NULL);
		WinExec("upgrd.exe", SW_SHOW);

		return 1;
	}
	return 0;
}

void CMasterApp::OnMnuZhurnKomplekt()
{
	CDlgRptInputZhurnKompl Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuDbBr()
{
	CDlgBDTl2 Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuDbNb()
{
	CDlgBDTl2 Dlg;
	Dlg.iType = 1;
	Dlg.DoModal();
}

void CMasterApp::OnMenuObnovlenie()
{
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_GetUpdateInf");
	Dlg.DoModal();
}

void CMasterApp::OnMnuRptPrihTl()
{
	CDlgInputRptPrihodTL Dlg;
	Dlg.DoModal();
}

int CMasterApp::DispatchPeresVedMsg( char * msg )
{
	int iDep_OCV = 0;
	if( strlen(msg) < 23 ) return -1;

	char cScript[40024] = "";
	char cScriptRez[40024] = "";
	char cQ[640] = "";
	char cQRez[640] = "";

	// Данные заголовка КП

	char  cVedNum[10] = "";
	char  cDateOtpr[16] = "";
	char  cIPR_Snd[10] = "";
	char  cIPR_Rcv[10] = "";
	DWORD dwIPR_Snd = 0;
	DWORD dwIPR_Rcv = 0;
	char  cNVag[10] = "";
	DWORD MasterRcvID = 0;
	char  cDatRcvPV[16] = "";
	long  Ind = 0;
	DWORD dwKPCount = 0;
	// Структура для заполнения данных по КП
	struct cKPPeres
	{
		__int64 qwIKP;
		__int64	qwIZAP;
		char cNKP[16];
		DWORD dwTKP;
		char cIzgotDt[9];
		DWORD dwIzgotIPR;
		char cPosForDt[9];
		DWORD dwPosForIPR;
		char cPosOsvDt[9];
		DWORD dwPosOsvIPR;
		int	 iDiameterR;
		int	 iObodR;
		int	 iGrebR;
		int	 iProkatR;
		int	 iDiameterL;
		int	 iObodL;
		int	 iGrebL;
		int	 iProkatL;
		cKPPeres()
		{
			ZeroMemory(this, sizeof(cKPPeres));
		}
	} pKP[40];
	
//	DBW.ExecSQL("sdddd");

	char *token;
	char seps[] = " \n\r";
	token = strtok(msg + 14, seps);
	strncpy(cVedNum, token, 10);
	if( strlen(cVedNum) > 4 ) return -1;

	token = strtok( NULL, seps ); 
	strncpy(cDateOtpr, token, 8);
	if( strlen(cDateOtpr) > 8 ) return -1;
	
	// отправитель
	token = strtok( NULL, seps );
	strncpy(cIPR_Snd, token, 8);
	if( strlen(cIPR_Snd) > 6 ) return -1;
	dwIPR_Snd = atoi(cIPR_Snd);

	sprintf(cQ, "select idep from nvTovDepo where ipr = %u", dwIPR_Snd);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_LONG, &iDep_OCV, 4, &Ind);
	DBW.CloseCursor();
	if( Ind == - 1 || iDep_OCV == 0 ) 
	{
		DBW.WriteLog("В таблице Депо не найден IPR");	
		return -1;
	}

	/// получатель
	token = strtok( NULL, seps );
	strncpy(cIPR_Rcv, token, 8);
	if( strlen(cIPR_Rcv) > 6 ) return -1;
	dwIPR_Rcv = atoi(cIPR_Rcv);

	token = strtok( NULL, seps ); // пропустим ":"
	char cTKP[20] = "";
	char cDat[20] = "";
	char cKLPR[20] = "";
	token = strtok( NULL, seps ); // пропустим первую цифру

//	DBW.ExecSQL("BEGIN TRAN");

	for( ; token!=0 && dwKPCount < 40; dwKPCount++ )
	{		
		token = strtok( NULL, seps ); // Номер КП
		strncpy(pKP[dwKPCount].cNKP, token, 12);
		if( strlen(pKP[dwKPCount].cNKP) > 12 ) return -1;		

		token = strtok( NULL, seps ); //Тип
		strncpy(cTKP, token, 4);
		if( strlen(cTKP) > 4) return -1;
		pKP[dwKPCount].dwTKP = atoi(cTKP);

		// Если был приход - нам нужен IKP
		sprintf(cQ, "pTov_GetKPByNKP '%s', %u", pKP[dwKPCount].cNKP, pKP[dwKPCount].dwTKP);
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_UBIGINT, &pKP[dwKPCount].qwIKP, 8, &Ind);
		DBW.CloseCursor();

		token = strtok( NULL, seps ); // Дата изготовления
		strncpy(cDat, token, 12);
		if( strlen(cDat) > 6 ) return -1;
		if( strlen(cDat) < 6 || !strcmp("0", cDat)) pKP[dwKPCount].cIzgotDt[0] = 0;
		else sprintf(pKP[dwKPCount].cIzgotDt, "%.4s%.2s01", cDat + 2, cDat);

		token = strtok( NULL, seps ); // Предпр. изготовитель
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 4) return -1;
		pKP[dwKPCount].dwIzgotIPR = GetIPRByKL(cKLPR);

		token = strtok( NULL, seps ); // Дата пос. фор.
		strncpy(cDat, token, 12);
		if( strlen(cDat) > 6 ) return -1;
		if( strlen(cDat) < 6 || !strcmp("0", cDat) ) pKP[dwKPCount].cPosForDt[0] = 0;
		else sprintf(pKP[dwKPCount].cPosForDt, "%.4s%.2s01", cDat + 2, cDat);
		
		token = strtok( NULL, seps ); // Предпр. пос. фор.
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 4) return -1;
		pKP[dwKPCount].dwPosForIPR = GetIPRByKL(cKLPR);

		token = strtok( NULL, seps ); // Дата пос. осв.
		strncpy(cDat, token, 12);
		if( strlen(cDat) > 6 ) return -1;
		if( strlen(cDat) < 6 || !strcmp("0", cDat) ) pKP[dwKPCount].cPosOsvDt[0] = 0;
		else sprintf(pKP[dwKPCount].cPosOsvDt, "%.4s%.2s01", cDat + 2, cDat);
		
		token = strtok( NULL, seps ); // Предпр. пос. осв.
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 4) return -1;
		pKP[dwKPCount].dwPosOsvIPR = GetIPRByKL(cKLPR);
// правое колесо
		token = strtok( NULL, seps ); // Прав Диаметр 
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 4) return -1;
		pKP[dwKPCount].iDiameterR = atoi(cKLPR);
//		if( pKP[dwKPCount].iDiameterR < 1000 ) pKP[dwKPCount].iDiameterR *= 10;

		token = strtok( NULL, seps ); // Прав Обод 
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 3) return -1;
		pKP[dwKPCount].iObodR = atoi(cKLPR);
		if( pKP[dwKPCount].iObodR < 100 ) pKP[dwKPCount].iObodR *= 10;

		token = strtok( NULL, seps ); // Прав Гребень 
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 3) return -1;
		pKP[dwKPCount].iGrebR = atoi(cKLPR);

		token = strtok( NULL, seps ); // Прав Прокат 
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 3) return -1;
		pKP[dwKPCount].iProkatR = atoi(cKLPR);
// левое колесо
		
		token = strtok( NULL, seps ); // лев Диаметр 
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 4) return -1;
		pKP[dwKPCount].iDiameterL = atoi(cKLPR);
//		if( pKP[dwKPCount].iDiameterL < 1000 ) pKP[dwKPCount].iDiameterL *= 10;

		token = strtok( NULL, seps ); // лев Обод 
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 3) return -1;
		pKP[dwKPCount].iObodL = atoi(cKLPR);
		if( pKP[dwKPCount].iObodL < 100 ) pKP[dwKPCount].iObodL *= 10;

		token = strtok( NULL, seps ); // лев Гребень 
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 3) return -1;
		pKP[dwKPCount].iGrebL = atoi(cKLPR);

		token = strtok( NULL, seps ); // лев Прокат 
		strncpy(cKLPR, token, 4);
		if( strlen(cKLPR) > 3) return -1;
		pKP[dwKPCount].iProkatL = atoi(cKLPR);
		
		token = strtok( NULL, seps ); //пропустим :
		token = strtok( NULL, seps ); // пропустим первую цифру

		SYSTEMTIME st;
		ZeroMemory(&st, sizeof(st));
		GetLocalTime(&st);
		st.wMilliseconds = 0;
		char cRashodScript[512] = "";

		// Оформим приход на ОЦВ
		sprintf(cQ, "pTov_PrihodKP %s,%s,%u,'%s',%u, %s,%s,%s,%s,%s, %s,%s,%s,%s,%s, %s,%s,%s,%s,%s,  %s,%s,%s,%s,%s, %s,%s,%s,%s,%s\n",		

			isNull(pKP[dwKPCount].qwIKP), //IKP
			"NULL", // IZAP
			iDep_OCV, // IDEP
			pKP[dwKPCount].cNKP, // @NKP
			pKP[dwKPCount].dwTKP,// @ITKP

			isNull(cDateOtpr), // DAT_POST
			"1", // @GRUZ
			"NULL", //VAG
			"NULL", //@PRIH_REM_VAG
			"NULL",//isNull(dwIPR_Snd),  // @PERES_IPR

			"NULL",//isNull(cDateOtpr),  // @PERES_DAT
			"NULL",//isNull(cVedNum), // @PERES_NVED
			isNull(pKP[dwKPCount].dwIzgotIPR), // @IzOs_IPR
			isNull(pKP[dwKPCount].cIzgotDt),   // @IzOs_DAT
			isNull(pKP[dwKPCount].dwPosForIPR),// @POSFOR_IPR

			isNull(pKP[dwKPCount].cPosForDt),  // @POSOSV_DAT
			isNull(pKP[dwKPCount].dwPosOsvIPR),//@POSOSV_IPR
			isNull(pKP[dwKPCount].cPosOsvDt),
			"NULL", //@ITR
			"NULL", //@TD_R

			"NULL",// @TD_L 
			isNull((DWORD)pKP[dwKPCount].iDiameterR), //@PRIH_DR
			isNull((DWORD)pKP[dwKPCount].iDiameterL), //@PRIH_DL
			"NULL", // @PRIH_NEISP
			"NULL", // @TR_REM

			"NULL", // @IFAM_PRIH
			"NULL", // @PRIZN_RAS
			"NULL", // ILK
			"NULL",  // @KOLES_T
			"NULL"  // @NPark
			);		

			DBW.ExecSQL(cQ);
			DBW.Fetch();
			DBW.GetData(1, SQL_C_ULONG, &pKP[dwKPCount].qwIKP, 8, &Ind);
			DBW.GetData(2, SQL_C_ULONG, &pKP[dwKPCount].qwIZAP, 8, &Ind);
			DBW.CloseCursor();

		sprintf(cQRez, "exec pTov_PrihodKP_Rez %u,'%s',%u, %s, %s, %s,%s,%s,%s,%s, %s,%s,%s,%s,%s, %s,%s,%s,%s,%s,  %s,%s,%s,%s,%s, %s,%s,%s,%s,%s\n",		
		
			iDep_OCV, // IDEP
			pKP[dwKPCount].cNKP, // @NKP
			pKP[dwKPCount].dwTKP,// @ITKP
			"NULL", // Old_IzgIPr
			"NULL", // Old_IzgDat

			isNull(cDateOtpr), // DAT_POST
			"1", // @GRUZ
			"NULL", //VAG
			"NULL", //@PRIH_REM_VAG
			"NULL",//isNull(dwIPR_Snd),  // @PERES_IPR

			"NULL",//isNull(cDateOtpr),  // @PERES_DAT
			"NULL",//isNull(cVedNum), // @PERES_NVED
			isNull(pKP[dwKPCount].dwIzgotIPR), // @IzOs_IPR
			isNull(pKP[dwKPCount].cIzgotDt),   // @IzOs_DAT
			isNull(pKP[dwKPCount].dwPosForIPR),// @POSFOR_IPR

			isNull(pKP[dwKPCount].cPosForDt),  // @POSOSV_DAT
			isNull(pKP[dwKPCount].dwPosOsvIPR),//@POSOSV_IPR
			isNull(pKP[dwKPCount].cPosOsvDt),
			"NULL", //@ITR
			"NULL", //@TD_R

			"NULL",// @TD_L 
			isNull((DWORD)pKP[dwKPCount].iDiameterR), //@PRIH_DR
			isNull((DWORD)pKP[dwKPCount].iDiameterL), //@PRIH_DL
			"NULL", // @PRIH_NEISP
			"NULL", // @TR_REM

			"NULL", // @IFAM_PRIH
			"NULL", // @PRIZN_RAS
			"NULL", // ILK
			"NULL",  // @KOLES_T
			"NULL"  // @NPark
			);		
			DBW.ExecSQLRzv(cQRez);

			sprintf(cQ, "exec pTov_UpdateRazmers %s, NULL, 1, %s, %s, %s, %s, NULL, NULL, %s, %s, NULL, NULL, %s, %s, %s, %s, %s, %s, NULL, NULL, NULL, NULL, NULL, %s, %s, %s",
						isNull(pKP[dwKPCount].qwIZAP),
						isNull(pKP[dwKPCount].dwPosForIPR),// @POSFOR_IPR
						isNull(pKP[dwKPCount].cPosForDt),  // @POSOSV_DAT
						isNull(pKP[dwKPCount].dwPosOsvIPR),//@POSOSV_IPR
						isNull(pKP[dwKPCount].cPosOsvDt),
						isNull((double)pKP[dwKPCount].iDiameterR / 10), //@DKK_R
						isNull((double)pKP[dwKPCount].iDiameterL / 10), //@DKK_L
						isNull((double)pKP[dwKPCount].iProkatR / 10), //@PROKAT_L
						isNull((double)pKP[dwKPCount].iProkatL / 10), //@PROKAT_R
						isNull((DWORD)pKP[dwKPCount].iObodR / 10), //@OBOD_L
						isNull((DWORD)pKP[dwKPCount].iObodL / 10), //@OBOD_R
						isNull((DWORD)pKP[dwKPCount].iGrebR / 10), //@GREB_L
						isNull((DWORD)pKP[dwKPCount].iGrebL / 10), //@GREB_R

						isNull(pKP[dwKPCount].dwIzgotIPR), // @IzOs_IPR
						isNull(pKP[dwKPCount].cIzgotDt),   // @IzOs_DAT

						isNull(pKP[dwKPCount].qwIKP));

			DBW.ExecSQL(cQ);
			DBW.CloseCursor();
			
			sprintf(cQRez, "exec pTov_UpdateRazmers_Rez '%s', %u, %s, %s, %u,  NULL, 1, %s, %s, %s, %s, NULL, NULL, %s, %s, NULL, NULL, %s, %s, %s, %s, %s, %s, NULL, NULL, NULL, NULL, NULL, %s, %s, %s",
						pKP[dwKPCount].cNKP, // @NKP
						pKP[dwKPCount].dwTKP,// @ITKP
						isNull(pKP[dwKPCount].dwIzgotIPR), // @IzOs_IPR
						isNull(pKP[dwKPCount].cIzgotDt),   // @IzOs_DAT
						iDep_OCV,
						
						isNull(pKP[dwKPCount].dwPosForIPR),// @POSFOR_IPR
						isNull(pKP[dwKPCount].cPosForDt),  // @POSOSV_DAT
						isNull(pKP[dwKPCount].dwPosOsvIPR),//@POSOSV_IPR
						isNull(pKP[dwKPCount].cPosOsvDt),
						isNull((double)pKP[dwKPCount].iDiameterR / 10), //@DKK_R
						isNull((double)pKP[dwKPCount].iDiameterL / 10), //@DKK_L
						isNull((double)pKP[dwKPCount].iProkatR / 10), //@PROKAT_L
						isNull((double)pKP[dwKPCount].iProkatL / 10), //@PROKAT_R
						isNull((DWORD)pKP[dwKPCount].iObodR / 10), //@OBOD_L
						isNull((DWORD)pKP[dwKPCount].iObodL / 10), //@OBOD_R
						isNull((DWORD)pKP[dwKPCount].iGrebR / 10), //@GREB_L
						isNull((DWORD)pKP[dwKPCount].iGrebL / 10), //@GREB_R

						isNull(pKP[dwKPCount].dwIzgotIPR), // @IzOs_IPR
						isNull(pKP[dwKPCount].cIzgotDt),   // @IzOs_DAT

						isNull(pKP[dwKPCount].qwIKP));

			DBW.ExecSQLRzv(cQRez);
			sprintf(cQ, "exec pTov_UpdateRemKP 1, %s, %s, 1, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL",
						isNull(pKP[dwKPCount].qwIZAP),
						DateToSQL(st));
			DBW.ExecSQL(cQ);
			DBW.CloseCursor();
	}

	sprintf(cScript, "begin tran\n declare @IPeres bigint\n exec @IPeres = pTov_InsertVedHdr %u, %s, %s, %u, %u, NULL, NULL, NULL, NULL, 0, %s\n",
            iDep_OCV,
            isNull(cVedNum),
            isNull(cDateOtpr),		// Дата отправки пересылочной ведомости
            dwIPR_Rcv,		// Ид. предприятия получателя            	
            1,				// признак 1-в вагоне, 0-на машине
			"NULL"  //	dwIPR_Sobst
			);
	
	sprintf(cScriptRez, "begin tran\n declare @IPeres bigint\n exec @IPeres = pTov_InsertVedHdr %u, %s, %s, %u, %u, NULL, NULL, NULL, NULL, 0, %s\n",
            iDep_OCV,
            isNull(cVedNum),
            isNull(cDateOtpr),		// Дата отправки пересылочной ведомости
            dwIPR_Rcv,		// Ид. предприятия получателя            	
            1,				// признак 1-в вагоне, 0-на машине
			"NULL"  //	dwIPR_Sobst
			);

	for( int i = 0; i < dwKPCount; i++ )
	{
		sprintf(cScript, "%s exec pTov_RashodKP %I64u, %d, 93, 1, NULL, %s, NULL, NULL, %s, %s, NULL, NULL, @IPeres\n",
				cScript,
				pKP[i].qwIZAP,
				iDep_OCV,
				isNull(cDateOtpr),
				isNull(dwIPR_Snd),
				cVedNum );

		sprintf(cScriptRez, "%s exec pTov_RashodKP_Rez 0, '%s', %u, %s, %s, NULL, %u, 93, 1, NULL, %s, NULL, NULL, %s, %s, NULL, NULL, @IPeres\n",
				cScriptRez,
				pKP[i].cNKP,
				pKP[i].dwTKP,// @ITKP
				isNull(pKP[i].cIzgotDt),   // @IzOs_DAT
				isNull(pKP[i].dwIzgotIPR), // @IzOs_IPR
				

				iDep_OCV,
				isNull(cDateOtpr),
				isNull(dwIPR_Snd),
				cVedNum );

	}

	strcat(cScript, " exec pTov_OtpravPeres @IPeres\n");
	strcat(cScript, "\ncommit tran");

	strcat(cScriptRez, " exec pTov_OtpravPeres @IPeres\n");
	strcat(cScriptRez, "\ncommit tran");

	DBW.ExecSQL(cScript);
	DBW.CloseCursor();

	DBW.ExecSQLRzv(cScriptRez);
	
//	DBW.ExecSQL("COMMIT TRAN");

	return 0;
}

DWORD CMasterApp::GetIPRByKL(char cKlPr[8])
{
	char cQ[64] = "";
	long Ind = 0;
	DWORD dwIpr = 0;
	sprintf(cQ, "pTov_GetPredByKl '%s'", cKlPr);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(2, SQL_C_LONG, &dwIpr, 4, &Ind);
	DBW.CloseCursor();
	return dwIpr;
}

int CMasterApp::DispatchSetPeresVedStatus(char *msg)
{
	
	char *token, cVedNum[32] = "", cVedDat[16] = "", cStatus[16] = "", cIPR[16] = "";
	char seps[] = " \n\r", cQ[128] = "";
	int iDep_VCHDE = 0;

	// IPR
	token = strtok(msg + 14, seps);
	strncpy(cIPR, token, 10);
	g_iIPr_VCHDE = atoi(cIPR);

	// Номер ведомости
	token = strtok( NULL , seps);
	strncpy(cVedNum, token, 10);
	
	// Дата
	token = strtok( NULL, seps ); 
	strncpy(cVedDat, token, 16);
	if( strlen(cVedDat) > 8 ) return -1;
	
	// статус
	token = strtok( NULL, seps );
	strncpy(cStatus, token, 16);
	if( strlen(cStatus) > 6 || atoi(cStatus) <= 0 || atoi(cStatus) > 4 ) return -1;


	sprintf(cQ, "pTov_mkcSetPeresVedStatus %u, %s, '%s', %s",
			g_iIPr_VCHDE,
			cVedNum,
			cVedDat,
			cStatus);

	DBW.ExecSQL(cQ);
	DBW.CloseCursor();


	return 0;
}

void CMasterApp::OnMnuPeresTlRcv()
{
	CDlgPeresTlLog Dlg;
	Dlg.DoModal();
}

void CMasterApp::OnMnuVu54Podr()
{
	CDlgRptVU54 Dlg;
	Dlg.iMode = 2;
    Dlg.DoModal();
}

void CMasterApp::OnMenuPptBdVag()
{
	CDlgPPT_InpBDVag Dlg;
	Dlg.DoModal();
}

//extern int g_iCanPush;
extern void Shuffle(char* pcSeq);

void CAboutDlg::OnBnClickedButtonOK2()
{
	if( !g_iCanPush ) return;
	DBW.ExecSQL("update tovPrihod_kp set prih_dr = prih_dr / 10 where prih_dr > 1000 and (idep = 3000002 or idep = 3000007)");
	char cQ[500] = "", cScript[400] = "";
//	sprintf(cScript, "exec pTov_SetEmployeePassword 3001067, '55555', 3");

//	DBW.WriteLog(cScript);
//	Shuffle(cScript);
//	sprintf(cQ, "(:4936 0 4624 1\r\n[%s]:)", cScript);
//	sprintf(cQ, "(:4936 0 2:)");
//	DBW.ExecSQLRzv(cScript);
//	DBW.WriteLog(cQ);
//	tele->SendMessageDst(cQ, &strSrv); 
	DBW.CloseCursor();
}

void CMasterApp::OnMnuPptPerestVag1520()
{
	CPrintableDlg Dlg;
	CDlgInputDate Dlg2;
	if( Dlg2.DoModal() == IDCANCEL ) return;

	sprintf(Dlg.cQ, "pTov_mkcReportPptTrafVkt %u, %s", g_iDep, Dlg2.cSQLDate);
	Dlg.DoModal();
}

void CMasterApp::OnMnuExport_PaspKP()
{
	typedef void (CALLBACK* ShowFormDllFunc)(char*, int, int, int);
	ShowFormDllFunc ShowForm; 
	HMODULE hm = LoadLibrary ("hc_xls.dll");
	ShowForm = (ShowFormDllFunc)GetProcAddress (hm, "ShowForm");

	if (ShowForm)
	{
		ShowForm ((char*)g_ConnStrIn, g_iDep, g_iFam,1);
	}
	FreeLibrary (hm);	
}

void CMasterApp::OnMnuSprSobstv()
{
	CDlgSprPrSobstv Dlg;
	Dlg.iNeedOKButton = 0;
	Dlg.DoModal();
}

void CMasterApp::OnMnuSpravZamDet()
{
	typedef void (CALLBACK* ShowFormDllFunc)(char*, int, int, int);
	ShowFormDllFunc ShowForm; 
	HMODULE hm = LoadLibrary ("hc_xls.dll");
	ShowForm = (ShowFormDllFunc)GetProcAddress (hm, "ShowForm");

	if (ShowForm)
	{
		ShowForm ((char*)g_ConnStrIn, g_iDep, g_iFam, 2);
	}
	FreeLibrary (hm);
}


void CMasterApp::OnMnuSprPostKpXls()
{
	CDlgInputRptPostKpXls Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;
	/*
	typedef void (CALLBACK* CReportPostKP)(char*, char*, char*);
	CReportPostKP ReportPostKP; 
	HMODULE hm = LoadLibrary ("ExlRep.dll");
	if( !hm )
	{
		AfxMessageBox("Ошибка загрузки ExlRep.dll");
		return;
	}
	ReportPostKP = (CReportPostKP)GetProcAddress (hm, "ReportPostKP");
	char cText[64] = "";
	char cDat[16] = "";
	
	
	itoa(g_iDep, cText, 10);
	strncpy( cDat, Dlg.cDat, 14 );
	strncpy( cDat, "20130601", 14 );

	if (ReportPostKP)
	{
		ReportPostKP ((char*)g_ConnStrIn, (char *)cText, (char *)cDat );
	} else
	{
		AfxMessageBox("Ошибка формирования отчета!");
	}
	FreeLibrary (hm);
	*/

	typedef void (CALLBACK* CReportPostKP)(wchar_t*, wchar_t*, wchar_t*);
	CReportPostKP ReportPostKP; 
	HMODULE hm = LoadLibrary ("ExlRep.dll");
	if( !hm )
	{
		AfxMessageBox("Невозможно загрузить 'ExlRep.dll'");
		return;
	}
	ReportPostKP = (CReportPostKP)GetProcAddress (hm, "ReportPostKP");
	char cDep[10] = "2";
	char cDat[32] = "20130601";
							  
	wchar_t wcConnStr[300] = L"Database=kcmod;User_Name=sa;Password=700087;Server=10.240.3.109";
	wchar_t wcIDep[10] = L"2";
	wchar_t wcDat[16] = L"20130501";

	
	mbstowcs(wcConnStr, (char *)g_cDelphiConnStr, 300);
	//mbstowcs(wcConnStr, (char *)"Database=kcmod;User_Name=sa;Password=700087;Server=10.240.3.109", 300);
	mbstowcs(wcIDep, itoa(g_iDep, cDep, 10), 10);
	mbstowcs(wcDat, Dlg.cDat, 14);
	
	
	if (ReportPostKP)
	{
		//ShowForm (tcConnStr, tcIDep, tcDat);
		ReportPostKP(wcConnStr, wcIDep, wcDat);
		//ShowForm(L"Database=kcmod;User_Name=sa;Password=700087;Server=10.240.3.109", L"1", L"20120909");
	} else
		AfxMessageBox("Не найдена ReportPostKP");
	FreeLibrary (hm);	
}


void CMasterApp::OnMnuArchive()
{
	CDlgInputArchive Dlg;
	Dlg.DoModal();
}
