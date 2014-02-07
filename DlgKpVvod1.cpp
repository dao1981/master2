// DlgKpVvod1.cpp : implementation file
//
#include "stdafx.h"
#include "master.h"
#include "DlgKpVvod1.h"
#include "DlgShowTwin.h"
#include "DlgPrihodKP.h"
#include "DlgRashod.h"
#include "DlgObmerKP.h"
#include "DlgRemKP.h"
#include "DlgMntBuks.h"
#include "DlgZapressKP.h"
#include "DlgPrihodOS.h"
#include "DlgPaspKP.h"
#include "DlgPrihKpList.h"
#include "DlgSprav1.h"
#include <sqlext.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern SQLRETURN    g_sqlret;
extern DWORD g_iDep;
extern CMasterApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgKpVvod1 dialog
int ZapressIsOpened = 1;
int PrihodOsIsOpened = 1;


CDlgKpVvod1::CDlgKpVvod1(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgKpVvod1::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgKpVvod1)
	//}}AFX_DATA_INIT
    iZp = 0;
    iFo = 0;
	qwIZap = 0;
	iGotKPfromSelKP = 0;
	iReadyState = 0;
}


void CDlgKpVvod1::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgKpVvod1)
	DDX_Control(pDX, IDOK, m_ButReady);
	DDX_Control(pDX, IDC_BUTTON2, m_ButObmer);
	DDX_Control(pDX, IDC_BUTTON4, m_ButMont);
	DDX_Control(pDX, IDC_BUTTON3, m_ButRem);
	DDX_Control(pDX, IDC_BUTTON7, m_ButZapr);
	DDX_Control(pDX, IDC_BUTTON5, m_ButRash);
	//	DDX_Control(pDX, IDC_EDIT3, m_Hint);
	DDX_Control(pDX, IDC_BUTTON8, m_ButTwin);
	DDX_Control(pDX, IDC_BUTTON6, m_ButPrihod2);
	DDX_Control(pDX, IDC_BUTTON1, m_ButPrihod);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_EDIT1, m_edKpNum);
	DDX_Control(pDX, IDC_EDIT7, m_edKlPrIzg);
	DDX_Control(pDX, IDC_EDIT2, m_edYearIzg);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_BUTTON10, m_butVybrat);
	DDX_Control(pDX, IDCANCEL, m_butExit);
	DDX_Control(pDX, IDC_BUTTON9, m_butPasp);
}


BEGIN_MESSAGE_MAP(CDlgKpVvod1, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgKpVvod1)
	ON_BN_CLICKED(IDOK, OnReady)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEditNKP)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeComboTKP)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButtonRemont)
	ON_BN_CLICKED(IDC_BUTTON4, OnButtonMntBuks)
	ON_BN_CLICKED(IDC_BUTTON7, OnButtonZapress)
	ON_BN_CLICKED(IDC_BUTTON6, OnBnPrihodOS)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON9, &CDlgKpVvod1::OnBnClickedButton_PaspKP)
	ON_BN_CLICKED(IDC_BUTTON10, &CDlgKpVvod1::OnBnClickedButton_SelectKP)
	ON_BN_CLICKED(IDC_BUTTON11, &CDlgKpVvod1::OnBnClicked_SelKlIzg)
	ON_EN_CHANGE(IDC_EDIT7, &CDlgKpVvod1::OnEnChangeEdit7)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgKpVvod1 message handlers
extern int g_iDefaultTypeKP;
BOOL CDlgKpVvod1::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
	
	m_edKpNum.QInit(100, 1);
	m_edYearIzg.QInit(40, 1);
	m_edKlPrIzg.QInit(80,1);

    long Ind = 0;
    DWORD iType = 0;
    char cQ[255]="pTov_GetTKP";
    char cText[64] = "";
    DBW.ExecSQL(cQ);
    for(DWORD i=0; DBW.Fetch() != SQL_NO_DATA && i < 64; i++ )
    {
        DBW.GetData( 1, SQL_C_ULONG, &iType, 8, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Combo1.AddString(cText);
		m_Combo1.SetItemData(i, iType);
        idKPType[i] = iType;
    }
    m_Combo1.SetCurSel(g_iDefaultTypeKP - 1);


//	m_Hint.SetWindowText("Введите номер и тип колесной пары и нажмите кнопку \"Готово\"");

	DBW.CloseCursor();

//	m_ButMont.EnableWindow(FALSE);
    iZp = 0;
    iFo = 0;

	m_HeaderCtrl.SetTitleText("Ввод данных по колесным парам");
	m_HeaderCtrl.SetDescText("Введите номер и тип колесной пары и нажмите кнопку \"Готово\" либо выберете КП с помощью кнопки \"Выбрать\".");
	m_HeaderCtrl.SetIconHandle(AfxGetApp()->LoadIcon(IDI_USER1));
	m_HeaderCtrl.SetIconOffset(10);
	
	m_HeaderCtrl.Init(this);
	m_HeaderCtrl.MoveCtrls(this);

    return TRUE;
}

void CDlgKpVvod1::OnReady() 
{
	m_ButReady.SetFocus();
	if( iReadyState /*&& !iGotKPfromSelKP*/ )
	{
		qwIZap = 0;
		
		m_edKpNum.ModifyStyle(WS_DISABLED, 0);
		m_edKlPrIzg.ModifyStyle(WS_DISABLED, 0);
		m_edYearIzg.ModifyStyle(WS_DISABLED, 0);
		m_butPasp.EnableWindow(FALSE);
		m_Combo1.EnableWindow(1);
	//	m_edKpNum.EnableWindow(0);
		COLORREF crInactive = RGB(255, 255, 255);
//		m_edKpNum.SetBkColor(crInactive);
		m_edKlPrIzg.SetBkColor(crInactive);
		m_edYearIzg.SetBkColor(crInactive);

		m_edKpNum.SetWindowText("");
		m_edKlPrIzg.SetWindowText("");
		m_edYearIzg.SetWindowText("");

		m_edKpNum.SetFocus();
		m_ButReady.SetWindowText("Готово");
		m_HeaderCtrl.SetDescText("Введите номер и тип колесной пары и нажмите кнопку \"Готово\" либо выберете КП с помощью кнопки \"Выбрать\".");
		iReadyState = 0;
		return;
	}

	if( m_edKpNum.isNull() )
	{
		AfxMessageBox("Необходимо указать номер КП!");
		m_edKpNum.SetFocus();
		return;
	}
	
	char cQ[255] = "";
	long Ind = 0;	

	if( !m_edKlPrIzg.isNull() )
	{
		int dwNum = 0;
		sprintf(cQ, "pTov_GetPrByKl %s", m_edKlPrIzg.GetString(1));
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
		DBW.CloseCursor();
		if( !Ind || Ind == -1 )
		{
			AfxMessageBox("Указанный производитель КП отсутствует в справочнике!");
			m_edKlPrIzg.SetFocus();
			return;
		}
	}

	if( !m_edYearIzg.isNull() && ( m_edYearIzg.GetAsDWord() < 1900 || m_edYearIzg.GetAsDWord() > 2014 ) )
	{
		AfxMessageBox("Год изготовления оси указан некорректно!");
		return;
	}
		

	DWORD dwCountKP = 0;
	__int64 qwInitIZap = 0;
	
	if( !iGotKPfromSelKP )
	{
		int idx = m_Combo1.GetCurSel();
		CString     cText;
		cQ[0] = 0;
		char cTKP[6] = "";
		
		if( idx > -1 )
		{
			itoa(m_Combo1.GetItemData(idx), cTKP, 10);
		} else
			strcpy(cTKP, "NULL");

		sprintf(cQ, "pTov_KP_GetPrihKPCount %u, %s, %s, %s, %s",
			g_iDep,
			m_edKpNum.GetString(1),
			cTKP,
			m_edYearIzg.GetString(1),
			m_edKlPrIzg.GetString(1));
				
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_ULONG, &dwCountKP, 4, &Ind );
		if( Ind != -1 && dwCountKP == 1 )
			DBW.GetData(2, SQL_C_UBIGINT, &qwInitIZap, 8, &Ind );
		
		DBW.CloseCursor();
	} else
	{
		dwCountKP = 1;
		qwInitIZap = qwIZap;
	}

	if( !dwCountKP ) // нет оприходованных КП с такими ключами
	{
//        m_Hint.SetWindowText("В базе данных нет паспорта указанной КП. Для занесения начальной информации нажмите на кнопку \"Приход\"");
		m_HeaderCtrl.SetDescText("В базе данных нет паспорта указанной КП. Для занесения начальной информации нажмите на кнопку \"Приход\"");
		m_ButPrihod.EnableWindow();
		m_ButPrihod2.EnableWindow();
	} else
	if(dwCountKP == 1) {
		m_HeaderCtrl.SetDescText("Данной колесной паре уже был оформлен приход, Вы можете продолжить работу с данной КП.");
	}

	m_edKpNum.ModifyStyle(0, WS_DISABLED);
	m_edKlPrIzg.ModifyStyle(0, WS_DISABLED);
	m_edYearIzg.ModifyStyle(0, WS_DISABLED);
	m_Combo1.EnableWindow(0);

	COLORREF crInactive = RGB(254, 255, 231);
	m_edKpNum.SetBkColor(crInactive);
	m_edKlPrIzg.SetBkColor(crInactive);
	m_edYearIzg.SetBkColor(crInactive);
	
	DWORD dwNum = 0;
	SetButtons(qwInitIZap);

	/*
	if( qwInitIZap )
	{
		SetButtons(qwInitIZap);
	}
	*/ 

	qwIZap = qwInitIZap;
	m_ButReady.SetWindowText("Начать работу с другой КП");
	iGotKPfromSelKP = 0;
	iReadyState = 1;

/*
    int idx = m_Combo1.GetCurSel();
    CString     cText;
    ZeroMemory(&Prih, sizeof(Prih));
    ZeroMemory(&Pasp, sizeof(Pasp));
    CDlgShowTwin TwinDlg;
    m_edKpNum.GetWindowText(cText);
    DWORD   dwNkp = (DWORD)_atoi64(cText);
    if( dwNkp == 0 )
    {
        AfxMessageBox("Введен некорректный номер КП!");
        return;
    }
    strncpy(cNumKP, cText, 32);
    dwTypeKP = idKPType[idx];
    Pasp.dwTKP = dwTypeKP;
	strcpy(Pasp.cNKP, cNumKP);
	m_Combo1.GetWindowText(Pasp.cTKP, 16);
    char cQ[512] = "";
    sprintf(cQ, "pTov_GetKPCountByNKP '%s', %u", cNumKP, dwTypeKP);
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch()) == SQL_NO_DATA || g_sqlret == SQL_ERROR)
    {
        DBW.CloseCursor();
        return;
    }
    iZp = 0;
    iFo = 0;
    DWORD   dwCount = 0;
    long    Ind = 0;
    m_ButPrihod.EnableWindow();
    BOOL isData = FALSE;
    DBW.GetData( 1, SQL_C_ULONG, &dwCount, 4, &Ind);
    DBW.CloseCursor();
    if( dwCount == 0 )
    {
        m_Hint.SetWindowText("В базе данных нет паспорта указанной КП. Для занесения начальной информации нажмите на кнопку \"Приход\"");
        if( g_dwTypeDep == 2 && PrihodOsIsOpened )m_ButPrihod2.EnableWindow();
    } else
    {
        m_ButTwin.EnableWindow();
        if( dwCount == 1)
        {
            sprintf(cQ, "pTov_GetIKPByNumKP '%s', %d", cNumKP, dwTypeKP);
            DBW.ExecSQL(cQ);
            if( (g_sqlret = DBW.Fetch()) == SQL_NO_DATA || g_sqlret == SQL_ERROR)
            {
                DBW.CloseCursor();
                return;
            }
            DBW.GetData( 1, SQL_C_SBIGINT, &qwIKP, 8, &Ind);
            DBW.CloseCursor();
            SelPrih();
        } else // dwCount > 1
        {
            TwinDlg.dwTKP = dwTypeKP;
            strncpy(TwinDlg.cNKP, cNumKP, 32);
            m_Combo1.GetLBText(idx, TwinDlg.cTKP);
            if( TwinDlg.DoModal() == IDCANCEL )
            {
                qwIKP = 0;
                DisableBtns();
                return;
            }
            qwIKP = TwinDlg.qwIKP;
            if( qwIKP )
            {
                SelPrih();
            }
        }
    }
    ClearFlag = true;
*/

}

void CDlgKpVvod1::SelPrih()
{
    char cQ[512] = "";
    char cText[64] = "";
    iFo = 0;
    iZp = 0;
    sprintf(cQ, "pTov_GetKPByIKP2 %I64u", qwIKP);
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch()) == SQL_NO_DATA || g_sqlret == SQL_ERROR)
    {
        DBW.CloseCursor();
        return;
    }
    long Ind;
    SQL_DATE_STRUCT date;
    DBW.GetData( 1, SQL_C_TYPE_DATE, &date, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 ) SqlDateToSysTime(date, &Prih.stDatIzg);
    DBW.GetData( 2, SQL_C_CHAR, &Pasp.cIzOsPr_KL, 32, &Ind);
    if( Ind == -1 ) // Нет записи об изготовлении оси
    {
        Pasp.cKLPR[0] = 0;
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
//        DateToStrRus(Prih.stDatFor, Pasp.cPOSFOR_DAT);
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
//        DateToStrRus(Prih.stDatOsv, Pasp.cPOSOSV_DAT);
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
    DBW.GetData( 11, SQL_C_CHAR, cText, 32, &Ind);
    if( Ind != -1 && !strncmp(cText, "ось", 4) )
    {
        m_ButPrihod.EnableWindow();
        if( PrihodOsIsOpened ) m_ButPrihod2.EnableWindow();
    }
    DBW.GetData( 12, SQL_C_SBIGINT, &Pasp.qwIKP, 8, &Ind);
    DBW.GetData( 13, SQL_C_USHORT, &Prih.wGruz, 2, &Ind);
    if( Ind == -1 ) Prih.wGruz = 1;
    DBW.GetData(14, SQL_C_ULONG, &Pasp.dwIzOsPr_ID, 4, &Ind);
    if( Ind == -1 ) Pasp.dwIzOsPr_ID = 0;
	DBW.GetData(15, SQL_C_ULONG, &Pasp.dwPosForPr_ID, 4, &Ind);
    if( Ind == -1 ) Pasp.dwPosForPr_ID = 0;
	DBW.GetData(16, SQL_C_ULONG, &Pasp.dwPosOsvPr_ID, 4, &Ind);
    if( Ind == -1 ) Pasp.dwPosOsvPr_ID = 0;
	DBW.GetData(17, SQL_C_CHAR, Pasp.cTKP, 32, &Ind);

    DBW.CloseCursor();
/*      second part     */
    DWORD   dwCount = 0;
    DWORD   dwGruz = 0;


    sprintf(cQ, "pTov_GetPrihodKPByIKP %I64u, %u", Pasp.qwIKP, g_iDep);
    DBW.ExecSQL(cQ);
	
	g_sqlret = DBW.Fetch();
	DBW.GetData( 1, SQL_C_SBIGINT, &Prih.qwIZAP, 8, &Ind);
    if( g_sqlret == SQL_NO_DATA || Ind == -1 )
    {
        Prih.dwPriznRas = 0;
        m_ButObmer.EnableWindow(FALSE);
        m_ButRash.EnableWindow(FALSE);
        m_ButRem.EnableWindow(FALSE);
        m_ButMont.EnableWindow(FALSE);
//        m_Hint.SetWindowText("Зарегистрируйте информацию о приходе.\r\n(нажмите на кнопку \"Приход\")");
		m_HeaderCtrl.SetDescText("Зарегистрируйте информацию о приходе.\r\n(нажмите на кнопку \"Приход\".)");
        DBW.CloseCursor();
        return;
    } else
    {
        long Ind = 0;
        // Анализ записи о приходе
/* Добавил DESC в pTov_GetPrihodKPByIKP (последняя запись стала первой)
        for( DWORD i=0; g_sqlret != SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
        {
            g_sqlret = SQLMoreResults(g_hsqlstmt);
        }
*/      
//        g_sqlret = DBW.Fetch();
//        DBW.GetData( 1, SQL_C_SBIGINT, &Prih.qwIZAP, 8, &Ind);
        DBW.GetData( 2, SQL_C_SLONG, &Prih.dwPriznRas, 4, &Ind);
        SQL_DATE_STRUCT sqlDate;
        DBW.GetData( 3, SQL_C_TYPE_DATE, &sqlDate, sizeof(SQL_DATE_STRUCT), &Ind);
        Prih.stDatPost.wDay = sqlDate.day;
        Prih.stDatPost.wMonth = sqlDate.month;
        Prih.stDatPost.wYear = sqlDate.year;
        DBW.GetData( 4, SQL_C_SLONG, &Prih.dwTREB_REM, 4, &Ind);
        if( Ind == -1 )
        {
            Prih.dwTREB_REM = 0;
        }
        DBW.GetData( 5, SQL_C_SLONG, &Prih.wITR, 4, &Ind);
        if( Ind == -1 )
        {
            Prih.wITR = 255;
        }
        char cKodKl[32]="";
        char cSName[32]="";
        SQL_DATE_STRUCT sdatDatRem;
        SQL_DATE_STRUCT sdatMbDat;
        DBW.GetData( 6, SQL_C_CHAR, cKodKl, 32, &Ind);
        DBW.GetData( 7, SQL_C_CHAR, cSName, 32, &Ind);
        DBW.GetData( 8, SQL_C_TYPE_DATE, &sdatDatRem, sizeof(SQL_DATE_STRUCT), &Ind);
        DBW.GetData( 9, SQL_C_TYPE_DATE, &sdatMbDat, sizeof(SQL_DATE_STRUCT), &Ind);
        DBW.GetData(10, SQL_C_SLONG, &dwGruz, 4, &Ind);
        DBW.CloseCursor();
        DBW.GetPrihodKP(Prih.qwIZAP, &Prih);
        if( Prih.dwPriznRas > 10 )
        {   // DAT_REM            
            Prih.dt5.wDay = sdatDatRem.day;
            Prih.dt5.wMonth = sdatDatRem.month;
            Prih.dt5.wYear = sdatDatRem.year;
        }
        if( Prih.dwPriznRas == 12 )
        {   // MB_DAT
            Prih.dt6.wDay = sdatMbDat.day;
            Prih.dt6.wMonth = sdatMbDat.month;
            Prih.dt6.wYear = sdatMbDat.year;
//            strncpy(Prih.cKneisp, cKodKl, 32);
        }
        strncpy(Prih.cNeisp_KL, cKodKl, 32);
    }
//    m_Hint.SetWindowText("В базе найдена запись о приходе.");
	m_HeaderCtrl.SetDescText("В базе найдена запись о приходе.");
    m_ButRash.EnableWindow();

    if( dwGruz == 5 || Prih.cNeisp_KL[0] == '5' )
    { // найден приход оси
        if( PrihodOsIsOpened )m_ButPrihod2.EnableWindow();
        m_ButPrihod.EnableWindow(FALSE);
        if( ZapressIsOpened ) m_ButZapr.EnableWindow();
        if( Prih.dwPriznRas > 1 )
        {
            m_ButRem.EnableWindow();
            m_ButMont.EnableWindow();
            m_ButObmer.EnableWindow();
        }
    } else
    { // найден приход КП
        m_ButObmer.EnableWindow();
        m_ButPrihod2.EnableWindow(FALSE);
//        SetButtons();

        if( Prih.dwPriznRas == 10 )
        { // требует смены элементов
            if( ZapressIsOpened ) m_ButZapr.EnableWindow();
        } else
        if( Prih.dwPriznRas > 10 || Prih.dwTREB_REM > 0 )
        {
            m_ButRem.EnableWindow();
            m_ButMont.EnableWindow();
            if( Prih.dwPriznRas >= 20 )
            {
                 if( ZapressIsOpened ) m_ButZapr.EnableWindow();
            }
        }

    }
}

void CDlgKpVvod1::OnButton8() 
{
    if(MessageBox("Вы уверены, что хотите завести двойника?", "Внимание!!!", MB_YESNO | MB_ICONQUESTION) == IDNO )
        return;
    iZp = 0;
    Prih.dwPriznRas = 0;
    if( PrihodOsIsOpened ) m_ButPrihod2.EnableWindow();
//    m_Hint.SetWindowText("Для занесения начальной информации нажмите на кнопку \"Приход\".");
    m_ButRem.EnableWindow(FALSE);
    m_ButObmer.EnableWindow(FALSE);
    m_ButMont.EnableWindow(FALSE);
    m_ButZapr.EnableWindow(FALSE);
    m_ButRash.EnableWindow(FALSE);
    CString num;
    DWORD dwT;
    m_edKpNum.GetWindowText(num);
    dwT = idKPType[m_Combo1.GetCurSel()];
    ZeroMemory(&Pasp, sizeof(Pasp));
    ZeroMemory(&Prih, sizeof(Prih));
    strcpy(Pasp.cNKP, num);
    Pasp.dwTKP = dwT;
}

void CDlgKpVvod1::OnButton1()  //Приход КП
{
	CDlgPrihodKP Dlg;
	if( qwIZap )
	{
		Dlg.qwIZap = qwIZap;
		Dlg.iInitFrom = INIT_FROM_DB;
	}
	else
	{
		char cText[64] = "";
		m_edKpNum.GetWindowText(Dlg.cNKP, 32);
		Dlg.iTKP = m_Combo1.GetItemData(m_Combo1.GetCurSel());
		m_Combo1.GetWindowText(cText, 64);
		Dlg.m_strTypeKP =  cText;

		m_edKlPrIzg.GetWindowText(Dlg.cKlPrIzg, 10);
		ZeroMemory(&Dlg.stOld_IzgDat, sizeof(SYSTEMTIME));
		Dlg.stOld_IzgDat.wDay = 1;
		Dlg.stOld_IzgDat.wMonth = 1;
		Dlg.stOld_IzgDat.wYear = m_edYearIzg.GetAsDWord();
//		m_edYearIzg.GetTime(&Dlg.stOld_IzgDat);
	}

	if( Dlg.DoModal() == IDCANCEL ) return;
	UpdateFieldsByIZap( qwIZap );
	qwIZap = Dlg.PrihKp.qwIZAP;
	if( qwIZap )
	{
		SetButtons(qwIZap);
	}

	/*
	CDlgPrihodKP Dlg;
    CString cStr = "";
    char s[64]="";
    char cQ[512] = "";
    char cText[64] = "";
    m_edKpNum.GetWindowText(cStr);
    Dlg.m_strNumKP = CString("Номер: ") + cNumKP;
    strcpy(Pasp.cNKP, cNumKP);
    m_Combo1.GetLBText(m_Combo1.GetCurSel(), cStr);
    Dlg.m_strTypeKP = CString("Тип: ") + cStr;
    Dlg.iZp = iZp;
    Dlg.iFo = iFo;
    Dlg.PrihKp = Prih;
    Dlg.PaspKp = Pasp;
    Pasp.dwTKP = dwTypeKP;
    if( Dlg.DoModal() == IDCANCEL ) 
    {
        return;
    }
    Prih = Dlg.PrihKp;
    Pasp = Dlg.PaspKp;
    DisableBtns();
    m_ButPrihod.EnableWindow();

    m_Hint.SetWindowText("В базе данных зарегистрирована запись о приходе");
    qwIKP = Pasp.qwIKP;
    SelPrih();
    ClearFlag = true;

    SetButtons();
*/
}

//Rashod
void CDlgKpVvod1::OnButton5() 
{
	
	CDlgRashod Dlg;
    CString cStr;
    m_edKpNum.GetWindowText(cStr);
    Dlg.m_strNKP = CString("Номер: ") + cStr;
	strcpy(Pasp.cNKP, cStr);
    m_Combo1.GetLBText(m_Combo1.GetCurSel(), cStr);
    Dlg.m_strTKP = CString("Тип: ") + cStr;
    Dlg.qwIZAP = qwIZap;
    Dlg.Prih = Prih;
	Dlg.Pasp = Pasp;
    if( Dlg.DoModal() == IDCANCEL ) return;
    Prih = Dlg.Prih;
    m_edKpNum.SetWindowText("");
    DisableBtns();
    iZp = 0;
    iFo = 0;
    ZeroMemory(&Prih, sizeof(Prih));
    ZeroMemory(&Pasp, sizeof(Pasp));
    m_edKpNum.SetFocus();
	
}

void CDlgKpVvod1::DisableBtns()
{
//    if( !ClearFlag ) return;
    m_ButPrihod.EnableWindow(FALSE);
    m_ButObmer.EnableWindow(FALSE);
    m_ButRem.EnableWindow(FALSE);
    m_ButMont.EnableWindow(FALSE);
    m_ButRash.EnableWindow(FALSE);
    m_ButPrihod2.EnableWindow(FALSE);
    m_ButTwin.EnableWindow(FALSE);
    m_ButZapr.EnableWindow(FALSE);
    ClearFlag = false;
}

void CDlgKpVvod1::OnChangeEditNKP() 
{
    DisableBtns();
    iZp = 0;
    iFo = 0;
    ZeroMemory(&Prih, sizeof(Prih));
    ZeroMemory(&Pasp, sizeof(Pasp));
}

void CDlgKpVvod1::OnSelchangeComboTKP() 
{
    DisableBtns();
    iZp = 0;
    iFo = 0;
    ZeroMemory(&Prih, sizeof(Prih));
    ZeroMemory(&Pasp, sizeof(Pasp));
}

//Обмер
void CDlgKpVvod1::OnButton2() 
{
	CDlgObmerKP Dlg;
    m_edKpNum.GetWindowText(Dlg.m_EditNKP);
    m_Combo1.GetLBText(m_Combo1.GetCurSel(), Dlg.m_EditTKP);
    Dlg.qwIZAP = qwIZap;
    if( Dlg.DoModal() == IDCANCEL ) return;

	if( qwIZap )
	{
		SetButtons(qwIZap);
/*		char cQ[255] = "";
		char cText[64] = "";
		long Ind = 0;
		sprintf( cQ, "pTov_KP_GetPrihodByIZap %s, %d", isNull(qwIZap), g_iDep );
		DBW.ExecSQL( cQ );
		DBW.Fetch();
		DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind > 0 )
		{
			m_edKlPrIzg.SetWindowText( cText );
		}
		
		SYSTEMTIME tm;
		ZeroMemory( &tm, sizeof( tm ) );
		mgSQLGetSysDate(5, &tm, &Ind );
		if( Ind > 0 )
		{			
			m_edYearIzg.SetValue( (DWORD)tm.wYear );
		}*/
	}


	/*
	CDlgObmerKP Dlg;
    m_edKpNum.GetWindowText(Dlg.m_EditNKP);
    m_Combo1.GetLBText(m_Combo1.GetCurSel(), Dlg.m_EditTKP);
    Dlg.qwIZAP = Prih.qwIZAP;
    Dlg.Pasp = Pasp;
    Dlg.Prih = Prih;
    Dlg.iZp = iZp;
    Dlg.iFo = iFo;
    if( Dlg.DoModal() == IDCANCEL ) return;
    Prih = Dlg.Prih;
    Pasp = Dlg.Pasp;
    iZp = Dlg.iZp;
    iFo = Dlg.iFo;
	*/
    
}

//Remont kp
void CDlgKpVvod1::OnButtonRemont() 
{
	
    CDlgRemKP Dlg;
    m_edKpNum.GetWindowText(Dlg.m_strNKP);
    m_Combo1.GetLBText(m_Combo1.GetCurSel(), Dlg.m_strTKP);
    Dlg.Pasp = Pasp;
    Dlg.Prih = Prih;

	Dlg.Prih.qwIZAP = qwIZap;

    if( Dlg.DoModal() == IDCANCEL ) return;
    Pasp = Dlg.Pasp;
    Prih = Dlg.Prih;
//    SetButtons();
	
}

void CDlgKpVvod1::OnButtonMntBuks() 
{    
	
    CString cStr1, cStr2;
    m_edKpNum.GetWindowText(cStr1);
    m_Combo1.GetLBText(m_Combo1.GetCurSel(), cStr2);
    CDlgMntBuks Dlg;
    Dlg.dwRem = Prih.dwTREB_REM;
    Dlg.dwTKP = Pasp.dwTKP;
    Dlg.m_strNumKP = CString("Номер: ") + cStr1;
    Dlg.m_strTKP = CString("Тип: ") + cStr2;
    Dlg.qwIZAP = Prih.qwIZAP;
    Dlg.Pasp = Pasp;
    Dlg.Prih = Prih;
    if( Dlg.DoModal() == IDCANCEL ) return;
    Pasp = Dlg.Pasp;
    Prih = Dlg.Prih;

}

void CDlgKpVvod1::SetButtons(__int64 qwInitIZap)
{
		char cQ[128] = "";
		char cText[64] = "";
		DWORD dwNum = 0; 
		long Ind = 0;

		sprintf(cQ, "pTov_KP_GetButtonsCfg %I64u", qwInitIZap );
		DBW.ExecSQL(cQ);
		DBW.Fetch();

		DBW.GetData(1, SQL_C_CHAR, cText, 20, &Ind );
		if( Ind != -1 ) m_edKpNum.SetWindowText(cText);

		DBW.GetData(2, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_butVybrat.EnableWindow(dwNum);
		else m_butVybrat.EnableWindow(0);

		DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_ButReady.EnableWindow(dwNum);
		else m_ButReady.EnableWindow(0);

		DBW.GetData(4, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_butExit.EnableWindow(dwNum);
		else m_butExit.EnableWindow(0);

		DBW.GetData(5, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_butPasp.EnableWindow(dwNum);
		else m_butPasp.EnableWindow(0);

		DBW.GetData(6, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_ButPrihod.EnableWindow(dwNum);
		else m_ButPrihod.EnableWindow(0);

		DBW.GetData(7, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_ButObmer.EnableWindow(dwNum);
		else m_ButObmer.EnableWindow(0);

		DBW.GetData(8, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_ButRem.EnableWindow(dwNum);
		else m_ButRem.EnableWindow(0);

		DBW.GetData(9, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_ButMont.EnableWindow(dwNum);
		else m_ButMont.EnableWindow(0);

		DBW.GetData(10, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_ButRash.EnableWindow(dwNum);
		else m_ButRash.EnableWindow(0);

		DBW.GetData(11, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_ButZapr.EnableWindow(dwNum);
		else m_ButZapr.EnableWindow(0);

		DBW.GetData(12, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_ButPrihod2.EnableWindow(dwNum);
		else m_ButPrihod2.EnableWindow(0);

		
		
		DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_edYearIzg.SetWindowText(cText);

		DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_edKlPrIzg.SetWindowText(cText);

		DBW.GetData(15, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_edKlPrIzg.SetData( dwNum );

		DBW.CloseCursor();
/*
        m_ButRash.EnableWindow();

        switch (Prih.dwPriznRas)
        {
        case 1:            
            if( Prih.dwTREB_REM ) 
            {
                m_ButRem.EnableWindow();
                m_ButObmer.EnableWindow();
            }
        break;
        case 10:
                if( ZapressIsOpened ) m_ButZapr.EnableWindow();
                if( strcmp(Prih.cNeisp_KL, "5") == 0 ) 
                {
                    m_ButPrihod.EnableWindow(FALSE);
                    if( PrihodOsIsOpened ) m_ButPrihod2.EnableWindow();
                } else
                {
                    m_ButPrihod2.EnableWindow(FALSE);
                    m_ButPrihod.EnableWindow();

                }
        break;
        case 11:
        case 12:
                m_ButRem.EnableWindow();
                m_ButMont.EnableWindow();
        break;
        case 20:
                if( ZapressIsOpened ) m_ButZapr.EnableWindow();
                m_ButRem.EnableWindow();
                m_ButMont.EnableWindow();
                m_ButObmer.EnableWindow();
        break;
        case 21:
        case 22:
                if( ZapressIsOpened ) m_ButZapr.EnableWindow();
                m_ButRem.EnableWindow();
                m_ButMont.EnableWindow();
                m_ButObmer.EnableWindow();
                if( strcmp(Prih.cNeisp_KL, "5") == 0 ) 
                {
                    m_ButPrihod.EnableWindow(FALSE);
                    if( PrihodOsIsOpened ) m_ButPrihod2.EnableWindow();
                } else
                {
                    m_ButPrihod2.EnableWindow(FALSE);
                    m_ButPrihod.EnableWindow();
                }
        break;
        }
		*/
}

void CDlgKpVvod1::OnButtonZapress() 
{
    CDlgZapressKP Dlg;
    Dlg.dwTKP = Pasp.dwTKP;
    Dlg.dwTypeRem = Prih.wITR;
    Dlg.qwIKP = Pasp.qwIKP;
    Dlg.qwIZAP = Prih.qwIZAP;
    Dlg.dwPriznRas = Prih.dwPriznRas;
    Dlg.dwGruz = Prih.wGruz;
    m_edKpNum.GetWindowText(Dlg.strNum);
    m_Combo1.GetWindowText(Dlg.strType);

    if( Dlg.DoModal() == IDCANCEL ) return;
    DBW.GetPaspKP(Pasp.qwIKP, &Pasp);
    DBW.GetPrihodKP(Prih.qwIZAP, &Prih); 
    Prih.dwPriznRas = Dlg.dwPriznRas;
    Prih.wGruz = (WORD)Dlg.dwGruz;    
//    SetButtons();

}

void CDlgKpVvod1::OnBnPrihodOS() 
{
	CDlgPrihodOS Dlg;
    m_edKpNum.GetWindowText(Dlg.strNum);
    m_Combo1.GetWindowText(Dlg.strType);
    Dlg.dwTKP = Pasp.dwTKP;
    Dlg.dwPriznRas = Prih.dwPriznRas;
    Dlg.dwGruz = Pasp.wGruz;
    Dlg.qwIKP = Pasp.qwIKP;
    Dlg.qwIZAP = Prih.qwIZAP;
    if( Dlg.DoModal() == IDCANCEL ) return;
    Pasp.wGruz = (WORD)Dlg.dwGruz;
    Prih.dwPriznRas = Dlg.dwPriznRas;
    Pasp.qwIKP = Dlg.qwIKP;
    qwIKP = Pasp.qwIKP;
    Prih.qwIZAP = Dlg.qwIZAP;
    Prih.stDatPost = Dlg.st;
    DBW.GetPrihodKP(Prih.qwIZAP, &Prih);

//    SelPrih();
/*
    m_ButPrihod.EnableWindow(FALSE);
    m_ButObmer.EnableWindow();
    m_ButZapr.EnableWindow();
    m_ButRem.EnableWindow();
    m_ButMont.EnableWindow();
    m_ButRash.EnableWindow();
    m_ButPrihod2.EnableWindow();
    m_ButTwin.EnableWindow();
*/
//    SetButtons();	

}

void CDlgKpVvod1::OnBnClickedButton_PaspKP()
{
	CDlgPaspKP Dlg;
	if( qwIZap ) Dlg.qwInitIZAP = qwIZap;
	else
	{
		m_edKpNum.GetWindowText(Dlg.cNKP, 12);
		m_edKlPrIzg.GetWindowText(Dlg.cKlPrIzg, 9);
		m_edYearIzg.GetWindowText(Dlg.cYearIzg, 8);
		Dlg.iTKP = (int)m_Combo1.GetItemData(m_Combo1.GetCurSel());
	}
	Dlg.DoModal();
}

void CDlgKpVvod1::OnBnClickedButton_SelectKP()
{
	CDlgPrihKpList Dlg;
	if( Dlg.DoModal() == IDCANCEL || !Dlg.qwRetIZap ) return;

	qwIZap = Dlg.qwRetIZap;
	UpdateFieldsByIZap( Dlg.qwRetIZap );

	iGotKPfromSelKP = 1;
	iReadyState = 0;
//	m_ButReady.SetWindowText("Новая КП");
	OnReady();	
}

void CDlgKpVvod1::UpdateFieldsByIZap( __int64 z )
{
	char cQ[255] = "";
	char cText[64] = "";
	DWORD dwNum = 0;
	long Ind = 0;
	sprintf(cQ, "pTov_KP_GetKpKeysByIZap %I64u", z);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_edKpNum.SetWindowText(cText);

	DBW.GetData(2, SQL_C_ULONG, &dwNum, 64, &Ind );
	if( Ind != -1 ) 
	{
		for( int i=0; i < m_Combo1.GetCount(); i++ )
			if( m_Combo1.GetItemData(i) == dwNum )
				m_Combo1.SetCurSel(i);
	}

	DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_edKlPrIzg.SetWindowText(cText);

	DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_edYearIzg.SetWindowText(cText);

	DBW.CloseCursor();
}

void CDlgKpVvod1::OnBnClicked_SelKlIzg()
{
	CDlgSprav1 Dlg;
    Dlg.iDlgKind = 4;
    if( Dlg.DoModal() == IDCANCEL ) return;

	m_edKlPrIzg.SetWindowText(Dlg.cKodPr);
	m_edKlPrIzg.SetData(Dlg.ret_dwIPR);
}

void CDlgKpVvod1::OnEnChangeEdit7()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDlgWithAccelerators::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
