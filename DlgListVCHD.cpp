// DlgListVCHD.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgListVCHD.h"
#include "PrintableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgListVCHD dialog


CDlgListVCHD::CDlgListVCHD(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgListVCHD::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgListVCHD)
	//}}AFX_DATA_INIT
}


void CDlgListVCHD::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgListVCHD)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgListVCHD, CDialog)
	//{{AFX_MSG_MAP(CDlgListVCHD)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton_ListDiag)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgListVCHD message handlers

BOOL CDlgListVCHD::OnInitDialog() 
{
	CDialog::OnInitDialog();
    DWORD dwPos = 0;
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

    DBW.ExecSQL("pTov_mkcRepSelectListDiagn");
    DBW.SetListHeader(&m_List);
    DBW.UpdateListByHandle(&m_List, &dwPos);
    DBW.CloseCursor();
   
	m_List.SetColumnWidth(1, 60);
	m_List.SetColumnWidth(2, 50);
	m_List.SetColumnWidth(3, 70);
	m_List.SetColumnWidth(4, 110);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgListVCHD::OnButton_ListDiag() 
{
    CPrintableDlg Dlg;
    strcpy(Dlg.cQ, "pTov_mkcReportListDiagn");
    Dlg.DoModal();
}

void CDlgListVCHD::OnOK()  
{
    if( m_List.GetSelectionMark() < 0 )
    {
        AfxMessageBox("Необходимо выбрать предприятие из списка!");
        return;
    }
    g_iDep = (DWORD)m_List.GetItemData(m_List.GetSelectionMark());
    DBW.GetDepoName(g_iDep, g_strDepoName, g_strDepoSName, g_dwTypeDep, g_dwDepoGruzPas);
	CDialog::OnOK();
}

