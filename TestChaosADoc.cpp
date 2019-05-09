// TestChaosADoc.cpp : implementation of the CTestChaosADoc class
//

#include "stdafx.h"
#include "TestChaosA.h"

#include "TestChaosADoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTestChaosADoc

IMPLEMENT_DYNCREATE(CTestChaosADoc, CDocument)

BEGIN_MESSAGE_MAP(CTestChaosADoc, CDocument)
	//{{AFX_MSG_MAP(CTestChaosADoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTestChaosADoc construction/destruction

CTestChaosADoc::CTestChaosADoc()
{
	// TODO: add one-time construction code here

}

CTestChaosADoc::~CTestChaosADoc()
{
}

BOOL CTestChaosADoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTestChaosADoc serialization

void CTestChaosADoc::Serialize(CArchive& ar)
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
// CTestChaosADoc diagnostics

#ifdef _DEBUG
void CTestChaosADoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTestChaosADoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTestChaosADoc commands
