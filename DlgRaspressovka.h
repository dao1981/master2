#pragma once


// CDlgRaspressovka dialog

class CDlgRaspressovka : public CDialog
{
	DECLARE_DYNAMIC(CDlgRaspressovka)

public:
	CDlgRaspressovka(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgRaspressovka();

// Dialog Data
	enum { IDD = IDD_RASPRESSOVKA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
};
