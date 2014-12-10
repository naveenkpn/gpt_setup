#include<AT89C513xA.h>
#include<stdint.h>
#include<string.h>
//#include<stdlib.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/itoa.c>

typedef unsigned char tChar;
typedef unsigned int tInt;
typedef unsigned long tLong;
typedef uint8_t int8;

enum data_source {PRBS7, PRBS15, RING, OFFSET_CAL};

static tChar chip_data[30],source_data[30];
static tChar fm_byte[6];

#define LCD_EN      0x080
#define LCD_RS      0x020

#include</home/naveen/Documents/Keil_work_sorted/headers/port_allot_sdcc.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/lcd4bit.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/uart.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/spi.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/fmeter.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/dac_adc.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/correlation.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/test_chip.h>
#include</home/naveen/Documents/Keil_work_sorted/headers/pll_lmk.h>

