#pragma once
#include "fastgrid.h"
#include "afxwin.h"
#include "maskedit.h"


// CDlgPeresTlLog dialog

class CDlgPeresTlLog : public CDialog
{
	DECLARE_DYNAMIC(CDlgPeresTlLog)

public:
	CDlgPeresTlLog(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPeresTlLog();
	int iRecieveMode;
// Dialog Data
	enum { IDD = IDD_PERES_TL_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();

	afx_msg void OnBnClickedButton3();
	CFastGrid m_List;
	CButton m_Check1;
	CButton m_Check2;
	CButton m_Check3;
	CButton m_Check4;
	CButton m_Check5;


	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;

	CButton	m_ButNew;
	CButton	m_ButDelete;
	CButton	m_ButEdit;
	CButton	m_ButSendRecv;
	CButton	m_Radio2;
	CButton	m_ButSelect;
	CButton	m_ButFam;
	CButton	m_ButPred;

	CMaskEdit	m_EdNVag;
	CMaskEdit	m_EdPrName;
	CMaskEdit	m_EdKlPr;
	CMaskEdit	m_NVed2;	
	CMaskEdit	m_NVed1;
	CMaskEdit	m_EdFam;
	CButton *b1, *b2;
	char	cQuery[128];

	void	RefreshList();

public:
	afx_msg void OnBnClickedOk();
public:
	afx_msg void OnBnClickedButton1();
public:
	afx_msg void OnBnClickedButton_Select();
};
