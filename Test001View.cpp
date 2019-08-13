// Test001View.cpp : implementation of the CTest001View class
//

#include "stdafx.h"
#include "Test001.h"

#include "Test001Doc.h"
#include "Test001View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTest001View

IMPLEMENT_DYNCREATE(CTest001View, CView)

BEGIN_MESSAGE_MAP(CTest001View, CView)
	//{{AFX_MSG_MAP(CTest001View)
	ON_WM_LBUTTONUP()
	ON_COMMAND(ID_LINE32772, OnLine32772)
	ON_COMMAND(ID_ERASE, OnErase)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTest001View construction/destruction

CTest001View::CTest001View()
{
	// TODO: add construction code here
	// 声明创建对话框
	this->m_MDlg = new CMDlg();
	this->m_MDlg->m_pView=this;

	this->m_point_color=RGB(255,0,0);
}

CTest001View::~CTest001View()
{
	if(this->m_MDlg!=NULL){
		delete this->m_MDlg;
	}
}

BOOL CTest001View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTest001View drawing

void CTest001View::OnDraw(CDC* pDC)
{
	CTest001Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	//this->m_pDC=pDC;
	//COLORREF color = RGB(255,0,0);
	CPoint startPoint,endPoint;
	for(int i=0; i < this->m_pt_array.GetSize(); i++){
		CPoint pt = this->m_pt_array[i];
		
		pDC->SetPixel(pt,this->m_point_color);
		pDC->SetPixel(pt.x,pt.y+1,this->m_point_color);
		pDC->SetPixel(pt.x,pt.y-1,this->m_point_color);
		pDC->SetPixel(pt.x-1,pt.y,this->m_point_color);
		pDC->SetPixel(pt.x+1,pt.y,this->m_point_color);
		// 坐标
		CString str;
		str.Format("(%d,%d)",pt.x,pt.y);
		pDC->TextOut(pt.x+5,pt.y+5,str);
		//  画线
		if(i==0)
			startPoint = this->m_pt_array[i];
		if(i>0){
			endPoint = this->m_pt_array[i];
			BasicGraphic::MID_Line(pDC,startPoint,endPoint,this->m_point_color);
			startPoint = endPoint;
		}
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTest001View printing

BOOL CTest001View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTest001View::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add extra initialization before printing
}

void CTest001View::OnEndPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTest001View diagnostics

#ifdef _DEBUG
void CTest001View::AssertValid() const
{
	CView::AssertValid();
}

void CTest001View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTest001Doc* CTest001View::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTest001Doc)));
	return (CTest001Doc*)m_pDocument;
}

void CTest001View::AddPoint(CPoint pt){
	this->m_pt_array.Add(pt);
}

void CTest001View::SetPointColor(COLORREF color){
	this->m_point_color = color;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTest001View message handlers

void CTest001View::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	// 拾取点
	this->m_pt_array.Add(point); 
	// 传递给对话框
	if(this->m_MDlg->GetSafeHwnd()!=NULL){
		this->m_MDlg->m_X=point.x;
		this->m_MDlg->m_Y=point.y;
		this->m_MDlg->UpdateData(FALSE);
	}
	// 调用 OnDraw()函数
	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}

void CTest001View::OnLine32772() 
{
	// TODO: Add your command handler code here
	if(this->m_MDlg->GetSafeHwnd() == NULL){
		this->m_MDlg->Create();
	}
	else{
		this->m_MDlg->ShowWindow(TRUE);
	}
}

void CTest001View::OnErase() 
{
	// TODO: Add your command handler code here
	
	this->m_pt_array.RemoveAll();
	this->Invalidate();
}
