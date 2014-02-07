// DlgWheelsToVan.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgWheelsToVan.h"
#include "DlgShowTwin.h"
#include "DlgPrihodKP.h"
#include "DlgSpravKdr.h"
#include "DlgOldKPList.h"
#include "PrintableDlg.h"
#include ".\dlgwheelstovan.h"
#include "DlgRashod.h"
#include "DlgObmerKP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgWheelsToVan dialog


CDlgWheelsToVan::CDlgWheelsToVan(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgWheelsToVan::IDD, pParent)
{
    m_EdFam.SetMode(5);
    dwKPNum = 0;
    cVagDate[0]=0;
    cVagDatRem[0]=0;
    m_Dat.iMode = 1;
	m_DatRemIn.iMode = 1;
	m_DatRemOut.iMode = 1;
    m_EdFam.SetMode(5);
    DBW.FillEmplArray(m_EdFam.lpEmpl, 14);
	qwILK = 0;
    dwMaxKPCount = 8;
    iMode = 0;
    dwVRemVag_ID = 0;
    dwErasedCount = 0;
    dwEditedCount = 0;
    ZeroMemory(bListEnabled, sizeof(bListEnabled));
	bFromPTO = 0;
	//{{AFX_DATA_INIT(CDlgWheelsToVan)
	m_nVag = _T("");
	m_vRem = _T("");
	ZeroMemory(dwNeedUpdate, sizeof(dwNeedUpdate) );
	//}}AFX_DATA_INIT
}

extern char g_cVagNum[10];

void CDlgWheelsToVan::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgWheelsToVan)
	DDX_Control(pDX, IDC_EDIT8, m_Lbl);
	DDX_Control(pDX, IDC_BUTTON3, m_ButWas);
	DDX_Control(pDX, IDC_EDIT7, m_DatRemOut);
	DDX_Control(pDX, IDC_EDIT6, m_DatRemIn);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_BUTTON1, m_ButAddKP);
	DDX_Control(pDX, IDC_EDIT5, m_Dat);
	DDX_Control(pDX, IDC_EDIT4, m_EdFam);
	DDX_Control(pDX, IDC_EDIT3, m_NKP);
	DDX_Control(pDX, IDC_EDIT2, m_EdVRem);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_COMBO1, m_cb);
	DDX_Text(pDX, IDC_EDIT1, m_nVag);
	DDX_Text(pDX, IDC_EDIT2, m_vRem);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgWheelsToVan, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgWheelsToVan)
	ON_BN_CLICKED(IDC_BUTTON1, OnAddKP)
	ON_BN_CLICKED(IDC_BUTTON2, OnFamButClick)
	ON_BN_CLICKED(IDOK, OnAddToBase)
	ON_BN_CLICKED(IDC_BUTTON3, OnOldKPListClick)
	ON_NOTIFY(NM_DBLCLK, IDC_LIST1, OnDblclkList)
	ON_NOTIFY(NM_RCLICK, IDC_LIST1, OnRclickList1)
	ON_COMMAND(ID_MENU_KP_PASP, OnMenuKpPasp)
	ON_COMMAND(ID_MENU_KP_REMOVE, OnMenuKpRemove)
	//}}AFX_MSG_MAP		
	ON_COMMAND(ID_MENU_RASHODKP, OnMenuRashodKp)
	ON_COMMAND(ID_MENU_RAZMER_KP, OnMenuRazmerKp)
	ON_COMMAND(ID_MENU_PRIHOD_KP, OnMenuPrihodKp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgWheelsToVan message handlers

BOOL CDlgWheelsToVan::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

    m_List.InsertColumn(0, "Номер КП", LVCFMT_LEFT,  100, -1);
    m_List.InsertColumn(1, "Тип", LVCFMT_LEFT,  100, -1);
    if( !iMode )
    {
	    m_List.InsertColumn(2, "Дата выкатки", LVCFMT_LEFT,  100, -1);
        m_Lbl.SetWindowText("Дата выкатки:");
    } else
    {
        m_List.InsertColumn(2, "Дата подкатки", LVCFMT_LEFT,  100, -1);
        SetWindowText("Оформление расхода КП, подкаченных под вагон");
        m_ButWas.SetWindowText("Были выкачены...");
        m_Lbl.SetWindowText("Дата подкатки:");
    }
	m_List.InsertColumn(3, "Мастер", LVCFMT_LEFT,  100, -1);

    DBW.FillComboWithTKP(&m_cb);

	char cQ[128] = "";
	long Ind = 0;
	char cText[64] = "";

	if( bFromPTO )
	{	
		SYSTEMTIME st;
		sprintf(cQ, "pTov_GetILKbyNVagRepairing %d, '%s'", g_iDep, g_cVagNum );
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_SBIGINT, &qwILK, 8, &Ind);
		if( Ind != -1 && qwILK == -1 )
		{
			char cMess[300] = "";
			DBW.GetData(2, SQL_C_CHAR, cMess, 300, &Ind );
			DBW.WriteLog(cMess);
			DBW.CloseCursor();
			AfxMessageBox(cMess);
			g_conf_MessageOnCancel = 0; // не будем ничего спрашивать при закрытии
			OnCancel();
			return FALSE;
		}
		DBW.GetData(2, SQL_C_ULONG, &dwVRemVag_ID, 4, &Ind );
		DBW.GetData(3, SQL_C_CHAR, &cText, 64, &Ind );
		if( Ind != -1 ) 
		{
			m_EdVRem.SetWindowText(cText);
		}
		mgSQLGetSysDate(4, &st, &Ind);
		if(Ind != -1 )
		{
			DateToStrRus( st, cText );
			m_DatRemInStr = cText;
		}
		mgSQLGetSysDate(5, &st, &Ind);
		if(Ind != -1 )
		{
			DateToStrRus( st, cText );
			m_DatRemOutStr = cText;
		}
		DBW.CloseCursor();
		m_EdNVag.SetWindowText(g_cVagNum);
		m_nVag = g_cVagNum;

		if( iMode ) qwLKID = qwILK;

	}

	sprintf( cQ, "ptov_GetRemVagIDByILK %I64u", qwILK );
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_ULONG, &dwVRemVag_ID, 4, &Ind);
	DBW.CloseCursor();

    m_cb.SetCurSel(0);
//    m_Dat.SetTime(); /*!!!!!!!!!!!!!!!!!!!!!!!*/
    m_Dat.InitDate();
	m_DatRemIn.SetWindowText(m_DatRemInStr);
    char dd[20] = "";
    strcpy(dd, m_DatRemInStr);
    dd[2] = '.';
    dd[5] = '.';
    m_Dat.SetWindowText(dd);
    
	m_DatRemOut.SetWindowText(cVagDatRem);
    IniKPList();

    DBW.FillEmplArray(m_EdFam.lpEmpl, iMode == 0 ? 1 : 10);

    m_Menu = new CMenu;
    m_Menu->LoadMenu(IDR_MENU_KP_RASH);
//    if( !iMode ) m_Menu->EnableMenuItem(ID_MENU_KP_REMOVE, FALSE);
    if( !iMode ) m_Menu->ModifyMenu(ID_MENU_KP_REMOVE, MF_BYCOMMAND, 99999);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgWheelsToVan::OnAddKP() 
{
	CString str;
    CString s;
    DWORD   dwNum = 0;
    long    Ind = 0;

    if( m_NKP.GetWindowTextLength() <= 0 )
    {
        AfxMessageBox("Не указан номер КП!");
        return;
    }
    m_NKP.GetWindowText(s);

    CString strTmp, s1;
    // Проверим есть ли она в списке уже
    for( int i = 0; i < m_List.GetItemCount(); i++ )
    {
        m_cb.GetWindowText(s1);
        if( s == m_List.GetItemText(i, 0) && 
            m_List.GetItemText(i,1) == s1 )
        {
            AfxMessageBox("Указанная КП уже есть в списке!", MB_OK);
            return;
        }
    }

    char cQ[255] = "";

    int iRet = 0;
    char cMsg[364] = "";
    __int64 qwIZAP = 0;
    DWORD dwPriznRas = 0, dwGruz = 0;

    if( iMode ) // Подкатка (Расход КП)
    {
        for( DWORD i=0; i < dwErasedCount; i++ )
        {
            if( s == p_ErasedPasp[i].cNKP && p_ErasedPasp[i].dwTKP == m_cb.GetItemData(m_cb.GetCurSel()))
            {
                pPasp[dwKPNum] = p_ErasedPasp[i];
                pPrih[dwKPNum] = p_ErasedPrih[i];
                RemoveFromRemoved(p_ErasedPrih[i].qwIZAP);
                dwKPNum++;
                RefreshKPList();
                return;
            }
        }
        str.Format("pTov_GetKPForVanR %u, '%s', %u, %s",
                    g_iDep,
                    s,
                    m_cb.GetItemData(m_cb.GetCurSel()),
                    isNull(dwVRemVag_ID));

        DBW.ExecSQL(str);
        DBW.Fetch();
        DBW.GetData(1, SQL_C_SLONG, &iRet, sizeof(int), &Ind);
        if( iRet == -1 )
        {
            DBW.GetData(2, SQL_C_CHAR, cMsg, 364, &Ind);
            AfxMessageBox(cMsg);
            DBW.CloseCursor();
            return;
        } else
        if( iRet == 1 )
        {
            DBW.GetData(2, SQL_C_CHAR, cMsg, 364, &Ind);
            if( MessageBox(cMsg, "Внимание!", MB_YESNO) == IDNO ) 
            {
                DBW.CloseCursor();
                return;           
            }
        }
        DBW.GetData(3, SQL_C_UBIGINT, &pPrih[dwKPNum].qwIZAP, 8, &Ind );
        DBW.GetData(4, SQL_C_ULONG, &pPrih[dwKPNum].dwPriznRas, 4, &Ind );
        DBW.GetData(5, SQL_C_ULONG, &dwGruz, 4, &Ind );
        DBW.GetData(6, SQL_C_UBIGINT, &pPrih[dwKPNum].qwIKP, 8, &Ind );
        DBW.CloseCursor();

        pPrih[dwKPNum].wGruz = (WORD)dwGruz;
        pPrih[dwKPNum].dwFamRash = m_EdFam.GetData();
        m_EdFam.GetWindowText(pPrih[dwKPNum].cFamRash, 32);
        m_Dat.GetTime(&pPrih[dwKPNum].stDatRash);
        bListEnabled[dwKPNum] = TRUE;
        strcpy(pPrih[dwKPNum].cNKP, s);
        pPrih[dwKPNum].dwTKP = m_cb.GetItemData(m_cb.GetCurSel());
        m_cb.GetWindowText(pPrih[dwKPNum].cTKP, 12);
        RemoveFromRemoved(pPrih[dwKPNum].qwIZAP);
		DBW.LoadPrihdKP( &pPrih[dwKPNum], pPrih[dwKPNum].qwIZAP );
		m_Dat.GetTime( &pPrih[dwKPNum].stDatRash );
		pPrih[dwKPNum].dwFamRash = m_EdFam.GetData();
		m_EdFam.GetWindowText( pPrih[dwKPNum].cFamRash, 31 );
        dwKPNum++;
        RefreshKPList();
    } else
    if( !iMode )
    {
        str.Format("pTov_GetKPCountByNKP '%s', %u",
                    s,
                    m_cb.GetItemData(m_cb.GetCurSel()));
        DBW.ExecSQL(str);
        DBW.Fetch();
        DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
        DBW.CloseCursor();
        char cQ[255] = "";
    
        if( dwNum == 0 )
        {
    newkp:
            CDlgPrihodKP Dlg;
            Dlg.iZp = 0;
            Dlg.iFo = 0;
			m_NKP.GetWindowText(s);
            strcpy(Dlg.PrihKp.cNKP, (LPCTSTR)s);
            Dlg.PrihKp.dwTKP = m_cb.GetItemData(m_cb.GetCurSel());            
			Dlg.iTKP = m_cb.GetItemData(m_cb.GetCurSel());

			strncpy( Dlg.cNKP, s, 21);
			strncpy( Dlg.PrihKp.cNKP, s, 21);

            m_cb.GetWindowText(s);			
			
            strcpy(Dlg.PrihKp.cTKP, s);
            m_EdFam.GetWindowText(s);
            Dlg.m_strFIO = s;
		    Dlg.dwIFam = m_EdFam.GetData();
			Dlg.PrihKp.dwFam = m_EdFam.GetData();
			Dlg.PrihKp.dwRemVagID = dwVRemVag_ID;
            Dlg.iMode = 2;

			strcpy(Dlg.PrihKp.cPrihNVag, m_nVag);
		    m_Dat.GetTime(&Dlg.PrihKp.stDatPost);

			Dlg.iInitFrom = INIT_FROM_GIVEN_SIMPLE;
            if( Dlg.DoModal() == IDCANCEL ) return;

			dwNeedUpdate[ dwKPNum ] = 1;
            pPrih[dwKPNum] = Dlg.PrihKp;
//            pPasp[dwKPNum] = Dlg.PaspKp;
            m_cb.GetLBText(m_cb.GetCurSel(), str);
            m_List.InsertItem(m_List.GetItemCount(), pPrih[dwKPNum].cNKP);
            m_List.SetItemText(m_List.GetItemCount() - 1, 1, (LPCTSTR)str);
		    char tt[64] = "";
		    DateToStrRus(Dlg.PrihKp.stDatPost, tt);
		    m_List.SetItemText(m_List.GetItemCount() - 1, 2, tt);
		    m_List.SetItemText(m_List.GetItemCount() - 1, 3, Dlg.PrihKp.cFam);
            p_bGotPasp[dwKPNum] = false;
            dwKPNum++;
        } else
        {
            char cQ[64] = "";
            if( dwNum == 1 )
            {
                CDlgPrihodKP Dlg;
                sprintf(cQ, "pTov_GetIKPByNumKP '%s', %u", s, m_cb.GetItemData(m_cb.GetCurSel()));
                DBW.ExecSQL(cQ);
                DBW.Fetch();
                DBW.GetData(1, SQL_C_UBIGINT, &Dlg.PaspKp.qwIKP, 8, &Ind);
                DBW.CloseCursor();
        //        DBW.GetPaspKP(Dlg.PaspKp.qwIKP, &Dlg.PaspKp);
                strcpy(Dlg.PaspKp.cNKP, (LPCTSTR)s);
                Dlg.PaspKp.dwTKP = m_cb.GetItemData(m_cb.GetCurSel());
                Dlg.m_strNumVag = m_nVag;
				

                Dlg.m_strNumKP = CString("Номер: ") + s;
                m_cb.GetWindowText(s);
                Dlg.m_strTypeKP =  CString("Тип: ") + s;
                Dlg.PaspKp.dwTKP = m_cb.GetItemData(m_cb.GetCurSel());
                strcpy(Dlg.PaspKp.cTKP, s);
                m_EdFam.GetWindowText(s);
                Dlg.m_strFIO = s;
		        Dlg.dwIFam = m_EdFam.GetData();
                Dlg.iMode = 2;
                Dlg.PrihKp.dwFam = m_EdFam.GetData();

		        Dlg.PrihKp.dwRemVagID = dwVRemVag_ID;
		        strcpy(Dlg.PrihKp.cPrihNVag, m_nVag);
		        m_Dat.GetTime(&Dlg.PrihKp.stDatPost);

                SelPrih(Dlg.PaspKp.qwIKP, Dlg.PaspKp, Dlg.PrihKp, Dlg.iFo, Dlg.iZp);
                Dlg.PrihKp.dwFam = m_EdFam.GetData();
//		        Dlg.PrihKp.dwRemVagID = dwVRemVag_ID;
		        strcpy(Dlg.PrihKp.cPrihNVag, m_nVag);
		        m_Dat.GetTime(&Dlg.PrihKp.stDatPost);

                char cText[64] = "";
                int  iNum = 0;
                sprintf(cQ, "pTov_CheckPrihodExists %I64u, %I64u", Dlg.PaspKp.qwIKP, qwILK);
                DBW.ExecSQL(cQ);
                DBW.Fetch();
                DBW.GetData(1, SQL_C_SLONG, &iNum, 4, &Ind);
                if( iNum == 1 )
                {
                    DBW.GetData(2, SQL_C_UBIGINT, &Dlg.PrihKp.qwIZAP, 4, &Ind);
                } else
                if( iNum == -1 )
                {
                    DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
                    AfxMessageBox(cText);
                    DBW.CloseCursor();
                    return;
                }
                DBW.CloseCursor();
                DBW.GetPrihodKP(Dlg.PrihKp.qwIZAP, &Dlg.PrihKp);

                Dlg.iMode = 2;
                if( Dlg.DoModal() == IDCANCEL ) return;

                pPrih[dwKPNum] = Dlg.PrihKp;
                pPasp[dwKPNum] = Dlg.PaspKp;
                p_bGotPasp[dwKPNum] = false;

                m_cb.GetLBText(m_cb.GetCurSel(), str);
                m_List.InsertItem(m_List.GetItemCount(), pPasp[dwKPNum].cNKP);
                m_List.SetItemText(m_List.GetItemCount() - 1, 1, (LPCTSTR)str);
		        char tt[64] = "";
		        DateToStrRus(Dlg.PrihKp.stDatPost, tt);
		        m_List.SetItemText(m_List.GetItemCount() - 1, 2, tt);
		        m_List.SetItemText(m_List.GetItemCount() - 1, 3, Dlg.PrihKp.cFam);

                dwKPNum++;
            } else
            if( dwNum > 1 )
            {
                m_NKP.GetWindowText(s);
                CDlgShowTwin Dlg;
                strcpy(Dlg.cNKP, (LPCSTR)s);
                m_cb.GetWindowText(s);
                strcpy(Dlg.cTKP, (LPCSTR)s);
                Dlg.dwTKP = m_cb.GetItemData(m_cb.GetCurSel());

                if( Dlg.DoModal() == IDCANCEL ) return;
                if( Dlg.iRez == 1 ) goto newkp;
                CDlgPrihodKP Dlg1;
                SelPrih(Dlg.qwIKP, Dlg1.PaspKp, Dlg1.PrihKp, Dlg1.iFo, Dlg1.iZp);
				if( Dlg1.PaspKp.cNKP[0] == 0 )
				{
					m_NKP.GetWindowText(s);
					strcpy(Dlg1.PaspKp.cNKP, (LPCSTR)s);
				}
				if( !Dlg1.PaspKp.dwTKP )
				{
					Dlg1.PaspKp.dwTKP = m_cb.GetItemData(m_cb.GetCurSel());
					m_cb.GetWindowText(s);
					strcpy(Dlg1.PaspKp.cTKP, (LPCSTR)s);
				}

				
                char cText[64] = "";
                int  iNum = 0;
                sprintf(cQ, "pTov_CheckPrihodExists %I64u, %I64u", Dlg1.PaspKp.qwIKP, qwILK);
                DBW.ExecSQL(cQ);
                DBW.Fetch();
                DBW.GetData(1, SQL_C_SLONG, &iNum, 4, &Ind);
                if( iNum == 1 )
                {
                    DBW.GetData(2, SQL_C_UBIGINT, &Dlg1.PrihKp.qwIZAP, 4, &Ind);
                } else
                if( iNum == -1 )
                {
                    DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
                    AfxMessageBox(cText);
                    DBW.CloseCursor();
                    return;
                }
                DBW.CloseCursor();

                DBW.GetPrihodKP(Dlg1.PrihKp.qwIZAP, &Dlg1.PrihKp);            
				if( Dlg1.m_strNumVag == "" )Dlg1.m_strNumVag = m_nVag;
				if( !Dlg1.PrihKp.dwRemVagID ) 
				{
					Dlg1.PrihKp.dwRemVagID = dwVRemVag_ID;
				}

                if( Dlg1.DoModal() == IDCANCEL ) return;

                pPrih[dwKPNum] = Dlg1.PrihKp;
                pPasp[dwKPNum] = Dlg1.PaspKp;
                m_cb.GetLBText(m_cb.GetCurSel(), str);
                m_List.InsertItem(m_List.GetItemCount(), pPasp[dwKPNum].cNKP);
                m_List.SetItemText(m_List.GetItemCount() - 1, 1, (LPCTSTR)str);
		        char tt[64] = "";
		        DateToStrRus(Dlg1.PrihKp.stDatPost, tt);
		        m_List.SetItemText(m_List.GetItemCount() - 1, 2, tt);
		        m_List.SetItemText(m_List.GetItemCount() - 1, 3, Dlg1.PrihKp.cFam);

                p_bGotPasp[dwKPNum] = false;
                dwKPNum++;
            }
        }
    }
//
    if( dwKPNum >= 8 ) m_ButAddKP.EnableWindow(FALSE);
/*
    else
    if( dwNum > 1 )
    {
        CDlgShowTwin Dlg;
        Dlg.dwTKP = m_cb.GetItemData(m_cb.GetCurSel());
        strcpy(Dlg.cNKP, s);
        if( Dlg.DoModal() == IDCANCEL ) return;
    }
    m_cb.GetLBText(m_cb.GetCurSel(), str);
    m_List.InsertItem(m_List.GetItemCount(), s);
    m_List.SetItemText(m_List.GetItemCount() - 1, 1, (LPCTSTR)str);
*/
//    m_List.SetItemData();
}


void CDlgWheelsToVan::OnFamButClick() 
{
	CDlgSpravKdr Dlg;
    if( !iMode )
        Dlg.iFilter = 1;
    else
        Dlg.iFilter = 10;

    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;

    m_EdFam.SetData(Dlg.dwFio);
    m_EdFam.SetWindowText(Dlg.cFio);

}

void CDlgWheelsToVan::OnAddToBase() 
{
    CString sQ;
    long    Ind = 0;
    char cD1[16] = "", cD2[16] = "";

    m_DatRemIn.GetWindowText(cD1, 16);
    m_DatRemOut.GetWindowText(cD2, 16);

    if( cD1[0] && SysDateCmp(RusDateToSysDate(cD1), m_Dat.GetAsSystemTime() ) > 0 )
    {
        if( !iMode ) MessageBox("Дата выкатки не может быть раньше даты поступления в ремонт", "Внимание", MB_OK);
        else MessageBox("Дата подкатки не может быть раньше даты поступления в ремонт", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( cD2[0] && SysDateCmp(RusDateToSysDate(cD2), m_Dat.GetAsSystemTime()) < 0 )
    {
        if( !iMode ) MessageBox("Дата выкатки не может быть позже даты выхода из ремонта", "Внимание", MB_OK);
        else MessageBox("Дата подкатки не может быть позже даты выхода из ремонта", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    
    if( !iMode ) // Выкатка КП (приход)
    {
        for( DWORD i = 0; i < dwKPNum && i < 16; i++ )
        {
//		    DBW.WritePrihodKP( &pPrih[i], &pPasp[i], TRUE, qwILK);
			if( dwNeedUpdate[i] ) DBW.WritePrihodKP( &pPrih[i], 1, qwILK );

        }
    } else
    {		// Подкадка КП (расход)
        //Удаляем удаленные
        for( DWORD i=0; i < dwErasedCount; i++ )
        {
            sQ.Format("pTov_RashodKPDel %I64u, %s", 
                        p_ErasedPrih[i].qwIZAP,
                        isNull(g_iFam));
            DBW.ExecSQL(sQ);
            DBW.CloseCursor();
            DBW.ReallocHandle();
        }
        //Изменяем измененные
//        for( DWORD i=0; i < 
        //Добавляем добавленные
        for(DWORD i = 0; i < dwKPNum; i++ )
        {
            if( m_List.isItemEnabled(i) )
            {
                pPrih[i].dwPriznRas = 91+(pPrih[i].dwPriznRas / 10);
                sQ.Format("pTov_KP_RashodKP %I64u, %u, %u, %u, %s, %s, %u, '%s', NULL, NULL, NULL, %s",
                        pPrih[i].qwIZAP,
                        g_iDep,
                        pPrih[i].dwPriznRas,
                        pPasp[i].wGruz,
                        isNull(pPrih[i].dwFamRash),
                        m_Dat.GetSQLDate(),
                        dwVRemVag_ID,
                        m_nVag,
                        isNull(qwLKID));
                DBW.ExecSQL(sQ);
                DBW.CloseCursor();
                DBW.ReallocHandle();

				if( g_iGotRezervDBW )
				{
					DBWrez.ExecSQL(sQ);
					DBWrez.CloseCursor();
					DBWrez.ReallocHandle();
				}
            }
        }
    }
    CDlgWithAccelerators::OnOK();
}

int CDlgWheelsToVan::IniKPList()
{
    CString cQ;
    char cText[64] = "";
    DWORD   dwNum = 0;
    long    Ind = 0;
    DWORD dwFam = 0;
    CString cFam = "";
	SYSTEMTIME st1;
	st1.wDay = 01;
	st1.wMonth = 01;
	st1.wYear = 1800;

    if( !iMode )
    {
        cQ.Format("pTov_GetWheelsByVagRem %I64u",
		    	  qwILK);
        DBW.ExecSQL(cQ);
        dwKPNum = 0;
	    SQL_DATE_STRUCT  sqlDat;
        for(int i=0; (g_sqlret = DBW.Fetch())!=SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 16; i++ )
        {
            DBW.GetData(1, SQL_C_UBIGINT, &pPrih[dwKPNum].qwIZAP, 8, &Ind);
            DBW.GetData(2, SQL_C_CHAR, pPrih[dwKPNum].cNKP, 32, &Ind);
            DBW.GetData(3, SQL_C_ULONG, &pPrih[dwKPNum].dwTKP, 4, &Ind);
            DBW.GetData(4, SQL_C_CHAR, pPrih[dwKPNum].cTKP, 32, &Ind);
		    DBW.GetData(5, SQL_C_DATE, &sqlDat, 32, &Ind);
		    SqlDateToSysTime(sqlDat, &pPrih[dwKPNum].stDatPost);
		    
            m_List.InsertItem(i, pPrih[i].cNKP);
            m_List.SetItemText(i, 1, pPrih[i].cTKP);
            m_List.EnableItem(i, FALSE);
		    DateToStrRus(pPrih[dwKPNum].stDatPost, cText);
		    m_List.SetItemText(i, 2, cText);
            
            DBW.GetData(14, SQL_C_CHAR, cText, 32, &Ind);
		    m_List.SetItemText(i, 3, cText);
            DBW.GetData(28, SQL_C_ULONG, &dwNum, 4, &Ind);        
		    if( SysDateCmp(pPrih[dwKPNum].stDatPost, st1) > 0 )
		    {
			    st1 = pPrih[dwKPNum].stDatPost;
			    dwFam = dwNum;
			    cFam = cText;
		    }

		    DBW.GetData(30, SQL_C_UBIGINT, &pPrih[dwKPNum].qwIKP, 8, &Ind);
            bListEnabled[dwKPNum] = false;
            dwKPNum++;
        }
        DBW.CloseCursor();
	    m_EdFam.SetWindowText(cFam);
	    m_EdFam.SetData(dwFam);
	    m_Dat.SetTime(&st1);

    //    RefreshKPList();
        dwKPInitNum = dwKPNum;
    } else
    {
        cQ.Format("pTov_GetWheelsByVagRem2 %I64u",
		    	  qwILK);
        DBW.ExecSQL(cQ);
        dwKPNum = 0;
	    SQL_DATE_STRUCT  sqlDat;
        for(int i=0; (g_sqlret = DBW.Fetch())!=SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 16; i++ )
        {
            DBW.GetData(1, SQL_C_UBIGINT, &pPrih[dwKPNum].qwIZAP, 8, &Ind);
            DBW.GetData(2, SQL_C_ULONG, &pPrih[dwKPNum].dwFamRash, 4, &Ind);
            DBW.GetData(3, SQL_C_CHAR, pPrih[dwKPNum].cNKP, 32, &Ind);
            DBW.GetData(4, SQL_C_CHAR, &pPrih[dwKPNum].cTKP, 16, &Ind);
            DBW.GetData(5, SQL_C_DATE, &sqlDat, 32, &Ind);
		    SqlDateToSysTime(sqlDat, &pPrih[dwKPNum].stDatRash);

            m_List.InsertItem(i, pPrih[i].cNKP);
            m_List.SetItemText(i, 1, pPrih[i].cTKP);
            m_List.EnableItem(i, FALSE);
		    DateToStrRus(pPrih[dwKPNum].stDatRash, cText);
		    m_List.SetItemText(i, 2, cText);

            DBW.GetData(6, SQL_C_CHAR, cText, 32, &Ind);
		    m_List.SetItemText(i, 3, cText);
            strcpy(pPrih[dwKPNum].cFamRash, cText);
            DBW.GetData(7, SQL_C_ULONG, &dwNum, 4, &Ind); 
		    if( SysDateCmp(pPrih[dwKPNum].stDatRash, st1) > 0 )
		    {
			    st1 = pPrih[dwKPNum].stDatRash;
			    dwFam = dwNum;
			    cFam = cText;
		    }
            DBW.GetData(8, SQL_C_ULONG, &pPrih[dwKPNum].dwTKP, 4, &Ind);

            dwKPNum++;
        }
        DBW.CloseCursor();
        if ( dwKPNum > 0 )
        {
	        m_EdFam.SetWindowText(cFam);
	        m_EdFam.SetData(dwFam);
	        m_Dat.SetTime(&st1);
        } else
        {
            m_DatRemOut.GetWindowText(cText, 64);
            cText[2] = '.';
            cText[5] = '.';
            m_Dat.SetWindowText(cText);
        }
    }
    if( dwKPNum >= 8 ) m_ButAddKP.EnableWindow(FALSE);
    return 0;
}

int CDlgWheelsToVan::RefreshKPList()
{
	BOOL *bEnaList = new BOOL[ m_List.GetItemCount() + 1 ];

    if( !iMode )
	    for( DWORD i=0; i < dwKPNum; i++ )
	    {
		    bEnaList[i] = m_List.isItemEnabled(i);
    	}
	m_List.DeleteAllItems();
    for( DWORD i=0; i < dwKPNum; i++ )
    {		
        m_List.InsertItem(m_List.GetItemCount(), pPrih[i].cNKP);
        m_List.SetItemText(m_List.GetItemCount() - 1, 1, pPrih[i].cTKP);
		m_List.SetItemData(i, (DWORD)pPrih[i].qwIKP);
		if( !iMode ) m_List.EnableItem(i, bEnaList[i]);
        else m_List.EnableItem(i, bListEnabled[i]);
		char tt[64] = "";
        if( !iMode )
        {
		    DateToStrRus(pPrih[i].stDatPost, tt);
		    m_List.SetItemText(i, 2, tt);
		    m_List.SetItemText(i, 3, pPrih[i].cFam);
        } else
        {
		    DateToStrRus(pPrih[i].stDatRash, tt);
		    m_List.SetItemText(i, 2, tt);
		    m_List.SetItemText(i, 3, pPrih[i].cFamRash);
        }
    }
    return 0;
}

int CDlgWheelsToVan::SelPrih(__int64 qwIKP, PASP_KP &Pasp, PRIH_KP &Prih, int &iFo, int &iZp)
{
    char cQ[512] = "";
    char cText[64] = "";
    sprintf(cQ, "pTov_GetKPByIKP2 %I64u", qwIKP);
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch()) == SQL_NO_DATA || g_sqlret == SQL_ERROR)
    {
        DBW.CloseCursor();
        return -1;
    }
    long Ind;
    SQL_DATE_STRUCT date;
    DBW.GetData( 1, SQL_C_TYPE_DATE, &date, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 ) SqlDateToSysTime(date, &Prih.stDatIzg);
    DBW.GetData( 2, SQL_C_CHAR, &Pasp.cIzOsPr_KL, 32, &Ind);
    if( Ind == -1 ) // Нет записи об изготовлении оси
    {
        Pasp.cKLPR[0] = 0;
		Pasp.cIzOsPr_KL[0] = 0;
        memset(&Prih.stDatIzg, 0, sizeof(Prih.stDatIzg));
        iZp = 1;    
    } else
    {
        iZp = 2;
//        DateToStrRus(Prih.stDatIzg, Pasp.cIZOS_DAT);
        Pasp.stIZOS_DAT = Prih.stDatIzg;
//        SqlDateToSysTime(date, &Prih.stDatIzg);
    }
    DBW.GetData( 3, SQL_C_CHAR, &Pasp.cPL_OS, 32, &Ind); // плавка оси
    if( Ind == -1 ) Pasp.cPL_OS[0] = 0;

    DBW.GetData( 4, SQL_C_TYPE_DATE, &date, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 ) SqlDateToSysTime(date, &Prih.stDatFor);
    DBW.GetData( 5, SQL_C_CHAR, &Pasp.cPosForPr_KL, 32, &Ind);
    if( Ind == -1 ) // не найдена отметка последнего формирования
    {
        Pasp.cPosForPr_KL[0] = 0;
        memset(&Prih.stDatFor, 0, sizeof(Prih.stDatFor));
    } else
    { // найдена отметка последнего формирования
        iFo++;
        Pasp.stPOSFOR_DAT = Prih.stDatFor;
    }
    DBW.GetData( 6, SQL_C_TYPE_DATE, &date, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 ) SqlDateToSysTime(date, &Prih.stDatOsv);
    DBW.GetData( 7, SQL_C_CHAR, &Pasp.cPosOsvPr_KL, 32, &Ind);
    if( Ind == -1 )
    {
        Pasp.cPosOsvPr_KL[0] = 0;
    }
    else
    { // найдена отметка последнего освидетельствования
        iFo+=2;
        Pasp.stPOSOSV_DAT = Prih.stDatOsv;
    }
    DBW.GetData( 8, SQL_C_CHAR, &Pasp.cRedName, 32, &Ind);
    if( Ind == -1 ) Pasp.cRedName[0] = 0;

    DBW.GetData( 9, SQL_C_CHAR, &cText, 32, &Ind);
    if( Ind != -1 ) Prih.dPrihDkk_l = atof(cText);
    else Prih.dPrihDkk_l = 0;
    DBW.GetData( 10, SQL_C_CHAR, &cText, 32, &Ind);
    if( Ind != -1 ) Prih.dPrihDkk_r = atof(cText);
    else Prih.dPrihDkk_r = 0;
//    DBW.GetData( 11, SQL_C_CHAR, &cText, 32, &Ind);

    DBW.GetData( 12, SQL_C_SBIGINT, &Pasp.qwIKP, 8, &Ind);
    DBW.GetData( 13, SQL_C_USHORT, &Prih.wGruz, 2, &Ind);
    if( Ind == -1 ) Prih.wGruz = 1;
    DBW.GetData( 14, SQL_C_SLONG, &Pasp.dwIzOsPr_ID, 4, &Ind);
    if( Ind == -1 ) Pasp.dwIzOsPr_ID = 0;
	DBW.GetData(15, SQL_C_ULONG, &Pasp.dwPosForPr_ID, 4, &Ind);
    if( Ind == -1 ) Pasp.dwPosForPr_ID = 0;
	DBW.GetData(16, SQL_C_ULONG, &Pasp.dwPosOsvPr_ID, 4, &Ind);
    if( Ind == -1 ) Pasp.dwPosOsvPr_ID = 0;
    DBW.CloseCursor();

    return 0;
}

void CDlgWheelsToVan::OnOldKPListClick() 
{
    CDlgOldKPList Dlg;
    Dlg.qwILK = qwLKID;

	Dlg.iInitCount = m_List.GetItemCount();

	for( int i=0; i < Dlg.iInitCount; i++ )
	{
//		Dlg.p_qwInitIKP[i] = pPasp[i].qwIKP;
        Dlg.p_qwInitIZAP[i] = pPrih[i].qwIZAP;
		Dlg.p_qwIZAP[i] = pPrih[i].qwIZAP;
	}
    Dlg.iMode = iMode;
    if( Dlg.DoModal() == IDCANCEL ) return;
    if( !iMode ) // Были подкачены
    {
	    for( int i=0; i < Dlg.iIKPCount && (unsigned)i < dwMaxKPCount; i++ )
	    {        
		    DBW.GetPaspKP(Dlg.p_qwIKP[i], &pPasp[dwKPNum]);

		    pPrih[dwKPNum].qwIZAP = 0;
		    pPrih[dwKPNum].wITR = (WORD)pPasp[dwKPNum].dwRedTypeID;
		    pPrih[dwKPNum].dwPosForPr_ID = pPasp[dwKPNum].dwPosForPr_ID;
		    pPrih[dwKPNum].dwPosOsvPr_ID = pPasp[dwKPNum].dwPosOsvPr_ID;
		    strcpy(pPrih[dwKPNum].cPosForPr_KL, pPasp[dwKPNum].cPosForPr_KL);
		    strcpy(pPrih[dwKPNum].cPosOsvPr_KL, pPasp[dwKPNum].cPosOsvPr_KL);
		    pPrih[dwKPNum].stDatIzg = pPasp[dwKPNum].stIZOS_DAT;
		    pPrih[dwKPNum].stDatFor = pPasp[dwKPNum].stPOSFOR_DAT;
		    pPrih[dwKPNum].stDatOsv = pPasp[dwKPNum].stPOSOSV_DAT;
    //		pPrih[dwKPNum].dDkk_r = pPasp[dwKPNum].
		    
		    pPrih[dwKPNum].dwFam = m_EdFam.GetData();
		    m_Dat.GetTime(&pPrih[dwKPNum].stDatPost);

		    pPrih[dwKPNum].dwRemVagID = dwVRemVag_ID;
		    strcpy(pPrih[dwKPNum].cPrihNVag, m_nVag);

		    m_List.InsertItem(dwKPNum, pPasp[dwKPNum].cNKP);
		    m_List.SetItemText(dwKPNum, 1, pPasp[dwKPNum].cTKP);
		    char tt[64] = "";
		    DateToStrRus(pPrih[dwKPNum].stDatPost, tt);
		    m_List.SetItemText(dwKPNum, 2, tt);
		    m_EdFam.GetWindowText(tt, 64);
		    m_List.SetItemText(dwKPNum, 3, tt);
		    dwKPNum++;
	    }
    } else
    {			// были выкачены
    	for( int i=0; i < Dlg.iIKPCount && (unsigned)i < dwMaxKPCount; i++ )
	    {        

/*		    DBW.GetPaspKP(Dlg.p_qwIKP[i], &pPasp[dwKPNum]);
            DBW.GetPrihodKP(Dlg.p_qwRetIZAP[i], &pPrih[dwKPNum]);*/

			DBW.LoadPrihdKP(&pPrih[dwKPNum], Dlg.p_qwRetIZAP[i]);
		    m_Dat.GetTime(&pPrih[dwKPNum].stDatRash);
//            pPrih[dwKPNum].qwIZAP = Dlg.p_qwRetIZAP[i];

/*
            pPrih[dwKPNum].dwPriznRas = Dlg.p_dwPriznRas[i];
            pPrih[dwKPNum].wGruz = (WORD)Dlg.p_dwGruz[i];
            pPasp[dwKPNum].wGruz = (WORD)Dlg.p_dwGruz[i];
*/
		    pPrih[dwKPNum].dwRemVagID = dwVRemVag_ID;
		    strcpy(pPrih[dwKPNum].cPrihNVag, m_nVag);

		    m_List.InsertItem(dwKPNum, pPrih[dwKPNum].cNKP);
		    m_List.SetItemText(dwKPNum, 1, pPrih[dwKPNum].cTKP);
		    char tt[64] = "";
		    DateToStrRus(pPrih[dwKPNum].stDatRash, tt);
		    m_List.SetItemText(dwKPNum, 2, tt);

		    m_EdFam.GetWindowText(tt, 64);
		    m_List.SetItemText(dwKPNum, 3, tt);

            pPrih[dwKPNum].dwFamRash = m_EdFam.GetData();
            m_EdFam.GetWindowText(pPrih[dwKPNum].cFamRash, 32);
            m_List.EnableItem(dwKPNum);
            bListEnabled[dwKPNum] = TRUE;

            RemoveFromRemoved(Dlg.p_qwRetIZAP[i]);
		    dwKPNum++;
            
        }
    }

}

void CDlgWheelsToVan::OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult) 
{
    if( !iMode )
    {
        int idx = m_List.GetSelectionMark();
        if( !m_List.isItemEnabled(idx) ) return;
        CDlgPrihodKP Dlg;
        Dlg.iZp = 0;
        Dlg.iFo = 0;
        Dlg.dwIFam =
        m_cb.GetWindowText(pPasp[idx].cTKP, 32);
        Dlg.PaspKp = pPasp[idx];
        Dlg.PrihKp = pPrih[idx];
        Dlg.iMode = 3;
        CString s;
        if( !pPrih[idx].dwFam )
        {
            m_EdFam.GetWindowText(s);
            Dlg.m_strFIO = s;
        }
		Dlg.dwIFam = m_EdFam.GetData();
        if( Dlg.DoModal() == IDCANCEL ) return;
	    pPasp[idx] = Dlg.PaspKp;
	    pPrih[idx] = Dlg.PrihKp;

        RefreshKPList();
    }
//    pPasp[i].
	*pResult = 0;
}


void CDlgWheelsToVan::OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult) 
{
	*pResult = 0;
    CPoint p;
    GetCursorPos(&p);
    CRect r;
    r.left = p.x;
    r.right = p.x + 100;
    r.top = p.y;
    r.bottom = p.y + 400;
    m_Menu->GetSubMenu(0)->TrackPopupMenu(TPM_LEFTALIGN | TPM_RIGHTBUTTON, p.x, p.y, this);
}

void CDlgWheelsToVan::OnMenuKpPasp() 
{
    if(m_List.GetSelectionMark() < 0 ) return;
    CPrintableDlg Dlg;
    sprintf(Dlg.cQ, "pTov_mkcReportPasp %I64u", pPrih[m_List.GetSelectionMark()].qwIZAP);
    Dlg.DoModal();
}

void CDlgWheelsToVan::OnMenuKpRemove() 
{
    if(m_List.GetSelectionMark() < 0 ) return;
    if( MessageBox("Вы уверены?", "Внимание!", MB_YESNO) == IDNO) return;
    p_ErasedPasp[dwErasedCount] = pPasp[m_List.GetSelectionMark()];
    p_ErasedPrih[dwErasedCount] = pPrih[m_List.GetSelectionMark()];
    dwErasedCount++;
    for( WORD i=m_List.GetSelectionMark(); i < dwKPNum; i++ )
    {
        pPrih[i] = pPrih[i + 1];
        pPasp[i] = pPasp[i + 1];
        p_iFo[i] = p_iFo[i + 1];
        p_iZp[i] = p_iZp[i + 1];
//        if( i < m_List.GetItemCount() ) m_List.EnableItem(i, m_List.isItemEnabled(i + 1));
        bListEnabled[i] = bListEnabled[i + 1];
    }
    dwKPNum--;
    RefreshKPList();
}

void CDlgWheelsToVan::RemoveFromRemoved(__int64 qwIZAP)
{
            for( DWORD j = 0; j < dwErasedCount; j++ )
            {
                if( qwIZAP == p_ErasedPrih[j].qwIZAP )
                {
                    for( DWORD x=j; x < dwErasedCount; x++ )
                    {
                        p_ErasedPrih[x] = p_ErasedPrih[x + 1];
                    }
                    dwErasedCount--;
                    return;
                }
            }
}

void CDlgWheelsToVan::OnCancel() 
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;	
	CDlgWithAccelerators::OnCancel();
}

void CDlgWheelsToVan::OnMenuRashodKp()
{
	if(m_List.GetSelectionMark() < 0 ) return;
	CDlgRashod Dlg;
	char cText[64] = "";
	Dlg.qwIZAP = pPrih[m_List.GetSelectionMark()].qwIZAP;
	m_List.GetItemText( m_List.GetSelectionMark(), 0, cText, 64 );
	Dlg.m_strNKP = cText;
	m_List.GetItemText( m_List.GetSelectionMark(), 1, cText, 64 );
	Dlg.m_strTKP = cText;
	Dlg.DoModal();
}

void CDlgWheelsToVan::OnMenuRazmerKp()
{
	if(m_List.GetSelectionMark() < 0 ) return;
	CDlgObmerKP Dlg;
	char cText[64] = "";

	Dlg.qwIZAP = pPrih[m_List.GetSelectionMark()].qwIZAP;

	m_List.GetItemText( m_List.GetSelectionMark(), 0, cText, 64 );
	Dlg.m_EditNKP = cText;
	m_List.GetItemText( m_List.GetSelectionMark(), 1, cText, 64 );
	strcpy( Dlg.cTKP, cText);
	Dlg.m_EditTKP = cText;
	Dlg.DoModal();
}

void CDlgWheelsToVan::OnMenuPrihodKp()
{
	if(m_List.GetSelectionMark() < 0 ) return;
	CDlgPrihodKP Dlg;
	char cText[64] = "";

//	Dlg.iMode = 3;
//	DBW.GetPaspKP( Dlg.PrihKp );

	if( !m_List.isItemEnabled( m_List.GetSelectionMark() ) )
	{
		/*
		char cQ[128] = "";
		long Ind = 0;
		sprintf( cQ, "pTov_GetIKPbyIZAP %I64u", Dlg.PrihKp.qwIZAP );
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_UBIGINT, &Dlg.PrihKp.qwIZAP, 8, &Ind );
		DBW.CloseCursor();

	//	Dlg.PaspKp = pPasp[m_List.GetSelectionMark()];
		Dlg.PrihKp = pPrih[m_List.GetSelectionMark()];

		Dlg.iMode = 3;
		DBW.GetPaspKP(Dlg.PaspKp.qwIKP, &Dlg.PaspKp);
		DBW.GetPrihodKP(Dlg.PrihKp.qwIZAP, &Dlg.PrihKp);
		*/
		Dlg.qwIZap = pPrih[ m_List.GetSelectionMark() ].qwIZAP;
		Dlg.iInitFrom = INIT_FROM_DB;
	} else
	{
		Dlg.PaspKp = pPasp[m_List.GetSelectionMark()];
		Dlg.PrihKp = pPrih[m_List.GetSelectionMark()];
		Dlg.iInitFrom = INIT_FROM_GIVEN;
	}
//	Dlg.PrihKp.qwIZAP = pPrih[m_List.GetSelectionMark()].qwIZAP;
/*
	m_List.GetItemText( m_List.GetSelectionMark(), 0, cText, 64 );
	Dlg.m_EditNKP = cText;
	m_List.GetItemText( m_List.GetSelectionMark(), 1, cText, 64 );
	Dlg.m_EditTKP = cText;*/
	Dlg.iMode = 2;
	if( Dlg.DoModal() == IDCANCEL ) return;
	pPrih[m_List.GetSelectionMark()] = Dlg.PrihKp;
	m_List.EnableItem( m_List.GetSelectionMark() );
	dwNeedUpdate[m_List.GetSelectionMark()] = 1;
}
