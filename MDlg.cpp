// MDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Test001.h"
#include "MDlg.h"
#include "Test001View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMDlg dialog


CMDlg::CMDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMDlg)
	m_X = 0;
	m_Y = 0;
	//}}AFX_DATA_INIT
}


void CMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMDlg)
	DDX_Text(pDX, IDC_EDITX, m_X);
	DDX_Text(pDX, IDC_EDITY, m_Y);
	//}}AFX_DATA_MAP
}

BOOL CMDlg::Create(){
	return CDialog::Create(132);  // CMDlg:IDD_MDLG
}


BEGIN_MESSAGE_MAP(CMDlg, CDialog)
	//{{AFX_MSG_MAP(CMDlg)
	ON_BN_CLICKED(IDC_BUTTON1, OnButtonColor)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMDlg message handlers

void CMDlg::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(TRUE);
	CPoint pt;
	pt.x=this->m_X;
	pt.y=this->m_Y;
	
	this->m_pView->SetPointColor(RGB(255,0,0));
	this->m_pView->AddPoint(pt);
	this->m_pView->Invalidate();
	// CDialog::OnOK();
}

void CMDlg::OnButtonColor() 
{
	// TODO: Add your control notification handler code here
	CColorDialog dlg;
	dlg.m_cc.Flags |= CC_RGBINIT|CC_FULLOPEN;
	if(IDOK == dlg.DoModal()){
		this->m_pView->SetPointColor(dlg.m_cc.rgbResult);
		this->m_pView->Invalidate();
	}
}
