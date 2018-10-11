Hardware Design for AN767 Board
###################################


Test Results
==============
* Text section can't be placed in SDRAM;
* SREC bootloader can't read anything;
   * xilisf library can't be built when serial flash family set as 3 or 4;
* Intr Controller selfTest failed;
* Timer selfTest failed;


Interrupt Controller
======================
10.10, 2018

OS option of FreeRTOS: DRC, FreeRTOS_drc failed: CPU has no connections to interrupt controller, mdt_error

AXI Interrupt Controller
-------------------------

Inputs
^^^^^^^^^
* s_axi: slave AXI, --> ``AXI InterConnect``;
* s_axi_aclk: clk_out1 (``Clock Wizard``);
* s_axi_aresetn: Peripheral_aresetn of ``Processor System Reset``;
* int[r]: 

When ``Enable Fast Interrupt Logic``:

* processor_clk:
* processor_rst: 

Outputs
^^^^^^^^^
* Interrupt:


Concat
---------
* Connect every interrupt output pin to input pin of Concat;
* Connect output to INTERRUPT pins of Interrupt Controller;


MIG 7 Series
================
* Clock Period : 3000ps : 333.33MHz (PHY working rate);
* PHY to Controller Clock Rate : 4:1 
* Chip: MT41J128M16HZ-15E
* Input Clock : 4000ps|250MHz ( also set clk_out2 in Clock Wizard as 250MHz )
* Data Width: 32-bit;
* Controller Data Width: 32-bit;

* Make interface of DDR3 external;


IOBUF Primitive
=================

* Bi-Directional Buffer
* Used in QUAD SPI IP
