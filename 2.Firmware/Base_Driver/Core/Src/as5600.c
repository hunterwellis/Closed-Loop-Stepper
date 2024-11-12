/*
 * as5600.c
 *
 *  Created on: Nov 11, 2024
 *      Author: hunter
 */


#include "as5600.h"

// Read angle
float AS5600_Angle(I2C_HandleTypeDef *hi2c1){

	//enc->rawValue = ((AS5600_Reg(hi2c1, enc, RAW_ANGLE_MSBS) & 0x0F) << 8) | AS5600_Reg(hi2c1, enc, RAW_ANGLE_LSBS);
	uint8_t msbs = AS5600_Reg(hi2c1, RAW_ANGLE_MSBS);
	uint8_t lsbs = AS5600_Reg(hi2c1, RAW_ANGLE_LSBS);

    // Combine the MSB and LSB to form the 12-bit raw angle value
    uint16_t rawValue = ((msbs & 0x0F) << 8) | lsbs;
    return (rawValue * 360.0f) / 4096.0f;

}

// Read from register
uint8_t AS5600_Reg(I2C_HandleTypeDef *hi2c1, uint8_t address){
	uint8_t data = 0;
	// request from encoder register
	if ( HAL_I2C_Master_Transmit(hi2c1, AS5600_ADDR, &address, 1, HAL_MAX_DELAY) != HAL_OK ) {
		return 0xFF;
	} else {
		// Read 2 bytes from the encoder register
		if ( HAL_I2C_Master_Receive(hi2c1, AS5600_ADDR, &data, 1, HAL_MAX_DELAY) != HAL_OK ) {
			return 0xFF;
		} else {
			//Combine the bytes
			return data;
		}
	}
}
