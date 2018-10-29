Interrupt Controller
####################################
10.28, 2018

Debug
============
* INTC self test failed:
   * After reset, and read interrupt status from Interrupt Status Register, and ACK them;
   * Before and After ACK, interrupt status is 0x20, MM2S interrupt of DMA controller is always OK;

* Reprogram FPGA chip, run same test program, everything is OK!   

