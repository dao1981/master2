#if !defined(AFX_DLGTLFROMVAG_H__92286A19_0F7A_4108_9D3F_4DCCCFE2D846__INCLUDED_)
#define AFX_DLGTLFROMVAG_H__92286A19_0F7A_4108_9D3F_4DCCCFE2D846__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgTLFromVag.h : header file
//
#include "DialogHeader.h"
#include "MaskEdit.h"
#include "afxwin.h"
/////////////////////////////////////////////////////////////////////////////
// CDlgTLFromVag dialog

class CDlgTLFromVag : public CDialog
{
// Construction
public:
	CDlgTLFromVag(CWnd* pParent = NULL);   // standard constructor
    int     m_iRashod;
	__int64 qwILK;
	PRIHOD_TL p_PrihodTl[10];
	int		iTlCount;

	char	m_cNVag[32];
	char	m_cDatRemIn[16];
	char	m_cDatRemOut[16];
	char	m_cVRem[32];
	DWORD	m_dwRemID;
// Dialog Data
	//{{AFX_DATA(CDlgTLFromVag)
	enum { IDD = IDD_TL_VAG };
	CMaskEdit	m_DatTlOut;
	CListCtrl	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgTLFromVag)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlgTLFromVag)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
    CDialogHeader m_HeaderCtrl;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton_AddTL();
	void RefreshList(void);
	afx_msg void OnBnClickedButton2();
	CMaskEdit m_EdFam;
	CEdit m_EdNVag;
	CEdit m_EdVRem;
	CEdit m_EdDatIn;
	CEdit m_EdDatOut;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTLFROMVAG_H__92286A19_0F7A_4108_9D3F_4DCCCFE2D846__INCLUDED_)
