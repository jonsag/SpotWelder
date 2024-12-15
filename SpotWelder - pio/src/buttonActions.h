/*******************************
  Weld Pulse
*******************************/
void weld()
{
  infoMessln("Weld button is pressed");
  infoMess("Welding for ");
  infoMess(pulseLength);
  infoMessln(" milli seconds!");

  startMillis = millis();
  welding = HIGH;

  digitalWrite(weldingLED, HIGH);
  digitalWrite(ssrPin, HIGH);
}

void arm()
{
  armed = HIGH;
  digitalWrite(armLED, HIGH);
}

void disarm()
{
  armed = LOW;
  digitalWrite(armLED, LOW);
}
void button4Action()
{
  infoMessln("Button 4 is pressed");
}