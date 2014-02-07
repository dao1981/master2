// DlgObmerKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgObmerKP.h"
#include "DlgSpravKdr.h"
#include "DlgSprav1.h"
#include "DlgSpravSmp.h"
#include ".\dlgobmerkp.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CMasterApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgObmerKP dialog


CDlgObmerKP::CDlgObmerKP(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgObmerKP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgObmerKP)
	m_EditNKP = _T("");
	m_EditTKP = _T("");
	//}}AFX_DATA_INIT
    qwIZAP = 0;
    dwNKP = 0;
    cTKP[0] = 0;
    dwTKP = 0;
//    dwFam = 0;
    iZp = 0;
    iFo = 0;
    dwIprIzg = 0;
    dwIprFor = 0;
    dwIprOsv = 0;
    dwNeisp = 0;
}


void CDlgObmerKP::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgObmerKP)
	DDX_Control(pDX, IDC_EDIT85, m_EdFIO);
	DDX_Control(pDX, IDC_EDIT5, m_EdOsMidd);
	DDX_Control(pDX, IDC_EDIT6, m_EdOsPred_l);
	DDX_Control(pDX, IDC_EDIT3, m_EdOsPred_r);
	DDX_Control(pDX, IDC_EDIT81, m_EdTD_l);
	DDX_Control(pDX, IDC_EDIT12, m_EdTD_r);
	DDX_Control(pDX, IDC_BUTTON4, m_But4);
	DDX_Control(pDX, IDC_EDIT80, m_EdD_l);
	DDX_Control(pDX, IDC_EDIT11, m_EdD_r);
	DDX_Control(pDX, IDC_EDIT7, m_EdOsPod_l);
	DDX_Control(pDX, IDC_EDIT4, m_EdOsPod_r);
	DDX_Control(pDX, IDC_EDIT8, m_EdGreb_r);
	DDX_Control(pDX, IDC_EDIT78, m_EdGreb_l);
	DDX_Control(pDX, IDC_EDIT79, m_EdObod_l);
	DDX_Control(pDX, IDC_EDIT9, m_EdObod_r);
	DDX_Control(pDX, IDC_EDIT13, m_EdProkat_l);
	DDX_Control(pDX, IDC_EDIT10, m_EdProkat_r);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_EDIT82, m_EdRasGr);
	DDX_Control(pDX, IDC_EDIT17, m_EdNeispName);
	DDX_Control(pDX, IDC_EDIT16, m_EdKodNeisp);
	DDX_Control(pDX, IDC_EDIT84, m_EdPrOsv);
	DDX_Control(pDX, IDC_EDIT83, m_EdPrFor);
	DDX_Control(pDX, IDC_EDIT77, m_Date3);
	DDX_Control(pDX, IDC_EDIT76, m_Date2);
	DDX_Control(pDX, IDC_EDIT14, m_Date1);
	DDX_Control(pDX, IDC_EDIT15, m_EdPrIzg);
	DDX_Text(pDX, IDC_EDIT1, m_EditNKP);
	DDX_Text(pDX, IDC_EDIT2, m_EditTKP);

	DDX_Control(pDX, IDC_CHECK2, m_S3_R);
	DDX_Control(pDX, IDC_CHECK3, m_S3_L);

	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgObmerKP, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgObmerKP)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonKlPr)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonPrFor)
	ON_BN_CLICKED(IDC_BUTTON3, OnButtonPrOsv)
	ON_BN_CLICKED(IDC_BUTTON4, OnButtonNeisp)
	ON_EN_KILLFOCUS(IDC_EDIT15, OnKillfocusIzgOs)
	ON_EN_KILLFOCUS(IDC_EDIT83, OnKillfocusPosFor)
	ON_EN_KILLFOCUS(IDC_EDIT84, OnKillfocusPosOsv)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDOK, &CDlgObmerKP::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT15, &CDlgObmerKP::OnEnChangeEdit15)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgObmerKP message handlers

BOOL CDlgObmerKP::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
    m_Date1.SetMode(3);
    m_Date2.SetMode(3);
    m_Date3.SetMode(3);
    m_EdProkat_l.iMode = m_EdProkat_r.iMode = 2;
    m_EdProkat_l.Prec = m_EdProkat_r.Prec = 1;
    m_EdProkat_l.Scale = m_EdProkat_r.Scale = 1;
    m_EdObod_r.iMode = m_EdObod_l.iMode = 2;
    m_EdObod_r.Scale = m_EdObod_l.Scale = 0;
    m_EdObod_r.Prec = m_EdObod_l.Prec = 2;
    m_EdGreb_r.iMode = m_EdGreb_l.iMode = 2;
    m_EdGreb_r.Prec = m_EdGreb_l.Prec = 2;
    m_EdGreb_r.Scale = m_EdGreb_l.Scale = 0;
    m_EdRasGr.iMode = 2;
    m_EdRasGr.Prec = 4;
    m_EdRasGr.Scale = 1;
    m_EdTD_r.QInit(20);
    m_EdTD_l.QInit(20);

	m_EdOsPred_l.iMode = m_EdOsPred_r.iMode = 2;
	m_EdOsPred_l.Prec  = m_EdOsPred_r.Prec = 3;
	m_EdOsPred_l.Scale = m_EdOsPred_r.Scale = 3;

/*
    m_EdOsPred_r.QInit(44);
    m_EdOsPred_l.QInit(44);
	*/
    m_EdOsMidd.QInit(30);

    m_EdFIO.SetMode(5);

    DBW.FillEmplArray(m_EdFIO.lpEmpl, 2);

    //Подст. ч. оси.. :- )
    m_EdOsPod_l.iMode = m_EdOsPod_r.iMode = 2;
    m_EdOsPod_l.Prec = m_EdOsPod_r.Prec = 3;
    m_EdOsPod_l.Scale = m_EdOsPod_r.Scale = 2;

    m_EdD_r.iMode = m_EdD_l.iMode = 2;
    m_EdD_r.Prec = m_EdD_l.Prec = 3;
    m_EdD_r.Scale = m_EdD_l.Scale = 1;

    m_Combo1.SetCurSel(1);
    
	IniForm();
    dwOld_IzgIPr = Pasp.dwIzOsPr_ID;
	stOld_IzgDat = Pasp.stIZOS_DAT;

    if( g_dwTypeDep == 1 ) 
    {
        m_EdOsPred_r.EnableWindow(FALSE);
        m_EdOsPred_l.EnableWindow(FALSE);
        m_EdOsPod_r.SetFocus();
    }
    else m_EdOsPred_r.SetFocus();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgObmerKP::IniForm()
{
    char cQ[128] = "";
    char cText[64] = "";
    long Ind = 0;
    double dNum = 0.0;
    DWORD dwNum = 0;
    SQL_DATE_STRUCT  sqlDat;
    SYSTEMTIME       sysTime;

    sprintf(cQ, "pTov_KP_GetObmerData %I64u, %u", qwIZAP, g_iDep );
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();

    // Грузовая - пассажирская
    DBW.GetData( 1, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 )
    {
        switch (dwNum)
        {
        case 0: m_Combo1.SetCurSel(0); break;
        case 2: m_Combo1.SetCurSel(1); m_Combo1.EnableWindow(FALSE); break;
        case 4: m_Combo1.SetCurSel(2); m_Combo1.EnableWindow(FALSE); break;
        }
    } else
        m_Combo1.SetCurSel(-1);
    // Фамилия производившего замеры
    DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 ) 
    {
        m_EdFIO.SetWindowText(cText);
        strcpy(Prih.cFam, cText);
        DBW.GetData( 3, SQL_C_SLONG, &dwNum, 4, &Ind);
        m_EdFIO.SetData(dwNum);
    }
    // Толщина диска
    DBW.GetData( 4, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        itoa(dwNum, cText, 10);
        m_EdTD_l.SetWindowText(cText);
    }
    DBW.GetData( 5, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        itoa(dwNum, cText, 10);
        m_EdTD_r.SetWindowText(cText);
    }
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
    // Клейма предприятий последнего формирования и освидетельствовпния
    DBW.GetData( 8, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        itoa(dwNum, cText, 10);
        m_EdPrFor.SetWindowText(cText);
    }
    DBW.GetData( 9, SQL_C_DATE, &sqlDat, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &sysTime);
        m_Date2.SetDate(&sysTime);
        Prih.stDatFor = sysTime;
    }
    DBW.GetData( 10, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        itoa(dwNum, cText, 10);
        m_EdPrOsv.SetWindowText(cText);
    }
    DBW.GetData( 11, SQL_C_DATE, &sqlDat, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &sysTime);
        m_Date3.SetDate(&sysTime);
        Prih.stDatOsv = sysTime;
    }
    // Код неисправности
    DBW.GetData( 12, SQL_C_CHAR, &cText, 64, &Ind);
    if( Ind != -1 ) 
    {
        m_EdKodNeisp.SetWindowText(cText);
    }
    DBW.GetData( 13, SQL_C_CHAR, cText, 64, &Ind);
    if( Ind != -1 ) 
    {
        m_EdNeispName.SetWindowText(cText);
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
/*        itoa(dwNum, cText, 10);
        m_EdObod_l.SetWindowText(cText);*/
    }
    DBW.GetData( 17, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        m_EdObod_r.SetValue(dwNum);
/*        itoa(dwNum, cText, 10);
        m_EdObod_r.SetWindowText(cText);*/
    }
    // Гребень
    DBW.GetData( 18, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        m_EdGreb_l.SetValue(dwNum);
/*        itoa(dwNum, cText, 10);
        m_EdGreb_l.SetWindowText(cText);*/
    }
    DBW.GetData( 19, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        m_EdGreb_r.SetValue(dwNum);
/*        itoa(dwNum, cText, 10);
        m_EdGreb_r.SetWindowText(cText);*/
    }
    // Диаметр оси посередине
    DBW.GetData( 20, SQL_C_SLONG, &dwNum, 4, &Ind);
    if( Ind != -1 ) 
    {
        itoa(dwNum, cText, 10);
        m_EdOsMidd.SetWindowText(cText);
    }
    // Диаметр предподступичной части оси
    //EdOsPred_r
    DBW.GetData( 21, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 )
    {
//        itoa(dwNum, cText, 10);
        m_EdOsPred_l.SetValue(dNum);
    }
    DBW.GetData( 22, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 ) 
    {
//        itoa(dwNum, cText, 10);
        m_EdOsPred_r.SetValue(dNum);
    }
    // Диаметр подступичной части оси
    DBW.GetData( 23, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 ) 
    {
/*        itoa(dwNum, cText, 10);
        m_EdOsPod_l.SetWindowText(cText);*/
        m_EdOsPod_l.SetValue(dNum);
    }
    DBW.GetData( 24, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 ) 
    {
        m_EdOsPod_r.SetValue(dNum);
/*      itoa(dwNum, cText, 10);
        m_EdOsPod_r.SetWindowText(cText);*/
    }
    // Расстояние между внутренними гранями
    DBW.GetData( 25, SQL_C_DOUBLE, &dNum, 8, &Ind);
    if( Ind != -1 ) 
    {
        m_EdRasGr.SetValue(dNum);
/*        itoa(dwNum, cText, 10);
        m_EdRasGr.SetWindowText(cText);*/
    }
    DBW.GetData( 26, SQL_C_SLONG, &dwIprFor, 4, &Ind);
    DBW.GetData( 27, SQL_C_SLONG, &dwIprOsv, 4, &Ind);
    DBW.GetData( 28, SQL_C_SLONG, &dwNeisp, 4, &Ind);
    DBW.GetData( 29, SQL_C_DATE, &sqlDat, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &sysTime);
        m_Date1.SetDate(&sysTime);
        Prih.stDatPost = sysTime;
    }
    DBW.GetData( 30, SQL_C_SLONG, &Pasp.dwIzOsPr_ID, 4, &Ind);
    dwIprIzg = Pasp.dwIzOsPr_ID;
    DBW.GetData( 31, SQL_C_CHAR, &Pasp.cIzOsPr_KL, 32, &Ind);
    m_EdPrIzg.SetWindowText(Pasp.cIzOsPr_KL);
    DBW.GetData( 32, SQL_C_DATE, &sqlDat, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Ind != -1 )
    {
        SqlDateToSysTime(sqlDat, &sysTime);
//        m_Date1.SetDate(&sysTime);
        Prih.stDatPost = sysTime;
    }
    DBW.GetData( 33, SQL_C_SLONG, &dwNum, 4, &Ind);
	if( Ind != -1 ) m_S3_R.SetCheck(dwNum);

	DBW.GetData( 34, SQL_C_SLONG, &dwNum, 4, &Ind);
	if( Ind != -1 ) m_S3_L.SetCheck(dwNum);

    DBW.CloseCursor();

}

void CDlgObmerKP::OnButton5() 
{
    CDlgSpravKdr Dlg;
    Dlg.iFilter = 2;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdFIO.SetData(Dlg.dwFio);
    m_EdFIO.SetWindowText(Dlg.cFio);
}

void CDlgObmerKP::OnButtonKlPr() 
{
    CDlgSprav1 Dlg;	
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwIprIzg = Dlg.ret_dwIPR;
    m_EdPrIzg.SetWindowText(Dlg.cKodPr);
}

void CDlgObmerKP::OnButtonPrFor() 
{
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 2;
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwIprFor = Dlg.ret_dwIPR;
    m_EdPrFor.SetWindowText(Dlg.cKodPr);	
}

void CDlgObmerKP::OnButtonPrOsv() 
{
    CDlgSprav1 Dlg;	
    Dlg.iDlgKind = 3; 
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwIprOsv = Dlg.ret_dwIPR;
    m_EdPrOsv.SetWindowText(Dlg.cKodPr);	
}

void CDlgObmerKP::OnButtonNeisp() 
{
    CDlgSpravSmp Dlg;
    Dlg.DlgMode = 111;
    Dlg.Style = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdKodNeisp.SetWindowText(Dlg.cRet);
    m_EdNeispName.SetWindowText(Dlg.c_retText2);
    dwNeisp = Dlg.dwRet;
}

int CDlgObmerKP::TestRazm1(double dMin, double dMax, double dVal)
{
    char s[64] = "";
    if( dVal < dMin && dMin)
    {        
        sprintf(s, "Значение %f меньше допустимого предела", dVal);
        MessageBox(s, "Внимание", MB_OK | MB_ICONINFORMATION );
        return -1;
    }
    if( dVal > dMax && dMax)
    {
        sprintf(s, "Значение %f больше допустимого предела", dVal);
        MessageBox(s, "Внимание", MB_OK | MB_ICONINFORMATION );
        return -1;
    }
    return 0;
}

void CDlgObmerKP::OnOK() 
{
    char cQ[255] = "";
    char cText[250] = "";
    char c_uPosFor[64] = "";
    char c_uPosOsv[64] = "";
    char c_uDkk[64] = "";
    char c_uTD[64] = "";
    char cPredR[16] = "";
    char cPredL[16] = "";
    char c_uPr[32] = "";
    char c_uObods[32] = "";
    char c_uGrebs[32] = "";
    char c_uOsPod[32] = "";
    char c_uOsMidd[32] = "";
    char c_uRasGr[32] = "";
    char c_uNeisp[32] = "";
    char cGP[8] = "";

    bool GotRazmers = true;
    long Ind = 0;
    SYSTEMTIME st1, st2, st3, tm;
    ZeroMemory(&st1, sizeof(SYSTEMTIME));
    ZeroMemory(&st2, sizeof(SYSTEMTIME));
    ZeroMemory(&st3, sizeof(SYSTEMTIME));
    ZeroMemory(&tm, sizeof(SYSTEMTIME));
    char cDate1[16] = "", cDate2[16] = "", cDate3[16] = "";
    m_Date1.GetAsDate(&st1);
    m_Date2.GetAsDate(&st2);
    m_Date3.GetAsDate(&st3); 

    if( (iZp == 1 && ! m_Date1.GetAsString(cDate1)) ||
        (iZp == 2 && !iFo && (dwIprIzg != Pasp.dwIzOsPr_ID) ||
        SysDateCmp(st1, Pasp.stIZOS_DAT))) 
    {
        if( !m_Date1.isValid()  && m_Date1.GetWindowTextLength() )
        {
            MessageBox("Введена некорректная дата изготовления оси", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        Prih.stDatIzg = st1;
        if( !m_EdPrIzg.GetWindowText(cText, 64) || !atoi(cText) )
        {
            MessageBox("Недопустимое клеймо предприятия изготовления оси", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        if( SysDateCmp(Prih.stDatIzg, Prih.stDatPost) > 0 ) //catch it
        {
            MessageBox("Дата поступления должна быть позже изготовления оси", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        Pasp.stIZOS_DAT = st1;
        DateToSql(Pasp.stIZOS_DAT, cText);
        m_EdPrIzg.GetWindowText(Pasp.cIzOsPr_KL, 32);
/*        sprintf(cQ, "pTov_UpdatePaspIZOS %d, %s, %I64u",
                    dwIprIzg,
                    cText,
                    Pasp.qwIKP);
        DBW.ExecSQL(cQ);
        DBW.CloseCursor();
		DBW.ReallocHandle();*/
        Pasp.dwIzOsPr_ID = dwIprIzg;

        iZp = 2;
/*        if( g_sqlret == SQL_ERROR )
        {
            MessageBox("Не удается записать данные изготовления оси", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }*/
    }
    // Контроль занесения сведений о последнем формировании
    if( m_Date2.isValid() || m_EdPrFor.GetWindowText(cText, 64) || dwIprFor )
    {
        if( !m_Date2.isValid() )
        {
            MessageBox("Введена некорректная дата последнего формирования", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        m_Date2.GetAsDate(&Prih.stDatFor);
        if( iZp == 2 && SysDateCmp(Prih.stDatIzg, Prih.stDatFor) > 0 )
        {
            MessageBox("Дата последнего формирования должна быть позже изготовления оси", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        if( SysDateCmp(Prih.stDatFor, Prih.stDatPost) > 0 )
        {
            MessageBox("Дата последнего формирования должна быть раньше даты поступления", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        if( !dwIprFor )
        {
            MessageBox("Недопустимое клеймо предприятия последнего формирования", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        //itoa(dwIprFor, Prih.cPosForIpr, 10);
		Prih.dwPosForPr_ID = dwIprFor;
        if( m_Date2.GetAsDate(&tm) ) strcpy(cText, "NULL");
        else sprintf(cText, "'%.4d%.2d%.2d'", tm.wYear, tm.wMonth, tm.wDay);
        sprintf(c_uPosFor, "%u, %s ", Prih.dwPosForPr_ID, cText);
    } else
        strcpy(c_uPosFor, "NULL, NULL");
    // Контроль занесения сведений о последнем освидетельствовании
    if( m_Date3.isValid() || m_EdPrOsv.GetWindowText(cText, 64) || dwIprOsv )
    {
        if( !m_Date3.isValid() )
        {
            MessageBox("Некорректная дата последнего освидетельствования", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        Prih.stDatOsv = st3;
        if( iZp == 2 && SysDateCmp(Prih.stDatIzg, Prih.stDatOsv) > 0 )
        {
            MessageBox("Дата последнего освидетельствования должна быть позже изготовления оси", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;            
        }
        if( SysDateCmp(Prih.stDatOsv, Prih.stDatPost) > 0 )
        {
            MessageBox("Дата последнего освидетельствования должна быть раньше даты поступления", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
		/*
        if( dwIprFor && SysDateCmp(Prih.stDatIzg, Prih.stDatOsv) > 0 )
        {
            MessageBox("Дата последнего освидетельствования должна быть не раньше даты последнего формирования", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
		*/
        if( !dwIprOsv )
        {
            MessageBox("Недопустимое клеймо предприятия последнего освидетельствования", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        //itoa(dwIprOsv, Prih.cPosOsvIpr, 10);
		Prih.dwPosOsvPr_ID = dwIprOsv;
//        m_Date3.GetAsString(cText);
        if( m_Date3.GetAsDate(&tm) ) strcpy(cText, "NULL");
        else sprintf(cText, "'%.4d%.2d%.2d'", tm.wYear, tm.wMonth, tm.wDay);
        sprintf(c_uPosOsv, "%u, %s", Prih.dwPosOsvPr_ID, cText);
    } else
    {
        strcpy(c_uPosOsv, "NULL, NULL");
    }
    //Запрос размеров
    double dV1 = 0, dV2 = 0;
    sprintf(cQ, "pTov_GetKPRazmer %u, %u, %u", g_iDep, Pasp.dwTKP, Prih.dwTREB_REM );
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    if( g_sqlret == SQL_NO_DATA )
    {
        GotRazmers = false;
    } else
    {
        DBW.GetData( 7, SQL_C_DOUBLE, &dV1, sizeof(double), &Ind);
        DBW.GetData( 8, SQL_C_DOUBLE, &dV2, sizeof(double), &Ind);
    }
    DBW.CloseCursor();
    // Контроль диаметров по кругу катания
    char cT1[32] = "", cT2[32] = "";    
    if( m_EdD_r.GetWindowTextLength() ||
        m_EdD_l.GetWindowTextLength() )
    {
/*
        m_EdD_r.GetWindowText(cT1, 32);
        m_EdD_l.GetWindowText(cT2, 32);
*/
        m_EdD_r.GetAsString(cT1);
        m_EdD_l.GetAsString(cT2);
        if( !cT1[0] )
        {
            MessageBox("Некорректно указан диаметр правого диска", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;            
        }
        if( !cT2[0] )
        {
            MessageBox("Некорректно указан диаметр левого диска", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;          
        }
        sprintf(c_uDkk, "%s, %s", cT2, cT1);
    } else
    {
        strcpy(c_uDkk, "NULL, NULL");
    }
    // Контроль толщины дисков
    if( m_EdTD_r.GetWindowTextLength() ||
        m_EdTD_l.GetWindowTextLength() )
    {
        m_EdTD_r.GetWindowText(cT1, 32);
        m_EdTD_l.GetWindowText(cT2, 32);       

        if( !atoi(cT1) && cT1[0] )
        {
            MessageBox("Некорректно указана толщина правого диска", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        if( !atoi(cT2) && cT2[0] )
        {
            MessageBox("Некорректно указана толщина левого диска", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;          
        }
        sprintf(c_uTD, "%s, %s", cT2, cT1);
    } else
    {
        strcpy(c_uTD, "NULL, NULL");
    }
    //Диаметр предподступичной части оси
    if( m_EdOsPred_r.GetWindowTextLength() ||
        m_EdOsPred_l.GetWindowTextLength() )
    {
        m_EdOsPred_r.GetWindowText(cT1, 32);
        m_EdOsPred_l.GetWindowText(cT2, 32);
        double dlV1, dlV2;
        if( !(dlV1 = atof(cT1)) && cT1[0] )
        {
            MessageBox("Некорректно указан диаметр предподступичной части оси (прав.)", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        if( !(dlV2 = atof(cT2)) && cT2[0] )
        {
            MessageBox("Некорректно указан диаметр предподступичной части оси (лев.)", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        if( dlV1 )
        {
            if( GotRazmers ) 
                if( TestRazm1(dV1, dV2, dlV1) ) return; //тестим прав.
            sprintf(cPredR, "%f", dlV1);
        } else
            strcpy(cPredR, "NULL");

        if( dlV2 )
        {
            if( GotRazmers )             
                if(TestRazm1(dV1, dV2, dlV2) ) return; //тестим лев.
            sprintf(cPredL, "%f", dlV2);

        } else
            strcpy(cPredL, "NULL");
    } else
    {
        strcpy(cPredL, "NULL");
        strcpy(cPredR, "NULL");
    }

    // Прокат
    if( !m_EdProkat_r.GetAsString(cT1) ||
        !m_EdProkat_l.GetAsString(cT2) )
    {
        m_EdProkat_r.GetAsString(cT1);
        m_EdProkat_l.GetAsString(cT2);
        if( !m_EdProkat_r.isValid() )
        {
            MessageBox("Некорректно указан прокат правого диска", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        if( !m_EdProkat_l.isValid() )
        {
            MessageBox("Некорректно указан прокат левого диска", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        sprintf(c_uPr, "%s, %s", cT2, cT1);
    } else
            strcpy(c_uPr, "NULL, NULL");
    // Обод
    if( !m_EdObod_r.GetAsString(cT1) ||
        !m_EdObod_l.GetAsString(cT2) )
    {
        m_EdObod_r.GetAsString(cT1);
        m_EdObod_l.GetAsString(cT2);
        if( !m_EdObod_r.isValid() )
        {
            MessageBox("Некорректно указан обод правого колеса", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        if( !m_EdObod_l.isValid() )
        {
            MessageBox("Некорректно указан обод левого колеса", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        sprintf(c_uObods, "%s, %s", cT2, cT1);
    } else
            strcpy(c_uObods, "NULL, NULL");
    // Гребень
    if( !m_EdGreb_r.GetAsString(cT1) ||
        !m_EdGreb_l.GetAsString(cT2) )
    {
        m_EdGreb_r.GetAsString(cT1);
        m_EdGreb_l.GetAsString(cT2);
        if( !m_EdGreb_r.isValid() )
        {
            MessageBox("Некорректно указан гребень правого колеса", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        if( !m_EdGreb_l.isValid() )
        {
            MessageBox("Некорректно указан гребень левого колеса", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        sprintf(c_uGrebs, "%s, %s", cT2, cT1);    
    } else
            strcpy(c_uGrebs, "NULL, NULL");
    // Контроль диаметра оси в подступичной части
    if( m_EdOsPod_r.GetWindowTextLength() ||
        m_EdOsPod_l.GetWindowTextLength() )
    {
/*        m_EdOsPod_r.GetWindowText(cT1, 32);
        m_EdOsPod_l.GetWindowText(cT2, 32);*/
        if( !m_EdOsPod_r.isValid() )
        {
            MessageBox("Некорректно указан диаметр оси в подступичной части правой стороны", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        if( !m_EdOsPod_l.isValid() )
        {
            MessageBox("Некорректно указан диаметр оси в подступичной части левой стороны", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        m_EdOsPod_l.GetAsString(cT2);
        m_EdOsPod_r.GetAsString(cT1);
        sprintf(c_uOsPod, "%s, %s", cT2, cT1);
    } else
        strcpy(c_uOsPod, "NULL, NULL");
    // Контроль диаметра оси посередине
    if( m_EdOsMidd.GetWindowText(cT1, 32) )
    {
/*
        if( !atoi(cT1) && cT1[0] )
        {
            MessageBox("Некорректно указан диаметр оси посередине", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
*/
        sprintf(c_uOsMidd, "%s", m_EdOsMidd.GetAsString());
    } else
        strcpy(c_uOsMidd, "NULL");
    // Контроль расстояния между внутренними гранями колеса
    m_EdRasGr.GetAsString(cT1);
    if( cT1[0] )
    {
        if( !m_EdRasGr.isValid() )
        {
            MessageBox("Некорректно указано расстояние между внутренними гранями колеса", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        sprintf(c_uRasGr, "%s", cT1);
    } else
        strcpy(c_uRasGr, "NULL");
    // Контроль кода неисправности
    if( m_EdKodNeisp.GetWindowText(cT1, 32) && dwNeisp)
    {
        if( !atoi(cT1) && cT1[0] )
        {
            MessageBox("Недопустимое значение кода неисправности", "Внимание", MB_OK | MB_ICONINFORMATION );
            return;
        }
        sprintf(c_uNeisp, "%u", dwNeisp);
    } else
        strcpy(c_uNeisp, "NULL");
    // Грузовая пассажирская
    switch (m_Combo1.GetCurSel())
    {
    case 0: strcpy(cGP, "0"); break;
    case 1: strcpy(cGP, "1"); break;
    case 2: strcpy(cGP, "4"); break;
    default: strcpy(cGP, "0"); break;

    }
    // Запись в базу
	CString cKlPrIzg = "";
	m_EdPrIzg.GetWindowText(cKlPrIzg);

    sprintf(cQ, "pTov_KP_UpdateRazmers %I64u, %u, %u, %s, %s, %s, %s, %s,"
                "%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %I64u, %d, %d",
                qwIZAP,
				g_iDep,
                m_EdFIO.GetData(),
                cGP,
                c_uPosFor, c_uPosOsv,
                c_uTD,
                c_uDkk,
                cPredL, cPredR,
                c_uPr, c_uObods,
                c_uGrebs, c_uOsPod, c_uOsMidd, c_uRasGr, c_uNeisp,
				isNull(cKlPrIzg), m_Date1.GetSQLDate(), Pasp.qwIKP, 
				
				m_S3_R.GetCheck(), m_S3_L.GetCheck());

	char cQRez[255] = "";
	    
    int ret = 0;
    DBW.ExecSQL(cQ);
    DBW.Fetch();
    DBW.GetData(1, SQL_C_SLONG, &ret, 4, &Ind);
    if( ret )
    {
        DBW.GetData(2, SQL_C_CHAR, &cText, 249, &Ind);
        AfxMessageBox(cText);
		if( ret == -1 )
		{
			Pasp.stIZOS_DAT = stOld_IzgDat;
			Pasp.dwIzOsPr_ID = dwOld_IzgIPr;
		}
    } else  //все нормально - шлем на резервный
	{
		DBWrez.ExecSQL(cQ);
		DBWrez.CloseCursor();
		DBWrez.ReallocHandle();		
/*
		sprintf(cQRez, "pTov_UpdateRazmers_Rez '%s', %u, %u, %s, %u, %u, %s, %s, %s, %s, %s,"
                "%s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %d, %d",
				Pasp.cNKP,
				Pasp.dwTKP,
				dwOld_IzgIPr,
				DateToSQL(stOld_IzgDat),
				g_iDep,
                m_EdFIO.GetData(),
                cGP,
                c_uPosFor, c_uPosOsv,
                c_uTD,
                c_uDkk,
                cPredL, cPredR,
                c_uPr, c_uObods,
                c_uGrebs, c_uOsPod, c_uOsMidd, c_uRasGr, c_uNeisp,
				dwIprIzg, m_Date1.GetSQLDate(), 
				
				m_S3_R.GetCheck(), m_S3_L.GetCheck());
		DBW.ExecSQLRzv(cQRez);*/
	} 
   DBW.CloseCursor();
	
   CDlgWithAccelerators::OnOK();
}

void CDlgObmerKP::OnKillfocusIzgOs() 
{
    CString str;
    m_EdPrIzg.GetWindowText(str);
    if( str == "" )
    {
        dwIprIzg = 0;
        return;
    }
    char cText[32] = "";
    char cQ[128] = "";
    long Ind = 0;

    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();

    bool lbCanIzgOs = false;

    DBW.GetData( 1, SQL_C_ULONG, &dwIprIzg, 4, &Ind);
    DBW.GetData( 2, SQL_C_CHAR, cText, 32, &Ind);
    DBW.GetData( 3, SQL_C_BIT, &lbCanIzgOs, 1, &Ind);

    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR || !lbCanIzgOs )
    {
        MessageBox("Введено некорректное клеймо предприятия изготовления оси!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdPrIzg.SetFocus();
        return;
    }
    m_Date2.SetFocus();
}

void CDlgObmerKP::OnKillfocusPosFor() 
{
    CString str;
    m_EdPrFor.GetWindowText(str);
    if( str == "" )
    {
        dwIprFor = 0;
        return;
    }
    char cText[32] = "";
    char cQ[128] = "";
    long Ind = 0;
    bool lbCanForm = false;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwIprFor, 4, &Ind);
    DBW.GetData( 2, SQL_C_CHAR, cText, 32, &Ind);
    DBW.GetData( 4, SQL_C_BIT, &lbCanForm, 1, &Ind);

    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR || !lbCanForm)
    {
        MessageBox("Введено некорректное клеймо предприятия последнего формирования!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdPrFor.SetFocus();
        return;        
    }
    m_Date3.SetFocus();
}

void CDlgObmerKP::OnKillfocusPosOsv() 
{
    CString str;
    m_EdPrOsv.GetWindowText(str);
    if( str == "" )
    {
        dwIprOsv = 0;
        return;
    }
    char cText[32] = "";
    char cQ[128] = "";
    long Ind = 0;
    bool lbCanOsv = false;
    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwIprOsv, 4, &Ind);
    DBW.GetData( 2, SQL_C_CHAR, cText, 32, &Ind);
    DBW.GetData( 5, SQL_C_BIT, &lbCanOsv, 1, &Ind);

    DBW.CloseCursor();
    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR || cText[0] == 0 || !lbCanOsv)
    {
        MessageBox("Введено некорректное клеймо предприятия последнего освидетельствования!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdPrOsv.SetFocus();
        return;
    }
    m_But4.SetFocus();
    
}

void CDlgObmerKP::OnCancel() 
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;	
	CDlgWithAccelerators::OnCancel();
}

void CDlgObmerKP::OnBnClickedCancel()
{
	OnCancel();
}

void CDlgObmerKP::OnBnClickedOk()
{
	OnOK();
}

void CDlgObmerKP::OnEnChangeEdit15()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDlgWithAccelerators::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
