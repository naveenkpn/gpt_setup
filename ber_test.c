#include</home/naveen/Documents/Keil_work_sorted/headers/header_list.h>

__bit test_result;
void main()
{
    int i=10,N=24;
    tChar temp;
    FLG_CPL=0;
    lcd_init();
    display("Initializing...");
    enable_spi(0);
    dac_set(0);
    chip_init_CCFFE();
    pll_init();
    clearscr();
    display("Set Jumpers and ping");
    enable_serial();
	temp = receive_serial();
	//send_serial("Testing");
    clearscr();
    display("BERT");
	
    msDelay(1000);
	
	load_test_data();
	
	for(i=0;i<20;i++)
		chip_data[i] = source_data[i];
	
	log_test_results();

	rotate_received_data();
	rotate_received_data();
	
	log_test_results();

    clearscr();
    display("Done");
	while(1);
}
