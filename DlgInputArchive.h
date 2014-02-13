#pragma once
#include "maskedit.h"


// диалоговое окно CDlgInputArchive

class CDlgInputArchive : public CDialog
{
	DECLARE_DYNAMIC(CDlgInputArchive)

public:
	CDlgInputArchive(CWnd* pParent = NULL);   // стандартный конструктор
	virtual ~CDlgInputArchive();

// Данные диалогового окна
	enum { IDD = IDD_BD_TL_PPT_ARCHIVE };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // поддержка DDX/DDV

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdNumTL;
	CMaskEdit m_EdNumNB;
	CMaskEdit m_EdNumBR;
	CMaskEdit m_EdDat1;
	CMaskEdit m_EdDat2;
	afx_msg void OnBnClickedCheckNTL();
	afx_msg void OnBnClickedCheckNNB();
	afx_msg void OnBnClickedCheckNBR();
	afx_msg void OnBnClickedCheckDatRem();
	afx_msg void OnBnClickedOk();
	virtual BOOL OnInitDialog();
};
