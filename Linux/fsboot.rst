From FS-BOOT to u-boot
#############################


FS-BOOT
==============
Create relocable binary
-------------------------
**petalinux-reloc_blob** : petalinux/tools/components/scripts has been not usful; it is obselated now;

**mb-realoc.sh** : build asemble and create blob for it: add 0x10c(268) bytes header for binary;

    /*   
     * b8b40008 corresponds to the instruction "brlid r5, locator;"  
     * defined in the bootstub routine in petalinux-reloc-blob  
     * This allows us to check if a valid u-boot image is in FLASH.  
     * Note: any changes to the bootstub code will need to update this.   
     */   

::

   mb-realoc.sh -i uboot.elf -o uboot-s
   

create MCS file (by vivado) to program FPGA device

**petalinux-package --boot**


Create bit stream of FPGA+ELF
--------------------------------

::

   HW_NAME=vMicroBlaze_wrapper
   OUTPUT_DIR=output
   
   echo "Build download bitstream containing FSBL..."
   mkdir -p $OUTPUT_DIR
   
  updatemem -force -meminfo $HW_NAME.mmi -bit $HW_NAME.bit -data executable.elf -proc vMicroBlaze_i/microblaze_0 -out $OUTPUT_DIR/system.bit 



QEMU and FS-BOOT
==================

FS-Boot and QEMU
------------------
qemu can't run fs-boot.elf, other ELFs work fine:

fs-boot is load and run in BRAM, qemu can't initialize BRAM??

Link fs-boot to RAM, then it works;


Flash image
--------------

::

   dd if=/dev/zero of=qemu_qspi.bin bs=64M count=1
   dd if=uboot-s.bin of=qemu_qspi.bin bs=1 seek=0 conv=notrunc

QEMU simulates different QSPI:
-------------------------------
DTS file created by petalinux is different from XSCT, petalinux add partitions for serving u-boot, env, kernel and file system;

modify *.dts and rebuild *.dtb, change from 'n25q512a' to:

			flash@0 {
				compatible = "s25fl256s0", "s25fl256s1";

for spanion flash;

For the first one, ID is 0x20 BA 20; for Spanion, it is 0x01 02 19 4d

commands:

::

   qemu-system-microblazeel -M microblaze-fdt-plnx -m 256 -serial mon:stdio -display none -dtb ../images/system.dtb -kernel executable.elf  -pflash ../uboot-s.bin 

   qemu-system-microblazeel -M microblaze-fdt-plnx -m 256 -serial mon:stdio -display none -dtb ../tests/vSysTest.dtb -kernel executable.elf -drive file=../qemu_qspi.bin,if=mtd,format=raw,index=0 -boot mode=1


**Validation**

When following command:

   qemu-system-microblazeel -M microblaze-fdt-plnx -m 256 -serial mon:stdio -display none -dtb ../microblaze-generic.dtb -kernel executable.elf -drive file=../uboot-s.bin,if=mtd,format=raw,index=0 -boot mode=1
   qemu_fdt_check_phandle: Couldn't find phandle for /memory: <no error>Invalid MicroBlaze version number: (null)
   
   qemu-system-microblazeel: Initialization of device n25q512a failed: failed to read the initial flash content

So, qemu simulation of QSPI is good now.



Flash read for s25fl256
-------------------------

Flash read command: OPCODE_FAST_READ, 0x0b;

Using 5 bytes transfer, not 8 bytes transfer which is defined by xilinx IP core;

XSDK program_flash
=====================

Cable info

::

   program_flash -jtagtargets -cable 

   1. Cable ESN  : Digilent/210276723338/
     Device   ID Code        IR Length    Part Name
   2. Cable ESN  : Digilent/210276723338B/
     Device   ID Code        IR Length    Part Name
       1       13636093           6        xc7a200t

Program FPGA+CPU and u-boot

::

   program_flash -f ../download.bit -offset 0x00000 -flash_type s25fl256sxxxxxx0-spi-x1_x2_x4 -cable type xilinx_tcf url TCP:127.0.0.1:3121 

   program_flash -f ../uboot-s.bin -offset 0x500000 -flash_type s25fl256sxxxxxx0-spi-x1_x2_x4 -cable type xilinx_tcf url TCP:127.0.0.1:3121 

When programming the second part, the first part will not be erased, OK!
