#if !defined(AFX_DLGBDSELECTREZ_H__7EFFDB39_6086_429B_9EBC_514AB4A2D824__INCLUDED_)
#define AFX_DLGBDSELECTREZ_H__7EFFDB39_6086_429B_9EBC_514AB4A2D824__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgBDSelectRez.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgBDSelectRez dialog
#include "FastGrid.h"
#include "afxwin.h"
#include "maskedit.h"

class CDlgBDSelectRez : public CDialog
{
// Construction
public:
	CDlgBDSelectRez(CWnd* pParent = NULL);   // standard constructor
	int	iMode;
	char cQ[1024];
    void RefreshList();
    bool bGotHeader;
    PRIHOD_PARAMS pp;
    CFont *Font;
    int  iParent; // 0 - Rem, 1 - Prihod
// Dialog Data
	//{{AFX_DATA(CDlgBDSelectRez)
	enum { IDD = IDD_DIALOG_SELECT_REZ };
	CButton	m_ButHistory;
	CButton	m_ButPerech;
	CFastGrid	m_List;
	CEdit	m_Ed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgBDSelectRez)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgBDSelectRez)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnRemoveKPButton();
	afx_msg void OnMakePasp();
	afx_msg void OnPerechenClicked();
	afx_msg void OnHistoryButton();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCancel();
	CButton m_ButRemoveKP;
	CButton m_ButMkPasp;
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedButtonVU55();
public:
	CMaskEdit m_EdSrch;
public:
	afx_msg void OnEnChangeEditFind();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGBDSELECTREZ_H__7EFFDB39_6086_429B_9EBC_514AB4A2D824__INCLUDED_)
