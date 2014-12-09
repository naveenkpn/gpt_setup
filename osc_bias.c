#include<AT89C513xA.h>
#include<stdint.h>
#include<string.h>
#include<stdlib.h>
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
	int8 i,N=24;
	tInt bias=0,scale;
	//tLong frequency;
	//tChar byte1, byte2, temp, ichar[2];
	
	i=10;
	lcd_init();
	display("Initializing...");
	chip_init();
	enable_spi(0);
	dac_set(bias);
	pll_init();//ALternately
//	divider_init();
	clearscr();
	display("Phase Noise");
	line2();
	display("Characterization");
	msDelay(1000);
	scale = 2650/N;
	bias = scale*(i+1);
	dac_set(bias);
	LF_SELECT = 0;
	clearscr();
	display("Oscillator");
	line2();
	display("bias set");
	msDelay(1000);
	clearscr();
	display("Measure Spectrum");
	while(1)
	{}
}
