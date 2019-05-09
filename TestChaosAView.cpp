// TestChaosAView.cpp : implementation of the CTestChaosAView class
//

#include "stdafx.h"
#include "TestChaosA.h"

#include "TestChaosADoc.h"
#include "TestChaosAView.h"

#include "math.h"
#include "TestCharsDlg.h";

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestChaosAView

IMPLEMENT_DYNCREATE(CTestChaosAView, CView)

BEGIN_MESSAGE_MAP(CTestChaosAView, CView)
	//{{AFX_MSG_MAP(CTestChaosAView)
	ON_COMMAND(ID_MENU_TEST, OnMenuTest)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestChaosAView construction/destruction

CTestChaosAView::CTestChaosAView()
{
	// TODO: add construction code here
	x=y=z=1;
	Af=0.5;
	af=0;
	a=10;
	r=28;
	b=8/3;
	x1=0;
	xll=0;
	h=0.01;
}

CTestChaosAView::~CTestChaosAView()
{
}

BOOL CTestChaosAView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTestChaosAView drawing

void CTestChaosAView::OnDraw(CDC* pDC)
{
	CTestChaosADoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here

	LogisticAlgorithm();
	
	CString str;
	str.Format("%f", xll);

	//pDC->TextOut(50, 50, str);
}

/////////////////////////////////////////////////////////////////////////////
// CTestChaosAView diagnostics

#ifdef _DEBUG
void CTestChaosAView::AssertValid() const
{
	CView::AssertValid();
}

void CTestChaosAView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTestChaosADoc* CTestChaosAView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTestChaosADoc)));
	return (CTestChaosADoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestChaosAView message handlers


void CTestChaosAView::LogisticAlgorithm()
{
	double kx1, ky1, kz1;
	double kx2, ky2, kz2;
	double kx3, ky3, kz3;
	double kx4, ky4, kz4;

	int yy = 20;
	
	for (int i=0; i<50; i++){
		kx1 = (y-x)*a;
		ky1 = r*x-y-x*z;
		kz1 = x*y-b*z;

		kx2 = a*((y+h*ky1/2)-(x+h*kx1/2));//need advanced 
		ky2 = r*(x+h*kx1/2)-(y+h*ky1/2)-(x+h*kx1/2)*(z+h*kz1/2);
		kz2 = (x+h*kx1/2)*(y+h*ky1/2)-b*(z+h*kz1/2);

		kx3 = a*((y+h*ky2/2)-(x+h*kx2/2));
		ky3 = r*(x+h*kx2/2)-(y+h*ky2/2)-(x+h*kx2/2)*(z+h*kz2/2);
		kz3 = (x+h*kx2/2)*(y+h*ky2/2)-b*(z+h*kz2/2);

		kx4 = a*((y+h*ky3)-(x+h*kx3));
		ky4 = r*(x+h*kx3)-(y+h*ky3)-(x+h*kx3)*(z+h*kz3);
		kz4 = (x+h*kx3)*(y+h*ky3)-b*(z+h*kz3);

		x = x+h*(kx1+2*kx2+2*kx3+kx4)/6;
		y = y+h*(ky1+2*ky2+2*ky3+ky4)/6;
		z = z+h*(kz1+2*kz2+2*kz3+kz4)/6;

		x1 = 10*x-GetInt(10*x);

		if (x>=0)
			xll = x1-0.5;
		else
			xll = x1+0.5;
/*
		CDC* pDC = GetDC();
		CString str;
		str.Format("%.8f", xll);
		pDC->TextOut(50, yy, str);
		yy = yy+30;
*/

		x = x+xll;
		y = y+xll;
		z = z+xll;
	}
}

//取得整数部分
double CTestChaosAView::GetInt(double dbX)
{
	double d;
	double f = modf(dbX, &d);
	return d;
}

void CTestChaosAView::OnMenuTest() 
{
	TestCharsDlg dlg;
	int ret = dlg.DoModal();
	TRACE("DoModal return = %d\n", ret);
}
