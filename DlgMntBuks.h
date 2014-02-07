#if !defined(AFX_DLGMNTBUKS_H__CB43FB85_DF27_485C_872B_8F39F381CAE5__INCLUDED_)
#define AFX_DLGMNTBUKS_H__CB43FB85_DF27_485C_872B_8F39F381CAE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgMntBuks.h : header file
//
#include "MaskEdit.h"
#include "DlgAccel1.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgMntBuks dialog

#define OS_D1       1
#define OS_D2       2
#define OS_D3       3
#define OS_D4       4
#define OVAL        5
#define KONUS       6
#define NP_LABK     7
#define RADZAZ_P    8
#define RADZAZ_Z    9
#define OS_ZAZ      10
#define VK_D1       11
#define NP_VK1      12
#define BUK_D1      13
#define BUK_D2      14

class CDlgMntBuks : public CDlgWithAccelerators
{
// Construction
public:
	CDlgMntBuks(CWnd* pParent = NULL);   // standard constructor
    void InitMaskedFields();
    void IniForm();
    void FormAkt();
    void CalcOval(int Side); // 0 - left, 1 - right
    void CalcConus(int Side);
    void CalcLabRing(int Side);
    void CalcIntRingP(int Side);
    void CalcIntRingZ(int Side);

// Dialog Data
	//{{AFX_DATA(CDlgMntBuks)
	enum { IDD = IDD_DIALOG_MNT_BUKS };
	CMaskEdit	m_FIO4;
	CMaskEdit	m_FIO3;
	CMaskEdit	m_FIO2;
	CMaskEdit	m_FIO1;
	CMaskEdit	m_n3;
	CMaskEdit	m_n5;
	CMaskEdit	m_n6;
	CMaskEdit	m_n4;
	CMaskEdit	m_n2;
	CMaskEdit	m_n1;
	CMaskEdit	m_i4;
	CMaskEdit	m_i2;
	CMaskEdit	m_i3;
	CMaskEdit	m_i1;
	CEdit	m_spart;
	CMaskEdit	m_pdat4;
	CMaskEdit	m_pdat3;
	CMaskEdit	m_pdat2;
	CMaskEdit	m_pdat1;
	CEdit	m_pnum4;
	CEdit	m_pnum3;
	CEdit	m_pnum2;
	CEdit	m_pnum1;
	CButton	m_PS;
	CMaskEdit	m_Date;
	CComboBox	m_Cb12;
	CComboBox	m_Cb11;
	CComboBox	m_Cb10;
	CComboBox	m_Cb9;
	CComboBox	m_Cb8;
	CComboBox	m_Cb7;
	CComboBox	m_Cb6;
	CComboBox	m_Cb5;
	CComboBox	m_Cb4;
	CComboBox	m_Cb3;
	CMaskEdit	m_h4;
	CMaskEdit	m_h3;
	CMaskEdit	m_h2;
	CMaskEdit	m_h1;
	CMaskEdit	m_g4;
	CMaskEdit	m_g3;
	CMaskEdit	m_g2;
	CMaskEdit	m_g1;
	CMaskEdit	m_f8;
	CMaskEdit	m_f7;
	CMaskEdit	m_f6;
	CMaskEdit	m_f5;
	CMaskEdit	m_f4;
	CMaskEdit	m_f3;
	CMaskEdit	m_f2;
	CMaskEdit	m_f1;
	CMaskEdit	m_e2;
	CMaskEdit	m_e4;
	CMaskEdit	m_e3;
	CMaskEdit	m_e1;
	CMaskEdit	m_d8;
	CMaskEdit	m_d6;
	CMaskEdit	m_d2;
	CMaskEdit	m_d16;
	CMaskEdit	m_d15;
	CMaskEdit	m_d14;
	CMaskEdit	m_d13;
	CMaskEdit	m_d12;
	CMaskEdit	m_d11;
	CMaskEdit	m_d10;
	CMaskEdit	m_d9;
	CMaskEdit	m_d7;
	CMaskEdit	m_d5;
	CMaskEdit	m_d4;
	CMaskEdit	m_d3;
	CMaskEdit	m_d1;
	CComboBox	m_Cb2;
	CComboBox	m_Cb1;
	CString	m_strNumKP;
	CString	m_strTKP;	
	//}}AFX_DATA

    PRIH_KP Prih;
    PASP_KP Pasp;

    DWORD dwTKP;
    DWORD dwRem;
    unsigned __int64 qwIZAP;

    void GetDopuskValues();
    int  CheckVal(double Value, int Kind);

    void RefreshCalculated();
    void SetComboItem(CComboBox *b, CString strMask);
    bool CheckWithRings();

    bool   bHaveDopusk;

    double vd_OS_d1_1;
    double vd_OS_d1_2;
    double vd_OS_d2_1;
    double vd_OS_d2_2;
    double vd_OS_d3_1;
    double vd_OS_d3_2;
    double vd_OS_d4_1;
    double vd_OS_d4_2;

    double vd_OVAL;
    double vd_KONUS;
    double vd_NP_LABK1, vd_NP_LABK2;
    double vd_RADZAZ_P, vd_RADZAZ_Z;
    
    double vd_BUK_D1_1, vd_BUK_D1_2, vd_BUK_D2_1, vd_BUK_D2_2;
    double vd_OS_ZAZ1, vd_OS_ZAZ2, vd_VK_D1_1, vd_VK_D1_2;

    double vd_NP_VK1_1, vd_NP_VK1_2;
    
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgMntBuks)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgMntBuks)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnMasterButton();
	afx_msg void OnOTKButton();
	afx_msg void OnSles1Button();
	afx_msg void OnSles2Button();
	afx_msg void OnPSClick();
	afx_msg void OnChangePr_R();
	afx_msg void OnChangePr_L();
	afx_msg void OnChange_d1R();
	afx_msg void OnChange_d2R();
	afx_msg void OnChange_d1L();
	afx_msg void OnChange_d2L();
	afx_msg void OnChange_Recall();
	afx_msg void OnChange_Recall_Left();
	afx_msg void OnRingVn_ZR();
	afx_msg void OnRingVn_ZL();
	afx_msg void OnRingVn_PR();
	afx_msg void OnRingVn_PL();
	afx_msg void OnArrowUp();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGMNTBUKS_H__CB43FB85_DF27_485C_872B_8F39F381CAE5__INCLUDED_)
