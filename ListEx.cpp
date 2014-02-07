// ListEx.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "ListEx.h"
#include "ViewPrintPreview.h"
#include "winspool.h"
#include "math.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern CMasterApp theApp;
/////////////////////////////////////////////////////////////////////////////
// CListEx

CListEx::CListEx()
{
    m_pTemplate=NULL;
    m_bPrintPreview=FALSE;
    m_HeaderOnEveryPage = TRUE;
    m_nHeaderLines = 0;

    m_PaperOrient = DMORIENT_PORTRAIT;
	m_nFromPage = 1;
	m_nToPage = 20000;
}

CListEx::~CListEx()
{
}

void SetDCFont(CDC *pDC, CString strFontName, int nFontWidth, int nFontHeight, long FontWeight = FW_NORMAL)
{
	CFont *font = new CFont;
	LOGFONT lf;
	lf.lfHeight			= nFontHeight;
	lf.lfWidth			= nFontWidth;
	lf.lfEscapement		= 0;
	lf.lfOrientation	= 0;
	lf.lfWeight			= FontWeight; //FW_NORMAL;
	lf.lfItalic			= 0;
	lf.lfUnderline		= 0;
	lf.lfStrikeOut		= 0;
	lf.lfCharSet		= RUSSIAN_CHARSET;
	lf.lfOutPrecision	= OUT_DEFAULT_PRECIS;
	lf.lfClipPrecision	= CLIP_DEFAULT_PRECIS;
	lf.lfQuality		= ANTIALIASED_QUALITY;
	lf.lfPitchAndFamily	= VARIABLE_PITCH | FF_ROMAN;
	
	strcpy( lf.lfFaceName, LPCTSTR(strFontName) );
	
	font->CreateFontIndirect(&lf);
    pDC->SelectObject(font);

}

void CListEx::Print()
{
	CDC dc;
	CPrintDialog printDlg(FALSE, PD_ALLPAGES | /*PD_PAGENUMS | */PD_USEDEVMODECOPIES | PD_NOSELECTION, theApp.m_pMainWnd);
	printDlg.m_pd.nMinPage = printDlg.m_pd.nFromPage = 1;
	printDlg.m_pd.nMaxPage = printDlg.m_pd.nToPage = 10;

	//	printDlg.m_lp
//    printDlg.
//    printDlg.set
    if (printDlg.DoModal() != IDOK)
        return;

	m_nFromPage = printDlg.m_pd.nFromPage;
	m_nToPage = printDlg.m_pd.nToPage;
    PRINTDLG pd;
    pd.lStructSize = (DWORD)sizeof(PRINTDLG) ;

//    char cPrinterName[128] = "";
    
    dc.Attach(printDlg.GetPrinterDC());         // attach a printer DC
    dc.m_bPrinting = TRUE;

    CString strTitle;
    strTitle.LoadString(AFX_IDS_APP_TITLE);

    DOCINFO di;                                 // Initialise print doc details
    memset(&di, 0, sizeof (DOCINFO));
    di.cbSize = sizeof (DOCINFO);
    di.lpszDocName = strTitle;
  
    BOOL bPrintingOK = dc.StartDoc(&di);        // Begin a new print job

    CPrintInfo Info;
    Info.m_rectDraw.SetRect(0,0, dc.GetDeviceCaps(HORZRES), dc.GetDeviceCaps(VERTRES));
//    Info.m_rectDraw.SetRect(dc.GetDeviceCaps(PHYSICALOFFSETX),0, dc.GetDeviceCaps(PHYSICALWIDTH+), dc.GetDeviceCaps(VERTRES));
    
    OnBeginPrinting(&dc, &Info);                // Initialise printing
    for (UINT page = Info.GetMinPage(); page <= Info.GetMaxPage() && bPrintingOK; page++)
    {
        dc.StartPage();                         // begin new page
        Info.m_nCurPage = page;
        OnPrint(&dc, &Info);                    // Print page
        bPrintingOK = (dc.EndPage() > 0);       // end page
    }
    OnEndPrinting(&dc, &Info);                  // Clean up after printing

    if (bPrintingOK)
        dc.EndDoc();                            // end a print job
    else
        dc.AbortDoc();                          // abort job.

    dc.Detach();                                // detach the printer DC
}

void CListEx::PrintPreview()
{
    if (m_bPrintPreview)
    {
        AfxGetApp()->m_pMainWnd->SetFocus();
        return;
    }
    CFrameWnd* pOldFrame=NULL;
    pOldFrame=(CFrameWnd*)AfxGetThread()->m_pMainWnd;
    if( !pOldFrame )
    {
        AfxMessageBox("SDSD");
        return;
    }
    pOldFrame->ShowWindow(SW_HIDE);
    if (!m_pTemplate)
    {
        m_pTemplate = new CSingleDocTemplate(
            IDR_MENU1,
            NULL,
            RUNTIME_CLASS(CFrameWnd),
            RUNTIME_CLASS(CViewPrintPreview));
        AfxGetApp()->AddDocTemplate(m_pTemplate);
    }
    CFrameWnd * pFrameWnd = m_pTemplate->CreateNewFrame( NULL, NULL );
    m_bPrintPreview=TRUE;
    m_pTemplate->InitialUpdateFrame( pFrameWnd, NULL, FALSE);
    CViewPrintPreview* pView=(CViewPrintPreview*)pFrameWnd->GetActiveView();
    pView->m_pCtrl=this;
    pView->m_pOldFrame=pOldFrame;
    AfxGetApp()->m_pMainWnd=pFrameWnd;
    pFrameWnd->SetWindowText("Ïðåäâàðèòåëüíûé ïðîñìîòð");    

	CMenu *pSysMenu = pFrameWnd->GetSystemMenu(FALSE); 
	if(pSysMenu)
	{ 
			pSysMenu->EnableMenuItem(SC_CLOSE, MF_GRAYED|MF_BYCOMMAND); 
	}
	pFrameWnd->ShowWindow(SW_SHOWMAXIMIZED);

    pView->OnFilePrintPreview();
}

void CListEx::OnBeginPrinting(CDC *pDC, CPrintInfo *pInfo)
{
    ASSERT(pDC && pInfo);
    if (!pDC || !pInfo) return;
    char cText[512] = "";
    m_LinesInDoc = this->GetItemCount();
//    if( !m_LinesInDoc) return;

/*
    m_CharSize.cx = 52;
    m_CharSize.cy = 110;
*/

    m_PageFont.DeleteObject();
    m_PageFont.CreatePointFont(100, "Courier New", pDC);
    CFont *fOld = pDC->SelectObject(&m_PageFont);
    m_CharSize = pDC->GetTextExtent("X");

    CSize PaperPixelsPerInch(pDC->GetDeviceCaps(LOGPIXELSX), pDC->GetDeviceCaps(LOGPIXELSY));
//    CSize ScreenPixelsPerInch(pCurrentDC->GetDeviceCaps(LOGPIXELSX), pCurrentDC->GetDeviceCaps(LOGPIXELSY));
/*    m_PaperSize = CSize(pDC->GetDeviceCaps(HORZRES)- pDC->GetDeviceCaps(PHYSICALOFFSETX)-pDC->GetDeviceCaps(LOGPIXELSX), 
                        pDC->GetDeviceCaps(VERTRES)-pDC->GetDeviceCaps(PHYSICALOFFSETY)-pDC->GetDeviceCaps(LOGPIXELSY));*/
      m_PaperSize = CSize(pDC->GetDeviceCaps(HORZRES), 
                        pDC->GetDeviceCaps(VERTRES));


    m_nCharPerLine = m_PaperSize.cx / m_CharSize.cx;
    m_nLinesPerPage = ( m_PaperSize.cy / m_CharSize.cy ) - 2;

	int iLinesWithPageBreakers = 0;

	int iCurLine = 0;
	int iCurPage = 0;
	for( int i=0; i < GetItemCount(); i++ )
	{
		GetItemText( i, 0, cText, 512 );
		iCurLine++;
		if(iCurLine == m_nLinesPerPage ) iCurLine = 0;
//		if( strcmp(cText, "--------------------< ÐÀÇÐÛÂ ÑÒÐÀÍÈÖÛ >--------------------") == 0 )
		if( cText[0] == 12 )
		{
			SetItemText(i, 0, "");
			for( int x = 0; x < m_nLinesPerPage - iCurLine; x++ )
			{
				InsertItem(i, "");
			}
//			AfxMessageBox("breaker");
		}
	}
	m_LinesInDoc = GetItemCount();
//    pInfo->m_rectDraw.SetRect(0,0, pDC->GetDeviceCaps(HORZRES), pDC->GetDeviceCaps(VERTRES));
        pInfo->m_rectDraw.SetRect(0,0, pDC->GetDeviceCaps(HORZRES), pDC->GetDeviceCaps(VERTRES));
    
	

    m_nHeaderLines = 0;
    do
    {
        m_nHeaderLines++;
        GetItemText(m_nHeaderLines, 0, cText, 512);
    } while( m_nHeaderLines == 1 && cText[0] == '+' );
/*    
    itoa(m_nHeaderLines, cText, 10);
    AfxMessageBox(cText);
*/
    unsigned int MaxStrLen = 0;
    for( int i=0; i < m_LinesInDoc; i++ )
    {
        this->GetItemText(i, 0, cText, 512);
		for( int x = strlen(cText) - 1; x >= m_nCharPerLine && cText[x] == ' '; x-- ) 
			cText[x] = 0;
        if( strlen(cText) > MaxStrLen ) MaxStrLen = strlen(cText);
    }

    m_SheetsPerPage = (int)ceil((double)MaxStrLen * (double)m_CharSize.cx / (double)m_PaperSize.cx);
	if( !m_SheetsPerPage ) m_SheetsPerPage++;
	int	iMaxPages = (int)ceil(((double)m_LinesInDoc / (double)m_nLinesPerPage)*(double)m_SheetsPerPage);
	if( !iMaxPages ) iMaxPages = m_SheetsPerPage; //áûëî = 1

	
	if( (m_nToPage - m_nFromPage + 1)*m_SheetsPerPage < iMaxPages) 
		iMaxPages = (m_nToPage - m_nFromPage + 1)*m_SheetsPerPage;

    pInfo->SetMaxPage(iMaxPages);
    pInfo->SetMinPage(1);
    pInfo->m_nCurPage = 1;
    
	iMaxPages = (m_nToPage - m_nFromPage) * m_SheetsPerPage;
	m_CurLongPage = m_nFromPage - 1;

    
	m_CurSheet = 0;

    pDC->SelectObject(fOld);
}

void CListEx::OnEndPrinting(CDC * /*pDC*/, CPrintInfo* pInfo)
{

}

void CListEx::OnPrint(CDC *pDC, CPrintInfo *pInfo)
{
    pDC->SetBkMode(TRANSPARENT);
    SetDCFont(pDC, "Courier New", m_CharSize.cx, m_CharSize.cy);
    char cText[1024] = "";
    char cLine[1024] = "";
    CString pstrArr[512];
    int  y = 1;
    
    m_CurLongPage = (pInfo->m_nCurPage - 1) / (m_SheetsPerPage );
    m_CurSheet = 0;
    for(unsigned int n=1; n < pInfo->m_nCurPage; n++ )
    {
        m_CurSheet++;
        if( m_CurSheet > m_SheetsPerPage - 1 ) m_CurSheet = 0;
    }

/*    if(m_CurSheet == 1) 
        AfxMessageBox("!");*/

	char msg[1024] = "";
	sprintf(msg, "m_nLinesPerPage = %u", m_nLinesPerPage);
	DBW.WriteLog(msg);
	sprintf(msg, "m_CurLongPage = %u", m_CurLongPage);
	DBW.WriteLog(msg);
	sprintf(msg, "m_CurSheet = %u", m_CurSheet);
	DBW.WriteLog(msg);
	sprintf(msg, "m_nCharPerLine = %u", m_nCharPerLine);
	DBW.WriteLog(msg);

	
	for( int i = m_nLinesPerPage * m_CurLongPage; i < m_nLinesPerPage * m_CurLongPage + m_nLinesPerPage && i < m_LinesInDoc && m_CurLongPage < m_nToPage; i++ )
    {
        if( !this->GetItemText(i, 0, cText, 1024) ) cLine[0] = 0;
		else
		{
			strncpy(cLine, cText + (m_CurSheet * m_nCharPerLine ), m_nCharPerLine);
			if( !cText[ m_CurSheet * m_nCharPerLine ] ) cLine[0] = 0;
		}
        cLine[m_nCharPerLine] = 0;
/*		sprintf(msg, ".OnPrint [y = %.3u] [i = %.3u] [%s][%s]", y, i, cLine, cText);
		DBW.WriteLog(msg);*/
/*		if( strcmp( cLine, "--------------------< ÐÀÇÐÛÂ ÑÒÐÀÍÈÖÛ >--------------------") == 0 )
		{

		}*/
        pDC->TextOut(0, y * m_CharSize.cy, cLine);
        y++;
    }
    if( m_EnablePageNumbers )
    {
        if(m_SheetsPerPage > 1)
        {
            sprintf(cText, "Ñòð. %d (%d/%d)", pInfo->m_nCurPage, m_CurLongPage + 1, m_CurSheet + 1);
        }else
        {
            sprintf(cText, "Ñòð.: %d", pInfo->m_nCurPage);
        }
        pDC->TextOut(pInfo->m_rectDraw.right - m_CharSize.cx * (strlen(cText)+2), pInfo->m_rectDraw.bottom - m_CharSize.cy, cText);
    }
}

BEGIN_MESSAGE_MAP(CListEx, CListCtrl)
	//{{AFX_MSG_MAP(CListEx)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CListEx message handlers
