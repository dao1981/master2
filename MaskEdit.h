#if !defined(AFX_MASKEDIT_H__74FDF8F3_050B_4481_A14B_8A1F396D6EBD__INCLUDED_)
#define AFX_MASKEDIT_H__74FDF8F3_050B_4481_A14B_8A1F396D6EBD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MaskEdit.h : header file
//
#include "EmplArray.h"
/////////////////////////////////////////////////////////////////////////////
// CMaskEdit window
#define ME_FIRST_ROW 1
#define ME_LAST_ROW  2
#define ME_SCROLL_NORMAL 4

class CMaskEdit : public CEdit
{
// Construction
//	DECLARE_DYNAMIC(CMaskEdit)
public:
	CMaskEdit();
    char cMask[64];
    int  iMode; // 0 - normal, 1 - Date, 2 - masked double, 3 mm.yyyy, 4-Fam, 5-Hard Fam
    int  Prec;  // digits before dot (only for mode 2)
    int  Scale; // digits after dot (only for mode 2)
    DWORD   dwData;
	DWORD	dwMaxLength; //if mode = 0

	BOOL	EnableWindow( BOOL bEnable = 1);
    void    SetMode(int iMode, BOOL bIsColored = FALSE, DWORD dwLength = 0);
    void    QInit(int Style, BOOL bStyleColored = 0);
    CString GetSQLDate();

    int     GetAsDate(SYSTEMTIME *);
    SYSTEMTIME GetAsSystemTime();
    double  GetAsDouble();
    int     GetAsString(char *);
    CString GetString(BOOL bWithNULL = FALSE);
    void    GetTime(SYSTEMTIME *);    

    int  InitDate();

    int  SetDate(SYSTEMTIME *);    
    int  SetTime(SYSTEMTIME *);
    int  SetValue(DWORD dwValue);
    int  SetValue(double dValue);
    int  SetAbsValue(double dV);
    int  SetAbsMaxValue(double dV1, double dV2);

    bool isValid();
    bool isNull();


    int     SetData(DWORD dwNum);
    DWORD   GetData();

    BOOL    bGotData;
//    bool isEmpty();
// Attributes    
    CEmplArray *lpEmpl;
    static DWORD dwBuffer;

	int iDontAskForFIO;

	COLORREF	m_crNormalTextColor;
	COLORREF	m_crNormalBkColor;
	COLORREF	m_crActiveTextColor;
	COLORREF	m_crActiveBkColor;

	COLORREF	m_crTextColor;
	COLORREF	m_crBkColor;
	CBrush m_brBkgnd;
	BOOL	bColored;

	DWORD		dwFlags;
	CString		*lpStrArray;
	DWORD		dwStrArraySize;
	int		iActive;
public:
private:    

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMaskEdit)
	//}}AFX_VIRTUAL

// Implementation
public:
	CString GetAsString();
	int SetFamTextByID(int dwIFAM);
	CString GetDataAsString(BOOL ZeroAsNull = FALSE);    
    virtual ~CMaskEdit();

	// Generated message map functions
protected:
	//{{AFX_MSG(CMaskEdit)
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKillfocus();
	afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetfocus();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg int OnMouseActivate(CWnd* pDesktopWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
public:
	void SetDate(SQL_DATE_STRUCT Dat);
	void SetTextColor(COLORREF crColor);
	void SetBkColor(COLORREF crColor);
	afx_msg HBRUSH CtlColor(CDC * pDC, UINT nCtlColor);
	CString GetText(void);
	DWORD GetAsDWord(void);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MASKEDIT_H__74FDF8F3_050B_4481_A14B_8A1F396D6EBD__INCLUDED_)
