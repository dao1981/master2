#pragma once
#include "maskedit.h"
#include "dlgaccel1.h"

// CDlgPerestRept dialog

class CDlgPerestRept : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgPerestRept)

public:
	CDlgPerestRept(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPerestRept();

// Dialog Data
	enum { IDD = IDD_PEREST_REPT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;
	CButton m_Check;
	CString d1, d2;
	int iCheck;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
