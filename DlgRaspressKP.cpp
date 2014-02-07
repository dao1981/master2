// DlgRaspressKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRaspressKP.h"
#include ".\dlgraspresskp.h"
#include "DlgSpravKdr.h"


// CDlgRaspressKP dialog

IMPLEMENT_DYNAMIC(CDlgRaspressKP, CDialog)
CDlgRaspressKP::CDlgRaspressKP(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRaspressKP::IDD, pParent)
{
	iGotHeader1 = 0;
	iGotHeader2 = 0;
	iOldKPCount = 0;
	iStarted = 0;
	iEdFocused = 0;
}

CDlgRaspressKP::~CDlgRaspressKP()
{
}

void CDlgRaspressKP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat);
	DDX_Control(pDX, IDC_EDIT2, m_EdFam);
	DDX_Control(pDX, IDC_LIST2, m_List1);
	DDX_Control(pDX, IDC_LIST3, m_List2);
	DDX_Control(pDX, IDC_EDIT7, m_EdKPNum);
	DDX_Control(pDX, IDC_STATIC11, m_Num1);
	DDX_Control(pDX, IDC_STATIC12, m_Num2);
	DDX_Control(pDX, IDC_BUTTON2, m_ButSelect);
	DDX_Control(pDX, IDC_BUTTON3, m_ButAdd);
	DDX_Control(pDX, IDC_BUTTON1, m_ButFam);
}


BEGIN_MESSAGE_MAP(CDlgRaspressKP, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_LIST2, OnLvnItemActivateList2)
	ON_NOTIFY(HDN_ITEMCLICK, 0, OnHdnItemclickList2)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
//	ON_EN_CHANGE(IDC_EDIT7, OnEnChangeEdit7)
	ON_EN_SETFOCUS(IDC_EDIT7, OnEnSetfocusEditKPNum)
	ON_EN_KILLFOCUS(IDC_EDIT7, OnEnKillfocusEdit7)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButtonLOG)
//	ON_BN_SETFOCUS(IDC_BUTTON2, OnBnSetfocusButtonSelect)
	ON_WM_GETDLGCODE()
//    ON_WM_KEYDOWN()
END_MESSAGE_MAP()



UINT CDlgRaspressKP::OnGetDlgCode() 
{
    return DLGC_WANTALLKEYS | DLGC_HASSETSEL;
}


/*
void CDlgRaspressKP::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
/*
	if (nChar == VK_TAB && GetKeyState(VK_SHIFT) & KF_UP)
    {
		AfxMessageBox("tab");
        // Process Shift+Tab keys
        MessageBeep(0);            //  Do nothing  - sample  code
    }
    else if (nChar == VK_RETURN)
    {       
		AfxMessageBox("enter");
        // Process Enter key
        MessageBeep(0);            //  Do nothing  - sample  code
    }
    else if (nChar == VK_TAB)
    {
		AfxMessageBox("tab2");
        // Process Tab key
        MessageBeep(0);            //  Do nothing  - sample  code
    }        
   
	CDlgWithAccelerators::OnKeyDown(nChar, nRepCnt, nFlags);
}
*/
// CDlgRaspressKP message handlers

BOOL CDlgRaspressKP::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Dat.InitDate();
	m_EdFam.SetMode(5);
	m_EdKPNum.SetMode(5);
//	m_EdKPNum.SetMode(0, 1, 10);
	DBW.FillEmplArray(m_EdFam.lpEmpl, 41);
	
    m_List1.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List1.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );    

    m_List2.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List2.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );    

	RefreshKPList();
	RefreshRightList();

	char cText[64] = "";
	itoa(m_List1.GetItemCount(), cText, 10);
	m_Num1.SetWindowText(cText);

	iStarted = 1;
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgRaspressKP::OnBnClickedButton1()
{
    CDlgSpravKdr Dlg;
    Dlg.iFilter = 41;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdFam.SetData(Dlg.dwFio);
    m_EdFam.SetWindowText(Dlg.cFio);}

void CDlgRaspressKP::RefreshKPList(void)
{
	char cQ[128] = "";
	DWORD dwIzapRow = 0;
	sprintf(cQ, "pTov_GetNKPforRaspres %d, %s", g_iDep, m_Dat.GetSQLDate());
	DBW.ExecSQL(cQ);
	if( !iGotHeader1 )
	{
		iGotHeader1 = 1;
		DBW.SetListHeader(&m_List1);
	}
	DBW.UpdateListByHandle(&m_List1, &dwIzapRow, 1, 1);
	DBW.CloseCursor();
/*	m_List1.SetColumnWidth(0, 100);
	m_List1.SetColumnWidth(1, 70);*/

	char cText[64] = "";
	itoa(m_List1.GetItemCount(), cText, 10);
	m_Num1.SetWindowText(cText);
	m_EdKPNum.SetWindowText("");

	m_EdKPNum.lpEmpl->Clear();
	for( int i=0; i < m_List1.GetItemCount(); i++ )
	{
		m_List1.GetItemText(i, 0, cText, 64);
		m_EdKPNum.lpEmpl->AddEmployee(1, cText, 0);
	}
}

void CDlgRaspressKP::OnBnClickedButton2()
{
/*	m_EdFam.EnableWindow(1);
	m_ButFam.EnableWindow(1);*/
	if( iEdFocused )
	{
//		AfxMessageBox("dont fuck with me!");
		return;
	}
	RefreshKPList();
	RefreshRightList();
	m_List1.RedrawWindow();
}

void CDlgRaspressKP::OnLvnItemActivateList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
	
	char cText[64] = "";
	m_List1.GetItemText(m_List1.GetSelectionMark(), 0, cText, 64);
	m_EdKPNum.SetWindowText(cText);
	OnBnClickedButtonAdd();
// DBL CLICK

	*pResult = 0;
}

void CDlgRaspressKP::OnHdnItemclickList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
//	AfxMessageBox("!");
	*pResult = 0;
}

void CDlgRaspressKP::RefreshRightList(void)
{
	char cQ[128] = "";
	DWORD dwIzapRow = 0;
	sprintf(cQ, "pTov_GetRaspresKPList %d, %s, %s", g_iDep, m_Dat.GetSQLDate(), isNull(m_EdFam.GetData()));
	DBW.ExecSQL(cQ);
	if( !iGotHeader2 ) 
	{
		DBW.SetListHeader(&m_List2);
		iGotHeader2 = 1;
	}
	DBW.UpdateListByHandle(&m_List2, &dwIzapRow, 1);
	DBW.CloseCursor();
/*	m_List2.SetColumnWidth(0, 100);
	m_List2.SetColumnWidth(1, 70);*/

	char cText[64] = "";
/*	itoa(m_List2.GetItemCount(), cText, 10);
	m_Num1.SetWindowText(cText);
	m_EdKPNum.SetWindowText("");
*/
	for( int i=0; i < m_List2.GetItemCount(); i++ )
		m_List2.EnableItem(i, 0);
	iOldKPCount = m_List2.GetItemCount();

	itoa(iOldKPCount, cText, 10);
	m_Num2.SetWindowText(cText);
}


void CDlgRaspressKP::OnBnClickedButtonAdd()
{
	if( !m_EdFam.GetData() )
	{
		AfxMessageBox("Необходимо указать фамилию слесаря!");
		return;
	}


	int nItems = m_List1.GetItemCount();
	char cText1[64] = "";
	char cText2[64] = "";
	m_EdKPNum.GetWindowText(cText1, 64);
	for( int i=0; i < nItems; i++ )
	{
		m_List1.GetItemText(i, 0, cText2, 64);
		if( !strcmp(cText1, cText2) )
		{
			m_List2.InsertItem(m_List2.GetItemCount(), cText2);
			m_List1.GetItemText(i, 1, cText2, 64);
			m_List2.SetItemText(m_List2.GetItemCount() - 1, 1, cText2);
			
			m_List2.qwSetItemData(m_List2.GetItemCount() - 1, m_List1.qwGetItemData(i));
			m_EdFam.GetWindowText(cText1, 64);
			m_List2.SetItemText(m_List2.GetItemCount() - 1, 3, cText1);
			m_List1.DeleteItem(i);

			itoa(m_List1.GetItemCount(), cText1, 10);
			m_Num1.SetWindowText(cText1);
			itoa(m_List2.GetItemCount(), cText1, 10);
			m_Num2.SetWindowText(cText1);

			lp_dwFam[m_List2.GetItemCount() - 1] = m_EdFam.GetData();

			m_EdKPNum.SetWindowText("");
/*			m_EdFam.EnableWindow(0);
			m_ButFam.EnableWindow(0);*/
			return;
		}
	}
}

void CDlgRaspressKP::OnBnClickedOk()
{
	char cQ[128] = "";
	for( int i=iOldKPCount; i < m_List2.GetItemCount(); i++ )
	{
		sprintf(cQ, "pTov_RaspresKP %s, %s, %s",
			isNull(m_List2.qwGetItemData(i)),
			m_Dat.GetSQLDate(),
			isNull(lp_dwFam[i]));
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();
	}
	OnOK();
}
/*
void CDlgRaspressKP::OnEnChangeEdit7()
{

	if( !iStarted ) return;
	static CString strOldText = "";
	static iOldIndex = -1;
	char cText[64] = "";
	char cText2[64] = "";
	m_EdKPNum.GetWindowText(cText, 64);
	int nCount = m_List1.GetItemCount();
	for( int i = 0; i < nCount; i++ )
	{
		m_List1.GetItemText(i, 0, cText2, 64);
		if( !strncmp(cText, cText2, strlen(cText)) )
		{
			if( iOldIndex != i )
			{
//				m_List1.ClearMark();
				m_List1.SetMarkedItem(iOldIndex, 0);
				m_List1.SetSelectionMark(i);
				m_List1.SetMarkedItem(i, 1);
				m_List1.EnsureVisible(i, 0);
				m_List1.RedrawWindow();
				iOldIndex = i;
			}
			m_EdKPNum.SetWindowText(cText2);
			m_EdKPNum.SetSel(strlen(cText), strlen(cText2), 0);
			strOldText = cText;
			return;
		}
	}
//	m_EdKPNum.SetWindowText(strOldText);
//	m_EdKPNum.SetSel(10);
}
*/
void CDlgRaspressKP::OnEnSetfocusEditKPNum()
{
	iEdFocused = 1;
}

void CDlgRaspressKP::OnEnKillfocusEdit7()
{
	iEdFocused = 0;
//	AfxMessageBox("fuck");
}

void CDlgRaspressKP::OnBnClickedButtonLOG()
{
	if( !m_Dat.isValid() || m_Dat.isNull() ) 
	{
		AfxMessageBox("Необходимо указать дату!");
		m_Dat.SetFocus();
		return;
	}
	char cQ[128] = "";
	sprintf(cQ, "pTov_mkcRepHtmRaspres %d, %s, %s, %s, NULL",
		g_iDep,
		m_Dat.GetSQLDate(),
		m_Dat.GetSQLDate(),
		isNull(m_EdFam.GetData())
		);
	DBW.DisplayHtmlReport(cQ);
}

void CDlgRaspressKP::OnBnSetfocusButtonSelect()
{

}

BOOL CDlgRaspressKP::PreTranslateMessage(MSG* pMsg)
{
	if ( ( pMsg->message == WM_KEYDOWN ) &&
		( pMsg->wParam == VK_RETURN ) )
	{
		if( m_EdKPNum.iActive )
		{
			OnBnClickedButtonAdd();			
			return true;
		} else
		if( m_Dat.iActive )
		{
			OnBnClickedButton2();
			m_EdFam.SetFocus();
			return true;
		} else
		if( m_EdFam.iActive )
		{
			m_EdKPNum.SetFocus();
			return true;
		}
	}
//	m_EdKPNum.SetWindowText("");
	return CDialog::PreTranslateMessage(pMsg);
}
