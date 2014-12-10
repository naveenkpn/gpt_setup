
void enable_serial()
{
	BDRCON = 0x01C;
	BRL = 0x0F3;			//Baud rate = 4800
	SCON = 0x050;
	PCON = 0x00;
}
/*================================================*/
void wait_serial()
{
	while(!TI){}
	TI = 0;
}
/*================================================*/
void send_serial(tChar *msg)
{
 tInt count;
 tChar temp;
 for (count=0; count <= strlen(msg)-1; ++count)
     {
       temp = msg[count];
			 SBUF=temp;
			 wait_serial();
		 }
}
/*================================================*/
void send_byte(tChar byte)
{
		SBUF=byte;
		wait_serial();
}
/*================================================*/
void new_line()
{
	send_serial("\n");
	send_byte(0x0D);
}
/*================================================*/
tChar receive_serial()
{
	while(!RI){}
	RI = 0;
	return SBUF;
}

tChar it_serial() __interrupt 5
{
	tChar rx_byte;
	if(RI)
	{
		rx_byte = SBUF;
		RI = 0;
		return rx_byte;
	} 
	if(TI)
	{
		TI = 0;
		return 0;
	}
	return 0;
}


void load_test_data()
{
	tInt i;
	clearscr();	
	display("Req test data");
	for(i=0;i<20;i++)
	{
		source_data[i]=receive_serial();
	}
	clearscr();
	display("test data read");
	line2();
	display("complete");
}	
