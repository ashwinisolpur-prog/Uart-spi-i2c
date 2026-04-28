# ðŸ”Œ Multi-Protocol Communication â€” UART, SPI & I2C on Microcontroller

![Embedded Systems](https://img.shields.io/badge/Domain-Embedded%20Systems-blue)
![Language](https://img.shields.io/badge/Language-C-green)
![Platform](https://img.shields.io/badge/Platform-Arduino%20%2F%20ESP32-orange)
![Status](https://img.shields.io/badge/Status-Complete-brightgreen)

A hands-on embedded systems project demonstrating configuration and usage of three major serial communication protocols â€” **UART**, **SPI**, and **I2C** â€” on a microcontroller. Each protocol is implemented from scratch using register-level C programming.

---

## ðŸ“Œ What This Project Does

- Configures **UART** for serial communication between microcontroller and PC terminal
- Sets up **SPI** for high-speed data transfer with a peripheral device
- Implements **I2C** to read data from a sensor using master-slave addressing
- Uses **hardware timers and interrupts** to handle time-sensitive operations without busy-waiting

---

## ðŸ› ï¸ Hardware Used

| Component | Purpose |
|---|---|
| Arduino / ESP32 | Main microcontroller |
| DHT22 / BMP280 Sensor | I2C data source |
| 16x2 Character LCD | Display output |
| Jumper wires & breadboard | Circuit connections |

---

## ðŸ“ Project Structure

```
â”œâ”€â”€ src/
â”‚   â”œâ”€â”€ uart_config.c       # UART initialization and transmit/receive
â”‚   â”œâ”€â”€ spi_config.c        # SPI master configuration
â”‚   â”œâ”€â”€ i2c_sensor.c        # I2C sensor read functions
â”‚   â”œâ”€â”€ timer_interrupt.c   # Timer setup and ISR handlers
â”‚   â””â”€â”€ main.c              # Main application logic
â”œâ”€â”€ include/
â”‚   â””â”€â”€ config.h            # Pin definitions and constants
â”œâ”€â”€ circuit_diagram.png     # Hardware connection diagram
â””â”€â”€ README.md
```

---

## âš™ï¸ How to Run

1. Clone this repository:
   ```bash
   git clone https://github.com/ashwini-solpur.prog/uart-spi-i2c-protocols.git
   ```

2. Open in Arduino IDE or your preferred embedded IDE

3. Connect hardware as per `circuit_diagram.png`

4. Flash to your board and open Serial Monitor at **9600 baud**

---

## ðŸ” Key Concepts Demonstrated

- **Register-level peripheral configuration** (no high-level library wrappers)
- **Interrupt Service Routines (ISR)** for non-blocking timer events
- **GPIO control** for digital I/O and LCD interfacing
- **ADC reading** from analog sensor pins
- **Protocol debugging** via UART serial output

---

## ðŸ“¸ Demo

>

<p align="center">
  <img src="project_demo.png" alt="Multi-Protocol Embedded System Setup" width="800">


---

## ðŸ‘©â€ðŸ’» About Me

**Ashwini Solpure** â€” Embedded Systems Engineer (Entry Level)
- ðŸ“§ solpurashu@gmail.com
- ðŸ“ Bengaluru, India
- ðŸŽ“ B.E. Electrical & Electronics Engineering â€” CGPA 8.06
- ðŸ… Govt. of India Certified â€” Advanced Embedded Systems (Skill India / NSDC)

---

## ðŸ“„ License

This project is open source under the [MIT License](LICENSE).
