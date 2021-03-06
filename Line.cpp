// Line.cpp: implementation of the CLine class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Painter.h"
#include "Line.h"
#include "Shape.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

int CLine::ShapeAmount=0;

CLine::CLine()
{
	setShapeType(LINE);
}
CLine::CLine(COLORREF p_borderColor,
	  COLORREF p_fillColor,
	  CPoint p_startPoint,
	  CPoint p_endPoint):
	CShape(p_borderColor,p_fillColor,p_startPoint,p_endPoint)
{
	ShapeAmount++;
	setShapeType(LINE);
}

//@funcName <draw>
//@statement <根据数据绘制图形>
//@parameter <被绘制设备上下文:CDC>
void CLine :: draw(CDC* pDC)
{
		//创建临时画笔，用于边框颜色
		CPen pen;
		pen.CreatePen(PS_SOLID,1,borderColor);
		pDC->SelectObject(&pen);//把画笔选入设备
		//创建临时画刷，用于填充颜色
		CBrush brush;
		brush.CreateSolidBrush(fillColor);
		pDC->SelectObject(&brush);
		//绘制
		pDC->MoveTo(startPoint);
		pDC->LineTo(endPoint);
		//删除临时工具
		pen.DeleteObject();
		brush.DeleteObject(); 

}

int CLine::Length()
{
	return  PythagorenTheorem(startPoint,endPoint);//；
}

int CLine::Node()
{
	return  getLineNode()+2;//；
}


CLine::~CLine()
{

}
