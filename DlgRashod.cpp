// DlgRashod.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRashod.h"
#include "DlgSpravKdr.h"
#include "DlgSprav1.h"
#include "DlgSprPrSobstv.h"
#include ".\telecom\teleI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern SQLRETURN    g_sqlret;
extern DWORD g_iDep;
extern CMasterApp theApp;
extern SYSTEMTIME g_CurrentDate;

extern CString g_strAsldTeleName;
extern int g_iEnableTelecom;
extern cd_TeleI *tele;
/////////////////////////////////////////////////////////////////////////////
// CDlgRashod dialog

int g_iGotPr  = 0;
extern DWORD		g_dwPrID;
CDlgRashod::CDlgRashod(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgRashod::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgRashod)
	m_strNKP = _T("");
	m_strTKP = _T("");
	//}}AFX_DATA_INIT
    qwIZAP = 0;
    dwKodRem = 0;
    dwIPR = 0;
    bCh1 = false;
    qwIPeres = 0;
    m_EdFam.SetMode(5);
    m_Date1.SetMode(1);
}


void CDlgRashod::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgRashod)
	DDX_Control(pDX, IDC_EDIT10, m_Date1);
	DDX_Control(pDX, IDC_EDIT9, m_EdFam);
	DDX_Control(pDX, IDC_EDIT4, m_EdPrName);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_EDIT8, m_VRem);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_BUTTON1, m_But1);
	DDX_Control(pDX, IDC_EDIT7, m_EdNSpis);
	DDX_Control(pDX, IDC_EDIT6, m_EdNVed);
	DDX_Control(pDX, IDC_EDIT5, m_EdPred);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_EDIT3, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT11, m_EdSobst);
	DDX_Text(pDX, IDC_EDIT1, m_strNKP);
	DDX_Text(pDX, IDC_EDIT2, m_strTKP);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgRashod, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgRashod)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_BN_CLICKED(IDC_RADIO3, OnRadio3)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_EN_KILLFOCUS(IDC_EDIT5, OnKillfocusKlPr)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CDlgRashod::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgRashod::OnBnClickedButton_Sobst)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgRashod message handlers

BOOL CDlgRashod::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
	m_EdNVag.QInit(80,1);
//    m_EdNVag.EnableWindow(FALSE);
//    m_Combo2.EnableWindow(FALSE);
    m_EdPred.EnableWindow(FALSE);
    m_But1.EnableWindow(FALSE);
    m_EdNVed.EnableWindow(FALSE);
    m_EdNSpis.EnableWindow(FALSE);

	m_EdSobst.SetMode(0, 1);
	m_EdSobst.ModifyStyle(0, WS_DISABLED);

    m_Date1.InitDate();
    char cQ[512] = "EXEC pTov_GetTypeRemVag";
    DWORD dwNum = 0;
    char cText[64] = "";
    long    Ind = 0;

    DBW.ExecSQL(cQ);
    for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 64; i++ )
    {
        DBW.GetData( 1, SQL_C_ULONG, &dwNum, 8, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        m_Combo2.AddString(cText);
        dwTRemVag[i] = dwNum;
    }
    DBW.CloseCursor();
    m_Combo1.SetCurSel(1);

    m_EdPrName.ModifyStyle(0, WS_DISABLED);    
    
    CButton *bn	= (CButton *)GetDlgItem(IDC_RADIO1);
    bn->SetCheck(1);
    OnRadio1();

    if( InitFormValues() == -1 ) return FALSE;
	return TRUE;
}

int CDlgRashod::InitFormValues()
{
    char            cQ[512] = "";
    char            cText[64] = "";
    SQL_DATE_STRUCT date;
    short int       siNum = 0;
    long            Ind = 0;
	DWORD			dwNum = 0;
    sprintf(cQ, "pTov_GetRashodInitValues %I64u", qwIZAP );
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_TYPE_DATE, &date, sizeof(SQL_DATE_STRUCT), &Ind);
    if( Prih.dwPriznRas == 11 || Prih.dwPriznRas == 12 )
    {
        if( Ind == -1 )
        {
            MessageBox("Не найдена информация о ремонте КП!", "МКЦ", MB_OK | MB_ICONINFORMATION);
            DBW.CloseCursor();
            return -1;
        }
        SqlDateToSysTime(date, &Prih.dt5);
        DBW.GetData( 2, SQL_C_ULONG, &dwKodRem, sizeof(dwKodRem), &Ind);
        DBW.GetData( 3, SQL_C_CHAR, cText, 64, &Ind);
        m_VRem.SetWindowText(cText);
        DBW.GetData( 4, SQL_C_TYPE_DATE, &date, sizeof(SQL_DATE_STRUCT), &Ind);
        // Предупреждение о непроизведенных операциях
        if( Ind == -1 )
        {
            MessageBox("Не заведена информация о монтаже букс.", "Предупреждение", MB_OK | MB_ICONINFORMATION);
        }
    } else
    if( Prih.dwPriznRas > 19 )
    {
        m_VRem.SetWindowText("Смена элементов");
    } else
    {
        if( Prih.dwTREB_REM > 0 )
            MessageBox("Не заведена информация о ремонте КП.", "Предупреждение", MB_OK | MB_ICONINFORMATION);
        m_VRem.SetWindowText("Ремонт не производился");
        Prih.dt5 = Prih.stDatPost;
    }
    DBW.GetData( 5, SQL_C_SSHORT, &siNum, sizeof(siNum), &Ind);
    if( Ind != -1 )
    {
        switch (siNum)
        {
        case 0: //  пассажирская
            m_Combo1.SetCurSel(0);
            m_Check1.EnableWindow(FALSE);
            break;
        case 2: //  буква Г на ободе
            m_Combo1.EnableWindow(FALSE);
            m_Check1.SetCheck(1);
            bCh1 = true;
            break;
        case 4: // разута отменяется монтажом
            m_Combo1.SetCurSel(2);
            m_Combo1.EnableWindow(FALSE);
            m_Check1.EnableWindow(FALSE);
            break;
        case 5: // ось отменяется формированием
            m_Combo1.SetCurSel(3);
            m_Combo1.EnableWindow(FALSE);
            m_Check1.EnableWindow(FALSE);
            break;
        }
    }
    else
        m_Combo1.SetCurSel(-1);
        DBW.GetData( 6, SQL_C_ULONG, &dwNum, sizeof(dwNum), &Ind);
		if( Ind != -1 ) m_EdSobst.SetData(dwNum);
		DBW.GetData( 7, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdSobst.SetWindowText(cText);
		


    DBW.CloseCursor();
    return 0;
}

void CDlgRashod::OnRadio1() 
{
    CButton *bn	= (CButton *)GetDlgItem(IDC_RADIO2);
    bn->SetCheck(0);
    bn	= (CButton *)GetDlgItem(IDC_RADIO3);
    bn->SetCheck(0);
    m_EdNVag.EnableWindow(TRUE);
    m_Combo2.EnableWindow(TRUE);
    m_EdPred.EnableWindow(FALSE);
    m_But1.EnableWindow(FALSE);
    m_EdNVed.EnableWindow(FALSE);
    m_EdNSpis.EnableWindow(FALSE);
    
    m_EdFam.SetWindowText("");
    m_EdFam.SetData(0);

    DBW.FillEmplArray(m_EdFam.lpEmpl, 10 );
    m_EdNVag.SetFocus();
}

void CDlgRashod::OnRadio2()
{
    CButton *bn	= (CButton *)GetDlgItem(IDC_RADIO1);
    bn->SetCheck(0);
    bn	= (CButton *)GetDlgItem(IDC_RADIO3);
    bn->SetCheck(0);
    m_EdNVag.EnableWindow(FALSE);
    m_Combo2.EnableWindow(FALSE);
    m_EdPred.EnableWindow(TRUE);
    m_But1.EnableWindow(TRUE);
    m_EdNVed.EnableWindow(TRUE);
    m_EdNSpis.EnableWindow(FALSE);

    m_EdFam.SetData(0);
    DBW.FillEmplArray(m_EdFam.lpEmpl, 8);
    m_EdFam.SetWindowText("");
    m_EdPred.SetFocus();
}

void CDlgRashod::OnRadio3()
{
    CButton *bn	= (CButton *)GetDlgItem(IDC_RADIO1);
    bn->SetCheck(0);
    bn	= (CButton *)GetDlgItem(IDC_RADIO2);
    bn->SetCheck(0);
    m_EdNVag.EnableWindow(FALSE);
    m_Combo2.EnableWindow(FALSE);
    m_EdPred.EnableWindow(FALSE);
    m_But1.EnableWindow(FALSE);
    m_EdNVed.EnableWindow(FALSE);
    m_EdNSpis.EnableWindow(TRUE);

    m_EdFam.SetData(0);
    DBW.FillEmplArray(m_EdFam.lpEmpl, 8);
    m_EdFam.SetWindowText("");
    m_EdNSpis.SetFocus();
}

void CDlgRashod::OnButton1() 
{
	/*
    CDlgSprav1 Dlg;	
    Dlg.iDlgKind = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    dwIPR = Dlg.ret_dwIPR;
    m_EdPred.SetWindowText(Dlg.cKodPr);
    m_EdPrName.SetWindowText(Dlg.cPrName);
	*/
	CDlgSprPrSobstv Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

    m_EdPred.SetWindowText(Dlg.cKlPr);
	dwIPR = Dlg.dwSobstID;
	m_EdPrName.SetWindowText(Dlg.cPrName);
}

void CDlgRashod::OnButton2() 
{
    int iFilter = 0;
    CButton *bn1 = (CButton *)GetDlgItem(IDC_RADIO1);
    CButton *bn2 = (CButton *)GetDlgItem(IDC_RADIO2);
    CButton *bn3 = (CButton *)GetDlgItem(IDC_RADIO3);
    if( !(bn1->GetCheck() || bn2->GetCheck() || bn3->GetCheck()) )
    {
        MessageBox("Не указанo, каким образом израсходована КП. Повторите ввод!",
                   "Контроль ввода",
                    MB_OK | MB_ICONINFORMATION);
        return;
    }
    if( bn1->GetCheck() ) iFilter = 10;
    else iFilter = 8;
    CDlgSpravKdr Dlg;
    Dlg.iFilter = iFilter;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdFam.SetWindowText(Dlg.cFio);
    m_EdFam.SetData(Dlg.dwFio);
}

void CDlgRashod::OnOK() 
{
    char c_cR[128] = "";
    char cQ[512] = "";
    
    char cpRashRemVag[32] = "";
    char cpRashVag[32] = "";
    char cpRashIpr[32] = "";
    char cpRashPeresNved[32] = "";
    char cpRashNspis[32] = "";

	int iNeedVedHdr = 0;

    CButton *bn1 = (CButton *)GetDlgItem(IDC_RADIO1);
    CButton *bn2 = (CButton *)GetDlgItem(IDC_RADIO2);
    CButton *bn3 = (CButton *)GetDlgItem(IDC_RADIO3);
    char cText[2550] = "";
    m_Date1.GetTime(&Prih.dt6);
    if( SysDateCmp(Prih.stDatPost, Prih.dt6 ) > 0 )
    {
        MessageBox("Дата расхода не может быть раньше даты поступления (ремонта).",
                   "Контроль ввода",
                    MB_OK | MB_ICONINFORMATION);
        return;
    }
	GetLocalTime(&g_CurrentDate);
    if( SysDateCmp(Prih.dt6, g_CurrentDate) > 0 )
    {
        MessageBox("Указанная дата еще не наступила.",
                   "Контроль ввода",
                   MB_OK | MB_ICONINFORMATION);
        return;
    }
    CString strNVag;
    m_EdNVag.GetWindowText(strNVag);
    if( bn1->GetCheck() &&  !VanNumberIsValid(strNVag) )
    {
        if( MessageBox("Не сходится контрольная сумма номера вагона! Исправить?",
                   "Контроль ввода",
                   MB_YESNO | MB_ICONINFORMATION) == IDYES)
        {
            m_EdNVag.SetFocus();
            return;
        }
    }
    // Фамилия работника
    if( !m_EdFam.GetData() )
    {
        MessageBox("Не указана фамилия производившего расход.",
                   "Контроль ввода", 
                   MB_OK | MB_ICONINFORMATION);
        return;
    }
    // Куда израсходованa
    if( bn1->GetCheck() )
    {
        // Контроль расхода под вагон
        m_EdNVag.GetWindowText(cText, 64);
        if( !cText[0] || strlen(cText) > 8 )
        {
            MessageBox("Некорректно указан номер вагона.",
                       "Контроль ввода", 
                        MB_OK | MB_ICONINFORMATION);
            return;
        }
        // Тип ремонта вагона
        if( m_Combo2.GetCurSel() == -1 )
        {
            MessageBox("Некорректно указан вид ремонта вагона.",
                       "Контроль ввода", 
                        MB_OK | MB_ICONINFORMATION);
            return;
        }
/*        sprintf(c_cR, "RASH_REM_VAG = %u, RASH_VAG = %s, RASH_IPR=NULL, RASH_PERES_NVED=NULL, RASH_NSPIS=NULL", 
                dwTRemVag[m_Combo2.GetCurSel()], cText);*/
        ultoa(dwTRemVag[m_Combo2.GetCurSel()], cpRashRemVag, 10);
        sprintf(cpRashVag, "'%s'", cText);
        strcpy(cpRashIpr, "NULL");
        strcpy(cpRashPeresNved, "NULL");
        strcpy(cpRashNspis, "NULL");
    } else
    if( bn2->GetCheck() )
    {
        // Контроль расхода пересылкой
        if( !dwIPR )
        {
            MessageBox("Не указано клеймо предприятия.",
                       "Контроль ввода", 
                        MB_OK | MB_ICONINFORMATION);
            return;            
        }
        if( !m_EdNVed.GetWindowTextLength() )
        {
            MessageBox("Не указан номер пересылочной ведомости.",
                       "Контроль ввода", 
                        MB_OK | MB_ICONINFORMATION);
            return; 
        }
        m_EdNVed.GetWindowText(cText, 64);
        if( strlen(cText) > 3 )
        {
            MessageBox("Слишком много цифр в номере пересылочной ведомости\nили номер ведомости введен некорректно.",
                       "Контроль ввода", 
                        MB_OK | MB_ICONINFORMATION);
            return; 
        }
/*        sprintf(c_cR, "RASH_VAG=NULL, RASH_IPR=%u, RASH_PERES_NVED=%s, RASH_NSPIS=NULL",
                dwIPR, cText);*/
        strcpy(cpRashRemVag, "NULL");
        strcpy(cpRashVag, "NULL");
        ultoa(dwIPR, cpRashIpr, 10);
        strcpy(cpRashPeresNved, cText);
        strcpy(cpRashNspis, "NULL");                
    } else
    if( bn3->GetCheck() )
    {
        if( !m_EdNSpis.GetWindowTextLength() )
        {
            MessageBox("Не указан номер акта на списание.",
                       "Контроль ввода", 
                        MB_OK | MB_ICONINFORMATION);
            return; 
        }
        m_EdNSpis.GetWindowText(cText, 64);
        if( !atoi(cText) || strlen(cText) > 3 )
        {
            MessageBox("Слишком много цифр в номере акта на списание\nили номер акта введен некорректно.",
                       "Контроль ввода", 
                        MB_OK | MB_ICONINFORMATION);
            return; 
        }
/*        sprintf(c_cR, "RASH_VAG=NULL, RASH_IPR=NULL, RASH_PERES_NVED=NULL, RASH_NSPIS=%s",
                cText);*/
        strcpy(cpRashRemVag, "NULL");
        strcpy(cpRashVag, "NULL");
        strcpy(cpRashIpr, "NULL");
        strcpy(cpRashPeresNved, "NULL");
        strcpy(cpRashNspis, cText);

    } else
    {
        MessageBox("Не указано, каким образом израсходована КП.",
                   "Контроль ввода", 
                   MB_OK | MB_ICONINFORMATION);
        return;
    }
    // Грузовая пассажирская
    char c_GP[16] = "";
    if( m_Check1.GetCheck() )
    {
        strcpy(c_GP, "2");
    } else
    switch (m_Combo1.GetCurSel())
    {
    case 0: strcpy(c_GP, "0"); break;
    case 1: strcpy(c_GP, "1"); break;
    case 2: strcpy(c_GP, "4"); break;
    case 3: strcpy(c_GP, "5"); break;
    default: strcpy(c_GP, "NULL");
    }
    DateToSql(Prih.dt6, cText);
    if( bn2->GetCheck() )
    {
        CString strQ;
        SYSTEMTIME st;
        long Ind = 0;
        ZeroMemory(&st, sizeof(st));
        int ret = 0;
        m_Date1.GetTime(&st);
        strQ.Format("pTov_CheckPeres %u, '%s', %u, %s, %u",
                    g_iDep, cpRashPeresNved, dwIPR, DateToSQL(st), m_EdFam.GetData());
        DBW.ExecSQL(strQ);
        DBW.Fetch();
        DBW.GetData(1, SQL_C_SLONG, &ret, 4, &Ind);
        if( Ind == -1 )
        {
            AfxMessageBox("Ошибка БД!");
            DBW.CloseCursor();
            return;
        }
        if( ret == -1 )
        {
            DBW.GetData(2, SQL_C_CHAR, cText, 200, &Ind);
            MessageBox(cText,
                   "Внимание", 
                   MB_OK | MB_ICONINFORMATION);
            DBW.CloseCursor();
            return;
        } else
        if( ret == 1 )
        {
            DBW.GetData(2, SQL_C_CHAR, cText, 200, &Ind);
            int r = MessageBox(cText,
                   "Внимание", 
                   MB_YESNOCANCEL | MB_ICONINFORMATION);
            if( r == IDCANCEL ) 
			{
				DBW.CloseCursor();
				return;
			}
            if( r == IDYES )
            {

                DBW.CloseCursor();
/*
				strQ.Format("pTov_InsertVedHdr %u, %s, %s, %u, NULL, NULL, %u, NULL, %u",
                    g_iDep,
                    cpRashPeresNved,
                    DateToSQL(st),
                    dwIPR,
                    m_EdFam.GetData(),
                    g_iFam);
*/
				
				strQ.Format("pTov_KP_WriteVedHdr %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %u",
						"NULL",
						isNull(g_iDep),
						cpRashPeresNved, //NVED
						 DateToSQL(st), //дата отправки
						"NULL",//дата получения

						isNull(g_dwPrID), // здесь надо включить свой ipr из таблицы partners
						isNull(dwIPR),
						isNull(m_EdSobst.GetData()),

						"null",
						1,
						m_EdNVag.GetAsString(),

						isNull(m_EdFam.GetData()), //мастер отправитель
						"NULL", //приемщик

						"NULL",
						isNull(g_iFam),
						1 );

                DBW.ExecSQL(strQ);
                DBW.Fetch();
                DBW.GetData(2, SQL_C_UBIGINT, &qwIPeres, 8, &Ind);
                sprintf(cpRashNspis, "%I64u", qwIPeres);
                DBW.CloseCursor();
				iNeedVedHdr = 1;
				
				if( g_iGotRezervDBW )
				{
					strQ.Format("pTov_KP_WriteVedHdr %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %u",
						isNull(qwIPeres),
						isNull(g_iDep),
						cpRashPeresNved, //NVED
						 DateToSQL(st), //дата отправки
						"NULL",//дата получения

						isNull(g_dwPrID), // здесь надо включить свой ipr из таблицы partners
						isNull(dwIPR),
						isNull(m_EdSobst.GetData()),

						"null",
						1,
						m_EdNVag.GetAsString(),

						isNull(m_EdFam.GetData()), //мастер отправитель
						"NULL", //приемщик

						"NULL",
						isNull(g_iFam),
						1 );
					 DBWrez.ExecSQL(strQ);
					 DBWrez.CloseCursor();
				}

            } else
            {
                qwIPeres = 0;
            }
        } else
        {
                DBW.GetData(2, SQL_C_UBIGINT, &qwIPeres, 8, &Ind);
        }
        DBW.CloseCursor();
    }
    SYSTEMTIME st;
    ZeroMemory(&st, sizeof(st));
    m_Date1.GetTime(&st);
    sprintf(cQ, "pTov_KP_RashodKP %I64u, %u, %u, %s, %u, %s, %s, %s, %s, %s, %s, NULL, %s, %s",
                qwIZAP,
                g_iDep,
                91+(Prih.dwPriznRas / 10),
                c_GP,
                m_EdFam.GetData(),
                DateToSQL(st),
                cpRashRemVag,
                cpRashVag,
                cpRashIpr,
                cpRashPeresNved,
                cpRashNspis,
                isNull(qwIPeres),
				isNull(m_EdSobst.GetData()));

    DBW.ExecSQL(cQ);
    DBW.CloseCursor();
    DBW.ReallocHandle();

	if( g_iGotRezervDBW )
	{
		DBWrez.ExecSQL(cQ);
		DBWrez.CloseCursor();
		DBWrez.ReallocHandle();
	}

	DWORD dwRet = 0;
		//char cText[2255] = "";
		//char cQ[128] = "";
	if( g_iEnableTelecom && g_strAsldTeleName )
	{
				sprintf( cQ, "pTov_KP_SendToAsuV %s", isNull(qwIZAP) );		
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
							//m_SendToAsuv.EnableWindow(0);
					}
	} else
	{
		AfxMessageBox("Невозможно отправить в АСЛД из-за некорректных настроек телеобработки!");
	}

	CDlgWithAccelerators::OnOK();
}

void CDlgRashod::OnKillfocusKlPr() 
{
    CString str;
    m_EdPred.GetWindowText(str);
    if( str == "" )
    {
        dwIPR = 0;
        m_EdPrName.SetWindowText("");
        return;
    }
    char cText[32] = "";
    char cQ[128] = "";
    long Ind = 0;

    sprintf(cQ, "pTov_GetPrByKl '%s'", str);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwIPR, 4, &Ind);
    DBW.GetData( 6, SQL_C_CHAR, cText, 32, &Ind);
    DBW.CloseCursor();

    if( g_sqlret == SQL_NO_DATA || g_sqlret == SQL_ERROR || cText[0] == 0 )
    {
        MessageBox("Введено некорректное клеймо!" ,"Внимание", MB_OK| MB_ICONINFORMATION);
        m_EdPrName.SetWindowText("");
        m_EdPred.SetFocus();
        return;
    }
    m_EdPrName.SetWindowText(cText);
    m_EdNVed.SetFocus();
}

void CDlgRashod::OnCancel() 
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;	
	CDlgWithAccelerators::OnCancel();
}

void CDlgRashod::OnBnClickedOk()
{
	OnOK();
}

void CDlgRashod::OnBnClickedButton_Sobst()
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
