#pragma once


// CDlgRemDefektBR dialog

class CDlgRemDefektBR : public CDialog
{
	DECLARE_DYNAMIC(CDlgRemDefektBR)

public:
	CDlgRemDefektBR(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgRemDefektBR();

// Dialog Data
	enum { IDD = IDD_DEFEKT_BR };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
};
