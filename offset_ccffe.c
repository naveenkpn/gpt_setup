#include<AT89C513xA.h>
#include<stdint.h>
#include<string.h>
//#include<stdlib.h>
static unsigned char chip_data[30], source_data[30];
static unsigned char fm_byte[6];
#include</home/naveen/Documents/Keil_work_sorted/headers/port_allot_sdcc.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/lcd4bit.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/uart.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/spi.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/fmeter.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/dac_adc.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/correlation.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/test_chip.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/pll_lmk.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/itoa.c>

__bit  FLG_CPL;

void main()
{
	lcd_init();
	display("Initializing...");
	chip_init();
	clearscr();
	display("Offset trim DUT1");
	sel_source(2);
	
	LF_SELECT = 0;
	while(1)
	{}
}
