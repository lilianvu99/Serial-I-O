# Serial-I-O
For this Lab assignment, your program is required to transmit the characters in your Red ID through the built-in USART port on the AVR Xplained mini 328 board. Simply use the built-in USART hardware of the AVR to transmit a serial string that contains your Red ID. You must set up the USART's serial mode and bit rate (a.k.a. baud rate) to 9600 bits/sec, 8 data bits, 1 stop bit, and poll the transmit status register to wait until it is ready before writing an output data byte to the USART's serial data register. The final output demonstration of the assignment is to show the characters corresponding to the 9 digits of your Red ID followed by carriage return and linefeed followed by a 500ms delay which must be repeated continuously at 9600 bits per second (one-bit period = 1/9600 seconds, ~100us/bit, for 10 bits, ~1ms per character). The Atmel Xplained Mini board will be the Transmitter, you must set up your computer as a USART (Serial) Receiver using PuTTY and the FT232R Breakout board for the final lab 3 demonstration. 