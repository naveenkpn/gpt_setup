#include<AT89C513xA.h>
#include<stdint.h>
#include<string.h>
static unsigned char chip_data[30];
static unsigned char fm_byte[6];
#include</home/naveen/Documents/Keil_work_sorted/headers/port_allot_sdcc.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/lcd4bit.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/uart.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/fmeter.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/spi.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/dac_adc.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/correlation.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/test_chip.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/pll_lmk.h>

//#define LD P1_4 
//SBIT(LD,0x90,4);
//__sbit __at 'P1_4' LD;
__bit FLG_CPL;

void main()
{
	unsigned int values[16] = {0,512,1024,1536,2048,2560,3072,3584,4095,4095,4095,4095,4095,4095,4095,4095};

	unsigned int index=0;

        unsigned char var1,var2;
        unsigned char firstbyte = 0x70;
        unsigned char secondbyte;
        SPCON = 0xBE;
        SPCON |= 0x40;
        lcd_init();
	display("DAC Test");
	index = 0;
        while(1)
        {
        var1 = values[index]%256;
        var2 = values[index]/256;
        firstbyte = 0x70;
        firstbyte |= var2;
        secondbyte = var1;

        DAC = 0;
//      LDAC = 0;
        SPDAT = firstbyte;
        wait_spi();
        SPDAT = secondbyte;
        wait_spi();
        DAC = 1;
	display("1");
//	enable_spi(0);
//	while(1)
//	{
//		dac_set(values[index]);
	index++;
	if(index==16)
	{
		index=0;
		//msDelay(1000);
		clearscr();
		FLG_CPL = !FLG_CPL;
		if(FLG_CPL==1)
		{
		 display("Toggle");
		// msDelay(1000);
		}
		if(FLG_CPL==0)
		{
		 display("D");
		// msDelay(1000);
		}
		 CDR_CCFFE = FLG_CPL;
	}
	}
}				
