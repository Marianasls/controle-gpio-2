#include "pico/stdlib.h"
#include <stdio.h>

#define LED_VERDE 11
#define LED_AZUL  12
#define LED_VERMELHO 13
#define BUZZER_A 21 
#define BUZZER_B 10

void desligar_todos_gpio() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
    gpio_put(BUZZER_A, 0);
    gpio_put(BUZZER_B, 0);
}

void inicializar_dispositivos() {
    gpio_init(LED_VERDE);
    gpio_init(LED_AZUL);
    gpio_init(LED_VERMELHO);
    gpio_init(BUZZER_A);
    gpio_init(BUZZER_B);

    gpio_set_dir(LED_VERDE, GPIO_OUT);
    gpio_set_dir(LED_AZUL, GPIO_OUT);
    gpio_set_dir(LED_VERMELHO, GPIO_OUT);
    gpio_set_dir(BUZZER_A, GPIO_OUT);
    gpio_set_dir(BUZZER_B, GPIO_OUT);

}

int main() {
    //inicializando os dispositivos
    stdio_init_all();

    //inicializando os pinos
    inicializar_dispositivos();
    
    //desligando todos os pinos
    desligar_todos_gpio();

    //iniciando o loop
    while (true) {
        //ligando somente o led verde
        desligar_todos_gpio();
        gpio_put(LED_VERDE, 1);
        sleep_ms(1000);

        //ligando somente o led azul
        desligar_todos_gpio();
        gpio_put(LED_AZUL, 1);
        sleep_ms(1000);

        //ligando somente o led vermelho
        desligar_todos_gpio();
        gpio_put(LED_VERMELHO, 1);
        sleep_ms(1000);

        //ligando somente o buzzer
        desligar_todos_gpio();        
        gpio_put(BUZZER_A, 1);
        gpio_put(BUZZER_B, 1);
        sleep_ms(1000);

        //acendendo todos os leds (branco)
        desligar_todos_gpio();
        gpio_put(LED_AZUL, 1);
        gpio_put(LED_VERDE, 1);
        gpio_put(LED_VERMELHO, 1);
        sleep_ms(1000);
    }

    return 0;
}