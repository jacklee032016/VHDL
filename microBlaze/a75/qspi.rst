QSPI Flash on AN767 Board
####################################
10.09, 2018

Debugging
============
Oct.28, 2018

Blocked when access control register firstly
---------------------------------------------
* accessing control register means access the first address in QSPI's address space;
* it involves some operation in hardware of CPU or just QSPI IP, or SPI Flash chip;

Resolve
^^^^^^^^^^
* QSPI IP's reset pin is not connect the sys_reset_wizard or any pin for reset;
* When QSPI IP want to access SPI Flash, it want to reset flash, but Flash can't be reset because of without reset pin;
* QSPI IP stop because the signal from flash;


xilisf initialization fail
------------------------------
* Initialization of XSPI BSP library is only initial and reset QSPI IP;
* xilisf then access control info from flash and check it, so xilisf need info about interface number and interface type;
* xilisf access flash info with command of 0x9F(Read ID), but return all 0xFF;

Try add FLASK_CLK signal to SPI flash through CCLK_0 pin of FPGA
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
* After check pins of QSPI IP, the clk is not connectted;
* Connect H13 (eg. CCLK_0 of XC7A75-2 FGG676 ) as FLASH_CLK and connect it to signal of clk of QSPI IP;
* Vivodo can't recognize H13 as validate pin even double check it correct;

Resolve
^^^^^^^^^^
* Enable STARTUP in QSPI IP:
   * add interface of STARTUP: cfgclk, cfgmclk, eos, preq;
   * remove clock from SPI interface;
* eg. when STARTUP is enabled, CCLK_0 is also used as clock of SPI interface defaultly;
   * H13 (eg. CCLK_0) can't used as other pins in constraints file;
* Everything is OK now;   


XIP
============
* When XIP is enabled, AXI FULL (not AXI LITE) is added to access memory space (AXI LITE is used to access Control registers);
* When it is read ControlRegister (baseAddress + 0x60), program is blocked without any response, xsct must reset CPU, sometimes, it can not be reset;


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


