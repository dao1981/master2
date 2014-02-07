#if !defined(AFX_PRINTABLEDLG_H__E8762280_8D70_4CD5_882E_24C194E71614__INCLUDED_)
#define AFX_PRINTABLEDLG_H__E8762280_8D70_4CD5_882E_24C194E71614__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PrintableDlg.h : header file
//
#include "ListEx.h"
/////////////////////////////////////////////////////////////////////////////
// CPrintableDlg dialog

class CPrintableDlg : public CDialog
{
// Construction
private:
//    CSingleDocTemplate* m_pTemplate;
public:
	CPrintableDlg(CWnd* pParent = NULL);   // standard constructor
    void OuterPrint();
    char cQ[512];
//    void PrintPreview();
	BOOL bDosCodePage;
// Dialog Data
	//{{AFX_DATA(CPrintableDlg)
	enum { IDD = IDD_DIALOG_FREZ };
	CButton	m_ButOK;
	CButton	m_Check2;
	CButton	m_Check1;
	CListEx	m_List;
	BOOL	m_bCheck1;
	BOOL	m_bCheck2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPrintableDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPrintableDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPreviewButton();
	afx_msg void OnPrintButton();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClose();
	afx_msg void OnButtonSaveToFile();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
public:
	void Dos2Win(unsigned char * cLine);
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PRINTABLEDLG_H__E8762280_8D70_4CD5_882E_24C194E71614__INCLUDED_)
