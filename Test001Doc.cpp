// Test001Doc.cpp : implementation of the CTest001Doc class
//

#include "stdafx.h"
#include "Test001.h"

#include "Test001Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest001Doc

IMPLEMENT_DYNCREATE(CTest001Doc, CDocument)

BEGIN_MESSAGE_MAP(CTest001Doc, CDocument)
	//{{AFX_MSG_MAP(CTest001Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest001Doc construction/destruction

CTest001Doc::CTest001Doc()
{
	// TODO: add one-time construction code here

}

CTest001Doc::~CTest001Doc()
{
}

BOOL CTest001Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTest001Doc serialization

void CTest001Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTest001Doc diagnostics

#ifdef _DEBUG
void CTest001Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTest001Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest001Doc commands
