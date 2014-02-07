#if !defined(AFX_DLGOBMERKP_H__10EC5723_7390_4671_858E_7D929FB642BD__INCLUDED_)
#define AFX_DLGOBMERKP_H__10EC5723_7390_4671_858E_7D929FB642BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgObmerKP.h : header file
//
#include "MaskEdit.h"
#include "DlgAccel1.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgObmerKP dialog

class CDlgObmerKP : public CDlgWithAccelerators
{
// Construction
public:
	CDlgObmerKP(CWnd* pParent = NULL);   // standard constructor

    void IniForm();
    __int64 qwIZAP;
    DWORD dwNKP;
    DWORD dwTKP;
    char cTKP[32];
//    DWORD dwFam;
    PRIH_KP Prih;
    PASP_KP Pasp;
    int iZp;
    int iFo;
    DWORD dwIprIzg;
    DWORD dwIprFor;
    DWORD dwIprOsv;
    DWORD dwNeisp;

	DWORD dwOld_IzgIPr;
	SYSTEMTIME stOld_IzgDat;
    
    int TestRazm1(double dMin, double dMax, double dVal);
// Dialog Data
	//{{AFX_DATA(CDlgObmerKP)
	enum { IDD = IDD_DIALOG_OBMER_KP };
	CMaskEdit	m_EdFIO;
	CMaskEdit	m_EdOsMidd;
	CMaskEdit	m_EdOsPred_l;
	CMaskEdit	m_EdOsPred_r;
	CMaskEdit	m_EdTD_l;
	CMaskEdit	m_EdTD_r;
	CButton		m_But4;
	CMaskEdit	m_EdD_l;
	CMaskEdit	m_EdD_r;
	CMaskEdit	m_EdOsPod_l;
	CMaskEdit	m_EdOsPod_r;
	CMaskEdit	m_EdGreb_r;
	CMaskEdit	m_EdGreb_l;
	CMaskEdit	m_EdObod_l;
	CMaskEdit	m_EdObod_r;
	CMaskEdit	m_EdProkat_l;
	CMaskEdit	m_EdProkat_r;
	CComboBox	m_Combo1;
	CMaskEdit	m_EdRasGr;
	CEdit	m_EdNeispName;
	CEdit	m_EdKodNeisp;
	CEdit	m_EdPrOsv;
	CEdit	m_EdPrFor;
	CMaskEdit	m_Date3;
	CMaskEdit	m_Date2;
	CMaskEdit	m_Date1;
	CEdit	m_EdPrIzg;
	CString	m_EditNKP;
	CString	m_EditTKP;
	//}}AFX_DATA
	CButton m_S3_L;
	CButton m_S3_R;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgObmerKP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgObmerKP)
	virtual BOOL OnInitDialog();
	afx_msg void OnButton5();
	afx_msg void OnButtonKlPr();
	afx_msg void OnButtonPrFor();
	afx_msg void OnButtonPrOsv();
	afx_msg void OnButtonNeisp();
	virtual void OnOK();
	afx_msg void OnKillfocusIzgOs();
	afx_msg void OnKillfocusPosFor();
	afx_msg void OnKillfocusPosOsv();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnEnChangeEdit15();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGOBMERKP_H__10EC5723_7390_4671_858E_7D929FB642BD__INCLUDED_)
