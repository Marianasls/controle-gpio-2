#include "pico/stdlib.h"

#define LED_VERDE 11
#define LED_AZUL  12
#define LED_VERMELHO 13
#define BUZZER    5

void desligar_todos_gpio() {
    gpio_put(LED_VERDE, 0);
    gpio_put(LED_AZUL, 0);
    gpio_put(LED_VERMELHO, 0);
    gpio_put(BUZZER, 0);
}

void inicializar_dispositivos() {
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

int main() {
    stdio_init_all();
    inicializar_dispositivos();

    while (true) {
        desligar_todos_gpio();
        gpio_put(LED_VERDE, 1);
        sleep_ms(1000);

        desligar_todos_gpio();
        gpio_put(LED_AZUL, 1);
        sleep_ms(1000);

        desligar_todos_gpio();
        gpio_put(LED_VERMELHO, 1);
        sleep_ms(1000);
    }

    return 0;
}