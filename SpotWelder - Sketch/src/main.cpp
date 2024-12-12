#include <Arduino.h>

#include "configuration.h" // sets all variables

/*
#include "U8glib.h"

U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE | U8G_I2C_OPT_DEV_0); // I2C / TWI

int potPin = 0; // analog pin used to connect the potentiometer
int potVal;     // variable to read the value from the analog pin

int inPin = 2;
int triggerSwitch = 0;
int ssrPin = 3;
int stringWidth = 0;

void draw(void)
{
  // graphic commands to redraw the complete screen
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(14, 10, "JD Spot Weld!"); // rename to personalize ;)
  u8g.setScale2x2();
  u8g.setPrintPos(20, 20);
  u8g.print(potVal);
  u8g.undoScale();
  u8g.drawStr(20, 60, "Miliseconds");
}
*/

void setup(void)
{
  /*******************************
    Wire
  *******************************/
  Wire.begin();

  /*******************************
    OLED
  *******************************/
  Wire.setClock(400000L);

  oled.begin(&Adafruit128x64, I2C_ADDRESS);

  // oled.setFont(Adafruit5x7);
  oled.setFont(System5x7);

  oled.clear();
  oled.println("Spot Welder");

  /*******************************
    Start serial
  *******************************/
  if (DEBUG || INFO)
  {
    oled.println("Starting serial ...");

    Serial.begin(serialSpeed);
  }
  else
  {
    oled.println();
  }

  /*******************************
    Print start information
  *******************************/
  infoMessln(programName); // print information
  infoMessln(date);
  infoMess("by ");
  infoMessln(author);
  infoMessln(email);
  infoMessln();

  /*******************************
   In- and outputs
 *******************************/
  oled.println("Starting in-, outputs ...");

  infoMessln("Starting in-, outputs ...");
  /*
    pinMode(levelLED_neg1, OUTPUT); // set level LEDs as outputs
    pinMode(levelLED_neg0, OUTPUT);
    pinMode(levelLED_level, OUTPUT);
    pinMode(levelLED_pos0, OUTPUT);
    pinMode(levelLED_pos1, OUTPUT);
  */

  oled.clear();

  infoMessln("Started!");
  infoMessln();

  startMillis = millis();
}

void loop(void)
{
/*
  infoMess(startMillis);
  infoMess("  ");
  infoMess(millis());
  infoMess("  ");
  infoMess(millis() - startMillis);
  infoMessln("  hej");
*/

  if (millis() - startMillis > 1000)
  {
    infoMessln("Alive");
    startMillis = millis();
  }
}
