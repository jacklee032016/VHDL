About Demo of Nexys Video Board
####################################
10.12, 2018

Flash part:
	* s25fl256xxxxxx0, eg. s25fl256sxxxxxx0-spi-x1_x2_x4

UART 16500, baudrate can be momdified;

Programming with download.bit:

   * Network: not support auto-adaption, so switch must be needed;



SDK
============

Can't build directly
----------------------
* Modify the bsp/microblaze0/libsrc/
* Only bsp/microblaze0/include/xparameters.h is created based on hardware design;

   