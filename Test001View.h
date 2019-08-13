// Test001View.h : interface of the CTest001View class
//
/////////////////////////////////////////////////////////////////////////////

#include<afxtempl.h>
#include<math.h>
#include "MDlg.h"
#include "BasicGraphic.h"

#if !defined(AFX_TEST001VIEW_H__4BC7723F_025D_42C5_B0F2_59136722953D__INCLUDED_)
#define AFX_TEST001VIEW_H__4BC7723F_025D_42C5_B0F2_59136722953D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CTest001Doc;
class CDC;
class CTest001View : public CView
{
protected: // create from serialization only
	CTest001View();
	DECLARE_DYNCREATE(CTest001View)

// Attributes
public:
	CTest001Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest001View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest001View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest001View)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLine32772();
	afx_msg void OnErase();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

private:
	
public:
	CArray<CPoint,CPoint> m_pt_array;
	CMDlg* m_MDlg;
	//CDC* m_pDC;
	COLORREF m_point_color;

public:
	void AddPoint(CPoint point);
	void SetPointColor(COLORREF color);
};

#ifndef _DEBUG  // debug version in Test001View.cpp
inline CTest001Doc* CTest001View::GetDocument()
   { return (CTest001Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST001VIEW_H__4BC7723F_025D_42C5_B0F2_59136722953D__INCLUDED_)
