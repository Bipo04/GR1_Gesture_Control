#include "RevEng_PAJ7620.h"

#define LED1 4
#define LED2 16
#define LED3 17
#define LED4 5

RevEng_PAJ7620 sensor = RevEng_PAJ7620();

void setup() 
{ 
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(9600);

  if( !sensor.begin() )           
  {
    Serial.print("PAJ7620 I2C error !");
    while(true) { }
  }
}

void loop() 
{
  String StrState = "";
  Gesture gesture;                   
  gesture = sensor.readGesture();  
  
  switch (gesture)
  {
    case GES_FORWARD:
      {
        StrState = "FORWARD";
        Serial.println(StrState);
        forward(300);
        break;
      }

    case GES_BACKWARD:
      {
        StrState = "BACKWARD";
        Serial.println(StrState);
        backward(300);
        break;
      }

    case GES_LEFT:
      {
        StrState = "LEFT";
        Serial.println(StrState);
        left(300);
        break;
      }

    case GES_RIGHT:
      {
        StrState = "RIGHT";
        Serial.println(StrState);
        right(300);
        break;
      }

    case GES_UP:
      {
        StrState = "UP";
        Serial.println(StrState);
        up(300);
        break;
      }

    case GES_DOWN:
      {
        StrState = "DOWN";
        Serial.println(StrState);
        down(300);
        break;
      }

    case GES_CLOCKWISE:
      {
        StrState = "CLOCKWISE";
        Serial.println(StrState);
        clockwise(200,3);
        break;
      }

    case GES_ANTICLOCKWISE:
      {
        StrState = "ANTICLOCKWISE";
        Serial.println(StrState);
        antiClockwise(200,3);
        break;
      }
  }

  delay(1000);
}

void LED_On(int pin){
  digitalWrite(pin, HIGH);
}

void LED_Off(int pin){
  digitalWrite(pin, LOW);
}

void up(int duration){
  LED_On(LED1);
  delay(duration);
  LED_Off(LED1);
}

void right(int duration){
  LED_On(LED2);
  delay(duration);
  LED_Off(LED2);
}

void down(int duration){
  LED_On(LED3);
  delay(duration);
  LED_Off(LED3);
}

void left(int duration){
  LED_On(LED4);
  delay(duration);
  LED_Off(LED4);
}

void clockwise(int durationPerLED, int rotations){
  for(int i = 0; i < rotations; i++){
    LED_On(LED1); delay(durationPerLED); LED_Off(LED1);
    LED_On(LED2); delay(durationPerLED); LED_Off(LED2);
    LED_On(LED3); delay(durationPerLED); LED_Off(LED3);
    LED_On(LED4); delay(durationPerLED); LED_Off(LED4);
  }
}

void antiClockwise(int durationPerLED, int rotations){
  for(int i = 0; i < rotations; i++){
    LED_On(LED1); delay(durationPerLED); LED_Off(LED1);
    LED_On(LED4); delay(durationPerLED); LED_Off(LED4);
    LED_On(LED3); delay(durationPerLED); LED_Off(LED3);
    LED_On(LED2); delay(durationPerLED); LED_Off(LED2);
  }
}

void forward(int duration){
  LED_On(LED1);
  LED_On(LED2);
  LED_On(LED4);
  delay(duration);
  LED_Off(LED1);
  LED_Off(LED2);
  LED_Off(LED4);
}

void backward(int duration){
  LED_On(LED2);
  LED_On(LED3);
  LED_On(LED4);
  delay(duration);
  LED_Off(LED2);
  LED_Off(LED3);
  LED_Off(LED4);
}