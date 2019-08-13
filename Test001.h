// Test001.h : main header file for the TEST001 application
//

#if !defined(AFX_TEST001_H__B7B14DE3_1A4D_454C_BBE7_422D3685FA8F__INCLUDED_)
#define AFX_TEST001_H__B7B14DE3_1A4D_454C_BBE7_422D3685FA8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTest001App:
// See Test001.cpp for the implementation of this class
//

class CTest001App : public CWinApp
{
public:
	CTest001App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest001App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTest001App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST001_H__B7B14DE3_1A4D_454C_BBE7_422D3685FA8F__INCLUDED_)
