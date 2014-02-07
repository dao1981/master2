#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgInput2955 dialog

class CDlgInput2955 : public CDialog
{
	DECLARE_DYNAMIC(CDlgInput2955)

public:
	CDlgInput2955(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInput2955();

// Dialog Data
	enum { IDD = IDD_INPUT_2955 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	CButton m_Check;
};
