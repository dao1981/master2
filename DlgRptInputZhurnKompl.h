#pragma once
#include "maskedit.h"
#include "DialogHeader.h"
#include "afxwin.h"

// CDlgRptInputZhurnKompl dialog

class CDlgRptInputZhurnKompl : public CDialog
{
	DECLARE_DYNAMIC(CDlgRptInputZhurnKompl)

public:
	CDlgRptInputZhurnKompl(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgRptInputZhurnKompl();

// Dialog Data
	enum { IDD = IDD_INPUT_RPT_ZHURN_KOMPLEKT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CDialogHeader m_HeaderCtrl;
	CMaskEdit m_EdDat1;
	CMaskEdit m_EdDat2;
	CMaskEdit m_EdNVag;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
	CMaskEdit m_EdDat3;
	CMaskEdit m_EdDat4;
	CButton m_Check1;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	CButton m_Rad1;
	CButton m_Rad2;
};
