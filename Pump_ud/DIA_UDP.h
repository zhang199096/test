#pragma once
#include "stdafx.h"


#include "resource.h"

// DIA_UDP �Ի���

class DIA_UDP : public CDialog
{
	DECLARE_DYNAMIC(DIA_UDP)

public:
	DIA_UDP(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DIA_UDP();

// �Ի�������
	enum { IDD = IDD_UDP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	// �����������ָ�룬���ڵ�����ʾ��Ϣ��������
	//void SetMainDlg(CDialog* p) { m_pMain = p; }

	afx_msg void OnEnChangeEdit1();
	afx_msg void OnStnClickedIpName2();
	int m_DevIP;
	int m_DevPort;
	afx_msg void OnBnClickedConnectButton();
	//static long Recv_handler(LPVOID arg, void *pCtrl);
private:
	CDialog*                     m_pMain;                       // ������Ľ���ָ��,���������溯������
};
