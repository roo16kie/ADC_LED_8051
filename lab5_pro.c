//實驗五 ADC 轉換
#include "reg51.h"
#define LED P0
#define DB P1
#define WR P3

int fake_led ;

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

fake_led = DB ^ 0xff;

if(fake_led > 0xfe)
	LED = 0xfe ;
else if (fake_led > 0xfc)
	LED = 0xfc ;
else if (fake_led > 0xf8)
	LED = 0xf8 ;
else if (fake_led > 0xf0)
	LED = 0xf0 ;
else if (fake_led > 0xe0)
	LED = 0xe0 ;
else if (fake_led > 0xc0)
	LED = 0xc0 ;
else if (fake_led > 0x80)
	LED = 0x80 ;
else if (fake_led > 0x00)
	LED = 0x00 ;

WR &= 0xbf;
WR |= 0x40;
}