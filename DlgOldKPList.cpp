// DlgOldKPList.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgOldKPList.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgOldKPList dialog


CDlgOldKPList::CDlgOldKPList(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgOldKPList::IDD, pParent)
{
	iInitCount = 0;
    iIKPCount = 0;

    iMode = 0;
	//{{AFX_DATA_INIT(CDlgOldKPList)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlgOldKPList::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgOldKPList)
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgOldKPList, CDialog)
	//{{AFX_MSG_MAP(CDlgOldKPList)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgOldKPList message handlers

BOOL CDlgOldKPList::OnInitDialog() 
{
	CDialog::OnInitDialog();

    m_List.ModifyStyle(LVS_NOCOLUMNHEADER, LVS_REPORT | LVS_SHOWSELALWAYS | WS_VISIBLE | WS_BORDER | WS_CHILD, 0);
    m_List.SetExtendedStyle(LVS_EX_CHECKBOXES | LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT | LVS_EX_FLATSB  );

    DWORD dwNum = 0;
    char  cText[64] = "";
    long  Ind = 0;
    __int64 qwNum = 0;

    CString cQ;
    if( !iMode ) cQ.Format("pTov_GetOldKPList %I64u", qwILK); //были подкачены
    else cQ.Format("pTov_GetOldKPList2 %I64u", qwILK); //были выкачены
    DBW.ExecSQL(cQ);
    DBW.SetListHeader(&m_List);
	int j = 0;
    for(int i = 0; DBW.Fetch() != SQL_NO_DATA && i < 16; i++ )
    {
        DBW.GetData(1, SQL_C_UBIGINT, &qwNum, 8, &Ind);
        if( Ind != -1 )
        {
            m_List.InsertItem(i, "");
            m_List.qwSetItemData(i, qwNum);
        }
        DBW.GetData(2, SQL_C_ULONG, &dwNum, 4, &Ind);
        switch( dwNum )
        {
        case 0: m_List.EnableItem(i, FALSE);
                m_List.SetCheck(i, FALSE);
                break;
        case 1: m_List.EnableItem(i);
                m_List.SetCheck(i, FALSE);
				
				for( j=0; j < iInitCount; j++ )
				{
					if( p_qwInitIZAP[j] == m_List.qwGetItemData(i) )
					{
						m_List.SetCheck(i, TRUE);
						m_List.EnableItem(i, FALSE);												
					}
				}				
                break;
        default:
				m_List.SetCheck(i, TRUE);
                m_List.EnableItem(i, FALSE);                
        }
        DBW.GetData(3, SQL_C_CHAR, cText, 64, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 0, cText);
        DBW.GetData(4, SQL_C_CHAR, cText, 64, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 1, cText);
        DBW.GetData(5, SQL_C_CHAR, cText, 64, &Ind);
        if( Ind != -1 ) m_List.SetItemText(i, 2, cText);
        if( iMode )
        {
            DBW.GetData(6, SQL_C_UBIGINT, &p_qwIZAP[i], 8, &Ind);
            DBW.GetData(7, SQL_C_ULONG, &p_dwPriznRas[i], 4, &Ind);
            DBW.GetData(8, SQL_C_ULONG, &p_dwGruz[i], 4, &Ind);
        }

    }
    DBW.CloseCursor();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDlgOldKPList::OnOK() 
{
	iIKPCount = 0;
    CString msg;
    char cText[64] = "";
	for( int i=0; i < m_List.GetItemCount(); i++ )
	{
		if( m_List.isItemEnabled(i) && m_List.GetCheck(i) )
		{
			p_qwIKP[iIKPCount] = m_List.qwGetItemData(i);
            p_qwRetIZAP[iIKPCount] = p_qwIZAP[i];
			iIKPCount++;
/*
            msg = "Ena";
            _i64toa(p_qwIKP[iIKPCount - 1], cText, 10);
            msg = (CString)"Ena" + (CString)cText;
*/
        } //else msg = "Dis";
//        AfxMessageBox(msg);
	}

	CDialog::OnOK();
}
