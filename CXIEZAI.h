#pragma once
#include "afxdialogex.h"


// CXIEZAI 对话框

class CXIEZAI : public CDialogEx
{
	DECLARE_DYNAMIC(CXIEZAI)

public:
	CXIEZAI(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CXIEZAI();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
