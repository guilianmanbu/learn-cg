#if !defined(AFX_MDLG_H__3598BC34_0D7C_4C62_95EC_3AB5A69E1D21__INCLUDED_)
#define AFX_MDLG_H__3598BC34_0D7C_4C62_95EC_3AB5A69E1D21__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MDlg.h : header file
//

//#include "Test001View.h"
class CTest001View;

/////////////////////////////////////////////////////////////////////////////
// CMDlg dialog

class CMDlg : public CDialog
{
// Construction
public:
	CMDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMDlg)
	enum { IDD = IDD_MDLG };
	int		m_X;
	int		m_Y;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMDlg)
	virtual void OnOK();
	afx_msg void OnButtonColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
// 自定义变量
public:
	CTest001View * m_pView;

// 自定义方法
public:
	BOOL Create();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MDLG_H__3598BC34_0D7C_4C62_95EC_3AB5A69E1D21__INCLUDED_)
