#if !defined(AFX_DLGSPRAVSMP_H__0B2B6710_F2D2_4F53_8219_46CDA566DE5E__INCLUDED_)
#define AFX_DLGSPRAVSMP_H__0B2B6710_F2D2_4F53_8219_46CDA566DE5E__INCLUDED_
#include "FastGrid.h"
#include "maskedit.h"
#include "afxwin.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSpravSmp.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSpravSmp dialog

class CDlgSpravSmp : public CDialog
{
// Construction
public:
	CDlgSpravSmp(CWnd* pParent = NULL);   // standard constructor
    void UpdateListByQuery();
    int DlgMode;
    char cQuery[512];
    DWORD dwID[255];
    DWORD dwRet;
    char cRet[64];
    int Style;
    char c_retText[80];
    char c_retText2[80];
	char c_retText3[80];
// Dialog Data
	//{{AFX_DATA(CDlgSpravSmp)
	enum { IDD = IDD_DIALOG_SPR };
	CFastGrid	m_List;
	CButton	m_bOK;
	int iGridMark;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSpravSmp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSpravSmp)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnListItemclick(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
public:
	CMaskEdit m_EdFind;
public:
	CStatic m_Lab1;
public:
	afx_msg void OnEnChangeEditFind();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSPRAVSMP_H__0B2B6710_F2D2_4F53_8219_46CDA566DE5E__INCLUDED_)
