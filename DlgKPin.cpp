// DlgKPin.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgKPin.h"
#include "DlgPrihodKP.h"
#include "DlgShowTwin.h"

#include <sql.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <odbcss.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp theApp;

DWORD idKPType[64];
//DWORD dwNumKP;
char cNumKP[32] = "";
DWORD dwTypeKP;
/////////////////////////////////////////////////////////////////////////////
// CDlgKPin dialog


CDlgKPin::CDlgKPin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgKPin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgKPin)
	m_iNumKP = 0;
	//}}AFX_DATA_INIT
}


void CDlgKPin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgKPin)
	DDX_Control(pDX, IDC_BUTTON8, m_TwinBn);
	DDX_Control(pDX, IDC_COMBO1, m_Combo1);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Text(pDX, IDC_EDIT1, m_iNumKP);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgKPin, CDialog)
	//{{AFX_MSG_MAP(CDlgKPin)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON8, OnButton8)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgKPin message handlers
BOOL CDlgKPin::OnInitDialog()
{
    long Ind = 0;
    DWORD iType = 0;
    char cQuery[]="pTov_GetTKP";
    char cText[64] = "";
    DBW.ExecSQL(cQuery);
    CComboBox *Box = (CComboBox *)GetDlgItem(IDC_COMBO1);    
    for(DWORD i=0; DBW.Fetch() != SQL_NO_DATA && i < 64; i++ )
    {
        DBW.GetData( 1, SQL_C_ULONG, &iType, 8, &Ind);
        DBW.GetData( 2, SQL_C_CHAR, cText, 64, &Ind);
        Box->AddString(cText);
        idKPType[i] = iType;
    }
    Box->SetCurSel(0);
    CEdit *e = (CEdit *)GetDlgItem(IDC_EDIT3);
    e->SetWindowText("Введите номер и тип колесной пары и нажмите кнопку \"Готово\"");
    DBW.CloseCursor();
    return TRUE;
}

void CDlgKPin::SelPrih()
{
    
}

void CDlgKPin::OnOK() 
{    
    CComboBox *box = (CComboBox *)GetDlgItem(IDC_COMBO1);
    int idx = box->GetCurSel();
    CString     cText;
    CDlgShowTwin TwinDlg;
    CEdit *ed = (CEdit *)GetDlgItem(IDC_EDIT1);
    ed->GetWindowText(cText);
    DWORD   dwNkp = (DWORD)_atoi64(cText);
    if( dwNkp == 0 )
    {
        AfxMessageBox("Введен некорректный номер КП!");
        return;
    }
    strncpy(cNumKP, cText, 32);
    dwTypeKP = idKPType[idx];
    char cQ[512] = "";
    sprintf(cQ, "pTov_GetKPCountByNKP '%s', %u", cNumKP, dwTypeKP);
    DBW.ExecSQL(cQ);    
    if( (g_sqlret = DBW.Fetch()) == SQL_NO_DATA || g_sqlret == SQL_ERROR)
    {
        return;
    }
    DWORD   dwCount = 0;
    long    Ind = 0;
    CButton *bn = (CButton *)GetDlgItem(IDC_BUTTON1);
    bn->EnableWindow(TRUE);
    BOOL isData = FALSE;
    DBW.GetData( 1, SQL_C_SLONG, &dwCount, 4, &Ind);
    DBW.CloseCursor();
    if( dwCount == 0 )
    {
        ed = (CEdit *)GetDlgItem(IDC_EDIT3);
        ed->SetWindowText("В базе данных нет паспорта указанной КП. Для занесения начальной информации нажмите на кнопку \"Приход\"");
        CButton *bn = (CButton *)GetDlgItem(IDC_BUTTON6);
        bn->EnableWindow(TRUE);
    } else
    {
        m_TwinBn.SetWindowText("asd");

        if( dwCount == 1)
        {
        //        m_TwinBn.ModifyStyle(WS_DISABLED, 0);
        // Unfinished
        } else
        if( dwCount > 1 )
        {
            CButton *bn = (CButton *)GetDlgItem(IDC_BUTTON8);
            bn->EnableWindow(TRUE);
            TwinDlg.dwTKP = dwTypeKP;
            strncpy(TwinDlg.cNKP, cNumKP, 32);
            box->GetLBText(idx, TwinDlg.cTKP);
            TwinDlg.DoModal();
            if( TwinDlg.iRez == 500 )
            {
// replace everything commented 2 form values...

                ed->SetWindowText("Зарегистрируйте информацию о приходе.\n(нажмите на кнопку \"Приход\")");
                /*
                label3.Caption:='В базе найдена запись о приходе.';
                Button5.Enabled:=true;
                */
                if( TwinDlg.dwGruz == 5 || Prih.cKneisp[0] == '5' )
                {
                    // найден приход оси
                    // PrOs.Enabled:=true; Zapr.Enabled:=true; Button1.Enabled:=false;
                    if( Prih.dwPriznRas > 1 )
                    {
/*
                       Button2.Enabled:=true; Button3.Enabled:=true;
                       button4.Enabled:=true;
*/                }
                }
                else
                {
                    // найден приход КП
                    // button4.Enabled:=true; PrOs.Enabled:=false;
                    if( Prih.dwPriznRas == 10 )// требует смены элементов
                    {
                        // Zapr.Enabled:=true   
                    }
                    else
                    if( Prih.dwPriznRas > 10 || Prih.wTREB_REM > 0)
                    {
                        // Button2.Enabled:=true; Button3.Enabled:=true;
                        if( Prih.dwPriznRas >= 20 )
                        {
                            // Zapr.Enabled:=true;
                        }
                    }
                }        
            }
        }
    }
//	CDialog::OnOK();
}

void CDlgKPin::OnButton1() //Приход КП
{
	CDlgPrihodKP Dlg;
    CString cText = "";
    char s[64]="";
    CEdit *ed = (CEdit *)GetDlgItem(IDC_EDIT1);
    ed->GetWindowText(cText);
    Dlg.m_strNumKP = CString("Номер: ") + cNumKP;
    CComboBox *box = (CComboBox *)GetDlgItem(IDC_COMBO1);
    box->GetLBText(box->GetCurSel(), cText);
    Dlg.m_strTypeKP = CString("Тип: ") + cText;    
    if( Dlg.DoModal() == IDCANCEL ) return;
}



void CDlgKPin::OnButton8() 
{
	
}
