// MyLabel.cpp : implementation file
//

#include "stdafx.h"
#include "MyLabel.h"
#include ".\mylabel.h"
// CMyLabel

IMPLEMENT_DYNAMIC(CMyLabel, CStatic)
CMyLabel::CMyLabel()
{
	m_BgColor = GetSysColor(COLOR_3DFACE);
	
//	m_BgColor = RGB(10,200,20);
	
	m_TextColor = GetSysColor(COLOR_BTNTEXT);
	m_bRotated = 1;
	
}

CMyLabel::~CMyLabel()
{
}


BEGIN_MESSAGE_MAP(CMyLabel, CStatic)
	ON_WM_PAINT()
END_MESSAGE_MAP()



// CMyLabel message handlers

CSize TextSize(CDC &dc, CString s)
{
	CRect	r(0,10,0,10);
	CSize	sz;
	sz.cy	=	dc.DrawText(s,r,DT_LEFT|DT_SINGLELINE|DT_NOCLIP|DT_CALCRECT);
	sz.cx	=	r.Width();
	return sz;
}

void CMyLabel::OnPaint()
{
	CPaintDC dc(this); 
	HDC		hMemDC;
	HDC		RotatedDC;
	HBITMAP hbm;
	HBITMAP hbm2;
	dc.SelectObject(GetFont());
	CString s;
	CRect	rectClient;
	GetClientRect(rectClient);

	this->GetWindowText(s);
	if( !m_bRotated )
	{
		if( m_bBold )
		{
			CFont m_BoldFont;
		}
		DrawText(dc, s, s.GetLength(), &rectClient, 0);
		return;
	}
	RECT TextRect;
	RECT RotatedTextRect;
	CSize	sz1, sz;
	sz.cx = 0;
	sz.cy = 0;
	sz1.cx = 0;
	sz1.cy = 0;

	int xx = 0;
	int n = 0;
	char *pText = NULL;
	char css[1024] = "";
	strcpy(css, s);
	pText = strtok(css, "\n");
	while( pText != NULL )
	{
		sz1 = TextSize(dc,pText);

		if(sz1.cx > sz.cx ) sz.cx = sz1.cx;
		if(sz1.cy > sz.cy ) sz.cy = sz1.cy;
		xx+=sz1.cx;
		pText = strtok(NULL, "\n");
		n++;
	}
//	sz.cy*=(n+3);
	sz.cy*=(n);
/*	sz.cy+=2;
	sz.cx+=2;*/
	 
	TextRect.left = 0;
	TextRect.top = 0;
	TextRect.right = sz.cx;
	TextRect.bottom = sz.cy;
	RotatedTextRect	= TextRect;
	RotatedTextRect.right = TextRect.bottom;
	RotatedTextRect.bottom = TextRect.right;

	hbm = CreateCompatibleBitmap(dc, 
								TextRect.right, 
								TextRect.bottom);

	hbm2 = CreateCompatibleBitmap(dc, 
								 TextRect.bottom,
								 TextRect.right);

	hMemDC = CreateCompatibleDC(dc.m_hDC);

	RotatedDC = CreateCompatibleDC(NULL);

	SelectObject(hMemDC, hbm);

	SelectObject(RotatedDC, hbm2);
	SelectObject(hMemDC, GetCurrentObject(dc, OBJ_FONT));
	::SetBkMode(hMemDC, TRANSPARENT);
	::SetBkMode(RotatedDC, TRANSPARENT);

	HBRUSH hBrush = CreateSolidBrush(m_BgColor);

/*	HBRUSH hBr1 = CreateSolidBrush(RGB(200,50,50));
	HBRUSH hBr2 = CreateSolidBrush(RGB(100,0,200));*/
	::SelectObject(hMemDC, hBrush);
	::SelectObject(RotatedDC, hBrush);

	::FillRect(hMemDC, &TextRect, hBrush);
	::FillRect(RotatedDC, &RotatedTextRect, hBrush);


	::FillRect(dc, &rectClient, hBrush);
	::SetTextColor(hMemDC, m_TextColor);
	
	DWORD dwStyle = GetStyle() & SS_TYPEMASK;
//	TextRect.left++;
	DrawText(hMemDC, s, s.GetLength(), &TextRect, dwStyle);
//	TextRect.left--;

	for( int i=0; i < TextRect.right; i++ )
	{
		for( int j=0; j < TextRect.bottom; j++ )
		{
			SetPixel(RotatedDC, j, RotatedTextRect.bottom - i - 1, GetPixel(hMemDC, i, j));
		}
	}
	BitBlt(dc, 
		   rectClient.left,
		   rectClient.bottom - RotatedTextRect.bottom,
		   rectClient.right, 
		   rectClient.bottom,
		   RotatedDC, 
		   0, 
		   0, 
		   SRCCOPY);
/*	BitBlt(g_pMon->GetSafeHdc(),
		5,15,500,500, RotatedDC, 0, 0,SRCCOPY);*/
	/*
	BitBlt(dc, 
		   rectClient.left,
		   rectClient.top, //- TextRect.bottom,
		   TextRect.bottom, 
		   TextRect.top,
		   RotatedDC, 
		   0, 
		   0, 
		   SRCCOPY);
   */
}
