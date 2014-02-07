// DlgSetupCommon.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSetupCommon.h"
#include ".\dlgsetupcommon.h"
#include <process.h>

extern char cConfigFileName[];
extern CMasterApp theApp;
// CDlgSetupCommon dialog

IMPLEMENT_DYNAMIC(CDlgSetupCommon, CDialog)
CDlgSetupCommon::CDlgSetupCommon(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetupCommon::IDD, pParent)
{
	m_iNeedDowngrade = 0;
}

CDlgSetupCommon::~CDlgSetupCommon()
{
}

void CDlgSetupCommon::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CHECK1, m_CheckSqlDbg);
	DDX_Control(pDX, IDC_CHECK2, m_CheckSilentCancel);
	DDX_Control(pDX, IDC_CHECK3, m_Check3);
	DDX_Control(pDX, IDC_EDIT1, m_EdDays);
	DDX_Control(pDX, IDC_EDIT2, m_EdLogDir);	
	DDX_Control(pDX, IDC_CHECK4, m_CheckAlerts);
}


BEGIN_MESSAGE_MAP(CDlgSetupCommon, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_CHECK3, OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButtonReverseUpgr)
END_MESSAGE_MAP()


// CDlgSetupCommon message handlers

extern bool g_LogEnabled;
extern int	g_iSqlLogByDay;
extern int	g_iLogClearDays;
extern char g_conf_cLogDir[64];
extern int g_iDisplayServerMessage;

extern int CheckDirExists(CString strPath);

BOOL CDlgSetupCommon::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdDays.QInit(20, 1);
	m_CheckSqlDbg.SetCheck(g_LogEnabled);
	m_CheckSilentCancel.SetCheck(g_conf_MessageOnCancel);
	m_EdLogDir.SetMode(0, 1, 100);	
	m_Check3.SetCheck(g_iSqlLogByDay);
	m_EdDays.EnableWindow(m_Check3.GetCheck());
	char cText[32] = "";
	itoa(g_iLogClearDays, cText, 10);
	m_EdDays.SetWindowText(cText);
	m_EdLogDir.SetWindowText(g_conf_cLogDir);

	m_CheckAlerts.SetCheck(g_iDisplayServerMessage);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSetupCommon::OnBnClickedOk()
{
	g_LogEnabled = (bool)m_CheckSqlDbg.GetCheck();
	g_conf_MessageOnCancel = m_CheckSilentCancel.GetCheck();
	g_iDisplayServerMessage = m_CheckAlerts.GetCheck();

	char cText[200] = "";

	m_EdLogDir.GetWindowText(cText, 255);
	if( CheckDirExists(cText) == -1)
	{
		AfxMessageBox("Указан несуществующий путь для журналов программы!");
		m_EdLogDir.SetFocus();
		return;
	}

	itoa(g_LogEnabled, cText, 10);
	WritePrivateProfileString("DEBUG", "EnableSqlLog", cText, cConfigFileName);
	
	if( !g_conf_MessageOnCancel )
		WritePrivateProfileString("ARM", "SilentCancel", "yes", cConfigFileName);
	else
		WritePrivateProfileString("ARM", "SilentCancel", "no", cConfigFileName);

	g_iLogClearDays = atoi(m_EdDays.GetString());
	g_iSqlLogByDay = m_Check3.GetCheck();

	if( m_Check3.GetCheck() )
	{
		WritePrivateProfileString("ARM", "SqlLogByDay", "1", cConfigFileName);
		WritePrivateProfileString("ARM", "LogClearDays", m_EdDays.GetString(), cConfigFileName);
	} else
	{
		WritePrivateProfileString("ARM", "SqlLogByDay", "0", cConfigFileName);
		WritePrivateProfileString("ARM", "LogClearDays", "0", cConfigFileName);
	}	
	m_EdLogDir.GetWindowText(cText, 255);
	WritePrivateProfileString("ARM", "LogDir", cText, cConfigFileName);	
//	AfxMessageBox("DF");
	itoa(g_iDisplayServerMessage, cText, 10);
	WritePrivateProfileString("ARM", "DisplayServerAlerts", cText, cConfigFileName);
	OnOK();
}

void CDlgSetupCommon::OnBnClickedCheck3()
{
	m_EdDays.EnableWindow(m_Check3.GetCheck());
}

void CDlgSetupCommon::OnBnClickedCheck1()
{
	m_Check3.SetCheck(m_CheckSqlDbg.GetCheck());
	OnBnClickedCheck3();
	m_Check3.EnableWindow(m_CheckSqlDbg.GetCheck());
	m_EdDays.EnableWindow(m_CheckSqlDbg.GetCheck());
}
extern int g_iUpdateByHttp;
void CDlgSetupCommon::OnBnClickedButtonReverseUpgr()
{
	if( !g_iUpdateByHttp ) return;
	if( AfxMessageBox("Сейчас будет установлена предыдущая версия программы! Продолжить?", MB_YESNO) == IDNO ) return;
	m_iNeedDowngrade = 1;
	OnCancel();
}
