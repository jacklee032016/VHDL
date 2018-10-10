QSPI Flash on AN767 Board
####################################
10.09, 2018


XIP
============


SDK Programming
=================
Flash Type:mt25ql256-spi-x1_x2_x4


SPI Flash 
============
* DataInout: 4 pins;
* Clock: 1 pin;
* CSn: 1 pin;

For connect to FPGA, CCLK pin of FPGA (which is Configure Clock) always connect to Clock pin of flash in order to configure FPGA; (FPGA always configured as Master)

So, for Quad mode, 5 pins needed to be connected;

For Standard SPI mode, io0 is MOSI(FPGA-->Flash), io1 is MISO (Flash-->FPGA)

QAD SPI IP
============

For Standard SPI mode, io0 is MOSI(FPGA-->Flash), io1 is MISO (Flash-->FPGA); ss is CSn;


STARTUPE2 Primitive
======================
When poweron and configure as Master mode, FPGA will configured from flash after power is ON; 

After FPGA is configured, flash may be accessed by other device.

So STARTUPE2 primitive is used to control or response the configuration flow of FPGA. 

For example, User startup Clock and User CCLK signal from MCU etc. are in the port of this primitive;


