#if !defined(AFX_FASTGRID_H__0D032961_7C15_4B00_BF80_25DDF1C6D444__INCLUDED_)
#define AFX_FASTGRID_H__0D032961_7C15_4B00_BF80_25DDF1C6D444__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// FastGrid.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CFastGrid window

struct CListDataEx
{
    BOOL        bEnabled;
    DWORD       dwItemData;
	DWORD		dwItemData2;
    COLORREF	crText;
	COLORREF	crBackground;
    BOOL        bBold;
	BOOL		bMarked;
    __int64     qwItemData;
    CListDataEx()
    {
        bEnabled = true;
        dwItemData = 0;
		dwItemData2 = 0;
        qwItemData = 0;
        bBold = FALSE;
		bMarked = FALSE;
        crText = RGB(10,10,10);
        crBackground = RGB(255,255,250);
    }
};

class CFastGrid : public CListCtrl
{
// Construction
public:
	CFastGrid();
//	~CFastGrid();
    BOOL  bSortAscending;
    int   nSortedCol;
    BOOL  bBold;

    BOOL  SortTextItems(int nCol, BOOL bAscending, int low = 0, int high = -1);
    void  SortList();

	COLORREF m_crWindow;
	COLORREF m_crWindowText;
    COLORREF m_crDisabledText;
    COLORREF m_crDisabledBg;
    COLORREF m_crHighLightText;
    COLORREF m_crHighLight;
    COLORREF m_crBtnFace;
/*
    BOOL    m_bHeaderIsSubclassed;
    m_HeaderCtrl
*/
//    BOOL  Enabled[1000];
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFastGrid)
	public:
	virtual BOOL DestroyWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	int iActive;
	void qwSetItemData(int nItem, __int64);
	__int64 qwGetItemData(int Index);
	DWORD GetItemData2();
	void SetData2(DWORD dwData2);
	void ClearMark();
	void SetMarkedItem(int index, BOOL bMark = TRUE);
	void EnableItem(int Index, BOOL State = true);
	BOOL isItemEnabled(int Index);
	void OnHeaderClicked(NMHDR* pNMHDR, LRESULT* pResult);
    int InsertItem(const LVITEM* pItem);
    int InsertItem(int nItem, LPCTSTR lpszItem);
    int GetColumns();
    BOOL SetItemData(int nItem, DWORD dwData);
    DWORD GetItemData(int nItem);
	void SetItemColor(int nItem, COLORREF colorText, COLORREF colorBkgnd);
    void DrawText(int nItem, 
				  int nSubItem, 
				  CDC *pDC, 
				  COLORREF crText,
				  COLORREF crBkgnd,
				  CRect& rect, 
				  CListDataEx *pCLD);
    void GetDrawColors(int nItem,
							   int nSubItem,
							   COLORREF& colorText,
							   COLORREF& colorBkgnd);
	virtual ~CFastGrid();
	BOOL DeleteItem(int nItem);
	BOOL DeleteAllItems();

	// Generated message map functions
protected:
	//{{AFX_MSG(CFastGrid)
//	afx_msg void OnClick(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchanging(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnInsertitem(NMHDR* pNMHDR, LRESULT* pResult);
    afx_msg void OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDestroy();
	//}}AFX_MSG
    afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	COLORREF GetItemColor(int nItem);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FASTGRID_H__0D032961_7C15_4B00_BF80_25DDF1C6D444__INCLUDED_)
