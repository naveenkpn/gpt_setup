
void dac_set(tLong bias)
{
	tLong byte1, byte2;
  	byte2 = bias%256;
	byte1 = bias/256;
	byte1 = 0x70 | byte1;
	
	if(bias > 2700)
	{
		clearscr();
		display("ERROR!");
		display_hex(byte1);
		display_hex(byte2);
		line2();
		display("DAC O/P ~ 1.2V");
		while(1);
	}
	else
	{
		DAC = 0;
		SPDAT = byte1;
		wait_spi();
		SPDAT = byte2;
		wait_spi();
		byte2 = SPDAT;
		DAC = 1;
	}
}

unsigned int adc_read(tInt N)
{
	//unsigned int bcd_number[4]={0,0,0,0};
	unsigned int adc_data;
	ADC = 0;
	SPDAT = 0X01;
	wait_spi();
  
	if(N==0)
		SPDAT = 0X88;
	if(N==1)
		SPDAT = 0X98;
	if(N==2)
		SPDAT = 0XA8;
	if(N==3)
		SPDAT = 0xB8;
	if(N==4)
		SPDAT = 0xC8;
	if(N==5)
		SPDAT = 0xD8;
	if(N==6)
		SPDAT = 0xE8;
	if(N==7)
		SPDAT = 0xF8;
	wait_spi();
	adc_data = SPDAT*256;        
	SPDAT = 0X88;
	wait_spi();
	adc_data = adc_data+SPDAT;
	ADC = 1;

	adc_data &= 0X03FF;
	return adc_data;
}

/*	for (i=0; i<4; i++) 
	{
		if (adc_data!=0) 
			{
				bcd_number[i] = adc_data%10 | 0x30;
				adc_data = adc_data/10;
			}
		else
			{
				bcd_number[i] = 0x30;
			}			
	}
	for(i=3;i>=0;i--)
	lcd_data(bcd_number[i]);
}*/
