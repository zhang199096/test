#pragma once
#include "stdafx.h"


#include "resource.h"

// DIA_UDP 对话框

class DIA_UDP : public CDialog
{
	DECLARE_DYNAMIC(DIA_UDP)

public:
	DIA_UDP(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DIA_UDP();

// 对话框数据
	enum { IDD = IDD_UDP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	// 设置主界面的指针，用于调用显示信息到界面中
	//void SetMainDlg(CDialog* p) { m_pMain = p; }

	afx_msg void OnEnChangeEdit1();
	afx_msg void OnStnClickedIpName2();
	int m_DevIP;
	int m_DevPort;
	afx_msg void OnBnClickedConnectButton();
	//static long Recv_handler(LPVOID arg, void *pCtrl);
private:
	CDialog*                     m_pMain;                       // 主界面的界面指针,用于主界面函数调用
};
