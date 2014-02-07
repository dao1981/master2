// DlgProkatTL1069.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgProkatTL1069.h"
#include ".\dlgprokattl1069.h"
#include "DlgPodkat1069.h"
#include "DlgSpravKdr.h"
extern char g_cDepESR[16];
// CDlgProkatTL1069 dialog

IMPLEMENT_DYNAMIC(CDlgProkatTL1069, CDlgWithAccelerators)
CDlgProkatTL1069::CDlgProkatTL1069(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgProkatTL1069::IDD, pParent)
{
	iGotHeader = 0;	
}

CDlgProkatTL1069::~CDlgProkatTL1069()
{
}

void CDlgProkatTL1069::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT3, m_Dat1);
	DDX_Control(pDX, IDC_EDIT116, m_Dat2);
	DDX_Control(pDX, IDC_EDIT4, m_EdVagNum);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_EDIT1, m_EdESR);
	DDX_Control(pDX, IDC_EDIT2, m_EdPark);
	DDX_Control(pDX, IDC_EDIT7, m_EdWay);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_CHECK2, m_Check2);
	DDX_Control(pDX, IDC_EDIT5, m_Dat);
	DDX_Control(pDX, IDC_EDIT6, m_EdFIO);
	DDX_Control(pDX, IDC_LABEL_COUNT, m_LabelCount);
}


BEGIN_MESSAGE_MAP(CDlgProkatTL1069, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClicked_Select)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton_PPTVans)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton_AddVag)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton_EditVag)
	ON_BN_CLICKED(IDC_BUTTON5, OnBnClickedButton_FIO)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton4)
END_MESSAGE_MAP()


// CDlgProkatTL1069 message handlers

BOOL CDlgProkatTL1069::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();
	m_LabelCount.SetWindowText("0");
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );
	m_EdESR.SetWindowText(g_cDepESR);
	m_Dat1.SetMode(1);
	m_Dat2.SetMode(1);
	m_EdFIO.SetMode(5);
	DBW.FillEmplArray(m_EdFIO.lpEmpl, 17);	
	// TODO:  Add extra initialization here

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgProkatTL1069::OnBnClicked_Select()
{

//	char cQ[512] = "";
	char cVagNum[32] = "";

	m_EdVagNum.GetWindowText(cVagNum, 32);

	sprintf(cQ, "pTov_pptVagPktList %u, %s, %s, %s",
			g_iDep,
			isAble(m_Check1.GetCheck(), m_Dat1.GetSQLDate()),
			isAble(m_Check1.GetCheck(), m_Dat2.GetSQLDate()),
			isAble(m_Check2.GetCheck(), isNull(cVagNum)));
	DBW.ExecSQL(cQ);
	RefreshList();
	DBW.CloseCursor();
	
}

void CDlgProkatTL1069::RefreshList(void)
{
	/*
	char cQ[512] = "";
	char cVagNum[32] = "";

	m_EdVagNum.GetWindowText(cVagNum, 32);

	sprintf(cQ, "pTov_pptVagPktList %u, %s, %s, %s",
			g_iDep,
			m_Dat1.GetSQLDate(),
			m_Dat2.GetSQLDate(),
			isNull(cVagNum));
	DBW.ExecSQL(cQ);*/
	DWORD dwPos = 0;
	if( !iGotHeader )
	{
		DBW.SetListHeader(&m_List);
		iGotHeader = 1;
	}
	DBW.UpdateListByHandle(&m_List, &dwPos, false, true);
	DBW.CloseCursor();
	char cNum[32] = "";
	itoa(m_List.GetItemCount(), cNum, 10);
	m_LabelCount.SetWindowText(cNum);

}

void CDlgProkatTL1069::OnBnClickedButton_PPTVans()
{
//	char cQ[512] = "";
	char cESR[16] = "";
	char cPark[16] = "";
	char cWay[16] = "";

	m_EdESR.GetWindowText(cESR, 16);
	m_EdPark.GetWindowText(cPark, 16);
	m_EdWay.GetWindowText(cWay, 16);	
	if( !cPark[0] ) strcpy(cPark, "NULL");
	if( !cWay[0] ) strcpy(cWay, "NULL");

	sprintf(cQ, "pTov_pptVagPutPktList %u, %s, %s, %s",
			g_iDep,
			isNull(cESR),
			cPark,
			cWay);
	DBW.ExecSQL(cQ);
	RefreshList();
	DBW.CloseCursor();
}

void CDlgProkatTL1069::OnBnClickedButton_AddVag()
{
/*	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;*/
	CDlgPodkat1069 Dlg;
	Dlg.iMode = 0;
	Dlg.qwPTVag_ID = 0;
	Dlg.dwBrigadir_ID = m_EdFIO.GetData();
	m_Dat.GetTime(&Dlg.stDat);
//	Dlg.qwPTVag_ID = m_List.qwGetItemData(idx);
	if( Dlg.DoModal() == IDCANCEL ) return;
	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(st));
	m_Dat1.GetTime(&st);
	m_Dat2.SetWindowText("");
	m_Check1.SetCheck(1);
	m_Check2.SetCheck(0);	
	m_Dat.SetTime(&st);
	OnBnClicked_Select();
}

void CDlgProkatTL1069::OnBnClickedButton_EditVag()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;

	CDlgPodkat1069 Dlg;
	Dlg.iMode = 1;
	Dlg.qwPTVag_ID = m_List.qwGetItemData(idx);
	if( !Dlg.qwPTVag_ID )
	{
		Dlg.dwBrigadir_ID = m_EdFIO.GetData();
		m_Dat.GetTime(&Dlg.stDat);
		m_List.GetItemText(idx, 0, Dlg.cNVag, 32);
	}
	if( Dlg.DoModal() == IDCANCEL ) return;
	DBW.ExecSQL(cQ);
	RefreshList();
	DBW.CloseCursor();
}

void CDlgProkatTL1069::OnBnClickedButton_FIO()
{
	CDlgSpravKdr Dlg;
	Dlg.DlgMode = 1;
	Dlg.iFilter = 17;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFIO.SetData(Dlg.dwFio);
	m_EdFIO.SetWindowText(Dlg.cFio);
}

void CDlgProkatTL1069::OnBnClickedButton4()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;
	if( MessageBox("Вы действительно хотите удалить данные о подкатке тележки 1067 под вагон?", "Внимание!", MB_YESNO ) == IDNO )
		return;
	char cQ1[512] = "";
	sprintf(cQ1, "pTov_pptDelVagPkt %I64u", m_List.qwGetItemData(idx));
	DBW.ExecSQL(cQ1);
	DBW.CloseCursor();
	DBW.ExecSQL(cQ);
	RefreshList();
	DBW.CloseCursor();
}
