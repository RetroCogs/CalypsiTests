#include <stdio.h>

struct _VIC2RAW {
	uint8_t     D000;
	uint8_t     D001;
	uint8_t     D002;
	uint8_t     D003;
	uint8_t     D004;
	uint8_t     D005;
	uint8_t     D006;
	uint8_t     D007;
	uint8_t     D008;
	uint8_t     D009;
	uint8_t     D00A;
	uint8_t     D00B;
	uint8_t     D00C;
	uint8_t     D00D;
	uint8_t     D00E;
	uint8_t     D00F;
	uint8_t     D010;
	uint8_t     D011;
	uint8_t     D012;
	uint8_t     D013;
	uint8_t     D014;
	uint8_t     D015;
	uint8_t     D016;
	uint8_t     D017;
	uint8_t     D018;
	uint8_t     D019;
	uint8_t     D01A;
	uint8_t     D01B;
	uint8_t     D01C;
	uint8_t     D01D;
	uint8_t     D01E;
	uint8_t     D01F;
};

struct _VIC2 {
	uint8_t     S0X;
	uint8_t     S0Y;
	uint8_t     S1X;
	uint8_t     S1Y;
	uint8_t     S2X;
	uint8_t     S2Y;
	uint8_t     S3X;
	uint8_t     S3Y;
	uint8_t     S4X;
	uint8_t     S4Y;
	uint8_t     S5X;
	uint8_t     S5Y;
	uint8_t     S6X;
	uint8_t     S6Y;
	uint8_t     S7X;
	uint8_t     S7Y;
	uint8_t     SXMSB;
	union {
		uint8_t YSCL : 3;
		uint8_t RSEL : 1;
		uint8_t DEN  : 1;
		uint8_t BMM  : 1;
		uint8_t ECM  : 1;
		uint8_t RC8  : 1;
	};
	uint8_t     RC;
	uint8_t     LPX;
	uint8_t     LPY;
	uint8_t     SE;
	union {
		uint8_t XSCL : 3;
		uint8_t CSEL : 1;
		uint8_t MCM  : 1;
		uint8_t RST  : 1;
	};
	uint8_t     SEXY;
	union {
		uint8_t _NA0 : 1;
		uint8_t CB   : 3;
		uint8_t VS   : 4;
	};
	union {
		uint8_t RIRQ : 1;
		uint8_t ISBC : 1;
		uint8_t ISSC : 1;
		uint8_t ILP  : 1;
	};
	union {
		uint8_t MRIRQ : 1;
		uint8_t MISBC : 1;
		uint8_t MISSC : 1;
	};
	uint8_t     BSP;
	uint8_t     SCM;
	uint8_t     SEXX;
	uint8_t     SSC;
	uint8_t     SBC;
	uint8_t     BORDERCOL;
	uint8_t     SCREENCOL;
	uint8_t     MC1;
	uint8_t     MC2;
	uint8_t     MC3;
	uint8_t     SPRMC0;
	uint8_t     SPRMC1;
	uint8_t     SPR0COL;
	uint8_t     SPR1COL;
	uint8_t     SPR2COL;
	uint8_t     SPR3COL;
	uint8_t     SPR4COL;
	uint8_t     SPR5COL;
	uint8_t     SPR6COL;
	uint8_t     SPR7COL;
	uint8_t     _NA1;
	uint8_t     C128_FAST;
};

#define VIC2        (* (volatile struct _VIC2 *)        0xd000)
#define VIC2RAW     (* (volatile struct _VIC2RAW *)        0xd000)

volatile unsigned char *V4 = (unsigned char *)0xD000;

uint8_t xscroll = 0;

int main () {

  while(1)
  {
  	// __asm(" inc 0xD020\n");
    //VIC2.BORDERCOL++;
    //V4[0x20]++;

    xscroll = (xscroll + 1) & 7;
    // VIC2.XSCL = xscroll;
	VIC2RAW.D016 = VIC2RAW.D016 & 0xf8 | xscroll;

    // __asm(" lda 0xd016\n"
    //       " and #0xf8\n"
    //       " ora xscroll\n"
    //       " sta 0xd016\n");

		VIC2.CSEL = 1;
		VIC2.MCM = 1;
		VIC2.RST = 0;

		VIC2.ECM = 1;

    //printf("HELLO WORLD!");

  }
  
  return 0;
}
