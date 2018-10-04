/*
 * housekeeping_task.c
 *
 *  Created on: Sep 18, 2018
 *      Author: Aisha
 *
 * Please feel free to experiment with the code.
 * Current method:
 * 	To collect RX house keeping data, the function IsisTrxvu_rcGetTelemetryAll(0, &rxTelemetry) is called
 * 	which returns a union ISIStrxvuRxTelemetry. We can extract data individually from a nested structure
 * 	like current, power etc. Or we may just receive a Raw value array with all Rx Telemetry data.
 * 	In this code, the first method is used which also processes the data then stores it in a structure that
 * 	is passed to a queue. The second method may also be considered since it will take less lines of code and
 * 	no processing. What do you think?
 *
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

#include <satellite-subsystems/GomEPS.h>
#include <satellite-subsystems/IsisTRXVU.h>

#include <Tasks/housekeeping_task.h>

extern xQueueHandle xQueue;


static void
vHousekeepingTask(void *pvParameters){
	housekeeping_data_collection data;


	unsigned short telemetryValue;
	float eng_value = 0.0;

	gom_eps_hk_basic_t myEpsTelemetry_hk_basic;
	ISIStrxvuTxTelemetry txTelemetry;
	ISIStrxvuRxTelemetry rxTelemetry;


	portTickType xLastWakeTime;
	xLastWakeTime = xTaskGetTickCount();

	while(1){
		printf("\t collecting Housekeeping Data... \n\r");
		//Create mutex for i2c communication

		//GomEpsGetHkData_basic(0, &myEpsTelemetry_hk_basic);
		IsisTrxvu_rcGetTelemetryAll(0, &rxTelemetry);

		//IsisTrxvu_tcGetTelemetryAll(0, &txTelemetry);

		telemetryValue = rxTelemetry.fields.tx_current;
		eng_value = ((float)telemetryValue) * 0.0897;
		data.tx_current = eng_value;

		telemetryValue = rxTelemetry.fields.rx_doppler;
		eng_value = ((float)telemetryValue) * 6.837 - 14000;
		data.rx_doppler = eng_value;

		telemetryValue = rxTelemetry.fields.rx_current;
		eng_value = ((float)telemetryValue) * 0.0305;
		data.rx_current = eng_value;

		telemetryValue = rxTelemetry.fields.bus_volt;
		eng_value = ((float)telemetryValue) * 0.00488;
		data.bus_volt = eng_value;

		telemetryValue = rxTelemetry.fields.board_temp;
		eng_value = ((float)telemetryValue) * -0.0546 + 189.5522;
		data.board_temp = eng_value;

		telemetryValue = rxTelemetry.fields.pa_temp;
		eng_value = ((float)telemetryValue) * -0.0546 + 189.5522;
		data.pa_temp = eng_value;

		telemetryValue = rxTelemetry.fields.rx_rssi;
		eng_value = ((float)telemetryValue * 0.03) + 152;
		data.rx_rssi = eng_value;

		xQueueSend(xQueue, &data, 0);

		vTaskDelayUntil( &xLastWakeTime, 6000 / portTICK_RATE_MS);
	}
}

int
vHousekeepingTaskInit(void)
{
	xTaskHandle xHKHandle;

	if (xTaskGenericCreate(vHousekeepingTask, (const signed char*)"taskHK", 1024, NULL,
			3, &xHKHandle, NULL, NULL) != pdTRUE)
	{
		return(1);
	}


    // Success.
    return(0);
}


