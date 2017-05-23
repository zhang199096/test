
// Pump_udDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Pump_ud.h"
#include "Pump_udDlg.h"
#include "afxdialogex.h"
#include "NetCommunicate.h"
#include <iostream>
#include <string>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
//#define MessageBox MessageBoxExW

using namespace std;
HOMING  Homing;
OVERALLSIGN OverAllSign;

HOMING Homing_pUMP;
OVERALLSIGN OverallSign_Pump;

DIA_CtrlPump m_ctrlPump;
DIA_UDP		 m_UDP;
ForTestDlg   m_ForTest;
DIA_LightCtrl m_ctrlLight;
// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
void ini_dialog_all_hide(void)
{
	m_ctrlPump.ShowWindow(SW_HIDE);
	m_UDP.ShowWindow(SW_HIDE);
	m_ForTest.ShowWindow(SW_HIDE);
}
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPump_udDlg �Ի���



CPump_udDlg::CPump_udDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CPump_udDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPump_udDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_pumpUDP, m_tab);
}

BEGIN_MESSAGE_MAP(CPump_udDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(TCN_SELCHANGE, IDC_pumpUDP, &CPump_udDlg::OnTcnSelchangepumpudp)
END_MESSAGE_MAP()


// CPump_udDlg ��Ϣ�������

BOOL CPump_udDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	int InsertItemIndex = 0;
	m_tab.InsertItem(InsertItemIndex++, _T("Mian Control Pump"));
	m_tab.InsertItem(InsertItemIndex++, _T("UDP IP"));
	m_tab.InsertItem(InsertItemIndex++, _T("ForTest"));
	m_tab.InsertItem(InsertItemIndex++, _T("FotLightDesk"));
	m_ctrlPump.Create(IDD_CTLPUMP, &m_tab);
	m_UDP.Create(IDD_UDP, &m_tab);
	m_ForTest.Create(IDD_FORTEST, &m_tab);
	m_ctrlLight.Create(IDD_LIGHT, &m_tab);
	PumpDlg = new DIA_CtrlPump(this);
	CRect rc;
	m_tab.GetClientRect(rc);
	rc.top += 23;
	rc.bottom -= 4;
	rc.left += 4;
	rc.right -= 4;
	m_ctrlPump.MoveWindow(&rc);
	m_ctrlPump.ShowWindow(SW_SHOW);
	m_UDP.MoveWindow(&rc);
	m_UDP.ShowWindow(SW_HIDE);
	m_ForTest.MoveWindow(&rc);
	m_ForTest.ShowWindow(SW_HIDE);
	m_ctrlLight.MoveWindow(&rc);
	m_ctrlLight.ShowWindow(SW_HIDE);

	int re = UDP_SetConnetIp(IP_PUMP_CONTROL);
	int k1 = UDP_InitNet();
	if (k1 == 0)
	{
		OverAllSign.PC_DSP_COM_OK = TRUE;
		OverallSign_Pump.PC_DSP_COM_OK = TRUE;
	}
	else
	{
		MessageBox(_T("�������ӹ��ϣ�"));
	}
	SetStreamHOOK(Recv_handler,this);

	//m_UDP.SetMainDlg(this);
	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CPump_udDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CPump_udDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CPump_udDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CPump_udDlg::OnTcnSelchangepumpudp(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE);
	ini_dialog_all_hide();
	int num = m_tab.GetCurSel();
	switch (num)
	{
	case 0:
		m_ctrlPump.ShowWindow(SW_SHOW);
			break;
	case 1:
		m_UDP.ShowWindow(SW_SHOW);
		break;
	case 2:
		m_ForTest.ShowWindow(SW_SHOW);
		break;
	case 3:
		m_ctrlLight.ShowWindow(SW_SHOW);
		break;
	default:
		break;
	}
	*pResult = 0;

}

long CPump_udDlg::Recv_handler(LPVOID arg, void *pCtrl)
{
	Int32 m_buffer[256];
	Int32 memcpyLength = 0;
	UCHAR * pData = (UCHAR *)arg;
	CPump_udDlg *pDlg = (CPump_udDlg *)pCtrl;
	memcpyLength = (*(pData + 1));
	memcpy(m_buffer, pData + 3, memcpyLength);
	for (int i = 0; i < memcpyLength/4;i++)
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
				if (pDlg->Rxbuf[2] == pDlg->Rxbuf[memcpyLength/4 -4])
				{
					pDlg->DisPumpStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
				else
				{
					pDlg->DisPumpStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 4], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
				
			}
		}
		else if (pDlg->Rxbuf[2] == TECAN4)
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
		else if(pDlg->Rxbuf[2] == LANPER1)
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
				if (pDlg->Rxbuf[3] == READIO )
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
		else if (pDlg->Rxbuf[2] == F3351 || pDlg->Rxbuf[2] == TENPERATURE || pDlg->Rxbuf[2] == ULTRASONIC)
		{
			for (int i = 0; i < memcpyLength / 4;i++)
			{
				m_ForTest.RxBuf[i] = pDlg->Rxbuf[i];
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
				m_ForTest.RxBuf[i] = pDlg->Rxbuf[i];
			}
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
			}
		}
		else if (pDlg->Rxbuf[2] == E625-1)
		{
			for (int i = 0; i < memcpyLength / 4; i++)
			{
				m_ctrlLight.RxBuf[i] = pDlg->Rxbuf[i];
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
				m_ForTest.RxBuf[i] = pDlg->Rxbuf[i];
			}
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				if (pDlg->Rxbuf[3] == MVPINIT || pDlg->Rxbuf[3] == MVPENCM || pDlg->Rxbuf[3] == MVPGOVA)
				{
					pDlg->DisDeviceStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 4]);
				}
				else if (pDlg->Rxbuf[3] == MVPRPOS)
				{
					pDlg->DisDeviceStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
				}
				else
				{
					pDlg->DisDeviceStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3], pDlg->Rxbuf[memcpyLength / 4 - 4]);
				}
				//pDlg->DisDeviceStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 4]);
			}
		}
		else if (pDlg->Rxbuf[2] == WEIGH)
		{
			for (int i = 0; i < memcpyLength / 4; i++)
			{
				m_ForTest.RxBuf[i] = pDlg->Rxbuf[i];
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
				m_ctrlLight.RxBuf[i] = pDlg->Rxbuf[i];
			}
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
			}
		}
		else if (pDlg->Rxbuf[2] == IDEX1 || pDlg->Rxbuf[2] == IDEX2)
		{
			crc_data = pDlg->Rxbuf[memcpyLength / 4 - 2];
			data = pDlg->NETCRC((pDlg->Rxbuf + 1), pDlg->Rxlength + 1);
			if (data == crc_data)
			{
				//add your Code
				//pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
			}
		}

		else
		{
			pDlg->DisIOStatus(pDlg->Rxbuf[2], pDlg->Rxbuf[memcpyLength / 4 - 3]);
			return FALSE;
		}

	}
	else
	{
		for (int i = 0; i < memcpyLength / 4; i++)
		{
			cout<< pDlg->Rxbuf[i] <<'\n';
		}
	}
	return TRUE;
}

unsigned short CPump_udDlg::crc16(unsigned char *data, unsigned short length)
{
	unsigned short i;
	unsigned short crc_result = 0xffff;
	while (length--)
	{
		crc_result ^= *data++;
		for (i = 0; i < 8; i++)
		{
			if (crc_result & 0x01)
			{
				crc_result = (crc_result >> 1) ^ 0xa001;
			}
			else
			{
				crc_result = crc_result >> 1;
			}
		}
	}
	return (crc_result);
}

unsigned int CPump_udDlg::crc32(unsigned int *data, unsigned short length)
{
	unsigned short i;
	unsigned int crc_result = 0xffffffff;
	while (length--)
	{
		crc_result ^= *data++;
		for (i = 0; i < 8; i++)
		{
			if (crc_result & 0x0001)
			{
				crc_result = (crc_result >> 1) ^ 0xa0000001;
			}
			else
			{
				crc_result = crc_result >> 1;
			}
		}
	}
	return (crc_result);
}

Int32 CPump_udDlg::NETCRC(Int32 *data, Int32 length)
{
	Int32 i;
	Int32 crc_result = 0x0;
	for (i = 0; i < length;i++)
	{
		crc_result ^= *data;
		data++;
	}
	return crc_result;
}

Int32 CPump_udDlg::DisPumpStatus(Int32 obj, Int32 Status)
{
	CString strA; 
	strA.Format(_T("return Value:0x%04x"), Status);	
	if (obj == ELDEX1)
	{
		switch (Status)
		{
		case ERROR_ELDEX_SetRunState_Buile_Fail:MessageBox(_T("ERROR_ELDEX_SetRunState_Buile_Fail"));break;
		case ERROR_ELDEX_SetRunState_232_TimeOut:MessageBox(_T("ERROR_ELDEX_SetRunState_232_TimeOut"));break;
		case ERROR_ELDEX_SetFlowrate_SetValuelInvalid: MessageBox(_T("ERROR_ELDEX_SetRunState_Buile_Fail"));break;
		case ERROR_ELDEX_SetRunState_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetRunState_PumpAsk_Buile_Fail      "));   break;
		case ERROR_ELDEX_SetRunState_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetRunState_SetValuelInvalid        "));   break;
		case ERROR_ELDEX_SetRunState_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetRunState_ReturnInvalid           "));   break;
		case ERROR_ELDEX_SetStopState_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetStopState_Buile_Fail             "));   break;
		case ERROR_ELDEX_SetStopState_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetStopState_232_TimeOut            "));   break;
		case ERROR_ELDEX_SetStopState_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetStopState_PumpAsk_Buile_Fail     "));   break;
		case ERROR_ELDEX_SetStopState_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetStopState_SetValuelInvalid       "));   break;
		case ERROR_ELDEX_SetStopState_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetStopState_ReturnInvalid          "));   break;
		case ERROR_ELDEX_SetFlowrate_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetFlowrate_Buile_Fail              "));   break;
		case ERROR_ELDEX_SetFlowrate_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetFlowrate_232_TimeOut             "));   break;
		case ERROR_ELDEX_SetFlowrate_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetFlowrate_PumpAsk_Buile_Fail      "));   break;
		case ERROR_ELDEX_SetFlowrate_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetFlowrate_ReturnInvalid           "));   break;
		case ERROR_ELDEX_GetFlowrate_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetFlowrate_Buile_Fail              "));   break;
		case ERROR_ELDEX_GetFlowrate_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetFlowrate_232_TimeOut             "));   break;
		case ERROR_ELDEX_GetFlowrate_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetFlowrate_PumpAsk_Buile_Fail      "));   break;
		case ERROR_ELDEX_GetFlowrate_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetFlowrate_SetValuelInvalid        "));   break;
		case ERROR_ELDEX_GetFlowrate_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetFlowrate_ReturnInvalid           "));   break;
		case ERROR_ELDEX_GetId_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetId_Buile_Fail                    "));   break;
		case ERROR_ELDEX_GetId_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetId_232_TimeOut                   "));   break;
		case ERROR_ELDEX_GetId_232_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetId_232_PumpAsk_Buile_Fail        "));   break;
		case ERROR_ELDEX_GetId_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetId_SetValuelInvalid              "));   break;
		case ERROR_ELDEX_GetId_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetId_ReturnInvalid                 "));   break;
		case ERROR_ELDEX_GetPressure_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetPressure_Buile_Fail              "));   break;
		case ERROR_ELDEX_GetPressure_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetPressure_232_TimeOut             "));   break;
		case ERROR_ELDEX_GetPressure_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetPressure_PumpAsk_Buile_Fail      "));   break;
		case ERROR_ELDEX_GetPressure_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetPressure_SetValuelInvalid        "));   break;
		case ERROR_ELDEX_GetPressure_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetPressure_ReturnInvalid           "));   break;
		case ERROR_ELDEX_SetHeightPressureLimit_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetHeightPressureLimit_Buile_Fail   "));   break;
		case ERROR_ELDEX_SetHeightPressureLimit_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetHeightPressureLimit_232_TimeOut  "));   break;
		case ERROR_ELDEX_SetHeightPressureLimit_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetHeightPressureLimit_PumpAsk_Buile"));   break;
		case ERROR_ELDEX_SetHeightPressureLimit_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetHeightPressureLimit_SetValuelInva"));   break;
		case ERROR_ELDEX_SetHeightPressureLimit_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetHeightPressureLimit_ReturnInvalid"));   break;
		case ERROR_ELDEX_SetLowPressureLimit_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetLowPressureLimit_Buile_Fail      "));   break;
		case ERROR_ELDEX_SetLowPressureLimit_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetLowPressureLimit_232_TimeOut     "));   break;
		case ERROR_ELDEX_SetLowPressureLimit_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetLowPressureLimit_PumpAsk_Buile_Fa"));   break;
		case ERROR_ELDEX_SetLowPressureLimit_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetLowPressureLimit_SetValuelInvalid"));   break;
		case ERROR_ELDEX_SetLowPressureLimit_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetLowPressureLimit_ReturnInvalid   "));   break;
		case ERROR_ELDEX_GetHeightPressureLimit_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetHeightPressureLimit_Buile_Fail   "));   break;
		case ERROR_ELDEX_GetHeightPressureLimit_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetHeightPressureLimit_232_TimeOut  "));   break;
		case ERROR_ELDEX_GetHeightPressureLimit_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetHeightPressureLimit_PumpAsk_Buile"));   break;
		case ERROR_ELDEX_GetHeightPressureLimit_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetHeightPressureLimit_SetValuelInva"));   break;
		case ERROR_ELDEX_GetHeightPressureLimit_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetHeightPressureLimit_ReturnInvalid"));   break;
		case ERROR_ELDEX_GetLowPressureLimit_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetLowPressureLimit_Buile_Fail      "));   break;
		case ERROR_ELDEX_GetLowPressureLimit_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetLowPressureLimit_232_TimeOut     "));   break;
		case ERROR_ELDEX_GetLowPressureLimit_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetLowPressureLimit_PumpAsk_Buile_Fa"));   break;
		case ERROR_ELDEX_GetLowPressureLimit_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetLowPressureLimit_SetValuelInvalid"));   break;
		case ERROR_ELDEX_GetLowPressureLimit_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetLowPressureLimit_ReturnInvalid   "));   break;
		case ERROR_ELDEX_SetCompressComp_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetCompressComp_Buile_Fail          "));   break;
		case ERROR_ELDEX_SetCompressComp_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetCompressComp_232_TimeOut         "));   break;
		case ERROR_ELDEX_SetCompressComp_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetCompressComp_PumpAsk_Buile_Fail  "));   break;
		case ERROR_ELDEX_SetCompressComp_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetCompressComp_SetValuelInvalid    "));   break;
		case ERROR_ELDEX_SetCompressComp_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetCompressComp_ReturnInvalid       "));   break;
		case ERROR_ELDEX_GetCompressComp_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetCompressComp_Buile_Fail          "));   break;
		case ERROR_ELDEX_GetCompressComp_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetCompressComp_232_TimeOut         "));   break;
		case ERROR_ELDEX_GetCompressComp_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetCompressComp_PumpAsk_Buile_Fail  "));   break;
		case ERROR_ELDEX_GetCompressComp_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetCompressComp_SetValuelInvalid    "));   break;
		case ERROR_ELDEX_GetCompressComp_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetCompressComp_ReturnInvalid       "));   break;
		case ERROR_ELDEX_SetRefillRateFactor_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetRefillRateFactor_Buile_Fail      "));   break;
		case ERROR_ELDEX_SetRefillRateFactor_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetRefillRateFactor_232_TimeOut     "));   break;
		case ERROR_ELDEX_SetRefillRateFactor_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetRefillRateFactor_PumpAsk_Buile_Fa"));   break;
		case ERROR_ELDEX_SetRefillRateFactor_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetRefillRateFactor_SetValuelInvalid"));   break;
		case ERROR_ELDEX_SetRefillRateFactor_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetRefillRateFactor_ReturnInvalid   "));   break;
		case ERROR_ELDEX_GetRefillRateFactor_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetRefillRateFactor_Buile_Fail      "));   break;
		case ERROR_ELDEX_GetRefillRateFactor_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetRefillRateFactor_232_TimeOut     "));   break;
		case ERROR_ELDEX_GetRefillRateFactor_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetRefillRateFactor_PumpAsk_Buile_Fa"));   break;
		case ERROR_ELDEX_GetRefillRateFactor_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetRefillRateFactor_SetValuelInvalid"));   break;
		case ERROR_ELDEX_GetRefillRateFactor_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetRefillRateFactor_ReturnInvalid   "));   break;
		case ERROR_ELDEX_SetDisablesKeypad_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetDisablesKeypad_Buile_Fail        "));   break;
		case ERROR_ELDEX_SetDisablesKeypad_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetDisablesKeypad_232_TimeOut       "));   break;
		case ERROR_ELDEX_SetDisablesKeypad_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetDisablesKeypad_PumpAsk_Buile_Fail"));   break;
		case ERROR_ELDEX_SetDisablesKeypad_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetDisablesKeypad_SetValuelInvalid  "));   break;
		case ERROR_ELDEX_SetDisablesKeypad_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetDisablesKeypad_ReturnInvalid     "));   break;
		case ERROR_ELDEX_SetEnablesKeypad_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetEnablesKeypad_Buile_Fail         "));   break;
		case ERROR_ELDEX_SetEnablesKeypad_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetEnablesKeypad_232_TimeOut        "));   break;
		case ERROR_ELDEX_SetEnablesKeypad_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetEnablesKeypad_PumpAsk_Buile_Fail "));   break;
		case ERROR_ELDEX_SetEnablesKeypad_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetEnablesKeypad_SetValuelInvalid   "));   break;
		case ERROR_ELDEX_SetEnablesKeypad_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetEnablesKeypad_ReturnInvalid      "));   break;
		case ERROR_ELDEX_SetPistonDiameter_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetPistonDiameter_Buile_Fail        "));   break;
		case ERROR_ELDEX_SetPistonDiameter_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetPistonDiameter_232_TimeOut       "));   break;
		case ERROR_ELDEX_SetPistonDiameter_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetPistonDiameter_PumpAsk_Buile_Fail"));   break;
		case ERROR_ELDEX_SetPistonDiameter_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetPistonDiameter_SetValuelInvalid  "));   break;
		case ERROR_ELDEX_SetPistonDiameter_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetPistonDiameter_ReturnInvalid     "));   break;
		case ERROR_ELDEX_GetPistonDiameter_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetPistonDiameter_Buile_Fail        "));   break;
		case ERROR_ELDEX_GetPistonDiameter_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetPistonDiameter_232_TimeOut       "));   break;
		case ERROR_ELDEX_GetPistonDiameter_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetPistonDiameter_PumpAsk_Buile_Fail"));   break;
		case ERROR_ELDEX_GetPistonDiameter_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetPistonDiameter_SetValuelInvalid  "));   break;
		case ERROR_ELDEX_GetPistonDiameter_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetPistonDiameter_ReturnInvalid     "));   break;
		case ERROR_ELDEX_SetStroke_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetStroke_Buile_Fail                "));   break;
		case ERROR_ELDEX_SetStroke_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetStroke_232_TimeOut               "));   break;
		case ERROR_ELDEX_SetStroke_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetStroke_PumpAsk_Buile_Fail        "));   break;
		case ERROR_ELDEX_SetStroke_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetStroke_SetValuelInvalid          "));   break;
		case ERROR_ELDEX_SetStroke_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetStroke_ReturnInvalid             "));   break;
		case ERROR_ELDEX_GetStroke_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetStroke_Buile_Fail                "));   break;
		case ERROR_ELDEX_GetStroke_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetStroke_232_TimeOut               "));   break;
		case ERROR_ELDEX_GetStroke_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetStroke_PumpAsk_Buile_Fail        "));   break;
		case ERROR_ELDEX_GetStroke_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetStroke_SetValuelInvalid          "));   break;
		case ERROR_ELDEX_GetStroke_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetStroke_ReturnInvalid             "));   break;
		case ERROR_ELDEX_SetPumpMeterial_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetPumpMeterial_Buile_Fail          "));   break;
		case ERROR_ELDEX_SetPumpMeterial_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetPumpMeterial_232_TimeOut         "));   break;
		case ERROR_ELDEX_SetPumpMeterial_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetPumpMeterial_PumpAsk_Buile_Fail  "));   break;
		case ERROR_ELDEX_SetPumpMeterial_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetPumpMeterial_SetValuelInvalid    "));   break;
		case ERROR_ELDEX_SetPumpMeterial_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetPumpMeterial_ReturnInvalid       "));   break;
		case ERROR_ELDEX_GetPumpMeterial_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetPumpMeterial_Buile_Fail          "));   break;
		case ERROR_ELDEX_GetPumpMeterial_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetPumpMeterial_232_TimeOut         "));   break;
		case ERROR_ELDEX_GetPumpMeterial_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetPumpMeterial_PumpAsk_Buile_Fail  "));   break;
		case ERROR_ELDEX_GetPumpMeterial_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetPumpMeterial_SetValuelInvalid    "));   break;
		case ERROR_ELDEX_GetPumpMeterial_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetPumpMeterial_ReturnInvalid       "));   break;
		case ERROR_ELDEX_GetFaultStatus_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetFaultStatus_Buile_Fail           "));   break;
		case ERROR_ELDEX_GetFaultStatus_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetFaultStatus_232_TimeOut          "));   break;
		case ERROR_ELDEX_GetFaultStatus_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetFaultStatus_PumpAsk_Buile_Fail   "));   break;
		case ERROR_ELDEX_GetFaultStatus_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetFaultStatus_SetValuelInvalid     "));   break;
		case ERROR_ELDEX_GetFaultStatus_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetFaultStatus_ReturnInvalid        "));   break;
		case ERROR_ELDEX_SetLedRedStopPump_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetLedRedStopPump_Buile_Fail        "));   break;
		case ERROR_ELDEX_SetLedRedStopPump_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetLedRedStopPump_232_TimeOut       "));   break;
		case ERROR_ELDEX_SetLedRedStopPump_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetLedRedStopPump_PumpAsk_Buile_Fail"));   break;
		case ERROR_ELDEX_SetLedRedStopPump_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetLedRedStopPump_SetValuelInvalid  "));   break;
		case ERROR_ELDEX_SetLedRedStopPump_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetLedRedStopPump_ReturnInvalid     "));   break;
		case ERROR_ELDEX_GetInterfacePara_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetInterfacePara_Buile_Fail         "));   break;
		case ERROR_ELDEX_GetInterfacePara_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_GetInterfacePara_232_TimeOut        "));   break;
		case ERROR_ELDEX_GetInterfacePara_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_GetInterfacePara_PumpAsk_Buile_Fail "));   break;
		case ERROR_ELDEX_GetInterfacePara_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_GetInterfacePara_SetValuelInvalid   "));   break;
		case ERROR_ELDEX_GetInterfacePara_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_GetInterfacePara_ReturnInvalid      "));   break;
		case ERROR_ELDEX_SetRestCmdBuf_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetRestCmdBuf_Buile_Fail            "));   break;
		case ERROR_ELDEX_SetRestCmdBuf_232_TimeOut:    MessageBox(_T("ERROR_ELDEX_SetRestCmdBuf_232_TimeOut           "));   break;
		case ERROR_ELDEX_SetRestCmdBuf_PumpAsk_Buile_Fail:    MessageBox(_T("ERROR_ELDEX_SetRestCmdBuf_PumpAsk_Buile_Fail    "));   break;
		case ERROR_ELDEX_SetRestCmdBuf_SetValuelInvalid:    MessageBox(_T("ERROR_ELDEX_SetRestCmdBuf_SetValuelInvalid      "));   break;
		case ERROR_ELDEX_SetRestCmdBuf_ReturnInvalid:    MessageBox(_T("ERROR_ELDEX_SetRestCmdBuf_ReturnInvalid         "));   break;
		default:
			MessageBox(strA);
			break;
		}
	}
	else if (obj == LANPER1)
	{
		switch (Status)
		{
		case ERROR_ELDEX_SetRunState_Buile_Fail:MessageBox(_T("ERROR_ELDEX_SetRunState_Buile_Fail")); break;
		case ERROR_ELDEX_SetRunState_232_TimeOut:MessageBox(_T("ERROR_ELDEX_SetRunState_232_TimeOut")); break;
		default:
			MessageBox(strA);
			break;
		}
	}
	else if (obj == TECAN1)
	{
		switch (Status)
		{
		case ERROR_ELDEX_SetRunState_Buile_Fail:MessageBox(_T("ERROR_ELDEX_SetRunState_Buile_Fail")); break;
		case ERROR_ELDEX_SetRunState_232_TimeOut:MessageBox(_T("ERROR_ELDEX_SetRunState_232_TimeOut")); break;
		case ERROR_LANPER_SetRunPar_Buile_Fail:  MessageBox(_T("ERROR_LANPER_SetRunPar_Buile_Fail        ")); break;
		case ERROR_LANPER_SetRunPar_485_TimeOut:  MessageBox(_T("ERROR_LANPER_SetRunPar_485_TimeOut       ")); break;
		case ERROR_LANPER_SetRunPar_PumpAsk_Buile_Fail:  MessageBox(_T("ERROR_LANPER_SetRunPar_PumpAsk_Buile_Fail")); break;
		case ERROR_LANPER_SetRunPar_SetValuelInvalid:  MessageBox(_T("ERROR_LANPER_SetRunPar_SetValuelInvalid  ")); break;
		case ERROR_LANPER_SetRunPar_ReturnInvalid:  MessageBox(_T("ERROR_LANPER_SetRunPar_ReturnInvalid     ")); break;
		case ERROR_LANPER_GetRunPar_Buile_Fail:  MessageBox(_T("ERROR_LANPER_GetRunPar_Buile_Fail        ")); break;
		case ERROR_LANPER_GetRunPar_485_TimeOut:  MessageBox(_T("ERROR_LANPER_GetRunPar_485_TimeOut       ")); break;
		case ERROR_LANPER_GetRunPar_PumpAsk_Buile_Fail:  MessageBox(_T("ERROR_LANPER_GetRunPar_PumpAsk_Buile_Fail")); break;
		case ERROR_LANPER_GetRunPar_SetValuelInvalid:  MessageBox(_T("ERROR_LANPER_GetRunPar_SetValuelInvalid  ")); break;
		case ERROR_LANPER_GetRunPar_ReturnInvalid:  MessageBox(_T("ERROR_LANPER_GetRunPar_ReturnInvalid     ")); break;
		case ERROR_LANPER_RSetId_Buile_Fail:  MessageBox(_T("ERROR_LANPER_RSetId_Buile_Fail           ")); break;
		case ERROR_LANPER_RSetId_485_TimeOut:  MessageBox(_T("ERROR_LANPER_RSetId_485_TimeOut          ")); break;
		case ERROR_LANPER_RSetId_PumpAsk_Buile_Fail:  MessageBox(_T("ERROR_LANPER_RSetId_PumpAsk_Buile_Fail   ")); break;
		case ERROR_LANPER_RSetId_SetValuelInvalid:  MessageBox(_T("ERROR_LANPER_RSetId_SetValuelInvalid     ")); break;
		case ERROR_LANPER_RSetId_ReturnInvalid:  MessageBox(_T("ERROR_LANPER_RSetId_ReturnInvalid        ")); break;
		case ERROR_LANPER_GetId_Buile_Fail:  MessageBox(_T("ERROR_LANPER_GetId_Buile_Fail            ")); break;
		case ERROR_LANPER_GetId_485_TimeOut:  MessageBox(_T("ERROR_LANPER_GetId_485_TimeOut           ")); break;
		case ERROR_LANPER_GetId_PumpAsk_Buile_Fail:  MessageBox(_T("ERROR_LANPER_GetId_PumpAsk_Buile_Fail    ")); break;
		case ERROR_LANPER_GetId_SetValuelInvalid:  MessageBox(_T("ERROR_LANPER_GetId_SetValuelInvalid      ")); break;
		case ERROR_LANPER_GetId_ReturnInvalid:  MessageBox(_T("ERROR_LANPER_GetId_ReturnInvalid         ")); break;

		default:
			MessageBox(strA);
			break;
		}
	}
	else if (obj == HAMILTON)
	{
		switch (Status)
		{
		case ERROR_HAMILTON_Init_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Init_Buile_Fail                  ")); break;
		case ERROR_HAMILTON_Init_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_Init_232_TimeOut                 ")); break;
		case ERROR_HAMILTON_Init_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Init_PumpAsk_Buile_Fail          ")); break;
		case ERROR_HAMILTON_Init_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_Init_SetValuelInvalid            ")); break;
		case ERROR_HAMILTON_Init_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_Init_ReturnInvalid               ")); break;
		case ERROR_HAMILTON_RepMsg_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RepMsg_Buile_Fail                ")); break;
		case ERROR_HAMILTON_RepMsg_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_RepMsg_232_TimeOut               ")); break;
		case ERROR_HAMILTON_RepMsg_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RepMsg_PumpAsk_Buile_Fail        ")); break;
		case ERROR_HAMILTON_RepMsg_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_RepMsg_SetValuelInvalid          ")); break;
		case ERROR_HAMILTON_RepMsg_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_RepMsg_ReturnInvalid             ")); break;
		case ERROR_HAMILTON_PosAbs_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_PosAbs_Buile_Fail                ")); break;
		case ERROR_HAMILTON_PosAbs_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_PosAbs_232_TimeOut               ")); break;
		case ERROR_HAMILTON_PosAbs_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_PosAbs_PumpAsk_Buile_Fail        ")); break;
		case ERROR_HAMILTON_PosAbs_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_PosAbs_SetValuelInvalid          ")); break;
		case ERROR_HAMILTON_PosAbs_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_PosAbs_ReturnInvalid             ")); break;
		case ERROR_HAMILTON_Pickup_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Pickup_Buile_Fail                ")); break;
		case ERROR_HAMILTON_Pickup_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_Pickup_232_TimeOut               ")); break;
		case ERROR_HAMILTON_Pickup_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Pickup_PumpAsk_Buile_Fail        ")); break;
		case ERROR_HAMILTON_Pickup_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_Pickup_SetValuelInvalid          ")); break;
		case ERROR_HAMILTON_Pickup_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_Pickup_ReturnInvalid             ")); break;
		case ERROR_HAMILTON_Dispense_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Dispense_Buile_Fail              ")); break;
		case ERROR_HAMILTON_Dispense_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_Dispense_232_TimeOut             ")); break;
		case ERROR_HAMILTON_Dispense_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Dispense_PumpAsk_Buile_Fail      ")); break;
		case ERROR_HAMILTON_Dispense_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_Dispense_SetValuelInvalid        ")); break;
		case ERROR_HAMILTON_Dispense_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_Dispense_ReturnInvalid           ")); break;
		case ERROR_HAMILTON_SetMaxSpeed_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetMaxSpeed_Buile_Fail           ")); break;
		case ERROR_HAMILTON_SetMaxSpeed_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetMaxSpeed_232_TimeOut          ")); break;
		case ERROR_HAMILTON_SetMaxSpeed_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetMaxSpeed_PumpAsk_Buile_Fail   ")); break;
		case ERROR_HAMILTON_SetMaxSpeed_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetMaxSpeed_SetValuelInvalid     ")); break;
		case ERROR_HAMILTON_SetMaxSpeed_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetMaxSpeed_ReturnInvalid        ")); break;
		case ERROR_HAMILTON_SetStartSpeed_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetStartSpeed_Buile_Fail         ")); break;
		case ERROR_HAMILTON_SetStartSpeed_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetStartSpeed_232_TimeOut        ")); break;
		case ERROR_HAMILTON_SetStartSpeed_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetStartSpeed_PumpAsk_Buile_Fail ")); break;
		case ERROR_HAMILTON_SetStartSpeed_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetStartSpeed_SetValuelInvalid   ")); break;
		case ERROR_HAMILTON_SetStartSpeed_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetStartSpeed_ReturnInvalid      ")); break;
		case ERROR_HAMILTON_SetStopSpeed_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetStopSpeed_Buile_Fail          ")); break;
		case ERROR_HAMILTON_SetStopSpeed_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetStopSpeed_232_TimeOut         ")); break;
		case ERROR_HAMILTON_SetStopSpeed_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetStopSpeed_PumpAsk_Buile_Fail  ")); break;
		case ERROR_HAMILTON_SetStopSpeed_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetStopSpeed_SetValuelInvalid    ")); break;
		case ERROR_HAMILTON_SetStopSpeed_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetStopSpeed_ReturnInvalid       ")); break;
		case ERROR_HAMILTON_SetAcceler_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetAcceler_Buile_Fail            ")); break;
		case ERROR_HAMILTON_SetAcceler_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetAcceler_232_TimeOut           ")); break;
		case ERROR_HAMILTON_SetAcceler_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetAcceler_PumpAsk_Buile_Fail    ")); break;
		case ERROR_HAMILTON_SetAcceler_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetAcceler_SetValuelInvalid      ")); break;
		case ERROR_HAMILTON_SetAcceler_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetAcceler_ReturnInvalid         ")); break;
		case ERROR_HAMILTON_SetBackSteps_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetBackSteps_Buile_Fail          ")); break;
		case ERROR_HAMILTON_SetBackSteps_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetBackSteps_232_TimeOut         ")); break;
		case ERROR_HAMILTON_SetBackSteps_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetBackSteps_PumpAsk_Buile_Fail  ")); break;
		case ERROR_HAMILTON_SetBackSteps_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetBackSteps_SetValuelInvalid    ")); break;
		case ERROR_HAMILTON_SetBackSteps_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetBackSteps_ReturnInvalid       ")); break;
		case ERROR_HAMILTON_RSet_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RSet_Buile_Fail                  ")); break;
		case ERROR_HAMILTON_RSet_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_RSet_232_TimeOut                 ")); break;
		case ERROR_HAMILTON_RSet_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RSet_PumpAsk_Buile_Fail          ")); break;
		case ERROR_HAMILTON_RSet_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_RSet_SetValuelInvalid            ")); break;
		case ERROR_HAMILTON_RSet_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_RSet_ReturnInvalid               ")); break;
		case ERROR_HAMILTON_TerminalCmd_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_TerminalCmd_Buile_Fail           ")); break;
		case ERROR_HAMILTON_TerminalCmd_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_TerminalCmd_232_TimeOut          ")); break;
		case ERROR_HAMILTON_TerminalCmd_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_TerminalCmd_PumpAsk_Buile_Fail   ")); break;
		case ERROR_HAMILTON_TerminalCmd_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_TerminalCmd_SetValuelInvalid     ")); break;
		case ERROR_HAMILTON_TerminalCmd_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_TerminalCmd_ReturnInvalid        ")); break;
		case ERROR_HAMILTON_GetState_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_GetState_Buile_Fail              ")); break;
		case ERROR_HAMILTON_GetState_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_GetState_232_TimeOut             ")); break;
		case ERROR_HAMILTON_GetState_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_GetState_PumpAsk_Buile_Fail      ")); break;
		case ERROR_HAMILTON_GetState_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_GetState_SetValuelInvalid        ")); break;
		case ERROR_HAMILTON_GetState_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_GetState_ReturnInvalid           ")); break;
		case ERROR_HAMILTON_GetState_ReturnStateInvalid: MessageBox(_T(" ERROR_HAMILTON_GetState_ReturnStateInvalid      ")); break;
		case ERROR_HAMILTON_Input_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Input_Buile_Fail                 ")); break;
		case ERROR_HAMILTON_Input_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_Input_232_TimeOut                ")); break;
		case ERROR_HAMILTON_Input_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Input_PumpAsk_Buile_Fail         ")); break;
		case ERROR_HAMILTON_Input_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_Input_SetValuelInvalid           ")); break;
		case ERROR_HAMILTON_Input_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_Input_ReturnInvalid              ")); break;
		case ERROR_HAMILTON_Output_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Output_Buile_Fail                ")); break;
		case ERROR_HAMILTON_Output_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_Output_232_TimeOut               ")); break;
		case ERROR_HAMILTON_Output_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Output_PumpAsk_Buile_Fail        ")); break;
		case ERROR_HAMILTON_Output_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_Output_SetValuelInvalid          ")); break;
		case ERROR_HAMILTON_Output_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_Output_ReturnInvalid             ")); break;
		case ERROR_HAMILTON_SetCounterPos_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetCounterPos_Buile_Fail         ")); break;
		case ERROR_HAMILTON_SetCounterPos_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetCounterPos_232_TimeOut        ")); break;
		case ERROR_HAMILTON_SetCounterPos_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetCounterPos_PumpAsk_Buile_Fail ")); break;
		case ERROR_HAMILTON_SetCounterPos_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetCounterPos_SetValuelInvalid   ")); break;
		case ERROR_HAMILTON_SetCounterPos_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetCounterPos_ReturnInvalid      ")); break;
		case ERROR_HAMILTON_RepDevStat_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RepDevStat_Buile_Fail            ")); break;
		case ERROR_HAMILTON_RepDevStat_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_RepDevStat_232_TimeOut           ")); break;
		case ERROR_HAMILTON_RepDevStat_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RepDevStat_PumpAsk_Buile_Fail    ")); break;
		case ERROR_HAMILTON_RepDevStat_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_RepDevStat_SetValuelInvalid      ")); break;
		case ERROR_HAMILTON_RepDevStat_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_RepDevStat_ReturnInvalid         ")); break;
		case ERROR_HAMILTON_MulCmdPosMove_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_MulCmdPosMove_Buile_Fail         ")); break;
		case ERROR_HAMILTON_MulCmdPosMove_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_MulCmdPosMove_232_TimeOut        ")); break;
		case ERROR_HAMILTON_MulCmdPosMove_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_MulCmdPosMove_PumpAsk_Buile_Fail ")); break;
		case ERROR_HAMILTON_MulCmdPosMove_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_MulCmdPosMove_SetValuelInvalid   ")); break;
		case ERROR_HAMILTON_MulCmdPosMove_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_MulCmdPosMove_ReturnInvalid      ")); break;
		case ERROR_HAMILTON_SetSpeed_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetSpeed_Buile_Fail              ")); break;
		case ERROR_HAMILTON_SetSpeed_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetSpeed_232_TimeOut             ")); break;
		case ERROR_HAMILTON_SetSpeed_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetSpeed_PumpAsk_Buile_Fail      ")); break;
		case ERROR_HAMILTON_SetSpeed_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetSpeed_SetValuelInvalid        ")); break;
		case ERROR_HAMILTON_SetSpeed_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetSpeed_ReturnInvalid           ")); break;
		case ERROR_HAMILTON_MulAbs_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_MulAbs_Buile_Fail                ")); break;
		case ERROR_HAMILTON_MulAbs_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_MulAbs_232_TimeOut               ")); break;
		case ERROR_HAMILTON_MulAbs_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_MulAbs_PumpAsk_Buile_Fail        ")); break;
		case ERROR_HAMILTON_MulAbs_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_MulAbs_SetValuelInvalid          ")); break;
		case ERROR_HAMILTON_MulAbs_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_MulAbs_ReturnInvalid             ")); break;
		default:
			MessageBox(strA);
			break;
		}
	}
	//MessageBox(_T("obj"));
	return TRUE;
}

Int32 CPump_udDlg::DisPumpStatus(Int32 obj, Int32 Status, Int32 para)
{
	CString strA;

	//strA.Format;
	//strA.Format("%d", Status);
	strA.Format(_T("return Value:0x%04x,Para:%d"), Status,para);
	//string str;
	//str.append(strA);

	if (obj == ELDEX1)
	{
		switch (Status)
		{
		case ERROR_ELDEX_SetRunState_Buile_Fail:
			MessageBox(_T("ERROR_ELDEX_SetRunState_Buile_Fail")); break;
		case ERROR_ELDEX_SetRunState_232_TimeOut:
			MessageBox(_T("ERROR_ELDEX_SetRunState_232_TimeOut")); break;
		case ERROR_ELDEX_SetFlowrate_SetValuelInvalid:
			MessageBox(_T("ERROR_ELDEX_SetRunState_Buile_Fail")); break;
		default:
			MessageBox(strA);
			break;
		}
	}
	else if (obj == LANPER1)
	{
		switch (Status)
		{
		case ERROR_ELDEX_SetRunState_Buile_Fail:
			MessageBox(_T("ERROR_ELDEX_SetRunState_Buile_Fail")); break;
		case ERROR_ELDEX_SetRunState_232_TimeOut:
			MessageBox(_T("ERROR_ELDEX_SetRunState_232_TimeOut")); break;
		default:
			MessageBox(strA);
			break;
		}
	}
	else if (obj == TECAN4)
	{
		switch (Status)
		{
		case ERROR_ELDEX_SetRunState_Buile_Fail:
			MessageBox(_T("ERROR_ELDEX_SetRunState_Buile_Fail"));break;
		case ERROR_ELDEX_SetRunState_232_TimeOut:
			MessageBox(_T("ERROR_ELDEX_SetRunState_232_TimeOut")); break;
		default:
			MessageBox(strA);
			break;
		}
	}
	else if (obj == HAMILTON)
	{
		switch (Status)
		{
		case ERROR_HAMILTON_Init_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Init_Buile_Fail                  ")); break;
		case ERROR_HAMILTON_Init_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_Init_232_TimeOut                 ")); break;
		case ERROR_HAMILTON_Init_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Init_PumpAsk_Buile_Fail          ")); break;
		case ERROR_HAMILTON_Init_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_Init_SetValuelInvalid            ")); break;
		case ERROR_HAMILTON_Init_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_Init_ReturnInvalid               ")); break;
		case ERROR_HAMILTON_RepMsg_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RepMsg_Buile_Fail                ")); break;
		case ERROR_HAMILTON_RepMsg_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_RepMsg_232_TimeOut               ")); break;
		case ERROR_HAMILTON_RepMsg_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RepMsg_PumpAsk_Buile_Fail        ")); break;
		case ERROR_HAMILTON_RepMsg_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_RepMsg_SetValuelInvalid          ")); break;
		case ERROR_HAMILTON_RepMsg_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_RepMsg_ReturnInvalid             ")); break;
		case ERROR_HAMILTON_PosAbs_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_PosAbs_Buile_Fail                ")); break;
		case ERROR_HAMILTON_PosAbs_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_PosAbs_232_TimeOut               ")); break;
		case ERROR_HAMILTON_PosAbs_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_PosAbs_PumpAsk_Buile_Fail        ")); break;
		case ERROR_HAMILTON_PosAbs_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_PosAbs_SetValuelInvalid          ")); break;
		case ERROR_HAMILTON_PosAbs_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_PosAbs_ReturnInvalid             ")); break;
		case ERROR_HAMILTON_Pickup_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Pickup_Buile_Fail                ")); break;
		case ERROR_HAMILTON_Pickup_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_Pickup_232_TimeOut               ")); break;
		case ERROR_HAMILTON_Pickup_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Pickup_PumpAsk_Buile_Fail        ")); break;
		case ERROR_HAMILTON_Pickup_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_Pickup_SetValuelInvalid          ")); break;
		case ERROR_HAMILTON_Pickup_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_Pickup_ReturnInvalid             ")); break;
		case ERROR_HAMILTON_Dispense_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Dispense_Buile_Fail              ")); break;
		case ERROR_HAMILTON_Dispense_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_Dispense_232_TimeOut             ")); break;
		case ERROR_HAMILTON_Dispense_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Dispense_PumpAsk_Buile_Fail      ")); break;
		case ERROR_HAMILTON_Dispense_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_Dispense_SetValuelInvalid        ")); break;
		case ERROR_HAMILTON_Dispense_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_Dispense_ReturnInvalid           ")); break;
		case ERROR_HAMILTON_SetMaxSpeed_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetMaxSpeed_Buile_Fail           ")); break;
		case ERROR_HAMILTON_SetMaxSpeed_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetMaxSpeed_232_TimeOut          ")); break;
		case ERROR_HAMILTON_SetMaxSpeed_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetMaxSpeed_PumpAsk_Buile_Fail   ")); break;
		case ERROR_HAMILTON_SetMaxSpeed_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetMaxSpeed_SetValuelInvalid     ")); break;
		case ERROR_HAMILTON_SetMaxSpeed_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetMaxSpeed_ReturnInvalid        ")); break;
		case ERROR_HAMILTON_SetStartSpeed_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetStartSpeed_Buile_Fail         ")); break;
		case ERROR_HAMILTON_SetStartSpeed_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetStartSpeed_232_TimeOut        ")); break;
		case ERROR_HAMILTON_SetStartSpeed_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetStartSpeed_PumpAsk_Buile_Fail ")); break;
		case ERROR_HAMILTON_SetStartSpeed_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetStartSpeed_SetValuelInvalid   ")); break;
		case ERROR_HAMILTON_SetStartSpeed_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetStartSpeed_ReturnInvalid      ")); break;
		case ERROR_HAMILTON_SetStopSpeed_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetStopSpeed_Buile_Fail          ")); break;
		case ERROR_HAMILTON_SetStopSpeed_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetStopSpeed_232_TimeOut         ")); break;
		case ERROR_HAMILTON_SetStopSpeed_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetStopSpeed_PumpAsk_Buile_Fail  ")); break;
		case ERROR_HAMILTON_SetStopSpeed_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetStopSpeed_SetValuelInvalid    ")); break;
		case ERROR_HAMILTON_SetStopSpeed_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetStopSpeed_ReturnInvalid       ")); break;
		case ERROR_HAMILTON_SetAcceler_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetAcceler_Buile_Fail            ")); break;
		case ERROR_HAMILTON_SetAcceler_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetAcceler_232_TimeOut           ")); break;
		case ERROR_HAMILTON_SetAcceler_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetAcceler_PumpAsk_Buile_Fail    ")); break;
		case ERROR_HAMILTON_SetAcceler_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetAcceler_SetValuelInvalid      ")); break;
		case ERROR_HAMILTON_SetAcceler_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetAcceler_ReturnInvalid         ")); break;
		case ERROR_HAMILTON_SetBackSteps_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetBackSteps_Buile_Fail          ")); break;
		case ERROR_HAMILTON_SetBackSteps_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetBackSteps_232_TimeOut         ")); break;
		case ERROR_HAMILTON_SetBackSteps_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetBackSteps_PumpAsk_Buile_Fail  ")); break;
		case ERROR_HAMILTON_SetBackSteps_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetBackSteps_SetValuelInvalid    ")); break;
		case ERROR_HAMILTON_SetBackSteps_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetBackSteps_ReturnInvalid       ")); break;
		case ERROR_HAMILTON_RSet_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RSet_Buile_Fail                  ")); break;
		case ERROR_HAMILTON_RSet_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_RSet_232_TimeOut                 ")); break;
		case ERROR_HAMILTON_RSet_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RSet_PumpAsk_Buile_Fail          ")); break;
		case ERROR_HAMILTON_RSet_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_RSet_SetValuelInvalid            ")); break;
		case ERROR_HAMILTON_RSet_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_RSet_ReturnInvalid               ")); break;
		case ERROR_HAMILTON_TerminalCmd_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_TerminalCmd_Buile_Fail           ")); break;
		case ERROR_HAMILTON_TerminalCmd_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_TerminalCmd_232_TimeOut          ")); break;
		case ERROR_HAMILTON_TerminalCmd_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_TerminalCmd_PumpAsk_Buile_Fail   ")); break;
		case ERROR_HAMILTON_TerminalCmd_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_TerminalCmd_SetValuelInvalid     ")); break;
		case ERROR_HAMILTON_TerminalCmd_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_TerminalCmd_ReturnInvalid        ")); break;
		case ERROR_HAMILTON_GetState_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_GetState_Buile_Fail              ")); break;
		case ERROR_HAMILTON_GetState_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_GetState_232_TimeOut             ")); break;
		case ERROR_HAMILTON_GetState_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_GetState_PumpAsk_Buile_Fail      ")); break;
		case ERROR_HAMILTON_GetState_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_GetState_SetValuelInvalid        ")); break;
		case ERROR_HAMILTON_GetState_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_GetState_ReturnInvalid           ")); break;
		case ERROR_HAMILTON_GetState_ReturnStateInvalid: MessageBox(_T(" ERROR_HAMILTON_GetState_ReturnStateInvalid      ")); break;
		case ERROR_HAMILTON_Input_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Input_Buile_Fail                 ")); break;
		case ERROR_HAMILTON_Input_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_Input_232_TimeOut                ")); break;
		case ERROR_HAMILTON_Input_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Input_PumpAsk_Buile_Fail         ")); break;
		case ERROR_HAMILTON_Input_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_Input_SetValuelInvalid           ")); break;
		case ERROR_HAMILTON_Input_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_Input_ReturnInvalid              ")); break;
		case ERROR_HAMILTON_Output_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Output_Buile_Fail                ")); break;
		case ERROR_HAMILTON_Output_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_Output_232_TimeOut               ")); break;
		case ERROR_HAMILTON_Output_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_Output_PumpAsk_Buile_Fail        ")); break;
		case ERROR_HAMILTON_Output_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_Output_SetValuelInvalid          ")); break;
		case ERROR_HAMILTON_Output_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_Output_ReturnInvalid             ")); break;
		case ERROR_HAMILTON_SetCounterPos_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetCounterPos_Buile_Fail         ")); break;
		case ERROR_HAMILTON_SetCounterPos_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetCounterPos_232_TimeOut        ")); break;
		case ERROR_HAMILTON_SetCounterPos_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetCounterPos_PumpAsk_Buile_Fail ")); break;
		case ERROR_HAMILTON_SetCounterPos_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetCounterPos_SetValuelInvalid   ")); break;
		case ERROR_HAMILTON_SetCounterPos_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetCounterPos_ReturnInvalid      ")); break;
		case ERROR_HAMILTON_RepDevStat_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RepDevStat_Buile_Fail            ")); break;
		case ERROR_HAMILTON_RepDevStat_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_RepDevStat_232_TimeOut           ")); break;
		case ERROR_HAMILTON_RepDevStat_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_RepDevStat_PumpAsk_Buile_Fail    ")); break;
		case ERROR_HAMILTON_RepDevStat_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_RepDevStat_SetValuelInvalid      ")); break;
		case ERROR_HAMILTON_RepDevStat_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_RepDevStat_ReturnInvalid         ")); break;
		case ERROR_HAMILTON_MulCmdPosMove_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_MulCmdPosMove_Buile_Fail         ")); break;
		case ERROR_HAMILTON_MulCmdPosMove_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_MulCmdPosMove_232_TimeOut        ")); break;
		case ERROR_HAMILTON_MulCmdPosMove_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_MulCmdPosMove_PumpAsk_Buile_Fail ")); break;
		case ERROR_HAMILTON_MulCmdPosMove_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_MulCmdPosMove_SetValuelInvalid   ")); break;
		case ERROR_HAMILTON_MulCmdPosMove_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_MulCmdPosMove_ReturnInvalid      ")); break;
		case ERROR_HAMILTON_SetSpeed_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetSpeed_Buile_Fail              ")); break;
		case ERROR_HAMILTON_SetSpeed_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_SetSpeed_232_TimeOut             ")); break;
		case ERROR_HAMILTON_SetSpeed_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_SetSpeed_PumpAsk_Buile_Fail      ")); break;
		case ERROR_HAMILTON_SetSpeed_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_SetSpeed_SetValuelInvalid        ")); break;
		case ERROR_HAMILTON_SetSpeed_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_SetSpeed_ReturnInvalid           ")); break;
		case ERROR_HAMILTON_MulAbs_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_MulAbs_Buile_Fail                ")); break;
		case ERROR_HAMILTON_MulAbs_232_TimeOut: MessageBox(_T(" ERROR_HAMILTON_MulAbs_232_TimeOut               ")); break;
		case ERROR_HAMILTON_MulAbs_PumpAsk_Buile_Fail: MessageBox(_T(" ERROR_HAMILTON_MulAbs_PumpAsk_Buile_Fail        ")); break;
		case ERROR_HAMILTON_MulAbs_SetValuelInvalid: MessageBox(_T(" ERROR_HAMILTON_MulAbs_SetValuelInvalid          ")); break;
		case ERROR_HAMILTON_MulAbs_ReturnInvalid: MessageBox(_T(" ERROR_HAMILTON_MulAbs_ReturnInvalid             ")); break;
		default:
			MessageBox(strA);
			break;
		}
	}
	//MessageBox(_T("obj"));
	return TRUE;
}

Int32 CPump_udDlg::DisIOStatus(Int32 obj, Int32 Status)
{
CString strA;
strA.Format(_T("return Value:0x%04x"), Status);
switch (Status)
{
case 1:
	break;
case CRCERROTOKEN:
	MessageBox(_T("CRCErr: ")+strA);
	break;
default:
	MessageBox(strA);
	break;
}
	return TRUE;
}

Int32 CPump_udDlg::DisDeviceStatus(Int32 obj, Int32 Status)
{
		CString strA;
		strA.Format(_T("return Value:0x%04x"), Status);
		if (obj == MVPvalve)
		{
			switch (Status)
			{
			case ERROR_MVP_Init_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Init_Buile_Fail             ")); break;
			case ERROR_MVP_Init_232_TimeOut:   MessageBox(_T(" ERROR_MVP_Init_232_TimeOut            ")); break;
			case ERROR_MVP_Init_Ask_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Init_Ask_Buile_Fail         ")); break;
			case ERROR_MVP_Init_SetValuelInvalid:   MessageBox(_T(" ERROR_MVP_Init_SetValuelInvalid       ")); break;
			case ERROR_MVP_Init_ReturnInvalid:   MessageBox(_T(" ERROR_MVP_Init_ReturnInvalid          ")); break;

			case ERROR_MVP_Move_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Move_Buile_Fail             ")); break;
			case ERROR_MVP_Move_232_TimeOut:   MessageBox(_T(" ERROR_MVP_Move_232_TimeOut            ")); break;
			case ERROR_MVP_Move_Ask_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Move_Ask_Buile_Fail         ")); break;
			case ERROR_MVP_Move_SetValuelInvalid:   MessageBox(_T(" ERROR_MVP_Move_SetValuelInvalid       ")); break;
			case ERROR_MVP_Move_ReturnInvalid:   MessageBox(_T(" ERROR_MVP_Move_ReturnInvalid          ")); break;

			case ERROR_MVP_Report_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Report_Buile_Fail           ")); break;
			case ERROR_MVP_Report_232_TimeOut:   MessageBox(_T(" ERROR_MVP_Report_232_TimeOut          ")); break;
			case ERROR_MVP_Report_Ask_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Report_Ask_Buile_Fail       ")); break;
			case ERROR_MVP_Report_SetValuelInvalid:   MessageBox(_T(" ERROR_MVP_Report_SetValuelInvalid     ")); break;
			case ERROR_MVP_Report_ReturnInvalid:   MessageBox(_T(" ERROR_MVP_Report_ReturnInvalid        ")); break;

			case ERROR_MVP_EnableCmd_Buile_Fail:   MessageBox(_T(" ERROR_MVP_EnableCmd_Buile_Fail        ")); break;
			case ERROR_MVP_EnableCmd_232_TimeOut:   MessageBox(_T(" ERROR_MVP_EnableCmd_232_TimeOut       ")); break;
			case ERROR_MVP_EnableCmd_Ask_Buile_Fail:   MessageBox(_T(" ERROR_MVP_EnableCmd_Ask_Buile_Fail    ")); break;
			case ERROR_MVP_EnableCmd_SetValuelInvalid:   MessageBox(_T(" ERROR_MVP_EnableCmd_SetValuelInvalid  ")); break;
			case ERROR_MVP_EnableCmd_ReturnInvalid:   MessageBox(_T(" ERROR_MVP_EnableCmd_ReturnInvalid     ")); break;
			default:
				MessageBox(strA);
				break;
			}
		}
		else if (obj == TENPERATURE)
		{
			MessageBox(_T("obj"));
		}
		else if (obj == MDS)
		{
			switch (Status)
			{
			case ERROR_MDS_SetFreq_Buile_Fail: MessageBox(_T("ERROR_MDS_SetFreq_Buile_Fail        ")); break;//E710 MDS-����ָ�����DSP�ṩ�ڴ治�㣩
			case ERROR_MDS_SetFreq_232_TimeOut: MessageBox(_T("ERROR_MDS_SetFreq_232_TimeOut       ")); break;//E711 MDS -232���ճ�ʱ
			case ERROR_MDS_SetFreq_Ask_Buile_Fail: MessageBox(_T("ERROR_MDS_SetFreq_Ask_Buile_Fail    ")); break;//E712 MDS -���ձûظ���Ϣ�������
			case ERROR_MDS_SetFreq_SetValuelInvalid: MessageBox(_T("ERROR_MDS_SetFreq_SetValuelInvalid  ")); break;//E713 MDS -PC���õ�ֵ��Ч
			case ERROR_MDS_SetFreq_ReturnInvalid: MessageBox(_T("ERROR_MDS_SetFreq_ReturnInvalid     ")); break;//E714 MDS-����ֵ����ָ�������ڣ�DSPϵͳ����
			case ERROR_MDS_SetPow_Buile_Fail: MessageBox(_T("ERROR_MDS_SetPow_Buile_Fail         ")); break;//E715 MDS-����ָ�����DSP�ṩ�ڴ治�㣩
			case ERROR_MDS_SetPow_232_TimeOut: MessageBox(_T("ERROR_MDS_SetPow_232_TimeOut        ")); break;//E716 MDS -232���ճ�ʱ
			case ERROR_MDS_SetPow_Ask_Buile_Fail: MessageBox(_T("ERROR_MDS_SetPow_Ask_Buile_Fail     ")); break;//E717 MDS -���ձûظ���Ϣ�������
			case ERROR_MDS_SetPow_SetValuelInvalid: MessageBox(_T("ERROR_MDS_SetPow_SetValuelInvalid   ")); break;//E718 MDS -PC���õ�ֵ��Ч
			case ERROR_MDS_SetPow_ReturnInvalid: MessageBox(_T("ERROR_MDS_SetPow_ReturnInvalid      ")); break;//E719 MDS-����ֵ����ָ�������ڣ�DSPϵͳ����
			case ERROR_MDS_SetdBm_Buile_Fail: MessageBox(_T("ERROR_MDS_SetdBm_Buile_Fail         ")); break;//E710 MDS-����ָ�����DSP�ṩ�ڴ治�㣩
			case ERROR_MDS_SetdBm_232_TimeOut: MessageBox(_T("ERROR_MDS_SetdBm_232_TimeOut        ")); break;//E711 MDS -232���ճ�ʱ
			case ERROR_MDS_SetdBm_Ask_Buile_Fail: MessageBox(_T("ERROR_MDS_SetdBm_Ask_Buile_Fail     ")); break;//E712 MDS -���ձûظ���Ϣ�������
			case ERROR_MDS_SetdBm_SetValuelInvalid: MessageBox(_T("ERROR_MDS_SetdBm_SetValuelInvalid   ")); break;//E713 MDS -PC���õ�ֵ��Ч
			case ERROR_MDS_SetdBm_ReturnInvalid: MessageBox(_T("ERROR_MDS_SetdBm_ReturnInvalid      ")); break;//E714 MDS-����ֵ����ָ�������ڣ�DSPϵͳ����
			case ERROR_MDS_SetSwitch_Buile_Fail: MessageBox(_T("ERROR_MDS_SetSwitch_Buile_Fail      ")); break;//E710 MDS-����ָ�����DSP�ṩ�ڴ治�㣩
			case ERROR_MDS_SetSwitch_232_TimeOut: MessageBox(_T("ERROR_MDS_SetSwitch_232_TimeOut     ")); break;//E711 MDS -232���ճ�ʱ
			case ERROR_MDS_SetSwitch_Ask_Buile_Fail: MessageBox(_T("ERROR_MDS_SetSwitch_Ask_Buile_Fail  ")); break;//E712 MDS -���ձûظ���Ϣ�������
			case ERROR_MDS_SetSwitch_SetValuelInvalid: MessageBox(_T("ERROR_MDS_SetSwitch_SetValuelInvalid")); break;//E713 MDS -PC���õ�ֵ��Ч
			case ERROR_MDS_SetSwitch_ReturnInvalid: MessageBox(_T("ERROR_MDS_SetSwitch_ReturnInvalid   ")); break;//E714 MDS-����ֵ����ָ�������ڣ�DSPϵͳ����
			case ERROR_MDS_RepPara_Buile_Fail: MessageBox(_T("ERROR_MDS_RepPara_Buile_Fail        ")); break;//E710 MDS-����ָ�����DSP�ṩ�ڴ治�㣩
			case ERROR_MDS_RepPara_232_TimeOut: MessageBox(_T("ERROR_MDS_RepPara_232_TimeOut       ")); break;//E711 MDS -232���ճ�ʱ
			case ERROR_MDS_RepPara_Ask_Buile_Fail: MessageBox(_T("ERROR_MDS_RepPara_Ask_Buile_Fail    ")); break;//E712 MDS -���ձûظ���Ϣ�������
			case ERROR_MDS_RepPara_SetValuelInvalid: MessageBox(_T("ERROR_MDS_RepPara_SetValuelInvalid  ")); break;//E713 MDS -PC���õ�ֵ��Ч
			case ERROR_MDS_RepPara_ReturnInvalid: MessageBox(_T("ERROR_MDS_RepPara_ReturnInvalid     ")); break;//E714 MDS-����ֵ����ָ�������ڣ�DSPϵͳ����                                           
			default:
				MessageBox(strA);
				break;
			}
		}
		//
		return TRUE;
}
Int32 CPump_udDlg::DisDeviceStatus(Int32 obj, Int32 Status,Int32 err)
{
	CString strA;
	strA.Format(_T("Stat_Ready:0x%04x,errCode:0x%04x"), Status,err);
	if (obj == MVPvalve)
	{
		switch (Status)
		{
		case ERROR_MVP_Init_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Init_Buile_Fail             ")); break;
		case ERROR_MVP_Init_232_TimeOut:   MessageBox(_T(" ERROR_MVP_Init_232_TimeOut            ")); break;
		case ERROR_MVP_Init_Ask_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Init_Ask_Buile_Fail         ")); break;
		case ERROR_MVP_Init_SetValuelInvalid:   MessageBox(_T(" ERROR_MVP_Init_SetValuelInvalid       ")); break;
		case ERROR_MVP_Init_ReturnInvalid:   MessageBox(_T(" ERROR_MVP_Init_ReturnInvalid          ")); break;

		case ERROR_MVP_Move_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Move_Buile_Fail             ")); break;
		case ERROR_MVP_Move_232_TimeOut:   MessageBox(_T(" ERROR_MVP_Move_232_TimeOut            ")); break;
		case ERROR_MVP_Move_Ask_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Move_Ask_Buile_Fail         ")); break;
		case ERROR_MVP_Move_SetValuelInvalid:   MessageBox(_T(" ERROR_MVP_Move_SetValuelInvalid       ")); break;
		case ERROR_MVP_Move_ReturnInvalid:   MessageBox(_T(" ERROR_MVP_Move_ReturnInvalid          ")); break;

		case ERROR_MVP_Report_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Report_Buile_Fail           ")); break;
		case ERROR_MVP_Report_232_TimeOut:   MessageBox(_T(" ERROR_MVP_Report_232_TimeOut          ")); break;
		case ERROR_MVP_Report_Ask_Buile_Fail:   MessageBox(_T(" ERROR_MVP_Report_Ask_Buile_Fail       ")); break;
		case ERROR_MVP_Report_SetValuelInvalid:   MessageBox(_T(" ERROR_MVP_Report_SetValuelInvalid     ")); break;
		case ERROR_MVP_Report_ReturnInvalid:   MessageBox(_T(" ERROR_MVP_Report_ReturnInvalid        ")); break;

		case ERROR_MVP_EnableCmd_Buile_Fail:   MessageBox(_T(" ERROR_MVP_EnableCmd_Buile_Fail        ")); break;
		case ERROR_MVP_EnableCmd_232_TimeOut:   MessageBox(_T(" ERROR_MVP_EnableCmd_232_TimeOut       ")); break;
		case ERROR_MVP_EnableCmd_Ask_Buile_Fail:   MessageBox(_T(" ERROR_MVP_EnableCmd_Ask_Buile_Fail    ")); break;
		case ERROR_MVP_EnableCmd_SetValuelInvalid:   MessageBox(_T(" ERROR_MVP_EnableCmd_SetValuelInvalid  ")); break;
		case ERROR_MVP_EnableCmd_ReturnInvalid:   MessageBox(_T(" ERROR_MVP_EnableCmd_ReturnInvalid     ")); break;
		default:
			MessageBox(strA);
			break;
		}
	}
	else if (obj == TENPERATURE)
	{
		MessageBox(_T("obj"));
	}
	else if (obj == MDS)
	{
		switch (Status)
		{
		case ERROR_MDS_SetFreq_Buile_Fail: MessageBox(_T("ERROR_MDS_SetFreq_Buile_Fail        ")); break;//E710 MDS-����ָ�����DSP�ṩ�ڴ治�㣩
		case ERROR_MDS_SetFreq_232_TimeOut: MessageBox(_T("ERROR_MDS_SetFreq_232_TimeOut       ")); break;//E711 MDS -232���ճ�ʱ
		case ERROR_MDS_SetFreq_Ask_Buile_Fail: MessageBox(_T("ERROR_MDS_SetFreq_Ask_Buile_Fail    ")); break;//E712 MDS -���ձûظ���Ϣ�������
		case ERROR_MDS_SetFreq_SetValuelInvalid: MessageBox(_T("ERROR_MDS_SetFreq_SetValuelInvalid  ")); break;//E713 MDS -PC���õ�ֵ��Ч
		case ERROR_MDS_SetFreq_ReturnInvalid: MessageBox(_T("ERROR_MDS_SetFreq_ReturnInvalid     ")); break;//E714 MDS-����ֵ����ָ�������ڣ�DSPϵͳ����
		case ERROR_MDS_SetPow_Buile_Fail: MessageBox(_T("ERROR_MDS_SetPow_Buile_Fail         ")); break;//E715 MDS-����ָ�����DSP�ṩ�ڴ治�㣩
		case ERROR_MDS_SetPow_232_TimeOut: MessageBox(_T("ERROR_MDS_SetPow_232_TimeOut        ")); break;//E716 MDS -232���ճ�ʱ
		case ERROR_MDS_SetPow_Ask_Buile_Fail: MessageBox(_T("ERROR_MDS_SetPow_Ask_Buile_Fail     ")); break;//E717 MDS -���ձûظ���Ϣ�������
		case ERROR_MDS_SetPow_SetValuelInvalid: MessageBox(_T("ERROR_MDS_SetPow_SetValuelInvalid   ")); break;//E718 MDS -PC���õ�ֵ��Ч
		case ERROR_MDS_SetPow_ReturnInvalid: MessageBox(_T("ERROR_MDS_SetPow_ReturnInvalid      ")); break;//E719 MDS-����ֵ����ָ�������ڣ�DSPϵͳ����
		case ERROR_MDS_SetdBm_Buile_Fail: MessageBox(_T("ERROR_MDS_SetdBm_Buile_Fail         ")); break;//E710 MDS-����ָ�����DSP�ṩ�ڴ治�㣩
		case ERROR_MDS_SetdBm_232_TimeOut: MessageBox(_T("ERROR_MDS_SetdBm_232_TimeOut        ")); break;//E711 MDS -232���ճ�ʱ
		case ERROR_MDS_SetdBm_Ask_Buile_Fail: MessageBox(_T("ERROR_MDS_SetdBm_Ask_Buile_Fail     ")); break;//E712 MDS -���ձûظ���Ϣ�������
		case ERROR_MDS_SetdBm_SetValuelInvalid: MessageBox(_T("ERROR_MDS_SetdBm_SetValuelInvalid   ")); break;//E713 MDS -PC���õ�ֵ��Ч
		case ERROR_MDS_SetdBm_ReturnInvalid: MessageBox(_T("ERROR_MDS_SetdBm_ReturnInvalid      ")); break;//E714 MDS-����ֵ����ָ�������ڣ�DSPϵͳ����
		case ERROR_MDS_SetSwitch_Buile_Fail: MessageBox(_T("ERROR_MDS_SetSwitch_Buile_Fail      ")); break;//E710 MDS-����ָ�����DSP�ṩ�ڴ治�㣩
		case ERROR_MDS_SetSwitch_232_TimeOut: MessageBox(_T("ERROR_MDS_SetSwitch_232_TimeOut     ")); break;//E711 MDS -232���ճ�ʱ
		case ERROR_MDS_SetSwitch_Ask_Buile_Fail: MessageBox(_T("ERROR_MDS_SetSwitch_Ask_Buile_Fail  ")); break;//E712 MDS -���ձûظ���Ϣ�������
		case ERROR_MDS_SetSwitch_SetValuelInvalid: MessageBox(_T("ERROR_MDS_SetSwitch_SetValuelInvalid")); break;//E713 MDS -PC���õ�ֵ��Ч
		case ERROR_MDS_SetSwitch_ReturnInvalid: MessageBox(_T("ERROR_MDS_SetSwitch_ReturnInvalid   ")); break;//E714 MDS-����ֵ����ָ�������ڣ�DSPϵͳ����
		case ERROR_MDS_RepPara_Buile_Fail: MessageBox(_T("ERROR_MDS_RepPara_Buile_Fail        ")); break;//E710 MDS-����ָ�����DSP�ṩ�ڴ治�㣩
		case ERROR_MDS_RepPara_232_TimeOut: MessageBox(_T("ERROR_MDS_RepPara_232_TimeOut       ")); break;//E711 MDS -232���ճ�ʱ
		case ERROR_MDS_RepPara_Ask_Buile_Fail: MessageBox(_T("ERROR_MDS_RepPara_Ask_Buile_Fail    ")); break;//E712 MDS -���ձûظ���Ϣ�������
		case ERROR_MDS_RepPara_SetValuelInvalid: MessageBox(_T("ERROR_MDS_RepPara_SetValuelInvalid  ")); break;//E713 MDS -PC���õ�ֵ��Ч
		case ERROR_MDS_RepPara_ReturnInvalid: MessageBox(_T("ERROR_MDS_RepPara_ReturnInvalid     ")); break;//E714 MDS-����ֵ����ָ�������ڣ�DSPϵͳ����                                           
		default:
			MessageBox(strA);
			break;
		}
	}
	//
	return TRUE;
}
