#include</home/naveen/Documents/Keil_work_sorted/headers/header_list.h>

void main()
{
	int8 i,N=24;
	tInt bias=0,scale;
	tLong frequency;
	tChar byte1, byte2, temp;//, ichar[2];

	lcd_init();
	display("Initializing...");
	chip_init_CCFFE();
	enable_spi(0);
	dac_set(bias);
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
		display_int(i);
		//itoa(i,ichar,10);
		//display(ichar);
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
