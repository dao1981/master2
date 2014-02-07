#if !defined(AFX_DLGPRIHODOS_H__FCCD05A4_5F93_477B_AA8B_06176F76C185__INCLUDED_)
#define AFX_DLGPRIHODOS_H__FCCD05A4_5F93_477B_AA8B_06176F76C185__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPrihodOS.h : header file
//
#include "MaskEdit.h"
#include "DlgAccel1.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgPrihodOS dialog

class CDlgPrihodOS : public CDlgWithAccelerators
{
// Construction
public:
	int FillForm();
	CDlgPrihodOS(CWnd* pParent = NULL);   // standard constructor
    DWORD   dwIPR;
    DWORD   dwIPR2;
    CString strNum;
    CString strType;

    __int64 qwIKP;
    __int64 qwIZAP;
    int iUpdate;
    DWORD dwTKP;
    DWORD dwPriznRas;
    DWORD dwGruz;
    SYSTEMTIME st;
// Dialog Data
	//{{AFX_DATA(CDlgPrihodOS)
	enum { IDD = IDD_DIALOG_PRIHOD_OS };
	CEdit	m_EdNPos;
	CEdit	m_EdNVed;
	CEdit	m_EdType;
	CEdit	m_EdNum;
	CEdit	m_EdKlPr2;
	CMaskEdit	m_EdFIO;
	CEdit	m_EdNamePr;
	CEdit	m_EdKlPr;
	CMaskEdit	m_Dat3;
	CMaskEdit	m_Dat2;
	CMaskEdit	m_Dat1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPrihodOS)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPrihodOS)
	afx_msg void OnButtonSelectPr();
	afx_msg void OnSelectIzgPr();
	afx_msg void OnButtonFIO();
	virtual BOOL OnInitDialog();
	afx_msg void OnKillfocusEditKl1();
	afx_msg void OnKillfocusEditPr2();
	virtual void OnOK();
	virtual void OnCancel();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPRIHODOS_H__FCCD05A4_5F93_477B_AA8B_06176F76C185__INCLUDED_)
