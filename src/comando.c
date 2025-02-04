#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "pio.h"

// Variável global para armazenar a cor (Entre 0 e 255 para intensidade)
uint8_t led_r = 0;   // Intensidade do vermelho
uint8_t led_g = 0;   // Intensidade do verde
uint8_t led_b = 100; // Intensidade do azul
static volatile int led_index = 0;

char command; // Variável para armazenar um comando de uma letra

// Função que interpreta os comandos recebidos
void handle_command(char command)
{
    if (command == '0')
    {
        printf("Mostrando no LED o número: 0\n");
        led_index = 0;
        set_one_led(led_index, led_r, led_g, led_b);
    }
    else if (command == '1')
    {
        printf("Mostrando no LED o número: 1\n");
        led_index = 1;
        set_one_led(led_index, led_r, led_g, led_b);
    }
    else if (command == '2')
    {
        printf("Mostrando no LED o número: 2\n");
        led_index = 2;
        set_one_led(led_index, led_r, led_g, led_b);
    }
    else if (command == '3')
    {
        printf("Mostrando no LED o número: 3\n");
        led_index = 3;
        set_one_led(led_index, led_r, led_g, led_b);
    }
    else if (command == '4')
    {
        printf("Mostrando no LED o número: 4\n");
        led_index = 4;
        set_one_led(led_index, led_r, led_g, led_b);
    }
    else if (command == '5')
    {
        printf("Mostrando no LED o número: 5\n");
        led_index = 5;
        set_one_led(led_index, led_r, led_g, led_b);
    }
    else if (command == '6')
    {
        printf("Mostrando no LED o número: 6\n");
        led_index = 6;
        set_one_led(led_index, led_r, led_g, led_b);
    }
    else if (command == '7')
    {
        printf("Mostrando no LED o número: 7\n");
        led_index = 7;
        set_one_led(led_index, led_r, led_g, led_b);
    }
    else if (command == '8')
    {
        printf("Mostrando no LED o número: 8\n");
        led_index = 8;
        set_one_led(led_index, led_r, led_g, led_b);
    }
    else if (command == '9')
    {
        printf("Mostrando no LED o número: 9\n");
        led_index = 9;
        set_one_led(led_index, led_r, led_g, led_b);
    }
    else
    {
        printf("Comando inválido. Digite 'HELP' para ver os comandos disponíveis.\n");
    }
}

void leitor_comando()
{
    printf("Digite um comando (0-9): ");
    scanf(" %c", &command); // Espaço antes de %c para ignorar espaços em branco
    handle_command(command);
}
