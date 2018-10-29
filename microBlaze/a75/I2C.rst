I2C on AN767 Board
####################################
10.28, 2018

Debug
============
* Debug: read revisoin of clock generator chip directly works, but read revision of senor chip which is behind the I2C switch chip:
   * I2C switch chip has different programming mode, not like clock generator;
   * I2C Address period + data period (RW), without address within chip;
   * so call xIic_send() directly for channle configuration, not bspI2cRead, which add another write period for address within chip;
   

Operations
============
xIic_send()/xIic_recv() : Poll mode;
In interrupt mode, xIic_start() and set handlers for all interrupts;
