/*
 * i2c_sensor.c
 * I2C Master Communication and Sensor Reading
 * Author: Ashwini Solpure
 * Platform: ESP32 / Arduino
 * Description: Implements I2C master to read data
 *              from DHT22/BMP280 sensor using
 *              master-slave addressing
 */

#include "i2c_sensor.h"

/* -----------------------------------------------
 * I2C Initialization
 * SCL Frequency: 100kHz (Standard Mode)
 * ----------------------------------------------- */
void I2C_Init(void) {
    /* Set SCL frequency to 100kHz */
    TWSR = 0x00;                    /* Prescaler = 1 */
    TWBR = ((F_CPU / 100000) - 16) / 2;

    /* Enable TWI (I2C) module */
    TWCR = (1 << TWEN);
}

/* -----------------------------------------------
 * Generate I2C START condition
 * ----------------------------------------------- */
void I2C_Start(void) {
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

/* -----------------------------------------------
 * Generate I2C STOP condition
 * ----------------------------------------------- */
void I2C_Stop(void) {
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

/* -----------------------------------------------
 * Write one byte to I2C bus
 * ----------------------------------------------- */
void I2C_WriteByte(unsigned char data) {
    TWDR = data;
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
}

/* -----------------------------------------------
 * Read byte from I2C bus with ACK
 * ----------------------------------------------- */
unsigned char I2C_ReadACK(void) {
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

/* -----------------------------------------------
 * Read byte from I2C bus with NACK (last byte)
 * ----------------------------------------------- */
unsigned char I2C_ReadNACK(void) {
    TWCR = (1 << TWINT) | (1 << TWEN);
    while (!(TWCR & (1 << TWINT)));
    return TWDR;
}

/* -----------------------------------------------
 * Read temperature from sensor over I2C
 * Sensor Address: 0x76 (BMP280)
 * Returns: temperature in Celsius (integer)
 * ----------------------------------------------- */
int Sensor_ReadTemperature(void) {
    unsigned char msb, lsb;
    int raw_temp;

    I2C_Start();
    I2C_WriteByte(SENSOR_ADDR << 1);         /* Write mode */
    I2C_WriteByte(TEMP_REGISTER);            /* Temperature register */

    I2C_Start();                             /* Repeated START */
    I2C_WriteByte((SENSOR_ADDR << 1) | 1);  /* Read mode */

    msb = I2C_ReadACK();
    lsb = I2C_ReadNACK();
    I2C_Stop();

    raw_temp = (msb << 8) | lsb;
    return raw_temp / 100;                   /* Convert to Celsius */
}

/* -----------------------------------------------
 * Read humidity from sensor over I2C
 * Returns: humidity in percentage (integer)
 * ----------------------------------------------- */
int Sensor_ReadHumidity(void) {
    unsigned char msb, lsb;

    I2C_Start();
    I2C_WriteByte(SENSOR_ADDR << 1);
    I2C_WriteByte(HUMIDITY_REGISTER);

    I2C_Start();
    I2C_WriteByte((SENSOR_ADDR << 1) | 1);

    msb = I2C_ReadACK();
    lsb = I2C_ReadNACK();
    I2C_Stop();

    return ((msb << 8) | lsb) / 100;
}
