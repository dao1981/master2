// DlgDisplRP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgDisplRP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include <sqlext.h>

extern CMasterApp   theApp;
extern SQLRETURN    g_sqlret;

/////////////////////////////////////////////////////////////////////////////
// CDlgDisplRP dialog


CDlgDisplRP::CDlgDisplRP(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgDisplRP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDisplRP)
	//}}AFX_DATA_INIT
}


void CDlgDisplRP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDisplRP)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgDisplRP, CDialog)
	//{{AFX_MSG_MAP(CDlgDisplRP)
	ON_BN_CLICKED(IDOK, OnChangeZap)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDisplRP message handlers

BOOL CDlgDisplRP::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

    char cQ[255] = "";
    strncpy(cQ, "pTov_GetAllRP", 255);
    DBW.ExecSQL(cQ);
    DBW.SetListHeader(&m_List);
    DBW.UpdateListByHandle(&m_List);
    DBW.CloseCursor();
	return TRUE;  
}

void CDlgDisplRP::OnChangeZap() 
{
    
}
