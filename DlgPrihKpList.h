#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgPrihKpList dialog

class CDlgPrihKpList : public CDialog
{
	DECLARE_DYNAMIC(CDlgPrihKpList)

public:
	CDlgPrihKpList(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPrihKpList();
	__int64 qwRetIZap;
	int iGotHeader;
// Dialog Data
	enum { IDD = IDD_KP_SELECT_PRIH };
	CFastGrid m_List;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnEnChangeEditFind();
public:
	CEdit m_EdMaskKP;
	__int64 qwRetIzapList[256];
	
	int iRetCount;
	int iModeCheckbox;

public:
	CButton m_But1;
public:
	afx_msg void OnBnClickedCheck39();
public:
	CButton m_But2;
public:
	CButton m_But3;
public:
	afx_msg void OnBnClickedCheck1();
public:
	afx_msg void OnBnClickedCheck31();
public:
	void RefreshList(void);
};
