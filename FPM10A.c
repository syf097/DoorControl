#include "FPM10A.h"

volatile unsigned char FPM10A_RECEICE_BUFFER[32];
unsigned int finger_id = 0;
extern void open();
	
//FINGERPRINT通信协议定义

code unsigned char FPM10A_Get_Device[10] ={0x01,0x00,0x07,0x13,0x00,0x00,0x00,0x00,0x00,0x1b};//口令验证
code unsigned char FPM10A_Pack_Head[6] = {0xEF,0x01,0xFF,0xFF,0xFF,0xFF};  //协议包头
code unsigned char FPM10A_Get_Img[6] = {0x01,0x00,0x03,0x01,0x00,0x05};    //获得指纹图像
code unsigned char FPM10A_Get_Templete_Count[6] ={0x01,0x00,0x03,0x1D,0x00,0x21 }; //获得模版总数
code unsigned char FPM10A_Search[11]={0x01,0x00,0x08,0x04,0x01,0x00,0x00,0x03,0xE7,0x00,0xF8}; //搜索指纹搜索范围0 - 999,使用BUFFER1中的特征码搜索
code unsigned char FPM10A_Search_0_9[11]={0x01,0x00,0x08,0x04,0x01,0x00,0x00,0x00,0x13,0x00,0x21}; //搜索0-9号指纹
code unsigned char FPM10A_Img_To_Buffer1[7]={0x01,0x00,0x04,0x02,0x01,0x00,0x08}; //将图像放入到BUFFER1
code unsigned char FPM10A_Img_To_Buffer2[7]={0x01,0x00,0x04,0x02,0x02,0x00,0x09}; //将图像放入到BUFFER2
code unsigned char FPM10A_Reg_Model[6]={0x01,0x00,0x03,0x05,0x00,0x09}; //将BUFFER1跟BUFFER2合成特征模版
//volatile:系统总是重新从它所在的内存读取数据，即使它前面的指令刚刚从该处读取过数据
/*------------------ FINGERPRINT命令字 --------------------------*/
 //发送包头
void FPM10A_Cmd_Send_Pack_Head(void)
{
	int i;	
	for(i=0;i<6;i++) //包头
   {
     Uart_Send_Byte(FPM10A_Pack_Head[i]);   
    }		
}

//接收反馈数据缓冲
void FPM10A_Receive_Data(unsigned char ucLength)
{
  unsigned char i;

  for (i=0;i<ucLength;i++)
     FPM10A_RECEICE_BUFFER[i] = Uart_Receive_Byte();

}

//FINGERPRINT_获得指纹图像命令
void FPM10A_Cmd_Get_Img(void)
{
    unsigned char i;
    FPM10A_Cmd_Send_Pack_Head(); //发送通信协议包头
    for(i=0;i<6;i++) //发送命令 0x1d
	{
       Uart_Send_Byte(FPM10A_Get_Img[i]);
	}
}
//讲图像转换成特征码存放在Buffer1中
void FINGERPRINT_Cmd_Img_To_Buffer1(void)
{
 	unsigned char i;
	FPM10A_Cmd_Send_Pack_Head(); //发送通信协议包头      
   	for(i=0;i<7;i++)   //发送命令 将图像转换成 特征码 存放在 CHAR_buffer1
     {
      Uart_Send_Byte(FPM10A_Img_To_Buffer1[i]);
   	  }
}

//搜索全部用户999枚
void FPM10A_Cmd_Search_Finger(void)
{
       unsigned char i;	   	    
			 FPM10A_Cmd_Send_Pack_Head(); //发送通信协议包头
       for(i=0;i<11;i++)
           {
    	      Uart_Send_Byte(FPM10A_Search[i]);   
   		   }
}





//搜索指纹
void FPM10A_Find_Fingerprint()
{
	unsigned int i;
	unsigned int find_fingerid = 0;
	unsigned char id_show[]={0,0,0};
	for(i=1;i<20000;i++)
	{
		FPM10A_Cmd_Get_Img(); //获得指纹图像
		FPM10A_Receive_Data(12);		
		//判断接收到的确认码,等于0指纹获取成功
		if(FPM10A_RECEICE_BUFFER[9]==0)
		{			
			Delay_Ms(100);
			FINGERPRINT_Cmd_Img_To_Buffer1();
			FPM10A_Receive_Data(12);		
			FPM10A_Cmd_Search_Finger();
			FPM10A_Receive_Data(16);			
			if(FPM10A_RECEICE_BUFFER[9] == 0) //搜索到  
			{				
		open();			//开门
			   }
				else //没有找到
				{
				 
		

				}
			}		
		}
}








