#include <RCSwitch.h> // Include the RC-Switch library for handling RF communication

// Set up the RF receiver
const int RECEIVER_PIN = 2; // Use interrupt 0 (pin 2 on most Arduino boards)
RCSwitch mySwitch = RCSwitch(); // Create a new RCSwitch object

// Set up the LED
const int LED_PIN = 12; // The LED is connected to pin 12

// Set the CAME protocol fixed code
unsigned long CAME_CODE = 0b001011001010; // 12-bit code

void setup() {
  pinMode(LED_PIN, OUTPUT); // Set the LED pin as an output
  digitalWrite(LED_PIN, LOW); // Turn the LED off initially

  Serial.begin(9600); // Initialize serial communication at 9600 baud rate
  mySwitch.enableReceive(0); // Enable the receiver on interrupt 0, which corresponds to pin #2
}

void loop() {
  if (mySwitch.available()) { // Check if there is a signal available from the receiver
    unsigned long receivedValue = mySwitch.getReceivedValue(); // Get the received value
    int receivedBitLength = mySwitch.getReceivedBitlength(); // Get the received bit length

    // Check if the received value matches the predefined CAME code and the bit length is 12
    if (receivedValue == CAME_CODE && receivedBitLength == 12) {
      digitalWrite(LED_PIN, HIGH); // Turn the LED on
      Serial.println(receivedValue); // Print receivedValue to the serial monitor
      delay(2000); // Wait for 2 seconds (2000 milliseconds)
      digitalWrite(LED_PIN, LOW); // Turn the LED off
    } else {
      digitalWrite(LED_PIN, LOW); // If the received value doesn't match, turn the LED off
    }
    mySwitch.resetAvailable(); // Reset the availability status of the received signal
  }
}
