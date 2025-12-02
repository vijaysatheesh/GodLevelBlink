#include <avr/io.h>
#include <util/delay.h>
#include <stdbool.h>

#define BLINK_DELAY 500

int main()
{
  //DDRB |= 0b00100000;S
  DDRB |= _BV(PORT5);
  while (true)
  {
    //  PORTB |= _BV(PORT5);
    //  _delay_ms(BLINK_DELAY);

    //  PORTB &= ~_BV(PORT5);
    //  _delay_ms(BLINK_DELAY);

    PORTB ^= _BV(PORT5);
    _delay_ms(BLINK_DELAY);  
  }
  
  return 0;
}
