Programming FPGA
####################

Installation/Upgrading driver of Cable USB II
=================================================

Drivers:

*. Jungo: WinDriver;

*. Xilinx: Xilinx Programming Cable, USB Cable

*. Default driver is not working, must add driver with xilinx tools;

Steps:

* Delete Driver and Reinstall with `Add Design Tools or Device 2017.4`: select;

* When everything is OK, the green light is on, otherwise it is yellow light;


Device 
==========
hardware Manager in Vivado

* `localhost/xilinx_tcf/xilinx/XXXXXX`:
   * 'xc7a75t_0':
      * `XADC(System Monitor)`;
	  * 'mt25ql256-spi-x1_x2_x4';

**Notes**:

* SPI Flash, 256Mb(density), Micro 25Q256A, mt25ql256, alias: n25q256-3.3v;

* `Configuration Memory Device`

	  