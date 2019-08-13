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

// ֱ�ߵ���ֵ΢���㷨����
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

// ֱ�ߵ��е㻭���㷨����
void BasicGraphic::MID_Line(CDC* &pDC,CPoint startPoint,CPoint endPoint,COLORREF &color){
	if(endPoint.x!=startPoint.x && endPoint.y!=startPoint.y){ // ������λ��ֱ�ߣ�һ��ֱ��
		int kFlag=0;  // 0��б��<=1 , 1:б��>1
		int sFlag=1;  // б�������ı�ʶ
		if(startPoint.x>endPoint.x){	// �������ҷ������
			CPoint pt = startPoint;
			startPoint = endPoint;
			endPoint = pt;
		}
		
		if(abs(endPoint.y-startPoint.y) > abs(endPoint.x-startPoint.x))
			kFlag = 1;   // б�ʾ���ֵ > 1
		if(startPoint.y>endPoint.y)  
			sFlag = -1;  // б�� < 0 �ı�־
		if(sFlag == -1)
			endPoint.y = startPoint.y+(startPoint.y-endPoint.y); // ����x�ᷭת���Ӷ���ת���һ����
		int a,b,tA,tAB,d,x,y;
		a = startPoint.y - endPoint.y;
		b = endPoint.x - startPoint.x;
		x = startPoint.x;
		y = startPoint.y;
		pDC->SetPixel(x,y,color);
		if(kFlag == 0){  // б��<=1
			d = 2*a+b;  // �б�ʽ��ʼֵ
			tA = 2*a;   // d>0 ʱ���б�ʽ����
			tAB = 2*(a+b);  // d<0ʱ���б�ʽ����
			for(int i=0;i<(endPoint.x-startPoint.x);i++){  // x�����н�
				if(d>=0){
					pDC->SetPixel(x+1,y,color);		// ȡ��(x+1,y)
					x+=1;
					d+=tA;
				}
				else{
					pDC->SetPixel(x+1,y+sFlag,color);   // ȡ��(x+1,y+1)
					x+=1;
					y+=sFlag;
					d+=tAB;
				}
			}
		}
		else{  // б��>1
			d=2*b+a;
			tA=2*b;
			tAB = 2*(a+b);
			for(int i=0;i<(endPoint.y-startPoint.y);i++){
				if(d>=0){
					pDC->SetPixel(x+1,y+sFlag,color);  // ȡ��(x+1,y+1)
					x+=1;
					y+=sFlag;
					d+=tAB;
				}
				else{
					pDC->SetPixel(x,y+sFlag,color);   // ȡ��(x,y+1)
					y+=sFlag;
					d+=tA;
				}
			}
		}
	}
	else if(startPoint.x == endPoint.x){  // ��ֱ��
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
	else{  // ˮƽ��
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