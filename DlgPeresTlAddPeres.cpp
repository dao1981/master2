// DlgPeresTlAddPeres.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPeresTlAddPeres.h"
#include "DlgSprav1.h"
#include "DlgSpravKdr.h"
#include "DlgPeresTL_AddDTL.h"
#include "DlgSprPrSobstv.h"

// CDlgPeresTlAddPeres dialog

IMPLEMENT_DYNAMIC(CDlgPeresTlAddPeres, CDialog)

CDlgPeresTlAddPeres::CDlgPeresTlAddPeres(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPeresTlAddPeres::IDD, pParent)
{
	qwIPERES = 0;
	iModeRecieve = 1;
	DlgStarted = 0;
	iBRCount = 0;
	iNBCount = 0;
	iDelCount = 0;
	dwIPR_Rcv = 0;
	dwIPR_Snd = 0;
}

CDlgPeresTlAddPeres::~CDlgPeresTlAddPeres()
{
}

void CDlgPeresTlAddPeres::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_BUTTON8, m_But2);
	DDX_Control(pDX, IDC_BUTTON25, m_ButMaterRcv);
	DDX_Control(pDX, IDC_BUTTON11, m_ButSobst);
	DDX_Control(pDX, IDC_BUTTON1, m_ButRcv);
	DDX_Control(pDX, IDC_EDIT11, m_Date1);
	DDX_Control(pDX, IDC_CHECK2, m_CheckAll);
	DDX_Control(pDX, IDC_EDIT8, m_EdMasterRcv);
	DDX_Control(pDX, IDC_EDIT7, m_DatRcv);
	DDX_Control(pDX, IDC_EDIT78, m_EdPrSobst);
	DDX_Control(pDX, IDC_EDIT16, m_EdPrSnd);
	DDX_Control(pDX, IDC_EDIT72, m_PrSnd);
	DDX_Control(pDX, IDC_EDIT118, m_PrSobst);
	DDX_Control(pDX, IDC_EDIT6, m_EdFamSnd);
//	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_EDIT3, m_CountCtrl);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_BUTTON6, m_Button3);
	DDX_Control(pDX, IDC_EDIT5, m_Edit4);
	DDX_Control(pDX, IDC_EDIT4, m_EdKlPrRcv);
	DDX_Control(pDX, IDC_EDIT2, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_BUTTON2, m_ButMastLow);
	DDX_Control(pDX, IDC_BUTTON5, m_ButAddKP);
/*
	DDX_Text(pDX, IDC_EDIT3, m_uiCount);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1Num);
	DDX_CBIndex(pDX, IDC_COMBO1, m_iPrRem);
	DDX_Text(pDX, IDC_EDIT2, m_cVagNum);
	DDX_Text(pDX, IDC_EDIT5, m_Edit4Text);
*/
}


BEGIN_MESSAGE_MAP(CDlgPeresTlAddPeres, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_EN_CHANGE(IDC_EDIT4, OnChangeEdit4)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
//	ON_BN_CLICKED(IDOK, OnAddVed)
	ON_BN_CLICKED(IDC_BUTTON25, OnButton_MasterRcv)
	ON_BN_CLICKED(IDC_BUTTON11, OnButton_GetSobst)
	ON_BN_CLICKED(IDC_CHECK2, OnCheck_SelectAll)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton_PrSender)
	//}}AFX_MSG_MAP
//	ON_EN_CHANGE(IDC_EDIT6, OnEnChangeEdit6)
ON_BN_CLICKED(IDC_BUTTON38, &CDlgPeresTlAddPeres::OnBnClickedButtonAddNB)
ON_BN_CLICKED(IDOK, &CDlgPeresTlAddPeres::OnBnClickedOk)
ON_EN_CHANGE(IDC_EDIT72, &CDlgPeresTlAddPeres::OnEnChangeEditPrSender)
ON_BN_CLICKED(IDC_BUTTON3, &CDlgPeresTlAddPeres::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDlgPeresTlAddPeres message handlers
extern CString g_strDepoKl;
extern DWORD g_dwPrID;

BOOL CDlgPeresTlAddPeres::OnInitDialog()
{
//	CDlgWithAccelerators::OnInitDialog();
	CDialog::OnInitDialog();

	char cQ[128] = "";
	char cText[64] = "";
	DWORD dwNum = 0;
	long Ind = 0;
	SYSTEMTIME tm;

	m_Edit4.ModifyStyle(0, WS_DISABLED, 0);
	m_EdPrSnd.ModifyStyle(0, WS_DISABLED, 0);
	m_EdPrSobst.ModifyStyle(0, WS_DISABLED, 0);
	m_CountCtrl.ModifyStyle(0, WS_DISABLED);

    CButton *b1 = (CButton *)GetDlgItem(IDC_RADIO1);
    CButton *b2 = (CButton *)GetDlgItem(IDC_RADIO2);
    ASSERT(b1);
    ASSERT(b2);
//    b1->SetCheck(1);	
    m_EdKlPrRcv.SetWindowText("");

	m_Edit1.QInit(100,1);
	m_PrSnd.QInit(60, 1);
	m_EdKlPrRcv.QInit(50, 1);
	m_EdNVag.SetMode(0, 1, 10);

	m_EdFamSnd.SetMode(5);
    DBW.FillEmplArray(m_EdFamSnd.lpEmpl, 1);
	m_EdMasterRcv.SetMode(5);
	DBW.FillEmplArray(m_EdMasterRcv.lpEmpl, 1);
	
	if( iModeRecieve )
	{
		m_EdKlPrRcv.SetWindowText(g_strDepoKl);
		m_EdKlPrRcv.SetData(g_dwPrID);
		dwIPR_Rcv = g_dwPrID;
		m_Edit4.SetWindowText(g_strDepoName);
		m_EdKlPrRcv.EnableWindow(0);
		m_ButRcv.EnableWindow(0);
		m_Edit4.EnableWindow(0);
	} else
	{
		m_PrSnd.SetWindowText(g_strDepoKl);
		m_PrSnd.SetData(g_dwPrID);
		m_EdPrSnd.SetWindowText(g_strDepoName);
		m_PrSnd.EnableWindow(0);
		m_But2.EnableWindow(0);
		m_EdPrSnd.EnableWindow(0);
	}



//    m_List.InsertColumn(3, "Состояние", LVCFMT_LEFT, 220, -1);
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD | LVS_SINGLESEL, 0);
    m_List.SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB );

	m_List.InsertColumn(0, "НБ/БР", LVCFMT_RIGHT, 60, -1);
	m_List.InsertColumn(1, "Номер", LVCFMT_RIGHT, 100, -1);
    m_List.InsertColumn(2, "Завод изготовитель", LVCFMT_LEFT, 300, -1);
	m_List.InsertColumn(3, "Год выпуска", LVCFMT_LEFT, 100, -1);

	if(iModeRecieve) m_List.SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );        
	if( !qwIPERES ) // Новая ведомость
	{
		sprintf(cQ, "pTov_PeresTl_GetNewNVed %I64u", qwIPERES );
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 )m_Edit1.SetWindowText(cText);
	}

	if( qwIPERES ) // передали IPeres - Редактирование
	{
		sprintf(cQ, "pTov_PeresTl_GetVedHdr %I64u", qwIPERES );
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Edit1.SetWindowText(cText);
		DBW.GetData(2, SQL_C_ULONG, &dwNum, 4, &Ind );
		mgSQLGetSysDate(3, &tm, &Ind );
		if( Ind != -1 ) m_Date1.SetTime(&tm);
		DBW.GetData(4, SQL_C_ULONG, &dwIPR_Snd, 4, &Ind );
		if( Ind != -1 )
		{
			m_EdKlPrRcv.SetData(dwIPR_Snd);
			DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_PrSnd.SetWindowText(cText);
			DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdPrSnd.SetWindowText(cText);
		}
		mgSQLGetSysDate(7, &tm, &Ind );
		if( Ind != -1 ) m_DatRcv.SetTime(&tm);
		DBW.GetData(8, SQL_C_ULONG, &dwIPR_Rcv, 4, &Ind );
		if( Ind != -1 )
		{
			m_EdKlPrRcv.SetData(dwIPR_Rcv);
			DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKlPrRcv.SetWindowText(cText);
			DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_Edit4.SetWindowText(cText);
		}
		DBW.GetData(11, SQL_C_ULONG, &dwFIO_Mast, 4, &Ind );
		if( Ind != -1 )
		{
			m_EdFamSnd.SetData(dwFIO_Mast);
			DBW.GetData(12, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdFamSnd.SetWindowText(cText);
		}
		DBW.GetData(13, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 )
		{
			m_EdMasterRcv.SetData(dwNum);
			DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdMasterRcv.SetWindowText(cText);

		}
		DBW.GetData(15, SQL_C_ULONG, &dwIPR_Sobst, 4, &Ind );
		if( Ind != -1 )
		{
			m_PrSobst.SetData(dwIPR_Sobst);
			DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_PrSobst.SetWindowText(cText);
			DBW.GetData(17, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdPrSobst.SetWindowText(cText);
		}
		DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_EdNVag.SetWindowText(cText);
		DBW.GetData(19, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 )
		{
			if(dwNum) b1->SetCheck(1);
			else b2->SetCheck(1);
		}
		DBW.CloseCursor();
	}

	iBRCount = 0;
	iNBCount = 0;	

	sprintf(cQ, "pTov_PeresTl_GetPvDTL %I64u", qwIPERES );
	DBW.ExecSQL(cQ);
	while( (g_sqlret = DBW.Fetch()) != SQL_NO_DATA )
	{
		DBW.GetData(1, SQL_C_LONG, &dwNum, 4, &Ind );
		if( Ind != -1 && dwNum == 1 ) //BR
		{
			DBW.GetData(2, SQL_C_UBIGINT, &pBR[iBRCount].qwIZapDTL, 8, &Ind);
			DBW.GetData(3, SQL_C_CHAR, pBR[iBRCount].cNum, 10, &Ind);
			DBW.GetData(4, SQL_C_LONG, &pBR[iBRCount].dwIRP, 4, &Ind );
			DBW.GetData(5, SQL_C_CHAR, pBR[iBRCount].cKlPr, 15, &Ind);
			DBW.GetData(6, SQL_C_CHAR, pBR[iBRCount].cPrName, 59, &Ind);
			DBW.GetData(7, SQL_C_CHAR, pBR[iBRCount].cYear, 6, &Ind);
			iBRCount++;
		}
		if( Ind != -1 && dwNum == 2 ) //NB
		{
			DBW.GetData(2, SQL_C_UBIGINT, &pNB[iNBCount].qwIZapDTL, 8, &Ind);
			DBW.GetData(3, SQL_C_CHAR, pNB[iNBCount].cNum, 10, &Ind);
			DBW.GetData(4, SQL_C_LONG, &pNB[iNBCount].dwIRP, 4, &Ind );
			DBW.GetData(5, SQL_C_CHAR, pNB[iNBCount].cKlPr, 15, &Ind);
			DBW.GetData(6, SQL_C_CHAR, pNB[iNBCount].cPrName, 59, &Ind);
			DBW.GetData(7, SQL_C_CHAR, pNB[iNBCount].cYear, 6, &Ind);
			iNBCount++;
		}
	}


	RefreshList();	
	DlgStarted = 1;
	return TRUE;
}

void CDlgPeresTlAddPeres::RefreshList()
{
	m_List.DeleteAllItems();
	char cText[64] = "";
	int idx = 0;
	for(int i = 0; i < 50 && i < iBRCount; i++, idx++ )
	{
		pBR[i].iGridIndex = idx;
		m_List.InsertItem(idx, "Б.Р.");
		m_List.SetItemText(idx, 1, pBR[i].cNum);
		sprintf( cText, "%s - %s", pBR[i].cKlPr, pBR[i].cPrName );
		m_List.SetItemText(idx, 2, cText);
		m_List.SetItemText(idx, 3, pBR[i].cYear);
		if( pBR[i].qwIZapDTL )
			m_List.SetItemColor(i, RGB(0,0,0), RGB(255,245,235));
	}

	for(int i = 0; i < 50 && i < iNBCount; i++, idx++ )
	{
		pNB[i].iGridIndex = idx;
		m_List.InsertItem(idx, "Н.Б.");
		m_List.SetItemText(idx, 1, pNB[i].cNum);
		sprintf( cText, "%s - %s", pNB[i].cKlPr, pNB[i].cPrName );
		m_List.SetItemText(idx, 2, cText);
		m_List.SetItemText(idx, 3, pNB[i].cYear);
		if( pNB[i].qwIZapDTL )
			m_List.SetItemColor(idx, RGB(0,0,0), RGB(255,245,235));

	}
	m_CountCtrl.SetWindowText(itoa(m_List.GetItemCount(), cText, 10));
}


//получатель
void CDlgPeresTlAddPeres::OnButton1() 
{
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdKlPrRcv.SetWindowText(Dlg.cKodPr);
	dwIPR_Rcv = Dlg.ret_dwIPR;
	m_EdKlPrRcv.SetData(dwIPR_Rcv);
    m_Edit4.SetWindowText(Dlg.cPrName);

}

void CDlgPeresTlAddPeres::OnChangeEdit4() 
{
    if( !DlgStarted || iModeRecieve ) return;
    char cText[64] = "";
    char cQ[64] = "";
    long Ind = 0;
	m_EdKlPrRcv.SetData(dwIPR_Rcv);
	dwIPR_Rcv = 0;
    m_EdKlPrRcv.GetWindowText(cText, 64);
    sprintf(cQ, "pTov_GetPredByKl '%s'", cText);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    m_Edit4.SetWindowText("");
    if( g_sqlret == SQL_NO_DATA ||
        g_sqlret == SQL_ERROR )
    {
        DBW.CloseCursor();
        return;
    }
    DBW.GetData( 1, SQL_C_CHAR, cText, 64, &Ind);
    DBW.GetData( 2, SQL_C_SLONG, &dwIPR_Rcv, 4, &Ind);
	m_EdKlPrRcv.SetData(dwIPR_Rcv);
    DBW.CloseCursor();
    m_Edit4.SetWindowText(cText);
}

void CDlgPeresTlAddPeres::OnEnChangeEditPrSender()
{
    if( !DlgStarted ) return;
    char cText[64] = "";
    char cQ[64] = "";
    long Ind = 0;
	m_PrSnd.GetWindowText(cText, 64);
	dwIPR_Snd = 0;
	m_PrSnd.SetData(0);
    sprintf(cQ, "pTov_GetPredByKl '%s'", cText);
    DBW.ExecSQL(cQ);
    g_sqlret = DBW.Fetch();
    m_EdPrSnd.SetWindowText("");
    if( g_sqlret == SQL_NO_DATA ||
        g_sqlret == SQL_ERROR )
    {
        DBW.CloseCursor();
        return;
    }
    DBW.GetData( 1, SQL_C_CHAR, cText, 64, &Ind);
    DBW.GetData( 2, SQL_C_SLONG, &dwIPR_Snd, 4, &Ind);
	m_PrSnd.SetData(dwIPR_Snd);
    DBW.CloseCursor();
    m_EdPrSnd.SetWindowText(cText);
}

//Master
void CDlgPeresTlAddPeres::OnButton2() 
{
	CDlgSpravKdr Dlg;
    Dlg.DlgMode = 1;
    Dlg.iFilter = 8;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdFamSnd.SetWindowText(Dlg.cFio);
    dwFIO_Mast = Dlg.dwFio;
    m_EdFamSnd.SetData(dwFIO_Mast);
}


//Add БР
void CDlgPeresTlAddPeres::OnButton5() 
{
	CDlgPeresTL_AddDTL Dlg;
	Dlg.iTypeDTL = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	strncpy(pBR[iBRCount].cNum, Dlg.cDTlNum, 10);
	strncpy(pBR[iBRCount].cYear, Dlg.cYear, 5);
	strncpy(pBR[iBRCount].cKlPr, Dlg.cKlPr, 16);
	strncpy(pBR[iBRCount].cPrName, Dlg.cPrName, 40);
	pBR[iBRCount].dwIRP = Dlg.dwIPR;
	iBRCount++;
	RefreshList();
}

//Add NB
void CDlgPeresTlAddPeres::OnBnClickedButtonAddNB()
{
	CDlgPeresTL_AddDTL Dlg;
	Dlg.iTypeDTL = 2;
	if( Dlg.DoModal() == IDCANCEL ) return;

	strncpy(pNB[iNBCount].cNum, Dlg.cDTlNum, 10);
	strncpy(pNB[iNBCount].cYear, Dlg.cYear, 5);
	strncpy(pNB[iNBCount].cKlPr, Dlg.cKlPr, 16);
	strncpy(pNB[iNBCount].cPrName, Dlg.cPrName, 40);
	pNB[iNBCount].dwIRP = Dlg.dwIPR;
	iNBCount++;

	RefreshList();
}

//Remove KP
void CDlgPeresTlAddPeres::OnButton6() 
{
	int idx = m_List.GetSelectionMark();
	if( idx < 0 ) return;

	if( idx < iBRCount ) 
	{
		if( pBR[idx].qwIZapDTL )
		{
			if( MessageBox("Внимание! Данной детали уже был оформлен приход?\nВы действительно хотите удалить эту деталь?",
					"Удаление детали", MB_YESNO | MB_ICONINFORMATION ) == IDNO) return;
			pDelDTl[iDelCount].qwIZapDTL = pBR[idx].qwIZapDTL;
			pDelDTl[iDelCount].iTypeDTL = 1;
			iDelCount++;
		}

		for( int i=idx; i < iBRCount; i++ )
		{
			pBR[i] = pBR[i + 1];
		}
		iBRCount--;
	}
	else
	{
		if( pNB[idx - iBRCount].qwIZapDTL )
		{
			if( MessageBox("Внимание! Данной детали уже был оформлен приход?\nВы действительно хотите удалить эту деталь?",
					"Удаление детали", MB_YESNO | MB_ICONINFORMATION ) == IDNO) return;
			pDelDTl[iDelCount].qwIZapDTL = pNB[idx - iBRCount].qwIZapDTL;
			pDelDTl[iDelCount].iTypeDTL = 2;
			iDelCount++;
		}

		for( int i=idx - iBRCount; i < iNBCount; i++ )
		{
			pNB[i] = pNB[i + 1];
		}
		iNBCount--;
	}
	RefreshList();
}

void CDlgPeresTlAddPeres::OnButton_PrSender() 
{
    CDlgSprav1 Dlg;
//    Dlg.iDlgKind = 7;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_PrSnd.SetWindowText(Dlg.cKodPr);
    m_EdPrSnd.SetWindowText(Dlg.cPrName);
    dwIPR_Snd = Dlg.ret_dwIPR;
	m_PrSnd.SetData(dwIPR_Snd);
}

void CDlgPeresTlAddPeres::OnCheck_SelectAll() 
{
    for( int i=0; i < m_List.GetItemCount(); i++ ) m_List.SetCheck(i, m_CheckAll.GetCheck());	
}


void CDlgPeresTlAddPeres::OnButton_GetSobst() 
{
	/*
    CDlgSprav1 Dlg;
    Dlg.iDlgKind = 7;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_PrSobst.SetWindowText(Dlg.cKodPr);	
    m_EdPrSobst.SetWindowText(Dlg.cPrName);
    dwIPR_Sobst = Dlg.ret_dwIPR;
	m_PrSobst.SetData(dwIPR_Sobst);
	*/
	CDlgSprPrSobstv Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

    m_PrSobst.SetWindowText(Dlg.cKlPr);
	dwIPR_Sobst = Dlg.dwSobstID;
	m_EdPrSobst.SetWindowText(Dlg.cPrName);
}

void CDlgPeresTlAddPeres::OnButton_MasterRcv() 
{
	CDlgSpravKdr Dlg;
    Dlg.DlgMode = 1;
    Dlg.iFilter = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;
    m_EdMasterRcv.SetWindowText(Dlg.cFio);
    m_EdMasterRcv.SetData(Dlg.dwFio);
}


void CDlgPeresTlAddPeres::OnBnClickedOk()
{
    char cQ[512] = "";
    char cText[64] = "";
    DWORD dwNum = 0;
    DWORD dwVedNum = 0;
    m_Edit1.GetWindowText(cText, 64);
    if( cText[0] == 0 )
    {
        AfxMessageBox("Не введен номер ведомости!");
		m_Edit1.SetFocus();
        return;
    }
    dwNum = atoi(cText);
    if( dwNum == 0 )
    {
        AfxMessageBox("Номер ведомости не может быть равен нулю!");
		m_Edit1.SetFocus();
        return;
    }
    dwVedNum = dwNum;

	if( m_Date1.isNull() || !m_Date1.isValid() )
	{
		MessageBox("Не указана дата пересылки!","Внимание",MB_OK);
		m_Date1.SetFocus();
		return;
	}


    m_EdNVag.GetWindowText(cText, 64);
    if( strlen(cText) > 10 )
    {
        AfxMessageBox("Номер вагона (автомобиля) не может привышать 9999999999!");
        return;
    }

    if( !dwIPR_Rcv )
    {
        AfxMessageBox("Не указано предприятие получатель!");
        return;
    }

    if( !dwIPR_Snd )
    {
        AfxMessageBox("Не указано предприятие отправитель!");
		m_PrSnd.SetFocus();
        return;
    }
	if( iModeRecieve )
	{
		if( !m_EdMasterRcv.GetData())
		{
			AfxMessageBox("Не указан мастер!");
			m_EdMasterRcv.SetFocus();
			return;
		}
		if( m_DatRcv.isNull() || !m_DatRcv.isValid() )
		{
			AfxMessageBox("Необходимо указать дату получения!");
			m_DatRcv.SetFocus();
			return;
		}
	}

	WriteData();
	OnOK();
}

int CDlgPeresTlAddPeres::WriteData(void)
{
	char cQ[512] = "";
/*
	@NVed int, m_Edit1
	@Dat_Snd smalldatetime, m_Date1 
	@IPR_Snd int, m_PrSnd
	@Dat_Rcv smalldatetime, m_DatRcv
	@IPR_Rcv int, m_Edit3
	@TL_Type tinyint,
	@IFam_Snd int, m_EdFamSnd
	@IFam_Rcv int, m_EdMasterRcv
	@OnVag bit, rad1
	@NVag varchar(10); m_Edit2
*/
	if( !qwIPERES )
	{
		sprintf(cQ, "exec pTov_PeresTl_AddVed %s, %s, %s, %s, %s, %u, %s, %s, %s, %u, %s",
			m_Edit1.GetString(1),
			m_Date1.GetSQLDate(),
			isNull(m_PrSnd.GetData()),
			m_DatRcv.GetSQLDate(),
			isNull(m_EdKlPrRcv.GetData()),
			1,
			isNull(m_EdFamSnd.GetData()),
			isNull(m_EdMasterRcv.GetData()),
			isNull(m_PrSobst.GetData()),
			1,
			m_EdNVag.GetString(1));

	//	AfxMessageBox(cQ);
		long Ind = 0;
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_UBIGINT, &qwIPERES, 8, &Ind);
		DBW.CloseCursor();
	}
	char cScript[2048] = "\n";

	for( int i = 0; i < iDelCount; i++ )
	{
		sprintf(cScript, "%s\n exec pTov_PeresTl_DelDtl %I64u, %I64u, %d",
				cScript,
				qwIPERES,
				pDelDTl[i].qwIZapDTL,
				pDelDTl[i].iTypeDTL);
	}
	strcat(cScript, "\n -- BR\n\n");
	for( int i = 0; i < iBRCount; i++ )
	{
		if( !pBR[i].qwIZapDTL )
			sprintf(cScript, "%s exec pTov_PeresTl_AddDTL %I64u, 1, %s, %s, %u, %u, %s\n",
				cScript,
				qwIPERES,
				isNull(pBR[i].cNum),
				pBR[i].cYear,
				pBR[i].dwIRP,
				g_dwPrID, 
				m_DatRcv.GetSQLDate());
		
	}
	strcat(cScript, "\n -- NB\n\n");
	for( int i = 0; i < iNBCount; i++ )
	{
		if( !pNB[i].qwIZapDTL )
			sprintf(cScript, "%s exec pTov_PeresTl_AddDTL %I64u, 2, %s, %s, %u, %u, %s\n",
				cScript,
				qwIPERES,
				isNull(pNB[i].cNum),
				pNB[i].cYear,
				pNB[i].dwIRP,
				g_dwPrID, 
				m_DatRcv.GetSQLDate());
	}
	DBW.ExecSQL(cScript);
	DBW.CloseCursor();
	return 0;
}


void CDlgPeresTlAddPeres::OnBnClickedButton3()
{
	m_PrSobst.SetData(0);
	m_PrSobst.SetWindowText("");
	m_EdPrSobst.SetWindowText("");	
}
