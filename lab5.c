//實驗五 ADC 轉換
#include "reg51.h"
#define LED P0
#define DB P1
#define WR P3
void main()
{
IT0 = 1;
EX0 = 1;
EA = 1;
LED = 0x00;
WR &= 0xbf;
WR |= 0x40;
while(1){};
}
void int_0(void) interrupt 0
{
LED = DB ^ 0xff;
WR &= 0xbf;
WR |= 0x40;
}