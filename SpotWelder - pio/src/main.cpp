#include <Arduino.h>

#include "configuration.h"
#include "buttons.h"

void draw(void)
{
  // graphic commands to redraw the complete screen
  u8g.setFont(u8g_font_unifont);
  u8g.drawStr(14, 10, "JD Spot Weld!"); // rename to personalize ;)
  u8g.setScale2x2();
  u8g.setPrintPos(20, 20);
  u8g.print(pulseLength);
  u8g.undoScale();
  u8g.drawStr(20, 60, "milliseconds");
}

void setup(void)
{
  /*******************************
    OLED
  *******************************/
  // flip screen, if required
  // u8g.setRot180();

  // set SPI backup if required
  // u8g.setHardwareBackup(u8g_backup_avr_spi);

  // assign default color value
  if (u8g.getMode() == U8G_MODE_R3G3B2)
  {
    u8g.setColorIndex(255); // white
  }
  else if (u8g.getMode() == U8G_MODE_GRAY2BIT)
  {
    u8g.setColorIndex(3); // max intensity
  }
  else if (u8g.getMode() == U8G_MODE_BW)
  {
    u8g.setColorIndex(1); // pixel on
  }
  else if (u8g.getMode() == U8G_MODE_HICOLOR)
  {
    u8g.setHiColorByRGB(255, 255, 255);
  }

  /*******************************
    Start serial
  *******************************/
  if (DEBUG || INFO)
  {
    Serial.begin(serialSpeed);
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
  infoMessln("Starting in-, outputs ...");

  pinMode(onLED, OUTPUT);
  pinMode(armLED, OUTPUT);
  pinMode(weldingLED, OUTPUT);

  pinMode(ssrPin, OUTPUT);

  /*******************************
    Setup FTDebouncer pins
  *******************************/
  infoMessln("Starting debouncer ...");

  pinDebouncer.addPin(armPin, LOW, onPinActivated, onPinDeactivated); // pin has external pull-down resistor
  pinDebouncer.addPin(triggerPin, LOW, onPinActivated, onPinDeactivated);

  pinDebouncer.begin();

  /*******************************
     Set up rotary encoders
   *******************************/
  infoMessln("Setting up rotary encoders  ...");

  rotary.setTrigger(HIGH); // set the trigger to be either a HIGH or LOW pin (Default: HIGH), note this sets all three pins to use the same state
  rotary.setDebounceDelay(debounceDelay);
  rotary.setErrorDelay(errorDelay);

  /*******************************
    Initiate variables
  *******************************/
  infoMessln("Initiating variables  ...");
  infoMessln();

  newPulseLength = pulseLength;

  /*******************************
    Finished boot
  *******************************/
  infoMessln();
  infoMessln("Started!");
  infoMessln();

  // startMillis = millis();

  /*******************************
    Draw screen
  *******************************/
  u8g.firstPage();
  do
  {
    draw();
  } while (u8g.nextPage());

  digitalWrite(onLED, HIGH);
}

void loop(void)
{
  // ******************** handle buttons *******************
  readButtons();
  pinDebouncer.update();

  // picture loop
  if (pulseLength != newPulseLength)
  {
    pulseLength = newPulseLength;
    infoMess("Pulse length: ");
    infoMessln(pulseLength);
    u8g.firstPage();
    do
    {
      draw();
    } while (u8g.nextPage());
  }

  currentMillis = millis();

  /*infoMess(startMillis);
  infoMess("\t");
  infoMess(currentMillis);
  infoMess("\t");
  infoMessln(startMillis - currentMillis);*/

  if ((welding == HIGH) && (armed == LOW))
  {
    digitalWrite(weldingLED, LOW);
    digitalWrite(ssrPin, LOW);

    infoMessln("Welding interrupted");
    infoMess("Welded for ");
    infoMess(currentMillis - startMillis);
    infoMessln(" milli seconds!");

    welding = LOW;
  }

  if ((welding == HIGH) && (currentMillis - startMillis >= pulseLength) && (armed == LOW))
  {
    digitalWrite(weldingLED, LOW);
    digitalWrite(ssrPin, LOW);

    infoMessln("Welding finished");
    infoMess("Welded for ");
    infoMess(currentMillis - startMillis);
    infoMessln(" milli seconds!");

    welding = LOW;
  }

  /*if (currentMillis - startMillis >= pulseLength)
  {
    if (ledState == LOW)
    {
      ledState = HIGH;
    }
    else
    {
      ledState = LOW;
    }

    digitalWrite(ssrPin, ledState);
    startMillis = currentMillis;
  }*/
}