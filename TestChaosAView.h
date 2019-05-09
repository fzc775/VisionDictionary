// TestChaosAView.h : interface of the CTestChaosAView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTCHAOSAVIEW_H__40A50FF0_ED53_4593_AF6E_7FB047FB9DAE__INCLUDED_)
#define AFX_TESTCHAOSAVIEW_H__40A50FF0_ED53_4593_AF6E_7FB047FB9DAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestChaosAView : public CView
{
protected: // create from serialization only
	CTestChaosAView();
	DECLARE_DYNCREATE(CTestChaosAView)
//Param
public:
	double x;
	double y;
	double z;
	double Af;
	double af;
	double a;
	double r;
	double b;
	double x1;
	double xll;
	double h;

// Attributes
public:
	CTestChaosADoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestChaosAView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	//}}AFX_VIRTUAL

// Implementation
public:
	double GetInt(double dbX);
	void LogisticAlgorithm();
	virtual ~CTestChaosAView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestChaosAView)
	afx_msg void OnMenuTest();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TestChaosAView.cpp
inline CTestChaosADoc* CTestChaosAView::GetDocument()
   { return (CTestChaosADoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCHAOSAVIEW_H__40A50FF0_ED53_4593_AF6E_7FB047FB9DAE__INCLUDED_)
