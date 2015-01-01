#include</home/naveen/Documents/Keil_work_sorted/headers/header_list.h>

void main()
{
	//enum data_source ABC;
	//ABC=PRBS7;
	tChar temp;
	lcd_init();
	display("Initializing...");
	enable_spi(0);
	dac_set(0);
	chip_init_CCFFE();
	pll_init();
	clearscr();
    enable_serial();
    display("Set Jumpers and ping");
    temp = receive_serial();
    clearscr();

	display("Offset trim DUT1");
	sel_source(OFFSET_CAL);
	msDelay(1);
	LF_SELECT = 0;
	CHIP_RESET = 0;
//	LF_SELECT=1;
	while(1);
//	{
//		LF_SELECT=1;
//		msDelay(10000);
//		LF_SELECT=0;
//		msDelay(10000);
//	}
}
