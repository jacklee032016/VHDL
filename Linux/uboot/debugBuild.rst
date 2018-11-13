
Once U-Boot has been loaded, pause the execution using XSDB and use the dow command to load the images into the targets memory. Once the images are loaded continue the execution and return to the U-Boot console.
MicroBlaze (kc705-microblazeel):

xsdb% stop
xsdb% dow -data linux.bin.ub 0x85000000
xsdb% dow -data core-image-minimal-kc705-microblazeel.cpio.gz.u-boot 0x86000000
xsdb% dow -data kc705-microblazeel.dtb 0x84000000
xsdb% con

U-Boot> bootm 0x85000000 0x86000000 0x84000000


bootgen -arch fpga -image u-boot.elf -w -o BOOT.bin  -interface spi 


petalinux-package --boot --fsbl <FSBL_ELF> --fpga <BITSTREAM> --uboot
It will generate a BOOT.BIN in your working directory with:
* specified <BITSTREAM>
* specified <FSBL_ELF>
* newly built u-boot image which is <PROJECT>/images/linux/u-boot.elf


Create MMI file from hardware definition (hdf)



Build process:
---------------
11,11, 2018

::

	./scripts/check-config.sh u-boot.cfg ./scripts/config_whitelist.txt .
	Error: You must add new CONFIG options using Kconfig
	The following new ad-hoc CONFIG options were detected:
	CONFIG_SYS_NO_FLASH

**Resolution**:
This is correct option, means without parrllel flash (NOR flash), which is created by scritp;

Add this option in config_whitelist.txt in sort order, then everything is OK;


Create binary for Hello example: too big for binary
------------------------------------------------------


