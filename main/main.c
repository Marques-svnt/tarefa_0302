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


int main()
{
    // Inicializações
    pinosInit();
    stdio_init_all();
    initializePio();


    while (true) {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}
