#pragma once
#include "afxwin.h"
#include"Common.h"

// DIA_CtrlPump 对话框

class DIA_CtrlPump : public CDialog
{
	DECLARE_DYNAMIC(DIA_CtrlPump)

public:
	DIA_CtrlPump(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DIA_CtrlPump();

// 对话框数据
	enum { IDD = IDD_CTLPUMP };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()

public:
	virtual BOOL OnInitDialog();
	void EnableWindowALLtureorFlase(int TrueorFalse);
	int DSP_com_BackCMD_b0(void);

	void vPackData(Int32 *p_pcPackData, Int32& p_wDataLength);
	void Add_Head(Int32 *p_pcPackData, Int32& p_wDataLength);
	Int32 TxBuf[700];
	Int32 RxBuf[700];
	Int32 *UINT32UPointer1, UINT32UPointer2;
//	CEdit m_Eldex_Cmd;
//	CStatic m_Cavro_ADDR;
	BYTE m_Cavro_addr;
//	BYTE m_Cavro_CMD;
	CString m_Cavro_CMD;
	CString m_Cavro_para1;
	CString m_Cavro_PARA2;
	CString m_Eldex_PARA;
	CString m_Lanper_ADDR;
	CString m_Lanper_CMD;
	CString m_Lanper_Direction;
	CString m_Lanper_NewADDR;
	CString m_Lanper_RUNSTATE;
	CString m_Lanper_SPEED;
	CString m_Lanper_SPEEDSTATE;
	unsigned short crc16(unsigned char *data, unsigned short length);
	unsigned int crc32(unsigned int *data, unsigned short length);
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedSendButton();
	CComboBox m_Pump_Select;
	afx_msg void OnCbnSelchangeComboPump();
//	CString m_Eldex_CMD;
	CComboBox m_Index_eldlx;
	CString m_Edit_Status;
	//Int32 DisPlayPumpStatus(Int32 obj,Int32 Ret,Int32 Para);
	//Int32 DisPlayPumpStatus(Int32 obj, Int32 Ret, CString Para);
	CComboBox m_Lanper_SelProcess;
	CComboBox m_Tecan_SelProcess;
	CString m_Hamilton_Addr;
	CString m_Hamilton_para1;
	CString m_Hamilton_para2;
	CComboBox m_Hamilton_SelProcess;
	int m_ELDEX_Addr;
	int m_IDEX_Num;
	int m_IDEX_Pos;
	int m_IDEX_ParaValue;
	CComboBox m_IDEXOpra_Sel;
};
