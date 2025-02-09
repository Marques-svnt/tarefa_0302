#include <stdio.h>
#include "pico/stdlib.h"
#include <stdlib.h>
#include "hardware/pio.h"
#include "pio.h"
#include "pinos.h"
#include "interrupt.h"
#include "uart.h"
#include "display.h"
#include "ssd1306.h"
#include "font.h"

int main()
{
    // Inicializações
    pinosInit();
    stdio_init_all();
    initializePio();
    initI2C();

    // Configuração da interrupção com callback
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    // Display inicial
    display("Aguardando", 25, 20);
    display("Comando", 35, 35);

    // Loop principal que chama o controle via UART para ligar os LEDs da matriz e exibir os caracteres digitados
    while (true)
    {
        uart_handler();
        sleep_ms(1000);
    }
}
