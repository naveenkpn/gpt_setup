#include</home/naveen/Documents/Keil_work_sorted/headers/header_list.h>

__bit test_result;
void main()
{
	int i=10,j,k,N=24;
	tInt bias,scale;
	tLong frequency;
	tChar temp;

	FLG_CPL=0;
	lcd_init();
	display("Initializing...");
	enable_spi(0);
	dac_set(0);
	chip_init_CDR();
	pll_init();
	clearscr();
	enable_serial();
	display("Set Jumpers and ping");
	temp = receive_serial();
	clearscr();
	display("     CDR");
	line2();
	display("Throughput test");
	
	msDelay(1000);
	enable_serial();
	load_test_data();
	clearscr();
	display("Setting up test");
	line2();
	display("With 7 bit PRBS");
	scale = 2650/N;
	
	for(i=N;i>0;i--)
	{
		for(j=0;j<20;j++)
		{
			chip_init_CCFFE();
			sel_source(RING);
			bias=scale*i;
			dac_set(bias);
			msDelay(1000);			
			for(k=j;k>=0;k--)
			{
				tick_RX_RC_CKIN();
				msDelay(1);
			}
        	frequency = fmeasure();
        	clearscr();
        	display("f(");
			display_int(i);
			display(",");
        	display_int(j);
        	display(")=");
        	display_freq(frequency);
			write_test_data_CCFFE();
			LF_SELECT = 0;
			msDelay(1);
			LF_SELECT = 1;
			read_results_CCFFE();
			test_result = cross_correlation();//source_data);
			if(test_result)
			{
				FLG_CPL=1;
                send_byte(fm_byte[0]);
                send_byte(fm_byte[1]);
                send_byte(fm_byte[2]);
                send_int(i);
                send_byte(',');
                send_int(j);
			}
		}
	}
	

	
	clearscr();
	display("Throughput test");
	line2();
	if(FLG_CPL)
	display("SUCCESS");
	else
	display("Failed");
	while(1);
}
