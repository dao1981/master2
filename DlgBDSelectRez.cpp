// DlgBDSelectRez.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgBDSelectRez.h"
#include "DlgEdRsn.h"
#include "PrintableDlg.h"
#include ".\dlgbdselectrez.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp theApp;
extern DWORD g_iFam;
/////////////////////////////////////////////////////////////////////////////
// CDlgBDSelectRez dialog
extern int g_iReportGridFontSize;
extern char g_cReportGridFontFace[64];

CDlgBDSelectRez::CDlgBDSelectRez(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBDSelectRez::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgBDSelectRez)
	//}}AFX_DATA_INIT
	iMode = 0;
    bGotHeader = false;
    iParent = 0;
}


void CDlgBDSelectRez::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgBDSelectRez)
	DDX_Control(pDX, IDC_BUTTON4, m_ButHistory);
	DDX_Control(pDX, IDC_BUTTON3, m_ButPerech);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_EDIT1, m_Ed);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_BUTTON2, m_ButRemoveKP);
	DDX_Control(pDX, IDC_BUTTON1, m_ButMkPasp);
	DDX_Control(pDX, IDC_EDIT2, m_EdSrch);
}


BEGIN_MESSAGE_MAP(CDlgBDSelectRez, CDialog)
	//{{AFX_MSG_MAP(CDlgBDSelectRez)
	ON_BN_CLICKED(IDC_BUTTON2, OnRemoveKPButton)
	ON_BN_CLICKED(IDC_BUTTON1, OnMakePasp)
	ON_BN_CLICKED(IDC_BUTTON3, OnPerechenClicked)
	ON_BN_CLICKED(IDC_BUTTON4, OnHistoryButton)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, OnLvnItemchangedList1)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON5, &CDlgBDSelectRez::OnBnClickedButtonVU55)
	ON_EN_CHANGE(IDC_EDIT2, &CDlgBDSelectRez::OnEnChangeEditFind)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgBDSelectRez message handlers
extern CString sOldText;
BOOL CDlgBDSelectRez::OnInitDialog()
{
	CDialog::OnInitDialog();
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );
	sOldText = "";
	m_EdSrch.QInit(110, 1);

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
    if( !iParent )
    {
        m_ButPerech.ModifyStyle(WS_VISIBLE, 0);
//        m_ButHistory.ModifyStyle(WS_VISIBLE, 0);
    }

	if( iMode == 3 ) //Тележки
	{
		m_ButPerech.ModifyStyle(WS_VISIBLE, 0);
        m_ButHistory.ModifyStyle(WS_VISIBLE, 0);
		m_ButRemoveKP.ModifyStyle(WS_VISIBLE, 0);
		m_ButMkPasp.ModifyStyle(WS_VISIBLE, 0);
	}

	return TRUE;
}

void CDlgBDSelectRez::RefreshList()
{
    char cRecCount[32];
	if( iMode )
	{
        m_List.DeleteAllItems();
		DBW.ExecSQL(cQ);
        if( !bGotHeader ) DBW.SetListHeader(&m_List);
		itoa(DBW.UpdateListByHandle(&m_List), cRecCount, 10);
		DBW.CloseCursor();
		m_Ed.SetWindowText(CString("Количество записей: ") + cRecCount);
	}
}

void CDlgBDSelectRez::OnOK() 
{
//    m_List.DeleteAllItems();
//    delete(&m_List);
	CDialog::OnOK();
}

void CDlgBDSelectRez::OnRemoveKPButton() 
{
    int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;

    CString s;
    char cText1[64] = "", cText2[64] = "";
    m_List.GetItemText(idx, 0, cText1, 64);
    m_List.GetItemText(idx, 1, cText2, 64);

    s.Format("Вы действительно хотите удалить КП %s %s?", cText1, cText2);

    if( MessageBox(s, "Внимание!", MB_YESNO) == IDNO ) return;

    CHeaderCtrl *pHd = m_List.GetHeaderCtrl();
    HDITEM hdi;
    __int64   qwIZAP = 0;
    int     iPriznRas = 0;
    char cText[64] = "";
    TCHAR Buffer[128] = "";
    hdi.mask = HDI_TEXT;
    hdi.pszText = Buffer;
    hdi.cchTextMax = 128;

    for( int i=0; i < pHd->GetItemCount(); i++ )
    {
        pHd->GetItem(i, &hdi);
        if( !stricmp("IZAP", hdi.pszText ) )
        {
            m_List.GetItemText( m_List.GetSelectionMark(), i, cText, 64);
            qwIZAP = _atoi64(cText);
        }
        if( !stricmp("PRIZN_RAS", hdi.pszText ) )
        {
            m_List.GetItemText( m_List.GetSelectionMark(), i, cText, 64);
            iPriznRas = atoi(cText);
        }
    }
    CDlgEdRsn Dlg;
    if( iPriznRas >= 90 )
    {        
        Dlg.m_osnTitle = "Укажите причину удаления израсходованной КП";
        if( Dlg.DoModal() == IDCANCEL ) return;
    }
	long Ind = 0;
    char cQ[512] = "";
	char cNKP[12] = "";
	DWORD dwTKP = 0, dwIPrIzg = 0;
	SYSTEMTIME stDatIzg;
	ZeroMemory(&stDatIzg, sizeof(stDatIzg));
	sprintf(cQ, "pTov_GetIKPbyIZAP %I64u", qwIZAP);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(2, SQL_C_CHAR, cNKP, 12, &Ind );
	DBW.GetData(3, SQL_C_ULONG, &dwTKP, 4, &Ind );
	DBW.GetData(4, SQL_C_ULONG, &dwIPrIzg, 4, &Ind );
	mgSQLGetSysDate(5, &stDatIzg, &Ind);
	DBW.CloseCursor();
	
    sprintf(cQ, "pTov_DeleteKP %I64u, %s, '%s'", qwIZAP, isNull(g_iFam), Dlg.m_Text );
    DBW.ExecSQL(cQ);
    DBW.CloseCursor();
    DBW.ReallocHandle();

	if( g_iGotRezervDBW )
	{
		DBWrez.ExecSQL(cQ);
		DBWrez.CloseCursor();
		DBWrez.ReallocHandle();
	}

	strncpy(cText, m_List.GetItemText(idx, 9), 64);

    m_List.DeleteItem(m_List.GetSelectionMark());
	char cRecCount[32];
	itoa(m_List.GetItemCount(), cRecCount, 10);
	m_Ed.SetWindowText(CString("Количество записей: ") + cRecCount);
/*
	sprintf(cQ, "pTov_DeleteKP_Rez %u, '%s', %u, %s, %s, %s, %s, %s",
		g_iDep,
		cNKP,
		dwTKP,
		DateToSQL(stDatIzg),
		isNull(dwIPrIzg),
		StrDateToSQL(cText, 1),
		isNull(g_iFam),
		isNull(Dlg.m_Text));
	DBW.ExecSQLRzv(cQ);*/

}

void CDlgBDSelectRez::OnMakePasp() 
{
    CHeaderCtrl *pHd = m_List.GetHeaderCtrl();
    HDITEM hdi;
    __int64   qwIZAP = 0;
    int     iPriznRas = 0;
    char cText[64] = "";
    TCHAR Buffer[128] = "";
    hdi.mask = HDI_TEXT;
    hdi.pszText = Buffer;
    hdi.cchTextMax = 128;

    for( int i=0; i < pHd->GetItemCount(); i++ )
    {
        pHd->GetItem(i, &hdi);
        if( !strcmp("IZAP", hdi.pszText ) )
        {
            m_List.GetItemText( m_List.GetSelectionMark(), i, cText, 64);
            qwIZAP = atoi(cText);
        }
    }
    char cQ[512] = "";

    sprintf(cQ, "pTov_mkcReportPasp %I64u", qwIZAP);

    CPrintableDlg Dlg;
    sprintf(Dlg.cQ, cQ);
    Dlg.m_bCheck1 = false;
    Dlg.m_bCheck2 = true;
    Dlg.DoModal();
}

void CDlgBDSelectRez::OnPerechenClicked() 
{
    CPrintableDlg Dlg;
    char cQ[512] = "";
//    PRIHOD_PARAMS pp;
    sprintf(cQ, "pTov_mkcReportNPKP %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u",
            g_iDep,
            pp.cDatPrih1,
            pp.cDatPrih2,
            pp.cDatRem1,
            pp.cDatRem2,
            pp.cDatRash1,
            pp.cDatRash2,
            pp.cNoRash_8,
            pp.cNotIsp_8,
            pp.cTKP_8,
            pp.cMaskNKP_32,
            pp.cTypeRemID_8,
            pp.cVagNumIn,
            pp.cVagNumOut,
            pp.cIPRRecieved_8,
            pp.cDv_8,
            pp.cIzgOsIPr_16,
            pp.cDatIzgOs1,
            pp.cDatIzgOs2,
            pp.cDatPosFor1,
            pp.cDatPosFor2,
            pp.cDKK1_16,
            pp.cDKK2_16,
            pp.cNeispID_8,
            pp.cPriznObt_8,
			isNull(pp.dwVagRemPrih),
			isNull(pp.dwVagRemRash),
			pp.iSpis);
    strcpy(Dlg.cQ, cQ);
    Dlg.DoModal();
}

void CDlgBDSelectRez::OnHistoryButton() 
{
    CString str1, str2;
    
    str1 = m_List.GetItemText(m_List.GetSelectionMark(), 0);
    str2 = m_List.GetItemText(m_List.GetSelectionMark(), 1);

    CPrintableDlg Dlg;
    sprintf(Dlg.cQ, "pTov_mkcReportHistoryKP1 '%s', '%s'", str1, str2);
	Dlg.DoModal();
}

void CDlgBDSelectRez::OnClose() 
{
    if(Font) delete Font;
	CDialog::OnClose();
}

void CDlgBDSelectRez::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
}

void CDlgBDSelectRez::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CDlgBDSelectRez::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

extern SQLCHAR      g_ConnStrIn[MAXBUFLEN];

void CDlgBDSelectRez::OnBnClickedButtonVU55()
{

    int   qwIZAP = 0;
    int     iPriznRas = 0;
	CHeaderCtrl *pHd = m_List.GetHeaderCtrl();
    HDITEM hdi;
    char cText[64] = "";
    TCHAR Buffer[128] = "";
    hdi.mask = HDI_TEXT;
    hdi.pszText = Buffer;
    hdi.cchTextMax = 128;

    for( int i=0; i < pHd->GetItemCount(); i++ )
    {
        pHd->GetItem(i, &hdi);
        if( !strcmp("IZAP", hdi.pszText ) )
        {
            m_List.GetItemText( m_List.GetSelectionMark(), i, cText, 64);
            qwIZAP = atoi(cText);
        }
    }

	typedef void (CALLBACK* CPrintVU55)(char*, int);
	CPrintVU55 VU55Form; 
	HMODULE hm = LoadLibrary ("hc_xls.dll");
	VU55Form = (CPrintVU55)GetProcAddress (hm, "PrintVU55");

	if (VU55Form)
	{
		VU55Form ((char*)g_ConnStrIn, qwIZAP);
	} else
	{
		AfxMessageBox("Ошибка формирования ВУ-55!");
	}
	FreeLibrary (hm);
}

void CDlgBDSelectRez::OnEnChangeEditFind()
{
    CString s1;
    CString s2;
	char tt[25] = "";
    m_EdSrch.GetAsString(tt);
	s1 = tt;
    if( s1.GetLength() <= 0 )
    {
        m_List.ClearMark();
        return;
    }

    for( int i=0; i < m_List.GetItemCount(); i++ )
    {
        s2 = m_List.GetItemText(i, 0);
        if( s2.Left(s1.GetLength()) == s1 )
        {
//            int x = m_List.SetSelectionMark(i);
			m_List.ClearMark();
            m_List.SetMarkedItem(i);
//            m_List.SetHotCursor(i);
            m_List.EnsureVisible(i, TRUE);
            m_List.RedrawWindow();
            sOldText = s1;
            return;
        }
    }
    m_EdSrch.GetWindowText(sOldText);
}
