
Run FS-BOOT
---------------

::

		FS-BOOT First Stage Bootloader (c) 2013-2014 Xilinx Inc.
		Build date: Nov  7 2018 15:38:33  
		Serial console: Uartlite
		FS-BOOT: No existing image in FLASH.
		FS-BOOT: Please download the image with JTAG.


Run u-boot
--------------

::

		U-Boot 2017.01 (Nov 07 2018 - 15:37:19 -0500)
		
		DRAM:  512 MiB
		SF: Detected s25fl256s_64k with page size 256 Bytes, erase size 64 KiB, total 32 MiB
		*** Warning - bad CRC, using default environment
		
		In:    serial
		Out:   serial
		Err:   serial
		Net:   AXI EMAC: 40c00000, phyaddr -1, interface rgmii
		eth0: ethernet@40c00000
		U-BOOT for first
		
		Hardware exception at 0x4040100c address
		Return address from exception 0x8001eccc
		Data bus error exception
		Unaligned word access
		Unaligned load access
		Register R0
		### ERROR ### Please RESET the board ###


Run image.elf: dow image.elf
------------------------------

::

		Ramdisk addr 0x00000000, 
		Compiled-in FDT at c03c8560
		Linux version 4.9.0-xilinx-v2017.4 (lzj@lzj-Ubuntu) (gcc version 6.2.0 (crosstool-NG 1.20.0) ) #4 Wed Nov 7 15:35:40 EST 2018
		setup_cpuinfo: initialising
		setup_cpuinfo: Using full CPU PVR support
		wt_msr_noirq
		setup_memory: max_mapnr: 0x20000
		setup_memory: min_low_pfn: 0x80000
		setup_memory: max_low_pfn: 0xa0000
		setup_memory: max_pfn: 0xa0000
		Zone ranges:
		  DMA      [mem 0x0000000080000000-0x000000009fffffff]
		  Normal   empty
		  HighMem  empty
		Movable zone start for each node
		Early memory node ranges
		  node   0: [mem 0x0000000080000000-0x000000009fffffff]
		Initmem setup node 0 [mem 0x0000000080000000-0x000000009fffffff]
		On node 0 totalpages: 131072
		free_area_init_node: node 0, pgdat c050a13c, node_mem_map c0a81000
		  DMA zone: 1024 pages used for memmap
		  DMA zone: 0 pages reserved
		  DMA zone: 131072 pages, LIFO batch:31
		pcpu-alloc: s0 r0 d32768 u32768 alloc=1*32768
		pcpu-alloc: [0] 0 
		Built 1 zonelists in Zone order, mobility grouping on.  Total pages: 130048
		Kernel command line: console=ttyUL0,115200 earlyprintk
		PID hash table entries: 2048 (order: 1, 8192 bytes)
		Dentry cache hash table entries: 65536 (order: 6, 262144 bytes)
		Inode-cache hash table entries: 32768 (order: 5, 131072 bytes)
		Memory: 508484K/524288K available (3873K kernel code, 137K rwdata, 1112K rodata, 4982K init, 576K bss, 15804K reserved, 0K cma-reserved, 0K highmem)
		Kernel virtual memory layout:
		  * 0xfffea000..0xfffff000  : fixmap
		  * 0xff800000..0xffc00000  : highmem PTEs
		  * 0xff800000..0xff800000  : early ioremap
		  * 0xf0000000..0xff800000  : vmalloc & ioremap
		NR_IRQS:33
		/amba_pl/interrupt-controller@41200000: num_irq=6, edge=0x22
		/amba_pl/timer@41c00000: irq=1
		clocksource: xilinx_clocksource: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 19112604467 ns
		xilinx_timer_shutdown
		xilinx_timer_set_periodic
		sched_clock: 32 bits at 100MHz, resolution 10ns, wraps every 21474836475ns
		Calibrating delay loop... 49.15 BogoMIPS (lpj=245760)
		pid_max: default: 4096 minimum: 301
		Mount-cache hash table entries: 1024 (order: 0, 4096 bytes)
		Mountpoint-cache hash table entries: 1024 (order: 0, 4096 bytes)
		devtmpfs: initialized
		clocksource: jiffies: mask: 0xffffffff max_cycles: 0xffffffff, max_idle_ns: 19112604462750000 ns
		NET: Registered protocol family 16
		PCI: Probing PCI hardware
		vgaarb: loaded
		clocksource: Switched to clocksource xilinx_clocksource
		NET: Registered protocol family 2
		TCP established hash table entries: 4096 (order: 2, 16384 bytes)
		TCP bind hash table entries: 4096 (order: 4, 81920 bytes)
		TCP: Hash tables configured (established 4096 bind 4096)
		UDP hash table entries: 256 (order: 1, 12288 bytes)
		UDP-Lite hash table entries: 256 (order: 1, 12288 bytes)
		NET: Registered protocol family 1
		RPC: Registered named UNIX socket transport module.
		RPC: Registered udp transport module.
		RPC: Registered tcp transport module.
		RPC: Registered tcp NFSv4.1 backchannel transport module.
		PCI: CLS 0 bytes, default 32
		random: fast init done
		Skipping unavailable RESET gpio -2 (reset)
		futex hash table entries: 16 (order: -4, 448 bytes)
		audit: initializing netlink subsys (disabled)
		audit: type=2000 audit(12.800:1): initialized
		workingset: timestamp_bits=30 max_order=17 bucket_order=0
		romfs: ROMFS MTD (C) 2007 Red Hat, Inc.
		io scheduler noop registered
		io scheduler deadline registered
		io scheduler cfq registered (default)
		Serial: 8250/16550 driver, 4 ports, IRQ sharing disabled
		40600000.serial: ttyUL0 at MMIO 0x40600000 (irq = 6, base_baud = 0) is a uartlite
		console [ttyUL0] enabled
		brd: module loaded
		m25p80 spi0.0: SPI transfer timed out
		m25p80 spi0.0: error -110 reading 9f
		m25p80: probe of spi0.0 failed with error -110
		libphy: Fixed MDIO Bus: probed
		xilinx_axienet 40c00000.ethernet: TX_CSUM 0
		xilinx_axienet 40c00000.ethernet: RX_CSUM 0
		NET: Registered protocol family 17
		Key type encrypted registered
		Warning: unable to open an initial console.
		Freeing unused kernel memory: 4980K (c050c000 - c09e9000)
		This architecture does not have kernel memory protection.
		net eth0: Promiscuous mode disabled.
		net eth0: Promiscuous mode disabled.
		random: crng init done
		
		PetaLinux 2017.4 first /dev/ttyUL0
		
		first login: 

		