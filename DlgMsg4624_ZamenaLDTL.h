#pragma once
#include "d:\develop\master2\controls\mylabel.h"
#include "maskedit.h"
#include "afxwin.h"
#include "DlgAccel1.h"
#include "DlgMsg4624_LDTL.h"
// CDlgMsg4624_ZamenaLDTL dialog


class CDlgMsg4624_ZamenaLDTL : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg4624_ZamenaLDTL)

public:
	CDlgMsg4624_ZamenaLDTL(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624_ZamenaLDTL();
	int rrr;
	CLDTLFormBuffer m_BackBuffer;
	//	CComboBox m_c1;
// Dialog Data
	enum { IDD = IDD_4624_ZAMENA_LDTL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:	
	CMyLabel m_Lab1;
	CMyLabel m_Lab2;
	CMyLabel m_Lab3;
	CMyLabel m_Lab4;
	CMaskEdit m_p[11][6];
	CMaskEdit m_Num[2];
	CComboBox m_c[6];
	CButton m_bn8Os;
	CButton m_bnFio;
protected:
	virtual void OnOK();
	virtual void OnCancel();
public:
	virtual BOOL OnInitDialog();		
	CMaskEdit m_FIO;
	afx_msg void OnBnClickedButton_FIO();
	afx_msg void OnCbnSelchangeCombo_1();
	afx_msg void OnCbnSelchangeCombo_2();
	afx_msg void OnCbnSelchangeCombo_4();
	afx_msg void OnCbnSelchangeCombo_5();
	afx_msg void OnArrowDown();
	afx_msg void OnArrowUp();
	afx_msg void OnBnClickedButton_8OS();
	void StoreValues(void);
	void DrawBuffer(int page);
};
