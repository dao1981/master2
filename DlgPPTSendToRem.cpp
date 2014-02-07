// DlgPPTSendToRem.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPPTSendToRem.h"
#include ".\dlgpptsendtorem.h"
#include "DlgSpravKdr.h"

// CDlgPPTSendToRem dialog

IMPLEMENT_DYNAMIC(CDlgPPTSendToRem, CDlgWithAccelerators)
CDlgPPTSendToRem::CDlgPPTSendToRem(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgPPTSendToRem::IDD, pParent)
{
}

CDlgPPTSendToRem::~CDlgPPTSendToRem()
{
}

void CDlgPPTSendToRem::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_FIO1);
	DDX_Control(pDX, IDC_EDIT3, m_EdTlNum);
	DDX_Control(pDX, IDC_LIST1, m_List);
}


BEGIN_MESSAGE_MAP(CDlgPPTSendToRem, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton_FIO1)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton_AddTl)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton_remove)
END_MESSAGE_MAP()


// CDlgPPTSendToRem message handlers

BOOL CDlgPPTSendToRem::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB );

	m_List.InsertColumn(0, "№ тележки", LVCFMT_LEFT, 80);
	m_List.InsertColumn(1, "Пробег", LVCFMT_LEFT, 80);
	m_List.InsertColumn(2, "Надрессорная балка", LVCFMT_LEFT, 80);
	m_List.InsertColumn(3, "Левая боковая рама", LVCFMT_LEFT, 80);
	m_List.InsertColumn(4, "Правая боковая рама", LVCFMT_LEFT, 80);
	m_List.InsertColumn(5, "Дата поступления", LVCFMT_LEFT, 80);
	m_List.InsertColumn(6, "От предприятия", LVCFMT_LEFT, 80);

	m_Dat1.SetMode(1,1);
	m_FIO1.SetMode(5,1);

	DBW.FillEmplArray(m_FIO1.lpEmpl, 16);

	m_EdTlNum.QInit(140, 1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgPPTSendToRem::OnBnClickedButton_FIO1()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 16;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_FIO1.SetData(Dlg.dwFio);
	m_FIO1.SetWindowText(Dlg.cFio);
}

void CDlgPPTSendToRem::OnBnClickedButton_AddTl()
{
	if( m_EdTlNum.isNull() )
	{
		AfxMessageBox("Необходимо указать номер тележки!");
		m_EdTlNum.SetFocus();
		return;
	}
	if( m_Dat1.isNull() )
	{
		AfxMessageBox("Необходимо указать дату!");
		m_Dat1.SetFocus();
		return;
	}
	char cText[640] = "";
	for( int i=0; i < m_List.GetItemCount(); i++ )
	{
		m_List.GetWindowText(cText, 64);
		if( !strcmp(cText, m_EdTlNum.GetAsString()) )
		{
			AfxMessageBox("Указанная тележка уже есть в списке!");
			return;
		}
	}
	char cQ[512] = "";	
	long Ind = 0;
	long rez = 0;
	__int64 qwNum = 0;
	sprintf( cQ, "pTov_pptGetTL1067ForRash %u, %s, %s",
			g_iDep,
			isNull(m_EdTlNum.GetAsString()),
			m_Dat1.GetSQLDate());
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SLONG, &rez, 64, &Ind);
	if( rez == -1 )
	{
		DBW.GetData(2, SQL_C_CHAR, cText, 640, &Ind);
		AfxMessageBox(cText);
		DBW.CloseCursor();
		m_EdTlNum.SetWindowText("");
		m_EdTlNum.SetFocus();
		return;
	}
	int idx = m_List.GetItemCount();
	DBW.GetData(2, SQL_C_UBIGINT, &qwNum, 8, &Ind);
	if( Ind != -1)
	{
		m_List.InsertItem(idx, "");		
		m_List.qwSetItemData(idx, qwNum);
	}
	DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 )
	{
		m_List.SetItemText(idx, 0, cText);
	}
	DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
	{
		m_List.SetItemText(idx, 1, cText);
	}
	DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind);
	{
		m_List.SetItemText(idx, 2, cText);
	}
	DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind);
	{
		m_List.SetItemText(idx, 3, cText);
	}
	DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind);
	{
		m_List.SetItemText(idx, 4, cText);
	}
	DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind);
	{
		m_List.SetItemText(idx, 5, cText);
	}
	DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind);
	{
		m_List.SetItemText(idx, 6, cText);
	}
	DBW.CloseCursor();
	m_EdTlNum.SetFocus();
	m_EdTlNum.SetWindowText("");
}

void CDlgPPTSendToRem::OnBnClickedOk()
{
	char cQ[512] = "";
	char cDat[16] = "";
	char cNTL[32] = "";

	if( m_FIO1.isNull() )
	{
		AfxMessageBox("Необходимо указать фамилию бригадира!");
		m_FIO1.SetFocus();
		return;
	}
	
	for( int i=0; i < m_List.GetItemCount() && i < 150; i++ )
	{
/*		m_List.GetItemText(0, cNTL, 32);
		m_List.GetItemText(1, */
		sprintf( cQ, "pTov_RashodTLppt %s, %s, %s",
				 isNull(m_List.qwGetItemData(i)),
				 m_Dat1.GetSQLDate(),
				 isNull(m_FIO1.GetData()));
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();
	}
	OnOK();
}

void CDlgPPTSendToRem::OnBnClickedButton_remove()
{
	if(m_List.GetSelectionMark() == -1) return;
	if( AfxMessageBox("Сейчас тележка будет удалена. Продолжить?", MB_YESNO) ==IDNO) return;
	m_List.DeleteItem(m_List.GetSelectionMark());
}

void CDlgPPTSendToRem::OnCancel()
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;	
	CDlgWithAccelerators::OnCancel();	
}
