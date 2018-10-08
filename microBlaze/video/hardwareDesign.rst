Hardware Design
######################


AXI Quad SPI IP
=================
10.07, 2018

Configuration
---------------
Select vendor as SPANSION in configuration page;

Interfaces
------------

Input
^^^^^^^
* AXI_LITE --> AXI InterConnect (from mb0);
* ext_spi_clk|s_axi_aclk  --> clk_out1 (Clock Wizard);

  * clk_out1 also connect AXI InterConnect and other peripheral devices;
* s_aresetn --> Processor System Reset( and many other devices);

  * These devices connect to same clk and reset are in same time domain;

Output
^^^^^^^^
* SPI_0: external pins(csn|db0-db3);
* STARTUP_IO: None
* ip2intc_inpt: None

SDK
------------
*BSP: xilisf
  * serial_flash_family: 5(SPANSION|Micro);
  * serial_flash_interface: 1


MicroBlaze Debug Module
=========================
10.07, 2018

Configuration
---------------
* Enable JTAG UART;
* JTAG User Register: USER2;

  * When debugging: TCP Debug Virtual Terminal: MicroBlaze Debug Module at USER2

Interfaces
------------
Input
^^^^^^^
* S_AXI --> AXI InterConnect;
* clk/aresetn: as QSPI;

  * When JTAG UART is enabled;

Output
^^^^^^^^
* Debug_sys_rst -->  mb_debug_sys_rst (Processor System Reset), to reset MB CPU;
* MB_DEBUG0 --> DEBUG, to out binary into MB CPU;

**Notes**:

* When Output pins are not connected, SDK can ``run`` program, but no message return;


First MicroBlaze in Video Board
==================================
10.05, 2018
* MicroBlaze  
   * Linux with MMU
   
      * MMU Memory Management: Virtual (None/UserMode/Protection)
   * 32K ILMB and DLMB BRAM;
   
* Clocking Wizard:
   * clk_out2: 200MHz (DDR3 use 4:1, work on 800MHz);
   * Change ``Reset`` to Active Low;

* AXI Timer
   * Connect to Concate, which connect INTC;

* AXI UARTLITE (from ``Board`` tab)
   * Connect to Concat2;

* MIG 7 Series (from ``Board`` tab)
   * ``sys_rst`` connect to ``Reset``;
   * ``sys_clk_i`` connect to ``clk_out2`` of Clocking Wizard;
   
  
