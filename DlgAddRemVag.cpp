// DlgAddRemVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgAddRemVag.h"
#include "DlgSpravKdr.h"
#include ".\dlgaddremvag.h"
#include "DlgSpravKdr.h"
#include "DlgSpravSmp.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgAddRemVag dialog


CDlgAddRemVag::CDlgAddRemVag(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgAddRemVag::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgAddRemVag)
	m_bCheck = FALSE;
	m_strNVag = _T("");
	//}}AFX_DATA_INIT
    m_TypeIndex = -1;
    bIsEdit = FALSE;
    m_DatCome.SetMode(1);
	bSetDat4624 = 0;
	bSetDateNachRem = 0;
	bSetDatSbor = 0;
	bSetDatPerechNeisp = 0;
	m_strNLK = "";

	m_cVktTel[0] = 0;
	m_cVktKP[0] = 0;
	m_cPdkTel[0] = 0;
	m_cPdkKP[0] = 0;

	m_dwIFam1 = 0;
	m_dwIFam2 = 0;
	m_dwIFam3 = 0;
	m_dwIFam4 = 0;
	m_dwIFam5 = 0;
}


void CDlgAddRemVag::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgAddRemVag)
	DDX_Control(pDX, IDC_EDIT116, m_DatSbor);
	DDX_Control(pDX, IDC_EDIT3, m_DatCome);
	DDX_Control(pDX, IDC_CHECK1, m_Check);
	DDX_Control(pDX, IDC_EDIT1, m_nVan);
	DDX_Control(pDX, IDC_COMBO1, m_RemKind);
	DDX_Check(pDX, IDC_CHECK1, m_bCheck);
	DDX_Text(pDX, IDC_EDIT1, m_strNVag);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_EDIT2, m_Hour);
	DDX_Control(pDX, IDC_EDIT7, m_Min1);
	DDX_Control(pDX, IDC_EDIT5, m_Hour3);
	DDX_Control(pDX, IDC_EDIT117, m_Min3);
	DDX_Control(pDX, IDC_EDIT148, m_Dat4624);
	DDX_Control(pDX, IDC_EDIT149, m_EdNLK);
	
	DDX_Control(pDX, IDC_EDIT12, m_DatNachRem);
	DDX_Control(pDX, IDC_EDIT4, m_Hour2);
	DDX_Control(pDX, IDC_EDIT93, m_Min2);


	DDX_Control(pDX, IDC_EDIT150, m_EdPdkTel);
	DDX_Control(pDX, IDC_EDIT151, m_EdPdkKP);
	DDX_Control(pDX, IDC_EDIT152, m_EdVktTel);
	DDX_Control(pDX, IDC_EDIT153, m_EdVktKP);

	DDX_Control(pDX, IDC_EDIT94, m_EdKodSobst);
	DDX_Control(pDX, IDC_EDIT69, m_EdNameSobst);

	DDX_Control(pDX, IDC_EDIT202, m_EdFio1);
	DDX_Control(pDX, IDC_EDIT204, m_EdFio2);
	DDX_Control(pDX, IDC_EDIT206, m_EdFio3);
	DDX_Control(pDX, IDC_EDIT205, m_EdFio4);
	DDX_Control(pDX, IDC_EDIT207, m_EdFio5);
	
}


BEGIN_MESSAGE_MAP(CDlgAddRemVag, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CDlgAddRemVag)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON3, OnBnClickedSobst)
	ON_BN_CLICKED(IDC_BUTTON29, OnBnClickedButtonFio1)
	ON_BN_CLICKED(IDC_BUTTON31, OnBnClickedButtonFio2)
	ON_BN_CLICKED(IDC_BUTTON63, OnBnClickedButtonFio3)
	ON_BN_CLICKED(IDC_BUTTON62, OnBnClickedButtonFio4)
	ON_BN_CLICKED(IDC_BUTTON64, OnBnClickedButtonFio5)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgAddRemVag message handlers

BOOL CDlgAddRemVag::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
    IniForm();
    m_nVan.SetModify(FALSE);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgAddRemVag::IniForm()
{
    DBW.FillComboWithTRemVag(&m_RemKind);
    if( m_TypeIndex != -1 )
    {
        for( int i=0; m_RemKind.GetCount() && i < 128; i++ )
        {
            if( (unsigned)m_TypeIndex == m_RemKind.GetItemData(i) )
            {
                m_RemKind.SetCurSel(i);
                break;
            }
        }
    }
	m_Hour.QInit(20,1);
	m_Min1.QInit(20,1);
	m_Hour2.QInit(20,1);
	m_Min2.QInit(20,1);
	m_Hour3.QInit(20,1);
	m_Min3.QInit(20,1);
	m_EdNLK.QInit(30,1);
	m_EdKodSobst.QInit(20,1);
	
	m_EdFio1.SetMode(5,1);
	DBW.FillEmplArray(m_EdFio1.lpEmpl, 10);
	m_EdFio2.SetMode(5,1);
	DBW.FillEmplArray(m_EdFio2.lpEmpl, 17);
	m_EdFio3.SetMode(5,1);
	DBW.FillEmplArray(m_EdFio3.lpEmpl, 39);
	m_EdFio4.SetMode(5,1);
	DBW.FillEmplArray(m_EdFio4.lpEmpl, 38);
	m_EdFio5.SetMode(5,1);
	DBW.FillEmplArray(m_EdFio5.lpEmpl, 40);

	m_EdKodSobst.SetWindowText(m_strKodSobst);
	m_EdNameSobst.SetWindowText(m_strNameSobst);
    if( bSetDateNachRem )
    {
        m_DatNachRem.SetTime(&m_stDateNachRem);
		m_Hour2.SetValue((DWORD)m_stDateNachRem.wHour);
		m_Min2.SetValue((DWORD)m_stDateNachRem.wMinute);
    }
    
	if( bSetDatPerechNeisp )
    {
        m_DatCome.SetTime(&m_stDatPerechNeisp);
		m_Hour.SetValue((DWORD)m_stDatPerechNeisp.wHour);
		m_Min1.SetValue((DWORD)m_stDatPerechNeisp.wMinute);
    }

	if( bSetDatSbor )
    {
        m_DatSbor.SetTime(&m_stDatSbor);
		m_Hour3.SetValue((DWORD)m_stDatSbor.wHour);
		m_Min3.SetValue((DWORD)m_stDatSbor.wMinute);
    }

	char cText[64] = "";
	if( bSetDat4624 )
	{
		sprintf(cText, "%.2d.%.2d.%.4d %.2d:%.2d",
			m_stDat4624.wDay,
			m_stDat4624.wMonth,
			m_stDat4624.wYear,
			m_stDat4624.wHour,
			m_stDat4624.wMinute);
		m_Dat4624.SetWindowText(cText);
	}
	m_EdNLK.SetWindowText(m_strNLK);

	m_EdPdkTel.SetWindowText(m_cPdkTel);
	m_EdPdkKP.SetWindowText(m_cPdkKP);
	m_EdVktTel.SetWindowText(m_cVktTel);
	m_EdVktKP.SetWindowText(m_cVktKP);

	if( m_dwIFam1 )
	{
		m_EdFio1.SetWindowText(m_strFam1);
		m_EdFio1.SetData(m_dwIFam1);
	}
	if( m_dwIFam2 )
	{
		m_EdFio2.SetWindowText(m_strFam2);
		m_EdFio2.SetData(m_dwIFam2);
	}
	if( m_dwIFam3 )
	{
		m_EdFio3.SetWindowText(m_strFam3);
		m_EdFio3.SetData(m_dwIFam3);
	}
	if( m_dwIFam4 )
	{
		m_EdFio4.SetWindowText(m_strFam4);
		m_EdFio4.SetData(m_dwIFam4);
	}
	if( m_dwIFam5 )
	{
		m_EdFio5.SetWindowText(m_strFam5);
		m_EdFio5.SetData(m_dwIFam5);
	}

}

void CDlgAddRemVag::OnOK() 
{
    CString str;
    CString nVan;
    CString Nin;
    m_nVan.GetWindowText(nVan);

    if( nVan == "" )
    {
        MessageBox("Необходимо указать номер вагона.", 
                   "Внимание", 
                   MB_OK | MB_ICONINFORMATION);
        return;
    }

    if( m_nVan.GetModify() &&
        !VanNumberIsValid(nVan) )
        if (MessageBox("Не сходится контрольная сумма номера вагона. Продолжить добавление?", 
                   "Внимание", 
                   MB_YESNO | MB_ICONINFORMATION) == IDNO)
        {
            return;        
        }
	
    if( m_RemKind.GetCurSel() == -1 )
    {
        MessageBox("Необходимо указать вид ремонта вагона.", 
                   "Внимание", 
                   MB_OK | MB_ICONINFORMATION);
        return;
    }

	char cText[1024] = "";

	if( m_Hour.GetWindowText(cText, 64) )
	{
		if( atoi(cText) < 0 || atoi(cText) > 24 )
		{
			AfxMessageBox("Время введено некорректно!");
			m_Hour.SetFocus();
			return;
		}
	}
	if( m_Min1.GetWindowText(cText, 64) )
		if( atoi(cText) < 0 || atoi(cText) > 60 )
		{
			AfxMessageBox("Время введено некорректно!");
			m_Min1.SetFocus();
			return;
		}

	if( m_Hour2.GetWindowText(cText, 64) )
	{
		if( atoi(cText) < 0 || atoi(cText) > 24 )
		{
			AfxMessageBox("Время введено некорректно!");
			m_Hour2.SetFocus();
			return;
		}
	}
	if( m_Min2.GetWindowText(cText, 64) )
		if( atoi(cText) < 0 || atoi(cText) > 60 )
		{
			AfxMessageBox("Время введено некорректно!");
			m_Min2.SetFocus();
			return;
		}
	if( m_Hour3.GetWindowText(cText, 64) )
	{
		if( atoi(cText) < 0 || atoi(cText) > 24 )
		{
			AfxMessageBox("Время введено некорректно!");
			m_Hour3.SetFocus();
			return;
		}
	}
	if( m_Min3.GetWindowText(cText, 64) )
		if( atoi(cText) < 0 || atoi(cText) > 60 )
		{
			AfxMessageBox("Время введено некорректно!");
			m_Min3.SetFocus();
			return;
		}

	if( m_DatCome.isNull() && m_DatNachRem.isNull() )
	{
        MessageBox("Необходимо указать дату перечисления в неисправные или дату начала ремонта.", 
                   "Внимание", 
                   MB_OK | MB_ICONINFORMATION);
        return;		
	}
/*
    if( !m_DatCome.isValid() )
    {
        MessageBox("Необходимо указать дату перечисления в неисправные.", 
                   "Внимание", 
                   MB_OK | MB_ICONINFORMATION);
        return;
    }
*/
    SYSTEMTIME st1, st2, Cur;
    m_DatSbor.GetAsDate(&st1);
    m_DatCome.GetAsDate(&st2);
	ZeroMemory(&Cur, sizeof(Cur));
	GetLocalTime(&Cur);
	if( SysDateCmp(st1, Cur) > 0 )
	{
		AfxMessageBox("Дата сборки больше текущей");
		m_DatSbor.SetFocus();
		return;
	}
	if( SysDateCmp(st2, Cur) > 0 )
	{
		AfxMessageBox("Дата перечисления в неисправные больше текущей");
		m_DatCome.SetFocus();
		return;
	}


    if( m_DatNachRem.isValid() )
    {
        SYSTEMTIME st1, st2;
        m_DatNachRem.GetAsDate(&st1);
        m_DatCome.GetAsDate(&st2);
		st2.wHour = (WORD)m_Hour.GetAsDWord();
		st2.wMinute = (WORD)m_Min1.GetAsDWord();
		st1.wHour = (WORD)m_Hour2.GetAsDWord();
		st1.wMinute = (WORD)m_Min2.GetAsDWord();
		
        if( SysDateCmp(st1, st2) < 0 )
        {
            MessageBox("Дата начала ремонта не может быть раньше даты перечисления в неисправные!",
                       "Внимание", 
                       MB_OK | MB_ICONINFORMATION);
            return;
        }
    }
	
	if( m_DatSbor.isValid() )
    {
        SYSTEMTIME st1, st2;
        m_DatSbor.GetAsDate(&st1);
        m_DatCome.GetAsDate(&st2);
		st1.wHour = (WORD)m_Hour3.GetAsDWord();
		st1.wMinute = (WORD)m_Min3.GetAsDWord();
		st2.wHour = (WORD)m_Hour.GetAsDWord();
		st2.wMinute = (WORD)m_Min1.GetAsDWord();

        if( SysDateCmp(st2, st1) > 0 )
        {
            MessageBox("Дата сборки не может быть раньше даты перечисления в неисправные!",
                       "Внимание", 
                       MB_OK | MB_ICONINFORMATION);
            return;
        }
		if( m_DatNachRem.isValid() )
		{
			m_DatNachRem.GetAsDate(&st2);
			st2.wHour = (WORD)m_Hour2.GetAsDWord();
			st2.wMinute = (WORD)m_Min2.GetAsDWord();

			if( SysDateCmp(st2, st1) > 0 )
			{
				MessageBox("Дата сборки не может быть раньше даты ремонта!",
						"Внимание", 
						MB_OK | MB_ICONINFORMATION);
				return;
			}
		}
    }

    if( m_Check.GetCheck() ) Nin = "1";
    else Nin = "0";

    long Ind = 0;
    
    long iRez = 0;

	char cDatePerVNeisp[32] = "";
	char cDateNachRem[32] = "";
	char cDateSbor[32] = "";

	strcpy(cDatePerVNeisp, m_DatCome.GetSQLDate() );
//	if( m_Hour.GetAsDWord() && m_Min1.GetAsDWord() )
//	{
		sprintf(cDatePerVNeisp + 9, " %.2d:%.2d'", m_Hour.GetAsDWord(), m_Min1.GetAsDWord());
//	}

	strcpy(cDateNachRem, m_DatNachRem.GetSQLDate() );
//	if( m_Hour2.GetAsDWord() && m_Min2.GetAsDWord() )
//	{
		sprintf(cDateNachRem + 9, " %.2d:%.2d'", m_Hour2.GetAsDWord(), m_Min2.GetAsDWord());
//	}

	strcpy(cDateSbor, m_DatSbor.GetSQLDate() );
//	if( m_Hour3.GetAsDWord() && m_Min3.GetAsDWord() )
//	{
		sprintf(cDateSbor + 9, " %.2d:%.2d'", m_Hour3.GetAsDWord(), m_Min3.GetAsDWord());
//	}


    if( !bIsEdit )
    {
        str.Format("pTov_AddRemVan %u, '%s', %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
                    g_iDep,
                    nVan, 
                    m_RemKind.GetItemData(m_RemKind.GetCurSel()), 

                    cDateNachRem, Nin, cDateSbor, cDatePerVNeisp,
					m_EdNLK.GetAsString(),
					m_EdKodSobst.GetAsString(),
					isNull(m_EdFio1.GetData()),
					isNull(m_EdFio2.GetData()),
					isNull(m_EdFio3.GetData()),
					isNull(m_EdFio4.GetData()),
					isNull(m_EdFio5.GetData()),
					isNull((DWORD)g_iFam));
        DBW.ExecSQL(str);
        DBW.Fetch();
        DBW.GetData(1, SQL_C_SLONG, &iRez, 4, &Ind);
        if( iRez == -1 )
        {
            DBW.GetData(2, SQL_C_CHAR, cText, 1024, &Ind);
            AfxMessageBox(cText);
        } else
		if( iRez == 0 )
		{
			DBW.GetData(2, SQL_C_UBIGINT, &m_retILK, 8, &Ind );
		}
    } else
    {
        str.Format("pTov_UpdateLKVag %I64u, '%s', %u, %s, %s, %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s",
                    m_qwILKVag,
                    nVan, 
                    m_RemKind.GetItemData(m_RemKind.GetCurSel()), 
                    cDateNachRem, 
                    Nin, 
                    cDateSbor,
                    g_iFam,
					cDatePerVNeisp,
					m_EdNLK.GetAsString(),
					m_EdKodSobst.GetAsString(),
					isNull(m_EdFio1.GetData()),
					isNull(m_EdFio2.GetData()),
					isNull(m_EdFio3.GetData()),
					isNull(m_EdFio4.GetData()),
					isNull(m_EdFio5.GetData()),
					isNull((DWORD)g_iFam));
    
        CString str2;
        str2 = str+ ", 1";

        int iRez;
		DBW.ExecSQL(str2);
        DBW.Fetch();
		cText[0] = 0;
		DBW.GetData(1, SQL_C_SLONG, &iRez, 4, &Ind);        
		DBW.GetData(2, SQL_C_CHAR, cText, 1024, &Ind);
		DBW.CloseCursor();
		DBW.ReallocHandle();

		if( iRez == -1 )
		{
			MessageBox(cText, "Внимание!", MB_OK);
			return;
		} else		
        if( iRez == 1)
        {    
			if( MessageBox(cText, "Внимание!", MB_YESNO ) == IDNO ) return;
            str2 = str + ",0";
            DBW.ExecSQL(str2);
		}
    }
    DBW.CloseCursor();
    DBW.ReallocHandle();

	m_nVan.GetWindowText(m_retNVag);
	m_RemKind.GetWindowText(m_retVRem);
	m_EdPdkKP.GetWindowText(m_retKPIn);
	m_EdVktKP.GetWindowText(m_retKPOut);
	m_EdNLK.GetWindowText(m_retNLK);
	m_DatNachRem.GetWindowText(m_retDatNachRem);
	m_DatSbor.GetWindowText(m_retDatRem);
	m_Dat4624.GetWindowText(m_retClose);


	CDlgWithAccelerators::OnOK();
}


void CDlgAddRemVag::OnCancel() 
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;	
	CDlgWithAccelerators::OnCancel();
}

void CDlgAddRemVag::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}

void CDlgAddRemVag::OnBnClickedSobst()
{
	CDlgSpravSmp Dlg;
	Dlg.DlgMode = 300;
	Dlg.Style = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_EdKodSobst.SetWindowText(Dlg.cRet);
	m_EdNameSobst.SetWindowText(Dlg.c_retText);
}

void CDlgAddRemVag::OnBnClickedButtonFio1()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 10;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFio1.SetWindowText(Dlg.cFio);
	m_EdFio1.SetData(Dlg.dwFio);
}

void CDlgAddRemVag::OnBnClickedButtonFio2()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 17;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFio2.SetWindowText(Dlg.cFio);
	m_EdFio2.SetData(Dlg.dwFio);
}

void CDlgAddRemVag::OnBnClickedButtonFio3()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 39;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFio3.SetWindowText(Dlg.cFio);
	m_EdFio3.SetData(Dlg.dwFio);
}

void CDlgAddRemVag::OnBnClickedButtonFio4()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 38;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFio4.SetWindowText(Dlg.cFio);
	m_EdFio4.SetData(Dlg.dwFio);
}

void CDlgAddRemVag::OnBnClickedButtonFio5()
{
	CDlgSpravKdr Dlg;
	Dlg.iFilter = 40;
	Dlg.DlgMode = 1;
	if( Dlg.DoModal() == IDCANCEL ) return;

	m_EdFio5.SetWindowText(Dlg.cFio);
	m_EdFio5.SetData(Dlg.dwFio);
}
