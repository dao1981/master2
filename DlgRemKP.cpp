// DlgRemKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRemKP.h"
#include "DlgSpravSmp.h"
#include "DlgSpravKdr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDlgRemKP dialog

DWORD p_dwFIOBuffer[20];
DWORD dwCount = 0;

CDlgRemKP::CDlgRemKP(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgRemKP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRemKP)
	m_strNKP = _T("");
	m_strTKP = _T("");
	//}}AFX_DATA_INIT
    dwKNPr = dwKNObt = 0;
    cFamSles1[0]=cSBU[0] = cKN[0] = cDVR[0] = cDNG[0] = 0;
    iVR = 0;

    m_EdF1.SetMode(5);
    DBW.FillEmplArray(m_EdF1.lpEmpl, 21);
    DWORD gfg = m_EdF1.GetData();
    m_EdF2.SetMode(5);
    DBW.FillEmplArray(m_EdF2.lpEmpl, 22);
    m_EdF3.SetMode(5);
    DBW.FillEmplArray(m_EdF3.lpEmpl, 23);
    m_EdF4.SetMode(5);
    DBW.FillEmplArray(m_EdF4.lpEmpl, 24);
    m_EdF5.SetMode(5);
    DBW.FillEmplArray(m_EdF5.lpEmpl, 25);
    m_EdF6.SetMode(5);
    DBW.FillEmplArray(m_EdF6.lpEmpl, 26);
    m_EdF7.SetMode(5);
    DBW.FillEmplArray(m_EdF7.lpEmpl, 27);
    m_EdF8.SetMode(5);
    DBW.FillEmplArray(m_EdF8.lpEmpl, 28);

    m_EdOsv.SetMode(5);
    DBW.FillEmplArray(m_EdOsv.lpEmpl, 7);

    m_Ed13.SetMode(5);
    DBW.FillEmplArray(m_Ed13.lpEmpl, 5);
    m_date1.iMode = 1;

}


void CDlgRemKP::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRemKP)
	DDX_Control(pDX, IDC_EDIT21, m_date1);
	DDX_Control(pDX, IDC_EDIT90, m_Ed13);
	DDX_Control(pDX, IDC_EDIT91, m_EdOsv);
	DDX_Control(pDX, IDC_EDIT9, m_EdF4);
	DDX_Control(pDX, IDC_EDIT88, m_EdF8);
	DDX_Control(pDX, IDC_EDIT87, m_EdF7);
	DDX_Control(pDX, IDC_EDIT86, m_EdF5);
	DDX_Control(pDX, IDC_EDIT8, m_EdF3);
	DDX_Control(pDX, IDC_EDIT78, m_EdF6);
	DDX_Control(pDX, IDC_EDIT16, m_EdF2);
	DDX_Control(pDX, IDC_EDIT3, m_EdF1);
	DDX_Control(pDX, IDC_BUTTON23, m_But7);

//	DDX_Control(pDX, IDC_BUTTON22, m_But6);
//	DDX_Control(pDX, IDC_BUTTON21, m_But5);
//	DDX_Control(pDX, IDC_BUTTON19, m_But3);
//	DDX_Control(pDX, IDC_BUTTON20, m_But4);

	DDX_Control(pDX, IDC_EDIT5, m_Ed4);
	DDX_Control(pDX, IDC_EDIT7, m_Ed3);
	DDX_Control(pDX, IDC_EDIT2, m_Ed2);
	DDX_Control(pDX, IDC_EDIT1, m_Ed1);
//	DDX_Control(pDX, IDC_EDIT46, m_Ed12);
//	DDX_Control(pDX, IDC_EDIT89, m_Ed11);
//	DDX_Control(pDX, IDC_EDIT83, m_Ed10);
//	DDX_Control(pDX, IDC_EDIT76, m_Ed9);
//	DDX_Control(pDX, IDC_EDIT14, m_Ed8);
//	DDX_Control(pDX, IDC_EDIT82, m_Ed7);
//	DDX_Control(pDX, IDC_EDIT4, m_Ed6);
//	DDX_Control(pDX, IDC_EDIT6, m_Ed5);
	DDX_Control(pDX, IDC_COMBO4, m_Combo4);
	DDX_Control(pDX, IDC_COMBO3, m_Combo3);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_COMBO6, m_CbM110);
	DDX_Text(pDX, IDC_EDIT19, m_strNKP);
	DDX_Text(pDX, IDC_EDIT20, m_strTKP);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRemKP, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgRemKP)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON23, OnButtonSles)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3F1)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4F2)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5F3)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6F4)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7F5)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8F6)
	ON_BN_CLICKED(IDC_BUTTON17, OnButton17F7)
	ON_BN_CLICKED(IDC_BUTTON18, OnButton18F7)
	ON_BN_CLICKED(IDC_BUTTON24, OnButtonOsv)
	ON_BN_CLICKED(IDOK, OnAddToBase)
	ON_CBN_EDITCHANGE(IDC_COMBO2, OnChangeVR)
	ON_CBN_EDITCHANGE(IDC_COMBO1, OnChangeVidRem)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnSelchangeCombo1)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT7, OnChangeEdit7)
	ON_COMMAND(ID_SHIFT_F2, OnShiftF2)
	ON_COMMAND(ID_SHIFT_F3, OnShiftF3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

void CDlgRemKP::EnableRabot(BOOL f = TRUE)
{
/*    m_Ed5.EnableWindow(f);
    m_Ed6.EnableWindow(f);
    m_Ed7.EnableWindow(f);
    m_Ed8.EnableWindow(f);
    m_Ed9.EnableWindow(f);
    m_Ed10.EnableWindow(f);
    m_Ed11.EnableWindow(f);
    m_Ed12.EnableWindow(f);
    m_Ed13.EnableWindow(f);*/
/*    
    m_But3.EnableWindow(f);
    m_But4.EnableWindow(f);
    m_But5.EnableWindow(f);
    m_But6.EnableWindow(f);
    m_But7.EnableWindow(f);
*/
}

void CDlgRemKP::IniForm()
{    
    // Вывод на форму ранее введенной информации]
    char cQ[512] = "";
    char cText[64] = "";
    long Ind = 0;
    m_Combo2.SetCurSel(0);
    m_Combo3.SetCurSel(0);    
    iVR = 0;
	/*
    if( Prih.dwPriznRas == 11 || Prih.dwPriznRas == 12 || 
        Prih.dwPriznRas == 21 || Prih.dwPriznRas == 22 )
    {
	*/
        sprintf(cQ, "pTov_GetRemKP %I64u", Prih.qwIZAP);
        DBW.ExecSQL(cQ);
        if( DBW.Fetch() == SQL_NO_DATA )
        {
 /*           MessageBox("Не найдена информация о ремонте КП!", "Внимание", MB_OK | MB_ICONINFORMATION);
            DBW.CloseCursor();
            sprintf(cQ, "pTov_UpdatePriznRas %I64u", Prih.qwIZAP);
            DBW.ExecSQL(cQ);*/
            DBW.CloseCursor();
        } else
        {
            // Дата ремонта
            SYSTEMTIME tm;
            DWORD dwNum = 0;            
            mgSQLGetSysDate(1, &tm, &Ind);
            m_date1.SetTime(&tm);
            // Вид ремонта
            DBW.GetData( 2, SQL_C_ULONG, &dwNum, 4, &Ind);
            m_Combo1.SetCurSel(dwNum - 1);
            iVR = dwNum;
            if( iVR == 1 ) 
            {
                EnableRabot();
            }
            // Фамилии
// Osv
            DBW.GetData( 3, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_EdOsv.SetData(dwNum);
                DBW.GetData( 4, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_EdOsv.SetWindowText(cText);
            }
// Sred
            DBW.GetData( 5, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_EdF4.SetData(dwNum);
                DBW.GetData( 6, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_EdF4.SetWindowText(cText);
            }
// Obod
            DBW.GetData( 7, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                DBW.GetData( 8, SQL_C_CHAR, cText, 64, &Ind);
                m_EdF7.SetData(dwNum);
                if( Ind != -1 ) m_EdF7.SetWindowText(cText);
            }
// Shk
            DBW.GetData( 9, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_EdF1.SetData(dwNum);
                DBW.GetData( 10, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_EdF1.SetWindowText(cText);
            }
// Podst
            DBW.GetData( 11, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_EdF2.SetData(dwNum);
                DBW.GetData( 12, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_EdF2.SetWindowText(cText);
            }
// VNK
            DBW.GetData( 13, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_EdF3.SetData(dwNum);
                DBW.GetData( 14, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_EdF3.SetWindowText(cText);
            }
// STOP
            DBW.GetData( 15, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_EdF5.SetData(dwNum);
                DBW.GetData( 16, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_EdF5.SetWindowText(cText);
            }
// Disk
            DBW.GetData( 17, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_EdF6.SetData(dwNum);
                DBW.GetData( 18, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_EdF6.SetWindowText(cText);
            }
// Greb
            DBW.GetData( 19, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_EdF8.SetData(dwNum);
                DBW.GetData( 20, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_EdF8.SetWindowText(cText);
            }
// Sles1
            DBW.GetData( 21, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_Ed13.SetData(dwNum);
                DBW.GetData( 22, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_Ed13.SetWindowText(cText);
            }
			DBW.GetData( 23, SQL_C_ULONG, &dwNum, 4, &Ind);
			if( Ind != -1 && dwNum == 1)
				m_CbM110.SetCurSel(1);
			else m_CbM110.SetCurSel(0);
				
// Выполненные работы
/*            DBW.GetData( 23, SQL_C_ULONG, &dwRab[0], 4, &Ind);
            if( Ind != -1 )
            {
                DBW.GetData( 24, SQL_C_CHAR, cText, 16, &Ind);
                if( Ind != -1 ) m_Ed5.SetWindowText(cText);
                DBW.GetData( 25, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_Ed6.SetWindowText(cText);             
            }
            DBW.GetData( 26, SQL_C_ULONG, &dwRab[1], 4, &Ind);
            if( Ind != -1 )
            {
                DBW.GetData( 27, SQL_C_CHAR, cText, 16, &Ind);
                if( Ind != -1 ) m_Ed9.SetWindowText(cText);
                DBW.GetData( 28, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_Ed10.SetWindowText(cText);
            }
            DBW.GetData( 29, SQL_C_ULONG, &dwRab[2], 4, &Ind);
            if( Ind != -1 )
            {
                DBW.GetData( 30, SQL_C_CHAR, cText, 16, &Ind);
                if( Ind != -1 ) m_Ed7.SetWindowText(cText);
                DBW.GetData( 31, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_Ed8.SetWindowText(cText);
            }
            DBW.GetData( 32, SQL_C_ULONG, &dwRab[3], 4, &Ind);
            if( Ind != -1 )
            {
                DBW.GetData( 33, SQL_C_CHAR, cText, 16, &Ind);
                if( Ind != -1 ) m_Ed11.SetWindowText(cText);
                DBW.GetData( 34, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_Ed12.SetWindowText(cText);
            }*/
// Причина обточки и прочий дефект
            DBW.GetData( 35, SQL_C_ULONG, &dwKNPr, 4, &Ind);
            if( Ind != -1 ) //Прочий
            {
                DBW.GetData( 36, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_Ed3.SetWindowText(cText);
                DBW.GetData( 37, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_Ed4.SetWindowText(cText);                
            }
            DBW.GetData( 38, SQL_C_ULONG, &dwKNObt, 4, &Ind);
            if( Ind != -1 ) // Обточка
            {
                DBW.GetData( 39, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_Ed1.SetWindowText(cText);
                DBW.GetData( 40, SQL_C_CHAR, cText, 64, &Ind);
                if( Ind != -1 ) m_Ed2.SetWindowText(cText);
            }
// Состояние буксового узла
            DBW.GetData( 41, SQL_C_ULONG, &dwSBU, 4, &Ind);
            if( Ind != -1 )
            {
                m_Combo4.SetCurSel(dwSBU);
            }
            else
                dwSBU = 3;
// Дефект по восстановлению резьбы
            DBW.GetData( 42, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
//                m_Combo2.SetCurSel(dwNum);
                for( int x=0; x < m_Combo2.GetCount(); x++ )
                {
                    if( m_Combo2.GetItemData(x) == dwNum ) 
                    {
                        m_Combo2.SetCurSel(x);
                        break;
                    }
                }
            }
// Дефект по наплавке гребня
            DBW.GetData( 43, SQL_C_ULONG, &dwNum, 4, &Ind);
            if( Ind != -1 )
            {
                m_Combo3.SetCurSel(dwNum);
            }
        }
        DBW.CloseCursor();
		/*
    }

    if( Prih.dwPriznRas < 10 )
    {
        if( Prih.dwTREB_REM == 1 || Prih.dwTREB_REM == 2 )
        {
            m_Combo1.SetCurSel(Prih.dwTREB_REM - 1);
            iVR = Prih.dwTREB_REM;
        }
        if( Prih.dwTREB_REM == 1 ) EnableRabot();
        // Неисправность
        if( Prih.cNeisp_KL[0] )
        {
            DWORD dwNum = 0;
            DWORD dwNum1 = 0;
            sprintf(cQ, "pTov_GetNeispKPbyKodKl %s", Prih.cNeisp_KL);
            strcpy(cKN, Prih.cNeisp_KL);
            DBW.ExecSQL(cQ);
            DBW.Fetch();
            DBW.GetData( 2, SQL_C_ULONG, &dwNum1, 4, &Ind);
            DBW.GetData( 3, SQL_C_CHAR, cText, 16, &Ind);
            DBW.GetData( 4, SQL_C_ULONG, &dwNum, 4, &Ind);
            
            DBW.CloseCursor();
            DBW.ReallocHandle();

            if( dwNum1 == 1 )
            {
                m_Ed1.SetWindowText(cKN);
                m_Ed2.SetWindowText(cText);
                dwKNObt = dwNum;
            }
            else
            {
                m_Ed3.SetWindowText(cKN);
                m_Ed4.SetWindowText(cText);
                dwKNPr = dwNum;
            }
        }        
    }
	*/
}
/////////////////////////////////////////////////////////////////////////////
// CDlgRemKP message handlers

BOOL CDlgRemKP::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
    EnableRabot(FALSE);
	m_CbM110.SetCurSel(0);
    bStarted = FALSE;
    DBW.FillComboWithOsRezRepairs(&m_Combo2);
	m_date1.InitDate();
    IniForm();
    bStarted = TRUE;
    m_Ed2.ModifyStyle(0, WS_DISABLED);
    m_Ed4.ModifyStyle(0, WS_DISABLED);    
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

// Вызов справочника неисправностей КП
void CDlgRemKP::OnButton2() 
{
    CDlgSpravSmp Dlg;
    Dlg.Style = 1;
    Dlg.DlgMode = 111;
    if( Dlg.DoModal() == IDCANCEL )
    {
        m_Ed3.SetWindowText("");
        m_Ed4.SetWindowText("");
        dwKNPr = 0;
        return;
    }
    m_Ed3.SetWindowText(Dlg.cRet);
    m_Ed4.SetWindowText(Dlg.c_retText2);
    dwKNPr = Dlg.dwRet;
}

// Вызов справочника неисправностей КП для обточки
void CDlgRemKP::OnButton1() 
{
	CDlgSpravSmp Dlg;
    Dlg.Style = 1;
    Dlg.DlgMode = 110;
    if( Dlg.DoModal() == IDCANCEL ) 
    {
        m_Ed1.SetWindowText("");
        m_Ed2.SetWindowText("");
        dwKNObt = 0;
        return;
    }
    m_Ed1.SetWindowText(Dlg.cRet);
    m_Ed2.SetWindowText(Dlg.c_retText2);
    dwKNObt = Dlg.dwRet;
}

void CDlgRemKP::OnButtonSles() 
{
    CDlgSpravKdr    Dlg;
    Dlg.iFilter = 5;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_Ed13.SetWindowText(Dlg.cFio);
    m_Ed13.SetData(Dlg.dwFio);
}

void CDlgRemKP::CallKadrDlg(int Bn)
{
    CDlgSpravKdr    Dlg;
    Dlg.DlgMode = 1;
    switch (Bn)
    {
    case 1: Dlg.iFilter = 21; break;
    case 2: Dlg.iFilter = 22; break;
    case 3: Dlg.iFilter = 23; break;
    case 4: Dlg.iFilter = 24; break;
    case 5: Dlg.iFilter = 25; break;
    case 6: Dlg.iFilter = 26; break;
    case 7: Dlg.iFilter = 27; break;
    case 8: Dlg.iFilter = 28; break;
    case 9: Dlg.iFilter = 7; break;
    }

    if( Dlg.DoModal() == IDCANCEL ) return;
    
    switch (Bn)
    {
    case 1: m_EdF1.SetWindowText(Dlg.cFio); m_EdF1.SetData(Dlg.dwFio); break;
    case 2: m_EdF2.SetWindowText(Dlg.cFio); m_EdF2.SetData(Dlg.dwFio); break;
    case 3: m_EdF3.SetWindowText(Dlg.cFio); m_EdF3.SetData(Dlg.dwFio); break;
    case 4: m_EdF4.SetWindowText(Dlg.cFio); m_EdF4.SetData(Dlg.dwFio); break;
    case 5: m_EdF5.SetWindowText(Dlg.cFio); m_EdF5.SetData(Dlg.dwFio); break;   
    case 6: m_EdF6.SetWindowText(Dlg.cFio); m_EdF6.SetData(Dlg.dwFio); break;
    case 7: m_EdF7.SetWindowText(Dlg.cFio); m_EdF7.SetData(Dlg.dwFio); break;
    case 8: m_EdF8.SetWindowText(Dlg.cFio); m_EdF8.SetData(Dlg.dwFio); break;
    case 9: m_EdOsv.SetWindowText(Dlg.cFio); m_EdOsv.SetData(Dlg.dwFio); break;
    }
    
}

void CDlgRemKP::OnButton3F1() 
{
    CallKadrDlg(1);	
}

void CDlgRemKP::OnButton4F2() 
{
    CallKadrDlg(2);
}

void CDlgRemKP::OnButton5F3() 
{
    CallKadrDlg(3);
}

void CDlgRemKP::OnButton6F4() 
{
    CallKadrDlg(4);
}

void CDlgRemKP::OnButton7F5() 
{
    CallKadrDlg(5);
}

void CDlgRemKP::OnButton8F6() 
{
    CallKadrDlg(6);
}

void CDlgRemKP::OnButton17F7() 
{
    CallKadrDlg(7);
}

void CDlgRemKP::OnButton18F7() 
{
    CallKadrDlg(8);
}

void CDlgRemKP::OnButtonOsv() 
{
	CallKadrDlg(9);
}

// Запись введенных параметров в базу
void CDlgRemKP::OnAddToBase() 
{
    // Вид ремонта
	int v = 0;
	int n = 1;
	if( (v = m_Combo1.GetCurSel()) < 0 )
    {
        MessageBox("Не указан вид ремонта. Повторите ввод!", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
    // Дата ремонта
    SYSTEMTIME ts;
    ZeroMemory(&ts, sizeof(ts));
    m_date1.GetTime(&ts);
    if( SysDateCmp(Prih.stDatPost, ts) > 0 )
    {
        MessageBox("Дата ремонта не может быть раньше даты поступления.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
	if( Prih.cNeisp_KL[0] == '1' )
	{
		n = 0;
	}
    // Проверка правильности указания фамилий
    if( !m_EdOsv.GetData() )
    {
        MessageBox("Не указана фамилия проводившего освидетельствование.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }

	if( v && !m_EdF1.GetData() && n )
    {
        MessageBox("Не указана фамилия проводившего дефектоскопию шейки.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
    if( v && !m_EdF2.GetData() && n  )
    {
        MessageBox("Не указана фамилия проводившего дефектоскопию подступичной части оси.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
    if( v && !m_EdF3.GetData() )
    {
        MessageBox("Не указана фамилия проводившего дефектоскопию внутренних колец.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
    if( !m_EdF4.GetData() && n  )
    {
        MessageBox("Не указана фамилия проводившего дефектоскопию средней части оси.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
	/*
    if( !m_EdF5.GetData() )
    {
        MessageBox("Не указана фамилия проводившего дефектоскопию стопорных планок.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
	*/
    if( !m_EdF6.GetData() && n  )
    {
        MessageBox("Не указана фамилия проводившего дефектоскопию дисков.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
    if( !m_EdF7.GetData() && n  )
    {
        MessageBox("Не указана фамилия проводившего дефектоскопию ободов.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
    if( v && !m_EdF8.GetData() && m_Combo3.GetCurSel() > 0  && n )
    {
        MessageBox("Не указана фамилия проводившего дефектоскопию гребней.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
    if( iVR == 1 && !m_Ed13.GetData() )
    {
        MessageBox("Не указана фамилия слесаря.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    }
    if( m_Ed13.GetData() ) itoa(m_Ed13.GetData(), cFamSles1, 10);
    else strcpy(cFamSles1, "NULL");

    char cN[16]="", cO[16]="", cQ[1024] = "";

    // Состояние буксового узла
	int xxx = m_Combo4.GetCurSel();
    switch(m_Combo4.GetCurSel())
    {
    case 1: 
    case 2: itoa(m_Combo4.GetCurSel(), cSBU, 10);
            break;
    case -1:if( iVR == 1 )
            {
                MessageBox("Не указано состояние буксового узла.", "Внимание", MB_OK | MB_ICONINFORMATION );
                return;
            }            
			strcpy(cSBU, "NULL");
			break;
    case 0: 
            if( iVR == 1 )
            {
                MessageBox("При неудовлетворительном состоянии буксового узла\nнеобходимо полное освидетельствование КП.", "Внимание", MB_OK | MB_ICONINFORMATION );
                return;
            } 
            else
                strcpy(cSBU, "NULL");
            break;
	default: strcpy(cSBU, "NULL");
    }
    // Дефект по восстановлению резьбы
    if( m_Combo2.GetCurSel() < 0 )
    {
        MessageBox("Некорректно указано наличие дефекта по восстановлению резьбы.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    } else
    if( m_Combo2.GetCurSel() < 0 )
    {
        strcpy(cDVR, "NULL");
    } else
        sprintf(cDVR, "%u", m_Combo2.GetItemData(m_Combo2.GetCurSel()));

    // Дефект по наплавке гребня
    if( m_Combo3.GetCurSel() < 0 )
    {
        MessageBox("Некорректно указано наличие дефекта по наплавке гребня.", "Внимание", MB_OK | MB_ICONINFORMATION );
        return;
    } else
    if( m_Combo3.GetCurSel() < 0 )
    {
        strcpy(cDNG, "NULL");
    } else
        sprintf(cDNG, "%d", m_Combo3.GetCurSel());

    // Причина обточки и прочий дефект - контроль значений
    if( !dwKNPr )
        strcpy(cN, "NULL");
    else
        sprintf(cN, "%d", dwKNPr);

    if( !dwKNObt )
        strcpy(cO, "NULL");
    else
        sprintf(cO, "%d", dwKNObt);
    
/*    SYSTEMTIME st;
    ZeroMemory(&st, sizeof(st));
    m_date1.GetTime(&st);*/
    // Запись в базу


    long Ind = 0;
    sprintf(cQ, "pTov_UpdateRemKP %u, %I64u, '%.4d%.2d%.2d', %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d",
            Prih.dwPriznRas,
            Prih.qwIZAP,
            ts.wYear,
            ts.wMonth,
            ts.wDay,
            iVR,
            m_EdOsv.GetDataAsString(TRUE),
            m_EdF1.GetDataAsString(TRUE), 
            m_EdF2.GetDataAsString(TRUE), 
            m_EdF3.GetDataAsString(TRUE), 
            m_EdF4.GetDataAsString(TRUE),
            m_EdF5.GetDataAsString(TRUE),
            m_EdF6.GetDataAsString(TRUE),
            m_EdF7.GetDataAsString(TRUE),
            m_EdF8.GetDataAsString(TRUE),
            m_Ed13.GetDataAsString(TRUE),
			cO, cN, cSBU, cDVR, cDNG, m_CbM110.GetCurSel());
	char cQRez[1024] = "";
	sprintf(cQRez, "pTov_UpdateRemKP_Rez %u, %u, '%s', %u, %u, %s, '%.4d%.2d%.2d', %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %d",
            Prih.dwPriznRas,

			g_iDep,
			Pasp.cNKP,
			Pasp.dwTKP,
			Pasp.dwIzOsPr_ID,
			DateToSQL(Pasp.stIZOS_DAT),

            ts.wYear,
            ts.wMonth,
            ts.wDay,
            iVR,
            m_EdOsv.GetDataAsString(TRUE),
            m_EdF1.GetDataAsString(TRUE), 
            m_EdF2.GetDataAsString(TRUE), 
            m_EdF3.GetDataAsString(TRUE), 
            m_EdF4.GetDataAsString(TRUE),
            m_EdF5.GetDataAsString(TRUE),
            m_EdF6.GetDataAsString(TRUE),
            m_EdF7.GetDataAsString(TRUE),
            m_EdF8.GetDataAsString(TRUE),
            m_Ed13.GetDataAsString(TRUE),
			cO, cN, cSBU, cDVR, cDNG, m_CbM110.GetCurSel());

	DBW.ExecSQLRzv(cQRez);
//    AfxMessageBox(cQ);
    DBW.ExecSQL(cQ);
    DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &Prih.dwPriznRas, 4, &Ind);
    DBW.CloseCursor();
    DBW.ReallocHandle();
    Prih.dt5 = ts;

    CDlgWithAccelerators::OnOK();
}

void CDlgRemKP::OnChangeVR() 
{
}

void CDlgRemKP::OnChangeVidRem() 
{
    
}

void CDlgRemKP::OnSelchangeCombo1() 
{
    switch( m_Combo1.GetCurSel() )
    {
    case 0: iVR = 1; EnableRabot(); break;
    case 1: iVR = 2; EnableRabot(FALSE); break;
    default: iVR = 0;
    }		
}

void CDlgRemKP::OnChangeEdit1() 
{
    if( !bStarted ) return;
    char cQ[64]="";
    char cText[64]="";
    m_Ed1.GetWindowText(cText, 64);
    m_Ed2.SetWindowText("");
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
    DBW.GetData( 2, SQL_C_SLONG, &dwKNObt, 4, &Ind);
    m_Ed2.SetWindowText(cText);
    DBW.CloseCursor();
}

void CDlgRemKP::OnChangeEdit7() 
{
    if( !bStarted ) return;
    char cQ[64]="";
    char cText[64]="";
    m_Ed3.GetWindowText(cText, 64);
    m_Ed4.SetWindowText("");
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
    DBW.GetData( 2, SQL_C_SLONG, &dwKNPr, 4, &Ind);
    m_Ed4.SetWindowText(cText);
    DBW.CloseCursor();
}

void CDlgRemKP::OnCancel() 
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;		
	CDlgWithAccelerators::OnCancel();
}

void CDlgRemKP::OnShiftF2() 
{
    for( int i=0; i < 20; i++ ) p_dwFIOBuffer[i] = 0;

    p_dwFIOBuffer[0] = m_EdF1.GetData();
    p_dwFIOBuffer[1] = m_EdF2.GetData();
    p_dwFIOBuffer[2] = m_EdF3.GetData();
    p_dwFIOBuffer[3] = m_EdF4.GetData();
    p_dwFIOBuffer[4] = m_EdF5.GetData();
    p_dwFIOBuffer[5] = m_EdF6.GetData();
    p_dwFIOBuffer[6] = m_EdF7.GetData();
    p_dwFIOBuffer[7] = m_EdF8.GetData();
    p_dwFIOBuffer[8] = m_EdOsv.GetData();
    p_dwFIOBuffer[9] = m_Ed13.GetData();

}

void CDlgRemKP::OnShiftF3() 
{
    m_EdF1.SetFamTextByID(p_dwFIOBuffer[0]);
    m_EdF2.SetFamTextByID(p_dwFIOBuffer[1]);
    m_EdF3.SetFamTextByID(p_dwFIOBuffer[2]);
    m_EdF4.SetFamTextByID(p_dwFIOBuffer[3]);
    m_EdF5.SetFamTextByID(p_dwFIOBuffer[4]);
    m_EdF6.SetFamTextByID(p_dwFIOBuffer[5]);
    m_EdF7.SetFamTextByID(p_dwFIOBuffer[6]);
    m_EdF8.SetFamTextByID(p_dwFIOBuffer[7]);
    m_EdOsv.SetFamTextByID(p_dwFIOBuffer[8]);
    m_Ed13.SetFamTextByID(p_dwFIOBuffer[9]);
    
}
