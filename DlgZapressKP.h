#if !defined(AFX_DLGZAPRESSKP_H__F43A535D_E9B2_415E_866D_03C5771CFC5A__INCLUDED_)
#define AFX_DLGZAPRESSKP_H__F43A535D_E9B2_415E_866D_03C5771CFC5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgZapressKP.h : header file
//
#include "DlgAccel1.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgZapressKP dialog
#include "MaskEdit.h"

class CDlgZapressKP : public CDlgWithAccelerators
{
// Construction
public:
	void FillFormFields();
	CDlgZapressKP(CWnd* pParent = NULL);   // standard constructor
    DWORD   dwIPR_IzOs;
    DWORD   dwIPR_R;
    DWORD   dwIPR_L;

    int CheckLimits();
/*    double dOsPodst1, dOsPodst2;
    double dDsk1, dDsk2;
    double dTsk1, dTsk2;
    double dDlsk1, dDlsk2;
    double dNzapr1, dNZapr2;
    double dUzapr1, dUzapr2;*/

    __int64 qwIZAP;
    __int64 qwIKP;
    DWORD   dwPriznRas;
    DWORD   dwGruz;
    int     iUpdate;
    DWORD dwTKP, dwTypeRem;
    CString strNum;
    CString strType;

    double dOS_PODST1;
    double dOS_PODST2;
    double dDSK1;
    double dDSK2;
    int    iTSK1;
    int    iTSK2;
    int    iDLSK1;
    int    iDLSK2;
    double dNZapr1;
    double dNZapr2;
    int    iUZapr1;
    int    iUZapr2;


// Dialog Data
	//{{AFX_DATA(CDlgZapressKP)
	enum { IDD = IDD_DIALOG_ZAPRES_KP };
	CEdit	m_EdType;
	CEdit	m_EdNum;
	CButton	m_Check2;
	CButton	m_Check1;
	CMaskEdit	m_EdNPWheel_L;
	CMaskEdit	m_EdNPWheel_R;
	CMaskEdit	m_EdNpos;
	CMaskEdit	m_EdNDiag;
	CMaskEdit	m_EdYear_L;
	CMaskEdit	m_EdYear_R;
	CMaskEdit	m_EdNWheel_L;
	CMaskEdit	m_EdNWheel_R;
	CMaskEdit	m_d12;
	CMaskEdit	m_d11;
	CMaskEdit	m_d10;
	CMaskEdit	m_d9;
	CMaskEdit	m_d8;
	CMaskEdit	m_d7;
	CMaskEdit	m_d6;
	CMaskEdit	m_d5;
	CMaskEdit	m_d4;
	CMaskEdit	m_d3;
	CMaskEdit	m_d2;
	CMaskEdit	m_d1;
	CMaskEdit	m_FIO2;
	CMaskEdit	m_FIO1;
	CEdit	m_EdPrName_L;
	CEdit	m_EdKlPr_L;
	CEdit	m_EdPrName_R;
	CEdit	m_EdKlPr_R;
	CEdit	m_EdKlPr1;
	CMaskEdit	m_Dat2;
	CMaskEdit	m_Dat1;
	//}}AFX_DATA
	CMaskEdit	m_EdParkNum;
	CMaskEdit m_DatRasfor;
	CMaskEdit m_EdFamRasfor;

	CButton m_ButSles;
	CStatic m_Lab1;
	CStatic m_Lab2;
	CButton m_CheckT;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgZapressKP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgZapressKP)
	afx_msg void OnButPr1();
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusEdKlPr1();
	afx_msg void OnButtonKlPr_R();
	afx_msg void OnButtonKlPr_L();
	afx_msg void OnKillfocusEdiKlPr_R();
	afx_msg void OnKillfocusEdiKlPr_L();
	afx_msg void OnButtonFIO1();
	afx_msg void OnButtonFIO2();
	virtual void OnOK();
	afx_msg void OnChangeEdit_d1();
	afx_msg void OnChangeEdit_d3();
	afx_msg void OnChangeEdit_d2();
	afx_msg void OnChangeEdit_d4();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCheck22();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGZAPRESSKP_H__F43A535D_E9B2_415E_866D_03C5771CFC5A__INCLUDED_)
