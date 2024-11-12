/*
 * as5600.h
 *
 *  Created on: Nov 11, 2024
 *      Author: hunter
 */

#ifndef INC_AS5600_H_
#define INC_AS5600_H_s

#include "stm32f1xx_hal.h"
#include <string.h>

static const uint8_t AS5600_ADDR = 0x36 << 1; // AS5600 Address
static const uint8_t RAW_ANGLE_MSBS = 0x0C;
static const uint8_t RAW_ANGLE_LSBS = 0x0D;

float AS5600_Angle(I2C_HandleTypeDef *hi2c1);
uint8_t AS5600_Reg(I2C_HandleTypeDef *hi2c1, uint8_t address);

#endif /* INC_AS5600_H_ */
