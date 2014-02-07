#if !defined(AFX_DLGMAKELK_KPORDER_H__C2C43642_0B44_4BC2_A445_24E78966ACAF__INCLUDED_)
#define AFX_DLGMAKELK_KPORDER_H__C2C43642_0B44_4BC2_A445_24E78966ACAF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMakeLK_KPOrder.h : header file
//
#include "FastGrid.h"
#include "Maskedit.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMakeLK_KPOrder dialog

class CDlgMakeLK_KPOrder : public CDialog
{
// Construction
public:
	int iOsCount;
	void ResetList();
	__int64 qwILK;
	int iCurrentKP;
	int iCurrentNum;
	int ReOrd;
    DWORD dwFamID;
	CDlgMakeLK_KPOrder(CWnd* pParent = NULL);   // standard constructor
    
    __int64 p_qwIZAP[8];
    BOOL    bGotOrder;
// Dialog Data
	//{{AFX_DATA(CDlgMakeLK_KPOrder)
	enum { IDD = IDD_DIALOG_MKLK_KP_ORDER };
	CMaskEdit	m_EdFam;
	CFastGrid	m_List;
	CEdit	m_EdNum;
	CButton	m_ButOK;
	CButton	m_ButCancel;
	CButton	m_ButReord;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMakeLK_KPOrder)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMakeLK_KPOrder)
	afx_msg void OnButton_ReOrder();
	virtual BOOL OnInitDialog();
	afx_msg void OnChangeEdit();
	afx_msg void OnClickList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSetfocusEditNum();
	afx_msg void OnButtonFam();
	afx_msg void OnNext();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMAKELK_KPORDER_H__C2C43642_0B44_4BC2_A445_24E78966ACAF__INCLUDED_)
