#if !defined(AFX_DLGDEPSELECT_H__DACA3735_7B53_4A70_B9F8_DF673C0C3338__INCLUDED_)
#define AFX_DLGDEPSELECT_H__DACA3735_7B53_4A70_B9F8_DF673C0C3338__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgDepSelect.h : header file
//

#include "FastGrid.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgDepSelect dialog

class CDlgDepSelect : public CDialog
{
// Construction
public:
	CDlgDepSelect(CWnd* pParent = NULL);   // standard constructor

    DWORD wDep;
	DWORD dwMainDep;
// Dialog Data
	//{{AFX_DATA(CDlgDepSelect)
	enum { IDD = IDD_DIALOG_SEL_CURRENT_DEP };
	CFastGrid	m_List;
	//}}AFX_DATA
	int	iMode; // если 1 то выбирает оператор дочерние предпри€ти€

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDepSelect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgDepSelect)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnDblclkList1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
protected:
	virtual void OnCancel();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGDEPSELECT_H__DACA3735_7B53_4A70_B9F8_DF673C0C3338__INCLUDED_)

