#pragma once
#include "fastgrid.h"
#include "afxwin.h"
#include "maskedit.h"


// CDlgPPT_BDVagRez dialog

class CDlgPPT_BDVagRez : public CDialog
{
	DECLARE_DYNAMIC(CDlgPPT_BDVagRez)

public:
	CDlgPPT_BDVagRez(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPPT_BDVagRez();
	
	CFastGrid m_List;
// Dialog Data
	enum { IDD = IDD_PPT_BD_VAG_REZ };
	char cQ[512];
	CString sOldText;
	char cQReport[512];
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
public:
//	CFastGrid m_List;
public:
	afx_msg void OnBnClickedOk();
	void RefreshList();
public:
	afx_msg void OnBnClickedButtonCancel1520();
public:
	afx_msg void OnBnClickedButton3();
public:
	CStatic m_LabCount;
public:
	CEdit m_EdMaskVan;
public:
	afx_msg void OnEnChangeEdit1();
public:
	afx_msg void OnBnClickedButtonReport();
public:
	afx_msg void OnBnClickedButton4624();
public:
	afx_msg void OnBnClickedButtonZapr2730();
public:
	afx_msg void OnBnClickedButtonPokaz2730();
public:
	afx_msg void OnBnClickedButton_2612();
public:
	afx_msg void OnBnClickedButton_Show2612();
};
