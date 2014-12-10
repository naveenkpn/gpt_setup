#include</home/naveen/Documents/Keil_work_sorted/headers/header_list.h>

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
	int8 i=10,N=24;
	tInt bias,scale;
	tLong frequency;
	tChar byte1,byte2,temp,ichar[2],jchar[2];
	__bit test_result;

	lcd_init();
	display("Initializing...");
	enable_spi(0);
	dac_set(0);
	chip_init_CCFFE();
	pll_init();
	clearscr();
	display("Set Jumpers and ping");
	temp = receive_serial();
	clearscr();
	display("     CCFFE");
	line2();
	display("Throughput test");
	
	msDelay(1000);
	enable_serial();
	load_source_data();
	clearscr();
	display("Setting up test");
	line(2);
	display("With 7 bit PRBS");
	scale = 2650/N;
	
	for(i=N,i>0;i--)
	{
		for(j=0;j<20;j++)
		{
			chip_init_CCFFE();
			sel_source(PRBS7);
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
        	itoa(i,ichar,10);
			display(",")
        	display_string(i);
        	display(ichar);
        	display(")=");
        	display_freq(frequency);
			CDR_CCFFE = 1
			LF_SELECT = 0;
			msDelay(1);
			LF_SELECT = 1;
			read_results();
			test_result = cross_correlation(source_data);
			if(test_result)
			{
	 			break;
			}
			if(i==0)
		{
			clearscr();
			display("Throughput test");
			line2();
			display("Failed");
			while(1);
		}
	}
	line2();
	display("Success");
	msDelay(2000);

	clearscr();
	display("Setting up test");
	line(2);
	display("With test data");
	scale = 2700/N;
	
	for(i=N,i>0;i--)
	{
		chip_init();
		sel_source(RING);
		load_test_data();
		bias = scale*i;
		dac_set(bias);
		msDelay(1000);
        frequency = fmeasure();
        clearscr();
        display("f(");
        itoa(i,ichar,10);
        display_string(i);
        display(ichar);
        display(")=");
        display_freq(frequency);
		
		LF_SELECT = 0;
		msDelay(1);
		LF_SELECT = 1;
		read_results();
		test_result = cross_correlation(source_data);
		if(test_result)
		{
	 		break;
		}
		if(i==0)
		{
			clearscr();
			display("Throughput test");
			line2();
			display("Failed");
			while(1);
		}
	}
	line2();
	display("Success");
	msDelay(2000);
	
	while(1);
}
