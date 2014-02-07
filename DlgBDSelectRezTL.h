#pragma once
#include "fastgrid.h"
#include "afxwin.h"
#include "maskedit.h"


// CDlgBDSelectRezTL dialog

class CDlgBDSelectRezTL : public CDialog
{
	DECLARE_DYNAMIC(CDlgBDSelectRezTL)
public:
	char	cQ[1024];
	CFont	*Font;
	BOOL	bGotHeader;
	CDlgBDSelectRezTL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgBDSelectRezTL();

// Dialog Data
	enum { IDD = IDD_SELECT_REZ_TL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CFastGrid m_List;
	void RefreshList(void);
	afx_msg void OnBnClickedButton_EditTL();
	afx_msg void OnBnClickedButton_DeleteTL();
	afx_msg void OnBnClickedButton_AddTl();
	afx_msg void OnBnClickedButton_PasportTL();
	CStatic m_lbRecCount;
	afx_msg void OnEnChangeEditNTl();
	CMaskEdit m_Edit;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedOk();
};
