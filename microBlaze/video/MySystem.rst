My System (Hardware and Software) of Nexys Video Board
########################################################
10.18, 2018

Ethernet
====================

Hardware Design
------------------

Ethernet
^^^^^^^^^^^^^^
* AXI_ETHERNET + AXI_DMA;
* Connect Interrupt pins to INTR;


Software
---------------

Flow
^^^^^^^

* xemac_add_if(): call netif driver provided by lwip network driver;
* MAC initializing : MAC initialize and netif;
* low_level_init() : PHY and input/output interface, provided by lwip network driver;
   * init_axiemac():
       * phy_setup() --> phy_bus_position, phy_speed negotiation, phy_speed etc;

* PHY Driver
   * provided from Lwip Netowrk driver;
   * not support RTL8211 (PHY_ID and PHY Module from PHY registers);
   * Nogotiation may fails, speed setup fails: network works still;


* xaxi_ethernet driver
  * MAC control, registers of MAC controller;
  * PHY accesss interface: phyRead()/phyWrite(), from MDIO interface;

