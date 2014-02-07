// DlgSetupUserMenuItems.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSetupUserMenuItems.h"
#include ".\dlgsetupusermenuitems.h"


// CDlgSetupUserMenuItems dialog

IMPLEMENT_DYNAMIC(CDlgSetupUserMenuItems, CDialog)
CDlgSetupUserMenuItems::CDlgSetupUserMenuItems(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSetupUserMenuItems::IDD, pParent)
{
	dwID = 0;
	dwID_Arm = 0;
	dwCount = 0;
	iBeenStarted = 0;
	iTitleIdx = 0;
	iGotTitle = 0;
}

CDlgSetupUserMenuItems::~CDlgSetupUserMenuItems()
{
}

void CDlgSetupUserMenuItems::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
}


BEGIN_MESSAGE_MAP(CDlgSetupUserMenuItems, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton4_EnableAll)
	ON_BN_CLICKED(IDC_BUTTON5, OnBnClickedButton5_DisableAll)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON6, OnBnClickedButton6)
END_MESSAGE_MAP()


// CDlgSetupUserMenuItems message handlers

BOOL CDlgSetupUserMenuItems::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );
	
	m_List.InsertColumn(0, "Квалификация",0, 300);
	DWORD dwNum = 0;
	char cQ[128] = "";
	char cText[64] = "";
	long Ind = 0;


		sprintf(cQ, "pTov_GetEmplQualification %u, 6", dwID );
		DBW.ExecSQL(cQ);
		RefreshList();
		
		sprintf(cQ, "pTov_GetArmList %u", dwID );
		DBW.ExecSQL(cQ);
		for(int i=0; DBW.Fetch() != SQL_NO_DATA; i++ )
		{
			DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind );
			DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 )
			{
				m_Combo.AddString(cText);
				m_Combo.SetItemData(i, dwNum);
			}
			DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind );
			if( Ind != -1 && dwNum && !iGotTitle)
			{
				iGotTitle = 1;
				iTitleIdx = i;
			}
		}
		DBW.CloseCursor();

	if( iGotTitle )m_Combo.SetCurSel(iTitleIdx);
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSetupUserMenuItems::OnBnClickedOk()
{
	dwCount = m_List.GetItemCount();
	for( int i=0; i < dwCount; i++ )
	{
		p_dwCheckMenuID[i] = m_List.GetItemData(i);
		p_dwCheckMenuVal[i] = m_List.GetCheck(i);
	}
	dwID_Arm = m_Combo.GetItemData(m_Combo.GetCurSel());
	iTitleIdx = m_Combo.GetCurSel();
	if( iTitleIdx != -1 ) iGotTitle = 1;
	OnOK();
}

void CDlgSetupUserMenuItems::OnBnClickedButton4_EnableAll()
{
	for( int i=0; i < m_List.GetItemCount(); i++ )
		m_List.SetCheck(i);
	m_Combo.SetCurSel(4);
}

void CDlgSetupUserMenuItems::OnBnClickedButton5_DisableAll()
{
	for( int i=0; i < m_List.GetItemCount(); i++ )
		m_List.SetCheck(i, 0);
}

void CDlgSetupUserMenuItems::OnBnClickedButton1()
{
	char cQ[150] = "";
	m_List.DeleteAllItems();
	sprintf(cQ, "pTov_GetEmplQualificationSpec 1");
	DBW.ExecSQL(cQ);
	iBeenStarted = 0;
	RefreshList();
	iBeenStarted = 1;
	m_Combo.SetCurSel(0);
}

void CDlgSetupUserMenuItems::RefreshList(void)
{
	DWORD dwNum = 0;
	char cText[64] = "";
	long Ind = 0;
	for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_ERROR && g_sqlret != SQL_NO_DATA && i < 500; i++ )
	{
		DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
		m_List.InsertItem(i, "");
		m_List.SetItemData(i, dwNum);
		cText[0] = 0;
		DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
		m_List.SetItemText(i, 0, cText);
		dwNum = 0;
		DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind);
		if ( !iBeenStarted )m_List.SetCheck(i, dwNum);
		else m_List.SetCheck(i, p_dwCheckMenuVal[i]);
/*		DBW.GetData(4, SQL_C_ULONG, &dwNum, 4, &Ind);
		m_List.SetItemColor(i, RGB(0,0,0), p_dwColors[dwNum - 1]);*/
	}
	DBW.CloseCursor();
}

void CDlgSetupUserMenuItems::OnBnClickedButton2()
{
	char cQ[150] = "";
	m_List.DeleteAllItems();
	sprintf(cQ, "pTov_GetEmplQualificationSpec 3");
	DBW.ExecSQL(cQ);
	iBeenStarted = 0;
	RefreshList();
	iBeenStarted = 1;
	m_Combo.SetCurSel(2);
}

void CDlgSetupUserMenuItems::OnBnClickedButton3()
{
	char cQ[150] = "";
	m_List.DeleteAllItems();
	sprintf(cQ, "pTov_GetEmplQualificationSpec 4");
	DBW.ExecSQL(cQ);
	iBeenStarted = 0;
	RefreshList();
	iBeenStarted = 1;
	m_Combo.SetCurSel(3);
}

void CDlgSetupUserMenuItems::OnBnClickedButton6()
{
	char cQ[150] = "";
	m_List.DeleteAllItems();
	sprintf(cQ, "pTov_GetEmplQualificationSpec 2");
	DBW.ExecSQL(cQ);
	iBeenStarted = 0;
	RefreshList();
	iBeenStarted = 1;
	m_Combo.SetCurSel(1);
}
