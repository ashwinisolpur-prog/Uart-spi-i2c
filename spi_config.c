/*
 * spi_config.c
 * SPI Master Configuration and Communication
 * Author: Ashwini Solpure
 * Platform: ESP32 / Arduino
 * Description: Configures SPI in master mode for
 *              high-speed peripheral communication
 */

#include "spi_config.h"

/* -----------------------------------------------
 * SPI Initialization - Master Mode
 * Clock: FOSC/16
 * Mode : 0 (CPOL=0, CPHA=0)
 * Order: MSB First
 * ----------------------------------------------- */
void SPI_Init(void) {
    /* Set MOSI, SCK, SS as output; MISO as input */
    SPI_DDR  |=  (1 << SPI_MOSI) | (1 << SPI_SCK) | (1 << SPI_SS);
    SPI_DDR  &= ~(1 << SPI_MISO);

    /* Set SS high (deselect slave) */
    SPI_PORT |= (1 << SPI_SS);

    /* Enable SPI, set as Master, clock rate FOSC/16 */
    SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}

/* -----------------------------------------------
 * Select SPI Slave (pull SS low)
 * ----------------------------------------------- */
void SPI_SlaveSelect(void) {
    SPI_PORT &= ~(1 << SPI_SS);
}

/* -----------------------------------------------
 * Deselect SPI Slave (pull SS high)
 * ----------------------------------------------- */
void SPI_SlaveDeselect(void) {
    SPI_PORT |= (1 << SPI_SS);
}

/* -----------------------------------------------
 * Transmit and Receive one byte via SPI
 * Returns: received byte from slave
 * ----------------------------------------------- */
unsigned char SPI_TransceiveByte(unsigned char data) {
    /* Load data into SPI data register */
    SPDR = data;

    /* Wait for transmission to complete */
    while (!(SPSR & (1 << SPIF)));

    /* Return received data */
    return SPDR;
}

/* -----------------------------------------------
 * Write a buffer of bytes to SPI slave
 * ----------------------------------------------- */
void SPI_WriteBuffer(unsigned char* buffer, unsigned int length) {
    SPI_SlaveSelect();

    for (unsigned int i = 0; i < length; i++) {
        SPI_TransceiveByte(buffer[i]);
    }

    SPI_SlaveDeselect();
}

/* -----------------------------------------------
 * Read a buffer of bytes from SPI slave
 * ----------------------------------------------- */
void SPI_ReadBuffer(unsigned char* buffer, unsigned int length) {
    SPI_SlaveSelect();

    for (unsigned int i = 0; i < length; i++) {
        buffer[i] = SPI_TransceiveByte(0xFF); /* Send dummy byte */
    }

    SPI_SlaveDeselect();
}
