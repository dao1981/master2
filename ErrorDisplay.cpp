// ErrorDisplay.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "ErrorDisplay.h"
#include ".\errordisplay.h"


// CErrorDisplay dialog

IMPLEMENT_DYNAMIC(CErrorDisplay, CDialog)
CErrorDisplay::CErrorDisplay(CWnd* pParent /*=NULL*/)
	: CDialog(CErrorDisplay::IDD, pParent)
	, m_MsgText(_T(""))
{
}

CErrorDisplay::~CErrorDisplay()
{
}

void CErrorDisplay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Edit);
}


BEGIN_MESSAGE_MAP(CErrorDisplay, CDialog)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton_Copy)
END_MESSAGE_MAP()


// CErrorDisplay message handlers

BOOL CErrorDisplay::OnInitDialog()
{
	CDialog::OnInitDialog();

//	m_Edit.SetWindowText(m_MsgText);
	CFont *f = m_Edit.GetDC()->GetCurrentFont();
	
	CRect	r1(0,10,0,10);
	CRect	r2;
	CSize	sz;
	sz.cy	=	m_Edit.GetDC()->DrawText("X",r1,DT_LEFT|DT_SINGLELINE|DT_NOCLIP|DT_CALCRECT);
	sz.cx	=	r1.Width();

	m_Edit.GetClientRect(r2);
	int iStrLen = r2.Width() / sz.cx;
//	char s[2048] = "";
//	strncpy(s, m_MsgText, 2048);
	CString s = m_MsgText;
	char c = '\n';
	int iLastSpace = 0;
	int iCurr = 0;
	for( int i=0; i < (signed)strlen(s); i++ )
	{
		if( s[i] == ' ' ) iLastSpace = i;
		if( iCurr > iStrLen && iLastSpace ) 
		{
//			s[iLastSpace] = '\r';
			s.Insert(iLastSpace, "\r\n");
//			s.
			iCurr = 0;
		} else
			iCurr++;
	}
	m_Edit.SetWindowText(s);

//	m_Edit.
	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

void CErrorDisplay::OnBnClickedButton_Copy()
{
	if(OpenClipboard())
	{
		HGLOBAL clipbuffer;
		char *buffer;
		EmptyClipboard();
		clipbuffer = GlobalAlloc(GMEM_DDESHARE, m_MsgText.GetLength()+1);
		buffer = (char*)GlobalLock(clipbuffer);
		strcpy(buffer, m_MsgText);
		GlobalUnlock(clipbuffer);
		SetClipboardData(CF_TEXT,clipbuffer);
		CloseClipboard();
	}
}
