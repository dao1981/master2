// DlgEditPass.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgEditPass.h"
#include ".\dlgeditpass.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgEditPass dialog

extern WORD g_iRang;

CDlgEditPass::CDlgEditPass(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgEditPass::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgEditPass)
	m_iRang = 0;
	m_cPass1 = _T("");
	m_cPass2 = _T("");
	m_cUser = _T("");
	//}}AFX_DATA_INIT
    Mode = 0;
	iRang = 0;
	iFam = 0;
	bRangWasChanged = FALSE;
	strcpy(cOldRang, "0");
}


void CDlgEditPass::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgEditPass)
	DDX_Control(pDX, IDC_EDIT5, m_Edit1);
	DDX_Text(pDX, IDC_EDIT5, m_iRang);
	DDV_MinMaxUInt(pDX, m_iRang, 0, 255);
	DDX_Text(pDX, IDC_EDIT6, m_cPass1);
	DDV_MaxChars(pDX, m_cPass1, 10);
	DDX_Text(pDX, IDC_EDIT7, m_cPass2);
	DDV_MaxChars(pDX, m_cPass2, 10);
	DDX_Text(pDX, IDC_EDIT4, m_cUser);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgEditPass, CDialog)
	//{{AFX_MSG_MAP(CDlgEditPass)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, OnBnClickedCancel)
	ON_EN_CHANGE(IDC_EDIT5, OnEnChangeEdit5)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgEditPass message handlers
extern CMasterApp theApp;
void CDlgEditPass::OnOK() 
{
	// TODO: Add extra validation here
    char    cText[64] = "";
    char    cText1[64] = "";

    (CEdit *)GetDlgItem(IDC_EDIT5)->GetWindowText(cText, 64);
    
    if( cText[0] == 0 )
    {
        AfxMessageBox("Необходимо указать ранг доступа!");
        return;
    }
	iRang = atoi(cText);
    (CEdit *)GetDlgItem(IDC_EDIT6)->GetWindowText(cText, 64);
    if( cText[0] == 0 )
    {
        AfxMessageBox("Не указан иднтификатор доступа!");
        return;
    }
    (CEdit *)GetDlgItem(IDC_EDIT7)->GetWindowText(cText1, 64);
	if( strncmp(cText, cText1, 10) )
    {
        AfxMessageBox("Идентификатор не подтвержден!");
        return;
    }
    long    Ind = 0;
    DWORD   dwNum = 0;
    sprintf(cText, "pTov_CheckPassExists '%s', %s", cText1, isNull((DWORD)iFam));
    DBW.ExecSQL(cText);
    g_sqlret = DBW.Fetch();
    DBW.GetData( 1, SQL_C_ULONG, &dwNum, 4, &Ind);
    DBW.CloseCursor();
    if( dwNum > 0 )
    {
        ::MessageBox(NULL, "Указанный идентификатор уже есть в БД.", "Проверка корректности идентификатора", MB_OK | MB_ICONINFORMATION);
        return;
    }
	CDialog::OnOK();
}

BOOL CDlgEditPass::OnInitDialog() 
{
	CDialog::OnInitDialog();
	if( Mode == 1 )
    {
        SetWindowText("Ввод пароля для нового пользователя");
        m_Edit1.ModifyStyle(WS_DISABLED | ES_READONLY, 0);
        m_Edit1.RedrawWindow();
    } else
    {
        m_Edit1.ModifyStyle(0, WS_DISABLED | ES_READONLY, 0);
        m_Edit1.RedrawWindow();
    }
	if( g_iRang < 4 ) m_Edit1.EnableWindow(FALSE);
	else m_Edit1.EnableWindow();

	if( !m_iRang )m_Edit1.SetWindowText(cOldRang);

//	if( m_Edit1.GetWindowTextLength() ) m_Edit1.SetWindowText(cOldRang);

	return TRUE;
}

void CDlgEditPass::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CDlgEditPass::OnBnClickedCancel()
{
	// TODO: Add your control notification handler code here
	OnCancel();
}

void CDlgEditPass::OnEnChangeEdit5()
{
	bRangWasChanged = TRUE;
}
