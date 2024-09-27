This project is based on replay attack at specific frequency 433mhz or 315mhz as per the module capabilities
Items needed:
1. Arduino board (Uno,Nano etc.)
2. 433mhz or 315mhz Radio modules (433mhz is widely used)
3. Jumper cables for connections
4. Push button (2 pin)
5. Antenna for radio modules (OPTIONAL)

Use generic radio module (FS1000A) this one:
This module can work with both 433mhz and 315mhz

![433](https://github.com/user-attachments/assets/ff3e5f46-3600-4a97-903f-3a51a0c7b552)

Connections are simple,
1. Arduino pin 2 >>> reciver input pin
2. Arduino pin 3 >>> transmitter input pin
3. connect 5v pin on reciver and transmitter to 5v pin on arduino
4. connect ground pin from reciver and transmitter to arduino ground
5. connect pins of push button to ground and pin 4 on arduino
![abc](https://github.com/user-attachments/assets/6bf3aef0-6bfd-4d96-aaa3-4495cee3fc50)

Now burn the code to adruino board by arduino ide
and test it.
