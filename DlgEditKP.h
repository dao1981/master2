#if !defined(AFX_DLGEDITKP_H__8CB2D10D_8435_411B_A509_DFD917690241__INCLUDED_)
#define AFX_DLGEDITKP_H__8CB2D10D_8435_411B_A509_DFD917690241__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgEditKP.h : header file
//
#include "MaskEdit.h"
#include "afxwin.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgEditKP dialog

class CDlgEditKP : public CDialog
{
// Construction
public:
	CDlgEditKP(CWnd* pParent = NULL);   // standard constructor

    DWORD dwTKP[256];
    DWORD dwRemKP[256];
    int   iMode;
    DWORD dwITKP;
    DWORD dwTREM;
// Dialog Data
	//{{AFX_DATA(CDlgEditKP)
	enum { IDD = IDD_DIALOG_TKP_ED };
	CMaskEdit	m_Edit1;
	CMaskEdit	m_Edit16;
	CMaskEdit	m_Edit2;
	CMaskEdit	m_Edit30;
	CMaskEdit	m_Edit3;
	CMaskEdit	m_Edit29;
	CMaskEdit	m_Edit7;
	CMaskEdit	m_Edit63;
	CMaskEdit	m_Edit61;
	CMaskEdit	m_Edit60;
	CMaskEdit	m_Edit59;
	CMaskEdit	m_Edit5;
	CMaskEdit	m_Edit68;
	CMaskEdit	m_Edit67;
	CMaskEdit	m_Edit66;
	CMaskEdit	m_Edit65;
	CMaskEdit	m_Edit64;
	CMaskEdit	m_Edit62;
	CMaskEdit	m_Edit57;
	CMaskEdit	m_Edit58;
	CMaskEdit	m_Edit56;
	CMaskEdit	m_Edit55;
	CMaskEdit	m_Edit53;
	CMaskEdit	m_Edit54;
	CMaskEdit	m_Edit52;
	CMaskEdit	m_Edit51;
	CMaskEdit	m_Edit49;
	CMaskEdit	m_Edit50;
	CMaskEdit	m_Edit48;
	CMaskEdit	m_Edit47;
	CMaskEdit	m_Edit45;
	CMaskEdit	m_Edit44;
	CMaskEdit	m_Edit41;
	CMaskEdit	m_Edit42;
	CMaskEdit	m_Edit40;
	CMaskEdit	m_Edit39;
	CMaskEdit	m_Edit38;
	CMaskEdit	m_Edit37;
	CMaskEdit	m_Edit35;
	CMaskEdit	m_Edit36;
	CMaskEdit	m_Edit34;
	CMaskEdit	m_Edit33;
	CMaskEdit	m_Edit31;
	CMaskEdit	m_Edit32;
	CMaskEdit	m_Edit27;
	CMaskEdit	m_Edit28;
	CMaskEdit	m_Edit26;
	CMaskEdit	m_Edit25;
	CMaskEdit	m_Edit24;
	CMaskEdit	m_Edit23;
	CMaskEdit	m_Edit21;
	CMaskEdit	m_Edit22;
	CMaskEdit	m_Edit20;
	CMaskEdit	m_Edit19;
	CMaskEdit	m_Edit17;
	CMaskEdit	m_Edit18;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgEditKP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgEditKP)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	CButton m_bOK;
	afx_msg void OnBnClickedButtonTpNSI();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGEDITKP_H__8CB2D10D_8435_411B_A509_DFD917690241__INCLUDED_)
