STARTUPE2 Primitive
#########################
October,10, 2018  Jack Lee


Objects
===============================================
CCLK is configuration dedicated pin of FPGA, it can be reused after configuration finished;

CCLK pin only available from STARTUPE2 primitive after configuration


::

  STARTUPE2_INST: STARTUPE2
			generic map(
					PROG_USR => "FALSE",
					SIM_CCLK_FREQ => 0.0)

			port map (
					CFGCLK => open,  -- CLK only used in configuration period
					CFGMCLK => open,  -- free run clock
					EOS => open,   -- End Of Start
					PREQ => open,   -- Programming Request
					CLK => '0',
					GSR => '0',
					GTS => '0',
					KEYCLEARB => '0',
					PACK => '0',
					USRCCLKO => spi_clk, -- external (EMCCLK) spi_?clk signal from the design which is provide signal to output on CCLK pin 
					USRCCLKTS => '0', -- Enable CCLK pin
					USRDONEO => '1',-- Drive DONE pin High even though tri-state 
					USRDONETS => '1' 
			); -- Maintain tri-state of DONE pin



QXI QUAD SPI IP
^^^^^^^^^^^^^^^^^^^^^^^^^^
* Support STARTUPEn pritimive (Enable or Disable);
* STARTUPE only be used in Master SPI mode;
* AXI QUAD SPI IP support slave/master mode, and plays as master device after configured;
* So, ``STARTUPE enable`` is not mandatory;


Code Segments
====================

User clock for flash after FPGA configured
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

		uC_SPISCK : in STD_LOGIC;-- SPI

Primitive
^^^^^^^^^^^^^^
It means connecting user clock input to CCLK after configuring;

::

	-- use this primitive, so FLASH_CLK is not used
		iStartUp : STARTUPE2
			generic map (
				PROG_USR => "FALSE", -- Activate program event security feature. Requires encrypted bitstreams.
				SIM_CCLK_FREQ => 0.0 -- Set the Configuration Clock Frequency(ns) for simulation.
			)
    
			port map (
				CFGCLK => open,        -- 1-bit output: Configuration main clock output
				CFGMCLK => open,       -- 1-bit output: Configuration internal oscillator clock output
				EOS => open,    -- 1-bit output: Active high output signal indicating the End Of Startup.
				PREQ => open,          -- 1-bit output: PROGRAM request to fabric output
				CLK => CLK27M,            -- 1-bit input: User start-up clock input
				GSR => '0',            -- 1-bit input: Global Set/Reset input (GSR cannot be used for the port name)
				GTS => '0',            -- 1-bit input: Global 3-state input (GTS cannot be used for the port name)
				KEYCLEARB => '0',      -- 1-bit input: Clear AES Decrypter Key input from Battery-Backed RAM (BBRAM)
				PACK => '0',           -- 1-bit input: PROGRAM acknowledge input
				USRCCLKO => uC_SPISCK,    -- 1-bit input: User CCLK input
				USRCCLKTS => '0',      -- 1-bit input: User CCLK 3-state enable input
				USRDONEO => '1',       -- 1-bit input: User DONE pin output control
				USRDONETS => '0'       -- 1-bit input: User DONE 3-state enable output
			);


Connect other pins from MCU to flash
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

		-- added for spi 
		-- not used: connec uC_SPISCK to USRCCLKO after configuration
		-- FLASH_CLK <= uC_SPISCK;

		FLASH_FCS_B <= uC_SPICSn;
		FLASH_D(0) <= uC_MOSI;
		uC_MISO <= FLASH_D(1);
		FLASH_D(1) <= 'Z';
		FLASH_D(2) <= 'Z';
		FLASH_D(3) <= 'Z';


Reference
================
* ug952: 7 series libraris;
* pg153-axi-quad-spi;

