#if !defined(AFX_DLGMAKELK_H__D50DE85D_626F_46E8_8BF9_C5EC9EA675BA__INCLUDED_)
#define AFX_DLGMAKELK_H__D50DE85D_626F_46E8_8BF9_C5EC9EA675BA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMakeLK.h : header file
//

#include "MaskEdit.h"
#include "FastGrid.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgMakeLK dialog

class CDlgMakeLK : public CDialog
{
// Construction
public:
	__int64 qwILK;
	CDlgMakeLK(CWnd* pParent = NULL);   // standard constructor
    int iOsCount;
    __int64 p_qwIZAP[8];

    BOOL bGotKPOrder;
    BOOL bKPOrderRecorded;
    DWORD dwMasterKP_ID;

// Dialog Data
	//{{AFX_DATA(CDlgMakeLK)
	enum { IDD = IDD_DIALOG_MKLK };
	CMaskEdit	m_Dat1;
	CMaskEdit	m_Dat2;
	CEdit	m_Ed2;
	CEdit	m_EdPrRem;
	CEdit	m_EdNum;
	CEdit	m_Ed1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMakeLK)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMakeLK)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton_KP();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMAKELK_H__D50DE85D_626F_46E8_8BF9_C5EC9EA675BA__INCLUDED_)
