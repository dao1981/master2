// DlgVagOn1067.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgVagOn1067.h"
#include ".\dlgvagon1067.h"
#include "dlgvagnumtrafaret.h"
#include "DlgVagOn1067Edit.h"
#include "PrintableDlg.h"

// CDlgVagOn1067 dialog
CDlgVagOn1067 *vd = NULL;

int iTimeUpd = 1;

IMPLEMENT_DYNAMIC(CDlgVagOn1067, CDialog)
CDlgVagOn1067::CDlgVagOn1067(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgVagOn1067::IDD, pParent)
{
	iGotHeader = 0;
	iList = -1;
	iStatusWaiting = 0;
}

CDlgVagOn1067::~CDlgVagOn1067()
{
}

VOID CALLBACK TimerRefreshBut( 
    HWND hwnd,        // handle to window for timer messages 
    UINT message,     // WM_TIMER message 
    UINT idTimer,     // timer identifier 
    DWORD dwTime) 
{
	if( iTimeUpd == 0 ) return;
	iTimeUpd = 0;
	vd->UpdButtonStatus();
//	iTimeUpd = 1;
}

void CDlgVagOn1067::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List1);
	DDX_Control(pDX, IDC_LIST2, m_List2);
	DDX_Control(pDX, IDC_STATIC1, m_Num1);
	DDX_Control(pDX, IDC_STATIC2, m_Num2);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag1);
	DDX_Control(pDX, IDC_EDIT2, m_EdNVag2);
	DDX_Control(pDX, IDC_BUTTON5, m_ButUpd);
}


BEGIN_MESSAGE_MAP(CDlgVagOn1067, CDialog)
	ON_NOTIFY(NM_SETFOCUS, IDC_LIST1, OnNMSetfocusList1)
	ON_NOTIFY(NM_SETFOCUS, IDC_LIST2, OnNMSetfocusList2)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnDeleteVag)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, OnEnChangeEdit2)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST2, &CDlgVagOn1067::OnLvnItemchangedList2)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CDlgVagOn1067::OnHdnItemclickList1)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgVagOn1067::OnBnClickedButton_EditVag)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlgVagOn1067::OnBnClickedButton_UpdateAll)
	ON_BN_CLICKED(IDC_BUTTON6, &CDlgVagOn1067::OnBnClickedButton_SpravkaPoAr)
END_MESSAGE_MAP()


// CDlgVagOn1067 message handlers

BOOL CDlgVagOn1067::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_List1.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
	m_List2.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
	m_List1.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );
	m_List2.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

	m_EdNVag1.QInit(80,1);
	m_EdNVag2.QInit(80,1);	
	vd = this;
//	UpdButtonStatus();

	MySetTimer();

	RefreshLists();
	return TRUE;  
}

extern CString toStr(DWORD);

void CDlgVagOn1067::RefreshLists(void)
{
	char cQ[128] = "";
	sprintf(cQ, "pTov_pptSelVagTraf %u", g_iDep);
	DBW.ExecSQL(cQ);
	
	if( !iGotHeader )
	{
		DBW.SetListHeader(&m_List1);
		iGotHeader = 1;
	}
	DWORD dwPos = 0;
	DBW.UpdateListByHandle(&m_List1, &dwPos, false, true);
	DBW.CloseCursor();
	m_Num1.SetWindowText(toStr(m_List1.GetItemCount()));

	if( m_List1.nSortedCol != -1 ) m_List1.SortList();
	if( m_List2.nSortedCol != -1 ) m_List2.SortList();

//***************************************************************
	sprintf(cQ, "pTov_pptSelVagNoTraf %u", g_iDep);
	DBW.ExecSQL(cQ);
	
	if( iGotHeader != 2)
	{
		DBW.SetListHeader(&m_List2);
		iGotHeader = 2;
	}
	dwPos = 0;
	DBW.UpdateListByHandle(&m_List2, &dwPos, false, true);
	DBW.CloseCursor();
	m_Num2.SetWindowText(toStr(m_List2.GetItemCount()));
	
	m_List1.SetColumnWidth(0, 70);
	m_List1.SetColumnWidth(1, 28);
	m_List1.SetColumnWidth(2, 65); // дата
	m_List1.SetColumnWidth(3, 75);
	m_List1.SetColumnWidth(4, 75);
	m_List1.SetColumnWidth(5, 30);


	m_List2.SetColumnWidth(0, 70);
	m_List2.SetColumnWidth(1, 65);
	m_List2.SetColumnWidth(2, 85);
	m_List2.SetColumnWidth(3, 85);
	m_List2.SetColumnWidth(4, 40);

}

void CDlgVagOn1067::OnNMSetfocusList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	iList = 0;
}

void CDlgVagOn1067::OnNMSetfocusList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: Add your control notification handler code here
	*pResult = 0;
	iList = 1;
}

void CDlgVagOn1067::OnBnDeleteVag()
{
	if( iList == -1 || m_List1.GetSelectionMark() == -1 ) return;

	char cQ[128] = "";
	__int64 qwIZap = 0;
	if( iList == 0 )
	{
		qwIZap = m_List1.qwGetItemData(m_List1.GetSelectionMark());
	} else
		qwIZap = m_List2.qwGetItemData(m_List2.GetSelectionMark());

	sprintf(cQ, "pTov_pptDelVagPkt %s", isNull(qwIZap));
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
}

void CDlgVagOn1067::OnBnClickedButton2()
{
	if( m_List2.GetSelectionMark() == -1 ) return;
	CDlgVagNumTrafaret Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;
	char cQ[128] = "";
	sprintf(cQ, "pTov_pptTrafIns %s, %s, %s", 
					isNull(m_List2.qwGetItemData(m_List2.GetSelectionMark())), 
					isNull(Dlg.wDomkrat), 
					isNull(Dlg.wRow));
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	RefreshLists();
}

void CDlgVagOn1067::OnBnClickedButton1()
{
	if( m_List1.GetSelectionMark() == -1 ) return;
	char cQ[128] = "";
	sprintf(cQ, "pTov_pptTrafIns %s, NULL, NULL", 
					isNull(m_List1.qwGetItemData(m_List1.GetSelectionMark())));
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	RefreshLists();
}


CString strOldText1 = "", strOldText2 = "";
void CDlgVagOn1067::OnEnChangeEdit1()
{
//	char cText[64] = "";
	CString s1;
	CString str = "";
	m_EdNVag1.GetWindowText(s1);
	s1.TrimRight(" ");
	if( s1.GetLength() <= 0 ) 
	{
		m_List1.ClearMark();
		strOldText1 = "";
		m_List1.RedrawWindow();
		return;
	}
	int iCount = m_List1.GetItemCount();
	for( int i=0; i < iCount; i++ )
	{
		str = m_List1.GetItemText(i, 0);
		if( str.Left(s1.GetLength()) == s1 )
		{
			m_List1.ClearMark();
			m_List1.SetMarkedItem(i);
			m_List1.EnsureVisible(i, TRUE);
			m_List1.RedrawWindow();
			strOldText1 = s1;
			return;
		}
	}
	m_EdNVag1.SetWindowText(strOldText1);
}

void CDlgVagOn1067::OnEnChangeEdit2()
{
	CString s1;
	CString str = "";
	m_EdNVag2.GetWindowText(s1);
	s1.TrimRight(" ");
	if( s1.GetLength() <= 0 ) 
	{
		m_List2.ClearMark();
		m_List2.RedrawWindow();
		strOldText2 = "";
		return;
	}	
	int iCount = m_List2.GetItemCount();
	for( int i=0; i < iCount; i++ )
	{
		m_List2.ClearMark();
		str = m_List2.GetItemText(i, 0);
		if( str.Left(s1.GetLength()) == s1 )
		{
			m_List2.SetMarkedItem(i);
			m_List2.EnsureVisible(i, TRUE);
			m_List2.RedrawWindow();
			strOldText2 = s1;
			return;
		}		
	}
	m_EdNVag2.SetWindowText(strOldText2);
}

void CDlgVagOn1067::OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CDlgVagOn1067::OnHdnItemclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);	
	*pResult = 0;

	if( phdr->hdr.hwndFrom == m_List1.GetHeaderCtrl()->m_hWnd )
	{
		if( phdr->iItem == 2 ) return; //дату не сортируем

		if( m_List1.nSortedCol == phdr->iItem ) m_List1.bSortAscending = !m_List1.bSortAscending;
		else m_List1.bSortAscending = 1;

		m_List1.nSortedCol = phdr->iItem;
		m_List1.SortList();
	} else
	if( phdr->hdr.hwndFrom == m_List2.GetHeaderCtrl()->m_hWnd )
	{
		if( phdr->iItem == 1 ) return; //дату не сортируем

		if( m_List2.nSortedCol == phdr->iItem ) m_List2.bSortAscending = !m_List2.bSortAscending;
		else m_List2.bSortAscending = 1;

		m_List2.nSortedCol = phdr->iItem;
		m_List2.SortList();
	}
}
/*
void CDlgVagOn1067::OnHdnItemclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);	
	*pResult = 0;

	if( phdr->iItem == 2 ) return; //дату не сортируем

	m_List1.nSortedCol = phdr->iItem;
	m_List1.SortList();
	}*/

void CDlgVagOn1067::OnBnClickedButton_EditVag()
{
	if( iList == -1 || 
		(iList == 0 && m_List1.GetSelectionMark() == -1 ) ||
		(iList == 1 && m_List2.GetSelectionMark() == -1 )
		) return;

	CDlgVagOn1067Edit Dlg;

	char cQ[128] = "";
	__int64 qwIZap = 0;
	
	if( iList == 0 )
	{
		m_List1.GetItemText( m_List1.GetSelectionMark(), 0, Dlg.cNVag, 10 );		
	} else
		m_List2.GetItemText( m_List2.GetSelectionMark(), 0, Dlg.cNVag, 10 );		

	if( Dlg.cNVag[0] ) Dlg.DoModal();
}

void CDlgVagOn1067::OnBnClickedButton_UpdateAll()
{
		DBW.ExecSQL("pTov_ppt_AkpvZapros");
		DBW.CloseCursor();
		DBW.ReallocHandle();
		UpdButtonStatus();
}

void CDlgVagOn1067::UpdButtonStatus(void)
{
	iTimeUpd = 0;
	char cText[255] = "";


	long Ind = 0;	
	DWORD dwNum = 0;
	int flag = 0;
	char cQ[255] = "pTov_ppt_AkpvStatus";
	DBW.ExecSQL( cQ );
	DBW.Fetch();
	DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 )
	{
		m_ButUpd.EnableWindow( dwNum );
		
		if( dwNum == 0 ) { m_ButUpd.EnableWindow( 0 ); iStatusWaiting = 1; iTimeUpd = 1;}
	}
	
	DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_ButUpd.SetWindowText(cText);
	DBW.CloseCursor();
	

	if( dwNum && iStatusWaiting ) 
	{
		
		DBW.ExecSQL("pTov_ppt_AkpvUpdate");
		DBW.CloseCursor();
		DBW.ReallocHandle();

		RefreshLists();
		iStatusWaiting = 0;
		AfxMessageBox("Обновление сведений по вагонам завершено!");
		
	}
	
}

BOOL CDlgVagOn1067::DestroyWindow()
{
	MyKillTimer();

	return CDialog::DestroyWindow();
}

void CDlgVagOn1067::MySetTimer(void)
{
	::SetTimer(this->m_hWnd, 16, 30003, TimerRefreshBut);
}

void CDlgVagOn1067::MyKillTimer(void)
{
	::KillTimer( this->m_hWnd, 16 );

}

void CDlgVagOn1067::OnBnClickedButton_SpravkaPoAr()
{
	CPrintableDlg Dlg;
	sprintf( Dlg.cQ, "pTov_mkcReportPptArend1067 %d", g_iDep );
	Dlg.DoModal();
}
