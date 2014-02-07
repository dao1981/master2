// DlgMakeLK_Send.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgMakeLK_Send.h"
#include "DlgSpravKdr.h"
#include "PrintableDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CDlgMakeLK_Send dialog


CDlgMakeLK_Send::CDlgMakeLK_Send(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgMakeLK_Send::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgMakeLK_Send)
	m_LNum = _T("");
	m_VagNum = _T("");
	m_Oper = _T("");
	//}}AFX_DATA_INIT
}


void CDlgMakeLK_Send::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgMakeLK_Send)
	DDX_Control(pDX, IDC_EDIT4, m_EdFam2);
	DDX_Control(pDX, IDC_EDIT3, m_EdFam1);
	DDX_Control(pDX, IDC_EDIT2, m_EdVag);
	DDX_Control(pDX, IDC_EDIT1, m_EdNum);
	DDX_Text(pDX, IDC_EDIT1, m_LNum);
	DDX_Text(pDX, IDC_EDIT2, m_VagNum);
	DDX_Text(pDX, IDC_EDIT4, m_Oper);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgMakeLK_Send, CDialog)
	//{{AFX_MSG_MAP(CDlgMakeLK_Send)
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonKdr)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton_MessageText)
	ON_BN_CLICKED(IDOK, OnSend)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton_LK_view)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgMakeLK_Send message handlers

BOOL CDlgMakeLK_Send::OnInitDialog() 
{
	CDialog::OnInitDialog();

    CString cQ;
    char cText[255] = "";
    long Ind = 0;
    int   iNum = 0;
    cQ.Format("pTov_LK_CheckComplete %I64u", qwILK);
    DBW.ExecSQL(cQ);
    DBW.Fetch();
    DBW.GetData(1, SQL_C_CHAR, &cText, 255, &Ind);
    DBW.CloseCursor();
    if( Ind != -1 ) 
    {
        CDialog::OnCancel();
        DBW.CloseCursor();
        AfxMessageBox(cText, MB_OK);
        return FALSE;
    }

    m_EdFam1.SetMode(5);
    DBW.FillEmplArray(m_EdFam1.lpEmpl, 8);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgMakeLK_Send::OnButtonKdr() 
{
    CDlgSpravKdr Dlg;
    Dlg.iFilter = 8;
    Dlg.DlgMode = 1;
    if( Dlg.DoModal() == IDCANCEL ) return;

    m_EdFam1.SetFamTextByID(Dlg.dwFio);
}

void CDlgMakeLK_Send::OnButton_MessageText()
{
    CPrintableDlg Dlg;
    sprintf(Dlg.cQ, "pTov_mkcS4624 %I64u", qwILK);
    Dlg.DoModal();
}

void CDlgMakeLK_Send::OnSend() 
{
	if( g_conf_strMessagePath != "" )
    {
        char cQ[64] = "";
        char cText[512] = "";
        long Ind = 0;

        sprintf(cQ, "pTov_mkcS4624 %I64u", qwILK);
        DBW.ExecSQL(cQ);
        DBW.Fetch();
        DBW.GetData(1, SQL_C_CHAR, cText, 512, &Ind);
        DBW.CloseCursor();

        if( cText[0] == 0 )
        {
            AfxMessageBox("Сообщение не сформировано!", MB_OK);
            theApp.WriteLog("Сообщение не сформировано!");
            return;
        }
        CString strN;
        SYSTEMTIME st;
        GetLocalTime(&st);
        strN.Format("%s%.2d%.2d_%s.txt", 
                    g_conf_strMessagePath,
                    st.wMonth,
                    st.wDay,
                    m_VagNum);
        char sl[64];
        sprintf(sl, "Msg: %s", strN);
        theApp.WriteLog((LPTSTR)sl, 3);
        FILE *f = fopen(strN, "wb");
        if( !f )
        {
            AfxMessageBox("Невозможно открыть файл!", MB_OK);
            return;
        }
        fwrite(cText, strlen(cText), 1, f);
        fclose(f);
   
        //закроем листок в базе
        sprintf(cQ, "pTov_LK_Complete %I64u, %u, %s", 
                qwILK,
                g_iFam,
                m_EdFam1.GetDataAsString(TRUE));
        DBW.ExecSQL(cQ);
        DBW.CloseCursor();
    }
    CDialog::OnOK();
}

void CDlgMakeLK_Send::OnButton_LK_view() 
{    
    CPrintableDlg Dlg;
    sprintf(Dlg.cQ, "pTov_mkcReportVU36MP %I64u", qwILK);
    Dlg.DoModal();
}
