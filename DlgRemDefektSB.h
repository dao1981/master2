#pragma once


// CDlgRemDefektSB dialog

class CDlgRemDefektSB : public CDialog
{
	DECLARE_DYNAMIC(CDlgRemDefektSB)

public:
	CDlgRemDefektSB(CWnd* pParent = NULL);   // standard constructor
	virtual ~CDlgRemDefektSB();

// Dialog Data
	enum { IDD = IDD_DEFEKT_SB };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
};
