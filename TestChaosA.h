// TestChaosA.h : main header file for the TESTCHAOSA application
//

#if !defined(AFX_TESTCHAOSA_H__B9CC5ACB_D4B1_41E0_8B97_5E30DE1C9A74__INCLUDED_)
#define AFX_TESTCHAOSA_H__B9CC5ACB_D4B1_41E0_8B97_5E30DE1C9A74__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTestChaosAApp:
// See TestChaosA.cpp for the implementation of this class
//

class CTestChaosAApp : public CWinApp
{
public:
	CTestChaosAApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestChaosAApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTestChaosAApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCHAOSA_H__B9CC5ACB_D4B1_41E0_8B97_5E30DE1C9A74__INCLUDED_)
