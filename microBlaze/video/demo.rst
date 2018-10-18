About Demo of Nexys Video Board
####################################
10.12, 2018


Debugging Etherent of Demo and bist
====================================

Bist
---------
* Standalone, main loop is controlled by input (all input is not echoed);
* only one test can be executed once a time because polling and replying one type of test in main loop;
* Only ``eth-start`` is inputted, ethernet is enabled, packet are sent back in main loop;


Demo
----------
* Main loop poll and reply all types of events;
* IP also shown in LED;

**ping always works, because ARP is enabled defaultly**;


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

   