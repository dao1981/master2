// DlgMsg4624_VagDateInput.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624_VagDateInput.h"
#include ".\dlgmsg4624_vagdateinput.h"

extern char		g_c4624DefNVag[32];
extern char		g_c4624DefDate[12];
extern int		g_iStandAlone;
extern SYSTEMTIME g_CurrentDate;
// CDlgMsg4624_VagDateInput dialog

IMPLEMENT_DYNAMIC(CDlgMsg4624_VagDateInput, CDlgWithAccelerators)
CDlgMsg4624_VagDateInput::CDlgMsg4624_VagDateInput(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg4624_VagDateInput::IDD, pParent)
{
	m_EdNVag.QInit(100);
	m_EdNVag.bColored = 1;
	m_Dat.bColored = 1;
	iCountVD = 1;
	m_iCheck = 0;
}

CDlgMsg4624_VagDateInput::~CDlgMsg4624_VagDateInput()
{
}

void CDlgMsg4624_VagDateInput::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT2, m_Dat);
	DDX_Control(pDX, IDC_CHECK1, m_Check);
	DDX_Control(pDX, IDC_EDIT7, m_Hour);
	DDX_Control(pDX, IDC_EDIT5, m_Min);
}


BEGIN_MESSAGE_MAP(CDlgMsg4624_VagDateInput, CDlgWithAccelerators)
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEdit1)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgMsg4624_VagDateInput message handlers

void CDlgMsg4624_VagDateInput::OnOK()
{
/*	if( m_Dat.isNull() )
	{
		AfxMessageBox("Необходимо указать дату!");
		return;
	}*/
/*	if( !m_Dat.isValid() )
	{
		AfxMessageBox("Дата указана некорректно!");
		return;
	}*/
	m_iCheck = m_Check.GetCheck();

	SYSTEMTIME st;
//	GetSystemTime(&g_CurrentDate);
	ZeroMemory(&st, sizeof(st));
	m_Dat.GetTime(&st);
	GetLocalTime(&g_CurrentDate);
	
//	char cText[64] = "";
//	DateToStrRus(g_CurrentDate, cText);
	
	if( SysDateCmp(st, g_CurrentDate) > 0 )
	{
		AfxMessageBox("Указанная дата ещё не наступила!");
		return;
	}
	ZeroMemory(&stDat, sizeof(stDat));
	m_Dat.GetTime(&stDat);
	if( m_Hour.GetWindowTextLength() && m_Min.GetWindowTextLength() ) 
	{
		stDat.wHour = (WORD)m_Hour.GetAsDouble();
		stDat.wMinute = (WORD)m_Min.GetAsDouble();		
		if( stDat.wHour > 24 )
		{
			AfxMessageBox("Время указано некорректно!");
			m_Hour.SetFocus();
			return;
		}
		if( stDat.wMinute > 60 )
		{
			AfxMessageBox("Время указано некорректно!");
			m_Min.SetFocus();
			return;
		}
		stDat.wMilliseconds = 33;
	} else
	{
		stDat.wMilliseconds = 0;
	}
//	AfxMessageBox(cText);
	//m_EdNVag.GetWindowText(cNVag32, 32);
	strcpy(cNVag32, m_EdNVag.GetAsString());

	CDialog::OnOK();
}

BOOL CDlgMsg4624_VagDateInput::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	if( g_c4624DefNVag[0] )
	{
		m_EdNVag.SetWindowText(g_c4624DefNVag);
	}
	if( g_c4624DefDate[0] )
		m_Dat.SetWindowText(g_c4624DefDate);


	if( !g_iStandAlone )
	{
		char cText[64] = "";
		long Ind = 0;
		DBW.ExecSQL("pTov_GetRemVanListOC");
		for( int i=0; i < 40 && (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
		{
			DBW.GetData(1, SQL_C_CHAR, m_pVagDate[iCountVD].cVagNum, 32, &Ind);
			DBW.GetData(2, SQL_C_CHAR, m_pVagDate[iCountVD].cDate, 16, &Ind);			
		}
		DBW.CloseCursor();
	}	
	m_Hour.QInit(20,1);
	m_Min.QInit(20,1);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg4624_VagDateInput::OnEnChangeEdit1()
{
	if( g_iStandAlone ) return;
//	m_
}

void CDlgMsg4624_VagDateInput::OnBnClickedOk()
{

	// TODO: Add your control notification handler code here
/*
	if( m_Check.GetCheck() )
	{
		if( AfxMessageBox("Запросить паспорт вагона из АСУОП?", MB_YESNO) == IDYES )
		{
			char cQ[128] = "";
			sprintf(cQ, "pTov_S4624SelPasp %u, %s, 
			return;
		}
		
	}
	*/

	OnOK();
}
