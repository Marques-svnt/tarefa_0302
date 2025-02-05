#ifndef DISPLAY_H
#define DISPLAY_H

//Declaração da função de display
void gpio_irq_handler(uint gpio, uint32_t events);
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C

#endif