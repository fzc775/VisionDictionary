#if !defined(AFX_TESTCHARSDLG_H__A624C148_1B67_4BA8_84F7_9607709FA0E6__INCLUDED_)
#define AFX_TESTCHARSDLG_H__A624C148_1B67_4BA8_84F7_9607709FA0E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TestCharsDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// TestCharsDlg dialog

class TestCharsDlg : public CDialog
{
public:
	double kx1, ky1, kz1;
	double kx2, ky2, kz2;
	double kx3, ky3, kz3;
	double kx4, ky4, kz4;
	double x, y, z;
	double Af, af;
	double a, r, b;
	double x1;
	double xll;
	double h;

	CString strKey;

// Construction
public:
	CString ChaosDecrypt(CString dataIn);
	CString ChaosEncrypt(CString dataIn);
	void InitiateData();
	double GetInt(double dbX);
	void LogisticAlgorithm();
	TestCharsDlg(CWnd* pParent = NULL);   // standard constructor

private:
	CString GenerateLogisticKey();
	CString DecryptData(CString dataIn, CString chaosKey);
	CString EncryptData(CString dataIn, CString chaosKey);
	CString GetChaosKey(CString strInput);


// Dialog Data
	//{{AFX_DATA(TestCharsDlg)
	enum { IDD = IDD_DIALOG1 };
	CString	m_strDecryptData;
	CString	m_strEncryptData;
	CString	m_nInputData;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(TestCharsDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(TestCharsDlg)
	afx_msg void OnButtonDecrypt();
	afx_msg void OnButtonEncrypt();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTCHARSDLG_H__A624C148_1B67_4BA8_84F7_9607709FA0E6__INCLUDED_)
