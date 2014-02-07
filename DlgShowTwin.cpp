// DlgShowTwin.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgShowTwin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <sqlext.h>
#include "PrintableDlg.h"
#include ".\dlgshowtwin.h"

extern SQLRETURN    g_sqlret;

extern CMasterApp theApp;
extern DWORD       g_iDep;
extern int	g_EnableObiedDvButton;
/////////////////////////////////////////////////////////////////////////////
// CDlgShowTwin dialog


CDlgShowTwin::CDlgShowTwin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgShowTwin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgShowTwin)
	//}}AFX_DATA_INIT
    cTKP[0]=0;
    cNKP[0]=0;
    dwTKP = 0;
    iZp = iFo = 0;
    qwIKP = 0;
    iRez = 0;
}


void CDlgShowTwin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgShowTwin)
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_EDIT2, m_TKP);
	DDX_Control(pDX, IDC_EDIT1, m_NKP);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_BUTTON3, m_ButIntergrTwin);
}


BEGIN_MESSAGE_MAP(CDlgShowTwin, CDialog)
	//{{AFX_MSG_MAP(CDlgShowTwin)
	ON_BN_CLICKED(IDC_BUTTON1, OnAddNewTwinClick)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClicked_V_ODNU)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgShowTwin message handlers

BOOL CDlgShowTwin::OnInitDialog() 
{
	CDialog::OnInitDialog();
    DWORD dwNum = 0;
	m_NKP.SetWindowText(cNKP);
    m_TKP.SetWindowText(cTKP);
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );
    char cQ[512] = "";
    sprintf(cQ, "pTov_GetKPByNKP '%s', %u", cNKP, dwTKP);
    DBW.ExecSQL(cQ);
    DBW.SetListHeader(&m_List);
    DBW.UpdateListByHandle(&m_List, &dwNum);
    DBW.CloseCursor();
	if( !g_EnableObiedDvButton ) m_ButIntergrTwin.ModifyStyle(WS_VISIBLE, 0);
//    m_List.SetSelectionMark(0);
	return TRUE;
}

void StrToDate(char *Str, SYSTEMTIME *Date)
{
        char    cStr[12]="";
//        m_List.GetItemText(Idx, 0, Pasp.cIZOS_PR, 32);
        
        cStr[0] = Str[0];
        cStr[1] = Str[1];
        cStr[2] = 0;
        Date->wDay = atoi(cStr);

        cStr[0] = Str[3];
        cStr[1] = Str[4];
        cStr[2] = 0;
        Date->wMonth = atoi(cStr);

        cStr[0] = Str[6];
        cStr[1] = Str[7];
        cStr[2] = Str[8];
        cStr[3] = Str[9];
        cStr[4] = 0;
        Date->wYear = atoi(cStr);
}

void CDlgShowTwin::OnOK() 
{
//    char cText[64] = "";
//    m_List.GetItemText(m_List.GetSelectionMark(), 11, cText, 64);
    qwIKP = m_List.GetItemData(m_List.GetSelectionMark());
	CDialog::OnOK();
}

void CDlgShowTwin::OnAddNewTwinClick() 
{
    iRez = 1;
    CDialog::OnOK();
}

void CDlgShowTwin::OnButton2() //Паспорт
{
	CPrintableDlg Dlg;
    if(m_List.GetSelectionMark() < 0 ) return;    
    sprintf(Dlg.cQ, "pTov_GetPaspByIKP %u", m_List.GetItemData(m_List.GetSelectionMark()));
    if( Dlg.DoModal() == IDCANCEL ) return;
}

void CDlgShowTwin::OnBnClicked_V_ODNU()
{
	if( m_List.GetSelectionMark() < 0 ) 
	{
		AfxMessageBox("Необходимо выбрать КП!");
		return;
	}
	char cScript[1000] = "";
	sprintf( cScript, "begin tran\ndeclare @IKP1 bigint\nset @IKP1=%s\n\n",
		isNull(m_List.GetItemData(m_List.GetSelectionMark())));

	for( int i=0; i < m_List.GetItemCount(); i++ )
	{
		if( i != m_List.GetSelectionMark() && m_List.GetCheck(i) )
			sprintf( cScript, "%s exec pTov_DeleteIKP @IKP1, %s\n",
			cScript,
			isNull(m_List.GetItemData(i)));
	}
	sprintf( cScript, "%s\ncommit tran", cScript);
	DBW.ExecSQL(cScript);
	OnOK();
}
