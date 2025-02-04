#include <stdio.h>
#include "pico/stdlib.h"
#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pio.h"
#include "pinos.h"
#include "interrupt.h"
#include "comando.h"


int main()
{
    // Inicializações
    pinosInit();
    stdio_init_all();
    initializePio();

    // Configuração da interrupção com callback
    gpio_set_irq_enabled_with_callback(BUTTON_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BUTTON_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);

    while (true) {
        leitor_comando();
        sleep_ms(1000);
    }
}
