#include "hardware/gpio.h"
#include "pico/stdlib.h"
#include <stdio.h>

const int BTN_PIN_G = 26;
const int BTN_PIN_R = 28;
const int LED_PIN_R = 4;
const int LED_PIN_G = 6;

int main() {
  stdio_init_all();

  gpio_init(BTN_PIN_G);
  gpio_set_dir(BTN_PIN_G, GPIO_IN);
  gpio_pull_up(BTN_PIN_G);

  gpio_init(BTN_PIN_R);
  gpio_set_dir(BTN_PIN_R, GPIO_IN);
  gpio_pull_up(BTN_PIN_R);

  gpio_init(LED_PIN_R);
  gpio_set_dir(LED_PIN_R, GPIO_OUT);
  gpio_init(LED_PIN_G);
  gpio_set_dir(LED_PIN_G, GPIO_OUT);

  bool led_state_1 = false;
  bool led_state_2 = false;

  while (true) {
    if (!gpio_get(BTN_PIN_G)) {
      led_state_1 = !led_state_1;
      gpio_put(LED_PIN_G, led_state_1);
      sleep_ms(250);
    }
    if (!gpio_get(BTN_PIN_R)) {
      led_state_2 = !led_state_2;
      gpio_put(LED_PIN_R, led_state_2);
      sleep_ms(250);
    }
  }
}
