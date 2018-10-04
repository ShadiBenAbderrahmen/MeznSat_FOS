/*
 * housekeeping_task.h
 *
 *  Created on: Sep 27, 2018
 *      Author: Aisha
 */

#ifndef HOUSEKEEPING_TASK_H_
#define HOUSEKEEPING_TASK_H_

extern int vHousekeepingTaskInit(void);

typedef struct housekeeping_data_collection
{
	//Communication HK
	float tx_current; ///< Rx Telemetry transmitter current.
	float rx_doppler; ///< Rx Telemetry receiver doppler.
	float rx_current; ///< Rx Telemetry receiver current.
	float bus_volt; ///< Rx Telemetry bus voltage.
	float board_temp; ///< Rx Telemetry board temperature.
	float pa_temp; ///< Rx Telemetry power amplifier temperature.
	float rx_rssi; ///< Rx Telemetry rssi measurement.

} housekeeping_data_collection;

#endif /* HOUSEKEEPING_TASK_H_ */
