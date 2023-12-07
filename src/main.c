#include <stdio.h>
#include "chips.h"

uint8_t xscroll = 0;

int main () {

  while(1)
  {
    xscroll = (xscroll + 1) & 7;

	// Union example
    VIC2.XSCL = xscroll;

	// Raw more manual option
	VIC2RAW.D016 = VIC2RAW.D016 & 0xf8 | xscroll;

	// Manual asm example
    __asm(" lda 0xd016\n"
          " and #0xf8\n"
          " ora xscroll\n"
          " sta 0xd016\n");
  }
  
  return 0;
}
