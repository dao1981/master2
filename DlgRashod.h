#if !defined(AFX_DLGRASHOD_H__2EC98832_BAB8_440C_80BF_8EDF5FACDE1E__INCLUDED_)
#define AFX_DLGRASHOD_H__2EC98832_BAB8_440C_80BF_8EDF5FACDE1E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRashod.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRashod dialog
#include "MaskEdit.h"
#include "DlgAccel1.h"

class CDlgRashod : public CDlgWithAccelerators
{
// Construction
public:
	CDlgRashod(CWnd* pParent = NULL);   // standard constructor
    DWORD dwTRemVag[64];
    __int64 qwIZAP;    
    __int64 qwIPeres;
    PRIH_KP Prih;
	PASP_KP Pasp;
    DWORD dwKodRem;

    int InitFormValues();
//    DWORD dwIFAM;
    DWORD dwIPR;

    bool bCh1;

// Dialog Data
	//{{AFX_DATA(CDlgRashod)
	enum { IDD = IDD_DIALOG_RASHOD_KP };
	CMaskEdit	m_Date1;
	CMaskEdit	m_EdFam;
	CEdit	m_EdPrName;
	CButton	m_Check1;
	CEdit	m_VRem;
	CComboBox	m_Combo1;
	CButton	m_But1;
	CEdit	m_EdNSpis;
	CEdit	m_EdNVed;
	CEdit	m_EdPred;
	CMaskEdit m_EdSobst;
	CComboBox	m_Combo2;
	CMaskEdit	m_EdNVag;
	CString	m_strNKP;
	CString	m_strTKP;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRashod)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRashod)
	afx_msg void OnRadio1();
	afx_msg void OnButton1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	virtual BOOL OnInitDialog();
	afx_msg void OnButton2();
	virtual void OnOK();
	afx_msg void OnKillfocusKlPr();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedButton_Sobst();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGRASHOD_H__2EC98832_BAB8_440C_80BF_8EDF5FACDE1E__INCLUDED_)
