#pragma once
#include "afxwin.h"


// CDlgChangeTypeKP dialog

class CDlgChangeTypeKP : public CDialog
{
	DECLARE_DYNAMIC(CDlgChangeTypeKP)

public:
	CDlgChangeTypeKP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgChangeTypeKP();
	DWORD dwNewTypeKP;
	char  cNewTypeName[64];
// Dialog Data
	enum { IDD = IDD_CHANGE_KP_TYPE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	CComboBox m_Combo;
public:
	afx_msg void OnBnClickedOk();
};
