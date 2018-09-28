PicoBlaze 
####################

Questions:
===========
* Steps of implementation?
* How CPU interact with pins of board?
* How to load sw into CPU in FPGA chip?


Hardware
=============
Pins definition:

* uC_RXD2/uC_TXD2 is MCU's USART interface connect to FPGA, and FPGA forward them to UART1_TXD/UART1_RXD;



Editro for PSM assmble language
================================
* ``PicoBlaze - Syntax Highlighting.udl.xml`` is from **PicoBlaze-Library** git;
* ``Language\Define YourLanguage..`` to import this XML file as language of ``PicoBlaze``;
* Check language of ``PicoBlaze`` in ``Language\Define YourLanguage..``;
* Open *.psm file and select language of ``PicoBlaze``, then syntax highlight;


Assemble to make *.vhd
===========================

::

	.\kcpsm6.exe .\uart\auto_baud_rate_control.psm 
	

**Notes:**

* ``ROM_form.vhd`` must be in the same directory of ``*.psm`` files to create *.vhd file;
* Component name is ``auto_baud_rate_control``;


VHDL Modules
=====================

#. **kcpsm6**: PicoBlaze Core;
#. **uart_tx**: UART Transmitter;
#. **uart_rx**: UART Receiver;
#. **rom(auto_baud_rate_control)**: software for PicoBlaze; support JTAG load interface for new software;
#. **main**: interface/main module;

**Notes**:

* `Supports JTAG interface` means some part of software of kcmps is always exists and run to receive, load and run newly-loaded software;


Build and Tests
======================

Building
-------------
* Create a project;
* Add design sources files;
* Add constraints files;
* Synthesis/Implementation/Generating

Tests
---------------
#. Cable USB II loads bitstream or binary into to FPGA, and then it runs in FPGA;
#. Program bitstream into SPI flash, and reboot MCU to load it;
