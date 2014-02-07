#pragma once
#include "afxwin.h"


// CErrorDisplay dialog

class CErrorDisplay : public CDialog
{
	DECLARE_DYNAMIC(CErrorDisplay)

public:
	CErrorDisplay(CWnd* pParent = NULL);   // standard constructor
	virtual ~CErrorDisplay();

// Dialog Data
	enum { IDD = IDD_ERROR_DISPLAY };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_Edit;
	CString m_MsgText;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton_Copy();
};
