// DlgPaspKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPaspKP.h"
#include "DlgSprPrSobstv.h"

// CDlgPaspKP dialog

IMPLEMENT_DYNAMIC(CDlgPaspKP, CDialog)

CDlgPaspKP::CDlgPaspKP(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgPaspKP::IDD, pParent)
{
	qwInitIZAP = 0;
	cNKP[0] = 0;
	iTKP = 0;
	cKlPrIzg[0] = 0;
	cYearIzg[0] = 0;
}

CDlgPaspKP::~CDlgPaspKP()
{
}

void CDlgPaspKP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdKlPrIzg);
	DDX_Control(pDX, IDC_EDIT2, m_EdNOs);
	DDX_Control(pDX, IDC_EDIT3, m_EdDatIzg);
	DDX_Control(pDX, IDC_COMBO1, m_cbTKP);
	DDX_Control(pDX, IDC_EDIT12, m_EdTKP);
	DDX_Control(pDX, IDC_EDIT4, m_EdSobstAdm);
	DDX_Control(pDX, IDC_EDIT5, m_EdSobstPr);
	DDX_Control(pDX, IDC_EDIT6, m_EdPorNom);
	DDX_Control(pDX, IDC_EDIT7, m_EdDatFor);
	DDX_Control(pDX, IDC_EDIT8, m_EdKlPrFor);
	DDX_Control(pDX, IDC_EDIT9, m_EdKR_KlPrIzg);
	DDX_Control(pDX, IDC_EDIT10, m_EdKR_Nom);
	DDX_Control(pDX, IDC_EDIT78, m_EdKR_DatIzg);
	DDX_Control(pDX, IDC_EDIT11, m_EdKR_NomPlav);
	DDX_Control(pDX, IDC_COMBO2, m_cbKR_MSteel);
	DDX_Control(pDX, IDC_EDIT13, m_EdKR_MSteel);
	DDX_Control(pDX, IDC_EDIT79, m_EdKR_Type);
	DDX_Control(pDX, IDC_CHECK1, m_ckKR_StarogKol);

	DDX_Control(pDX, IDC_EDIT80, m_EdKL_KlPrIzg);
	DDX_Control(pDX, IDC_EDIT81, m_EdKL_Nom);
	DDX_Control(pDX, IDC_EDIT82, m_EdKL_DatIzg);
	DDX_Control(pDX, IDC_EDIT75, m_EdKL_NomPlav);
	DDX_Control(pDX, IDC_COMBO37, m_cbKL_MSteel);
	DDX_Control(pDX, IDC_EDIT84, m_EdKL_MSteel);
	DDX_Control(pDX, IDC_EDIT158, m_EdKL_Type);
	DDX_Control(pDX, IDC_CHECK34, m_ckKL_StarogKol);
	DDX_Control(pDX, IDC_CHECK48, m_ckStarogOs);
	DDX_Control(pDX, IDC_BUTTON4, m_ButPrintPasp);
}


BEGIN_MESSAGE_MAP(CDlgPaspKP, CDialog)
	ON_BN_CLICKED(IDOK, &CDlgPaspKP::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON2, &CDlgPaspKP::OnBnClickedButton_Sobst)
	ON_EN_CHANGE(IDC_EDIT12, &CDlgPaspKP::OnEnChangeEdit12)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CDlgPaspKP::OnEnChangeComboTKP)
	ON_BN_CLICKED(IDC_BUTTON4, &CDlgPaspKP::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CDlgPaspKP::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDlgPaspKP message handlers

BOOL CDlgPaspKP::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdKlPrIzg.QInit(60, 1);
	m_EdNOs.QInit(60, 1);
	m_EdDatIzg.QInit(20, 1);
	m_EdTKP.QInit(10, 1);
	m_EdSobstAdm.QInit(20, 1);
	m_EdSobstPr.QInit(60, 1);
	m_EdPorNom.QInit(10, 1);
	m_EdDatFor.SetMode(3,1);
	m_EdKlPrFor.QInit(60, 1);
	m_EdKR_KlPrIzg.QInit(60, 1);
	m_EdKR_Nom.QInit(60, 1);
	m_EdKR_DatIzg.QInit(20, 1);
	m_EdKR_NomPlav.QInit(50, 1);
	m_EdKR_MSteel.QInit(10, 1);
	m_EdKR_Type.QInit(10, 1);

	m_EdKL_KlPrIzg.QInit(60, 1);
	m_EdKL_Nom.QInit(60, 1);
	m_EdKL_DatIzg.QInit(20, 1);
	m_EdKL_NomPlav.QInit(50, 1);
	m_EdKL_MSteel.QInit(10, 1);
	m_EdKL_Type.QInit(10, 1);

	DBW.FillComboWithTKP(&m_cbTKP);	

	if( qwInitIZAP )
	{
		char cQ[255] = "";
		char cText[64] = "";
		char cText2[64] = "";
		DWORD dwNum = 0;
		long Ind = 0;
		sprintf(cQ, "pTov_KP_GetPaspByIzap %d, %I64u", g_iDep, qwInitIZAP);
		DBW.ExecSQL(cQ);
		g_sqlret = DBW.Fetch();

		if( g_sqlret != SQL_NO_DATA && g_sqlret != SQL_ERROR )
		{
			DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKlPrIzg.SetWindowText(cText);
			DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdNOs.SetWindowText(cText);
			DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdDatIzg.SetWindowText(cText);
			DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdTKP.SetWindowText(cText);
			DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdSobstAdm.SetWindowText(cText);

			DBW.GetData(6, SQL_C_ULONG, &dwNum, 4, &Ind );
			if( Ind != -1 ) m_EdSobstPr.SetData(dwNum);
			DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdSobstPr.SetWindowText(cText);			
			
			DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdPorNom.SetWindowText(cText);
/*
			DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdDatFor.SetWindowText(cText);
*/
			SYSTEMTIME st;
			mgSQLGetSysDate(9, &st, &Ind);
			if( Ind != -1 ) m_EdDatFor.SetTime(&st);

			DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKlPrFor.SetWindowText(cText);
			DBW.GetData(11, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKR_KlPrIzg.SetWindowText(cText);
			DBW.GetData(12, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKR_Nom.SetWindowText(cText);
			DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 )
			{
				if( cText[1] == 0 ) { cText[1] = cText[0]; cText[0] = '0'; cText[2] = 0; }
				m_EdKR_DatIzg.SetWindowText(cText);
			}
			DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 )
			{
				if( strlen(cText) < 5 )
				{
					strcpy(cText2, "00000");
					strcpy(cText2 + 5 - strlen(cText), cText);
					m_EdKR_NomPlav.SetWindowText(cText2);
				} else
					m_EdKR_NomPlav.SetWindowText(cText);
			}
			DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKR_MSteel.SetWindowText(cText);
			DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKR_Type.SetWindowText(cText);

			DBW.GetData(17, SQL_C_ULONG, &dwNum, 4, &Ind );
			if( Ind != -1 ) m_ckKR_StarogKol.SetCheck(dwNum);


			DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKL_KlPrIzg.SetWindowText(cText);
			DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKL_Nom.SetWindowText(cText);
			DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) 
			{
				if( cText[1] == 0 ) { cText[1] = cText[0]; cText[0] = '0'; cText[2] = 0; }
				m_EdKL_DatIzg.SetWindowText(cText);
			}
			DBW.GetData(21, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 )
			{
				if( strlen(cText) < 5 )
				{
					strcpy(cText2, "00000");
					strcpy(cText2 + 5 - strlen(cText), cText);
					m_EdKL_NomPlav.SetWindowText(cText2);
				} else
					m_EdKL_NomPlav.SetWindowText(cText);
			}
			DBW.GetData(22, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKL_MSteel.SetWindowText(cText);
			DBW.GetData(23, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_EdKL_Type.SetWindowText(cText);

			DBW.GetData(24, SQL_C_ULONG, &dwNum, 4, &Ind );
			if( Ind != -1 ) m_ckKL_StarogKol.SetCheck(dwNum);

			DBW.GetData(25, SQL_C_ULONG, &dwNum, 4, &Ind );
			if( Ind != -1 ) m_ckStarogOs.SetCheck(dwNum);


			DBW.CloseCursor();
			m_ButPrintPasp.EnableWindow();
		} 
	} else
	if( cNKP[0] ) 
	{
		m_EdNOs.SetWindowText(cNKP);
		m_EdKlPrIzg.SetWindowText(cKlPrIzg);
		if( cYearIzg[2] == ' ') cYearIzg[2] = 0;
		if( strlen(cYearIzg) > 2 )
			m_EdDatIzg.SetWindowText(cYearIzg + 2);
		else
			m_EdDatIzg.SetWindowText(cYearIzg);

		m_EdTKP.SetValue((DWORD)iTKP);
		m_ButPrintPasp.EnableWindow(FALSE);
	}
	return TRUE; 
}

void CDlgPaspKP::OnBnClickedOk()
{
	char cQ[255] = "";
	int xxx = m_cbTKP.GetCurSel();
	char cDatIzg[64] = "";
	if( !m_EdDatIzg.isNull() )
	{
		if( m_EdDatIzg.GetAsDWord() < 20 )
			sprintf(cDatIzg, "'20%s0101'", m_EdDatIzg.GetString());
		else
			sprintf(cDatIzg, "'19%s0101'", m_EdDatIzg.GetString());
	} else
		strcpy(cDatIzg, "NULL");

	sprintf( cQ, "pTov_KP_SavePasp %u, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %s, %u, %u  ",
			g_iDep,
			isNull(qwInitIZAP),
			m_EdNOs.GetString(1),

//			m_EdDatIzg.GetSQLDate(),
			cDatIzg,
			isNull(m_EdKlPrIzg.GetAsDWord()),

			m_cbTKP.GetItemData(m_cbTKP.GetCurSel()),
			m_EdSobstAdm.GetString(1),
			isNull(m_EdSobstPr.GetData()),
			isNull(m_EdPorNom.GetAsDWord()),
			m_EdDatFor.GetSQLDate(),
			isNull(m_EdKlPrFor.GetAsDWord()), //10

			isNull(m_EdKR_KlPrIzg.GetAsDWord()),
			m_EdKR_Nom.GetString(1),
			m_EdKR_DatIzg.isNull() ? "NULL" : m_EdKR_DatIzg.GetAsString(),
			m_EdKR_NomPlav.isNull() ? "NULL" : CString("'") + m_EdKR_NomPlav.GetAsString() + "'",
			isNull(m_EdKR_MSteel.GetAsDWord()),
			isNull(m_EdKR_Type.GetAsDWord()),
			m_ckKR_StarogKol.GetCheck(), //17

			isNull(m_EdKL_KlPrIzg.GetAsDWord()),
			m_EdKL_Nom.GetString(1),
			isNull(m_EdKL_DatIzg.GetAsDWord()),
			m_EdKL_NomPlav.isNull() ? "NULL" : CString("'") + m_EdKL_NomPlav.GetAsString() + "'",
			isNull(m_EdKL_MSteel.GetAsDWord()),
			isNull(m_EdKL_Type.GetAsDWord()),
			m_ckKL_StarogKol.GetCheck(), //24

			m_ckStarogOs.GetCheck()
			);

	

	DBW.ExecSQL(cQ);
	DBW.CloseCursor();

	OnOK();
}


void CDlgPaspKP::OnBnClickedButton_Sobst()
{
	CDlgSprPrSobstv Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdSobstPr.SetData(Dlg.dwSobstID);
	m_EdSobstPr.SetWindowText(Dlg.cPrName);
}

void CDlgPaspKP::OnEnChangeEdit12()
{
	char cText[4]= "";
	m_EdTKP.GetWindowText(cText, 3);
	if( cText[0] < '0' || cText[0] > '9' ) return;
	SetComboBoxItemByID(&m_cbTKP, atoi(cText));
}

void CDlgPaspKP::OnEnChangeComboTKP()
{
	char cText[4]= "";
	int idx = m_cbTKP.GetCurSel();
	if( idx < 0 ) return;
	itoa( m_cbTKP.GetItemData(idx), cText, 10);
	m_EdTKP.SetWindowText(cText);
}

extern SQLCHAR      g_ConnStrIn[MAXBUFLEN];

void CDlgPaspKP::OnBnClickedButton4()
{
	typedef void (CALLBACK* CPrintVU55)(char*, int);
	CPrintVU55 VU55Form; 
	HMODULE hm = LoadLibrary ("hc_xls.dll");
	VU55Form = (CPrintVU55)GetProcAddress (hm, "PrintVU55");

	if (VU55Form)
	{
		VU55Form ((char*)g_ConnStrIn, qwInitIZAP);
	} else
	{
		AfxMessageBox("Ошибка формирования ВУ-55!");
	}
	FreeLibrary (hm);
}

void CDlgPaspKP::OnBnClickedButton3()
{
/*
	m_EdKlPrIzg.SetWindowText("");
	m_EdNOs.SetWindowText("");
	m_EdDatIzg.SetWindowText("");
	m_cbTKP.SetCurSel(-1);*/
	m_EdTKP.SetWindowText("");
	m_EdSobstAdm.SetWindowText("");
	m_EdSobstPr.SetWindowText("");
	m_EdPorNom.SetWindowText("");
	m_EdDatFor.SetWindowText("");
	m_EdKlPrFor.SetWindowText("");
	m_EdKR_KlPrIzg.SetWindowText("");
	m_EdKR_Nom.SetWindowText("");
	m_EdKR_DatIzg.SetWindowText("");
	m_EdKR_NomPlav.SetWindowText("");
	m_cbKR_MSteel.SetCurSel(-1);
	m_EdKR_MSteel.SetWindowText("");
	m_EdKR_Type.SetWindowText("");
	m_ckKR_StarogKol.SetCheck(0);

	m_EdKL_KlPrIzg.SetWindowText("");
	m_EdKL_Nom.SetWindowText("");
	m_EdKL_DatIzg.SetWindowText("");
	m_EdKL_NomPlav.SetWindowText("");
	m_cbKL_MSteel.SetCurSel(-1);
	m_EdKL_MSteel.SetWindowText("");
	m_EdKL_Type.SetWindowText("");
	m_ckKL_StarogKol.SetCheck(0);
	m_ckStarogOs.SetCheck(0);
}
