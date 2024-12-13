String programName = "SpotWelder";
String date = "20241212";
String author = "Jon Sagebrand";
String email = "jonsagebrand@gmail.com";

/*******************************
  Serial
*******************************/
#define serialSpeed 9600

/*******************************
  Debugging
*******************************/
#define DEBUG 0 // debugMess is off when 0
#define INFO 1

#if DEBUG
#define debugMess(x) Serial.print(x)
#define debugMessln(x) Serial.println(x)
#else
#define debugMess(x)
#define debugMessln(x)
#endif

#if INFO || DEBUG
#define infoMess(x) Serial.print(x)
#define infoMessln(x) Serial.println(x)
#else
#define infoMess(x)
#define infoMessln(x)
#endif

/*******************************
  Mire
*******************************/
#include <Wire.h> // load the wire library

/*******************************
  OLED
*******************************/
// OLED screens I2C address: 0x3c

#include "SSD1306Ascii.h"
#include "SSD1306AsciiWire.h"

#define I2C_ADDRESS 0x3C

SSD1306AsciiWire oled; // start oled instance

/*******************************
  In- and outputs
*******************************/

/*******************************
  Misc
*******************************/
double startMillis;
