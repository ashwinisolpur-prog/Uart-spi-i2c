/*
 * config.h
 * Pin Definitions and System Constants
 * Author: Ashwini Solpure
 */

#ifndef CONFIG_H
#define CONFIG_H

#include <avr/io.h>
#include <avr/interrupt.h>

/* CPU Clock Frequency */
#define F_CPU           16000000UL

/* UART Baud Rate */
#define BAUD_RATE       9600
#define UBRR_VALUE      ((F_CPU / (16UL * BAUD_RATE)) - 1)

/* SPI Pin Definitions */
#define SPI_DDR         DDRB
#define SPI_PORT        PORTB
#define SPI_MOSI        PB3
#define SPI_MISO        PB4
#define SPI_SCK         PB5
#define SPI_SS          PB2

/* I2C Sensor Definitions */
#define SENSOR_ADDR         0x76    /* BMP280 default I2C address */
#define TEMP_REGISTER       0xFA
#define HUMIDITY_REGISTER   0xFD

/* LCD Pin Definitions */
#define LCD_DDR         DDRD
#define LCD_PORT        PORTD
#define LCD_RS          PD0
#define LCD_EN          PD1
#define LCD_D4          PD4
#define LCD_D5          PD5
#define LCD_D6          PD6
#define LCD_D7          PD7

#endif /* CONFIG_H */
