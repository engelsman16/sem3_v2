#include "led.h"

Led::Led(GPIO_TypeDef *port, uint16_t pin) 
: port(port), pin(pin)
{
}

void Led::Init()
{
    port->MODER |= (port->MODER & ~(0b11 << (pin * 2))) | (0b01 << (pin * 2));
    port->OTYPER |= ~(0b1 << pin);
}

void Led::On()
{
    port->ODR |= (0b01 << pin);
}

void Led::Off()
{
    port->ODR &= ~(0b01 << pin);
}

void Led::Toggle()
{
    port->ODR ^= (0b01 << pin);
}
