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
//#include</home/naveen/Documents/Keil_work_sorted/headers/test_chip.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/pll_lmk.h>

//#define LD P1_4 
//SBIT(LD,0x90,4);
//__sbit __at 'P1_4' LD;

void main()
{
	unsigned int val=0;
	enable_spi(0);	
	while(1)
	{
		val = adc_read(1);
		dac_set(val);
		
	}
}				
