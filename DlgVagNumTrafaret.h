#pragma once
#include "maskedit.h"
#include "dlgaccel1.h"

// CDlgVagNumTrafaret dialog

class CDlgVagNumTrafaret : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgVagNumTrafaret)

public:
	CDlgVagNumTrafaret(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgVagNumTrafaret();

// Dialog Data
	enum { IDD = IDD_VAG_NTRAFARET };
	WORD wDomkrat;
	WORD wRow;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdDom;
	CMaskEdit m_EdRow;
protected:
	virtual void PreInitDialog();
	virtual void OnOK();
public:
	afx_msg void OnBnClickedOk();
};
