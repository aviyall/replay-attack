# **Replay Attack on 433MHz/315MHz Frequency using Arduino**

This project demonstrates a replay attack using an Arduino board and radio frequency modules operating at either 433MHz or 315MHz (based on the module’s capability). The primary aim is to capture and resend signals at a specific frequency, replicating the behavior of a remote control.

## **Components Needed**
1. **Arduino Board**: Uno, Nano, or other compatible models.
2. **433MHz/315MHz RF Modules**: FS1000A is recommended 
3. **Jumper Wires**: To connect components.
4. **Push Button (2-pin)**: Used to trigger transmission.
5. **Antenna for RF Module (Optional)**: Improves signal range and reliability.

### **RF Module FS1000A**
This module have two versions one working at 315mhz and the other at 433mhz the frequency used by devices varies in places but 433mhz is the most common one keep this in mind while buying this. 

![433MHz Radio Module](https://github.com/user-attachments/assets/ff3e5f46-3600-4a97-903f-3a51a0c7b552)

## **Wiring Diagram**
The following connections are required for the setup:

1. **Arduino Pin 2** → **Receiver Input Pin**
2. **Arduino Pin 3** → **Transmitter Input Pin**
3. **5V Pin (Arduino)** → **5V on both Receiver and Transmitter**
4. **GND (Arduino)** → **GND on both Receiver and Transmitter**
5. **Pin 4 (Arduino)** → One side of the push button (Other side to GND)
![fs1000a-pinout](https://github.com/user-attachments/assets/b2234e3e-bde6-494d-876f-9cd5f12cc1ca)

## Workflow
- After turning on the device it listens for incoming signals
- After capturing the signal, pressing the button causes the LED on the Arduino board to blink, and the signal is replayed once.
- Finally, pressing the reset button restarts the device, causing the code to execute from the beginning and enabling it to listen for new signals.


