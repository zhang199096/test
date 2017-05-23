// DIA_CtrlPump.cpp : 实现文件
//

#include "stdafx.h"
#include "Pump_ud.h"
#include "DIA_CtrlPump.h"
#include "afxdialogex.h"
#include "manipulatorDlg_include.h"
#include "NetCommunicate.h"

// DIA_CtrlPump 对话框

IMPLEMENT_DYNAMIC(DIA_CtrlPump, CDialog)

DIA_CtrlPump::DIA_CtrlPump(CWnd* pParent /*=NULL*/)
	: CDialog(DIA_CtrlPump::IDD, pParent)
	, m_Cavro_addr(0)
	//, m_Cavro_CMD(0)
	, m_Cavro_CMD(_T(""))
	, m_Cavro_para1(_T(""))
	, m_Cavro_PARA2(_T(""))
	, m_Eldex_PARA(_T(""))
	, m_Lanper_ADDR(_T(""))
	, m_Lanper_CMD(_T(""))
	, m_Lanper_Direction(_T(""))
	, m_Lanper_NewADDR(_T(""))
	, m_Lanper_RUNSTATE(_T(""))
	, m_Lanper_SPEED(_T(""))
	, m_Lanper_SPEEDSTATE(_T(""))
	//, m_Eldex_CMD(_T(""))
	, m_Edit_Status(_T(""))
	, m_Hamilton_Addr(_T(""))
	, m_Hamilton_para1(_T(""))
	, m_Hamilton_para2(_T(""))
	, m_ELDEX_Addr(0)
	, m_IDEX_Num(0)
	, m_IDEX_Pos(0)
	, m_IDEX_ParaValue(0)
{

}

DIA_CtrlPump::~DIA_CtrlPump()
{
}

void DIA_CtrlPump::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//  DDX_Control(pDX, IDC_ElDEX_CMD_EDIT, m_Eldex_Cmd);
	//  DDX_Control(pDX, IDC_CAVRO_ADDR, m_Cavro_ADDR);
	DDX_Text(pDX, IDC_CAVRO_ADDR_EDIT, m_Cavro_addr);
	//  DDX_Text(pDX, IDC_CAVRO_CMD, m_Cavro_CMD);
	DDX_Text(pDX, IDC_CAVRO_CMD_EDIT, m_Cavro_CMD);
	DDX_Text(pDX, IDC_CAVRO_PARA1_EDIT, m_Cavro_para1);
	DDX_Text(pDX, IDC_CAVRO_PARA2_EDIT, m_Cavro_PARA2);
	DDX_Text(pDX, IDC_ElDEX_PARA_EDIT, m_Eldex_PARA);
	DDX_Text(pDX, IDC_LANPER_ADDR_EDIT, m_Lanper_ADDR);
	DDX_Text(pDX, IDC_LANPER_CMD_EDIT, m_Lanper_CMD);
	DDX_Text(pDX, IDC_LANPER_DIRECTION_EDIT, m_Lanper_Direction);
	DDX_Text(pDX, IDC_LANPER_NEWADDR_EDIT, m_Lanper_NewADDR);
	DDX_Text(pDX, IDC_LANPER_RUNSTATE_EDIT, m_Lanper_RUNSTATE);
	DDX_Text(pDX, IDC_LANPER_SPEED_EDIT, m_Lanper_SPEED);
	DDX_Text(pDX, IDC_LANPER_SPEEDSTATE_EDIT, m_Lanper_SPEEDSTATE);
	DDX_Control(pDX, IDC_COMBO_PUMP, m_Pump_Select);
	//  DDX_Text(pDX, IDC_ElDEX_CMD_EDIT, m_Eldex_CMD);
	DDX_Control(pDX, IDC_COMBO_INDEX, m_Index_eldlx);
	DDX_Text(pDX, IDC_EDIT_STAUS, m_Edit_Status);
	DDX_Control(pDX, IDC_COMBO_LANPER_INDEX, m_Lanper_SelProcess);
	DDX_Control(pDX, IDC_COMBO_TECAN_INDEX, m_Tecan_SelProcess);
	DDX_Text(pDX, IDC_HAMILTON_ADDR_EDIT, m_Hamilton_Addr);
	DDX_Text(pDX, IDC_HAMILTON_PARA1_EDIT, m_Hamilton_para1);
	DDX_Text(pDX, IDC_HAMILTON_PARA2_EDIT, m_Hamilton_para2);
	DDX_Control(pDX, IDC_COMBO_HAMILTON_INDEX, m_Hamilton_SelProcess);
	DDX_Text(pDX, IDC_ElDEX_CMD_EDIT, m_ELDEX_Addr);
	DDX_Text(pDX, IDC_IDEX_NUM_VALUE, m_IDEX_Num);
	DDX_Text(pDX, IDC_IDEX_POS_VALUE, m_IDEX_Pos);
	DDX_Text(pDX, IDC_IDEX_PARA_VALUE, m_IDEX_ParaValue);
	DDX_Control(pDX, IDC_COMBOIDEX, m_IDEXOpra_Sel);
}


BEGIN_MESSAGE_MAP(DIA_CtrlPump, CDialog)
	ON_BN_CLICKED(IDC_SEND_BUTTON, &DIA_CtrlPump::OnBnClickedSendButton)
	ON_CBN_SELCHANGE(IDC_COMBO_PUMP, &DIA_CtrlPump::OnCbnSelchangeComboPump)
END_MESSAGE_MAP()


// DIA_CtrlPump 消息处理程序
BOOL DIA_CtrlPump::OnInitDialog()
{
	CDialog::OnInitDialog();
	
	m_Eldex_PARA = "";
	GetDlgItem(IDC_ElDEX_CMD_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_ElDEX_PARA_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_LANPER_CMD_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_LANPER_ADDR_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_LANPER_NEWADDR_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_LANPER_SPEED_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_LANPER_SPEEDSTATE_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_LANPER_RUNSTATE_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_LANPER_DIRECTION_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_CAVRO_CMD_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_CAVRO_ADDR_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_CAVRO_PARA1_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_CAVRO_PARA2_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_HAMILTON_ADDR_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_HAMILTON_PARA1_EDIT)->SetWindowTextW(_T("0"));
	GetDlgItem(IDC_HAMILTON_PARA2_EDIT)->SetWindowTextW(_T("0"));
	SetTimer(0, 1, NULL);
	SetTimer(1, 1, NULL);
	m_Index_eldlx.AddString(_T("A	设置为运行态"));
	m_Index_eldlx.AddString(_T("B	设置为暂停态"));
	m_Index_eldlx.AddString(_T("C	设置泵流速为"));
	m_Index_eldlx.AddString(_T("D	读取流速"));
	m_Index_eldlx.AddString(_T("E	读取泵ID"));
	m_Index_eldlx.AddString(_T("F	读取泵压力"));
	m_Index_eldlx.AddString(_T("G	设置泵压力上限"));
	m_Index_eldlx.AddString(_T("H	设置泵压力下限"));
	m_Index_eldlx.AddString(_T("I	读取泵压力上限"));
	m_Index_eldlx.AddString(_T("J	读取泵压力下限"));
	m_Index_eldlx.AddString(_T("K	设置泵的压缩补偿系"));
	m_Index_eldlx.AddString(_T("L	读取泵的压缩补偿系"));
	m_Index_eldlx.AddString(_T("M	SR"));
	m_Index_eldlx.AddString(_T("N	RR"));
	m_Index_eldlx.AddString(_T("O	禁用键盘"));
	m_Index_eldlx.AddString(_T("P	使能键盘"));
	m_Index_eldlx.AddString(_T("Q	设置活塞的直径"));
	m_Index_eldlx.AddString(_T("R	读取活塞的直径"));
	m_Index_eldlx.AddString(_T("S	设置活塞冲程"));
	m_Index_eldlx.AddString(_T("T	读取活塞冲程"));
	m_Index_eldlx.AddString(_T("U	设置泵的材料"));
	m_Index_eldlx.AddString(_T("V	读取泵的材料"));
	m_Index_eldlx.AddString(_T("W	读取泵故障状态:"));
	m_Index_eldlx.AddString(_T("X	LED红灯亮并停止泵"));
	m_Index_eldlx.AddString(_T("Y	清除命令缓冲区"));

	m_Lanper_SelProcess.AddString(_T("A	设置运行参数"));
	m_Lanper_SelProcess.AddString(_T("B	读取运行参数"));
	m_Lanper_SelProcess.AddString(_T("C	复位泵地址"));
	m_Lanper_SelProcess.AddString(_T("D	读取设备地址"));

	m_Tecan_SelProcess.AddString(_T("A	初始化活塞速度"));
	m_Tecan_SelProcess.AddString(_T("B	退出一次性针头"));
	m_Tecan_SelProcess.AddString(_T("C	运行至绝对位置"));
	m_Tecan_SelProcess.AddString(_T("D	相对吸取"));
	m_Tecan_SelProcess.AddString(_T("E	相对释放"));
	m_Tecan_SelProcess.AddString(_T("F	设置最高速度"));
	m_Tecan_SelProcess.AddString(_T("G	设置启动速度"));
	m_Tecan_SelProcess.AddString(_T("H	设置断流速度"));
	m_Tecan_SelProcess.AddString(_T("I	设置坡度"));
	m_Tecan_SelProcess.AddString(_T("J 设置后冲量"));
	m_Tecan_SelProcess.AddString(_T("K 复位设备"));
	m_Tecan_SelProcess.AddString(_T("L 清除命令缓冲区"));
	m_Tecan_SelProcess.AddString(_T("M 请求设备状态"));

	m_Hamilton_SelProcess.AddString(_T("@初始化"));
	m_Hamilton_SelProcess.AddString(_T("A运行至绝对位置  "));
	//m_Hamilton_SelProcess.AddString(_T("B初始化活塞速度  "));
	m_Hamilton_SelProcess.AddString(_T("C相对释放        "));//
	m_Hamilton_SelProcess.AddString(_T("D相对吸取        "));
	m_Hamilton_SelProcess.AddString(_T("E输入阀门运动    "));
	m_Hamilton_SelProcess.AddString(_T("F输出阀门运动    "));
	m_Hamilton_SelProcess.AddString(_T("G设置最高速度    "));
	m_Hamilton_SelProcess.AddString(_T("H设置启动速度    "));
	m_Hamilton_SelProcess.AddString(_T("I设置断流速度    "));
	m_Hamilton_SelProcess.AddString(_T("J设置加速度      "));
	m_Hamilton_SelProcess.AddString(_T("K设置后冲量      "));
	m_Hamilton_SelProcess.AddString(_T("L获取设备状态    "));
	m_Hamilton_SelProcess.AddString(_T("M复位位置计数器  "));
	m_Hamilton_SelProcess.AddString(_T("N请求设备状态    "));
	m_Hamilton_SelProcess.AddString(_T("O终止命令        "));
	m_Hamilton_SelProcess.AddString(_T("P多命令模式      "));
	m_Hamilton_SelProcess.AddString(_T("Q多命令带循环模式"));
	m_Hamilton_SelProcess.AddString(_T("R设置速度        "));
	m_Hamilton_SelProcess.AddString(_T("S多命令带循环模式"));
	m_Hamilton_SelProcess.AddString(_T("T恢复终止命令    "));


	m_IDEXOpra_Sel.AddString(_T("@设置位置"));
	m_IDEXOpra_Sel.AddString(_T("A设置阀门profile  "));
	m_IDEXOpra_Sel.AddString(_T("C设置命令模式   "));//
	m_IDEXOpra_Sel.AddString(_T("D报告阀门状态       "));
	m_IDEXOpra_Sel.AddString(_T("E读取阀profile    "));
	m_IDEXOpra_Sel.AddString(_T("F读取硬件版本号    "));
	m_IDEXOpra_Sel.AddString(_T("G读取最新错误码    "));
	m_IDEXOpra_Sel.AddString(_T("H读取阀门命令    "));
	m_IDEXOpra_Sel.AddString(_T("I请求阀门状态    "));


	m_Pump_Select.SetCurSel(0);
	m_Index_eldlx.SetCurSel(0);
	m_Lanper_SelProcess.SetCurSel(0);
	m_Tecan_SelProcess.SetCurSel(0);
	m_Hamilton_SelProcess.SetCurSel(0);
	m_IDEXOpra_Sel.SetCurSel(0);
	EnableWindowALLtureorFlase(FALSE);
	/*默认选择eldex*/
	GetDlgItem(IDC_ElDEX_CMD_EDIT)->EnableWindow(TRUE);
	GetDlgItem(IDC_ElDEX_PARA_EDIT)->EnableWindow(TRUE);
	GetDlgItem(IDC_COMBO_INDEX)->EnableWindow(TRUE);
	return TRUE;
}

unsigned short DIA_CtrlPump::crc16(unsigned char *data, unsigned short length)
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

unsigned int DIA_CtrlPump::crc32(unsigned int *data, unsigned short length)
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

void DIA_CtrlPump::EnableWindowALLtureorFlase(int TrueorFalse)
{
	GetDlgItem(IDC_ElDEX_CMD_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_ElDEX_PARA_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_LANPER_CMD_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_LANPER_ADDR_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_LANPER_NEWADDR_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_LANPER_SPEED_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_LANPER_SPEEDSTATE_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_LANPER_RUNSTATE_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_LANPER_DIRECTION_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_CAVRO_CMD_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_CAVRO_ADDR_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_CAVRO_PARA1_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_CAVRO_PARA2_EDIT)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_COMBO_INDEX)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_COMBO_LANPER_INDEX)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_COMBO_TECAN_INDEX)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_HAMILTON_ADDR_EDIT)-> EnableWindow(TrueorFalse);
	GetDlgItem(IDC_HAMILTON_PARA1_EDIT)-> EnableWindow(TrueorFalse);
	GetDlgItem(IDC_HAMILTON_PARA2_EDIT)-> EnableWindow(TrueorFalse);
	GetDlgItem(IDC_COMBO_HAMILTON_INDEX)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_IDEX_NUM_VALUE)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_IDEX_PARA_VALUE)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_IDEX_POS_VALUE)->EnableWindow(TrueorFalse);
	GetDlgItem(IDC_COMBOIDEX)->EnableWindow(TrueorFalse);
}

void DIA_CtrlPump::OnBnClickedSendButton()
{
	//EnableWindowALLtureorFlase(FALSE);
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
	//*SendUINT32UPointer1++;
	int index = m_Pump_Select.GetCurSel();
	int D_Eldex_index = m_Index_eldlx.GetCurSel();
	int D_Lanper_index = m_Lanper_SelProcess.GetCurSel();
	int D_tecan_index = m_Tecan_SelProcess.GetCurSel();
	int D_Hamilton_index = m_Hamilton_SelProcess.GetCurSel();
	int D_IDEX_Index = m_IDEXOpra_Sel.GetCurSel();
	if (index == 0)
	{
		int  eldex_Para = _ttoi(m_Eldex_PARA);
		switch (D_Eldex_index)
		{
		case 0:
			*SendUINT32UPointer1++ = m_ELDEX_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = ELDEX_SET_RUN;
			length_CMD++;
			break;
		case 1:
			*SendUINT32UPointer1++ = m_ELDEX_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = ELDEX_SET_STOP;
			length_CMD++;
			break;
		case 2:
			*SendUINT32UPointer1++ = m_ELDEX_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = ELDEX_SET_SPEED;
			length_CMD++;
			*SendUINT32UPointer1++ = eldex_Para;
			length_CMD++;
			break;
		case 3:
			*SendUINT32UPointer1++ = m_ELDEX_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = ELDEX_GET_SPEED;
			length_CMD++;
			break;
		case 4:
			*SendUINT32UPointer1++ = m_ELDEX_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = ELDEX_GET_ID;
			length_CMD++;
			break;
		case 5:
			*SendUINT32UPointer1++ = m_ELDEX_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = ELDEX_GET_PRESSURE;
			length_CMD++;
			break;
		case 6:
			*SendUINT32UPointer1++ = m_ELDEX_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = ELDEX_SET_H;
			length_CMD++;
			*SendUINT32UPointer1++ = eldex_Para;
			length_CMD++;
			break;
		case 7:
			*SendUINT32UPointer1++ = m_ELDEX_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = ELDEX_SET_L;
			length_CMD++;
			*SendUINT32UPointer1++ = eldex_Para;
			length_CMD++;
			break;
		case 8:
			*SendUINT32UPointer1++ = m_ELDEX_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = ELDEX_GET_H;
			length_CMD++;
			break;
		case 9:
			*SendUINT32UPointer1++ = m_ELDEX_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = ELDEX_GET_H;
			length_CMD++;
			break;
		default:
			MessageBox(_T("请设置参数！！"));
			break;
		}
		
		//*SendUINT32UPointer1++ = eldex_cmd;
	} 
	else if (index == 1)
	{
		switch (D_Lanper_index)
		{
		case 0:
			*SendUINT32UPointer1++ = LANPER1;
			length_CMD++;
			*SendUINT32UPointer1++ = LANPER_SET_RUN_PAR;
			length_CMD++;
			break;
		case 1:
			*SendUINT32UPointer1++ = LANPER1;
			length_CMD++;
			*SendUINT32UPointer1++ = LANPER_RED_RUN_PAR;
			length_CMD++;
			break;
		case 2:
			*SendUINT32UPointer1++ = LANPER1;
			length_CMD++;
			*SendUINT32UPointer1++ = LANPER_SET_NEW_ADD;
			length_CMD++;
			break;
		case 3:
			*SendUINT32UPointer1++ = LANPER1;
			length_CMD++;
			*SendUINT32UPointer1++ = LANPER_RED_ID;
			length_CMD++;
			break;
		case 4:
			*SendUINT32UPointer1++ = LANPER1;
			length_CMD++;
			*SendUINT32UPointer1++ = LANPER_SET_ID;
			length_CMD++;
			break;
		default:
			MessageBox(_T("请设置参数！！"));
			break;
		}
	}
	else if (index == 2)
	{	//查看参数对应应该对照协议手册
		int Tecan_Addr = m_Cavro_addr;
		int Tecan_Para1 = _ttoi(m_Cavro_para1);
		int Tecan_Para2 = _ttoi(m_Cavro_PARA2);
		switch (D_tecan_index)
		{
		case 0:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_INIT;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para1;
			length_CMD++;
			break;
		case 1:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_EJECT;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			break;
		case 2:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_POS_ABS;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para2;
			length_CMD++;
			break;
		case 3:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_ASPIRATE;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para2;
			length_CMD++;
			break;
		case 4:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_DISTRIBUTE;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para2;
			length_CMD++;
			break;
		case 5:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_MAX_SPEED;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para2;
			length_CMD++;
			break;
		case 6:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_START_SPEED;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para2;
			length_CMD++;
			break;
		case 7:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_STOP_SPEED;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para2;
			length_CMD++;
			break;
		case 8:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_SLOPE;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para2;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para2;
			length_CMD++;
			break;
		case 9:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_BACK_IMPULSE;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Para2;
			length_CMD++;
			break;
		case 10:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_REST_DEV;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			break;
		case 11:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_CLEAN_CMD;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			break;
		case 12:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = TECAN_GET_STATE;
			length_CMD++;
			*SendUINT32UPointer1++ = Tecan_Addr;
			length_CMD++;
			break;
		default:
			MessageBox(_T("请设置参数！！"));
			break;
		}
	}
	else if (index == 3)
	{
		int Hamilton_Addr = _ttoi(m_Hamilton_Addr);
		int Hamilton_Para1 = _ttoi(m_Hamilton_para1);
		int Hamilton_Para2 = _ttoi(m_Hamilton_para2);
		switch (D_Hamilton_index)
		{
		case 0:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_INIT;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para2;
			length_CMD++;
			break;
		case 1:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_POS_ABS;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para2;
			length_CMD++;
			break;
		case 2:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_DISPENSE;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para2;
			length_CMD++;
			break;
		case 3:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_PICKUP;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para2;
			length_CMD++;
			break;
		case 4:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_INPUT;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			break;
		case 5:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_OUTPUT;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			break;
		case 6:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_MAX_SPEED;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			break;
		case 7:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_START_SPEED;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			break;
		case 8:
			*SendUINT32UPointer1++ = TECAN4;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_STOP_SPEED;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			break;
		case 9:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_ACCELER;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			break;
		case 10:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_RET_STEPS;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para2;
			length_CMD++;
			break;
		case 11:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_GET_STATUS;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			break;
		case 12:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_SET_CNTPOS;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			break;
		case 13:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_REP_DEVSTA;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Para1;
			length_CMD++;
			break;
		case 14:
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_TERMINAL;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			break;
		case 15://多命令模式
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_MUL_CMDPOS;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = 2;
			length_CMD++;
			*SendUINT32UPointer1++ = 1000;
			length_CMD++;
			*SendUINT32UPointer1++ = 7;
			length_CMD++;
			*SendUINT32UPointer1++ = 1000;
			length_CMD++;
			break;
		case 16://多命令模式
			*SendUINT32UPointer1++ = HAMILTON;
			length_CMD++;
			*SendUINT32UPointer1++ = HAMILTON_MUL_CMDLOOP;
			length_CMD++;
			*SendUINT32UPointer1++ = Hamilton_Addr;
			length_CMD++;
			*SendUINT32UPointer1++ = 2; //input
			length_CMD++;
			*SendUINT32UPointer1++ = 1000;
			length_CMD++;
			*SendUINT32UPointer1++ = 7; //output
			length_CMD++;
			*SendUINT32UPointer1++ = 1000;
			length_CMD++;
			*SendUINT32UPointer1++ = 8; //loops
			length_CMD++;
			break;
		default:
			MessageBox(_T("请设置参数！！"));
			break;
		}
	}
	else if(index == 4)
	{
		int TempIDEXNUM;
		if (m_IDEX_Num == 1)
		{
			TempIDEXNUM = IDEX1;
		}
		else if (m_IDEX_Num == 2)
		{
			TempIDEXNUM = IDEX2;
		}
		else
		{
			return ;
		}
// 		int IDEX_Addr = _ttoi(m_IDEX_Num);
// 		int IDEX_POS = _ttoi(m_IDEX_Num);
// 		int IDEX_PARA_VALUE = _ttoi(m_IDEX_Num);
		switch (D_IDEX_Index)
		{
		case 0: //commands the valve to a new position
			*SendUINT32UPointer1++ = TempIDEXNUM;
			length_CMD++;
			*SendUINT32UPointer1++ = IDEX_RUN_POSITION;
			length_CMD++;
			*SendUINT32UPointer1++ = m_IDEX_Pos;
			length_CMD++;
			break;
		case 1: //sets valve profile
			*SendUINT32UPointer1++ = TempIDEXNUM;
			length_CMD++;
			*SendUINT32UPointer1++ = IDEX_SET_PROFILE;
			length_CMD++;
			*SendUINT32UPointer1++ = m_IDEX_ParaValue;
			length_CMD++;
			break;
		case 2://sets valve command mode
			*SendUINT32UPointer1++ = TempIDEXNUM;
			length_CMD++;
			*SendUINT32UPointer1++ = IDEX_SET_NEWID;
			length_CMD++;
			*SendUINT32UPointer1++ = m_IDEX_ParaValue;
			length_CMD++;
			break;
		case 3://commands the valve to the home position
			*SendUINT32UPointer1++ = TempIDEXNUM;
			length_CMD++;
			*SendUINT32UPointer1++ = IDEX_RUN_HOME;
			length_CMD++;
			break;
		case 4://requests valve status
			*SendUINT32UPointer1++ = TempIDEXNUM;
			length_CMD++;
			*SendUINT32UPointer1++ = IDEX_READ_POSITION;
			length_CMD++;
			break;
		case 5://reads valve profile
			*SendUINT32UPointer1++ = TempIDEXNUM;
			length_CMD++;
			*SendUINT32UPointer1++ = IDEX_READ_PROFILE;
			length_CMD++;
			break;
		case 6://reads firmware revision
			*SendUINT32UPointer1++ = TempIDEXNUM;
			length_CMD++;
			*SendUINT32UPointer1++ = IDEX_READ_FIRMWARE;
			length_CMD++;
			break;
		case 7://reads the latest valve error code
			*SendUINT32UPointer1++ = TempIDEXNUM;
			length_CMD++;
			*SendUINT32UPointer1++ = IDEX_READ_LASTERRO;
			length_CMD++;
			break;
		case 8://reads the valve command mode
			*SendUINT32UPointer1++ = TempIDEXNUM;
			length_CMD++;
			*SendUINT32UPointer1++ = IDEX_READ_CMDMODE;
			length_CMD++;
			break;
		default:
			break;
		}
	}
	//this->vPackData(TxBuf, length_CMD);
	memcpy(Package, TxBuf, length_CMD*4);
	vPackData(Package, length_CMD);

	//Add_Head(Package, length_CMD);
	//vPackData(SendUINT32UPointer1, 2);
	//*SendUINT32UPointer1 = 0xbb;
	//Uint32 se;
	Int32 send_buffer[700];
	for (int i = 0; i <= length_CMD ; i++)
	{
		send_buffer[i] = htonl(Package[i]);
	}


	UDP_SendData((char*)send_buffer, (length_CMD) * 4, IP_PUMP_CONTROL);
	//EnableWindowALLtureorFlase(TRUE);
}

int DIA_CtrlPump::DSP_com_BackCMD_b0(void)
{
//	unsigned int temp, temp1;
//	double xvalue, yvalue, zvalue;
	CString str, str1;

//	short i;
	int data32;

	//UINT32UPointer1 =(unsigned int *) &RxBuf[7];
	UINT32UPointer1 = &RxBuf[7];


	data32 = 0;
	data32 = *UINT32UPointer1++;	// 5

	str.Empty();
	str.Format(_T("%.3f"), data32 / 60.0f);
	return 1;
}

void DIA_CtrlPump::OnTimer(UINT_PTR nIDEvent)
{
	switch (nIDEvent)
	{
	case 0:
		KillTimer(0);
		DSP_com_BackCMD_b0();
		SetTimer(0, 1, NULL);
	case 1:
		KillTimer(1);
		//
		SetTimer(1, 1, NULL);
	default:
		break;
	}
}

void DIA_CtrlPump::OnCbnSelchangeComboPump()
{
	// TODO:  在此添加控件通知处理程序代码
	int index = m_Pump_Select.GetCurSel();
	if (index == 0)
	{
		GetDlgItem(IDC_ElDEX_CMD_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_ElDEX_PARA_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_INDEX)->EnableWindow(TRUE);
		GetDlgItem(IDC_LANPER_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_NEWADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_SPEED_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_SPEEDSTATE_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_RUNSTATE_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_DIRECTION_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_LANPER_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_PARA1_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_PARA2_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_TECAN_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_PARA1_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_PARA2_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_HAMILTON_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_NUM_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_PARA_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_POS_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBOIDEX)->EnableWindow(FALSE);
	}
	else if (index == 1)
	{
		GetDlgItem(IDC_ElDEX_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ElDEX_PARA_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_CMD_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_LANPER_ADDR_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_LANPER_NEWADDR_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_LANPER_SPEED_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_LANPER_SPEEDSTATE_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_LANPER_RUNSTATE_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_LANPER_DIRECTION_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_LANPER_INDEX)->EnableWindow(TRUE);
		GetDlgItem(IDC_CAVRO_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_PARA1_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_PARA2_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_TECAN_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_PARA1_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_PARA2_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_HAMILTON_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_NUM_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_PARA_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_POS_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBOIDEX)->EnableWindow(FALSE);
	}
	else  if (index == 2)
	{
		GetDlgItem(IDC_ElDEX_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ElDEX_PARA_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_NEWADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_SPEED_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_RUNSTATE_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_SPEEDSTATE_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_DIRECTION_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_LANPER_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_CMD_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_CAVRO_ADDR_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_CAVRO_PARA1_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_CAVRO_PARA2_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_TECAN_INDEX)->EnableWindow(TRUE);
		GetDlgItem(IDC_HAMILTON_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_PARA1_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_PARA2_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_HAMILTON_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_NUM_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_PARA_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_POS_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBOIDEX)->EnableWindow(FALSE);
	}
	else if (index == 3)
	{
		GetDlgItem(IDC_ElDEX_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ElDEX_PARA_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_NEWADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_SPEED_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_RUNSTATE_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_SPEEDSTATE_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_DIRECTION_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_LANPER_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_PARA1_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_PARA2_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_TECAN_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_ADDR_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_HAMILTON_PARA1_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_HAMILTON_PARA2_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_HAMILTON_INDEX)->EnableWindow(TRUE);
		GetDlgItem(IDC_IDEX_NUM_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_PARA_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_POS_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBOIDEX)->EnableWindow(FALSE);
	}
	else if (index == 3)
	{
		GetDlgItem(IDC_ElDEX_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ElDEX_PARA_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_NEWADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_SPEED_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_RUNSTATE_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_SPEEDSTATE_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_DIRECTION_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_LANPER_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_PARA1_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_PARA2_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_TECAN_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_ADDR_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_HAMILTON_PARA1_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_HAMILTON_PARA2_EDIT)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBO_HAMILTON_INDEX)->EnableWindow(TRUE);
		GetDlgItem(IDC_IDEX_NUM_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_PARA_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_POS_VALUE)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBOIDEX)->EnableWindow(FALSE);
	}
	else
	{
		GetDlgItem(IDC_ElDEX_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_ElDEX_PARA_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_NEWADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_SPEED_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_RUNSTATE_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_SPEEDSTATE_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_LANPER_DIRECTION_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_LANPER_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_CMD_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_PARA1_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_CAVRO_PARA2_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_TECAN_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_ADDR_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_PARA1_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_HAMILTON_PARA2_EDIT)->EnableWindow(FALSE);
		GetDlgItem(IDC_COMBO_HAMILTON_INDEX)->EnableWindow(FALSE);
		GetDlgItem(IDC_IDEX_NUM_VALUE)->EnableWindow(TRUE);
		GetDlgItem(IDC_IDEX_PARA_VALUE)->EnableWindow(TRUE);
		GetDlgItem(IDC_IDEX_POS_VALUE)->EnableWindow(TRUE);
		GetDlgItem(IDC_COMBOIDEX)->EnableWindow(TRUE);
	}
}


void DIA_CtrlPump::vPackData(Int32 *p_pcPackData, Int32& p_wDataLength)
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
	memcpy(p_pcPackData, l_acData, l_ik*4);
	p_wDataLength = l_ik;
}
void DIA_CtrlPump::Add_Head(Int32 *p_pcPackData, Int32& p_wDataLength)
{
	Int32	l_acData[700];
	Int32 l_ik;
	memset(l_acData, 0x00, sizeof(l_acData));
	l_acData[0] = 0xAAAA0000 | ((p_wDataLength << 8) + p_wDataLength);
	// = 0xAAAA0606;
	l_ik = 1;
	for (int l_i = 0; l_i < p_wDataLength; l_i++)
	{
		l_acData[l_ik++] = p_pcPackData[l_i];
	}//	for (int l_i = 0; l_i < p_wDataLength; l_i++)
	memcpy(p_pcPackData, l_acData, sizeof(l_acData));
	
}

