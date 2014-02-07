// FastGrid.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "FastGrid.h"
#include ".\fastgrid.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CFastGrid

CFastGrid::CFastGrid()
{
    bSortAscending = 1;
    nSortedCol = -1;
	iActive = 0;

	m_crWindow        = ::GetSysColor(COLOR_WINDOW);
	m_crWindowText    = ::GetSysColor(COLOR_WINDOWTEXT);
    m_crBtnFace       = ::GetSysColor(COLOR_BTNFACE);
	m_crHighLight     = ::GetSysColor(COLOR_HIGHLIGHT);
	m_crHighLightText = ::GetSysColor(COLOR_HIGHLIGHTTEXT);
    m_crDisabledText  = m_crWindowText;
    m_crDisabledBg    = RGB(230, 230, 230);
    bBold = FALSE;

//    memset(&Enabled, true, sizeof(bool)*1000);
//    ZeroMemory(&Enabled, sizeof(bool)*1000);
}

CFastGrid::~CFastGrid()
{

}

/*
CFastGrid::~CFastGrid()
{
}
*/

afx_msg BOOL CFastGrid::OnEraseBkgnd(CDC *pDC)
{
    return 1;
}

BOOL CFastGrid::SortTextItems(int nCol, BOOL bAscending, int low, int high)
{
//	return TRUE;
    if( nCol >= ((CHeaderCtrl*)GetDlgItem(0))->GetItemCount() )
        return FALSE;
    if( high == -1 ) high = GetItemCount() - 1;
    int lo = low;
    int hi = high;
    CString midItem;
    if( hi <= lo ) return FALSE;
    midItem = GetItemText( (lo+hi)/2, nCol );
    // loop through the list until indices cross
    while( lo <= hi )
    {
        // rowText will hold all column text for one row
        CStringArray rowText;
        // find the first element that is greater than or equal to 
        // the partition element starting from the left Index.
        if( bAscending )
            while( ( lo < high ) && ( GetItemText(lo, nCol) < midItem ) )
                ++lo;
        else
            while( ( lo < high ) && ( GetItemText(lo, nCol) > midItem ) )
                ++lo;
        // find an element that is smaller than or equal to 
        // the partition element starting from the right Index.
        if( bAscending )
            while( ( hi > low ) && ( GetItemText(hi, nCol) > midItem ) )
                --hi;
        else
            while( ( hi > low ) && ( GetItemText(hi, nCol) < midItem ) )
                --hi;
        // if the indexes have not crossed, swap
        // and if the items are not equal
        if( lo <= hi )
        {
            // swap only if the items are not equal
            if( GetItemText(lo, nCol) != GetItemText(hi, nCol))
            {
                // swap the rows
                LV_ITEM lvitemlo, lvitemhi;
                int nColCount = ((CHeaderCtrl*)GetDlgItem(0))->GetItemCount();
                rowText.SetSize( nColCount );
                int i;
                for( i=0; i<nColCount; i++)
                    rowText[i] = GetItemText(lo, i);
                lvitemlo.mask = LVIF_IMAGE | LVIF_PARAM | LVIF_STATE;
                lvitemlo.iItem = lo;
                lvitemlo.iSubItem = 0;
                lvitemlo.stateMask = LVIS_CUT|LVIS_DROPHILITED|LVIS_FOCUSED|LVIS_SELECTED | LVIS_OVERLAYMASK | LVIS_STATEIMAGEMASK;
                lvitemhi = lvitemlo;
                lvitemhi.iItem = hi;
                GetItem( &lvitemlo );
                GetItem( &lvitemhi );
                for( i=0; i<nColCount; i++)
                    SetItemText(lo, i, GetItemText(hi, i));
                lvitemhi.iItem = lo;
                SetItem( &lvitemhi );
                for( i=0; i<nColCount; i++)
                    SetItemText(hi, i, rowText[i]);
                lvitemlo.iItem = hi;
                SetItem( &lvitemlo );
            }
            ++lo;
            --hi;
        }
    }
    // If the right index has not reached the left side of array
    // must now sort the left partition.
    if( low < hi ) SortTextItems( nCol, bAscending , low, hi);
    // If the left index has not reached the right side of array
    // must now sort the right partition.
    if( lo < high ) SortTextItems( nCol, bAscending , lo, high );
    return TRUE;
}


BEGIN_MESSAGE_MAP(CFastGrid, CListCtrl)
	//{{AFX_MSG_MAP(CFastGrid)
//	ON_NOTIFY_REFLECT(NM_CLICK, OnClick)
	ON_NOTIFY_REFLECT(LVN_ITEMCHANGING, OnItemchanging)
	ON_NOTIFY_REFLECT(LVN_INSERTITEM, OnInsertitem)
    ON_NOTIFY_REFLECT(NM_CUSTOMDRAW, OnCustomDraw)
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_WM_SETFOCUS()
	ON_WM_KILLFOCUS()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CFastGrid message handlers
static int CALLBACK CompareProc(LPARAM lP1, LPARAM lP2, LPARAM lParamSort)
{
    CFastGrid *pL = (CFastGrid *)lParamSort;
    char    str1[32], str2[32];
    pL->GetItemText(lP1, pL->nSortedCol, str1, 32);
    pL->GetItemText(lP2, pL->nSortedCol, str2, 32);
    return strcmp(str1, str2);

}

void CFastGrid::OnHeaderClicked(NMHDR *pNMHDR, LRESULT *pResult)
{
	HD_NOTIFY *phdn = (HD_NOTIFY *) pNMHDR;

    if( phdn->iButton == 0 )
    {
        // User clicked on header using left mouse button
        if( phdn->iItem == nSortedCol )
            bSortAscending = !bSortAscending;
        else
            bSortAscending = TRUE;
        nSortedCol = phdn->iItem;
        SortTextItems( nSortedCol, bSortAscending );
//        SortItems(CompareProc, (LPARAM)this);
    }
//	AfxMessageBox("YYYYW");
	*pResult = 0;
}

void CFastGrid::SortList()
{
    SortTextItems( nSortedCol, bSortAscending );
}


/*
void CFastGrid::OnClick(NMHDR* pNMHDR, LRESULT* pResult) 
{
/*
    DWORD pos = GetMessagePos();
    CPoint pt(LOWORD(pos), HIWORD(pos));
    ScreenToClient(&pt);

    int Index = GetTopIndex();

	*pResult = 0;
}
*/

void CFastGrid::OnItemchanging(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* p = (NM_LISTVIEW*)pNMHDR;
	
    UINT x = p->uNewState;

	char c[12] = "";
	itoa(p->uOldState, c, 10);
//	AfxMessageBox(c);
//	AfxMessageBox("c");
    if( isItemEnabled(p->iItem) == FALSE && (p->uOldState & 8192 || p->uNewState & 8192) )
    {
        *pResult = 1;
    } else
	{
	    *pResult = 0;
	}

}

void CFastGrid::OnInsertitem(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* p = (NM_LISTVIEW*)pNMHDR;
 
	*pResult = 0;
}

BOOL CFastGrid::isItemEnabled(int Index)
{
    if( Index < 0 || Index > 1000 ) return FALSE;
//    return Enabled[Index];
	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(Index);
	if (!pXLCD)
	{
		return FALSE;
	}

	return pXLCD->bEnabled;
    
}

void CFastGrid::EnableItem(int Index, BOOL State)
{
    if( Index < 0 || Index > 1000 ) return;
	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(Index);
	if (!pXLCD)
	{
		return;
	}
    pXLCD->bEnabled = State;
}

int CFastGrid::InsertItem(const LVITEM* pItem)
{
	ASSERT(pItem->iItem >= 0);
	if (pItem->iItem < 0)
		return -1;

	int index = CListCtrl::InsertItem(pItem);

	if (index < 0)
		return index;

//	CListDataEx *pXLCD = new CListDataEx[GetColumns()];
	CListDataEx *pXLCD = new CListDataEx;
	ASSERT(pXLCD);
	if (!pXLCD)
		return -1;

/*	pXLCD[0].crText       = m_crWindowText;
	pXLCD[0].crBackground = m_crWindow;
	pXLCD[0].nImage       = pItem->iImage;
*/
	CListCtrl::SetItemData(index, (DWORD) pXLCD);

	return index;

}

int CFastGrid::InsertItem(int nItem, LPCTSTR lpszItem)
{
	ASSERT(nItem >= 0);
	if (nItem < 0)
		return -1;

//    return CListCtrl::InsertItem(nItem, lpszItem);

    int index = CListCtrl::InsertItem(nItem, lpszItem);

	if (index < 0)
		return index;

//	CListDataEx *pXLCD = new CListDataEx[GetColumns()];
	CListDataEx *pXLCD = new CListDataEx;
	ASSERT(pXLCD);
	if (!pXLCD)
		return -1;

    CListCtrl::SetItemData(index, (DWORD_PTR) pXLCD);
    return index;

}


int CFastGrid::GetColumns()
{
	return GetHeaderCtrl()->GetItemCount();
}

BOOL CFastGrid::SetItemData(int nItem, DWORD dwData)
{
	ASSERT(nItem >= 0);
	ASSERT(nItem < GetItemCount());
	if ((nItem < 0) || nItem >= GetItemCount())
		return FALSE;

	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(nItem);
	if (!pXLCD)
	{
		return FALSE;
	}

	pXLCD->dwItemData = dwData;

	return TRUE;
}

DWORD CFastGrid::GetItemData(int nItem)
{
	ASSERT(nItem >= 0);
	ASSERT(nItem < GetItemCount());
	if ((nItem < 0) || nItem >= GetItemCount())
		return 0;

	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(nItem);
	if (!pXLCD)
	{
		return 0;
	}

	return pXLCD->dwItemData;
}

void CFastGrid::OnCustomDraw(NMHDR* pNMHDR, LRESULT* pResult)
{
	NMLVCUSTOMDRAW* pLVCD = reinterpret_cast<NMLVCUSTOMDRAW*>(pNMHDR);

	// Take the default processing unless we set this to something else below.
	*pResult = CDRF_DODEFAULT;

	// First thing - check the draw stage. If it's the control's prepaint
	// stage, then tell Windows we want messages for every item.

	if (pLVCD->nmcd.dwDrawStage == CDDS_PREPAINT)
	{
		*pResult = CDRF_NOTIFYITEMDRAW;
        CDC* pDC1 = CDC::FromHandle(pLVCD->nmcd.hdc);        
	}
	else if (pLVCD->nmcd.dwDrawStage == CDDS_ITEMPREPAINT)
	{
		// This is the notification message for an item.  We'll request
		// notifications before each subitem's prepaint stage.

		*pResult = CDRF_NOTIFYSUBITEMDRAW;
	}
	else if (pLVCD->nmcd.dwDrawStage == (CDDS_ITEMPREPAINT | CDDS_SUBITEM))
	{
		// This is the prepaint stage for a subitem. Here's where we set the
		// item's text and background colors. Our return value will tell
		// Windows to draw the subitem itself, but it will use the new colors
		// we set here.

		int nItem = static_cast<int> (pLVCD->nmcd.dwItemSpec);
		int nSubItem = pLVCD->iSubItem;

		CListDataEx *pXLCD = (CListDataEx *) pLVCD->nmcd.lItemlParam;
		ASSERT(pXLCD);

		COLORREF crText  = m_crWindowText;
		COLORREF crBkgnd = m_crWindow;

		if (pXLCD)
		{
/*            
			crText  = pXLCD[nSubItem].crText;
			crBkgnd = pXLCD[nSubItem].crBackground;
*/          
			crText  = pXLCD->crText;
			crBkgnd = pXLCD->crBackground;
            /*
            crText  = RGB(255,255,0);
			crBkgnd = RGB(150,150,10);
            */

			if (!pXLCD->bEnabled)
            {
                crText = m_crDisabledText;
				crBkgnd = m_crDisabledBg;
            }
			if( pXLCD->bMarked )
			{
//				crText  = pXLCD[nSubItem].crText;
				crText  = pXLCD->crText;
				crBkgnd = RGB(170,220,250);
			}
			if( GetItemState(nItem, LVIS_SELECTED))
			{				
				crText  = pXLCD->crText;
				crBkgnd = RGB(255,255,255);
//				AfxMessageBox("marked is");
			}
		}
/*                crText = RGB(255,255,255);
				crBkgnd = RGB(0,0,0);*/

		// store the colors back in the NMLVCUSTOMDRAW struct
		pLVCD->clrText = crText;
		pLVCD->clrTextBk = crBkgnd;

		CDC* pDC = CDC::FromHandle(pLVCD->nmcd.hdc);
		CRect rect;
		GetSubItemRect(nItem, nSubItem, LVIR_BOUNDS, rect);
        if( ( GetExStyle() & LVS_EX_CHECKBOXES) )
        {
            *pResult = CDRF_DODEFAULT;
        } else
/*
		if (pXLCD && (pXLCD[nSubItem].bShowProgress))
		{
			DrawProgress(nItem, nSubItem, pDC, crText, crBkgnd, rect, pXLCD);

			*pResult = CDRF_SKIPDEFAULT;	// We've painted everything.
		}
#ifndef DO_NOT_INCLUDE_XCOMBOLIST
		else if (pXLCD && (pXLCD[nSubItem].bCombo))
		{
			if (GetItemState(nItem, LVIS_SELECTED))
				DrawComboBox(nItem, nSubItem, pDC, crText, crBkgnd, rect, pXLCD);
			else
				DrawText(nItem, nSubItem, pDC, crText, crBkgnd, rect, pXLCD);

			*pResult = CDRF_SKIPDEFAULT;	// We've painted everything.
		}
#endif
		else if (pXLCD && (pXLCD[nSubItem].nCheckedState != -1))
		{
			DrawCheckbox(nItem, nSubItem, pDC, crText, crBkgnd, rect, pXLCD);

			*pResult = CDRF_SKIPDEFAULT;	// We've painted everything.
		}
		else*/
		{
//			rect.left += DrawImage(nItem, nSubItem, pDC, crText, crBkgnd, rect, pXLCD);

/*			if( GetItemState(nItem, LVIS_SELECTED))
			{
				DrawText(nItem, nSubItem, pDC, RGB(0,255,0), RGB(255,0,0), rect, pXLCD);
			} else*/
				DrawText(nItem, nSubItem, pDC, crText, crBkgnd, rect, pXLCD);
			*pResult = CDRF_SKIPDEFAULT;	// We've painted everything.
		}
        
	}
    
}

void CFastGrid::DrawText(int nItem,
						  int nSubItem,
						  CDC *pDC,
						  COLORREF crText,
						  COLORREF crBkgnd,
						  CRect& rect,
						  CListDataEx *pXLCD)
{
	ASSERT(pDC);
	ASSERT(pXLCD);

	GetDrawColors(nItem, nSubItem, crText, crBkgnd);

	pDC->FillSolidRect(&rect, crBkgnd);
	CString str;
	str = GetItemText(nItem, nSubItem);

	if (!str.IsEmpty())
	{
		// get text justification
		HDITEM hditem;
		hditem.mask = HDI_FORMAT;
        CHeaderCtrl *m_HeaderCtrl = GetHeaderCtrl();
        
		m_HeaderCtrl->GetItem(nSubItem, &hditem);
		int nFmt = hditem.fmt & HDF_JUSTIFYMASK;
		UINT nFormat = DT_VCENTER | DT_SINGLELINE;
		if (nFmt == HDF_CENTER)
			nFormat |= DT_CENTER;
		else if (nFmt == HDF_LEFT)
			nFormat |= DT_LEFT;
		else
			nFormat |= DT_RIGHT;

		CFont *pOldFont = NULL;
		CFont boldfont;

		// check if bold specified for subitem
//		if (pXLCD && pXLCD[nSubItem].bBold)
		if (pXLCD && pXLCD->bBold)
		{
			CFont *font = pDC->GetCurrentFont();
			if (font)
			{
				LOGFONT lf;
				font->GetLogFont(&lf);
				lf.lfWeight = FW_BOLD;
				boldfont.CreateFontIndirect(&lf);
				pOldFont = pDC->SelectObject(&boldfont);
			}
		}		
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(crText);
		pDC->SetBkColor(crBkgnd);
		pDC->DrawText(str, &rect, nFormat);
		if (pOldFont)
			pDC->SelectObject(pOldFont);
	}
}

void CFastGrid::GetDrawColors(int nItem,
							   int nSubItem,
							   COLORREF& colorText,
							   COLORREF& colorBkgnd)
{
	DWORD dwStyle    = GetStyle();
	DWORD dwExStyle  = GetExtendedStyle();

	COLORREF crText  = colorText;
	COLORREF crBkgnd = colorBkgnd;

	if (GetItemState(nItem, LVIS_SELECTED))
	{
		if (dwExStyle & LVS_EX_FULLROWSELECT)
		{
			// selected?  if so, draw highlight background
			crText  = m_crHighLightText;
			crBkgnd = m_crHighLight;
					crText = RGB(255,0,255);
					crBkgnd = RGB(0,0,0);

			// has focus?  if not, draw gray background
/*			if (m_hWnd != ::GetFocus())
			{
				if (dwStyle & LVS_SHOWSELALWAYS)
				{
					crText  = m_crWindowText;
					crBkgnd = m_crBtnFace;
//					crText = RGB(255,0,255);
//					crBkgnd = RGB(0,0,0);
				}
				else
				{
					crText  = colorText;
					crBkgnd = colorBkgnd;
				}
			}*/
		}
		else	// not full row select
		{
			if (nSubItem == 0)
			{
				// selected?  if so, draw highlight background
				crText  = m_crHighLightText;
				crBkgnd = m_crHighLight;

				// has focus?  if not, draw gray background
				if (m_hWnd != ::GetFocus())
				{
					if (dwStyle & LVS_SHOWSELALWAYS)
					{
						crText  = m_crWindowText;
						crBkgnd = m_crBtnFace;
					}
					else
					{
						crText  = colorText;
						crBkgnd = colorBkgnd;
					}
				}
			}
		}
	}

	colorText = crText;
	colorBkgnd = crBkgnd;
}
/*
void CFastGrid::SubclassHeaderControl()
{
	if (m_bHeaderIsSubclassed)
		return;

	// if the list control has a header control window, then
	// subclass it

	// Thanks to Alberto Gattegno and Alon Pelegààand their article
	// "A Multiline Header Control Inside a CListCtrl" for easy way
	// to determine if the header control exists.

	CHeaderCtrl* pHeader = GetHeaderCtrl();
	if (pHeader)
	{
		VERIFY(m_HeaderCtrl.SubclassWindow(pHeader->m_hWnd));
		m_bHeaderIsSubclassed = TRUE;
	}
}
*/

void CFastGrid::SetMarkedItem(int index, BOOL bMark)
{
	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(index);
	if (!pXLCD)
	{
		return;
	}
	pXLCD->bMarked = bMark;
}

void CFastGrid::ClearMark()
{
	CListDataEx *pX = NULL;
	for( int i=0; i < GetItemCount(); i++ )
	{
		pX = (CListDataEx *) CListCtrl::GetItemData(i);
		if( pX )
		{
			pX->bMarked = FALSE;
		}
	}
}

BOOL CFastGrid::DeleteItem(int nItem)
{
	ASSERT(nItem >= 0);
	ASSERT(nItem < GetItemCount());
	if ((nItem < 0) || nItem >= GetItemCount())
		return FALSE;

	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(nItem);
	if (pXLCD)
    {
		delete pXLCD;
        pXLCD = NULL;
    }
	CListCtrl::SetItemData(nItem, 0);
	return CListCtrl::DeleteItem(nItem);
}

BOOL CFastGrid::DeleteAllItems()
{
	int n = GetItemCount();
	for (int i = 0; i < n; i++)
	{
		CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(i);
		if (pXLCD)
        {
			delete pXLCD;
            pXLCD = NULL;
        }
		CListCtrl::SetItemData(i, 0);
	}
	return CListCtrl::DeleteAllItems();
}

void CFastGrid::OnDestroy() 
{
	int n = GetItemCount();
	for (int i = 0; i < n; i++)
	{
		CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(i);
		if (pXLCD)
		{
				delete pXLCD;
                pXLCD = NULL;
		}
		CListCtrl::SetItemData(i, 0);
	}
	CListCtrl::DeleteAllItems();
	CListCtrl::OnDestroy();
}

void CFastGrid::SetData2(DWORD dwData2)
{

	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(GetSelectionMark());
    ASSERT(pXLCD);
	if (!pXLCD)
	{
		return;
	}
	pXLCD->dwItemData2 = dwData2;
}

DWORD CFastGrid::GetItemData2()
{
	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(GetSelectionMark());
    ASSERT(pXLCD);
	if (!pXLCD)
	{
		return 0;
	}
	return pXLCD->dwItemData2;
}

__int64 CFastGrid::qwGetItemData(int Index)
{
	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(Index);
    ASSERT(pXLCD);
	if (!pXLCD)
	{
		return 0;
	}
	return pXLCD->qwItemData;    
}

void CFastGrid::qwSetItemData(int nItem, __int64 qwData)
{
	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(nItem);
    ASSERT(pXLCD);
	if (!pXLCD)
	{
		return;
	}
	pXLCD->qwItemData = qwData;
}

BOOL CFastGrid::DestroyWindow() 
{
	int n = GetItemCount();
	for (int i = 0; i < n; i++)
	{
		CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(i);
		if (pXLCD)
		{
				delete pXLCD;
                pXLCD = NULL;
		}
		CListCtrl::SetItemData(i, 0);
	}
	return CListCtrl::DestroyWindow();
}

void CFastGrid::SetItemColor(int nItem, COLORREF colorText, COLORREF colorBkgnd)
{
	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(nItem);
    ASSERT(pXLCD);
	if (!pXLCD)
	{
		return;
	}
	pXLCD->crText = colorText;
	pXLCD->crBackground = colorBkgnd;
}


void CFastGrid::OnSetFocus(CWnd* pOldWnd)
{
	CListCtrl::OnSetFocus(pOldWnd);
	iActive = 1;	
}

void CFastGrid::OnKillFocus(CWnd* pNewWnd)
{
	CListCtrl::OnKillFocus(pNewWnd);
	iActive = 0;
	
}

COLORREF CFastGrid::GetItemColor(int nItem)
{
	CListDataEx *pXLCD = (CListDataEx *) CListCtrl::GetItemData(nItem);
    ASSERT(pXLCD);
	if (!pXLCD)
	{
		return 0;
	}
/*	pXLCD->crText = colorText;
	pXLCD->crBackground = colorBkgnd;*/
	return pXLCD->crBackground;
}
