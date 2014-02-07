// DlgRaspressovka.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgRaspressovka.h"
#include ".\dlgraspressovka.h"


// CDlgRaspressovka dialog

IMPLEMENT_DYNAMIC(CDlgRaspressovka, CDialog)
CDlgRaspressovka::CDlgRaspressovka(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgRaspressovka::IDD, pParent)
{
}

CDlgRaspressovka::~CDlgRaspressovka()
{
}

void CDlgRaspressovka::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CDlgRaspressovka, CDialog)
END_MESSAGE_MAP()


// CDlgRaspressovka message handlers

BOOL CDlgRaspressovka::OnInitDialog()
{
	CDialog::OnInitDialog();

	

	return TRUE;  // return TRUE unless you set the focus to a control

}
