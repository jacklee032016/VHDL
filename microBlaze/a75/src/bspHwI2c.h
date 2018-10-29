
#ifndef	__BSP_HW_I2C_H__
#define	__BSP_HW_I2C_H__

#define	BSP_IIC_BASE_ADDRESS					XPAR_IIC_0_BASEADDR

#define	EXT_I2C_PCA9554_ADDRESS				(0xE0 >> 1)

#define	EXT_I2C_ADDRESS_LM1983				(0xCA >> 1)		/* ADDR pin is Tie low */
#define	EXT_I2C_ADDRESS_LM1983_FLOAT		(0xCE >> 1)

#define	EXT_I2C_ADDRESS_SENSOR             		(0x30 >> 1)


#define	EXT_I2C_PCA9554_CS_MAC				(4)	/* CS0, MAC address; not used */
#define	EXT_I2C_PCA9554_CS_SENSOR			(5)	/* CS1, sensor and EEPROM  */
#define	EXT_I2C_PCA9554_CS_FPGA				(6)	/* CS2, FPGA */
#define	EXT_I2C_PCA9554_CS_BOOTROM			(7)	/* CS3, Ethernet switch */

#define	EXT_I2C_PCA9554_CS_NONE				(0xFF) /* connect to I2C of MCU directly */


#define LMH1983_STATUS_INP				0x00
#define LMH1983_STATUS					0x01

#define LMH1983_PLL_LOCK				0x02
#define LMH1983_REVISION_ID			0x03
#define LMH1983_DEV_CTRL				0x05
#define LMH1983_INP_POL				0x06
#define LMH1983_OMODE_PLL2			0x07
#define LMH1983_OMODE_PLL3			0x08
#define LMH1983_OMODE_MISC			0x09
#define LMH1983_OBUFFER				0x0A
#define LMH1983_OFRAME1_CTRL_MSB		0x0B
#define LMH1983_OFRAME1_CTRL_LSB		0x0C
#define LMH1983_OFRAME2_CTRL_MSB		0x0D
#define LMH1983_OFRAME2_CTRL_LSB		0x0E
#define LMH1983_OFRAME3_CTRL_MSB		0x0F
#define LMH1983_OFRAME3_CTRL_LSB		0x10


/* registers for LM95245 sensor */
#define	EXT_I2C_SENSOR_LOCAL_TEMP_MSB		0x00
#define	EXT_I2C_SENSOR_LOCAL_TEMP_LSB		0x30
#define	EXT_I2C_SENSOR_MANUFACTURE_ID		0xFE
#define	EXT_I2C_SENSOR_REVISION_ID			0xFF


/* only EEPROM MAC has serial no; this address is the beginning of second half 256, eg.128 byte */
#define	EEPROM_MEM_SERIALNO_ADDR			0x80

/* address of EEROM */
#define	EEPROM_AT24MAC402_ADDRESS			(0xBE >> 1)	/* Evaludation board AT24MAC, 4Kb */
#define	EEPROM_AT24C04BN_ADDRESS			(0xAC >> 1)	/* 4Kb, on channel-1, shared with Sensor */
#define	EEPROM_24AA02E48T_ADDRESS			(0xA0 >> 1)	/* 2Kb, on channel-0 */

#define	EEPROM_AT24MAC402_SIZE				(128)	/* bytes, 1Kb  not include the second half */
#define	EEPROM_AT24C04BN_SIZE				(512)	/* 4Kb,  */
#define	EEPROM_24AA02E48T_SIZE				(256)	/* 2Kb */

#define	EEPROM_AT24MAC402_PAGE_SIZE			(16)		/* 16 page of 16 byte for whole 2kbit */
#define	EEPROM_AT24C04BN_PAGE_SIZE			(16)		/* 16byte/page, total 32 pages */
#define	EEPROM_24AA02E48T_PAGE_SIZE			(8)		/* 8bytes/page, total 32 pages */


#define	EXT_EEPROM_4K							1

#if EXT_EEPROM_4K
#define	EXT_I2C_EEPROM_ADDRESS				EEPROM_AT24C04BN_ADDRESS	/*default, 4K, channel-1*/
#define	EXT_I2C_EEPROM_CHANNEL				EXT_I2C_PCA9554_CS_SENSOR	/* channel-1 */
#define	EXT_I2C_EEPROM_SIZE					EEPROM_AT24C04BN_SIZE
#define	EXT_I2C_EEPROM_PAGE_SIZE				EEPROM_AT24C04BN_PAGE_SIZE
#else
#define	EXT_I2C_EEPROM_ADDRESS				EEPROM_24AA02E48T_ADDRESS
#define	EXT_I2C_EEPROM_CHANNEL				EXT_I2C_PCA9554_CS_MAC	/* channel-0 */
#define	EXT_I2C_EEPROM_SIZE					EEPROM_24AA02E48T_SIZE
#define	EXT_I2C_EEPROM_PAGE_SIZE				EEPROM_24AA02E48T_PAGE_SIZE
#endif


#define	BSP_IIC_REGISTER_WRITE(offset, value) \
			XIic_WriteReg(BSP_IIC_BASE_ADDRESS, (offset), (value))

#define	BSP_IIC_REGISTER_READ(offset) \
			XIic_ReadReg(BSP_IIC_BASE_ADDRESS, (offset) )

#define	BSP_IIC_WRITE(iicAddr, buf, len) \
			XIic_Send(BSP_IIC_BASE_ADDRESS, (iicAddr), (buf), (len),  XIIC_STOP /*XIIC_REPEATED_START*/)

#define	BSP_IIC_READ(iicAddr, buf, len) \
			 XIic_Recv(BSP_IIC_BASE_ADDRESS, (iicAddr), (buf), (len), XIIC_STOP)
			 

#endif

