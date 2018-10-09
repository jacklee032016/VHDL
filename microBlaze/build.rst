Toolchains and Build for MicroBlaze
#######################################

Standardalone Program
=======================

Compile:
---------------
::

	-Wall -O0 -g3 -c -fmessage-length=0  -Wl,--no-relax -ffunction-sections -fdata-sections
  -Wl,--gc-sections 
  
Place each function or data item into its own section in the output file if the target supports arbitrary sections. The name of the function or the name of the data item determines the section's name in the output file. 
	 -Wl,--gc-sections to remove unused sections in file

::

	-fmessage-length=n
       Try to format error messages so that they fit on lines of about n characters.  The default is 72 characters for g++ and 0 for the rest of the front ends supported by GCC.  If n is
       zero, then no line-wrapping will be done; each error message will appear on a single line.
	
Hardware design:

::

	-mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mno-xl-soft-div -mcpu=v10.0 -mno-xl-soft-mul -mxl-multiply-high  

	-I../../sboot_bsp/microblaze_0/include

mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"src/bootloader.o" -I../../sboot_bsp/microblaze_0/include -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mno-xl-soft-div -mcpu=v10.0 -mno-xl-soft-mul -mxl-multiply-high -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"src/bootloader.d" -MT"src/bootloader.o" -o "src/bootloader.o" "../src/bootloader.c"

mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"src/platform.o" -I../../sboot_bsp/microblaze_0/include -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mno-xl-soft-div -mcpu=v10.0 -mno-xl-soft-mul -mxl-multiply-high -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"src/platform.d" -MT"src/platform.o" -o "src/platform.o" "../src/platform.c"

mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"src/srec.o" -I../../sboot_bsp/microblaze_0/include -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mno-xl-soft-div -mcpu=v10.0 -mno-xl-soft-mul -mxl-multiply-high -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"src/srec.d" -MT"src/srec.o" -o "src/srec.o" "../src/srec.c"



Linking
-----------------

::

  mb-gcc -Wl,-T -Wl,../src/lscript.ld 
	  -L../../sboot_bsp/microblaze_0/lib 
	  -mlittle-endian -mxl-barrel-shift -mxl-pattern-compare -mno-xl-soft-div -mcpu=v10.0 -mno-xl-soft-mul -mxl-multiply-high 
	  -Wl,--no-relax -Wl,--gc-sections -o "sboot.elf"  
	  ./src/bootloader.o ./src/platform.o ./src/srec.o   -Wl,--start-group,-lxil,-lgcc,-lc,--end-group -Wl,--start-group,-lxilisf,-lxil,-lgcc,-lc,--end-group


Libraries: xil, gcc, c, xilisf


make -k clean 
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/bram_v4_2/src -s clean 
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/cpu_v2_6/src -s clean 
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/intc_v3_7/src -s clean 
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/spi_v4_3/src -s clean 
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/standalone_v6_5/src -s clean 
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/tmrctr_v4_4/src -s clean 
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/uartlite_v3_2/src -s clean 
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/xilisf_v5_9/src -s clean 
rm -f microblaze_0/lib/libxil.a

15:14:07 Build Finished (took 5s.85ms)

15:14:08 **** Build of project sboot_bsp ****
make -k all 
"Running Make include in microblaze_0/libsrc/bram_v4_2/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/bram_v4_2/src -s include  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Running Make include in microblaze_0/libsrc/cpu_v2_6/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/cpu_v2_6/src -s include  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Running Make include in microblaze_0/libsrc/intc_v3_7/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/intc_v3_7/src -s include  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Running Make include in microblaze_0/libsrc/spi_v4_3/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/spi_v4_3/src -s include  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Running Make include in microblaze_0/libsrc/standalone_v6_5/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/standalone_v6_5/src -s include  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Running Make include in microblaze_0/libsrc/tmrctr_v4_4/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/tmrctr_v4_4/src -s include  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Running Make include in microblaze_0/libsrc/uartlite_v3_2/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/uartlite_v3_2/src -s include  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Running Make include in microblaze_0/libsrc/xilisf_v5_9/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/xilisf_v5_9/src -s include  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Running Make libs in microblaze_0/libsrc/bram_v4_2/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/bram_v4_2/src -s libs  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Compiling bram"
mb-ar: creating ../../../lib/libxil.a


"Running Make libs in microblaze_0/libsrc/cpu_v2_6/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/cpu_v2_6/src -s libs  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Compiling cpu"

"Running Make libs in microblaze_0/libsrc/intc_v3_7/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/intc_v3_7/src -s libs  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Compiling intc"

"Running Make libs in microblaze_0/libsrc/spi_v4_3/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/spi_v4_3/src -s libs  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Compiling spi"

"Running Make libs in microblaze_0/libsrc/standalone_v6_5/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/standalone_v6_5/src -s libs  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Compiling standalone";

"Running Make libs in microblaze_0/libsrc/tmrctr_v4_4/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/tmrctr_v4_4/src -s libs  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Compiling tmrctr"

"Running Make libs in microblaze_0/libsrc/uartlite_v3_2/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/uartlite_v3_2/src -s libs  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Compiling uartlite"



"Running Make libs in microblaze_0/libsrc/xilisf_v5_9/src"
D:/Xilinx/SDK/2017.4/gnuwin/bin/make -C microblaze_0/libsrc/xilisf_v5_9/src -s libs  "SHELL=CMD" "COMPILER=mb-gcc" "ARCHIVER=mb-ar" "COMPILER_FLAGS= -O2 -c -mcpu=v10.0 -mlittle-endian -mno-xl-soft-div -mno-xl-soft-mul -mxl-barrel-shift -mxl-multiply-high -mxl-pattern-compare" "EXTRA_COMPILER_FLAGS=-ffunction-sections -fdata-sections -Wall -Wextra"
"Compiling XilIsf Library"

xilisf.c: In function 'XIsf_RegisterInterface':
xilisf.c:1363:37: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
  InstancePtr->XIsf_Iface_SetOptions = XSpi_SetOptions;
                                     ^
xilisf.c:1364:41: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
  InstancePtr->XIsf_Iface_SetSlaveSelect = XSpi_SetSlaveSelect;
                                         ^
xilisf.c:1365:35: warning: assignment from incompatible pointer type [-Wincompatible-pointer-types]
  InstancePtr->XIsf_Iface_Transfer = XSpi_Transfer;
                                   ^
xilisf.c: In function 'GetRealAddr':
xilisf.c:2170:6: warning: unused variable 'LqspiCr' [-Wunused-variable]
  u32 LqspiCr;
      ^~~~~~~
xilisf.c:2168:29: warning: unused parameter 'QspiPtr' [-Wunused-parameter]
 u32 GetRealAddr(XIsf_Iface *QspiPtr, u32 Address)
                             ^~~~~~~
At top level:
xilisf.c:538:12: warning: 'XIsf_FCTIndex' defined but not used [-Wunused-variable]
 static u32 XIsf_FCTIndex;
            ^~~~~~~~~~~~~
xilisf_erase.c: In function 'SectorErase':
xilisf_erase.c:322:14: warning: unused variable 'ReadStatusCmd' [-Wunused-variable]
  u8 FSRFlag, ReadStatusCmd;
              ^~~~~~~~~~~~~
xilisf_erase.c:322:5: warning: unused variable 'FSRFlag' [-Wunused-variable]
  u8 FSRFlag, ReadStatusCmd;
     ^~~~~~~
xilisf_erase.c:321:6: warning: unused variable 'WriteBfrPtr' [-Wunused-variable]
  u8 *WriteBfrPtr = InstancePtr->WriteBufPtr;
      ^~~~~~~~~~~
xilisf_erase.c:320:5: warning: unused variable 'ReadFlagSRCmd' [-Wunused-variable]
  u8 ReadFlagSRCmd[] = {READ_FLAG_STATUS_CMD, 0};
     ^~~~~~~~~~~~~
xilisf_erase.c:319:5: warning: unused variable 'ReadStatusCmdBuf' [-Wunused-variable]
  u8 ReadStatusCmdBuf[] = { READ_STATUS_CMD, 0 };
     ^~~~~~~~~~~~~~~~
xilisf_erase.c:318:5: warning: unused variable 'FlashStatus' [-Wunused-variable]
  u8 FlashStatus[2] = {0};
     ^~~~~~~~~~~
xilisf_erase.c:317:5: warning: unused variable 'FlagStatus' [-Wunused-variable]
  u8 FlagStatus[2] = {0};
     ^~~~~~~~~~
xilisf_erase.c:314:6: warning: unused variable 'BankSel' [-Wunused-variable]
  u32 BankSel;
      ^~~~~~~
xilisf_erase.c:313:5: warning: unused variable 'Mode' [-Wunused-variable]
  u8 Mode;
     ^~~~
xilisf_erase.c: In function 'SubSectorErase':
xilisf_erase.c:566:14: warning: unused variable 'ReadStatusCmd' [-Wunused-variable]
  u8 FSRFlag, ReadStatusCmd;
              ^~~~~~~~~~~~~
xilisf_erase.c:566:5: warning: unused variable 'FSRFlag' [-Wunused-variable]
  u8 FSRFlag, ReadStatusCmd;
     ^~~~~~~
xilisf_erase.c:565:6: warning: unused variable 'WriteBfrPtr' [-Wunused-variable]
  u8 *WriteBfrPtr = InstancePtr->WriteBufPtr;
      ^~~~~~~~~~~
xilisf_erase.c:564:5: warning: unused variable 'ReadFlagSRCmd' [-Wunused-variable]
  u8 ReadFlagSRCmd[] = {READ_FLAG_STATUS_CMD, 0};
     ^~~~~~~~~~~~~
xilisf_erase.c:563:5: warning: unused variable 'ReadStatusCmdBuf' [-Wunused-variable]
  u8 ReadStatusCmdBuf[] = { READ_STATUS_CMD, 0 };
     ^~~~~~~~~~~~~~~~
xilisf_erase.c:562:5: warning: unused variable 'FlashStatus' [-Wunused-variable]
  u8 FlashStatus[2] = {0};
     ^~~~~~~~~~~
xilisf_erase.c:561:5: warning: unused variable 'FlagStatus' [-Wunused-variable]
  u8 FlagStatus[2] = {0};
     ^~~~~~~~~~
xilisf_erase.c:558:6: warning: unused variable 'BankSel' [-Wunused-variable]
  u32 BankSel;
      ^~~~~~~
xilisf_erase.c:557:5: warning: unused variable 'Mode' [-Wunused-variable]
  u8 Mode;
     ^~~~
xilisf_read.c: In function 'ReadData':
xilisf_read.c:434:6: warning: unused variable 'TempByteCnt' [-Wunused-variable]
  u32 TempByteCnt = LocalByteCnt;
      ^~~~~~~~~~~
xilisf_read.c:430:5: warning: unused variable 'ShiftSize' [-Wunused-variable]
  u8 ShiftSize;
     ^~~~~~~~~
xilisf_read.c:429:6: warning: unused variable 'BufferIndex' [-Wunused-variable]
  u32 BufferIndex;
      ^~~~~~~~~~~
xilisf_read.c:425:6: warning: unused variable 'BankSel' [-Wunused-variable]
  u32 BankSel;
      ^~~~~~~
xilisf_read.c:424:5: warning: unused variable 'Mode' [-Wunused-variable]
  u8 Mode;
     ^~~~
xilisf_read.c: In function 'FastReadData':
xilisf_read.c:660:6: warning: unused variable 'TempByteCnt' [-Wunused-variable]
  u32 TempByteCnt = LocalByteCnt;
      ^~~~~~~~~~~
xilisf_read.c:656:5: warning: unused variable 'ShiftSize' [-Wunused-variable]
  u8 ShiftSize;
     ^~~~~~~~~
xilisf_read.c:655:6: warning: unused variable 'BufferIndex' [-Wunused-variable]
  u32 BufferIndex;
      ^~~~~~~~~~~
xilisf_read.c:652:6: warning: unused variable 'BankSel' [-Wunused-variable]
  u32 BankSel;
      ^~~~~~~
xilisf_read.c:649:5: warning: unused variable 'Mode' [-Wunused-variable]
  u8 Mode;
     ^~~~
xilisf_write.c: In function 'WriteData':
xilisf_write.c:451:5: warning: unused variable 'ReadFlagSRCmd' [-Wunused-variable]
  u8 ReadFlagSRCmd[] = {READ_FLAG_STATUS_CMD, 0};
     ^~~~~~~~~~~~~
xilisf_write.c:450:5: warning: unused variable 'ReadStatusCmdBuf' [-Wunused-variable]
  u8 ReadStatusCmdBuf[] = { READ_STATUS_CMD, 0 };
     ^~~~~~~~~~~~~~~~
xilisf_write.c:438:5: warning: unused variable 'FlashStatus' [-Wunused-variable]
  u8 FlashStatus[2] = {0};
     ^~~~~~~~~~~
xilisf_write.c:437:5: warning: unused variable 'FlagStatus' [-Wunused-variable]
  u8 FlagStatus[2] = {0};
     ^~~~~~~~~~
xilisf_write.c:434:6: warning: unused variable 'BankSel' [-Wunused-variable]
  u32 BankSel;
      ^~~~~~~
xilisf_write.c:432:5: warning: unused variable 'Mode' [-Wunused-variable]
  u8 Mode;
     ^~~~
'Finished building libraries'

15:14:13 Build Finished (took 5s.848ms)


Environment for Shell
=======================
D:/Xilinx/SDK/2017.4/tps/win64/jre/bin/server;
D:/Xilinx/SDK/2017.4/tps/win64/jre/bin;
D:/Xilinx/SDK/2017.4/tps/win64/jre/lib/amd64;

D:\Xilinx\SDK\2017.4\gnuwin\bin;

D:\Xilinx\SDK\2017.4\gnu\microblaze\nt\bin;
D:\Xilinx\SDK\2017.4\gnu\microblaze\linux_toolchain\nt64_le\bin;
D:\Xilinx\SDK\2017.4\gnu\microblaze\linux_toolchain\nt64_be\bin;

D:\Xilinx\SDK\2017.4\gnu\arm\nt\bin;

D:\Xilinx\SDK\2017.4\gnu\aarch64\nt\aarch64-none\bin;
D:\Xilinx\SDK\2017.4\gnu\aarch64\nt\aarch64-linux\bin;

D:\Xilinx\SDK\2017.4\gnu\armr5\nt\gcc-arm-none-eabi\bin;
D:\Xilinx\SDK\2017.4\gnu\aarch32\nt\gcc-arm-none-eabi\bin;
D:\Xilinx\SDK\2017.4\gnu\aarch32\nt\gcc-arm-linux-gnueabi\bin;

D:\Xilinx\SDK\2017.4\tps\win64\cmake-3.3.2\bin;;
D:\Xilinx\SDK\2017.4\bin;
D:\Xilinx\SDK\2017.4\lib\win64.o;
D:\Xilinx\SDK\2017.4\tps\win64\jre\bin\server;
D:\Xilinx\SDK\2017.4\tps\win64\jre\bin;


D:\Xilinx\Vivado\2017.4\ids_lite\ISE\bin\nt64;
D:\Xilinx\Vivado\2017.4\ids_lite\ISE\lib\nt64;
D:\Xilinx\Vivado\2017.4\bin;
D:\Xilinx\Vivado\2017.4\lib\win64.o;
D:\Xilinx\Vivado\2017.4\tps\win64\jre\bin\server;
D:\Xilinx\Vivado\2017.4\tps\win64\jre\bin;
