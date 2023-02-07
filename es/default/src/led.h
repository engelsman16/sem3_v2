#ifndef LED_H
#define LED_H

#include <stm32f303xe.h>

class Led
{
public:
    Led(GPIO_TypeDef *port, uint16_t pin);
    void init();
    void on();
    void off();
    void toggle();

private:
    GPIO_TypeDef *port;
    uint16_t pin;
};

#endif
