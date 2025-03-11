/* as5600.h
 * Author: Hunter Ellis
 */

#ifndef INC_AS5600_H_
#define INC_AS5600_H_

#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/i2c.h>

#define AS5600_ADDR 0x36 // AS5600 Address
#define RAW_ANGLE_MSBS 0x0C // register for MSBS
#define RAW_ANGLE_LSBS 0x0D // register for LSBS

#endif /* INC_AS5600_H_ */
