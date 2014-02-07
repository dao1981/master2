// DlgRegisterTL.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRegisterTL.h"
#include ".\dlgregistertl.h"
#include "dlgsprav1.h"
#include "dlgspravkdr.h"


// CDlgRegisterTL dialog

IMPLEMENT_DYNAMIC(CDlgRegisterTL, CDlgWithAccelerators)
CDlgRegisterTL::CDlgRegisterTL(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgRegisterTL::IDD, pParent)
{
	dwSender_IPR = 0;
	dwRamaIzg1_IPR = 0;
	dwRamaIzg2_IPR = 0;
	dwMesto_IPR = 0;
	dwBalka_IPR = 0;
	dwKP1_IPR = 0;
	dwKP2_IPR = 0;
	qwTL_ID = 0;

	qwITL = 0;
	qwITNB = 0;
	qwITBR = 0;
	cTlNum[0] = 0;
	iSomeAdded = 0;
	iMode = 0;
	dwDefIPR = 0;
}

CDlgRegisterTL::~CDlgRegisterTL()
{
}

void CDlgRegisterTL::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO3, m_Cb_LR_1);
	DDX_Control(pDX, IDC_COMBO6, m_Cb_LR_2);
	DDX_Control(pDX, IDC_COMBO7, m_Cb_LR_3);
	DDX_Control(pDX, IDC_COMBO19, m_Cb_LR_4);
	DDX_Control(pDX, IDC_COMBO4, m_Cb_TKP1);
	DDX_Control(pDX, IDC_COMBO5, m_Cb_TKP2);
	DDX_Control(pDX, IDC_EDIT2, m_DatPrih);
	DDX_Control(pDX, IDC_EDIT3, m_EdSenderKl);
	DDX_Control(pDX, IDC_EDIT7, m_EdSenderName);
	DDX_Control(pDX, IDC_EDIT5, m_EdFioMast);
	DDX_Control(pDX, IDC_EDIT116, m_EdRamaIzgKl);
	DDX_Control(pDX, IDC_EDIT4, m_EdRamaIzgName);
	DDX_Control(pDX, IDC_EDIT119, m_EdRamaIzg2Kl);
	DDX_Control(pDX, IDC_EDIT120, m_EdRamaIzg2Name);
	DDX_Control(pDX, IDC_EDIT76, m_EdBalkaIzgKl);
	DDX_Control(pDX, IDC_EDIT83, m_EdBalkaIzgName);
	DDX_Control(pDX, IDC_EDIT77, m_EdKP1IzgKl);
	DDX_Control(pDX, IDC_EDIT90, m_EdKP1IzgName);
	DDX_Control(pDX, IDC_EDIT91, m_EdKP2IzgKl);
	DDX_Control(pDX, IDC_EDIT124, m_EdKP2IzgName);
	DDX_Control(pDX, IDC_EDIT103, m_EdMestoKl);
	DDX_Control(pDX, IDC_EDIT126, m_EdMestoName);
	DDX_Control(pDX, IDC_EDIT85, m_DatKP1);
	DDX_Control(pDX, IDC_EDIT121, m_DatKP2);
	DDX_Control(pDX, IDC_EDIT1, m_EdNTL);
	DDX_Control(pDX, IDC_EDIT127, m_EdProbeg);
	DDX_Control(pDX, IDC_EDIT16, m_EdNBR1);
	DDX_Control(pDX, IDC_EDIT74, m_EdNBR2);
	DDX_Control(pDX, IDC_EDIT6, m_EdYear1);
	DDX_Control(pDX, IDC_EDIT71, m_EdYear2);
	DDX_Control(pDX, IDC_EDIT14, m_EdNNB);
	DDX_Control(pDX, IDC_EDIT84, m_EdYear3);
	DDX_Control(pDX, IDC_EDIT118, m_EdNKP1);
	DDX_Control(pDX, IDC_EDIT123, m_EdNKP2);
	DDX_Control(pDX, IDC_EDIT125, m_DatKompl);
}


BEGIN_MESSAGE_MAP(CDlgRegisterTL, CDlgWithAccelerators)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedBut_SelectSender)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedBut_SelectMaster)
	ON_CBN_SELCHANGE(IDC_COMBO3, OnCbnSelchangeCb_LR1)
	ON_CBN_SELCHANGE(IDC_COMBO6, OnCbnSelchangeCb_LR2)
	ON_CBN_SELCHANGE(IDC_COMBO7, OnCbnSelchangeCb_LR3)
	ON_CBN_SELCHANGE(IDC_COMBO19, OnCbnSelchangeCb_LR4)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedBut_SelectIzgRama1)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedBut_SelectIzgRama2)
	ON_BN_CLICKED(IDC_BUTTON15, OnBnClickedBut_SelectBalkaPr)
	ON_BN_CLICKED(IDC_BUTTON23, OnBnClickedBut_SelectIzgKp1)
	ON_BN_CLICKED(IDC_BUTTON27, OnBnClickedBut_SelectIzgKP2)
	ON_BN_CLICKED(IDC_BUTTON28, OnBnClickedBu_SelectMesto)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON7, OnBnClickedButton_AddToBase)
END_MESSAGE_MAP()


// CDlgRegisterTL message handlers

BOOL CDlgRegisterTL::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();
	InitForm();
	char cQ[512] = "";
	char cText[64] = "";
	long Ind = 0;
	if( !iMode )
	{
		sprintf(cQ, "pTov_GetNewNTLppt %u", g_iDep);
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cTlNum, 32, &Ind);
		if( cTlNum[0] == '-' )
		{
			char cMess[512] = "";
			DBW.GetData(2, SQL_C_CHAR, cMess, 512, &Ind);
			DBW.CloseCursor();
			AfxMessageBox(cMess);
			OnCancel();
			return FALSE;
		}
		DBW.GetData(2, SQL_C_UBIGINT, &qwITL, 8, &Ind);
		DBW.GetData(3, SQL_C_UBIGINT, &qwITBR, 8, &Ind);
		DBW.GetData(4, SQL_C_UBIGINT, &qwITNB, 8, &Ind);

		DBW.GetData(5, SQL_C_ULONG, &dwDefIPR, 4, &Ind);
		if( Ind != -1 )
		{
			dwRamaIzg2_IPR = dwBalka_IPR = dwKP1_IPR = dwKP2_IPR = dwRamaIzg1_IPR = dwDefIPR;
			DBW.GetData(6, SQL_C_CHAR, cText, 32, &Ind);
			if( Ind != -1 )
			{
				strcpy(cDefKLPR, cText);
				m_EdBalkaIzgKl.SetWindowText(cText);
				m_EdRamaIzgKl.SetWindowText(cText);
				m_EdRamaIzg2Kl.SetWindowText(cText);
				m_EdKP1IzgKl.SetWindowText(cText);
				m_EdKP2IzgKl.SetWindowText(cText);
			}			
			DBW.GetData(7, SQL_C_CHAR, cText, 32, &Ind);
			if( Ind != -1 )
			{
				strcpy(cDefPrName, cText);
				m_EdBalkaIzgName.SetWindowText(cText);
				m_EdRamaIzgName.SetWindowText(cText);
				m_EdRamaIzg2Name.SetWindowText(cText);
				m_EdKP1IzgName.SetWindowText(cText);
				m_EdKP2IzgName.SetWindowText(cText);
			}
		}

		DBW.CloseCursor();
		m_EdNTL.SetWindowText(cTlNum);
	} else
	{
		SQL_DATE_STRUCT  sqlDat;
		DWORD dwNum = 0;

		sprintf(cQ, "pTov_GetPrihodTLpptByIZap %I64u", qwTL_ID);
		DBW.ExecSQL(cQ);
		DBW.Fetch();

		DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdNTL.SetWindowText(cText);
		DBW.GetData(2, SQL_C_DATE, &sqlDat, sizeof(sqlDat), &Ind);
		if( Ind != -1 ) m_DatPrih.SetDate(sqlDat);
		DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdProbeg.SetWindowText(cText);
		DBW.GetData(5, SQL_C_ULONG, &dwSender_IPR, 4, &Ind);
		DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdSenderKl.SetWindowText(cText);
		DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdSenderName.SetWindowText(cText);
		DBW.GetData(8, SQL_C_ULONG, &dwNum, 4, &Ind);
		DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 )
		{
			m_EdFioMast.SetData(dwNum);
			m_EdFioMast.SetWindowText(cText);
		}
		DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdNNB.SetWindowText(cText);
		DBW.GetData(11, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdYear3.SetWindowText(cText);

		DBW.GetData(12, SQL_C_ULONG, &dwBalka_IPR, 4, &Ind);
		DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdBalkaIzgKl.SetWindowText(cText);
		DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdBalkaIzgName.SetWindowText(cText);
//Боковая рама (левая)
		DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdNBR1.SetWindowText(cText);
		DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdYear1.SetWindowText(cText);
		DBW.GetData(17, SQL_C_ULONG, &dwRamaIzg1_IPR, 4, &Ind);
		DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdRamaIzgKl.SetWindowText(cText);
		DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdRamaIzgName.SetWindowText(cText);
//Боковая рама (правая)
		DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdNBR2.SetWindowText(cText);
		DBW.GetData(21, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdYear2.SetWindowText(cText);
		DBW.GetData(22, SQL_C_ULONG, &dwRamaIzg2_IPR, 4, &Ind);
		DBW.GetData(23, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdRamaIzg2Kl.SetWindowText(cText);
		DBW.GetData(24, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_EdRamaIzg2Name.SetWindowText(cText);
		DBW.GetData(25, SQL_C_UBIGINT, &qwITL, 8, &Ind);
		DBW.GetData(26, SQL_C_UBIGINT, &qwITNB, 8, &Ind);
		DBW.GetData(27, SQL_C_UBIGINT, &qwITBR, 8, &Ind);		
		DBW.CloseCursor();
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgRegisterTL::InitForm(void)
{
	m_Cb_LR_1.AddString("Левая");
	m_Cb_LR_1.AddString("Правая");
	m_Cb_LR_1.SetItemData(0,0);
	m_Cb_LR_1.SetItemData(1,1);
	m_Cb_LR_1.SetCurSel(0);


	m_Cb_LR_2.AddString("Левая");
	m_Cb_LR_2.AddString("Правая");
	m_Cb_LR_2.SetItemData(0,0);
	m_Cb_LR_2.SetItemData(1,1);
	m_Cb_LR_2.SetCurSel(1);

	m_Cb_LR_3.AddString("Первая");
	m_Cb_LR_3.AddString("Вторая");
	m_Cb_LR_3.SetItemData(0,0);
	m_Cb_LR_3.SetItemData(1,1);
	m_Cb_LR_3.SetCurSel(0);

	m_Cb_LR_4.AddString("Первая");
	m_Cb_LR_4.AddString("Вторая");
	m_Cb_LR_4.SetItemData(0,0);
	m_Cb_LR_4.SetItemData(1,1);
	m_Cb_LR_4.SetCurSel(1);

	DBW.FillComboWithTKP(&m_Cb_TKP1);
	DBW.FillComboWithTKP(&m_Cb_TKP2);

	m_Cb_TKP1.SetCurSel(0);
	m_Cb_TKP2.SetCurSel(0);

	m_DatPrih.SetMode(1);

	m_EdSenderName.ModifyStyle(0, WS_DISABLED, 0);
	m_EdRamaIzgName.ModifyStyle(0, WS_DISABLED, 0);
	m_EdRamaIzg2Name.ModifyStyle(0, WS_DISABLED, 0);
	m_EdBalkaIzgKl.ModifyStyle(0, WS_DISABLED, 0);

	m_EdFioMast.SetMode(5);
	DBW.FillEmplArray(m_EdFioMast.lpEmpl, 16);

	m_DatKP1.SetMode(3);
	m_DatKP2.SetMode(3);

	m_DatKompl.SetMode(1);
}

void CDlgRegisterTL::OnBnClickedBut_SelectSender()
{
	CDlgSprav1 Dlg;

	if( Dlg.DoModal() == IDCANCEL ) return;
	dwSender_IPR = Dlg.ret_dwIPR;
	m_EdSenderKl.SetWindowText(Dlg.cKodPr);
	m_EdSenderName.SetWindowText(Dlg.cPrName);
}

void CDlgRegisterTL::OnBnClickedBut_SelectMaster()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 16;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFioMast.SetWindowText(Dlg.cFio);
	m_EdFioMast.SetData(Dlg.dwFio);
}

void CDlgRegisterTL::OnCbnSelchangeCb_LR1()
{
	if( m_Cb_LR_1.GetItemData(m_Cb_LR_1.GetCurSel()) )
	{
		m_Cb_LR_2.SetCurSel(0);
	} else
		m_Cb_LR_2.SetCurSel(1);
}

void CDlgRegisterTL::OnCbnSelchangeCb_LR2()
{
	if( m_Cb_LR_2.GetItemData(m_Cb_LR_2.GetCurSel()) )
	{
		m_Cb_LR_1.SetCurSel(0);
	} else
		m_Cb_LR_1.SetCurSel(1);
}

void CDlgRegisterTL::OnCbnSelchangeCb_LR3()
{
	if( m_Cb_LR_3.GetItemData(m_Cb_LR_3.GetCurSel()) )
	{
		m_Cb_LR_4.SetCurSel(0);
	} else
		m_Cb_LR_4.SetCurSel(1);
}

void CDlgRegisterTL::OnCbnSelchangeCb_LR4()
{
	if( m_Cb_LR_4.GetItemData(m_Cb_LR_4.GetCurSel()) )
	{
		m_Cb_LR_3.SetCurSel(0);
	} else
		m_Cb_LR_3.SetCurSel(1);

}

void CDlgRegisterTL::OnBnClickedBut_SelectIzgRama1()
{
	CDlgSprav1 Dlg;
	Dlg.iDlgKind = 8;

	if( Dlg.DoModal() == IDCANCEL ) return;
	dwRamaIzg1_IPR = Dlg.ret_dwIPR;
	m_EdRamaIzgKl.SetWindowText(Dlg.cKodPr);
	m_EdRamaIzgName.SetWindowText(Dlg.cPrName);
	
}

void CDlgRegisterTL::OnBnClickedBut_SelectIzgRama2()
{
	CDlgSprav1 Dlg;
	Dlg.iDlgKind = 8;

	if( Dlg.DoModal() == IDCANCEL ) return;
	dwRamaIzg2_IPR = Dlg.ret_dwIPR;
	m_EdRamaIzg2Kl.SetWindowText(Dlg.cKodPr);
	m_EdRamaIzg2Name.SetWindowText(Dlg.cPrName);
}

void CDlgRegisterTL::OnBnClickedBut_SelectBalkaPr()
{
	CDlgSprav1 Dlg;
	Dlg.iDlgKind = 8;

	if( Dlg.DoModal() == IDCANCEL ) return;
	dwBalka_IPR = Dlg.ret_dwIPR;
	m_EdBalkaIzgKl.SetWindowText(Dlg.cKodPr);
	m_EdBalkaIzgName.SetWindowText(Dlg.cPrName);
}


void CDlgRegisterTL::OnBnClickedBut_SelectIzgKp1()
{
	CDlgSprav1 Dlg;
	Dlg.iDlgKind = 4;

	if( Dlg.DoModal() == IDCANCEL ) return;
	dwKP1_IPR = Dlg.ret_dwIPR;
	m_EdKP1IzgKl.SetWindowText(Dlg.cKodPr);
	m_EdKP1IzgName.SetWindowText(Dlg.cPrName);
	
}

void CDlgRegisterTL::OnBnClickedBut_SelectIzgKP2()
{
	CDlgSprav1 Dlg;
	Dlg.iDlgKind = 4;

	if( Dlg.DoModal() == IDCANCEL ) return;
	dwKP2_IPR = Dlg.ret_dwIPR;
	m_EdKP2IzgKl.SetWindowText(Dlg.cKodPr);
	m_EdKP2IzgName.SetWindowText(Dlg.cPrName);
}

void CDlgRegisterTL::OnBnClickedBu_SelectMesto()
{
	CDlgSprav1 Dlg;
	Dlg.iDlgKind = 4;

	if( Dlg.DoModal() == IDCANCEL ) return;
	dwMesto_IPR = Dlg.ret_dwIPR;
	m_EdMestoKl.SetWindowText(Dlg.cKodPr);
	m_EdMestoName.SetWindowText(Dlg.cPrName);
}


void CDlgRegisterTL::OnBnClickedOk()
{
	if( m_DatPrih.isNull() )
	{
		AfxMessageBox("Необходимо указать дату!");
		m_DatPrih.SetFocus();
		return;
	}
	if( WriteData() ) return;
	OnOK();
}

void CDlgRegisterTL::ResetForm(void)
{
	m_EdNTL.SetWindowText("");
	m_DatPrih.SetWindowText("");
	m_EdProbeg.SetWindowText("");
	m_EdSenderKl.SetWindowText("");
	m_EdSenderName.SetWindowText("");
	m_EdFioMast.SetWindowText("");
	m_Cb_LR_1.SetCurSel(0);
	m_Cb_LR_3.SetCurSel(0);
	m_EdNBR1.SetWindowText("");
	m_EdNBR2.SetWindowText("");
	m_EdYear1.SetWindowText("");
	m_EdYear2.SetWindowText("");
	m_EdYear3.SetWindowText("");
	m_EdRamaIzg2Kl.SetWindowText("");
	m_EdRamaIzg2Name.SetWindowText("");
	m_EdRamaIzgKl.SetWindowText("");
	m_EdRamaIzgName.SetWindowText("");
	m_EdNNB.SetWindowText("");
	m_EdBalkaIzgKl.SetWindowText("");
	m_EdBalkaIzgName.SetWindowText("");

	m_EdNKP1.SetWindowText("");
	m_EdNKP2.SetWindowText("");
	m_Cb_TKP1.SetCurSel(0);
	m_Cb_TKP2.SetCurSel(0);
	m_DatKP1.SetWindowText("");
	m_DatKP2.SetWindowText("");
	m_EdKP1IzgKl.SetWindowText("");
	m_EdKP2IzgKl.SetWindowText("");
	m_EdKP1IzgName.SetWindowText("");
	m_EdKP2IzgName.SetWindowText("");
	m_DatKompl.SetWindowText("");
	m_EdMestoKl.SetWindowText("");
	m_EdMestoName.SetWindowText("");



	dwSender_IPR = 0;
	dwRamaIzg1_IPR = 0;
	dwRamaIzg2_IPR = 0;
	dwMesto_IPR = 0;
	dwBalka_IPR = 0;
	dwKP1_IPR = 0;
	dwKP2_IPR = 0;
	qwTL_ID = 0;
/*
	qwITL = 0;
	qwITNB = 0;
	qwITBR = 0;
*/
	cTlNum[0] = 0;

	iMode = 0;

	dwRamaIzg2_IPR = dwBalka_IPR = dwKP1_IPR = dwKP2_IPR = dwRamaIzg1_IPR = dwDefIPR;

	m_EdBalkaIzgKl.SetWindowText(cDefKLPR);
	m_EdRamaIzgKl.SetWindowText(cDefKLPR);
	m_EdRamaIzg2Kl.SetWindowText(cDefKLPR);
	m_EdKP1IzgKl.SetWindowText(cDefKLPR);
	m_EdKP2IzgKl.SetWindowText(cDefKLPR);
			
	m_EdBalkaIzgName.SetWindowText(cDefPrName);
	m_EdRamaIzgName.SetWindowText(cDefPrName);
	m_EdRamaIzg2Name.SetWindowText(cDefPrName);
	m_EdKP1IzgName.SetWindowText(cDefPrName);
	m_EdKP2IzgName.SetWindowText(cDefPrName);

	m_EdNTL.SetFocus();
}

void CDlgRegisterTL::OnBnClickedButton_AddToBase()
{
	char cNewNTL[32] = "";
	if( WriteData(cNewNTL) ) return;
	ResetForm();
	iSomeAdded = 1;
	char cQ[128] = "";
	long Ind = 0;
	sprintf(cQ, "pTov_GetNewNTLppt %u", g_iDep);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, cTlNum, 32, &Ind);
	DBW.GetData(2, SQL_C_UBIGINT, &qwITL, 8, &Ind);
	DBW.GetData(3, SQL_C_UBIGINT, &qwITBR, 8, &Ind);
	DBW.GetData(4, SQL_C_UBIGINT, &qwITNB, 8, &Ind);
	DBW.CloseCursor();


	strcpy(cTlNum, cNewNTL);
	m_EdNTL.SetWindowText(cTlNum);
}

int CDlgRegisterTL::WriteData(char *cNewNTL /*= NULL*/, __int64 *qw_NewITL /*= 0*/ , __int64 *qw_NewITBR /*= 0*/, __int64 *qwNewITNB /*= 0*/)
{
	if( m_DatPrih.isNull() )
	{
		AfxMessageBox("Необходимо указать дату прихода");
		m_DatPrih.SetFocus();
		return -1;
	}
	char	cQ[512] = "";
	char	cQRez[512] = "";
	char	cMess[1024] = "";
	int		iRet = 0;
	long	Ind = 0;
	CString strNTL, strProbeg, strNBR1, strNBR2, strNNB, strYear1, strYear2, strYear3, strNKP1, strNKP2;
	m_EdNTL.GetWindowText(strNTL);
	m_EdProbeg.GetWindowText(strProbeg);
	DWORD dwKM= atoi(strProbeg);
	m_EdNBR1.GetWindowText(strNBR1);
	m_EdNBR2.GetWindowText(strNBR2);
	m_EdNNB.GetWindowText(strNNB);
	m_EdYear1.GetWindowText(strYear1);
	m_EdYear2.GetWindowText(strYear2);
	m_EdYear3.GetWindowText(strYear3);
	m_EdNKP1.GetWindowText(strNKP1);
	m_EdNKP2.GetWindowText(strNKP2);

	int iTKP1 = 0, iTKP2 = 0;

	if( m_Cb_TKP1.GetCurSel() > -1) iTKP1 = m_Cb_TKP1.GetItemData(m_Cb_TKP1.GetCurSel());
	
	if( m_Cb_TKP2.GetCurSel() > -1) iTKP2 = m_Cb_TKP2.GetItemData(m_Cb_TKP2.GetCurSel());	
	if( iTKP1 > 10 ) iTKP1 = 0;
	if( iTKP2 > 10 ) iTKP2 = 0;

	sprintf(cQ, "pTov_PrihodTLppt %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %u, %s, %s, %s, %u, %s, %s, %s, %s",
			g_iDep,
			isNull(qwITL),
			isNull(qwITNB),
			isNull(qwITBR),
			isNull(qwTL_ID),
			isNull(strNTL),
			m_DatPrih.GetSQLDate(),
			isNull(m_EdFioMast.GetData()),
			isNull(dwSender_IPR),
			isNull(dwKM),
			m_Cb_LR_1.GetItemData(m_Cb_LR_1.GetCurSel()),
			
			isNull(strNBR1),
			isNull(dwRamaIzg1_IPR),
			isNull(strYear1),
			
			isNull(strNBR2),
			isNull(dwRamaIzg2_IPR),
			isNull(strYear2),
			
			isNull(strNNB),
			isNull(dwBalka_IPR),
			isNull(strYear3),

			m_Cb_LR_3.GetItemData(m_Cb_LR_3.GetCurSel()),

			isNull(strNKP1),
			isNull(DWORD(iTKP1)),
			isNull(dwKP1_IPR),
			m_DatKP1.GetSQLDate(),

			isNull(strNKP2),
			isNull(DWORD(iTKP2)),
			isNull(dwKP2_IPR),
			m_DatKP2.GetSQLDate(),

			m_DatKompl.GetSQLDate(),
			isNull(dwMesto_IPR)
			);
	sprintf(cQRez, "pTov_PrihodTLppt_Rez %u, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %u, %s, %u, %s, %s, %s, %u, %s, %s, %s, %s",
			g_iDep,
			isNull(qwITL),
			isNull(qwITNB),
			isNull(qwITBR),

//			isNull(qwTL_ID),

			isNull(strNTL),
			m_DatPrih.GetSQLDate(),
			isNull(m_EdFioMast.GetData()),
			isNull(dwSender_IPR),
			isNull(dwKM),
			m_Cb_LR_1.GetItemData(m_Cb_LR_1.GetCurSel()),
			
			isNull(strNBR1),
			isNull(dwRamaIzg1_IPR),
			isNull(strYear1),
			
			isNull(strNBR2),
			isNull(dwRamaIzg2_IPR),
			isNull(strYear2),
			
			isNull(strNNB),
			isNull(dwBalka_IPR),
			isNull(strYear3),

			m_Cb_LR_3.GetItemData(m_Cb_LR_3.GetCurSel()),

			isNull(strNKP1),
			isNull(DWORD(iTKP1)),
			isNull(dwKP1_IPR),
			m_DatKP1.GetSQLDate(),

			isNull(strNKP2),
			isNull(DWORD(iTKP2)),
			isNull(dwKP2_IPR),
			m_DatKP2.GetSQLDate(),

			m_DatKompl.GetSQLDate(),
			isNull(dwMesto_IPR)
			);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SLONG, &iRet, 4, &Ind);
	if( iRet == -1 )
	{
		DBW.GetData(2, SQL_C_CHAR, cMess, 1024, &Ind );
		AfxMessageBox(cMess);
		DBW.CloseCursor();
		return -1;
	}
	if( cNewNTL ) DBW.GetData(2, SQL_C_CHAR, cNewNTL, 32, &Ind);
	DBW.CloseCursor();

	DBW.ExecSQLRzv(cQRez);

	return 0;
}

