
void wait_spi(void)
{
	while(!(SPSTA/128)){}
}
/*================================================*/
void enable_spi(tInt type)
{
	if(type==0)
	{
		SPCON = 0x31;
		SPCON |= 0x40;
	}
	else if(type==1)
	{
		SPCON = 0xB2;
		SPCON |= 0x40;
	}
}
/*================================================*/
void disable_spi()
{
	SPCON &=0xBF;
}
/*================================================*/
