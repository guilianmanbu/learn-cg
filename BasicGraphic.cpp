// BasicGraphic.cpp: implementation of the BasicGraphic class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Test001.h"
#include "BasicGraphic.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

BasicGraphic::BasicGraphic()
{

}

BasicGraphic::~BasicGraphic()
{

}

// 直线的数值微分算法函数
void BasicGraphic::DDA_Line(CDC* & pDC,CPoint& startPoint,CPoint& endPoint,COLORREF &color){
	if(endPoint.x!=startPoint.x && endPoint.y!=startPoint.y){
		double k = ((float)(endPoint.y-startPoint.y)) / ((float)(endPoint.x-startPoint.x));
		double x = (double)startPoint.x;
		double y = (double)startPoint.y;
		pDC->SetPixel((int)x,(int)y,color);
		if(abs(k)<=1.0){
			if(endPoint.x>startPoint.x){
				for(int i=0;i<(endPoint.x-startPoint.x);i++){
					x +=1;
					y +=k;
					pDC->SetPixel((int)x,(int)(y+0.5),color);
				}
			}
			else{
				for(int i=0;i<(startPoint.x-endPoint.x);i++){
					x -= 1;
					y -= k;
					pDC->SetPixel((int)x,(int)(y+0.5),color);
				}
			}
		}
		else{
			double invK = 1.0 / k;
			for(int i=0;i<abs(endPoint.y-startPoint.y);i++){
				if(endPoint.y>startPoint.y){
					y += 1;
					x += invK;
				}else{
					y -= 1;
					x -= invK;
				}
				pDC->SetPixel((int)(x+0.5),(int)y,color);
			}
		}
	}
	else if(startPoint.x == endPoint.x){
		if(startPoint.y<endPoint.y){
			for(int i=startPoint.y;i<=endPoint.y;i++){
				pDC->SetPixel(startPoint.x,i,color);
			}
		}
		else{
			for(int i=startPoint.y;i>=endPoint.y;i--){
				pDC->SetPixel(startPoint.x,i,color);
			}
		}
	}
	else{
		if(startPoint.x<endPoint.x){
			for(int i=startPoint.x;i<=endPoint.x;i++){
				pDC->SetPixel(i,startPoint.y,color);
			}
		}
		else{
			for(int i=startPoint.x;i>=endPoint.x;i--){
				pDC->SetPixel(i,startPoint.y,color);
			}
		}
	}
}

// 直线的中点画线算法函数
void BasicGraphic::MID_Line(CDC* &pDC,CPoint startPoint,CPoint endPoint,COLORREF &color){
	if(endPoint.x!=startPoint.x && endPoint.y!=startPoint.y){ // 非特殊位置直线，一般直线
		int kFlag=0;  // 0：斜率<=1 , 1:斜率>1
		int sFlag=1;  // 斜率正负的标识
		if(startPoint.x>endPoint.x){	// 从左向右方向绘制
			CPoint pt = startPoint;
			startPoint = endPoint;
			endPoint = pt;
		}
		
		if(abs(endPoint.y-startPoint.y) > abs(endPoint.x-startPoint.x))
			kFlag = 1;   // 斜率绝对值 > 1
		if(startPoint.y>endPoint.y)  
			sFlag = -1;  // 斜率 < 0 的标志
		if(sFlag == -1)
			endPoint.y = startPoint.y+(startPoint.y-endPoint.y); // 关于x轴翻转，从而都转入第一象限
		int a,b,tA,tAB,d,x,y;
		a = startPoint.y - endPoint.y;
		b = endPoint.x - startPoint.x;
		x = startPoint.x;
		y = startPoint.y;
		pDC->SetPixel(x,y,color);
		if(kFlag == 0){  // 斜率<=1
			d = 2*a+b;  // 判别式初始值
			tA = 2*a;   // d>0 时，判别式增量
			tAB = 2*(a+b);  // d<0时，判别式增量
			for(int i=0;i<(endPoint.x-startPoint.x);i++){  // x方向行进
				if(d>=0){
					pDC->SetPixel(x+1,y,color);		// 取点(x+1,y)
					x+=1;
					d+=tA;
				}
				else{
					pDC->SetPixel(x+1,y+sFlag,color);   // 取点(x+1,y+1)
					x+=1;
					y+=sFlag;
					d+=tAB;
				}
			}
		}
		else{  // 斜率>1
			d=2*b+a;
			tA=2*b;
			tAB = 2*(a+b);
			for(int i=0;i<(endPoint.y-startPoint.y);i++){
				if(d>=0){
					pDC->SetPixel(x+1,y+sFlag,color);  // 取点(x+1,y+1)
					x+=1;
					y+=sFlag;
					d+=tAB;
				}
				else{
					pDC->SetPixel(x,y+sFlag,color);   // 取点(x,y+1)
					y+=sFlag;
					d+=tA;
				}
			}
		}
	}
	else if(startPoint.x == endPoint.x){  // 竖直线
		if(startPoint.y<endPoint.y){
			for(int i=startPoint.y;i<=endPoint.y;i++){
				pDC->SetPixel(startPoint.x,i,color);
			}
		}
		else{
			for(int i=startPoint.y;i>=endPoint.y;i--){
				pDC->SetPixel(startPoint.x,i,color);
			}
		}
	}
	else{  // 水平线
		if(startPoint.x<endPoint.x){
			for(int i=startPoint.x;i<=endPoint.x;i++){
				pDC->SetPixel(i,startPoint.y,color);
			}
		}
		else{
			for(int i=startPoint.x;i>=endPoint.x;i--){
				pDC->SetPixel(i,startPoint.y,color);
			}
		}
	}
}

// 直线的 Bresenham 算法函数
void BasicGraphic::BRESENHAM_Line(CDC *&pDC,CPoint startPoint,CPoint endPoint,COLORREF &color){
	if(endPoint.x!=startPoint.x && endPoint.y!=startPoint.y){  // 非特殊位置直线，一般直线
		int kFlag =0;  //  0：斜率<=1 , 1:斜率>1
		int sFlag = 1;  // 斜率正负的标识
		// 首先判断两个端点，通过交换使起点小于终点
		if(startPoint.x > endPoint.x){
			CPoint pt = startPoint;
			startPoint = endPoint;
			endPoint = pt;
		}
		if(abs(endPoint.y-startPoint.y) > abs(endPoint.x-startPoint.x))
			kFlag = 1;   // 斜率绝对值 > 1
		if(startPoint.y > endPoint.y)
			sFlag = -1;  // 斜率 < 0 的标志
		if(sFlag == -1)  // 关于x轴翻转，从而都转入第一象限
			endPoint.y=startPoint.y+(startPoint.y-endPoint.y);
		int x,y,dx,dy,p;
		dx = endPoint.x-startPoint.x;
		dy = endPoint.y-startPoint.y;
		x = startPoint.x;
		y = startPoint.y;
		pDC->SetPixel(x,y,color);
		if(kFlag==0){  // 斜率<=1  沿x方向行进
			p = 2*dy-dx;  // 判别式初始值
			for(int i=0;i<(endPoint.x-startPoint.x);i++){
				if(p<=0){
					pDC->SetPixel(x+1,y,color);  // 取点(x+1,y)
					x+=1;
					p+=2*dy;
				}
				else{
					pDC->SetPixel(x+1,y+sFlag,color);  // 取点(x+1,y+1)
					x+=1;
					y+=sFlag;
					p+=2*dy-2*dx;
				}
			}
		}
		else{  // 斜率>1  沿y方向行进
			p = 2*dx-dy;
			for(int i=0;i<(endPoint.y-startPoint.y);i++){
				if(p<=0){
					pDC->SetPixel(x,y+sFlag,color);  // 取点(x,y+1)
					y+=sFlag;
					p+=2*dx;
				}
				else{
					pDC->SetPixel(x+1,y+sFlag,color);  // 取点(x+1,y+1)
					y+=sFlag;
					x+=1;
					p+=2*dx-2*dy;
				}
			}
		}
	}
	else if(startPoint.x == endPoint.x){  // 竖直线
		if(startPoint.y<endPoint.y){
			for(int i=startPoint.y;i<=endPoint.y;i++){
				pDC->SetPixel(startPoint.x,i,color);
			}
		}
		else{
			for(int i=startPoint.y;i>=endPoint.y;i--){
				pDC->SetPixel(startPoint.x,i,color);
			}
		}
	}
	else{  // 水平线
		if(startPoint.x<endPoint.x){
			for(int i=startPoint.x;i<=endPoint.x;i++){
				pDC->SetPixel(i,startPoint.y,color);
			}
		}
		else{
			for(int i=startPoint.x;i>=endPoint.x;i--){
				pDC->SetPixel(i,startPoint.y,color);
			}
		}
	}
}
/* Bresenham 算法与中点算法相似，都通过判别式来确定，
在一个方向还是两个方向同时递增，同时根据递增方向确定判别式的递增量。
两种算法的区别在于判别式的不同。 */