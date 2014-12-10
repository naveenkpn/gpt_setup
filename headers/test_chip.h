/*================================================*/
tChar read_chip_byte()
{
	tChar byte;
	CHIP_RO_EN=0;
	SPDAT = 0XC8;
	wait_spi();
	CHIP_RO_EN=1;
	byte = SPDAT;
	return byte;
}	
/*================================================*/
void read_results()
{
	tInt i;
	disable_spi();
	enable_spi(1);
	for(i=0;i<20;i++)
	{
		chip_data[i] = read_chip_byte();
	}
	disable_spi();
	enable_spi(0);
}	
/*================================================*/
void read_RC_init()
{
	tChar state;
	state=RCState;
	state &=0x0F;
	clearscr();
	display("RC state = ");
	display_hex(state);
	line2();
	if(state!=0x00)
	{
		display("Reset Failed!");
		msDelay(2000);
	}
	else
	{
		display("Reset Successful");
	}
	msDelay(500);
}
/*================================================*/
void chip_init_CCFFE()
{
	CHIP_RESET = 1;
	TNH_RC_CKIN = 1;
	RX_RC_CKIN = 1;
	DATA_LOAD_EN = 1;
	LF_SELECT = 1;
	DATA_SEL0 = 0;
	DATA_SEL1 = 0;
	CDR_CCFFE = 1;
	SPICK = 1;
	DAC = 1;
	ADC = 1;
	FMETER = 1;
	PLL = 1;
	CHIP_RO_EN = 1;
	msDelay(100);
	read_RC_init();
}
/*================================================*/
void chip_reset()
{
	CHIP_RESET = 1;
    TNH_RC_CKIN = 1;
    RX_RC_CKIN = 1;
    DATA_LOAD_EN = 1;
    LF_SELECT = 1;
    CHIP_RO_EN = 1;
    msDelay(100);
	CHIP_RESET=0;
}
/*================================================*/
/*tChar read_chip_byte1()
{
	tChar byte;
	READ_OUT_CCFFE_ENABLE = 0;			//Alternately READ_OUT_CDR_ENABLE for DUT 2/3
	msDelay(10);
	SPDAT = 0XC8;
	wait_spi();
	msDelay(10);
	READ_OUT_CCFFE_ENABLE = 1;
	byte = SPDAT;
	return byte;
}*/
/*================================================*/
void write_chip_byte(tChar byte)
{
	DATA_LOAD_EN = 1;
	msDelay(10);
	SPDAT = byte;
	wait_spi();
	msDelay(10);
	DATA_LOAD_EN = 0;
	byte = SPDAT;
}
/*================================================*/
void tick_RX_RC_CKIN()
{
    msDelay(10);
    RX_RC_CKIN = 0;
    msDelay(10);
    RX_RC_CKIN = 1;
}
/*================================================*/
void tick_TNH_RC_CKIN()
{
    msDelay(10);
    TNH_RC_CKIN = 0;
    msDelay(10);
    TNH_RC_CKIN = 1;
}
/*================================================*/
void write_test_data()
{
    tInt i;
	disable_spi();
    enable_spi(1);
    for(i=0;i<16;i++)
    {
        write_chip_byte(source_data[i]);
    }
    disable_spi();
	enable_spi(0);
}
/*================================================*/
void sel_source(enum data_source I)
{
	if(I==RING)				//RING
	{
		DATA_SEL0=0;
		DATA_SEL1=0;
	}
	if(I==PRBS7)			//PRBS7
	{
		DATA_SEL0=1;
		DATA_SEL1=0;
	}
	if(I==PRBS15)			//PRBS15
	{
		DATA_SEL0=1;
		DATA_SEL1=1;
	}
	if(I==OFFSET_CAL)		//OFFSET CALIBRATION
	{
		DATA_SEL0=0;
		DATA_SEL1=1;
	}
}
