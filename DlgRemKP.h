#if !defined(AFX_DLGREMKP_H__41445FE6_51BB_459C_AB3B_37534511C5CC__INCLUDED_)
#define AFX_DLGREMKP_H__41445FE6_51BB_459C_AB3B_37534511C5CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRemKP.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRemKP dialog
#include "MaskEdit.h"
#include "DlgAccel1.h"
class CDlgRemKP : public CDlgWithAccelerators
{
// Construction
public:
	CDlgRemKP(CWnd* pParent = NULL);   // standard constructor
    PASP_KP Pasp;
    PRIH_KP Prih;
    int  iVR;
    void IniForm();
    void EnableRabot(BOOL);

    DWORD dwRab[4];

    DWORD dwKNPr;
    DWORD dwKNObt;
    DWORD dwSBU;

    char  cSBU[8];
    char  cKN[32];

    char  cDVR[16], cDNG[16];
    char  cFamSles1[64];

    void CallKadrDlg(int Bn);
    BOOL  bStarted;
// Dialog Data
	//{{AFX_DATA(CDlgRemKP)
	enum { IDD = IDD_DIALOG_REMDEFEKT };
	CMaskEdit	m_date1;
	CMaskEdit	m_Ed13;
	CMaskEdit	m_EdOsv;
	CMaskEdit	m_EdF4;
	CMaskEdit	m_EdF8;
	CMaskEdit	m_EdF7;
	CMaskEdit	m_EdF5;
	CMaskEdit	m_EdF3;
	CMaskEdit	m_EdF6;
	CMaskEdit	m_EdF2;
	CMaskEdit	m_EdF1;
	CButton	m_But7;
	CButton	m_But6;
	CButton	m_But5;
	CButton	m_But3;
	CButton	m_But4;
	CEdit	m_Ed4;
	CEdit	m_Ed3;
	CEdit	m_Ed2;
	CEdit	m_Ed1;
	CEdit	m_Ed12;
	CEdit	m_Ed11;
	CEdit	m_Ed10;
	CEdit	m_Ed9;
	CEdit	m_Ed8;
	CEdit	m_Ed7;
	CEdit	m_Ed6;
	CEdit	m_Ed5;
	CComboBox	m_Combo4;
	CComboBox	m_Combo3;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	CComboBox	m_CbM110;
	CString	m_strNKP;
	CString	m_strTKP;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRemKP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRemKP)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnButtonSles();
	afx_msg void OnButton3F1();
	afx_msg void OnButton4F2();
	afx_msg void OnButton5F3();
	afx_msg void OnButton6F4();
	afx_msg void OnButton7F5();
	afx_msg void OnButton8F6();
	afx_msg void OnButton17F7();
	afx_msg void OnButton18F7();
	afx_msg void OnButtonOsv();
	afx_msg void OnAddToBase();
	afx_msg void OnChangeVR();
	afx_msg void OnChangeVidRem();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnChangeEdit1();
	afx_msg void OnChangeEdit7();
	virtual void OnCancel();
	afx_msg void OnShiftF2();
	afx_msg void OnShiftF3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGREMKP_H__41445FE6_51BB_459C_AB3B_37534511C5CC__INCLUDED_)
