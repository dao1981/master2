#pragma once
#include "maskedit.h"
#include "DlgAccel1.h"
// CDlgMsg4624_BlTl dialog

class CDlgMsg4624_BlTl : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg4624_BlTl)

public:
	CDlgMsg4624_BlTl(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624_BlTl();

// Dialog Data
	enum { IDD = IDD_4624_BL_TL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_pEd[5][2];
	virtual BOOL OnInitDialog();
protected:
	virtual void OnCancel();
	virtual void OnOK();
public:
	CMaskEdit m_EdFIO1_BLTL;
	CMaskEdit m_EdFIO2_BLTL;
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton31();
	afx_msg void OnArrowDown();
	afx_msg void OnArrowUp();

	CButton m_bnFio1;
	CButton m_bnFio2;
};
