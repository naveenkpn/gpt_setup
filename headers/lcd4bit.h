
void msDelay(int msec)
{	  
int cntr_1, cntr_2;
for (cntr_1 = 0; cntr_1 <= msec; ++cntr_1 )
    {
      for ( cntr_2 = 0; cntr_2 <= 355; ++cntr_2);
    }
}
/*================================================*/
void lcd_cmd (tChar cmd)
{ 
	LCD_PORT = ((cmd >> 4) & 0x0F)|LCD_EN;
	LCD_PORT = ((cmd >> 4) & 0x0F);
	msDelay(1);
	LCD_PORT = (cmd & 0x0F)|LCD_EN;
	LCD_PORT = (cmd & 0x0F);
	msDelay(2);
}
/*================================================*/
void lcd_init ()
{
	LCD_PORT = 0x00;
	msDelay(1);
	LCD_PORT = 0x02;
	LCD4B_E = 1;
	msDelay(10);
	LCD4B_E = 0;
	
	msDelay(10);
	lcd_cmd(0x28);               
	msDelay(1);
	lcd_cmd(0x01);       
	msDelay(1);
	lcd_cmd(0x80);       
	msDelay(1);	
	lcd_cmd(0x0E);       
	msDelay(1);
}
 /*================================================*/
void lcd_data (tChar dat)
{ 
	LCD_PORT = (((dat >> 4) & 0x0F)|LCD_EN|LCD_RS);
	LCD_PORT = (((dat >> 4) & 0x0F)|LCD_RS);
	msDelay(1);
    	LCD_PORT = ((dat & 0x0F)|LCD_EN|LCD_RS);
	LCD_PORT = ((dat & 0x0F)|LCD_RS);
 	msDelay(1);
}
/*================================================*/
void display(tChar *msg)
{
 tInt count;
 tChar temp;
 for (count=0; count <= strlen(msg)-1; ++count)
     {
       if(count == 16)
       lcd_cmd(0xc0);
			 temp = msg[count];
			 lcd_data(temp);		 
      }
}
/*================================================*/
void movback(tInt n)
{
	tInt i;
	for(i=0;i<n;i++)
	lcd_cmd(0x010);
}
/*================================================*/
void clearscr()
{
	lcd_cmd(0x01);
}
/*================================================*/
void line2()
{
	lcd_cmd(0x0C0);
}
/*================================================*/
void display_hex(tChar hex)
{
	tChar number;
	unsigned char temp_L;           // dummy variable that will hold LSBs of Hex number
	unsigned char temp_H;           // dummy variable that will hold MSBs of Hex number

	number = hex;
	
	temp_H = number & 0x00FF;           // Obtain the upper 4 bits (MSBs) of hex number	
	temp_H = temp_H >> 4;           // 
	if(temp_H >9)                   // Check if the number is a letter
	temp_H += 0x37;             // Convert the number to a letter in ASCII
	else
	temp_H += 0x30;             // Convert the number to ASCII number
	
	lcd_data(temp_H);           // Display the number
	
	temp_L = number & 0x0F;           // Obtain the lower 4 bits (LSBs) of hex number
	if(temp_L >9)                   // Check if the the number is a letter
	temp_L += 0x37;             // Convert the number to a letter in ASCII
	else
	temp_L += 0x30;             // Convert the number to ASCII number
	
	lcd_data(temp_L);           // Display the number
}
/*================================================*/
		
