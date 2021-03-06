// AcknowledgementDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "TrafficMonitor.h"
#include "AcknowledgementDlg.h"
#include "afxdialogex.h"


// CAcknowledgementDlg 对话框

IMPLEMENT_DYNAMIC(CAcknowledgementDlg, CDialog)

CAcknowledgementDlg::CAcknowledgementDlg(CWnd* pParent /*=nullptr*/)
	: CDialog(IDD_ACKNOWLEDGEMENT_DIALOG, pParent)
{

}

CAcknowledgementDlg::~CAcknowledgementDlg()
{
}

void CAcknowledgementDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TRADITIONAL_CHINESE_TRANSLATOR_STATIC, m_traditional_chanese_translator_link);
}


BEGIN_MESSAGE_MAP(CAcknowledgementDlg, CDialog)
END_MESSAGE_MAP()


// CAcknowledgementDlg 消息处理程序


BOOL CAcknowledgementDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// TODO:  在此添加额外的初始化
	m_traditional_chanese_translator_link.SetURL(_T("http://mkvq.blogspot.com/"));

	m_Mytip.Create(this, TTS_ALWAYSTIP | TTS_NOPREFIX);
	m_Mytip.AddTool(&m_traditional_chanese_translator_link, CCommon::LoadText(IDS_CONTACT_TRANSLATOR, _T("\r\nhttp://mkvq.blogspot.com/")));
	m_Mytip.SetDelayTime(300);	//设置延迟
	m_Mytip.SetMaxTipWidth(800);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


BOOL CAcknowledgementDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 在此添加专用代码和/或调用基类
	if (pMsg->message == WM_MOUSEMOVE)
		m_Mytip.RelayEvent(pMsg);

	return CDialog::PreTranslateMessage(pMsg);
}
