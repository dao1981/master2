// DlgTLFromVag.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgTLFromVag.h"
#include ".\dlgtlfromvag.h"
#include "DlgPrihodTL.h"
#include "DlgSpravKdr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgTLFromVag dialog


CDlgTLFromVag::CDlgTLFromVag(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgTLFromVag::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgTLFromVag)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
    m_iRashod = 0;
	iTlCount = 0;
	qwILK = 0;

	m_cNVag[0] = 0;
	m_cVRem[0] = 0;
	m_cDatRemIn[0] = 0;
	m_cDatRemOut[0] = 0;
}


void CDlgTLFromVag::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgTLFromVag)
	DDX_Control(pDX, IDC_EDIT3, m_DatTlOut);
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
	DDX_Control(pDX, IDC_EDIT16, m_EdFam);
	DDX_Control(pDX, IDC_EDIT1, m_EdNVag);
	DDX_Control(pDX, IDC_EDIT2, m_EdVRem);
	DDX_Control(pDX, IDC_EDIT6, m_EdDatIn);
	DDX_Control(pDX, IDC_EDIT7, m_EdDatOut);
}


BEGIN_MESSAGE_MAP(CDlgTLFromVag, CDialog)
	//{{AFX_MSG_MAP(CDlgTLFromVag)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, OnBnClickedButton_AddTL)
	ON_BN_CLICKED(IDC_BUTTON2, OnBnClickedButton2)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgTLFromVag message handlers

BOOL CDlgTLFromVag::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here    
    if( !m_iRashod )
    {
	    m_HeaderCtrl.SetTitleText("Приход тележек");
	    m_HeaderCtrl.SetDescText("Оформление прихода тележек, выкаченных из-под вагона.");
    } else
    {
        this->SetWindowText("Расход тележек");
	    m_HeaderCtrl.SetTitleText("Расход тележек");
	    m_HeaderCtrl.SetDescText("Оформление расхода тележек, подкаченных под вагон.");
    }
    m_HeaderCtrl.SetIconHandle(AfxGetApp()->LoadIcon(IDI_TELEGA));

//	m_HeaderCtrl.SetIconHandle(::LoadIcon(AfxGetResourceHandle(),MAKEINTRESOURCE(IDR_MAINFRAME)));

	m_HeaderCtrl.Init(this);
	m_HeaderCtrl.MoveCtrls(this);

    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

    m_List.InsertColumn(0, "№ Балки", LVCFMT_LEFT,100 );
    m_List.InsertColumn(1, "№ Бок. рамы 1", LVCFMT_LEFT,100);
    m_List.InsertColumn(2, "№ Бок. рамы 2", LVCFMT_LEFT,100);

    m_DatTlOut.InitDate();
	m_EdFam.SetMode(5);
	DBW.FillEmplArray(m_EdFam.lpEmpl, 16);


	m_EdNVag.SetWindowText(m_cNVag);
	m_EdVRem.SetWindowText(m_cVRem);
	m_EdDatIn.SetWindowText(m_cDatRemIn);
	m_EdDatOut.SetWindowText(m_cDatRemOut);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgTLFromVag::OnBnClickedOk()
{
	char cQ[512] = "";
	char cText[64] = "";

	long Ind = 0;
	int  iRet = 0;
	DBW.ExecSQL("begin tran");
	DBW.CloseCursor();
	for( int i=0; i < iTlCount; i++ )
	{		
		sprintf(cQ, "pTov_PrihodTL %s, %s, %s, %s, %u, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
			isNull(qwILK),
			isNull(p_PrihodTl[i].qwTl_ID),
			m_DatTlOut.GetSQLDate(),
			isNull(m_EdFam.GetData()),

			p_PrihodTl[i].dwRightGoesFirst,

			p_PrihodTl[i].cRL_Num32,
			isNull(p_PrihodTl[i].dwRL_IPR),
			isNull(p_PrihodTl[i].dwRL_Year),
			isNull(p_PrihodTl[i].dwRL_Defect),
			isNull(p_PrihodTl[i].dwRL_VRem),

			p_PrihodTl[i].cRR_Num32,
			isNull(p_PrihodTl[i].dwRR_IPR),
			isNull(p_PrihodTl[i].dwRR_Year),
			isNull(p_PrihodTl[i].dwRR_Defect),
			isNull(p_PrihodTl[i].dwRR_VRem),

			p_PrihodTl[i].cB_Num32,
			isNull(p_PrihodTl[i].dwB_IPR),
			isNull(p_PrihodTl[i].dwB_Year),
			isNull(p_PrihodTl[i].dwB_Defect),
			isNull(p_PrihodTl[i].dwB_VRem),

			isNull(p_PrihodTl[i].dwPosition1),
			isNull(p_PrihodTl[i].dwPosition2),
			isNull(p_PrihodTl[i].cUslNum32));
		DBW.ExecSQL(cQ);
		DBW.Fetch();
		DBW.GetData(1, SQL_C_SLONG, &iRet, 4, &Ind);
		if( Ind != -1 && iRet == -1)
		{
			DBW.GetData(1, SQL_C_CHAR, cText, 64, &Ind);
			DBW.CloseCursor();
			DBW.ExecSQL("rollback tran");
			AfxMessageBox(cText);
			return;
		}
		DBW.CloseCursor();
	}
	DBW.ExecSQL("commit tran");
	OnOK();
}

void CDlgTLFromVag::OnBnClickedButton_AddTL()
{
	CDlgPrihodTL Dlg;
	if( Dlg.DoModal() == IDCANCEL ) return;
	p_PrihodTl[iTlCount] = Dlg.PrihodTl;
	iTlCount++;
	RefreshList();
}

void CDlgTLFromVag::RefreshList(void)
{
	m_List.DeleteAllItems();
	for( int i=0; i < iTlCount; i++ )
	{
		m_List.InsertItem(i, p_PrihodTl[i].cB_Num32);
		m_List.SetItemText(i, 1, p_PrihodTl[i].cRL_Num32);
		m_List.SetItemText(i, 2, p_PrihodTl[i].cRR_Num32);
	}
}

void CDlgTLFromVag::OnBnClickedButton2()
{
	CDlgSpravKdr Dlg;
	Dlg.DlgMode = 1;
	Dlg.iFilter = 16;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_EdFam.SetData(Dlg.dwFio);
	m_EdFam.SetWindowText(Dlg.cFio);
	
}
