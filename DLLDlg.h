
// DLLDlg.h: 头文件
//

#pragma once


// CDLLDlg 对话框
class CDLLDlg : public CDialogEx
{
// 构造
public:
	CDLLDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLL_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio7();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnEnChangeMfceditbrowse1();
	CEdit m_edit1;
	CMFCEditBrowseCtrl m_choose;
	CEdit m_edit2;
	afx_msg void OnBnClickedButton1();
	CComboBox m_combo;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton8();
	afx_msg DWORD GetCurrentPID();
	afx_msg PCHAR GetDLLPath();
	afx_msg void OnBnClickedButton6();
	void CDLLDlg::PrintVariableToEditBox(int value);
	void CDLLDlg::PrintTextToEditBox2(const CString& text);
};
