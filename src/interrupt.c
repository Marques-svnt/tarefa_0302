#include <stdio.h>
#include "pico/stdlib.h"
#include "pio.h"
#include "display.h"

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
        printf("Botão A: %d\n", a); // Para controle quando se usa o monitor serial para verificar se há bouncing
        a++;
        if (led_on_g == false)
        {
            led_on_g = true;
            gpio_put(PIN_LED_G, led_on_g);

            printf("Ligando o LED verde\n");

            display_limpa();
            display("Ligando LED", 15, 20);
            display("Verde", 45, 35);
        }
        else if (led_on_g == true)
        {
            led_on_g = false;
            gpio_put(PIN_LED_G, led_on_g);

            printf("Desligando o LED verde\n");

            display_limpa();
            display("Desligando LED", 10, 20);
            display("Verde", 45, 35);
        }
    }

    // Ligar e desligar o led azul ao apertar o botão B
    else if (gpio == BUTTON_B && debounce(&last_time_B, 200000))
    {
        last_time_B = current_time;
        printf("Botão B: %d\n", a);
        a++;
        if (led_on_b == false)
        {
            led_on_b = true;
            gpio_put(PIN_LED_B, led_on_b);

            printf("Ligando o LED azul\n");

            display_limpa();
            display("Ligando LED", 15, 20);
            display("Azul", 45, 35);
        }
        else if (led_on_b == true)
        {
            led_on_b = false;
            gpio_put(PIN_LED_B, led_on_b);

            printf("Desligando o LED azul\n");

            display_limpa();
            display("Desligando LED", 10, 20);
            display("Azul", 45, 35);
        }
    }
}