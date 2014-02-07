#pragma once


// CColoredButton

class CColoredButton : public CButton
{
	DECLARE_DYNAMIC(CColoredButton)

public:
	CColoredButton();
	virtual ~CColoredButton();

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	void SetBkColor(COLORREF crColor);

	COLORREF	m_crBkColor;
	CBrush m_brBkgnd;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	COLORREF m_color;
	BOOL m_selected;
};


