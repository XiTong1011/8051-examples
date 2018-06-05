#include <mcs51/8051.h>
#include <stdio.h>
#include "serial.h"

void serial_init()
{
  // configure serial for 9600 baud, 8 data bits, 1 stop bit.
  TMOD |= 0x20;
  SCON |= 0x40;
  // TH1 = 256 - 11.0592 * 1000 * 1000 / 12 / 32 / 9600;
  TH1 = 0xFD;
  // start the timer1
  TR1 = 1;
  // tell putchar() the serial is ready to send
  SCON |= 0x02;
}

void serial_print(unsigned char *str)
{
  printf(str);
}
