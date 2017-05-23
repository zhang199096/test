
// Pump_udDlg.h : ͷ�ļ�
//

#pragma once
#include "stdafx.h"
#include "Pump_ud.h"
#include "Pump_udDlg.h"
#include "DIA_CtrlPump.h"
#include "DIA_UDP.h"
#include "resource.h"
#include "manipulatorDlg_include.h"
#include "DIA_CtrlPump.h"
#include "ForTestDlg.h"
#include "DIA_LightCtrl.h"
extern void ini_dialog_all_hide(void);
//extern ForTestDlg   m_ForTest;
//extern DIA_LightCtrl m_ctrlLight;
// CPump_udDlg �Ի���
class CPump_udDlg : public CDialogEx
{
// ����
public:
	CPump_udDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_PUMP_UD_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CTabCtrl m_tab;
	CDialog *m_pDiolog[3];
	int Rxlength;
	Int32 Txbuf[100];
	Int32 Rxbuf[700];
	//Int32 TxBuf[700];
	//Int32 RxBuf[700];
	afx_msg void OnTcnSelchangepumpudp(NMHDR *pNMHDR, LRESULT *pResult);
	static long Recv_handler(LPVOID arg,void *pCtrl);
	unsigned short crc16(unsigned char *data, unsigned short length);
	unsigned int crc32(unsigned int *data, unsigned short length);
	Int32 NETCRC(Int32 *data, Int32 length);
	DIA_CtrlPump *PumpDlg;
	Int32 DisPumpStatus(Int32 obj,Int32 Status);
	Int32 DisPumpStatus(Int32 obj, Int32 Status, Int32 para);

	Int32 DisIOStatus(Int32 obj,Int32 Status);

	Int32 DisDeviceStatus(Int32 obj, Int32 Status);
	Int32 DisDeviceStatus(Int32 obj, Int32 Status, Int32 err);
};
