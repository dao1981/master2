#pragma once
#include "afxwin.h"
#include "MaskEdit.h"

// CDlgVagOn1067Edit dialog

class CDlgVagOn1067Edit : public CDialog
{
	DECLARE_DYNAMIC(CDlgVagOn1067Edit)

public:
	CDlgVagOn1067Edit(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgVagOn1067Edit();
	char cNVag[16];
	void LoadData();
// Dialog Data
	enum { IDD = IDD_VAGON_NA_KOLEE_EDIT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
	virtual void PreInitDialog();
public:
	virtual BOOL OnInitDialog();
public:
	CStatic m_labNVag;
	CMaskEdit m_EdKodAdm1;
	CMaskEdit m_EdKodAdm2;
	CMaskEdit m_EdAdmName1;
	CMaskEdit m_EdAdmName2;
	CMaskEdit m_EdOKPO1;
	CMaskEdit m_EdOKPO2;
	CMaskEdit m_EdOKPO3;
	CMaskEdit m_EdOKPO4;
	CMaskEdit m_EdName1;
	CMaskEdit m_EdName2;
	CMaskEdit m_EdName3;
	CMaskEdit m_EdName4;
	CMaskEdit m_EdKod2;
	CMaskEdit m_EdKod3;
	CMaskEdit m_EdKod4;
	CMaskEdit m_EdRod1;
	CMaskEdit m_EdNomAr;
	CMaskEdit m_EdSrokAr;
	CMaskEdit m_EdTip;
	CMaskEdit m_EdModel;
	CMaskEdit m_EdRodMod;
	CMaskEdit m_EdKartDat;

	afx_msg void OnBnClickedButton_ZapFromKartot();

	afx_msg void OnBnClickedButton_UpdKartot();
};
