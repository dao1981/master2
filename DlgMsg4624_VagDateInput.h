#pragma once
#include "maskedit.h"
#include "afxwin.h"
#include "DlgAccel1.h"

struct CVagDate
{
	char cVagNum[32];
	char cDate[16];
	CVagDate() { ZeroMemory(this, sizeof(CVagDate));};
};
// CDlgMsg4624_VagDateInput dialog

class CDlgMsg4624_VagDateInput : public CDlgWithAccelerators
{
	DECLARE_DYNAMIC(CDlgMsg4624_VagDateInput)

public:
	CDlgMsg4624_VagDateInput(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgMsg4624_VagDateInput();

	char cNVag32[32];
	SYSTEMTIME stDat;
	int	m_iCheck;

	CVagDate	m_pVagDate[40];
	int	iCountVD;
// Dialog Data
	enum { IDD = IDD_4624_VAGDATE_INPUT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CMaskEdit m_EdNVag;
	CMaskEdit m_Dat;
protected:
	virtual void OnOK();
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedOk();
	CButton m_Check;
	CMaskEdit m_Hour;
	CMaskEdit m_Min;
};
