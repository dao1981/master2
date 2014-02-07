#if !defined(AFX_DLGADDREMVAG_H__543848D6_E4A5_4688_8A86_5ACD5A5FAD00__INCLUDED_)
#define AFX_DLGADDREMVAG_H__543848D6_E4A5_4688_8A86_5ACD5A5FAD00__INCLUDED_

#include "MaskEdit.h"
#include "DlgAccel1.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgAddRemVag.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgAddRemVag dialog

class CDlgAddRemVag : public CDlgWithAccelerators
{
// Construction
public:
	__int64 m_qwILKVag;
	bool bIsEdit;
	bool bSetDateNachRem;
    bool bSetDatSbor;
	bool bSetDatPerechNeisp;

	bool bSetDat4624;

	SYSTEMTIME m_stDateNachRem;
    SYSTEMTIME m_stDatSbor;	
	SYSTEMTIME m_stDatPerechNeisp;

	SYSTEMTIME m_stDat4624;
	int m_TypeIndex;
	void SprFamSelect(int ButNum);
    void IniForm();
	CString m_strNLK;
	char m_cVktTel[10];
	char m_cVktKP[10];
	char m_cPdkTel[10];
	char m_cPdkKP[10];
	CString m_strKodSobst;
	CString m_strNameSobst;

	CDlgAddRemVag(CWnd* pParent = NULL);   // standard constructor

	DWORD m_dwIFam1;
	DWORD m_dwIFam2;
	DWORD m_dwIFam3;
	DWORD m_dwIFam4;
	DWORD m_dwIFam5;

	CString m_strFam1;
	CString m_strFam2;
	CString m_strFam3;
	CString m_strFam4;
	CString m_strFam5;

	CString m_retNVag;
	CString m_retVRem;
	CString m_retDatNachRem;
	CString m_retKPOut;
	CString m_retKPIn;
	CString m_retDatRem;
	CString m_retNLK;
	CString m_retClose;
	__int64 m_retILK;
// Dialog Data
	//{{AFX_DATA(CDlgAddRemVag)
	enum { IDD = IDD_DIALOG_ADD_VAG };
	CMaskEdit	m_DatSbor;
	CMaskEdit	m_DatCome;
	CButton	m_Check;
	CEdit	m_nVan;
	CComboBox	m_RemKind;
	BOOL	m_bCheck;
	CString	m_strNVag;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgAddRemVag)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgAddRemVag)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CMaskEdit m_Hour;
	CMaskEdit m_Min1;
	CMaskEdit m_Hour2;
	CMaskEdit m_Min2;

	CMaskEdit m_DatNachRem;
	CMaskEdit m_Hour3;
	CMaskEdit m_Min3;

	CEdit m_Dat4624;
	CMaskEdit m_EdNLK;
	CEdit m_EdPdkTel;
	CEdit m_EdPdkKP;
	CEdit m_EdVktTel;
	CEdit m_EdVktKP;
	CMaskEdit m_EdKodSobst;
	CEdit m_EdNameSobst;

	CMaskEdit m_EdFio1;
	CMaskEdit m_EdFio2;
	CMaskEdit m_EdFio3;
	CMaskEdit m_EdFio4;
	CMaskEdit m_EdFio5;

	afx_msg void OnBnClickedSobst();
	afx_msg void OnBnClickedButtonFio1();
	afx_msg void OnBnClickedButtonFio2();
	afx_msg void OnBnClickedButtonFio3();
	afx_msg void OnBnClickedButtonFio4();
	afx_msg void OnBnClickedButtonFio5();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGADDREMVAG_H__543848D6_E4A5_4688_8A86_5ACD5A5FAD00__INCLUDED_)
