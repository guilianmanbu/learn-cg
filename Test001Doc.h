// Test001Doc.h : interface of the CTest001Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TEST001DOC_H__87C714B4_878A_4033_BF07_46CC04D90B72__INCLUDED_)
#define AFX_TEST001DOC_H__87C714B4_878A_4033_BF07_46CC04D90B72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTest001Doc : public CDocument
{
protected: // create from serialization only
	CTest001Doc();
	DECLARE_DYNCREATE(CTest001Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTest001Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTest001Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTest001Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TEST001DOC_H__87C714B4_878A_4033_BF07_46CC04D90B72__INCLUDED_)
