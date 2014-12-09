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
	int8 i,N=24;
	tInt bias,scale;
	tLong frequency;
	tChar byte1, byte2, temp, ichar[2];
	
	lcd_init();
	display("Initializing...");
	chip_init();
	enable_spi(0);
	pll_init();//Alternately 
//	divider_init();
	clearscr();
	display("   Oscillator");
	line2();
	display("Characterization");
	msDelay(1000);

	clearscr();
	display("Waiting for Host to ping");
	enable_serial();
	fmeter_reset();
	LF_SELECT = 0;
	scale = 2650/N;
	
	i=0;
	for(i=0;i<N;i++)
	{
		bias = scale*(i+1);
		dac_set(bias);
		msDelay(1000);
		byte2 = bias%256;
       	byte1 = bias/256;
		temp=receive_serial();
		frequency = fmeasure();
		clearscr();
		display("f(");
		itoa(i,ichar,10);
		display(ichar);
		display(")=");
		display_freq(frequency);
		temp = receive_serial();
		send_byte(i);
		send_byte(byte1);
		send_byte(byte2);
		send_byte(fm_byte[0]);
		send_byte(fm_byte[1]);
		send_byte(fm_byte[2]);
		msDelay(1000);
	}

	clearscr();
	display("Test Completed");
 	msDelay(5000);
	while(1)
	{}
}
