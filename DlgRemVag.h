#if !defined(AFX_DLGREMVAG_H__C37C52C7_AEA2_4ABE_B137_7A9F9F166311__INCLUDED_)
#define AFX_DLGREMVAG_H__C37C52C7_AEA2_4ABE_B137_7A9F9F166311__INCLUDED_

#include "FastGrid.h"
#include "MaskEdit.h"
#include "NewMenu.h"
#include "afxwin.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgRemVag.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CDlgRemVag dialog

class CDlgRemVag : public CDialog
{
// Construction
public:
	void EditSelectedVan();
	CMenu * m_Menu;
	int RefreshVagList(CString);
	int RefreshList();
	CDlgRemVag(CWnd* pParent = NULL);   // standard constructor

    CString strNVagMask;
    CString strZakr;
// Dialog Data
	//{{AFX_DATA(CDlgRemVag)
	enum { IDD = IDD_DIALOG_REMVAG };
	CButton	m_Check7;
	CEdit	m_EdVagCount;
	CComboBox	m_Cb;
	CButton	m_Check6;
	CEdit	m_EdCount;
	CEdit	m_EdMaskVan;
	CButton	m_BnSelect;
	CButton	m_Check5;
	CButton	m_Check4;
	CButton	m_Check3;
	CButton	m_Check2;
	CMaskEdit	m_Dat4;
	CMaskEdit	m_Dat3;
	CMaskEdit	m_Dat2;
	CMaskEdit	m_Dat1;
	CEdit	m_EditNVag;
	CFastGrid	m_List;
	CButton	m_Check1;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRemVag)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgRemVag)
	afx_msg void OnAddVanClick();
	virtual BOOL OnInitDialog();
	afx_msg void OnWheelsButton();
	afx_msg void OnCheck1();
	afx_msg void OnItemclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnChangeEditNVag();
	afx_msg void OnCheck2();
	afx_msg void OnCheck4();
	afx_msg void OnCheck5();
	afx_msg void OnButton4();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnCheck3();
	afx_msg void OnChangeEdit2();
	afx_msg void OnChangeEdit3();
	afx_msg void OnChangeEdit7();
	afx_msg void OnChangeEdit116();
	afx_msg void OnChangeEditFind();
	afx_msg void OnCheck6();
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnSelchangeCombo1();
	afx_msg void OnDblclkList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnRclickList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	afx_msg void OnButton5();
	afx_msg void OnRemoveVag();
	afx_msg void OnButton_Rashod();
	afx_msg void OnButton6();
	afx_msg void OnButton_PrintLK();
	afx_msg void OnItemchangedList1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnOdstatechangedList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnButton_VanSprav();
	afx_msg void OnCheck7();
	afx_msg void OnButton_PrihodTL();
	afx_msg void OnButton_TL_Rashod();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton_VagInRem();
	CButton m_ButVagInRem;
	afx_msg void OnBnClickedButton_4624();
	afx_msg void OnBnClickedButtonVU36_sokr();
	CButton m_ButNeispVag;
	afx_msg void OnBnClickedButton48();
public:
	CButton m_ButAddVag;
public:
	CButton m_ButDelVag;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGREMVAG_H__C37C52C7_AEA2_4ABE_B137_7A9F9F166311__INCLUDED_)
