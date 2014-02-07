#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgInput2958 dialog

class CDlgInput2958 : public CDialog
{
	DECLARE_DYNAMIC(CDlgInput2958)

public:
	CDlgInput2958(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgInput2958();

// Dialog Data
	enum { IDD = IDD_INPUT_2958 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat;
	CButton m_Check;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
