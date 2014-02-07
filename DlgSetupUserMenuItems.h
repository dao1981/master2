#pragma once
#include "fastgrid.h"
#include "afxwin.h"


// CDlgSetupUserMenuItems dialog

class CDlgSetupUserMenuItems : public CDialog
{
	DECLARE_DYNAMIC(CDlgSetupUserMenuItems)

public:
	CDlgSetupUserMenuItems(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgSetupUserMenuItems();

// Dialog Data
	enum { IDD = IDD_SETUP_MENUITEMS };
	DWORD dwID;
	DWORD dwID_Arm;
	DWORD *p_dwCheckMenuID;
	DWORD *p_dwCheckMenuVal;
	DWORD dwCount;
	int	  iTitleIdx;
	int	  iGotTitle;
	int	  iBeenStarted;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CFastGrid m_List;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton4_EnableAll();
	afx_msg void OnBnClickedButton5_DisableAll();
	afx_msg void OnBnClickedButton1();
	void RefreshList(void);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CComboBox m_Combo;
	afx_msg void OnBnClickedButton6();
};
