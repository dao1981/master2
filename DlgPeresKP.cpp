// DlgPeresKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPeresKP.h"
#include "DlgAddPeres.h"
#include "PrintableDlg.h"
#include "DlgSprav1.h"
#include "DlgSpravKdr.h"
#include <sqlext.h>
#include ".\dlgpereskp.h"
#include ".\telecom\teleI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp   theApp;
extern BYTE gs_DateFmt;

extern DWORD g_iDep;
extern CString g_strAsldTeleName;
extern int g_iEnableTelecom;
extern bool g_LogEnabled;
extern cd_TeleI *tele;

/////////////////////////////////////////////////////////////////////////////
// CDlgPeresKP dialog


CDlgPeresKP::CDlgPeresKP(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPeresKP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgPeresKP)
	//}}AFX_DATA_INIT
    iRecieveMode = 0;
}


void CDlgPeresKP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPeresKP)
	DDX_Control(pDX, IDOK, m_ButNew);
	DDX_Control(pDX, IDC_BUTTON6, m_ButDelete);
	DDX_Control(pDX, IDC_BUTTON1, m_ButEdit);
	DDX_Control(pDX, IDC_BUTTON8, m_ButSendRecv);
	DDX_Control(pDX, IDC_BUTTON2, m_Radio2);
	DDX_Control(pDX, IDC_BUTTON5, m_ButSelect);
	DDX_Control(pDX, IDC_BUTTON4, m_ButFam);
	DDX_Control(pDX, IDC_EDIT8, m_Ed6);
	DDX_Control(pDX, IDC_EDIT6, m_Ed5);
	DDX_Control(pDX, IDC_EDIT5, m_Ed4);
	DDX_Control(pDX, IDC_BUTTON3, m_ButPred);
	DDX_Control(pDX, IDC_EDIT4, m_Ed3);
	DDX_Control(pDX, IDC_EDIT16, m_Ed2);	
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_CHECK6, m_Check5);
	DDX_Control(pDX, IDC_CHECK5, m_Check4);
	DDX_Control(pDX, IDC_CHECK4, m_Check3);
	DDX_Control(pDX, IDC_CHECK3, m_Check2);
	DDX_Control(pDX, IDC_CHECK2, m_Check1);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_EDIT3, m_Ed1);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPeresKP, CDialog)
	//{{AFX_MSG_MAP(CDlgPeresKP)
	ON_BN_CLICKED(IDOK, OnNewPeres)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButtonPrint)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck1)
	ON_BN_CLICKED(IDC_CHECK3, OnCheck2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_CHECK4, OnCheck3)
	ON_BN_CLICKED(IDC_CHECK5, OnCheck4)
	ON_BN_CLICKED(IDC_CHECK6, OnCheck5)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_EN_CHANGE(IDC_EDIT4, OnChangeEditKleimo)
	ON_EN_CHANGE(IDC_EDIT1, OnChangeFilter)
	ON_BN_CLICKED(IDC_RADIO1, OnRadio1)
	ON_BN_CLICKED(IDC_RADIO2, OnRadio2)
	ON_EN_CHANGE(IDC_EDIT8, OnChangeEdit8)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton_Delete)
	ON_EN_CHANGE(IDC_EDIT2, OnChangeFilter)
	ON_EN_CHANGE(IDC_EDIT3, OnChangeFilter)
	ON_EN_CHANGE(IDC_EDIT16, OnChangeFilter)
	ON_EN_CHANGE(IDC_EDIT6, OnChangeFilter)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton_Send)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlgPeresKP::OnBnClickedButton_SendToASUV)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPeresKP message handlers

BOOL CDlgPeresKP::OnInitDialog() 
{
	CDialog::OnInitDialog();
    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

	long	Ind = 0;

    m_Check1.SetCheck(1);
    SYSTEMTIME st;
    GetLocalTime(&st);

    m_Dat2.SetTime(&st);
    if( st.wMonth == 1 )
    {
        st.wMonth = 12;
        st.wYear--;
    } else
        st.wMonth--;
	if( st.wMonth == 2 && st.wDay > 28)
	{
		st.wDay = 28;
	}
	if( st.wDay == 31 ) st.wDay = 30;
    m_Dat1.SetTime(&st);

    if( iRecieveMode )
    {
        CButton *b1 = NULL, *b2 = NULL;
        b1 = (CButton *)GetDlgItem(IDC_RADIO1);
        b2 = (CButton *)GetDlgItem(IDC_RADIO2);
        m_Check4.ModifyStyle(WS_VISIBLE,0);
        b1->ModifyStyle(WS_VISIBLE,0 );
        b2->ModifyStyle(WS_VISIBLE,0 );
        m_Ed5.ModifyStyle(WS_VISIBLE, 0);
        m_ButSendRecv.SetWindowText("Получить");
        this->SetWindowText("Список приходных пересылочных ведомостей");
		m_Check3.SetWindowText("Отправитель:");
    }
    if( !iRecieveMode )
    {
        sprintf(cQuery, "pTov_GetPeresLog %s, %s, NULL, NULL, NULL, NULL, NULL, NULL, %u", 
                m_Dat1.GetSQLDate(), 
                m_Dat2.GetSQLDate(), 
                g_iDep);
    } else
    {
        sprintf(cQuery, "pTov_GetPeresLog2 %s, %s, NULL, NULL, NULL, NULL, %u", 
                m_Dat1.GetSQLDate(), 
                m_Dat2.GetSQLDate(), 
                g_iDep);
    }
    DBW.ExecSQL(cQuery);
    DBW.SetListHeader(&m_List);
//    DBW.UpdateListByHandle(&m_List);
	RefreshList();
    DBW.CloseCursor();

    m_Ed6.SetMode(5);
    DBW.FillEmplArray(m_Ed6.lpEmpl, 8);
    OnCheck1();
    OnCheck2();
    OnCheck3();
    OnCheck4();
    OnCheck5();

    if( iRecieveMode )
    {
//        m_ButEdit.EnableWindow(FALSE);

//        m_ButNew.EnableWindow(FALSE);
//        m_ButDelete.EnableWindow(FALSE);
    }
	return TRUE;
}

void CDlgPeresKP::OnNewPeres() 
{
    CDlgAddPeres Dlg;

	if( iRecieveMode )
	{
		Dlg.iCreateRecieveMode = 1;
		Dlg.iRecieveMode = 1;
		Dlg.DoModal();
		OnButton5();
		return;
	}

    if( Dlg.DoModal() == IDCANCEL ) return;
    char cQ[256] = "";
    char cText[64] = "";
// Запись в базу заголовка ведомости

    if( Dlg.m_iPrRem == -1 )
    {
        strncpy(cText, "NULL", 6);
    }
    else
    {
        itoa(Dlg.m_iPrRem + 1, cText, 10);
    }
	/*
    sprintf(cQ, "pTov_InsertVedHdr %d, %u, '%s', %d, %s, '%s', %d, %s, %d, %u, %s",
                g_iDep,
                Dlg.m_Edit1Num,
                Dlg.cVedDate,
                Dlg.dwIPR_Rcv,
                cText,
                Dlg.m_cVagNum,
                Dlg.dwFIO_Mast,
                isNull(Dlg.dwFIO_Priem),
                g_iFam,
                Dlg.iOnVag,
				isNull(Dlg.dwIPR_Sobst));
*/
			sprintf(cQ, "pTov_KP_WriteVedHdr %s, %s, %s, '%s', %s, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %u",
						isNull(Dlg.qwIPeres),
						isNull(g_iDep),
						isNull((DWORD)Dlg.m_Edit1Num), //NVED
						Dlg.cVedDate, //дата отправки
						"NULL",//дата получения

						isNull(Dlg.dwIPR_Snd),
						isNull(Dlg.dwIPR_Rcv),
						isNull(Dlg.dwIPR_Sobst),

						cText,
						Dlg.iOnVag,
						isNull(Dlg.m_cVagNum),

						isNull(Dlg.dwFIO_Mast), //мастер отправитель
						isNull(Dlg.dwFIO_Priem), //приемщик

						isNull(Dlg.dwFIO_MastRcv),
						isNull(g_iFam),
						1 );


    DBW.ExecSQL(cQ);
    DBW.Fetch();
    __int64 qwIPeres = 0; 
    long Ind = 0;
    DBW.GetData(1, SQL_C_UBIGINT, &qwIPeres, 8, &Ind);
    if( g_sqlret == SQL_ERROR || Ind == -1 )
    {
		DBW.WriteLog("Нет IPeres!");
		DBW.CloseCursor();
		DBW.ReallocHandle();
        return;
    }
    DBW.CloseCursor();
	DBW.ReallocHandle();

	if( g_iGotRezervDBW )
	{
			sprintf(cQ, "pTov_KP_WriteVedHdr %s, %s, %s, '%s', %s, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %u",
						isNull(qwIPeres),
						isNull(g_iDep),
						isNull((DWORD)Dlg.m_Edit1Num), //NVED
						Dlg.cVedDate, //дата отправки
						"NULL",//дата получения

						isNull(Dlg.dwIPR_Snd),
						isNull(Dlg.dwIPR_Rcv),
						isNull(Dlg.dwIPR_Sobst),

						cText,
						Dlg.iOnVag,
						isNull(Dlg.m_cVagNum),

						isNull(Dlg.dwFIO_Mast), //мастер отправитель
						isNull(Dlg.dwFIO_Priem), //приемщик

						isNull(Dlg.dwFIO_MastRcv),
						isNull(g_iFam),
						1 );
			DBWrez.ExecSQL(cQ);
			DBWrez.CloseCursor();
			DBWrez.ReallocHandle();
	}

    DWORD x=Dlg.dwPriznRas[0];
// Выполнение расхода КП, занесенным при последнем редактировании
/*
	for( DWORD i=0; i < Dlg.dwKPCount; i++ )
    {
        // Занесение паспортных данных
        sprintf(cQ, "pTov_RashodKP %I64u, %u, %u, %u, %u, '%s', NULL, NULL, %u, %u, NULL, NULL, %I64u",
            Dlg.qwIZAP[i], 
            g_iDep,
            91 + Dlg.dwPriznRas[i] / 10,
            Dlg.dwGruz[i],
            Dlg.dwFIO_Mast,
            Dlg.cVedDate,
            Dlg.dwIPR_Rcv,
            Dlg.m_Edit1Num,
            qwIPeres);
		
		sprintf(cQRez, "%s\nexec pTov_RashodKP_Rez 0, '%s', %u, %s, %s, %s,  %u, %u, %u, %u, '%s', NULL, NULL, %u, %u, NULL, NULL, @IPeres",
			cQRez,
			Dlg.cNKP[i],
			Dlg.p_dwTKP[i],
			DateToSQL(Dlg.stDatIzg[i]),
			isNull(Dlg.dwIPrIzg[i]),
			isNull(g_iFam),
			
            g_iDep,
            91 + Dlg.dwPriznRas[i] / 10,
            Dlg.dwGruz[i],
            Dlg.dwFIO_Mast,
            Dlg.cVedDate,
            Dlg.dwIPR_Rcv,
            Dlg.m_Edit1Num);


//        AfxMessageBox(cQ);

		DBW.ExecSQL(cQ);
        DBW.CloseCursor();
        DBW.ReallocHandle();
//        DBW.CloseCursor();
    }
*/

	for( DWORD i=0; i < Dlg.dwKPCount; i++ )
    {
		cQ[0] = 0;
		if( Dlg.p_dwRemoved[ i ] )
			sprintf( cQ, "pTov_Peres_RemoveKpFromPV %s, %s", isNull(Dlg.qwIZAP[i]), isNull(qwIPeres));
		else
		if( i >= Dlg.dwOldKPCount )
			sprintf( cQ, "pTov_Peres_AddKpToPV %s, %s", isNull(Dlg.qwIZAP[i]), isNull(qwIPeres));
		if( cQ[0] )
		{
			DBW.ExecSQL(cQ);
			DBW.CloseCursor();
			DBW.ReallocHandle();

			if( g_iGotRezervDBW )
			{
				DBWrez.ExecSQL(cQ);
				DBWrez.CloseCursor();
				DBWrez.ReallocHandle();
			}
		}
    }

    OnButton5();
/*	sprintf(cQuery, "pTov_GetPeresLog NULL, NULL, NULL, NULL, NULL, NULL, NULL, NULL, %u", g_iDep);
    DBW.ExecSQL(cQuery);
    RefreshList();
//    DBW.SetListHeader(&m_List);
//    DBW.UpdateListByHandle(&m_List);
    DBW.CloseCursor();
*/
}

//Корректировка
void CDlgPeresKP::OnButton1() 
{
    CDlgAddPeres Dlg;
    char cText[64] = "";
    Dlg.iMode = 1;
    int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
    m_List.GetItemText(idx, 0, cText, 64);
    Dlg.dwVedNum = atoi(cText);
    m_List.GetItemText(idx, 2, Dlg.cVedDate, 12);
//    Dlg.qwIPeres = qwIPERES[idx];
	Dlg.qwIPeres = m_List.qwGetItemData(idx);
    if( gs_DateFmt == 1 )
    {
        char cDay[3]="";
        char cMonth[3]="";
        char cYear[5]="";
        cDay[0] = Dlg.cVedDate[0];
        cDay[1] = Dlg.cVedDate[1];
        cDay[2] = 0;
        cMonth[0] = Dlg.cVedDate[3];
        cMonth[1] = Dlg.cVedDate[4];
        cMonth[2] = 0;
        cYear[0] = Dlg.cVedDate[6];
        cYear[1] = Dlg.cVedDate[7];
        cYear[2] = Dlg.cVedDate[8];
        cYear[3] = Dlg.cVedDate[9];
        cYear[4] = 0;
        Dlg.cVedDate[0] = cMonth[0];
        Dlg.cVedDate[1] = cMonth[1];
        Dlg.cVedDate[3] = cDay[0];
        Dlg.cVedDate[4] = cDay[1];
        memset(&Dlg.stVedDate, 0, sizeof(SYSTEMTIME));
        Dlg.stVedDate.wDay = atoi(cDay);
        Dlg.stVedDate.wMonth = atoi(cMonth);
        Dlg.stVedDate.wYear = atoi(cYear);
    }
    Dlg.iRecieveMode = iRecieveMode;

	
	if( !iRecieveMode )
	{
		m_List.GetItemText(idx, 7, cText, 64);
		if( cText[0] != 'ф' )Dlg.iShowAddDelButtons = 0;
	} else
	{
		m_List.GetItemText(idx, 8, cText, 64);
		if( cText[0] != 'ф' )
		{
			AfxMessageBox("Пересылочная ведомость поступила с другого предприятия автоматически, для получения нажмите 'Получить'!");
			return;
		} else
		{
			Dlg.iCreateRecieveMode = 1;
			Dlg.iShowAddDelButtons = 1;
		}
	}

    if( Dlg.DoModal() == IDCANCEL ) return;
    if( !iRecieveMode ) SendVed(&Dlg);

    OnButton5();
}

void CDlgPeresKP::OnButtonPrint() 
{
	CPrintableDlg Dlg;
	if(m_List.GetSelectionMark() < 0 ) return;
	sprintf(Dlg.cQ, "pTov_mkcReportVU50 %I64u", m_List.qwGetItemData(m_List.GetSelectionMark()));
	Dlg.DoModal();

}

void CDlgPeresKP::RefreshList()
{

	char cText[64] = "";
	long Ind = 0;
	DWORD Pos = 0;
	DBW.UpdateListByHandle(&m_List, &Pos, false, true);
	if( iRecieveMode ) 
	{
		for( int i=0; i < m_List.GetItemCount(); i++ )
		{
			m_List.GetItemText(i, 8, cText, 64);
			if( cText[0] == 'ф' ) m_List.SetItemColor(i, RGB(0,0,0), RGB(255,235,235));
			else
			if( strcmp(cText, "поступила") == 0 ) m_List.SetItemColor(i, RGB(0,0,0), RGB(235,235,255));
			else
			m_List.SetItemColor(i, RGB(0,0,0), RGB(235,255,235));
		}
	} else
	{
		for( int i=0; i < m_List.GetItemCount(); i++ )
		{
			m_List.GetItemText(i, 7, cText, 64);
			if( cText[0] == 'ф' ) m_List.SetItemColor(i, RGB(0,0,0), RGB(255,235,235));
			else
			if( cText[0] == 'о' ) m_List.SetItemColor(i, RGB(0,0,0), RGB(235,235,255));
			else
			m_List.SetItemColor(i, RGB(0,0,0), RGB(235,255,235));
		}
	}
	m_List.RedrawWindow();

}

void CDlgPeresKP::OnCheck1() 
{
	m_Dat1.EnableWindow(m_Check1.GetCheck());
	m_Dat2.EnableWindow(m_Check1.GetCheck());
    m_ButSelect.EnableWindow();
}

void CDlgPeresKP::OnCheck2() 
{
	m_Ed1.EnableWindow(m_Check2.GetCheck());
	m_Ed2.EnableWindow(m_Check2.GetCheck());
    m_ButSelect.EnableWindow();
}

void CDlgPeresKP::OnButton3() 
{
	CDlgSprav1 Dlg;
    Dlg.iDlgKind = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_Ed3.SetWindowText(Dlg.cKodPr); //Клеймо
    dwFiltIPR = Dlg.ret_dwIPR;
    if( !Dlg.cKodPr[0] )
    {
        m_Ed4.SetWindowText(Dlg.cPrName);
    }
    OnChangeFilter();
}

void CDlgPeresKP::OnCheck3() 
{
	m_Ed3.EnableWindow(m_Check3.GetCheck());
	m_Ed4.EnableWindow(m_Check3.GetCheck());
    m_ButPred.EnableWindow(m_Check3.GetCheck());
    if( !m_Check3.GetCheck() ) dwFiltIPR = 0;
    m_ButSelect.EnableWindow();
}

void CDlgPeresKP::OnCheck4() 
{
    CButton *b1 = NULL, *b2 = NULL;
    b1 = (CButton *)GetDlgItem(IDC_RADIO1);
    b2 = (CButton *)GetDlgItem(IDC_RADIO2);

    b1->EnableWindow(m_Check4.GetCheck());
    b2->EnableWindow(m_Check4.GetCheck());

    m_Ed5.EnableWindow(m_Check4.GetCheck());
    m_ButSelect.EnableWindow();
}

void CDlgPeresKP::OnCheck5() 
{
    m_ButFam.EnableWindow(m_Check5.GetCheck());
    m_Ed6.EnableWindow(m_Check5.GetCheck());
    m_ButSelect.EnableWindow();
}

void CDlgPeresKP::OnButton4() 
{
	CDlgSpravKdr Dlg;
    Dlg.iFilter = 8;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_Ed6.SetData(Dlg.dwFio);
    m_Ed6.SetFamTextByID(Dlg.dwFio);
    OnChangeFilter();
}

void CDlgPeresKP::OnButton5() // Выбрать
{
	CString cPrm, cQ = "";
    CString str;
    char cText[64] = "";

    if( m_Check1.GetCheck() )
    {
        cPrm.Format(" %s, %s, ", m_Dat1.GetSQLDate(), m_Dat2.GetSQLDate() );
    } else
        cPrm = " NULL, NULL, ";
    if( m_Check2.GetCheck() )
    {
        if( m_Ed1.GetWindowText(cText, 32) )
        {
            cPrm += (CString)cText + ", ";
        } else
            cPrm += " NULL, ";

        if( m_Ed2.GetWindowText(cText, 32) )
        {
            cPrm += (CString)cText + ", ";
        } else
            cPrm += " NULL, ";
    } else
    {
        cPrm += " NULL, NULL, ";
    }

    if( m_Check3.GetCheck() && dwFiltIPR )
    {
        cPrm += isNull(dwFiltIPR) + ", ";
    } else
        cPrm += "NULL, ";

    if( !iRecieveMode )
    {
        if( m_Check4.GetCheck() )
        {
            CButton *b1 = NULL;
            b1 = (CButton *)GetDlgItem(IDC_RADIO1);
            if( b1->GetCheck() )
                cPrm += " 1, ";
            else
                cPrm += " 0, ";

            if(m_Ed5.GetWindowText(cText, 32))
            {
                cPrm += (CString)cText + ", ";
            } else
                cPrm += " NULL, ";
        } else
            cPrm += "NULL, NULL, ";
    }

    if( m_Check5.GetCheck() )
    {
        cPrm += m_Ed6.GetDataAsString(TRUE) + ", ";
    } else
        cPrm += "NULL, ";
    if( !iRecieveMode )
        cQ.Format("pTov_GetPeresLog %s %u", cPrm, g_iDep);
    else
        cQ.Format("pTov_GetPeresLog2 %s %u", cPrm, g_iDep);

    DBW.ExecSQL(cQ);    
    RefreshList();
    DBW.CloseCursor();

    m_ButSelect.EnableWindow(FALSE);

}

void CDlgPeresKP::OnChangeEditKleimo() 
{
    char cQ[255] = "";
    char cText[64] = "";
    m_Ed4.SetWindowText("");
    if( !m_Ed3.GetWindowText(cText, 64) )
    {
        dwFiltIPR = 0;
        return;
    }
    sprintf(cQ, "pTov_GetPredByKl %s", cText);
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
    DBW.GetData( 2, SQL_C_SLONG, &dwFiltIPR, 4, &Ind);
    m_Ed4.SetWindowText(cText);
    DBW.CloseCursor();
    OnChangeFilter();
}

void CDlgPeresKP::OnChangeFilter() 
{
    m_ButSelect.EnableWindow();	
}

void CDlgPeresKP::OnRadio1() 
{
    OnChangeFilter();	
}

void CDlgPeresKP::OnRadio2() 
{
    OnChangeFilter();
}

void CDlgPeresKP::OnChangeEdit8() 
{
    OnChangeFilter();
}

void CDlgPeresKP::OnButton_Delete() 
{
    int idx = m_List.GetSelectionMark();

    if( idx == -1 ) return;

    char cText[64] = "";
	char cText2[64] = "";

	if( !iRecieveMode )
	{
		m_List.GetItemText(idx, 4, cText, 64);
		if( atoi(cText) != 0 )
		{
			MessageBox("Нельзя удалить не пустю ведомость!", "Внимание");
			return;
		}
	} else
	{
		m_List.GetItemText(idx, 4, cText, 64);
		m_List.GetItemText(idx, 6, cText2, 64);
		if( atoi(cText) != 0 || atoi(cText2) != 0)
		{
			MessageBox("Нельзя удалить не пустю ведомость!", "Внимание");
			return;
		}
	}
	long Ind = 0;
	CString cQ;
	DWORD dwNVed = 0;
	SYSTEMTIME stDate;
	cQ.Format("pTov_GetPeresByID2 %I64u", m_List.qwGetItemData(idx));
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_ULONG, &dwNVed, 4, &Ind );
	mgSQLGetSysDate(2, &stDate, &Ind );
	DBW.CloseCursor();
/*
	char cQRez[512] = "";
	sprintf(cQRez, "declare @IPeres bigint\nexec @IPeres = pTov_GetIPeresByNumDate %u, %s, %u\n\nif @iperes is not null exec pTov_DeletePeresVed @IPeres",
			dwNVed,
			DateToSQL(stDate),
			g_iDep);
	DBW.ExecSQLRzv(cQRez);*/

    
	cQ.Format("pTov_DeletePeresVed %I64u", m_List.qwGetItemData(idx));
    DBW.ExecSQL(cQ);
    DBW.CloseCursor();

	if( g_iGotRezervDBW )
	{
		DBWrez.ExecSQL(cQ);
		DBWrez.CloseCursor();
	}

    OnButton5();
}

void CDlgPeresKP::OnButton_Send() 
{
    int idx = m_List.GetSelectionMark();
    if( idx < 0 )
    {
        MessageBox("Необходимо выбрать ведомость!", "Внимание", MB_OK);
        return;
    }
    char cText[64] = "";
	char cQRez[1024]= "";
    if(!iRecieveMode)
    {
		m_List.GetItemText(idx, 7, cText, 64);
		if( cText[0] != 'ф' )
		{
			AfxMessageBox("Невозможно отправить!");
			return;
		}
        m_List.GetItemText(idx, 7, cText, 64);
        if( cText[0] == 'О' || cText[0] == 'о' )
        {
            MessageBox("Выбранная ведомость уже отправлена!", "Внимание", MB_OK);
            return;
        }
		long Ind = 0;
        CString cQ;

		if( g_iEnableTelecom && g_strAsldTeleName )
		{
				DWORD dwBadCount = 0;
				cQ.Format("pTov_Peres_CanSendToAsuV %s", isNull(m_List.qwGetItemData(idx)));
				DBW.ExecSQL( cQ );		
				DBW.Fetch();
				DBW.GetData(1, SQL_C_ULONG, &dwBadCount, 4, &Ind);
				DBW.CloseCursor();
				if( dwBadCount > 0 )
				{
					char cMess[255] = "";
					sprintf(cMess, "В пересылочной ведомости есть КП (%d шт.), информацию по которым, невозможно передать в АСЛД.\nПродолжить отправку ведомости?", dwBadCount);
					if( MessageBox(cMess, "", MB_YESNO) == IDNO) return;
				}
		}

		cQ.Format("pTov_Peres_Otprav %I64u", m_List.qwGetItemData(idx));
        DBW.ExecSQL(cQ);
		DBW.CloseCursor();
		
		if( g_iGotRezervDBW )
		{
			DBWrez.ExecSQL(cQ);
			DBWrez.CloseCursor();
			DBWrez.ReallocHandle();
		}



		DWORD dwNVed = 0;
		SYSTEMTIME stDate;
		cQ.Format("pTov_GetPeresByID2 %I64u", m_List.qwGetItemData(idx));
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_ULONG, &dwNVed, 4, &Ind );
		mgSQLGetSysDate(2, &stDate, &Ind );
		DBW.CloseCursor();
       
			int idx = m_List.GetSelectionMark();
			if( idx == -1 ) return;
			__int64 lqwIPeres = m_List.qwGetItemData(idx);
			char cText[20000] = "";
			Ind = 0;			
			cQ.Format("pTov_Peres_SendToAsuV NULL, %s", isNull(lqwIPeres) );
		//	g_LogEnabled = 0;
			DBW.ExecSQL( cQ );
		//	g_LogEnabled = 1;
			DBW.Fetch();
			DBW.GetData(1, SQL_C_CHAR, cText, 20000, &Ind);
			DBW.CloseCursor();

			if( Ind > 0 && g_iEnableTelecom && g_strAsldTeleName )
			{
				char msg[200] = "";
				sprintf(msg, "Отправка данных в АС ЛД (%s)", g_strAsldTeleName ) ;
				DBW.WriteLog((char *)msg);
				CString snd = (CString)"<tov><asld docid=\"1\">\n" + cText + (CString) "\n</asld></tov>";
				//DBW.SendMessageToDst( snd, "mkc", g_strAisldTeleName );
				if( tele ) tele->SendMessageDst(snd, &g_strAsldTeleName);
			}

    } else
    {
		m_List.GetItemText(idx, 8, cText, 64);
		if( cText[0] == 'ф' )
		{
			AfxMessageBox("Ведомость оформлена на вашем предприятии, для ее изменения нажмите 'Корректировка'!");
			return;			
		}
        CDlgAddPeres Dlg;
        Dlg.iRecieveMode = 1;
        Dlg.iMode = 0;
		Dlg.qwIPeres = m_List.qwGetItemData(idx);
        m_List.GetItemText(idx, 0, cText, 64);
        Dlg.dwVedNum = atoi(cText);
		Dlg.iShowAddDelButtons = 0;

        if( Dlg.DoModal() == IDCANCEL) return;
    }
	OnButton5();
}

void CDlgPeresKP::SendVed(CDlgAddPeres *Dlg)
{
    char cText[64] = "";
    char cQ[512] = "";
    if( Dlg->m_iPrRem == -1 )
    {
        strncpy(cText, "NULL", 6);
    }
    else
    {
        itoa(Dlg->m_iPrRem + 1, cText, 10);        
    }
	//char ccDt[16] = "";
	//DateToSql(Dlg->stVedDate, ccDt);

	char cQRez[2048] = "";
    if( Dlg->iHeader == 1)
    {
        sprintf(cQ, "pTov_UpdateVedHdr %I64u, %s, %s, %s, %s, %s, %s, %u, %s",
                Dlg->qwIPeres,
                isNull(Dlg->dwIPR_Rcv),
                cText, 
                isNull(Dlg->m_cVagNum),
                isNull(Dlg->dwFIO_Mast),
                isNull(Dlg->dwFIO_Priem),
                isNull(g_iFam),
                Dlg->iOnVag,
                isNull(Dlg->dwIPR_Sobst)
        );
		sprintf(cQRez, "declare @IPeres bigint\nexec @IPeres = pTov_GetIPeresByNumDate %u, %s, %u\nexec pTov_UpdateVedHdr @IPeres, %s, %s, %s, %s, %s, %u, %u, %s\n",
			Dlg->dwVedNum, DateToSQL(Dlg->stVedDate), g_iDep,
			                isNull(Dlg->dwIPR_Rcv),
            cText, 
            isNull(Dlg->m_cVagNum),
            isNull(Dlg->dwFIO_Mast),
            isNull(Dlg->dwFIO_Priem),
            g_iFam,
            Dlg->iOnVag,
            isNull(Dlg->dwIPR_Sobst));
    } else
    if( Dlg->iHeader == 0 )
    {
        if( Dlg->m_iPrRem == -1 )
        {
            strncpy(cText, "NULL", 6);
        }
        else
        {
            itoa(Dlg->m_iPrRem + 1, cText, 10);
        }
        sprintf(cQ, "pTov_InsertVedHdr %d, %u, %s, %d, %s, '%s', %s, %s, %s, %s, %s",
                g_iDep,
                Dlg->m_Edit1Num,
                DateToSQL(Dlg->stVedDate),
                Dlg->dwIPR_Rcv,
                cText,
                Dlg->m_cVagNum,
                isNull(Dlg->dwFIO_Mast),
                isNull(Dlg->dwFIO_Priem),
				isNull(g_iFam),
				isNull((WORD)Dlg->iOnVag),
                isNull(Dlg->dwIPR_Sobst));
    }
    __int64 qwIPeres = 0; 
    long Ind = 0;
    DBW.ExecSQL(cQ);
    DBW.Fetch();
    DBW.GetData(1, SQL_C_UBIGINT, &qwIPeres, 8, &Ind);
    DBW.CloseCursor();
    DBW.ReallocHandle();

    for( DWORD i=0; i < Dlg->dwKPCount; i++ )
    {
		/*
        sprintf(cQ, "pTov_RashodKP %I64u, %u, %u, %u, %s, %s, NULL, NULL, %s, %s, NULL, NULL, %s",
            Dlg->qwIZAP[i], 
            g_iDep,
			Dlg->p_dwRemoved[ i ] ? 0 : 91 + Dlg->dwPriznRas[i] / 10,
            Dlg->dwGruz[i],
			Dlg->p_dwRemoved[ i ] ? "NULL" : isNull(Dlg->dwFIO_Mast),
            Dlg->p_dwRemoved[ i ] ? "NULL" : CString("'") + CString(Dlg->cVedDate) + CString("'"),
            Dlg->p_dwRemoved[ i ] ? "NULL" : isNull(Dlg->dwIPR_Rcv),
            Dlg->p_dwRemoved[ i ] ? "NULL" : isNull(Dlg->m_Edit1Num),
            Dlg->p_dwRemoved[ i ] ? "NULL" : isNull(qwIPeres));

		sprintf(cQRez, "%s\nexec pTov_RashodKP_Rez 0, '%s', %u, %s, %s, %s,  %u, %u, %u, %u, '%s', NULL, NULL, %u, %u, NULL, NULL, @IPeres",
			cQRez,
			Dlg->cNKP[i],
			Dlg->p_dwTKP[i],
			DateToSQL(Dlg->stDatIzg[i]),
			isNull(Dlg->dwIPrIzg[i]),
			isNull(g_iFam),
			
            g_iDep,
            91 + Dlg->dwPriznRas[i] / 10,
            Dlg->dwGruz[i],
            Dlg->dwFIO_Mast,
            Dlg->cVedDate,
            Dlg->dwIPR_Rcv,
            Dlg->m_Edit1Num);
*/
		cQ[0] = 0;
		if( Dlg->p_dwRemoved[ i ] )
			sprintf( cQ, "pTov_Peres_RemoveKpFromPV %s, %s", isNull(Dlg->qwIZAP[i]), isNull(qwIPeres));
		else
		if( i >= Dlg->dwOldKPCount )
			sprintf( cQ, "pTov_Peres_AddKpToPV %s, %s", isNull(Dlg->qwIZAP[i]), isNull(qwIPeres));
		if( cQ[0] )
		{
			DBW.ExecSQL(cQ);
			DBW.CloseCursor();
			DBW.ReallocHandle();
		}
    }

	for( DWORD i=0; i < Dlg->dwKPCount; i++ )
    {
	if( Dlg->p_dwNewTKP[i] != 0 && 
		Dlg->p_dwNewTKP[i] != 100 && Dlg->p_dwTKP[i] == 100 
		&& Dlg->p_dwTKP[i] != Dlg->p_dwNewTKP[i] 
	)
			{
				sprintf(cQ, "exec pTov_SetTypeKP %s, %s",
						isNull(Dlg->qwIZAP[i]),
						isNull(Dlg->p_dwNewTKP[i]) );
				DBW.ExecSQL(cQ);
				DBW.Fetch();
				DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
				DBW.WriteLog(cText);
				DBW.CloseCursor();

			}
	}

	DBW.WriteLog(cQRez);
	DBW.ExecSQLRzv(cQRez);
    OnButton5();
}

void CDlgPeresKP::OnBnClickedCancel()
{
	m_List.DeleteAllItems();
	OnCancel();
}


void CDlgPeresKP::OnBnClickedButton_SendToASUV()
{
	int idx = m_List.GetSelectionMark();
    if( idx == -1 ) return;
	__int64 lqwIPeres = m_List.qwGetItemData(idx);
	char cText[20000] = "";
	long Ind = 0;
	char cQ[128] = "";
	sprintf( cQ, "pTov_Peres_SendToAsuV NULL, %s", isNull(lqwIPeres) );
//	g_LogEnabled = 0;
	DBW.ExecSQL( cQ );
//	g_LogEnabled = 1;
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cText, 20000, &Ind);
	DBW.CloseCursor();

	if( Ind > 0 && g_iEnableTelecom && g_strAsldTeleName )
	{
		CString snd = (CString)"<tov><asld docid=\"1\">\n" + cText + (CString) "\n</asld></tov>";
		//DBW.SendMessageToDst( snd, "mkc", g_strAisldTeleName );
		if( tele ) tele->SendMessageDst(snd, &g_strAsldTeleName);
	}



}
