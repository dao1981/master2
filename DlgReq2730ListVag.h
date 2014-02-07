#pragma once
#include "fastgrid.h"
#include "maskedit.h"


// CDlgReq2730ListVag dialog

class CDlgReq2730ListVag : public CDialog
{
	DECLARE_DYNAMIC(CDlgReq2730ListVag)

public:
	CDlgReq2730ListVag(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgReq2730ListVag();

// Dialog Data
	enum { IDD = IDD_REQ2730_LIST_VAG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CFastGrid m_List;
	CMaskEdit m_EdNVag;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButtonDelete();
};
