CC=avr-gcc
CFLAGS= -Os -DF_CPU=16000000UL -mmcu=atmega328p


all:button.out # chanage this to change code.

USBPORT:=$(shell ls /dev/ttyACM*)

%.out: %.c
	$(CC) $(CFLAGS) $< -o $@

%.hex: %.out
	avr-objcopy -O ihex -R .eeprom $< $@

install.%: %.hex
	avrdude -F -V -c arduino -p ATMEGA328P -P $(USBPORT) -b 115200 -U flash:w:$<

clean:
	rm -f *.hex *.out

