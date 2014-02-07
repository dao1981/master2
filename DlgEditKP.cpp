// DlgEditKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgEditKP.h"
#include "MaskEdit.h"
#include <sqlext.h>
#include ".\dlgeditkp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp   theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgEditKP dialog


CDlgEditKP::CDlgEditKP(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEditKP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgEditKP)
	//}}AFX_DATA_INIT
    iMode = 0;
    dwITKP = 0;
}


void CDlgEditKP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEditKP)
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_EDIT16, m_Edit16);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT30, m_Edit30);
	DDX_Control(pDX, IDC_EDIT3, m_Edit3);
	DDX_Control(pDX, IDC_EDIT29, m_Edit29);
	DDX_Control(pDX, IDC_EDIT7, m_Edit7);
	DDX_Control(pDX, IDC_EDIT63, m_Edit63);
	DDX_Control(pDX, IDC_EDIT61, m_Edit61);
	DDX_Control(pDX, IDC_EDIT60, m_Edit60);
	DDX_Control(pDX, IDC_EDIT59, m_Edit59);
	DDX_Control(pDX, IDC_EDIT5, m_Edit5);
	DDX_Control(pDX, IDC_EDIT68, m_Edit68);
	DDX_Control(pDX, IDC_EDIT67, m_Edit67);
	DDX_Control(pDX, IDC_EDIT66, m_Edit66);
	DDX_Control(pDX, IDC_EDIT65, m_Edit65);
	DDX_Control(pDX, IDC_EDIT64, m_Edit64);
	DDX_Control(pDX, IDC_EDIT62, m_Edit62);
	DDX_Control(pDX, IDC_EDIT57, m_Edit57);
	DDX_Control(pDX, IDC_EDIT58, m_Edit58);
	DDX_Control(pDX, IDC_EDIT56, m_Edit56);
	DDX_Control(pDX, IDC_EDIT55, m_Edit55);
	DDX_Control(pDX, IDC_EDIT53, m_Edit53);
	DDX_Control(pDX, IDC_EDIT54, m_Edit54);
	DDX_Control(pDX, IDC_EDIT52, m_Edit52);
	DDX_Control(pDX, IDC_EDIT51, m_Edit51);
	DDX_Control(pDX, IDC_EDIT49, m_Edit49);
	DDX_Control(pDX, IDC_EDIT50, m_Edit50);
	DDX_Control(pDX, IDC_EDIT48, m_Edit48);
	DDX_Control(pDX, IDC_EDIT47, m_Edit47);
	DDX_Control(pDX, IDC_EDIT45, m_Edit45);
	DDX_Control(pDX, IDC_EDIT44, m_Edit44);
	DDX_Control(pDX, IDC_EDIT41, m_Edit41);
	DDX_Control(pDX, IDC_EDIT42, m_Edit42);
	DDX_Control(pDX, IDC_EDIT40, m_Edit40);
	DDX_Control(pDX, IDC_EDIT39, m_Edit39);
	DDX_Control(pDX, IDC_EDIT38, m_Edit38);
	DDX_Control(pDX, IDC_EDIT37, m_Edit37);
	DDX_Control(pDX, IDC_EDIT35, m_Edit35);
	DDX_Control(pDX, IDC_EDIT36, m_Edit36);
	DDX_Control(pDX, IDC_EDIT34, m_Edit34);
	DDX_Control(pDX, IDC_EDIT33, m_Edit33);
	DDX_Control(pDX, IDC_EDIT31, m_Edit31);
	DDX_Control(pDX, IDC_EDIT32, m_Edit32);
	DDX_Control(pDX, IDC_EDIT27, m_Edit27);
	DDX_Control(pDX, IDC_EDIT28, m_Edit28);
	DDX_Control(pDX, IDC_EDIT26, m_Edit26);
	DDX_Control(pDX, IDC_EDIT25, m_Edit25);
	DDX_Control(pDX, IDC_EDIT24, m_Edit24);
	DDX_Control(pDX, IDC_EDIT23, m_Edit23);
	DDX_Control(pDX, IDC_EDIT21, m_Edit21);
	DDX_Control(pDX, IDC_EDIT22, m_Edit22);
	DDX_Control(pDX, IDC_EDIT20, m_Edit20);
	DDX_Control(pDX, IDC_EDIT19, m_Edit19);
	DDX_Control(pDX, IDC_EDIT17, m_Edit17);
	DDX_Control(pDX, IDC_EDIT18, m_Edit18);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDOK, m_bOK);
}


BEGIN_MESSAGE_MAP(CDlgEditKP, CDialog)
	//{{AFX_MSG_MAP(CDlgEditKP)
	ON_WM_CHAR()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButtonTpNSI)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEditKP message handlers
extern WORD g_iRang;
BOOL CDlgEditKP::OnInitDialog() 
{
	CDialog::OnInitDialog();
    long Ind = 0;
    char cText[64] = "";

	if( g_iRang < 3 )
		m_bOK.EnableWindow(FALSE);


    DBW.ExecSQL("pTov_GetTKP");
    for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 255;)
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwTKP[i], 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 30, &Ind);
        if( Ind != -1 ) 
        {
            m_Combo1.AddString(cText);
            i++;
        }
    }
    DBW.CloseCursor();

    DBW.ExecSQL("pTov_GetRemKP");
    for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 255;)
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwRemKP[i], 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 30, &Ind);
        if( Ind != -1 ) 
        {
            m_Combo2.AddString(cText);
            i++;
        }
    }
/*    m_Combo1.SetCurSel(0);
    m_Combo2.SetCurSel(0);*/
    DBW.CloseCursor();
    if( iMode == 0 ) return TRUE;
    char cQ[256] = "";
    sprintf(cQ, "pTov_GetFullTypeKP %u, %u, %u", g_iDep, dwITKP, dwTREM);
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch()) == SQL_ERROR ||
        g_sqlret == SQL_NO_DATA )
    {
        DBW.CloseCursor();
        return FALSE;
    }
    DWORD  dwNum = 0;
    double dNum = 0.0;
    DBW.GetData( 1, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind == -1 ) return FALSE;
	DWORD i;
    for(i=0; i < (DWORD)m_Combo1.GetCount() && dwTKP[i] != dwNum; i++ );
    m_Combo1.SetCurSel(i);
    m_Combo1.EnableWindow(FALSE);

    DBW.GetData( 2, SQL_C_SLONG, &dwNum, 4, &Ind);
    for( i=0; i < (DWORD)m_Combo2.GetCount() && dwRemKP[i] != dwNum; i++ );
    if( Ind == -1 ) return FALSE;
    m_Combo2.SetCurSel(i);
    m_Combo2.EnableWindow(FALSE);
    //2 1 7
    DBW.GetData( 3, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit2.SetValue(dwNum);
    DBW.GetData( 4, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit1.SetValue(dwNum);
    DBW.GetData( 5, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit7.SetValue(dwNum);
    //5 3 15
    DBW.GetData( 6, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit5.SetValue(dwNum);
    DBW.GetData( 7, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit3.SetValue(dwNum);
    DBW.GetData( 8, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit16.SetValue(dwNum);
    //67 68
    DBW.GetData( 9, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit67.SetValue(dNum);
    DBW.GetData( 10, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit68.SetValue(dNum);
    // 18 17
    // Диам.оси в подступич.(min)
    DBW.GetData( 11, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit18.SetValue(dNum);
    // Диам.оси в подступич.(max)
    DBW.GetData( 12, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit17.SetValue(dNum);
    //19 20
    // Диам.оси посередине (min)
    DBW.GetData( 13, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit19.SetValue(dNum);
    // Диам.оси посередине (max)
    DBW.GetData( 14, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit20.SetValue(dNum);
    // 22 21 23
    // Толщина гребня (min)
    DBW.GetData( 15, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit22.SetValue(dNum);
    // Толщина гребня (max)
    DBW.GetData( 16, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit21.SetValue(dNum);
    // Расхождение толщины гребня
    DBW.GetData( 17, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit23.SetValue(dNum);
    // 24 25 26
    // Толщина обода (min)
    DBW.GetData( 18, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit24.SetValue(dNum);
    // Толщина обода (max)
    DBW.GetData( 19, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit25.SetValue(dNum);
    // Расхождение толщины обода
    DBW.GetData( 20, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit26.SetValue(dNum);
    // 28 27
    // Прокат колеса (min)
    DBW.GetData( 21, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 )
    {
        m_Edit28.SetValue(dNum);
    }
    // Прокат колеса (max)
    DBW.GetData( 22, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit27.SetValue(dNum);
    // 29 30
    // Mежду внут.гран.колеса (min)
    DBW.GetData( 23, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit29.SetValue(dwNum);
    // Mежду внут.гран.колеса (max)
    DBW.GetData( 24, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit30.SetValue(dwNum);
    // 32 31
    // d1 шейки оси (min)
    DBW.GetData( 25, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit32.SetValue(dNum);
    // d1 шейки оси (max)
    DBW.GetData( 26, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit31.SetValue(dNum);
    //33 34
    // d2 шейки оси (min)
    DBW.GetData( 27, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit33.SetValue(dNum);
    // d2 шейки оси (max)
    DBW.GetData( 28, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit34.SetValue(dNum);
    // 36 35
    // d3 шейки оси (min)
    DBW.GetData( 29, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit36.SetValue(dNum);
    // d3 шейки оси (max)
    DBW.GetData( 30, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit35.SetValue(dNum);
    //37 38
    // d4 шейки оси (min)
    DBW.GetData( 31, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit37.SetValue(dNum);
    // d4 шейки оси (max)
    DBW.GetData( 32, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit38.SetValue(dNum);
    // 39
    // Овальность шейки
    DBW.GetData( 33, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit39.SetValue(dNum);
    // 40
    // Конусность шейки
    DBW.GetData( 34, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit40.SetValue(dNum);
    // 42 41
    // Натяг лабир.кольца(min)
    DBW.GetData( 35, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit42.SetValue(dNum);
    // Натяг лабир.кольца(max)
    DBW.GetData( 36, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit41.SetValue(dNum);
    // 44 45
    // Радиал.зазор заднего подш.
    DBW.GetData( 37, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit44.SetValue(dNum);
    // Радиал.зазор переднего подш.
    DBW.GetData( 38, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit45.SetValue(dNum);
    // 47 48 50 49
    // D1 буксы (min)
    DBW.GetData( 39, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit47.SetValue(dNum);
    // D1 буксы (max)
    DBW.GetData( 40, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit48.SetValue(dNum);
    // D2 буксы (min)
    DBW.GetData( 41, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit50.SetValue(dNum);
    // D2 буксы (max)
    DBW.GetData( 42, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit49.SetValue(dNum);
    // 51 52
    // Диам.внутр.кольца (min)
    DBW.GetData( 43, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit51.SetValue(dNum);
    // Диам.внутр.кольца (max)
    DBW.GetData( 44, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit52.SetValue(dNum);
    // 54 53
    // Натяг внутр.кольца (min)
    DBW.GetData( 45, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit54.SetValue(dNum);
    // Натяг внутр.кольца (max)
    DBW.GetData( 46, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit53.SetValue(dNum);
    // 55 56
    // Осевой зазор(min)
    DBW.GetData( 47, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit55.SetValue(dNum);
    // Осевой зазор(max)
    DBW.GetData( 48, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit56.SetValue(dNum);
    // 58 57
    // Диаметр ступицы(min)
    DBW.GetData( 49, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit58.SetValue(dNum);
    // Диаметр ступицы(max)
    DBW.GetData( 50, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit57.SetValue(dNum);
    // 59 60 
    // Толщина ступицы(min)
    DBW.GetData( 51, SQL_C_SLONG, &dwNum, sizeof(dwNum), &Ind);
    if( Ind != -1 ) m_Edit59.SetValue(dwNum);
    // Толщина ступицы(max)
    DBW.GetData( 52, SQL_C_SLONG, &dwNum, sizeof(dwNum), &Ind);
    if( Ind != -1 ) m_Edit60.SetValue(dNum);
    // 62 61
    // Длина ступицы(min)
    DBW.GetData( 53, SQL_C_SLONG, &dwNum, sizeof(dwNum), &Ind);
    if( Ind != -1 ) m_Edit62.SetValue(dwNum);
    // Длина ступицы(max)
    DBW.GetData( 54, SQL_C_SLONG, &dwNum, sizeof(dwNum), &Ind);
    if( Ind != -1 ) m_Edit61.SetValue(dNum);
    // 63 64
    // Натяг запрессовки(min)
    DBW.GetData( 55, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit63.SetValue(dNum);
    // Натяг запрессовки(max)
    DBW.GetData( 56, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit64.SetValue(dNum);
    // 67 68
    // Усилие запрессовки(min)
    DBW.GetData( 57, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit67.SetValue(dNum);
    // Усилие запрессовки(max)
    DBW.GetData( 58, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit68.SetValue(dNum);
    
    DBW.CloseCursor();
	return TRUE;
}


void CDlgEditKP::OnOK() 
{
    if( !iMode ) // Если добавляем
    {
        // Контроль на дублирующиеся записи
        long Ind = 0;
        DWORD dwCount = 0;
        char cQ[512] = "";
        if( m_Combo1.GetCurSel() < 0 )
        {
            ::MessageBox(NULL, "Необходимо указать тип КП.", "Контроль ввода", MB_OK | MB_ICONINFORMATION);  
            return;
        }
        if( m_Combo2.GetCurSel() < 0 )
        {
            ::MessageBox(NULL, "Необходимо указать вид ремонта.", "Контроль ввода", MB_OK | MB_ICONINFORMATION);  
            return;
        }
        sprintf(cQ, "pTov_CheckDopuskExist %d, %d, %d",
                dwTKP[m_Combo1.GetCurSel()],
                dwRemKP[m_Combo2.GetCurSel()],
                g_iDep);
        DBW.ExecSQL(cQ);
        g_sqlret = DBW.Fetch();
        if( g_sqlret == SQL_ERROR )
        {
            DBW.CloseCursor();
            return;
        }
        DBW.GetData( 1, SQL_C_SLONG, &dwCount, sizeof(dwCount), &Ind);
        DBW.CloseCursor();
        if( Ind == -1 ) return;
        if( dwCount > 0 )
        {
            ::MessageBox(NULL, "В справочнике уже есть запись для колесных пар указанного типа.", "Контроль ввода", MB_OK | MB_ICONINFORMATION);            
            return;
        }
    }
    if(!(m_Edit2.isValid() &&
         m_Edit5.isValid() &&
         m_Edit18.isValid() &&
         m_Edit19.isValid() &&
         m_Edit22.isValid() &&
         m_Edit24.isValid() &&
         m_Edit28.isValid() &&
         m_Edit29.isValid() &&
         m_Edit32.isValid() &&
         m_Edit33.isValid() &&
         m_Edit36.isValid() &&
         m_Edit37.isValid() &&
         m_Edit42.isValid() &&
         m_Edit47.isValid() &&
         m_Edit50.isValid() &&
         m_Edit51.isValid() &&
         m_Edit54.isValid() &&
         m_Edit55.isValid() &&
         m_Edit58.isValid() &&
         m_Edit59.isValid() &&
         m_Edit62.isValid() &&
         m_Edit63.isValid() &&
         m_Edit66.isValid() &&
         m_Edit67.isValid() )        
         )
    {
        AfxMessageBox("Минимальное значение указано некорректно!");
        return;
    }
    if(!(m_Edit1.isValid() &&
         m_Edit3.isValid() &&
         m_Edit17.isValid() &&
         m_Edit20.isValid() &&
         m_Edit21.isValid() &&
         m_Edit25.isValid() &&
         m_Edit27.isValid() &&
         m_Edit30.isValid() &&
         m_Edit31.isValid() &&
         m_Edit34.isValid() &&
         m_Edit35.isValid() &&
         m_Edit38.isValid() &&
         m_Edit39.isValid() &&
         m_Edit40.isValid() &&
         m_Edit41.isValid() &&
         m_Edit44.isValid() &&
         m_Edit45.isValid() &&
         m_Edit48.isValid() &&
         m_Edit49.isValid() &&
         m_Edit52.isValid() &&
         m_Edit53.isValid() &&
         m_Edit56.isValid() &&
         m_Edit57.isValid() &&
         m_Edit60.isValid() &&
         m_Edit61.isValid() &&
         m_Edit64.isValid() &&
         m_Edit65.isValid() &&
         m_Edit68.isValid())
         )
    {
        AfxMessageBox("Максимальное значение указано некорректно!");        
        return;
    }
    if(!(m_Edit61.isValid() &&
         m_Edit64.isValid() &&
         m_Edit65.isValid() &&
         m_Edit68.isValid())
       )
    {
        AfxMessageBox("Некорректно указано расхождение значений!");
        return;
    }
    char cParams[512] = "";
    char cDKK1[32], cDKK2[32], cDKK3[32], cTD1[32], cTD2[32], cTD3[32], cDO_POD1[32], cDO_POD2[32];
    char cDO_S1[32], cDO_S2[32], cTG1[32], cTG2[32], cTG3[32], cTO1[32], cTO2[32], cTO3[32], cP1[32], cP2[32];
    char cRVG1[32], cRVG2[32], cOD11[32], cOD12[32], cOD21[32], cOD22[32], cOD31[32], cOD32[32], cOD41[32], cOD42[32];
    char cOV[32], cKON[32], cNPL1[32], cNPL2[32], cRZZ[32], cRZP[32], cBD11[32], cBD12[32], cBD21[32], cBD22[32];
    char cPDV1[32], cPDV2[32], cNPV1[32], cNPV2[32], cOZ1[32], cOZ2[32], cDO_PR1[32], cDO_PR2[32];
    char cDS1[32], cDS2[32], cTS1[32], cTS2[32], cDLS1[32], cDLS2[32], cNZ1[32], cNZ2[32], cUZ1[32], cUZ2[32];
    char cProc[32] = "pTov_InsertTKP";
    m_Edit2.GetAsString(cDKK1);
    m_Edit1.GetAsString(cDKK2);
    m_Edit7.GetAsString(cDKK3);
    m_Edit5.GetAsString(cTD1);
    m_Edit3.GetAsString(cTD2);
    m_Edit16.GetAsString(cTD3);
    m_Edit18.GetAsString(cDO_POD1);
    m_Edit17.GetAsString(cDO_POD2);
    m_Edit19.GetAsString(cDO_S1);
    m_Edit20.GetAsString(cDO_S2);
    m_Edit22.GetAsString(cTG1);
    m_Edit21.GetAsString(cTG2);
    m_Edit23.GetAsString(cTG3);
    m_Edit24.GetAsString(cTO1);
    m_Edit25.GetAsString(cTO2);
    m_Edit26.GetAsString(cTO3);
    m_Edit28.GetAsString(cP1);
    m_Edit27.GetAsString(cP2);
    m_Edit29.GetAsString(cRVG1);
    m_Edit30.GetAsString(cRVG2);
    m_Edit32.GetAsString(cOD11);
    m_Edit31.GetAsString(cOD12);
    m_Edit33.GetAsString(cOD21);
    m_Edit34.GetAsString(cOD22);
    m_Edit36.GetAsString(cOD31);
    m_Edit35.GetAsString(cOD32);
    m_Edit37.GetAsString(cOD41);
    m_Edit38.GetAsString(cOD42);
    m_Edit39.GetAsString(cOV);
    m_Edit40.GetAsString(cKON);
    m_Edit42.GetAsString(cNPL1);
    m_Edit41.GetAsString(cNPL2);
    m_Edit44.GetAsString(cRZZ);
    m_Edit45.GetAsString(cRZP);
    m_Edit47.GetAsString(cBD11);
    m_Edit48.GetAsString(cBD12);
    m_Edit50.GetAsString(cBD21);
    m_Edit49.GetAsString(cBD22);
    m_Edit51.GetAsString(cPDV1);
    m_Edit52.GetAsString(cPDV2);
    m_Edit54.GetAsString(cNPV1);
    m_Edit53.GetAsString(cNPV2);
    m_Edit55.GetAsString(cOZ1);
    m_Edit56.GetAsString(cOZ2);
    m_Edit58.GetAsString(cDS1);
    m_Edit57.GetAsString(cDS2);
    m_Edit59.GetAsString(cTS1);
    m_Edit60.GetAsString(cTS2);
    m_Edit62.GetAsString(cDLS1);
    m_Edit61.GetAsString(cDLS2);
    m_Edit63.GetAsString(cNZ1);
    m_Edit64.GetAsString(cNZ2);
    m_Edit66.GetAsString(cUZ1);
    m_Edit65.GetAsString(cUZ2);
    m_Edit67.GetAsString(cDO_PR1);
    m_Edit68.GetAsString(cDO_PR2);


    if( iMode )
    {
        strcpy(cProc, "pTov_UpdateTKP");
    }
    sprintf(cParams, "%s "\
                     "%d, %d, %u, %s, %s, %s, %s, %s, %s, %s, "\
                     "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, "\
                     "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, "\
                     "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, "\
                     "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, "\
                     "%s, %s, %s, %s, %s, %s, %s, %s, %s",
            cProc,
            dwTKP[m_Combo1.GetCurSel()],
            dwRemKP[m_Combo2.GetCurSel()],
            g_iDep,
            cDKK1, cDKK2, cDKK3,
            cTD1, cTD2, cTD3,
            cDO_PR1, cDO_PR2, cDO_POD1, cDO_POD2,
            cDO_S1, cDO_S2,
            cTG1, cTG2, cTG3, cTO1, cTO2, cTO3,
            cP1, cP2, cRVG1, cRVG2,
            cOD11, cOD12, cOD21, cOD22,
            cOD31, cOD32, cOD41, cOD42,
            cOV, cKON, cNPL1, cNPL2,
            cRZZ, cRZP,
            cBD11, cBD12, cBD21, cBD22,
            cPDV1, cPDV2, cNPV1, cNPV2,
            cOZ1, cOZ2,
            cDS1, cDS2, cTS1, cTS2, cDLS1, cDLS2, 
            cNZ1, cNZ2, cUZ1, cUZ2);

    DBW.ExecSQL(cParams);
    if( g_sqlret != SQL_ERROR ) AfxMessageBox("Корректировка завершена!");
    DBW.CloseCursor();
//    AfxMessageBox(cParams);
	CDialog::OnOK();
}

void CDlgEditKP::OnBnClickedButtonTpNSI()
{
	if( m_Combo1.GetCurSel() < 0 )
    {
        ::MessageBox(NULL, "Необходимо указать тип КП.", "Контроль ввода", MB_OK | MB_ICONINFORMATION);  
        return;
    }
    if( m_Combo2.GetCurSel() < 0 )
    {
        ::MessageBox(NULL, "Необходимо указать вид ремонта.", "Контроль ввода", MB_OK | MB_ICONINFORMATION);  
        return;
    }
	char cQ[128] = "";
	long Ind = 0;	

    sprintf(cQ, "pTov_GetDopTypeKP %u, %u", dwTKP[m_Combo1.GetCurSel()], dwRemKP[m_Combo2.GetCurSel()]);
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch()) == SQL_ERROR ||
        g_sqlret == SQL_NO_DATA )
    {
        DBW.CloseCursor();
        return;
    }
    DWORD  dwNum = 0;
    double dNum = 0.0;
    DBW.GetData( 1, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind == -1 ) return;
	int i;
    for( i=0; i < (DWORD)m_Combo1.GetCount() && dwTKP[i] != dwNum; i++ );
    m_Combo1.SetCurSel(i);
    m_Combo1.EnableWindow(FALSE);

    DBW.GetData( 2, SQL_C_SLONG, &dwNum, 4, &Ind);
    for( i=0; i < (DWORD)m_Combo2.GetCount() && dwRemKP[i] != dwNum; i++ );
    if( Ind == -1 ) return;
    m_Combo2.SetCurSel(i);
    m_Combo2.EnableWindow(FALSE);
    //2 1 7
    DBW.GetData( 3, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit2.SetValue(dwNum);
    DBW.GetData( 4, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit1.SetValue(dwNum);
    DBW.GetData( 5, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit7.SetValue(dwNum);
    //5 3 15
    DBW.GetData( 6, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit5.SetValue(dwNum);
    DBW.GetData( 7, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit3.SetValue(dwNum);
    DBW.GetData( 8, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit16.SetValue(dwNum);
    //67 68
    DBW.GetData( 9, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit67.SetValue(dNum);
    DBW.GetData( 10, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit68.SetValue(dNum);
    // 18 17
    // Диам.оси в подступич.(min)
    DBW.GetData( 11, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit18.SetValue(dNum);
    // Диам.оси в подступич.(max)
    DBW.GetData( 12, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit17.SetValue(dNum);
    //19 20
    // Диам.оси посередине (min)
    DBW.GetData( 13, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit19.SetValue(dNum);
    // Диам.оси посередине (max)
    DBW.GetData( 14, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit20.SetValue(dNum);
    // 22 21 23
    // Толщина гребня (min)
    DBW.GetData( 15, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit22.SetValue(dNum);
    // Толщина гребня (max)
    DBW.GetData( 16, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit21.SetValue(dNum);
    // Расхождение толщины гребня
    DBW.GetData( 17, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit23.SetValue(dNum);
    // 24 25 26
    // Толщина обода (min)
    DBW.GetData( 18, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit24.SetValue(dNum);
    // Толщина обода (max)
    DBW.GetData( 19, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit25.SetValue(dNum);
    // Расхождение толщины обода
    DBW.GetData( 20, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit26.SetValue(dNum);
    // 28 27
    // Прокат колеса (min)
    DBW.GetData( 21, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 )
    {
        m_Edit28.SetValue(dNum);
    }
    // Прокат колеса (max)
    DBW.GetData( 22, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit27.SetValue(dNum);
    // 29 30
    // Mежду внут.гран.колеса (min)
    DBW.GetData( 23, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit29.SetValue(dwNum);
    // Mежду внут.гран.колеса (max)
    DBW.GetData( 24, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_Edit30.SetValue(dwNum);
    // 32 31
    // d1 шейки оси (min)
    DBW.GetData( 25, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit32.SetValue(dNum);
    // d1 шейки оси (max)
    DBW.GetData( 26, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit31.SetValue(dNum);
    //33 34
    // d2 шейки оси (min)
    DBW.GetData( 27, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit33.SetValue(dNum);
    // d2 шейки оси (max)
    DBW.GetData( 28, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit34.SetValue(dNum);
    // 36 35
    // d3 шейки оси (min)
    DBW.GetData( 29, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit36.SetValue(dNum);
    // d3 шейки оси (max)
    DBW.GetData( 30, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit35.SetValue(dNum);
    //37 38
    // d4 шейки оси (min)
    DBW.GetData( 31, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit37.SetValue(dNum);
    // d4 шейки оси (max)
    DBW.GetData( 32, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit38.SetValue(dNum);
    // 39
    // Овальность шейки
    DBW.GetData( 33, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit39.SetValue(dNum);
    // 40
    // Конусность шейки
    DBW.GetData( 34, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit40.SetValue(dNum);
    // 42 41
    // Натяг лабир.кольца(min)
    DBW.GetData( 35, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit42.SetValue(dNum);
    // Натяг лабир.кольца(max)
    DBW.GetData( 36, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit41.SetValue(dNum);
    // 44 45
    // Радиал.зазор заднего подш.
    DBW.GetData( 37, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit44.SetValue(dNum);
    // Радиал.зазор переднего подш.
    DBW.GetData( 38, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit45.SetValue(dNum);
    // 47 48 50 49
    // D1 буксы (min)
    DBW.GetData( 39, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit47.SetValue(dNum);
    // D1 буксы (max)
    DBW.GetData( 40, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit48.SetValue(dNum);
    // D2 буксы (min)
    DBW.GetData( 41, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit50.SetValue(dNum);
    // D2 буксы (max)
    DBW.GetData( 42, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit49.SetValue(dNum);
    // 51 52
    // Диам.внутр.кольца (min)
    DBW.GetData( 43, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit51.SetValue(dNum);
    // Диам.внутр.кольца (max)
    DBW.GetData( 44, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit52.SetValue(dNum);
    // 54 53
    // Натяг внутр.кольца (min)
    DBW.GetData( 45, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit54.SetValue(dNum);
    // Натяг внутр.кольца (max)
    DBW.GetData( 46, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit53.SetValue(dNum);
    // 55 56
    // Осевой зазор(min)
    DBW.GetData( 47, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit55.SetValue(dNum);
    // Осевой зазор(max)
    DBW.GetData( 48, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit56.SetValue(dNum);
    // 58 57
    // Диаметр ступицы(min)
    DBW.GetData( 49, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit58.SetValue(dNum);
    // Диаметр ступицы(max)
    DBW.GetData( 50, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit57.SetValue(dNum);
    // 59 60 
    // Толщина ступицы(min)
    DBW.GetData( 51, SQL_C_SLONG, &dwNum, sizeof(dwNum), &Ind);
    if( Ind != -1 ) m_Edit59.SetValue(dwNum);
    // Толщина ступицы(max)
    DBW.GetData( 52, SQL_C_SLONG, &dwNum, sizeof(dwNum), &Ind);
    if( Ind != -1 ) m_Edit60.SetValue(dNum);
    // 62 61
    // Длина ступицы(min)
    DBW.GetData( 53, SQL_C_SLONG, &dwNum, sizeof(dwNum), &Ind);
    if( Ind != -1 ) m_Edit62.SetValue(dwNum);
    // Длина ступицы(max)
    DBW.GetData( 54, SQL_C_SLONG, &dwNum, sizeof(dwNum), &Ind);
    if( Ind != -1 ) m_Edit61.SetValue(dNum);
    // 63 64
    // Натяг запрессовки(min)
    DBW.GetData( 55, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit63.SetValue(dNum);
    // Натяг запрессовки(max)
    DBW.GetData( 56, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit64.SetValue(dNum);
    // 67 68
    // Усилие запрессовки(min)
    DBW.GetData( 57, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit67.SetValue(dNum);
    // Усилие запрессовки(max)
    DBW.GetData( 58, SQL_C_DOUBLE, &dNum, sizeof(dNum), &Ind);
    if( Ind != -1 ) m_Edit68.SetValue(dNum);
    
    DBW.CloseCursor();
}
