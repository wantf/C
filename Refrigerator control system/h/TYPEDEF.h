/******************************************************/
/*				COMPANY : MIDEA									*/
/*				MICOM	: SAMSUNG S3C9488(8MHz)					*/
/*				START	: 2011-04-28		    					*/
/*				END 	: 2010-04-30     		    				*/
/*				PGM 	: SHIN JAE SUNG							*/
/*				MODEL	: BCD(SBS)545-WKMC DISPLAY				*/
/******************************************************/

typedef	unsigned char	byte;
typedef	unsigned short	word;

#define	clear		0
#define	set		1

#define	OD_Low	0
#define	OD_High	1

#define	Low	0
#define	High	1
/*
#ifdef _MAIN_SOURCE
	#define MEM_EXT
#else
	#define MEM_EXT	extern
#endif

__tiny MEM_EXT uchar LED_Index;   // Page0 0x00
__tinyp1 MEM_EXT uchar LCD_Buffer; // Page1 0x00~0x15
__no_init __tinyp1 MEM_EXT uchar test @ 0x14; // Page1 0x00~0x15
__tiny MEM_EXT uchar A;   // Page0 0x00
__tiny MEM_EXT uchar B;   // Page0 0x00
*/
#define UINT8       unsigned char
//#define BIT         unsigned char

typedef struct tag_uint8_bits
{
    unsigned char bit0:1;
    unsigned char bit1:1;
    unsigned char bit2:1;
    unsigned char bit3:1;
    unsigned char bit4:1;
    unsigned char bit5:1;
    unsigned char bit6:1;
    unsigned char bit7:1;
} UINT8_BITS;

typedef union tag_uint8_union
{
    UINT8       Byte;
    UINT8_BITS  Bits;
} UINT8_UNION;

typedef struct bits{
  unsigned char BIT0 :1;
  unsigned char BIT1 :1;
  unsigned char BIT2 :1;
  unsigned char BIT3 :1;
  unsigned char BIT4 :1;
  unsigned char BIT5 :1;
  unsigned char BIT6 :1;
  unsigned char BIT7 :1;
} strBits;
/*
struct bits_word{
  unsigned int BIT0 :1;
  unsigned int BIT1 :1;
  unsigned int BIT2 :1;
  unsigned int BIT3 :1;
  unsigned int BIT4 :1;
  unsigned int BIT5 :1;
  unsigned int BIT6  :1;
  unsigned int BIT7  :1;
  unsigned int BIT8  :1;
  unsigned int BIT9  :1;
  unsigned int BIT10 :1;
  unsigned int BIT11 :1;
  unsigned int BIT12 :1;
  unsigned int BIT13 :1;
  unsigned int BIT14 :1;
  unsigned int BIT15 :1;
 };
*/
#define IPOD_CONNECTION

#define Sfr_Bit_Set(sfr,bit)         (sfr |= (1 << bit))  
#define Sfr_Bit_Clear(sfr,bit)       (sfr &= ~(1 << bit))
#define Sfr_Bit_Test_True(sfr,bit)   (sfr & (1 << bit))
#define Sfr_Bit_Test_False(sfr,bit)  (!(sfr & (1 << bit)))


#define _DI()		asm("DI")
#define _EI()		asm("EI")
#define _NOP()		asm("NOP")

#define P00_ON         Sfr_Bit_Test_True(P0,0)
#define P00_OFF        Sfr_Bit_Test_False(P0,0)

