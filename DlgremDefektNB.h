#pragma once


// CDlgremDefektNB dialog

class CDlgremDefektNB : public CDialog
{
	DECLARE_DYNAMIC(CDlgremDefektNB)

public:
	CDlgremDefektNB(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgremDefektNB();

// Dialog Data
	enum { IDD = IDD_DEFEKT_NB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
