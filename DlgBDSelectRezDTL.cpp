// DlgBDSelectRezDTL.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgBDSelectRezDTL.h"
#include ".\dlgbdselectrezdtl.h"


// CDlgBDSelectRezDTL dialog

IMPLEMENT_DYNAMIC(CDlgBDSelectRezDTL, CDialog)
CDlgBDSelectRezDTL::CDlgBDSelectRezDTL(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBDSelectRezDTL::IDD, pParent)
{
	iDetailID = 0;
}

CDlgBDSelectRezDTL::~CDlgBDSelectRezDTL()
{
}

void CDlgBDSelectRezDTL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_STATIC_X, m_lbRecCount);
}


BEGIN_MESSAGE_MAP(CDlgBDSelectRezDTL, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton_Delete)
END_MESSAGE_MAP()


// CDlgBDSelectRezDTL message handlers
extern int g_iReportGridFontSize;
extern char g_cReportGridFontFace[64];
BOOL CDlgBDSelectRezDTL::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

	m_List.SetFont(Font);

	switch ( iDetailID )
	{
	case 0: SetWindowText("Выборка по боковым рамам"); break;
	case 1: SetWindowText("Выборка по надрессорная балкам"); break;
	case 2: SetWindowText("Выборка по соединительным балкам"); break;
	}

	bGotHeader = false;
    RefreshList();
    m_List.SetSelectionMark(0);
    bGotHeader = true;


	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgBDSelectRezDTL::RefreshList(void)
{
    char cRecCount[32];
	DWORD  dwColID = 0;
    m_List.DeleteAllItems();
	DBW.ExecSQL(cQ);
    if( !bGotHeader ) DBW.SetListHeader(&m_List);
	itoa(DBW.UpdateListByHandle(&m_List, &dwColID, false, true), cRecCount, 10);
	DBW.CloseCursor();

	char cText[64] = "";
	itoa(m_List.GetItemCount(), cText, 10);
	m_lbRecCount.SetWindowText(cText);
}

void CDlgBDSelectRezDTL::OnBnClickedButton_Delete()
{
	int idx = m_List.GetSelectionMark();
	if( idx < 0 ) return;
	char cQ[264] = "";
	char cDatPrih[15] = "";
	char cDetNum[15] = "";
	char cYear[5] = "";
	char cKlIzg[10] = "";
	m_List.GetItemText(idx, 0, cDatPrih, 15);
	m_List.GetItemText(idx, 1, cDetNum, 15);
	m_List.GetItemText(idx, 2, cYear, 5);
	m_List.GetItemText(idx, 3, cKlIzg, 10);

	long lNum = 0, Ind = 0;
	char cText[250] = "";

	sprintf(cQ, "pTov_TLPrihDel %d, %d, %s, '%s', %s, %s",
			g_iDep,
			iDetailID,
			StrDateToSQL(cDatPrih, 1),
			cDetNum,
			isNull(cYear),
			isNull(cKlIzg));
	DBW.ExecSQL(cQ);
	if( g_sqlret != SQL_ERROR )
	{
		DBW.Fetch();
		DBW.GetData(1, SQL_C_SLONG, &lNum, sizeof(long), &Ind);
		switch( lNum  )
		{
		case 1:
			m_List.DeleteItem(idx);
			break;
		case -1:
			DBW.GetData(2, SQL_C_CHAR, cText, 250, &Ind);
			AfxMessageBox(cText);
			break;
		default:
			DBW.GetData(2, SQL_C_CHAR, cText, 250, &Ind);
			AfxMessageBox(cText);
			DBW.CloseCursor();	
			RefreshList();
		break;
		}
		
	} else
	{
		AfxMessageBox("Ошибка удаления детали тележки");
	}

	DBW.CloseCursor();






}
