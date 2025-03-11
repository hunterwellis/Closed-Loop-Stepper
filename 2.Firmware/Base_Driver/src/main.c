#include <libopencm3/stm32/rcc.h>
#include <libopencm3/stm32/gpio.h>
#include "as5600.h"

void gpio_setup(void){

    rcc_periph_clock_enable(RCC_GPIOC);
    rcc_periph_clock_enable(RCC_GPIOA);
    
    // enable PC13 (--> LED on bluepill)
    gpio_set_mode(GPIOC,
            GPIO_MODE_OUTPUT_2_MHZ,
            GPIO_CNF_OUTPUT_PUSHPULL,
            GPIO13);

    // H-Bridge Inputs
    // A+
    gpio_set_mode(GPIOA,
            GPIO_MODE_OUTPUT_2_MHZ,
            GPIO_CNF_OUTPUT_PUSHPULL,
            GPIO4);
    // A-
    gpio_set_mode(GPIOA,
            GPIO_MODE_OUTPUT_2_MHZ,
            GPIO_CNF_OUTPUT_PUSHPULL,
            GPIO5);
    // B+
    gpio_set_mode(GPIOA,
            GPIO_MODE_OUTPUT_2_MHZ,
            GPIO_CNF_OUTPUT_PUSHPULL,
            GPIO6);
    // B-
    gpio_set_mode(GPIOA,
            GPIO_MODE_OUTPUT_2_MHZ,
            GPIO_CNF_OUTPUT_PUSHPULL,
            GPIO7);

}

static void i2c_setup(void){

    rcc_periph_clock_enable(RCC_I2C1);

    // config GPIO pins for I2C1: PB6 (SCL) & PB7 (SDA)
    gpio_set_mode(GPIOB, GPIO_MODE_OUTPUT_50_MHZ,
            GPIO_CNF_OUTPUT_ALTFN_OPENDRAIN,
            GPIO_I2C1_SCL | GPIO_I2C1_SDA);

    i2c_peripheral_disable(I2C1);

    i2c_set_clock_frequency(I2C1, AS5600_ADDR);
    i2c_set_ccr(I2C1, 180);  // CCR = PCLK1 / (2 * 100kHz)
    i2c_set_trise(I2C1, 37); // TRISE = (1/PCLK1) * 1µs + 1

    // Enable I2C1
    i2c_peripheral_enable(I2C1);

}

static void pwm_setup(void){

}

static void can_setup(void){

}

int main(void){
    
    gpio_setup();
    i2c_setup();

    while(1){
        
        /*uint8_t message = 0;*/
        /**/
        /*// start communication and send data*/
        /*i2c_send_start(I2C1);*/
        /*while (!(I2C_SR1(I2C1) & I2C_SR1_SB)); // wait for START condition */
        /**/
        /*i2c_send_7bit_address(I2C1, AS5600_ADDR, I2C_READ);*/
        /*while (!(I2C_SR1(I2C1) & I2C_SR1_ADDR)); // wait for slave ack*/
        /**/
        /*(void)I2C_SR2(I2C1); // clear ADDR flag*/
        /**/
        /*// master ack */
        /*i2c_enable_ack(I2C1);*/
        /*i2c_send_stop(I2C1);*/
        /**/
        /*while (!(I2C_SR1(I2C1) & I2C_SR1_RxNE));*/
        /*message = i2c_get_data(I2C1);*/
        /**/
        /*i2c_send_stop(I2C1); // Stop communication*/
        /**/
        /*(void)message;*/
        // blink led
        for (int i = 0; i < 1000000; i++){
            __asm__("nop");
        }
        
        gpio_toggle(GPIOC, GPIO13);

    }

    return 0;
}

