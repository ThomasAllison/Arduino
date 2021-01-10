// Tutorial for the display https://www.instructables.com/Tutorial-How-to-4-Digit-Display-Interface-With-Ard/

#include <dht.h>
#include <Arduino.h>
#include <TM1637Display.h>

dht DHT;

#define DHT11_PIN 7
#define CLK_PIN 2
#define DIO_PIN 3

#define TEST_DELAY   2000

TM1637Display display(CLK_PIN, DIO_PIN);


void setup(){
  Serial.begin(9600);

  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x0f);
  
  // All segments on
  display.setSegments(data);
  delay(TEST_DELAY);
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  int displayNumber = temperatureAndHumidityInt();

  display.showNumberDec(displayNumber);
  delay(2000);
}

int temperatureAndHumidityInt(){
  int temperature = DHT.temperature;
  int humidity = DHT.humidity;
  int displayNumber = (temperature * 100) + humidity;

  return displayNumber;
}
