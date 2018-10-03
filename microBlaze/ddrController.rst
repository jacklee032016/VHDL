
Vivado Project Options:
   Target Device                   : xc7a75t-fgg676
   Speed Grade                     : -2
   HDL                             : verilog
   Synthesis Tool                  : VIVADO

If any of the above options are incorrect, please click on "Cancel", change the CORE Generator Project Options, and restart MIG.

MIG Output Options:
   Module Name                     : firstMB_mig_7series_0_0
   No of Controllers               : 1
   Selected Compatible Device(s)   : xc7a100t-fgg676

FPGA Options:
   System Clock Type               : No Buffer
   Reference Clock Type            : No Buffer
   Debug Port                      : OFF
   Internal Vref                   : disabled
   IO Power Reduction              : ON
   XADC instantiation in MIG       : Enabled

Extended FPGA Options:
   DCI for DQ,DQS/DQS#,DM          : enabled
   Internal Termination (HR Banks) : 50 Ohms
    
/*******************************************************/
/*                  Controller 0                       */
/*******************************************************/
Controller Options :
   Memory                        : DDR3_SDRAM
   Interface                     : AXI
   Design Clock Frequency        : 3000 ps (333.33 MHz)
   Phy to Controller Clock Ratio : 2:1
   Input Clock Period            : 3000 ps
   CLKFBOUT_MULT (PLL)           : 4
   DIVCLK_DIVIDE (PLL)           : 1
   VCC_AUX IO                    : 1.8V
   Memory Type                   : Components
   Memory Part                   : MT41J128M16XX-15E
   Equivalent Part(s)            : --
   Data Width                    : 32
   ECC                           : Disabled
   Data Mask                     : enabled
   ORDERING                      : Strict

AXI Parameters :
   Data Width                    : 32
   Arbitration Scheme            : RD_PRI_REG
   Narrow Burst Support          : 0
   ID Width                      : 4

Memory Options:
   Burst Length (MR0[1:0])          : 8 - Fixed
   Read Burst Type (MR0[3])         : Sequential
   CAS Latency (MR0[6:4])           : 5
   Output Drive Strength (MR1[5,1]) : RZQ/6
   Controller CS option             : Enable
   Rtt_NOM - ODT (MR1[9,6,2])       : RZQ/6
   Rtt_WR - Dynamic ODT (MR2[10:9]) : Dynamic ODT off
   Memory Address Mapping           : BANK_ROW_COLUMN


Bank Selections:

System_Control: 
	SignalName: sys_rst
		PadLocation: No connect  Bank: Select Bank
	SignalName: init_calib_complete
		PadLocation: No connect  Bank: Select Bank
	SignalName: tg_compare_error
		PadLocation: No connect  Bank: Select Bank

