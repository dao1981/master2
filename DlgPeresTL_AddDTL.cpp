// DlgPeresTL_AddDTL.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPeresTL_AddDTL.h"
#include "DlgSprav1.h"

// CDlgPeresTL_AddDTL dialog

IMPLEMENT_DYNAMIC(CDlgPeresTL_AddDTL, CDialog)

CDlgPeresTL_AddDTL::CDlgPeresTL_AddDTL(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPeresTL_AddDTL::IDD, pParent)
{
	iTypeDTL = 1;
	DlgStarted = 0;
}

CDlgPeresTL_AddDTL::~CDlgPeresTL_AddDTL()
{
}

void CDlgPeresTL_AddDTL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT74, m_EdNDtl);
	DDX_Control(pDX, IDC_EDIT71, m_EdDat);
	DDX_Control(pDX, IDC_EDIT119, m_EdKlPr);
	DDX_Control(pDX, IDC_EDIT120, m_EdPrName);
}


BEGIN_MESSAGE_MAP(CDlgPeresTL_AddDTL, CDialog)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgPeresTL_AddDTL::OnBnClickedButtonSelPr)
	ON_EN_CHANGE(IDC_EDIT119, &CDlgPeresTL_AddDTL::OnEnChangeEditKLPR)
	ON_BN_CLICKED(IDOK, &CDlgPeresTL_AddDTL::OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgPeresTL_AddDTL message handlers

BOOL CDlgPeresTL_AddDTL::OnInitDialog()
{
	CDialog::OnInitDialog();

	if( iTypeDTL == 2) SetWindowText("Надрессорная балка");
	else SetWindowText("Боковая рама");

	m_EdNDtl.QInit(100, 1);
	m_EdDat.QInit(40, 1);
	m_EdKlPr.QInit(60, 1);
	m_EdPrName.ModifyStyle(0, WS_DISABLED, 0);;

	DlgStarted = 1;
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgPeresTL_AddDTL::OnBnClickedButtonSelPr()
{
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 8;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdKlPr.SetWindowText(Dlg.cKodPr);	
    m_EdPrName.SetWindowText(Dlg.cPrName);
	m_EdKlPr.SetData(Dlg.ret_dwIPR);
}

void CDlgPeresTL_AddDTL::OnEnChangeEditKLPR()
{
    if( !DlgStarted ) return;
    char cText[64] = "";
    char cQ[64] = "";
	DWORD dwNum = 0;
    long Ind = 0;

    m_EdKlPr.GetWindowText(cText, 64);
    sprintf(cQ, "pTov_GetPredByKl '%s'", cText);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    m_EdPrName.SetWindowText("");
    if( g_sqlret == SQL_NO_DATA ||
        g_sqlret == SQL_ERROR )
    {
        DBW.CloseCursor();
        return;
    }
    DBW.GetData( 1, SQL_C_CHAR, cText, 64, &Ind);
    DBW.GetData( 2, SQL_C_SLONG, &dwNum, 4, &Ind);
	m_EdKlPr.SetData(dwNum);
    DBW.CloseCursor();
    m_EdPrName.SetWindowText(cText);
}

void CDlgPeresTL_AddDTL::OnBnClickedOk()
{
//	m_EdNDtl.GetWindowText(cDTlNum, 10);
	m_EdDat.GetWindowText(cYear, 5);
//	m_EdKlPr.GetWindowText(cKlPr, 16);
	m_EdPrName.GetWindowText(cPrName, 40);
	dwIPR = m_EdKlPr.GetData();
	
	strncpy(cDTlNum, m_EdNDtl.GetString(), 10);
	strncpy(cKlPr, m_EdKlPr.GetString(), 5);

	if( !cDTlNum[0] )
	{
		AfxMessageBox("Необходимо указать заводской номер детали");
		m_EdNDtl.SetFocus();
		return;

	}
	if( !cYear[0] )
	{
		AfxMessageBox("Необходимо указать год выпуска детали");
		m_EdDat.SetFocus();
		return;

	}
	if( atoi(cYear) < 1800 || atoi(cYear) > 2020 ) 
	{
		AfxMessageBox("Год выпуска детали указан некорректно");
		m_EdDat.SetFocus();
		return;

	}

	if( !dwIPR )
	{
		AfxMessageBox("Необходимо указать предприятие производителя");
		m_EdKlPr.SetFocus();
		return;
	}
	OnOK();
}

