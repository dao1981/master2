// DlgMakeLK_KPOrder.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMakeLK_KPOrder.h"
#include "DlgSpravKdr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgMakeLK_KPOrder dialog


CDlgMakeLK_KPOrder::CDlgMakeLK_KPOrder(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMakeLK_KPOrder::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMakeLK_KPOrder)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
    ReOrd = 0;
    qwILK = 0;
    bGotOrder = FALSE;
}


void CDlgMakeLK_KPOrder::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMakeLK_KPOrder)
	DDX_Control(pDX, IDC_EDIT2, m_EdFam);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_EDIT1, m_EdNum);
	DDX_Control(pDX, IDOK, m_ButOK);
	DDX_Control(pDX, IDCANCEL, m_ButCancel);
	DDX_Control(pDX, IDC_BUTTON1, m_ButReord);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMakeLK_KPOrder, CDialog)
	//{{AFX_MSG_MAP(CDlgMakeLK_KPOrder)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton_ReOrder)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit)
	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnClickList)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList)
	ON_EN_SETFOCUS(IDC_EDIT1, OnSetfocusEditNum)
	ON_BN_CLICKED(IDC_BUTTON3, OnButtonFam)
	ON_BN_CLICKED(IDOK, OnNext)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMakeLK_KPOrder message handlers

void CDlgMakeLK_KPOrder::OnButton_ReOrder() 
{
    bGotOrder = FALSE;
    if( !ReOrd )
    {
	    ReOrd = 1;
        m_ButReord.SetWindowText("Отменить перенумерацию");
        m_ButOK.EnableWindow(FALSE);
        m_ButCancel.EnableWindow(FALSE);
//        m_EdNum.EnableWindow();        
        m_EdNum.SetWindowText("1");
        iCurrentNum = 1;
        iCurrentKP = 0;
        ResetList();
    } else
    {
	    ReOrd = 0;
        m_ButReord.SetWindowText("Изменить порядок КП");
        m_ButOK.EnableWindow();
        m_ButCancel.EnableWindow();
//        m_EdNum.EnableWindow(FALSE);
        m_EdNum.SetWindowText("");
//        ResetList();
    }
}

BOOL CDlgMakeLK_KPOrder::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );    

//    m_EdNum.EnableWindow(FALSE);
    m_EdFam.SetMode(5);
    DBW.FillEmplArray(m_EdFam.lpEmpl, 10);
    CString sQ; 
    __int64 qwNum = 0;
    long Ind = 0;
    DWORD   dwPos = 0;
    char cText[64] = "";
    sQ.Format("pTov_LkGetKP %I64u", qwILK);
    DBW.ExecSQL(sQ);
    DBW.SetListHeader(&m_List);
    DBW.UpdateListByHandle(&m_List, &dwPos, false, true);
    DBW.CloseCursor();
    m_EdNum.ModifyStyle(0, WS_DISABLED);
    m_List.nSortedCol = 1;
    m_List.SortList();
    if( m_List.GetItemText(0, 0) != "" ) bGotOrder = TRUE;
    if( dwFamID ) m_EdFam.SetFamTextByID(dwFamID);
    iCurrentNum = 1;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMakeLK_KPOrder::OnChangeEdit() 
{
    /*
    CString str;
    m_EdNum.GetWindowText(str);
    int num = atoi(str);
    if( num < 1 || num > 8 ) 
    {
        m_EdNum.SetWindowText("");
        return;
    }
    */
}

void CDlgMakeLK_KPOrder::OnClickList(NMHDR* pNMHDR, LRESULT* pResult) 
{
    int Index = m_List.GetSelectionMark();
    if( Index == -1 ) return;
    char cText[64] = "";
    itoa(iCurrentNum, cText, 10);
    m_List.SetItemText(Index, 1, cText);
    iCurrentNum++;
    if( iCurrentNum == 9 )
    {
        OnButton_ReOrder();
    }
	*pResult = 0;
}

void CDlgMakeLK_KPOrder::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{

	int Index = m_List.GetSelectionMark();
    if( Index == -1 || ReOrd != 1 || !m_List.isItemEnabled(Index)) return;
    char cText[64] = "";
    itoa(iCurrentNum, cText, 10);
    m_List.SetItemText(Index, 1, cText);
    int iT = (iCurrentNum + 1)/2;
    itoa(iT, cText, 10);
    m_List.SetItemText(Index, 0, cText);
    m_List.EnableItem(Index, FALSE);
    m_List.nSortedCol = 1;
    m_List.SortList();
    iCurrentNum++;
    if( iCurrentNum > iOsCount )
    {
        OnButton_ReOrder();
        bGotOrder = TRUE;
    } else
    {
        itoa(iCurrentNum, cText, 10);
        m_EdNum.SetWindowText(cText);
    }
	*pResult = 0;
}

void CDlgMakeLK_KPOrder::ResetList()
{
    for( int i=0; i < m_List.GetItemCount(); i++ )
    {
        m_List.SetItemText(i, 0, "");
        m_List.SetItemText(i, 1, "N/A");
        m_List.EnableItem(i);
    }
    m_List.RedrawWindow();
}

void CDlgMakeLK_KPOrder::OnSetfocusEditNum() 
{
    if( ReOrd == 1 ) ReOrd = 2;
    else return;
}

void CDlgMakeLK_KPOrder::OnButtonFam() 
{
    CDlgSpravKdr Dlg;
    Dlg.DlgMode = 1;
    Dlg.iFilter = 10;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdFam.SetFamTextByID(Dlg.dwFio);
    m_EdFam.SetData(Dlg.dwFio);
}

void CDlgMakeLK_KPOrder::OnNext() 
{
    if(	!bGotOrder ) 
    {
        AfxMessageBox("Необходимо указать порядок КП!");
        return;
    }
    if( !m_EdFam.GetData() )
    {
        AfxMessageBox("Необходимо указать фамилию мастера!");
        return;
    }
    for( int i=0; i < iOsCount && i < 8; i++ )
    {
        p_qwIZAP[i] = m_List.qwGetItemData(i);
    }
    CDialog::OnOK();
}
