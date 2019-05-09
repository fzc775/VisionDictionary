// TestCharsDlg.cpp : implementation file
//

#include "stdafx.h"
#include "TestChaosA.h"
#include "TestCharsDlg.h"

#include "math.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// TestCharsDlg dialog


TestCharsDlg::TestCharsDlg(CWnd* pParent /*=NULL*/)
	: CDialog(TestCharsDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(TestCharsDlg)
	m_strDecryptData = _T("");
	m_strEncryptData = _T("");
	m_nInputData = _T("");
	//}}AFX_DATA_INIT
}


void TestCharsDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(TestCharsDlg)
	DDX_Text(pDX, IDC_DECRYPTDATA, m_strDecryptData);
	DDX_Text(pDX, IDC_ENCRYPTDATA, m_strEncryptData);
	DDX_Text(pDX, IDC_INPUTDATA, m_nInputData);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(TestCharsDlg, CDialog)
	//{{AFX_MSG_MAP(TestCharsDlg)
	ON_BN_CLICKED(IDC_BUTTON_DECRYPT, OnButtonDecrypt)
	ON_BN_CLICKED(IDC_BUTTON_ENCRYPT, OnButtonEncrypt)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// TestCharsDlg message handlers

// 解密数据 
void TestCharsDlg::OnButtonDecrypt() 
{
	UpdateData(true);

	//m_strDecryptData = DecryptData(m_strEncryptData, strKey);
	m_strDecryptData = ChaosDecrypt(m_strEncryptData);

	UpdateData(false);
}

// 加密数据
void TestCharsDlg::OnButtonEncrypt() 
{
	//InitiateData();
	//LogisticAlgorithm();
	

	UpdateData(true);

	//m_strEncryptData = EncryptData("12345678", strKey);
	m_strEncryptData = ChaosEncrypt(m_nInputData);

	UpdateData(false);
}

void TestCharsDlg::LogisticAlgorithm()
{
	double kx1, ky1, kz1;
	double kx2, ky2, kz2;
	double kx3, ky3, kz3;
	double kx4, ky4, kz4;

	
	for (int i=0; i<1; i++){
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

		if (x1>=0)
			xll = x1-0.5;
		else
			xll = x1+0.5;

		CString strTemp;
		strTemp.Format("%.8f", xll);

		strKey = GetChaosKey(strTemp);
		AfxMessageBox(strKey);

		x = x+xll;
		y = y+xll;
		z = z+xll;
	}
}

//取得整数部分
double TestCharsDlg::GetInt(double dbX)
{
	double d;
	double f = modf(dbX, &d);
	return d;
}

void TestCharsDlg::InitiateData()
{
	kx1	= ky1 = kz1 = 0;
	kx2 = ky2 = kz2 = 0;
	kx3 = ky3 = kz3 = 0;
	kx4 = ky4 = kz4 = 0;
	x	= y = z = 1;
	Af	= 0.5;
	af	= 0;
	a	= 10;
	r	= 28;
	b	= 8/3;
	x1	= 0;
	xll = 0;
	h	= 0.01;
}



// 取得小数点后8位数，作为一个密钥
CString TestCharsDlg::GetChaosKey(CString strInput)
{
	int site = strInput.Find('.');
	CString strBack = strInput.Mid(++site, 8);
	
	return strBack;
}

// 加密数据，输入数据和密钥均为长度8的字符串
// 返回加密后的密文
CString TestCharsDlg::EncryptData(CString dataIn, CString chaosKey)
{
	int nKey;
	int nTemp;
	char chData;
	CString subKey;
	CString strTemp, strReturn;

	for (int i=0; i<8; i++) {
		chData = dataIn.GetAt(i);
		subKey = chaosKey.Mid(i, 1);

		nKey = atoi(subKey);

		nTemp = chData + nKey;
		strTemp.Format("%c", nTemp);

		strReturn += strTemp;
	}


	return strReturn;
}


// 解密数据，输入数据和密钥均为长度8的字符串
// 返回解密后的密文
CString TestCharsDlg::DecryptData(CString dataIn, CString chaosKey)
{
	int nKey;
	int nTemp;
	char chData;
	CString subKey;
	CString strTemp, strReturn;

	for (int i=0; i<8; i++) {
		chData = dataIn.GetAt(i);
		subKey = chaosKey.Mid(i, 1);

		nKey = atoi(subKey);

		nTemp = chData - nKey;
		strTemp.Format("%c", nTemp);

		strReturn += strTemp;
	}


	return strReturn;
}

// 加密任意长度的数据
CString TestCharsDlg::ChaosEncrypt(CString dataIn)
{
	int dataLen;
	int Offset, Remainder, Quotient;
	int BLOCKSIZE = 8;
	int BlockCount;
	CString strKey, strTemp;
	CString strReturn;		 

	dataLen = dataIn.GetLength();

	// 得到商
	Quotient = dataLen / BLOCKSIZE;
	// 得到余数
	Remainder = dataLen % BLOCKSIZE;

	// 得到实际的分块数
	if (Remainder != 0)
		BlockCount = Quotient + 1;
	else 
		BlockCount = Quotient;

	InitiateData();
	for ( int i=0; i<BlockCount; i++ ) {
		if ( i==Quotient ){
			Offset = Remainder;
			strTemp = dataIn.Mid(i*BLOCKSIZE, Offset);

			// 填充空位
			strTemp += '+';
			for (int j=0; j<BLOCKSIZE-Offset-1; j++)
				strTemp += 'F';
		}
		else {
			Offset = BLOCKSIZE;
			strTemp = dataIn.Mid(i*BLOCKSIZE, Offset);
		}

		strKey = GenerateLogisticKey();	

		strReturn += EncryptData(strTemp, strKey);
	}

	return strReturn;

}

// 解密任意长度的数据
CString TestCharsDlg::ChaosDecrypt(CString dataIn)
{
	int dataLen;
	int BlockCount;
	int BLOCKSIZE = 8;
	CString strKey, strTemp;
	CString strReturn;

	dataLen = dataIn.GetLength();

	// 得到实际的分块数
	BlockCount = dataLen / BLOCKSIZE;

	InitiateData();

	for (int i=0; i<BlockCount; i++) {
		strTemp = dataIn.Mid(i*BLOCKSIZE, BLOCKSIZE);
		strKey = GenerateLogisticKey();

		strReturn += DecryptData(strTemp, strKey);
	}

	int nSite = 0;
	for (int j=dataLen-1; j>(dataLen-8); j--) {
		if (strReturn.GetAt(j)=='+') nSite = j;
	}

	strReturn = strReturn.Mid(0, nSite);

	return strReturn;
}

// 产生一个8位密钥流
CString TestCharsDlg::GenerateLogisticKey()
{
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

		if (x1>=0)
			xll = x1-0.5;
		else
			xll = x1+0.5;

		CString strA;
		strA.Format("%f", xll);
		AfxMessageBox(strA);

		CString strTemp;
		strTemp.Format("%.8f", xll);

		strKey = GetChaosKey(strTemp);
		//AfxMessageBox(strKey);

		x = x+xll;
		y = y+xll;
		z = z+xll;

	return strKey;
}





