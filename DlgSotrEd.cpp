// DlgSotrEd.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSotrEd.h"
#include "DlgEditPass.h"
#include "DlgEdRsn.h"
#include "EmplArray.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include "odbcss.h"
#include ".\dlgsotred.h"


extern SQLRETURN    g_sqlret;
extern CMasterApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CDlgSotrEd dialog


CDlgSotrEd::CDlgSotrEd(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSotrEd::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSotrEd)
	m_cbPRKP = FALSE;
	m_cbPZMKP = FALSE;
	m_cbPDSH = FALSE;
	m_cbPDPO = FALSE;
	m_cbPDVK = FALSE;
	m_cbPDSO = FALSE;
	m_cbPDSP = FALSE;
	m_cbPDD = FALSE;
	m_cbPDO = FALSE;
	m_cbPDG = FALSE;
	m_cbPDROL = FALSE;
	m_cbPDSEP = FALSE;
	m_cbPDNK = FALSE;
	m_cbPOSV = FALSE;
	m_cbPMB = FALSE;
	m_cbSL1 = FALSE;
	m_cbSL2 = FALSE;
	m_cbPOTK = FALSE;
	m_cbPOP = FALSE;
	m_cbPRP = FALSE;
	m_cbPKP = FALSE;
	m_cbOTP = FALSE;
	m_cbPVPV = FALSE;
	m_cbMRP = FALSE;
	m_cbORED = FALSE;
	m_cbRRED = FALSE;
	m_cbMRED = FALSE;
	m_cbZKP = FALSE;
	m_cbBZKP = FALSE;
	m_Edit1Text = _T("");
	m_Edit5Text = _T("");
	m_Edit4Text = _T("");
	//}}AFX_DATA_INIT
    miRang = 0;
    Mode = 0;
    mcPass[0]=0;
    ret_dwProfID = 0;
}

CDlgSotrEd::~CDlgSotrEd()
{
    CObject::~CObject();
}

void CDlgSotrEd::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSotrEd)
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_CHECK30, m_Check1);
	DDX_Control(pDX, IDC_EDIT6, m_Edit5);
	DDX_Control(pDX, IDC_EDIT5, m_Edit4);
	DDX_Check(pDX, IDC_CHECK1, m_cbPRKP);
	DDX_Check(pDX, IDC_CHECK2, m_cbPZMKP);
	DDX_Check(pDX, IDC_CHECK6, m_cbPDSH);
	DDX_Check(pDX, IDC_CHECK7, m_cbPDPO);
	DDX_Check(pDX, IDC_CHECK9, m_cbPDVK);
	DDX_Check(pDX, IDC_CHECK11, m_cbPDSO);
	DDX_Check(pDX, IDC_CHECK13, m_cbPDSP);
	DDX_Check(pDX, IDC_CHECK12, m_cbPDD);
	DDX_Check(pDX, IDC_CHECK16, m_cbPDO);
	DDX_Check(pDX, IDC_CHECK14, m_cbPDG);
	DDX_Check(pDX, IDC_CHECK8, m_cbPDROL);
	DDX_Check(pDX, IDC_CHECK10, m_cbPDSEP);
	DDX_Check(pDX, IDC_CHECK15, m_cbPDNK);
	DDX_Check(pDX, IDC_CHECK17, m_cbPOSV);
	DDX_Check(pDX, IDC_CHECK19, m_cbPMB);
	DDX_Check(pDX, IDC_CHECK21, m_cbSL1);
	DDX_Check(pDX, IDC_CHECK23, m_cbSL2);
	DDX_Check(pDX, IDC_CHECK25, m_cbPOTK);
	DDX_Check(pDX, IDC_CHECK24, m_cbPOP);
	DDX_Check(pDX, IDC_CHECK26, m_cbPRP);
	DDX_Check(pDX, IDC_CHECK3, m_cbPKP);
	DDX_Check(pDX, IDC_CHECK4, m_cbOTP);
	DDX_Check(pDX, IDC_CHECK5, m_cbPVPV);
	DDX_Check(pDX, IDC_CHECK28, m_cbMRP);
	DDX_Check(pDX, IDC_CHECK18, m_cbORED);
	DDX_Check(pDX, IDC_CHECK20, m_cbRRED);
	DDX_Check(pDX, IDC_CHECK22, m_cbMRED);
	DDX_Check(pDX, IDC_CHECK27, m_cbZKP);
	DDX_Check(pDX, IDC_CHECK29, m_cbBZKP);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1Text);
	DDX_Text(pDX, IDC_EDIT6, m_Edit5Text);
	DDX_Text(pDX, IDC_EDIT5, m_Edit4Text);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgSotrEd, CDialog)
	//{{AFX_MSG_MAP(CDlgSotrEd)
	ON_BN_CLICKED(IDC_CHECK30, OnCheck30)
	ON_EN_KILLFOCUS(IDC_EDIT1, OnKillfocusEdit1)
	ON_EN_SETFOCUS(IDC_EDIT5, OnSetfocusTabNum)
	//}}AFX_MSG_MAP
	ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSotrEd message handlers

void CDlgSotrEd::OnOK() 
{
    CString cText;
    char cQ[64] = "";
    m_Edit1.GetWindowText(cText);
    if( cText == "" )
    {
        AfxMessageBox("Не указана фамилия!");
        return;
    }
/*
    if( m_Combo.GetCurSel() < 0 )
    {
        AfxMessageBox("Не указана профессия!");
        m_Combo.SetFocus();
        return;
    }
*/
    if( Mode == 0 ) 
    {
        sprintf(cQ, "pTov_GetEmployer 1, '%s'", cText);
    }
    else if( Mode == 1 ) sprintf(cQ, "pTov_GetEmployer 2, '%s', %d", cText, id);
    DBW.ExecSQL(cQ); 
    if( Mode == 0 && DBW.Fetch() != SQL_NO_DATA )
    {
        char msg[128] = "";
        sprintf(msg, "Человек с ФИО \"%s\" уже есть в списке сотрудников!\nПродожить ли добавление нового сотрудника?", cText);
        if( MessageBox(msg, "Мастер", MB_YESNO) == IDNO )
        {
            DBW.CloseCursor();
            return;
        }
    }
    char cTabNum[32] = "";
    long Ind = 0;
    DBW.GetData( 2, SQL_C_CHAR, &cTabNum, 32, &Ind);
    DBW.CloseCursor();
/*    m_Edit2.GetWindowText(cText);
    if( cText == "" )
    {
        AfxMessageBox("Не указано имя!");
        return;
    }
    m_Edit3.GetWindowText(cText);
    if( cText == "" )
    {
        AfxMessageBox("Не указано отчество!");
        return;
    }
*/
    m_Edit4.GetWindowText(cText);
    if( cText == "" )
    {
        AfxMessageBox("Не указан табельный номер!");
        return;
    }
    if( strcmp(cTabNum, cText) == 0 )
    {
        AfxMessageBox("В базе уже есть человек с указанными ФИО и табельным номером.\nДобавление не возможно!");
        return;
    }
/*    CDlgEdRsn Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;*/
    id = m_Edit1.GetData();
    m_Edit1.lpEmpl = NULL;
    if( m_Combo.GetCurSel() != -1 )
    {
        ret_dwProfID = m_Combo.GetItemData(m_Combo.GetCurSel());
    } else
        ret_dwProfID = 0;
	CDialog::OnOK();
}

void CDlgSotrEd::OnCheck30() 
{
    if( m_Check1.GetCheck() )
    {
        m_Check1.SetCheck(0);
        miRang = 0;
        mcPass[0] = 0;
        return;
    }
    CDlgEditPass Dlg;
    Dlg.Mode = 1;
    m_Edit1.GetWindowText(Dlg.m_cUser);
    if( Dlg.DoModal() == IDCANCEL ) return;   
    m_Check1.SetCheck(1);
    strncpy(mcPass, Dlg.m_cPass1, 20);
    miRang = Dlg.m_iRang;
}

BOOL CDlgSotrEd::OnInitDialog() 
{
	CDialog::OnInitDialog();
    DWORD dwNum = 0;
    DWORD dwTab = 0;
    char cText[64] = "";
	char cQ[128] = "";
    long Ind = 0;
    m_Edit1.iMode = 4;
    m_Edit1.lpEmpl = &EmplArr;
    if( miRang > 0 )
    {
        m_Check1.SetCheck(1);
    }
    if( !Mode ) id = 0;
    sprintf(cQ, "pTov_GetAllUnregEmpl %u", g_iDep);
    DBW.ExecSQL(cQ);   
    for(DWORD i=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && i < 9024; i++ )
    {
        cText[0] = 0;
        dwNum = 0;
        dwTab = 0;
        DBW.GetData( 1, SQL_C_SLONG, &dwNum, 4, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 20, &Ind);        
 //TabNumber 
        DBW.GetData( 3, SQL_C_ULONG, &dwTab, 20, &Ind);       
/*
   //Dolg
        DBW.GetData( 3, SQL_C_CHAR, cText, 20, &Ind);
*/        
        if( Ind != -1 ) EmplArr.AddEmployee(dwNum, cText, dwTab);
        m_Edit1.lpEmpl = &EmplArr;
    }
    DBW.CloseCursor();
    DBW.FillComboWithProfessions(&m_Combo);
    for(DWORD i=0; i < (unsigned)m_Combo.GetCount(); i++ )
    {
        if( m_Combo.GetItemData(i) == ret_dwProfID )
        {
            m_Combo.SetCurSel(i);
            break;
        }
    }
	return TRUE;
}

void CDlgSotrEd::OnKillfocusEdit1() 
{
    char cQ[128] = "";
    char cText[64] = "";
    int  lID = id;
    m_Edit1.GetWindowText(cText, 64);
    if( !id )
    {
        id = EmplArr.GetIDbyFIO(cText);
        if( id )
        {
            itoa(EmplArr.GetTabNumByID(id), cText, 10);
            m_Edit4.SetWindowText(cText);
        }
    }
    strupr(cText);
    for( int i=0; cText[i] && i < 255; i++ )
        if( cText[i] >= 'а' && cText[i] <= 'я' ) cText[i] -= 32;
    for( int i=1; cText[i] != ' ' && cText[i] && i < 255; i++ )
    {
        if( cText[i] >= 'А' && cText[i] <= 'Я' ) cText[i] += 32;
    }
    m_Edit1.SetWindowText(cText);
    
    if( id && lID)
    {
        char cMess[255] = "";
        sprintf(cMess, "В глобальном списке сотрудников уже есть сотрудник с ФИО \"%s\".\nДобавить его в список сотрудников МКЦ?", cText);
        if( MessageBox(cMess, "Внимание", MB_YESNO) == IDYES )
        {
            itoa(EmplArr.GetTabNumByID(id), cText, 10);
            m_Edit4.EnableWindow(FALSE);
            m_Edit5.SetWindowText(cText);
            m_Edit4.SetFocus();
        }
        else
            id = 0;
    }
}


void CDlgSotrEd::OnSetfocusTabNum() 
{
    char cText[64] = "";
    if( m_Edit1.GetData() )
    {
        itoa(EmplArr.GetTabNumByID(m_Edit1.GetData()), cText, 10);
            m_Edit4.SetWindowText(cText);
    }
}

void CDlgSotrEd::OnCbnSelchangeCombo1()
{
	// TODO: Add your control notification handler code here
}
