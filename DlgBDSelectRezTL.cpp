// DlgBDSelectRezTL.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgBDSelectRezTL.h"
#include ".\dlgbdselectreztl.h"
#include "DlgRegisterTL.h"
#include "PrintableDlg.h"

extern int g_iReportGridFontSize;
extern char g_cReportGridFontFace[64];
// CDlgBDSelectRezTL dialog

IMPLEMENT_DYNAMIC(CDlgBDSelectRezTL, CDialog)
CDlgBDSelectRezTL::CDlgBDSelectRezTL(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBDSelectRezTL::IDD, pParent)
{
	bGotHeader = 0;
	Font = NULL;
	cQ[0] = 0;
}

CDlgBDSelectRezTL::~CDlgBDSelectRezTL()
{
}

void CDlgBDSelectRezTL::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_STATIC_X, m_lbRecCount);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}


BEGIN_MESSAGE_MAP(CDlgBDSelectRezTL, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton_EditTL)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton_DeleteTL)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton_AddTl)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton_PasportTL)
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEditNTl)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgBDSelectRezTL message handlers

BOOL CDlgBDSelectRezTL::OnInitDialog()
{
	CDialog::OnInitDialog();
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

	LOGFONT lf;
    ZeroMemory(&lf, sizeof(lf));
    lf.lfHeight = g_iReportGridFontSize;
    lf.lfCharSet = RUSSIAN_CHARSET;
	strcpy(lf.lfFaceName, g_cReportGridFontFace);
    Font = new CFont;
    VERIFY(Font->CreateFontIndirect(&lf));
	m_List.SetFont(Font);

	bGotHeader = false;
    RefreshList();
    m_List.SetSelectionMark(0);
    bGotHeader = true;

	m_Edit.SetMode(0, 1, 12);
/*
	if( iMode == 3 ) //Тележки
	{
		m_ButPerech.ModifyStyle(WS_VISIBLE, 0);
        m_ButHistory.ModifyStyle(WS_VISIBLE, 0);
		m_ButRemoveKP.ModifyStyle(WS_VISIBLE, 0);
		m_ButMkPasp.ModifyStyle(WS_VISIBLE, 0);
	}
*/

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgBDSelectRezTL::RefreshList(void)
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

void CDlgBDSelectRezTL::OnBnClickedButton_EditTL()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;

	CDlgRegisterTL Dlg;
	Dlg.qwTL_ID = m_List.qwGetItemData(idx);
	Dlg.iMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	RefreshList();
}

void CDlgBDSelectRezTL::OnBnClickedButton_DeleteTL()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;

	char cQ[512] = "";
	sprintf(cQ, "pTov_DeleteTLppt %I64u", m_List.qwGetItemData(idx));
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
//	RefreshList();
	m_List.DeleteItem(idx);
	
	char cText[64] = "";
	itoa(m_List.GetItemCount(), cText, 10);
	m_lbRecCount.SetWindowText(cText);

}

void CDlgBDSelectRezTL::OnBnClickedButton_AddTl()
{
	CDlgRegisterTL Dlg;
	if( Dlg.DoModal() == IDCANCEL && !Dlg.iSomeAdded) 
	{
		return;
	}
	RefreshList();
}

void CDlgBDSelectRezTL::OnBnClickedButton_PasportTL()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;

	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_mkcReportPaspTLppt %I64u", m_List.qwGetItemData(idx));
	Dlg.DoModal();
}

int last_marked = 0;
char last_text[64] = "";
void CDlgBDSelectRezTL::OnEnChangeEditNTl()
{
	char cText[64] = "";
	char cNum[64] = "";

	m_Edit.GetWindowText(cNum, 64);
	m_List.SetMarkedItem(last_marked, 0);
	m_List.RedrawItems(last_marked, last_marked);
	for( int i=0; i < m_List.GetItemCount(); i++ )
	{
		m_List.GetItemText(i, 0, cText, 64);
		if( strncmp(cText, cNum, strlen(cNum)) == 0 )
		{
			m_List.SetSelectionMark(i);
			m_List.SetMarkedItem(i);
			last_marked = i;
			m_List.EnsureVisible(i, 0);
			m_List.RedrawItems(i, i);
			strcpy(last_text, cNum);
//			m_List.RedrawWindow();
			return;
		}
	}
	m_Edit.SetWindowText(last_text);
	m_Edit.SetSel(strlen(last_text), strlen(last_text), 0);
	m_List.RedrawWindow();
}

void CDlgBDSelectRezTL::OnBnClickedCancel()
{
	if( AfxMessageBox("Закрыть форму?", MB_YESNO) == IDNO) return;
	OnCancel();
}

void CDlgBDSelectRezTL::OnBnClickedOk()
{
	if( AfxMessageBox("Закрыть форму?", MB_YESNO) == IDNO) return; 
	OnOK();
}
