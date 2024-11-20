#include <RCSwitch.h>

RCSwitch my_rf = RCSwitch();  // An object for the RF module

const int buttonPin = 4;  // pin connected to the button
const int ledPin = 13;    // built-in LED pin

bool buttonState = HIGH;       
bool lastButtonState = HIGH; 

bool signalCaptured = false;  
int binaryValue = 0;
int bitLength = 0;      // initializing variables
int protocol = 0;

void setup() {
  Serial.begin(9600);
  
  my_rf.enableReceive(0);  // receiver on pin 2 for interrupt 0
  my_rf.enableTransmit(3); // transmitter on pin 3
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);         
  digitalWrite(ledPin, LOW);
}

void loop() {
  if (!signalCaptured && my_rf.available()) {
    binaryValue = my_rf.getReceivedValue();
    bitLength = my_rf.getReceivedBitlength();
    protocol = my_rf.getReceivedProtocol();
    
    if (binaryValue != 0) {
      Serial.print("Signal captured: ");
      Serial.println(binaryValue);
      Serial.print("Bit length: ");
      Serial.println(bitLength);
      Serial.print("Protocol: ");
      Serial.println(protocol);

      signalCaptured = true; 
      my_rf.resetAvailable();  // Reset receiver 
    }
  }

  buttonState = digitalRead(buttonPin);  

  if (buttonState == LOW && lastButtonState == HIGH) {
    // Blink the LED once
    digitalWrite(ledPin, HIGH);
    delay(200);  
    digitalWrite(ledPin, LOW);

    if (signalCaptured) {
      my_rf.setProtocol(protocol);  // Set the protocol for transmission
      my_rf.send(binaryValue, bitLength);  // Send the captured signal
      Serial.println("Signal retransmitted.");
    } else {
      Serial.println("No signal captured yet.");
    }
  }

  lastButtonState = buttonState;
}
