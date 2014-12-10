/*================================================*/
void rotate_received_data()
{
	tChar temp[20];
	tInt i;
	
	for(i=0;i<20;i++)
	{
		if(i==19)
		{
			temp[i] = (chip_data[i] << 1) | ((chip_data[0] >> 7) & 0x01);
		}
		else
		{
			temp[i] = chip_data[i] << 1 | ((chip_data[i+1] >> 7) & 0x01);
		}
	}
	for(i=0;i<20;i++)
	{
		chip_data[i] = temp[i];
	}	
} 
/*================================================*/
void flip_received_data()
{
	tChar temp[20];
	tInt i;

	
	for(i=0;i<20;i++)
	{
		if(i==19)
		{
			temp[i] = (chip_data[i] << 1) | ((chip_data[0] >> 7) & 0x01);
		}
		else
		{
			temp[i] = chip_data[i] << 1 | ((chip_data[i+1] >> 7) & 0x01);
		}
	}
	for(i=0;i<20;i++)
	{
		chip_data[i] = temp[i];
	}	
} 
/*================================================*/
__bit cross_correlation()//tChar *source_data)
{
	tChar i,j;
	__bit test_result = 0;
	for(i=0;i<160;i++)
	{
		if(!test_result)
		{
		for(j=0;j<16;j++)
		{
			if(source_data[j]!=chip_data[j])
			{
				rotate_received_data();
				break;
			}
			else
			{
				if(j==15)
				test_result = 1;
			}
		}
	}
	else
	break;
	}
	return test_result;
}
/*================================================*/


