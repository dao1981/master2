// AddFacelessVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "AddFacelessVag.h"
#include ".\addfacelessvag.h"
#include "DlgPodkat1069.h"


// CAddFacelessVag dialog

IMPLEMENT_DYNAMIC(CAddFacelessVag, CDialog)
CAddFacelessVag::CAddFacelessVag(CWnd* pParent /*=NULL*/)
	: CDialog(CAddFacelessVag::IDD, pParent)
{
	qwTlVagID = 0;
	dwBrigadir_ID = 0;
//	qwReplaceVagID = 0;
	iVagPrih = 0;
}

CAddFacelessVag::~CAddFacelessVag()
{
}

void CAddFacelessVag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_EdVag);
}


BEGIN_MESSAGE_MAP(CAddFacelessVag, CDialog)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CAddFacelessVag message handlers

BOOL CAddFacelessVag::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_EdVag.QInit(80, 1);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CAddFacelessVag::OnBnClickedOk()
{
	char cText[64] = "";
	char cQ[64] = "";
	long Ind = 0;
	int  iRet = 0;
	char cMess[2048] = "";
	int iCancelFlag = 0;

	m_EdVag.GetWindowText(strNVag);

	sprintf(cQ, "pTov_pptAddVagVkt '%s', 1", strNVag);
	DBW.ExecSQL(cQ);
	DBW.Fetch();
	DBW.GetData(1, SQL_C_SLONG, &iRet, 4, &Ind);
	if( iRet == -1 )
	{
		DBW.GetData(2, SQL_C_CHAR, cMess, 1024, &Ind);
		if( MessageBox(cMess, "", MB_YESNO) == IDYES) 
		{
			// Будем оформлять приход нового вагона
			iVagPrih = 1;
			CDlgPodkat1069 Dlg;
			Dlg.iTLReplaceMode = 1;
			strncpy(Dlg.cNVag, strNVag, 9);
			GetLocalTime(&Dlg.stDat);
			Dlg.dwBrigadir_ID = dwBrigadir_ID;
			strncpy(Dlg.cNTL1, cNTL1, 16);
			strncpy(Dlg.cNTL2, cNTL2, 16);


			if( Dlg.DoModal() == IDCANCEL )
				iCancelFlag = 1;
/*			else 
			{
			if( !Dlg.qwPTVag_ID )
			{
				AfxMessageBox("Ошибка записи прихода вагона!");
				return;
			}
			qwReplaceVagID = Dlg.qwPTVag_ID;
			}
*/
		}
	} else
	{
		DBW.GetData(2, SQL_C_UBIGINT, &qwTlVagID, 8, &Ind);
		DBW.GetData(4, SQL_C_CHAR, &cText, 4, &Ind);
		if( Ind == -1 )
		{
			AfxMessageBox("Нельзя взять тележку из-под обезличенного вагона!");
			return;
		}
	}
	DBW.CloseCursor();
	
	if( iCancelFlag )
		CDialog::OnCancel();
	else
		OnOK();
}
