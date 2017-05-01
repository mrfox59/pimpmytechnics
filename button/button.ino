
int buttonPin;
int r, v, b;

const int SERIAL_PORT = 9600;

void setup()
{
   buttonPin = 2; //whatever pin your button is plugged into
   r = 0;
  Serial.begin(SERIAL_PORT);
   pinMode(buttonPin, INPUT_PULLUP);
}

void loop()
{
  //code you always run here; you can leave this section blank if you want the entire program to stop and start, or add code here if you want it to always run

  //check button press here and if it is pressed then toggle run variable between 0 and 255; REQUIRED!
  if(digitalRead(buttonPin) == LOW) //funcitons based off of button pulling input pin LOW
  {

while(r < 256 && digitalRead(buttonPin) == HIGH){
  // do something repetitive 200 times
  r++;
      if(r == 255){
        r = 0;
        v++;
        if(v == 255){
          b++;
        }
        
      }
      
      Serial.println(r);
      Serial.println(v);
      Serial.println(b);
}
    
    /*for(r=0;r<256;r++){
      if(r==255){
        v++;
        if(v==255){
          b++;
        }
      }
      */
    //}
    
  }
}
