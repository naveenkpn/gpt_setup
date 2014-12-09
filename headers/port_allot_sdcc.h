
enum data_source{PRBS7, PRBS15, RING, OFFSET_CAL};

//Port 0
#define RCState   P0

#define TNH_RC_CKIN P0_4
#define RX_RC_CKIN P0_5
#define DATA_LOAD_EN P0_6
#define LF_SELECT P0_7

//Port 1
#define DAC P1_0
#define ADC P1_1
#define FMETER P1_2
#define CHIP_RO_EN P1_3
#define CDR_CCFFE P1_4
#define SPICK P1_6

//Port 2 LCD
#define LCD_PORT P2

#define LCD4B_E P2_7
#define LCD4B_RW P2_6
#define LCD4B_RS P2_5

//Port 3

#define PLL_LD P3_2
#define PLL P3_4
#define DATA_SEL0 P3_5
#define DATA_SEL1 P3_6
#define CHIP_RESET P3_7

//Port 4
