/*
 * DESIoT_device.c
 *
 *  Created on: Jun 20, 2023
 *      Author: ADMIN
 */


#include "DESIoT_device.h"

void DESIoT_begin() {

}

void DESIoT_loop() {

}

void DESIOT_Rx1byte(uint8_t rxByte)
{

}

/**
 * Send a data packet requiring to assign an integer to the gateway.
 */
void DESIoT_assignInt(uint8_t VS, size_t integer)
{
	uint8_t dataPacket[DESIOT_CMD_LEN + DESIOT_DATALEN_LEN + DESIOT_ASSIGN_INT_PKG_LEN] = {0};

	DESIoT_dataPacket_t *pDataPacket = (DESIoT_dataPacket_t*)dataPacket;

	pDataPacket->cmd = DESIOT_CMD_ASSIGN_VIRTUAL_STORAGE;
	pDataPacket->dataLen = sizeof(integer);

	uint8_t *data = (dataPacket + DESIOT_CMD_LEN + DESIOT_DATALEN_LEN);
	data[0] = VS; // assign VS
	memcpy(data + 1, &integer, sizeof(integer)); // assign integer

	DESIoT_sendDataPacket(sizeof(dataPacket), dataPacket);
}


/**
 *
 */
void DESIoT_sendDataPacket(const size_t dataLen, uint8_t *data)
{
	uint8_t frame[DESIOT_HEADERS_LEN + dataLen + DESIOT_CRC_LEN];
	memset(frame, 0, sizeof(frame));

	DESIoT_headFrame_t *headFrame = (DESIoT_headFrame_t*)frame;
	DESIoT_trailFrame_t *trailFrame = (DESIoT_trailFrame_t*)(frame + sizeof(frame) - (DESIOT_TRAIL_LEN + DESIOT_CRC_LEN));

	headFrame->h1 = DESIOT_H1_DEFAULT;
	headFrame->h2 = DESIOT_H2_DEFAULT;
	trailFrame->t1 = DESIOT_T1_DEFAULT;
	trailFrame->t2 = DESIOT_T2_DEFAULT;

	// set data packet to frame
	memcpy(frame + DESIOT_HEAD_LEN, data, dataLen);

	trailFrame->crc = 0;
	DESIOT_SENDBYTES_F_NAME(sizeof(frame), frame);
}

DESIOT_ATT_WEAK DESIOT_SENDBYTES
{

}
