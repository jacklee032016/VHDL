U-Boot for MicroBlaze
############################
10.18, 2018


The devices that have been tested include UART lite, UART 16550, Linear flash, EMAC lite, LL TEMAC with PLB DMA, and AXI EMAC with AXI DMA. The timer counter and interrupt controller were also tested.
Tests were done on Spartan 605 (PLB and AXI) and Kintex 705 (AXI) evaluation platforms using XPS 14.2 and 14.3.

flash : NOR flash
spi : 	spi/qspi flashes
i2c : 	i2c controller
ethernet lite : 	EMAC lite
ethernet : AXI EMAC with AXI DMA


u-boot repository:
=====================

   https://github.com/Xilinx/u-boot-xlnx.git


Configuration
====================

::

  make microblaze-generic_defconfig


	board/xilinx/microblaze-generic/xparameters.h
	board/xilinx/microblaze-generic/config.mk

	include/configs/microblaze-generic.h
	arch/microblaze/dts/microblaze-generic.dts

	Replace the dts file of u-boot-xlnx via petalinux project. Convert the .dtb file into .dts file in petalinux project

   dtc -I dtb -O dts -o <plnx-proj-root>/components/plnx_workspace/device-tree/device-tree-generation/plnx_microblaze-system.dts

  Renamed this generated dts file to microblaze-generic.dts and copy it to the u-boot-xlnx
    
    <plnx-proj-root>/components/plnx_workspace/device-tree/device-tree-generation/microblaze-generic.dts
    cp <plnx-proj-root>/components/plnx_workspace/device-tree/device-tree-generation/microblaze-generic.dts u-boot-xlnx/arch/microblaze/dts


Make
=============

::

	make distclean
	export CROSS_COMPILE=microblazeel-xilinx-linux-gnu-
	export ARCH=microblazeel
	make microblaze-generic_defconfig
	scripts/kconfig/merge_config.sh -m .config  <plnx-proj-root >/project-spec/meta-plnx-generated/recipes-bsp/u-boot/configs/config.cfg
	make

	