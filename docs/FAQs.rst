FAQs for Design 
#########################
October,1st, 2018  Jack Lee

UART input/output to/from FPGA_UART/MCU_UART
===============================================
::

  uC_RXT2 <= UART1_TXD1;
  
It complains: can't read from output port, use ``buffer`` or ``inout`` port:

So, a signal should be added as the output of UART logic, then output this signal to both of these 2 ports;

::
 
 UART_RXD1 <= uC_TXD2;
 
It complains: can't update input signal;

So one signal should be added to play as the input of UART logic, and some combining logic to combine these 2 signals to this newly-added signal;

