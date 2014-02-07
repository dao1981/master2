#pragma once
#include "maskedit.h"
#include "DlgAccel1.h"

// CDlgMsg2957_1 dialog

class CDlgMsg2957_1 : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg2957_1)

public:
	CDlgMsg2957_1(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg2957_1();

// Dialog Data
	enum { IDD = IDD_MSG_2957_1 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Ed[10][7];
	CMaskEdit m_EdRas[2][7];
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOK();
	virtual void OnCancel();
public:
	afx_msg void OnEnChangeSomeEdit();
	afx_msg void OnArrowUp();
	afx_msg void OnArrowDown();
};
