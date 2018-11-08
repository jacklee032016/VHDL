PetaLinux Startup
############################

Start PetaLinux
====================

::

    source PETA_HOME/settings.sh
    
    echo $PETALINUX



Create and build project from HDF 
=======================================

Create a project of microblaze
--------------------------------

::

  petalinux-create --type project --template microblaze --name first

  INFO: Create project: first
  INFO: New project successfully created in /media/sf_vivados/v/Linux/peta/first


Define HW description
------------------------

Only one hdf file exists in current working directory

::

  **petalinux-config --get-hw-description -p /media/sf_vivados/v/Linux/peta/first/**


  INFO: Getting hardware description...
  cp: omitting directory ¡®/media/sf_vivados/v/Linux/peta/first¡¯
  INFO: Rename videoSys.hdf to system.hdf
	[INFO] generating Kconfig for project
	                                                                                                                                                                                                             
	                                                                                                                                                                                                             
	INFO: Updating the flash partition size to 0x3e0000 bytes, based on the bitstream in the HDF
	[INFO] menuconfig project
	/media/sf_vivados/v/Linux/peta/first/build/misc/config/Kconfig.syshw:30:warning: defaults for choice values not supported
	/media/sf_vivados/v/Linux/peta/first/build/misc/config/Kconfig:568:warning: config symbol defined without type
	configuration written to /media/sf_vivados/v/Linux/peta/first/project-spec/configs/config
	
	*** End of the configuration.
	*** Execute 'make' to start the build or try 'make help'.
	
	[INFO] sourcing bitbake
	[INFO] generating plnxtool conf
	[INFO] generating meta-plnx-generated layer
	/media/sf_vivados/v/Linux/peta/first/build/misc/plnx-generated /media/sf_vivados/v/Linux/peta
	/media/sf_vivados/v/Linux/peta
	[INFO] generating machine configuration
	[INFO] generating bbappends for project . This may take time ! 
	/media/sf_vivados/v/Linux/peta/first/build/misc/plnx-generated /media/sf_vivados/v/Linux/peta
	/media/sf_vivados/v/Linux/peta
	[INFO] generating u-boot configuration files
	                                                                                                                                                                                                             
	[INFO] generating kernel configuration files
	[INFO] generating kconfig for Rootfs
	Generate rootfs kconfig
	[INFO] oldconfig rootfs
	[INFO] generating petalinux-user-image.bb
	


Build u-boot
---------------------

::

   petalinux-build -c u-boot -v

		[INFO] building u-boot
		[INFO] sourcing bitbake
		INFO: bitbake virtual/bootloader
		WARNING: /opt/peta/components/yocto/source/microblaze_full/layers/meta-virtualization/recipes-networking/netns/netns_git.bb: cannot map 'microblazeel' to a Go architecture                  | ETA:  --:--:--
		WARNING: /opt/peta/components/yocto/source/microblaze_full/layers/meta-virtualization/recipes-devtools/go-cross/go-cross_1.6.bb: cannot map 'microblazeel' to a Go architecture               | ETA:  0:04:27
		WARNING: /opt/peta/components/yocto/source/microblaze_full/layers/meta-virtualization/recipes-devtools/go-cross/go-cross_1.5.bb: cannot map 'microblazeel' to a Go architecture
		WARNING: /opt/peta/components/yocto/source/microblaze_full/layers/meta-virtualization/recipes-containers/runc/runc_git.bb: cannot map 'microblazeel' to a Go architecture
		WARNING: /opt/peta/components/yocto/source/microblaze_full/layers/meta-gnome/recipes-gnome/libart-lgpl/libart-lgpl_2.3.21.bb: Unable to get checksum for libart-lgpl SRC_URI entry art_config.h: file could not be found
		Parsing recipes: 100% |#######################################################################################################################################################################| Time: 0:04:29
		Parsing of 2466 .bb files complete (0 cached, 2466 parsed). 3259 targets, 552 skipped, 0 masked, 0 errors.
		NOTE: Resolving any missing task queue dependencies
		Initialising tasks: 100% |####################################################################################################################################################################| Time: 0:00:17
		Checking sstate mirror object availability: 100% |############################################################################################################################################| Time: 0:00:28
		NOTE: Executing SetScene Tasks
		NOTE: Executing RunQueue Tasks
		fs-boot-2017.4+gitAUTOINC+77448ae629-r0 do_compile: NOTE: fs-boot: compiling from external source tree /opt/peta/tools/hsm/data/embeddedsw
		NOTE: Tasks Summary: Attempted 2031 tasks of which 1531 didn't need to be rerun and all succeeded.
		
		Summary: There were 5 WARNING messages shown.
		INFO: Copying Images from deploy to images
		INFO: Creating images/linux directory
		NOTE: Failed to copy built images to tftp dir:  /tftpboot
		[INFO] successfully built u-boot


Run in QEMU
--------------

::

   petalinux-boot --qemu --u-boot




Use of Prebuilt Image
=============================

Create a project from prebuild BSP
-------------------------------------

::

  petalinux-create --type project --source ../bsp/xilinx-zc702-v2018.2-final.bsp

A directory of ``xilinx-zc702-2018.2`` is created in working directory, sub-directory of ``pre-built`` contains images;


Run image from pre-built BSP:

::

	cd xilinx-zc702-2018.2
	petalinux-boot --qemu --prebuilt 3

