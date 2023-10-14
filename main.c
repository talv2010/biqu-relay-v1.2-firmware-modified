
#include "intrins.h"
#include <stc15wxx.h>

void delay_ms(unsigned int ms);

#define green_led P30
#define red_led P31
#define ps_on P32
#define relay P55

void main(void)
{
	P3M1 = 0xB4;
  P3M0 = 0xB4;
	P5M0 = 0xFF;
	green_led=0x00;
	red_led=0x00;
	relay=0x00;
	delay_ms(60000);
	while(1)
	{
  if (ps_on){							//off
			green_led=0xFF;
		  red_led=0x00;
			delay_ms(30000);
	  	relay=0xFF;
		}
		else{								//on
			green_led=0x00;
		  red_led=0xFF;
			delay_ms(1000);
		  relay=0x00;
		}
		delay_ms(1000);
	};
}
	
void delay_ms(unsigned int ms) {
    unsigned int i, j;
    for (i = 0; i < ms; i++) {
        for (j = 0; j < 1180; j++);
    }
}