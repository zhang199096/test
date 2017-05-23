// DIA_UDP.cpp : 实现文件
//

#include "stdafx.h"
#include "Pump_ud.h"
#include "DIA_UDP.h"
#include "afxdialogex.h"
#include "Pump_udDlg.h"
#include "DIA_LightCtrl.h"
#include "ForTestDlg.h"
// DIA_UDP 对话框

IMPLEMENT_DYNAMIC(DIA_UDP, CDialog)

//ForTestDlg   Dlg_ForTest;
//DIA_LightCtrl Dlg_ctrlLight;

//extern ForTestDlg   m_ForTest;
//extern DIA_LightCtrl m_ctrlLight;
DIA_UDP::DIA_UDP(CWnd* pParent /*=NULL*/)
	: CDialog(DIA_UDP::IDD, pParent)
	, m_DevIP(0)
	, m_DevPort(0)
{

}

DIA_UDP::~DIA_UDP()
{
}

void DIA_UDP::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_IP, m_DevIP);
	DDX_Text(pDX, IDC_IP2, m_DevPort);
}


BEGIN_MESSAGE_MAP(DIA_UDP, CDialog)
	ON_EN_CHANGE(IDC_IP, &DIA_UDP::OnEnChangeEdit1)
	ON_STN_CLICKED(IDC_IP_NAME2, &DIA_UDP::OnStnClickedIpName2)
	ON_BN_CLICKED(IDC_CONNECT_BUTTON, &DIA_UDP::OnBnClickedConnectButton)
END_MESSAGE_MAP()


// DIA_UDP 消息处理程序


void DIA_UDP::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialog::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void DIA_UDP::OnStnClickedIpName2()
{
	// TODO:  在此添加控件通知处理程序代码
}


void DIA_UDP::OnBnClickedConnectButton()
{
	// TODO:  在此添加控件通知处理程序代码
	//CPump_udDlg *pDlg = (CPump_udDlg *)GetParent()->GetParent();  //网上给出的方法

//	CPump_udDlg * pMain = (CPump_udDlg *)m_pMain;  //使用小猪的方法；调用主界面函数
	UpdateData(TRUE);
// 	int re = UDP_SetConnetIp(m_DevIP);
// //	int k1 = UDP_InitNet(m_DevPort);
// 	if (k1 == 0)
// 	{
// 		MessageBox(_T("网络连接成功！"));
// 		//OverAllSign.PC_DSP_COM_OK = TRUE;
// 		//OverallSign_Pump.PC_DSP_COM_OK = TRUE;
// 	}
// 	else
// 	{
// 		MessageBox(_T("网络连接故障！"));
// 	}
//	SetStreamHOOK(pMain->Recv_handler, this);
}
/*
long DIA_UDP::Recv_handler(LPVOID arg, void *pCtrl)
{
	Int32 m_buffer[256];
	Int32 memcpyLength = 0;
	UCHAR * pData = (UCHAR *)arg;
	CPump_udDlg *pDlg = (CPump_udDlg *)pCtrl;
	memcpyLength = (*(pData + 1));
	memcpy(m_buffer, pData + 3, memcpyLength);
	for (int i = 0; i < memcpyLength / 4; i++)
	{
		pDlg->Rxbuf[i] = htonl(m_buffer[i]);
	}
	unsigned int crc_data, data;
	pDlg->Rxlength = pDlg->Rxbuf[1];
	if ((pDlg->Rxbuf[0] == STARTTOKEN) && (pDlg->Rxbuf[pDlg->Rxlength + 3] == STOPTOKEN))
	{
		if (pDlg->Rxbuf[2] == ELDEX1)
		{
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				//PumpDlg.DisPlayPumpStatus
				if (pDlg->Rxbuf[2] == pDlg->Rxbuf[memcpyLength / 4 - 4])
				{
					pDlg->DisPumpStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
				else
				{
					pDlg->DisPumpStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 4], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}

			}
		}
		else if (pDlg->Rxbuf[2] == TECAN1)
		{
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				//PumpDlg.DisPlayPumpStatus
				if (pDlg->Rxbuf[2] == pDlg->Rxbuf[memcpyLength / 4 - 4])
				{
					pDlg->DisPumpStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
				else
				{
					pDlg->DisPumpStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 4], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
			}
		}
		else if (pDlg->Rxbuf[2] == LANPER1)
		{
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				//PumpDlg.DisPlayPumpStatus
				if (pDlg->Rxbuf[2] == pDlg->Rxbuf[memcpyLength / 4 - 4])
				{
					pDlg->DisPumpStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
				else
				{
					pDlg->DisPumpStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 4], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
			}
		}
		else if (pDlg->Rxbuf[2] == HAMILTON)
		{
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				//PumpDlg.DisPlayPumpStatus
				if (pDlg->Rxbuf[2] == pDlg->Rxbuf[memcpyLength / 4 - 4])
				{
					pDlg->DisPumpStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
				else
				{
					pDlg->DisPumpStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 4], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
			}
		}
		else if (pDlg->Rxbuf[2] == GPIOABIT16 || pDlg->Rxbuf[2] == GPIOBBIT16 || pDlg->Rxbuf[2] == GPIOCBIT16 || pDlg->Rxbuf[2] == GPIODBIT16)
		{
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				if (pDlg->Rxbuf[3] == READIO)
				{
					pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
				else
				{
					pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[3]);

				}
				//pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				//PumpDlg.IOstatus
				//MessageBox(_T("hhe"));
			}
		}
		else if (pDlg->Rxbuf[2] == F3351 || pDlg->Rxbuf[2] == TENPERATURE)
		{
			for (int i = 0; i < memcpyLength / 4; i++)
			{
				Dlg_ForTest.RxBuf[i] = pDlg->Rxbuf[i];
			}
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
			}
		}
		else if (pDlg->Rxbuf[2] == VOLTAGE || pDlg->Rxbuf[2] == NET_HEAT)
		{
			for (int i = 0; i < memcpyLength / 4; i++)
			{
				Dlg_ForTest.RxBuf[i] = pDlg->Rxbuf[i];
			}
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
			}
		}
		else if (pDlg->Rxbuf[2] == E625 - 1)
		{
			for (int i = 0; i < memcpyLength / 4; i++)
			{
				Dlg_ctrlLight.RxBuf[i] = pDlg->Rxbuf[i];
			}
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
			}
		}
		else if (pDlg->Rxbuf[2] == MVPvalve)
		{
			for (int i = 0; i < memcpyLength / 4; i++)
			{
				Dlg_ForTest.RxBuf[i] = pDlg->Rxbuf[i];
			}
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				pDlg->DisDeviceStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
			}
		}
		else if (pDlg->Rxbuf[2] == WEIGH)
		{
			for (int i = 0; i < memcpyLength / 4; i++)
			{
				Dlg_ForTest.RxBuf[i] = pDlg->Rxbuf[i];
			}
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				pDlg->DisDeviceStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
			}
		}
		else if (pDlg->Rxbuf[2] == MDS)
		{
			for (int i = 0; i < memcpyLength / 4; i++)
			{
				Dlg_ctrlLight.RxBuf[i] = pDlg->Rxbuf[i];
			}
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
			}
		}
		else
		{
			return FALSE;
		}

	}
	return TRUE;
}
*/