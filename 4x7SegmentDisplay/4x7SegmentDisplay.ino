#include <Arduino.h>
#include <TM1637Display.h>

// Module connection pins (Digital Pins)
#define CLK 2
#define DIO 3

// The amount of time (in milliseconds) between tests
#define TEST_DELAY   2000

TM1637Display display(CLK, DIO);

void setup()
{
}

void loop()
{
  int k;
  uint8_t data[] = { 0xff, 0xff, 0xff, 0xff };
  display.setBrightness(0x0f);
  
  // All segments on
  display.setSegments(data);
  delay(TEST_DELAY);
  
  // Selectively set different digits
  data[0] = display.encodeDigit(1);
  data[1] = display.encodeDigit(2);
  data[2] = display.encodeDigit(3);
  data[3] = display.encodeDigit(4);

  display.setSegments(data);
  
  delay(TEST_DELAY);
  
}
