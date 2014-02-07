#pragma once
#include "maskedit.h"
#include "afxwin.h"


// CDlgPaspKP dialog

class CDlgPaspKP : public CDialog
{
	DECLARE_DYNAMIC(CDlgPaspKP)

public:
	CDlgPaspKP(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgPaspKP();
	__int64 qwInitIZAP;

	char cNKP[32];
	int iTKP;
	char cKlPrIzg[10];
	char cYearIzg[9];
//
// Dialog Data
	enum { IDD = IDD_PASP_KP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	afx_msg void OnBnClickedOk();

	virtual BOOL OnInitDialog();

public:
	CMaskEdit m_EdKlPrIzg;
	CMaskEdit m_EdNOs;
	CMaskEdit m_EdDatIzg;
	CComboBox m_cbTKP;
	CMaskEdit m_EdTKP;
	CMaskEdit m_EdSobstAdm;
	CMaskEdit m_EdSobstPr;
	CMaskEdit m_EdPorNom;
	CMaskEdit m_EdDatFor;
	CMaskEdit m_EdKlPrFor;
	CMaskEdit m_EdKR_KlPrIzg;
	CMaskEdit m_EdKR_Nom;
	CMaskEdit m_EdKR_DatIzg;
	CMaskEdit m_EdKR_NomPlav;
	CComboBox m_cbKR_MSteel;
	CMaskEdit m_EdKR_MSteel;
	CMaskEdit m_EdKR_Type;
	CButton m_ckKR_StarogKol;

	CMaskEdit m_EdKL_KlPrIzg;
	CMaskEdit m_EdKL_Nom;
	CMaskEdit m_EdKL_DatIzg;
	CMaskEdit m_EdKL_NomPlav;
	CComboBox m_cbKL_MSteel;
	CMaskEdit m_EdKL_MSteel;
	CMaskEdit m_EdKL_Type;
	CButton m_ckKL_StarogKol;

	CButton m_ckStarogOs;
public:
	afx_msg void OnBnClickedButton_Sobst();
public:
	afx_msg void OnEnChangeEdit12();
	afx_msg void OnEnChangeComboTKP();
public:
	afx_msg void OnBnClickedButton4();
public:
	CButton m_ButPrintPasp;
public:
	afx_msg void OnBnClickedButton3();
};
