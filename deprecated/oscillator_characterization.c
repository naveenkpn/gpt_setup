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

__bit  FLG_CPL;

void main()
{
	int8 i,N=10;
	tInt bias;
	tLong frequency;
	tChar byte1, byte2, temp;

	lcd_init();
	msDelay(10);
	lcd_init();
	msDelay(10);
	lcd_init();
	clearscr();
	display("   Oscillator");
	line2();
	display("Characterization");
	
	enable_spi(0);
	
	clearscr();
	display("Freq = ");
	enable_serial();
	fmeter_reset();
	
	//send_byte('G');
	//for(i=0;i<N;i++)
	i=0;
	while(1)
	{
		bias = 400*(i+1);
		dac_set(bias);
		msDelay(1000);
		line2();
		//display_hex(i);
		//lcd_data(' ');
		byte2 = bias%256;
       		byte1 = bias/256;
		temp=receive_serial();
		frequency = fmeasure();
		display_freq(frequency);
		temp = receive_serial();
		send_byte(i);
		send_byte(byte1);
		send_byte(byte2);
		send_byte(fm_byte[0]);
		send_byte(fm_byte[1]);
		send_byte(fm_byte[2]);
		msDelay(1000);
		i++;
		if(i==N)
		i=0;
	}

	clearscr();
	display("Test Completed");
 	msDelay(5000);
	while(1)
	{}
}
