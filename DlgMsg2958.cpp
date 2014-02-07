// DlgMsg2958.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMsg2958.h"
#include ".\dlgmsg2958.h"
#include "PrintableDlg.h"

extern int g_iMessageNumber;
extern CMasterApp theApp;
extern COLORREF p_crColors[6];
// CDlgMsg2958 dialog

IMPLEMENT_DYNAMIC(CDlgMsg2958, CDlgWithAccelerators)
CDlgMsg2958::CDlgMsg2958(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgMsg2958::IDD, pParent)
{
}

CDlgMsg2958::~CDlgMsg2958()
{
	m_iShowKP = 0;
	ZeroMemory(&stDat, sizeof(stDat));
}

void CDlgMsg2958::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LAB1, m_Lab1);

	DDX_Control(pDX, IDC_ED00, m_Ed[0][0]);
	DDX_Control(pDX, IDC_ED10, m_Ed[1][0]);
	DDX_Control(pDX, IDC_ED20, m_Ed[2][0]);
	DDX_Control(pDX, IDC_ED30, m_Ed[3][0]);
	DDX_Control(pDX, IDC_ED40, m_Ed[4][0]);
	DDX_Control(pDX, IDC_ED50, m_Ed[5][0]);
	DDX_Control(pDX, IDC_ED60, m_Ed[6][0]);
	DDX_Control(pDX, IDC_ED70, m_Ed[7][0]);
	DDX_Control(pDX, IDC_ED80, m_Ed[8][0]);
	DDX_Control(pDX, IDC_ED90, m_Ed[9][0]);
	DDX_Control(pDX, IDC_ED10_0, m_Ed[10][0]);
	DDX_Control(pDX, IDC_ED11_0, m_Ed[11][0]);
	DDX_Control(pDX, IDC_ED12_0, m_Ed[12][0]);
	DDX_Control(pDX, IDC_ED13_0, m_Ed[13][0]);
	DDX_Control(pDX, IDC_ED14_0, m_Ed[14][0]);
	DDX_Control(pDX, IDC_ED15_0, m_Ed[15][0]);
	DDX_Control(pDX, IDC_ED16_0, m_Ed[16][0]);
	DDX_Control(pDX, IDC_ED17_0, m_Ed[17][0]);
	DDX_Control(pDX, IDC_BUTTON1, bnSost);

	DDX_Control(pDX, IDC_ED01, m_Ed1[0][1]);
	DDX_Control(pDX, IDC_ED11, m_Ed1[1][1]);
	DDX_Control(pDX, IDC_ED21, m_Ed1[2][1]);
	DDX_Control(pDX, IDC_ED31, m_Ed1[3][1]);
	DDX_Control(pDX, IDC_ED41, m_Ed1[4][1]);
	DDX_Control(pDX, IDC_ED51, m_Ed1[5][1]);
	DDX_Control(pDX, IDC_ED61, m_Ed1[6][1]);
	DDX_Control(pDX, IDC_ED71, m_Ed1[7][1]);
	DDX_Control(pDX, IDC_ED81, m_Ed1[8][1]);
	DDX_Control(pDX, IDC_ED91, m_Ed1[9][1]);
	DDX_Control(pDX, IDC_ED10_1, m_Ed1[10][1]);
	DDX_Control(pDX, IDC_ED11_1, m_Ed1[11][1]);
	DDX_Control(pDX, IDC_ED12_1, m_Ed1[12][1]);
	DDX_Control(pDX, IDC_ED13_1, m_Ed1[13][1]);
	DDX_Control(pDX, IDC_ED14_1, m_Ed1[14][1]);
	DDX_Control(pDX, IDC_ED15_1, m_Ed1[15][1]);
	DDX_Control(pDX, IDC_ED16_1, m_Ed1[16][1]);
	DDX_Control(pDX, IDC_ED17_1, m_Ed1[17][1]);

	DDX_Control(pDX, IDC_ED02, m_Ed[0][2]);
	DDX_Control(pDX, IDC_ED12, m_Ed[1][2]);
	DDX_Control(pDX, IDC_ED22, m_Ed[2][2]);
	DDX_Control(pDX, IDC_ED32, m_Ed[3][2]);
	DDX_Control(pDX, IDC_ED42, m_Ed[4][2]);
	DDX_Control(pDX, IDC_ED52, m_Ed[5][2]);
	DDX_Control(pDX, IDC_ED62, m_Ed[6][2]);
	DDX_Control(pDX, IDC_ED72, m_Ed[7][2]);
	DDX_Control(pDX, IDC_ED82, m_Ed[8][2]);
	DDX_Control(pDX, IDC_ED92, m_Ed[9][2]);
	DDX_Control(pDX, IDC_ED10_2, m_Ed[10][2]);
	DDX_Control(pDX, IDC_ED11_2, m_Ed[11][2]);
	DDX_Control(pDX, IDC_ED12_2, m_Ed[12][2]);
	DDX_Control(pDX, IDC_ED13_2, m_Ed[13][2]);
	DDX_Control(pDX, IDC_ED14_2, m_Ed[14][2]);
	DDX_Control(pDX, IDC_ED15_2, m_Ed[15][2]);
	DDX_Control(pDX, IDC_ED16_2, m_Ed[16][2]);
	DDX_Control(pDX, IDC_ED17_2, m_Ed[17][2]);

	DDX_Control(pDX, IDC_ED03, m_Ed1[0][3]);
	DDX_Control(pDX, IDC_ED13, m_Ed1[1][3]);
	DDX_Control(pDX, IDC_ED25, m_Ed1[2][3]);
	DDX_Control(pDX, IDC_ED33, m_Ed1[3][3]);
	DDX_Control(pDX, IDC_ED43, m_Ed1[4][3]);
	DDX_Control(pDX, IDC_ED53, m_Ed1[5][3]);
	DDX_Control(pDX, IDC_ED63, m_Ed1[6][3]);
	DDX_Control(pDX, IDC_ED73, m_Ed1[7][3]);
	DDX_Control(pDX, IDC_ED83, m_Ed1[8][3]);
	DDX_Control(pDX, IDC_ED93, m_Ed1[9][3]);
	DDX_Control(pDX, IDC_ED10_3, m_Ed1[10][3]);
	DDX_Control(pDX, IDC_ED11_3, m_Ed1[11][3]);
	DDX_Control(pDX, IDC_ED12_3, m_Ed1[12][3]);
	DDX_Control(pDX, IDC_ED13_3, m_Ed1[13][3]);
	DDX_Control(pDX, IDC_ED14_3, m_Ed1[14][3]);
	DDX_Control(pDX, IDC_ED15_3, m_Ed1[15][3]);
	DDX_Control(pDX, IDC_ED16_3, m_Ed1[16][3]);
	DDX_Control(pDX, IDC_ED17_3, m_Ed1[17][3]);

	DDX_Control(pDX, IDC_ED04, m_Ed[0][4]);
	DDX_Control(pDX, IDC_ED24, m_Ed[1][4]);
	DDX_Control(pDX, IDC_ED26, m_Ed[2][4]);
	DDX_Control(pDX, IDC_ED34, m_Ed[3][4]);
	DDX_Control(pDX, IDC_ED44, m_Ed[4][4]);
	DDX_Control(pDX, IDC_ED54, m_Ed[5][4]);
	DDX_Control(pDX, IDC_ED64, m_Ed[6][4]);
	DDX_Control(pDX, IDC_ED74, m_Ed[7][4]);
	DDX_Control(pDX, IDC_ED84, m_Ed[8][4]);
	DDX_Control(pDX, IDC_ED94, m_Ed[9][4]);
	DDX_Control(pDX, IDC_ED10_4, m_Ed[10][4]);
	DDX_Control(pDX, IDC_ED11_4, m_Ed[11][4]);
	DDX_Control(pDX, IDC_ED12_4, m_Ed[12][4]);
	DDX_Control(pDX, IDC_ED13_4, m_Ed[13][4]);
	DDX_Control(pDX, IDC_ED14_4, m_Ed[14][4]);
	DDX_Control(pDX, IDC_ED15_4, m_Ed[15][4]);
	DDX_Control(pDX, IDC_ED16_4, m_Ed[16][4]);
	DDX_Control(pDX, IDC_ED17_4, m_Ed[17][4]);

	DDX_Control(pDX, IDC_ED05, m_Ed1[0][5]);
	DDX_Control(pDX, IDC_ED28, m_Ed1[1][5]);
	DDX_Control(pDX, IDC_ED29, m_Ed1[2][5]);
	DDX_Control(pDX, IDC_ED35, m_Ed1[3][5]);
	DDX_Control(pDX, IDC_ED45, m_Ed1[4][5]);
	DDX_Control(pDX, IDC_ED55, m_Ed1[5][5]);
	DDX_Control(pDX, IDC_ED65, m_Ed1[6][5]);
	DDX_Control(pDX, IDC_ED75, m_Ed1[7][5]);
	DDX_Control(pDX, IDC_ED85, m_Ed1[8][5]);
	DDX_Control(pDX, IDC_ED95, m_Ed1[9][5]);
	DDX_Control(pDX, IDC_ED10_5, m_Ed1[10][5]);
	DDX_Control(pDX, IDC_ED11_5, m_Ed1[11][5]);
	DDX_Control(pDX, IDC_ED12_5, m_Ed1[12][5]);
	DDX_Control(pDX, IDC_ED13_5, m_Ed1[13][5]);
	DDX_Control(pDX, IDC_ED14_5, m_Ed1[14][5]);
	DDX_Control(pDX, IDC_ED15_5, m_Ed1[15][5]);
	DDX_Control(pDX, IDC_ED16_5, m_Ed1[16][5]);
	DDX_Control(pDX, IDC_ED17_5, m_Ed1[17][5]);


	DDX_Control(pDX, IDC_ED06, m_Ed[0][6]);
	DDX_Control(pDX, IDC_ED36, m_Ed[1][6]);
	DDX_Control(pDX, IDC_ED37, m_Ed[2][6]);
	DDX_Control(pDX, IDC_ED38, m_Ed[3][6]);
	DDX_Control(pDX, IDC_ED46, m_Ed[4][6]);
	DDX_Control(pDX, IDC_ED56, m_Ed[5][6]);
	DDX_Control(pDX, IDC_ED66, m_Ed[6][6]);
	DDX_Control(pDX, IDC_ED76, m_Ed[7][6]);
	DDX_Control(pDX, IDC_ED86, m_Ed[8][6]);
	DDX_Control(pDX, IDC_ED96, m_Ed[9][6]);
	DDX_Control(pDX, IDC_ED10_6, m_Ed[10][6]);
	DDX_Control(pDX, IDC_ED11_6, m_Ed[11][6]);
	DDX_Control(pDX, IDC_ED12_6, m_Ed[12][6]);
	DDX_Control(pDX, IDC_ED13_6, m_Ed[13][6]);
	DDX_Control(pDX, IDC_ED14_6, m_Ed[14][6]);
	DDX_Control(pDX, IDC_ED15_6, m_Ed[15][6]);
	DDX_Control(pDX, IDC_ED16_6, m_Ed[16][6]);
	DDX_Control(pDX, IDC_ED17_6, m_Ed[17][6]);

	DDX_Control(pDX, IDC_ED07, m_Ed1[0][7]);
	DDX_Control(pDX, IDC_ED47, m_Ed1[1][7]);
	DDX_Control(pDX, IDC_ED48, m_Ed1[2][7]);
	DDX_Control(pDX, IDC_ED49, m_Ed1[3][7]);
	DDX_Control(pDX, IDC_ED57, m_Ed1[4][7]);
	DDX_Control(pDX, IDC_ED58, m_Ed1[5][7]);
	DDX_Control(pDX, IDC_ED67, m_Ed1[6][7]);
	DDX_Control(pDX, IDC_ED77, m_Ed1[7][7]);
	DDX_Control(pDX, IDC_ED87, m_Ed1[8][7]);
	DDX_Control(pDX, IDC_ED97, m_Ed1[9][7]);
	DDX_Control(pDX, IDC_ED10_7, m_Ed1[10][7]);
	DDX_Control(pDX, IDC_ED11_7, m_Ed1[11][7]);
	DDX_Control(pDX, IDC_ED12_7, m_Ed1[12][7]);
	DDX_Control(pDX, IDC_ED13_7, m_Ed1[13][7]);
	DDX_Control(pDX, IDC_ED14_7, m_Ed1[14][7]);
	DDX_Control(pDX, IDC_ED15_7, m_Ed1[15][7]);
	DDX_Control(pDX, IDC_ED16_7, m_Ed1[16][7]);
	DDX_Control(pDX, IDC_ED17_7, m_Ed1[17][7]);

	DDX_Control(pDX, IDC_EDIT2, m_EdPr);
	DDX_Control(pDX, IDC_EDIT7, m_Dat);
}


BEGIN_MESSAGE_MAP(CDlgMsg2958, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_EN_CHANGE(IDC_ED10, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED20, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED30, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED40, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED50, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED60, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED70, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED80, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED90, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED10_0, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED11_0, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED12_0, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED13_0, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED14_0, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED15_0, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED16_0, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED17_0, OnEnChangeEd10)

	ON_EN_CHANGE(IDC_ED12, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED22, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED32, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED42, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED52, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED62, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED72, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED82, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED92, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED10_2, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED11_2, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED12_2, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED13_2, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED14_2, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED15_2, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED16_2, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED17_2, OnEnChangeEd10)

	ON_EN_CHANGE(IDC_ED14, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED24, OnEnChangeEd10)		
	ON_EN_CHANGE(IDC_ED34, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED44, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED54, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED64, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED74, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED84, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED94, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED10_4, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED11_4, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED12_4, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED13_4, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED14_4, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED15_4, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED16_4, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED17_4, OnEnChangeEd10)
	ON_EN_CHANGE(IDC_ED26, OnEnChangeEd10)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON39, OnBnClickedButton_Report)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
END_MESSAGE_MAP()


// CDlgMsg2958 message handlers

BOOL CDlgMsg2958::OnInitDialog()
{
	CDlgWithAccelerators::OnInitDialog();

	m_EdPr.QInit(40, 1);
	m_Dat.SetMode(3, 1);
	m_Dat.SetTime(&stDat);
	m_Dat.ModifyStyle(0, WS_DISABLED, 0);
	for( int i=0; i < 8; i++ )
	{
		m_Ed[0][i].SetMode(0, 1, 10);
		m_Ed[2][i].QInit(60, 1);
		m_Ed[4][i].QInit(60, 1);
		m_Ed[5][i].QInit(60, 1);

		m_Ed[1][i].QInit(50, 1);
		m_Ed[3][i].QInit(50, 1);
		m_Ed[6][i].QInit(50, 1);
		for(int x=8; x < 18; x++ )
		{
			m_Ed[x][i].QInit(50, 1);
		}
		m_Ed[7][i].QInit(40, 1);
	}
	m_Ed[0][0].SetWindowText("01-Деп");
	m_Ed[0][2].SetWindowText("02-Кап");
	m_Ed[0][4].SetWindowText("03-ТР");
	m_Ed[0][6].SetWindowText("04-Всего");
	
	m_Ed[0][0].ModifyStyle(0, WS_DISABLED, 0);
	m_Ed[0][2].ModifyStyle(0, WS_DISABLED, 0);
	m_Ed[0][4].ModifyStyle(0, WS_DISABLED, 0);
	m_Ed[0][6].ModifyStyle(0, WS_DISABLED, 0);
	
	for( int i=1; i < 18; i++ )
		m_Ed[i][6].ModifyStyle(0, WS_DISABLED, 0);

	FillForm();
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMsg2958::OnBnClickedOk()
{
	if( StoreToBase() == -1 ) return;
	OnOK();
}

void CDlgMsg2958::FillForm(void)
{
	char cQ[512] = "";
	char cText[64] = "";
	long Ind = 0;

	sprintf(cQ, "pTov_S2950Sel %d, %s, %d", g_iDep, m_Dat.GetSQLDate(), m_iShowKP);

	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SBIGINT, &qwIDS, 8, &Ind);
	if( Ind == -1 ) qwIDS = 0;
	DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 ) m_EdPr.SetWindowText(cText);
	SYSTEMTIME tm;
	mgSQLGetSysDate(3, &tm, &Ind );
	if( Ind != -1 ) m_Dat.SetTime(&tm);
	int nField = 4;
	/*первая строчка*/
	for( int i=0; i < 17; i++ )
	{
		DBW.GetData(nField, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_Ed[i + 1][0].SetWindowText(cText);
		nField++;
	}
	/*третья строчка*/
	for( int i=0; i < 17; i++ )
	{
		DBW.GetData(nField, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_Ed[i + 1][2].SetWindowText(cText);
		nField++;
	}
	/*пятая строчка*/
	for( int i=0; i < 17; i++ )
	{
		DBW.GetData(nField, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_Ed[i + 1][4].SetWindowText(cText);
		nField++;
	}
	/*теперь серые */

	for( int i=0; i < 17; i++ )
	{
		DBW.GetData(nField, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_Ed1[i + 1][1].SetWindowText(cText);
		nField++;
	}
	/*четвертая строчка*/
	for( int i=0; i < 17; i++ )
	{
		DBW.GetData(nField, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_Ed1[i + 1][3].SetWindowText(cText);
		nField++;
	}
	/*шестая строчка*/
	for( int i=0; i < 17; i++ )
	{
		DBW.GetData(nField, SQL_C_CHAR, cText, 64, &Ind);
		if( Ind != -1 ) m_Ed1[i + 1][5].SetWindowText(cText);
		nField++;
	}
	DBW.GetData(nField, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 ) bnSost.SetWindowText(cText);
	nField++;
	DBW.GetData(nField, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 ) 
	{
		SetWindowText(CString("[") + CString(cText) + CString("] Сведения о количестве и причинах обточек КП за месяц"));
	}
	nField++;
	DWORD dwNum = 0;
	DBW.GetData(nField, SQL_C_ULONG, &dwNum, 4, &Ind );
	if( Ind != -1 && dwNum)
	{
		bnSost.SetBkColor(p_crColors[dwNum]);
	}

	DBW.CloseCursor();

	/*посчитаем серые суммы */
	char s1[12] = "", s2[12] = "", s3[12] = ""; 
	unsigned long iSum = 0;
	if( m_iShowKP )
		for( int i=1; i < 18; i++ )
		{
			m_Ed1[i][1].GetWindowText(s1, 12);
			m_Ed1[i][3].GetWindowText(s2, 12);
			m_Ed1[i][5].GetWindowText(s3, 12);
			
			iSum = (unsigned long)atoi(s1) + (unsigned long)atoi(s2) + (unsigned long)atoi(s3);
			ultoa(iSum, s1, 10);
			m_Ed1[i][7].SetWindowText(s1);
		}
		
}

void CDlgMsg2958::OnEnChangeEd10()
{
//	AfxMessageBox("!");
	for( int i=1; i < 18; i++ )
	{
			m_Ed[i][6].SetValue(m_Ed[i][0].GetAsDWord() +
			m_Ed[i][2].GetAsDWord() +
			m_Ed[i][4].GetAsDWord());
			
	}

}

void CDlgMsg2958::OnBnClickedButton2() //send
{
	if( StoreToBase() == -1 ) return;
	char cQ[128] = "";
	char cText[4000] = "";
	long Ind = 0;
/*	if( WriteMessageToBase() == 0 )
	{*/
		sprintf(cQ, "pTov_S29xxSend %s", isNull(qwIDS));
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();

		sprintf(cQ, "pTov_S2950Form %I64u", qwIDS );
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cText, 4000, &Ind);
		DBW.CloseCursor();

		if( g_iMessageNumber )
		{	
			if( Ind != -1 )
			{
				DBW.SendMessageToTov(cText);
			}
		} else
			theApp.SendTeleMessage(cText, "S2950");
//	}
	OnOK();
}

int CDlgMsg2958::StoreToBase(void)
{
	CString strMess[] = {
		"Значение 'кол-во КП требующих обточки' для деповского ремонта указано неверно.\nПересчитать автоматически?",
		"Значение 'кол-во КП требующих обточки' для капитального ремонта указано неверно.\nПересчитать автоматически?"",", 
		"Значение 'кол-во КП требующих обточки' для текущего ремонта указано неверно.\nПересчитать автоматически?"",", 
		"КП отправлено в ВКМ или ВРЗ",
		"КП не требующих обточки",
		"КП требующих обточки",
		"Причины обточек - Выщербины",
		"Причины обточек - Ползуны/Всего",
		"Причины обточек - В т.ч. на 1 колесе",
		"Причины обточек - Навары",
		"Причины обточек - Кольцевые выработки",
		"Причины обточек - Тонкий гребень/Без наплавки",
		"Причины обточек - Тонкий гребень/С наплавкой",
		"Причины обточек - Подрез гребня",
		"Причины обточек - Остроконечный накат гребня",
		"Причины обточек - Прокат",
		"Причины обточек - Неравномерный прокат",
		"Причины обточек - Прочие"};
	char cMess[512] = "";

	for( int i=0; i < 6; i+=2 )
	{
		if( m_Ed[5][i].GetAsDWord() !=
			m_Ed[6][i].GetAsDWord() +
			m_Ed[7][i].GetAsDWord() +
			m_Ed[9][i].GetAsDWord() + 
			m_Ed[10][i].GetAsDWord() + 
			m_Ed[11][i].GetAsDWord() +
			m_Ed[12][i].GetAsDWord() +
			m_Ed[13][i].GetAsDWord() +
			m_Ed[14][i].GetAsDWord() +
			m_Ed[15][i].GetAsDWord() +
			m_Ed[16][i].GetAsDWord() +
			m_Ed[17][i].GetAsDWord()
			)
		{
			if( AfxMessageBox(strMess[i/2], MB_YESNO ) == IDNO )
			{
				m_Ed[5][i].SetFocus();
				return -1;
			}
			m_Ed[5][i].SetValue(m_Ed[6][i].GetAsDWord() +
								m_Ed[7][i].GetAsDWord() +
								m_Ed[9][i].GetAsDWord() +
								m_Ed[10][i].GetAsDWord() +
								m_Ed[11][i].GetAsDWord() +
								m_Ed[12][i].GetAsDWord() +
								m_Ed[13][i].GetAsDWord() +
								m_Ed[14][i].GetAsDWord() +
								m_Ed[15][i].GetAsDWord() +
								m_Ed[16][i].GetAsDWord() +
								m_Ed[17][i].GetAsDWord());
		}
	}


	if( m_Ed[2][0].GetAsDWord() !=
		m_Ed[3][0].GetAsDWord() +
		m_Ed[4][0].GetAsDWord() +
		m_Ed[5][0].GetAsDWord() )
	{
		if( AfxMessageBox("Значение 'всего КП поступило в ремонт' для деповского ремонта указано неверно.\nПересчитать автоматически?", MB_YESNO ) == IDNO )
		{
			m_Ed[2][0].SetFocus();
			return -1;
		}
		m_Ed[2][0].SetValue(m_Ed[3][0].GetAsDWord() +
							m_Ed[4][0].GetAsDWord() +
							m_Ed[5][0].GetAsDWord());
	}

	if( m_Ed[2][2].GetAsDWord() !=
		m_Ed[3][2].GetAsDWord() +
		m_Ed[4][2].GetAsDWord() +
		m_Ed[5][2].GetAsDWord() )
	{
		if( AfxMessageBox("Значение 'всего КП поступило в ремонт' для капитального ремонта указано неверно.\nПересчитать автоматически?", MB_YESNO ) == IDNO )
		{
			m_Ed[2][2].SetFocus();
			return -1;
		}
		m_Ed[2][2].SetValue(m_Ed[3][2].GetAsDWord() + 
							  m_Ed[4][2].GetAsDWord() +
							  m_Ed[5][2].GetAsDWord());
	}

	if( m_Ed[2][4].GetAsDWord() !=
		m_Ed[3][4].GetAsDWord() +
		m_Ed[4][4].GetAsDWord() +
		m_Ed[5][4].GetAsDWord() )
	{
		if( AfxMessageBox("Значение 'всего КП поступило в ремонт' для текущего ремонта указано неверно.\nПересчитать автоматически?", MB_YESNO ) == IDNO )
		{
			m_Ed[2][4].SetFocus();
			return -1;
		}
		m_Ed[2][4].SetValue(m_Ed[3][4].GetAsDWord() +
							m_Ed[4][4].GetAsDWord() +
							m_Ed[5][4].GetAsDWord());
	}

	char cQ[1024] = "";
	sprintf(cQ, "pTov_S2950Ins %s, %d, '%s', %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, \
%s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, \
%d",
	isNull(qwIDS),
	g_iDep,
	m_EdPr.GetString(),
	m_Dat.GetSQLDate(),
	m_Ed[1][0].GetString(1),
	m_Ed[2][0].GetString(1),
	m_Ed[3][0].GetString(1),
	m_Ed[4][0].GetString(1),
	m_Ed[5][0].GetString(1),
	m_Ed[6][0].GetString(1),
	m_Ed[7][0].GetString(1),
	m_Ed[8][0].GetString(1),
	m_Ed[9][0].GetString(1),
	m_Ed[10][0].GetString(1),
	m_Ed[11][0].GetString(1),
	m_Ed[12][0].GetString(1),
	m_Ed[13][0].GetString(1),
	m_Ed[14][0].GetString(1),
	m_Ed[15][0].GetString(1),
	m_Ed[16][0].GetString(1),
	m_Ed[17][0].GetString(1),

	m_Ed[1][2].GetString(1),
	m_Ed[2][2].GetString(1),
	m_Ed[3][2].GetString(1),
	m_Ed[4][2].GetString(1),
	m_Ed[5][2].GetString(1),
	m_Ed[6][2].GetString(1),
	m_Ed[7][2].GetString(1),
	m_Ed[8][2].GetString(1),
	m_Ed[9][2].GetString(1),
	m_Ed[10][2].GetString(1),
	m_Ed[11][2].GetString(1),
	m_Ed[12][2].GetString(1),
	m_Ed[13][2].GetString(1),
	m_Ed[14][2].GetString(1),
	m_Ed[15][2].GetString(1),
	m_Ed[16][2].GetString(1),
	m_Ed[17][2].GetString(1),

	m_Ed[1][4].GetString(1),
	m_Ed[2][4].GetString(1),
	m_Ed[3][4].GetString(1),
	m_Ed[4][4].GetString(1),
	m_Ed[5][4].GetString(1),
	m_Ed[6][4].GetString(1),
	m_Ed[7][4].GetString(1),
	m_Ed[8][4].GetString(1),
	m_Ed[9][4].GetString(1),
	m_Ed[10][4].GetString(1),
	m_Ed[11][4].GetString(1),
	m_Ed[12][4].GetString(1),
	m_Ed[13][4].GetString(1),
	m_Ed[14][4].GetString(1),
	m_Ed[15][4].GetString(1),
	m_Ed[16][4].GetString(1),
	m_Ed[17][4].GetString(1),

	m_Ed[1][6].GetString(1),
	m_Ed[2][6].GetString(1),
	m_Ed[3][6].GetString(1),
	m_Ed[4][6].GetString(1),
	m_Ed[5][6].GetString(1),
	m_Ed[6][6].GetString(1),
	m_Ed[7][6].GetString(1),
	m_Ed[8][6].GetString(1),
	m_Ed[9][6].GetString(1),
	m_Ed[10][6].GetString(1),
	m_Ed[11][6].GetString(1),
	m_Ed[12][6].GetString(1),
	m_Ed[13][6].GetString(1),
	m_Ed[14][6].GetString(1),
	m_Ed[15][6].GetString(1),
	m_Ed[16][6].GetString(1),
	m_Ed[17][6].GetString(1),
	g_iFam);

//	AfxMessageBox(cQ);
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();
	return 0;
}

void CDlgMsg2958::OnBnClickedButton1() //Состояние
{
	CPrintableDlg Dlg;
	sprintf(Dlg.cQ, "pTov_S29xxInf %s, 2950", isNull(qwIDS));
	Dlg.DoModal();
	
}

void CDlgMsg2958::OnBnClickedButton_Report()
{
	char cQ[128] = "";
	sprintf(cQ, "pTov_mkcRepHtmS2950 %d, %s, %d", 
		g_iDep,
		m_Dat.GetSQLDate(),
		m_iShowKP);
	DBW.DisplayHtmlReport(cQ);
}

void CDlgMsg2958::OnBnClickedCancel()
{
	OnCancel();
}
