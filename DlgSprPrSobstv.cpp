// DlgSprPrSobstv.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSprPrSobstv.h"
#include "DlgSprPrSobstvAdd.h"

// CDlgSprPrSobstv dialog

IMPLEMENT_DYNAMIC(CDlgSprPrSobstv, CDialog)

CDlgSprPrSobstv::CDlgSprPrSobstv(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSprPrSobstv::IDD, pParent)
{
	iGotHeader = 0;
	iNeedOKButton = 1;
	dwSobstID = 0;
	cPrName[0] = 0;
}

CDlgSprPrSobstv::~CDlgSprPrSobstv()
{
}

void CDlgSprPrSobstv::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDOK, m_ButAdd);
	DDX_Control(pDX, IDC_BUTTON1, m_ButEdit);
	DDX_Control(pDX, IDC_BUTTON2, m_ButDel);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDOK2, m_ButOK);
}


BEGIN_MESSAGE_MAP(CDlgSprPrSobstv, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgSprPrSobstv::OnBnClickedAddPr)
	ON_BN_CLICKED(IDC_BUTTON1, &CDlgSprPrSobstv::OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgSprPrSobstv::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDOK2, &CDlgSprPrSobstv::OnBnClickedOk2)
	ON_NOTIFY(HDN_ITEMDBLCLICK, 0, &CDlgSprPrSobstv::OnHdnItemdblclickList1)
END_MESSAGE_MAP()


// CDlgSprPrSobstv message handlers
extern WORD g_iRang;

BOOL CDlgSprPrSobstv::OnInitDialog()
{
	CDialog::OnInitDialog();

	if( g_iRang < 4 )
	{
		m_ButAdd.EnableWindow(0);
		m_ButEdit.EnableWindow(0);
		m_ButDel.EnableWindow(0);
	}

	if( !iNeedOKButton ) m_ButOK.ModifyStyle(WS_VISIBLE, 0);

	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

	RefreshList();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgSprPrSobstv::RefreshList(void)
{
	char cQ[128] = "";
	DWORD dwIDPos = 0;
	sprintf(cQ, "pTov_SobstvGetAll" );
	DBW.ExecSQL(cQ);
	if( !iGotHeader )
	{
		iGotHeader = 1;
		DBW.SetListHeader(&m_List);
		m_List.SetColumnWidth(0, 250);
	}
	DBW.UpdateListByHandle(&m_List, &dwIDPos, 1);
	DBW.CloseCursor();

}

void CDlgSprPrSobstv::OnBnClickedAddPr()
{
	CDlgSprPrSobstvAdd Dlg;
	Dlg.iMode = 0;
	if( Dlg.DoModal() == IDCANCEL ) return;

	RefreshList();
//	OnOK();
}

void CDlgSprPrSobstv::OnBnClickedButtonEdit()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;
	CDlgSprPrSobstvAdd Dlg;
	Dlg.iMode = 1;
	Dlg.dwPrID = m_List.GetItemData(idx);
	if( Dlg.DoModal() == IDCANCEL ) return;

	RefreshList();
}

void CDlgSprPrSobstv::OnBnClickedButtonDelete()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;

	if( MessageBox("Вы действительно хотите удалить выбранное предприятие?", 0, MB_YESNO) == IDNO )
		return;

	char cQ[128] = "";
	sprintf(cQ, "pTov_SobstvPrDelete %d", m_List.GetItemData(idx));
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();

	RefreshList();
}

void CDlgSprPrSobstv::OnBnClickedOk2()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) 
	{
		AfxMessageBox("Необходимо выбрать предприятие из списка!");
		return;
	}
	dwSobstID = m_List.GetItemData(idx);
	m_List.GetItemText(idx, 0, cPrName, 80);
	m_List.GetItemText(idx, 3, cKlPr, 64);
	m_List.GetItemText(idx, 2, cOKPO, 64);

	OnOK();
}

void CDlgSprPrSobstv::OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	*pResult = 0;
	if( iNeedOKButton )OnBnClickedOk2();
	else OnBnClickedButtonEdit();
}
