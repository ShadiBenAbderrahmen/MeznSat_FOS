/*
 * priorities.h
 *
 *  Created on: Oct 1, 2018
 *      Author: Aisha
 *
 * Header containing priorities to be assigned to all the tasks that will be run by the kernel.
 *
 * NOTE: Any change to task priorities must be edited in this file rather than directly from  xTaskCreate().
 *
 */

#ifndef PRIORITIES_H_
#define PRIORITIES_H_

#define PRIORITY_NORMAL_TASK    2
#define PRIORITY_HOUSEKEEPING_TASK       1
#define PRIORITY_SAFE_TASK    2
#define PRIORITY_GROUND_TASK       1

#endif /* PRIORITIES_H_ */
