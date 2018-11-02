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