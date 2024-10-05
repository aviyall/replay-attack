#include <RCSwitch.h>

RCSwitch my_rf = RCSwitch();  // An object for the rf module

const int button = 4;  // pin connected to the button
bool signal = false;
int binary_value;
int bitlength;  
int reci_delay;  
int protocol;

void setup() {
  Serial.begin(9600);
  
  my_rf.enableReceive(0);  // Receiver on interrupt 0 => that is pin 2 on arduino uno/nano
  my_rf.enableTransmit(3); // Transmitter on pin 3, can be any digital pin

  pinMode(button, INPUT_PULLUP);  // set the button pin as input with internal pull-up resistor
}

void loop() {
  // capture the signal
  if (my_rf.available()) { 
    binary_value = my_rf.getReceivedValue();
    bitlength = my_rf.getReceivedBitlength();
    reci_delay = my_rf.getReceivedDelay();
    protocol = my_rf.getReceivedProtocol();
    
    // display captured values
    if (binary_value != 0) {
      Serial.print("Received code: ");
      Serial.println(binary_value);
      Serial.print("Bit length: ");
      Serial.println(bitlength);
      Serial.print("Delay: ");
      Serial.println(reci_delay);
      Serial.print("Protocol: ");
      Serial.println(protocol);

      signal = true;  // This will indicate a signal is captured
      my_rf.resetAvailable();  // reset the receiver for capturing next signal
    }
  }

  // if signal is captured and button is pressed, signal is transmitted
  if (signal && digitalRead(button) == LOW) {
    my_rf.setProtocol(protocol);  // set the protocol
    my_rf.send(binary_value, bitlength);  // send the stored values
    Serial.println("signal retransmitted.");
    delay(500);  // delay
  }
}
