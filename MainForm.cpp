// MainForm.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "MainForm.h"
#include "AuthDlg.h"
#include "PrintableDlg.h"
#include "NewMenu.h"
#include "DlgMsg4624_Main.h"
#include "DlgMsg2955.h"
#include "DlgMsg2956.h"
#include "DlgMsg2957Main.h"
#include "DlgMsg2958.h"
#include "DlgSetupTO.h"
#include "DlgWheelsToVan.h"
#include "DlgMsg4624Log.h"
#include "DlgSprav1.h"
#include "DlgPeresKP.h"
#include "DlgRemVag.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#ifndef PTO_KP_ED_ID
#define PTO_KP_ED_ID 30001
#define PTO_KP_ED_RASH_ID 30002
#define ER_PR_ID 30003
#define PTO_PRIH_VED 30004
#define PTO_RASH_VED 30005
#define PTO_REM_VAG 30006
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainForm dialog
extern CMasterApp theApp;
extern HWND g_hDlgWnd;
extern DWORD g_dwCurDlg;
extern CPrintableDlg *g_pPrnDlg;
extern int g_iNoPPT;
extern int g_iMessageNumber;
extern int g_iDisplayMnu2730Req;
extern SYSTEMTIME g_stMessage2955Date;
extern SYSTEMTIME g_stMessage2956Date;
extern SYSTEMTIME g_stMessage2957Date;
extern CString g_strArmTitle;
extern int g_iDisplayServerMessage;

CMainForm::CMainForm(CWnd* pParent /*=NULL*/)
	: CDlgWithAccelerators(CMainForm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMainForm)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
    m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	bMsg4624Only = 0;
}


void CMainForm::DoDataExchange(CDataExchange* pDX)
{
	CDlgWithAccelerators::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMainForm)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMainForm, CDlgWithAccelerators)
	//{{AFX_MSG_MAP(CMainForm)
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
    ON_COMMAND(ID_FILE_PRINT, OnPrintSome)
END_MESSAGE_MAP()
    

/////////////////////////////////////////////////////////////////////////////
// CMainForm message handlers
extern WORD g_iRang;

int RemoveUnusedMenu(CMenu *m)
{
	CMenu *mSub = NULL;
	int num = m->GetMenuItemCount();
	CString name;
	MENUITEMINFO info;
	ZeroMemory(&info,sizeof(info));
	int iItemCount = 0;
	if( !num )
		return 9; //Меню пустое, удалить
	for (int i=0; i<num; i++)
	{
		m->GetMenuString (i, name, MF_BYPOSITION); 
/*		if(name.Compare (lpszSubMenuName) == 0)
		{
			m->RemoveMenu(i, MF_BYPOSITION);
			return 1;
		}*/
		int ret = 0;
		mSub = m->GetSubMenu(i);
		if( mSub ) ret = RemoveUnusedMenu(mSub);
		else iItemCount++;
		if( ret == 9 ) 
		{
			m->RemoveMenu(i, MF_BYPOSITION);		
			i--;
			num--;
		} else
		if( ret == 1 ) iItemCount++;
	}
	if( iItemCount > 0 ) return 1;
	return 9;
}
extern int g_iNeedSetupPath;
extern int g_iShowServerNameInWindowHeader;
extern CString g_strServerName;
extern int g_iMessageLogOnly;
extern int g_iArmTitleFromINI;

extern DWORD g_dwTDep;

BOOL CMainForm::OnInitDialog() 
{
	CDlgWithAccelerators::OnInitDialog();
/*    m_hIcon = ::LoadIcon(NULL, MAKEINTRESOURCE(IDR_MAINFRAME));*/	
    char cLook[64] = "";
    int rez = GetPrivateProfileString(
                        "LOOK",
                        "MenuLook",
                        NULL,
                        cLook,
                        64,
                        "./master.ini");

	CNewMenu *m = new CNewMenu;
    m->LoadMenu(IDR_MNU);

	if( g_iArmTitleFromINI )
	{
		SetWindowText(g_strArmTitle);
	} else
	if( g_iShowServerNameInWindowHeader )
	{
		SetWindowText(g_strArmTitle + CString(" ") + g_strDepoName + CString(" --- [ ") + g_strServerName + CString(" ]"));
	} else
		SetWindowText(g_strArmTitle + CString(" ") + g_strDepoName);

	if( g_iNoPPT )
	{
		m->RemoveMenu(0, MF_BYPOSITION);
	}	

/*
	if( !g_iDisplayMnu2730Req )
	{
		m->RemoveMenu(13, MF_BYPOSITION);
	}
*/
    SetMenu(m);
    if( !strcmp(cLook, "XP") )
    {
        CNewMenu::SetMenuDrawMode(CNewMenu::STYLE_XP);
    } else
        CNewMenu::SetMenuDrawMode(CNewMenu::STYLE_ORIGINAL_NOBORDER);
	if( g_dwTypeDep != 3)
	{
		m->EnableMenuItem(ID_MENU_SELECT_DEPO, FALSE);
	}

	SetIcon(m_hIcon, FALSE);		// Set small icon
    SetIcon(m_hIcon, TRUE);			// Set big icon

	if( g_iDisplayServerMessage )
	{
		char cQ[64] = "";
		char cMess[1024] = "";
		long Ind = 0;
		sprintf( cQ, "pTov_GetStartInf %d", g_iFam );
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_CHAR, cMess, 1024, &Ind );
		DBW.CloseCursor();
		if( Ind != -1 && cMess[0] != 0 )
		{
			AfxMessageBox(cMess);
		}
	}

	if( bMsg4624Only )
	{
		if( g_iDep )
		{
			DBW.GetDepoName(g_iDep, g_strDepoName, g_strDepoSName, g_dwTDep, g_dwDepoGruzPas);		
		}
		this->ShowWindow(SW_HIDE);
		if( g_iMessageNumber == 4624 )
		{
			CDlgMsg4624_Main Dlg4624;
			strcpy(Dlg4624.cVagNum32, cVagNum32);
			Dlg4624.stDat4624 = stRemDat;
			Dlg4624.DoModal();
		} else
		if( g_iMessageNumber == 2955 )
		{
			CDlgMsg2955 Dlg;
			Dlg.stRptDate = g_stMessage2955Date;
			Dlg.DoModal();
		} else
		if( g_iMessageNumber == 2956 )
		{
			CDlgMsg2956 Dlg;
			Dlg.stDate = g_stMessage2956Date;
			Dlg.DoModal();
		} else
		if( g_iMessageNumber == 2957 )
		{
			CDlgMsg2957Main Dlg;
			Dlg.stDate = g_stMessage2957Date;
			Dlg.DoModal();
		} else
		if( g_iMessageNumber == 2958 )
		{
			CDlgMsg2958 Dlg;
			Dlg.stDat = g_stMessage2957Date;
			Dlg.DoModal();
		} else
		if( g_iMessageNumber == PTO_KP_ED_ID )
		{
			CDlgWheelsToVan Dlg;
			Dlg.bFromPTO = 1;
			Dlg.DoModal();
		} else
		if( g_iMessageNumber == PTO_KP_ED_RASH_ID )
		{
			CDlgWheelsToVan Dlg;
			Dlg.iMode = 1;
			Dlg.bFromPTO = 1;
			Dlg.DoModal();
		} else
		if( g_iMessageNumber == ER_PR_ID )
		{
			g_iRang = 5;
			CDlgSprav1 Dlg;
			Dlg.DoModal();
		} else
		if( g_iMessageNumber == PTO_PRIH_VED )
		{
			CDlgPeresKP Dlg;
			Dlg.iRecieveMode = 1;
			Dlg.DoModal();
		} else
		if( g_iMessageNumber == PTO_RASH_VED )
		{
			CDlgPeresKP Dlg;
			Dlg.iRecieveMode = 0;
			Dlg.DoModal();
		} else
		if( g_iMessageNumber == PTO_REM_VAG )
		{
			CDlgRemVag Dlg;
			Dlg.DoModal();
		} else
		if( g_iMessageLogOnly )
		{			
			CDlgMsg4624Log Dlg;
			theApp.m_pMainWnd = &Dlg;
			Dlg.iMain = 1;
			Dlg.strWindowName = g_strArmTitle + " - Журнал сообщений (" + g_strDepoName + ")" ;
			Dlg.DoModal();
		}
		OnCancel();
		return TRUE;
	} else
	{
		if( g_iNeedSetupPath )
		{
			AfxMessageBox("Необходимо настроить пути для хранения сообщений!");
			CDlgSetupTO Dlg;
			Dlg.DoModal();
		}
		if( g_iRang < 4 )
		{
			char cQ[512] = "";
			sprintf(cQ, "pTov_GetMenuConfig %u", g_iFam);
			DBW.ExecSQL(cQ);
			DWORD dwMenuID = 0;
			long Ind = 0;
			for( int i=0; (g_sqlret = DBW.Fetch()) != SQL_ERROR && g_sqlret != SQL_NO_DATA && i < 500; i++)
			{
				DBW.GetData(1, SQL_C_ULONG, &dwMenuID, 4, &Ind);
				if( Ind != -1 )
				{
					m->RemoveMenu(dwMenuID, MF_BYCOMMAND);
				}
			}
			DBW.CloseCursor();
			m->RemoveMenu(32792, MF_BYCOMMAND); //нельзя менять себе пароль
		}
		CNewMenu *mSub = NULL;
		RemoveUnusedMenu(m);
	}
	return TRUE;
}

void CMainForm::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
    if( nChar == 27 ) 
    {
        AfxMessageBox("Catched");
        return;
    }
	CDlgWithAccelerators::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMainForm::OnCancel()
{
//    return;
    CDlgWithAccelerators::OnCancel();
}

void CMainForm::OnPrintSome()
{
/*    AfxMessageBox("TRY!");
    ::SendMessage(g_hDlgWnd, ID_FILE_PRINT, NULL, NULL);*/
}

BOOL CMainForm::OnCommand(WPARAM wParam, LPARAM lParam) 
{
    if( wParam == ID_FILE_PRINT && g_dwCurDlg)
    {
//        ::SendMessage(g_hDlgWnd, ID_FILE_PRINT, wParam, lParam);
        if(g_pPrnDlg) g_pPrnDlg->OuterPrint();
    }
	return CDlgWithAccelerators::OnCommand(wParam, lParam);
}
