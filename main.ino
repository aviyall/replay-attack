
#include <RCSwitch.h>

RCSwitch mySwitch = RCSwitch();

const int buttonPin = 4;  // Pin connected to the button
bool signalCaptured = false;
unsigned long capturedCode;
unsigned int capturedLength;
unsigned int capturedDelay;
unsigned int capturedProtocol;

void setup() {
  Serial.begin(9600);
  mySwitch.enableReceive(0);  // Receiver on interrupt 0 => that is pin 2 on arduino boards
  mySwitch.enableTransmit(3); // Transmitter on pin 3

  pinMode(buttonPin, INPUT_PULLUP);  // Set the button pin as input with internal pull-up resistor
}

void loop() {
  // Capture the signal
  if (mySwitch.available()) {
    capturedCode = mySwitch.getReceivedValue();
    capturedLength = mySwitch.getReceivedBitlength();
    capturedDelay = mySwitch.getReceivedDelay();
    capturedProtocol = mySwitch.getReceivedProtocol();

    if (capturedCode != 0) {
      Serial.print("Received code: ");
      Serial.println(capturedCode);
      Serial.print("Bit length: ");
      Serial.println(capturedLength);
      Serial.print("Delay: ");
      Serial.println(capturedDelay);
      Serial.print("Protocol: ");
      Serial.println(capturedProtocol);

      signalCaptured = true;  // Indicate that a signal has been captured
      mySwitch.resetAvailable();  // Reset the receiver for the next signal
    }
  }

  // Transmit the stored signal when the button is pressed
  if (signalCaptured && digitalRead(buttonPin) == LOW) {
    mySwitch.setProtocol(capturedProtocol);  // Set the protocol
    mySwitch.send(capturedCode, capturedLength);  // Send the stored code
    Serial.println("Signal retransmitted.");
    delay(500);  // Debounce delay
  }
}

