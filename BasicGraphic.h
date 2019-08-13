// BasicGraphic.h: interface for the BasicGraphic class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASICGRAPHIC_H__FC4EAFC1_C51C_40DE_A71A_044BCF2B162B__INCLUDED_)
#define AFX_BASICGRAPHIC_H__FC4EAFC1_C51C_40DE_A71A_044BCF2B162B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class BasicGraphic  
{
public:
	BasicGraphic();
	virtual ~BasicGraphic();

	// 直线的数值微分算法函数
	static void DDA_Line(CDC* &pDC,CPoint &startPoint,CPoint &endPoint,COLORREF &color);
	// 直线的中点画线算法函数
	static void MID_Line(CDC* &pDC,CPoint startPoint,CPoint endPoint,COLORREF &color);
};

#endif // !defined(AFX_BASICGRAPHIC_H__FC4EAFC1_C51C_40DE_A71A_044BCF2B162B__INCLUDED_)
