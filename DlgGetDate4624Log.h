#pragma once
#include "maskedit.h"


// CDlgGetDate4624Log dialog

class CDlgGetDate4624Log : public CDialog
{
	DECLARE_DYNAMIC(CDlgGetDate4624Log)

public:
	CDlgGetDate4624Log(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgGetDate4624Log();
	char cSQLDatRet[12];
// Dialog Data
	enum { IDD = IDD_4624_GET_DATE_LOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_Dat1;
	virtual BOOL OnInitDialog();
protected:
	virtual void OnOK();
};
