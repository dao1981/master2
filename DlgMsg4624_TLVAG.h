#pragma once
#include "d:\develop\master2\controls\mylabel.h"
#include "maskedit.h"
#include "DlgAccel1.h"

// CDlgMsg4624_TLVAG dialog

class CDlgMsg4624_TLVAG : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg4624_TLVAG)

public:
	CDlgMsg4624_TLVAG(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624_TLVAG();

// Dialog Data
	enum { IDD = IDD_4624_TLVAG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMyLabel m_Lab1;
	CMyLabel m_Lab2;
	CMyLabel m_Lab3;
protected:
	virtual void OnOK();
	virtual void OnCancel();
public:
	CMaskEdit m_pL[8];
	CMaskEdit m_EdFIO1_LDTL;
	CMaskEdit m_EdFIO2_LDTL;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton_FIO1();
	afx_msg void OnBnClickedButton_FIO2();
	CMaskEdit m_p[8][8];
	afx_msg void OnArrowDown();
	afx_msg void OnArrowUp();

	CButton m_bnFio1;
	CButton m_bnFio2;
};
