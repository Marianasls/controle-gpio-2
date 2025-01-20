#include <stdio.h>
#include "pico/stdlib.h"

// Definições dos pinos
#define LED_VERDE 11
#define LED_AZUL 12
#define LED_VERMELHO 13
#define BUZZER 21

// Função para desligar todos os LEDs
void desligar_leds() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
}

// Função para acionar o buzzer por 2 segundos
void acionar_buzzer() {
    gpio_put(BUZZER, 1);
    sleep_ms(2000);
    gpio_put(BUZZER, 0);
}

int main() {
    // Inicialização da UART
    stdio_init_all();

    // Configuração dos pinos como saída
    gpio_init(LED_VERDE);
    gpio_set_dir(LED_VERDE, GPIO_OUT);

    gpio_init(LED_AZUL);
    gpio_set_dir(LED_AZUL, GPIO_OUT);

    gpio_init(LED_VERMELHO);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);

    gpio_init(BUZZER);
    gpio_set_dir(BUZZER, GPIO_OUT);

    // Loop principal
    printf("Sistema iniciado. Aguardando comandos via UART...\n");

    while (true) {
        char comando[20];

        if (scanf("%s", comando) == 1) {
            printf("Comando recebido: %s\n", comando);

            if (strcmp(comando, "VERDE") == 0) {
                desligar_leds();
                gpio_put(LED_VERDE, 1);
                printf("LED verde ligado.\n");
            } else if (strcmp(comando, "AZUL") == 0) {
                desligar_leds();
                gpio_put(LED_AZUL, 1);
                printf("LED azul ligado.\n");
            } else if (strcmp(comando, "VERMELHO") == 0) {
                desligar_leds();
                gpio_put(LED_VERMELHO, 1);
                printf("LED vermelho ligado.\n");
            } else if (strcmp(comando, "BRANCO") == 0) {
                gpio_put(LED_VERDE, 1);
                gpio_put(LED_AZUL, 1);
                gpio_put(LED_VERMELHO, 1);
                printf("Todos os LEDs ligados (branco).\n");
            } else if (strcmp(comando, "DESLIGAR") == 0) {
                desligar_leds();
                printf("Todos os LEDs desligados.\n");
            } else if (strcmp(comando, "BUZZER") == 0) {
                acionar_buzzer();
                printf("Buzzer acionado por 2 segundos.\n");
            } else if (strcmp(comando, "REBOOT") == 0) {
                printf("Reiniciando o sistema...\n");
                sleep_ms(1000);
                watchdog_reboot(0, 0, 0); // Reinicia o sistema
            } else {
                printf("Comando inválido.\n");
            }
        }
    }

    return 0;
}