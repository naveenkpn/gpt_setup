#include<AT89C513xA.h>
//#include<stdint.h>
#include<string.h>
static unsigned char chip_data[30];
#include</home/naveen/Documents/Keil_work_sorted/headers/port_allot_sdcc.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/lcd4bit.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/fmeter.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/spi.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/dac_adc.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/uart.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/correlation.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/test_chip.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/pll_lmk.h>

__bit  FLG_CPL;

void read20()
{
	tInt i;
	//tChar temp;
	for(i=0;i<20;i++)
	{
		chip_data[i]=receive_serial();
	}
}

void send20()
{
	tInt i;
	for(i=0;i<20;i++)
	{
		send_byte(chip_data[i]);
	}
}

void main()
{
	tInt values[16] = {0,512,1024,2048,4096,8192,8192,4096,2048,1024,512,0,0,0,0,0};
	tInt index=0;
	tChar source_data[30] = "ABCDEFGHIJKLMNOP";
	
	__bit test_result;
	
	//source_data = "ABCDEFGHIJKLMNOP";
	lcd_init();
	clearscr();
	display("SDCC - Unix");
	line2();
	display("Integrity Check");
	msDelay(1000);
	
	//Testing of Serial interface
/*	clearscr();
	display("UART Test");
	msDelay(1000);
	clearscr();
	display("Sending test data to PC");*/
	enable_serial();/*
	send_serial("Data received from PT-51");
	msDelay(1000);
	clearscr();
	display("Test reception");
	line2();
	display("Req char 'J'");
	temp = receive_serial();
	clearscr();
	if(temp == 'J')
	{
		display("Test Successful");
	}
	else
	{
		display("UART Test Failed");
	}
	msDelay(1000);*/
	/*
	//DAC Test
	enable_spi(0);
	clearscr();
	display("DAC Test");
	index=0;
	for(i=0;i<255;i++)
	{
		dac_set(values[index]);
		index++;
		
		if(index==8)
		{
			clearscr();
			display("Slope positive");
		}
		if(index==16)
		{
			clearscr();
    	display("Slope negative");
   		index = 0;
		}
	}
	msDelay(1000);
	clearscr();
	display("DAC testing complete");
		
	//ADC testing
	clearscr();
	display("ADC Testing");
	enable_spi(0);*/
	
	//Correlation test
	clearscr();
	display("Correlation test");
	line2();
	display("Reading results");
	read20();
	
	send_serial("\n");
	send_serial("Chip read complete");
	new_line();
	send20();
	
	msDelay(2000);
	clearscr();
	display("Returning source data to PC");
	//send_serial(source_data);
	new_line();
	send_serial("Chip data = ");
	send20();
	//send_serial(source_data);
	test_result = cross_correlation(source_data);
	clearscr();
	if(test_result)
	{
	 display("Test Successful");
	}
	else
	{
	 //flip_received_data();
	 //test_flip = cross_correlation(source_data);
	 //if(test_flip)
	 //{
	//	display("reverse Match");
	 //}
	 //else
	// {
	  display("Fail");
	 }
	//}
	new_line();
	send20();
	while(1);
}
