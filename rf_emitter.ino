#include <RCSwitch.h> // Include the RC-Switch library for handling RF communication

// Set up the RF transmitter
const int TRANSMITTER_PIN = 12; // The transmitter is connected to pin 12
RCSwitch mySwitch = RCSwitch(); // Create a new RCSwitch object

// Set the CAME protocol fixed code
unsigned long CAME_CODE = 0b001011001010; // 12-bit code

const int button = 2; // Button is connected to pin 2
void setup() {
  pinMode(button, INPUT); // Set the button pin as an input
  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  mySwitch.enableTransmit(TRANSMITTER_PIN); // Enable the transmitter on pin 12
  mySwitch.setProtocol(1); // Protocol 1 is the default
  mySwitch.setPulseLength(320); // Adjust the pulse length if needed
}

void loop() {
  if (digitalRead(button) == 1) { // Check if the button is pressed
    mySwitch.send(CAME_CODE, 12); // Send the 12-bit CAME code
    Serial.print("Sent code: ");
    Serial.println(CAME_CODE, DEC); // Print the sent code to the serial monitor in decimal format
    delay(1000); // Wait for 1 second (1000 milliseconds)
  }
}
