// DlgPodkatTL1520.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPodkatTL1520.h"
#include ".\dlgpodkattl1520.h"
#include "DlgSpravKdr.h"
#include "PrintableDlg.h"
#include "addfacelessvag.h"

// CDlgPodkatTL1520 dialog
extern char g_cDepESR[16];

IMPLEMENT_DYNAMIC(CDlgPodkatTL1520, CDialog)
CDlgPodkatTL1520::CDlgPodkatTL1520(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPodkatTL1520::IDD, pParent)
{
	iGotHeader = 0;
	iVagCount = 0;
}

CDlgPodkatTL1520::~CDlgPodkatTL1520()
{
}

void CDlgPodkatTL1520::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT2, m_EdESR);
	DDX_Control(pDX, IDC_EDIT7, m_EdPark);
	DDX_Control(pDX, IDC_EDIT43, m_EdWay);
	DDX_Control(pDX, IDC_EDIT120, m_EdFIO);
	DDX_Control(pDX, IDC_EDIT4, m_Dat);
	DDX_Control(pDX, IDC_EDIT3, m_EdFIO2);
}


BEGIN_MESSAGE_MAP(CDlgPodkatTL1520, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClicked_AddVag)
	ON_BN_CLICKED(IDCANCEL2, OnBnClicked_OK)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton_DeleteVan)
	ON_BN_CLICKED(IDCANCEL3, OnBnClickedCancel_Naryad)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton_VagOnPPT)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedButton_FIO)
	ON_EN_CHANGE(IDC_EDIT3, &CDlgPodkatTL1520::OnEnChangeEdit3)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgPodkatTL1520::OnBnClickedButton_Slesar)
END_MESSAGE_MAP()


// CDlgPodkatTL1520 message handlers

void CDlgPodkatTL1520::OnBnClicked_AddVag()
{
	char cQ[255] = "";
	char cText[64] = "";

	if( m_Dat.isNull() )
	{
		AfxMessageBox("Необходимо указать дату!");
		m_Dat.SetFocus();
		return;
	}

	if( !m_EdFIO.GetData() )
	{
		AfxMessageBox("Необходимо указать фамилию бригадира!");
		m_EdFIO.SetFocus();
		return;
	}


	if( !m_EdNVag.GetWindowText(cText, 64) )
	{
		AfxMessageBox("Необходимо указать номер вагона!");
		return;
	}

	long Ind = 0;
	int	iRet = 0;
	char cMess[1024] = "";
	CString ss = cText;
	ss.TrimRight(" ");
	sprintf(cQ, "pTov_pptAddVagVkt '%s'", ss);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SLONG, &iRet, 4, &Ind);
	if( iRet == -1 )
	{
		DBW.GetData(2, SQL_C_CHAR, cMess, 1024, &Ind);
		AfxMessageBox(cMess);
		DBW.CloseCursor();
		DBW.ReallocHandle();
		return;
	}
	else
	{
		DBW.GetData(2, SQL_C_UBIGINT, &pVagList[iVagCount].qwVagID, 8, &Ind);
		DBW.GetData(3, SQL_C_CHAR, pVagList[iVagCount].cNVag32, 32, &Ind);
		DBW.GetData(4, SQL_C_CHAR, &pVagList[iVagCount].cPos1, 4, &Ind);
		DBW.GetData(5, SQL_C_CHAR, &pVagList[iVagCount].cPos2, 4, &Ind);
		DBW.GetData(6, SQL_C_CHAR, pVagList[iVagCount].cDatPodk16, 16, &Ind);
		DBW.GetData(7, SQL_C_CHAR, pVagList[iVagCount].cNTL1, 32, &Ind);
		DBW.GetData(8, SQL_C_CHAR, pVagList[iVagCount].cNTL2, 32, &Ind);
		DBW.GetData(9, SQL_C_CHAR, pVagList[iVagCount].cFIO64, 64, &Ind);
		m_EdFIO2.GetWindowText(pVagList[iVagCount].cFIO64_Sles, 64);
		pVagList[iVagCount].iFam_Sles = m_EdFIO2.GetData();
	}
	DBW.CloseCursor();
	DBW.ReallocHandle();
	for( int i=0; i < iVagCount; i++ )
		if( pVagList[iVagCount].qwVagID == pVagList[i].qwVagID )
		{
			AfxMessageBox("Указанный вагон уже есть в списке!");
			return;
		}

	// Тележек этого вагона нет на складе
	if( pVagList[iVagCount].cPos1[0] == 0 )
	{
		CAddFacelessVag Dlg;
		Dlg.dwBrigadir_ID = m_EdFIO.GetData();
		strncpy( Dlg.cNTL1, pVagList[iVagCount].cNTL1, 16);
		strncpy( Dlg.cNTL2, pVagList[iVagCount].cNTL2, 16);

		if( Dlg.DoModal() == IDOK )
		{
			strncpy(pVagList[iVagCount].cTlVag, Dlg.strNVag,9);
			pVagList[iVagCount].qwTlVagID = Dlg.qwTlVagID;
			pVagList[iVagCount].iPrihVag = Dlg.iVagPrih;
//			pVagList[iVagCount].qwReplacedVagID = Dlg.qwReplaceVagID;
		} else
			return;
	}
	iVagCount++;
	RefreshList();
	m_EdNVag.SetWindowText("");
//	OnOK();
}

BOOL CDlgPodkatTL1520::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

	m_List.InsertColumn(0, "№ Вагона", LVCFMT_LEFT, 100);
	m_List.InsertColumn(1, "Слесарь", LVCFMT_LEFT, 150);
	m_List.InsertColumn(2, "Домкрат", LVCFMT_LEFT, 60);
	m_List.InsertColumn(3, "Ряд", LVCFMT_LEFT, 60);
	m_List.InsertColumn(4, "Дата подкатки", LVCFMT_LEFT, 100);
	m_List.InsertColumn(5, "№ тележ.1", LVCFMT_LEFT, 100);
	m_List.InsertColumn(6, "№ тележ.2", LVCFMT_LEFT, 100);
	m_List.InsertColumn(7, "Бригадир", LVCFMT_LEFT, 100);
	m_List.InsertColumn(8, "№ вагона тележки", LVCFMT_LEFT, 150);
	

	m_EdESR.QInit(60);
	m_EdPark.QInit(90);
	m_EdWay.QInit(90);
	m_EdESR.SetWindowText(g_cDepESR);

	m_EdFIO.SetMode(5);
	DBW.FillEmplArray(m_EdFIO.lpEmpl, 17);

	m_EdFIO2.SetMode(5);
	DBW.FillEmplArray(m_EdFIO2.lpEmpl, 0);
	m_Dat.SetMode(1);

	char cQ[512] = "";
	long Ind = 0;
//	sprintf(cQ, "pTov_pptVagPutVktList ", );
	

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgPodkatTL1520::OnBnClicked_OK()
{
	if( !m_EdFIO.GetData())
	{
		AfxMessageBox("Необходимо указать фамилию бригадира!");
		m_EdFIO.SetFocus();
		return;
	}
	if( m_Dat.isNull() )
	{
		AfxMessageBox("Необходимо указать дату перестановки!");
		m_Dat.SetFocus();
		return;
	}
	char cQ[255] = "";
	long lNum = 0;
	long Ind = 0;
	for( int i=0; i < iVagCount; i++ )
	{
		sprintf(cQ, "pTov_pptVagVkt %u, %s, %s, %s, %s, %s, %s",
			g_iDep,
			isNull(pVagList[i].qwVagID),
			isNull(pVagList[i].cNVag32),
			m_Dat.GetSQLDate(),
			isNull(m_EdFIO.GetData()),
			isNull(pVagList[i].qwTlVagID),
			isNull(pVagList[i].iFam_Sles)
			);
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();

		if( pVagList[i].iPrihVag ) // нужно оформить приход вагону (когда меняем тележки)
		{
			sprintf(cQ, "pTov_pptVagPkt %u, NULL, %s, %s, %s, %s, %s, NULL, NULL",
					g_iDep,					
					pVagList[i].cTlVag,
					m_Dat.GetSQLDate(),
					isNull(m_EdFIO.GetData()),
					pVagList[i].cNTL1,
					pVagList[i].cNTL2);
			DBW.ExecSQL(cQ);
			DBW.Fetch();
			DBW.GetData(1, SQL_C_SLONG, &lNum, 4, &Ind);
			if( lNum == -1 )
			{
				char cMess[2048] = "";
				DBW.GetData(2, SQL_C_CHAR, cMess, 2048, &Ind);
				AfxMessageBox(cMess);
				DBW.CloseCursor();
				return;
			} /*else
			if( lNum == 1 )
			{
				DBW.GetData(2, SQL_C_UBIGINT, &qwPTVag_ID, 8, &Ind);
			}*/
			DBW.CloseCursor();
		}

		if( pVagList[i].qwTlVagID )
		{
			sprintf(cQ, "pTov_pptTrafIns %s", isNull(pVagList[i].qwTlVagID));
			DBW.ExecSQL(cQ);
			DBW.CloseCursor();
			DBW.ReallocHandle();
		}
	}
	OnOK();
}

void CDlgPodkatTL1520::OnBnClickedButton_DeleteVan()
{
	int idx = m_List.GetSelectionMark();
	if( idx == -1 ) return;

	for( int i=idx; i < iVagCount && i < 127; i++ )
	{
		pVagList[i] = pVagList[i+1];
	}
	iVagCount--;
	RefreshList();
}

void CDlgPodkatTL1520::OnBnClickedCancel_Naryad()
{
	char cQ[512] = "pTov_mkcReportVagCrTabILK";
	char cText[64] = "";
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	for( int i=0; i < m_List.GetItemCount(); i++ )
	{
//		m_List.GetItemText(i, 0, cText, 64);
		sprintf(cQ, "pTov_mkcReportVagInsILK %s, %s", isNull(pVagList[i].qwVagID),  isNull(pVagList[i].iFam_Sles) );
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();
	}
	CPrintableDlg Dlg;
	m_EdFIO.GetWindowText(cText, 64);
	sprintf(Dlg.cQ, "pTov_mkcReportPptVag1520 %u, %s, %s", g_iDep, m_Dat.GetSQLDate(), isNull(cText));
	Dlg.DoModal();
}

void CDlgPodkatTL1520::OnBnClickedButton_VagOnPPT()
{
	char cQ[512] = "";
	DWORD dwCol = 0;
	long Ind = 0;
	char cText1[64], cText2[64];
	m_EdPark.GetWindowText(cText1, 64);
	m_EdWay.GetWindowText(cText2, 64);

	sprintf(cQ, "pTov_pptVagPutVktList %u, %s, %s, %s",
				g_iDep,
				m_EdESR.GetString(1),
				isNull((DWORD)atoi(cText1)),
				isNull((DWORD)atoi(cText2)));
	DBW.ExecSQL(cQ);
	for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i <128; i++ )
	{
		DBW.GetData(1, SQL_C_UBIGINT, &pVagList[iVagCount].qwVagID, 8, &Ind);
		DBW.GetData(2, SQL_C_CHAR, pVagList[iVagCount].cNVag32, 32, &Ind);
		DBW.GetData(3, SQL_C_CHAR, &pVagList[iVagCount].cPos1, 4, &Ind);
		DBW.GetData(4, SQL_C_CHAR, &pVagList[iVagCount].cPos2, 4, &Ind);
		DBW.GetData(5, SQL_C_CHAR, pVagList[iVagCount].cDatPodk16, 16, &Ind);
		DBW.GetData(6, SQL_C_CHAR, pVagList[iVagCount].cNTL1, 32, &Ind);
		DBW.GetData(7, SQL_C_CHAR, pVagList[iVagCount].cNTL2, 32, &Ind);
		DBW.GetData(8, SQL_C_CHAR, pVagList[iVagCount].cFIO64, 64, &Ind);
		m_EdFIO2.GetWindowText(pVagList[iVagCount].cFIO64_Sles, 64);
		pVagList[iVagCount].iFam_Sles = m_EdFIO2.GetData();
		iVagCount++;
	}
	DBW.CloseCursor();
	RefreshList();
}

void CDlgPodkatTL1520::OnBnClickedButton_FIO()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 17;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFIO.SetData(Dlg.dwFio);
	m_EdFIO.SetWindowText(Dlg.cFio);
}

void CDlgPodkatTL1520::RefreshList(void)
{
	m_List.DeleteAllItems();
	for( int i=0; i < iVagCount; i++ )
	{
		m_List.InsertItem(i, pVagList[i].cNVag32);
		m_List.qwSetItemData(i, pVagList[i].qwVagID);
		m_List.SetItemText(i, 1, pVagList[i].cFIO64_Sles);
		m_List.SetItemText(i, 2, pVagList[i].cPos1);
		m_List.SetItemText(i, 3, pVagList[i].cPos2);
		m_List.SetItemText(i, 4, pVagList[i].cDatPodk16);
		m_List.SetItemText(i, 5, pVagList[i].cNTL1);
		m_List.SetItemText(i, 6, pVagList[i].cNTL2);
		m_List.SetItemText(i, 7, pVagList[i].cFIO64);
		m_List.SetItemText(i, 8, pVagList[i].cTlVag);		
	}
}

void CDlgPodkatTL1520::OnCancel()
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;	
	char cScript[10192] = "";

	/*
	if( iVagCount > 0 )
	{
		for( int i=0; i < iVagCount; i++ )
		{
			if( pVagList[i].qwReplacedVagID )
				sprintf(cScript, "%s\n exec pTov_pptDelVagPkt %s",
						cScript,
						isNull(pVagList[i].qwReplacedVagID));
		}
		if(cScript[0])
		{
			DBW.ExecSQL(cScript);
			DBW.CloseCursor();
			DBW.ReallocHandle();
		}
	}
	*/
	
	CDialog::OnCancel();
}

void CDlgPodkatTL1520::OnEnChangeEdit3()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialog::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}

void CDlgPodkatTL1520::OnBnClickedButton_Slesar()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 0;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFIO2.SetData(Dlg.dwFio);
	m_EdFIO2.SetWindowText(Dlg.cFio);
}
