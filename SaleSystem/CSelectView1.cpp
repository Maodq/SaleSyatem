// CSelectView1.cpp: 实现文件
//

#include "pch.h"
#include "SaleSystem.h"
#include "CSelectView1.h"


// CSelectView1

IMPLEMENT_DYNCREATE(CSelectView1, CTreeView)

CSelectView1::CSelectView1()
{

}

CSelectView1::~CSelectView1()
{
}

BEGIN_MESSAGE_MAP(CSelectView1, CTreeView)
END_MESSAGE_MAP()


// CSelectView1 诊断

#ifdef _DEBUG
void CSelectView1::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CSelectView1::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSelectView1 消息处理程序
