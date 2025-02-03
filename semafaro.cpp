
#include <avr/io.h> 
#include <xinu.h>
#include "avr_gpio.h"

#define RED_PIN     PB0  
#define YELLOW_PIN  PB1  
#define GREEN_PIN   PB2  

sid32 green_ready, yellow_ready, red_ready;

void init_leds() {
    gpio_setmode(&DDRB, RED_PIN, GPIO_OUTPUT);
    gpio_setmode(&DDRB, YELLOW_PIN, GPIO_OUTPUT);
    gpio_setmode(&DDRB, GREEN_PIN, GPIO_OUTPUT);

    gpio_write(&PORTB, RED_PIN, LOW);
    gpio_write(&PORTB, YELLOW_PIN, LOW); 
    gpio_write(&PORTB, GREEN_PIN, LOW);
}

void set_light(uint8_t led_pin) {
    gpio_write(&PORTB, RED_PIN, LOW); 
    gpio_write(&PORTB, YELLOW_PIN, LOW);
    gpio_write(&PORTB, GREEN_PIN, LOW);

    gpio_write(&PORTB, led_pin, HIGH);
    
}


int green_process(int nargs, char *args[]) {
    while (1) {
        wait(green_ready);
        set_light(GREEN_PIN);
        sleep(5);  
        signal(yellow_ready);
    return 0;
}


int yellow_red_process(int nargs, char *args[]) {
    while (1) {
        wait(yellow_ready);  
        set_light(YELLOW_PIN);
        sleep(2);  
        signal(red_ready); 

        wait(red_ready);  
        set_light(RED_PIN);
        sleep(5);  
        signal(green_ready); 
    }
    return 0;
}


process main(void) {
    init_leds(); 


    green_ready = semcreate(1); 
    yellow_ready = semcreate(0); 
    red_ready = semcreate(0); 


    resume(create(green_process, 256, 20, "Green", 0));
    resume(create(yellow_red_process, 256, 20, "YellowRed", 0));

    return OK;
}
