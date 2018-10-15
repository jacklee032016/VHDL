About Demo of Nexys Video Board
####################################
10.12, 2018

Flash part:
	* s25fl256xxxxxx0, eg. s25fl256sxxxxxx0-spi-x1_x2_x4

UART 16500, baudrate can be momdified;

Programming with download.bit:

   * Network: not support auto-adaption, so switch must be needed;

New Version SDK
=================
* SDK create new workspace and import the *.hdf file, which contains bitstream file also;
* 


Existed SDK
============
Bootloader (srec) can't work
-------------------------------
* Debug with VERBOSE and INFO options (different from new SDK), can't read SREC line: read length is bigger than maximum, 256 bytes;



Standalong_v4.2: Link ``xil_printf()`` is from libgloss.x, not xil_printf(), like new version standalone_v6.9;

Can't build directly
----------------------
* Modify the bsp/microblaze0/libsrc/: comments declaration of ``print()``;
* Only bsp/microblaze0/include/xparameters.h is created based on hardware design;

   