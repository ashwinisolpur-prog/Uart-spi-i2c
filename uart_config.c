/*
 * uart_config.c
 * UART Initialization and Communication
 * Author: Ashwini Solpure
 * Platform: ESP32 / Arduino
 * Description: Configures UART for serial communication
 *              between microcontroller and PC terminal
 */

#include "uart_config.h"

/* -----------------------------------------------
 * UART Initialization
 * Baud Rate: 9600
 * Data Bits: 8
 * Stop Bits: 1
 * Parity   : None
 * ----------------------------------------------- */
void UART_Init(void) {
    /* Set baud rate register */
    UBRR0H = (unsigned char)(UBRR_VALUE >> 8);
    UBRR0L = (unsigned char)(UBRR_VALUE);

    /* Enable transmitter and receiver */
    UCSR0B = (1 << RXEN0) | (1 << TXEN0);

    /* Set frame format: 8 data bits, 1 stop bit */
    UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
}

/* -----------------------------------------------
 * Transmit a single byte via UART
 * ----------------------------------------------- */
void UART_TransmitByte(unsigned char data) {
    /* Wait until transmit buffer is empty */
    while (!(UCSR0A & (1 << UDRE0)));
    UDR0 = data;
}

/* -----------------------------------------------
 * Transmit a null-terminated string via UART
 * ----------------------------------------------- */
void UART_TransmitString(const char* str) {
    while (*str != '\0') {
        UART_TransmitByte(*str);
        str++;
    }
}

/* -----------------------------------------------
 * Receive a single byte via UART
 * Returns: received byte
 * ----------------------------------------------- */
unsigned char UART_ReceiveByte(void) {
    /* Wait until data is received */
    while (!(UCSR0A & (1 << RXC0)));
    return UDR0;
}

/* -----------------------------------------------
 * Print integer value over UART
 * ----------------------------------------------- */
void UART_PrintInt(int value) {
    char buffer[10];
    int i = 0;

    if (value == 0) {
        UART_TransmitByte('0');
        return;
    }

    if (value < 0) {
        UART_TransmitByte('-');
        value = -value;
    }

    while (value > 0) {
        buffer[i++] = '0' + (value % 10);
        value /= 10;
    }

    /* Print digits in reverse order */
    for (int j = i - 1; j >= 0; j--) {
        UART_TransmitByte(buffer[j]);
    }
}
