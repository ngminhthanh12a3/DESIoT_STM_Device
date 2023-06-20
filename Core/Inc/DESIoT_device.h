/*
 * DESIoT_device.h
 *
 *  Created on: Jun 20, 2023
 *      Author: ADMIN
 */

#ifndef INC_DESIOT_DEVICE_H_
#define INC_DESIOT_DEVICE_H_

#include <stdint.h>
#include <stddef.h>
#include <string.h>

// DESIoT virtual storages
#define DESIOT_VS0 0x0u
#define DESIOT_VS1 0x1u
#define DESIOT_VS2 0x2u
#define DESIOT_VS3 0x3u
#define DESIOT_VS4 0x4u
#define DESIOT_VS5 0x5u
#define DESIOT_VS6 0x6u
#define DESIOT_VS7 0x7u
#define DESIOT_VS8 0x8u
#define DESIOT_VS9 0x9u
#define DESIOT_VS10 0xAu
#define DESIOT_VS11 0xBu
#define DESIOT_VS12 0xCu
#define DESIOT_VS13 0xDu
#define DESIOT_VS14 0xEu
#define DESIOT_VS15 0xFu
#define DESIOT_VS16 0x10u
#define DESIOT_VS17 0x11u
#define DESIOT_VS18 0x12u
#define DESIOT_VS19 0x13u
#define DESIOT_VS20 0x14u
#define DESIOT_VS21 0x15u
#define DESIOT_VS22 0x16u
#define DESIOT_VS23 0x17u
#define DESIOT_VS24 0x18u
#define DESIOT_VS25 0x19u
#define DESIOT_VS26 0x1Au
#define DESIOT_VS27 0x1Bu
#define DESIOT_VS28 0x1Cu
#define DESIOT_VS29 0x1Du
#define DESIOT_VS30 0x1Eu
#define DESIOT_VS31 0x1Fu

// Lengths of packet types
#define DESIOT_H1_LEN 1u
#define DESIOT_H2_LEN 1u
#define DESIOT_HEAD_LEN (DESIOT_H1_LEN + DESIOT_H2_LEN)

#define DESIOT_T1_LEN 1u
#define DESIOT_T2_LEN 1u
#define DESIOT_TRAIL_LEN (DESIOT_T1_LEN + DESIOT_T2_LEN)

#define DESIOT_HEADERS_LEN (DESIOT_HEAD_LEN + DESIOT_TRAIL_LEN)

#define DESIOT_CRC_LEN 2u

#define DESIOT_CMD_LEN 0x1u
#define DESIOT_DATALEN_LEN 0x2u

// Length of packet assigning integer
#define DESIOT_VS_ID_LEN 0x1u
#define DESIOT_VS_INTEGER_LEN 0x4u
#define DESIOT_ASSIGN_INT_PKG_LEN (DESIOT_VS_ID_LEN + DESIOT_VS_INTEGER_LEN)

// DESIoT default values
#define DESIOT_H1_DEFAULT 0x7u
#define DESIOT_H2_DEFAULT 0x17u
#define DESIOT_T1_DEFAULT 0x7u
#define DESIOT_T2_DEFAULT 0x17u

#define DESIOT_SENDBYTES_F_NAME DESIoT_sendBytes
#define DESIOT_SENDBYTES \
	void DESIOT_SENDBYTES_F_NAME (size_t DESIOT_ATT_UNUSED size, uint8_t DESIOT_ATT_UNUSED *bytes)

// attributes
#define DESIOT_ATT_PACKED __attribute__ ((__packed__))
#define DESIOT_ATT_UNUSED __attribute__((__unused__))
#define DESIOT_ATT_WEAK __attribute__((weak))
enum DESIoTCMD {
	DESIOT_CMD_ASSIGN_VIRTUAL_STORAGE
};

typedef struct {
	uint8_t h1;
	uint8_t h2;
}DESIOT_ATT_PACKED DESIoT_headFrame_t;

typedef struct {
	uint8_t t1;
	uint8_t t2;
	uint16_t crc;
} DESIOT_ATT_PACKED DESIoT_trailFrame_t;

typedef struct{
	uint8_t cmd;
	uint16_t dataLen;
	uint8_t *data;
} DESIOT_ATT_PACKED DESIoT_dataPacket_t;

void DESIoT_begin();
void DESIoT_loop();
void DESIOT_Rx1byte(uint8_t rxByte);
void DESIoT_assignInt(uint8_t VS, size_t integer);
void DESIoT_sendDataPacket(const size_t dataLen, uint8_t *data);

// weak functions
DESIOT_SENDBYTES;
#endif /* INC_DESIOT_DEVICE_H_ */
