Hardware Design for AN767 Board
###################################

Only Receive boardcast packets, can't send to rtl8305H
========================================================

Switch chip
---------------
* Port 4: RJ45, 100M;
* Port 5: FPGA, RGMII interface, 1000M; only in this mode; 125MHz TX clock;
* Port 6: MCU, MII, 100M;

Controlled by MicroBlaze
^^^^^^^^^^^^^^^^^^^^^^^^^^
Failed: Speed, and configuration command;
* I2C Clock 100KHz; 400KHz (same as SAME70 MCU);
* with or without MII_COL and MII_CRS pins connectted to 0;


IP Cores
--------------
SGDMA, Scatter, Gather DMA,

IRQs:

* 4: ethernet subsystem; 
   * Pending IRQ, RxReject: recevied packets are rejected (dest for other NIC??);
   * Check TX packets statistics, works fine;
* 5: DMA RX, S2MM (Slave to Master Memory);
* 6: DMA TX, MM2S (Master Memory to Slave);
   * BD : Buffer Descriptor;
   * TxBDRing, RxBDRing;
* 7: MAC IRQ (TEMAC IRQ), related with MDIO interface; Not used;

ETH_CLK, 25MHz, is not used in AN767 design;

RGMII interface 1.3 and 2.0, support 2.0, 1.8V/2.5v;


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


[hwBspI2c.c-277.bspHwI2cInit()]: 
[hwBspI2c.c-283.bspHwI2cInit()]: 
[hwBspI2c.c-303.bspHwI2cInit()]: 
[hwBspI2c.c-305.bspHwI2cInit()]: 
[hwBspRtk.c-186._extConfigRtkOnePort()]: Configure port : 0, read status:
Before Configured, Port#0       10M     HALF_DUPLEX     LINK_DOWN       NWAY=0


[hwBspRtk.c-202._extConfigRtkOnePort()]:        set status
Port#0  10M     HALF_DUPLEX     LINK_DOWN       NWAY=0


Port 0 Status: speed:0, duplex:1; link:1; rxpause:0; txpause:0

         ERR:ERROR: [hwBspRtk.c-83._printPortState()]: port 0 mode ERROR, return : busy watting time out, 
[hwBspRtk.c-186._extConfigRtkOnePort()]: Configure port : 1, read status:
Before Configured, Port#1       10M     HALF_DUPLEX     LINK_DOWN       NWAY=0


[hwBspRtk.c-202._extConfigRtkOnePort()]:        set status
Port#1  10M     HALF_DUPLEX     LINK_DOWN       NWAY=0


Port 1 Status: speed:0, duplex:1; link:1; rxpause:0; txpause:0

         ERR:ERROR: [hwBspRtk.c-83._printPortState()]: port 1 mode ERROR, return : busy watting time out, 
[hwBspRtk.c-186._extConfigRtkOnePort()]: Configure port : 2, read status:
Before Configured, Port#2       10M     HALF_DUPLEX     LINK_UP NWAY=0


[hwBspRtk.c-202._extConfigRtkOnePort()]:        set status
Port#2  10M     HALF_DUPLEX     LINK_UP NWAY=0


Port 2 Status: speed:0, duplex:1; link:1; rxpause:0; txpause:0

         ERR:ERROR: [hwBspRtk.c-83._printPortState()]: port 2 mode ERROR, return : busy watting time out, 
[hwBspRtk.c-186._extConfigRtkOnePort()]: Configure port : 3, read status:
Before Configured, Port#3       10M     HALF_DUPLEX     LINK_UP NWAY=0


[hwBspRtk.c-202._extConfigRtkOnePort()]:        set status
Port#3  10M     HALF_DUPLEX     LINK_UP NWAY=0


Port 3 Status: speed:0, duplex:1; link:1; rxpause:0; txpause:0

         ERR:ERROR: [hwBspRtk.c-83._printPortState()]: port 3 mode ERROR, return : busy watting time out, 
[hwBspRtk.c-186._extConfigRtkOnePort()]: Configure port : 4, read status:
Before Configured, Port#4       10M     HALF_DUPLEX     LINK_DOWN       NWAY=1


[hwBspRtk.c-202._extConfigRtkOnePort()]:        set status
Port#4  10M     HALF_DUPLEX     LINK_DOWN       NWAY=1


Port 4 Status: speed:0, duplex:1; link:1; rxpause:0; txpause:0

         ERR:ERROR: [hwBspRtk.c-83._printPortState()]: port 4 mode ERROR, return : input parameter out of range, 
[hwBspRtk.c-186._extConfigRtkOnePort()]: Configure port : 5, read status:
Before Configured, Port#5       10M     HALF_DUPLEX     LINK_DOWN       NWAY=1


[hwBspRtk.c-202._extConfigRtkOnePort()]:        set status
         ERR:ERROR: [hwBspRtk.c-211._extConfigRtkOnePort()]: port 5 ERROR, return : functions not supported by this chip model, 
chipType:6, not suportPort#5    10M     HALF_DUPLEX     LINK_DOWN       NWAY=1


Port 5 Status: speed:0, duplex:1; link:1; rxpause:0; txpause:0

         ERR:ERROR: [hwBspRtk.c-83._printPortState()]: port 5 mode ERROR, return : functions not supported by this chip model, 
[hwBspRtk.c-186._extConfigRtkOnePort()]: Configure port : 6, read status:
chipType:1, not suportBefore Configured, Port#6 10M     HALF_DUPLEX     LINK_UP NWAY=1


[hwBspRtk.c-202._extConfigRtkOnePort()]:        set status
Port#6  10M     HALF_DUPLEX     LINK_UP NWAY=1


Port 6 Status: speed:0, duplex:1; link:1; rxpause:0; txpause:0

         ERR:ERROR: [hwBspRtk.c-83._printPortState()]: port 6 mode ERROR, return : invalid input parameter, 
Port#4 reset OK!


Port#5 reset OK!


Port#6 reset OK!


Port#4 start OK!


Port#5 start OK!


Port#6 start OK!