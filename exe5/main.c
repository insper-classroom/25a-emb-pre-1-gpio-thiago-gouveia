#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"

const int BTN_PIN_G = 26;
const int BTN_PIN_B = 7;

int main() {
    stdio_init_all();

    gpio_init(BTN_PIN_G);
    gpio_set_dir(BTN_PIN_G, GPIO_IN);
    gpio_pull_up(BTN_PIN_G);

    gpio_init(BTN_PIN_B);
    gpio_set_dir(BTN_PIN_B, GPIO_IN);
    gpio_pull_up(BTN_PIN_B);
    int cnt_1 = 0;
    int cnt_2 = 0;

    while (true) {

        if (!gpio_get(BTN_PIN_G)) {
            printf("Botao G: %d\n", cnt_1++);
        }

        if (!gpio_get(BTN_PIN_B)) {
            printf("Botao B: %d\n", cnt_2++);
        }
    }
}
