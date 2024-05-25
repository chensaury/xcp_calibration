/*
 * PSI5.c
 *
 *  Created on: 2023楠烇拷8閺堬拷2閺冿拷
 *      Author: LENOVO
 */

#include "PSI5.h"
#include "SPI.h"
#include "Dio.h"

#define SPI_Write_Register  (0x01)
#define SPI_Read_Register   (0x02)
#define SPI_Sync_Pulse      (0x03)
#define SPI_Get_Data_16b    (0x04)
#define SPI_Get_Data_24b    (0x05)
#define SPI_Get_Data_32b    (0x07)
#define SPI_Get_Data_48b    (0x08)
#define SPI_NOP             (0x0E)
#define SPI_SW_Reset        (0x0F)

#define ASIC_CNFG_1         (0x00)
#define ASIC_CNFG_2         (0x01)
#define ASIC_CNFG_3         (0x02)
#define CH1_CFG1            (0x03)
#define CH1_CFG2            (0x04)
#define CH1_CFG3            (0x05)
#define CH1_CFG4            (0x06)
#define CH1_CFG5            (0x07)
#define CH1_CFG6            (0x08)
#define CH1_CFG7            (0x09)
#define CH2_CFG1            (0x0A)
#define CH2_CFG2            (0x0B)
#define CH2_CFG3            (0x0C)
#define CH2_CFG4            (0x0D)
#define CH2_CFG5            (0x0E)
#define CH2_CFG6            (0x0F)
#define CH2_CFG7            (0x10)
#define CH3_CFG1            (0x11)
#define CH3_CFG2            (0x12)
#define CH3_CFG3            (0x13)
#define CH3_CFG4            (0x14)
#define CH3_CFG5            (0x15)
#define CH3_CFG6            (0x16)
#define CH3_CFG7            (0x17)
#define CH4_CFG1            (0x18)
#define CH4_CFG2            (0x19)
#define CH4_CFG3            (0x1A)
#define CH4_CFG4            (0x1B)
#define CH4_CFG5            (0x1C)
#define CH4_CFG6            (0x1D)
#define CH4_CFG7            (0x1E)

#define ERROR_STATUS_1      (0x25)
#define ERROR_STATUS_2      (0x26)
#define ERROR_STATUS_3      (0x27)
#define ERROR_STATUS_4      (0x28)
#define ERROR_STATUS_5      (0x29)
#define ERROR_STATUS_6      (0x2A)
#define ERROR_STATUS_7      (0x2B)
#define ERROR_STATUS_8      (0x2C)
#define ERROR_STATUS_9      (0x2D)
#define ERROR_STATUS_10     (0x2E)

#define DataBit       24    //16 24 32
#define BufferLen     4     //3 4

psi5Buffers g_psi5Buffers;

uint16 Command = 0;
uint16 Address = 0;
uint16 HData = 0;
uint16 LData = 0;

uint16 CRC_Check_State[4][2] = {{0}};

void ReadReg(uint8 arr, uint16 *rxdata);
void WriteReg(uint8 arr, uint16 txdata);
void delay(uint32 um);
void PSI5TransmitData(const uint16 *txbuff, uint16 *rxbuff);

void PSI5_Init(void)
{
    g_psi5Buffers.spiMasterTxBuffer[0] = 0x0000;
    PSI5TransmitData(&g_psi5Buffers.spiMasterTxBuffer[0], &g_psi5Buffers.spiMasterRxBuffer[0]);

    delay(10);

    Dio_WriteChannel(DioConf_DioChannel_PSI5NRES,0x01);

    delay(10);

#if (DataBit == 16)
    //配置通道1、2、3、4   16bit
    WriteReg(CH1_CFG7, 0x0C00);
    WriteReg(CH2_CFG7, 0x0C00);
    WriteReg(CH3_CFG7, 0x0C00);
    WriteReg(CH4_CFG7, 0x0C00);

#elif (DataBit == 24)
    //配置通道1、2、3、4   24bit
    WriteReg(CH1_CFG7, 0x0800);
    WriteReg(CH2_CFG7, 0x0800);
    WriteReg(CH3_CFG7, 0x0800);
    WriteReg(CH4_CFG7, 0x0800);

#elif (DataBit == 32)
    //配置通道1、2、3、4   36bit
    WriteReg(CH1_CFG7, 0x0400);
    WriteReg(CH2_CFG7, 0x0400);
    WriteReg(CH3_CFG7, 0x0400);
    WriteReg(CH4_CFG7, 0x0400);

#endif

    //配置VG栅极输出
    WriteReg(ASIC_CNFG_1, 0x0003);

    //配置通道速率
    WriteReg(ASIC_CNFG_2, 0x00F0);

    //使能1、2、3、4通道
    WriteReg(ASIC_CNFG_3, 0x004F);

    //时隙设置
    WriteReg(CH1_CFG1, 0x0655);
    WriteReg(CH1_CFG2, 0x06BB);
    WriteReg(CH1_CFG3, 0x0000);

    WriteReg(CH2_CFG1, 0x0655);
    WriteReg(CH2_CFG2, 0x06BB);
    WriteReg(CH2_CFG3, 0x0000);

    WriteReg(CH3_CFG1, 0x0655);
    WriteReg(CH3_CFG2, 0x06BB);
    WriteReg(CH3_CFG3, 0x0000);

    WriteReg(CH4_CFG1, 0x0655);
    WriteReg(CH4_CFG2, 0x06BB);
    WriteReg(CH4_CFG3, 0x0000);

//    //WriteReg(CH3_CFG1, 0x06BF);
//    //WriteReg(CH3_CFG1, 0x00B5);
//
//    WriteReg(CH3_CFG1, 0x0055);
//
//    WriteReg(CH3_CFG2, 0x00BB);
//    //WriteReg(CH3_CFG2, 0x0000);
//    WriteReg(CH3_CFG3, 0x0000);

}

//参数有效值
//@channel : 1 ～ 4
void PSI5_ReadData_24Bit(sint16 psi5data[][2])
{
    uint8 command, slot;
    sint16 data = 0;

    Dio_WriteChannel(DioConf_DioChannel_PSI5Triger, 0x01);
    delay(5);
    Dio_WriteChannel(DioConf_DioChannel_PSI5Triger, 0x00);
    delay(400);

    command = SPI_Get_Data_24b;

    for(uint8 channel = 1; channel <= 4; ++channel){

        slot = 0x00;
        g_psi5Buffers.spiMasterTxBuffer[0] = command << 12;
        g_psi5Buffers.spiMasterTxBuffer[0] |= (channel << 9);
        g_psi5Buffers.spiMasterTxBuffer[0] |= (slot << 6);

        g_psi5Buffers.spiMasterTxBuffer[1] = 0x0000;
        g_psi5Buffers.spiMasterTxBuffer[2] = 0x0000;
        g_psi5Buffers.spiMasterTxBuffer[3] = 0xE000;


        for(int i = 0; i < BufferLen; ++i){
            PSI5TransmitData(&g_psi5Buffers.spiMasterTxBuffer[i], &g_psi5Buffers.spiMasterRxBuffer[i]);
        }

        data = g_psi5Buffers.spiMasterRxBuffer[2] << 2;
        data |= g_psi5Buffers.spiMasterRxBuffer[3] >> 14;
        data &= 0x3FF;
        if((data >> 9) == 1){
            data |= 0xFC00;
        }
        psi5data[channel - 1][slot] = data ;

        slot = 0x01;
        g_psi5Buffers.spiMasterTxBuffer[0] = command << 12;
        g_psi5Buffers.spiMasterTxBuffer[0] |= (channel << 9);
        g_psi5Buffers.spiMasterTxBuffer[0] |= (slot << 6);

        g_psi5Buffers.spiMasterTxBuffer[1] = 0x0000;
        g_psi5Buffers.spiMasterTxBuffer[2] = 0x0000;
        g_psi5Buffers.spiMasterTxBuffer[3] = 0xE000;


        for(int i = 0; i < BufferLen; ++i){
            PSI5TransmitData(&g_psi5Buffers.spiMasterTxBuffer[i], &g_psi5Buffers.spiMasterRxBuffer[i]);
        }

        data = g_psi5Buffers.spiMasterRxBuffer[2] << 2;
        data |= g_psi5Buffers.spiMasterRxBuffer[3] >> 14;
        psi5data[channel - 1][slot] = data;
    }

//    ReadReg(ERROR_STATUS_3, &CRC_Check_State[0][0]);
//    ReadReg(ERROR_STATUS_5, &CRC_Check_State[1][0]);
//    ReadReg(ERROR_STATUS_7, &CRC_Check_State[2][0]);
//    ReadReg(ERROR_STATUS_9, &CRC_Check_State[3][0]);


}


void ReadReg(uint8 arr, uint16 *rxdata)
{
    g_psi5Buffers.spiMasterTxBuffer[0] = 0;
    g_psi5Buffers.spiMasterTxBuffer[1] = 0;
    g_psi5Buffers.spiMasterTxBuffer[2] = 0xE000;

    Command = SPI_Read_Register << 12;
    Address = arr << 6;

    g_psi5Buffers.spiMasterTxBuffer[0] = (Command | Address);
    g_psi5Buffers.spiMasterTxBuffer[1] = 0;

    for(int i = 0; i < 3; ++i){
        PSI5TransmitData(&g_psi5Buffers.spiMasterTxBuffer[i], &g_psi5Buffers.spiMasterRxBuffer[i]);
    }

    rxdata[0] = (g_psi5Buffers.spiMasterRxBuffer[2] & 0x0040);
    rxdata[1] = (g_psi5Buffers.spiMasterRxBuffer[2] & 0x0400);
}

void WriteReg(uint8 arr, uint16 txdata)
{
    g_psi5Buffers.spiMasterTxBuffer[0] = 0;
    g_psi5Buffers.spiMasterTxBuffer[1] = 0;
    g_psi5Buffers.spiMasterTxBuffer[2] = 0xE000;

    Command = (SPI_Write_Register & 0xF) << 12;
    Address = (arr & 0x3F) << 6;
    HData = txdata >> 10;
    LData = (txdata & 0x03FF) << 6;

    g_psi5Buffers.spiMasterTxBuffer[0] = (Command | Address | HData);
    g_psi5Buffers.spiMasterTxBuffer[1] = LData;

    for(int i = 0; i < 3; ++i){
        PSI5TransmitData(&g_psi5Buffers.spiMasterTxBuffer[i], &g_psi5Buffers.spiMasterRxBuffer[i]);
    }
}

void PSI5TransmitData(const uint16 *txbuff, uint16 *rxbuff)
{
    Std_ReturnType stdRet = E_NOT_OK;

    stdRet = Spi_SetupEB(0, txbuff, rxbuff, 1);

    if( E_OK == stdRet )
    {
        stdRet = Spi_SyncTransmit(0);
    }
}
volatile int t_cnt = 0;
void delay(uint32 um)
{
    for(long long i = 0; i < 10 * um; ++i)//35
    {
    	t_cnt ++;
    	if(t_cnt > 10000)
    		t_cnt = 0;
    }
}
