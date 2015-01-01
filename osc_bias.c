#include</home/naveen/Documents/Keil_work_sorted/headers/header_list.h>

void main()
{
	int8 i,N=24;
	tInt bias=0,scale;
	tLong frequency;
	//tChar byte1, byte2, temp, ichar[2];
	tChar temp;
	
	i=10;
	lcd_init();
	display("Initializing...");
	chip_init_CCFFE();
	enable_spi(0);
	dac_set(bias);
//	pll_init();//ALternately
	divider_init();
	clearscr();
    enable_serial();
    display("Set Jumpers and ping");
    temp = receive_serial();
    clearscr();

	display("Phase Noise");
	line2();
	display("Characterization");
	msDelay(1000);
	scale = 2650/N;
	bias = scale*(i+1);
	dac_set(bias);
	CHIP_RESET=0;
	LF_SELECT = 0;
	clearscr();
	display("Oscillator");
	line2();
	display("bias set");
	msDelay(1000);
	clearscr();
	display("Measure Spectrum");
	while(1)
	{
		frequency = fmeasure();
		display_freq(frequency);
		msDelay(1000);	
	}
}
