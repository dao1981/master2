// DlgDepSelect.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgDepSelect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgDepSelect dialog


CDlgDepSelect::CDlgDepSelect(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDepSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDepSelect)
	//}}AFX_DATA_INIT
	iMode = 0;
	dwMainDep = 0;
}


void CDlgDepSelect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDepSelect)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDepSelect, CDialog)
	//{{AFX_MSG_MAP(CDlgDepSelect)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList1)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CDlgDepSelect::OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDepSelect message handlers

BOOL CDlgDepSelect::OnInitDialog() 
{
	CDialog::OnInitDialog();
    wDep = 0;
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

	if(!iMode ) DBW.ExecSQL("pTov_GetAllDepts");
	else
	{
		char cQ[128] = "";
		sprintf(cQ, "pTov_GetAllSubDepts %u", dwMainDep);
		DBW.ExecSQL(cQ);
	}
    DBW.SetListHeader(&m_List);
    DBW.UpdateListByHandle(&m_List);
    m_List.SetColumnWidth(0, 70);
    m_List.SetColumnWidth(1, 70);
    m_List.SetColumnWidth(2, 250);
    m_List.SetColumnWidth(3, 170);
    
    DBW.CloseCursor();

	if( m_List.GetItemCount() == 1 )
	{
		m_List.SetSelectionMark(0);
		OnOK();
	}

	return TRUE;
}

void CDlgDepSelect::OnOK()
{
    char cText[64] = "";
    int Index = m_List.GetSelectionMark();
    if( Index < 0 )
    {
        MessageBox("Необходимо выбрать хотя бы одно значение из списка!", "МКЦ", MB_OK | MB_ICONINFORMATION);
        return;
    }
    m_List.GetItemText(Index ,0, cText, 64);
    wDep = atoi(cText);
    char cQ[512] = "";
    sprintf(cQ, "pTov_CheckDepExistsByID %u", wDep);
    DBW.ExecSQL(cQ);
	cText[0] = 0;
	long Ind = 0;
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
	DBW.WriteLog(cText);
    DBW.CloseCursor();
    DBW.ReallocHandle();
	CDialog::OnOK();
}

void CDlgDepSelect::OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
    OnOK();
	*pResult = 0;
}

void CDlgDepSelect::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CDlgDepSelect::OnCancel()
{
	// TODO: Add your specialized code here and/or call the base class

	//CDialog::OnCancel();
}
