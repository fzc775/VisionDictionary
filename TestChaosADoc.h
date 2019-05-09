// TestChaosADoc.h : interface of the CTestChaosADoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTCHAOSADOC_H__568DAB6D_2C36_4F67_90D6_0D989536C8ED__INCLUDED_)
#define AFX_TESTCHAOSADOC_H__568DAB6D_2C36_4F67_90D6_0D989536C8ED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTestChaosADoc : public CDocument
{
protected: // create from serialization only
	CTestChaosADoc();
	DECLARE_DYNCREATE(CTestChaosADoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestChaosADoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTestChaosADoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestChaosADoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCHAOSADOC_H__568DAB6D_2C36_4F67_90D6_0D989536C8ED__INCLUDED_)
