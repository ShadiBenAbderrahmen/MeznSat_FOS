/*
 * normal_mode_task.c
 *
 *  Created on: Sep 18, 2018
 *      Author: Aisha
 *
 * The the normal task runs as it checks for a queue. If the queue contains a value (HK data),
 * it will print the data for now. The next step is to manage the memory (store and retrieve) for this data.
 */

#include <freertos/FreeRTOS.h>
#include <freertos/semphr.h>
#include <freertos/task.h>
#include <freertos/queue.h>

#include <hal/Timing/WatchDogTimer.h>
#include <hal/Drivers/LED.h>
#include <hal/boolean.h>
#include <hal/Utility/util.h>

#include <at91/utility/trace.h>
#include <at91/peripherals/cp15/cp15.h>
#include <at91/utility/exithandler.h>
#include <at91/commons.h>

#include <Tasks/housekeeping_task.h>

xQueueHandle xQueue;

void vNormalModeTask(void *pvParameters){
	housekeeping_data_collection data;

	while(1){
		printf("\t I am inside the normal mode \n\r");

		if(xQueueReceive(xQueue, &data, 0) == pdPASS){
			//store to file
			printf("\t The normal mode is storing to a file... Store complete \n\r");
			printf("Board temp is = %f \r\n", data.board_temp);
			printf("tx current is is = %f \r\n", data.tx_current);
			printf("bus voltage is = %f \r\n", data.bus_volt);

		}
		vTaskDelay(100);
	}
}

int
vNormalModeTaskInit(void)
{
	xTaskHandle xHKHandle;
	xQueue = xQueueCreate(5, sizeof( housekeeping_data_collection ));

	if (xTaskGenericCreate(vNormalModeTask, (const signed char*)"taskHK", 1024, NULL,
			2, &xHKHandle, NULL, NULL) != pdTRUE)
	{
		return(1);
	}

    // Success.
    return(0);
}
