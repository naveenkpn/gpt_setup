void wait_spi();
void fmeter_reset()
{
	tInt temp;
	FMETER = 0;
	msDelay(10);
	SPDAT = 0xA5;
	wait_spi();
	temp = SPDAT;
	FMETER = 1;
}	

long unsigned fmeasure()
{
	tChar temp;
	//unsigned int fm_byte[3],temp;
	
	long unsigned freq;
	FMETER = 0;
	msDelay(1);
	SPDAT = 0x01;
	wait_spi();
	temp = SPDAT;
	msDelay(100);
	SPDAT = 0x01;
	wait_spi();
	fm_byte[2] = SPDAT;
	msDelay(100);
	SPDAT = 0x01;
	wait_spi();
	fm_byte[1] = SPDAT;
	msDelay(100);
	SPDAT = 0x01;
	wait_spi();
	fm_byte[0] = SPDAT;
	temp = SPDAT;
	
	FMETER = 1;
	
	freq = fm_byte[0] + fm_byte[1]*256 + fm_byte[2]*65536;
//	freq = fm_byte[0] + fm_byte[1] + fm_byte[2]*256;
	
//	freq = freq*256;
	freq = freq/0.3;
	
//	display_hex(fm_byte[2]);
//	display_hex(fm_byte[1]);
//	display_hex(fm_byte[0]);
//	display(" ");
	return freq;
}

void display_freq(long unsigned freq)
{
	unsigned int bcd_number[10]={0,0,0,0,0,0,0,0,0,0},i;
	for(i=0; i<10; i++) 
	{
		if (freq!=0) 
			{
				bcd_number[i] = freq%10 | 0x30;
				freq = freq/10;
			}
		else
			{
				bcd_number[i] = 0x30;
			}			
	}
/* 	i=9;
	for(i=10; i>-1; --i)
	{
		lcd_data(bcd_number[i]);
		if(i==9)
		{		
			lcd_data('.');
		}	
	} */
	for(i=0; i<3; i++)
	{
		lcd_data(bcd_number[9-i]);
		if(i==0)
		{
			lcd_data('.');
		}
	}
	display(" GHz");
}


//astrix and obelix
