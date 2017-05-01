const int inPin = 2;
//const int outPin= 13;
int elapsedtime=0;

int ledstate =LOW;
int switchstate = LOW;
int previous = LOW;

long prevtime = 0;
long debounce = 200;
long dur_on = 0; //duration between on/off

void setup(){
  pinMode(inPin,INPUT);
  //pinMode(outPin,OUTPUT);
  Serial.begin(9600);
}

void loop(){

  switchstate=digitalRead(inPin); 
  if ((millis()-prevtime)>debounce){
    if(switchstate!=previous && switchstate==HIGH){
      if (ledstate==LOW){
        //digitalWrite(outPin,HIGH);
        
        Serial.println("A:"+String(elapsedtime));
        prevtime=millis();
        ledstate=HIGH;
      }
      else if(ledstate==HIGH){
        //digitalWrite(outPin,LOW);
        ledstate=LOW;
        elapsedtime=millis()-prevtime;
        Serial.println(elapsedtime);
         prevtime=millis();
      }
    }
  }
}
      
