#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N_LEDS 60
#define wait 25 //ms
#define largeur 6


int buttonPin;
int r, v, b;

// const int SERIAL_PORT = 9600;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_LEDS, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{
  strip.begin();
  strip.setBrightness(255);
   buttonPin = 2; //whatever pin your button is plugged into
   r = 255;
   v = b = 0;
  //Serial.begin(SERIAL_PORT);
   pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  while(digitalRead(buttonPin) == HIGH){
    
    if (r == 255 && v != 255 && b == 0){
      v++;
    } else if (r != 0 && v == 255 && b == 0){
      r--;
    } else if (r == 0 && v == 255 && b != 255){
      b++;
    } else if (r == 0 && v != 0 && b == 255){
      v--;
    } else if (r != 255 && v == 0 && b == 255 ){
      r++;
    } else if (r == 255 & v == 0 && b != 0) {
      b--;
    }

  //Serial.println("bleu "+String(b)+" - vert "+String(v)+" - rouge "+String(r));
  for(int i=0;i<largeur;i++){
    strip.setPixelColor(i  , strip.Color(r,v,b));
    strip.show();
  }    
}
  // on fait tourner le chenillard, avec la dernière valeur du selecteur rvb
  chase(strip.Color(r,v,b));
  strip.show();
}

void chase(uint32_t c) {
  for(uint16_t i=(largeur-1); i<strip.numPixels()+largeur; i++) {
      strip.setPixelColor(i  , c); // j'assigne la couleurs aux leds
      strip.setPixelColor(i-largeur, 0); // j'eteind les led précednte a la largeur
      strip.show();
      if(i>=(strip.numPixels())){
        int delta = i-strip.numPixels();
        strip.setPixelColor(delta  , c); // offset couleur led du demarrage
      }
      delay(wait);
  }
}
