#ifndef DISPLAY_H
#define DISPLAY_H

// Declaração da função de display
void initI2C();
void display(const char *texto, int x, int y);
void display_limpa();

// Definições relacioanadas ao I2C
#define I2C_PORT i2c1
#define I2C_SDA 14
#define I2C_SCL 15
#define endereco 0x3C

#endif