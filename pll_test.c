#include<AT89C5131.h>
#include<string.h>
#include<port_allot.h>
#include<lcd4bit.h>
#include<fmeter.h>
#include<spi.h>
#include<dac_adc.h>
//#include<pll_lmk.h>

sbit TST_LED = P1^4;
bit  FLG_CPL;


void main()
{	
	lcd_init();
	clearscr();
	
	display("LMK02000 Testing");
//	pll_init();
//	enable_spi(1);
	line2();
	display("Wait...");
	msDelay(1000);
	
	SPCON = 0xB2;
	SPCON |= 0x40;
	
	clearscr();
	display("1");
	
	
	PLL = 0;
	msDelay(1);
	SPDAT = 0x80;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	msDelay(1);
	PLL = 1;
	msDelay(10);
	
	
	clearscr();
	display("2");
		
	PLL = 0;
	msDelay(1);
	SPDAT = 0X00;
	wait_spi();
	SPDAT = 0x03;
	wait_spi();
	SPDAT = 0x0FF;
	wait_spi();
	SPDAT = 0x04;
	wait_spi();
	msDelay(1);
	PLL = 1;
	msDelay(10);



	PLL = 0;
	msDelay(1);
	SPDAT = 0X2B;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x01;
	wait_spi();
	SPDAT = 0x0E;
	wait_spi();
	msDelay(1);
	PLL = 1;
	msDelay(10);


		
	msDelay(2000);
	clearscr();
	line2();
	display("O/P = Fin/4");
	while(1)
	{
		FLG_CPL = FLG_CPL^1;
    TST_LED = FLG_CPL;
		msDelay(200);
		
	}
}