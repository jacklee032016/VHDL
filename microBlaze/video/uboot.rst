u-boot for Nexys Video Board
########################################################
11.18, 2018

Change Log
====================
11.18, 2018

**DEBUG_UART**:

  add DEBUG_UART support, which is not use device tree to configure;
  
  So printascii() function can be used even in start.S;


**Device Tree**:
  Created by petalinux or XSDK;
  
  There are some small differences between them, such as QSPI partitions in petalinux's version;
  
  blob of device tree: how to link to binary and set in the register or field of gd;

  r35 is used as Global Data pointer


**RTL8211E PHY**:

	Modify the PHY address probing in MAC driver;
	
  When configure RTL8211 PHY using auto-negotiation, cross-over cable can be used;
  
  Cable must be connected in order to make auto-negotitation work;


*Startup Flow**:

  _start() in start.s;
  
  board_init_f(): arrry of initializing;
  
  board_init_r(): array of initializing;
  
  main.c


**Main Modifations**:

   board/xilinx/microblaze: header and config.mk;
   arch/microblaze: CPU related initialization;
   include/configs/microblaze-generic.h: configurations;
   