#  Multi-Protocol Communication- UART, SPI & I2C on Microcontroller

![Embedded Systems](https://img.shields.io/badge/Domain-Embedded%20Systems-blue)
![Language](https://img.shields.io/badge/Language-C-green)
![Platform](https://img.shields.io/badge/Platform-Arduino%20%2F%20ESP32-orange)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen)

A hands-on embedded systems project demonstrating configuration and usage of three major serial communication protocols **UART**, **SPI**, and **I2C** on a microcontroller. Each protocol is implemented from scratch using register-level C programming.

---

## What This Project Does

- Configures **UART** for serial communication between microcontroller and PC terminal
- Sets up **SPI** for high-speed data transfer with a peripheral device
- Implements **I2C** to read data from a sensor using master-slave addressing
- Uses **hardware timers and interrupts** to handle time-sensitive operations without busy-waiting

---

## Hardware Used

| Component | Purpose |
|---|---|
| Arduino / ESP32 | Main microcontroller |
| DHT22 / BMP280 Sensor | I2C data source |
| 16x2 Character LCD | Display output |
| Jumper wires & breadboard | Circuit connections |

---

## Project Structure

```
-src/uart_config.c       - UART initialization and transmit/receive
-src/spi_config.c        - SPI master configuration
-src/i2c_sensor.c        - I2C sensor read functions
-src/timer_interrupt.c   - Timer setup and ISR handlers
-src/main.c              - Main application logic
-include/config.h            - Pin definitions and constants
-circuit-diagram.jpg     - Hardware connection diagram
-README.md               -Project documentation
```

---

## How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/ashwinisolpur-prog/Uart-spi-i2c.git
   ```

2. Open in Arduino IDE or your preferred embedded IDE

3. Connect hardware as per `circuit-diagram.jpg`

4. Flash to your board and open Serial Monitor at **9600 baud**

---

## Key Concepts Demonstrated

- **Register-level peripheral configuration** (no high-level library wrappers)
- **Interrupt Service Routines (ISR)** for non-blocking timer events
- **GPIO control** for digital I/O and LCD interfacing
- **ADC reading** from analog sensor pins
- **Protocol debugging** via UART serial output

---

## Demo

![Circuit Setup](circuit-diagram.jpg)

---

## About Me

**Ashwini Solpure**  Embedded Systems Engineer (Entry Level)
- Email: solpurashu@gmail.com
- Location: Bengaluru, India
- Education: B.E. Electrical & Electronics Engineering - CGPA 8.06
- Certified: Govt. of India Certified - Advanced Embedded Systems (Skill India / NSDC)

---

##  License

This project is open source under the [MIT License](LICENSE).
