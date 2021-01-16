// Tutorial for the display https://www.instructables.com/Tutorial-How-to-4-Digit-Display-Interface-With-Ard/

#include <Arduino.h>
#include <TM1637Display.h>

#define CLK_PIN 2
#define DIO_PIN 3
#define BUTTON_PIN_PLUS 7
#define BUTTON_PIN_MIN 8

TM1637Display display(CLK_PIN, DIO_PIN);

int buttonStatePlus = 0;
int buttonStateMin = 0;
int displayNumber = 0;


void setup(){
  Serial.begin(9600);

  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x0f);

  pinMode(BUTTON_PIN_PLUS, INPUT);
  pinMode(BUTTON_PIN_MIN, INPUT);
  
  // All segments on
  display.setSegments(data);
  delay(200);
}

void loop(){
  buttonStatePlus = digitalRead(BUTTON_PIN_PLUS);
  buttonStateMin = digitalRead(BUTTON_PIN_MIN);

  if (buttonStatePlus == HIGH) {
    displayNumber = displayNumber + 5;
  } 

  if (buttonStateMin == HIGH) {
    displayNumber = displayNumber - 5;
  } 
  
  display.showNumberDec(displayNumber);
  delay(250);
}
