#define AVR_GPIO_H //importa os registradores do avr para controle direto do hardware
#include <avr/io.h> 

#define GPIO_OUTPUT 1
#define GPIO_INPUT  0 
#define HIGH        1
#define LOW         0


static inline void gpio_setmode(volatile uint8_t *ddr, uint8_t pin, uint8_t mode) {
    if (mode == GPIO_OUTPUT) {
        *ddr |= (1 << pin); //define os pinos como saida
    } else {
        *ddr &= ~(1 << pin); // define os pinos como entrada
    }
}

static inline void gpio_write(volatile uint8_t *port, uint8_t pin, uint8_t value) {
    if (value == HIGH) {// liga ou desliga os pinos do microcontrolador
        *port |= (1 << pin);//define o pino como ligado
    } else {
        *port &= ~(1 << pin); // define o pino como desligado
    }
}

#endif
