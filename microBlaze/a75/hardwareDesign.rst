Hardware Design for AN767 Board
###################################

AXI ETHERNET Design
=============================
10.19, 2018


Hardware Design
--------------------

* AXI 1G/2.5G Enternet Subsystem + AXI Direct Memory Access;
* (Tri Mode Ethernet MAC + AXI Ethernet Buffer);
* RGMII interface;
* External 25MHz Clock:
   * Clocking Wizard:
      * Input 25MHz;
      * Output:
         * 200MHz: ref_clk|axis_clk of AXI_ETHERNET; clocks of DMA; 
         * 125MHz: gtx_clk of AXI_ETHERNET


About MDIO
^^^^^^^^^^^^^^^^^^^^^
* No connection to MDIO interface, so PHY can't be read and controlled;



Modification of MicroBlaze
=============================
10.11, 2018
Output Bus Interface 
-----------------------
* **M_AXI_DP** : Peripheral Data interface, eg, mapping peripheral device into memory address space;
   *  --> S00_AXI of ``AXI Interconnection``;
      * ``AXI_Interconnection`` plays as bus bridge to mapping AXI Slave transaction from CPU to AXI Master Transaction to peripheral devices;
      * So, 

Add Following Bus Intefaces
-------------------------------

When enable ``Data and Instuction Cache`` in MicroBlaze configuration page, following bus interface is added:

* **M_AXI_DC**: Data Side Cache AXI4 interface
* **M_ADC_IC**: Instruction Side Cache AXI4 interface

This bus interfaces are bus of master device (MicroBlaze), need to connect bus of slace device (AXI4 Interconnection or AXI4 SmartConnection);

Connect to existed AXI4 InterConnection
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
* MIG is mapped into Instruction Address Space: **So text section can be placed in MIG SDRAM now**;
* Other all AXI4 Slave also are mapped to Instruction address space;


Connect to new AI4 SmartConnection or AXI4 Interconnection
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
* Only MIG is mapped into instruction address space;

   * M_AXI_DC --> S00_AXI of SMC;
   * M_AXI_IC --> S01_AXI of SMC;
   * clk_out1 --> aclk of SMC;
   * ui_clk of MIG --> aclk1 of SMC (SMC must has 2 clock domain, one for system domain, one for SDRAM/DDR3);
      * ui_clk of MIG --> sloweset_sync_clk of rst_mig (same DDR clock domain, different from system clock domain);
   * preipheral_aresetn of rst_mig --> aresetn of SMC:
      * also --> aresetn of MIG (same DDR3 reset domain which is different from system reset domain);

**Notes**:

* When text section can't be placed into SDRAM, you can't find MIG in Instruction Address space in ``Address Editor``;


LMB (I|D) enlarge to 128 KB
=============================



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
