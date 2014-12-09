
//Port 0
#define RCState   P0

sbit TNH_RC_CKIN = P0^4;
sbit RX_RC_CKIN = P0^5;
sbit DATA_LOAD_EN = P0^6;
sbit LF_SELECT = P0^7;

//Port 1
sbit DAC = P1^0;
sbit ADC = P1^1;
sbit FMETER = P1^2;
sbit CHIP_RO_EN = P1^3;
sbit CDR_CCFFE = P1^4;
//sbit MISO = P1^5;
//sbit SCK = P1^6;
//sbit MOSI = P1^7;

//Port 2 LCD

//Port 3
//sbit RXD = P3^0;
//sbit TXD = P3^1;
sbit PLL_LD = P3^2;
//sbit P3^3;
sbit PLL = P3^4;
sbit DATA_SEL0 = P3^5;
sbit DATA_SEL1 = P3^6;
sbit CHIP_RESET = P3^7;

//Port 4
