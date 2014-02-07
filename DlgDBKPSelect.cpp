// DlgDBKPSelect.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgDBKPSelect.h"
#include "DlgSprav1.h"
#include "DlgSpravSmp.h"
#include "DlgBDSelectRez.h"
#include ".\dlgdbkpselect.h"
#include "printabledlg.h"
#include "DlgSprPrSobstv.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


extern CMasterApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgDBKPSelect dialog


CDlgDBKPSelect::CDlgDBKPSelect(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgDBKPSelect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgDBKPSelect)
	//}}AFX_DATA_INIT
    dwPeresIPR = 0;
    dwOsIPR = 0;
    dwNeisp = 0;
	iSelectCount = 0;
}


void CDlgDBKPSelect::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgDBKPSelect)
	DDX_Control(pDX, IDC_EDIT79, m_Dt6);
	DDX_Control(pDX, IDC_EDIT12, m_Dt5);
	DDX_Control(pDX, IDC_EDIT11, m_Dt4);
	DDX_Control(pDX, IDC_EDIT78, m_Dt3);
	DDX_Control(pDX, IDC_EDIT9, m_Dt2);
	DDX_Control(pDX, IDC_EDIT8, m_Dt1);
	DDX_Control(pDX, IDC_EDIT83, m_Dt10);
	DDX_Control(pDX, IDC_EDIT76, m_Dt9);
	DDX_Control(pDX, IDC_EDIT14, m_Dt8);
	DDX_Control(pDX, IDC_EDIT13, m_Dt7);
	DDX_Control(pDX, IDC_EDIT71, m_Edit9);
	DDX_Control(pDX, IDC_EDIT70, m_Edit8);
	DDX_Control(pDX, IDC_COMBO8, m_Combo3);
	DDX_Control(pDX, IDC_BUTTON4, m_Button4);
	DDX_Control(pDX, IDC_EDIT15, m_Edit10);
	DDX_Control(pDX, IDC_BUTTON1, m_Button1);
	DDX_Control(pDX, IDC_BUTTON2, m_Button2);
	DDX_Control(pDX, IDC_EDIT7, m_Edit7);
	DDX_Control(pDX, IDC_CHECK8, m_Check9);
	DDX_Control(pDX, IDC_COMBO3, m_Combo2);
	DDX_Control(pDX, IDC_EDIT6, m_Edit6);
	DDX_Control(pDX, IDC_EDIT5, m_Edit5);
	DDX_Control(pDX, IDC_CHECK12, m_Check16);
	DDX_Control(pDX, IDC_CHECK11, m_Check15);
	DDX_Control(pDX, IDC_CHECK37, m_Check14);
	DDX_Control(pDX, IDC_CHECK33, m_Check12);
	DDX_Control(pDX, IDC_CHECK35, m_Check11);
	DDX_Control(pDX, IDC_CHECK9, m_Check10);
	DDX_Control(pDX, IDC_EDIT4, m_Edit4);
	DDX_Control(pDX, IDC_EDIT3, m_Edit3);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_CHECK7, m_Check8);
	DDX_Control(pDX, IDC_CHECK6, m_Check7);
	DDX_Control(pDX, IDC_CHECK5, m_Check6);
	DDX_Control(pDX, IDC_CHECK4, m_Check5);
	DDX_Control(pDX, IDC_CHECK3, m_Check4);
	DDX_Control(pDX, IDC_CHECK2, m_Check3);
	DDX_Control(pDX, IDC_CHECK31, m_Check2);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_COMBO4, m_ComboRem1);
	DDX_Control(pDX, IDC_COMBO5, m_ComboRem2);
	DDX_Control(pDX, IDC_CHECK10, m_CheckSpis);

	DDX_Control(pDX, IDC_BUTTON8, m_ButSobst);
	DDX_Control(pDX, IDC_EDIT18, m_EdSobst);

	DDX_Control(pDX, IDC_CHECK13, m_Check17);

}


BEGIN_MESSAGE_MAP(CDlgDBKPSelect, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgDBKPSelect)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_CHECK1, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK31, OnCheck2)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck5)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck6)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck7)
	ON_BN_CLICKED(IDC_CHECK7, OnCheck8)
	ON_BN_CLICKED(IDC_CHECK9, OnCheck10)
	ON_BN_CLICKED(IDC_CHECK35, OnCheck11)
	ON_BN_CLICKED(IDC_CHECK33, OnCheck12)
	ON_BN_CLICKED(IDC_CHECK37, OnCheck14)
	ON_BN_CLICKED(IDC_CHECK11, OnCheck15)
	ON_BN_CLICKED(IDC_CHECK12, OnCheck16)
	ON_BN_CLICKED(IDC_CHECK13, OnCheck17)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON7, OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CDlgDBKPSelect::OnBnClickedButton_Sobst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgDBKPSelect message handlers

void CDlgDBKPSelect::OnOK() 
{
    PRIHOD_PARAMS pp;
    char cFilter[1024] = "";
    SYSTEMTIME st1, st2;
    ZeroMemory(&st1, sizeof(st1));
    ZeroMemory(&st2, sizeof(st2));

    if( m_Check1.GetCheck() )
    {
        m_Dt1.GetTime(&st1);
        m_Dt2.GetTime(&st2);

        sprintf(cFilter, "AND PRIHOD_KP.DAT_POST >= ''%.4d%.2d%.2d'' AND PRIHOD_KP.DAT_POST <=''%.4d%.2d%.2d'' ",
                st1.wYear, st1.wMonth, st1.wDay, st2.wYear, st2.wMonth, st2.wDay);

        //sprintf(pp.cDatPrih1, "'%.4d%.2d%.2d'", st1.wYear, st1.wMonth, st1.wDay);
        //sprintf(pp.cDatPrih2, "'%.4d%.2d%.2d'", st2.wYear, st2.wMonth, st2.wDay);
        strcpy(pp.cDatPrih1, m_Dt1.GetSQLDate());
        strcpy(pp.cDatPrih2, m_Dt2.GetSQLDate());

    }
    if( m_Check2.GetCheck() )
    {
        m_Dt3.GetTime(&st1);
        m_Dt4.GetTime(&st2);
        sprintf(cFilter, "%sAND ((REM_KP.DAT_REM>=''%.4d%.2d%.2d'' AND REM_KP.DAT_REM<=''%.4d%.2d%.2d'') OR (REM_KP.DAT_REM IS NULL AND ZAPRES_KP.DAT_FOR>=''%.4d%.2d%.2d'' AND ZAPRES_KP.DAT_FOR<=''%.4d%.2d%.2d''))",
                cFilter, st1.wYear, st1.wMonth, st1.wDay, st2.wYear, st2.wMonth, st2.wDay,
				st1.wYear, st1.wMonth, st1.wDay, st2.wYear, st2.wMonth, st2.wDay);
        //sprintf(pp.cDatRem1, "'%.4d%.2d%.2d'", st1.wYear, st1.wMonth, st1.wDay);
        //sprintf(pp.cDatRem2, "'%.4d%.2d%.2d'", st2.wYear, st2.wMonth, st2.wDay);
        strcpy(pp.cDatRem1, m_Dt3.GetSQLDate());
        strcpy(pp.cDatRem2, m_Dt4.GetSQLDate());
    }
    CButton *bn	= (CButton *)GetDlgItem(IDC_RADIO1);
    if( bn->GetCheck() )
    {
        m_Dt5.GetTime(&st1);
        m_Dt6.GetTime(&st2);
        sprintf(cFilter, "%sAND PRIHOD_KP.RASH_DAT >= \"%.4d%.2d%.2d\" AND PRIHOD_KP.RASH_DAT <=\"%.4d%.2d%.2d\" ",
                cFilter, st1.wYear, st1.wMonth, st1.wDay, st2.wYear, st2.wMonth, st2.wDay);

        //sprintf(pp.cDatRash1, "'%.4d%.2d%.2d'", st1.wYear, st1.wMonth, st1.wDay);
        //sprintf(pp.cDatRash2, "'%.4d%.2d%.2d'", st2.wYear, st2.wMonth, st2.wDay);
        strcpy(pp.cDatRash1, m_Dt5.GetSQLDate());
        strcpy(pp.cDatRash2, m_Dt6.GetSQLDate());

    } else
    {
        CButton *bn	= (CButton *)GetDlgItem(IDC_RADIO2);
        if( bn->GetCheck() )
        {
            sprintf(cFilter, "%sAND (PRIHOD_KP.PRIZN_RAS<90) ", cFilter);

            strcpy(pp.cNoRash_8, "1");
        }
        else
        {
            CButton *bn	= (CButton *)GetDlgItem(IDC_RADIO3);
            if( bn->GetCheck() )
            {
                sprintf(cFilter, "%s AND (PRIHOD_KP.PRIZN_RAS<=10 AND PRIHOD_KP.TR_REM>0 AND PRIHOD_KP.TR_REM IS NOT NULL) ", cFilter);
                strcpy(pp.cNotIsp_8, "1");
            }            
        }
    }
    //Проверка типов КП
    if( m_Check3.GetCheck() )
    {
        if( m_Combo1.GetCurSel() < 0 ) 
        {
            MessageBox("Некорректно указан тип КП!", "Внимание", MB_OK );
            return;
        }
        sprintf(cFilter, "%sAND PASP1.ITKP=%d", cFilter, dwTKP[m_Combo1.GetCurSel()]);
        sprintf(pp.cTKP_8, "%u", dwTKP[m_Combo1.GetCurSel()]);
    }
    // Проверка выкатки из-под вагона
    char cText[64] = "";
    if( m_Check6.GetCheck() )
    {
        if( !m_Edit2.GetWindowText(cText, 64) )
        {
            strcat(cFilter, "AND NOT(VAG IS NULL) ");
            sprintf(pp.cVagNumIn, "' '", cText);
        } else
        {
            for(unsigned int i=0; i < strlen(cText) && i < 64; i++ ) 
                if( cText[i] == '*' ) cText[i] = '%';
            sprintf(cFilter, "%sAND (VAG=''%s'') ", cFilter, cText);
            sprintf(pp.cVagNumIn, "'%s'", cText);
        }
		if( m_ComboRem1.GetCurSel() >= 0 )
		{
			pp.dwVagRemPrih = m_ComboRem1.GetItemData(m_ComboRem1.GetCurSel());		
		}
    }
    // Проверка подкатки под вагон
    if( m_Check7.GetCheck() )
    {
        if( !m_Edit3.GetWindowText(cText, 64) )
        {
            strcat(cFilter, "AND NOT(RASH_VAG IS NULL) ");
            sprintf(pp.cVagNumOut, "' '", cText);
        } else
        {
            for(unsigned int i=0; i < strlen(cText) && i < 64; i++ ) 
                if( cText[i] == '*' ) cText[i] = '%';
            sprintf(cFilter, "%sAND (RASH_VAG=''%s'') ", cFilter, cText);    
            sprintf(pp.cVagNumOut, "'%s'", cText);
        }
		if( m_ComboRem2.GetCurSel() >= 0 )
		{
			pp.dwVagRemRash = m_ComboRem2.GetItemData(m_ComboRem2.GetCurSel());
		}
    }
    // Проверка прихода с пересылки
    if( m_Check8.GetCheck() )
    {
        if( !m_Edit4.GetWindowText(cText, 64) )
        {
            strcat(cFilter, "AND PERES_IPR IS NOT NULL ");
            strcpy(pp.cIPRRecieved_8, "0");
        } else
        {            
            sprintf(cFilter, "%sAND PERES_IPR=%d ", cFilter, dwPeresIPR);

            itoa(dwPeresIPR, pp.cIPRRecieved_8, 10);
        }
    }
    // Проверка номеров КП
    if( m_Check4.GetCheck() )
    {
        if( !m_Edit1.GetWindowText(cText, 64) )
        {
            MessageBox("Не указано содержание номера КП!", "Внимание", MB_OK);
            return;
        }
        for(unsigned int i=0; i < strlen(cText) && i < 64; i++ ) 
            if( cText[i] == '*' ) cText[i] = '%';
        sprintf(cFilter, "%sAND (PASP1.NKP LIKE ''%%%s%%'') ", cFilter, cText);
        sprintf(pp.cMaskNKP_32, "'%s'", cText);
    }
    // Проверка даты изготовления оси
    if( m_Check11.GetCheck() )
    {
        m_Dt7.GetTime(&st1);
        m_Dt8.GetTime(&st2);
        sprintf(cFilter, "%sAND PASP1.IZOS_DAT>=\''%.4d%.2d%.2d\'' AND PASP1.IZOS_DAT <=''%.4d%.2d%.2d'' ",
                cFilter, st1.wYear, st1.wMonth, st1.wDay, st2.wYear, st2.wMonth, st2.wDay);
        sprintf(pp.cDatIzgOs1, "%s", m_Dt7.GetSQLDate());
        sprintf(pp.cDatIzgOs2, "%s", m_Dt8.GetSQLDate());
    }
    // Проверка даты формирования
    if( m_Check12.GetCheck() )
    {
        m_Dt9.GetTime(&st1);
        m_Dt10.GetTime(&st2);
        sprintf(cFilter, "%sAND PRIHOD_KP.POSFOR_DAT>=\''%.4d%.2d%.2d\'' AND PRIHOD_KP.POSFOR_DAT <=\"%.4d%.2d%.2d\" ",
                cFilter, st1.wYear, st1.wMonth, st1.wDay, st2.wYear, st2.wMonth, st2.wDay);
        sprintf(pp.cDatPosFor1, "%s", m_Dt9.GetSQLDate());
        sprintf(pp.cDatPosFor2, "%s", m_Dt10.GetSQLDate());

    }
    // Проверка изготовителя оси
    if( m_Check10.GetCheck())
    {
		if( !dwOsIPR )
		{
			MessageBox("Не указано клеймо изготовления оси!", "Внимание", MB_OK);
			return;
		}
		else
        {
			sprintf(cFilter, "%sAND PASP1.IZOS_IPR=%d ", cFilter, dwOsIPR);
            //itoa(dwOsIPR, pp.cIzgOsIPr_16, 10);
			m_Edit5.GetWindowText( pp.cIzgOsIPr_16, 10 );
        }
    }
    
    // Проверка кода неисправности
    if( m_Check15.GetCheck() )
    {
        if( !dwNeisp )
        {
            MessageBox("Не указан код неисправности!", "Внимание", MB_OK);
            return;
        }
        sprintf(cFilter, "%sAND PRIHOD_KP.PRIH_NEISP=%d ", cFilter, dwNeisp);
        itoa(dwNeisp, pp.cNeispID_8, 10);
    }
    //Контроль требуемого ремонта
    if( m_Check5.GetCheck() )
    {
        if( m_Combo2.GetCurSel() < 0 )
        {
            MessageBox("Не указан вид ремонта КП!", "Внимание", MB_OK);
            return;
        }
		switch(dwRemKP[m_Combo2.GetCurSel()])
		{
		case 0:
			sprintf(cFilter, "%sAND REM_KP.KOD_REM IS NULL AND ZAPRES_KP.DAT_FOR IS NULL ", cFilter, dwRemKP[m_Combo2.GetCurSel()]);
		break;
		case 1:
		case 2:
			sprintf(cFilter, "%sAND REM_KP.KOD_REM = %d ", cFilter, dwRemKP[m_Combo2.GetCurSel()]);
		break;
		case 3:
			sprintf(cFilter, "%sAND ZAPRES_KP.DAT_FOR IS NOT NULL ", cFilter);
		break;
		case 4:
			sprintf(cFilter, "%sAND PRIHOD_KP.TR_REM = %d AND PRIHOD_KP.PRIZN_RAS > 90 ", cFilter, dwRemKP[m_Combo2.GetCurSel()]);
		break;
		default:
			sprintf(cFilter, "%sAND PRIHOD_KP.TR_REM = %d ", cFilter, dwRemKP[m_Combo2.GetCurSel()]);
		break;
		}
//        sprintf(cFilter, "%sAND REM_KP.KOD_REM=%d ", cFilter, dwRemKP[m_Combo2.GetCurSel()]);
        itoa(dwRemKP[m_Combo2.GetCurSel()], pp.cTypeRemID_8, 10);
    }

	if( m_Check14.GetCheck() )
	{
		char cText1[64] = "";
/*		if( !m_Edit7.GetWindowText(cText, 10) && !m_Edit6.GetWindowText(cTex))
		{
			MessageBox("Не указаны границы диаметров!", "Внимание!!!", MB_OK);
			return;
		}
*/
		m_Edit7.GetWindowText(cText, 10);
		m_Edit10.GetWindowText(cText1, 10);
 		if( cText[0] )
		{
			sprintf(cFilter, "%sAND ((PRIHOD_KP.DKK_L >= %s AND PRIHOD_KP.DKK_R >= %s)OR(PRIHOD_KP.DKK_L IS NULL AND PRIHOD_KP.PRIH_DL >= %s AND PRIHOD_KP.PRIH_DR >= %s )) ",
				cFilter, cText, cText, cText, cText);
            strcpy(pp.cDKK1_16, cText);
		}
		if( cText1[0] )
		{
			sprintf(cFilter, "%sAND ((PRIHOD_KP.DKK_L <= %s AND PRIHOD_KP.DKK_R <= %s)OR(PRIHOD_KP.DKK_L IS NULL AND PRIHOD_KP.PRIH_DL <= %s AND PRIHOD_KP.PRIH_DR <= %s )) ",
				cFilter, cText1, cText1, cText1, cText1);
            strcpy(pp.cDKK2_16, cText1);
		}
	}
    if( m_Check16.GetCheck() )
    {
        switch( m_Combo3.GetCurSel() )
        {
        case 0: sprintf(cFilter, "%sAND (REM_KP.Kod_Neisp_Obt is not NULL) ", cFilter ); strcpy(pp.cPriznObt_8, "1"); break;
        case 1: sprintf(cFilter, "%sAND (REM_KP.Kod_Neisp_Obt is NULL) ", cFilter ); strcpy(pp.cPriznObt_8, "0"); break;
        default: MessageBox("Не указан признак обточки!", "Внимание", MB_OK); return;
        }
    }
	char cQ[512] = "";
	// Проверка выборки двойников
	CDlgBDSelectRez Dlg;    
    Dlg.iParent = 1;
	if( m_Check9.GetCheck() )
	{
//	    sprintf(Dlg.cQ, "pTov_BDKPSelect 1, %d, '%s'", g_iDep, cFilter);
        strcpy(pp.cDv_8, "1");
	} 
/*    
    else
	{
	    sprintf(Dlg.cQ, "pTov_BDKPSelect 0, %d, '%s'", g_iDep, cFilter);
	}
*/
	pp.iSpis = m_CheckSpis.GetCheck();
	char cProc[64] = "pTov_BDKPSelect ";

	if( iSelectCount )
	{
		strcpy(cProc, "pTov_BDKPSelectCount ");
	}
	char cSobstPrih[32] = "";
	itoa(m_EdSobst.GetData(), cSobstPrih, 10);

	if( m_Check17.GetCheck() )
	{
		sprintf(cSobstPrih, "%u", m_EdSobst.GetData());
	} else
		sprintf(cSobstPrih, "NULL");

    sprintf(Dlg.cQ, "%s %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s",
            cProc,
			g_iDep,
			isAble( m_Check1.GetCheck(), m_Dt1.GetSQLDate()),
            isAble( m_Check1.GetCheck(), m_Dt2.GetSQLDate()),
            isAble( m_Check2.GetCheck(), m_Dt3.GetSQLDate()),
            isAble( m_Check2.GetCheck(), m_Dt4.GetSQLDate()),
            isAble( bn->GetCheck(), m_Dt5.GetSQLDate()),
            isAble( bn->GetCheck(), m_Dt6.GetSQLDate()),

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
			isAble( m_Check11.GetCheck(), m_Dt7.GetSQLDate()),
            isAble( m_Check11.GetCheck(), m_Dt8.GetSQLDate()),
            isAble( m_Check12.GetCheck(), m_Dt9.GetSQLDate()),
            isAble( m_Check12.GetCheck(), m_Dt10.GetSQLDate()),

            pp.cDKK1_16,
            pp.cDKK2_16,
            pp.cNeispID_8,
            pp.cPriznObt_8,
			isNull(pp.dwVagRemPrih),
			isNull(pp.dwVagRemRash),
			pp.iSpis,
			cSobstPrih
			);

    Dlg.pp = pp;
	Dlg.iMode = 1;	
	if( !iSelectCount )
	{
		if( Dlg.DoModal() == IDCANCEL ) return;
	}
	else
	{
		CPrintableDlg Dlg1;
		strcpy(Dlg1.cQ, Dlg.cQ);
		Dlg1.DoModal();		
		return;
	}
	CDlgWithAccelerators::OnOK();
}

BOOL CDlgDBKPSelect::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();

    m_Dt7.SetMode(3);
    m_Dt8.SetMode(3);
    m_Dt9.SetMode(3);
    m_Dt10.SetMode(3);

    char cText[32];
    long Ind = 0;
    EnableCtrls(FALSE);
    DBW.ExecSQL("pTov_GetTKP");
    for(WORD i=0; (g_sqlret = DBW.Fetch())!= SQL_NO_DATA &&
          g_sqlret != SQL_ERROR; i++ )
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwTKP[i], 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Combo1.AddString(cText);
    }
    DBW.CloseCursor();

    DBW.ExecSQL("pTov_GetRemKP");
    for(WORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 255;)
    {
        DBW.GetData( 1, SQL_C_SLONG, &dwRemKP[i], 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 30, &Ind);
        if( Ind != -1 ) 
        {
            m_Combo2.AddString(cText);
            i++;
        }
    }
    DBW.CloseCursor();

	DBW.FillComboWithTRemVag(&m_ComboRem1);
	DBW.FillComboWithTRemVag(&m_ComboRem2);

//	m_Check15.ModifyStyle(WS_VISIBLE, 0);

/*	m_Check16.ModifyStyle(WS_VISIBLE, 0);
	m_Check17.ModifyStyle(WS_VISIBLE, 0);
	m_Combo3.ModifyStyle(WS_VISIBLE, 0);	
	m_Combo4.ModifyStyle(WS_VISIBLE, 0);
*/
//	m_Edit9.ModifyStyle(WS_VISIBLE, 0);
//	m_Edit8.ModifyStyle(WS_VISIBLE, 0);
//	m_Button4.ModifyStyle(WS_VISIBLE, 0);
	

    dwPeresIPR = 0;
    dwOsIPR = 0;
    dwNeisp = 0;
    SetWindowText((CString)"Выборка из базы данных прихода КП " + g_strDepoName);
	return TRUE;
}

void CDlgDBKPSelect::EnableCtrls(BOOL State)
{
    m_Dt1.EnableWindow(State);
    m_Dt2.EnableWindow(State);
    m_Dt3.EnableWindow(State);
    m_Dt4.EnableWindow(State);
    m_Dt5.EnableWindow(State);
    m_Dt6.EnableWindow(State);
    m_Dt7.EnableWindow(State);
    m_Dt8.EnableWindow(State);
    m_Dt9.EnableWindow(State);
    m_Dt10.EnableWindow(State);
    m_Combo1.EnableWindow(State);
    m_Combo2.EnableWindow(State);
    m_Edit1.EnableWindow(State);
    m_Edit2.EnableWindow(State);
    m_Edit3.EnableWindow(State);
    m_Edit4.EnableWindow(State);
    m_Edit7.EnableWindow(State);
    m_Combo3.EnableWindow(State);
    m_Button1.EnableWindow(FALSE);
    m_Button2.EnableWindow(FALSE);
    m_Button4.EnableWindow(FALSE);
    m_Edit10.EnableWindow(FALSE);
	m_ComboRem1.EnableWindow(State);
	m_ComboRem2.EnableWindow(State);
	
	m_EdSobst.EnableWindow(State);
	m_ButSobst.EnableWindow(State);
/*    m_Combo3.EnableWindow(FALSE);
    m_Combo4.EnableWindow(FALSE);
*/
//    m_Edit8.EnableWindow(State);
    
}

void CDlgDBKPSelect::OnButton1() 
{
    CDlgSprav1	Dlg;
	Dlg.iDlgKind = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwPeresIPR = Dlg.ret_dwIPR;
    m_Edit4.SetWindowText(Dlg.cPrName);
}

void CDlgDBKPSelect::OnButton2() 
{
    CDlgSprav1	Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwOsIPR = Dlg.ret_dwIPR;
    m_Edit5.SetWindowText(Dlg.cKodPr);
    m_Edit6.SetWindowText(Dlg.cPrName);
}

void CDlgDBKPSelect::OnButton4() 
{
    CDlgSpravSmp Dlg;
    Dlg.DlgMode = 111;
    Dlg.Style = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwNeisp = Dlg.dwRet;
   
    m_Edit8.SetWindowText(Dlg.cRet);
    m_Edit9.SetWindowText(Dlg.c_retText3);
}

void CDlgDBKPSelect::OnCheck1() 
{
    if( m_Check1.GetCheck() ) 
    {
        m_Dt1.EnableWindow(TRUE);
        m_Dt2.EnableWindow(TRUE);
        m_Dt1.SetFocus();
    }
    else 
    {
        m_Dt1.EnableWindow(FALSE);
        m_Dt2.EnableWindow(FALSE);
    }
}

void CDlgDBKPSelect::OnCheck2() 
{
    if( m_Check2.GetCheck() ) 
    {
        m_Dt3.EnableWindow(TRUE);
        m_Dt4.EnableWindow(TRUE);
        m_Dt3.SetFocus();
    }
    else 
    {
        m_Dt3.EnableWindow(FALSE);
        m_Dt4.EnableWindow(FALSE);
    }	
}

void CDlgDBKPSelect::OnRadio1() 
{
    m_Dt5.EnableWindow(TRUE);
    m_Dt6.EnableWindow(TRUE);
    m_Dt5.SetFocus();
   	
}

void CDlgDBKPSelect::OnRadio2() 
{
    m_Dt5.EnableWindow(FALSE);
    m_Dt6.EnableWindow(FALSE);
}

void CDlgDBKPSelect::OnRadio3() 
{
    m_Dt5.EnableWindow(FALSE);
    m_Dt6.EnableWindow(FALSE);	
}

void CDlgDBKPSelect::OnCheck3() 
{
    if( m_Check3.GetCheck() ) 
    {
        m_Combo1.EnableWindow(TRUE);
        m_Combo1.SetFocus();
    }
    else 
    {
        m_Combo1.EnableWindow(FALSE);
    }		
}

void CDlgDBKPSelect::OnCheck4() 
{
    if( m_Check4.GetCheck() ) 
    {
        m_Edit1.EnableWindow(TRUE);
        m_Edit1.SetFocus();
    }
    else 
    {
        m_Edit1.EnableWindow(FALSE);
    }		
}

void CDlgDBKPSelect::OnCheck5() 
{
    if( m_Check5.GetCheck() ) 
    {
        m_Combo2.EnableWindow(TRUE);
        m_Combo2.SetFocus();
    }
    else 
    {
        m_Combo2.EnableWindow(FALSE);
    }		
	
}

void CDlgDBKPSelect::OnCheck6() 
{
    if( m_Check6.GetCheck() ) 
    {
        m_Edit2.EnableWindow(TRUE);
        m_Edit2.SetFocus();
		m_ComboRem1.EnableWindow();
    }
    else 
    {
        m_Edit2.EnableWindow(FALSE);
		m_ComboRem1.EnableWindow(FALSE);
    }
}

void CDlgDBKPSelect::OnCheck7() 
{
    if( m_Check7.GetCheck() ) 
    {
        m_Edit3.EnableWindow(TRUE);
        m_Edit3.SetFocus();
		m_ComboRem2.EnableWindow();

    }
    else 
    {
        m_Edit3.EnableWindow(FALSE);
		m_ComboRem2.EnableWindow(FALSE);
    }		
}

void CDlgDBKPSelect::OnCheck8() 
{
    if( m_Check8.GetCheck() ) 
    {
        m_Button1.EnableWindow(TRUE);
    }
    else 
    {
        m_Button1.EnableWindow(FALSE);
    }
}

void CDlgDBKPSelect::OnCheck10() 
{
    if( m_Check10.GetCheck() ) 
    {
        m_Button2.EnableWindow(TRUE);
        m_Button2.SetFocus();
    }
    else 
    {
        m_Button2.EnableWindow(FALSE);
        m_Edit5.SetWindowText("");
        m_Edit6.SetWindowText("");
        dwOsIPR = 0;
    }
}

void CDlgDBKPSelect::OnCheck11() 
{
    if( m_Check11.GetCheck() ) 
    {
        m_Dt7.EnableWindow(TRUE);
        m_Dt8.EnableWindow(TRUE);
        m_Dt7.SetFocus();
    }
    else 
    {
        m_Dt7.EnableWindow(FALSE);
        m_Dt8.EnableWindow(FALSE);
    }	
}

void CDlgDBKPSelect::OnCheck12() 
{
    if( m_Check12.GetCheck() ) 
    {
        m_Dt9.EnableWindow(TRUE);
        m_Dt10.EnableWindow(TRUE);
        m_Dt9.SetFocus();
    }
    else 
    {
        m_Dt9.EnableWindow(FALSE);
        m_Dt10.EnableWindow(FALSE);
    }	
	
}

void CDlgDBKPSelect::OnCheck14() 
{
    if( m_Check14.GetCheck() ) 
    {
        m_Edit7.EnableWindow(TRUE);
        m_Edit10.EnableWindow(TRUE);
        m_Edit7.SetFocus();
    }
    else 
    {
        m_Edit7.EnableWindow(FALSE);
        m_Edit10.EnableWindow(FALSE);
    }
//	AfxMessageBox("oo");
}

void CDlgDBKPSelect::OnCheck15() 
{
    if( m_Check15.GetCheck() ) 
    {
        m_Button4.EnableWindow(TRUE);
        m_Button4.SetFocus();
    }
    else 
    {
        m_Button4.EnableWindow(FALSE);
        m_Edit8.SetWindowText("");
        m_Edit9.SetWindowText("");
        dwNeisp = 0;
    }    	
}

void CDlgDBKPSelect::OnCheck16() 
{
    if( m_Check16.GetCheck() ) 
    {
        m_Combo3.EnableWindow(TRUE);
        m_Combo3.SetFocus();
    }
    else 
    {
        m_Combo3.EnableWindow(FALSE);
    }
}

void CDlgDBKPSelect::OnCheck17() 
{

	m_EdSobst.EnableWindow(m_Check17.GetCheck());
	m_ButSobst.EnableWindow(m_Check17.GetCheck());
	/*    if( m_Check17.GetCheck() ) 
    {
        m_Combo4.EnableWindow(TRUE);
    }
    else 
    {
        m_Combo4.EnableWindow(FALSE);
    }
*/
}

void CDlgDBKPSelect::OnBnClickedOk()
{
	iSelectCount = 0;
	OnOK();
}

void CDlgDBKPSelect::OnBnClickedButton7()
{
	iSelectCount = 1;
	OnOK();
}

void CDlgDBKPSelect::OnBnClickedButton_Sobst()
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
