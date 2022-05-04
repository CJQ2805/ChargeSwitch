#ifndef __OTT2001A_H
#define __OTT2001A_H	
#include <SysCommDef.h>	
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ���������ɣ��������������κ���;
//ALIENTEK STM32������
//4.3����ݴ�����-OTT2001A ��������	   
//����ԭ��@ALIENTEK
//������̳:www.openedv.com
//��������:2015/12/28
//�汾��V1.0
//��Ȩ���У�����ؾ���
//Copyright(C) �������������ӿƼ����޹�˾ 2014-2024
//All rights reserved									  
////////////////////////////////////////////////////////////////////////////////// 


//IO��������	
#define OTT_RST PIout(8) //OTT2001A��λ����
#define OTT_INT PHin(7)  //OTT2001A������		
  
//ͨ��OTT_SET_REGָ��,���Բ�ѯ�������Ϣ 
//ע��,�����X,Y����Ļ������ϵ�պ��Ƿ���.
#define OTT_MAX_X 		2700	 	//TP X��������ֵ(������)
#define OTT_MAX_Y 		1500    	//TP Y��������ֵ(�᷽��)

//��������
#define OTT_SCAL_X		0.2963		//��Ļ�� ������/OTT_MAX_X		
#define OTT_SCAL_Y		0.32		//��Ļ�� ������/OTT_MAX_Y		
 
//I2C��д����	
#define OTT_CMD_WR 		0XB2     	//д����
#define OTT_CMD_RD 		0XB3		//������
 
//�Ĵ�����ַ
#define OTT_GSTID_REG 	0X0000   	//OTT2001A��ǰ��⵽�Ĵ������
#define OTT_TP1_REG 	0X0100  	//��һ�����������ݵ�ַ
#define OTT_TP2_REG 	0X0500		//�ڶ������������ݵ�ַ
#define OTT_TP3_REG 	0X1000		//���������������ݵ�ַ
#define OTT_TP4_REG 	0X1400		//���ĸ����������ݵ�ַ
#define OTT_TP5_REG 	0X1800		//��������������ݵ�ַ  
#define OTT_SET_REG   	0X0900   	//�ֱ������üĴ�����ַ
#define OTT_CTRL_REG  	0X0D00   	//����������(��/��)  

 	

u8 OTT2001A_WR_Reg(u16 reg,u8 *buf,u8 len);		//д�Ĵ���(ʵ������)
void OTT2001A_RD_Reg(u16 reg,u8 *buf,u8 len);	//���Ĵ���
void OTT2001A_SensorControl(u8 cmd);//��������/�رղ���
u8 OTT2001A_Init(void); 			//4.3���ݴ�����ʼ������
u8 OTT2001A_Scan(u8 mode);			//���ݴ�����ɨ�躯��

#endif












