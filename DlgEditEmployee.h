#pragma once
#include "fastgrid.h"
#include "afxwin.h"
#include "maskedit.h"
#include "dialogheader.h"
#include "DlgAccel1.h"

// CDlgEditEmployee dialog

struct CStateItem
{
	DWORD	dwID;
	bool	bState;
};

class CDlgEditEmployee : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgEditEmployee)

public:
	DWORD	dwID;
	DWORD	dwID_Arm;	
	CEmplArray EmplArr;
	int		iMode;
//	DWORD	id;
	DWORD	dwTab;
	CStateItem OldState[128];
	CStateItem NewState[128];
	DWORD	dwStateCount;
	char	cNewPassword[32];
	int		iNewRang;
	BOOL	bRangWasChanged;
	int		iBeenStarted;

	int		iTitleIndex;
	int		iGotTitle;
	char	cOldRang[10];

	int		iAutoUsed;
	CDialogHeader m_HeaderCtrl;
	CDlgEditEmployee(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgEditEmployee();

// Dialog Data
	enum { IDD = IDD_EDIT_EMPLOYEE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CFastGrid m_List;

	afx_msg void OnBnClickedOk();
	// // Группировка
	CComboBox m_Combo2;
	CComboBox m_Combo;
	CComboBox m_ComboDpt;
	CMaskEdit m_Edit1;
	void FillFormData(void);
	CEdit m_Edit2;
//	CEdit m_Edit3;
	afx_msg void OnCbnSelchangeCombo1();
	afx_msg void OnCbnSelchangeCombo2();
//	afx_msg void OnNMClickList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedCheck1();
	CButton m_Check1;
	afx_msg void OnEnKillfocusEdit2();
	afx_msg void OnBnClickedButton2();
	CButton m_ButSetPass;
	CButton m_ButSetupMnu;
protected:
	virtual void OnCancel();
public:
	afx_msg void OnEnSetfocusEdit3();
	afx_msg void OnBnClickedSetupMnu();
	DWORD	p_dwCheckMenuID[255];
	DWORD	p_dwCheckMenuVal[255];
	DWORD   dwCheckMenuCount;
	CButton m_ButTovKadr;
public:
	afx_msg void OnBnClickedButton_TovKadr();
};
