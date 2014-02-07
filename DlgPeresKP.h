#if !defined(AFX_DLGPERESKP_H__F940B42B_D855_43FA_A21F_4AEA92E28E88__INCLUDED_)
#define AFX_DLGPERESKP_H__F940B42B_D855_43FA_A21F_4AEA92E28E88__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgPeresKP.h : header file
//

#include "FastGrid.h"
#include "maskedit.h"
#include "DlgAddPeres.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgPeresKP dialog

class CDlgPeresKP : public CDialog
{
// Construction
public:
	void SendVed(CDlgAddPeres *Dlg);
	void RefreshList();
	CDlgPeresKP(CWnd* pParent = NULL);   // standard constructor
    char cQuery[128];
//	__int64 qwIPERES[128];

    DWORD dwFiltIPR;
    int   iRecieveMode;
// Dialog Data
	//{{AFX_DATA(CDlgPeresKP)
	enum { IDD = IDD_DIALOG_PERES_VED };	
	CButton	m_ButNew;
	CButton	m_ButDelete;
	CButton	m_ButEdit;
	CButton	m_ButSendRecv;
	CButton	m_Radio2;
	CButton	m_ButSelect;
	CButton	m_ButFam;
	CMaskEdit	m_Ed6;
	CEdit	m_Ed5;
	CEdit	m_Ed4;
	CButton	m_ButPred;
	CEdit	m_Ed3;
	CEdit	m_Ed2;	
	CMaskEdit	m_Dat2;
	CMaskEdit	m_Dat1;
	CButton	m_Check5;
	CButton	m_Check4;
	CButton	m_Check3;
	CButton	m_Check2;	
	CButton	m_Check1;
	CFastGrid	m_List;
	CEdit	m_Ed1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgPeresKP)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgPeresKP)
	virtual BOOL OnInitDialog();
	afx_msg void OnNewPeres();
	afx_msg void OnButton1();
	afx_msg void OnButtonPrint();
	afx_msg void OnCheck1();
	afx_msg void OnCheck2();
	afx_msg void OnButton3();
	afx_msg void OnCheck3();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnChangeEditKleimo();
	afx_msg void OnChangeFilter();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnChangeEdit8();
	afx_msg void OnButton_Delete();
	afx_msg void OnButton_Send();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton_SendToASUV();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGPERESKP_H__F940B42B_D855_43FA_A21F_4AEA92E28E88__INCLUDED_)
