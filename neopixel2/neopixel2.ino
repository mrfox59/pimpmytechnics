// Simple NeoPixel test.  Lights just a few pixels at a time so a
// 1m strip can safely be powered from Arduino 5V pin.  Arduino
// may nonetheless hiccup when LEDs are first connected and not
// accept code.  So upload code first, unplug USB, connect pixels
// to GND FIRST, then +5V and digital pin 6, then re-plug USB.
// A working strip will show a few pixels moving down the line,
// cycling between red, green and blue.  If you get no response,
// might be connected to wrong end of strip (the end wires, if
// any, are no indication -- look instead for the data direction
// arrows printed on the strip).

#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N_LEDS 60
#define wait 15
#define largeur 6
// Variables générales
//const int SERIAL_PORT = 9600;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(60);
  Serial.begin(SERIAL_PORT);
}

void loop() {
  chase(strip.Color(0,0,255));
  
}

void chase(uint32_t c) {
  for(uint16_t i=(largeur-1); i<strip.numPixels()+largeur; i++) {
      /*Serial.print("allume -> ");
      Serial.print(i);
      Serial.print("/");
      Serial.print(strip.numPixels());
      Serial.println();
      */
      strip.setPixelColor(i  , c); // Draw new pixel
      //Serial.print("eteint ->");
      //Serial.print(i-largeur);
      //Serial.println();
      strip.setPixelColor(i-largeur, 0); // Erase pixel a few steps back
      strip.show();
      if(i>=(strip.numPixels())){
        int delta = i-strip.numPixels();
        /*Serial.print("delta -> ");
        Serial.print(delta);
        Serial.print("/");
        Serial.print(strip.numPixels());
        Serial.println();
        */
        strip.setPixelColor(delta  , c); // Draw new pixel
      }
      delay(wait);
  }
}
