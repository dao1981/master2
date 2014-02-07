// DlgMsg4624Log.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg4624Log.h"
#include ".\dlgmsg4624log.h"
#include "DlgMsg4624_Main.h"
#include "DlgMsg4624_Main.h"
#include "DlgMsg4624_VagDateInput.h"
#include "PrintableDlg.h"
#include ".\telecom\teleI.h"

#include "DlgAddVansToRem.h"
#include "DlgSpravKdr.h"
#include "DlgSpravSmp.h"
#include "DlgInput2955.h"
#include "DlgInput2956.h"
#include "DlgInput2957.h"
#include "DlgInput2958.h"
#include "DlgEditDepo.h"
#include "DlgRptInputZhurnKompl.h"
#include "DlgReq2730ListVag.h"

// CDlgMsg4624Log dialog

extern cd_TeleI teleObj;	
extern cd_TeleI *tele;	
extern CString g_strTelecomServer;
extern int g_iEnableTelecom;
extern CMasterApp theApp;
extern int g_iStandAlone;

int iNoListRefresh;

IMPLEMENT_DYNAMIC(CDlgMsg4624Log, CDialog)
CDlgMsg4624Log::CDlgMsg4624Log(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMsg4624Log::IDD, pParent)
{
	cDat1[0] = 0;
	p_crColors[0] = RGB(255, 255, 255);
	p_crColors[1] = RGB(255, 203, 202);
	p_crColors[2] = RGB(248, 249, 208);
	p_crColors[3] = RGB(210, 247, 213);
	p_crColors[4] = RGB(220, 220, 220);
	p_crColors[5] = RGB(25, 25, 255);
	iNoListRefresh = 0;
	strWindowName = "";
	iMain = 0;
//	m = NULL;
}

CDlgMsg4624Log::~CDlgMsg4624Log()
{
}

void CDlgMsg4624Log::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, m_List);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_STATIC_COUNT1, m_Count1);
	DDX_Control(pDX, IDC_STATIC_COUNT2, m_Count2);
	DDX_Control(pDX, IDC_CHECK1, m_CheckSokr);
	DDX_Control(pDX, IDC_BUTTON2, m_ButDelASOUP);
	DDX_Control(pDX, IDC_BUTTON3, m_ButDelBD);
	DDX_Control(pDX, IDC_BUTTON5, m_ButVU36);
	DDX_Control(pDX, IDC_BUTTON6, m_But497);
	DDX_Control(pDX, IDC_BUTTON1, m_ButEdit);
}
CDlgMsg4624Log *ppp = NULL;

BEGIN_MESSAGE_MAP(CDlgMsg4624Log, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClicked_Select)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButtonEdit)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButtonDelBD)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButtonNew4624)
	ON_BN_CLICKED(IDC_BUTTON5, OnBnClickedButtonVU36)
	ON_BN_CLICKED(IDC_BUTTON6, OnBnClickedButton497)
	ON_NOTIFY(NM_CLICK, IDC_LIST2, OnNMClickList2)
	ON_NOTIFY(HDN_ITEMCHANGED, IDC_LIST2, OnHdnItemchangedList2)
	ON_NOTIFY(HDN_ITEMCHANGING, IDC_LIST2, OnHdnItemchangingList2)
	ON_NOTIFY(LVN_ITEMACTIVATE, IDC_LIST2, OnLvnItemActivateList2)
	ON_BN_CLICKED(IDC_BUTTON7, OnBnClickedButtonText4624)
	ON_COMMAND(ID_M_4624_ZAPR2730, OnMenu4624Zapr2730)
	ON_COMMAND(ID_M_4624_2955, OnMenu4624_2955)
	ON_COMMAND(ID_M_4624_2957, OnM46242957)
	ON_COMMAND(ID_M_4624_2956, OnMenu4624_2956)
	ON_COMMAND(ID_M_4624_2958, OnMenu4624_2958)
	ON_COMMAND(ID_M_4624_KOMPL, OnM4624_ZhurnalKompl)
	ON_COMMAND(ID_M_4624_PASP_DEPO, OnM4624PaspDepo)
	ON_COMMAND(ID_N_4624_KADR, OnN4624Kadr)
	ON_COMMAND(ID_M_4624_KOD_ASOUP, OnM4624KodAsoup)
	ON_COMMAND(ID_M_4624_VAG_V_REM, OnM4624VagVRem)
	ON_COMMAND(ID_M_4624_NEISP_VAG, OnM4624NeispVag)
	ON_COMMAND(ID_MNU4624_ZAM_DET, &CDlgMsg4624Log::OnMnu4624ZamDet)
END_MESSAGE_MAP()


// CDlgMsg4624Log message handlers

VOID CALLBACK TimerRefresh( 
    HWND hwnd,        // handle to window for timer messages 
    UINT message,     // WM_TIMER message 
    UINT idTimer,     // timer identifier 
    DWORD dwTime) 
{
	if(	iNoListRefresh ) return;
/*	CString x = "";
	x.Format("%d", idTimer);
	AfxMessageBox(x);*/
	int x = ppp->m_List.GetSelectionMark();
//	ppp->m_List.GetFirstSelectedItemPosition
	if( idTimer == 12 )
		ppp->OnBnClicked_Select();
	if( x > -1 ) 
	{
		ppp->m_List.SetSelectionMark(x);
		ppp->m_List.EnsureVisible(x, 1);
		ppp->m_List.SetItemState( x ,LVIS_SELECTED | LVIS_FOCUSED , LVIS_SELECTED | LVIS_FOCUSED);
		/*		ppp->m_List.RedrawWindow();
		ppp->m_List.RedrawItems(0, 100);*/
	}
}

extern int g_iStandAlone;
BOOL CDlgMsg4624Log::OnInitDialog()
{
	CDialog::OnInitDialog();
	ppp = this;
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB );

	m_List.InsertColumn(0, "№ вагона", LVCFMT_LEFT, 70);
	m_List.InsertColumn(1, "Время отправки", LVCFMT_LEFT, 90);
	m_List.InsertColumn(2, "Время квитанции", LVCFMT_LEFT, 90);
	m_List.InsertColumn(3, "Код приема", LVCFMT_LEFT, 90);
	m_List.InsertColumn(4, "Код ошибки", LVCFMT_LEFT, 380);
	
	m_ButEdit.EnableWindow(FALSE);
	m_ButDelBD.EnableWindow(FALSE);
	m_ButDelASOUP.EnableWindow(FALSE);
	m_But497.EnableWindow(FALSE);
	m_ButVU36.EnableWindow(FALSE);

	m_CheckSokr.SetCheck(1);
	m_Dat1.SetMode(1, 1);
	m_Dat1.InitDate();
	strcpy(cDat1, m_Dat1.GetSQLDate());
	RefreshList();

	::SetTimer(this->m_hWnd, 12, 60003, TimerRefresh); // was 60003

	if( strWindowName != "" )
		SetWindowText(strWindowName);

	if( !iMain )
	{
		CMenu *m = this->GetMenu();
		m->RemoveMenu(5, MF_BYPOSITION);
		m->RemoveMenu(5, MF_BYPOSITION);
	} else
	{
		ModifyStyle(0, WS_OVERLAPPEDWINDOW );
	}
	if( g_iStandAlone ) 
	{
		CMenu *m = this->GetMenu();
/*		m_ButVagInRem.ModifyStyle(WS_VISIBLE, 0);
		m_ButNeispVag.ModifyStyle(WS_VISIBLE, 0);*/
		m->RemoveMenu(ID_M_4624_VAG_V_REM, MF_BYCOMMAND);
		m->RemoveMenu(ID_M_4624_NEISP_VAG, MF_BYCOMMAND);		
	}
	
/*
	CMenu *m = new CMenu;
    m->LoadMenu(IDR_MENU4624);
	SetMenu(m);
*/

	return TRUE;
}

void CDlgMsg4624Log::OnBnClicked_Select()
{
	strcpy(cDat1, m_Dat1.GetSQLDate());
	RefreshList();

//	OnOK();
}
extern CString toStr(DWORD);
void CDlgMsg4624Log::RefreshList(void)
{
	char cQ[200] = "";
	__int64 qwNum = 0;
	DWORD dwNum = 0;
	long	Ind = 0;
	char	cText[64] = "";
	DWORD	dwGreenCount = 0;
//	m_List.DeleteAllItems();
	sprintf(cQ, "pTov_S4624Send %u, %s", g_iDep, cDat1);
	DBW.ExecSQL(cQ);
	int iListSize = m_List.GetItemCount();

	int i;
	for( i=0; i < 1024 && (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
	{
		if( i + 1 > iListSize )
			m_List.InsertItem(i, "");

		DBW.GetData(1, SQL_C_UBIGINT, &qwNum, 8, &Ind);
		if( Ind != -1 ) m_List.qwSetItemData(i, qwNum);

		DBW.GetData(2, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 && dwNum < 12 && dwNum != m_List.GetItemData(i)) 
		{
			m_List.SetItemColor(i, 0,  p_crColors[dwNum] );
			m_List.SetItemData(i, dwNum);
		}
		if( dwNum == 3 ) dwGreenCount++;
		DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_List.SetItemText(i, 0, cText);
		else m_List.SetItemText(i, 0, "");
		DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_List.SetItemText(i, 1, cText);
		else m_List.SetItemText(i, 1, "");
		DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_List.SetItemText(i, 2, cText);
		else m_List.SetItemText(i, 2, "");
		DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_List.SetItemText(i, 3, cText);
		else m_List.SetItemText(i, 3, "");
		DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) 
		{
//			theApp.Dos2Win((unsigned char *)cText, 64);
			for( int x=0; cText[x] && x < 64; x++ )
			{
				if( cText[x] == '\n' ) cText[x] = ' ';
				if( cText[x] == '\r' ) cText[x] = ' ';
			}
			m_List.SetItemText(i, 4, cText);
		}
		else m_List.SetItemText(i, 4, "");
	}
//	if( iListSize > i ) m_List.SetItemCount(i + 1);
	for( int x=0; x < iListSize - i ; x++ ) m_List.DeleteItem(i);
	m_Count1.SetWindowText(toStr(m_List.GetItemCount()));
	m_Count2.SetWindowText(toStr(dwGreenCount));
	DBW.CloseCursor();
}

void CDlgMsg4624Log::OnBnClickedCancel()
{
	KillTimer(3003);
	OnCancel();

}

void CDlgMsg4624Log::OnBnClickedButtonEdit()
{
	int index = m_List.GetSelectionMark();
	if( index < 0 ) return;
	CDlgMsg4624_Main Dlg1;
	char cText[64] = "";

	m_Dat1.GetTime(&Dlg1.stRemDat);
	m_List.GetItemText(index, 0, Dlg1.cVagNum32, 32);
	m_List.GetItemText(index, 1, cText, 32);
	char cx[3] = {0,0,0};
	if( cText[0] != 0 )
	{
		strncpy(cx, cText, 2);
		Dlg1.stRemDat.wHour = atoi(cx);
		strncpy(cx, cText+3, 2);
		Dlg1.stRemDat.wMinute = atoi(cx);
		strncpy(cx, cText+5, 2);
		Dlg1.stRemDat.wSecond = atoi(cx);
		Dlg1.stRemDat.wMilliseconds = 33;
	} 
	Dlg1.stDat4624 = Dlg1.stRemDat;
	iNoListRefresh = 1;
	Dlg1.DoModal();
	iNoListRefresh = 0;
}
extern CString g_strASOUPTeleName;
extern int g_iNoPPT;
void CDlgMsg4624Log::OnBnClickedButton2()
{
	int x = m_List.GetSelectionMark();
	if( x < 0 ) return;
	if( m_List.GetItemData(x) != 1 && 
		m_List.GetItemData(x) != 2 &&
		m_List.GetItemData(x) != 3 ) return;
	char cQ[256] = "";	
	char cText[512] = "";
	long Ind = 0;

//	g_iStandAlone = 0;
	sprintf(cQ, "pTov_S4624FormDel %I64u, %d", m_List.qwGetItemData(x), g_iFam);
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cText, 512, &Ind);
		DBW.CloseCursor();

	if( g_iStandAlone ) 
	{		
		theApp.SendTeleMessage(cText, "4624del_");
	}
	else
	{
		m_List.GetItemText(x, 0, cText, 64);
		CString s1;
		s1.Format("(:4936 %d 4\n12R %s 14849:)", g_iFam, cText);
		char mess[512] = "";
		sprintf(mess, "message text: %s", s1);
		DBW.WriteLog(mess);
		if( g_iEnableTelecom && tele )
		{ 
			if(g_iNoPPT)
				tele->SendMessageDst(s1, &g_strTelecomServer);
			else
				tele->SendMessageDst(s1, &g_strASOUPTeleName);
		}
	}
	RefreshList();
}

void CDlgMsg4624Log::OnBnClickedButtonDelBD()
{
	int x = m_List.GetSelectionMark();
	if( x < 0 ) return;
	if( m_List.GetItemData(x) != 0 && 
		m_List.GetItemData(x) != 1 &&
		m_List.GetItemData(x) != 4 ) return;

//	if( AfxMessageBox("") == IDYES

	char cQ[256] = "";	
	sprintf(cQ, "pTov_S4624DelBD %I64u", m_List.qwGetItemData(x));
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
//	RefreshList();
	m_List.DeleteItem(x);

}

void CDlgMsg4624Log::OnBnClickedButtonNew4624()
{
	CDlgMsg4624_VagDateInput Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

	CDlgMsg4624_Main Dlg1;
	Dlg1.iInfoFromVagPasp = Dlg.m_iCheck;
	Dlg1.m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	strcpy(Dlg1.cVagNum32, Dlg.cNVag32);
//	Dlg1.stRemDat = Dlg.stDat;
	Dlg1.stDat4624 = Dlg.stDat;
	Dlg1.DoModal();
	RefreshList();
}

void CDlgMsg4624Log::OnBnClickedButtonVU36()
{
	int x = m_List.GetSelectionMark();
	if( x < 0 ) return;
/*	if( m_List.GetItemData(x) != 1 && 
		m_List.GetItemData(x) != 2 &&
		m_List.GetItemData(x) != 3 ) return;*/

	char cNVag[32] = "";
	m_List.GetItemText(x, 0, cNVag, 32);
	if( !m_CheckSokr.GetCheck() )
	{
		CPrintableDlg Dlg;
		sprintf(Dlg.cQ, "pTov_GetVU36ByNVag '%s', 0, %d", cNVag, 0 );
		Dlg.m_bCheck1 = 1;
		Dlg.DoModal();
	} else
	{	
		char cQ[128] = "";
		sprintf(cQ, "pTov_GetVU36ByNVag '%s', 0, %d", cNVag,  1 );
		DBW.DisplayHtmlReport(cQ);
	}
	
}

void CDlgMsg4624Log::OnBnClickedButton497()
{
	int x = m_List.GetSelectionMark();
	if( x < 0 ) return;
	if( m_List.GetItemData(x) != 1 && 
		m_List.GetItemData(x) != 3 &&
		m_List.GetItemData(x) != 4 ) return;
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_MkcGetText497 %s", isNull(m_List.qwGetItemData(x)));
	Dlg.DoModal();

}

void CDlgMsg4624Log::OnNMClickList2(NMHDR *pNMHDR, LRESULT *pResult)
{

	SetButtonsState();
	*pResult = 0;
}

void CDlgMsg4624Log::OnHdnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
//	AfxMessageBox("@!");
	*pResult = 0;
}

void CDlgMsg4624Log::OnHdnItemchangingList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
//	AfxMessageBox("!@!");
	*pResult = 0;
}

void CDlgMsg4624Log::OnLvnItemActivateList2(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMITEMACTIVATE pNMIA = reinterpret_cast<LPNMITEMACTIVATE>(pNMHDR);
//	AfxMessageBox("233");
	*pResult = 0;
}

BOOL CDlgMsg4624Log::PreTranslateMessage(MSG* pMsg)
{
	BOOL x =  CDialog::PreTranslateMessage(pMsg);
	if( m_List.iActive )
	{
		if ( ( pMsg->message == WM_KEYDOWN  )
//			&& ( pMsg->wParam == VK_UP || pMsg->wParam == VK_DOWN )
		)
		{
			SetButtonsState();
		}		
	}
	return x;
}

void CDlgMsg4624Log::SetButtonsState(void)
{
			m_ButEdit.EnableWindow();
			m_ButVU36.EnableWindow();
			m_But497.EnableWindow();

			int x = m_List.GetSelectionMark();
			if( x < 0 ) return;
			DWORD d = m_List.GetItemData(x);
			if( d == 0 || d == 1 || d == 2 || d == 4  ) m_ButDelBD.EnableWindow();
			else m_ButDelBD.EnableWindow(FALSE);

			if( d == 1 || d == 2 || d == 3 ) m_ButDelASOUP.EnableWindow();
			else m_ButDelASOUP.EnableWindow(FALSE);

			if( d == 1 || d == 3 || d == 4 ) m_But497.EnableWindow();
			else m_But497.EnableWindow(FALSE);
}

void CDlgMsg4624Log::OnBnClickedButtonText4624()
{
	int x = m_List.GetSelectionMark();
	if( x < 0 ) return;
	CPrintableDlg Dlg;

	sprintf(Dlg.cQ, "pTov_S4624Form %I64u, 1", m_List.qwGetItemData(x));
	Dlg.DoModal();
	
}

void CDlgMsg4624Log::OnMenu4624Zapr2730()
{
	CDlgReq2730ListVag Dlg;
	Dlg.DoModal();}

void CDlgMsg4624Log::OnMenu4624_2955()
{
	CDlgInput2955 Dlg;
	Dlg.DoModal();
}

void CDlgMsg4624Log::OnMenu4624_2956()
{
	CDlgInput2956 Dlg;
	Dlg.DoModal();
}

void CDlgMsg4624Log::OnM46242957()
{
	CDlgInput2957 Dlg;
	Dlg.DoModal();
}


void CDlgMsg4624Log::OnMenu4624_2958()
{
	CDlgInput2958 Dlg;
	Dlg.DoModal();
}

void CDlgMsg4624Log::OnM4624_ZhurnalKompl()
{
	CDlgRptInputZhurnKompl Dlg;
	Dlg.DoModal();
}

void CDlgMsg4624Log::OnM4624PaspDepo()
{
	CDlgEditDepo Dlg;
	Dlg.DoModal();

}

void CDlgMsg4624Log::OnN4624Kadr()
{
	CDlgSpravKdr Dlg;
    Dlg.DoModal();

}

void CDlgMsg4624Log::OnM4624KodAsoup()
{
	CDlgSpravSmp Dlg;
	Dlg.DlgMode = 201;
	Dlg.DoModal();
}

void CDlgMsg4624Log::OnM4624VagVRem()
{
		CDlgAddVansToRem Dlg;
		if( Dlg.DoModal() == IDCANCEL ) return;
		RefreshList();
}

void CDlgMsg4624Log::OnM4624NeispVag()
{
		CDlgAddVansToRem Dlg;
		Dlg.iNeisp = 1;
		if( Dlg.DoModal() == IDCANCEL ) return;
}

extern SQLCHAR g_ConnStrIn[255];
void CDlgMsg4624Log::OnMnu4624ZamDet()
{
	typedef void (CALLBACK* ShowFormDllFunc)(char*, int, int, int);
	ShowFormDllFunc ShowForm; 
	HMODULE hm = LoadLibrary ("hc_xls.dll");
	ShowForm = (ShowFormDllFunc)GetProcAddress (hm, "ShowForm");

	if (ShowForm)
	{
		ShowForm ((char*)g_ConnStrIn, g_iDep, g_iFam, 2);
	}
	FreeLibrary (hm);
}
