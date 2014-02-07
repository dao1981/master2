// DlgBDTl2.cpp : implementation file
//

#include "stdafx.h"
#include "master.h"
#include "DlgBDTl2.h"
#include ".\dlgbdtl2.h"
#include "DlgSprav1.h"
#include "DlgBDSelectRezDTL.h"
// CDlgBDTl2 dialog

IMPLEMENT_DYNAMIC(CDlgBDTl2, CDialog)
CDlgBDTl2::CDlgBDTl2(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgBDTl2::IDD, pParent)
{
	iType = 0;
}

CDlgBDTl2::~CDlgBDTl2()
{
}

void CDlgBDTl2::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_Dat1);
	DDX_Control(pDX, IDC_EDIT2, m_Dat2);
	DDX_Control(pDX, IDC_EDIT7, m_Dat3);
	DDX_Control(pDX, IDC_EDIT5, m_Dat4);
	DDX_Control(pDX, IDC_EDIT6, m_EdNVag1);
	DDX_Control(pDX, IDC_EDIT130, m_EdNVag2);
	DDX_Control(pDX, IDC_COMBO3, m_cbRem1);
	DDX_Control(pDX, IDC_COMBO6, m_cbRem2);
	DDX_Control(pDX, IDC_EDIT120, m_EdKlPr);
	DDX_Control(pDX, IDC_EDIT157, m_PrName);
	DDX_Control(pDX, IDC_EDIT94, m_Dat5);
	DDX_Control(pDX, IDC_EDIT70, m_Dat6);
	DDX_Control(pDX, IDC_EDIT133, m_EdNDet);
	DDX_Control(pDX, IDC_CHECK1, m_Check1);
	DDX_Control(pDX, IDC_CHECK31, m_Check2);
	DDX_Control(pDX, IDC_CHECK47, m_Check3);
	DDX_Control(pDX, IDC_CHECK39, m_Check4);
	DDX_Control(pDX, IDC_CHECK40, m_Check5);
	DDX_Control(pDX, IDC_CHECK44, m_Check6);
	DDX_Control(pDX, IDC_CHECK45, m_Check7);
	DDX_Control(pDX, IDC_CHECK46, m_Check8);
	DDX_Control(pDX, IDC_BUTTON4, m_butPR);
}


BEGIN_MESSAGE_MAP(CDlgBDTl2, CDialog)
	ON_BN_CLICKED(IDC_CHECK1, OnBnClickedCheck1_DatPost)
	ON_BN_CLICKED(IDC_CHECK31, OnBnClickedCheck2_DatRash)
	ON_BN_CLICKED(IDC_CHECK47, OnBnClickedCheck3_Neizr)
	ON_BN_CLICKED(IDC_CHECK39, OnBnClickedCheck4_VagNPost)
	ON_BN_CLICKED(IDC_CHECK40, OnBnClickedCheck5_VagNRash)
	ON_BN_CLICKED(IDC_CHECK44, OnBnClickedCheck6_PrIzg)
	ON_BN_CLICKED(IDC_CHECK45, OnBnClickedCheck7_GodIzg)
	ON_BN_CLICKED(IDC_CHECK46, OnBnClickedCheck8_MaskNDet)
	ON_BN_CLICKED(IDC_BUTTON4, OnBnClickedButton4)
	ON_BN_CLICKED(IDOK, OnBnClickedOk)
END_MESSAGE_MAP()


// CDlgBDTl2 message handlers

void CDlgBDTl2::OnBnClickedCheck1_DatPost()
{
	m_Dat1.EnableWindow(m_Check1.GetCheck());
	m_Dat2.EnableWindow(m_Check1.GetCheck());
}

void CDlgBDTl2::OnBnClickedCheck2_DatRash()
{
	m_Dat3.EnableWindow(m_Check2.GetCheck());
	m_Dat4.EnableWindow(m_Check2.GetCheck());
	m_Check3.SetCheck(0);
}

void CDlgBDTl2::OnBnClickedCheck3_Neizr()
{
	m_Check2.SetCheck(0);
	m_Dat3.EnableWindow(m_Check2.GetCheck());
	m_Dat4.EnableWindow(m_Check2.GetCheck());

}

void CDlgBDTl2::OnBnClickedCheck4_VagNPost()
{
	m_EdNVag1.EnableWindow(m_Check4.GetCheck());
	m_cbRem1.EnableWindow(m_Check4.GetCheck());
}

void CDlgBDTl2::OnBnClickedCheck5_VagNRash()
{
	m_EdNVag2.EnableWindow(m_Check5.GetCheck());
	m_cbRem2.EnableWindow(m_Check5.GetCheck());
}

void CDlgBDTl2::OnBnClickedCheck6_PrIzg()
{
	m_EdKlPr.EnableWindow(m_Check6.GetCheck());
	m_butPR.EnableWindow(m_Check6.GetCheck());
	m_PrName.EnableWindow(m_Check6.GetCheck());
}

void CDlgBDTl2::OnBnClickedCheck7_GodIzg()
{
	m_Dat5.EnableWindow(m_Check7.GetCheck());
	m_Dat6.EnableWindow(m_Check7.GetCheck());
}

void CDlgBDTl2::OnBnClickedCheck8_MaskNDet()
{
	m_EdNDet.EnableWindow(m_Check8.GetCheck());
}

BOOL CDlgBDTl2::OnInitDialog()
{
	CDialog::OnInitDialog();

	if( iType ) SetWindowText("Фильтр выборки из БД надрессорных балок");

	m_EdNDet.SetMode(0, 1, 10);
	m_EdKlPr.QInit(20, 1);
	m_PrName.SetMode(0, 1);
	m_EdNDet.SetMode(0, 1, 10);
	m_EdNVag1.SetMode(0, 1, 10);
	m_EdNVag2.SetMode(0, 1, 10);

	DBW.FillComboWithTRemVag(&m_cbRem1);
	DBW.FillComboWithTRemVag(&m_cbRem2);

	return TRUE;
}

void CDlgBDTl2::OnBnClickedButton4()
{
	CDlgSprav1 Dlg;
//	Dlg.iDlgKind = 6;
	if( Dlg.DoModal() == IDCANCEL ) return;
	m_EdKlPr.SetData(Dlg.ret_dwIPR);
	m_EdKlPr.SetWindowText(Dlg.cKodPr);
	m_PrName.SetWindowText(Dlg.cPrName);
}

void CDlgBDTl2::OnBnClickedOk()
{
	CDlgBDSelectRezDTL Dlg;
	
	DWORD x1 =  0;//( m_cbRem1.GetCurSel() == -1 ? 0 : m_cbRem1.GetItemData(m_cbRem1.GetCurSel()));
	if( m_cbRem1.GetCurSel() == -1 )
		x1 = 0;
	else
		x1 = m_cbRem1.GetItemData(m_cbRem1.GetCurSel());
	CString cProcName = "pTov_BDBRSelect ";
	if( iType )
	{
		cProcName = "pTov_BDNBSelect ";
		Dlg.iDetailID = 1;
	}
	sprintf(Dlg.cQ, "%s %d, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s, %s",
			cProcName,
			g_iDep,
			isAble(m_Check1.GetCheck(), m_Dat1.GetSQLDate()),
			isAble(m_Check1.GetCheck(), m_Dat2.GetSQLDate()),
			isAble(m_Check2.GetCheck(), m_Dat3.GetSQLDate()),
			isAble(m_Check2.GetCheck(), m_Dat4.GetSQLDate()),
			isNull((WORD)m_Check3.GetCheck()),
			isAble(m_Check4.GetCheck(), isNull(m_EdNVag1.GetAsString())),
//			isAble(m_Check4.GetCheck(), isNull( m_cbRem1.GetCurSel() == -1 ? 0 : m_cbRem1.GetItemData(m_cbRem1.GetCurSel()) )),
			isAble(m_Check4.GetCheck(), isNull(x1)),
			isAble(m_Check5.GetCheck(), isNull(m_EdNVag2.GetAsString())),
			isAble(m_Check5.GetCheck(), isNull( m_cbRem2.GetCurSel() == -1 ? 0 : m_cbRem2.GetItemData(m_cbRem2.GetCurSel()) )),
			isAble(m_Check6.GetCheck(), isNull(m_EdKlPr.GetData())),
			isAble(m_Check7.GetCheck(), m_Dat5.GetSQLDate()),
			isAble(m_Check7.GetCheck(), m_Dat6.GetSQLDate()),
			isAble(m_Check8.GetCheck(), isNull(m_EdNDet.GetString())));
	
	
	if( Dlg.DoModal() == IDCANCEL ) return;
	OnOK();
}
