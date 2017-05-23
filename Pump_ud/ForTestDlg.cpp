// ForTestDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Pump_ud.h"
#include "ForTestDlg.h"
#include "afxdialogex.h"
#include "Common.h"
#include "Pump_udDlg.h"

// ForTestDlg 对话框

IMPLEMENT_DYNAMIC(ForTestDlg, CDialogEx)

ForTestDlg::ForTestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(ForTestDlg::IDD, pParent)
	, m_JOGSpeed(0)
	, m_JOGDistance(0)
	, m_rw_IOData(0)
	, m_SensorData(0)
	, m_Heat_IO(0)
	, m_Voltage_Data(0)
	, m_valve_pos(0)
	, m_rep_Valve_pos(0)
	, m_Valve_index(0)
	, m_Weigh_ID(0)
	, m_Weight(0)
{

}

ForTestDlg::~ForTestDlg()
{
}

void ForTestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO_SELAIXS, m_Combox_SelMotion);
	DDX_Text(pDX, IDC_EDIT_JOGSPEED, m_JOGSpeed);
	DDX_Text(pDX, IDC_EDIT_JOGDISTANCE, m_JOGDistance);
	DDX_Control(pDX, IDC_COMBO_IOSEL, m_sel_IO);
	DDX_Control(pDX, IDC_COMBO_RWSEL, m_sel_RW);
	DDX_Text(pDX, IDC_EDITIODATA, m_rw_IOData);
	DDX_Control(pDX, IDC_COMBO3, m_sel_Sensor);
	DDX_Text(pDX, IDC_EDIT_SENSOR, m_SensorData);
	DDX_Text(pDX, IDC_EDIT_HEAT, m_Heat_IO);
	DDX_Text(pDX, IDC_EDIT_VOLTAGE, m_Voltage_Data);
	DDX_Control(pDX, IDC_COMBO_SEL_CONTORL, m_Sel_Control);
	DDX_Text(pDX, IDC_EDIT_VALVE_POS, m_valve_pos);
	DDX_Text(pDX, IDC_EDIT_REP_POS, m_rep_Valve_pos);
	DDX_Control(pDX, IDC_COMBO_VALVE_OPSET, m_MVP_OpeSet);
	DDX_Text(pDX, IDC_EDIT_VALVE_ADDR, m_Valve_index);
	DDX_Text(pDX, IDC_EDIT_WEIGH_ADDR, m_Weigh_ID);
	DDX_Text(pDX, IDC_EDIT_WEIGHT, m_Weight);
	DDX_Control(pDX, IDC_COMBO_VALVE_OPTWEIGH, m_sel_WeighType);
}


BEGIN_MESSAGE_MAP(ForTestDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON_FOREWARD, &ForTestDlg::OnBnClickedButtonForeward)
	ON_BN_CLICKED(IDC_BUTTON_RESERVE, &ForTestDlg::OnBnClickedButtonReserve)
	ON_BN_CLICKED(IDC_BUTTON_IOSEND, &ForTestDlg::OnBnClickedButtonIosend)
	//ON_EN_CHANGE(IDC_EDITIODATA, &ForTestDlg::OnEnChangeEditiodata)
	//ON_CBN_SELCHANGE(IDC_COMBO3, &ForTestDlg::OnCbnSelchangeCombo3)
	ON_BN_CLICKED(IDC_BUTTON_SENSORSEND, &ForTestDlg::OnBnClickedButtonSensorsend)
	ON_WM_TIMER()
	ON_WM_PAINT()

	ON_BN_CLICKED(IDC_BUTTON_CTRLSEND, &ForTestDlg::OnBnClickedButtonCtrlsend)
	ON_BN_CLICKED(IDC_BUTTON_MVPSEND, &ForTestDlg::OnBnClickedButtonMvpsend)
	ON_BN_CLICKED(IDC_BUTTON_WEIGHSEND, &ForTestDlg::OnBnClickedButtonWeighsend)
END_MESSAGE_MAP()

BOOL ForTestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	GetDlgItem(IDC_EDIT_JOGDISTANCE)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_EDIT_JOGSPEED)->SetWindowTextW(_T("0"));
	m_Combox_SelMotion.AddString(_T("A	轴"));
	m_Combox_SelMotion.AddString(_T("B	轴"));
	m_Combox_SelMotion.AddString(_T("C	轴"));
	m_Combox_SelMotion.AddString(_T("D	轴"));
	m_Combox_SelMotion.AddString(_T("E	轴"));
	m_Combox_SelMotion.AddString(_T("F	轴"));
	
	//m_MVP_OpeSet.AddString()
	m_MVP_OpeSet.AddString(_T("A初始化"));
	m_MVP_OpeSet.AddString(_T("B偏移阀门位置"));
	m_MVP_OpeSet.AddString(_T("C报告阀门位置"));
	m_MVP_OpeSet.AddString(_T("D使能命令"));
	m_MVP_OpeSet.AddString(_T("E报告状态"));


	m_Combox_SelMotion.SetCurSel(0);
	m_MVP_OpeSet.SetCurSel(0);
	SetTimer(0, 1, NULL);
	SetTimer(1, 1, NULL);
	return TRUE;
}
// ForTestDlg 消息处理程序

void ForTestDlg::OnBnClickedButtonForeward()
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_Combox_SelMotion.GetCurSel();
	switch (index)
	{
	case 0:
		break;
	case 1:
		break;
	}

}


void ForTestDlg::OnBnClickedButtonReserve()
{
	// TODO:  在此添加控件通知处理程序代码
	//指向const对象的指针
	//char acConst[] = "const";
	//const char *pcConst = acConst;
	//*pcConst = 'c';         /* Error，像这样修改pcConst指向内容的做法是不允许的 */
	//pcConst = "const too";  /* OK，像这样修改pcConst的值是允许的 */
	//const 指针
// 	char acConst[] = "const";
// 	char *const pcConst = acConst;
// 	*pcConst = 'v';         /* OK，像这样修改pcConst指向内容的做法是允许的， 修改后，acConst的内容变为"Const" */
// 	pcConst = "const too";  /* Error，像这样修改pcConst的值是不允许的 */
	char acConst[] = "acConst";
	const char *const pcConst = acConst;
	//*pcConst = "const";
	//pcConst = "const too";

}

void ForTestDlg::OnTimer(UINT_PTR nIDEvent)
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
	//	SetTimer(nIDEvent, 1, NULL);
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

int ForTestDlg::DSP_com_BackCMD_b0(void)
{
	//UpdateData(FALSE);
//	unsigned int temp, temp1;
//	double xvalue, yvalue, zvalue;
	CString str, str1;

//	short i;
	int data32;
	int *UInt32UPointer;
	if (RxBuf[2] == TENPERATURE)
	{
		UInt32UPointer = &RxBuf[4];
		int Int_SenserData = *UInt32UPointer++;
		m_SensorData = ((double)Int_SenserData) / 1000;
		str.Format(_T("%.3f"), m_SensorData);
		GetDlgItem(IDC_EDIT_SENSOR)->SetWindowText(str);
	}
	if (RxBuf[2] == F3351)
	{
		UInt32UPointer = &RxBuf[4];
		int Int_SenserData = *UInt32UPointer++;
		//m_SensorData = ((double)Int_SenserData) / 1000;
		str.Format(_T("%d"), Int_SenserData);
		GetDlgItem(IDC_EDIT_SENSOR)->SetWindowText(str);
	}
	if (RxBuf[2] == ULTRASONIC)
	{
		UInt32UPointer = &RxBuf[4];
		int Int_SenserData = *UInt32UPointer++;
		//m_SensorData = ((double)Int_SenserData) / 1000;
		str.Format(_T("%d"), Int_SenserData);
		GetDlgItem(IDC_EDIT_SENSOR)->SetWindowText(str);
	}
	if (RxBuf[2] == MVPvalve)
	{
		UInt32UPointer = &RxBuf[5];
		m_rep_Valve_pos = *UInt32UPointer++;
		str.Format(_T("%d"), m_rep_Valve_pos);
		GetDlgItem(IDC_EDIT_REP_POS)->SetWindowText(str);
	}
	if (RxBuf[2] == WEIGH)
	{
		UInt32UPointer = &RxBuf[4];
		m_Weight = *UInt32UPointer++;
		str.Format(_T("%d"), m_Weight);
		GetDlgItem(IDC_EDIT_WEIGHT)->SetWindowText(str);
	}
	else
	{

	}
	//UINT32UPointer1 =(unsigned int *) &RxBuf[7];
	//UINT32UPointer1 = &RxBuf[7];
	data32 = 0;
	data32 = 1;	// 5

	str.Empty();
	str.Format(_T("%.3f"), data32 / 60.0f);
	UpdateData(TRUE);
	return 1;
}

void ForTestDlg::OnBnClickedButtonIosend()
{
	// TODO:  
	UpdateData(TRUE);
//	Int32 data;
//	Int32 temp;
	Int16 length;
	length = 18;
	//Uint32  *SendUINT32UPointer1;
	Int32  *SendUINT32UPointer1;
	// TODO:  在此添加控件通知处理程序代码
	Int32  Package[700];
	memset(Package, 0x00, sizeof(Package));
	SendUINT32UPointer1 = TxBuf;
	Int32 length_CMD = 0;
	int indexIO = m_sel_IO.GetCurSel();
	int indexRW = m_sel_RW.GetCurSel();
	//*SendUINT32UPointer1++;
	if (0 == indexRW)  //read IO
	{
		switch (indexIO)
		{
		case 0:
			*SendUINT32UPointer1++ = GPIOABIT16;
			length_CMD++;
			*SendUINT32UPointer1++ = READIO;
			length_CMD++;
			break;
		case 1:
			*SendUINT32UPointer1++ = GPIOBBIT16;
			length_CMD++;
			*SendUINT32UPointer1++ = READIO;
			length_CMD++;
			break;
		case 2:
			*SendUINT32UPointer1++ = GPIOCBIT16;
			length_CMD++;
			*SendUINT32UPointer1++ = READIO;
			length_CMD++;
			break;
		case 4:
			*SendUINT32UPointer1++ = GPIODBIT16;
			length_CMD++;
			*SendUINT32UPointer1++ = READIO;
			length_CMD++;
			break;
		default:
			break;
		}
	}
	else if (1 == indexRW)  //write IO
	{
		int  IOData = m_rw_IOData;
		switch (indexIO)
		{
		case 0:
			*SendUINT32UPointer1++ = GPIOABIT16;
			length_CMD++;
			*SendUINT32UPointer1++ = WRITEIO;
			length_CMD++;
			*SendUINT32UPointer1++ = 0x0;
			length_CMD++;
			*SendUINT32UPointer1++ = IOData;
			length_CMD++;
			break;
		case 1:
			*SendUINT32UPointer1++ = GPIOBBIT16;
			length_CMD++;
			*SendUINT32UPointer1++ = WRITEIO;
			length_CMD++;
			*SendUINT32UPointer1++ = 0x0;
			length_CMD++;
			*SendUINT32UPointer1++ = IOData;
			length_CMD++;
			break;
		case 2:
			*SendUINT32UPointer1++ = GPIOCBIT16;
			length_CMD++;
			*SendUINT32UPointer1++ = WRITEIO;
			length_CMD++;
			*SendUINT32UPointer1++ = 0x0;
			length_CMD++;
			*SendUINT32UPointer1++ = IOData;
			length_CMD++;
			break;
		case 3:
			*SendUINT32UPointer1++ = GPIODBIT16;
			length_CMD++;
			*SendUINT32UPointer1++ = WRITEIO;
			length_CMD++;
			*SendUINT32UPointer1++ = 0x0;
			length_CMD++;
			*SendUINT32UPointer1++ = IOData;
			length_CMD++;
			break;

		default:
			break;

		 }
		}
		memcpy(Package, TxBuf, length_CMD * 4);
		vPackData(Package, length_CMD);
		//Add_Head(Package, length_CMD);
		//vPackData(SendUINT32UPointer1, 2);
		//*SendUINT32UPointer1 = 0xbb;
		//Uint32 se;
		Int32 send_buffer[700];
		for (int i = 0; i <= length_CMD; i++)
		{
			send_buffer[i] = htonl(Package[i]);
		}


		UDP_SendData((char*)send_buffer, (length_CMD)* 4, IP_PUMP_CONTROL);
	}

void ForTestDlg::vPackData(Int32 *p_pcPackData, Int32& p_wDataLength)
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

void ForTestDlg::OnBnClickedButtonSensorsend()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
//	Int32 data;
//	Int32 temp;
	Int16 length;
	length = 18;
	Int32  *SendUINT32UPointer1;
	// TODO:  在此添加控件通知处理程序代码
	Int32  Package[700];
	memset(Package, 0x00, sizeof(Package));
	SendUINT32UPointer1 = TxBuf;
	Int32 length_CMD = 0;
	int indexSelSensor = m_sel_Sensor.GetCurSel();
	//int indexIO = m_sel_IO.GetCurSel();
	//int indexRW = m_sel_RW.GetCurSel();
	//*SendUINT32UPointer1++;
	if (0 == indexSelSensor)  //read temper
	{
		
		*SendUINT32UPointer1++ = F3351;
			length_CMD++;
			*SendUINT32UPointer1++ = READF335;
			length_CMD++;

	}
	else if (1 == indexSelSensor)  //write 335
	{
		
			*SendUINT32UPointer1++ = TENPERATURE;
			length_CMD++;
			*SendUINT32UPointer1++ = READTE;
			length_CMD++;
		
	}
	else if (2 == indexSelSensor)
	{
		*SendUINT32UPointer1++ = ULTRASONIC;
		length_CMD++;
		*SendUINT32UPointer1++ = READUL;
		length_CMD++;
	}
	memcpy(Package, TxBuf, length_CMD * 4);
	vPackData(Package, length_CMD);

	Int32 send_buffer[700];
	for (int i = 0; i <= length_CMD; i++)
	{
		send_buffer[i] = htonl(Package[i]);
	}


	UDP_SendData((char*)send_buffer, (length_CMD)* 4, IP_PUMP_CONTROL);
	Sleep(1000);
	SetTimer(0, 1, NULL);
}

void ForTestDlg::OnBnClickedButtonCtrlsend()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
//	Int32 data;
//	Int32 temp;
	Int16 length;
	length = 18;
	Int32  *SendUINT32UPointer1;
	// TODO:  在此添加控件通知处理程序代码
	Int32  Package[700];
	memset(Package, 0x00, sizeof(Package));
	SendUINT32UPointer1 = TxBuf;
	Int32 length_CMD = 0;
	int indexControl = m_Sel_Control.GetCurSel();
	int m_heatData = m_Heat_IO;
	int m_voltage = m_Voltage_Data;
	//*SendUINT32UPointer1++;
	if (0 == indexControl)  //read temper
	{

		*SendUINT32UPointer1++ = VOLTAGE;
		length_CMD++;
		*SendUINT32UPointer1++ = GTVO;
		length_CMD++;
		*SendUINT32UPointer1++ = m_voltage*100;
		length_CMD++;

	}
	else if (1 == indexControl)  //write 335
	{

		*SendUINT32UPointer1++ = NET_HEAT;
		length_CMD++;
		*SendUINT32UPointer1++ = HEAT;
		length_CMD++;
		*SendUINT32UPointer1++ = m_heatData;
		length_CMD++;

	}
	memcpy(Package, TxBuf, length_CMD * 4);
	vPackData(Package, length_CMD);

	//Add_Head(Package, length_CMD);
	//vPackData(SendUINT32UPointer1, 2);
	//*SendUINT32UPointer1 = 0xbb;
	//Uint32 se;
	Int32 send_buffer[700];
	for (int i = 0; i <= length_CMD; i++)
	{
		send_buffer[i] = htonl(Package[i]);
	}


	UDP_SendData((char*)send_buffer, (length_CMD)* 4, IP_PUMP_CONTROL);
	Sleep(100);
	//SetTimer(0, 1, NULL);
}

void ForTestDlg::OnBnClickedButtonMvpsend()
{
	// TODO:  在此添加控件通知处理程序代码
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//Int32 data;
	//Int32 temp;
	Int16 length;
	length = 18;
	Int32  *SendUINT32UPointer1;
	// TODO:  在此添加控件通知处理程序代码
	Int32  Package[700];
	memset(Package, 0x00, sizeof(Package));
	SendUINT32UPointer1 = TxBuf;
	Int32 length_CMD = 0;
	int indexMvpOperationSet = m_MVP_OpeSet.GetCurSel();
	//int indexControl = m_Sel_Control.GetCurSel();
	int m_valvePosition = m_valve_pos;
	int m_rep_ValvePositon = m_rep_Valve_pos;
	//int m_heatData = m_Heat_IO;
	//int m_voltage = m_Voltage_Data;
	//*SendUINT32UPointer1++;
	if (0 == indexMvpOperationSet)  //read temper
	{

		*SendUINT32UPointer1++ = MVPvalve;
		length_CMD++;
		*SendUINT32UPointer1++ = MVPINIT;
		length_CMD++;
		*SendUINT32UPointer1++ = m_Valve_index;
		length_CMD++;

	}
	else if (1 == indexMvpOperationSet)  //write 335
	{

		*SendUINT32UPointer1++ = MVPvalve;
		length_CMD++;
		*SendUINT32UPointer1++ = MVPGOVA;
		length_CMD++;
		*SendUINT32UPointer1++ = m_Valve_index;
		length_CMD++;
		*SendUINT32UPointer1++ = m_valve_pos;
		length_CMD++;
		*SendUINT32UPointer1++ = 1;
		length_CMD++;

	}
	else if (2 == indexMvpOperationSet)  //write 335
	{

		*SendUINT32UPointer1++ = MVPvalve;
		length_CMD++;
		*SendUINT32UPointer1++ = MVPRPOS;
		length_CMD++;
		*SendUINT32UPointer1++ = m_Valve_index;
		length_CMD++;

	}
	else if (3 == indexMvpOperationSet)  //write 335
	{

		*SendUINT32UPointer1++ = MVPvalve;
		length_CMD++;
		*SendUINT32UPointer1++ = MVPENCM;
		length_CMD++;
		*SendUINT32UPointer1++ = m_Valve_index;
		length_CMD++;

	}
	else if (4 == indexMvpOperationSet)
	{
		*SendUINT32UPointer1++ = MVPvalve;
		length_CMD++;
		*SendUINT32UPointer1++ = MVPRPST;
		length_CMD++;
		*SendUINT32UPointer1++ = m_Valve_index;
		length_CMD++;
		*SendUINT32UPointer1++ = 1;  //1：获取状态，2，获取错误信息，3，。。。
		length_CMD++;
	}
	memcpy(Package, TxBuf, length_CMD * 4);
	vPackData(Package, length_CMD);

	//Add_Head(Package, length_CMD);
	//vPackData(SendUINT32UPointer1, 2);
	//*SendUINT32UPointer1 = 0xbb;
	//Uint32 se;
	Int32 send_buffer[700];
	for (int i = 0; i <= length_CMD; i++)
	{
		send_buffer[i] = htonl(Package[i]);
	}


	UDP_SendData((char*)send_buffer, (length_CMD)* 4, IP_PUMP_CONTROL);
	Sleep(1000);
	SetTimer(0, 1, NULL);
}

void ForTestDlg::OnBnClickedButtonWeighsend()
{
	// TODO:  在此添加控件通知处理程序代码
	UpdateData(TRUE);
	//	Int32 data;
	//	Int32 temp;
	Int16 length;
	length = 18;
	Int32  *SendUINT32UPointer1;
	// TODO:  在此添加控件通知处理程序代码
	Int32  Package[700];
	memset(Package, 0x00, sizeof(Package));
	SendUINT32UPointer1 = TxBuf;
	Int32 length_CMD = 0;
	int indexWeighType = m_sel_WeighType.GetCurSel();
	//int indexIO = m_sel_IO.GetCurSel();
	//int indexRW = m_sel_RW.GetCurSel();
	//*SendUINT32UPointer1++;
	if (0 == indexWeighType)  //read temper
	{

		*SendUINT32UPointer1++ = WEIGH;
		length_CMD++;
		*SendUINT32UPointer1++ = GETWEUGHT;
		length_CMD++;
		*SendUINT32UPointer1++ = m_Weigh_ID;
		length_CMD++;

	}
	else if (1 == indexWeighType)  //write 335
	{

		*SendUINT32UPointer1++ = WEIGH;
		length_CMD++;
		*SendUINT32UPointer1++ = GETGALWEIGH;
		length_CMD++;

	}
	memcpy(Package, TxBuf, length_CMD * 4);
	vPackData(Package, length_CMD);

	//Add_Head(Package, length_CMD);
	//vPackData(SendUINT32UPointer1, 2);
	//*SendUINT32UPointer1 = 0xbb;
	//Uint32 se;
	Int32 send_buffer[700];
	for (int i = 0; i <= length_CMD; i++)
	{
		send_buffer[i] = htonl(Package[i]);
	}


	UDP_SendData((char*)send_buffer, (length_CMD)* 4, IP_PUMP_CONTROL);
	Sleep(1000);
	SetTimer(0, 1, NULL);
}
