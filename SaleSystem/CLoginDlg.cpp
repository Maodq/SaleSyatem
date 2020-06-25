// CLoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "SaleSystem.h"
#include "CLoginDlg.h"
#include "afxdialogex.h"
#include "InfoFile.h"


// CLoginDlg 对话框

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	//  DDX_Control(pDX, IDC_EDIT2, m_pwd);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CLoginDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CLoginDlg::OnBnClickedButton2)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginDlg 消息处理程序


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化

	m_user = TEXT("user");	//用户名
	m_pwd = TEXT("123456");//密码
	UpdateData(FALSE); //内容更新到对应的控件
	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CLoginDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE); //更新控件的数据到对应的变量

	CInfoFile file; //创建操作文件类对象，需要头文件#include "InfoFile.h" 
	CString user, pwd;

	//读取配置文件，获取用户名密码，参数为引用传递
	file.ReadLogin(user, pwd);

	if (m_user == user)//用户名相等
	{
		if (m_pwd != pwd)
		{
			MessageBox(_T("密码错误"));
			m_user.Empty(); //清空
			m_pwd.Empty();
		}
		else
		{
			MessageBox(TEXT("登录成功"));
			CDialogEx::OnOK();
		}
	}
	else
	{
		MessageBox(_T("用户名不存在"));
		m_user.Empty();
		m_pwd.Empty();
	}
}


void CLoginDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	exit(0);
}


void CLoginDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	exit(0);
	CDialogEx::OnClose();
}
