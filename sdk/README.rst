SDK readme
####################################
Nov.5, 2018

Hardware Software Interface (HSI) and XSCT
===========================================

Create workspace, hardware project, BSP project and app project

refer to `createSwProject.tcl`_

Create Device Tree 
---------------------

Create Device Tree source
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Clone xilinx device repository in directory of 'repo':

::

  git clone https://github.com/Xilinx/device-tree-xlnx


Add new repositary

::
  
  set_repo_path  ./repo  : set repository in SDK
  
  repo -os : display device_tree is one of the OSes


After that, SDK/SXCT can create a BSP project of 'device_tree'


Create Binary of Device Tree
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Device Tree Compiler(DTC)

::

  git clone https://git.kernel.org/pub/scm/utils/dtc/dtc.git
  make

  dtc -I dts -O dtb -o dt/system-top.dtb dt/system-top.dts


Simulation with QEMU
=============================

::

  qemu-system-microblazeel -M microblaze-fdt-plnx -m 256 -serial mon:stdio -display none -hw-dtb ../system-top.dtb -kernel /media/sf_vivados/v/xsct/sdkVideo/workspace/hello/Debug/hello.elf

microblaze-fdt       Microblaze device tree driven machine model
microblaze-fdt-plnx  Microblaze device tree driven machine model for PetaLinux
none                 empty machine
petalogix-ml605      PetaLogix linux refdesign for xilinx ml605 little endian
petalogix-s3adsp1800 PetaLogix linux refdesign for xilinx Spartan 3ADSP1800 (default)


.. _a link: createSwProject.tcl
