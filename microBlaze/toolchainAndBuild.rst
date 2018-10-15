Toolchain and Link for MicroBlaze
########################################



Specs for ToolChains
========================
Find specs of toolchains

::

  mb-gcc -dumpspecs > specs.txt


Multilib for toolchains
--------------------------

::

  *multilib:
    . !mxl-barrel-shift !mno-xl-soft-mul !mxl-multiply-high !mlittle-endian;
    bs mxl-barrel-shift !mno-xl-soft-mul !mxl-multiply-high !mlittle-endian;
    m !mxl-barrel-shift mno-xl-soft-mul !mxl-multiply-high !mlittle-endian;
    le !mxl-barrel-shift !mno-xl-soft-mul !mxl-multiply-high mlittle-endian;
    m/mh !mxl-barrel-shift mno-xl-soft-mul mxl-multiply-high !mlittle-endian;
    m/le !mxl-barrel-shift mno-xl-soft-mul !mxl-multiply-high mlittle-endian;
    m/mh/le !mxl-barrel-shift mno-xl-soft-mul mxl-multiply-high mlittle-endian;
    bs/m mxl-barrel-shift mno-xl-soft-mul !mxl-multiply-high !mlittle-endian;
    bs/le mxl-barrel-shift !mno-xl-soft-mul !mxl-multiply-high mlittle-endian;
    bs/m/mh mxl-barrel-shift mno-xl-soft-mul mxl-multiply-high !mlittle-endian;
    bs/m/le mxl-barrel-shift mno-xl-soft-mul !mxl-multiply-high mlittle-endian;
    bs/m/mh/le mxl-barrel-shift mno-xl-soft-mul mxl-multiply-high mlittle-endian;

So, 4 options: barrel-shift, soft-mul, multiply-high, little-endian


Link for Standalone Program
-----------------------------

::

  *startfile_executable:
      crt0.o%s crti.o%s crtbegin.o%s

  *startfile_crtinit:
      %{!pg: %{!mno-clearbss: crtinit.o%s} %{mno-clearbss: sim-crtinit.o%s}} %{pg: %{!mno-clearbss: pgcrtinit.o%s} %{mno-clearbss: sim-pgcrtinit.o%s}}

Link process

::
  
  crt0.o crti.o crtbegin.o crtinit.o
  user.o and library
  crtend.o crtn.o 
  
Refer to code for MicroBlaze;

crt0.o : initialize vector table of 4 items;
crtinit.o : initialize BSS, and call main directly  



Video Board
-------------

Video Demo is build with ``bs/m/le/``, eg, '-mlittle-endian' '-mxl-barrel-shift' '-mno-xl-soft-mul';

Other options for Video Demo is '-mxl-pattern-compare' '-mcpu=v9.4' ;

So, binary code for my video hardware is not compatible with Video Demo;



Link Info
==================

::

  Using built-in specs.
  COLLECT_GCC=d:\Xilinx\SDK\2017.4\gnu\microblaze\nt\bin\mb-gcc.exe

  COLLECT_LTO_WRAPPER=d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../libexec/gcc/microblaze-xilinx-elf/6.2.0/lto-wrapper.exe
  Target: microblaze-xilinx-elf

  Configured with: /proj/sdk/gnu/microblaze/builds/HEAD/nightly/2017_11_15/rdi_scripts/../build/nt/ctng_bld/target_build/src/gcc-custom/configure 
     --build=i686-build_pc-linux-gnu 
     --host=i686-host_w64-mingw32 
     --target=microblaze-xilinx-elf 
     --prefix=/proj/sdk/gnu/microblaze/builds/HEAD/nightly/2017_11_15/rdi_scripts/../build/nt/ctng_output 
     --with-local-prefix=/proj/sdk/gnu/microblaze/builds/HEAD/nightly/2017_11_15/rdi_scripts/../build/nt/ctng_output/microblaze-xilinx-elf/sysroot 
     --disable-libmudflap 
     --with-sysroot=/proj/sdk/gnu/microblaze/builds/HEAD/nightly/2017_11_15/rdi_scripts/../build/nt/ctng_output/microblaze-xilinx-elf/sysroot 
     --with-newlib 
     --enable-threads=no 
     --disable-shared 
     --with-pkgversion='crosstool-NG 1.20.0' 
     --disable-__cxa_atexit 
     --with-gmp=/proj/sdk/gnu/microblaze/builds/HEAD/nightly/2017_11_15/rdi_scripts/../build/nt/ctng_bld/target_build/microblaze-xilinx-elf/buildtools/complibs-host 
     --with-mpfr=/proj/sdk/gnu/microblaze/builds/HEAD/nightly/2017_11_15/rdi_scripts/../build/nt/ctng_bld/target_build/microblaze-xilinx-elf/buildtools/complibs-host 
     --with-mpc=/proj/sdk/gnu/microblaze/builds/HEAD/nightly/2017_11_15/rdi_scripts/../build/nt/ctng_bld/target_build/microblaze-xilinx-elf/buildtools/complibs-host 
     --with-ppl=no 
     --with-isl=no 
     --with-cloog=no 
     --with-libelf=/proj/sdk/gnu/microblaze/builds/HEAD/nightly/2017_11_15/rdi_scripts/../build/nt/ctng_bld/target_build/microblaze-xilinx-elf/buildtools/complibs-host 
     --enable-lto 
     --enable-target-optspace 
     --without-long-double-128 
     --disable-libgomp 
     --disable-libmudflap 
     --disable-nls 
     --disable-libstdcxx-pch 
     --enable-languages=c,c++
  Thread model: single
  gcc version 6.2.0 (crosstool-NG 1.20.0)

  COMPILER_PATH=
     d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../libexec/gcc/microblaze-xilinx-elf/6.2.0/;
     d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../libexec/gcc/;
     d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/../../../../microblaze-xilinx-elf/bin/

  LIBRARY_PATH=
     d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/bs/m/le/;
     d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/../../../../microblaze-xilinx-elf/lib/bs/m/le/;
     d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/;
     d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/;
     d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/../../../../microblaze-xilinx-elf/lib/


  COLLECT_GCC_OPTIONS='-v' '-L../../bist_bsp/microblaze_0/lib' '-mlittle-endian' '-mxl-barrel-shift' '-mxl-pattern-compare' '-mcpu=v9.4' '-mno-xl-soft-mul' '-o' 'bist.elf'

 d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../libexec/gcc/microblaze-xilinx-elf/6.2.0/collect2.exe 
      -plugin d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../libexec/gcc/microblaze-xilinx-elf/6.2.0/liblto_plugin-0.dll 
      -plugin-opt=d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../libexec/gcc/microblaze-xilinx-elf/6.2.0/lto-wrapper.exe 
      -plugin-opt=-fresolution=C:\Users\j.lee\AppData\Local\Temp\ccE6JWwn.res 
      -plugin-opt=-pass-through=-lgcc 
      -plugin-opt=-pass-through=-lgloss 
      -plugin-opt=-pass-through=-lxil 
      -plugin-opt=-pass-through=-lc 
      -plugin-opt=-pass-through=-lm 
      -plugin-opt=-pass-through=-lgcc 
 
      --sysroot=/proj/sdk/gnu/microblaze/builds/HEAD/nightly/2017_11_15/rdi_scripts/../build/nt/ctng_output/microblaze-xilinx-elf/sysroot 
      -N -relax -EL --oformat=elf32-microblazeel -G 0 
      -dT d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/../../../../microblaze-xilinx-elf/lib/xilinx.ld 
      -o bist.elf 
      
      d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/../../../../microblaze-xilinx-elf/lib/bs/m/le/crt0.o 
      d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/bs/m/le/crti.o 
      d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/bs/m/le/crtbegin.o 
      d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/../../../../microblaze-xilinx-elf/lib/bs/m/le/crtinit.o 
      -L../../bist_bsp/microblaze_0/lib 
      -Ld:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/bs/m/le 
      -Ld:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/../../../../microblaze-xilinx-elf/lib/bs/m/le 
      -Ld:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0 
      -Ld:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc 
      -Ld:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/../../../../microblaze-xilinx-elf/lib 
      
      -T ../src/lscript.ld 
      --no-relax --gc-sections 
      ./src/xadc/xadc.o 
      ./src/video/video.o 
      ./src/userio/userio.o 
      ./src/uart/uart.o 
      ./src/sd/sd.o 
      ./src/oled/oled.o 
      ./src/lwipdemo/echo.o 
      ./src/lwipdemo/eth.o 
      ./src/lwipdemo/i2c_access.o 
      ./src/lwipdemo/platform.o 
      ./src/lwipdemo/platform_mb.o 
      ./src/lwipdemo/platform_ppc.o 
      ./src/lwipdemo/platform_zynq.o 
      ./src/lwipdemo/sfp.o 
      ./src/lwipdemo/si5324.o 
      ./src/intc/intc.o 
      ./src/iic/iic.o 
      ./src/dp/displayport_lpm.o 
      ./src/dp/displayport_tx_drv.o 
      ./src/dp/dp.o 
      ./src/dp/xil_ccc_app.o 
     ./src/dp/xil_displayport.o 
     ./src/dp/xlib_string.o 
     ./src/audio/audio.o 
     ./src/main.o 
     
     --start-group -lxil -lgcc -lc --end-group 
     --start-group-lxil -llwip4 -lgcc -lc --end-group 
     -lgcc 
     -start-group -lgloss -lxil -lc -lm -end-group 
     -lgcc 
     
     d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/bs/m/le/crtend.o 
     d:/xilinx/sdk/2017.4/gnu/microblaze/nt/bin/../lib/gcc/microblaze-xilinx-elf/6.2.0/bs/m/le/crtn.o

     COLLECT_GCC_OPTIONS='-v' '-L../../bist_bsp/microblaze_0/lib' '-mlittle-endian' '-mxl-barrel-shift' '-mxl-pattern-compare' '-mcpu=v9.4' '-mno-xl-soft-mul' '-o' 'bist.elf'
     