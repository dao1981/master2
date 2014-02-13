// DlgBDSelectRezTL.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgBDSelectRezTL.h"
#include ".\dlgbdselectreztl.h"
#include "DlgRegisterTL.h"
#include "PrintableDlg.h"
#include "afxwin.h"
#include "afxdb.h"

//#include "excel8.h"

extern int g_iReportGridFontSize;
extern char g_cReportGridFontFace[64];
// CDlgBDSelectRezTL dialog

IMPLEMENT_DYNAMIC(CDlgBDSelectRezTL, CDialog)
CDlgBDSelectRezTL::CDlgBDSelectRezTL(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBDSelectRezTL::IDD, pParent)
{
	bGotHeader = 0;
	iNewProc = 0;
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
	DDX_Control(pDX, IDC_BUTTON3, m_BtnAdd);
}


BEGIN_MESSAGE_MAP(CDlgBDSelectRezTL, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton_EditTL)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton_DeleteTL)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton_AddTl)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton_PasportTL)
	ON_EN_CHANGE(IDC_EDIT1, OnEnChangeEditNTl)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_NOTIFY(HDN_ITEMCLICK, 0, &CDlgBDSelectRezTL::OnHdnItemclickList1)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlgBDSelectRezTL::OnBnClickedButtonExportExcel)
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

	if( iNewProc == 1 )
	{
		m_BtnAdd.SetWindowText("Отменить отправку");
	}
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
	if( iNewProc == 0 )
	{
		if( Dlg.DoModal() == IDCANCEL && !Dlg.iSomeAdded) 
		{
			return;
		}
	} else
	{
		if( m_List.GetSelectionMark() > -1 )
		{
			char cText[64] = "";
			sprintf( cText, "%I64u", m_List.qwGetItemData( m_List.GetSelectionMark() ));
			AfxMessageBox( cText );
		}
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


void CDlgBDSelectRezTL::OnHdnItemclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	*pResult = 0;

	if( phdr->hdr.hwndFrom == m_List.GetHeaderCtrl()->m_hWnd )
	{
		if( (
			iNewProc == 0 &&
			(
			phdr->iItem == 2 ||
			phdr->iItem == 4 ||
			phdr->iItem == 6 ||
			phdr->iItem == 7 ||
			phdr->iItem == 8 ||
			phdr->iItem == 9 ) ) ||
			(iNewProc == 1 &&
			(
			phdr->iItem == 1 ||
			phdr->iItem == 2 ||
			phdr->iItem == 3 ||
			phdr->iItem == 4 ||
			phdr->iItem == 7  ))

		) 
		return; //дату не сортируем

		if( m_List.nSortedCol == phdr->iItem ) m_List.bSortAscending = !m_List.bSortAscending;
		else m_List.bSortAscending = 1;

		m_List.nSortedCol = phdr->iItem;

		if( iNewProc == 1 )
			if( phdr->iItem == 0 || phdr->iItem == 6 )
			{
				m_List.SortList(1); //сортируем как INT64
			} else
			{
				m_List.SortList();
			}
		else
		if( iNewProc == 0 )
			if( phdr->iItem == 0 || phdr->iItem == 3 || phdr->iItem == 5 )
			{
				m_List.SortList(1); //сортируем как INT64
			} else
			{
				m_List.SortList();
			}
	} 
}


void CDlgBDSelectRezTL::OnBnClickedButtonExportExcel()
{
	
	CDatabase database;
	CString sDriver = "MICROSOFT EXCEL DRIVER (*.XLS)"; // exactly the same name as in the ODBC-Manager
	CString sExcelFile = "Тележки1067.xls";                // Filename and path for the file to be created
	if( iNewProc ) sExcelFile = "Тележки1067arx.xls";
	CString sSql;
  
	CString strColListInsert = "";
	CString strColListCreate = "";
	int iColCount = 0;
	LVITEM Item;
	HDITEM hItem;
	enum   { sizeOfBuffer = 256 };
	TCHAR  lpBuffer[sizeOfBuffer];
	bool   fFound = false;

	hItem.mask = HDI_TEXT;
	hItem.pszText = lpBuffer;
	hItem.cchTextMax = sizeOfBuffer;
	CHeaderCtrl *hcHeader = m_List.GetHeaderCtrl();
  
	iColCount =  hcHeader->GetItemCount();
	CString strTitle = "";
	for( int i = 0; i < iColCount; i++ )
	{
		if( i ) 
		{	  
			strColListInsert += ", ";
			strColListCreate += ", ";
		}
	  
		if( hcHeader->GetItem(i, &hItem) )
		{
			strTitle = hItem.pszText;
			strTitle.Remove('.');
			strColListInsert = strColListInsert + "[" + strTitle + "]";
			strColListCreate = strColListCreate + "[" + strTitle + "] TEXT";
		}
	}

  
    // Build the creation string for access without DSN
	DeleteFile(".\\" + sExcelFile);
    if( !CopyFile(".\\html\\" + sExcelFile, ".\\" + sExcelFile, 1) )
	{
		// Создам шаблон
		sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\".\\html\\%s\";DBQ=.\\html\\%s",
                sDriver, sExcelFile, sExcelFile);
		database.OpenEx(sSql,CDatabase::noOdbcDialog);
		sSql = "CREATE TABLE [Тележки 1067] (" + strColListCreate + ")";
		database.ExecuteSQL(sSql);
		database.Close();
		CopyFile(".\\html\\" + sExcelFile, ".\\" + sExcelFile, 1);
	}

	sSql.Format("DRIVER={%s};DSN='';FIRSTROWHASNAMES=1;READONLY=FALSE;CREATE_DB=\".\\%s\";DBQ=%s",
                sDriver, sExcelFile, sExcelFile);

    // Create the database (i.e. Excel sheet)
    if( database.OpenEx(sSql,CDatabase::noOdbcDialog) )
    {
		/*
		TRY
		{
		sSql = "CREATE TABLE [Тележки 1067] (" + strColListCreate + ")";
		database.ExecuteSQL(sSql);
		}
		CATCH_ALL(e)
		{
		}
		END_CATCH_ALL
		*/
		

		for( int i = 0; i < m_List.GetItemCount(); i++ )
		{
			CString strLine = "";
			for( int j = 0; j < iColCount; j++ )
			{
				if( j ) strLine += ", ";
				strLine += "'" + m_List.GetItemText(i, j) + "'";
			}
			//sSql = "INSERT INTO [Тележки 1067] (" + strColListInsert + ") VALUES ( " + strLine + " )";
			sSql = "INSERT INTO [Тележки 1067] VALUES ( " + strLine + " )";
			database.ExecuteSQL(sSql);
		}
		
      
	}      

    database.Close();
	CString str = "excel.exe .\\" + sExcelFile;
	ShellExecute(NULL, "open", "excel.exe", 
                           sExcelFile, 
                           NULL, SW_SHOWNORMAL);

}
