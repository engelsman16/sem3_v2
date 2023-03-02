#include "button.h"

Button::Button(GPIO_TypeDef *port, uint16_t pin) 
: port(port), pin(pin)
{

}

void Button::Init()
{
    port->MODER = (port->MODER & ~(0b11 << (pin * 2))) | (0b00 << (pin * 2));
    port->PUPDR = (port->PUPDR & ~(0b11 << (pin * 2))) | (0b01 << (pin * 2));
}
