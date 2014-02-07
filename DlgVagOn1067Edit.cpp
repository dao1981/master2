// DlgVagOn1067Edit.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgVagOn1067Edit.h"


// CDlgVagOn1067Edit dialog

IMPLEMENT_DYNAMIC(CDlgVagOn1067Edit, CDialog)

CDlgVagOn1067Edit::CDlgVagOn1067Edit(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgVagOn1067Edit::IDD, pParent)
{
	cNVag[0] = 0;
}

CDlgVagOn1067Edit::~CDlgVagOn1067Edit()
{
}

void CDlgVagOn1067Edit::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_ST_NVAG, m_labNVag);
	DDX_Control(pDX, IDC_EDIT9, m_EdKodAdm1);
	DDX_Control(pDX, IDC_EDIT78, m_EdKodAdm2);
	DDX_Control(pDX, IDC_EDIT10, m_EdAdmName1);
	DDX_Control(pDX, IDC_EDIT12, m_EdAdmName2);
	DDX_Control(pDX, IDC_EDIT1, m_EdOKPO1);
	DDX_Control(pDX, IDC_EDIT7, m_EdOKPO2);
	DDX_Control(pDX, IDC_EDIT6, m_EdOKPO3);
	DDX_Control(pDX, IDC_EDIT120, m_EdOKPO4);
	DDX_Control(pDX, IDC_EDIT3, m_EdName1);
	DDX_Control(pDX, IDC_EDIT16, m_EdName2);
	DDX_Control(pDX, IDC_EDIT116, m_EdName3);
	DDX_Control(pDX, IDC_EDIT74, m_EdName4);
	DDX_Control(pDX, IDC_EDIT5, m_EdKod2);
	DDX_Control(pDX, IDC_EDIT4, m_EdKod3);
	DDX_Control(pDX, IDC_EDIT93, m_EdKod4);
	DDX_Control(pDX, IDC_EDIT8, m_EdRod1);
	DDX_Control(pDX, IDC_EDIT146, m_EdNomAr);
	DDX_Control(pDX, IDC_EDIT131, m_EdSrokAr);
	DDX_Control(pDX, IDC_EDIT159, m_EdTip);
	DDX_Control(pDX, IDC_EDIT160, m_EdModel);
	DDX_Control(pDX, IDC_EDIT161, m_EdRodMod);
	DDX_Control(pDX, IDC_EDIT11, m_EdKartDat);
}


BEGIN_MESSAGE_MAP(CDlgVagOn1067Edit, CDialog)
	ON_BN_CLICKED(IDC_BUTTON7, &CDlgVagOn1067Edit::OnBnClickedButton_ZapFromKartot)
	ON_BN_CLICKED(IDC_BUTTON8, &CDlgVagOn1067Edit::OnBnClickedButton_UpdKartot)
END_MESSAGE_MAP()


// CDlgVagOn1067Edit message handlers

void CDlgVagOn1067Edit::PreInitDialog()
{
	// TODO: Add your specialized code here and/or call the base class

	CDialog::PreInitDialog();
}

BOOL CDlgVagOn1067Edit::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_labNVag.SetWindowText( cNVag );

	 m_EdKodAdm1.SetMode(0, 1);
	 m_EdKodAdm2.SetMode(0, 1);
	 m_EdAdmName1.SetMode(0, 1);
	 m_EdAdmName2.SetMode(0, 1);
	 m_EdOKPO1.SetMode(0, 1);
	 m_EdOKPO2.SetMode(0, 1);
	 m_EdOKPO3.SetMode(0, 1);
	 m_EdOKPO4.SetMode(0, 1);
	 m_EdName1.SetMode(0, 1);
	 m_EdName2.SetMode(0, 1);
	 m_EdName3.SetMode(0, 1);
	 m_EdName4.SetMode(0, 1);
	 m_EdKod2.SetMode(0, 1);
	 m_EdKod3.SetMode(0, 1);
	 m_EdKod4.SetMode(0, 1);
	 m_EdRod1.SetMode(0, 1);
	 m_EdNomAr.SetMode(0, 1);
	 m_EdSrokAr.SetMode(0, 1);
	 m_EdTip.SetMode(0, 1);
	 m_EdModel.SetMode(0, 1);
	 m_EdRodMod.SetMode(0, 1);
	 m_EdKartDat.SetMode(0, 1);

	COLORREF cl1 = RGB(240, 240, 255);
	COLORREF cl2 = RGB(250, 250, 220);

	 m_EdKodAdm1.SetBkColor(cl1);
	 m_EdKodAdm2.SetBkColor(cl2);
	 m_EdAdmName1.SetBkColor(cl1);
	 m_EdAdmName2.SetBkColor(cl2);
	 m_EdOKPO1.SetBkColor(cl1);
	 m_EdOKPO2.SetBkColor(cl1);
	 m_EdOKPO3.SetBkColor(cl2);
	 m_EdOKPO4.SetBkColor(cl2);
	 m_EdName1.SetBkColor(cl1);
	 m_EdName2.SetBkColor(cl1);
	 m_EdName3.SetBkColor(cl2);
	 m_EdName4.SetBkColor(cl2);
	 m_EdKod2.SetBkColor(cl1);
	 m_EdKod3.SetBkColor(cl2);
	 m_EdKod4.SetBkColor(cl2);
	 m_EdRod1.SetBkColor(cl1);
	 m_EdNomAr.SetBkColor(cl2);
	 m_EdSrokAr.SetBkColor(cl2);
	 m_EdTip.SetBkColor(cl2);
	 m_EdModel.SetBkColor(cl2);
	 m_EdRodMod.SetBkColor(cl2);
	 m_EdKartDat.SetBkColor(cl2);

	m_EdKodAdm1.ModifyStyle( 0, WS_DISABLED );
	m_EdKodAdm2.ModifyStyle( 0, WS_DISABLED );
	m_EdAdmName1.ModifyStyle( 0, WS_DISABLED );
	m_EdAdmName2.ModifyStyle( 0, WS_DISABLED );
	m_EdOKPO1.ModifyStyle( 0, WS_DISABLED );
	m_EdOKPO2.ModifyStyle( 0, WS_DISABLED );
	m_EdOKPO3.ModifyStyle( 0, WS_DISABLED );
	m_EdOKPO4.ModifyStyle( 0, WS_DISABLED );
	m_EdName1.ModifyStyle( 0, WS_DISABLED );
	m_EdName2.ModifyStyle( 0, WS_DISABLED );
	m_EdName3.ModifyStyle( 0, WS_DISABLED );
	m_EdName4.ModifyStyle( 0, WS_DISABLED );
	m_EdKod2.ModifyStyle( 0, WS_DISABLED );
	m_EdKod3.ModifyStyle( 0, WS_DISABLED );
	m_EdKod4.ModifyStyle( 0, WS_DISABLED );
	m_EdRod1.ModifyStyle( 0, WS_DISABLED );
	m_EdNomAr.ModifyStyle( 0, WS_DISABLED );
	m_EdSrokAr.ModifyStyle( 0, WS_DISABLED );
	m_EdTip.ModifyStyle( 0, WS_DISABLED );
	m_EdModel.ModifyStyle( 0, WS_DISABLED );
	m_EdRodMod.ModifyStyle( 0, WS_DISABLED );
	m_EdKartDat.ModifyStyle( 0, WS_DISABLED );

	LoadData();

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgVagOn1067Edit::LoadData()
{
	char cQ[255] = "", cText[64] = "";
	long Ind = 0;
	sprintf( cQ, "pTov_ppt_GetVagData2 %s", cNVag );
	DBW.ExecSQL( cQ );
	DBW.Fetch();

	DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdKodAdm1.SetWindowText( cText );

	DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdAdmName1.SetWindowText( cText );

	DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdOKPO1.SetWindowText( cText );

	DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdName1.SetWindowText( cText );

	DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdOKPO2.SetWindowText( cText );

	DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdKod2.SetWindowText( cText );

	DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdName2.SetWindowText( cText );

	DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdRod1.SetWindowText( cText );

	DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdKartDat.SetWindowText( cText );
	
	DBW.GetData(10, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdKodAdm2.SetWindowText( cText );

	DBW.GetData(11, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdAdmName2.SetWindowText( cText );

	DBW.GetData(12, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdOKPO3.SetWindowText( cText );

	DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdKod3.SetWindowText( cText );

	DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdName3.SetWindowText( cText );

	DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdOKPO4.SetWindowText( cText );

	DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdKod4.SetWindowText( cText );

	DBW.GetData(17, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdName4.SetWindowText( cText );

	DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdNomAr.SetWindowText( cText );

	DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdSrokAr.SetWindowText( cText );


	DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdTip.SetWindowText( cText );

	DBW.GetData(21, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdModel.SetWindowText( cText );

	DBW.GetData(22, SQL_C_CHAR, cText, 64, &Ind );
	if( Ind != -1 ) m_EdRodMod.SetWindowText( cText );


	DBW.CloseCursor();
}

void CDlgVagOn1067Edit::OnBnClickedButton_ZapFromKartot()
{
/*
	CString s = "";
	m_EdKodAdm2.GetWindowText(s);
	m_EdKodAdm1.SetWindowText(s);

	m_EdAdmName2.GetWindowText(s);
	m_EdAdmName1.SetWindowText(s);


	m_EdOKPO3.GetWindowText(s);
	m_EdOKPO1.SetWindowText(s);
	m_EdName3.GetWindowText(s);
	m_EdName1.SetWindowText(s);

	m_EdOKPO4.GetWindowText(s);
	m_EdOKPO2.SetWindowText(s);
	m_EdKod4.GetWindowText(s);
	m_EdKod2.SetWindowText(s);
	m_EdName4.GetWindowText(s);
	m_EdName2.SetWindowText(s);
*/

	if( MessageBox("Заполнить данные по вагону из картотеки", "Внимание!", MB_YESNO) == IDNO ) return;

	char cQ[64] = "";
	sprintf( cQ, "pTov_ppt_SetVagDataFromAkpv %s", cNVag );
	DBW.ExecSQL( cQ );
	DBW.CloseCursor();
	
	LoadData();

}

void CDlgVagOn1067Edit::OnBnClickedButton_UpdKartot()
{
	char cQ[64] = "";
	sprintf( cQ, "pTov_ppt_UpdVagAkpv %s", cNVag );
	DBW.ExecSQL( cQ );
	DBW.CloseCursor();
	AfxMessageBox("Данные по вагону обновятся через несколько минут!");
	CDialog::OnCancel();
}
