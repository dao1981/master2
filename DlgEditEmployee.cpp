// DlgEditEmployee.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgEditEmployee.h"
#include ".\dlgeditemployee.h"
#include "Dlgeditpass.h"
#include "DlgSetupUserMenuItems.h"
#include "DlgShowTOVKadr.h"

extern WORD g_iRang;

DWORD p_dwColors[6] = {RGB(208,255,255),
					   RGB(208,255,220),
					   RGB(243,210,208),
					   RGB(255,217,208),
					   RGB(255,227,247),
					   RGB(227,235,235)};

// CDlgEditEmployee dialog

IMPLEMENT_DYNAMIC(CDlgEditEmployee, CDlgWithAccelerators)
CDlgEditEmployee::CDlgEditEmployee(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CDlgEditEmployee::IDD, pParent)
{
//	id = 0;
	dwID = 0;
	iMode = 0;
	ZeroMemory(&OldState, sizeof( OldState ));
	ZeroMemory(&NewState, sizeof( NewState ));
	for( int i=0; i < 255; i++ )
		p_dwCheckMenuID[i] = 0;
	
	for( int i=0; i < 255; i++ )
		p_dwCheckMenuVal[i] = 0;
	dwStateCount = 0;
	cNewPassword[0] = 0;
	iNewRang = 0;
	bRangWasChanged = 0;
	iAutoUsed = 0;
	dwCheckMenuCount = 0;
	dwID_Arm = 0;
	iBeenStarted = 0;
	iTitleIndex = 0;
	iGotTitle = 0;
	cOldRang[0] = 0;
}

CDlgEditEmployee::~CDlgEditEmployee()
{
}

void CDlgEditEmployee::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Control(pDX, IDC_COMBO2, m_Combo2);
	DDX_Control(pDX, IDC_COMBO1, m_Combo);
	DDX_Control(pDX, IDC_EDIT2, m_Edit1);
	DDX_Control(pDX, IDC_EDIT3, m_Edit2);
//	DDX_Control(pDX, IDC_EDIT7, m_Edit3);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_BUTTON2, m_ButSetPass);
	DDX_Control(pDX, IDC_BUTTON1, m_ButSetupMnu);
	DDX_Control(pDX, IDC_COMBO3, m_ComboDpt);
	DDX_Control(pDX, IDC_BUTTON3, m_ButTovKadr);
}


BEGIN_MESSAGE_MAP(CDlgEditEmployee, CDlgWithAccelerators)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_CBN_SELCHANGE(IDC_COMBO1, OnCbnSelchangeCombo1)
	ON_CBN_SELCHANGE(IDC_COMBO2, OnCbnSelchangeCombo2)
//	ON_NOTIFY(NM_CLICK, IDC_LIST1, OnNMClickList1)
ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1)
ON_EN_KILLFOCUS(IDC_EDIT2, OnEnKillfocusEdit2)
ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
ON_EN_SETFOCUS(IDC_EDIT3, OnEnSetfocusEdit3)
ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedSetupMnu)
ON_BN_CLICKED(IDC_BUTTON3, &CDlgEditEmployee::OnBnClickedButton_TovKadr)
END_MESSAGE_MAP()


// CDlgEditEmployee message handlers

BOOL CDlgEditEmployee::OnInitDialog()
{
	CDialog::OnInitDialog();
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | LVS_SINGLESEL | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

	m_Edit1.ModifyStyle(0, WS_DISABLED, 0);
	m_Edit2.ModifyStyle(0, WS_DISABLED, 0);

	if( g_iRang < 4 && g_iFam != dwID )
	{
		m_ButSetPass.EnableWindow(FALSE);
		m_ButSetupMnu.EnableWindow(FALSE);
		
	} else
	{
		if( !dwID ) m_ButTovKadr.ModifyStyle(0, WS_VISIBLE, 0);
	}

	m_List.InsertColumn(0, "Квалификация");
	RECT p;
	m_List.GetWindowRect(&p);
	m_List.SetColumnWidth(0, p.right - p.left - 4);
	char cQ[512] = "";
	long Ind = 0;
	DWORD dwNum = 0;
	char cText[64] = "";

	m_Combo2.AddString("Все");
	m_Combo2.SetItemData(0,0);
	DBW.ExecSQL("exec pTov_GetQualifGroups");
	for( int i=1; (g_sqlret = DBW.Fetch()) != SQL_ERROR && g_sqlret != SQL_NO_DATA && i < 500; i++)
	{
		DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
		DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
		m_Combo2.AddString(cText);
		m_Combo2.SetItemData(i, dwNum);
	}
	DBW.CloseCursor();
	m_Combo2.SetCurSel(0);


	sprintf(cQ, "pTov_GetEmplQualification %u", dwID);
	DBW.ExecSQL(cQ);
	for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_ERROR && g_sqlret != SQL_NO_DATA && i < 500; i++ )
	{
		DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
		m_List.InsertItem(i, "");
		m_List.SetItemData(i, dwNum);
		OldState[i].dwID = dwNum;
		NewState[i].dwID = dwNum;

		cText[0] = 0;
		DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
		m_List.SetItemText(i, 0, cText);
		dwNum = 0;
		DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind);
		m_List.SetCheck(i, dwNum);
		OldState[i].bState = dwNum;
		NewState[i].bState = dwNum;
		dwStateCount++;
		DBW.GetData(4, SQL_C_ULONG, &dwNum, 4, &Ind);
		m_List.SetItemColor(i, RGB(0,0,0), p_dwColors[dwNum - 1]);
	}	
	DBW.CloseCursor();
	DBW.FillComboWithProfessions(&m_Combo);

	m_Edit1.iMode = 4;
    m_Edit1.lpEmpl = &EmplArr;
	if( !iMode ) dwID = 0;
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
    }
	m_Edit1.lpEmpl = &EmplArr;
    DBW.CloseCursor();

	sprintf(cQ, "pTov_GetAllParentDepts %u", g_iDep);
	DBW.ExecSQL(cQ);

	for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_ERROR && g_sqlret != SQL_NO_DATA && i < 500; i++)
	{
		DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
		DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
		m_ComboDpt.AddString(cText);
		m_ComboDpt.SetItemData(i, dwNum);
	}
	DBW.CloseCursor();
	m_Combo2.SetCurSel(0);	

	if( iMode )
	{
	    m_HeaderCtrl.SetTitleText("Регистрационная карта сотрудника");
	    m_HeaderCtrl.SetDescText("Корректировка регистрацонных данных сотрудника.");
		m_Edit1.iDontAskForFIO = 1;
	} else
	{
	    m_HeaderCtrl.SetTitleText("Регистрационная карта сотрудника");
	    m_HeaderCtrl.SetDescText("Добавление учетной записи сотрудника сотрудника.");

	}
	m_HeaderCtrl.SetIconHandle(AfxGetApp()->LoadIcon(IDI_USER));
	m_HeaderCtrl.Init(this);
	m_HeaderCtrl.MoveCtrls(this);


	if( iMode && dwID ) FillFormData();

	return TRUE;
}

void CDlgEditEmployee::FillFormData(void)
{
	char cQ[512] = "";
	char cText[64] = "";
	DWORD dwNum = 0;
	long Ind = 0;
	sprintf(cQ, "pTov_GetEmployee %u", dwID);
	DBW.ExecSQL(cQ);
	DBW.Fetch();

	DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
	if( Ind != -1 ) 
	{
		m_Edit1.SetWindowText(cText);
		m_Edit1.SetData(dwID);
	}

	DBW.GetData(2, SQL_C_ULONG, &dwTab, 4, &Ind);
	if( Ind != -1 )
	{
		itoa(dwTab, cText, 10);
		m_Edit2.SetWindowText(cText);
	}

	strcpy(cOldRang, "0");
	DBW.GetData(3, SQL_C_CHAR, cOldRang, 64, &Ind);
//	if( Ind != -1 ) m_Edit3.SetWindowText(cText);

	DBW.GetData(4, SQL_C_ULONG, &dwNum, 4, &Ind);
	DWORD dwIDepEmpl = 0;
	DBW.GetData(5, SQL_C_ULONG, &dwIDepEmpl, 4, &Ind);
	DBW.CloseCursor();

	for( int i=0; i < m_Combo.GetCount(); i++ )
	{
		if( m_Combo.GetItemData(i) == dwNum ) 
		{
			m_Combo.SetCurSel(i);
			break;
		}
	}

	for( int i=0; i < m_ComboDpt.GetCount(); i++ )
	{
		if( m_ComboDpt.GetItemData(i) == dwIDepEmpl ) 
		{
			m_ComboDpt.SetCurSel(i);
			break;
		}
	} 
/*
	if( !m_Edit3.GetWindowTextLength() )
	{
		m_Combo.GetWindowText(cText, 64);
		m_Edit3.SetWindowText(cText);
	}
*/
}

void CDlgEditEmployee::OnCbnSelchangeCombo1()
{
	char cText[64] = "";
	m_Combo.GetWindowText(cText, 64);
//	m_Edit3.SetWindowText(cText);
}

void CDlgEditEmployee::OnCbnSelchangeCombo2()
{
	for( int i=0; i < m_List.GetItemCount(); i++ )
	{
		for( DWORD j = 0; j < dwStateCount; j++ )
		{
			if(NewState[j].dwID == m_List.GetItemData(i))
				NewState[j].bState = m_List.GetCheck(i);
		}
	}

	DWORD dwGroupID = m_Combo2.GetItemData(m_Combo2.GetCurSel());
	char cText[64] = "";
	DWORD dwNum = 0;
	long	Ind = 0;
	char cQ[256] = "";
	m_List.DeleteAllItems();
	sprintf(cQ, "pTov_GetEmplQualification %u, %s", dwID, isNull(dwGroupID));
	DBW.ExecSQL(cQ);
	for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_ERROR && g_sqlret != SQL_NO_DATA && i < 500; i++ )
	{
		DBW.GetData(1, SQL_C_ULONG, &dwNum, 4, &Ind);
		m_List.InsertItem(i, "");
		m_List.SetItemData(i, dwNum);
		cText[0] = 0;
		DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind);
		m_List.SetItemText(i, 0, cText);
		dwNum = 0;
		DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind);
		m_List.SetCheck(i, dwNum);
		DBW.GetData(4, SQL_C_ULONG, &dwNum, 4, &Ind);
		m_List.SetItemColor(i, RGB(0,0,0), p_dwColors[dwNum - 1]);
	}
	DBW.CloseCursor();
	for( int i=0; i < m_List.GetItemCount(); i++ )
	{		
		for( DWORD j = 0; j < dwStateCount; j++ )
		{
			if(NewState[j].dwID == m_List.GetItemData(i))
				m_List.SetCheck(i, NewState[j].bState);
		}
	}
}

void CDlgEditEmployee::OnBnClickedOk()
{
	for( int i=0; i < m_List.GetItemCount(); i++ )
	{
		for( DWORD j = 0; j < dwStateCount; j++ )
		{
			if(NewState[j].dwID == m_List.GetItemData(i))
				NewState[j].bState = m_List.GetCheck(i);
		}
	}

	char cQ[512] = "";
	char cFIO[64] = "";
	char cTabNum[64] = "";
	long Ind = 0;
	m_Edit1.GetWindowText(cFIO, 64);
	m_Edit2.GetWindowText(cTabNum,64);

	if( m_Combo.GetCurSel() == -1 )
	{
		AfxMessageBox("Не указана должность сотрудника!");
		m_Combo.SetFocus();
		return;
	}
	if( !cTabNum[0] )
	{
		AfxMessageBox("Не указан табельный номер сотрудника!");
		m_Edit2.SetFocus();
		return;
	}
	
	DWORD dwNewIDep = m_ComboDpt.GetItemData(m_ComboDpt.GetCurSel());
	
	if( iMode )
	{
		sprintf(cQ, "pTov_UpdateEmployee %u, %s, %s, %s, %s, %s",
				dwID,
				isNull(cFIO),
				cTabNum,
				isNull(m_Combo.GetItemData(m_Combo.GetCurSel())),
				isNull(dwNewIDep),
				isNull(dwID_Arm));
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_ULONG, &dwID, 4, &Ind);
		DBW.CloseCursor();
	} else
	{
		sprintf(cQ, "pTov_UpdateEmployee %s, %s, %s, %s, %s, %s",
				isNull(m_Edit1.GetData()),
				isNull(cFIO),
				cTabNum,
				isNull(m_Combo.GetItemData(m_Combo.GetCurSel())),
				isNull(dwNewIDep),
				isNull(dwID_Arm));
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_ULONG, &dwID, 4, &Ind);
		DBW.CloseCursor();
//		dwID = m_Edit1.GetData();]
		if( dwID == 0 && m_Edit1.GetData() )
		{
			dwID = m_Edit1.GetData();
		} else
			m_Edit1.SetData(dwID);
	}

	for( DWORD i=0; i < dwStateCount; i++ )
	{
		if( OldState[i].bState != NewState[i].bState )
		{
			sprintf(cQ, "pTov_SetEmployeeQual %u, %u, %u",
					dwID,
					NewState[i].dwID,
					!NewState[i].bState);
			DBW.ExecSQL(cQ);
			DBW.CloseCursor();
		}
	}

	if( cNewPassword[0] || bRangWasChanged )
	{
		sprintf(cQ, "pTov_SetEmployeePassword %u, '%s', %u", dwID, cNewPassword, iNewRang);
		DBW.ExecSQL(cQ);
		DBW.CloseCursor();
	}

	if( dwCheckMenuCount )
	{
		char cScript[5000] = "";
		strcpy(cScript, "begin tran\n");
		for( int i=0; i < dwCheckMenuCount; i++ )
		{
			sprintf(cScript, "%s\nexec pTov_SetEmployeeQual %u, %u, %u", 
				cScript,
				dwID,
				p_dwCheckMenuID[i],
				!p_dwCheckMenuVal[i]);			
		}
		strcat(cScript, "\ncommit tran");
		DBW.ExecSQL(cScript);
		DBW.CloseCursor();
	}

	sprintf(cQ, "exec pTov_UpdateEmployeeIDep %s, %s", 
			isNull(dwID),
			isNull(m_ComboDpt.GetItemData(m_ComboDpt.GetCurSel())));
	DBW.ExecSQL(cQ);
	DBW.CloseCursor();

	OnOK();
}

void CDlgEditEmployee::OnBnClickedCheck1()
{
	for( int i=0; i < m_List.GetItemCount(); i++ )
		m_List.SetCheck(i, m_Check1.GetCheck());
}

void CDlgEditEmployee::OnEnKillfocusEdit2()
{
	if( iMode ) return;
    char cQ[128] = "";
    char cText[64] = "";
    int  lID = dwID;
    m_Edit1.GetWindowText(cText, 64);
    if( !dwID )
    {
        dwID = EmplArr.GetIDbyFIO(cText);
        if( dwID )
        {
            itoa(EmplArr.GetTabNumByID(dwID), cText, 10);
            m_Edit2.SetWindowText(cText);
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
    DWORD dwNum = 0;
	DWORD dwKadrIDep = 0;
	long Ind = 0;
    if( dwID && lID)
    {
        char cMess[255] = "";
        sprintf(cMess, "В глобальном списке сотрудников уже есть сотрудник с ФИО2 \"%s\".\nДобавить его в список сотрудников МКЦ?", cText);
        if( MessageBox(cMess, "Внимание", MB_YESNO) == IDYES )
        {
/*            itoa(EmplArr.GetTabNumByID(dwID), cText, 10);
            m_Edit2.EnableWindow(FALSE);
            m_Edit3.SetWindowText(cText);*/
			sprintf( cQ, "pTov_GetEmplInfo2 %u", dwID );
			DBW.ExecSQL(cQ);
			g_sqlret = DBW.Fetch();
			if( g_sqlret != SQL_NO_DATA && g_sqlret != SQL_ERROR )
			{
				DBW.GetData(2, SQL_C_CHAR, cText, 64, &Ind );
				if( Ind != -1 ) m_Edit2.SetWindowText(cText);
				DBW.GetData(3, SQL_C_ULONG, &dwNum, 4, &Ind);
				if( Ind != -1 )
				{
					for( int i=0; i < m_Combo.GetCount(); i++ )
					{
						if( m_Combo.GetItemData(i) == dwNum ) m_Combo.SetCurSel(i);
					}
				}
				DBW.GetData(4, SQL_C_ULONG, &dwKadrIDep, 4, &Ind);
				if( Ind != -1 )
				{
					for( int i=0; i < m_ComboDpt.GetCount(); i++ )
					{
						if( m_ComboDpt.GetItemData(i) == dwKadrIDep ) m_ComboDpt.SetCurSel(i);
					}
				}
/*				DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
				if( Ind != -1 ) m_Edit3. SetWindowText(cText);
				DBW.GetData(5, SQL_C_ULONG, */
			}
			DBW.CloseCursor();
            m_Edit2.SetFocus();
        }
        else
            dwID = 0;
    }
}

void CDlgEditEmployee::OnBnClickedButton2()
{
	CDlgEditPass Dlg;
	if( !iMode ) Dlg.Mode = 1;
	else Dlg.Mode = 0;
	if( g_iFam == dwID ) Dlg.m_iRang = g_iRang;
	Dlg.iFam = dwID;
	strcpy(Dlg.cOldRang, cOldRang);
	if( Dlg.DoModal() == IDCANCEL) return;
	
//	Dlg.m_iRang = atoi(cOldRang);

	if( Dlg.m_cPass1 == "" )
	{
		AfxMessageBox("Пароль не может быть пустым!");
		return;
	}
	bRangWasChanged = Dlg.bRangWasChanged;
	strcpy(cNewPassword, Dlg.m_cPass1);
	iNewRang = Dlg.iRang;
}

void CDlgEditEmployee::OnCancel()
{
    if( g_conf_MessageOnCancel && MessageBox("Закрыть форму без сохранения данных?", "Мастер", MB_YESNO) == IDNO ) return;	

	CDialog::OnCancel();
}

void CDlgEditEmployee::OnEnSetfocusEdit3()
{
	DWORD x = m_Edit1.GetData();
	if( iMode ) return;
	if( !m_Edit1.GetData() )
	{
		m_Edit2.SetWindowText("");
//		m_Edit3.SetWindowText("");
		m_Combo.SetCurSel(-1);		
		return;
	}
	char cQ[128] = "";
	char cText[64] = "";
	DWORD dwNum = 0;
	DWORD dwKadrIDep = 0;
	long Ind = 0;
	sprintf( cQ, "pTov_GetEmplInfo2 %u", m_Edit1.GetData() );
	DBW.ExecSQL(cQ);
	g_sqlret = DBW.Fetch();
	if( g_sqlret != SQL_NO_DATA && g_sqlret != SQL_ERROR )
	{
		DBW.GetData(2, SQL_C_ULONG, &dwNum, 4, &Ind);
		if( Ind != -1 )
		{
			for( int i=0; i < m_Combo.GetCount(); i++ )
			{
				if( m_Combo.GetItemData(i) == dwNum ) m_Combo.SetCurSel(i);
			}
		}
		DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
		if( Ind != -1 ) m_Edit2.SetWindowText(cText);
		m_Combo.GetWindowText(cText, 64);

		DBW.GetData(4, SQL_C_ULONG, &dwKadrIDep, 4, &Ind);
		if( Ind != -1 )
		{
			for( int i=0; i < m_ComboDpt.GetCount(); i++ )
			{
				if( m_ComboDpt.GetItemData(i) == dwKadrIDep ) m_ComboDpt.SetCurSel(i);
			}
		}

//		m_Edit3.SetWindowText(cText);

/*				DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind );
				if( Ind != -1 ) m_Edit3. SetWindowText(cText);
				DBW.GetData(5, SQL_C_ULONG, */
	}
	DBW.CloseCursor();
	iAutoUsed = 1;
}

void CDlgEditEmployee::OnBnClickedSetupMnu()
{
	CDlgSetupUserMenuItems Dlg;
	Dlg.dwID = dwID;
	Dlg.p_dwCheckMenuID = p_dwCheckMenuID;
	Dlg.p_dwCheckMenuVal = p_dwCheckMenuVal;
	Dlg.dwCount = dwCheckMenuCount;
	Dlg.iBeenStarted = iBeenStarted;

	if( iGotTitle )
	{
		Dlg.iTitleIdx = iTitleIndex;
		Dlg.iGotTitle = 1;
	}

	if( Dlg.DoModal() == IDCANCEL ) 
	{
		return;
	}
	iBeenStarted = 1;
	dwCheckMenuCount = Dlg.dwCount;
	dwID_Arm = Dlg.dwID_Arm;
	if( Dlg.iGotTitle )
	{
		iTitleIndex = Dlg.iTitleIdx;
		iGotTitle = 1;
	}

}

void CDlgEditEmployee::OnBnClickedButton_TovKadr()
{
	CDlgShowTOVKadr Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;
	dwID = Dlg.dwIFam_Ret;
	FillFormData();
}
