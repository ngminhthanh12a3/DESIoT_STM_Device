/*
 * DESIoT_device.h
 *
 *  Created on: Jun 20, 2023
 *      Author: ADMIN
 */

#ifndef INC_DESIOT_DEVICE_H_
#define INC_DESIOT_DEVICE_H_

#include <stdint.h>

void DESIoT_begin();
void DESIoT_loop();
void DESIOT_Rx1byte(uint8_t rxByte);

#endif /* INC_DESIOT_DEVICE_H_ */
