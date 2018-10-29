
#include "xparameters.h"
#include "xiic.h"
#include "xil_printf.h"

#include "bspHwI2c.h"

unsigned bspI2cWrite(u8 iicAddr, u8 address, u8 addrLen, u8 *data, u16 dataLen)
{
	volatile unsigned SentByteCount;
	volatile unsigned AckByteCount;
	
	if(addrLen)
	{
		do
		{
			SentByteCount = BSP_IIC_WRITE(iicAddr, (u8 *)&address, addrLen );
			if (SentByteCount != addrLen )
			{
				/* Send is aborted so reset Tx FIFO */
				BSP_IIC_REGISTER_WRITE(XIIC_CR_REG_OFFSET, XIIC_CR_TX_FIFO_RESET_MASK);
				BSP_IIC_REGISTER_WRITE(XIIC_CR_REG_OFFSET, XIIC_CR_ENABLE_DEVICE_MASK);
			}

		} while (SentByteCount != addrLen );
	}

	/*
	 * Write a page of data at the specified address to the EEPROM.
	 */
	SentByteCount = BSP_IIC_WRITE(iicAddr, data, dataLen);

	/*
	 * Wait for the write to be complete by trying to do a write and
	 * the device will not ack if the write is still active.
	 */
	do
	{
		AckByteCount = BSP_IIC_WRITE(iicAddr, (u8 *)&address, 1 );
//		xil_printf("AckByteCount=%d\r\n", AckByteCount);
		if (AckByteCount != 1)
		{
			/* Send is aborted so reset Tx FIFO */
			BSP_IIC_REGISTER_WRITE(XIIC_CR_REG_OFFSET, XIIC_CR_TX_FIFO_RESET_MASK);
			BSP_IIC_REGISTER_WRITE(XIIC_CR_REG_OFFSET, XIIC_CR_ENABLE_DEVICE_MASK);
		}

	} while (AckByteCount != 1);


	/*Return the number of bytes	 */
	return SentByteCount;
}


unsigned bspI2cRead(u8 iicAddr, u8 addr, u8 addrLen, u8 *buf, u16 len)
{
	volatile unsigned ReceivedByteCount;
	u16 StatusReg;

	if(addrLen)
	{
		do {
			StatusReg = BSP_IIC_REGISTER_READ(XIIC_SR_REG_OFFSET);
			if(!(StatusReg & XIIC_SR_BUS_BUSY_MASK))
			{
				ReceivedByteCount = BSP_IIC_WRITE(iicAddr, (u8 *)&addr, addrLen );

				if (ReceivedByteCount != addrLen)
				{
					/* Send is aborted so reset Tx FIFO */
					BSP_IIC_REGISTER_WRITE(XIIC_CR_REG_OFFSET, XIIC_CR_TX_FIFO_RESET_MASK);
					BSP_IIC_REGISTER_WRITE(XIIC_CR_REG_OFFSET, XIIC_CR_ENABLE_DEVICE_MASK);
				}
			}
		} while (ReceivedByteCount != addrLen );
	}

	/*
	 * Read the number of bytes at the specified address 
	 */
	ReceivedByteCount = BSP_IIC_READ(iicAddr, buf, len);

	/*
	 * Return the number of bytes.
	 */
	return ReceivedByteCount;
}

	
static void _bspI2cPca9554Config(u8 channel)
{
	u8 data = channel;
	volatile unsigned ReceivedByteCount;

	/* Send test pattern to EEPROM */
	if (BSP_IIC_WRITE(EXT_I2C_PCA9554_ADDRESS, &data, 1) != 1)
	{
		EXT_ABORT( "\tI2C channo configuration failed: %d", channel);
	}

#if 0
#if 1
	ReceivedByteCount = BSP_IIC_READ(EXT_I2C_PCA9554_ADDRESS, &data, 1);
	if(ReceivedByteCount != 1)
	{
		EXT_ERRORF(("Read ChanNo Failed:%d", ReceivedByteCount) );
	}
#else 
	if (bspI2cRead(EXT_I2C_PCA9554_ADDRESS, 0,0, &data, 1) != 1)
	{
		EXT_ABORT( "\tI2C channo read failed");
	}
#endif

	if(data != channel)
	{
		EXT_ERRORF(("Read ChanNo:%d, should be %d", data, channel) );
	}
	else
	{
		EXT_INFOF(("Read ChanNo:%d == %d", data, channel) );
	}
#endif

}



unsigned bspI2cExtRead(u8 channo, u8 iicAddr, u8 address, u8 addrLen, u8 *buf, u16 len)
{
	_bspI2cPca9554Config((channo != EXT_I2C_PCA9554_CS_NONE)?channo:0);

	return bspI2cRead(iicAddr, address, addrLen, buf, len);
}


unsigned bspI2cExtWrite(u8 channo, u8 iicAddr, u8 address, u8 addrLen, u8 *buf, u16 len)
{
	_bspI2cPca9554Config((channo != EXT_I2C_PCA9554_CS_NONE)?channo:0);

	return bspI2cWrite(iicAddr, address, addrLen, buf, len);
}


int bspI2cChipDetect(void)
{
	int byteCount;
	u8 data;
	unsigned char revisionId = 0;
	unsigned char	manufactureId = 0;
	int index = 0;


	byteCount = bspI2cRead( EXT_I2C_ADDRESS_LM1983, LMH1983_REVISION_ID, 1, &data, 1);
	if(data != 0xC0)
	{
		EXT_ERRORF(("LMH1983 RevisionID wrong: %2x", data));
		return XST_FAILURE;
	}
	else
	{
		EXT_INFOF(("LMH1983 RevisionID OK: %2x", data));
	}

	byteCount = bspI2cExtRead(EXT_I2C_PCA9554_CS_NONE, EXT_I2C_ADDRESS_LM1983, LMH1983_REVISION_ID, 1, &data, 1);
	if(data != 0xC0)
	{
		EXT_ERRORF(("LMH1983 RevisionID wrong: %2x", data));
	}
	else
	{
		EXT_INFOF(("LMH1983 RevisionID OK: %2x", data));
	}


	bspI2cExtRead(EXT_I2C_PCA9554_CS_SENSOR, EXT_I2C_ADDRESS_SENSOR, EXT_I2C_SENSOR_MANUFACTURE_ID, 1, &manufactureId, 1);
	bspI2cExtRead(EXT_I2C_PCA9554_CS_SENSOR, EXT_I2C_ADDRESS_SENSOR, EXT_I2C_SENSOR_REVISION_ID, 1, &revisionId, 1);

	EXT_INFOF(( "Sensor: Manu ID:'0x%x'; RevisionID:'0x%x': %s", manufactureId, revisionId, (revisionId== 0xB3 && manufactureId==0x01)?"OK":"Error" ));
	if(revisionId!= 0xB3 || manufactureId!=0x01)
	{
		return XST_FAILURE;
	}


	return XST_SUCCESS;
}

static const u8 test_data_tx[] =
{
	/** SAM TWI EEPROM EXAMPLE */
	'M', 'u', 'x', 'L', 'a', 'b', '-', 'A',
	'N', '7', '6', '7', 'M', '-','O', 'K',
	'P', 'a', 'g', 'e', '-', 'N', 'o', ',',
	'2'
};

#define TEST_DATA_LENGTH  (sizeof(test_data_tx) / sizeof(u8))

/* startAddress is at page border*/
void extEepromWrite(unsigned char startAddress, unsigned char *value, unsigned int size)
{
	unsigned int i;
	unsigned int pages = (size+EXT_I2C_EEPROM_PAGE_SIZE-1)/EXT_I2C_EEPROM_PAGE_SIZE;
	unsigned char left = EXT_I2C_EEPROM_PAGE_SIZE;
	unsigned char start = 0;

	for(i=0; i< pages; i++)
	{/* the offset address is send together, don't send it independently */
		left = ((size - start)>EXT_I2C_EEPROM_PAGE_SIZE)?EXT_I2C_EEPROM_PAGE_SIZE:(size - start);
		if(i>0)
		{
//			EXT_DELAY_US(1500);
		}
#if 0
		xil_printf("EEPROM Write No.%d page at 0x%x, length %d"EXT_NEW_LINE, i, start, left );
#endif
		bspI2cExtWrite(EXT_I2C_EEPROM_CHANNEL, EXT_I2C_EEPROM_ADDRESS, startAddress+start, 1, value+start, left);
		start += EXT_I2C_EEPROM_PAGE_SIZE;
	}
	
}



void extEepromRead(unsigned char startAddress, unsigned char *value, unsigned int size)
{
	bspI2cExtRead(EXT_I2C_EEPROM_CHANNEL, EXT_I2C_EEPROM_ADDRESS, startAddress, 1, value, size);
}


char bspBistI2cEeprom(void )
{
	u8 datarx[TEST_DATA_LENGTH];
	unsigned char address = 0;
	unsigned int size = TEST_DATA_LENGTH;
	unsigned int i;


	//	extEepromRead(0, datarx, TEST_DATA_LENGTH);
	
	/* write and readback 25 bytes, acrossing 2 pages in EEPROM */
	extEepromWrite(address, (unsigned char *)test_data_tx, size);

	extEepromRead(address, datarx, size);
	
	for(i=0; i< size; i++)
	{
		if(datarx[i] != test_data_tx[i])
		{
			EXT_ERRORF(("ERROR: No.%d bytes is different, %x!=%x", (int)i, datarx[i],  test_data_tx[i]));
			return XST_FAILURE;
		}
	}

	EXT_INFOF(("EPPROM read/write OK!"));
	return XST_SUCCESS;
}


short bspSensorGetTemperatureCelsius(void)
{/* 11 bits: sign bit + 10 bit value */
	unsigned char regVal;
	short temperature = 0;
    
	bspI2cExtRead(EXT_I2C_PCA9554_CS_SENSOR, EXT_I2C_ADDRESS_SENSOR, EXT_I2C_SENSOR_LOCAL_TEMP_MSB, 1, &regVal, 1);

//	EXT_DEBUGF("LM95245 Temp(MSB): %d", regVal);
	temperature = (regVal<<8);
	bspI2cExtRead(EXT_I2C_PCA9554_CS_SENSOR, EXT_I2C_ADDRESS_SENSOR, EXT_I2C_SENSOR_LOCAL_TEMP_LSB, 1, &regVal, 1);

	/* only 3 bits in LSB register */
	temperature |=  (regVal>>5); //*0.125;// / 256.0;
      
//	EXT_DEBUGF("LM95245 Temp(LSB): %d*0.125;", (regVal>>5) );
	return temperature;
}



int iicBist(void)
{
	short temp;

	bspI2cChipDetect();

	bspBistI2cEeprom();

	temp = bspSensorGetTemperatureCelsius();
	EXT_INFOF(("Current temperature:%d+%d*0.125", (temp>>8), (temp&0xFF) ));

	return XST_SUCCESS;
}

int xlnxI2cTestRegister(XIic *InstancePtr)
{
	int Status = XST_SUCCESS;
	int GlobalIntrStatus;
	u32 IntrEnableStatus;

	Xil_AssertNonvoid(InstancePtr != NULL);
	Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

	/*
	 * Store the Global Interrupt Register and the Interrupt Enable Register
	 * contents.
	 */
	GlobalIntrStatus = XIic_IsIntrGlobalEnabled(InstancePtr->BaseAddress);
	IntrEnableStatus = XIic_ReadIier(InstancePtr->BaseAddress);

	EXT_DEBUGF(EXT_DBG_ON, ("IIC: GlobalIntrStatus:%d; IntrEnableStatus:%d", GlobalIntrStatus, IntrEnableStatus) );
	/*
	 * Reset the device so it's in a known state and the default state of
	 * the interrupt registers can be tested.
	 */
	XIic_Reset(InstancePtr);

	if (XIic_IsIntrGlobalEnabled(InstancePtr->BaseAddress)!= 0) {
		Status = XST_FAILURE;
	}

	if (XIic_ReadIier(InstancePtr->BaseAddress)!= 0) {
		Status = XST_FAILURE;
	}

	/*
	 * Test Read/Write to the Interrupt Enable register.
	 */
	XIic_WriteIier(InstancePtr->BaseAddress, XIIC_TX_RX_INTERRUPTS);
	if (XIic_ReadIier(InstancePtr->BaseAddress)!= XIIC_TX_RX_INTERRUPTS) {
		Status = XST_FAILURE;
	}

	EXT_DEBUGF(EXT_DBG_ON, ("IIC: RW Interrupt Enable register OK") );
	/*
	 * Reset device to remove the affects of the previous test.
	 */
	XIic_Reset(InstancePtr);

	/*
	 * Restore the Global Interrupt Register and the Interrupt Enable
	 * Register contents.
	 */
	if (GlobalIntrStatus == TRUE) {
		XIic_IntrGlobalEnable(InstancePtr->BaseAddress);
	}
	XIic_WriteIier(InstancePtr->BaseAddress, IntrEnableStatus);

	EXT_DEBUGF(EXT_DBG_ON, ("IIC: Restore  Global Interrupt Register and Interrupt Enable register OK") );

	return Status;
}

int xlnxI2cSelfTest(u16 DeviceId)
{
	int Status;
	XIic_Config *ConfigPtr;	/* Pointer to configuration data */

	/*
	 * The following are declared globally so they are zeroed and so they are
	 * easily accessible from a debugger.
	 */
	XIic Iic; /* The driver instance for IIC Device */

	/*
	 * Initialize the IIC driver so that it is ready to use.
	 */
	ConfigPtr = XIic_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		return XST_FAILURE;
	}

	Status = XIic_CfgInitialize(&Iic, ConfigPtr, ConfigPtr->BaseAddress);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}

#if 0
	/*
	 * Perform a self-test to ensure that the hardware was built
	 * correctly.
	 */
	Status = xlnxI2cTestRegister(&Iic);
	if (Status != XST_SUCCESS) {
		return XST_FAILURE;
	}
#endif

	iicBist();

	return XST_SUCCESS;
}

