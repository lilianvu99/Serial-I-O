/*
 * Lab 2.c
 *
 * Created: 6/2/2019 2:55:16 PM
 * Author : Lilian Vu
 */
#define F_CPU 16000000UL
#include <avr/io.h>
#include <stdio.h>
#include <stdlib.h>
#include <util/delay.h>
#include <string.h>
#define BAUD 9600 //define baud rate
#define BAUDRATE ((F_CPU/(BAUD*16UL)-1)) //set baud rate
void UART_init(void);
void UART_transmit(unsigned char data);
void UART_init(void) {
 UBRR0H = (BAUDRATE >> 8); //shift register right by 8 bits
 UBRR0L = BAUDRATE; //set baud rate
 UCSR0B |= (1 << TXEN0) | (1 << RXEN0); //enable receiver and transmitter
 UCSR0C |= (0 << USBS0) | (3 << UCSZ00); //8 bit data format
}
void UART_transmit (unsigned char data) {
 while (!(UCSR0A & (1 << UDRE0)));
 UDR0 = data;
}
/*unsigned char UART_receive (void) {
 while ((!(UCSR0A)) & (1 << RXC0));
 return UDR0;
}*/
int main (void) {
 
 char RedID[] = "821477716\r\n";
 UART_init();
 
 while(1) {
 int i = 0;
 for (i= 0; i < strlen(RedID); i++) {
  UART_transmit(RedID[i]);
  _delay_ms(500);
 }
 _delay_ms(500);
 }
 
 return 0;
}
