// DIA_LightCtrl.cpp : 实现文件
//

#include "stdafx.h"
#include "Pump_ud.h"
#include "DIA_LightCtrl.h"
#include "afxdialogex.h"
#include "Pump_udDlg.h"

// DIA_LightCtrl 对话框

IMPLEMENT_DYNAMIC(DIA_LightCtrl, CDialogEx)

DIA_LightCtrl::DIA_LightCtrl(CWnd* pParent /*=NULL*/)
	: CDialogEx(DIA_LightCtrl::IDD, pParent)
	, m_MovPosition(0)
	, m_Dev_Set(0)
	, m_channel(0)
	, m_Freq(0)
	, m_Power(0)
	, m_dBm(0)
	, m_Switch(0)
{

}

DIA_LightCtrl::~DIA_LightCtrl()
{
}

void DIA_LightCtrl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_OPSEL, m_Sel_operation);
	DDX_Text(pDX, IDC_EDIT_pos, m_MovPosition);
	DDX_Text(pDX, IDC_EDITIDEVSET, m_Dev_Set);
	DDX_Text(pDX, IDC_EDIT_CHANNEL, m_channel);
	DDX_Control(pDX, IDC_COMBO_OPSEL_MDS, m_MDS_SelOpr);
	DDX_Text(pDX, IDC_EDIT_Freq, m_Freq);
	DDX_Text(pDX, IDC_EDIT_POWER, m_Power);
	DDX_Text(pDX, IDC_EDIT_dBm, m_dBm);
	DDX_Text(pDX, IDC_EDIT_SWITCH, m_Switch);
}


BEGIN_MESSAGE_MAP(DIA_LightCtrl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_IOSEND, &DIA_LightCtrl::OnBnClickedButtonIosend)
	ON_WM_TIMER()
	ON_WM_PAINT()
	ON_BN_CLICKED(IDC_BUTTON_MDS, &DIA_LightCtrl::OnBnClickedButtonMds)
END_MESSAGE_MAP()


// DIA_LightCtrl 消息处理程序

BOOL DIA_LightCtrl::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	return TRUE;
}
// ForTestDlg 消息处理程序


void DIA_LightCtrl::OnBnClickedButtonIosend()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Int16 length;
	length = 18;
	Int32  *SendUINT32UPointer1;
	// TODO:  在此添加控件通知处理程序代码
	Int32  Package[700];
	memset(Package, 0x00, sizeof(Package));
	SendUINT32UPointer1 = TxBuf;
	Int32 length_CMD = 0;
	int indexIO = m_Sel_operation.GetCurSel();
	int mMovepos = (int)(m_MovPosition * 1000);	
		switch (indexIO)
		{
		case 0:
			*SendUINT32UPointer1++ = E625-1;
			length_CMD++;
			*SendUINT32UPointer1++ = E625MOVPOS;
			length_CMD++;
			*SendUINT32UPointer1++ = mMovepos;
			length_CMD++;
			break;
		case 1:
			*SendUINT32UPointer1++ = E625-1;
			length_CMD++;
			*SendUINT32UPointer1++ = E625RPOPOS;
			length_CMD++;
			*SendUINT32UPointer1++ = m_Dev_Set+9;
			length_CMD++;
			break;
		default:
			break;
		}
	memcpy(Package, TxBuf, length_CMD * 4);
	vPackData(Package, length_CMD);
	Int32 send_buffer[700];
	for (int i = 0; i <= length_CMD; i++)
	{
		send_buffer[i] = htonl(Package[i]);
	}
	UDP_SendData((char*)send_buffer, (length_CMD)* 4, IP_PUMP_CONTROL);
}

void DIA_LightCtrl::OnTimer(UINT_PTR nIDEvent)
{
	if (nIDEvent == 0)
	{
		KillTimer(nIDEvent);
		DSP_com_BackCMD_b0();
		//SetTimer(nIDEvent, 1, NULL);
	}
	else
	{
		KillTimer(nIDEvent);
		DSP_com_BackCMD_b0();
		//SetTimer(nIDEvent, 1, NULL);
	}
	// 	switch (nIDEvent)
	// 	{
	// 	case 0:
	// 		KillTimer(nIDEvent);
	// 		DSP_com_BackCMD_b0();
	// 		SetTimer(nIDEvent, 1, NULL);
	// 		break;
	// 	case 1:
	// 		KillTimer(1);
	// 		//
	// 		SetTimer(1, 1, NULL);
	// 		break;
	// 	default:
	// 		break;
	// 	}
}

int DIA_LightCtrl::DSP_com_BackCMD_b0(void)
{
	//UpdateData(FALSE);
// 	unsigned int temp, temp1;
// 	double xvalue, yvalue, zvalue;
// 	CString str, str1;
// 
// 	short i;
// 	int data32;
// 	int *UInt32UPointer;
// 	if (RxBuf[2] == TENPERATURE)
// 	{
// 		UInt32UPointer = &RxBuf[4];
// 		int Int_SenserData = *UInt32UPointer++;
// 		m_SensorData = ((double)Int_SenserData) / 1000;
// 		str.Format(_T("%.3f"), m_SensorData);
// 		GetDlgItem(IDC_EDIT_SENSOR)->SetWindowText(str);
// 	}
// 	else
// 	{
// 
// 	}
	//UINT32UPointer1 =(unsigned int *) &RxBuf[7];
	//UINT32UPointer1 = &RxBuf[7];


// 	data32 = 0;
// 	data32 = 1;	// 5
// 
// 	str.Empty();
// 	str.Format(_T("%.3f"), data32 / 60.0f);
	CString str, str1;
	//int data32;
	int *UInt32UPointer;
	if (RxBuf[2] == E625 - 1 && RxBuf[3] == E625RPOPOS)
	{
		UInt32UPointer = &RxBuf[4];
		int Int_SenserData = *UInt32UPointer++;
		m_MovPosition = ((double)Int_SenserData) / 1000;
		str.Format(_T("%.3f"), m_MovPosition);
		GetDlgItem(IDC_EDIT_SENSOR)->SetWindowText(str);
	}
	if (RxBuf[2] == MDS && RxBuf[3] == MDSREP)//获取参数
	{
		UInt32UPointer = &RxBuf[4];
		int Int_FreqData = *UInt32UPointer++;
		int Int_dBm = *UInt32UPointer++;
		int Int_Swi = *UInt32UPointer++;
		m_Freq = ((double)Int_FreqData) / 1000;
		m_dBm = ((double)Int_dBm) / 10;
		m_Switch = Int_Swi;
		str.Format(_T("%.3f"), m_Freq);
		GetDlgItem(IDC_EDIT_Freq)->SetWindowText(str);
		str.Format(_T("%.1f"), m_dBm);
		GetDlgItem(IDC_EDIT_dBm)->SetWindowText(str);
		str.Format(_T("%d"), m_Switch);
		GetDlgItem(IDC_EDIT_SWITCH)->SetWindowText(str);
	}
	UpdateData(TRUE);
	return 1;
}

void DIA_LightCtrl::vPackData(Int32 *p_pcPackData, Int32& p_wDataLength)
{
	if (NULL == p_pcPackData)
	{
		return;
	}
	Int32    l_i, l_ik;
	Int32   l_cBCC = 0;
	Int32	l_acData[1024];

	memset(l_acData, 0x00, sizeof(l_acData));

	l_acData[0] = STARTTOKEN;
	l_acData[1] = p_wDataLength;
	l_ik = 2;

	for (l_i = 0; l_i < p_wDataLength; l_i++)
	{
		l_acData[l_ik++] = p_pcPackData[l_i];
		l_cBCC = l_cBCC ^ p_pcPackData[l_i];
	}//	for (int l_i = 0; l_i < p_wDataLength; l_i++)
	l_acData[l_ik++] = l_cBCC^p_wDataLength;
	l_acData[l_ik++] = STOPTOKEN;
	memcpy(p_pcPackData, l_acData, l_ik * 4);
	p_wDataLength = l_ik;
}


void DIA_LightCtrl::OnBnClickedButtonMds()
{
	// TODO:  在此添加控件通知处理程序代码
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Int16 length;
	length = 18;
	Int32  *SendUINT32UPointer1;
	// TODO:  在此添加控件通知处理程序代码
	Int32  Package[700];
	memset(Package, 0x00, sizeof(Package));
	SendUINT32UPointer1 = TxBuf;
	Int32 length_CMD = 0;
	int indexIO = m_MDS_SelOpr.GetCurSel();
	int mFREQ = (int)(m_Freq * 1000);
	int mDBM = (int)(m_dBm * 100);

	switch (indexIO)
	{
	case 0:
		*SendUINT32UPointer1++ = MDS;
		length_CMD++;
		*SendUINT32UPointer1++ = MDSSETF;
		length_CMD++;
		*SendUINT32UPointer1++ = m_channel;
		length_CMD++;
		*SendUINT32UPointer1++ = mFREQ;
		length_CMD++;
		break;
	case 1:
		*SendUINT32UPointer1++ = MDS;
		length_CMD++;	
		*SendUINT32UPointer1++ = MDSSETD;
		length_CMD++;
		*SendUINT32UPointer1++ = m_channel;
		length_CMD++;
		*SendUINT32UPointer1++ = mDBM;
		length_CMD++;
		break;
	case 2:
		*SendUINT32UPointer1++ = MDS;
		length_CMD++;	
		*SendUINT32UPointer1++ = MDSSETP;
		length_CMD++;
		*SendUINT32UPointer1++ = m_channel;
		length_CMD++;
		*SendUINT32UPointer1++ = m_Power;
		length_CMD++;
		break;
	case 3:
		*SendUINT32UPointer1++ = MDS;
		length_CMD++;	
		*SendUINT32UPointer1++ = MDSSETS;
		length_CMD++;
		*SendUINT32UPointer1++ = m_channel;
		length_CMD++;
		*SendUINT32UPointer1++ = m_Switch;
		length_CMD++;
		break;
	case 4:
		*SendUINT32UPointer1++ = MDS;
		length_CMD++;
		*SendUINT32UPointer1++ = MDSREP;
		length_CMD++;
		*SendUINT32UPointer1++ = m_channel;
		length_CMD++;
		break;
	default:
		break;
	}
	memcpy(Package, TxBuf, length_CMD * 4);
	vPackData(Package, length_CMD);
	Int32 send_buffer[700];
	for (int i = 0; i <= length_CMD; i++)
	{
		send_buffer[i] = htonl(Package[i]);
	}
	UDP_SendData((char*)send_buffer, (length_CMD)* 4, IP_PUMP_CONTROL);
}
