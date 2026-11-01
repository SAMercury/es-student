//
//  
#include <stdio.h>
#include "pico/stdlib.h"        // даёт базовые типы и функцию задержки sleep_ms
#include "hardware/gpio.h"      // функции работы с выводами микроконтроллера

const uint LED_PIN = 25;
const uint BUTTON_PIN = 15;
const uint DEBOUNCE_MS = 20;

bool get_button_debounce(uint pin)
{
    bool state = gpio_get(pin);
    sleep_ms(DEBOUNCE_MS);
    return state && gpio_get(pin);
}

int main()
{
    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    gpio_init(BUTTON_PIN);
    gpio_set_dir(BUTTON_PIN, GPIO_IN);
    gpio_pull_up(BUTTON_PIN);

    bool led = false;
    bool previous = false;

    // готовит к работе все устройства ввода-вывода, 
    // которые были выбраны в CMakeLists.txt. сразу в обе стороны: вывод и ввод.
    stdio_init_all(); // Включить канал до первого обращения к нему

    while (1)
    {
        printf("Hello, world!\n");
        sleep_ms(1000);
    }
}


