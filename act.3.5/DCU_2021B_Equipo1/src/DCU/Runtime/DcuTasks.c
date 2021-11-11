/*
 * Tasks.c
 *
 *  Created on: 8 sep. 2021
 *      Author: uid87544
 */

/* Kernel includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

/* SDK includes. */
#include "sdk_project_config.h"


#include "BasicTypes.h"
#include "Window.h"
#include "Door.h"
#include "Button.h"
#include "DoorApp.h"
#include "WindowApp.h"
#include "Wdg.h"
#include "Mcu.h"
#include "Mpu.h"
#include "Adc.h"
#include "Dio.h"
#include "DcuTasks.h"


/* Local Function Prototypes */
void Tasks_StartOS(void);


/* ============================================================================
 * Function Name:
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void app_task_200ms( void *pvParameters )
{
	TickType_t xNextWakeTime;

	/* Casting pvParameters to void because it is unused */
	(void)pvParameters;

	/* Initialize xNextWakeTime - this only needs to be done once. */
	xNextWakeTime = xTaskGetTickCount();

	for( ;; )
	{

		void PINS_DRV_TogglePins(GPIO_Type * const base,
		                         pins_channel_type_t pins);

		/* Place this task in the blocked state until it is time to run again.
		The block time is specified in ticks, the constant used converts ticks
		to ms.  While in the Blocked state this task will not consume any CPU
		time. */
		vTaskDelayUntil( &xNextWakeTime, 200 );

	}
}

/* ============================================================================
 * Function Name:
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void app_task_100ms( void *pvParameters )
{
	TickType_t xNextWakeTime;

	/* Casting pvParameters to void because it is unused */
	(void)pvParameters;

	/* Initialize xNextWakeTime - this only needs to be done once. */
	xNextWakeTime = xTaskGetTickCount();

	for( ;; )
	{
		Adc_Run();
				if(Adc_Get_AntiPinch_Value()<500)
		{
			//LED_GREEN OFF
						PINS_DRV_WritePin (LED_GREEN_PORT, LED_GREEN_PIN, 0);
		}else{
			//Toggle LED_GREEN
						//void
			PINS_DRV_TogglePins(LED_GREEN_PORT,1u<< LED_GREEN_PIN);
		}

		/* Place this task in the blocked state until it is time to run again.
		The block time is specified in ticks, the constant used converts ticks
		to ms.  While in the Blocked state this task will not consume any CPU
		time. */
		vTaskDelayUntil( &xNextWakeTime, 100 );

	}
}

/* ============================================================================
 * Function Name:
 * Description:
 * Arguments:
 * Return:
 * ========================================================================= */
void app_task_10ms( void *pvParameters )
{
	TickType_t xNextWakeTime;

	/* Casting pvParameters to void because it is unused */
	(void)pvParameters;

	/* Initialize xNextWakeTime - this only needs to be done once. */
	xNextWakeTime = xTaskGetTickCount();

	for( ;; )
	{

		/* Place this task in the blocked state until it is time to run again.
		The block time is specified in ticks, the constant used converts ticks
		to ms.  While in the Blocked state this task will not consume any CPU
		time. */
		vTaskDelayUntil( &xNextWakeTime, 10 );

	}
}



void Tasks_StartOS(void)
{
	xTaskCreate(app_task_200ms,        "App200ms",         configMINIMAL_STACK_SIZE, NULL,  4, NULL);
	xTaskCreate(app_task_100ms,        "App100ms",         configMINIMAL_STACK_SIZE, NULL,  2, NULL);
	xTaskCreate(app_task_10ms,        "App10ms",         configMINIMAL_STACK_SIZE, NULL,  3, NULL);

	Mpu_Init();

	vTaskStartScheduler();

}

void init_hook(void) {

    Mcu_Init();



	Wdg_Init();

    Dio_Init();

    Adc_Init();

	Tasks_StartOS();
}
