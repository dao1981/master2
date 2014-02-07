#if !defined(AFX_DLGRPTVU54_H__FB15F75D_4952_4113_8F3E_25DC5EC0BFE8__INCLUDED_)
#define AFX_DLGRPTVU54_H__FB15F75D_4952_4113_8F3E_25DC5EC0BFE8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRptVU54.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRptVU54 dialog
#include "MaskEdit.h"
class CDlgRptVU54 : public CDialog
{
// Construction
public:
	CDlgRptVU54(CWnd* pParent = NULL);   // standard constructor
    int iMode;
// Dialog Data
	//{{AFX_DATA(CDlgRptVU54)
	enum { IDD = IDD_DIALOG_RPT_VU64 };
	CMaskEdit	m_Dat2;
	CMaskEdit	m_Dat1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRptVU54)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRptVU54)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRPTVU54_H__FB15F75D_4952_4113_8F3E_25DC5EC0BFE8__INCLUDED_)
