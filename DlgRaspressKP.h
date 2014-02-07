#pragma once
#include "maskedit.h"
#include "fastgrid.h"
#include "afxwin.h"
#include "DlgAccel1.h"

// CDlgRaspressKP dialog

class CDlgRaspressKP : public CDialog
{
	DECLARE_DYNAMIC(CDlgRaspressKP)

public:
	CDlgRaspressKP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgRaspressKP();

// Dialog Data
	enum { IDD = IDD_RASPRESSOVKA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat;
	CMaskEdit m_EdFam;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	void RefreshKPList(void);
	CFastGrid m_List1;
	afx_msg void OnBnClickedButton2();
	CFastGrid m_List2;
	afx_msg void OnLvnItemActivateList2(NMHDR *pNMHDR, LRESULT *pResult);

	afx_msg void OnHdnItemclickList2(NMHDR *pNMHDR, LRESULT *pResult);
	
	CMaskEdit m_EdKPNum;
	CStatic m_Num1;
	CStatic m_Num2;
	void RefreshRightList(void);

	int iGotHeader1;
	int iGotHeader2;
	int iOldKPCount;
	int iStarted;
	int iEdFocused;
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnSetfocusEditKPNum();
	CButton m_ButSelect;
	CButton m_ButAdd;
	afx_msg void OnEnKillfocusEdit7();
	CButton m_ButFam;
	afx_msg void OnBnClickedButtonLOG();

	DWORD lp_dwFam[512];
	afx_msg void OnBnSetfocusButtonSelect();
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	UINT OnGetDlgCode();
	virtual BOOL PreTranslateMessage(MSG* pMsg);
};
