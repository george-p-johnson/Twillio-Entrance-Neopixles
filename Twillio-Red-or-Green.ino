#include <Adafruit_NeoPixel.h>

// Data pin
#define LED_PIN 6
// Number of LEDs in strip
#define LED_COUNT 8

// Initialize strip - my test strip is a RBGW
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_RGBW + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin();
  strip.setBrightness(50);
  Serial.println("Ready");
}

void loop() {
  // Read serial
  if (Serial.available() > 0) {
    setAllPixels(0, 255, 0); // Set all to red as defualt
    Serial.println("Setting strip to red");

    char incomingByte = Serial.read();

    // App sends a int of 1 to trigger green for 5 seconds
    if (incomingByte == '1') {

      Serial.println("Setting strip to green");
      setAllPixels(255, 0, 0);  
      delay(5000);
    }
  }
  delay(50);
}

// Function to set all pixels to the same color
void setAllPixels(uint8_t r, uint8_t g, uint8_t b) {
  for (int i = 0; i < LED_COUNT; i++) {
    strip.setPixelColor(i, strip.Color(r, g, b));
  }
  strip.show();
}





// void loop() {
//   // Check if data is available to read from serial
//   if (Serial.available() > 0) {
//     // Read the incoming byte
//     char incomingByte = Serial.read();

//     // Process the incoming byte
//     if (incomingByte == '1') {
//       // Turn all pixels green
//       setAllPixels(0, 255, 0);  // RGB for green
//       Serial.println("Setting strip to GREEN");
//     } else if (incomingByte == '2') {
//       // Turn all pixels red
//       setAllPixels(255, 0, 0);  // RGB for red
//       Serial.println("Setting strip to RED");
//     }
//   }