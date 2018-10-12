MicroBlaze Projects for Video Board
####################################
10.05, 2018

Flash part:
	s25fl256xxxxxx0


XMD
---------
Can be used in XSCT console:

::
  
  xmd 
  connect mb mdm
  
 JTAG chain configuration
 --------------------------------------------------
 Device   ID Code        IR Length    Part Name
  1       13636093           6        xc7a200t

 MicroBlaze Processor Configuration :
 -------------------------------------
 Version............................0x24 - UnSupported Version
 Optimization.......................Performance
 Interconnect.......................AXI-LE
 MMU Type...........................Full_MMU
 No of PC Breakpoints...............1
 No of Read Addr/Data Watchpoints...0
 No of Write Addr/Data Watchpoints..0
 Instruction Cache Support..........on
 Instruction Cache Base Address.....0x80000000
 Instruction Cache High Address.....0x9fffffff
 Data Cache Support.................on
 Data Cache Base Address............0x80000000
 Data Cache High Address............0x9fffffff
 Exceptions  Support................on
 FPU  Support.......................off
 Hard Divider Support...............on
 Hard Multiplier Support............on - (Mul64)
 Barrel Shifter Support.............on
 MSR clr/set Instruction Support....on
 Compare Instruction Support........on
 PVR Supported......................on
 PVR Configuration Type.............Full
 Data Cache Write-back Support......off
 Fault Tolerance Support............off
 Stack Protection Support...........off

::

  dow sboot.elf
  con : run

  stop
  dow hello2.elf
  con


Baudrate
---------
Only change in hardware design; set as 115200;

Debugging for First MicroBlaze
==================================
ELF can't be run onboard with SDK
------------------------------------
Video can be programmed by vivado and SDK, but ``run`` alerts microblaze#0 can't be found.

* MDM, MicroBlzae Debug Module is not included in design block, so SDK can't found any device of MicroBlaze;
* Programming means FPGA chip and JTAG interface is found;
* Hello.elf is linked in address 0x0000,0000 in BRAM;
* Build hello.elf in release version, not debug version;
* Replace bootloop with hello.elf when programming FPGA in SDK;

**Notes:**

* Debug version of ELF also works in BRAM without debug support of HW:
  ** Debug version: GCC options, not the hardware options;
  
   