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
}

void loop(){
  int chk = DHT.read11(DHT11_PIN);
  output();
  delay(1000);
}

void output(){
  int temperature = DHT.temperature;
  int humidity = DHT.humidity;
  int displayNumber = (temperature * 100) + humidity;
  
  Serial.print("Temperature = ");
  Serial.println(DHT.temperature);
//  Serial.println(temperature);
  Serial.print("Humidity = ");
  Serial.println(DHT.humidity);
//  Serial.println(humidity);
  Serial.print("Combinbed = ");
  Serial.println(displayNumber);

}

//void loop()
//{
//  int k;
//  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
//  display.setBrightness(0x0f);
//  
//  // All segments on
//  display.setSegments(data);
//  delay(TEST_DELAY);
//  
//  // Selectively set different digits
//  data[0] = display.encodeDigit(1);
//  data[1] = display.encodeDigit(2);
//  data[2] = display.encodeDigit(3);
//  data[3] = display.encodeDigit(4);
//
//  display.setSegments(data);
//  
//  delay(TEST_DELAY);
//  
//}
