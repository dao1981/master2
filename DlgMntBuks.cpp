// DlgMntBuks.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMntBuks.h"
#include "DlgSpravKdr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgMntBuks dialog


CDlgMntBuks::CDlgMntBuks(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMntBuks::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMntBuks)
	m_strNumKP = _T("");
	m_strTKP = _T("");
	//}}AFX_DATA_INIT
    vd_OS_d1_1 = 0.0;
    vd_OS_d1_2 = 0.0;
    vd_OS_d2_1 = 0.0;
    vd_OS_d2_2 = 0.0;
    vd_OS_d3_1 = 0.0;
    vd_OS_d3_2 = 0.0;
    vd_OS_d4_1 = 0.0;
    vd_OS_d4_2 = 0.0;

    vd_OVAL = 0.0;
    vd_KONUS = 0.0;
    vd_NP_LABK1 = 0.0; 
    vd_NP_LABK2 = 0.0;
    vd_RADZAZ_P = 0.0; 
    vd_RADZAZ_Z = 0.0;
    
    vd_BUK_D1_1 = 0.0; 
    vd_BUK_D1_2 = 0.0; 
    vd_BUK_D2_1 = 0.0; 
    vd_BUK_D2_2 = 0.0;
    vd_OS_ZAZ1 = 0.0; 
    vd_OS_ZAZ2 = 0.0; 
    vd_VK_D1_1 = 0.0; 
    vd_VK_D1_2 = 0.0;
    vd_NP_VK1_1 = 0.0; 
    vd_NP_VK1_2 = 0.0;

    m_FIO1.SetMode(5);
    DBW.FillEmplArray(m_FIO1.lpEmpl, 3);
    m_FIO2.SetMode(5);
    DBW.FillEmplArray(m_FIO2.lpEmpl, 4);
    m_FIO3.SetMode(5);
    DBW.FillEmplArray(m_FIO3.lpEmpl, 6);
    m_FIO4.SetMode(5);
    DBW.FillEmplArray(m_FIO4.lpEmpl, 6);
    

}


void CDlgMntBuks::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMntBuks)
	DDX_Control(pDX, IDC_EDIT115, m_FIO4);
	DDX_Control(pDX, IDC_EDIT45, m_FIO3);
	DDX_Control(pDX, IDC_EDIT44, m_FIO2);
	DDX_Control(pDX, IDC_EDIT35, m_FIO1);
	DDX_Control(pDX, IDC_EDIT93, m_n3);
	DDX_Control(pDX, IDC_EDIT94, m_n5);
	DDX_Control(pDX, IDC_EDIT70, m_n6);
	DDX_Control(pDX, IDC_EDIT6, m_n4);
	DDX_Control(pDX, IDC_EDIT5, m_n2);
	DDX_Control(pDX, IDC_EDIT4, m_n1);
	DDX_Control(pDX, IDC_EDIT114, m_i4);
	DDX_Control(pDX, IDC_EDIT113, m_i2);
	DDX_Control(pDX, IDC_EDIT112, m_i3);
	DDX_Control(pDX, IDC_EDIT111, m_i1);
	DDX_Control(pDX, IDC_EDIT34, m_spart);
	DDX_Control(pDX, IDC_EDIT21, m_pdat4);
	DDX_Control(pDX, IDC_EDIT20, m_pdat3);
	DDX_Control(pDX, IDC_EDIT18, m_pdat2);
	DDX_Control(pDX, IDC_EDIT17, m_pdat1);
	DDX_Control(pDX, IDC_EDIT19, m_pnum4);
	DDX_Control(pDX, IDC_EDIT69, m_pnum3);
	DDX_Control(pDX, IDC_EDIT11, m_pnum2);
	DDX_Control(pDX, IDC_EDIT7, m_pnum1);
	DDX_Control(pDX, IDC_CHECK1, m_PS);
	DDX_Control(pDX, IDC_EDIT47, m_Date);
	DDX_Control(pDX, IDC_COMBO18, m_Cb12);
	DDX_Control(pDX, IDC_COMBO17, m_Cb11);
	DDX_Control(pDX, IDC_COMBO16, m_Cb10);
	DDX_Control(pDX, IDC_COMBO14, m_Cb9);
	DDX_Control(pDX, IDC_COMBO15, m_Cb8);
	DDX_Control(pDX, IDC_COMBO13, m_Cb7);
	DDX_Control(pDX, IDC_COMBO12, m_Cb6);
	DDX_Control(pDX, IDC_COMBO5, m_Cb5);
	DDX_Control(pDX, IDC_COMBO11, m_Cb4);
	DDX_Control(pDX, IDC_COMBO4, m_Cb3);	
	DDX_Control(pDX, IDC_EDIT110, m_h4);
	DDX_Control(pDX, IDC_EDIT108, m_h3);
	DDX_Control(pDX, IDC_EDIT109, m_h2);
	DDX_Control(pDX, IDC_EDIT107, m_h1);
	DDX_Control(pDX, IDC_EDIT106, m_g4);
	DDX_Control(pDX, IDC_EDIT104, m_g3);
	DDX_Control(pDX, IDC_EDIT105, m_g2);
	DDX_Control(pDX, IDC_EDIT103, m_g1);
	DDX_Control(pDX, IDC_EDIT89, m_f8);
	DDX_Control(pDX, IDC_EDIT83, m_f7);
	DDX_Control(pDX, IDC_EDIT92, m_f6);
	DDX_Control(pDX, IDC_EDIT76, m_f5);
	DDX_Control(pDX, IDC_EDIT14, m_f4);
	DDX_Control(pDX, IDC_EDIT75, m_f3);
	DDX_Control(pDX, IDC_EDIT82, m_f2);
	DDX_Control(pDX, IDC_EDIT81, m_f1);
	DDX_Control(pDX, IDC_EDIT95, m_e2);
	DDX_Control(pDX, IDC_EDIT90, m_e4);
	DDX_Control(pDX, IDC_EDIT85, m_e3);
	DDX_Control(pDX, IDC_EDIT84, m_e1);
	DDX_Control(pDX, IDC_EDIT80, m_d8);
	DDX_Control(pDX, IDC_EDIT79, m_d6);
	DDX_Control(pDX, IDC_EDIT8, m_d2);
	DDX_Control(pDX, IDC_EDIT102, m_d16);
	DDX_Control(pDX, IDC_EDIT101, m_d15);
	DDX_Control(pDX, IDC_EDIT100, m_d14);
	DDX_Control(pDX, IDC_EDIT99, m_d13);
	DDX_Control(pDX, IDC_EDIT39, m_d12);
	DDX_Control(pDX, IDC_EDIT98, m_d11);
	DDX_Control(pDX, IDC_EDIT97, m_d10);
	DDX_Control(pDX, IDC_EDIT96, m_d9);
	DDX_Control(pDX, IDC_EDIT13, m_d7);
	DDX_Control(pDX, IDC_EDIT12, m_d5);
	DDX_Control(pDX, IDC_EDIT10, m_d4);
	DDX_Control(pDX, IDC_EDIT9, m_d3);
	DDX_Control(pDX, IDC_EDIT3, m_d1);
	DDX_Control(pDX, IDC_COMBO2, m_Cb2);
	DDX_Control(pDX, IDC_COMBO1, m_Cb1);
	DDX_Text(pDX, IDC_EDIT1, m_strNumKP);
	DDX_Text(pDX, IDC_EDIT2, m_strTKP);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMntBuks, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgMntBuks)
	ON_BN_CLICKED(IDC_BUTTON5, OnMasterButton)
	ON_BN_CLICKED(IDC_BUTTON6, OnOTKButton)
	ON_BN_CLICKED(IDC_BUTTON7, OnSles1Button)
	ON_BN_CLICKED(IDC_BUTTON8, OnSles2Button)
	ON_BN_CLICKED(IDC_CHECK1, OnPSClick)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnChangePr_R)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnChangePr_L)
	ON_EN_CHANGE(IDC_EDIT3, OnChange_d1R)
	ON_EN_CHANGE(IDC_EDIT12, OnChange_d2R)
	ON_EN_CHANGE(IDC_EDIT8, OnChange_d1L)
	ON_EN_CHANGE(IDC_EDIT79, OnChange_d2L)
	ON_EN_CHANGE(IDC_EDIT101, OnChange_Recall)
	ON_EN_CHANGE(IDC_EDIT102, OnChange_Recall_Left)
	ON_EN_CHANGE(IDC_EDIT107, OnRingVn_ZR)
	ON_EN_CHANGE(IDC_EDIT109, OnRingVn_ZL)
	ON_EN_CHANGE(IDC_EDIT108, OnRingVn_PR)
	ON_EN_CHANGE(IDC_EDIT110, OnRingVn_PL)
	ON_COMMAND(ID_ARROW_UP, OnArrowUp)
	ON_WM_SYSKEYDOWN()
	ON_CBN_SELCHANGE(IDC_COMBO1, OnChangePr_R)
	ON_EN_CHANGE(IDC_EDIT99, OnChange_Recall)
	ON_EN_CHANGE(IDC_EDIT98, OnChange_Recall)
	ON_EN_CHANGE(IDC_EDIT96, OnChange_Recall)
	ON_EN_CHANGE(IDC_EDIT100, OnChange_Recall_Left)
	ON_EN_CHANGE(IDC_EDIT39, OnChange_Recall_Left)
	ON_EN_CHANGE(IDC_EDIT97, OnChange_Recall_Left)
	ON_EN_CHANGE(IDC_EDIT9, OnChange_d1R)
	ON_EN_CHANGE(IDC_EDIT13, OnChange_d2R)
	ON_EN_CHANGE(IDC_EDIT10, OnChange_d1L)
	ON_EN_CHANGE(IDC_EDIT80, OnChange_d2L)
	ON_WM_VKEYTOITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMntBuks message handlers

void CDlgMntBuks::InitMaskedFields()
{
    m_d1.QInit(33);
    m_d2.QInit(33);
    m_d3.QInit(33);
    m_d4.QInit(33);
    m_d5.QInit(33);
    m_d6.QInit(33);
    m_d7.QInit(33);
    m_d8.QInit(33);
    m_d9.QInit(33);
    m_d10.QInit(33);
    m_d11.QInit(33);
    m_d12.QInit(33);
    m_d13.QInit(33);
    m_d14.QInit(33);
    m_d15.QInit(33);
    m_d16.QInit(33);

    m_e1.QInit(12);
    m_e2.QInit(12);
    m_e3.QInit(12);
    m_e4.QInit(12);

    m_f1.QInit(32);
    m_f2.QInit(32);
    m_f3.QInit(32);
    m_f4.QInit(32);
    m_f5.QInit(32);
    m_f6.QInit(32);
    m_f7.QInit(32);
    m_f8.QInit(32);

    m_g1.QInit(12);
    m_g2.QInit(12);
    m_g3.QInit(12);
    m_g4.QInit(12);

    m_h1.QInit(33);
    m_h2.QInit(33);
    m_h3.QInit(33);
    m_h4.QInit(33);

    m_i1.QInit(33);
    m_i2.QInit(33);
    m_i3.QInit(33);
    m_i4.QInit(33);

    m_n1.QInit(33);
    m_n2.QInit(33);
    m_n3.QInit(33);
    m_n4.QInit(33);
    m_n5.QInit(33);
    m_n6.QInit(33);
    
    m_Date.iMode = 1;
    m_Date.InitDate();
}

BOOL CDlgMntBuks::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();

	m_pdat1.SetMode(0, 0, 5);
	m_pdat2.SetMode(0, 0, 5);
	m_pdat3.SetMode(0, 0, 5);
	m_pdat4.SetMode(0, 0, 5);

    char cQ[128] = "";
    sprintf(cQ, "pTov_GetRemKP %I64u", qwIZAP);
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch())==SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {
        DBW.CloseCursor();
        MessageBox("Перед монтажом букс необходимо ввести информацию о ремонте КП!", "Внимание", MB_OK | MB_ICONINFORMATION);
        CDlgWithAccelerators::OnCancel();
        return FALSE;
    }
    DBW.CloseCursor();

    m_n1.ModifyStyle(0, WS_DISABLED);
    m_n2.ModifyStyle(0, WS_DISABLED);
    m_n3.ModifyStyle(0, WS_DISABLED);
    m_n4.ModifyStyle(0, WS_DISABLED);
    m_n5.ModifyStyle(0, WS_DISABLED);
    m_n6.ModifyStyle(0, WS_DISABLED);
    m_i1.ModifyStyle(0, WS_DISABLED);
    m_i2.ModifyStyle(0, WS_DISABLED);
    m_i3.ModifyStyle(0, WS_DISABLED);
    m_i4.ModifyStyle(0, WS_DISABLED);

	InitMaskedFields();
/*
    SetComboItem(&m_Cb5, "42726Е2М");
    SetComboItem(&m_Cb9, "232726Е2М");
    SetComboItem(&m_Cb6, "42726Е2М");
    SetComboItem(&m_Cb10,"232726Е2М");
*/
    FormAkt();
    m_PS.SetCheck(1);
    OnPSClick();

    IniForm();
    GetDopuskValues();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMntBuks::IniForm()
{
    // Вывод на форму ранее введенных параметров
    char cQ[64] = "";
//    if( Prih.dwPriznRas < 11 ) return; // Не было записи
    sprintf(cQ, "pTov_GetMontBuks %I64u", qwIZAP);
    DBW.ExecSQL(cQ);
    if( (g_sqlret = DBW.Fetch()) == SQL_NO_DATA || g_sqlret == SQL_ERROR )
    {

        DBW.CloseCursor();
        return;
    }
    long        Ind = 0;
    SYSTEMTIME  st;
    DWORD       dwNum = 0;
    double      d1 = 0.0, d2 = 0.0, d3 = 0.0, d4 = 0.0, d5 = 0.0, d6 = 0.0, d7 = 0.0, d8 = 0.0, 
                d9 = 0.0, d10 = 0.0, d11 = 0.0, d12 = 0.0, d13 = 0.0, d14 = 0.0, d15 = 0.0, d16 = 0.0;
    double dNum = 0.0;
    char cText[64] = "";
    //Дата
    mgSQLGetSysDate(1, &st, &Ind);
    m_Date.SetTime(&st);
    //Признаки снятия колец
    DBW.GetData( 2, SQL_C_SLONG, &dwNum, 4, &Ind);
    m_Cb1.SetCurSel(dwNum - 1);
    DBW.GetData( 3, SQL_C_SLONG, &dwNum, 4, &Ind);
    m_Cb2.SetCurSel(dwNum - 1);
    DBW.GetData( 4, SQL_C_DOUBLE, &d1, 8, &Ind);
    if( Ind != -1 )m_d1.SetValue(d1);
    DBW.GetData( 5, SQL_C_DOUBLE, &d2, 8, &Ind);
    if( Ind != -1 )m_d2.SetValue(d2);
    DBW.GetData( 6, SQL_C_DOUBLE, &d3, 8, &Ind);
    if( Ind != -1 )m_d3.SetValue(d3);
    DBW.GetData( 7, SQL_C_DOUBLE, &d4, 8, &Ind);
    if( Ind != -1 )m_d4.SetValue(d4);
    DBW.GetData( 8, SQL_C_DOUBLE, &d5, 8, &Ind);
    if( Ind != -1 )m_d5.SetValue(d5);
    DBW.GetData( 9, SQL_C_DOUBLE, &d6, 8, &Ind);
    if( Ind != -1 )m_d6.SetValue(d6);
    DBW.GetData( 10, SQL_C_DOUBLE, &d7, 8, &Ind);
    if( Ind != -1 )m_d7.SetValue(d7);
    DBW.GetData( 11, SQL_C_DOUBLE, &d8, 8, &Ind);
    if( Ind != -1 )m_d8.SetValue(d8);
    DBW.GetData( 12, SQL_C_DOUBLE, &d9, 8, &Ind);
    if( Ind != -1 )m_d9.SetValue(d9);
    DBW.GetData( 13, SQL_C_DOUBLE, &d10, 8, &Ind);
    if( Ind != -1 )m_d10.SetValue(d10);
    DBW.GetData( 14, SQL_C_DOUBLE, &d11, 8, &Ind);
    if( Ind != -1 )m_d11.SetValue(d11);
    DBW.GetData( 15, SQL_C_DOUBLE, &d12, 8, &Ind);
    if( Ind != -1 )m_d12.SetValue(d12);
    DBW.GetData( 16, SQL_C_DOUBLE, &d13, 8, &Ind);
    if( Ind != -1 )m_d13.SetValue(d13);
    DBW.GetData( 17, SQL_C_DOUBLE, &d14, 8, &Ind);
    if( Ind != -1 )m_d14.SetValue(d14);
    DBW.GetData( 18, SQL_C_DOUBLE, &d15, 8, &Ind);
    if( Ind != -1 )m_d15.SetValue(d15);
    DBW.GetData( 19, SQL_C_DOUBLE, &d16, 8, &Ind);
    if( Ind != -1 )m_d16.SetValue(d16);
    // Рассчетные значения
/*
    DBW.GetData( 20, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_n1.SetWindowText(cText);
    DBW.GetData( 21, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_n2.SetWindowText(cText);
    DBW.GetData( 22, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_n3.SetWindowText(cText);
    DBW.GetData( 23, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_n4.SetWindowText(cText);
    DBW.GetData( 24, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_n5.SetWindowText(cText);
    DBW.GetData( 25, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_n6.SetWindowText(cText);
*/
    // Радиальный зазор
    DBW.GetData( 26, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_e1.SetValue(dNum);
    DBW.GetData( 27, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_e2.SetValue(dNum);
    DBW.GetData( 28, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_e3.SetValue(dNum);
    DBW.GetData( 29, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_e4.SetValue(dNum);
    // Посадочные диаметры
    DBW.GetData( 30, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_f1.SetValue(dNum);
    DBW.GetData( 31, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_f2.SetValue(dNum);
    DBW.GetData( 32, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_f3.SetValue(dNum);
    DBW.GetData( 33, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_f4.SetValue(dNum);
    DBW.GetData( 34, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_f5.SetValue(dNum);
    DBW.GetData( 35, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_f6.SetValue(dNum);
    DBW.GetData( 36, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_f7.SetValue(dNum);
    DBW.GetData( 37, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_f8.SetValue(dNum);
    DBW.GetData( 38, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_PS.SetCheck(dwNum);
    
    // Подшипники

    // Задний правый
    DBW.GetData( 39, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        for( int i=0; i < m_Cb3.GetCount() && i < 255 ; i++ )
            if( dwNum == m_Cb3.GetItemData(i) )
            {
                m_Cb3.SetCurSel(i);
                break;
            }
    }
    DBW.GetData( 40, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        for( int i=0; i < m_Cb5.GetCount() && i < 255 ; i++ )
            if( dwNum == m_Cb5.GetItemData(i) )
            {
                m_Cb5.SetCurSel(i);
                break;
            }
    }
    DBW.GetData( 41, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_pnum1.SetWindowText(cText);
    DBW.GetData( 42, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_pdat1.SetWindowText(cText);
    
    // Задний левый
    DBW.GetData( 43, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        for( int i=0; i < m_Cb4.GetCount() && i < 255 ; i++ )
            if( dwNum == m_Cb4.GetItemData(i) )
            {
                m_Cb4.SetCurSel(i);
                break;
            }
    }
    DBW.GetData( 44, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        for( int i=0; i < m_Cb6.GetCount() && i < 255 ; i++ )
            if( dwNum == m_Cb6.GetItemData(i) )
            {
                m_Cb6.SetCurSel(i);
                break;
            }
    }
    DBW.GetData( 45, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_pnum2.SetWindowText(cText);
    DBW.GetData( 46, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_pdat2.SetWindowText(cText);

    // Передний правый
    DBW.GetData( 47, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        for( int i=0; i < m_Cb7.GetCount() && i < 255 ; i++ )
            if( dwNum == m_Cb7.GetItemData(i) )
            {
                m_Cb7.SetCurSel(i);
                break;
            }
    }
    DBW.GetData( 48, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        for( int i=0; i < m_Cb9.GetCount() && i < 255 ; i++ )
            if( dwNum == m_Cb9.GetItemData(i) )
            {
                m_Cb9.SetCurSel(i);
                break;
            }
    }
    DBW.GetData( 49, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_pnum3.SetWindowText(cText);
    DBW.GetData( 50, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_pdat3.SetWindowText(cText);
    
    // Передний левый
    DBW.GetData( 51, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        for( int i=0; i < m_Cb8.GetCount() && i < 255 ; i++ )
            if( dwNum == m_Cb8.GetItemData(i) )
            {
                m_Cb8.SetCurSel(i);
                break;
            }
    }
    DBW.GetData( 52, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        for( int i=0; i < m_Cb10.GetCount() && i < 255 ; i++ )
            if( dwNum == m_Cb10.GetItemData(i) )
            {
                m_Cb10.SetCurSel(i);
                break;
            }
    }
    DBW.GetData( 53, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_pnum4.SetWindowText(cText);
    DBW.GetData( 54, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_pdat4.SetWindowText(cText);
    // Смазка
    DBW.GetData( 55, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        for( int i=0; i < m_Cb11.GetCount() && i < 255 ; i++ )
            if( dwNum == m_Cb11.GetItemData(i) )
            {
                m_Cb11.SetCurSel(i);
                break;
            }
    }
    DBW.GetData( 56, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        for( int i=0; i < m_Cb12.GetCount() && i < 255 ; i++ )
            if( dwNum == m_Cb12.GetItemData(i) )
            {
                m_Cb12.SetCurSel(i);
                break;
            }
    }
    DBW.GetData( 57, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_spart.SetWindowText(cText);

    // Минимальный осевой зазор
    DBW.GetData( 58, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_g1.SetValue(dNum);
    DBW.GetData( 59, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_g2.SetValue(dNum);
    DBW.GetData( 60, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_g3.SetValue(dNum);
    DBW.GetData( 61, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_g4.SetValue(dNum);

    // Посадочный диаметр внутреннего кольца
    DBW.GetData( 62, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_h1.SetValue(dNum);
    DBW.GetData( 63, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_h2.SetValue(dNum);
    DBW.GetData( 64, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_h3.SetValue(dNum);
    DBW.GetData( 65, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_h4.SetValue(dNum);

    // Натяг на посадку внутреннего кольца
    DBW.GetData( 66, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_i1.SetValue(dNum);
    DBW.GetData( 67, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_i2.SetValue(dNum);
    DBW.GetData( 68, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_i3.SetValue(dNum);
    DBW.GetData( 69, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )m_i4.SetValue(dNum);

    // Фамилии
    // Иденификаторы
    DBW.GetData( 70, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_FIO1.SetData(dwNum);
    DBW.GetData( 71, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_FIO2.SetData(dwNum);
    DBW.GetData( 72, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_FIO3.SetData(dwNum);
    DBW.GetData( 73, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) m_FIO4.SetData(dwNum);
    // Теперь буквами
    DBW.GetData( 74, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_FIO1.SetWindowText(cText);
    DBW.GetData( 75, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_FIO2.SetWindowText(cText);
    DBW.GetData( 76, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_FIO3.SetWindowText(cText);
    DBW.GetData( 77, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 )m_FIO4.SetWindowText(cText);

    DBW.CloseCursor();

    CalcOval(0);
    CalcConus(0);
    CalcIntRingP(0);
    CalcIntRingZ(0);
    CalcLabRing(0);	
    CalcOval(1);
    CalcConus(1);
    CalcIntRingP(1);
    CalcIntRingZ(1);
    CalcLabRing(1);	

    OnChangePr_L();
    OnChangePr_R();
/*
    SetComboItem(&m_Cb5, "42726Л1М");
    SetComboItem(&m_Cb9, "232726Л1М");
    SetComboItem(&m_Cb6, "42726Л1М");
    SetComboItem(&m_Cb10,"232726Л1М");
*/
    // Рассчетные значения
//    RefreshCalculated(); 
//    m_n1
}


void CDlgMntBuks::FormAkt()
{
    char    cQ[512] = "";
    char    cText[64] = "";
    long    Ind = 0;
    DWORD   dwNum = 0;
    // Заполнение меню предприятий изготовления подшипников
    strcpy(cQ, "pTov_GetPrPodsh");
    DBW.ExecSQL(cQ);
    for(int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwNum, 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Cb3.AddString(cText);
        m_Cb3.SetItemData(i, dwNum);
        m_Cb4.AddString(cText);
        m_Cb4.SetItemData(i, dwNum);
        m_Cb7.AddString(cText);
        m_Cb7.SetItemData(i, dwNum);
        m_Cb8.AddString(cText);
        m_Cb8.SetItemData(i, dwNum);
    }
    if( g_sqlret == SQL_ERROR )
    {
        MessageBox("Ошибка НСИ!", "Внимание", MB_OK);
        return;
    }
    DBW.CloseCursor();
    // Заполнение меню типов подшипников
    strcpy(cQ, "pTov_GetTypesRP");
    DBW.ExecSQL(cQ);
    for(int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwNum, 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Cb5.AddString(cText);
        m_Cb5.SetItemData(i, dwNum);
        m_Cb6.AddString(cText);
        m_Cb6.SetItemData(i, dwNum);
        m_Cb9.AddString(cText);
        m_Cb9.SetItemData(i, dwNum);
        m_Cb10.AddString(cText);
        m_Cb10.SetItemData(i, dwNum);
    }
    if( g_sqlret == SQL_ERROR )
    {
        MessageBox("Ошибка НСИ!", "Внимание", MB_OK);
        return;
    }
    DBW.CloseCursor();
    // Заполнение меню предприятий изготовления смазки
    strcpy(cQ, "pTov_GetPrSmaz");
    DBW.ExecSQL(cQ);
    for(int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwNum, 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Cb12.AddString(cText);
        m_Cb12.SetItemData(i, dwNum);
    }
    if( g_sqlret == SQL_ERROR )
    {
        MessageBox("Ошибка НСИ!", "Внимание", MB_OK);
        return;
    }
    DBW.CloseCursor();
    // Заполнение меню марок смазки
    strcpy(cQ, "pTov_GetSmazkaKind");
    DBW.ExecSQL(cQ);
    for(int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwNum, 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Cb11.AddString(cText);
        m_Cb11.SetItemData(i, dwNum);
    }
    if( g_sqlret == SQL_ERROR )
    {
        MessageBox("Ошибка НСИ!", "Внимание", MB_OK);
        return;
    }
    DBW.CloseCursor();
}


void CDlgMntBuks::GetDopuskValues()
{
    char cQ[128] = "";
    sprintf(cQ, "pTov_GetDopuskBuks %u, %u, %u", g_iDep, dwTKP, dwRem);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR)
    {
        DBW.CloseCursor();
        bHaveDopusk = false;
        return;
    }
    double  dNum = 0;
    long    Ind = 0;

    DBW.GetData( 1, SQL_C_DOUBLE, &vd_OS_d1_1, 8, &Ind);
    DBW.GetData( 2, SQL_C_DOUBLE, &vd_OS_d1_2, 8, &Ind);
    DBW.GetData( 3, SQL_C_DOUBLE, &vd_OS_d2_1, 8, &Ind);
    DBW.GetData( 4, SQL_C_DOUBLE, &vd_OS_d2_2, 8, &Ind);
    DBW.GetData( 5, SQL_C_DOUBLE, &vd_OS_d3_1, 8, &Ind);
    DBW.GetData( 6, SQL_C_DOUBLE, &vd_OS_d3_2, 8, &Ind);
    DBW.GetData( 7, SQL_C_DOUBLE, &vd_OS_d4_1, 8, &Ind);
    DBW.GetData( 8, SQL_C_DOUBLE, &vd_OS_d4_2, 8, &Ind);

    DBW.GetData( 9, SQL_C_DOUBLE, &vd_OVAL, 8, &Ind);
    DBW.GetData( 10, SQL_C_DOUBLE, &vd_KONUS, 8, &Ind);
    DBW.GetData( 11, SQL_C_DOUBLE, &vd_NP_LABK1, 8, &Ind);
    DBW.GetData( 12, SQL_C_DOUBLE, &vd_NP_LABK2, 8, &Ind);

    DBW.GetData( 13, SQL_C_DOUBLE, &vd_RADZAZ_P, 8, &Ind);
    DBW.GetData( 14, SQL_C_DOUBLE, &vd_RADZAZ_Z, 8, &Ind);

    DBW.GetData( 15, SQL_C_DOUBLE, &vd_BUK_D1_1, 8, &Ind);
    DBW.GetData( 16, SQL_C_DOUBLE, &vd_BUK_D1_2, 8, &Ind);
    DBW.GetData( 17, SQL_C_DOUBLE, &vd_BUK_D2_1, 8, &Ind);
    DBW.GetData( 18, SQL_C_DOUBLE, &vd_BUK_D2_2, 8, &Ind);

    DBW.GetData( 19, SQL_C_DOUBLE, &vd_OS_ZAZ1, 8, &Ind);
    DBW.GetData( 20, SQL_C_DOUBLE, &vd_OS_ZAZ2, 8, &Ind);
    DBW.GetData( 21, SQL_C_DOUBLE, &vd_VK_D1_1, 8, &Ind);
    DBW.GetData( 22, SQL_C_DOUBLE, &vd_VK_D1_2, 8, &Ind);

    DBW.GetData( 23, SQL_C_DOUBLE, &vd_NP_VK1_1, 8, &Ind);
    DBW.GetData( 24, SQL_C_DOUBLE, &vd_NP_VK1_2, 8, &Ind);
    
    DBW.CloseCursor();
    bHaveDopusk = true;
}
int CDlgMntBuks::CheckVal(double Value, int Kind)
{
    if( !bHaveDopusk ) return 0;

    switch (Kind)
    {
    case OS_D1:
        if( !vd_OS_d1_2 ) return 0;
        if( Value >= vd_OS_d1_1 && Value <= vd_OS_d1_2 ) return 0;
        return -1;
    case OS_D2:
        if( !vd_OS_d2_2 ) return 0;
        if( Value >= vd_OS_d2_1 && Value <= vd_OS_d2_2 ) return 0;
        return -1;
    case OS_D3:
        if( !vd_OS_d3_2 ) return 0;
        if( Value >= vd_OS_d3_1 && Value <= vd_OS_d3_2 ) return 0;
        return -1;
    case OS_D4:
        if( !vd_OS_d4_2 ) return 0;
        if( Value >= vd_OS_d4_1 && Value <= vd_OS_d4_2 ) return 0;
        return -1;
    case OVAL:
        if( !vd_OVAL ) return 0;
        if( Value <= vd_OVAL ) return 0;
        return -1;
    case KONUS:
        if( !vd_KONUS ) return 0;
        if( Value <= vd_KONUS ) return 0;
        return -1;
    case NP_LABK:
        if( !vd_NP_LABK2 ) return 0;
        if( Value >= vd_NP_LABK1 && Value <= vd_NP_LABK2 ) return 0;
        return -1;
    case RADZAZ_P:
        if( !vd_RADZAZ_P ) return 0;
        if( Value <= vd_RADZAZ_P ) return 0;
        return -1;
    case RADZAZ_Z:
        if( !vd_RADZAZ_Z ) return 0;
        if( Value <= vd_RADZAZ_Z ) return 0;
        return -1;
    case OS_ZAZ:
        if( !vd_OS_ZAZ2 ) return 0;
        if( Value >= vd_OS_ZAZ1 && Value <= vd_OS_ZAZ2 ) return 0;
        return -1;
    case VK_D1:
        if( !vd_VK_D1_2 ) return 0;
        if( Value >= vd_VK_D1_1 && Value <= vd_VK_D1_2 ) return 0;
        return -1;
    case NP_VK1:
        if( !vd_NP_VK1_2 ) return 0;
        if( Value >= vd_NP_VK1_1 && Value <= vd_NP_VK1_2 ) return 0;
        return -1;
    case BUK_D1:
        if( !vd_BUK_D1_2 ) return 0;
        if( Value >= vd_BUK_D1_1 && Value <= vd_BUK_D1_2 ) return 0;
        return -1;
    case BUK_D2:
        if( !vd_BUK_D2_2 ) return 0;
        if( Value >= vd_BUK_D2_1 && Value <= vd_BUK_D2_2 ) return 0;
        return -1;
    }
    return 0;
}

bool CDlgMntBuks::CheckWithRings()
{
    // Проверим правую сторону
    int id = m_Cb1.GetCurSel();
    if( id == 3 ) return true;
    if( m_d1.isNull() && (id == 0 || id == 1 || id == 2 ) )
    {
        MessageBox("Не указано значение d1 (прав).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d3.isNull() && (id == 0 || id == 1 || id == 2 ) )
    {
        MessageBox("Не указано значение d1' (прав).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d5.isNull() && (id == 0 || id == 1 ) )
    {
        MessageBox("Не указано значение d2 (прав).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d7.isNull() && (id == 0 || id == 1 ) )
    {
        MessageBox("Не указано значение d2' (прав).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d9.isNull() && (id == 0 ) )
    {
        MessageBox("Не указано значение d3 (прав).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d11.isNull() && (id == 0 ) )
    {
        MessageBox("Не указано значение d3' (прав).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d13.isNull() && (id == 0 ) )
    {
        MessageBox("Не указано значение d4 (прав).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d15.isNull() && (id == 0 ) )
    {
        MessageBox("Не указано значение d4' (прав).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_h1.isNull() && (id == 0 || id == 1 ) )
    {
        MessageBox("Не указано значение заднего правого посадочного диаметра внутреннего кольца.","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_h3.isNull() && (id == 0 || id == 1 || id == 2) )
    {
        MessageBox("Не указано значение переднего правого посадочного диаметра внутреннего кольца.","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }

    id = m_Cb2.GetCurSel();
    // теперь левую
    if( m_d2.isNull() && (id == 0 || id == 1 || id == 2 ) )
    {
        MessageBox("Не указано значение d1 (лев.).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d4.isNull() && (id == 0 || id == 1 || id == 2 ) )
    {
        MessageBox("Не указано значение d1' (лев.).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d6.isNull() && (id == 0 || id == 1 ) )
    {
        MessageBox("Не указано значение d2 (лев.).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d8.isNull() && (id == 0 || id == 1 ) )
    {
        MessageBox("Не указано значение d2' (лев.).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d10.isNull() && (id == 0 ) )
    {
        MessageBox("Не указано значение d3 (лев.).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d12.isNull() && (id == 0 ) )
    {
        MessageBox("Не указано значение d3' (лев.).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d14.isNull() && (id == 0 ) )
    {
        MessageBox("Не указано значение d4 (лев.).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_d16.isNull() && (id == 0 ) )
    {
        MessageBox("Не указано значение d4' (лев.).","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_h2.isNull() && (id == 0 || id == 1 ) )
    {
        MessageBox("Не указано значение заднего левого посадочного диаметра внутреннего кольца.","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    if( m_h4.isNull() && (id == 0 || id == 1 ) )
    {
        MessageBox("Не указано значение переднего левого посадочного диаметра внутреннего кольца.","Внимание", MB_OK | MB_ICONINFORMATION);
        return false;
    }
    return true;
}

void CDlgMntBuks::OnOK() 
{
    // Контроль вводимых параметров и занесение в базу

    // Контроль корректности даты
    char msg[512] = "";
    SYSTEMTIME st1, st2;
    ZeroMemory(&st1, sizeof(st1));
    ZeroMemory(&st2, sizeof(st2));
    int iKol1 = 0;
    int iKol2 = 0;
    iKol1 = m_Cb1.GetCurSel();
    iKol2 = m_Cb2.GetCurSel();

    if( !m_Date.isValid() )
    {
        MessageBox("Некорректно указана дата монтажа букс.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    m_Date.GetTime(&st1);
    GetLocalTime(&st2);
    if( SysDateCmp(st1, st2) > 0 )
    {
        MessageBox("Указанная дата монтажа еще не наступила.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( SysDateCmp(st1, Prih.stDatPost) < 0 )
    {
        MessageBox("Дата монтажа не может быть раньше даты поступления.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    
    // Проверим обязательные для всех признаков колец данные
    //Радиальный зазор в свободном состоянии
    if( !m_e1.isValid() || !m_e1.GetAsDouble() )
    {
        MessageBox("Некорректно указан задний правый радиальный зазор в свободном состоянии.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( CheckVal(m_e1.GetAsDouble(), RADZAZ_Z) )
    {
        sprintf(msg, "Значение заднего правого радиального зазора в свободном состоянии выходит за рамки допустимых значений\n(Макс.: %.2f)", vd_RADZAZ_Z);
        MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
        m_e1.SetFocus();
        return;
    }
    if( !m_e2.isValid() || !m_e2.GetAsDouble() )
    {
        MessageBox("Некорректно указан задний левый радиальный зазор в свободном состоянии.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( CheckVal(m_e2.GetAsDouble(), RADZAZ_Z) )
    {
        sprintf(msg, "Значение заднего левого радиального зазора в свободном состоянии выходит за рамки допустимых значений\n(макс: %.2f)", vd_RADZAZ_Z);
        MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
        m_e2.SetFocus();
        return;
    }
    if( !m_e3.isValid() || !m_e3.GetAsDouble() )
    {
        MessageBox("Некорректно указан передний правый радиальный зазор в свободном состоянии.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( CheckVal(m_e3.GetAsDouble(), RADZAZ_P) )
    {
        sprintf(msg, "Значение переднего правого радиального зазора в свободном состоянии выходит за рамки допустимых значений\n(макс: %.2f)", vd_RADZAZ_P);
        MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
        m_e3.SetFocus();        
        return;
    }
    if( !m_e4.isValid() || !m_e4.GetAsDouble() )
    {
        MessageBox("Некорректно указан передний левый радиальный зазор в свободном состоянии.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( CheckVal(m_e4.GetAsDouble(), RADZAZ_P) )
    {
        sprintf(msg, "Значение переднего левого радиального зазора в свободном состоянии выходит за рамки допустимых значений\n(макс: %.2f)", vd_RADZAZ_P);
        MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
        m_e4.SetFocus();        
        return;
    }
    // Подшипники
    if( m_Cb3.GetCurSel() < 0 )
    {
        MessageBox("Не указан завод для правого заднего подшипника", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( m_Cb4.GetCurSel() < 0 )
    {
        MessageBox("Не указан завод для левого заднего подшипника", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( m_Cb5.GetCurSel() < 0 )
    {
        MessageBox("Не указан тип правого заднего подшипника", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( m_Cb6.GetCurSel() < 0 )
    {
        MessageBox("Не указан тип левого заднего подшипника", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    // Передний
    if( m_Cb7.GetCurSel() < 0 )
    {
        MessageBox("Не указан завод для правого переднего подшипника", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( m_Cb8.GetCurSel() < 0 )
    {
        MessageBox("Не указан завод для левого переднего подшипника", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( m_Cb9.GetCurSel() < 0 )
    {
        MessageBox("Не указан тип правого переднего подшипника", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( m_Cb10.GetCurSel() < 0 )
    {
        MessageBox("Не указан тип левого переднего подшипника", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    // Смазка
    if( m_Cb11.GetCurSel() < 0 )
    {
        MessageBox("Не указана марка смазки", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( m_Cb12.GetCurSel() < 0 )
    {
        MessageBox("Не указано предприятие изготовления смазки", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    char cText[64] = "";
    if(!m_spart.GetWindowText(cText, 64))
    {
        MessageBox("Не указана партия смазки", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( strlen(cText) > 3 )
    {
        MessageBox("Слишком много символов в партии смазки (допускается не более 3)", "Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    // Минимальный осевой зазор
    if( !m_g1.isValid() || !m_g1.GetAsDouble() )
    {
        MessageBox("Некорректно указан задний правый минимальный осевой зазор.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( CheckVal(m_g1.GetAsDouble(), OS_ZAZ) )
    {
        sprintf(msg, "Значение заднего правого осевого зазора выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_OS_ZAZ1, vd_OS_ZAZ2);
        MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
        m_g1.SetFocus();
        return;
    }
    if( !m_g2.isValid() || !m_g2.GetAsDouble() )
    {
        MessageBox("Некорректно указан задний левый минимальный осевой зазор.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( CheckVal(m_g2.GetAsDouble(), OS_ZAZ) )
    {
        sprintf(msg, "Значение заднего левого осевого зазора выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_OS_ZAZ1, vd_OS_ZAZ2);
        MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
        m_g2.SetFocus();
        return;
    }
    if( !m_g3.isValid() || !m_g3.GetAsDouble() )
    {
        MessageBox("Некорректно указан передний правый минимальный осевой зазор.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( CheckVal(m_g3.GetAsDouble(), OS_ZAZ) )
    {
        sprintf(msg, "Значение переднего правого осевого зазора выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_OS_ZAZ1, vd_OS_ZAZ2);
        MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
        m_g3.SetFocus();
        return;
    }
    if( !m_g4.isValid() || !m_g4.GetAsDouble() )
    {
        MessageBox("Некорректно указан передний левый минимальный осевой зазор.","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( CheckVal(m_g4.GetAsDouble(), OS_ZAZ) )
    {
        sprintf(msg, "Значение переднего левого осевого зазора выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_OS_ZAZ1, vd_OS_ZAZ2);
        MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
        m_g4.SetFocus();
        return;
    }
    if( !m_FIO1.GetData() )
    {
        MessageBox("Не указана фамилия мастера","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( !m_FIO2.GetData() )
    {
        MessageBox("Не указана фамилия приемщика ОТК","Внимание", MB_OK | MB_ICONINFORMATION);
        return;
    }

    // Размеры оси и предподступичной части (мм)
    if( !m_d1.isNull() && m_d1.GetAsDouble() )
    {
        if( CheckVal(m_d1.GetAsDouble(), OS_D1) )
        {
            sprintf(msg, "Значение d1 (прав.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d1_1, vd_OS_d1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d1.SetFocus();
            return;
        }    
    }
    if( !m_d2.isNull() && m_d2.GetAsDouble() )
    {
        if( CheckVal(m_d2.GetAsDouble(), OS_D1) )
        {
            sprintf(msg, "Значение d1 (лев.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d1_1, vd_OS_d1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d2.SetFocus();
            return;
        }    
    }
    if( !m_d3.isNull() && m_d3.GetAsDouble() )
    {
        if( CheckVal(m_d3.GetAsDouble(), OS_D1) )
        {
            sprintf(msg, "Значение d1' (прав.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d1_1, vd_OS_d1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d3.SetFocus();
            return;
        }    
    }
    if( !m_d4.isNull() && m_d4.GetAsDouble() )
    {
        if( CheckVal(m_d4.GetAsDouble(), OS_D1) )
        {
            sprintf(msg, "Значение d1' (лев.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d1_1, vd_OS_d1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d4.SetFocus();
            return;
        }    
    }
    if( !m_d5.isNull() && m_d5.GetAsDouble() )
    {
        if( CheckVal(m_d5.GetAsDouble(), OS_D2) )
        {
            sprintf(msg, "Значение d2 (прав.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d2_1, vd_OS_d2_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d5.SetFocus();
            return;
        }    
    }
    if( !m_d6.isNull() && m_d6.GetAsDouble() )
    {
        if( CheckVal(m_d6.GetAsDouble(), OS_D2) )
        {
            sprintf(msg, "Значение d2 (лев.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d2_1, vd_OS_d2_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d6.SetFocus();
            return;
        }    
    }
    if( !m_d7.isNull() && m_d7.GetAsDouble() )
    {
        if( CheckVal(m_d7.GetAsDouble(), OS_D2) )
        {
            sprintf(msg, "Значение d2' (прав.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d2_1, vd_OS_d2_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d7.SetFocus();
            return;
        }    
    }
    if( !m_d8.isNull() && m_d8.GetAsDouble() )
    {
        if( CheckVal(m_d8.GetAsDouble(), OS_D2) )
        {
            sprintf(msg, "Значение d2' (лев.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d2_1, vd_OS_d2_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d8.SetFocus();
            return;
        }    
    }
    if( !m_d9.isNull() && m_d9.GetAsDouble() )
    {
        if( CheckVal(m_d9.GetAsDouble(), OS_D3) )
        {
            sprintf(msg, "Значение d3 (прав.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d3_1, vd_OS_d3_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d9.SetFocus();
            return;
        }    
    }
    if( !m_d10.isNull() && m_d10.GetAsDouble() )
    {
        if( CheckVal(m_d10.GetAsDouble(), OS_D3) )
        {
            sprintf(msg, "Значение d3 (лев.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d3_1, vd_OS_d3_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d10.SetFocus();
            return;
        }    
    }
    if( !m_d11.isNull() && m_d11.GetAsDouble() )
    {
        if( CheckVal(m_d11.GetAsDouble(), OS_D3) )
        {
            sprintf(msg, "Значение d3' (прав.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d3_1, vd_OS_d3_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d11.SetFocus();
            return;
        }    
    }
    if( !m_d12.isNull() && m_d12.GetAsDouble() )
    {
        if( CheckVal(m_d12.GetAsDouble(), OS_D3) )
        {
            sprintf(msg, "Значение d3' (лев.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d3_1, vd_OS_d3_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d12.SetFocus();
            return;
        }
    }
    if( !m_d13.isNull() && m_d13.GetAsDouble() )
    {
        if( CheckVal(m_d13.GetAsDouble(), OS_D4) )
        {
            sprintf(msg, "Значение d4 (прав.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d4_1, vd_OS_d4_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d13.SetFocus();
            return;
        }    
    }
    if( !m_d14.isNull() && m_d14.GetAsDouble() )
    {
        if( CheckVal(m_d14.GetAsDouble(), OS_D4) )
        {
            sprintf(msg, "Значение d4 (лев.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d4_1, vd_OS_d4_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d14.SetFocus();
            return;
        }
    }
    if( !m_d15.isNull() && m_d15.GetAsDouble() )
    {
        if( CheckVal(m_d15.GetAsDouble(), OS_D4) )
        {
            sprintf(msg, "Значение d4' (прав.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d4_1, vd_OS_d4_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d15.SetFocus();
            return;
        }
    }
    if( !m_d16.isNull() && m_d16.GetAsDouble() )
    {
        if( CheckVal(m_d16.GetAsDouble(), OS_D4) )
        {
            sprintf(msg, "Значение d4' (лев.) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_OS_d4_1, vd_OS_d4_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_d16.SetFocus();
            return;
        }
    }
    if( !m_n1.isNull() )
    {
        if( CheckVal(m_n1.GetAsDouble(), OVAL) )
        {
            sprintf(msg, "Значение наибольшей овальности шейки оси (прав.) выходит за рамки допустимых значений\n(макс: %.2f)", vd_OVAL);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            return;
        }        
    }
    if( !m_n2.isNull() )
    {
        if( CheckVal(m_n2.GetAsDouble(), OVAL) )
        {
            sprintf(msg, "Значение наибольшей овальности шейки оси (лев.) выходит за рамки допустимых значений\n(макс: %.2f)", vd_OVAL);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            return;
        }        
    }
    if( !m_n3.isNull() )
    {
        if( CheckVal(m_n3.GetAsDouble(), KONUS) )
        {
            sprintf(msg, "Значение наибольшей конусности шейки оси (прав.) выходит за рамки допустимых значений\n(макс: %.2f)", vd_KONUS);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            return;
        }        
    }
    if( !m_n4.isNull() )
    {
        if( CheckVal(m_n4.GetAsDouble(), KONUS) )
        {
            sprintf(msg, "Значение наибольшей конусности шейки оси (лев.) выходит за рамки допустимых значений\n(макс: %.2f)", vd_KONUS);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            return;
        }        
    }
    if( !m_n5.isNull() )
    {
        if( CheckVal(m_n5.GetAsDouble(), NP_LABK) )
        {
            sprintf(msg, "Значение натяга на посадку лабиринтного кольца (прав.) выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_NP_LABK1, vd_NP_LABK2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            return;
        }        
    }
    if( !m_n6.isNull() )
    {
        if( CheckVal(m_n6.GetAsDouble(), NP_LABK) )
        {
            sprintf(msg, "Значение натяга на посадку лабиринтного кольца (лев.) выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_NP_LABK1, vd_NP_LABK2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            return;
        }        
    }
    // Посадочные диаметры буксы
    if( !m_f1.isNull() )
    {
        if( CheckVal(m_f1.GetAsDouble(), BUK_D1) )
        {
            sprintf(msg, "Значение посадочного диаметра буксы D1 (прав.) выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_BUK_D1_1, vd_BUK_D1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_f1.SetFocus();
            return;
        }
    } else
    {
            MessageBox("Не указано значение посадочного диаметра буксы D1 (прав.)","Внимание", MB_OK | MB_ICONINFORMATION);
            return;
    }
    if( !m_f2.isNull() )
    {
        if( CheckVal(m_f2.GetAsDouble(), BUK_D1) )
        {
            sprintf(msg, "Значение посадочного диаметра буксы D1 (лев.) выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_BUK_D1_1, vd_BUK_D1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_f2.SetFocus();
            return;
        }
    } else
    {
            MessageBox("Не указано значение посадочного диаметра буксы D1 (лев.)","Внимание", MB_OK | MB_ICONINFORMATION);
            return;
    }

    if( !m_f3.isNull() )
    {
        if( CheckVal(m_f3.GetAsDouble(), BUK_D1) )
        {
            sprintf(msg, "Значение посадочного диаметра буксы D1' (прав.) выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_BUK_D1_1, vd_BUK_D1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_f3.SetFocus();
            return;
        }
    } else
    {
            MessageBox("Не указано значение посадочного диаметра буксы D1' (прав.)","Внимание", MB_OK | MB_ICONINFORMATION);
            return;
    }
    if( !m_f4.isNull() )
    {
        if( CheckVal(m_f4.GetAsDouble(), BUK_D1) )
        {
            sprintf(msg, "Значение посадочного диаметра буксы D1' (лев.) выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_BUK_D1_1, vd_BUK_D1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_f4.SetFocus();
            return;
        }
    } else
    {
            MessageBox("Не указано значение посадочного диаметра буксы D1' (лев.)","Внимание", MB_OK | MB_ICONINFORMATION);
            return;
    }
    if( !m_f5.isNull() )
    {
        if( CheckVal(m_f5.GetAsDouble(), BUK_D2) )
        {
            sprintf(msg, "Значение посадочного диаметра буксы D2 (прав.) выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_BUK_D2_1, vd_BUK_D2_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_f5.SetFocus();
            return;
        }
    } else
    {
            MessageBox("Не указано значение посадочного диаметра буксы D2 (прав.)","Внимание", MB_OK | MB_ICONINFORMATION);
            return;
    }
    if( !m_f6.isNull() )
    {
        if( CheckVal(m_f6.GetAsDouble(), BUK_D2) )
        {
            sprintf(msg, "Значение посадочного диаметра буксы D2 (лев.) выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_BUK_D2_1, vd_BUK_D2_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_f6.SetFocus();
            return;
        }
    } else
    {
            MessageBox("Не указано значение посадочного диаметра буксы D2 (лев.)","Внимание", MB_OK | MB_ICONINFORMATION);
            return;
    }
    if( !m_f7.isNull() )
    {
        if( CheckVal(m_f7.GetAsDouble(), BUK_D2) )
        {
            sprintf(msg, "Значение посадочного диаметра буксы D2' (прав.) выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_BUK_D2_1, vd_BUK_D2_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_f7.SetFocus();
            return;
        }
    } else
    {
            MessageBox("Не указано значение посадочного диаметра буксы D2' (прав.)","Внимание", MB_OK | MB_ICONINFORMATION);
            return;
    }
    if( !m_f8.isNull() )
    {
        if( CheckVal(m_f8.GetAsDouble(), BUK_D2) )
        {
            sprintf(msg, "Значение посадочного диаметра буксы D2' (лев.) выходит за рамки допустимых значений\n(мин: %.2f, макс: %.2f)", vd_BUK_D2_1, vd_BUK_D2_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_f8.SetFocus();
            return;
        }
    } else
    {
            MessageBox("Не указано значение посадочного диаметра буксы D2' (лев.)","Внимание", MB_OK | MB_ICONINFORMATION);
            return;
    }
    // посадочный диаметр внутреннего кольца
    if( !m_h1.isNull() )
    {
        if( CheckVal(m_h1.GetAsDouble(), VK_D1) )
        {   
            sprintf(msg, "Значение посадочного диаметра внутреннего кольца (правый-задний) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_VK_D1_1, vd_VK_D1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_h1.SetFocus();
            return;
        }
    }
    if( !m_h2.isNull() )
    {
        if( CheckVal(m_h2.GetAsDouble(), VK_D1) )
        {
            sprintf(msg, "Значение посадочного диаметра внутреннего кольца (левый-задний) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_VK_D1_1, vd_VK_D1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_h2.SetFocus();
            return;
        }
    }
    if( !m_h3.isNull() && iKol1 != 3)
    {
        if( CheckVal(m_h3.GetAsDouble(), VK_D1) )
        {
            sprintf(msg, "Значение посадочного диаметра внутреннего кольца (правый-передний) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_VK_D1_1, vd_VK_D1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_h3.SetFocus();
            return;
        }
    }
    if( !m_h4.isNull() && iKol2 != 3)
    {
        if( CheckVal(m_h4.GetAsDouble(), VK_D1) )
        {
            sprintf(msg, "Значение посадочного диаметра внутреннего кольца (левый-передний) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_VK_D1_1, vd_VK_D1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_h4.SetFocus();
            return;
        }
    }
    // Натяг на посадку внутреннего кольца
    if( !m_i1.isNull() )
    {
        if( CheckVal(m_i1.GetAsDouble(), NP_VK1) )
        {
            sprintf(msg, "Значение натяга на посадку внутреннего кольца (правый-задний) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_NP_VK1_1, vd_NP_VK1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_i1.SetFocus();
            return;
        }
    }
    //Натяг на посадку
    if( !m_i2.isNull() )
    {
        if( CheckVal(m_i2.GetAsDouble(), NP_VK1) )
        {
            sprintf(msg, "Значение натяга на посадку внутреннего кольца (левый-задний) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_NP_VK1_1, vd_NP_VK1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_i2.SetFocus();
            return;
        }
    }
    if( !m_i3.isNull() )
    {
        if( CheckVal(m_i3.GetAsDouble(), NP_VK1) )
        {
            sprintf(msg, "Значение натяга на посадку внутреннего кольца (правый-передний) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_NP_VK1_1, vd_NP_VK1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_i3.SetFocus();
            return;
        }
    }
    if( !m_i4.isNull() )
    {
        if( CheckVal(m_i4.GetAsDouble(), NP_VK1) )
        {
            sprintf(msg, "Значение натяга на посадку внутреннего кольца (левый-передний) выходит за рамки допустимых значений\n(мин: %.3f, макс: %.3f)", vd_NP_VK1_1, vd_NP_VK1_2);
            MessageBox(msg,"Внимание", MB_OK | MB_ICONINFORMATION);
            m_i4.SetFocus();
            return;
        }
    }

    if( !CheckWithRings() ) return;

    SYSTEMTIME st;
    char cMB_DAT[16] = "";
    char cMB_PRR[32], cMB_PRL[32];
    CString strOS_D;
	ZeroMemory(&st, sizeof(st));
    m_Date.GetTime(&st);
	st.wMilliseconds = 0;
    DateToSql(st, cMB_DAT);

    itoa(m_Cb1.GetCurSel() + 1, cMB_PRR, 10);
    itoa(m_Cb2.GetCurSel() + 1, cMB_PRL, 10);
    strOS_D = m_d1.GetString() + "," +
              m_d2.GetString() + "," +
              m_d3.GetString() + "," +
              m_d4.GetString() + "," +
              m_d5.GetString() + "," +
              m_d6.GetString() + "," +
              m_d7.GetString() + "," +
              m_d8.GetString() + "," +
              m_d9.GetString() + "," +
              m_d10.GetString() + "," +
              m_d11.GetString() + "," +
              m_d12.GetString() + "," +
              m_d13.GetString() + "," +
              m_d14.GetString() + "," +
              m_d15.GetString() + "," +
              m_d16.GetString();
    
    

    char cQ[1024] = "";
    char cPrm[1024] = "";
    CString s_pnum1, s_pnum2, s_pnum3, s_pnum4;
    CString s_pdat1, s_pdat2, s_pdat3, s_pdat4;
    CString s_smaz_part;
    m_pnum1.GetWindowText(s_pnum1);
    m_pnum2.GetWindowText(s_pnum2);
    m_pnum3.GetWindowText(s_pnum3);
    m_pnum4.GetWindowText(s_pnum4);
    m_pdat1.GetWindowText(s_pdat1);
    m_pdat2.GetWindowText(s_pdat2);
    m_pdat3.GetWindowText(s_pdat3);
    m_pdat4.GetWindowText(s_pdat4);
    m_spart.GetWindowText(s_smaz_part);

    char fm1[32], fm2[32], fm3[32], fm4[32];
    if( !m_FIO1.GetData() ) strcpy(fm1, "NULL");
    else itoa(m_FIO1.GetData(), fm1, 10);
    if( !m_FIO2.GetData() ) strcpy(fm2, "NULL");
    else itoa(m_FIO2.GetData(), fm2, 10);
    if( !m_FIO3.GetData() ) strcpy(fm3, "NULL");
    else itoa(m_FIO3.GetData(), fm3, 10);
    if( !m_FIO4.GetData() ) strcpy(fm4, "NULL");
    else itoa(m_FIO4.GetData(), fm4, 10);

    sprintf(cQ, "pTov_SetMontBuks %I64u, %s, %s, %s, %d, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d, %d, '%s', '%s', %d, %d, '%s', '%s', %d, %d, '%s', '%s', %d, %d, '%s', '%s', %d, %d, '%s', %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d",
            qwIZAP,
            cMB_DAT,
            cMB_PRL, cMB_PRR,
            m_PS.GetCheck(),
            strOS_D,
            m_n1.GetString(), m_n2.GetString(), m_n3.GetString(), m_n4.GetString(), m_n5.GetString(), m_n6.GetString(),
            m_e1.GetString(), m_e2.GetString(), m_e3.GetString(), m_e4.GetString(),
            m_f1.GetString(), m_f2.GetString(), m_f3.GetString(), m_f4.GetString(), m_f5.GetString(), m_f6.GetString(), m_f7.GetString(), m_f8.GetString(),
            m_Cb3.GetItemData(m_Cb3.GetCurSel()), m_Cb5.GetItemData(m_Cb5.GetCurSel()), s_pnum1, s_pdat1,
            m_Cb4.GetItemData(m_Cb4.GetCurSel()), m_Cb6.GetItemData(m_Cb6.GetCurSel()), s_pnum2, s_pdat2,
            m_Cb7.GetItemData(m_Cb7.GetCurSel()), m_Cb9.GetItemData(m_Cb9.GetCurSel()), s_pnum3, s_pdat3,
            m_Cb8.GetItemData(m_Cb8.GetCurSel()), m_Cb10.GetItemData(m_Cb10.GetCurSel()), s_pnum4, s_pdat4,
            m_Cb11.GetItemData(m_Cb11.GetCurSel()), m_Cb12.GetItemData(m_Cb12.GetCurSel()), s_smaz_part,
            m_g1.GetString(), m_g2.GetString(), m_g3.GetString(), m_g4.GetString(),
            m_h1.GetString(), m_h2.GetString(), m_h3.GetString(), m_h4.GetString(),
            m_i1.GetString(), m_i2.GetString(), m_i3.GetString(), m_i4.GetString(),
            fm1, fm2, fm3, fm4, Prih.dwPriznRas);
//    AfxMessageBox(cQ, MB_OK);
    long    Ind = 0;
    DBW.ExecSQL(cQ);
    DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &Prih.dwPriznRas, 4, &Ind);
    DBW.CloseCursor();
    DBW.ReallocHandle();
/*    
    if( Prih.dwPriznRas == 11 || Prih.dwPriznRas == 12 )
    {
        Prih.dwPriznRas++;
        sprintf(cQ, "pTov_SetMontBuksPriznRas %I64u, %u", qwIZAP, Prih.dwPriznRas);
        DBW.ExecSQL(cQ);
        DBW.CloseCursor();
        theApp.ReallocHandle();
    }
*/
	CDlgWithAccelerators::OnOK();
}

void CDlgMntBuks::OnMasterButton() 
{
	CDlgSpravKdr Dlg;
    Dlg.iFilter = 3;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
//    dwFIO1 = Dlg.dwFio;
    m_FIO1.SetData(Dlg.dwFio);
    m_FIO1.SetWindowText(Dlg.cFio);
}

void CDlgMntBuks::OnOTKButton() 
{
	CDlgSpravKdr Dlg;
    Dlg.iFilter = 4;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_FIO2.SetData(Dlg.dwFio);
    m_FIO2.SetWindowText(Dlg.cFio);	
}

void CDlgMntBuks::OnSles1Button() 
{
	CDlgSpravKdr Dlg;
    Dlg.iFilter = 6;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_FIO3.SetData(Dlg.dwFio);
    m_FIO3.SetWindowText(Dlg.cFio);		
}

void CDlgMntBuks::OnSles2Button() 
{
	CDlgSpravKdr Dlg;
    Dlg.iFilter = 6;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_FIO4.SetData(Dlg.dwFio);
    m_FIO4.SetWindowText(Dlg.cFio);			
}

void CDlgMntBuks::SetComboItem(CComboBox *b, CString strMask)
{
    if( !b ) return;
    CString strText;
    for( int i=0; i < b->GetCount() && i < 255; i++ )
    {
        b->GetLBText(i, strText);
        if( strText == strMask )
        {
            b->SetCurSel(i);
            return;
        }
    }
}

void CDlgMntBuks::OnPSClick() 
{
    CString strText;
    if( m_PS.GetCheck() )
    {
        SetComboItem(&m_Cb5, "42726Е2М");
        SetComboItem(&m_Cb9, "232726Е2М");
        SetComboItem(&m_Cb6, "42726Е2М");
        SetComboItem(&m_Cb10,"232726Е2М");
    } else
    {
        SetComboItem(&m_Cb5, "42726Л1М");
        SetComboItem(&m_Cb9, "232726Л1М");
        SetComboItem(&m_Cb6, "42726Л1М");
        SetComboItem(&m_Cb10,"232726Л1М");
    }
}

void CDlgMntBuks::OnChangePr_R() 
{
    switch( m_Cb1.GetCurSel() )
    {
    case 0:
        m_d1.EnableWindow();
        m_d3.EnableWindow();
        m_d5.EnableWindow();
        m_d7.EnableWindow();
        m_d9.EnableWindow();
        m_d11.EnableWindow();
        m_d13.EnableWindow();
        m_d15.EnableWindow();
        m_h1.EnableWindow();
        m_h3.EnableWindow();
    break;
    case 1:
        m_d1.EnableWindow();
        m_d3.EnableWindow();
        m_d5.EnableWindow();
        m_d7.EnableWindow();
        m_d9.EnableWindow(FALSE);
        m_d11.EnableWindow(FALSE);
        m_d13.EnableWindow(FALSE);
        m_d15.EnableWindow(FALSE);
        m_d9.SetWindowText("");
        m_d11.SetWindowText("");
        m_d13.SetWindowText("");
        m_d15.SetWindowText("");
        m_h1.EnableWindow();
        m_h3.EnableWindow();
        m_n5.SetWindowText("");
    break;
    case 2:
/*        m_d1.SetWindowText("");
        m_d3.SetWindowText("");*/
        m_d5.SetWindowText("");
        m_d7.SetWindowText("");
        m_d9.SetWindowText("");
        m_d11.SetWindowText("");
        m_d13.SetWindowText("");
        m_d15.SetWindowText("");

        m_d1.EnableWindow(TRUE);
        m_d3.EnableWindow(TRUE);
        m_d5.EnableWindow(FALSE);
        m_d7.EnableWindow(FALSE);
        m_d9.EnableWindow(FALSE);
        m_d11.EnableWindow(FALSE);
        m_d13.EnableWindow(FALSE);
        m_d15.EnableWindow(FALSE);

        m_n1.SetWindowText("");
        m_n3.SetWindowText("");
        m_n5.SetWindowText("");

//        m_h1.EnableWindow();
        m_h3.EnableWindow();        

        m_h1.EnableWindow(FALSE);        
        m_h1.SetWindowText("");	
/*
        m_h3.EnableWindow(FALSE);
        m_h3.SetWindowText("");	
*/
        m_n1.EnableWindow(FALSE);
        m_n3.EnableWindow(FALSE);
        m_n5.EnableWindow(FALSE);
    break;
    case 3:
        m_n1.SetWindowText("");	
        m_n3.SetWindowText("");	
        m_n5.SetWindowText("");

        m_n1.SetWindowText("");
        m_n3.SetWindowText("");
        m_n5.SetWindowText("");
        m_n1.EnableWindow(FALSE);
        m_n3.EnableWindow(FALSE);
        m_n5.EnableWindow(FALSE);

        m_d1.EnableWindow(FALSE);
        m_d3.EnableWindow(FALSE);
        m_d5.EnableWindow(FALSE);
        m_d7.EnableWindow(FALSE);
        m_d9.EnableWindow(FALSE);
        m_d11.EnableWindow(FALSE);
        m_d13.EnableWindow(FALSE);
        m_d15.EnableWindow(FALSE);
        m_h1.EnableWindow(FALSE);
        m_h3.EnableWindow(FALSE);

        m_d1.SetWindowText("");
        m_d3.SetWindowText("");
        m_d5.SetWindowText("");
        m_d7.SetWindowText("");
        m_d9.SetWindowText("");
        m_d11.SetWindowText("");
        m_d13.SetWindowText("");	
        m_d15.SetWindowText("");	
    break;
    }
}

void CDlgMntBuks::OnChangePr_L() 
{
    switch( m_Cb2.GetCurSel() )
    {
    case 0:
        m_d2.EnableWindow();
        m_d4.EnableWindow();
        m_d6.EnableWindow();
        m_d8.EnableWindow();
        m_d10.EnableWindow();
        m_d12.EnableWindow();
        m_d14.EnableWindow();
        m_d16.EnableWindow();
        m_h2.EnableWindow();
        m_h4.EnableWindow();
    break;
    case 1:
        m_d2.EnableWindow();
        m_d4.EnableWindow();
        m_d6.EnableWindow();
        m_d8.EnableWindow();
        m_d10.EnableWindow(FALSE);
        m_d12.EnableWindow(FALSE);
        m_d14.EnableWindow(FALSE);
        m_d16.EnableWindow(FALSE);
        m_d10.SetWindowText("");
        m_d12.SetWindowText("");
        m_d14.SetWindowText("");
        m_d16.SetWindowText("");
        m_h2.EnableWindow();
        m_h4.EnableWindow();
        m_n6.SetWindowText("");	
    break;
    case 2:
/*        m_d2.SetWindowText("");
        m_d4.SetWindowText("");*/
        m_d6.SetWindowText("");
        m_d8.SetWindowText("");
        m_d10.SetWindowText("");
        m_d12.SetWindowText("");
        m_d14.SetWindowText("");
        m_d16.SetWindowText("");

        m_d2.EnableWindow();
        m_d4.EnableWindow();
        m_d6.EnableWindow(FALSE);
        m_d8.EnableWindow(FALSE);
        m_d10.EnableWindow(FALSE);
        m_d12.EnableWindow(FALSE);
        m_d14.EnableWindow(FALSE);
        m_d16.EnableWindow(FALSE);

        m_n2.SetWindowText("");	
        m_n4.SetWindowText("");	
        m_n6.SetWindowText("");
//        m_h2.EnableWindow();
        m_h4.EnableWindow();


        m_h2.EnableWindow(FALSE);      
        m_h2.SetWindowText("");	
/*
        m_h4.EnableWindow(FALSE);
        m_h4.SetWindowText("");	
*/
/*
        m_n2.EnableWindow(FALSE);
        m_n4.EnableWindow(FALSE);
        m_n6.EnableWindow(FALSE);*/
    break;
    case 3:
        m_n2.SetWindowText("");	
        m_n4.SetWindowText("");	
        m_n6.SetWindowText("");
/*
        m_n2.SetWindowText("");
        m_n4.SetWindowText("");
        m_n6.SetWindowText("");
        m_n2.EnableWindow(FALSE);
        m_n4.EnableWindow(FALSE);
        m_n6.EnableWindow(FALSE);*/

        m_d2.EnableWindow(FALSE);
        m_d4.EnableWindow(FALSE);
        m_d6.EnableWindow(FALSE);
        m_d8.EnableWindow(FALSE);
        m_d10.EnableWindow(FALSE);
        m_d12.EnableWindow(FALSE);
        m_d14.EnableWindow(FALSE);
        m_d16.EnableWindow(FALSE);
        m_h2.EnableWindow(FALSE);
        m_h4.EnableWindow(FALSE);

        m_d2.SetWindowText("");
        m_d4.SetWindowText("");
        m_d6.SetWindowText("");
        m_d8.SetWindowText("");
        m_d10.SetWindowText("");
        m_d12.SetWindowText("");
        m_d14.SetWindowText("");	
        m_d16.SetWindowText("");	
/*
        m_n2.EnableWindow(FALSE);
        m_n4.EnableWindow(FALSE);
        m_n6.EnableWindow(FALSE);
*/

    break;
    }
}


void CDlgMntBuks::RefreshCalculated()
{
    // Рассчетные значения
    double
    d1 = m_d1.GetAsDouble(),
    d2 = m_d2.GetAsDouble(),
    d3 = m_d3.GetAsDouble(),
    d4 = m_d4.GetAsDouble(),
    d5 = m_d5.GetAsDouble(),
    d6 = m_d6.GetAsDouble(),
    d7 = m_d7.GetAsDouble(),
    d8 = m_d8.GetAsDouble(),
    d9 = m_d9.GetAsDouble(),
    d10 = m_d10.GetAsDouble(),
    d11 = m_d11.GetAsDouble(),
    d12 = m_d12.GetAsDouble(),
    d13 = m_d13.GetAsDouble(),
    d14 = m_d14.GetAsDouble(),
    d15 = m_d15.GetAsDouble(),
    d16 = m_d16.GetAsDouble();

    m_n1.SetAbsMaxValue(d1 - d3, d5 - d7);    
    m_n2.SetAbsMaxValue(d2 - d4, d6 - d8);
    m_n3.SetAbsMaxValue(d1 - d5, d3 - d7);
    m_n4.SetAbsMaxValue(d2 - d6, d4 - d8);
    m_n5.SetAbsValue((d9 + d11)/2 - (d13 - d15)/2);
    m_n6.SetAbsValue((d10 + d12)/2 - (d14- d16)/2);
}

void CDlgMntBuks::CalcLabRing(int Side)
{
    double
    d9 = m_d9.GetAsDouble(),
    d10 = m_d10.GetAsDouble(),
    d11 = m_d11.GetAsDouble(),
    d12 = m_d12.GetAsDouble(),
    d13 = m_d13.GetAsDouble(),
    d14 = m_d14.GetAsDouble(),
    d15 = m_d15.GetAsDouble(),
    d16 = m_d16.GetAsDouble();
    if( Side )
    {
        m_n5.SetWindowText("");
        if( d15 == 0 || d13 == 0 || d11 == 0 || d9 == 0 ) return;
        m_n5.SetValue((d9 + d11)/2 - (d13 + d15)/2);
    } else
    {
        m_n6.SetWindowText("");
        if( d16 == 0 || d14 == 0 || d12 == 0 || d10 == 0 ) return;
        m_n6.SetValue((d10 + d12)/2 - (d14 + d16)/2);
    }
}

void CDlgMntBuks::CalcConus(int Side) //0 - left, 1 - right
{
    double
    d1 = m_d1.GetAsDouble(),
    d2 = m_d2.GetAsDouble(),
    d3 = m_d3.GetAsDouble(),
    d4 = m_d4.GetAsDouble(),
    d5 = m_d5.GetAsDouble(),
    d6 = m_d6.GetAsDouble(),
    d7 = m_d7.GetAsDouble(),
    d8 = m_d8.GetAsDouble();
    if( Side )
    {
        m_n3.SetWindowText("");
        if( d1 == 0 || d5 == 0 || d3 == 0 || d7 == 0 ) return;
        m_n3.SetAbsMaxValue(d1 - d5, d3 - d7);
    } else
    {
        m_n4.SetWindowText("");
        if( d8 == 0 || d6 == 0 || d4 == 0 || d2 == 0 ) return;
        m_n4.SetAbsMaxValue(d2 - d6, d4 - d8);
    }
}

void CDlgMntBuks::CalcOval(int Side)
{
    if( Side ) m_n1.SetWindowText("");
    else m_n2.SetWindowText("");
    if(Side && (m_d1.isNull() || m_d3.isNull()) && (m_d5.isNull() || m_d7.isNull()) )
    {
        return;
    }
    if(!Side &&(m_d2.isNull() || m_d4.isNull()) && (m_d6.isNull() || m_d8.isNull()) )
    {
        return;
    }
    double
    d1 = m_d1.GetAsDouble(),
    d2 = m_d2.GetAsDouble(),
    d3 = m_d3.GetAsDouble(),
    d4 = m_d4.GetAsDouble(),
    d5 = m_d5.GetAsDouble(),
    d6 = m_d6.GetAsDouble(),
    d7 = m_d7.GetAsDouble(),
    d8 = m_d8.GetAsDouble();
    char cText[64] = "";
    if( Side )
    {
        if( m_d1.isNull() || m_d3.isNull() )
        {
            m_n1.SetAbsValue(d5 - d7);
        } else
        if( m_d5.isNull() || m_d7.isNull() )
        {
            m_n1.SetAbsValue(d1 - d3);
        } else
            m_n1.SetAbsMaxValue(d1 - d3, d5 - d7);
    } else
    {
        if( m_d2.isNull() || m_d4.isNull() )
        {
            m_n2.SetAbsValue(d6 - d8);
        } else
        if( m_d6.isNull() || m_d8.isNull() )
        {
            m_n2.SetAbsValue(d2 - d4);
        } else
            m_n2.SetAbsMaxValue(d2 - d4, d6 - d8);
    }

}
// Вычисление натяга на посадку
void CDlgMntBuks::CalcIntRingP(int Side)
{
    double
    d1 = m_d1.GetAsDouble(),
    d2 = m_d2.GetAsDouble(),
    d3 = m_d3.GetAsDouble(),
    d4 = m_d4.GetAsDouble(),
    vk_pl = m_h4.GetAsDouble(),
    vk_pr = m_h3.GetAsDouble();

    if( Side )
    {
        m_i3.SetWindowText("");
        if( d1 == 0 || d3 == 0 || vk_pr == 0 ) return;
        m_i3.SetValue((d1 + d3)/2 - vk_pr);
    } else
    {
        m_i4.SetWindowText("");
        if( d2 == 0 || d4 == 0 || vk_pl == 0 ) return;
        m_i4.SetValue((d2 + d4)/2 - vk_pl);
    }
}

void CDlgMntBuks::CalcIntRingZ(int Side)
{
    double
    d5 = m_d5.GetAsDouble(),
    d6 = m_d6.GetAsDouble(),
    d7 = m_d7.GetAsDouble(),
    d8 = m_d8.GetAsDouble(),
    vk_zl = m_h2.GetAsDouble(),
    vk_zr = m_h1.GetAsDouble();

    if( Side )
    {
        m_i1.SetWindowText("");
        if( d5 == 0 || d7 == 0 || vk_zr == 0 ) return;
        m_i1.SetValue((d5 + d7)/2 - vk_zr);
    } else
    {
        m_i2.SetWindowText("");
        if( d6 == 0 || d8 == 0 || vk_zl == 0 ) return;
        m_i2.SetValue((d6 + d8)/2 - vk_zl);
    }
}

void CDlgMntBuks::OnChange_d1R() 
{
    CalcOval(1);
    CalcConus(1);
    CalcIntRingP(1);
}

void CDlgMntBuks::OnChange_d2R() 
{
    CalcOval(1);
    CalcConus(1);
    CalcIntRingZ(1);
}

void CDlgMntBuks::OnChange_d1L() 
{
    CalcOval(0);
    CalcConus(0);
    CalcIntRingP(0);
}

void CDlgMntBuks::OnChange_d2L() 
{
    CalcOval(0);
    CalcConus(0);
    CalcIntRingZ(0);
}

void CDlgMntBuks::OnChange_Recall() 
{
    CalcLabRing(1);
}


void CDlgMntBuks::OnChange_Recall_Left() 
{
    CalcLabRing(0);
}

void CDlgMntBuks::OnRingVn_ZR() 
{
    CalcIntRingZ(1);
}

void CDlgMntBuks::OnRingVn_ZL() 
{
    CalcIntRingZ(0);
}

void CDlgMntBuks::OnRingVn_PR() 
{
    CalcIntRingP(1);
}

void CDlgMntBuks::OnRingVn_PL() 
{
    CalcIntRingP(0);
}

//DEL void CDlgMntBuks::OnArrowUp() 
//DEL {
//DEL 	
//DEL }

void CDlgMntBuks::OnArrowUp() 
{
	// TODO: Add your command handler code here
	
}

void CDlgMntBuks::OnCancel() 
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;		
	CDlgWithAccelerators::OnCancel();
}
