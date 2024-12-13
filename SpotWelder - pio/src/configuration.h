String programName = "SpotWelder";
String date = "20241213";
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
  Wire
*******************************/
// #include <Wire.h> // load the wire library

/*******************************
  OLED
*******************************/
// OLED screens I2C address: 0x3c

// #include "SSD1306Ascii.h"
// #include "SSD1306AsciiWire.h"

// #define I2C_ADDRESS 0x3C

// SSD1306AsciiWire oled; // start oled instance

#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0);

/*******************************
 FTDebouncer setup
*******************************/
const byte debounceTime = 15;

#if !defined(nullptr)
#define nullptr NULL
#endif

#include "FTDebouncer.h" // load library for debouncing buttons
FTDebouncer pinDebouncer(debounceTime);

/*******************************
  Rotary encoders
*******************************/
#include <SimpleRotary.h>

SimpleRotary rotary(2, 3, 4); // multi function button, CLK, DT, SW (pin A, pin B, button pin)

#define debounceDelay 2 // set the debounce delay in ms, default 2
#define errorDelay 200  // set the error correction delay in ms, default 200

byte rotate;
byte push;

/*******************************
  In- and outputs
*******************************/
int potPin = 0; // analog pin used to connect the potentiometer

#define triggerPin 10
int ssrPin = 8;

/*******************************
  Misc
*******************************/
double startMillis;
double currentMillis;

boolean ledState;
#define blinkInterval 500

int pulseLength = 500; // variable to read the value from the analog pin
int pulseStep = 10;
int newPulseLength;

boolean welding = LOW;
