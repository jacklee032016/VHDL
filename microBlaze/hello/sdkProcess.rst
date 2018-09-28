make all 
'Building file: ../src/helloworld.c'
'Invoking: MicroBlaze gcc compiler'
mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"src/helloworld.o" -I../../hello_bsp/microblaze_0/include -mlittle-endian -mcpu=v10.0 -mxl-soft-mul -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"src/helloworld.d" -MT"src/helloworld.o" -o "src/helloworld.o" "../src/helloworld.c"
'Finished building: ../src/helloworld.c'
' '
'Building file: ../src/platform.c'
'Invoking: MicroBlaze gcc compiler'
mb-gcc -Wall -O0 -g3 -c -fmessage-length=0 -MT"src/platform.o" -I../../hello_bsp/microblaze_0/include -mlittle-endian -mcpu=v10.0 -mxl-soft-mul -Wl,--no-relax -ffunction-sections -fdata-sections -MMD -MP -MF"src/platform.d" -MT"src/platform.o" -o "src/platform.o" "../src/platform.c"
'Finished building: ../src/platform.c'
' '
'Building target: hello.elf'
'Invoking: MicroBlaze gcc linker'
mb-gcc -Wl,-T -Wl,../src/lscript.ld -L../../hello_bsp/microblaze_0/lib -mlittle-endian -mcpu=v10.0 -mxl-soft-mul -Wl,--no-relax -Wl,--gc-sections -o "hello.elf"  ./src/helloworld.o ./src/platform.o   -Wl,--start-group,-lxil,-lgcc,-lc,--end-group
'Finished building target: hello.elf'
' '
'Invoking: MicroBlaze Print Size'
mb-size hello.elf  |tee "hello.elf.size"
   text	   data	    bss	    dec	    hex	filename
   2748	    268	   3112	   6128	   17f0	hello.elf
'Finished building: hello.elf.size'
' '

10:51:14 Build Finished (took 1s.22ms)


cmd /C updatemem -force -meminfo \
D:/vivado/projects/mbHello/mbHello.sdk/mb767_board_hw_platform_0/mb767_board.mmi -bit \
D:/vivado/projects/mbHello/mbHello.sdk/mb767_board_hw_platform_0/mb767_board.bit -data \
D:/Xilinx/SDK/2017.4/data/embeddedsw/lib/microblaze/mb_bootloop_le.elf -proc \
processor/firstMB_i/microblaze_0 -out \
D:/vivado/projects/mbHello/mbHello.sdk/mb767_board_hw_platform_0/download.bit 

****** updatemem v2017.4 (64-bit)
  **** SW Build 2086221 on Fri Dec 15 20:55:39 MST 2017
    ** Copyright 1986-2017 Xilinx, Inc. All Rights Reserved.

source D:/Xilinx/SDK/2017.4/scripts/updatemem/main.tcl -notrace
 Loading bitfile D:/vivado/projects/mbHello/mbHello.sdk/mb767_board_hw_platform_0/mb767_board.bit
Loading data files...
Updating memory content...
Creating bitstream...
Bitstream compression saved 24584224 bits.
Writing bitstream D:/vivado/projects/mbHello/mbHello.sdk/mb767_board_hw_platform_0/download.bit...
  update_mem: Time (s): cpu = 00:00:11 ; elapsed = 00:00:12 . Memory (MB): peak = 488.602 ; gain = 434.531
INFO: [Common 17-206] Exiting updatemem at Fri Sep 28 16:30:56 2018...
