#pragma once
#include "afxcmn.h"
#include "afxwin.h"


// CDlgSelKPType dialog

class CDlgSelKPType : public CDialog
{
	DECLARE_DYNAMIC(CDlgSelKPType)

public:
	CString strNKP;
	CDlgSelKPType(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSelKPType();

// Dialog Data
	enum { IDD = IDD_SEL_KP_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_List;
public:
	virtual BOOL OnInitDialog();
	DWORD dwITKP;
	CString strTKP;
public:
	afx_msg void OnNMDblclkList1(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnBnClickedOk();
public:
	CStatic m_LabNKP;
};
