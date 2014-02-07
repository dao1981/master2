#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgInput2956 dialog

class CDlgInput2956 : public CDialog
{
	DECLARE_DYNAMIC(CDlgInput2956)

public:
	CDlgInput2956(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInput2956();

// Dialog Data
	enum { IDD = IDD_INPUT_2956 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat;
	CButton m_Check;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
};
