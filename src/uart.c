#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "pio.h"
#include "display.h"

// Variável global para armazenar a cor (Entre 0 e 255 para intensidade)
uint8_t led_r = 0;   // Intensidade do vermelho
uint8_t led_g = 0;   // Intensidade do verde
uint8_t led_b = 100; // Intensidade do azul

void uart_handler()
{
    if (stdio_usb_connected())
    { // Certifica-se de que o USB está conectado
        char c;
        printf("Digite um comando (0 a 9): \n");
        if (scanf("%c", &c) == 1) // Lê caractere da entrada padrão
        {
            printf("Recebido: '%c'\n", c);

            display_limpa(); // Limpa o display

            char caractere[50];                              // Buffer para o texto a ser exibido
            snprintf(caractere, sizeof(caractere), "%c", c); // Formata o caractere para ser inserido como texto no display

            // Exibe o caractere na tela do display
            display("Caractere", 30, 20);
            display(caractere, 60, 35);

            // Checar qual matriz deve ligar
            switch (c)
            {
            case '0':
                set_one_led(0, led_r, led_g, led_b);
                break;
            case '1':
                set_one_led(1, led_r, led_g, led_b);
                break;
            case '2':
                set_one_led(2, led_r, led_g, led_b);
                break;
            case '3':
                set_one_led(3, led_r, led_g, led_b);
                break;
            case '4':
                set_one_led(4, led_r, led_g, led_b);
                break;
            case '5':
                set_one_led(5, led_r, led_g, led_b);
                break;
            case '6':
                set_one_led(6, led_r, led_g, led_b);
                break;
            case '7':
                set_one_led(7, led_r, led_g, led_b);
                break;
            case '8':
                set_one_led(8, led_r, led_g, led_b);
                break;
            case '9':
                set_one_led(9, led_r, led_g, led_b);
                break;
            default:
                set_one_led(10, led_r, led_g, led_b);
                break;
            }
        }
    }
}