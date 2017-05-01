#include <Adafruit_NeoPixel.h>

#define PIN 6
 
// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(60, PIN, NEO_GRB + NEO_KHZ800);
    

void setup() {
  strip.begin();
  strip.setBrightness(100);  // Lower brightness and save eyeballs!
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {
  // Some example procedures showing how to display to the pixels:
  colorWipeB(strip.Color(0, 0, 0)); 
  colorWipe(strip.Color(64, 0, 0), 10); // Red
  colorWipeB(strip.Color(0, 0, 0));
  colorWipeR(strip.Color(64, 0, 0), 10); // Red
  colorWipeB(strip.Color(0, 0, 0));
  colorWipe(strip.Color(0, 64, 0), 10); // Green
  colorWipeB(strip.Color(0, 0, 0));
  colorWipeR(strip.Color(0, 64, 0), 10); // Green
  colorWipeB(strip.Color(0, 0, 0));
  colorWipe(strip.Color(0, 0, 64), 10); // Blue
  colorWipeB(strip.Color(0, 0, 0));
  colorWipeR(strip.Color(0, 0, 64), 10); // Blue
  
}

// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
}
  void colorWipeR(uint32_t c, uint8_t wait) {
  for(uint16_t i=strip.numPixels(); i>0; i--) {
      strip.setPixelColor(i, c);
      strip.show();
      delay(wait);
  }
  
}
 void colorWipeB(uint32_t c) {
  for(uint16_t i=strip.numPixels(); i>0; i--) {
      strip.setPixelColor(i, c);
      strip.show();
      
  }
  
}
