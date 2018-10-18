Run ELF of MicroBlaze in QEMU
###################################
Oct.16, 2018


From hdf to DTB
==================

hdf file to DTS
-----------------

::

  git clone https://github.com/Xilinx/device-tree-xlnx

  proc gen_dtb {hdf} {
     open_hw_design $hdf
     set_repo_path ./repo
     create_sw_design device-tree -os device_tree -proc microblaze_0
     generate_target -dir my_dts
  }

create DTS file in SDK
---------------------------
Create a project of BSP for Device Tree;

From DTS to DTB
--------------------------

::

  git clone https://git.kernel.org/pub/scm/utils/dtc/dtc.git
  make

  dtc -I dts -O dtb -o dt/system-top.dtb dt/system-top.dts

QEMU
-----

::

   ./configure --target-list="microblazeel-softmmu" && make


Run with QEMU
================

Suggested Command-Line

::

 qemu-system-microblazeel -M microblaze-fdt-plnx -m 256 -serial mon:stdio -display none -dtb <path to dtb file> -kernel <path to kernel file>


Below is an example of booting a Linux ELF image on a MicroBlaze machine. The Linux kernel should start booting and a shell prompt should be displayed. Control A-X will exit QEMU.

::    

  qemu-system-microblazeel -M microblaze-fdt-plnx -m 256 -serial mon:stdio -display none -dtb system-top.dtb -kernel hello.elf    
    
  qemu-system-microblazeel -M microblaze-fdt-plnx -m 256 -serial mon:stdio -display none -hw-dtb system-top.dtb -kernel hello.elf

  qemu-system-microblazeel -M microblaze-fdt-plnx -m 256 -serial mon:stdio -display none -device loader,file=mb_bootloop_le.elf -gdb tcp::1137 -hw-dtb my_dts/system-top.dtb



Terms
========
MSS : Microprocessor Software Specification
MLD : Microprocessor Library Definition
MDD : Microprocessor Driver Definition

