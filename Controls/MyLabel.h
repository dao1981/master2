#pragma once


// CMyLabel

class CMyLabel : public CStatic
{
	DECLARE_DYNAMIC(CMyLabel)

public:
	CMyLabel();
	virtual ~CMyLabel();

	COLORREF m_BgColor;
	COLORREF m_TextColor;

	BOOL	m_bRotated;
	BOOL	m_bBold;
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
};


