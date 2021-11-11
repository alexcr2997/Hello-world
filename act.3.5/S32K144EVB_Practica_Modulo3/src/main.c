/*
 * main implementation: use this 'C' sample to create your own application
 *
 */
#include "S32K144.h"
#include "LED_routine.h"

#define DELAY (for(counter)

#if defined (__ghs__)
    #define __INTERRUPT_SVC  __interrupt
    #define __NO_RETURN _Pragma("ghs nowarning 111")
#elif defined (__ICCARM__)
    #define __INTERRUPT_SVC  __svc
    #define __NO_RETURN _Pragma("diag_suppress=Pe111")
#elif defined (__GNUC__)
    #define __INTERRUPT_SVC  __attribute__ ((interrupt ("SVC")))
    #define __NO_RETURN
#else
    #define __INTERRUPT_SVC
    #define __NO_RETURN
#endif

int counter;
void toggle_LEDs(void);

/*
 * Description:
 *
 * This simple project toggles the 3 user LEDs in the S32K144-EVB board periodically, following next sequence:
 * RED -> GREEN -> BLUE
 *
 * The toggling of the LEDs should be easy to perceive to human eye.
 */

int main(void)
{
	/* Enable clock gate for PORT D */
    PCC->PCCn[PCC_PORTD_INDEX] |= PCC_PCCn_CGC_MASK;

    /* Initialize PTD0, PTD15 and PTD16 as General Purpose Input-Output (GPIO) */
    PORTD->PCR[0] = PORT_PCR_MUX(1);
    PORTD->PCR[15] = PORT_PCR_MUX(1);
    PORTD->PCR[16] = PORT_PCR_MUX(1);

    /* Set all pins initially to 1 (all LEDs off due to negative logic in the board) */
    PTD->PSOR = (1<<16) | (1<<15) | (1<<0);

    /* Set all pins as output */
    PTD->PDDR = (1<<16) | (1<<15) | (1<<0);

    for (;;)
    {
    	/* Call LEDs toggling subroutine from separate compilation module */
    	toggle_LEDs();
    }
    /* to avoid the warning message for GHS and IAR: statement is unreachable*/
    __NO_RETURN
    return 0;
}
