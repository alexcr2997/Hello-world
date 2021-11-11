/*
 * LED_routine.c
 *
 */
#include "S32K144.h"

void toggle_LEDs(void)
{
	int counter;

	if(RED_TOGGLE)
	{
		PTD->PTOR |= (1<<15);
		for(counter = 0; counter < 800000; counter++){};
		PTD->PTOR |= (1<<15);
	}
	if(GREEN_TOGGLE)
	{
		PTD->PTOR |= (1<<16);
		for(counter = 0; counter < 800000; counter++){};
		PTD->PTOR |= (1<<16);
	}
	if(BLUE_TOGGLE)
	{
		PTD->PTOR |= (1<<0);
		for(counter = 0; counter < 800000; counter++){};
		PTD->PTOR |= (1<<0);
	}
}
