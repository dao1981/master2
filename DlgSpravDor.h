#if !defined(AFX_DLGSPRAVDOR_H__A8BFC9F7_33CD_4654_8824_137285A35134__INCLUDED_)
#define AFX_DLGSPRAVDOR_H__A8BFC9F7_33CD_4654_8824_137285A35134__INCLUDED_
#include "FastGrid.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgSpravDor.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgSpravDor dialog

class CDlgSpravDor : public CDialog
{
// Construction
public:
	CDlgSpravDor(CWnd* pParent = NULL);   // standard constructor
    char  c_cFullName[32];
    char  c_cShortName[32];
    char  c_cKodDor[32];
    char  c_cDor[6];

    int   DlgMode;
    int   SelMode;
// Dialog Data
	//{{AFX_DATA(CDlgSpravDor)
	enum { IDD = IDD_DIALOG_SPRAV_DOROG };
	CFastGrid	m_List;
	CButton	m_ButOK;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgSpravDor)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgSpravDor)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnItemclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGSPRAVDOR_H__A8BFC9F7_33CD_4654_8824_137285A35134__INCLUDED_)
