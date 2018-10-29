Hardware Design for AN767 Board
###################################

AXI ETHERNET Design
=============================
10.19, 2018

Problem and Debug
---------------------
* Only receive boardcast packets from ethernet switch;
* Peripheral tests: loop only in Marvel PHY;
* DMA TX Interrupt Handler correctly; 


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

