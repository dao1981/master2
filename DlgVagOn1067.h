#pragma once
#include "fastgrid.h"
#include "afxwin.h"
#include "maskedit.h"


// CDlgVagOn1067 dialog

class CDlgVagOn1067 : public CDialog
{
	DECLARE_DYNAMIC(CDlgVagOn1067)

public:
	CDlgVagOn1067(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgVagOn1067();

// Dialog Data
	enum { IDD = IDD_VAGON_NA_KOLEE_1067 };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:


	CFastGrid m_List1;
	CFastGrid m_List2;
	virtual BOOL OnInitDialog();
	void RefreshLists(void);
	int	iGotHeader;
	CStatic m_Num1;
	CStatic m_Num2;
	int iStatusWaiting;

	int iList;
	afx_msg void OnNMSetfocusList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMSetfocusList2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnDeleteVag();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	CMaskEdit m_EdNVag1;
	CMaskEdit m_EdNVag2;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();
public:
	afx_msg void OnLvnItemchangedList2(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnHdnItemclickList1(NMHDR *pNMHDR, LRESULT *pResult);
public:
	afx_msg void OnBnClickedButton_EditVag();
public:
	afx_msg void OnBnClickedButton_UpdateAll();
public:
	CButton m_ButUpd;
public:
	void UpdButtonStatus(void);
public:
	virtual BOOL DestroyWindow();
public:
	void MySetTimer(void);
public:
	void MyKillTimer(void);
public:
	afx_msg void OnBnClickedButton_SpravkaPoAr();
};
