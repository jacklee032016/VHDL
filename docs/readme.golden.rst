README for Golden Image 
#########################
April,23rd, 2018  Jack Lee

May,1st, Tuesday
===================
	Add reset signal and RESET realteck switch chip, so golden image can be used to update image through ethernet;
										
Constrains and configuration
===================================
	set_property BITSTREAM.CONFIG.CONFIGFALLBACK ENABLE [current_design]
	
	set_property BITSTREAM.CONFIG.NEXT_CONFIG_ADDR 0x0400000 [current_design]
	
	# internal CFG_MCLK (50MHz) for Watchdog, a version prescaled by 256(100 to 300 KHz), 5.12us per unit
	
	# about 1~2 second
	
	set_property BITSTREAM.CONFIG.TIMER_CFG 0x50000 [current_design]										

Functions of Golden Image:
=============================
* LED1:
   * Link(U)	: 5 seconds
   * Power(B): ON
* LED2:
   * ACT(U)	: 1Hz
   * SDI(B)	:	10HZ
* SPI Flash			

Test and Validation:
==========================
* Golden in address 0;
	
* ledTimeCtrl.bin:
   * SDI/POWER	: ON
   * ACT/Link	: 0.5Hz
			
			address 4M and 6M

	If erasing 4M sector, golden image will be displayed after a short delay; and ledTimeCtrl in address of 6M is not used;
	
	If ledTimeCtrl is there, blink quickly after poweron or reconfigure FPGA;

