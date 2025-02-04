#include <stdio.h>
#include "pico/stdlib.h"
#include "pio.h"

// Variáveis globais
static volatile uint a = 1;
static volatile uint32_t last_time_A = 0; // Armazena o tempo do último evento (em microssegundos)
static volatile uint32_t last_time_B = 0;
bool led_on_g = false; // Estado do led verde inicialmente desligado
bool led_on_b = false; // Estado do led azul inicialmente desligado

// Função responsável pelo debounce
bool debounce(volatile uint32_t *last_time, uint32_t debounce_time)
{
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    if (current_time - *last_time > debounce_time)
    {
        *last_time = current_time;
        return true;
    }
    return false;
}

// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events)
{
    uint32_t current_time = to_us_since_boot(get_absolute_time());

    // Ligar e desligar o led verde ao apertar o botão A
    if (gpio == BUTTON_A && debounce(&last_time_A, 200000))
    {
        last_time_A = current_time;
        printf("A: %d\n", a); // Para controle quando se usa o monitor serial para verificar se há bouncing
        a++;
        if (led_on_g == false)
        {
            led_on_g = true;
            gpio_put(PIN_LED_G, led_on_g);
        }
        else if (led_on_g == true)
        {
            led_on_g = false;
            gpio_put(PIN_LED_G, led_on_g);
        }
    }
    // Ligar e desligar o led verde ao apertar o botão A
    else if (gpio == BUTTON_B && debounce(&last_time_A, 200000))
    {
        last_time_B = current_time;
        printf("B: %d\n", a);
        a++;
        {
            if (led_on_b == false)
            {
                led_on_b = true;
                gpio_put(PIN_LED_B, led_on_b);
            }
            else if (led_on_b == true)
            {
                led_on_b = false;
                gpio_put(PIN_LED_B, led_on_b);
            }
        }
    }
}