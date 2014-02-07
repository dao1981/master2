#if !defined(AFX_DLGPRIHODKP_H__392EE19D_F4B8_4F28_AE42_6E1117991721__INCLUDED_)
#define AFX_DLGPRIHODKP_H__392EE19D_F4B8_4F28_AE42_6E1117991721__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPrihodKP.h : header file
//
#include "MaskEdit.h"
#include "DlgAccel1.h"

/////////////////////////////////////////////////////////////////////////////
// CDlgPrihodKP dialog

class CDlgPrihodKP : public CDlgWithAccelerators
{
// Construction
public:
	CDlgPrihodKP(CWnd* pParent = NULL);   // standard constructor
    afx_msg void OnCombo1Change();

	int iInitFrom;

	__int64 qwIZap;
	__int64 qwIKP;
	char cNKP[32];
	int iTKP;
	char cKlPrIzg[32];
	SYSTEMTIME stDatIzg;


    DWORD dwTypeRem[512];
    DWORD dwItr[512];
    bool  ZapIzOs();
    int   iMode;
    void  IniForm();
    void  IniFromGiven();
	void  IniObmer();
    int   iZp;
    int   iFo;
    PASP_KP PaspKp;
    PRIH_KP PrihKp;
    bool  bStarted;

    DWORD dwPrPeres;
    DWORD dwPrIzgot;
    DWORD dwPrPosFor;
    DWORD dwPrPosOsv;

	DWORD dwKlPrIzgot;
    DWORD dwKlPrPosFor;
    DWORD dwKlPrPosOsv;


    DWORD dwIFam;
	DWORD dwOld_IzgIPr;
	SYSTEMTIME stOld_IzgDat;

    char  cTypePrIzgot[32];
    DWORD dwNeispId;

// Dialog Data
	//{{AFX_DATA(CDlgPrihodKP)
	enum { IDD = IDD_DIALOG_PRIHOD_KP };
	CButton	m_ButPasp;
	CMaskEdit	m_DatPost;
	CComboBox	m_Combo4;
	CEdit	m_EdTKP;
	CEdit	m_EdNKP;
	CMaskEdit	m_EdFIOPrih;
	CButton	m_ButFIO;
	CMaskEdit	m_Edit5;
	CMaskEdit	m_Edit4;
	CMaskEdit	m_Edit6;
	CMaskEdit	m_Edit7;
	CMaskEdit	m_DatOsv;
	CMaskEdit	m_DatFor;
	CMaskEdit	m_DatIzg;
	CMaskEdit	m_Date5;
	CMaskEdit	m_EdSobst;

	CEdit	m_Edit17;
	CComboBox	m_Combo3;
	CEdit	m_EdNeispName;
	CMaskEdit	m_EdNeispCode;
/*
	CMaskEdit	m_EdKlPrOsv;
	CMaskEdit	m_EdKlPrFor;
	CMaskEdit	m_EdKlPrIzg;
*/
	CEdit	m_EdKlPrOsv;
	CEdit	m_EdKlPrFor;
	CEdit	m_EdKlPrIzg;

	CMaskEdit	m_Edit15;
	CButton	m_Button6;
	CMaskEdit	m_Edit14;
	CMaskEdit	m_EditVag;
	CButton	m_Check2;
	CButton	m_Check1;
	CButton	m_CheckBox1;
	CButton m_SendToAsuv;
	CComboBox	m_Combo2;
	CComboBox	m_Combo1;
	CComboBox	m_ComboTKP;

	CMaskEdit	m_EdD_l;
	CMaskEdit	m_EdD_r;
	CMaskEdit	m_EdGreb_r;
	CMaskEdit	m_EdGreb_l;
	CMaskEdit	m_EdObod_l;
	CMaskEdit	m_EdObod_r;
	CMaskEdit	m_EdProkat_l;
	CMaskEdit	m_EdProkat_r;

	CString	m_strNumKP;
	CString	m_strTypeKP;
	CString	m_Edit8Text;
	CString	m_Edit6Text;
	int		m_Cb1Index;
	int		m_Cb2ndex;
	CString	m_strNumVag;
	CString	m_strFIO;
	//}}AFX_DATA
	CButton	m_CheckSteel;
	CMaskEdit m_EdParkNum;
	CComboBox m_CbSteel;
	CStatic m_LabTkp;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPrihodKP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPrihodKP)
	virtual BOOL OnInitDialog();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnButton6();
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton2();
	afx_msg void OnChangeEdit9();
	afx_msg void OnAddToBase();
	afx_msg void OnChangeEdit14();
	afx_msg void OnKillfocusPrIzg();
	afx_msg void OnSendToASUV();
	afx_msg void OnKillfocusPrForOsv();
	afx_msg void OnKillfocusPrPosOsv();
	afx_msg void OnKillfocusVagNum();
	afx_msg void OnSetfocusPrIzg();
	afx_msg void OnKillfocusEdit_PR1();
	afx_msg void OnButtonPasport();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButtonSelSobst();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPRIHODKP_H__392EE19D_F4B8_4F28_AE42_6E1117991721__INCLUDED_)
