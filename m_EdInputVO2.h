#pragma once
#include "maskedit.h"
#include "afxwin.h"


// m_EdInputVO2 dialog

class m_EdInputVO2 : public CDialog
{
	DECLARE_DYNAMIC(m_EdInputVO2)

public:
	m_EdInputVO2(CWnd* pParent = NULL);   // standard constructor
	virtual ~m_EdInputVO2();

// Dialog Data
	enum { IDD = IDD_INPUT_VO2 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CComboBox m_Cb;
	CButton m_Check;
};
