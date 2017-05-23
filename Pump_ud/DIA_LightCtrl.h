#pragma once
#include "afxwin.h"
#include "afxwin.h"
#include "Common.h"
#include "NetCommunicate.h"
#include "NetCommunicate.h"
#include "UDP_Rerro.h"
#include "UDP_Export.h"

// DIA_LightCtrl 对话框

class DIA_LightCtrl : public CDialogEx
{
	DECLARE_DYNAMIC(DIA_LightCtrl)

public:
	DIA_LightCtrl(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DIA_LightCtrl();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	int DSP_com_BackCMD_b0(void);


	Int32 TxBuf[700];
	Int32 RxBuf[700];

	void vPackData(Int32 *p_pcPackData, Int32& p_wDataLength);

// 对话框数据
	enum { IDD = IDD_LIGHT };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_Sel_operation;
	double m_MovPosition;
	int m_Dev_Set;
	afx_msg void OnBnClickedButtonIosend();
	int m_channel;
	CComboBox m_MDS_SelOpr;
	double m_Freq;
	int m_Power;
	double m_dBm;
	int m_Switch;
	afx_msg void OnBnClickedButtonMds();
};
