#include <avr/io.h>
#include <stdbool.h>
#include <util/delay.h>
#include <avr/interrupt.h>

#define CLOCK_RATE 16000000
#define PRESCALER 10
#define COUNTER_VALUE (CLOCK_RATE >> PRESCALER) // How many clock tics to wait to get an interrupt

ISR(TIMER1_COMPA_vect)
{
    PORTB ^= _BV(PORTB5);
}

int main()
{

    DDRB |= ~_BV(PORTB0);
    DDRB |= _BV(PORTB5);
    OCR1A = COUNTER_VALUE; // Output compare register for timer 1

    TCCR1A = 0x00;                       // Timer counter configuration register for timer 1
    TCCR1B |= (1 << WGM12);              // for CTC mode (clear timer on compare).
                                         // each clocktick the value of timer is compared to OCR1A register.
                                         // if matches clear timer and give interrupt.
    TCCR1B |= (1 << CS10) | (1 << CS12); // set the prescaler to divide values by 1024.
                                         // sets the CS10th and CS12th bits 1.

    TIMSK1 |= (1 << OCIE1A); // Timwe inturrupt mask register.
                             // sets the OCIE (output compare interrupt enable)

    sei(); // enables interrupts

    while (true)
    {
        PORTB |= _BV(PORTB0);

        if (!(PINB & _BV(PORTB0)))
        {
            // PORTB ^= _BV(PORTB5);
            // _delay_ms(500);
            return 0;
        }
    };

    return 0;
}