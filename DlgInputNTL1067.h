#pragma once
#include "maskedit.h"


// CDlgInputNTL1067 dialog

class CDlgInputNTL1067 : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputNTL1067)

public:
	CDlgInputNTL1067(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInputNTL1067();

// Dialog Data
	enum { IDD = IDD_GET_NTL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Edit;
	virtual BOOL OnInitDialog();
	CString m_strNTL;
	afx_msg void OnBnClickedOk();
};
