#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"

#define LED_VERDE 11
#define LED_AZUL  12
#define LED_VERMELHO 13
#define BUZZER 5

char captura_de_comando(void){
    char escolha;

    system("cls");
    printf("MENU\n\nA - Ligar LED vermelho\nB - Ligar LED verde\nC - Ligar LED azul\nD - Ligar buzzer\n");
    printf("E - Ligar tudo em sequencia\n\n");
    escolha = getchar();
    return escolha;
}

void desligar_todos_gpio(void){
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
    gpio_put(BUZZER, 0);
}

void inicializar_dispositivos(void){
    gpio_init(LED_VERDE);
    gpio_init(LED_AZUL);
    gpio_init(LED_VERMELHO);
    gpio_init(BUZZER);

    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(BUZZER, GPIO_OUT);

    desligar_todos_gpio();
}

int main(void){
    char escolha;
    stdio_init_all();
    inicializar_dispositivos();

    while (true) {
        escolha = captura_de_comando();
        desligar_todos_gpio();

        switch(escolha){
            case 'A': // Ligar LED vermelho
                gpio_put(LED_VERMELHO, 1);
                printf("LED vermelho acionado!\n");
                sleep_ms(1000);
                gpio_put(LED_VERMELHO, 0);
                break;
            case 'B': // Ligar LED verde
                gpio_put(LED_VERDE, 1);
                printf("LED verde acionado!\n");
                sleep_ms(1000);
                gpio_put(LED_VERDE, 0);
                break;
            case 'C': // Ligar LED azul
                gpio_put(LED_AZUL, 1);
                printf("LED azul acionado!\n");
                sleep_ms(1000);
                gpio_put(LED_AZUL, 0);
                break;
            case 'D': // Ligar buzzer
                gpio_put(BUZZER, 1);
                printf("Buzzer acionado!\n");
                sleep_ms(1000);
                gpio_put(BUZZER, 0);
                break;
            case 'E': // Ligar tudo em sequência
                gpio_put(LED_VERMELHO, 1);
                sleep_ms(600);
                gpio_put(LED_VERMELHO, 0);
                gpio_put(LED_VERDE, 1);
                sleep_ms(600);
                gpio_put(LED_VERDE, 0);
                gpio_put(LED_AZUL, 1);
                sleep_ms(600);
                gpio_put(LED_AZUL, 0);
                gpio_put(BUZZER, 1);
                sleep_ms(600);
                gpio_put(BUZZER, 0);
                break;
            default: // Caso o comando digitado não corresponda a nenhum dos apresentados no menu
                printf("Comando invalido. Tente novamente.\n");
        }
        desligar_todos_gpio();
    }

    return 0;
}
