// DlgCreateIni.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgCreateIni.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgCreateIni dialog


CDlgCreateIni::CDlgCreateIni(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgCreateIni::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgCreateIni)
	m_strServerName = _T("");
	m_strLogin = _T("");
	m_strPassword = _T("");
	//}}AFX_DATA_INIT
}


void CDlgCreateIni::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgCreateIni)
	DDX_Control(pDX, IDC_EDIT3, m_EdPass);
	DDX_Control(pDX, IDC_EDIT2, m_EdLogin);
	DDX_Control(pDX, IDC_EDIT1, m_EdSrv);
	DDX_Text(pDX, IDC_EDIT1, m_strServerName);
	DDX_Text(pDX, IDC_EDIT2, m_strLogin);
	DDX_Text(pDX, IDC_EDIT3, m_strPassword);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgCreateIni, CDialog)
	//{{AFX_MSG_MAP(CDlgCreateIni)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgCreateIni message handlers

void CDlgCreateIni::OnOK() 
{
    if( CheckValid() ) return;
	CDialog::OnOK();
}

int CDlgCreateIni::CheckValid()
{
    CString s;
    
    m_EdSrv.GetWindowText(s);
    if( s == "" ) 
    {
        MessageBox("Необходимо указать имя сервера!", "Внимание", MB_OK);
        return -1;
    }
    if( !m_EdLogin.GetWindowTextLength() )
    {
        if( MessageBox("Не указано имя пользователя!\nИспользовать для подключения аутентификацию Windows?", 
                       "Внимание",
                       MB_YESNO) == IDNO)
        {
            return -1;
        }
        m_EdPass.SetWindowText("");
    }
    return 0;
}

void CDlgCreateIni::OnButton1() //Тест
{
	if( CheckValid() ) return;

    CString s1, s2, s3;
    CDBWire TestWire;
    m_EdSrv.GetWindowText(s1);
    m_EdLogin.GetWindowText(s2);
    m_EdPass.GetWindowText(s3);
    if( TestWire.Connect(s1, s2, s3) )
    {
        MessageBox("Ошибка подключения к серверу!\n\nПроверьте корректность введенных данных, наличие прав пользователя для доступа к базе kcmod, а также работоспособность сети.",
                   "Внимание", MB_OK);
    } else
    {
        MessageBox("Подключение прошло успешно!", "Внимание", MB_OK);
    }
    TestWire.Disconnect();
}

BOOL CDlgCreateIni::OnInitDialog() 
{
	CDialog::OnInitDialog();
	HICON hIcon;
    hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
    SetIcon(hIcon, TRUE);
    SetIcon(hIcon, FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
