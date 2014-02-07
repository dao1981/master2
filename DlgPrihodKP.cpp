// DlgPrihodKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPrihodKP.h"
#include "DlgSprav1.h"
#include "DlgSpravKdr.h"
#include "DlgSpravSmp.h"
#include "MaskEdit.h"
#include "PrintableDlg.h"
#include "DlgSprPrSobstv.h"
#include ".\telecom\teleI.h"

#include <sql.h>
#include <sqlext.h> 
#include <sqltypes.h>
#include "odbcss.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp theApp;

int iCheckVagValid = 0;

extern SQLRETURN    g_sqlret;
extern SYSTEMTIME   g_CurrentDate;
extern DWORD         g_iDep;
extern BYTE         gs_DateFmt;
extern cd_TeleI *tele;

#define PRIHOD_KP_WRITE_TO_BASE 0
#define PRIHOD_KP_FROM_VAG 2

/////////////////////////////////////////////////////////////////////////////
// CDlgPrihodKP dialog

bool bPrPeresWasEdited = false;

CDlgPrihodKP::CDlgPrihodKP(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgPrihodKP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPrihodKP)
	m_strNumKP = _T("");
	m_strTypeKP = _T("");
	m_Edit8Text = _T("");
	m_Edit6Text = _T("");
	m_Cb1Index = -1;
	m_Cb2ndex = -1;
	m_strNumVag = _T("");
	m_strFIO = _T("");
	//}}AFX_DATA_INIT
    iMode = 0;
    bStarted = false;
    dwPrIzgot = 0;
    dwPrPeres = 0;
    dwPrPosFor = 0;
    dwPrPosOsv = 0;
	dwNeispId = 0;
    iZp = 0;
    iFo = 0;
    m_DatIzg.SetMode(3);
    m_DatFor.SetMode(3);
    m_DatOsv.SetMode(3);
    m_DatPost.SetMode(1);    
	dwKlPrIzgot = 0;
    dwKlPrPosFor = 0;
    dwKlPrPosOsv = 0;
	dwIFam = 0;

	qwIZap = 0;
	qwIKP = 0;
	cNKP[0] = 0;
	iTKP = 0;
	cKlPrIzg[0] = 0;
	ZeroMemory(&stDatIzg, sizeof(stDatIzg));
	ZeroMemory(&stOld_IzgDat, sizeof(stOld_IzgDat)); 
	iInitFrom = INIT_FROM_GIVEN_SIMPLE;
	
}


void CDlgPrihodKP::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPrihodKP)
	DDX_Control(pDX, IDC_BUTTON7, m_ButPasp);
	DDX_Control(pDX, IDC_BUTTON29, m_SendToAsuv);
	DDX_Control(pDX, IDC_EDIT22, m_DatPost);
	DDX_Control(pDX, IDC_COMBO4, m_Combo4);
	DDX_Control(pDX, IDC_COMBO6, m_ComboTKP);
	DDX_Control(pDX, IDC_EDIT2, m_EdTKP);
	DDX_Control(pDX, IDC_EDIT1, m_EdNKP);
	DDX_Control(pDX, IDC_EDIT13, m_EdFIOPrih);
	DDX_Control(pDX, IDC_BUTTON5, m_ButFIO);
	DDX_Control(pDX, IDC_EDIT5, m_Edit5);
	DDX_Control(pDX, IDC_EDIT4, m_Edit4);
	DDX_Control(pDX, IDC_EDIT6, m_Edit6);
	DDX_Control(pDX, IDC_EDIT7, m_Edit7);
	DDX_Control(pDX, IDC_EDIT21, m_DatOsv);
	DDX_Control(pDX, IDC_EDIT20, m_DatFor);
	DDX_Control(pDX, IDC_EDIT18, m_DatIzg);
	DDX_Control(pDX, IDC_EDIT19, m_Date5);
	DDX_Control(pDX, IDC_EDIT17, m_Edit17);
	DDX_Control(pDX, IDC_COMBO3, m_Combo3);
	DDX_Control(pDX, IDC_EDIT10, m_EdNeispName);
	DDX_Control(pDX, IDC_EDIT9, m_EdNeispCode);
	DDX_Control(pDX, IDC_EDIT12, m_EdKlPrOsv);
	DDX_Control(pDX, IDC_EDIT11, m_EdKlPrFor);
	DDX_Control(pDX, IDC_EDIT8, m_EdKlPrIzg);
	DDX_Control(pDX, IDC_EDIT15, m_Edit15);
	DDX_Control(pDX, IDC_BUTTON6, m_Button6);
	DDX_Control(pDX, IDC_EDIT14, m_Edit14);
	DDX_Control(pDX, IDC_EDIT3, m_EditVag);
	DDX_Control(pDX, IDC_RADIO2, m_Check2);
	DDX_Control(pDX, IDC_RADIO1, m_Check1);
	DDX_Control(pDX, IDC_CHECK1, m_CheckBox1);
	DDX_Control(pDX, IDC_EDIT24, m_EdParkNum);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_EDIT25, m_EdSobst);
	DDX_Control(pDX, IDC_COMBO5, m_CbSteel);
	DDX_Control(pDX, IDC_STATIC_TKPLAB, m_LabTkp);
	DDX_Text(pDX, IDC_EDIT1, m_strNumKP);
	DDX_Text(pDX, IDC_EDIT2, m_strTypeKP);
	DDX_Text(pDX, IDC_EDIT8, m_Edit8Text);
	DDX_Text(pDX, IDC_EDIT6, m_Edit6Text);
	DDX_CBIndex(pDX, IDC_COMBO1, m_Cb1Index);
	DDX_CBIndex(pDX, IDC_COMBO2, m_Cb2ndex);
	DDX_Text(pDX, IDC_EDIT3, m_strNumVag);
	DDX_Text(pDX, IDC_EDIT13, m_strFIO);
	
	DDX_Control(pDX, IDC_EDIT95, m_EdD_l);
	DDX_Control(pDX, IDC_EDIT46, m_EdD_r);

	DDX_Control(pDX, IDC_EDIT78, m_EdGreb_r);
	DDX_Control(pDX, IDC_EDIT79, m_EdGreb_l);
	DDX_Control(pDX, IDC_EDIT83, m_EdObod_l);
	DDX_Control(pDX, IDC_EDIT76, m_EdObod_r);
	DDX_Control(pDX, IDC_EDIT84, m_EdProkat_l);
	DDX_Control(pDX, IDC_EDIT77, m_EdProkat_r);
	//}}AFX_DATA_MAP
//	DDX_Control(pDX, IDC_CHECK6, m_CheckSteel);
}


BEGIN_MESSAGE_MAP(CDlgPrihodKP, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgPrihodKP)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON29,OnSendToASUV)
	ON_EN_CHANGE(IDC_EDIT9, OnChangeEdit9)
	ON_BN_CLICKED(IDOK, OnAddToBase)
	ON_EN_CHANGE(IDC_EDIT14, OnChangeEdit14)
	ON_EN_KILLFOCUS(IDC_EDIT8, OnKillfocusPrIzg)
	ON_EN_KILLFOCUS(IDC_EDIT11, OnKillfocusPrForOsv)
	ON_EN_KILLFOCUS(IDC_EDIT12, OnKillfocusPrPosOsv)
	ON_EN_KILLFOCUS(IDC_EDIT3, OnKillfocusVagNum)
	ON_EN_SETFOCUS(IDC_EDIT18, OnSetfocusPrIzg)
	ON_EN_KILLFOCUS(IDC_EDIT14, OnKillfocusEdit_PR1)
	ON_BN_CLICKED(IDC_BUTTON7, OnButtonPasport)
    ON_CBN_SELCHANGE(IDC_COMBO1, OnCombo1Change)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON8, &CDlgPrihodKP::OnBnClickedButtonSelSobst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPrihodKP message handlers

BOOL CDlgPrihodKP::OnInitDialog() 
{
	bPrPeresWasEdited = false;
	CDlgWithAccelerators::OnInitDialog();  
    iCheckVagValid = 0;
	m_EdParkNum.SetMode(0, 0, 5);
    m_Combo2.EnableWindow(FALSE);
	m_Edit17.ModifyStyle(0, WS_DISABLED);
    m_Date5.EnableWindow(FALSE);
    m_Edit15.EnableWindow(FALSE);
    m_Button6.EnableWindow(FALSE);

	m_EdProkat_l.iMode = m_EdProkat_r.iMode = 2;
    m_EdProkat_l.Prec = m_EdProkat_r.Prec = 1;
    m_EdProkat_l.Scale = m_EdProkat_r.Scale = 1;
    m_EdObod_r.iMode = m_EdObod_l.iMode = 2;
    m_EdObod_r.Scale = m_EdObod_l.Scale = 0;
    m_EdObod_r.Prec = m_EdObod_l.Prec = 2;
    m_EdGreb_r.iMode = m_EdGreb_l.iMode = 2;
    m_EdGreb_r.Prec = m_EdGreb_l.Prec = 2;
    m_EdGreb_r.Scale = m_EdGreb_l.Scale = 0;
	m_EdD_r.iMode = m_EdD_l.iMode = 2;
    m_EdD_r.Prec = m_EdD_l.Prec = 3;
    m_EdD_r.Scale = m_EdD_l.Scale = 1;
	
	OnRadio1();

	m_EditVag.QInit(80, 1);
	m_EdNeispCode.QInit(21, 1);
	
	m_EdSobst.ModifyStyle(0, WS_DISABLED);

    m_Edit6.iMode = m_Edit7.iMode = 2;
    m_Edit6.Prec = m_Edit7.Prec = 3;
    m_Edit6.Scale = m_Edit7 .Scale = 1;
    m_DatPost.InitDate();
/*
	m_EdKlPrOsv.QInit(50, 1);
	m_EdKlPrFor.QInit(50, 1);
	m_EdKlPrIzg.QInit(50, 1);
*/
	m_Combo1.SetItemData(0, 0);
	m_Combo1.SetItemData(1, 1);
	m_Combo1.SetItemData(2, 4);

    m_EdFIOPrih.SetMode(5);

    DBW.FillEmplArray(m_EdFIOPrih.lpEmpl, 1);
//    m_EdFIOPrih.lpEmpl->
    m_Edit15.QInit(40, 1);

	m_CbSteel.AddString("T");
	m_CbSteel.SetItemData(0, 1);
	m_CbSteel.AddString("2");
	m_CbSteel.SetItemData(1, 2);
	m_CbSteel.AddString("2Г");
	m_CbSteel.SetItemData(2, 3);

    char cQuery[512] = "SELECT ITR, SNAME FROM nsTovTYPE_RED WHERE IKORR IS NULL";
    char cText[512] = "";
    long Ind;

    DBW.ExecSQL(cQuery);
    for(WORD i=0; (g_sqlret = DBW.Fetch() != SQL_NO_DATA) && g_sqlret != SQL_ERROR && i < 512; i++)
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwItr[i], 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 512, &Ind);
        m_Combo2.AddString(cText);
		m_Combo2.SetItemData(i, dwItr[i]);
    }
    DBW.CloseCursor();

    strncpy(cQuery, "pTov_GetTypeRemKP", 32 );
    DBW.ExecSQL(cQuery);
    for(WORD i=0; (g_sqlret = DBW.Fetch() != SQL_NO_DATA) && g_sqlret != SQL_ERROR && i < 512; i++)
    {
        DBW.GetData( 2, SQL_C_CHAR, cText, 512, &Ind);
        m_Combo3.AddString(cText);
        DBW.GetData( 3, SQL_C_SLONG, &dwTypeRem[i], 4, &Ind);
		m_Combo3.SetItemData(i, dwTypeRem[i]);
    }
    DBW.CloseCursor();
/*    m_Edit8.ModifyStyle(0, WS_DISABLED);
    m_EdKlPrFor.ModifyStyle(0, WS_DISABLED);*/
    m_Edit4.QInit(20);
    m_Edit5.QInit(20);
	m_Edit14.QInit(60, 1);
	DBW.FillComboWithTRemVag(&m_Combo4);
//	IniFromGiven();
	
	m_ComboTKP.ModifyStyle( WS_VISIBLE, 0 );
	char cQ[255] = "";
	DWORD dwNum = 0;
	SYSTEMTIME st;
	
	m_ComboTKP.ModifyStyle(WS_VISIBLE, 0);
/*	if( PaspKp.dwTKP == 100 ) // тип КП неопределен
	{*/
		strncpy(cQ, "pTov_GetTKP",15);
		cText[0] = 0;
		dwNum = 0;
		DBW.ExecSQL(cQ);
		Ind = 0;
		for(DWORD i=0; DBW.Fetch() != SQL_NO_DATA && i < 64; i++ )
		{
			DBW.GetData( 1, SQL_C_ULONG, &dwNum, 8, &Ind);
			DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
			m_ComboTKP.AddString(cText);
			m_ComboTKP.SetItemData(i, dwNum);
			if( dwNum == 100 ) m_ComboTKP.SetCurSel(i);
		}
		DBW.CloseCursor();
//	}

	if( iInitFrom == INIT_FROM_DB && qwIZap ) // Заполняем форму целиком из базы по IZAP
	{
		PrihKp.qwIZAP = qwIZap;
		sprintf( cQ, "pTov_KP_GetPrihodByIZap %I64u, %u", qwIZap, g_iDep );
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, &cText, 20, &Ind);
		if( Ind != -1 ) 
		{
			m_EdNKP.SetWindowText(cText);
			strncpy(cNKP, cText, 12);
		}
		DBW.GetData(2, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 ) 
		{
			SetComboBoxItemByID( &m_ComboTKP, dwNum );
			if( dwNum == 100 )
			{
				m_ComboTKP.ModifyStyle( 0, WS_VISIBLE, 0 );
				m_EdTKP.ModifyStyle( WS_VISIBLE, 0 );
//				m_LabTkp.ModifyStyle( WS_VISIBLE, 0 );
			} else
			{
				m_ComboTKP.ModifyStyle( WS_VISIBLE, 0 );
			}
			iTKP = dwNum;
			PrihKp.dwTKP = dwNum;
		}		
		DBW.GetData(3, SQL_C_CHAR, &cText, 10, &Ind);
		if( Ind != -1 ) m_EdTKP.SetWindowText(cText);
		
		DBW.GetData(4, SQL_C_CHAR, &cText, 10, &Ind);
		if( Ind != -1 ) m_EdKlPrIzg.SetWindowText(cText);

		mgSQLGetSysDate(5, &st, &Ind );
		if( Ind != -1 ) m_DatIzg.SetTime(&st);

		mgSQLGetSysDate(6, &st, &Ind );
		if( Ind != -1 ) m_DatPost.SetTime(&st);
		
		DBW.GetData(7, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 )
		{
			switch ( dwNum )
			{
			case 0: // Пассажирская
						m_Combo1.SetCurSel(0);
						m_Combo2.EnableWindow();
						m_CheckBox1.EnableWindow(FALSE);
			break;
			case 1: // Грузовая
						m_Combo1.SetCurSel(1);
						m_Combo2.EnableWindow(FALSE);
						m_CheckBox1.EnableWindow(); 
			break;
			case 2: // "Г" На ободе :- )
						m_Combo1.SetCurSel(1);
						m_CheckBox1.SetCheck(1);
						m_Combo2.EnableWindow(FALSE);
			break;
			case 4: // Разутая
						m_Combo1.SetCurSel(2);
						m_CheckBox1.EnableWindow(FALSE);
						m_Combo2.EnableWindow();
			break;
			}
		}
		DBW.GetData(8, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 )
		{
			SetComboBoxItemByID( &m_Combo2, dwNum);
		}
		mgSQLGetSysDate(9, &st, &Ind );
		if( Ind != -1 ) m_DatFor.SetTime(&st);

		DBW.GetData(10, SQL_C_CHAR, &cText, 10, &Ind);
		if( Ind != -1 ) m_EdKlPrFor.SetWindowText(cText);

		mgSQLGetSysDate(11, &st, &Ind );
		if( Ind != -1 ) m_DatOsv.SetTime(&st);

		DBW.GetData(12, SQL_C_CHAR, &cText, 10, &Ind);
		if( Ind != -1 ) m_EdKlPrOsv.SetWindowText(cText);

		DBW.GetData(13, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 )
			m_EdNeispCode.SetData(dwNum);

		DBW.GetData(14, SQL_C_CHAR, &cText, 10, &Ind);
		if( Ind != -1 ) m_EdNeispCode.SetWindowText(cText);

		DBW.GetData(15, SQL_C_CHAR, &cText, 20, &Ind);
		if( Ind != -1 ) m_EdNeispName.SetWindowText(cText);

		DBW.GetData(16, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) SetComboBoxItemByID(&m_Combo3, dwNum);

		DBW.GetData(17, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_EdFIOPrih.SetData(dwNum);

		DBW.GetData(18, SQL_C_CHAR, &cText, 20, &Ind);
		if( Ind != -1 ) m_EdFIOPrih.SetWindowText(cText);

		DBW.GetData(19, SQL_C_CHAR, &cText, 20, &Ind);
		if( Ind != -1 ) m_EdParkNum.SetWindowText(cText);

		DBW.GetData(20, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) SetComboBoxItemByID(&m_CbSteel, dwNum);

		DBW.GetData(21, SQL_C_CHAR, &cText, 6, &Ind);
		if( Ind != -1 ) m_Edit4.SetWindowText(cText);

		DBW.GetData(22, SQL_C_CHAR, &cText, 6, &Ind);
		if( Ind != -1 ) m_Edit5.SetWindowText(cText);

		DBW.GetData(23, SQL_C_CHAR, &cText, 6, &Ind);
		if( Ind != -1 ) m_Edit6.SetWindowText(cText);

		DBW.GetData(24, SQL_C_CHAR, &cText, 6, &Ind);
		if( Ind != -1 ) m_Edit7.SetWindowText(cText);

		DBW.GetData(25, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_EdSobst.SetData(dwNum);

		DBW.GetData(26, SQL_C_CHAR, &cText, 64, &Ind);
		if( Ind != -1 ) m_EdSobst.SetWindowText(cText);

		//Из-под вагона
		DBW.GetData(27, SQL_C_CHAR, &cText, 64, &Ind);
		if( Ind != -1 ) 
		{
			OnRadio1();
			m_EditVag.SetWindowText(cText);
			m_Check1.SetCheck(1);
		}

		DBW.GetData(28, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) SetComboBoxItemByID(&m_Combo4, dwNum);
		// Пересылка
		DBW.GetData(29, SQL_C_CHAR, &cText, 64, &Ind);
		if( Ind != -1 ) m_Edit15.SetWindowText(cText);
		mgSQLGetSysDate(30, &st, &Ind );		
		if( Ind != -1 ) 
		{	
			OnRadio2();
			m_Date5.SetTime(&st);
			m_Check2.SetCheck(1);
			m_Button6.EnableWindow(1);
		}
		DBW.GetData(31, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) 
		{
			m_Edit14.SetData(dwNum);
			dwPrPeres = dwNum;
		}
		DBW.GetData(32, SQL_C_CHAR, &cText, 64, &Ind);
		if( Ind != -1 ) m_Edit14.SetWindowText(cText);
		DBW.GetData(33, SQL_C_CHAR, &cText, 64, &Ind);
		if( Ind != -1 ) m_Edit17.SetWindowText(cText);

		DBW.GetData(34, SQL_C_UBIGINT, &qwIKP, 8, &Ind );

		DBW.CloseCursor();
	} else
	if( iInitFrom == INIT_FROM_GIVEN_SIMPLE )
	{
		m_EdNKP.SetWindowText(cNKP);
		if( cKlPrIzg[0] ) m_EdKlPrIzg.SetWindowText(cKlPrIzg);
		if( stOld_IzgDat.wYear ) m_DatIzg.SetTime(&stOld_IzgDat);

		if( PrihKp.cNKP[0] ){m_EdNKP.SetWindowText( PrihKp.cNKP ); strncpy( cNKP, PrihKp.cNKP, 20 );}
		if( PrihKp.dwTKP ) {m_EdTKP.SetWindowText( DBW.GetTKPNameByID( PrihKp.dwTKP ));iTKP = PrihKp.dwTKP;}
				

	}

	if( iMode == PRIHOD_KP_FROM_VAG ) // приход новой КП из формы "ввод данных по вагонам"
	{
	
		if( iInitFrom != INIT_FROM_DB )
		{
			if( PrihKp.cPrihNVag[0] )m_EditVag.SetWindowText(PrihKp.cPrihNVag);
			if( PrihKp.stDatPost.wYear ) m_DatPost.SetTime(&PrihKp.stDatPost);

			if( PrihKp.cNKP[0] ){ m_EdNKP.SetWindowText( PrihKp.cNKP ); strncpy( cNKP, PrihKp.cNKP, 20 );}
			if( PrihKp.dwTKP ){ m_EdTKP.SetWindowText( DBW.GetTKPNameByID( PrihKp.dwTKP )); iTKP = PrihKp.dwTKP;}

			if( PrihKp.dwRemVagID )SetComboBoxItemByID(&m_Combo4, PrihKp.dwRemVagID );

			m_EdFIOPrih.SetData(PrihKp.dwFam);
		}
		if( !m_EditVag.isNull() )
		{
			m_Check1.SetCheck(1);
			OnRadio1();
		} else
		{
			OnRadio2();
		}

		m_EditVag.ModifyStyle(0, WS_DISABLED);
		m_Combo4.ModifyStyle(0, WS_DISABLED);
		m_Check1.ModifyStyle(0, WS_DISABLED);
		m_Check2.EnableWindow(FALSE);
		m_Edit14.EnableWindow(FALSE);
		m_Edit15.EnableWindow(FALSE);
		m_Edit17.EnableWindow(FALSE);
		m_Button6.EnableWindow(FALSE);
		m_Date5.EnableWindow(FALSE);
		m_DatPost.EnableWindow(TRUE);
		iCheckVagValid = 0;

		if( iInitFrom == INIT_FROM_GIVEN ) IniFromGiven();

	}
	IniObmer();
	if( !qwIZap && !PrihKp.qwIZAP ) m_ButPasp.EnableWindow(0);
	bStarted = 1;
	
/*
    if( !PaspKp.qwIKP ) m_ButPasp.EnableWindow(FALSE);    
    m_Check1.SetCheck(1);
    OnRadio1();

    if( iMode != 3 ) IniForm();
	if( PaspKp.qwIKP || iMode == 2 || iMode == 3 ) IniFromGiven();

    if( !PrihKp.qwIZAP ) 
    {
        if( g_dwDepoGruzPas == 1 ) m_Combo1.SetCurSel(1);
        else
        m_Combo1.SetCurSel(0);

        if( g_dwTypeDep == 2 ) 
        {
            m_Check1.SetCheck(0);
            m_Check2.SetCheck(1);
            OnRadio2();
        }
    }
    bStarted = true;
    OnChangeEdit9();


    if( iMode == 2 || iMode == 3 )
    {
        m_EditVag.ModifyStyle(0, WS_DISABLED);
        m_Combo4.ModifyStyle(0, WS_DISABLED);
        m_Check1.ModifyStyle(0, WS_DISABLED);
        m_Check2.EnableWindow(FALSE);
        m_Edit14.EnableWindow(FALSE);
        m_Edit15.EnableWindow(FALSE);
        m_Edit17.EnableWindow(FALSE);
        m_Button6.EnableWindow(FALSE);
        m_Date5.EnableWindow(FALSE);
        m_DatPost.EnableWindow(TRUE);

        iCheckVagValid = 0;
    } else
        iCheckVagValid = 1;
	stOld_IzgDat = PaspKp.stIZOS_DAT;
	dwOld_IzgIPr = PaspKp.dwIzOsPr_ID;
*/
    return TRUE;
}

afx_msg void CDlgPrihodKP::OnCombo1Change()
{
    switch(m_Combo1.GetCurSel())
    {
    case 0:
    case 2:
		m_Combo2.EnableWindow();
		m_CheckBox1.EnableWindow(FALSE);
    break;
    case 1:
		m_Combo2.EnableWindow(FALSE);
		m_CheckBox1.EnableWindow();
    break;
    }
}

void CDlgPrihodKP::OnRadio1() 
{
//    if( m_Check1.GetCheck() ) return;
    m_Check1.SetCheck(1);
    m_Check2.SetCheck(0);
//    m_EditVag.ModifyStyle(WS_DISABLED, 0);
    m_EditVag.EnableWindow();
/*
    m_Edit14.ModifyStyle(0, WS_DISABLED);
    m_Edit17.ModifyStyle(0, WS_DISABLED);
*/
    m_Button6.EnableWindow(FALSE);
/*    m_Button6.ModifyStyle(0, WS_DISABLED);
    m_Button6.RedrawWindow();*/
    m_Date5.EnableWindow(FALSE);
//    m_Date5.ModifyStyle(0, WS_DISABLED);
    m_Edit15.EnableWindow(FALSE);
    m_Edit14.SetWindowText("");
    m_Edit17.SetWindowText("");
//	m_Edit14.ModifyStyle(WS_DISABLED, 0);
    m_Edit17.ModifyStyle(WS_DISABLED, 0);    
    m_Edit17.EnableWindow(FALSE);
	m_Edit14.EnableWindow(FALSE);	

    m_Date5.SetWindowText("");
    m_Edit15.SetWindowText("");
	m_Combo4.EnableWindow();
    dwPrPeres = 0;
    m_EditVag.SetFocus();
	m_Edit14.SetData(0);
    
//    m_Edit15.ModifyStyle(0, WS_DISABLED);
//    m_Edit15.ModifyStyleEx(0, WS_EX_TRANSPARENT);
//    m_Date5.RedrawWindow();
//    m_Edit15.RedrawWindow();
//    m_EditVag.RedrawWindow();
}

void CDlgPrihodKP::OnRadio2() 
{
//    if( m_Check2.GetCheck() ) return;
    m_Check2.SetCheck(1);
    m_Check1.SetCheck(0);
    m_EditVag.EnableWindow(FALSE);

    m_Button6.EnableWindow();
    m_Date5.EnableWindow();
    m_Edit15.EnableWindow();
    m_EditVag.SetWindowText("");
	m_Combo4.SetCurSel(-1);
	m_Combo4.EnableWindow(FALSE);
	m_Edit14.EnableWindow();
	m_Edit17.EnableWindow();
    m_Edit17.ModifyStyle(0, WS_DISABLED, 0);
    m_Edit14.SetFocus();
}

// Предприятие пересылки
void CDlgPrihodKP::OnButton6() 
{
	/*
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_Edit14.SetWindowText(Dlg.cKodPr);
    m_Edit17.SetWindowText(Dlg.cPrName);
    dwPrPeres = Dlg.ret_dwIPR;
	bPrPeresWasEdited = false;
//    strcpy(cTypePrIzgot, Dlg.cTypePr);
*/
	CDlgSprPrSobstv Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

	dwPrPeres = Dlg.dwSobstID;
	bPrPeresWasEdited = false;
//	m_Edit14.SetWindowText
	m_Edit14.SetData(dwPrPeres);
	m_Edit14.SetWindowText(Dlg.cKlPr);	
	m_Edit17.SetWindowText(Dlg.cPrName);

}

//Изг. оси
void CDlgPrihodKP::OnButton1() 
{
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 4;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdKlPrIzg.SetWindowText(Dlg.cKodPr); //Клеймо
    dwPrIzgot = Dlg.ret_dwIPR;
//	m_EdKlPrIzg.SetData(Dlg.ret_dwIPR);
//    PaspKp.dwIZOS_IPR = Dlg.ret_dwIPR;
    strcpy(cTypePrIzgot, Dlg.cTypePr);
//    ultoa(Dlg.ret_dwIPR, PaspKp.cIZOS_PR, 10);
    strcpy(PaspKp.cIzOsPr_KL, Dlg.cKodPr);
	dwKlPrIzgot = atoi(Dlg.cKodPr);
//	PaspKp.dwIzOsPr_ID = dwPrIzgot;
}

//Последнее формирование
void CDlgPrihodKP::OnButton3() 
{
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 2;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdKlPrFor.SetWindowText(Dlg.cKodPr);	
    dwPrPosFor = Dlg.ret_dwIPR;
	dwKlPrPosFor = atoi(Dlg.cKodPr);
//	m_EdKlPrFor.SetData(Dlg.ret_dwIPR);
}

//Последнее освидетельствование
void CDlgPrihodKP::OnButton4() 
{
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 3;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdKlPrOsv.SetWindowText(Dlg.cKodPr);
//	m_EdKlPrOsv.SetData(Dlg.ret_dwIPR);
    dwPrPosOsv = Dlg.ret_dwIPR;
	dwKlPrPosFor = atoi(Dlg.cKodPr);
}

void CDlgPrihodKP::OnButton5() 
{
    CDlgSpravKdr Dlg;
    Dlg.DlgMode = 1;
    Dlg.iFilter = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdFIOPrih.SetWindowText(Dlg.cFio);
	m_EdFIOPrih.SetData(Dlg.dwFio);
    PrihKp.dwFam = Dlg.dwFio;
}

//код неисправности
void CDlgPrihodKP::OnButton2() 
{
    CDlgSpravSmp Dlg;
    Dlg.Style = 1;
    Dlg.DlgMode = 111;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdNeispCode.SetWindowText(Dlg.cRet);
	m_EdNeispCode.SetData(Dlg.dwRet);
    char st[32] = "";
    for( int i=0; i < m_Combo3.GetCount(); i++ )
    {
        m_Combo3.GetLBText(i, st);
        if( !stricmp(Dlg.c_retText, st) ) 
        {
            m_Combo3.SetCurSel(i);
            return;
        }
    }
}

void CDlgPrihodKP::OnChangeEdit9() 
{
    if( !bStarted ) return;
    char cQ[64]="";
    char cText[64]="";
    m_EdNeispCode.GetWindowText(cText, 64);
    m_EdNeispName.SetWindowText("");
    sprintf( cQ, "pTov_GetTKP 2, '%s'", cText );
    DBW.ExecSQL(cQ);
    if( (g_sqlret=DBW.Fetch()) == SQL_NO_DATA &&
         g_sqlret == SQL_ERROR ) 
    {
        DBW.CloseCursor();
        return;
    }
    long Ind = 0;
    cText[0] = 0;
    DBW.GetData( 1, SQL_C_CHAR, cText, 64, &Ind);
    DBW.GetData( 2, SQL_C_SLONG, &dwNeispId, 4, &Ind);
	m_EdNeispCode.SetData(dwNeispId);
    m_EdNeispName.SetWindowText(cText);
    DBW.CloseCursor();
}


void CDlgPrihodKP::IniForm()
{
    char cQ[512] = "";
    char cText[64] = "";
	if( PaspKp.dwIzOsPr_ID )
	{
		m_DatIzg.SetTime( &PaspKp.stIZOS_DAT );
		m_EdKlPrIzg.SetWindowText(PaspKp.cIzOsPr_KL);
		dwPrIzgot = PaspKp.dwIzOsPr_ID;
	}
    //  Занесение в форму ранее введенной обязательной информации о приходе КП

    if( DBW.GetPrihodKP(PrihKp.qwIZAP, &PrihKp) == 0 )
	{
		if( PrihKp.dwPosForPr_ID == 0 )
		{
			strcpy(PrihKp.cPosForPr_KL, PaspKp.cPosForPr_KL);
			PrihKp.dwPosForPr_ID = PaspKp.dwPosForPr_ID;
			dwPrPosFor = PrihKp.dwPosForPr_ID;
//			m_CheckSteel.SetCheck(PrihKp.iSteelType);

			for( int i=0; i < m_CbSteel.GetCount() && i < 10; i++ )
			{
				if( m_CbSteel.GetItemData(i) == PrihKp.iSteelType )
					m_CbSteel.SetCurSel(i);
			}

			if( PrihKp.iParkNum )
			{
				itoa(PrihKp.iParkNum, cText, 10);			
				m_EdParkNum.SetWindowText(cText);
			}
		}
		if( PrihKp.dwPosOsvPr_ID == 0 )
		{
			strcpy(PrihKp.cPosOsvPr_KL, PaspKp.cPosOsvPr_KL);
			PrihKp.dwPosOsvPr_ID = PaspKp.dwPosOsvPr_ID;
			dwPrPosOsv = PrihKp.dwPosOsvPr_ID;
		}
	} else
	{
			strcpy(PrihKp.cPosForPr_KL, PaspKp.cPosForPr_KL);
			PrihKp.dwPosForPr_ID = PaspKp.dwPosForPr_ID;
			dwPrPosFor = PrihKp.dwPosForPr_ID;
			strcpy(PrihKp.cPosOsvPr_KL, PaspKp.cPosOsvPr_KL);
			PrihKp.dwPosOsvPr_ID = PaspKp.dwPosOsvPr_ID;
			dwPrPosOsv = PrihKp.dwPosOsvPr_ID;
	}
	m_ComboTKP.ModifyStyle(WS_VISIBLE, 0);
	if( PaspKp.dwTKP == 100 ) // тип КП неопределен
	{
		char cQ[255]="pTov_GetTKP";
		char cText[64] = "";
		DWORD dwNum = 0;
		DBW.ExecSQL(cQ);
		long Ind = 0;
		m_ComboTKP.ModifyStyle(0, WS_VISIBLE);
		m_EdTKP.ModifyStyle(WS_VISIBLE, 0);
		for(DWORD i=0; DBW.Fetch() != SQL_NO_DATA && i < 64; i++ )
		{
			DBW.GetData( 1, SQL_C_ULONG, &dwNum, 8, &Ind);
			DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
			m_ComboTKP.AddString(cText);
			m_ComboTKP.SetItemData(i, dwNum);
			if( dwNum == 100 ) m_ComboTKP.SetCurSel(i);
		}

	}	
}

int iNeedClosePrih = 1;
int iAddToBaseOK = 0;

void CDlgPrihodKP::OnAddToBase() 
{
	iAddToBaseOK = 0;
    char cText[64] = "";
    char cParams[512] = "";
    char cQ[1024] = "";
    char cPosForParam[255] = "";
    char cPosOsvParam[255] = "";
    char cTrParam[64] = "";
    char cTdParam[64] = "";
    char cDkkParam[64] = "";
    char cNeParam[64] = "";
    char cRParam[64] = "";
    char cGpParam[64] = "";
    char cPrParam[64] = "";
    long Ind = 0;
    bool WritePasp = FALSE;
	/*
    SYSTEMTIME lt1, lt2, lt3, lt4;
    ZeroMemory(&lt1, sizeof(lt1));
    ZeroMemory(&lt2, sizeof(lt2));
    ZeroMemory(&lt3, sizeof(lt3));
    ZeroMemory(&lt4, sizeof(lt4));
*/
    char s[64] = "";

    if( m_Combo1.GetCurSel() == 1 && 
        m_EditVag.GetWindowText(s, 64) &&
        iCheckVagValid && 
        m_Combo1.GetCurSel() == 1 && 
        !VanNumberIsValid(s) )
	{
		if( MessageBox("Не сходится контрольная сумма номера вагона. Исправить?" ,"Внимание", MB_YESNO | MB_ICONINFORMATION) == IDYES )
		{
			m_EditVag.SetFocus();
            return;
		}
	}
    
    // Контроль занесения обязательных параметров
    // Определение даты прихода

//    m_DatPost.GetTime(&lt1);
	if( SysDateCmp( g_CurrentDate, m_DatPost.GetAsSystemTime() ) < 0 )
    {
        AfxMessageBox("Указанная дата еще не наступила!");
		m_DatPost.SetFocus();
        return;
    }

	/*
    m_DatIzg.GetTime(&lt2);
    m_DatFor.GetTime(&lt3);
    m_DatOsv.GetTime(&lt4);
	*/

	if( !m_DatIzg.isNull() && !m_DatFor.isNull() && SysDateCmp(m_DatIzg.GetAsSystemTime(), m_DatFor.GetAsSystemTime()) > 0 )
    {
        MessageBox("Дата последнего формирования должна быть позже изготовления оси.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
	if( !m_DatFor.isNull() && !m_DatOsv.isNull() &&SysDateCmp(m_DatFor.GetAsSystemTime(), m_DatOsv.GetAsSystemTime()) > 0 )
    {
        MessageBox("Дата последнего освидетельствования должна быть не раньше даты последнего формирования.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
	if( !m_DatIzg.isNull() && !m_DatOsv.isNull() && SysDateCmp(m_DatIzg.GetAsSystemTime(), m_DatOsv.GetAsSystemTime()) > 0 )
    {
        MessageBox("Дата последнего освидетельствования должна быть не раньше даты изготовления оси.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
/*
    PrihKp.stDatPost = lt1;
	if( PrihKp.dwPriznRas > 10 && SysDateCmp(PrihKp.dt5, m_DatPost.GetAsSystemTime()) < 0)
    {
        AfxMessageBox("Дата поступления не может быть позже даты ремонта.");
        return;
    }
    if( PrihKp.dwPriznRas == 12 && SysDateCmp(PrihKp.dt6, PrihKp.stDatPost) < 0)
    {
        AfxMessageBox("Дата поступления не может быть позже даты монтажа букс.");
        return;
    }

    // Some exceptions here in pascal source ### 
    m_DatIzg.GetTime(&PrihKp.stDatIzg);
    if( iZp == 2 && SysDateCmp(PrihKp.stDatIzg, PrihKp.stDatPost) > 0)
    {
        AfxMessageBox("Дата поступления должна быть позже изготовления оси.");
        return;
    }
	*/
    // Откуда поступила
    if( m_Check1.GetCheck() )
    {
        // из-под вагона

        m_EditVag.GetWindowText(cText, 64);

        if( atoi( cText ) == 0 )
        {
            MessageBox("Номер вагона введен не верно", "Внимание", MB_OK | MB_ICONINFORMATION);
            return;
        }
		if( m_Combo4.GetCurSel() == -1 )
		{
			MessageBox("Не указан вид ремонта вагона!", "Внимание", MB_OK | MB_ICONINFORMATION );
			m_Combo4.EnableWindow(1);
			m_Combo4.ModifyStyle(WS_DISABLED, 0);
			return;
		}
/*
		char cf[12] = "";
		itoa(m_Combo4.GetItemData(m_Combo4.GetCurSel()), cf, 10); //VREM
	
        cText[12] = 0;
        sprintf(cParams, "'%s', %s, NULL, NULL, NULL ", cText, cf); //NVAG
        strcpy(PrihKp.cPrihNVag, cText);
*/
    } else
    if( m_Check2.GetCheck() )
    {        
        // с пересылки
        m_Edit14.GetWindowText(cText, 64);
        if( dwPrPeres == 0 )
        {
            AfxMessageBox("Не указано предприятие, откуда прибыла КП.");
			m_Edit14.SetFocus();
            return;
        }
		
		if( m_Date5.isNull() )
		{
			AfxMessageBox("Не указана дата пересылки КП!");
			m_Date5.SetFocus();
			return;
		}

		if( m_Edit15.isNull() )
		{
			AfxMessageBox("Необходимо указать номер пересылочной ведомости!");
			m_Edit15.SetFocus();
			return;
		}
		/*
        sprintf(cParams, "NULL, NULL, %u, ", dwPrPeres); //NVAG=NULL, dwPrPeres
        PrihKp.dwPeresIPR = dwPrPeres;
        // Проверка даты

        char cT[12]="";
        SYSTEMTIME stL;
        if( m_Date5.GetAsDate(&stL) ) strcat(cParams, " NULL");
        else
        {
            sprintf(cParams, "%s '%.4d%.2d%.2d'", 
                    cParams, 
                    stL.wYear, 
                    stL.wMonth,
                    stL.wDay);
        }
        // Проверка номера ведомости
        m_Edit15.GetWindowText(cText, 64);
        if( cText[0] == 0 )
        {
             strcat(cParams, ", NULL"); //PERES_NVED
            PrihKp.dwNVedPeres = 0;
        } else
        if( atoi(cText) == 0 )
        {
            AfxMessageBox("Некорректный номер пересылочной ведомости.");
            return;
        } else
        {
            PrihKp.dwNVedPeres = atol(cText);
            sprintf(cParams, "%s, %s ", cParams, cText); //PERES_NVED
        }
		*/
    } else
    {
        AfxMessageBox("Не указано, откуда прибыла КП.");
        return;
    }
	/*
    // Фамилия принявшего
    m_EdFIOPrih.GetWindowText(cText, 64);
    if( cText[0] == 0 )
    {
        AfxMessageBox("Не указана фамилия принявшего.");
        return;
    }
    strncpy(PrihKp.cFam, cText, 64);
    
    // Контроль занесения сведений о последнем формировании
    // if (Trim(inp_posfor_dat.Text)<>'.') or (Trim(inp_posfor_ipr.Text)<>'')
    if( m_EdKlPrFor.GetWindowTextLength() )
    {
        if( !m_DatFor.isValid() )
        {
            AfxMessageBox("Некорректно указана дата последнего формирования");
            return;
        }
        m_DatFor.GetTime(&PrihKp.stDatFor);        

        if(iZp == 2 && SysDateCmp(PrihKp.stDatIzg, PrihKp.stDatFor) > 0 ) 
        {
            AfxMessageBox("Дата последнего формирования должна быть позже изготовления оси.");
            return;
        }
        if( SysDateCmp(PrihKp.stDatFor, PrihKp.stDatPost ) > 0 )
        {
            AfxMessageBox("Дата последнего формирования должна быть раньше даты поступления.");
            return;
        }
		PrihKp.dwPosForPr_ID = dwPrPosFor;

        sprintf (cPosForParam , "%u, '%.4d%.2d%.2d',",
                PrihKp.dwPosForPr_ID,
                PrihKp.stDatFor.wYear,
                PrihKp.stDatFor.wMonth,
                PrihKp.stDatFor.wDay);

    }
    else // нет последнего формирования        
    {

        strncpy(cPosForParam, "NULL, NULL, ", 14);
    }
// Контроль занесения сведений о последнем освидетельствовании
    if( m_EdKlPrOsv.GetWindowTextLength() )
    {
        m_DatOsv.GetTime(&PrihKp.stDatOsv);
        if( iZp == 2 && SysDateCmp(PrihKp.stDatIzg, PrihKp.stDatOsv) > 0 ) 
        {
            AfxMessageBox("Дата последнего освидетельствованииz должна быть позже изготовления оси.");
            return;
        }
        if( SysDateCmp(PrihKp.stDatOsv, PrihKp.stDatPost ) > 0 )
        {
            AfxMessageBox("Дата последнего освидетельствованиия должна быть раньше даты поступления.");
            return;
        }
        if( m_EdKlPrIzg.GetWindowTextLength() && SysDateCmp(PrihKp.stDatFor, PrihKp.stDatOsv ) > 0 )
        {
            AfxMessageBox("Дата последнего освидетельствования должна быть не раньше даты последнего формирования.");
            return;
        }
        // проверка правильности клейма (похерили)
		PrihKp.dwPosOsvPr_ID = dwPrPosOsv;
       
        sprintf( cPosOsvParam, "%d, '%.4d%.2d%.2d', ",
                 dwPrPosOsv,
                 PrihKp.stDatOsv.wYear,
                 PrihKp.stDatOsv.wMonth,
                 PrihKp.stDatOsv.wDay);
    } else
    {
        dwPrPosOsv = 0;
        strncpy(cPosOsvParam, "NULL, NULL, ", 14);
    }
    // Контроль типа редуктора
    if( PrihKp.wGruz == 0 && m_Combo2.GetCurSel() >= 0 )
    {
        sprintf(cTrParam, "%d, ", dwItr[m_Combo2.GetCurSel()] ); 
        PaspKp.dwRedTypeID = dwItr[m_Combo2.GetCurSel()];
        PrihKp.wITR = (unsigned short)dwItr[m_Combo2.GetCurSel()];
    }
    else
    {
        PaspKp.dwRedTypeID = 0;
        strncpy(cTrParam, "NULL, ", 7);
        PrihKp.wITR = 0;
    }
    // Контроль толщины дисков
    if( m_Edit4.GetWindowTextLength() != 0 || m_Edit5.GetWindowTextLength() )
    {
        m_Edit5.GetWindowText(cText, 32);
        PrihKp.wTd_l = atoi(cText);
        if( !m_Edit5.isNull() && PrihKp.wTd_l == 0 )
        {
            AfxMessageBox("Некорректно указана толщина левого диска.");
            return;
        }
        m_Edit4.GetWindowText(cText, 32);
        PrihKp.wTd_r = atoi(cText);
        if( !m_Edit4.isNull() && PrihKp.wTd_r == 0 )
        {
            AfxMessageBox("Некорректно указана толщина правого диска.");
            return;            
        }
        m_Edit4.GetWindowText(cTdParam, 64);
        m_Edit5.GetWindowText(cText, 64);
        sprintf(cTdParam, "%s, %s, ", cTdParam, cText);
    }
    else
    {
        strcpy(cTdParam, "NULL, NULL, ");
    }
    // Контроль диаметров по кругу катания
    if( m_Edit6.GetWindowTextLength() || m_Edit7.GetWindowTextLength() )
    {
        m_Edit7.GetWindowText(cText, 64);
        PrihKp.dDkk_l = atof(cText);
        if( PrihKp.dDkk_l == 0.0 )
        {
            AfxMessageBox("Некорректно указан диаметр левого диска.");
            return;
        }
        m_Edit6.GetWindowText(cText, 64);
        PrihKp.dDkk_r = atof(cText);
        if( PrihKp.dDkk_r == 0.0 )
        {
            AfxMessageBox("Некорректно указан диаметр правого диска.");
            return;
        }
        m_Edit6.GetWindowText(cDkkParam, 64);
        m_Edit7.GetWindowText(cText, 64);
        sprintf(cDkkParam, "%s, %s, ", cDkkParam, cText);
    }
    else
    {
        strcpy(cDkkParam, "NULL, NULL, ");
    }
    // Контроль кода неисправности
    if( m_EdNeispCode.GetWindowTextLength() && m_EdNeispName.GetWindowTextLength() )
    {
        PrihKp.dwNeisp_ID = dwNeispId;
        sprintf(cNeParam, "%u", PrihKp.dwNeisp_ID);
    }
    else
    {
        strcpy(cNeParam, "NULL");
        PrihKp.cNeisp_KL[0] = 0;//"NULL");;
        PrihKp.cNeisp_NAME[0] = 0;
		PrihKp.dwNeisp_ID = 0;
    }
    //Контроль требуемого ремонта
    if( m_Combo3.GetCurSel() > -1 )
    {
        PrihKp.dwTREB_REM = dwTypeRem[m_Combo3.GetCurSel()];
        _itoa(dwTypeRem[m_Combo3.GetCurSel()], cRParam, 10);
    }
    else
    {
        strcpy(cRParam, "NULL");
        PrihKp.dwTREB_REM = 0;
    }
    // Грузовая пассажирская
    if( m_Combo1.GetCurSel() != -1)
    {
        {
            switch( m_Combo1.GetCurSel() )
            {
            case 0: strcpy(cGpParam, "0"); PrihKp.wGruz = 0; // Пас
            break;
            case 1: strcpy(cGpParam, "1"); PrihKp.wGruz = 1; // Груз
				if( m_CheckBox1.GetCheck() ) // "Г" на ободе
				{
		            strcpy(cGpParam, "2");
				    PrihKp.wGruz = 2;
				}
            break;
            case 2: strcpy(cGpParam, "4"); PrihKp.wGruz = 4; // Разутая
            }
        }
    } else
    {
        strcpy(cGpParam, "NULL");
        PrihKp.wGruz = 0;
    }

	PaspKp.dwIzOsPr_ID = dwPrIzgot;
	m_EdKlPrIzg.GetWindowText(PaspKp.cIzOsPr_KL, 32);
	m_EdKlPrFor.GetWindowText(PaspKp.cPosForPr_KL, 32);
	strcpy(PrihKp.cPosForPr_KL, PaspKp.cPosForPr_KL);
	m_EdKlPrOsv.GetWindowText(PaspKp.cPosOsvPr_KL, 32);
	strcpy(PrihKp.cPosOsvPr_KL, PaspKp.cPosOsvPr_KL);

	PaspKp.dwPosForPr_ID = PrihKp.dwPosForPr_ID = dwPrPosFor;
	PaspKp.dwPosOsvPr_ID = PrihKp.dwPosOsvPr_ID = dwPrPosOsv;
	char cIzOsPr_ID[16] = "", cPosForPr_ID[16] = "", cPosOsvPr_ID[16] = "";
	if( dwPrIzgot ) itoa(dwPrIzgot, cIzOsPr_ID, 10);
	else strcpy(cIzOsPr_ID, "NULL");
	if( dwPrPosFor ) itoa(dwPrPosFor, cPosForPr_ID, 10);
	else strcpy(cPosForPr_ID, "NULL");
	if( dwPrPosOsv ) itoa(dwPrPosOsv, cPosOsvPr_ID, 10);
	else strcpy(cPosOsvPr_ID, "NULL");

    m_DatIzg.GetTime(&PaspKp.stIZOS_DAT);


	PrihKp.dwFam = m_EdFIOPrih.GetData();
    if( iMode == 2 ) 
    {
        CDlgWithAccelerators::OnOK();
        return;
    } else
	if( iMode == 3 )
	{
		PrihKp.dwNeisp_ID = dwNeispId;
		m_EdNeispCode.GetWindowText(PrihKp.cNeisp_KL, 32);
		m_EdNeispName.GetWindowText(PrihKp.cNeisp_NAME, 32);
        PrihKp.dwFam = m_EdFIOPrih.GetData();
        CDlgWithAccelerators::OnOK();
        return;
	}
    // Запись в базу

	char cIZAP[16] = "", cIKP[16] = "";

	if( PaspKp.qwIKP == 0 ) strcpy(cIKP, "NULL");
	else _i64toa(PaspKp.qwIKP, cIKP, 10);

	if( PrihKp.qwIZAP == 0 ) strcpy(cIZAP, "NULL");
	else _i64toa(PrihKp.qwIZAP, cIZAP, 10);

	char cRemVanNum[32] = "";
	char cRemID[8] = "";
	char cNeispID[16] = "";
	char cTrebRemID[16] = "";
	char cTypeRedID[16] = "";

	if( PrihKp.cPrihNVag[0] == 0 ) 
	{
		strcpy(cRemVanNum, "NULL");
		strcpy(cRemID, "NULL");
	}
	else 
	{
		strcpy(cRemVanNum, PrihKp.cPrihNVag);
		itoa(m_Combo4.GetItemData(m_Combo4.GetCurSel()), cRemID, 10);
	}
	
	if( dwNeispId ) itoa(dwNeispId, cNeispID, 10);
	else strcpy(cNeispID, "NULL");
	
	if( m_Combo3.GetCurSel() != -1 ) itoa(m_Combo3.GetItemData(m_Combo3.GetCurSel()), cTrebRemID, 10);
	else strcpy( cTrebRemID, "NULL" );

	if( m_Combo2.GetCurSel() != -1 ) itoa(m_Combo2.GetItemData(m_Combo2.GetCurSel()), cTypeRedID, 10);
	else strcpy( cTypeRedID, "NULL" );
	
	char cDate[16] = "";
    SYSTEMTIME stTime4;
    memset(&stTime4, 0, sizeof(stTime4));
    m_DatPost.GetTime(&stTime4);
    sprintf(cDate, "'%.4d%.2d%.2d'",
                stTime4.wYear,
                stTime4.wMonth,
                stTime4.wDay);
 // нормальный приход - напрямую в базу
	sprintf(cQ, "pTov_PrihodKP %s, %s, %u, '%s', %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, NULL, %d, %s, %s",		//  ^cIzOsPr
			cIKP,
			cIZAP,
			g_iDep,
			PaspKp.cNKP,
			PaspKp.dwTKP,
			cDate,
			cGpParam,
			cParams,
			cIzOsPr_ID,
			m_DatIzg.GetSQLDate(),
			cPosForPr_ID,
			m_DatFor.GetSQLDate(),
			cPosOsvPr_ID,
			m_DatOsv.GetSQLDate(),
			cTypeRedID,
			m_Edit4.GetString(),
			m_Edit5.GetString(),
			m_Edit6.GetString(),
			m_Edit7.GetString(),
			cNeispID,
			cTrebRemID,
			isNull(PrihKp.dwFam),
			PrihKp.dwPriznRas,
//			m_CheckSteel.GetCheck(),
			m_CbSteel.GetCurSel() == -1 ? 0 : m_CbSteel.GetItemData(m_CbSteel.GetCurSel()),
			
			m_EdParkNum.GetString(1),
			isNull(m_EdSobst.GetData())
			);
	char cQRzv[255] = "";

	sprintf(cQRzv, "pTov_PrihodKP_Rez %u, '%s', %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, NULL, %d, %s, %s",		//  ^cIzOsPr
			g_iDep,
			PaspKp.cNKP,
			PaspKp.dwTKP,
			isNull(dwOld_IzgIPr),
			DateToSQL(stOld_IzgDat),
			cDate,
			cGpParam,
			cParams,
			cIzOsPr_ID,
			m_DatIzg.GetSQLDate(),
			cPosForPr_ID,
			m_DatFor.GetSQLDate(),
			cPosOsvPr_ID,
			m_DatOsv.GetSQLDate(),
			cTypeRedID,
			m_Edit4.GetString(),
			m_Edit5.GetString(),
			m_Edit6.GetString(),
			m_Edit7.GetString(),
			cNeispID,
			cTrebRemID,
			isNull(PrihKp.dwFam),
			PrihKp.dwPriznRas,
//			m_CheckSteel.GetCheck(),
			m_CbSteel.GetCurSel() == -1 ? 0 : m_CbSteel.GetItemData(m_CbSteel.GetCurSel()),
			m_EdParkNum.GetString(1),
			isNull(m_EdSobst.GetData())
			);
	char cMess[512] = "";
	DBW.ExecSQL(cQ);
//	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cMess, 512, &Ind);
    theApp.WriteLog(cMess);
    if( cMess[0] == 0 )
    {
        strcpy(cMess, "0");
    }
	if( !_atoi64(cMess) )
	{
		MessageBox( cMess ,"Внимание", MB_OK | MB_ICONINFORMATION);	
        DBW.WriteLog( cMess );
        DBW.CloseCursor();
        return;
	} else
	{
        DBW.WriteLog("Есть IKP и IZAP");
        cMess[21] = 0;
		PaspKp.qwIKP = _atoi64(cMess);
		DBW.GetData(2, SQL_C_UBIGINT, &PrihKp.qwIZAP, 8, &Ind );
		DBW.GetData(3, SQL_C_ULONG, &PrihKp.dwPriznRas, 4, &Ind );

        sprintf(cMess, "IKP = %I64u, IZAP = %I64u, PriznRas = %u",
            PaspKp.qwIKP, PrihKp.qwIZAP, PrihKp.dwPriznRas);
        DBW.WriteLog(cMess);
//		AfxMessageBox("Данные занесены в базу!");
	}
	DBW.CloseCursor();
    m_Edit14.GetWindowText(PrihKp.cPeresPr_KL, 31);
    m_Edit17.GetWindowText(PrihKp.cPeresPr_NAME, 31);
	// обычная запись прошла нормально, отправим сообщение на резервный
	DBW.ExecSQLRzv(cQRzv);

	// а теперь поменям тип (если надо)
	if( PaspKp.dwTKP == 100 && m_ComboTKP.GetItemData( m_ComboTKP.GetCurSel() ) != 100 )
	{
		sprintf(cQ, "pTov_SetTypeKP %s, %s", 
			isNull(PaspKp.qwIKP),
			isNull(m_ComboTKP.GetItemData(m_ComboTKP.GetCurSel())));
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();

		sprintf(cQRzv, "pTov_SetTypeKP_Rez '%s', %s, %s, %s, %s",
			PaspKp.cNKP,
			isNull(PaspKp.dwTKP),
			isNull(PaspKp.dwIzOsPr_ID),
			DateToSQL(PaspKp.stIZOS_DAT),

			isNull(m_ComboTKP.GetItemData(m_ComboTKP.GetCurSel())));

		DBW.ExecSQLRzv(cQRzv);
		PaspKp.dwTKP = m_ComboTKP.GetItemData(m_ComboTKP.GetCurSel());
	}
*/

// Новая запись

	m_EdKlPrFor.GetWindowText(cText, 64); dwKlPrPosFor = atoi(cText);
	m_EdKlPrOsv.GetWindowText(cText, 64); dwKlPrPosOsv = atoi(cText);
	m_EdKlPrIzg.GetWindowText(cText, 64); dwKlPrIzgot = atoi(cText);
/*
		char cGruzPas[12] = "";
	int idx = m_Combo1.GetCurSel();
	if( idx < 0 ) strcpy(cGruzPas, "NULL");
	else if( idx == 1 && m_CheckBox1.GetCheck() ) strcpy(cGruzPas, "2");
	else itoa(m_Combo1.GetItemData(idx), cGruzPas, 10);
*/
	// просто заполним структуру PrihKP
		strncpy( PrihKp.cNKP, cNKP, 20 );
		PrihKp.dwTKP = iTKP;

		m_DatPost.GetTime( &PrihKp.stDatPost );

		m_EditVag.GetWindowText( PrihKp.cPrihNVag, 10 );
		PrihKp.dwRemVagID = m_Combo4.GetCurSel() == -1 ? 0 : m_Combo4.GetItemData( m_Combo4.GetCurSel() );
		
		if( PrihKp.dwTKP == 100 ) PrihKp.dwTKP = m_ComboTKP.GetItemData( m_ComboTKP.GetCurSel() );
		
		m_Edit14.GetWindowText(PrihKp.cPeresPr_KL, 24);
		m_Edit17.GetWindowText(PrihKp.cPeresPr_NAME, 32);
		PrihKp.dwPeresIPR = m_Edit14.GetData();
		//PrihKp.dwPeresIPR = dwPrPeres;

		m_Date5.GetTime( &PrihKp.stPeresDat );
		PrihKp.dwNVedPeres = m_Edit15.GetAsDWord();

		m_DatIzg.GetTime( &PrihKp.stDatIzg );
		m_DatFor.GetTime( &PrihKp.stDatFor );
		m_DatOsv.GetTime( &PrihKp.stDatOsv );

		PrihKp.dwIzgPr_ID = dwPrIzgot;
		PrihKp.dwPosForPr_ID = dwPrPosFor;
		PrihKp.dwPosOsvPr_ID = dwPrPosOsv;

		m_EdKlPrIzg.GetWindowText( PrihKp.cIzgPr_KL, 32 );
		m_EdKlPrFor.GetWindowText( PrihKp.cPosForPr_KL, 32 );
		m_EdKlPrOsv.GetWindowText( PrihKp.cPosOsvPr_KL, 32 );
		
		PrihKp.iSteelType = m_CbSteel.GetCurSel() == -1 ? 0 : m_CbSteel.GetItemData(m_CbSteel.GetCurSel()); 

		PrihKp.wITR = m_Combo2.GetCurSel() == -1 ? 0 : m_Combo2.GetItemData(m_Combo2.GetCurSel());

		PrihKp.wTd_r = m_Edit4.GetAsDWord();
		PrihKp.wTd_l = m_Edit5.GetAsDWord();

		PrihKp.dPrihDkk_r = m_Edit6.GetAsDouble();
		PrihKp.dPrihDkk_l = m_Edit7.GetAsDouble();

		m_EdNeispCode.GetWindowText(PrihKp.cNeisp_KL, 10);
		m_EdNeispName.GetWindowText(PrihKp.cNeisp_NAME, 20);
		PrihKp.dwNeisp_ID = m_EdNeispCode.GetData();

		PrihKp.dwTREB_REM = m_Combo3.GetCurSel() == -1 ? 0 : m_Combo3.GetItemData(m_Combo3.GetCurSel());

		m_EdFIOPrih.GetWindowText( PrihKp.cFam, 30);
		PrihKp.dwFam = m_EdFIOPrih.GetData();

		PrihKp.iParkNum = m_EdParkNum.GetAsDWord();

		PrihKp.dwSobstIPRPrih = m_EdSobst.GetData();
		
		PrihKp.wOb_l = m_EdObod_l.GetAsDWord();
		PrihKp.wOb_r = m_EdObod_r.GetAsDWord();
		PrihKp.wGr_l = m_EdGreb_l.GetAsDWord();
		PrihKp.wGr_r = m_EdGreb_r.GetAsDWord();
		PrihKp.dPr_l = m_EdProkat_l.GetAsDouble();
		PrihKp.dPr_r = m_EdProkat_r.GetAsDouble();
		PrihKp.dPrihDkk_l = m_EdD_l.GetAsDouble();
		PrihKp.dPrihDkk_r = m_EdD_r.GetAsDouble();
		

		switch ( m_Combo1.GetCurSel()  )
		{
			case 0: PrihKp.wGruz = 0; break;
			case 1: if( !m_CheckBox1.GetCheck() ) PrihKp.wGruz = 1;
					else if( m_CheckBox1.GetCheck() ) PrihKp.wGruz = 2; break;
			case 2: PrihKp.wGruz = 4; break;
		}
	
	if( iMode != PRIHOD_KP_FROM_VAG )
	{
		DBW.WritePrihodKP( &PrihKp, 1 );
		qwIZap = PrihKp.qwIZAP;
		if( g_iGotRezervDBW ) DBWrez.WritePrihodKP( &PrihKp, 1 );

	}
	iAddToBaseOK = 1;
	if( iNeedClosePrih == 1 )
		CDlgWithAccelerators::OnOK();
	else
		iNeedClosePrih = 1;
}

bool CDlgPrihodKP::ZapIzOs()
{
//    PaspIzOs:=true;
    char cQ[512] = "";
    long    Ind = 0;
    if( !m_EdKlPrIzg.GetWindowTextLength() )
    {
        return true;
    }
    SYSTEMTIME stD;
    ZeroMemory(&stD, sizeof(stD));
    m_DatIzg.GetTime(&stD);
    if( iZp == 2 && 
        iFo > 0 && 
        (dwPrIzgot != PaspKp.dwIzOsPr_ID ||
         SysDateCmp(stD, PaspKp.stIZOS_DAT))
       )
    {
        AfxMessageBox("Данные изготовления оси не могут быть изменены, т.к.\n\
                       КП с таким номером уже была израсходована.\n\
                       Повторите ввод или заведите двойника!");                       
        return false;
    }
    if( iZp == 1 || 
        ( iZp == 2 && iFo == 0 /*&& 
/*         (dwPrIzgot != (unsigned)atol(PaspKp.cIZOS_PR) ||
          SysDateCmp(stD, PaspKp.stIZOS_DAT))*/
        )
      )
    {
        if( SysDateCmp(PrihKp.stDatIzg, PrihKp.stDatPost) > 0 )
        {
            AfxMessageBox("Дата поступления должна быть позже изготовления оси.");
            return false;
        }
        PaspKp.stIZOS_DAT = PrihKp.stDatIzg;
        // Проверка правильности клейма предприятия изготовления оси
        CString str;
        m_EdKlPrIzg.GetWindowText(str);
        sprintf(cQ, "pTov_GetPrByKl '%.16s'", str);
        DBW.ExecSQL(cQ);
        if( DBW.Fetch() == SQL_NO_DATA )
        {
            AfxMessageBox("Недопустимое клеймо предприятия изготовления оси.");
            DBW.CloseCursor();
            return false;
        }
        bool    bCanOs = false;
        DBW.GetData( 3, SQL_C_BIT, &bCanOs, 32, &Ind);        
        DBW.CloseCursor();
        if( bCanOs )
        {
            PaspKp.dwIzOsPr_ID = dwPrIzgot; 
                sprintf(cQ, "pTov_UpdatePaspIZOS %d, '%.4d%.2d%.2d', %I64u",
                        dwPrIzgot,
                        PaspKp.stIZOS_DAT.wYear,
                        PaspKp.stIZOS_DAT.wMonth,
                        PaspKp.stIZOS_DAT.wDay,
                        PaspKp.qwIKP);
            DBW.ExecSQL(cQ);
            DBW.CloseCursor();
            DBW.ReallocHandle();
        } else
        {
            AfxMessageBox("Указанное предприятия не изготовливает оси.");
            return false;
        }
    }
    return true;
}

void CDlgPrihodKP::OnChangeEdit14() 
{
if( !bStarted ) return;
    char cText[64] = "";
    char cQ[64] = "";
    long Ind = 0;
    m_Edit14.GetWindowText(cText, 64);
	m_Edit17.SetWindowText("");
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
    DBW.GetData( 2, SQL_C_SLONG, &dwPrPeres, 4, &Ind);
    DBW.CloseCursor();
	m_Edit14.SetData( dwPrPeres );
    m_Edit17.SetWindowText(cText);
}
extern CString g_strAsldTeleName;
extern int g_iEnableTelecom;

void CDlgPrihodKP::OnSendToASUV() 
{
	if( g_iEnableTelecom && g_strAsldTeleName )
	{
		iNeedClosePrih = 0;
		CString str = "";
		m_EdKlPrIzg.GetWindowText(str);
		if( str == "" )
		{
			AfxMessageBox("Для отправки данных в АСЛД необходимо указать предприятие изготовитель!");
			m_EdKlPrIzg.SetFocus();
			return;
		}
		str = "";
		m_DatIzg.GetWindowText(str);
		if( str == "" )
		{
			AfxMessageBox("Для отправки данных в АСЛД необходимо указать дату изготовления КП!");
			m_DatIzg.SetFocus();
			return;
		}		

		if( m_CbSteel.GetCurSel() == -1 )
		{
			AfxMessageBox("Для отправки данных в АСЛД необходимо указать марку стали КП!");
			m_CbSteel.SetFocus();
			return;
		}

		str = "";
		m_Edit6.GetWindowText( str );

		if( str == "" )
		{
			AfxMessageBox("Для отправки данных в АСЛД необходимо указать диаметры КП!");
			m_Edit6.SetFocus();
			return;
		}
		str = "";
		m_Edit7.GetWindowText( str );

		if( str == "" )
		{
			AfxMessageBox("Для отправки данных в АСЛД необходимо указать диаметры КП!");
			m_Edit7.SetFocus();
			return;
		}
		str = "";
		OnAddToBase();
		if( iAddToBaseOK == 0 ) return;
		DWORD dwRet = 0;
		char cText[2255] = "";
		char cQ[128] = "";

				sprintf( cQ, "pTov_KP_SendToAsuV %s", isNull(qwIZap) );		
				DBW.ExecSQL( cQ );
				DBW.Fetch();
				DBW.GetData(1, SQL_C_CHAR, cText, 2255, &Ind);
				if( strcmp( cText, "-1" ) == 0 )
				{
					DBW.GetData(2, SQL_C_CHAR, cText, 2255, &Ind);
					DBW.CloseCursor();
					AfxMessageBox( cText );
					return;
				}			
				DBW.CloseCursor();
	
					char msg[200] = "";
					sprintf(msg, "Отправка данных в АС ЛД (%s)", g_strAsldTeleName ) ;
					DBW.WriteLog((char *)msg);
					CString snd = (CString)"<tov><asld docid=\"1\">\n" + cText + (CString) "\n</asld></tov>";
					//DBW.SendMessageToDst( snd, "mkc", g_strAisldTeleName );
					if( tele ) 
					{
							tele->SendMessageDst(snd, &g_strAsldTeleName);	
							AfxMessageBox("Данные отправлены в АСЛД!");
							m_SendToAsuv.EnableWindow(0);
					}
	} else
	{
		AfxMessageBox("Невозможно отправить в АСЛД из-за некорректных настроек телеобработки!");
	}
}

void CDlgPrihodKP::OnKillfocusPrIzg() 
{
    CString str;
    m_EdKlPrIzg.GetWindowText(str);
    if( str == "" )
    {
        dwPrIzgot = 0;
        return;
    }
    char cText[32] = "";
    char cQ[128] = "";
    long Ind = 0;

    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();

    bool lbCanIzgOs = false;

    DBW.GetData( 1, SQL_C_ULONG, &dwPrIzgot, 4, &Ind);
    DBW.GetData( 2, SQL_C_CHAR, cText, 32, &Ind);
    DBW.GetData( 3, SQL_C_BIT, &lbCanIzgOs, 1, &Ind);
    DBW.CloseCursor();	
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR /*|| !lbCanIzgOs*/ )
    {
        MessageBox("Введено некорректное клеймо предприятия изготовления оси!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdKlPrIzg.SetWindowText("");
		m_EdKlPrIzg.SetFocus();
        return;
    }
    m_DatFor.SetFocus();
	dwKlPrIzgot = atoi(str);
}

void CDlgPrihodKP::OnKillfocusPrForOsv() 
{
    CString str;
    m_EdKlPrFor.GetWindowText(str);
    if( str == "" )
    {
        dwPrPosFor = 0;
        return;
    }
    char cText[32] = "";
    char cQ[128] = "";
    long Ind = 0;
    bool lbCanForm = false;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwPrPosFor, 4, &Ind);
    DBW.GetData( 2, SQL_C_CHAR, cText, 32, &Ind);
	lbCanForm = 1;
//    DBW.GetData( 4, SQL_C_BIT, &lbCanForm, 1, &Ind);
    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR /*|| !lbCanForm*/)
    {
        MessageBox("Введено некорректное клеймо предприятия последнего формирования!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdKlPrFor.SetWindowText("");
		m_EdKlPrFor.SetFocus();
        return;        
    }
	dwKlPrPosFor = atoi(str);
    m_DatOsv.SetFocus();
}

void CDlgPrihodKP::OnKillfocusPrPosOsv() 
{
    CString str;
    m_EdKlPrOsv.GetWindowText(str);
    if( str == "" )
    {
        dwPrPosOsv = 0;
        return;
    }
    char cText[32] = "";
    char cQ[128] = "";
    long Ind = 0;
    bool lbCanOsv = false;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwPrPosOsv, 4, &Ind);
    DBW.GetData( 2, SQL_C_CHAR, cText, 32, &Ind);
	lbCanOsv = 1;
//    DBW.GetData( 5, SQL_C_BIT, &lbCanOsv, 1, &Ind);

    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR || cText[0] == 0 || !lbCanOsv)
    {
        MessageBox("Введено некорректное клеймо предприятия последнего освидетельствования!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
		m_EdKlPrOsv.SetWindowText("");
        m_EdKlPrOsv.SetFocus();
        return;
    }
	dwKlPrPosOsv = atoi(str);
    m_EdNeispCode.SetFocus();
}

void CDlgPrihodKP::IniFromGiven()
{
    m_EdNKP.SetWindowText( PrihKp.cNKP );
	m_EdTKP.SetWindowText( DBW.GetTKPNameByID(PrihKp.dwTKP));

	int i = 0;
    switch (PrihKp.wGruz)
    {
	case 0: // Пассажирская
                m_Combo1.SetCurSel(0);
				m_Combo2.EnableWindow();
				m_CheckBox1.EnableWindow(FALSE);
//                m_Combo2.SetCurSel(PaspKp.cRED); //finish it later ###
				for( i=0; i < m_Combo2.GetCount(); i++ )
					if( m_Combo2.GetItemData(i) == PrihKp.wITR ) 
					{
						m_Combo2.SetCurSel(i);
						break;
					}

                //Тип редуктора
    break;
	case 1: // Грузовая
				m_Combo1.SetCurSel(1);
				m_Combo2.EnableWindow(FALSE);
				m_CheckBox1.EnableWindow(); 
	break;
	case 2: // "Г" На ободе :- )
				m_Combo1.SetCurSel(1);
                m_CheckBox1.SetCheck(1);
				m_Combo2.EnableWindow(FALSE);
//				m_Combo1.EnableWindow(FALSE);
	break;
	case 4: // Разутая
				m_Combo1.SetCurSel(2);
				m_CheckBox1.EnableWindow(FALSE);
				m_Combo2.EnableWindow();
				for( i=0; i < m_Combo2.GetCount(); i++ )
					if( m_Combo2.GetItemData(i) == PrihKp.wITR ) 
					{
						m_Combo2.SetCurSel(i);
						break;
					}

	break;
	}


	if( PrihKp.wTd_r ) m_Edit4.SetValue((DWORD)PrihKp.wTd_r);
    if( PrihKp.wTd_l ) m_Edit5.SetValue((DWORD)PrihKp.wTd_l);
    if( PrihKp.dPrihDkk_r ) m_Edit6.SetValue(PrihKp.dPrihDkk_r);
    if( PrihKp.dPrihDkk_l ) m_Edit7.SetValue(PrihKp.dPrihDkk_l);

	if( PrihKp.wOb_l ) m_EdObod_l.SetValue( (DWORD)PrihKp.wOb_l );
	if( PrihKp.wOb_r ) m_EdObod_r.SetValue( (DWORD)PrihKp.wOb_r );

	if( PrihKp.wGr_l ) m_EdGreb_l.SetValue( (DWORD)PrihKp.wGr_l );
	if( PrihKp.wGr_r ) m_EdGreb_r.SetValue( (DWORD)PrihKp.wGr_r );

	if( PrihKp.dPr_l ) m_EdProkat_l.SetValue( PrihKp.dPr_l );
	if( PrihKp.dPr_r ) m_EdProkat_r.SetValue( PrihKp.dPr_r );

    m_DatIzg.SetTime(&PrihKp.stDatIzg);
    m_DatFor.SetTime(&PrihKp.stDatFor);
    m_DatOsv.SetTime(&PrihKp.stDatOsv);
	m_DatPost.SetTime(&PrihKp.stDatPost);
	m_EdKlPrIzg.SetWindowText(PrihKp.cIzgPr_KL);
	m_EdKlPrFor.SetWindowText(PrihKp.cPosForPr_KL);
	m_EdKlPrOsv.SetWindowText(PrihKp.cPosOsvPr_KL);

	dwPrPosFor = PrihKp.dwPosForPr_ID;
	dwPrPosOsv = PrihKp.dwPosOsvPr_ID;

	m_EdFIOPrih.SetData(PrihKp.dwFam);
	m_EdFIOPrih.SetFamTextByID(PrihKp.dwFam);
    if( !m_EdFIOPrih.GetWindowTextLength() && PrihKp.dwFam ) m_EdFIOPrih.SetWindowText(PrihKp.cFam);

	char cText[32] = "";
	if( PrihKp.cPrihNVag[0] )
	{
		OnRadio1();
		m_EditVag.SetWindowText(PrihKp.cPrihNVag);
		for( int i=0; i < m_Combo4.GetCount(); i++ )
		{
			if( PrihKp.dwRemVagID == m_Combo4.GetItemData(i) )
			{
				m_Combo4.SetCurSel(i);
				break;
			}
		}
	} else
    if( PrihKp.dwPeresIPR )
	{
		m_Edit14.SetWindowText(PrihKp.cPeresPr_KL);
		m_Edit17.SetWindowText(PrihKp.cPeresPr_NAME);
		dwPrPeres = PrihKp.dwPeresIPR;
		m_Date5.SetTime(&PrihKp.stPeresDat);
        OnRadio2();
		if(PrihKp.dwNVedPeres)
		{
			ltoa(PrihKp.dwNVedPeres, cText, 10);
			m_Edit15.SetWindowText(cText);						
		}
    } else
        OnRadio1();

	m_EdNeispCode.SetWindowText(DBW.GetNeispKlByID(PrihKp.dwNeisp_ID));
	m_EdNeispCode.SetData(PrihKp.dwNeisp_ID);
	m_EdNeispName.SetWindowText(PrihKp.cNeisp_NAME);
	
	for( i=0; i < m_Combo3.GetCount(); i++ )
    {
		if( PrihKp.dwTREB_REM == m_Combo3.GetItemData(i) )
        {
            m_Combo3.SetCurSel(i);
            break;
        }
    }
//    m_CheckSteel.SetCheck(PrihKp.iSteelType);
	for( int i=0; i < m_CbSteel.GetCount() && i < 10; i++ )
	{
		if( m_CbSteel.GetItemData(i) == PrihKp.iSteelType )
			m_CbSteel.SetCurSel(i);
	}

	if( PrihKp.iParkNum )
	{
		itoa(PrihKp.iParkNum, cText, 10);
		m_EdParkNum.SetWindowText(cText);
	}
//    m_Edit8.SetWindowText(PrihKp.
	char cQ[128] = "";
	if( PrihKp.dwSobstIPRPrih )
	{
		sprintf(cQ, "pTov_SobstvPrGet %u", PrihKp.dwSobstIPRPrih);
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 )
		{
			m_EdSobst.SetWindowText(cText);
			m_EdSobst.SetData(PrihKp.dwSobstIPRPrih);
		}
	}
}

void CDlgPrihodKP::OnKillfocusVagNum() 
{
    /*
    char s[64] = "";
	if( !bStarted || m_Combo1.GetCurSel() == 2 || !m_EditVag.GetWindowText(s, 64) ) return;	
	if( iCheckVagValid && m_Combo1.GetCurSel() == 1 && !VanNumberIsValid(s) )
	{
		if( MessageBox("Не сходится контрольная сумма номера вагона. Исправить?" ,"Внимание", MB_YESNO | MB_ICONINFORMATION) == IDYES )
		{
			m_EditVag.SetFocus();
		}
	}*/
}

void CDlgPrihodKP::OnSetfocusPrIzg() 
{

}

void CDlgPrihodKP::OnKillfocusEdit_PR1() 
{
    CString str, sss;
    m_Edit14.GetWindowText(str);
	m_Edit17.GetWindowText(sss);
    if( str == "" )
    {
		if( bPrPeresWasEdited ) 
		{
			dwPrPeres = 0;
			m_Edit17.SetWindowText("");
		}
        return;
    }
	bPrPeresWasEdited = 1;
    char cText[255] = "";
    char cQ[128] = "";
    long Ind = 0;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwPrPeres, 4, &Ind);
    DBW.GetData( 7, SQL_C_CHAR, cText, 254, &Ind);
/*    DBW.GetData( 4, SQL_C_BIT, &lbCanForm, 1, &Ind);*/
    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        MessageBox("Введено некорректное клеймо предприятия!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_Edit14.SetWindowText("");
        m_Edit17.SetWindowText("");
		m_Edit14.SetFocus();
        return;
    }
    m_Edit17.SetWindowText(cText);	
}

void CDlgPrihodKP::OnButtonPasport() 
{
    CPrintableDlg Dlg;
    if( !PrihKp.qwIZAP ) return;
	sprintf( Dlg.cQ, "pTov_mkcReportPasp %I64u", PrihKp.qwIZAP);
    Dlg.DoModal();
}


void CDlgPrihodKP::OnCancel() 
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;	
	CDlgWithAccelerators::OnCancel();
}

void CDlgPrihodKP::OnBnClickedButtonSelSobst()
{
	CDlgSprPrSobstv Dlg;
	if( Dlg.DoModal() == IDCANCEL ) 
	{
		m_EdSobst.SetWindowText("");
		m_EdSobst.SetData(0);
		return;
	}
	m_EdSobst.SetWindowText(Dlg.cPrName);
	m_EdSobst.SetData(Dlg.dwSobstID);
}


void CDlgPrihodKP::IniObmer()
{
	char cQ[255] = "";
	sprintf(cQ, "pTov_KP_GetObmerData %I64u, %u", PrihKp.qwIZAP, g_iDep );
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();

	DWORD dwNum = 0;
	double dNum = 0.0;
    // Диаметр по кругу катания
    DBW.GetData( 6, SQL_C_DOUBLE, &dNum, sizeof(double), &Ind);
    if( Ind != -1 ) 
    {
		m_EdD_l.SetValue(dNum);
    }
    DBW.GetData( 7, SQL_C_DOUBLE, &dNum, sizeof(double), &Ind);
    if( Ind != -1 ) 
    {
		m_EdD_r.SetValue(dNum);
    }

	
    // Прокат
    DBW.GetData( 14, SQL_C_DOUBLE, &dNum, sizeof(double), &Ind);
    if( Ind != -1 ) 
    {
        m_EdProkat_l.SetValue(dNum);
    }
    DBW.GetData( 15, SQL_C_DOUBLE, &dNum, sizeof(double), &Ind);
    if( Ind != -1 ) 
    {
        m_EdProkat_r.SetValue(dNum);
    }
    // Обод
    DBW.GetData( 16, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        m_EdObod_l.SetValue(dwNum);
    }
    DBW.GetData( 17, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        m_EdObod_r.SetValue(dwNum);
    }
    // Гребень
    DBW.GetData( 18, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        m_EdGreb_l.SetValue(dwNum);
    }
    DBW.GetData( 19, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        m_EdGreb_r.SetValue(dwNum);
    }
	DBW.CloseCursor();
}