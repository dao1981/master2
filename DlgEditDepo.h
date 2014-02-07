#pragma once
#include "afxwin.h"
#include "maskedit.h"
#include "dlgaccel1.h"


// CDlgEditDepo dialog

class CDlgEditDepo : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgEditDepo)

public:
	CDlgEditDepo(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgEditDepo();

// Dialog Data
	enum { IDD = IDD_EDIT_DEPO };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	DWORD dwIPR;

	virtual BOOL OnInitDialog();
	CComboBox m_Cb1;
	CComboBox m_Cb2;
	CComboBox m_Cb3;
	CMaskEdit m_EdDepoName;
	CMaskEdit m_EdDepoSName;
	CMaskEdit m_EdKod;
	CMaskEdit m_EdKodOtd;
	CMaskEdit m_EdKleimo;
	CMaskEdit m_EdKodDor;
	CMaskEdit m_EdESR;
	CMaskEdit m_EdKPNum;
	CMaskEdit m_EdPasKP;
	CMaskEdit m_EdNeispKP;
	CMaskEdit m_EdRevizNum;
	CMaskEdit m_EdKPZ;
	CMaskEdit m_EdPTO;
	CMaskEdit m_EdOtvet;
	CMaskEdit m_EdKodS29xx;
	CButton m_Rad1;
	CButton m_butOK;
	CButton m_CheckAutoPrih;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonSelStan();
};
