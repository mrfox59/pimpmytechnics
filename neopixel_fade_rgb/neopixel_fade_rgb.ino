#include <Adafruit_NeoPixel.h>

// constants won't change. They're used here to 
// set pin numbers:
const int ledPin = 6;     // the number of the neopixel strip
const int numLeds = 60;


//Adafruit_NeoPixel pixels = Adafruit_NeoPixel(8, ledPin);
Adafruit_NeoPixel strip = Adafruit_NeoPixel(numLeds, ledPin, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin();
  strip.setBrightness(80); // 1/3 brightness

}

void loop() {

  unsigned int rgbColour[3];

  // Start off with red.
  rgbColour[0] = 255;
  rgbColour[1] = 0;
  rgbColour[2] = 0;  

  // Choose the colours to increment and decrement.
  for (int decColour = 0; decColour < 3; decColour += 1) {
    int incColour = decColour == 2 ? 0 : decColour + 1;

    // cross-fade the two colours.
    for(int i = 0; i < 255; i += 1) {
      rgbColour[decColour] -= 1;
      rgbColour[incColour] += 1;
      
      for(int i=0;i<strip.numPixels();i++){
        strip.setPixelColor(i  , strip.Color(rgbColour[0], rgbColour[1], rgbColour[2]));
        strip.show();
      }
    }
  }

}




