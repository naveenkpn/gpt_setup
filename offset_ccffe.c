#include</home/naveen/Documents/Keil_work_sorted/headers/header_list.h>

void main()
{
	//enum data_source ABC;
	//ABC=PRBS7;
	lcd_init();
	display("Initializing...");
	enable_spi(0);
	dac_set(0);
	chip_init_CCFFE();
	clearscr();
	display("Offset trim DUT1");
	sel_source(OFFSET_CAL);
	msDelay(1);
	LF_SELECT = 0;
	while(1)
	{}
}
