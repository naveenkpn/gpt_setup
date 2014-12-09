#include<AT89C513xA.h>
#include<stdint.h>
#include<string.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/port_allot_sdcc.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/lcd4bit.h>
void main()
{
	int i,N=24;
	tLong bias;
	tLong byte1, byte2;
	
	lcd_init();
	display("Modulus Test");
	i=0;
	for(i=0;i<N;i++)
	{
		bias = 4096*(i+1)/N;
		line2();
		byte2 = bias%256;
       	byte1 = bias/256;
		display_hex(byte1);
		display_hex(byte2);
		msDelay(1000);
	}

	clearscr();
	display("Test Completed");
 	msDelay(5000);
	while(1)
	{}
}
