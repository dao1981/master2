// DlgAddPeres.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgAddPeres.h"
#include "DlgSprav1.h"
#include "DlgSpravKdr.h"
#include "DlgAddKpSmall.h"
#include "PrintableDlg.h"
#include "DlgChangeTypeKP.h"
#include "DlgSprPrSobstv.h"
#include "DlgPrihKpList.h"
#include "DlgSelKPType.h"
#include ".\telecom\teleI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAddPeres dialog
#include <sqlext.h>
#include ".\dlgaddperes.h"

extern SQLRETURN    g_sqlret;
extern CMasterApp   theApp;
extern BYTE gs_DateFmt;
extern DWORD g_iDep;
extern CString g_strDepoKl;
extern DWORD g_dwPrID;
extern CString g_strAsldTeleName;
extern int g_iEnableTelecom;
extern cd_TeleI *tele;

CDlgAddPeres::CDlgAddPeres(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgAddPeres::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAddPeres)
	m_uiCount = 0;
	m_Edit1Num = 0;
	m_iPrRem = -1;
	m_cVagNum = _T("");
	m_Edit4Text = _T("");
	//}}AFX_DATA_INIT
    qwIPeres = 0;
    dwKPCount=0;
    dwOldKPCount=0;
    iMode=0;
    dwVedNum=0;
    cVedDate[0]=0;
    iHeader = 0;
    dwIPR_Rcv = 0;
    iOnVag = 0;

    dwFIO_Priem = 0;
    dwFIO_Mast = 0;
	dwFIO_MastRcv = 0;

    m_Edit5.SetMode(5);
    m_Edit6.SetMode(5);
    m_EdMasterRcv.SetMode(5);
    iRecieveMode = 0;
    DlgStarted = 0;
    m_DatRcv.SetMode(1);
    m_Date1.SetMode(1);
	dwIPR_Rcv = 0;
	dwIPR_Snd = 0;	
	dwIPR_Sobst = 0;
	iCreateRecieveMode = 0;
	ZeroMemory(qwIKP, sizeof(qwIKP));
	ZeroMemory(qwIZAP, sizeof(qwIZAP));
	ZeroMemory(p_dwNeispID, sizeof(p_dwNeispID));
	ZeroMemory(p_dwNewTKP, sizeof(p_dwNewTKP));
	ZeroMemory(&stVedDate, sizeof(stVedDate));
	ZeroMemory(&stDatIzg, sizeof(SYSTEMTIME)*128);
	ZeroMemory(&dwIPrIzg, sizeof(dwIPrIzg));
	ZeroMemory(&p_dwRemoved, sizeof(p_dwRemoved));

	ZeroMemory(&p_dwObod_KP1, sizeof(p_dwObod_KP1));
	ZeroMemory(&p_dwObod_KP2, sizeof(p_dwObod_KP2));
	ZeroMemory(&p_dwGreb_KP1, sizeof(p_dwGreb_KP1));
	ZeroMemory(&p_dwGreb_KP2, sizeof(p_dwGreb_KP2));
	ZeroMemory(&p_dProkat_KP1, sizeof(p_dProkat_KP1));
	ZeroMemory(&p_dProkat_KP2, sizeof(p_dProkat_KP2));

	iShowAddDelButtons = 1;
}


void CDlgAddPeres::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAddPeres)
	DDX_Control(pDX, IDC_BUTTON8, m_But2);
	DDX_Control(pDX, IDC_BUTTON25, m_ButMaterRcv);
	DDX_Control(pDX, IDC_BUTTON11, m_ButSobst);
	DDX_Control(pDX, IDC_BUTTON1, m_ButRcv);
	DDX_Control(pDX, IDC_EDIT11, m_Date1);
	DDX_Control(pDX, IDC_CHECK2, m_CheckAll);
	DDX_Control(pDX, IDC_EDIT8, m_EdMasterRcv);
	DDX_Control(pDX, IDC_EDIT7, m_DatRcv);
	DDX_Control(pDX, IDC_EDIT78, m_EdPrSobst);
	DDX_Control(pDX, IDC_EDIT16, m_EdPrSnd);
	DDX_Control(pDX, IDC_EDIT72, m_PrSnd);
	DDX_Control(pDX, IDC_EDIT118, m_PrSobst);
	DDX_Control(pDX, IDC_EDIT70, m_Edit6);
	DDX_Control(pDX, IDC_EDIT6, m_Edit5);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_EDIT3, m_CountCtrl);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_BUTTON6, m_Button3);
	DDX_Control(pDX, IDC_EDIT5, m_Edit4);
	DDX_Control(pDX, IDC_EDIT4, m_Edit3);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT3, m_uiCount);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1Num);
	DDX_CBIndex(pDX, IDC_COMBO1, m_iPrRem);
	DDX_Text(pDX, IDC_EDIT2, m_cVagNum);
	DDX_Text(pDX, IDC_EDIT5, m_Edit4Text);
	DDX_Control(pDX, IDC_BUTTON2, m_ButMastLow);
	DDX_Control(pDX, IDC_BUTTON4, m_ButPriemLow);
	DDX_Control(pDX, IDC_BUTTON5, m_ButAddKP); 
	DDX_Control(pDX, IDC_BUTTON12, m_ButIzNal);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgAddPeres, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgAddPeres)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT4, OnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDOK, OnAddVed)
	ON_BN_CLICKED(IDC_BUTTON25, OnButton_MasterRcv)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton_GetSobst)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck_SelectAll)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton_PrSender)
	//}}AFX_MSG_MAP
	ON_EN_CHANGE(IDC_EDIT6, OnEnChangeEdit6)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnNMRclickList1)
	ON_COMMAND(ID_MNU_PSP, OnMnuPsp)
	ON_EN_CHANGE(IDC_EDIT72, &CDlgAddPeres::OnEnChangeEditPrOtpr)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CDlgAddPeres::OnLvnItemchangedList1)
	ON_BN_CLICKED(IDC_BUTTON12, &CDlgAddPeres::OnBnClickedButton_SelFromNal)
	ON_NOTIFY(HDN_ITEMDBLCLICK, 0, &CDlgAddPeres::OnHdnItemdblclickList1)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, &CDlgAddPeres::OnNMDblclkList1)
	ON_EN_CHANGE(IDC_EDIT118, &CDlgAddPeres::OnEnChangeEdit118)
	ON_BN_CLICKED(IDC_BUTTON14, &CDlgAddPeres::OnBnClickedButton_ClearSobst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAddPeres message handlers

BOOL CDlgAddPeres::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();

	ZeroMemory( &p_dwNewTKP, sizeof( p_dwNewTKP ) );

	m_Edit4.ModifyStyle(0, WS_DISABLED, 0);
	m_EdPrSnd.ModifyStyle(0, WS_DISABLED, 0);
	m_EdPrSobst.ModifyStyle(0, WS_DISABLED, 0);
	m_CountCtrl.ModifyStyle(0, WS_DISABLED);

    CButton *b1 = (CButton *)GetDlgItem(IDC_RADIO1);
    CButton *b2 = (CButton *)GetDlgItem(IDC_RADIO2);
    ASSERT(b1);
    ASSERT(b2);
    b1->SetCheck(1);	
    m_Edit3.SetWindowText("");
    char cQ[64] = "pTov_GetNewVedNum";
    char cText[64] = "";
    long lNum = 0;
    long Ind = 0;
	m_Edit1.QInit(80, 1);
    m_List.InsertColumn(0, "Номер КП", LVCFMT_RIGHT, 80, -1);
    m_List.InsertColumn(1, "Тип КП", LVCFMT_LEFT, 100, -1);
	m_List.InsertColumn(2, "Изготовитель", LVCFMT_LEFT, 120, -1);
	m_List.InsertColumn(3, "Год изг.", LVCFMT_LEFT, 80, -1);
    m_List.InsertColumn(4, "Состояние", LVCFMT_LEFT, 220, -1);
	m_List.InsertColumn(5, "", LVCFMT_LEFT, 320, -1);
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD | LVS_SINGLESEL, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB );
//    m_Button3.ModifyStyle(0, WS_DISABLED);
//    m_Button3.EnableWindow(FALSE);
	if( iRecieveMode )
		m_ButIzNal.ModifyStyle(WS_VISIBLE,0);
	else
		m_ButIzNal.ModifyStyle(0, WS_VISIBLE);
	if( iMode == 0 && iCreateRecieveMode )
	{
		dwIPR_Rcv = g_dwPrID;
        m_Edit3.SetWindowText(g_strDepoKl);        
		m_Edit3.EnableWindow(FALSE);
		m_Edit4.SetWindowText(g_strDepoName);
		m_ButRcv.EnableWindow(FALSE);
		m_Date1.InitDate();
		m_But2.EnableWindow();
		m_PrSnd.EnableWindow();
	} else
    if( iMode == 0 && !iRecieveMode )
    {
		dwIPR_Snd = g_dwPrID;
        sprintf(cQ, "pTov_GetNewVedNum %u", g_iDep);
        DBW.ExecSQL(cQ);
        if( (g_sqlret = DBW.Fetch()) == SQL_NO_DATA || 
             g_sqlret == SQL_ERROR ) return FALSE;
        DBW.GetData( 1, SQL_C_SLONG, &lNum, 4, &Ind);
        DBW.CloseCursor();
        itoa(lNum, cText, 10);
        m_Edit1.SetWindowText(cText);
        m_Date1.InitDate();
        m_PrSnd.SetWindowText(g_strDepoKl);
        m_EdPrSnd.SetWindowText(g_strDepoName);
        m_PrSnd.EnableWindow(FALSE);
        m_EdPrSnd.EnableWindow(FALSE);
        m_But2.EnableWindow(FALSE);
        m_ButMaterRcv.EnableWindow(FALSE);
    } else
    if( iMode == 1 || iRecieveMode)
    {
        itoa(dwVedNum, cText, 10);
        m_Edit1.SetWindowText(cText);
        m_Date1.SetTime(&stVedDate);
        m_Edit1.EnableWindow(FALSE);
        dwOldKPCount = dwKPCount;

        sprintf(cQ, "pTov_Peres_GetPVByID %I64u", qwIPeres);
        DBW.ExecSQL(cQ);
        if( g_sqlret == SQL_ERROR )
        {
            AfxMessageBox("SQL Error!");
            DBW.CloseCursor();
            return FALSE;
        }
        char cc[128] = "";
        DWORD dwNum = 0;
        SQL_DATE_STRUCT  sqlDat;
        SYSTEMTIME st;

        if( (g_sqlret = DBW.Fetch()) != SQL_NO_DATA )            
        {   			
            DBW.GetData( 1, SQL_C_SLONG, &lNum, 4, &Ind);
            if( lNum )
            {
                m_Combo1.SetCurSel(lNum - 1);
            }
            DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_Edit2.SetWindowText(cText);
            DBW.GetData( 3, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_Edit5.SetWindowText(cText);
            DBW.GetData( 4, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_Edit6.SetWindowText(cText);
            DBW.GetData( 5, SQL_C_ULONG, &dwFIO_Mast, 4, &Ind);
            DBW.GetData( 6, SQL_C_ULONG, &dwFIO_Priem, 4, &Ind);
            m_Edit5.SetData(dwFIO_Mast);
            m_Edit6.SetData(dwFIO_Priem);
            DBW.GetData( 7, SQL_C_UBIGINT, &qwIPeres, 8, &Ind);

            DBW.GetData( 8, SQL_C_DATE, &sqlDat, sizeof(sqlDat), &Ind);
            if( Ind != -1 )
            {
                SqlDateToSysTime(sqlDat, &st);
                m_Date1.SetTime(&st);
            }
			DBW.GetData( 9, SQL_C_ULONG, &dwIPR_Rcv, 4, &Ind);
			cText[0] = 0;

			DBW.GetData( 10, SQL_C_CHAR, cText, 64, &Ind);
            DBW.GetData( 11, SQL_C_CHAR, cc, 128, &Ind);
    		if( cText[0] ) m_Edit3.SetWindowText(cText);
            if( cc[0] ) m_Edit4.SetWindowText(cc);
            DBW.GetData( 12, SQL_C_ULONG, &dwNum, 4, &Ind);
            b1->SetCheck(dwNum);
            b2->SetCheck(!dwNum);

            DBW.GetData( 13, SQL_C_ULONG, &dwIPR_Snd, 4, &Ind);
            DBW.GetData( 14, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 )
            {
                m_PrSnd.SetWindowText(cText);                
            }
            DBW.GetData( 15, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 )
            {
                m_EdPrSnd.SetWindowText(cText);
            }
            DBW.GetData( 16, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_EdMasterRcv.SetData(dwNum);
                DBW.GetData( 17, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 )
                {
                    m_EdMasterRcv.SetWindowText(cText);
                }
            }
            DBW.GetData( 18, SQL_C_DATE, &sqlDat, sizeof(sqlDat), &Ind);
            if( Ind != -1 )
            {
                SqlDateToSysTime(sqlDat, &st);
                m_DatRcv.SetTime(&st);
            }
            DBW.GetData( 19, SQL_C_ULONG, &dwIPR_Sobst, 4, &Ind);
            DBW.GetData( 20, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 )
            {
                m_PrSobst.SetWindowText(cText);                
            }
            DBW.GetData( 21, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 )
            {
                m_EdPrSobst.SetWindowText(cText);
            }
			DBW.GetData( 22, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 )
            {
				m_Edit1.SetWindowText(cText);
            }

            iHeader = 1;
        } else iHeader = 0;
        DBW.CloseCursor();

/*
        m_Edit4.GetWindowText(cText, 64);        
        sprintf(cQ, "pTov_GetPredBySName '%s'", cText);
        cText[0] = 0;
        DBW.ExecSQL(cQ);
        if( (g_sqlret = DBW.Fetch()) != SQL_ERROR &&
             g_sqlret != SQL_NO_DATA )
        {
            DBW.GetData( 1, SQL_C_SLONG, &dwIPR, 4, &Ind);
            DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        }
        DBW.CloseCursor();
        m_Edit3.SetWindowText(cText);
*/
    }
    DBW.FillEmplArray(m_Edit5.lpEmpl, 8);
    DBW.FillEmplArray(m_Edit6.lpEmpl, 9);
    DBW.FillEmplArray(m_EdMasterRcv.lpEmpl, 1);
    m_CheckAll.ModifyStyle(WS_VISIBLE,0);
    if( iRecieveMode )
    {
        SetWindowText("Приходная пересылочная ведомость");
        if(!iCreateRecieveMode)m_List.SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );        
        m_CheckAll.ModifyStyle(0, WS_VISIBLE);
//        m_ButMaterRcv.EnableWindow(FALSE);
        m_ButRcv.EnableWindow(FALSE);
//        m_ButSobst.EnableWindow(FALSE);
        m_Edit3.EnableWindow(FALSE);
//        m_PrSobst.EnableWindow(FALSE);
        m_Date1.EnableWindow(FALSE);
        m_Combo1.EnableWindow(FALSE);
        b1->EnableWindow(FALSE);
        b2->EnableWindow(FALSE);
        m_Edit2.EnableWindow(FALSE);
        m_PrSnd.EnableWindow(FALSE);
        m_But2.EnableWindow(FALSE);
		m_Edit5.EnableWindow(FALSE);
		m_Edit6.EnableWindow(FALSE);
		m_ButPriemLow.EnableWindow(FALSE);
		m_ButMastLow.EnableWindow(FALSE);
		if( !iCreateRecieveMode )
		{
			m_Button3.ModifyStyle(WS_VISIBLE, 0);
			m_ButAddKP.ModifyStyle(WS_VISIBLE, 0);
			m_ButIzNal.ModifyStyle(WS_VISIBLE, 0);

		} else
		{
//			m_Button3.EnableWindow(FALSE);
			m_Date1.EnableWindow();
			m_Edit2.EnableWindow();
			b1->EnableWindow();
			b2->EnableWindow();
			m_Combo1.EnableWindow();
			m_PrSnd.EnableWindow();
			m_But2.EnableWindow();
			m_CheckAll.ModifyStyle(WS_VISIBLE,0);
//			m_Edit1.SetWindowText("");
		}
    } else
    {
        m_EdMasterRcv.EnableWindow(FALSE);
        m_DatRcv.EnableWindow(FALSE);
        m_But2.EnableWindow(FALSE);
        m_ButMaterRcv.EnableWindow(FALSE);
		dwIPR_Snd = g_dwPrID;
	}
	if( !iShowAddDelButtons )
	{
		m_Button3.ModifyStyle(WS_VISIBLE, 0);
		m_ButAddKP.ModifyStyle(WS_VISIBLE, 0);
//		m_ButIzNal.ModifyStyle(WS_VISIBLE, 0);
	} else
	{
		m_Button3.ModifyStyle( 0, WS_VISIBLE );
		m_ButAddKP.ModifyStyle( 0, WS_VISIBLE );
//		m_ButIzNal.ModifyStyle( 0, WS_VISIBLE );
	}

    GetKpList();
    DlgStarted = 1;
//    OnChangeEdit4();

	m_Menu = new CMenu;
    m_Menu->LoadMenu(IDR_MENU_PASPORT);


	return TRUE;
}

//получатель
void CDlgAddPeres::OnButton1() 
{
	/*
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_Edit3.SetWindowText(Dlg.cKodPr);
	dwIPR_Rcv = Dlg.ret_dwIPR;
    if( !Dlg.cKodPr[0] )
    {
        m_Edit4.SetWindowText(Dlg.cPrName);
    }
	*/
	CDlgSprPrSobstv Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

	
    m_Edit3.SetWindowText(Dlg.cKlPr);
	dwIPR_Rcv = Dlg.dwSobstID;
	m_Edit4.SetWindowText(Dlg.cPrName);
}

void CDlgAddPeres::OnChangeEdit4() 
{
    if( !DlgStarted || iRecieveMode ) return;
    char cText[64] = "";
    char cQ[64] = "";
    long Ind = 0;
    m_Edit3.GetWindowText(cText, 64);
	m_Edit4.SetWindowText("");
	if( cText[0] == 0 ) return;
    sprintf(cQ, "pTov_GetPartnByKl '%s'", cText);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();    
    if( g_sqlret == SQL_NO_DATA ||
        g_sqlret == SQL_ERROR )
    {
        DBW.CloseCursor();
        return;
    }
    DBW.GetData( 1, SQL_C_CHAR, cText, 64, &Ind);
    DBW.GetData( 2, SQL_C_SLONG, &dwIPR_Rcv, 4, &Ind);
    DBW.CloseCursor();
    m_Edit4.SetWindowText(cText);
}

//Master
void CDlgAddPeres::OnButton2() 
{
	CDlgSpravKdr Dlg;
    Dlg.DlgMode = 1;
    Dlg.iFilter = 8;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_Edit5.SetWindowText(Dlg.cFio);
    dwFIO_Mast = Dlg.dwFio;
    m_Edit5.SetData(dwFIO_Mast);
}

void CDlgAddPeres::OnButton4() 
{
	CDlgSpravKdr Dlg;
    Dlg.DlgMode = 1;
    Dlg.iFilter = 9;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_Edit6.SetWindowText(Dlg.cFio);
    dwFIO_Priem = Dlg.dwFio;
    m_Edit6.SetData(dwFIO_Priem);
}

//Add KP
void CDlgAddPeres::OnButton5() 
{
	CDlgAddKpSmall Dlg;
	if( iCreateRecieveMode )
	{
		Dlg.iCreateRecieveMode = 1;
	}
    SYSTEMTIME tm;
    ZeroMemory(&tm, sizeof(tm));
    m_Date1.GetTime(&tm);
    sprintf(Dlg.cDate, "%.4d%.2d%.2d", tm.wYear, tm.wMonth, tm.wDay);
    
	if( Dlg.DoModal() == IDCANCEL ) return;
    
	if( !iCreateRecieveMode && Dlg.qwIZAP == 0 ) return;

    for( DWORD i=0; i < 128 && i < dwKPCount && !iCreateRecieveMode; i++ )
    {
        if( qwIZAP[i] == Dlg.qwIZAP )
        {
            AfxMessageBox("Указанная КП уже занесена в ведомость!");
            return;
        }
    }
	DWORD dwCount = m_List.GetItemCount();
	char cText[64] = "";
	char cText2[64] = "";

	if( iCreateRecieveMode )
	{
		for( DWORD i=0; i < 128 && i < dwCount; i++ )
		{
			m_List.GetItemText(i, 0, cText, 64);
			m_List.GetItemText(i, 1, cText2, 64);
			if( Dlg.m_EditText == cText && Dlg.m_strTKP == cText2 )
			{
				AfxMessageBox("Указанная КП уже занесена в ведомость!");
				return;
			}
		}

		p_dwNeispID[dwCount] = Dlg.dwNeispID;
	}


    char cQ[64] = "";
	cText[0] = 0;
	long Ind = 0;
	if( !iCreateRecieveMode )
	{
		m_List.InsertItem(dwCount, Dlg.cNumKP);
		m_List.SetItemText(dwCount, 1, Dlg.m_strTKP);
		m_List.SetItemText(dwCount, 2, Dlg.cKlPrIzg);
		m_List.SetItemText(dwCount, 3, Dlg.cYearIzg);
		m_List.SetItemText(dwCount, 4, Dlg.cRemont64);
		

	} else
	{
		m_List.InsertItem(dwCount, Dlg.m_EditText);
		m_List.SetItemText(dwCount, 1, Dlg.m_strTKP);
		m_List.SetItemText(dwCount, 2, Dlg.cKlPrIzg);
		m_List.SetItemText(dwCount, 3, Dlg.cYearIzg);

		m_List.SetItemText(dwCount, 4, Dlg.m_strNeispName);
		p_dwTKP[dwCount] = Dlg.dwTypeKP;

	}
    itoa(dwCount + 1, cText, 10);
    m_CountCtrl.SetWindowText(cText);
    m_Button3.EnableWindow(TRUE);
    qwIKP[dwKPCount] = Dlg.qwIKP;
    qwIZAP[dwKPCount] = Dlg.qwIZAP;
    dwPriznRas[dwKPCount] = Dlg.dwPriznRas;
    dwGruz[dwKPCount] = Dlg.dwGruz;

	strncpy(cNKP[dwKPCount], Dlg.cNumKP, 12);
	p_dwTKP[dwKPCount] = Dlg.dwTypeKP;
	stDatIzg[dwKPCount] = Dlg.stDatIzg;
	dwIPrIzg[dwKPCount] = Dlg.dwIPrIzg;

	p_dwGreb_KP1[dwKPCount] = Dlg.dwGreb_KP1;
	p_dwGreb_KP2[dwKPCount] = Dlg.dwGreb_KP2;
	p_dwObod_KP1[dwKPCount] = Dlg.dwObod_KP1;
	p_dwObod_KP2[dwKPCount] = Dlg.dwObod_KP2;
	p_dProkat_KP1[dwKPCount] = Dlg.dProkat_KP1;
	p_dProkat_KP2[dwKPCount] = Dlg.dProkat_KP2;
	p_dDiam_KP1[dwCount] = Dlg.dDiam_KP1;
	p_dDiam_KP2[dwCount] = Dlg.dDiam_KP2;
	p_dwDisk_KP1[dwCount] = Dlg.dwDisk_KP1;
	p_dwDisk_KP2[dwCount] = Dlg.dwDisk_KP2;
	p_dwTypePodshASUV[dwCount] = Dlg.dwTPodsh == 0 ? 9 : Dlg.dwTPodsh;
	p_dwMSteel[dwCount] = Dlg.dwmSteel;



//	stDatIzg[dwCount] = Dlg.m_iYearIzg;
//	dwIprIzg[dwCount] = Dlg.m_iKlPrIzg;

	dwKPCount++;
}

//Remove KP
void CDlgAddPeres::OnButton6() 
{
	int idx = m_List.GetSelectionMark();
    if( idx == -1 || dwKPCount == 0 ) return;

	if(MessageBox("Вы уверены что хотите удалить колесную пару из пересылочной ведомости?", "Внимание", MB_YESNO) == IDNO) return;
/*
    if( iMode == 1 && (unsigned int)idx < dwOldKPCount)
    {
        AfxMessageBox("Указанной КП уже выполнен расход.\nКорректировку следует производить в базе данных.");
        return;
    }
*/
	if( !m_List.isItemEnabled( idx ) ) // Если КП серая, то ее нужно занести в список на удаление из БД
	{
		p_dwRemoved[ idx ] = 1;
		m_List.SetItemText( idx, 3, "УДАЛЕНА" );
		return;
	}


    for( DWORD i=idx; i < dwKPCount; i++ )
    {
        qwIKP[i] = qwIKP[i+1];
		qwIZAP[i] = qwIZAP[i + 1];
    }
    dwKPCount--;
    m_List.DeleteItem(idx);
    char cText[32]="";
    itoa(dwKPCount, cText, 10);
    m_CountCtrl.SetWindowText(cText);

    if( dwKPCount == 0 )
    {
        m_Button3.EnableWindow(FALSE);
    }
}

void CDlgAddPeres::OnAddVed() 
{
    char cQ[512] = "";
    char cText[64] = "";
    DWORD dwNum = 0;
    DWORD dwVedNum = 0;
    m_Edit1.GetWindowText(cText, 64);
	dwFIO_MastRcv = m_EdMasterRcv.GetData();
    if( cText[0] == 0 )
    {
        AfxMessageBox("Не введен номер ведомости!");
		m_Edit1.SetFocus();
        return;
    }
    dwNum = atoi(cText);
    if( dwNum == 0 )
    {
        AfxMessageBox("Номер ведомости не может быть равен нулю!");
		m_Edit1.SetFocus();
        return;
    }
    dwVedNum = dwNum;

	if( m_Date1.isNull() || !m_Date1.isValid() )
	{
		MessageBox("Не указана дата пересылки!","Внимание",MB_OK);
		m_Date1.SetFocus();
		return;
	}

	if( dwIPR_Rcv == dwIPR_Snd  )
	{
		AfxMessageBox("Предприятие оправитель и получатель должны быть разными! Невозможно отправить пересылку!");
		return;
	}

/*    SYSTEMTIME tm;
    memset(&tm, 0, sizeof(SYSTEMTIME));*/
    if( !iRecieveMode )
	{
		sprintf(cQ, "pTov_GetPeresByNumDate %d, %s, %u",
			    dwNum,
				m_Date1.GetSQLDate(),
				g_iDep);
  
		DBW.ExecSQL(cQ);
		if( (g_sqlret = DBW.Fetch())==SQL_ERROR )
		{
			AfxMessageBox("Ошибка добавления новой ведомости");
			DBW.CloseCursor();
			return;
		}
		if( iMode == 0 && g_sqlret != SQL_NO_DATA )
		{
			AfxMessageBox("В этом году уже оформлялась пересылочная ведомость с указанным номером!");
			DBW.CloseCursor();
			return;
		}
	    DBW.CloseCursor();
	}

    m_Edit2.GetWindowText(cText, 64);
    if( strlen(cText) > 10 )
    {
        AfxMessageBox("Номер вагона (автомобиля) не может привышать 9999999999!");
        return;
    }
    /*
    if( _atoi64(cText) == 0 )
    {
        AfxMessageBox("Некорректно указан номер вагона!");
        return;
    }
    */
    if( !dwIPR_Rcv )
    {
        AfxMessageBox("Не указано предприятие получатель!");
        return;
    }

    if( !dwIPR_Snd )
    {
        AfxMessageBox("Не указано предприятие отправитель!");
		m_PrSnd.SetFocus();
        return;
    }
	if( iRecieveMode )
	{
		if( !m_EdMasterRcv.GetData())
		{
			AfxMessageBox("Не указан мастер!");
			m_EdMasterRcv.SetFocus();
			return;
		}
		if( m_DatRcv.isNull() || !m_DatRcv.isValid() )
		{
			AfxMessageBox("Необходимо указать дату получения!");
			m_DatRcv.SetFocus();
			return;
		}
	}

	
	//    memset(&tm, 0, sizeof(SYSTEMTIME));
/*
    struct tm *tm_curtime = new( struct tm );
    time_t tTime;
    time(&tTime);
    CTime cTm1, cTm2 = tTime;
    m_Date1.GetTime(cTm1);
    if( cTm1 > cTm2 )
    {
        AfxMessageBox("Указанное число еще не наступило!");
        return;
    }*/
    m_Edit5.GetWindowText(cText, 64);
    if( !iRecieveMode && !iCreateRecieveMode && cText[0] == 0 )
    {
        AfxMessageBox("Введен несуществующий табельный номер мастера или человек с указанным номером не имеет права отправлять КП");
        return;
    }
    /*
    m_Edit6.GetWindowText(cText, 64);
    if( cText[0] == 0 )
    {
        AfxMessageBox("Введен несуществующий табельный номер приемщика или человек с указанным номером не имеет квалификации приемщика ВПВ");
        return;
    }
    */
    if( dwKPCount == 0 )
    {
        AfxMessageBox("Не занесены номера колесных пар!");
        return;
    }
    m_Date1.GetTime(&stVedDate);
    
    sprintf(cVedDate, "%.4d%.2d%.2d",
					stVedDate.wYear,
                    stVedDate.wMonth,
                    stVedDate.wDay);
    CButton *b = (CButton *)GetDlgItem(IDC_RADIO1);
    ASSERT(b);
    if( b->GetCheck() ) iOnVag = 1;
    dwFIO_Mast = m_Edit5.GetData();
    dwFIO_Priem = m_Edit6.GetData();

    if( !iRecieveMode ) 
    {
        CDlgWithAccelerators::OnOK();
        return;
    }
    char cNVag[64] = "";
    m_Edit2.GetWindowText(cNVag, 64);
    CButton *b1 = (CButton *)GetDlgItem(IDC_RADIO1);
/*
    sprintf(cQ, "pTov_InsertVedHdrPrih %u, %u, %s, %u, %u, NULL, %u, %s, %s, %s, %s",
            g_iDep,
            dwVedNum,
            m_Date1.GetSQLDate(),
            dwIPR_Snd,
            dwIPR_Sobst,
            b1->GetCheck(),
            isNull(cNVag),
            m_EdMasterRcv.GetDataAsString(TRUE),
            m_DatRcv.GetSQLDate(),
            isNull(g_iFam));*/

//	char cQRez[8192] = "";
	long Ind = 0;
	int	iNum = 0;
	dwNum = 0;
	char cMess[1024] = "";

	if( !iCreateRecieveMode )
	{
		sprintf(cQ, "pTov_KP_WriteVedHdr %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %u",
						isNull(qwIPeres),
						isNull(g_iDep),
						m_Edit1.GetString(1), //NVED
						m_Date1.GetSQLDate(), //дата отправки
						m_DatRcv.GetSQLDate(),//дата получения

						isNull(dwIPR_Snd),
						isNull(dwIPR_Rcv),
						isNull(dwIPR_Sobst),

						m_Combo1.GetCurSel() == -1 ? "NULL" : isNull( (DWORD)m_Combo1.GetCurSel() + 1 ),
						iOnVag,
						isNull(cNVag),

						isNull(m_Edit5.GetData()), //мастер отправитель
						isNull(m_Edit6.GetData()), //приемщик

						isNull(m_EdMasterRcv.GetData()),
						isNull(g_iFam),
						0 );

		DBW.ExecSQL(cQ);
		DBW.CloseCursor();

		if( g_iGotRezervDBW )
		{
			DBWrez.ExecSQL(cQ);
			DBWrez.CloseCursor();
		}

		__int64 qwIZapNew = 0;
		for( DWORD i=0; i < dwKPCount; i++ )
		{
			if( m_List.GetCheck(i) && m_List.isItemEnabled(i) )
			{
				qwIZapNew = 0;
				sprintf(cQ, "pTov_PrihodKPRcv %I64u, %I64u, %I64u, %u, %s",
					qwIPeres,
					qwIZAP[i],
					qwIKP[i],
					g_iDep,
					m_DatRcv.GetSQLDate());
				DBW.ExecSQL(cQ);
				DBW.Fetch();
				iNum = 0;
				DBW.GetData(1, SQL_C_SLONG, &iNum, 4, &Ind);
				if( iNum != 0 )
				{
					DBW.GetData(2, SQL_C_CHAR, &cMess, 1024, &Ind);
					AfxMessageBox(cMess);
				} else
				{
					DBW.GetData(2, SQL_C_UBIGINT, &qwIZapNew, sizeof(qwIZapNew), &Ind);
					if( g_iGotRezervDBW && qwIZapNew )
					{
						sprintf(cQ, "pTov_PrihodKPRcv %I64u, %I64u, %I64u, %u, %s, %s",
						qwIPeres,
						qwIZAP[i],
						qwIKP[i],
						g_iDep,
						m_DatRcv.GetSQLDate(),
						qwIZapNew); // на резервный отправляем с готовым новым izap

						DBWrez.ExecSQL(cQ);
						DBWrez.CloseCursor();
						DBWrez.ReallocHandle();
					}

				}

				DBW.CloseCursor();

			}
			// Смертельный номер (смена типа КП)
			if( p_dwNewTKP[i] != 0 && p_dwNewTKP[i] != 100 && p_dwTKP[i] == 100 )
			{
				sprintf(cQ, "exec pTov_SetTypeKP %s, %s",
						isNull(qwIZAP[i]),
						isNull(p_dwNewTKP[i]) );
				DBW.ExecSQL(cQ);
				DBW.Fetch();
				DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
				DBW.WriteLog(cText);
				DBW.CloseCursor();

			}
			
		}
	} else
	{
/*			if( iMode == 0 )
			{
				sprintf(cQ, "pTov_InsertVedHdrPrih %u, %u, %s, %u, %u, %s, %u, %s, %s, %s, %s",
						g_iDep,
						dwVedNum,
						m_Date1.GetSQLDate(),
						dwIPR_Snd,
						dwIPR_Sobst,
						m_Combo1.GetCurSel() == -1 ? "NULL" : isNull( (DWORD)m_Combo1.GetCurSel() + 1 ),
						b1->GetCheck(),
						isNull(cNVag),
						m_EdMasterRcv.GetDataAsString(TRUE),
						m_DatRcv.GetSQLDate(),
						isNull(g_iFam));
			} else
			{
				sprintf(cQ, "pTov_UpdateVedHdrPrih %I64u, %s, %s, %s, %s, %s, %u, %s, %s, %s, %s",
						qwIPeres,

						m_Edit1.GetString(1),
						m_Date1.GetSQLDate(),
						isNull(dwIPR_Snd),
						isNull(dwIPR_Sobst),
						m_Combo1.GetCurSel() == -1 ? "NULL" : isNull( (DWORD)m_Combo1.GetCurSel() + 1 ),
						iOnVag,
						isNull(cNVag),
						isNull(m_EdMasterRcv.GetData()),
						m_DatRcv.GetSQLDate(),
						isNull(g_iFam));
			}*/
			sprintf(cQ, "pTov_KP_WriteVedHdr %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %u",
						isNull(qwIPeres),
						isNull(g_iDep),
						m_Edit1.GetString(1), //NVED
						m_Date1.GetSQLDate(), //дата отправки
						m_DatRcv.GetSQLDate(),//дата получения

						isNull(dwIPR_Snd),
						isNull(dwIPR_Rcv),
						isNull(dwIPR_Sobst),

						m_Combo1.GetCurSel() == -1 ? "NULL" : isNull( (DWORD)m_Combo1.GetCurSel() + 1 ),
						iOnVag,
						isNull(cNVag),

						isNull(m_Edit5.GetData()), //мастер отправитель
						isNull(m_Edit6.GetData()), //приемщик

						isNull(m_EdMasterRcv.GetData()),
						isNull(g_iFam),
						0 );

			Ind = 0;
			DBW.ExecSQL(cQ);
			DBW.Fetch();
			DBW.GetData(1, SQL_C_UBIGINT, &qwIPeres, 8, &Ind);
			DBW.CloseCursor();

			if( g_iGotRezervDBW )
			{
				sprintf(cQ, "pTov_KP_WriteVedHdr %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %u",
							isNull(qwIPeres),
							isNull(g_iDep),
							m_Edit1.GetString(1), //NVED
							m_Date1.GetSQLDate(), //дата отправки
							m_DatRcv.GetSQLDate(),//дата получения

							isNull(dwIPR_Snd),
							isNull(dwIPR_Rcv),
							isNull(dwIPR_Sobst),

							m_Combo1.GetCurSel() == -1 ? "NULL" : isNull( (DWORD)m_Combo1.GetCurSel() + 1 ),
							iOnVag,
							isNull(cNVag),

							isNull(m_Edit5.GetData()), //мастер отправитель
							isNull(m_Edit6.GetData()), //приемщик

							isNull(m_EdMasterRcv.GetData()),
							isNull(g_iFam),
							0 );
				DBWrez.ExecSQL(cQ);
				DBWrez.CloseCursor();
				DBWrez.ReallocHandle();

			}
			
			char cNKP[32] = "";
			DWORD dwNeispID = 0;
			__int64 qwIZap = 0;
//			for( DWORD i=0; i < dwKPCount; i++ )
			for( DWORD i=dwOldKPCount; i < dwKPCount; i++ ) // заенсем только новые КП
			{
				if( m_List.isItemEnabled(i) )
				{
					m_List.GetItemText(i, 0, cNKP, 32);
//					i == -1 ? dwNeispID = 0 : dwNeispID = p_dwNeispID[i];
					dwNeispID = p_dwNeispID[i];
/*
					sprintf(cQ, "pTov_KP_Peres_Prihod %I64u, %s, %s, %u, %u, %s, %s",
							qwIPeres,
							isNull(qwIKP[i]),
							isNull(cNKP),
							p_dwTKP[i],
							g_iDep,
							m_DatRcv.GetSQLDate(),
							isNull(dwNeispID));
*/
					char cKlPr[16] = "";
					m_List.GetItemText(i, 2, cKlPr, 12);
					sprintf(cQ, "pTov_KP_WritePrihod %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s,  %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
					"NULL",
					g_iDep,
					isNull(cNKP),
					isNull(p_dwTKP[i]),
					isNull(cKlPr), //isNull(p->cIzgPr_KL),
					DateToSQL(stDatIzg[i]), //DateToSQL( p->stDatIzg ), 
					"NULL",
					m_DatRcv.GetSQLDate(),
					"NULL",
					"NULL",
					isNull(dwIPR_Snd),
					m_Date1.GetSQLDate(), //DateToSQL( p->stPeresDat ),
					m_Edit1.GetString(1), //isNull( p->dwNVedPeres ),
					"NULL", 
					"NULL",
					"NULL",
					"NULL",
					"NULL",
					"NULL", // m_DatFor.GetSQLDate(),
					"NULL",
					"NULL",
					"NULL",
					isNull(p_dwMSteel[i]),
					isNull(p_dwNeispID[i]),
					"NULL", //isNull( p->dwTREB_REM ),
					isNull(m_EdMasterRcv.GetData()), //isNull( p->dwFam ),
					"NULL",
					isNull(dwIPR_Sobst), //isNull( p->dwSobstIPRPrih ),
					"NULL",
					"NULL",
					"NULL",

					"NULL",
					"NULL",
					"NULL",
					"NULL",
					"NULL",
					isNull( qwIPeres ),
					"NULL",
					"NULL",
					isNull( p_dwTypePodshASUV[i] )
					);

					DBW.ExecSQL(cQ);
					DBW.Fetch();
					iNum = 0;
					DBW.GetData(1, SQL_C_SLONG, &iNum, 4, &Ind);
					if( iNum == -1 )
					{
						DBW.GetData(2, SQL_C_CHAR, cMess, 512, &Ind );
						AfxMessageBox(cMess);
					} else
					if( iNum == 0 )
					{
						DBW.GetData(2, SQL_C_ULONG, &qwIZap, sizeof(qwIZap), &Ind );
						DBW.CloseCursor();
						
						sprintf( cQ, "pTov_KP_UpdateRazmers2 %s, %s, %s, %s, %s, %f, %f, %s, %s, %s, %s",
								isNull( qwIZap ),
								isNull(p_dwObod_KP1[i]),
								isNull(p_dwObod_KP2[i]),
								isNull(p_dwGreb_KP1[i]),
								isNull(p_dwGreb_KP2[i]),
								p_dProkat_KP1[i],
								p_dProkat_KP2[i],								
								isNull(p_dDiam_KP1[i]),
								isNull(p_dDiam_KP2[i]),
								isNull(p_dwDisk_KP1[i]),
								isNull(p_dwDisk_KP2[i])
								);

						DBW.ExecSQL( cQ );
						DBW.CloseCursor();


						if( g_iGotRezervDBW )
						{
							sprintf(cQ, "pTov_KP_WritePrihod %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s,  %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
								isNull(qwIZap),
								g_iDep,
								isNull(cNKP),
								isNull(p_dwTKP[i]),
								"NULL",	"NULL",	"NULL",
								m_DatRcv.GetSQLDate(),
								"NULL",	"NULL",
								isNull(dwIPR_Snd),
								m_Date1.GetSQLDate(), //DateToSQL( p->stPeresDat ),
								m_Edit1.GetString(1), //isNull( p->dwNVedPeres ),
								"NULL",	"NULL",	"NULL",	"NULL",	"NULL",	"NULL", "NULL",	"NULL",	"NULL",
								isNull(p_dwMSteel[i]),
								isNull(p_dwNeispID[i]),
								"NULL", //isNull( p->dwTREB_REM ),
								isNull(m_EdMasterRcv.GetData()), //isNull( p->dwFam ),
								"NULL",
								isNull(dwIPR_Sobst), //isNull( p->dwSobstIPRPrih ),
								"NULL",	"NULL",	"NULL",	"NULL",	"NULL",	"NULL",	"NULL",	"NULL",
								isNull( qwIPeres ), "NULL", "NULL", isNull( p_dwTypePodshASUV[i]));

							DBWrez.ExecSQL(cQ);
							DBWrez.CloseCursor();

							sprintf( cQ, "pTov_KP_UpdateRazmers2 %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
								isNull( qwIZap ),
								isNull(p_dwObod_KP1[i]),
								isNull(p_dwObod_KP2[i]),
								isNull(p_dwGreb_KP1[i]),
								isNull(p_dwGreb_KP2[i]),
								isNull(p_dProkat_KP1[i]),
								isNull(p_dProkat_KP2[i]),
								isNull(p_dDiam_KP1[i]),
								isNull(p_dDiam_KP2[i]),
								isNull(p_dwDisk_KP1[i]),
								isNull(p_dwDisk_KP2[i])								
								);

							DBWrez.ExecSQL( cQ );
							DBWrez.CloseCursor();
							DBWrez.ReallocHandle();
						}

					}
					

				
				}
			}

			// Теперь удалим из базы приход КП которые были помечены на удаление
			for( int i = 0; i < dwOldKPCount; i++ )
			{
				if( p_dwRemoved[ i ] )
				{
					sprintf( cQ, "pTov_DeleteKP %s, %s", isNull( qwIZAP[ i ] ), isNull(g_iFam) );
					DBW.ExecSQL(cQ);
					DBW.CloseCursor();
					if( g_iGotRezervDBW )
					{
						DBWrez.ExecSQL(cQ);
						DBWrez.CloseCursor();
					}

				}
			}
	} 
	
	if( g_strAsldTeleName && iRecieveMode && g_iEnableTelecom && qwIPeres )
	{		
		char cText[20000] = "";
		long Ind = 0;
		char cQ[128] = "";
		
		if( g_iEnableTelecom && g_strAsldTeleName )
		{
				DWORD dwBadCount = 0;
				sprintf(cQ, "pTov_Peres_CanSendToAsuV %s", isNull(qwIPeres));
				DBW.ExecSQL( cQ );		
				DBW.Fetch();
				DBW.GetData(1, SQL_C_ULONG, &dwBadCount, 4, &Ind);
				DBW.CloseCursor();
				if( dwBadCount > 0 )
				{
					char cMess[255] = "";
					sprintf(cMess, "В пересылочной ведомости есть КП (%d шт.), информацию по которым, невозможно передать в АСЛД!", dwBadCount);
					AfxMessageBox(cMess);					
					//if( MessageBox(cMess, "", MB_YESNO) == IDNO) return;
				}
		}
		//sprintf( cQ, "pTov_Peres_SendToAsuV NULL, %s", isNull( qwIPeres) );
		
		sprintf( cQ, "pTov_Peres_SendToAsuV null, %s", isNull(qwIPeres) );
	//	g_LogEnabled = 0;
		DBW.ExecSQL( cQ );
	//	g_LogEnabled = 1;
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cText, 20000, &Ind);
		DBW.CloseCursor();
		char msg[255] = "";
		sprintf( msg, "Ind = %d | g_iEnableTelecom = %d | g_strAsldTeleName = %s", Ind, g_iEnableTelecom, g_strAsldTeleName );

		DBW.WriteLog( msg );
		if( Ind > 0 && g_iEnableTelecom && g_strAsldTeleName )
		{
			CString snd = (CString)"<tov><asld docid=\"1\">\n" + cText + (CString) "\n</asld></tov>";
			//DBW.SendMessageToDst( snd, "mkc", g_strAisldTeleName );
			DBW.WriteLog("Отправка данных в АС ЛД");
			if( tele ) tele->SendMessageDst(snd, &g_strAsldTeleName);
		}
	}

	/*
	else
	if( iMode == 1 && iCreateRecieveMode )
	{
		char cQ[512] = "";
		char cVagNum[32] = "";
		m_Edit2.GetWindowText(cVagNum, 31);


		sprintf(cQ, "pTov_UpdateVedHdrPrih %I64u, %s, %s, %s, %s, %s, %u, '%s', %s, %s, %s",
			qwIPeres,

			m_Edit1.GetString(1),
			m_Date1.GetSQLDate(),
			isNull(dwIPR_Snd),
			isNull(dwIPR_Sobst),
			"NULL",
			iOnVag,
			cVagNum,
			isNull(m_EdMasterRcv.GetData()),
			m_DatRcv.GetSQLDate(),
			isNull(g_iFam));

		DBW.ExecSQL(cQ);
		DBW.CloseCursor();

		for( DWORD i=dwOldKPCount; i < dwKPCount; i++ ) // заенсем только новые КП
		{
								m_List.GetItemText(i, 0, cNKP, 32);
//					i == -1 ? dwNeispID = 0 : dwNeispID = p_dwNeispID[i];
					dwNeispID = p_dwNeispID[i];
					sprintf(cQ, "pTov_PrihodKPPeres %I64u, %s, %s, %u, %u, %s, %s",
							qwIPeres,
							isNull(qwIKP[i]),
							isNull(cNKP),
							p_dwTKP[i],
							g_iDep,
							m_DatRcv.GetSQLDate(),
							isNull(dwNeispID));
							
					DBW.ExecSQL(cQ);
					DBW.Fetch();
					iNum = 0;
					DBW.GetData(1, SQL_C_SLONG, &iNum, 4, &Ind);
					if( iNum == -1 )
					{
						DBW.GetData(2, SQL_C_CHAR, cMess, 512, &Ind );
						AfxMessageBox(cMess);
					}
					DBW.CloseCursor();

		}

		return;

	}
*/

//	DBW.ExecSQLRzv(cQRez);
    CDlgWithAccelerators::OnOK();
}

void CDlgAddPeres::OnCancel() 
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;		
	CDlgWithAccelerators::OnCancel();
}

void CDlgAddPeres::GetKpList()
{
//    if( !iMode && !iRecieveMode ) return;
    char cQ[512] = "";
    long Ind = 0;
    char cText[64] = "";
    DWORD dwNum = 0;
    if( !iRecieveMode )
    {
		/*
        sprintf(cQ, "pTov_GetPeresKpList %u, %s, %u", dwVedNum, DateToSQL(stVedDate), g_iDep);
        DBW.ExecSQL(cQ);
        for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 1024; i++ )
        {
            DBW.GetData( 1, SQL_C_SBIGINT, &qwIKP[i], 8, &Ind);
            dwKPCount++;
            DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
            m_List.InsertItem(i, cText);
			strncpy(cNKP[i], cText, 11);
            DBW.GetData( 3, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 1, cText);
            DBW.GetData( 4, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 2, cText);
            DBW.GetData( 5, SQL_C_SBIGINT, &qwIZAP[i], 8, &Ind);
			m_List.EnableItem(i, false);
        }
        DBW.CloseCursor();
*/
        sprintf(cQ, "pTov_Peres_GetKPListPrih %I64u", qwIPeres);
        DBW.ExecSQL(cQ);
        for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 1024; i++ )
        {
            DBW.GetData( 1, SQL_C_ULONG, &dwNum, 4, &Ind);      
            DBW.GetData( 2, SQL_C_SBIGINT, &qwIZAP[i], 8, &Ind);
            DBW.GetData( 3, SQL_C_SBIGINT, &qwIKP[i], 8, &Ind);
			DBW.GetData( 4, SQL_C_CHAR, cText, 64, &Ind);
            dwKPCount++;
            m_List.InsertItem( i, cText);
			strncpy(cNKP[i], cText, 11);
            m_List.SetCheck(i, dwNum);
			m_List.EnableItem(i, 0);

            DBW.GetData( 5, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 1, cText);
            DBW.GetData( 6, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 4, cText);
			DBW.GetData( 7, SQL_C_ULONG, &p_dwTKP[i], 4, &Ind);
			if( Ind == -1 ) p_dwTKP[i] == 100;
			/*if(p_dwTKP[i] == 100 ) flag100 = 1;*/
			DBW.GetData( 8, SQL_C_ULONG, &dwIPrIzg[i], 4, &Ind);
			mgSQLGetSysDate(9, &stDatIzg[i], &Ind);
			DBW.GetData( 10, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 2, cText);
			DBW.GetData( 11, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 3, cText);
		}
		DBW.CloseCursor();
        itoa(dwKPCount, cText, 10);
        m_CountCtrl.SetWindowText(cText);
		dwOldKPCount = dwKPCount;
        return;
    }
/*	iRecieveMode = iRecieveMode;
	iCreateRecieveMode = iCreateRecieveMode;*/
	// Существующая (полученная) приходная ведомость
	int flag100 = 0;
    if( !iMode && !iCreateRecieveMode)
    {
        sprintf(cQ, "pTov_GetPeresKpListRcv %I64u", qwIPeres);
        DBW.ExecSQL(cQ);
        for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 1024; i++ )
        {
            DBW.GetData( 1, SQL_C_ULONG, &dwNum, 4, &Ind);      
            DBW.GetData( 2, SQL_C_SBIGINT, &qwIZAP[i], 8, &Ind);
            DBW.GetData( 3, SQL_C_SBIGINT, &qwIKP[i], 8, &Ind);
			DBW.GetData( 4, SQL_C_CHAR, cText, 64, &Ind);
            dwKPCount++;
            m_List.InsertItem( i, cText);
			strncpy(cNKP[i], cText, 11);
            m_List.SetCheck(i, dwNum);
			m_List.EnableItem(i, !dwNum);

            DBW.GetData( 5, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 1, cText);
            DBW.GetData( 6, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 4, cText);
			DBW.GetData( 7, SQL_C_ULONG, &p_dwTKP[i], 4, &Ind);
			if(p_dwTKP[i] == 100 ) flag100 = 1;
			DBW.GetData( 8, SQL_C_ULONG, &dwIPrIzg[i], 4, &Ind);
			mgSQLGetSysDate(9, &stDatIzg[i], &Ind);
			DBW.GetData( 10, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 2, cText);
			DBW.GetData( 11, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 3, cText);

        }
        DBW.CloseCursor();
        itoa(dwKPCount, cText, 10);
        m_CountCtrl.SetWindowText(cText);
		if( flag100 ) m_CheckAll.EnableWindow(FALSE);
    } 
	else
    {
        sprintf(cQ, "pTov_Peres_GetKPListPrih %I64u", qwIPeres);
        DBW.ExecSQL(cQ);
        for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 1024; i++ )
        {
            DBW.GetData( 1, SQL_C_ULONG, &dwNum, 4, &Ind);      
            DBW.GetData( 2, SQL_C_SBIGINT, &qwIZAP[i], 8, &Ind);
            DBW.GetData( 3, SQL_C_SBIGINT, &qwIKP[i], 8, &Ind);
			DBW.GetData( 4, SQL_C_CHAR, cText, 64, &Ind);
            dwKPCount++;
            m_List.InsertItem( i, cText);
			strncpy(cNKP[i], cText, 11);
            m_List.SetCheck(i, dwNum);
			m_List.EnableItem(i, !dwNum);

            DBW.GetData( 5, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 1, cText);
            DBW.GetData( 6, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 4, cText);
			DBW.GetData( 7, SQL_C_ULONG, &p_dwTKP[i], 4, &Ind);
			if(p_dwTKP[i] == 100 ) flag100 = 1;
			DBW.GetData( 8, SQL_C_ULONG, &dwIPrIzg[i], 4, &Ind);
			mgSQLGetSysDate(9, &stDatIzg[i], &Ind);
			DBW.GetData( 10, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 2, cText);
			DBW.GetData( 11, SQL_C_CHAR, cText, 64, &Ind);
            if( Ind != -1 ) m_List.SetItemText(i, 3, cText);

        }
        DBW.CloseCursor();
        itoa(dwKPCount, cText, 10);
        m_CountCtrl.SetWindowText(cText);
		dwOldKPCount = dwKPCount;
		if( flag100 ) m_CheckAll.EnableWindow(FALSE);    
	}
//    if( !iMode ) m_Menu->EnableMenuItem(ID_MENU_KP_REMOVE, FALSE);
//    if( !iMode ) m_Menu->ModifyMenu(ID_MENU_KP_REMOVE, MF_BYCOMMAND, 99999);
}

void CDlgAddPeres::OnButton_MasterRcv() 
{
	CDlgSpravKdr Dlg;
    Dlg.DlgMode = 1;
    Dlg.iFilter = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdMasterRcv.SetWindowText(Dlg.cFio);
    m_EdMasterRcv.SetData(Dlg.dwFio);
}

void CDlgAddPeres::OnButton_GetSobst() 
{
	/*
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 7;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_PrSobst.SetWindowText(Dlg.cKodPr);	
    m_EdPrSobst.SetWindowText(Dlg.cPrName);
    dwIPR_Sobst = Dlg.ret_dwIPR;
*/

	CDlgSprPrSobstv Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

    m_PrSobst.SetWindowText(Dlg.cKlPr);
	dwIPR_Sobst = Dlg.dwSobstID;
	m_EdPrSobst.SetWindowText(Dlg.cPrName);


}

void CDlgAddPeres::OnCheck_SelectAll() 
{
    for( int i=0; i < m_List.GetItemCount(); i++ ) m_List.SetCheck(i, m_CheckAll.GetCheck());	
}

void CDlgAddPeres::OnButton_PrSender() 
{
	/*
    CDlgSprav1 Dlg;
//    Dlg.iDlgKind = 7;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_PrSnd.SetWindowText(Dlg.cKodPr);	
    m_EdPrSnd.SetWindowText(Dlg.cPrName);
    dwIPR_Snd = Dlg.ret_dwIPR;
	*/
	CDlgSprPrSobstv Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

    m_PrSnd.SetWindowText(Dlg.cKlPr);
	dwIPR_Snd = Dlg.dwSobstID;
	m_EdPrSnd.SetWindowText(Dlg.cPrName);

}

void CDlgAddPeres::OnEnChangeEdit6()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDlgWithAccelerators::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CDlgAddPeres::OnNMRclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{	
	*pResult = 0;
    CPoint p;
    GetCursorPos(&p);
    CRect r;
    r.left = p.x;
    r.right = p.x + 100;
    r.top = p.y;
    r.bottom = p.y + 400;
	if( !m_Menu ) return;
    m_Menu->GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, p.x, p.y, this);

}

void CDlgAddPeres::OnMnuPsp()
{
	int idx = m_List.GetSelectionMark();
	if( idx < 0 ) return;
	
	CPrintableDlg Dlg;
    sprintf(Dlg.cQ, "pTov_mkcReportPasp %I64u", qwIZAP[idx]);
    Dlg.DoModal();
}

BOOL CDlgAddPeres::DestroyWindow()
{
	delete m_Menu;
	return CDlgWithAccelerators::DestroyWindow();
}

void CDlgAddPeres::OnEnChangeEditPrOtpr()
{
    if( !DlgStarted || !iRecieveMode ) return;
    char cText[64] = "";
    char cQ[64] = "";
    long Ind = 0;
    m_PrSnd.GetWindowText(cText, 64);
	m_EdPrSnd.SetWindowText("");
	if( cText[0] == 0 ) return;
    sprintf(cQ, "pTov_GetPartnByKl '%s'", cText);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    
    if( g_sqlret == SQL_NO_DATA ||
        g_sqlret == SQL_ERROR )
    {
        DBW.CloseCursor();
        return;
    }
    DBW.GetData( 1, SQL_C_CHAR, cText, 64, &Ind);
    DBW.GetData( 2, SQL_C_SLONG, &dwIPR_Snd, 4, &Ind);
    DBW.CloseCursor();
    m_EdPrSnd.SetWindowText(cText);
}

void CDlgAddPeres::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: Add your control notification handler code here
	if( !DlgStarted ) return;
	if( !iRecieveMode ) return;
	int idx = pNMLV->iItem;

//	int idx = m_List.GetSelectionMark();
	if( idx < 0 || idx > m_List.GetItemCount() ) return;

	if( p_dwTKP[idx] != 100 || p_dwNewTKP[idx] ) return;
	if( !m_List.GetCheck(idx) ) return;
	CDlgChangeTypeKP Dlg;
	Dlg.dwNewTypeKP = 100;
	Dlg.DoModal();
	p_dwNewTKP[idx] = Dlg.dwNewTypeKP;
	m_List.SetItemText(idx, 1, Dlg.cNewTypeName);
	*pResult = 0;

}

void CDlgAddPeres::OnBnClickedButton_SelFromNal()
{
	CDlgPrihKpList Dlg;
	Dlg.iModeCheckbox = 1;
	if( Dlg.DoModal() == IDCANCEL || !Dlg.iRetCount ) return;

	int c = m_List.GetItemCount();
	int fl = 0;
	long Ind = 0;
	char cQ[512] = "";
	char cText[64] = "";

	for( int i=0; i < Dlg.iRetCount; i++ )
	{
		fl = 0;
		for( int x=0; x < c; x++ )
		{
			if( qwIZAP[x] == Dlg.qwRetIzapList[ i ] )
			{
				fl = 1;
				break;
			}
		}
		if( fl == 0 )
		{
			sprintf( cQ, "pTov_KP_GetPrihodByIZap %I64u, %d", Dlg.qwRetIzapList[ i ], g_iDep );
			DBW.ExecSQL( cQ );
			DBW.Fetch();
			DBW.GetData( 1, SQL_C_CHAR, cText, 64, &Ind ); //номер
			if( Ind != -1 )
			{
				dwKPCount++;
				qwIZAP[ m_List.GetItemCount() ] = Dlg.qwRetIzapList[ i ];			
				m_List.InsertItem( m_List.GetItemCount(), cText);

				DBW.GetData( 3, SQL_C_CHAR, cText, 64, &Ind ); //тип
				if( Ind != -1 ) m_List.SetItemText( m_List.GetItemCount() - 1, 1, cText );
				DBW.GetData( 4, SQL_C_CHAR, cText, 64, &Ind ); //Клеймо
				if( Ind != -1 ) m_List.SetItemText( m_List.GetItemCount() - 1, 2, cText );
				SYSTEMTIME stt;
				mgSQLGetSysDate(5, &stt, &Ind);
				if( Ind != -1 ) 
				{
					itoa( stt.wYear, cText, 10);
					m_List.SetItemText( m_List.GetItemCount() - 1, 3, cText );
				}

				DBW.GetData( 15, SQL_C_CHAR, cText, 64, &Ind ); //неисправность
				if( Ind != -1 ) m_List.SetItemText( m_List.GetItemCount() - 1, 4, cText );
			}
			DBW.CloseCursor();
		}

	}
}

void CDlgAddPeres::OnHdnItemdblclickList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMHEADER phdr = reinterpret_cast<LPNMHEADER>(pNMHDR);
	
	*pResult = 0;
}

void CDlgAddPeres::OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	if( iCreateRecieveMode ) return;
	
	int idx = m_List.GetSelectionMark();
	if( idx < 0 || idx > m_List.GetItemCount() ) return;
	if( p_dwTKP[ idx ] != 100 ) return;


	CDlgSelKPType Dlg;
	Dlg.strNKP = cNKP[ idx ];
	if( Dlg.DoModal() == IDCANCEL ) return;

	if( Dlg.dwITKP == p_dwTKP[ idx ] ) return;
	p_dwNewTKP[ idx ] = Dlg.dwITKP;
	m_List.SetItemText( idx, 1, Dlg.strTKP );

	*pResult = 0;
}

void CDlgAddPeres::OnEnChangeEdit118()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDlgWithAccelerators::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CDlgAddPeres::OnBnClickedButton_ClearSobst()
{
	m_PrSobst.SetWindowText("");
	dwIPR_Sobst = 0;
	m_EdPrSobst.SetWindowText("");
}
