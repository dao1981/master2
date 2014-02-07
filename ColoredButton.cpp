// ColoredButton.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "ColoredButton.h"
#include ".\coloredbutton.h"


// CColoredButton

IMPLEMENT_DYNAMIC(CColoredButton, CButton)
CColoredButton::CColoredButton()
{
	m_color=GetSysColor(COLOR_BTNFACE);
	m_selected = FALSE;
}

CColoredButton::~CColoredButton()
{
}


BEGIN_MESSAGE_MAP(CColoredButton, CButton)
	ON_WM_ERASEBKGND()
	ON_WM_CTLCOLOR()
//	ON_WM_DRAWITEM()
END_MESSAGE_MAP()



// CColoredButton message handlers


BOOL CColoredButton::OnEraseBkgnd(CDC* pDC)
{
/*        CBrush backBrush(RGB(255, 128, 128));

      // ���������� ������ �����
      CBrush* pOldBrush = pDC->SelectObject(&backBrush);

      CRect rect;
      pDC->GetClipBox(&rect);     // ������� ������ �������

      pDC->PatBlt(rect.left, rect.top, rect.Width(), rect.Height(),
          PATCOPY);
      pDC->SelectObject(pOldBrush);
	return TRUE;*/
	return CButton::OnEraseBkgnd(pDC);
}

void CColoredButton::SetBkColor(COLORREF crColor)
{
	m_color = crColor;
	RedrawWindow();
}

HBRUSH CColoredButton::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = /*CDialog::*/OnCtlColor(pDC, pWnd, nCtlColor);
	pDC->SetTextColor( RGB( 255, 0, 0 ) );
	return hbr;
}

void CColoredButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	CClientDC dc(this); // device context for painting
	
	CRect rect, ignoreRect;
	GetClientRect(&rect);

	//First, fill with background. Don't overwrite the button
	ignoreRect = rect;
	ignoreRect.DeflateRect(2, 2);

	dc.SaveDC();
	dc.ExcludeClipRect(&ignoreRect);
	dc.FillSolidRect(&rect, ::GetSysColor(COLOR_BTNFACE));

	//Is in focus?
	if(::GetFocus() == m_hWnd)
	{
		//Draw focus rect two times. This is necessary to make the focus
		//rect visible when using a high contrast color scheme in windows
		COLORREF old = dc.SetBkColor(::GetSysColor(COLOR_BTNFACE));
		dc.DrawFocusRect(&rect);
		dc.SetBkColor(::GetSysColor(COLOR_BTNTEXT));
		dc.DrawFocusRect(&rect);
		dc.SetBkColor(old);
	}

	dc.RestoreDC(-1);

	rect.DeflateRect(2, 2);
	ignoreRect.DeflateRect(1, 1);

	//Draw selection rect, or background color if no selection
	{
		COLORREF rgbBorder = GetSysColor (COLOR_3DDKSHADOW);
		if(!m_selected)
			rgbBorder = GetSysColor (COLOR_BTNFACE);

		CPen borderPen(PS_SOLID, 1, rgbBorder);
		CPen* pold = dc.SelectObject(&borderPen);
		dc.MoveTo(rect.TopLeft());
		dc.LineTo(rect.right-1, rect.top);
		dc.LineTo(rect.right-1, rect.bottom-1);
		dc.LineTo(rect.left, rect.bottom-1);
		dc.LineTo(rect.left, rect.top);
		dc.SelectObject(pold);
	}


	//Shrink the rect, 1 pixel on all sides.
	rect.DeflateRect(1,1);

	//We want to ignore the area inside the border...
	ignoreRect = rect;
	ignoreRect.DeflateRect(2, 2);

	//Draw border
	UINT uFrameCtrl = DFCS_BUTTONPUSH;
	//Is button pushed?
	if ((lpDrawItemStruct->itemState & ODS_SELECTED) == ODS_SELECTED)
		uFrameCtrl |= DFCS_PUSHED;
	//Disabled?
	if ((lpDrawItemStruct->itemState & ODS_DISABLED) == ODS_DISABLED)
		uFrameCtrl |= DFCS_INACTIVE;
	
	//Draw the frame, but ignore the area inside
	dc.SaveDC();
	dc.ExcludeClipRect(&ignoreRect);
	dc.DrawFrameControl(&rect, DFC_BUTTON, uFrameCtrl);
	dc.RestoreDC(-1);
	
	//Draw color
	rect.DeflateRect(2,2);
	dc.FillSolidRect(&rect,	m_color);

	//Draw pattern if disabled
	if(!IsWindowEnabled())
	{	
		COLORREF but = ::GetSysColor(COLOR_BTNFACE);

		for(int x=rect.left; x<rect.right; x++)
			for(int y=rect.top; y<rect.bottom; y++)
				if( (x+y)%2 == 0)
				dc.SetPixel(x, y, but);
	}	


	//Draw text
	// Get caption text
	CString strCaption;
	GetWindowText (strCaption);
	
	//Any text to draw?
	if(!strCaption.IsEmpty())
	{
		int oldTextColor = dc.SetTextColor(COLOR_BTNTEXT);
		
		// Determine drawing format
		DWORD  dwFormat = DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS | DT_CENTER;
			
		// Determine dimensions of caption
		CRect rectCaption = rect;
	
		//Make push effect by shrinking the rect
		if ((lpDrawItemStruct->itemState & ODS_SELECTED) == ODS_SELECTED)
			rectCaption.DeflateRect(0, 0, -2, -2);
		
		//Draw text transparent...
		int oldMode = dc.SetBkMode(TRANSPARENT);
		//...with the original font
		CFont* oldFont = dc.SelectObject(GetFont());
		
		//OK, draw the text...
		if ((lpDrawItemStruct->itemState & ODS_DISABLED) == ODS_DISABLED)
		{
			//Draw like this if disabled.
			rectCaption.OffsetRect(1, 1);
			dc.SetTextColor(GetSysColor (COLOR_3DHILIGHT));
			dc.DrawText(strCaption, &rectCaption, dwFormat);
			
			rectCaption.OffsetRect(-1,-1);
			dc.SetTextColor(GetSysColor (COLOR_GRAYTEXT));
			dc.DrawText(strCaption, &rectCaption, dwFormat);
		}
		else
			dc.DrawText(	strCaption,
							&rectCaption,
							dwFormat );

		//Set some stuff back
		dc.SelectObject(oldFont);
		dc.SetBkMode(oldMode);
		dc.SetTextColor(oldTextColor);
	}
}
