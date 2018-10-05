MicroBlaze Projects for Video Board
####################################
10.05, 2018

First MicroBlaze in Video Board
==================================
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
   
   