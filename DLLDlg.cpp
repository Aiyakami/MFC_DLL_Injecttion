
// DLLDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "DLL.h"
#include "DLLDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//日志功能实现函数
void  CDLLDlg::PrintVariableToEditBox(int value)
{
	// 获取编辑框的当前文本长度
	int length = m_edit1.GetWindowTextLength();
	int m_lastPrintPos = 0;
	// 将光标移动到上一次打印结束的位置下方
	m_edit1.SetSel(length, length);
	m_edit1.ReplaceSel(_T("\r"));

	// 打印新的变量值
	CString newText;
	newText.Format(_T("%d\r\n"), value); // 这里使用 \r\n 换行
	m_edit1.ReplaceSel(newText);

	// 记录打印结束的位置
	m_lastPrintPos = m_edit1.GetWindowTextLength();
}

void  CDLLDlg::PrintTextToEditBox2(const CString& text)
{
	// 获取编辑框的当前文本长度
	int length = m_edit1.GetWindowTextLength();
	int m_lastPrintPos = 0;
	// 将光标移动到上一次打印结束的位置下方
	m_edit1.SetSel(length, length);
	m_edit1.ReplaceSel(_T("\r"));

	// 打印新的文字
	CString newText = text + _T("\r\n");
	m_edit1.ReplaceSel(newText);

	// 记录打印结束的位置
	m_lastPrintPos = m_edit1.GetWindowTextLength();
}

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDLLDlg 对话框



CDLLDlg::CDLLDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DLL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDI_ICON1);
}

void CDLLDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	//DDX_Control(pDX, IDC_MFCEDITBROWSE1, m_choose);
	DDX_Control(pDX, IDC_EDIT6, m_edit2);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Control(pDX, IDC_EDIT7, m_edit1);
}

BEGIN_MESSAGE_MAP(CDLLDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_RADIO7, &CDLLDlg::OnBnClickedRadio7)
	ON_CBN_SELCHANGE(IDC_COMBO4, &CDLLDlg::OnCbnSelchangeCombo4)
	//ON_EN_CHANGE(IDC_MFCEDITBROWSE1, &CDLLDlg::OnEnChangeMfceditbrowse1)
	ON_BN_CLICKED(IDC_BUTTON1, &CDLLDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CDLLDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CDLLDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON8, &CDLLDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON6, &CDLLDlg::OnBnClickedButton6)
END_MESSAGE_MAP()


// CDLLDlg 消息处理程序

BOOL CDLLDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	//默认编辑框位500
	//m_choose.
	m_edit2.SetWindowTextW(TEXT("WH_TOURNALRECORD"));
	m_edit1.SetWindowTextW(TEXT("500"));
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CDLLDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CDLLDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CDLLDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CDLLDlg::OnBnClickedRadio7()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDLLDlg::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CDLLDlg::OnEnChangeMfceditbrowse1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


#include <windows.h>
#include <tlhelp32.h>
#define MAX_PROCESSES 1024
//刷新
void CDLLDlg::OnBnClickedButton1()
{
	HANDLE hSnapshot;
	PROCESSENTRY32 pe32;

	// 创建进程快照
	hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (hSnapshot == INVALID_HANDLE_VALUE) {
		printf("Failed to create snapshot\n");
		return;
	}

	pe32.dwSize = sizeof(PROCESSENTRY32);

	// 获取第一个进程
	if (!Process32First(hSnapshot, &pe32)) {
		printf("Failed to get process information\n");
		CloseHandle(hSnapshot);
		return;
	}

	// 保存进程信息的数组
	wchar_t processes[MAX_PROCESSES][MAX_PATH];
	int count = 0;

	// 遍历进程列表
	do {
		wcscpy(processes[count], pe32.szExeFile);//两个字符指针 宽自己复制
		count++;
	} while (Process32Next(hSnapshot, &pe32) && count < MAX_PROCESSES);

	// 输出进程列表
	for (int i = 0; i < count; i++) {
		//wprintf(L"%ls\n", processes[i]);
		m_combo.AddString(processes[i]);//循环写入下拉框控件
	}
	CloseHandle(hSnapshot);
}

#include <vector>
bool fuzzyMatch(CString str, CString sub) {
	std::vector<int> indices; // 存储所有匹配的索引
	int index = str.Find(sub[0]); // 在主字符串中查找子串的第一个字符
	while (index != -1) { // 继续查找直到子串不再出现
		bool match = true;
		// 检查子串的其余字符是否按顺序出现在主字符串中（不必相邻）
		for (int i = 1; i < sub.GetLength(); i++) {
			if (str.Mid(index + i, 1) != sub.Mid(i, 1)) {
				match = false;
				break;
			}
		}
		if (match) {
			indices.push_back(index); // 记录匹配索引
		}
		index = str.Find(sub[0], index + 1); // 在主字符串中查找下一个子串的第一个字符
	}
	return !indices.empty(); // 如果存在匹配，则返回true
}

//筛选函数
void CDLLDlg::OnBnClickedButton4()
{
	//遍历下拉框的内容
	int nCount = m_combo.GetCount(); // 获取下拉框中项目的数量
	for (int i = 0; i < nCount; i++)
	{
		//获取编辑框的内容
		CString strContent;
		GetDlgItemText(IDC_EDIT2, strContent); // IDC_YOUR_EDIT_CONTROL 是编辑框的ID
		CString strItemText;
		m_combo.GetLBText(i, strItemText); // 获取索引为i的项目文本
		//进行匹配，匹配成功保留，不成就删除当前元素
		if (!fuzzyMatch(strItemText, strContent)) {
			m_combo.DeleteString(i);//减去之后会自动往前缩进
			i--;
			nCount -= 1;
		}
	}
}

//选择DLL实现
void CDLLDlg::OnBnClickedButton5()
{
	CString selectedFile;
	// 构造文件对话框对象
	CFileDialog fileDlg(TRUE);
	// 设置对话框的标题和过滤器
	fileDlg.m_ofn.lpstrTitle = _T("选择文件");
	fileDlg.m_ofn.lpstrFilter = _T("所有文件 (*.*)|*.*||");

	// 显示文件对话框，让用户选择文件
	if (fileDlg.DoModal() == IDOK) {
		selectedFile = fileDlg.GetPathName(); // 获取用户选择的文件路径
		//写入控件中
		SetDlgItemText(IDC_EDIT3, selectedFile);
	}
}

DWORD FindProcessIdByProcessName(CString processName)
{
	HANDLE hSnapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (INVALID_HANDLE_VALUE == hSnapshot) return 0;
	PROCESSENTRY32 pe32;
	pe32.dwSize = sizeof(PROCESSENTRY32);

	if (!Process32First(hSnapshot, &pe32))
	{
		CloseHandle(hSnapshot);
		return 0;
	}
	do
	{
		// 在这里，我们将pe32.szExeFile（当前遍历到的进程名）与传入的processName进行比较
		if (processName.CompareNoCase(pe32.szExeFile) == 0)
		{
			CloseHandle(hSnapshot);
			return pe32.th32ProcessID; // 找到匹配的进程，返回其PID
		}
	} while (Process32Next(hSnapshot, &pe32));

	CloseHandle(hSnapshot); // 关闭快照句柄
	return 0; // 没有找到匹配的进程，返回0
}


DWORD CDLLDlg::GetCurrentPID() {
	int nIndex = m_combo.GetCurSel(); // 获取当前选中项的索引
	if (nIndex != CB_ERR) // 确保有选中项
	{
		CString strSelectedText;
		m_combo.GetLBText(nIndex, strSelectedText); // 获取选中项的文本

		//根据文本取出PID
		DWORD PID = FindProcessIdByProcessName(strSelectedText);
		return PID;
	}
}

PCHAR CDLLDlg::GetDLLPath() {
	CString Content;
	GetDlgItemText(IDC_EDIT3, Content); // IDC_YOUR_EDIT_CONTROL 是编辑框的ID


	//char* psz = Content.GetBuffer(Content.GetLength());

	LPWSTR lpwstr = Content.GetBuffer(Content.GetLength());
	// 第一步：计算所需的缓冲区大小
	int bufferSize = WideCharToMultiByte(CP_ACP, 0, lpwstr, -1, NULL, 0, NULL, NULL);//ANSI编码（CP_ACP）和UTF-8编码（CP_UTF8）
	if (bufferSize == 0) {
		return NULL;
	}
	// 第二步：分配缓冲区
	char* utf8Str = new char[bufferSize];
	// 第三步：执行转换
	int result = WideCharToMultiByte(CP_UTF8, 0, lpwstr, -1, utf8Str, bufferSize, NULL, NULL);
	if (result == 0) {
		delete[] utf8Str; // 清理分配的内存
		return NULL;
	};
	return utf8Str;
}

//远程线程注入声明
BOOL RemoteThreadInject(DWORD dwPID, char* pszDllPath);

//消息钩子关键函数声明
DWORD getThreadID(DWORD ulTargetProcessID);
BOOL InjectDllBySetWindowsHook(DWORD ulTargetProcessID, PCHAR ptr);

//消息钩子注入定义
BOOL MessageHookInject(DWORD pid, PCHAR ptr)
{
	//开始消息钩子注入
	if (!InjectDllBySetWindowsHook(pid, ptr))
	{
		cout << "Set Hook Failed!\r\n" << endl;
		return FALSE;
	}
	cout << "Inject Success!\r\n" << endl;
	return TRUE;
}


//注入  远程线程注入 PID DLL路径
void CDLLDlg::OnBnClickedButton8()//类的命名空间
{
	//获取pid
	DWORD pid = GetCurrentPID();
	//DLL路径
	PCHAR ptr = GetDLLPath(); //char*  pchar
	//获取注入方式的选择
	//int method = GetInjectMethod();
	//注入
	//int method = 1;
	//switch (method)
	//{
	//case 1:
	//	RemoteThreadInject(pid, ptr);
	//default:
	//	break;
	//}
	int nRadioID = GetCheckedRadioButton(IDC_RADIO1, IDC_RADIO7);
	// 使用switch语句根据选择调用不同的函数
	switch (nRadioID)
	{
	case IDC_RADIO1:
		RemoteThreadInject(pid, ptr);
		break;

	case IDC_RADIO2:
		MessageHookInject(pid, ptr);
		break;

	case IDC_RADIO3:
		//注入方式三
		break;

	case IDC_RADIO4:
		//注入方式四
		break;

	case IDC_RADIO5:
		//注入方式五
		break;

	case IDC_RADIO6:
		//注入方式六
		break;

	case IDC_RADIO7:
		//注入方式七
		break;

	default:
		break;
	}

}


void CDLLDlg::OnBnClickedButton6()
{
	CString selectedFile;
	// 构造文件对话框对象
	CFileDialog fileDlg(TRUE);

	// 设置对话框的标题和过滤器
	fileDlg.m_ofn.lpstrTitle = _T("选择文件");
	fileDlg.m_ofn.lpstrFilter = _T("所有文件 (*.*)|*.*||");

	// 显示文件对话框，让用户选择文件
	if (fileDlg.DoModal() == IDOK) {
		selectedFile = fileDlg.GetPathName(); // 获取用户选择的文件路径
		//写入控件中
		SetDlgItemText(IDC_EDIT2, selectedFile);
	}
}

//远程线程注入实现
BOOL RemoteThreadInject(DWORD dwPID, char* pszDllPath) {
	HANDLE hProcess, hThread;
	LPVOID pRemoteBuf;
	DWORD dwBufSize = strlen(pszDllPath) + 1;
	LPTHREAD_START_ROUTINE pThreadProc;
	// 打开目标进程
	hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwPID);
	if (hProcess == NULL) {
		printf("Failed to open process. Error code: %d\n", GetLastError());
		return FALSE;
	}
	// 在目标进程中分配内存空间
	pRemoteBuf = VirtualAllocEx(hProcess, NULL, dwBufSize, MEM_COMMIT, PAGE_READWRITE);
	if (pRemoteBuf == NULL) {
		printf("Failed to allocate memory in the remote process. Error code: %d\n", GetLastError());
		CloseHandle(hProcess);
		return FALSE;
	}
	// 将DLL路径写入目标进程的内存空间
	if (!WriteProcessMemory(hProcess, pRemoteBuf, pszDllPath, dwBufSize, NULL)) {
		printf("Failed to write DLL path to remote process memory. Error code: %d\n", GetLastError());
		VirtualFreeEx(hProcess, pRemoteBuf, 0, MEM_RELEASE);
		CloseHandle(hProcess);
		return FALSE;
	}
	// 获取LoadLibraryA函数地址
	pThreadProc = (LPTHREAD_START_ROUTINE)GetProcAddress(GetModuleHandleA("kernel32.dll"), "LoadLibraryA");
	if (pThreadProc == NULL) {
		printf("Failed to get address of LoadLibraryA function. Error code: %d\n", GetLastError());
		VirtualFreeEx(hProcess, pRemoteBuf, 0, MEM_RELEASE);
		CloseHandle(hProcess);
		return FALSE;
	}
	// 在目标进程中创建远程线程，执行LoadLibraryA函数
	hThread = CreateRemoteThread(hProcess, NULL, 0, pThreadProc, pRemoteBuf, 0, NULL);
	if (hThread == NULL) {
		printf("Failed to create remote thread. Error code: %d\n", GetLastError());
		VirtualFreeEx(hProcess, pRemoteBuf, 0, MEM_RELEASE);
		CloseHandle(hProcess);
		return FALSE;
	}
	// 等待远程线程执行完成
	WaitForSingleObject(hThread, INFINITE);
	// 清理资源
	CloseHandle(hThread);
	VirtualFreeEx(hProcess, pRemoteBuf, 0, MEM_RELEASE);
	CloseHandle(hProcess);
	return TRUE;
}


//消息钩子注入关键函数实现
//获取线程id
DWORD getThreadID(DWORD ulTargetProcessID)
{
	//获取32位线程快照
	HANDLE Handle = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (Handle != INVALID_HANDLE_VALUE)
	{
		THREADENTRY32 te;
		//初始化结构体
		te.dwSize = sizeof(te);
		//枚举遍历线程直至找到目标线程
		if (Thread32First(Handle, &te))
		{
			do
			{
				//确保THREADENTRY32结构体的dwSize成员值足够大，以包含th32OwnerProcessID字段
				if (te.dwSize >= FIELD_OFFSET(THREADENTRY32, th32OwnerProcessID) + sizeof(te.th32OwnerProcessID))
				{
					//检查线程是否属于目标进程
					if (te.th32OwnerProcessID == ulTargetProcessID)
					{
						//获取线程句柄并返回线程ID
						HANDLE hThread = OpenThread(READ_CONTROL, FALSE, te.th32ThreadID);
						//获取句柄可以确保线程有效
						if (!hThread)
						{
							printf("Couldn't get thread handle\r\n");
						}
						else
						{
							//返回线程ID
							return te.th32ThreadID;
						}
					}
				}
				//获取下一个线程
			} while (Thread32Next(Handle, &te));
		}
	}
	CloseHandle(Handle);
	return (DWORD)0;
}


//消息钩子注入关键函数定义
//通过SetWindowsHookEx()设置消息钩子实现注入
BOOL InjectDllBySetWindowsHook(DWORD ulTargetProcessID, PCHAR ptr)
{
	HANDLE  TargetProcessHandle = NULL;
	//初始化线程句柄
	TargetProcessHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ulTargetProcessID);
	if (NULL == TargetProcessHandle)
	{
		printf("Couldn't get Target Process Handle\r\n");
		return FALSE;
	}

	//加载dll
	HMODULE DllModule = LoadLibrary((LPCWSTR)ptr);
	if (DllModule == NULL)
	{
		printf("can't find dll\r\n");
		return FALSE;
	}

	//获取dll中导出的函数 "MyMessageProcess"的地址
	HOOKPROC   Sub_1Address = NULL;
	Sub_1Address = (HOOKPROC)GetProcAddress(DllModule, "MyMessageProcess");
	if (Sub_1Address == NULL)
	{
		printf("can't found MyMessageProcess");
		return FALSE;
	}

	//获取线程id
	DWORD ThreadID = getThreadID(ulTargetProcessID);

	//设置键盘钩子监视键盘事件
	HHOOK Handle = SetWindowsHookEx(WH_KEYBOARD,
		Sub_1Address, DllModule, ThreadID);

	if (Handle == NULL)
	{
		printf("hook failed\r\n");
		return FALSE;
	}
	printf("hook success\r\n");
	getchar();

	//释放钩子
	UnhookWindowsHookEx(Handle);

	//释放dll模块
	FreeLibrary(DllModule);
}
