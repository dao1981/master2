#if !defined(AFX_DLGSHOWTWIN_H__740626DD_46DD_4439_8EE7_36F586834588__INCLUDED_)
#define AFX_DLGSHOWTWIN_H__740626DD_46DD_4439_8EE7_36F586834588__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgShowTwin.h : header file
//
#include "FastGrid.h"
#include "afxwin.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgShowTwin dialog

class CDlgShowTwin : public CDialog
{
// Construction
public:
	CDlgShowTwin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlgShowTwin)
	enum { IDD = IDD_DIALOG_SHOW_DV };
	CFastGrid	m_List;
	CEdit	m_TKP;
	CEdit	m_NKP;
	//}}AFX_DATA
    char  cNKP[32];
    DWORD dwTKP;
    char  cTKP[64];

    __int64 qwIKP;

    BOOL    isOs;

    int     iZp, iFo;
    int     iRez;
    DWORD   dwGruz;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgShowTwin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgShowTwin)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnAddNewTwinClick();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClicked_V_ODNU();
	CButton m_ButIntergrTwin;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSHOWTWIN_H__740626DD_46DD_4439_8EE7_36F586834588__INCLUDED_)
