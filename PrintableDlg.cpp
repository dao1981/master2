// PrintableDlg.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "ListEx.h"
#include "PrintableDlg.h"
#include "PrinterSelectDlg.h"
#include ".\printabledlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp theApp;
extern DWORD g_dwCurDlg;
extern CPrintableDlg *g_pPrnDlg;
/////////////////////////////////////////////////////////////////////////////
// CPrintableDlg dialog


CPrintableDlg::CPrintableDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPrintableDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPrintableDlg)
	m_bCheck1 = FALSE;
	m_bCheck2 = FALSE;
	//}}AFX_DATA_INIT
    cQ[0] = 0;
	bDosCodePage = 0;
}


void CPrintableDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPrintableDlg)
	DDX_Control(pDX, IDOK, m_ButOK);
	DDX_Control(pDX, IDC_CHECK2, m_Check2);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_LIST1, m_List);
	DDX_Check(pDX, IDC_CHECK1, m_bCheck1);
	DDX_Check(pDX, IDC_CHECK2, m_bCheck2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPrintableDlg, CDialog)
	//{{AFX_MSG_MAP(CPrintableDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnPreviewButton)
	ON_BN_CLICKED(IDC_BUTTON2, OnPrintButton)
	ON_WM_SIZE()    
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON3, OnButtonSaveToFile)
	//}}AFX_MSG_MAP
    ON_COMMAND(ID_FILE_PRINT, OnPrintButton)
END_MESSAGE_MAP()
    
/////////////////////////////////////////////////////////////////////////////
// CPrintableDlg message handlers
extern HWND g_hDlgWnd;

BOOL CPrintableDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
    g_hDlgWnd = this->m_hWnd;
    g_dwCurDlg = 1;
    g_pPrnDlg = this;
    if(cQ[0] == 0) return FALSE;
    long Ind;
    char cLine[8196] = "";
    LOGFONT lf;
//    m_Check1.SetCheck(1);
//    m_Check2.SetCheck(1);
    ZeroMemory(&lf, sizeof(lf));
    lf.lfHeight = 14;
    lf.lfCharSet = RUSSIAN_CHARSET;
    strcpy(lf.lfFaceName, "Courier New");
    CFont *Font = new CFont;
    VERIFY(Font->CreateFontIndirect(&lf));
    m_List.SetFont(Font);
    m_List.InsertColumn(0, "", 2000 );

    DBW.ExecSQL(cQ);
    DWORD dwLength = 0;
    char ccc[8196] = "";
    int iOldPos = 0;
    int iCurLine = 0;

	int iRetCount = 0;

    for(DWORD i=0; i < 99999 && (g_sqlret = DBW.Fetch()) != SQL_NO_DATA && g_sqlret != SQL_ERROR; i++ )
    {
        iOldPos = 0;
        DBW.GetData( 1, SQL_C_CHAR, cLine, 8196, &Ind);
//		CString(cLine).Replace( "\r\n", "\n");
        if( Ind != -1 )
        {
			iRetCount = 0;
            for( int x = 0; x < Ind; x++ )
            {
                if( cLine[x] == 0x0D || cLine[x] == 0x0A )
                {
                    strncpy(ccc, cLine + iOldPos, x);
                    ccc[x - iOldPos] = 0;
                    m_List.InsertItem(iCurLine, ccc);
                    iCurLine++;
                    iOldPos = x + 1;
                    if( (cLine[x] == 0x0D && cLine[x + 1] == 10) || (cLine[x] == 0x0A && cLine[x + 1] == 0x0D) )
                    {
						x++;
                        iOldPos++;
                    }
                }
            } 
//			theApp.Dos2Win((unsigned char *)cLine + iOldPos, strlen(cLine + iOldPos));
			m_List.InsertItem(iCurLine, cLine + iOldPos);
            iCurLine++;

            if( dwLength < (unsigned)m_List.GetStringWidth(cLine)) dwLength = m_List.GetStringWidth(cLine);
        } 
/*		else
		{

			iRetCount++;
			if( iRetCount >= 3 )
			{
				iRetCount = 0;
//				m_List.InsertItem(iCurLine, "");
				strcpy( cLine, "--------------------< РАЗРЫВ СТРАНИЦЫ >--------------------");
				m_List.InsertItem(iCurLine, cLine);
//				m_List.InsertItem(iCurLine, "");
				iCurLine+=3;
			}
		}*/
    }
    DBW.CloseCursor();
	DBW.ReallocHandle();

    m_List.SetColumnWidth(0, dwLength + 10);
//    m_List.SetColumnWidth(0, 0);
    return TRUE;
}

void CPrintableDlg::OnPreviewButton() 
{
    if( m_Check1.GetCheck() ) 
        theApp.SetPrintOrientation(DMORIENT_LANDSCAPE);
    else 
        theApp.SetPrintOrientation(DMORIENT_PORTRAIT);

    if( m_Check2.GetCheck() )
        m_List.m_EnablePageNumbers = TRUE;
    else
        m_List.m_EnablePageNumbers = FALSE;
    m_List.PrintPreview();	
}

void CPrintableDlg::OnPrintButton() 
{
    if( m_Check1.GetCheck() ) 
    {
        theApp.SetPrintOrientation(DMORIENT_LANDSCAPE);
        m_List.m_PaperOrient = DMORIENT_LANDSCAPE;
    }
    else 
    {
        theApp.SetPrintOrientation(DMORIENT_PORTRAIT);
        m_List.m_PaperOrient = DMORIENT_PORTRAIT;
    }

    if( m_Check2.GetCheck() )
        m_List.m_EnablePageNumbers = TRUE;
    else
        m_List.m_EnablePageNumbers = FALSE;
/*    CPrinterSelectDlg Dlg;
    if( Dlg.DoModal() == IDCANCEL ) return;
//    if( Dlg*/
    
    m_List.Print();	
}

void CPrintableDlg::OnSize(UINT nType, int cx, int cy) 
{

	CDialog::OnSize(nType, cx, cy);
	int cxFrame=GetSystemMetrics(SM_CXDLGFRAME),
	cyFrame=GetSystemMetrics(SM_CYDLGFRAME);

    RECT r;
//    RECT b;
    if( !m_List ) return;

    this->GetWindowRect(&r);
    this->ScreenToClient(&r);
//    m_List.SetWindowPos(&wndTopMost, cx, cy, r.right - 2, r.left - 2, SWP_DRAWFRAME | SWP_FRAMECHANGED);
    m_List.MoveWindow(r.left+2, r.top + 100, r.right-2, r.bottom - 80);
/*    m_ButOK.GetWindowRect(&b);
    m_ButOK.ScreenToClient(&b);    
//    this->GetWindowRect(&r);
//    m_Ed.SetWindowText(cText);
//    m_ButOK.MoveWindow(r.left, r.top, r.right,  200);
    m_ButOK.MoveWindow(200, 200, 500, 350);
	*/
}

void CPrintableDlg::OuterPrint()
{
    OnPrintButton();
}

void CPrintableDlg::OnClose() 
{
    g_pPrnDlg = NULL;	
	CDialog::OnClose();
}

void CPrintableDlg::OnButtonSaveToFile() 
{
    DWORD dwCount = m_List.GetItemCount();
    CString strFileName, strDirName;
    CString strLine;
    CFileDialog FileDlg(false, "txt", NULL, OFN_OVERWRITEPROMPT, "Текстовый файл (*.txt)|*.txt", NULL);
    if( FileDlg.DoModal() == IDCANCEL ) return;
    strFileName = FileDlg.GetFileName();
	strDirName = FileDlg.GetFolderPath();

    FILE *f = fopen(strDirName + "\\" + strFileName, "wt");
    if( !f )
    {
        MessageBox("Ошибка открытия файла!",
                   "Внимание",
                    MB_OK | MB_ICONINFORMATION);
        return;
    }
    
	for( DWORD i=0; i < dwCount && i < 32000; i++ )
    {
        strLine = m_List.GetItemText(i, 0);
        fprintf(f, "%s\n", strLine);
    }
    fclose(f);
}

void CPrintableDlg::Dos2Win(unsigned char * cLine)
{
	if( !bDosCodePage ) return;

	for( int i=0; cLine[i]; i++ )
	{
		if( cLine[i] >= 0x80 && cLine[i] <= 0x9F )
		{
			cLine[i] += 64;
		}
	}
}
