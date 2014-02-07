#pragma once
#include "MaskEdit.h"
#include "DlgAccel1.h"
// CDlgMsg4624_ZamenaBlTl dialog

class CDlgMsg4624_ZamenaBlTl : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg4624_ZamenaBlTl)

public:
	CDlgMsg4624_ZamenaBlTl(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624_ZamenaBlTl();

// Dialog Data
	enum { IDD = IDD_4624_ZAMENA_BL_TL };
	CMaskEdit m_pEd[5][2];
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_FIO;
	CButton   m_bnFio;
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnBnClickedButton_FIO();
	afx_msg void OnArrowDown();
	afx_msg void OnArrowUp();
};
