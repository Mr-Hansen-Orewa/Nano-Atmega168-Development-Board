# Read Me

## Overview
I am designing a development board for year 11 students (15-16 year olds) to use in 2023

## Parts list
- Arduino Nano with Atmega168 controller 
- Yellow LED
- RGB LED
- Trimpot
- LDR
- DIP switch
- Button

## Pinout and Headers
 - D0 - goes to a header.
 - D1 - goes to a header.
 - D2 - momentary switch.
 - D3 - goes to a header.
 - D4 - DIP switch.
 - D5 - goes to a header.
 - D6 - goes to a header.
 - D7 - DIP switch.
 - D8 - DIP switch.
 - D9 - RGB LED Blue/Green (silkscreen issues).
 - D10 - RGB LED Blue/Green (silkscreen issues).
 - D11 - RGB LED Red.
 - D12 - goes to a header.
 - D13 - Yellow LED.
 - D14/A0 - LDR.
 - D15/A1 - trimpot.
 - D16/A2 - goes to a header.
 - D17/A3 - goes to a header.
 - D18/A4 - goes to a header.
 - D19/A5 - goes to a header.
 - A6 - goes to a header.
 - A7 - goes to a header.

## Cool bits
I used the import bmp script in the automate menu to put the logo on the silkscreen. 

I also put a testpoint rectangle in the tStop layer to leave it as exposed copper for a GND testpoint.

## Future ideas/versions
Have a qwiic / stemmaQT connector on the I2C pins its a JST SH 4-pin Vertical Connector on Adafruit.
Or have an led matrix board directly soldered to the I2C pins.
Or another button without the debounce resistor - maybe both buttons have resistors but also those solder pads to enable or disable them once shown button bounce issues.
Reverse polarity protection on/before the VIN on the nano