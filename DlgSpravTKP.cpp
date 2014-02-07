// DlgSpravTKP.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgSpravTKP.h"
#include "DlgEditKP.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#include <sqlext.h>
#include ".\dlgspravtkp.h"

extern SQLRETURN    g_sqlret;
extern CMasterApp   theApp;
extern DWORD        g_iDep;
/////////////////////////////////////////////////////////////////////////////
// CDlgSpravTKP dialog


CDlgSpravTKP::CDlgSpravTKP(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgSpravTKP::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgSpravTKP)
	//}}AFX_DATA_INIT
    DlgMode = 0;
    cQuery[0] = 0;
}


void CDlgSpravTKP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgSpravTKP)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_BUTTON1, but1);
	DDX_Control(pDX, IDC_BUTTON2, but2);
	DDX_Control(pDX, IDC_BUTTON3, but3);
	DDX_Control(pDX, IDC_STATIC_X, m_Lab);
}


BEGIN_MESSAGE_MAP(CDlgSpravTKP, CDialog)
	//{{AFX_MSG_MAP(CDlgSpravTKP)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgSpravTKP message handlers
extern WORD g_iRang;
BOOL CDlgSpravTKP::OnInitDialog() 
{
	CDialog::OnInitDialog();
	m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );
    DWORD dwCount = 0;
    char  cName[64] = "";
	sprintf(cQuery, "pTov_GetAllTypeKP %u", g_iDep); 
    DBW.ExecSQL(cQuery);
    DBW.SetListHeader(&m_List);
    UpdateListByQuery();
    DBW.CloseCursor();
	if( g_iRang < 3 )
	{
//		m_Lab.ModifyStyle(WS_VISIBLE, 0);
		but1.ModifyStyle(WS_VISIBLE, 0);
//		but2.ModifyStyle(WS_VISIBLE, 0);
		but3.ModifyStyle(WS_VISIBLE, 0);
	}
	return TRUE; 
}

long strtohextoval(SQL_NUMERIC_STRUCT scNum)
{
    long val=0,value=0;
    int i=1,last=1,current;
    int a=0,b=0;

        for(i=0;i<=15;i++)
        {
		    current = (int) scNum.val[i];
			a= current % 16; //Obtain LSD
			b= current / 16; //Obtain MSD
				
			value += last* a;	
			last = last * 16;	
			value += last* b;
			last = last * 16;	
  		}
 	 return value;
} 

void CDlgSpravTKP::UpdateListByQuery()
{
//    DBW.SetListHeader(&m_List);
    DBW.UpdateListByHandle(&m_List);
/*
    DWORD dwCount = 0;
//    SQL_NUMERIC_STRUCT nsNum;
    SQLHDESC h_desc = NULL;
    char  cText[512] = "";
    DWORD  dwNum = 0;
    long  Ind = 0;
    long  lNum = 0;
//    long a, b;
    char  cRez[512] = "";
    m_List.DeleteAllItems();

    SQLColAttribute(g_hsqlstmt, 0, SQL_DESC_COUNT, NULL, 0, NULL, &dwCount);
    for(DWORD j=0; (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR && j < 1024; j++ )
    {
        for( WORD i=0; i < dwCount; i++ )
        {
            SQLColAttribute(g_hsqlstmt, i + 1, SQL_DESC_TYPE_NAME, cText, 64, NULL, NULL);
            SQLColAttribute(g_hsqlstmt, i + 1, SQL_DESC_TYPE, NULL, 0, NULL, &dwNum);
            DBW.GetData( i + 1, SQL_C_CHAR, cText, 128, &Ind);
/*
            m_List.SetItemText(j, i, cText);
            sprintf(cRez, "%s (%d)", cText, dwNum);
            if( dwNum == 2 ) // numeric
            {
                SQLGetStmtAttr(g_hsqlstmt, SQL_ATTR_APP_ROW_DESC,&h_desc, 0, NULL);
                SQLSetDescField (h_desc,i + 1,SQL_DESC_TYPE,(VOID*)SQL_C_NUMERIC,0);
                SQLSetDescField (h_desc,i + 1,SQL_DESC_PRECISION,(VOID*) 6,0);
                SQLSetDescField (h_desc,i + 1,SQL_DESC_SCALE,(VOID*) 3,0);
                a=b=sizeof(nsNum);
                memset(nsNum.val, 0, 16);
                DBW.GetData( i + 1, SQL_ARD_TYPE, &nsNum, 19, &Ind);
                Ind = sizeof(nsNum);
                long lVal = 0;
                double rez = 0;
                int divisor = 1;
                lVal = strtohextoval(nsNum);
                if( nsNum.scale > 0 )
                    for(int x=0; x < nsNum.scale; x++ )
                        divisor *= 10;
                rez = (double)lVal/(double)divisor;
                if( !nsNum.sign ) rez = -rez;

                if( nsNum.scale > 1 )
                {
                    sprintf(cText, "%6.2f", rez);
                }
                else
                    itoa(lVal, cText, 10);
            } 
            else
                DBW.GetData( i + 1, SQL_C_CHAR, cText, 128, &Ind);
*/
/*
            if( Ind != -1 ) 
                if( i == 0 )
                    m_List.InsertItem(LVIF_TEXT | LVIF_STATE, j, cText, 0, LVIS_SELECTED, 0, 0);
                else
                    m_List.SetItemText(j, i, cText);
        }
    }
    */
}

// Добавление
void CDlgSpravTKP::OnButton1() 
{
    CDlgEditKP Dlg;
    InitEditForm(&Dlg);
    if( Dlg.DoModal() == IDCANCEL ) return;
    RefreshList();
}

// Корректировка справочника
void CDlgSpravTKP::OnButton2()
{
    if( m_List.GetSelectionMark() == -1 ) return;
    char cText[64] = "";
    CDlgEditKP Dlg;
    InitEditForm(&Dlg);
    Dlg.iMode = 1;
    m_List.GetItemText(m_List.GetSelectionMark(), 58, cText, 64);
    Dlg.dwITKP = atoi(cText);
    m_List.GetItemText(m_List.GetSelectionMark(), 59, cText, 64);
    Dlg.dwTREM = atoi(cText);
    if( Dlg.DoModal() == IDCANCEL ) return;
    RefreshList();
}

//Удаление записи
void CDlgSpravTKP::OnButton3() 
{
    if( m_List.GetSelectionMark() == -1 ) return;
    char cMess[128] = "";
    char cType[32] = "", cRem[32] = "";
    m_List.GetItemText(m_List.GetSelectionMark(), 0, cType, 32);
    m_List.GetItemText(m_List.GetSelectionMark(), 1, cRem, 32);
    sprintf(cMess, "Вы уверены, что хотите удалить запись размеров КП %s при ремонте %s?",
            cType,
            cRem);
    if( ::MessageBox(NULL, cMess, "Внимание", MB_YESNO | MB_ICONINFORMATION) == IDNO ) return;
    char cQ[128] = "";
    m_List.GetItemText(m_List.GetSelectionMark(), 58, cType, 64);
    m_List.GetItemText(m_List.GetSelectionMark(), 59, cRem, 64);
    sprintf(cQ, "pTov_DeleteDopusk %s, %s, %u", cType, cRem, g_iDep);
    DBW.ExecSQL(cQ);
    DBW.CloseCursor();
    RefreshList();
}

void CDlgSpravTKP::RefreshList()
{
	sprintf(cQuery, "pTov_GetAllTypeKP %u", g_iDep);
    DBW.ExecSQL(cQuery);
    UpdateListByQuery();
    DBW.CloseCursor();
}

void CDlgSpravTKP::InitEditForm(CDlgEditKP *Dlg)
{
    //xxx
    Dlg->m_Edit1.iMode = Dlg->m_Edit2.iMode = Dlg->m_Edit7.iMode = 2;
    Dlg->m_Edit1.Prec = Dlg->m_Edit2.Prec = Dlg->m_Edit7.Prec = 3;
    //xx
    Dlg->m_Edit5.iMode = Dlg->m_Edit3.iMode = Dlg->m_Edit16.iMode = 2;
    Dlg->m_Edit5.Prec = Dlg->m_Edit3.Prec = Dlg->m_Edit16.Prec = 2;

    // init here xxx.xx
    Dlg->m_Edit20.iMode = Dlg->m_Edit19.iMode = Dlg->m_Edit17.iMode = Dlg->m_Edit18.iMode = 2;
    Dlg->m_Edit20.Prec = Dlg->m_Edit19.Prec = Dlg->m_Edit17.Prec = Dlg->m_Edit18.Prec = 3;
    Dlg->m_Edit20.Scale = Dlg->m_Edit19.Scale = Dlg->m_Edit17.Scale = Dlg->m_Edit18.Scale = 2;
    // and here is xx.x
    Dlg->m_Edit21.iMode = Dlg->m_Edit22.iMode =  Dlg->m_Edit23.iMode = Dlg->m_Edit24.iMode = Dlg->m_Edit25.iMode =  Dlg->m_Edit26.iMode = 2;
    Dlg->m_Edit21.Prec = Dlg->m_Edit22.Prec =  Dlg->m_Edit23.Prec = Dlg->m_Edit24.Prec = Dlg->m_Edit25.Prec =  Dlg->m_Edit26.Prec = 2;
    Dlg->m_Edit21.Scale = Dlg->m_Edit22.Scale =  Dlg->m_Edit23.Scale = Dlg->m_Edit24.Scale = Dlg->m_Edit25.Scale =  Dlg->m_Edit26.Scale = 1;
    // and here is x.x
    Dlg->m_Edit27.iMode =  Dlg->m_Edit28.iMode = 2;
    Dlg->m_Edit27.Prec =  Dlg->m_Edit28.Prec = 1;
    Dlg->m_Edit27.Scale =  Dlg->m_Edit28.Scale = 1;
    // xxxx
    Dlg->m_Edit29.iMode = Dlg->m_Edit30.iMode = 2;
    Dlg->m_Edit29.Prec = Dlg->m_Edit30.Prec = 4;
    //this is xxx.xxx
    Dlg->m_Edit31.iMode = Dlg->m_Edit32.iMode = 
    Dlg->m_Edit33.iMode = Dlg->m_Edit34.iMode = 
    Dlg->m_Edit35.iMode = Dlg->m_Edit36.iMode = 
    Dlg->m_Edit37.iMode = Dlg->m_Edit38.iMode = 2;

    Dlg->m_Edit31.Prec =  Dlg->m_Edit32.Prec =
    Dlg->m_Edit33.Prec =  Dlg->m_Edit34.Prec =
    Dlg->m_Edit35.Prec =  Dlg->m_Edit36.Prec =
    Dlg->m_Edit37.Prec =  Dlg->m_Edit38.Prec = 3;

    Dlg->m_Edit31.Scale =  Dlg->m_Edit32.Scale =
    Dlg->m_Edit33.Scale =  Dlg->m_Edit34.Scale =
    Dlg->m_Edit35.Scale =  Dlg->m_Edit36.Scale =
    Dlg->m_Edit37.Scale =  Dlg->m_Edit38.Scale = 3;
    //and here is x.xxx
    Dlg->m_Edit39.iMode = Dlg->m_Edit40.iMode = 2;
    Dlg->m_Edit39.Prec = Dlg->m_Edit40.Prec = 1;
    Dlg->m_Edit39.Scale = Dlg->m_Edit40.Scale = 3;
    //x.xxx again
    Dlg->m_Edit41.iMode = Dlg->m_Edit42.iMode = 2;
    Dlg->m_Edit41.Prec = Dlg->m_Edit42.Prec = 1;
    Dlg->m_Edit41.Scale = Dlg->m_Edit42.Scale = 3;
    //x.xx
    Dlg->m_Edit44.iMode = Dlg->m_Edit45.iMode = 2;
    Dlg->m_Edit44.Prec = Dlg->m_Edit45.Prec = 1;
    Dlg->m_Edit44.Scale = Dlg->m_Edit45.Scale = 2;
    //this is xxx.xxx again
    Dlg->m_Edit47.QInit(33);
    Dlg->m_Edit48.QInit(33);
    Dlg->m_Edit49.QInit(33);
    Dlg->m_Edit50.QInit(33);
    Dlg->m_Edit51.QInit(33);
    Dlg->m_Edit52.QInit(33);
    Dlg->m_Edit53.QInit(13);
    Dlg->m_Edit54.QInit(13);
    //x.xx
    Dlg->m_Edit57.QInit(32);
    Dlg->m_Edit58.QInit(32);

    Dlg->m_Edit55.iMode = Dlg->m_Edit56.iMode = 2;


    Dlg->m_Edit55.Prec = Dlg->m_Edit56.Prec = 1;

    Dlg->m_Edit55.Scale = Dlg->m_Edit56.Scale = 2;
    // xxx.
    Dlg->m_Edit59.QInit(22);
    Dlg->m_Edit60.QInit(22);
    // xx.
    Dlg->m_Edit61.QInit(32);
    Dlg->m_Edit62.QInit(32);
    //xxx.xx
    Dlg->m_Edit63.QInit(13);
    Dlg->m_Edit64.QInit(13);
    Dlg->m_Edit67.iMode = Dlg->m_Edit68.iMode = 2;
    Dlg->m_Edit67.Prec = Dlg->m_Edit68.Prec = 3;
    Dlg->m_Edit67.Scale = Dlg->m_Edit68.Scale = 2;
    //xxx
    Dlg->m_Edit65.iMode = Dlg->m_Edit66.iMode = 2;
    Dlg->m_Edit65.Prec = Dlg->m_Edit66.Prec = 3;
    Dlg->m_Edit65.Scale = Dlg->m_Edit66.Scale = 0;	
}

void CDlgSpravTKP::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	OnOK();
}
