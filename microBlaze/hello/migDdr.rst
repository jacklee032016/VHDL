MIG DDR for AN767 Board
####################################
Sep.28, 2018

Video Board:

::

 Memory type : DDR3 SDRAM
 Max. clock period : 2500ps (800Mbps data rate)
 Clock ratio : 4:1
 Memory type : Components
 Memory part : MT41K256M16HA-125
 Memory voltage : 1.5V
 Data width : 16
 Data mask : Enabled
 Input clock period : 10000ps (100 MHz)
 Output driver impedance : RZQ/6
 Chip Select pin : Disabled
 Rtt (nominal) ¨C On-die termination : RZQ/6
 Internal Vref : Enabled
 Internal termination impedance : 50ohms

Parameters
 
::

  Clock Period: 3000ps (312.5Mhz), VCO Frequency: 625Mhz;
     For XC75 grade -2 chip: the clock period must be bigger than 2500 ps;
	 For Video board, 2500 ps is very good;
  Input Clock Period:  250Mhz (Change the ``clk-Out2`` in Clock Wizard)
     Options of Input Clock Period is based on the Clock Period, eg. based on the running frequency of DDR RAM chip;
	 For Video board, input clock period is 5000ps|200MHz;
	 Because the Clock Period is different, 5000ps|200Mhz is not in the options list;
	 
	 So first select the Input Clock Period, then configure clk_out2 of Clock Wizard as the same value;
	 
 
[Timing 38-282] The design failed to meet the timing requirements. Please see the timing summary report for details on the timing violations.
 

[DRC PDRC-34] MMCM_adv_ClkFrequency_div_no_dclk: The computed value 399.938 MHz (CLKIN1_PERIOD, net pll_clk3) for the VCO operating frequency of the MMCME2_ADV site MMCME2_ADV_X1Y2 (cell processor/firstMB_i/mig_7series_0/u_firstMB_mig_7series_0_0_mig/u_ddr3_infrastructure/gen_mmcm.mmcm_i) falls outside the operating range of the MMCM VCO frequency for this device (600.000 - 1440.000 MHz). The computed value is (CLKFBOUT_MULT_F * 1000 / (CLKINx_PERIOD * DIVCLK_DIVIDE)). Please run update_timing to update the MMCM settings. If that does not work, adjust either the input period CLKINx_PERIOD (20.003099), multiplication factor CLKFBOUT_MULT_F (8.000000) or the division factor DIVCLK_DIVIDE (1), in order to achieve a VCO frequency within the rated operating range for this device.

[DRC PDRC-43] PLL_adv_ClkFrequency_div_no_dclk: The computed value 399.938 MHz (CLKIN1_PERIOD, net clk_out2) for the VCO operating frequency of the PLLE2_ADV site PLLE2_ADV_X1Y2 (cell processor/firstMB_i/mig_7series_0/u_firstMB_mig_7series_0_0_mig/u_ddr3_infrastructure/plle2_i) falls outside the operating range of the PLL VCO frequency for this device (800.000 - 1866.000 MHz). The computed value is (CLKFBOUT_MULT_F * 1000 / (CLKINx_PERIOD * DIVCLK_DIVIDE)). Please adjust either the input period CLKINx_PERIOD (5.000775), multiplication factor CLKFBOUT_MULT_F (2) or the division factor DIVCLK_DIVIDE (1), in order to achieve a VCO frequency within the rated operating range for this device.



[DRC PDRC-34] MMCM_adv_ClkFrequency_div_no_dclk: The computed value 399.938 MHz (CLKIN1_PERIOD, net pll_clk3) for the VCO operating frequency of the MMCME2_ADV site MMCME2_ADV_X1Y2 
(cell processor/firstMB_i/mig_7series_0/u_firstMB_mig_7series_0_0_mig/u_ddr3_infrastructure/gen_mmcm.mmcm_i) 
falls outside the operating range of the MMCM VCO frequency for this device (600.000 - 1440.000 MHz). 
The computed value is (CLKFBOUT_MULT_F * 1000 / (CLKINx_PERIOD * DIVCLK_DIVIDE)). 
Please run update_timing to update the MMCM settings. 
If that does not work, adjust either the input period CLKINx_PERIOD (20.003099), multiplication factor CLKFBOUT_MULT_F (8.000000) or the division factor DIVCLK_DIVIDE (1), 
in order to achieve a VCO frequency within the rated operating range for this device.


::

  [Place 30-64] Illegal IOStandard configured for port 'CK_N'. I/O port 'CK_N' is differential, but has single-ended IOStandard value LVCMOS15.
  [Place 30-64] Illegal IOStandard configured for port 'CK_P'. I/O port 'CK_P' is differential, but has single-ended IOStandard value LVCMOS15.
  [Place 30-64] Illegal IOStandard configured for port 'DQS0_N'. I/O port 'DQS0_N' is differential, but has single-ended IOStandard value SSTL15.
  [Place 30-64] Illegal IOStandard configured for port 'DQS0_P'. I/O port 'DQS0_P' is differential, but has single-ended IOStandard value SSTL15.

  [Place 30-64] Illegal IOStandard configured for port 'DQS3_N'. I/O port 'DQS3_N' is differential, but has single-ended IOStandard value SSTL15.
  [Place 30-64] Illegal IOStandard configured for port 'DQS3_P'. I/O port 'DQS3_P' is differential, but has single-ended IOStandard value SSTL15.

  
Errors in Constraints File 
   
   io standard of these pins are defined as ``IOSTANDARD DIFF_SSTL15`` from ``SSTL15``;
   
   These definitions can be found in MIG design files;
  

::  
  
  [DRC MDRV-1] Multiple Driver Nets: 
  Net 
     processor/firstMB_i/mig_7series_0/u_firstMB_mig_7series_0_0_mig/u_memc_ui_top_axi/mem_intfc0/ddr_phy_top0/u_ddr_mc_phy_wrapper/u_ddr_mc_phy/ddr_phy_4lanes_0.u_ddr_phy_4lanes/ddr_byte_lane_D.ddr_byte_lane_D/ddr_ck_gen_loop[0].ddr_ck_gen.ddr_ck_obuf/OB
  has multiple drivers: 
   
     processor/firstMB_i/mig_7series_0/u_firstMB_mig_7series_0_0_mig/u_memc_ui_top_axi/mem_intfc0/ddr_phy_top0/u_ddr_mc_phy_wrapper/u_ddr_mc_phy/ddr_phy_4lanes_0.u_ddr_phy_4lanes/ddr_byte_lane_D.ddr_byte_lane_D/ddr_ck_gen_loop[0].ddr_ck_gen.ddr_ck_obuf/P/O, 
  and 
     processor/firstMB_i/mig_7series_0/u_firstMB_mig_7series_0_0_mig/u_memc_ui_top_axi/mem_intfc0/ddr_phy_top0/u_ddr_mc_phy_wrapper/u_ddr_mc_phy/ddr_phy_4lanes_0.u_ddr_phy_4lanes/ddr_byte_lane_D.ddr_byte_lane_D/ddr_ck_gen_loop[0].ddr_ck_gen.ddr_ck_obuf/N/O.
 

Top Level module error:

   port mapping CK_N twice: used in CK_P and CK_N;
 