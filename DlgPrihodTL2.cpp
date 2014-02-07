// DlgPrihodTL2.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgPrihodTL2.h"
#include ".\dlgprihodtl2.h"
#include "DlgSprav1.h"
#include "DlgSpravKdr.h"
#include ".\telecom\teleI.h"

extern cd_TeleI *tele;

// CDlgPrihodTL2 dialog

IMPLEMENT_DYNAMIC(CDlgPrihodTL2, CDlgWithAccelerators)
CDlgPrihodTL2::CDlgPrihodTL2(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgPrihodTL2::IDD, pParent)
{
	qwILK = 0;
	i8Os = 0;
	qwIDS = 0;
	dwVRem = 0;
	ZeroMemory(&stDatPostVRem, sizeof(stDatPostVRem));
}

CDlgPrihodTL2::~CDlgPrihodTL2()
{
}

void CDlgPrihodTL2::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LABS1, m_Lab1);
	DDX_Control(pDX, IDC_E00, m_p[1][0]);
	DDX_Control(pDX, IDC_E10, m_p[2][0]);
	DDX_Control(pDX, IDC_E20, m_p[4][0]);
	DDX_Control(pDX, IDC_E30, m_p[5][0]);
	DDX_Control(pDX, IDC_E40, m_p[6][0]);
	DDX_Control(pDX, IDC_E50, m_p[7][0]);
	DDX_Control(pDX, IDC_ED60, m_p[8][0]);

	DDX_Control(pDX, IDC_E11, m_p[2][1]);
	DDX_Control(pDX, IDC_E21, m_p[4][1]);
	DDX_Control(pDX, IDC_E31, m_p[5][1]);
	DDX_Control(pDX, IDC_E41, m_p[6][1]);
	DDX_Control(pDX, IDC_E51, m_p[7][1]);
	DDX_Control(pDX, IDC_E81, m_p[8][1]);

	DDX_Control(pDX, IDC_E12, m_p[2][2]);
	DDX_Control(pDX, IDC_E22, m_p[4][2]);
	DDX_Control(pDX, IDC_E32, m_p[5][2]);
	DDX_Control(pDX, IDC_E42, m_p[6][2]);
	DDX_Control(pDX, IDC_E52, m_p[7][2]);
	DDX_Control(pDX, IDC_E62, m_p[8][2]);

	// вторая тележка 

	DDX_Control(pDX, IDC_E03, m_p[1][3]);
	DDX_Control(pDX, IDC_E13, m_p[2][3]);
	DDX_Control(pDX, IDC_E23, m_p[4][3]);
	DDX_Control(pDX, IDC_E33, m_p[5][3]);
	DDX_Control(pDX, IDC_E43, m_p[6][3]);
	DDX_Control(pDX, IDC_E53, m_p[7][3]);
	DDX_Control(pDX, IDC_E63, m_p[8][3]);

	DDX_Control(pDX, IDC_E14, m_p[2][4]);
	DDX_Control(pDX, IDC_E24, m_p[4][4]);
	DDX_Control(pDX, IDC_E34, m_p[5][4]);
	DDX_Control(pDX, IDC_E44, m_p[6][4]);
	DDX_Control(pDX, IDC_E54, m_p[7][4]);
	DDX_Control(pDX, IDC_E64, m_p[8][4]);

	DDX_Control(pDX, IDC_E15, m_p[2][5]);
	DDX_Control(pDX, IDC_E25, m_p[4][5]);
	DDX_Control(pDX, IDC_E35, m_p[5][5]);
	DDX_Control(pDX, IDC_E45, m_p[6][5]);
	DDX_Control(pDX, IDC_E55, m_p[7][5]);
	DDX_Control(pDX, IDC_E65, m_p[8][5]);

	// третья тележка

	DDX_Control(pDX, IDC_E19, m_p[1][6]);
	DDX_Control(pDX, IDC_E27, m_p[2][6]);
	DDX_Control(pDX, IDC_E28, m_p[4][6]);
	DDX_Control(pDX, IDC_E107, m_p[5][6]);
	DDX_Control(pDX, IDC_E108, m_p[6][6]);
	DDX_Control(pDX, IDC_E109, m_p[7][6]);
	DDX_Control(pDX, IDC_ED68, m_p[8][6]);

	DDX_Control(pDX, IDC_E26, m_p[2][7]);
	DDX_Control(pDX, IDC_E29, m_p[4][7]);
	DDX_Control(pDX, IDC_E66, m_p[5][7]);
	DDX_Control(pDX, IDC_E76, m_p[6][7]);
	DDX_Control(pDX, IDC_E110, m_p[7][7]);
	DDX_Control(pDX, IDC_E121, m_p[8][7]);

	DDX_Control(pDX, IDC_E111, m_p[2][8]);
	DDX_Control(pDX, IDC_E112, m_p[4][8]);
	DDX_Control(pDX, IDC_E57, m_p[5][8]);
	DDX_Control(pDX, IDC_E67, m_p[6][8]);
	DDX_Control(pDX, IDC_E113, m_p[7][8]);
	DDX_Control(pDX, IDC_E122, m_p[8][8]);

	// четвертая тележка 

	DDX_Control(pDX, IDC_E114, m_p[1][9]);
	DDX_Control(pDX, IDC_E115, m_p[2][9]);
	DDX_Control(pDX, IDC_E116, m_p[4][9]);
	DDX_Control(pDX, IDC_E39, m_p[5][9]);
	DDX_Control(pDX, IDC_E49, m_p[6][9]);
	DDX_Control(pDX, IDC_E59, m_p[7][9]);
	DDX_Control(pDX, IDC_E123, m_p[8][9]);

	DDX_Control(pDX, IDC_E117, m_p[2][10]);
	DDX_Control(pDX, IDC_E118, m_p[4][10]);
	DDX_Control(pDX, IDC_E74, m_p[5][10]);
	DDX_Control(pDX, IDC_E84, m_p[6][10]);
	DDX_Control(pDX, IDC_E94, m_p[7][10]);
	DDX_Control(pDX, IDC_E124, m_p[8][10]);

	DDX_Control(pDX, IDC_E119, m_p[2][11]);
	DDX_Control(pDX, IDC_E120, m_p[4][11]);
	DDX_Control(pDX, IDC_E75, m_p[5][11]);
	DDX_Control(pDX, IDC_E85, m_p[6][11]);
	DDX_Control(pDX, IDC_E95, m_p[7][11]);
	DDX_Control(pDX, IDC_E125, m_p[8][11]);

	DDX_Control(pDX, IDC_COMBO1, m_c[0]);
	DDX_Control(pDX, IDC_COMBO21, m_c[1]);
	DDX_Control(pDX, IDC_COMBO33, m_c[2]);
	DDX_Control(pDX, IDC_COMBO23, m_c[3]);
	DDX_Control(pDX, IDC_COMBO25, m_c[4]);
	DDX_Control(pDX, IDC_COMBO26, m_c[5]);
	DDX_Control(pDX, IDC_COMBO30, m_c[6]);
	DDX_Control(pDX, IDC_COMBO40, m_c[7]);
	DDX_Control(pDX, IDC_COMBO41, m_c[8]);
	DDX_Control(pDX, IDC_COMBO42, m_c[9]);
	DDX_Control(pDX, IDC_COMBO43, m_c[10]);
	DDX_Control(pDX, IDC_COMBO44, m_c[11]);


	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT2, m_EdVidRem);
	DDX_Control(pDX, IDC_EDIT6, m_EdDatPost);
	DDX_Control(pDX, IDC_EDIT7, m_EdDatVyhRem);
	DDX_Control(pDX, IDC_EDIT3, m_EdDatVykatki);
	DDX_Control(pDX, IDC_EDIT16, m_EdFamMast);
	DDX_Control(pDX, IDC_BUTTON7, m_bnFrom2730);
	DDX_Control(pDX, IDC_BUTTON16, m_bnReport);
	DDX_Control(pDX, IDOK, m_bnOK);
	DDX_Control(pDX, IDCANCEL, m_bnCancel);	
	DDX_Control(pDX, IDC_BUTTON29, m_bnSendToAsld);
}


BEGIN_MESSAGE_MAP(CDlgPrihodTL2, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO21, OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO33, OnCbnSelchangeCombo2)
	ON_CBN_SELCHANGE(IDC_COMBO25, OnCbnSelchangeCombo4)
	ON_CBN_SELCHANGE(IDC_COMBO26, OnCbnSelchangeCombo5)
	ON_CBN_SELCHANGE(IDC_COMBO40, OnCbnSelchangeCombo7)
	ON_CBN_SELCHANGE(IDC_COMBO41, OnCbnSelchangeCombo8)
	ON_CBN_SELCHANGE(IDC_COMBO43, OnCbnSelchangeCombo10)
	ON_CBN_SELCHANGE(IDC_COMBO44, OnCbnSelchangeCombo11)
	ON_BN_CLICKED(IDC_BUTTON7, OnBnClickedButtonFill2730)
	ON_BN_CLICKED(IDC_BUTTON25, OnBnClickedButton25)
	ON_BN_CLICKED(IDC_BUTTON38, OnBnClickedButton38)
	ON_BN_CLICKED(IDC_BUTTON43, OnBnClickedButton43)
	ON_BN_CLICKED(IDC_BUTTON33, OnBnClickedButton33)
	ON_BN_CLICKED(IDC_BUTTON34, OnBnClickedButton34)
	ON_BN_CLICKED(IDC_BUTTON44, OnBnClickedButton44)
	ON_BN_CLICKED(IDC_BUTTON51, OnBnClickedButton51)
	ON_BN_CLICKED(IDC_BUTTON52, OnBnClickedButton52)
	ON_BN_CLICKED(IDC_BUTTON53, OnBnClickedButton53)
	ON_BN_CLICKED(IDC_BUTTON54, OnBnClickedButton54)
	ON_BN_CLICKED(IDC_BUTTON55, OnBnClickedButton55)
	ON_BN_CLICKED(IDC_BUTTON56, OnBnClickedButton56)

	ON_BN_CLICKED(IDC_BUTTON29, OnBnClickedSendAsld)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_EN_KILLFOCUS(IDC_E10, OnEnKillfocusE10)
	ON_BN_CLICKED(IDC_BUTTON16, OnBnClickedButtonReport)
END_MESSAGE_MAP()


// CDlgPrihodTL2 message handlers

int CDlgPrihodTL2::SaveData()
{
		SetAllIPR();

	char cScript[10000] = "";
	char cProcGetILK[255] = "";
	CString strProcPrihFromVag[4];
	SYSTEMTIME stVyk, st1;
	ZeroMemory(&stVyk, sizeof(stVyk));

	char cText[220] = "";

	m_EdDatVykatki.GetTime(&stVyk);

	// делаю так чтобы сравнивать только даты (без времени)
	st1 = stDatVyhIzRem;
	st1.wHour = 0;
	st1.wMinute = 0;


	if(st1.wYear && SysDateCmp(st1, stVyk) < 0 )
	{
		AfxMessageBox("Дата выкатки не может быть позже даты выхода из ремонта!", MB_OK );
		return -1;
	}

	st1 = stDatPostVRem;
	st1.wHour = 0;
	st1.wMinute = 0;
	if( SysDateCmp(st1, stVyk) > 0 )
	{
		AfxMessageBox("Дата выкатки не может быть раньше даты поступления в ремонт!", MB_OK );
		return -1;
	}


	DateToSql(stDatPostVRem, cText);
	sprintf( cProcGetILK, "pTov_GetILKbyNVag %d, '%s', %s, %s",
			g_iDep,
			m_EdNVag.GetAsString(),
			isNull(dwVRem),
			cText);
	
//	int iOrder = !m_c[i + 1].GetCurSel();

	for( int i=0; ( i < 2 && !i8Os ) || ( i < 4 && i8Os ); i++ )
	{
		strProcPrihFromVag[i].Format("insert into #KodReslt\n\
      exec pTov_TLPrihFromVag @ILK, %d, @IZapTL%d, %s, %s, %s, %d, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
			g_iDep,
			i + 1,
			m_p[1][i*3].GetAsString(),
			cText,
			isNull(m_EdFamMast.GetData()),
			!m_c[i*3 + 1].GetCurSel(),
			
			m_p[4][i * 3].GetAsString(),
			isNull(m_p[5][i * 3].GetData()),
			m_p[6][i * 3].GetAsString(),
			m_p[7][i * 3].GetAsString(),
			m_p[8][i * 3].GetAsString(),
	//		m_c2[0].GetCurSel(),
			"NULL",
					
			m_p[4][i * 3 + 1].GetAsString(),
			isNull(m_p[5][i * 3 + 1].GetData()),
			m_p[6][i * 3 + 1].GetAsString(),
			m_p[7][i * 3 + 1].GetAsString(),
			m_p[8][i * 3 + 1].GetAsString(),
	//		m_c2[1].GetCurSel(),
			"NULL",

			m_p[4][i * 3 + 2].GetAsString(),
			isNull(m_p[5][i * 3 + 2].GetData()),
			m_p[6][i * 3 + 2].GetAsString(),
			m_p[7][i * 3 + 2].GetAsString(),
			m_p[8][i * 3 + 2].GetAsString(),
	//		m_c2[2].GetCurSel());
			"NULL");
	}
	sprintf(cScript, "set nocount on\n\
begin tran\n\
  create table #reslt ( ILK bigint, IZapTL1 bigint, IZapTL2 bigint, IZapTL3 bigint, IZapTL4 bigint)\n\
  create table #KodReslt ( Kod int, StringRez varchar(2000))\n\
  declare @ILK bigint,\n\
        @IZapTL1 bigint, @IZapTL2 bigint, @IZapTL3 bigint, @IZapTL4 bigint\n\
  insert into #reslt\n\
	execute %s\n\
  select @ILK = ILK,\n\
	@IZapTL1=IZapTL1, @IZapTL2=IZapTL2, @IZapTL3=IZapTL3, @IZapTL4=IZapTL4\n\
	from #reslt\n\
  if( @ILK > 0 )\n\
  begin\n\
	-- print '@ILK='+ isnull(Str (@ILK, 7), 'null')\n\
	%s\n\
	%s\n\
	%s\n\
	%s\n\
	if exists (select Kod from #KodReslt where Kod<0)\n\
        begin\n\
          select -1, StringRez from #KodReslt where Kod<0\n\
          drop table #reslt\n\
          drop table #KodReslt\n\
          rollback\n\
          return\n\
        end\n\
  end\n drop table #reslt\ndrop table #KodReslt\n\
  COMMIT TRAN\nselect 0",

	cProcGetILK,
	strProcPrihFromVag[0],
	strProcPrihFromVag[1],
	strProcPrihFromVag[2],
	strProcPrihFromVag[3]
	);

	long Ind = 0;
	DWORD dwNum = 0;
//	DBW.WriteLog(cScript);
	DBW.ExecSQL(cScript);
	DBW.Fetch();
	DBW.GetData( 1, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != 0 )
	{
		if( dwNum == -1 )
		{
			DBW.GetData( 1, SQL_C_CHAR, &cText, 220, &Ind );
			AfxMessageBox(cText);
			DBW.CloseCursor();
			return -1;
		}
	}
	DBW.CloseCursor();
	DBW.ReallocHandle();
	return 0;
}

void CDlgPrihodTL2::OnBnClickedOk()
{
	if( SaveData() == 0 )
		OnOK();
}

BOOL CDlgPrihodTL2::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_p[1][0].QInit(10,1);
	m_p[1][3].QInit(10,1);
	m_p[1][6].QInit(10,1);
	m_p[1][9].QInit(10,1);

	m_p[2][0].SetWindowText("Надр. балка");
	m_p[2][1].SetWindowText("Бок. рама");
	m_p[2][2].SetWindowText("Бок. рама");

	m_p[2][3].SetWindowText("Надр. балка");
	m_p[2][4].SetWindowText("Бок. рама");
	m_p[2][5].SetWindowText("Бок. рама");

	m_p[2][6].SetWindowText("Надр. балка");
	m_p[2][7].SetWindowText("Бок. рама");
	m_p[2][8].SetWindowText("Бок. рама");

	m_p[2][9].SetWindowText("Надр. балка");
	m_p[2][10].SetWindowText("Бок. рама");
	m_p[2][11].SetWindowText("Бок. рама");

	m_p[2][0].ModifyStyle(0, WS_DISABLED);
	m_p[2][1].ModifyStyle(0, WS_DISABLED);
	m_p[2][2].ModifyStyle(0, WS_DISABLED);
	m_p[2][3].ModifyStyle(0, WS_DISABLED);
	m_p[2][4].ModifyStyle(0, WS_DISABLED);
	m_p[2][5].ModifyStyle(0, WS_DISABLED);
	m_p[2][6].ModifyStyle(0, WS_DISABLED);
	m_p[2][7].ModifyStyle(0, WS_DISABLED);
	m_p[2][8].ModifyStyle(0, WS_DISABLED);
	m_p[2][9].ModifyStyle(0, WS_DISABLED);
	m_p[2][10].ModifyStyle(0, WS_DISABLED);
	m_p[2][11].ModifyStyle(0, WS_DISABLED);

	for( int i=0; i < 12; i++ )
	{
		m_p[4][i].QInit(20,1);
		m_p[5][i].QInit(40,1);
		m_p[6][i].QInit(100,1);
		m_p[7][i].QInit(40,1);
		m_p[8][i].QInit(40,1);
	}
	for( int i = 1; i < 12; i++ )
	{
		if( i == 3 ||  i == 6 ||  i == 9) continue;
		m_c[i].AddString("Лев.");
		m_c[i].AddString("Прав.");
		m_c[i].SetItemData(0, 0);
		m_c[i].SetItemData(1, 1);
	}

	m_c[1].SetCurSel(1);
	m_c[2].SetCurSel(0);
	m_c[4].SetCurSel(1);
	m_c[5].SetCurSel(0);
	m_c[7].SetCurSel(1);
	m_c[8].SetCurSel(0);
	m_c[10].SetCurSel(1);
	m_c[11].SetCurSel(0);

	m_p[1][0].SetWindowText("1");
	m_p[1][3].SetWindowText("2");
	m_p[1][6].SetWindowText("3");
	m_p[1][9].SetWindowText("4");


	FillForm();
	m_EdNVag.SetMode(0,1);
/*	m_EdDatPost.SetMode(0,1);
	m_EdDatVyhRem.SetMode(0,1);
	m_EdDatVykatki.SetMode(0,1);*/
	m_EdFamMast.SetMode(5,1);
	DBW.FillEmplArray(m_EdFamMast.lpEmpl, 16);
	return TRUE;
}

void CDlgPrihodTL2::FillForm(void)
{
	char cQ[512] = "";
	char cText[64] = "";
	SYSTEMTIME st;
	long Ind = 0;
	DWORD dwNum = 0;
	sprintf( cQ, "pTov_TLGetVagPrihod %s", isNull(qwILK));
	DBW.ExecSQL(cQ);
	g_sqlret = DBW.Fetch();
	if( g_sqlret != SQL_NO_DATA && g_sqlret != SQL_ERROR )
	{
		DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 )
		{
			m_EdNVag.SetWindowText(cText);
		}

		DBW.GetData(2, SQL_C_ULONG, &dwVRem, 64, &Ind );
		DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 )
		{
			m_EdVidRem.SetWindowText(cText);
		}

		mgSQLGetSysDate(4, &st, &Ind);
		if( Ind != -1 )
		{
			m_EdDatPost.SetTime(&st);
			stDatPostVRem = st;
			stDatPostVRem.wMilliseconds = 33;
		}
		mgSQLGetSysDate(5, &stDatVyhIzRem, &Ind);
		if( Ind != -1 )
		{
			m_EdDatVyhRem.SetTime(&stDatVyhIzRem);
			
		}
		mgSQLGetSysDate(6, &st, &Ind);
		if( Ind != -1 )
		{
			m_EdDatVykatki.SetTime(&st);
		}
		DBW.GetData(7, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 )
		{
			m_EdFamMast.SetData(dwNum);
			DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 )
			{
				m_EdFamMast.SetWindowText(cText);				
			}
		}
		DBW.GetData(9, SQL_C_ULONG, &i8Os, 4, &Ind );
		DBW.GetData(10, SQL_C_UBIGINT, &qwIDS, 8, &Ind );
		if( Ind == -1 ) qwIDS = 0;		
	}
	DBW.CloseCursor();
	if( !qwIDS )
	{
		m_bnFrom2730.EnableWindow(FALSE);
	}
	
	sprintf( cQ, "pTov_TLgetVagPrihodInf %I64u", qwILK );
	DBW.ExecSQL( cQ );
	for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && ((i < 4 && i8Os) || i < 2); i++ )
	{
		// порядковый номер
		DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[1][i*3].SetWindowText(cText);

		//Надр. балка
		// код собственника
		DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[4][ i*3 ].SetWindowText(cText);
		// предприятие 
		DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_p[5][ i*3 ].SetData( dwNum);
		DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[5][ i*3 ].SetWindowText(cText);
		// номер детали
		DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[6][ i*3 ].SetWindowText(cText);
		// дата изготовления
		DBW.GetData(6, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[7][ i*3 ].SetWindowText(cText);
		// Код дефекта
		DBW.GetData(7, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[8][ i*3 ].SetWindowText(cText);
		// вид ремонта
		DBW.GetData(8, SQL_C_CHAR, cText, 64, &Ind );

		//бок. рама (прав)
		// код собственника
		DBW.GetData(9, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[4][ i*3+1 ].SetWindowText(cText);
		// предприятие 
		DBW.GetData(10, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_p[5][ i*3+1 ].SetData( dwNum);
		DBW.GetData(11, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[5][ i*3+1 ].SetWindowText(cText);
		// номер детали
		DBW.GetData(12, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[6][ i*3+1 ].SetWindowText(cText);
		// дата изготовления
		DBW.GetData(13, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[7][ i*3+1 ].SetWindowText(cText);
		// Код дефекта
		DBW.GetData(14, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[8][ i*3+1 ].SetWindowText(cText);
		// вид ремонта
		DBW.GetData(15, SQL_C_CHAR, cText, 64, &Ind );

		//бок. рама (лев)
		// код собственника
		DBW.GetData(16, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[4][ i*3+2 ].SetWindowText(cText);
		// предприятие 
		DBW.GetData(17, SQL_C_ULONG, &dwNum, 4, &Ind );
		if( Ind != -1 ) m_p[5][ i*3+2 ].SetData( dwNum);
		DBW.GetData(18, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[5][ i*3+2 ].SetWindowText(cText);
		// номер детали
		DBW.GetData(19, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[6][ i*3+2 ].SetWindowText(cText);
		// дата изготовления
		DBW.GetData(20, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[7][ i*3+2 ].SetWindowText(cText);
		// Код дефекта
		DBW.GetData(21, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[8][ i*3+2 ].SetWindowText(cText);
		// вид ремонта
		DBW.GetData(22, SQL_C_CHAR, cText, 64, &Ind );
	}
	DBW.CloseCursor();

	if( !i8Os )
	{
		m_p[1][6].EnableWindow(FALSE);
		m_p[1][9].EnableWindow(FALSE);
		for( int i=6; i < 12; i++ )
		{
			m_p[2][i].EnableWindow(FALSE);
			m_p[4][i].EnableWindow(FALSE);
			m_p[5][i].EnableWindow(FALSE);
			m_p[6][i].EnableWindow(FALSE);
			m_p[7][i].EnableWindow(FALSE);
			m_p[8][i].EnableWindow(FALSE);
			m_c[i].EnableWindow(FALSE);
		}
		WINDOWPLACEMENT pm;
		this->GetWindowPlacement(&pm);
		pm.rcNormalPosition.bottom = pm.rcNormalPosition.bottom - 205;
		this->SetWindowPlacement(&pm);
		
		m_bnFrom2730.GetWindowPlacement(&pm);
		pm.rcNormalPosition.top -= 200;
		pm.rcNormalPosition.bottom -= 200;
		m_bnFrom2730.SetWindowPlacement(&pm);

		m_bnOK.GetWindowPlacement(&pm);
		pm.rcNormalPosition.top -= 200;
		pm.rcNormalPosition.bottom -= 200;
		m_bnOK.SetWindowPlacement(&pm);

		m_bnCancel.GetWindowPlacement(&pm);
		pm.rcNormalPosition.top -= 200;
		pm.rcNormalPosition.bottom -= 200;
		m_bnCancel.SetWindowPlacement(&pm);
		
		m_bnReport.GetWindowPlacement(&pm);
		pm.rcNormalPosition.top -= 200;
		pm.rcNormalPosition.bottom -= 200;
		m_bnReport.SetWindowPlacement(&pm);

		m_bnSendToAsld.GetWindowPlacement(&pm);
		pm.rcNormalPosition.top -= 200;
		pm.rcNormalPosition.bottom -= 200;
		m_bnSendToAsld.SetWindowPlacement(&pm);
		
	}
}

void CDlgPrihodTL2::OnCbnSelchangeCombo1()
{
	m_c[2].SetCurSel(!m_c[1].GetCurSel());
}

void CDlgPrihodTL2::OnCbnSelchangeCombo2()
{
	m_c[1].SetCurSel(!m_c[2].GetCurSel());
}

void CDlgPrihodTL2::OnCbnSelchangeCombo4()
{
	m_c[5].SetCurSel(!m_c[4].GetCurSel());
}

void CDlgPrihodTL2::OnCbnSelchangeCombo5()
{
	m_c[4].SetCurSel(!m_c[5].GetCurSel());
}

void CDlgPrihodTL2::OnCbnSelchangeCombo7()
{
	m_c[8].SetCurSel(!m_c[7].GetCurSel());
}

void CDlgPrihodTL2::OnCbnSelchangeCombo8()
{
	m_c[7].SetCurSel(!m_c[8].GetCurSel());
}

void CDlgPrihodTL2::OnCbnSelchangeCombo10()
{
	m_c[11].SetCurSel(!m_c[10].GetCurSel());
}

void CDlgPrihodTL2::OnCbnSelchangeCombo11()
{
	m_c[10].SetCurSel(!m_c[11].GetCurSel());
}

void CDlgPrihodTL2::OnBnClickedButtonFill2730()
{
	char cQ[512] = "";
	char cText[1024] = "";
	DWORD dwNum = 0;
	long Ind = 0;

	DWORD dwRem = 0;
	m_EdVidRem.GetWindowText(cText, 64);
	dwRem = atoi(cText);
	
	sprintf(cQ, "pTov_S4624SelTL %s, 2, %s",
			isNull(qwIDS),
			isNull(qwILK));
	DBW.ExecSQL(cQ);

	int iRow = 0;
	int iCol = 1;
	for( int i=0; (g_sqlret = DBW.Fetch())!=SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 4; i++ )
	{
		iCol = 1;
		DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_p[1][i*3].SetWindowText(cText);
		iCol++;

		for( int j=4; j < 8; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_p[j][i*3].SetWindowText(cText);
			iCol++;
		}
		iCol+=7;
		for( int j=4; j < 8; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_p[j][i*3+1].SetWindowText(cText);
			iCol++;
		}
		iCol+=6;
		for( int j=4; j < 8; j++ )
		{
			DBW.GetData(iCol, SQL_C_CHAR, cText, 64, &Ind );
			if( Ind != -1 ) m_p[j][i*3+2].SetWindowText(cText);
			iCol++;
		}
	}
	DBW.CloseCursor();	
}



void CDlgPrihodTL2::OnBnClickedButton25()
{
	SetPr(0);
}

void CDlgPrihodTL2::OnBnClickedButton38()
{
	SetPr(1);
}

void CDlgPrihodTL2::OnBnClickedButton43()
{
	SetPr(2);
}

void CDlgPrihodTL2::OnBnClickedButton33()
{
	SetPr(3);
}

void CDlgPrihodTL2::OnBnClickedButton34()
{
	SetPr(4);
}

void CDlgPrihodTL2::OnBnClickedButton44()
{
	SetPr(5);
}

void CDlgPrihodTL2::OnBnClickedButton51()
{
	SetPr(6);
}

void CDlgPrihodTL2::OnBnClickedButton52()
{
	SetPr(7);
}

void CDlgPrihodTL2::OnBnClickedButton53()
{
	SetPr(8);
}

void CDlgPrihodTL2::OnBnClickedButton54()
{
	SetPr(9);
}

void CDlgPrihodTL2::OnBnClickedButton55()
{
	SetPr(10);
}

void CDlgPrihodTL2::OnBnClickedButton56()
{
	SetPr(11);
}

void CDlgPrihodTL2::SetPr(int RowIndex)
{
	CDlgSprav1 Dlg;
	Dlg.iDlgKind = 6;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_p[5][RowIndex].SetWindowText(Dlg.cKodPr);
	m_p[5][RowIndex].SetData(Dlg.ret_dwIPR);
}

void CDlgPrihodTL2::SetAllIPR(void)
{
	char cText[64] = "";
	char cQ[128] = "";
	long Ind = 0;
	DWORD dwNum = 0;
	for( int i=0; (i < 6 && !i8Os) || (i < 12 ); i++ )
	{
		m_p[5][i].GetWindowText(cText, 64);
		if( cText[0] )
		{
			sprintf(cQ, "pTov_GetPredByKl '%s'", cText );
			DBW.ExecSQL(cQ);
			DBW.Fetch();
			DBW.GetData(2, SQL_C_ULONG, &dwNum, 4, &Ind );
			if( Ind != -1 )
			{
				m_p[5][i].SetData(dwNum);
			} else
				m_p[5][i].SetData(0);

			DBW.CloseCursor();
		}
	}
}

void CDlgPrihodTL2::OnBnClickedButton2()
{
	CDlgSpravKdr Dlg;
    Dlg.DlgMode = 1;
    Dlg.iFilter = 16;
    if( Dlg.DoModal() == IDCANCEL ) return;
	m_EdFamMast.SetData(Dlg.dwFio);
	m_EdFamMast.SetWindowText(Dlg.cFio);
	
}

void CDlgPrihodTL2::OnEnKillfocusE10()
{
//	AfxMessageBox("DDD");
}

void CDlgPrihodTL2::OnBnClickedButtonReport()
{
	char cQ[256] = "";
	sprintf(cQ, "pTov_mkcRepHtmPrihTL %d, %s, %s, NULL",
		g_iDep,
		m_EdNVag.GetString(1),
		m_EdDatVykatki.GetSQLDate());
		DBW.DisplayHtmlReport(cQ);

}

extern CString g_strAsldTeleName;
extern int g_iEnableTelecom;

void CDlgPrihodTL2::OnBnClickedSendAsld()
{
	if( SaveData() ) return;

	if( g_iEnableTelecom && g_strAsldTeleName )
	{
		
		DWORD dwRet = 0;
		char cText[2255] = "";
			char cQ[128] = "";
			char msg[200] = "";
				sprintf( cQ, "pTov_TL_SendToASUV_NB %s", isNull(qwILK) );		
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
						
				sprintf(msg, "Отправка данных в АС ЛД (%s)", g_strAsldTeleName ) ;
				DBW.WriteLog((char *)msg);
				CString snd = (CString)"<tov><asld docid=\"1\">\n" + cText + (CString) "\n</asld></tov>";
				//DBW.SendMessageToDst( snd, "mkc", g_strAisldTeleName );
				if( tele ) 
				{
							tele->SendMessageDst(snd, &g_strAsldTeleName);	
							//AfxMessageBox("Данные отправлены в АСЛД!");
							m_bnSendToAsld.EnableWindow(0);
				}

				sprintf( cQ, "pTov_TL_SendToASUV_BR %s", isNull(qwILK) );		
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
				
				sprintf(msg, "Отправка данных в АС ЛД (%s)", g_strAsldTeleName ) ;
				DBW.WriteLog((char *)msg);
				snd = (CString)"<tov><asld docid=\"1\">\n" + cText + (CString) "\n</asld></tov>";
				//DBW.SendMessageToDst( snd, "mkc", g_strAisldTeleName );
				if( tele ) 
				{
							tele->SendMessageDst(snd, &g_strAsldTeleName);	
							AfxMessageBox("Данные отправлены в АСЛД!");
							m_bnSendToAsld.EnableWindow(0);
				}
	} else
	{
		AfxMessageBox("Невозможно отправить в АСЛД из-за некорректных настроек телеобработки!");
	}
}
