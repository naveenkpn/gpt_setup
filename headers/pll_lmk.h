
void pll_init()
{
	enable_spi(1);
	PLL = 0;
	msDelay(1);
	SPDAT = 0X80;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	msDelay(1);
	PLL = 1;
	msDelay(10);
	
	PLL = 0;
	msDelay(1);
	SPDAT = 0X00;
	wait_spi();
	SPDAT = 0x03;
	wait_spi();
	SPDAT = 0xFF;
	wait_spi();
	SPDAT = 0x04;
	wait_spi();
	msDelay(1);
	PLL = 1;
	msDelay(10);
	
	PLL = 0;
	msDelay(1);
	SPDAT = 0X2B;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x01;
	wait_spi();
	SPDAT = 0x0E;
	wait_spi();
	msDelay(1);
	PLL = 1;
	msDelay(10);

	PLL = 0;
	msDelay(1);
	SPDAT = 0X00;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x01;
	wait_spi();
	SPDAT = 0x0F;
	wait_spi();
	msDelay(1);
	PLL = 1;
	msDelay(10);
	disable_spi();
}

void divider_init()
{
	enable_spi(1);
	PLL = 0;
	msDelay(1);
	SPDAT = 0X80;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	msDelay(1);
	PLL = 1;
	msDelay(10);
	
	PLL = 0;
	msDelay(1);
	SPDAT = 0X00;
	wait_spi();
	SPDAT = 0x03;
	wait_spi();
	SPDAT = 0xFF;
	wait_spi();
	SPDAT = 0x04;
	wait_spi();
	msDelay(1);
	PLL = 1;
	msDelay(10);
	
	PLL = 0;
	msDelay(1);
	SPDAT = 0X68;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x00;
	wait_spi();
	SPDAT = 0x0E;
	wait_spi();
	msDelay(1);
	PLL = 1;
	msDelay(10);
	disable_spi();
}
