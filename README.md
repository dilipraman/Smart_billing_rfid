
# Smart Trolley System

## Overview
This project implements a Smart Trolley System using the LPC2129 microcontroller, an RFID tag, and an EM-18 RFID reader. The system is designed to manage items in a trolley, allowing users to add and remove items using RFID tags. The project utilizes external interrupts to handle RFID tag detection.

## Components Used

| Component         | Description                                      |
|-------------------|--------------------------------------------------|
| **Microcontroller** | LPC2129                                        |
| **RFID Reader**    | EM-18                                          |
| **RFID Tags**      | Various RFID tags for item identification       |
| **Display**        | LCD for user interface                          |
| **UART**           | For serial communication                        |
| **Power Supply**   | Appropriate power supply for the LPC2129 board |

## Features
- Add items to the trolley using RFID tags.
- Remove items from the trolley using RFID tags.
- Display the total price of items in the trolley.
- User-friendly interface on the LCD.
- Utilizes external interrupts for efficient RFID tag reading.

## Code Structure
- **main.c**: Contains the main logic for the Smart Trolley System.
- **INTR.c**: Handles external interrupts for adding/removing items.
- **UART.c**: Manages UART communication for RFID data transmission.
- **lcd4biit.h**: Contains functions for controlling the LCD display.
- **delay.h**: Provides delay functions for timing control.

## Usage
1. Power on the system.
2. Scan an RFID tag to add an item to the trolley.
3. Scan the corresponding RFID tag to remove an item from the trolley.
4. The total price will be displayed on the LCD.

## Acknowledgments
- [LPC2129 Documentation](https://www.nxp.com/docs/en/user-guide/UM10139.pdf)
- [EM-18 RFID Reader Documentation](https://www.electronicwings.com/nxp/em-18-rfid-reader-module)

