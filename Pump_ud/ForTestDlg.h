#pragma once
#include "afxwin.h"
#include "Common.h"
#include "NetCommunicate.h"
#include "NetCommunicate.h"
#include "UDP_Rerro.h"
#include "UDP_Export.h"
// ForTestDlg 对话框

class ForTestDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ForTestDlg)

public:
	ForTestDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~ForTestDlg();
	virtual BOOL OnInitDialog();
	//BOOL OnInitDialog();
// 对话框数据
	enum { IDD = IDD_FORTEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	GCODE GCodeBuffer[STDGCODE_MOD];
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButtonForeward();
	afx_msg void OnBnClickedButtonReserve();
	int DSP_com_BackCMD_b0(void);
	CComboBox m_Combox_SelMotion;
	double m_JOGSpeed;
	double m_JOGDistance;
	CComboBox m_sel_IO;
	CComboBox m_sel_RW;
	afx_msg void OnBnClickedButtonIosend();
	int m_rw_IOData;
	afx_msg void OnEnChangeEditiodata();

	Int32 TxBuf[700];
	Int32 RxBuf[700];

	void vPackData(Int32 *p_pcPackData, Int32& p_wDataLength);
	afx_msg void OnCbnSelchangeCombo3();
	CComboBox m_sel_Sensor;
	double m_SensorData;
	afx_msg void OnBnClickedButtonSensorsend();
	int m_Heat_IO;
	int m_Voltage_Data;
	CComboBox m_Sel_Control;
	afx_msg void OnBnClickedButtonCtrlsend();
	int m_valve_pos;
	int m_rep_Valve_pos;
	CComboBox m_MVP_OpeSet;
	afx_msg void OnBnClickedButtonMvpsend();
	int m_Valve_index;
	int m_Weigh_ID;
	int m_Weight;
	CComboBox m_sel_WeighType;
	afx_msg void OnBnClickedButtonWeighsend();
};
