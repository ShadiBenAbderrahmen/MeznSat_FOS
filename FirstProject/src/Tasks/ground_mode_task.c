/*
 * ground_mode_task.c
 *
 *  Created on: Sep 30, 2018
 *      Author: Aisha
 */


#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/task.h>

#include <hal/Timing/WatchDogTimer.h>
#include <hal/Drivers/LED.h>
#include <hal/boolean.h>
#include <hal/Utility/util.h>

#include <at91/utility/trace.h>
#include <at91/peripherals/cp15/cp15.h>
#include <at91/utility/exithandler.h>
#include <at91/commons.h>

void vGroundContactModeTask(void *pvParameters){

	while(1){
		printf("\t I am inside the Ground Contact mode \n\r");
		vTaskDelay(100);
	}
}

int
vGroundContactModeTaskInit(void) //called from main.c
{
	xTaskHandle xGCHandle;

		if (xTaskGenericCreate(vGroundContactModeTask, (const signed char*)"taskGC", 1024, NULL,
				2, &xGCHandle, NULL, NULL) != pdTRUE)
		{
			return(1);
		}

	    // Success.
	    return(0);
}
