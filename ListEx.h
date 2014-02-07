#if !defined(AFX_LISTEX_H__5C6868E1_2465_4130_841E_CE2B7F9D6BA2__INCLUDED_)
#define AFX_LISTEX_H__5C6868E1_2465_4130_841E_CE2B7F9D6BA2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ListEx.h : header file
//
#include <afxtempl.h>
/////////////////////////////////////////////////////////////////////////////
// CListEx window

class CListEx : public CListCtrl
{
public:
    BOOL m_bPrintPreview;
    void PrintPreview();
	CSingleDocTemplate* m_pTemplate;
    virtual void OnBeginPrinting(CDC *pDC, CPrintInfo *pInfo);
    virtual void OnPrint(CDC *pDC, CPrintInfo *pInfo);
    virtual void OnEndPrinting(CDC *pDC, CPrintInfo *pInfo);

    void Print();

    CFont m_PrinterFont;
    CFont *m_pListFont;
    int   iOld;

    int   m_CurSheet;
    int   m_CurLongPage;

    int   m_LinesInDoc;

    CSize m_CharSize;
    CSize m_PaperSize;

    int   m_nLinesPerPage;
    int   m_SheetsPerPage;
    int   m_nCharPerLine;

    int   m_nHeaderLines;

    BOOL  m_HeaderOnEveryPage;
    BOOL  m_EnablePageNumbers;
    int   m_PaperOrient;

    int   m_FontSize;
    CFont m_PageFont;

	int m_nFromPage;
	int m_nToPage;
    
// Construction
public:
	CListEx();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListEx)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CListEx();

	// Generated message map functions
protected:
	//{{AFX_MSG(CListEx)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTEX_H__5C6868E1_2465_4130_841E_CE2B7F9D6BA2__INCLUDED_)
