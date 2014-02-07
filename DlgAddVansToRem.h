#pragma once
#include "fastgrid.h"
#include "afxwin.h"
#include "maskedit.h"


// CDlgAddVansToRem dialog

class CDlgAddVansToRem : public CDialog
{
	DECLARE_DYNAMIC(CDlgAddVansToRem)

public:
	CDlgAddVansToRem(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgAddVansToRem();

// Dialog Data
	enum { IDD = IDD_ADDVANS };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CFastGrid m_List;
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedCheck1();
	CButton m_Check1;
	afx_msg void OnBnClickedButton_4624();
	int iNeisp; //0 вагоны в ремонте, 1 неисправные
	afx_msg void OnEnChangeEditFind();
	CEdit m_EdMaskVan;
};
