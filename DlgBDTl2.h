#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgBDTl2 dialog

class CDlgBDTl2 : public CDialog
{
	DECLARE_DYNAMIC(CDlgBDTl2)

public:
	CDlgBDTl2(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgBDTl2();

// Dialog Data
	enum { IDD = IDD_BD_INPUT_TL };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int iType;
	CMaskEdit m_Dat1;
	CMaskEdit m_Dat2;
	CMaskEdit m_Dat3;
	CMaskEdit m_Dat4;
	CMaskEdit m_EdNVag1;
	CMaskEdit m_EdNVag2;
	CComboBox m_cbRem1;
	CComboBox m_cbRem2;
	CMaskEdit m_EdKlPr;
	CMaskEdit m_PrName;
	CMaskEdit m_Dat5;
	CMaskEdit m_Dat6;
	CMaskEdit m_EdNDet;
	afx_msg void OnBnClickedCheck1_DatPost();
	afx_msg void OnBnClickedCheck2_DatRash();
	afx_msg void OnBnClickedCheck3_Neizr();
	afx_msg void OnBnClickedCheck4_VagNPost();
	afx_msg void OnBnClickedCheck5_VagNRash();
	afx_msg void OnBnClickedCheck6_PrIzg();
	afx_msg void OnBnClickedCheck7_GodIzg();
	afx_msg void OnBnClickedCheck8_MaskNDet();
	CButton m_Check1;
	CButton m_Check2;
	CButton m_Check3;
	CButton m_Check4;
	CButton m_Check5;
	CButton m_Check6;
	CButton m_Check7;
	CButton m_Check8;
	CButton m_butPR;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedOk();
};
