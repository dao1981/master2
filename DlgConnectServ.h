#pragma once
#include "afxwin.h"


// CDlgConnectServ dialog

class CDlgConnectServ : public CDialog
{
	DECLARE_DYNAMIC(CDlgConnectServ)

public:
	CDlgConnectServ(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgConnectServ();

// Dialog Data
	enum { IDD = IDD_CONNECT };
	DWORD dwAttemptCount;
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CStatic m_LabAtt;
	int Connected();
	int iConnectFlag;
protected:
	virtual void OnOK();
};
