#ifndef BUTTON_H
#define BUTTON_H

#include <stm32f303xe.h>

class Button
{
public:
    Button(GPIO_TypeDef *port, uint16_t pin);
    void Init();

private:
    GPIO_TypeDef *port;
    uint16_t pin;
};

#endif
