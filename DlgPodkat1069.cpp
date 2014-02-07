// DlgPodkat1069.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPodkat1069.h"
#include ".\dlgpodkat1069.h"
#include "DlgSpravKdr.h"


// CDlgPodkat1069 dialog

IMPLEMENT_DYNAMIC(CDlgPodkat1069, CDlgWithAccelerators)
CDlgPodkat1069::CDlgPodkat1069(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgPodkat1069::IDD, pParent)
{
	iMode = 0;
	iTLReplaceMode = 0;
	dwBrigadir_ID = 0;
	qwPTVag_ID = 0;
	cNVag[0] = 0;
	ZeroMemory(&stDat, sizeof(stDat));
	ZeroMemory(&stOldPktDate, sizeof(stOldPktDate));
	dwGot2730 = 0;
	cNTL1[0] = 0;
	cNTL2[0] = 0;
}

CDlgPodkat1069::~CDlgPodkat1069()
{
}

void CDlgPodkat1069::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT2, m_EdDat);
	DDX_Control(pDX, IDC_EDIT7, m_EdFIO);
	DDX_Control(pDX, IDC_EDIT43, m_EdNTL1);
	DDX_Control(pDX, IDC_EDIT117, m_EdNTL2);
	DDX_Control(pDX, IDC_EDIT4, m_EdPos1);
	DDX_Control(pDX, IDC_EDIT120, m_EdPos2);
	DDX_Control(pDX, IDC_CHECK1, m_Check2730);
	DDX_Control(pDX, IDC_CHECK31, m_Check2612);
	DDX_Control(pDX, IDC_BUTTON2, m_ButTl1);
	DDX_Control(pDX, IDC_BUTTON3, m_ButTl2);
}


BEGIN_MESSAGE_MAP(CDlgPodkat1069, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton_Brigadir)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgPodkat1069 message handlers

BOOL CDlgPodkat1069::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_ButTl1.EnableWindow(0);
	m_ButTl2.EnableWindow(0);

	m_EdNVag.QInit(80);
	m_EdDat.SetMode(1);
	m_EdFIO.SetMode(5);
	DBW.FillEmplArray(m_EdFIO.lpEmpl, 17);
	m_EdNTL1.QInit(90);
	m_EdNTL2.QInit(90);
	m_EdPos1.QInit(90);
	m_EdPos2.QInit(90);

	m_Check2730.SetCheck(1);
	m_Check2612.SetCheck(1);

	long Ind = 0;
	char cQ[512] = "";
	char cText[64] = "";
	DWORD dwNum = 0;

	if( !iMode || !qwPTVag_ID)
	{
		m_EdDat.SetTime(&stDat);
		m_EdFIO.SetFamTextByID(dwBrigadir_ID);
		m_EdNVag.SetWindowText(cNVag);
	} else
	{
		if( qwPTVag_ID )
		{
			sprintf( cQ, "pTov_pptGetVagPkt %I64u", qwPTVag_ID );
			DBW.ExecSQL(cQ);
			DBW.Fetch();
			DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) 
			{
				m_EdNVag.SetWindowText(cText);
				strncpy(cNVag, cText, 8);
			}
			DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_EdDat.SetWindowText(cText);
			DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind);
			if( Ind != -1 ) m_EdFIO.SetData(dwNum);
			DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_EdFIO.SetWindowText(cText);
			DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_EdNTL1.SetWindowText(cText);
			DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_EdNTL2.SetWindowText(cText);
			DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_EdPos1.SetWindowText(cText);
			DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind);
			if( Ind != -1 ) m_EdPos2.SetWindowText(cText);
			dwNum = 1;
			DBW.GetData(9, SQL_C_ULONG, &dwGot2730, 4, &Ind);
			DBW.CloseCursor();
		} 
	}

	m_EdDat.GetTime(&stOldPktDate);
	if( dwGot2730 ) 
	{
		m_Check2730.SetWindowText("Есть данные по 2730");
		m_Check2730.SetCheck(1);
	} else
	{
		if( cNVag[0] == '5' )
		{
			m_Check2730.EnableWindow(0);
		}
	}
	
	if( iTLReplaceMode )
	{
		
		m_EdNTL1.SetWindowText(cNTL1);
		m_EdNTL2.SetWindowText(cNTL2);


		m_EdNVag.EnableWindow(0);
		m_EdDat.EnableWindow(0);
		m_EdFIO.EnableWindow(0);
		m_EdPos1.EnableWindow(0);
		m_EdPos2.EnableWindow(0);
		m_EdNTL1.EnableWindow(0);
		m_EdNTL2.EnableWindow(0);
	}

	return TRUE;
}

void CDlgPodkat1069::OnBnClickedButton_Brigadir()
{
	CDlgSpravKdr Dlg;
	Dlg.DlgMode = 1;
	Dlg.iFilter = 17;
	if( Dlg.DoModal() == IDCANCEL) return;
	m_EdFIO.SetData(Dlg.dwFio);
	m_EdFIO.SetWindowText(Dlg.cFio);
}
extern CString g_strASOUPTeleName;
extern CMasterApp theApp;

extern int g_i2730ReqMessage;
void CDlgPodkat1069::OnBnClickedOk()
{
	if( !m_EdDat.isValid() )
	{
		AfxMessageBox("Дата указана некорректно");
		m_EdDat.SetFocus();
		return;
	}
	if( m_EdDat.isNull() )
	{
		AfxMessageBox("Необходимо указать дату подкатки!");
		m_EdDat.SetFocus();
		return;
	}

	CString str = "";
	m_EdNVag.GetWindowText(str);

	if( !iTLReplaceMode && !VanNumberIsValid(str) )
	{
		if( AfxMessageBox("Не сходится контрольная сумма номера вагона! Исправить?", MB_YESNO) == IDYES) return;
	}
	char cQ[512] = "";
	long Ind = 0, lNum = 0;
/*
	sprintf(cQ, "pTov_S2730CheckExist '%s'", str );
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_ULONG, &dwGot2730, 4, &Ind );
	DBW.CloseCursor();
*/
	if( !iTLReplaceMode )
	{
		sprintf(cQ, "pTov_pptVagPkt %u, %s, %s, %s, %s, %s, %s, %s, %s",
				g_iDep,
				isNull(qwPTVag_ID),
				m_EdNVag.GetString(1),
				m_EdDat.GetSQLDate(),
				isNull(m_EdFIO.GetData()),
				m_EdNTL1.GetString(1),
				m_EdNTL2.GetString(1),
				m_EdPos1.GetString(0),
				m_EdPos2.GetString(0));
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_SLONG, &lNum, 4, &Ind);
		if( lNum == -1 )
		{
			char cMess[2048] = "";
			DBW.GetData(2, SQL_C_CHAR, cMess, 2048, &Ind);
			AfxMessageBox(cMess);
			DBW.CloseCursor();
			return;
		} else
		if( lNum == 1 )
		{
			DBW.GetData(2, SQL_C_UBIGINT, &qwPTVag_ID, 8, &Ind);
		}
		DBW.CloseCursor();
	}
// 	DBW.ReallocHandle();
	if( /*!dwGot2730 &&*/ m_Check2730.GetCheck() && g_strASOUPTeleName != "" )
	{
		CString strMess;
		if( g_i2730ReqMessage == 4618) strMess.Format("(: 4618 2730: %s:)", m_EdNVag.GetString(0) );
		else strMess.Format("(: 4628 2730: %s:)", m_EdNVag.GetString(0) );
		theApp.SendTeleMessage(strMess, CString("2730_") + cNVag);
	}
	if( m_Check2612.GetCheck() && g_strASOUPTeleName != "" )
	{
		CString strMess;
/*		if( g_i2730ReqMessage == 4618) strMess.Format("(: 4618 2612: %s:)", m_EdNVag.GetString(0) );
		else*/ 
			strMess.Format("(: 4618 2612: %s:)", m_EdNVag.GetString(0) );
		theApp.SendTeleMessage(strMess, CString("2612_") + cNVag);
	}

	OnOK();
}

void CDlgPodkat1069::OnCancel()
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;	
	CDlgWithAccelerators::OnCancel();
}
