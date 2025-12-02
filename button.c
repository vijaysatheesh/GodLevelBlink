#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>

int main(){
    
    DDRB |= ~_BV(PORTB0);
    while(true){
        PORTB |= _BV(PORTB0);

        if(!(PINB & _BV(PORTB0))){
            PORTB ^= _BV(PORTB5);
            _delay_ms(500);
        }
    };
    
    return 0;
}