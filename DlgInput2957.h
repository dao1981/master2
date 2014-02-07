#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgInput2957 dialog

class CDlgInput2957 : public CDialog
{
	DECLARE_DYNAMIC(CDlgInput2957)

public:
	CDlgInput2957(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInput2957();

// Dialog Data
	enum { IDD = IDD_INPUT_2957 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CMaskEdit m_Dat;
	CButton m_Check;
	virtual BOOL OnInitDialog();
};
