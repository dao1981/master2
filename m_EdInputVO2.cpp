// m_EdInputVO2.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "m_EdInputVO2.h"
#include ".\m_edinputvo2.h"


// m_EdInputVO2 dialog

IMPLEMENT_DYNAMIC(m_EdInputVO2, CDialog)
m_EdInputVO2::m_EdInputVO2(CWnd* pParent /*=NULL*/)
	: CDialog(m_EdInputVO2::IDD, pParent)
{
}

m_EdInputVO2::~m_EdInputVO2()
{
}

void m_EdInputVO2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT2, m_Dat);
	DDX_Control(pDX, IDC_COMBO1, m_Cb);
	DDX_Control(pDX, IDC_CHECK1, m_Check);
}


BEGIN_MESSAGE_MAP(m_EdInputVO2, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// m_EdInputVO2 message handlers

BOOL m_EdInputVO2::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Dat.QInit(40, 1);
	m_Cb.AddString("Январь");
	m_Cb.AddString("Февраль");
	m_Cb.AddString("Март");
	m_Cb.AddString("Апрель");
	m_Cb.AddString("Май");
	m_Cb.AddString("Июнь");
	m_Cb.AddString("Июль");
	m_Cb.AddString("Август");
	m_Cb.AddString("Сентябрь");
	m_Cb.AddString("Октябрь");
	m_Cb.AddString("Ноябрь");
	m_Cb.AddString("Декабрь");

	for( int i=0; i < 12; i++ )
	{
		m_Cb.SetItemData(i, i + 1);
	}

	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(st));
	GetLocalTime(&st);
	
	if( st.wMonth == 0 )
	{
		st.wMonth = 12;
		st.wYear--;
	}
	char cdw[100] = "";
	itoa(st.wYear, cdw, 10);
	m_Dat.SetWindowText(cdw);
	m_Cb.SetCurSel(st.wMonth - 2);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void m_EdInputVO2::OnBnClickedOk()
{
	char cQ[256] = "";
	long Ind = 0;
	SYSTEMTIME st;
	ZeroMemory(&st, sizeof(st));
	GetLocalTime(&st);
	
	char cY[10] = "";
	m_Dat.GetWindowText(cY, 10);
	WORD wYear = atoi(cY);

	if( wYear < 1900 || st.wYear < wYear )
	{
		AfxMessageBox("Год указан некорректно!");
		m_Dat.SetFocus();
		return;
	}

	if( st.wYear == wYear && st.wMonth < m_Cb.GetCurSel() + 1)
	{
		AfxMessageBox("Месяц введен некорректно!");
		m_Cb.SetFocus();
		return;
	}


	if( m_Check.GetCheck() )
	{
		FILE *f = fopen("html\\tmp.html", "w");
		if( !f ) 
		{
			AfxMessageBox("Невозможно открыть файл для сохранения отчета");
			return;
		}
		char ccc[5120] = "";
		sprintf(cQ, "pTov_mkcRepHTMVO2 %d, '%.2d%.2d01'", g_iDep, wYear, m_Cb.GetItemData(m_Cb.GetCurSel()));
		DBW.ExecSQL(cQ);
		for( int i = 0; i < 256 && (g_sqlret = DBW.Fetch())!= SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
		{
			DBW.GetData(1, SQL_C_CHAR, ccc, 5120, &Ind);
			fprintf(f, "%s\n", ccc);
		}
		DBW.CloseCursor();
		fclose(f);
		ShellExecute(NULL, "open", "html\\tmp.html", NULL, NULL, SW_SHOWNORMAL);
		OnOK();
		return;

	}

	char rpt[60000] = "";
	char c = 0;
	FILE *f = fopen("html\\vo2_template.htm", "r");
	if( f )
	{
		c = fgetc(f);
		int i;
		for( i=0; i < 60000 && !feof(f); i++ )
		{			
			rpt[i] = c;
			c = fgetc(f);
		}
		fclose(f);
		rpt[i] = 0;
	}
	else
	{
		AfxMessageBox ("Невозможно открыть шаблон vo2_template.htm\nФормирование невозможно");
		return;
	}

	CString str = rpt;	
	strcpy(rpt, "N/A");

	sprintf(cQ, "pTov_mkcRepSelVO2S %d, '%.2d%.2d01'", g_iDep, wYear, m_Cb.GetItemData(m_Cb.GetCurSel()));
	DBW.ExecSQL(cQ);

	DBW.Fetch();
	DBW.GetData(1, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 ) str.Replace("###1###", rpt);
	else str.Replace("###1###", "N/A");
	DBW.GetData(2, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 )str.Replace("###2###", rpt);
	else str.Replace("###2###", "N/A");
	DBW.GetData(3, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 ) str.Replace("###3###", rpt);
	else str.Replace("###3###", "N/A");
	DBW.GetData(4, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 ) str.Replace("###4###", rpt);
	else str.Replace("###4###", "N/A");
	DBW.GetData(5, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 ) str.Replace("###5###", rpt);
	else str.Replace("###5###", "N/A");
	DBW.GetData(6, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 ) str.Replace("###6###", rpt);
	else str.Replace("###6###", "N/A");
	DBW.GetData(7, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 )str.Replace("###7###", rpt);
	else str.Replace("###7###", "N/A");
	DBW.GetData(8, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 ) str.Replace("###8###", rpt);
	else str.Replace("###8###", "N/A");

	DBW.GetData(9, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 )str.Replace("###9###", rpt);
	else str.Replace("###9###", "N/A");
	DBW.GetData(10, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 ) str.Replace("###10###", rpt);
	else str.Replace("###10###", "N/A");
	DBW.GetData(11, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 ) str.Replace("###11###", rpt);
	else str.Replace("###11###", "N/A");
	DBW.GetData(12, SQL_C_CHAR, rpt, 100, &Ind );
	if( Ind != -1 ) str.Replace("###12###", rpt);
	else str.Replace("###12###", "N/A");

	DBW.CloseCursor();
	f = fopen("html\\tmp.html", "w");
	fprintf(f, "%s", str);
	fclose(f);
	ShellExecute(NULL, "open", "html\\tmp.html", NULL, NULL, SW_SHOWNORMAL);
	OnOK();
}
