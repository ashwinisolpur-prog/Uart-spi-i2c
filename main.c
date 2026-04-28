/*
 * main.c
 * Multi-Protocol Embedded Communication System
 * Author: Ashwini Solpure
 * Platform: ESP32 / Arduino
 * Description: Main application integrating UART, SPI,
 *              and I2C protocols with timer interrupts
 *              to read and display sensor data
 */

#include "uart_config.h"
#include "spi_config.h"
#include "i2c_sensor.h"
#include "timer_interrupt.h"
#include "config.h"

/* -----------------------------------------------
 * System Initialization
 * ----------------------------------------------- */
void System_Init(void) {
    UART_Init();
    SPI_Init();
    I2C_Init();
    Timer1_Init();

    UART_TransmitString("=================================\r\n");
    UART_TransmitString("  Multi-Protocol Embedded System \r\n");
    UART_TransmitString("  Author: Ashwini Solpure        \r\n");
    UART_TransmitString("=================================\r\n");
    UART_TransmitString("System Initialized.\r\n\r\n");
}

/* -----------------------------------------------
 * Read and display sensor data
 * ----------------------------------------------- */
void ReadAndDisplaySensor(void) {
    int temperature = Sensor_ReadTemperature();
    int humidity    = Sensor_ReadHumidity();

    UART_TransmitString("Temperature : ");
    UART_PrintInt(temperature);
    UART_TransmitString(" C\r\n");

    UART_TransmitString("Humidity    : ");
    UART_PrintInt(humidity);
    UART_TransmitString(" %\r\n");
    UART_TransmitString("-------------------------\r\n");
}

/* -----------------------------------------------
 * SPI test - write and read back a test byte
 * ----------------------------------------------- */
void SPI_Test(void) {
    unsigned char test_data = 0xA5;
    unsigned char received;

    SPI_SlaveSelect();
    received = SPI_TransceiveByte(test_data);
    SPI_SlaveDeselect();

    UART_TransmitString("SPI TX: 0xA5 | RX: 0x");
    UART_PrintInt(received);
    UART_TransmitString("\r\n");
}

/* -----------------------------------------------
 * Main Entry Point
 * ----------------------------------------------- */
int main(void) {
    System_Init();

    while (1) {
        /* Check if 1 second timer has elapsed */
        if (Timer_IsElapsed()) {

            UART_TransmitString("[T=");
            UART_PrintInt(Timer_GetCount());
            UART_TransmitString("s] ");

            /* Read sensor data via I2C */
            ReadAndDisplaySensor();

            /* Run SPI test every 5 seconds */
            if (Timer_GetCount() % 5 == 0) {
                SPI_Test();
            }
        }
        /* Main loop is non-blocking — all timing via ISR */
    }

    return 0;
}
