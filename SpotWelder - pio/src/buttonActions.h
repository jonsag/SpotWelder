/*******************************
  Weld Pulse
*******************************/
void weld()
{
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
  infoMessln();
  infoMessln("Armed!");
  armed = HIGH;
  digitalWrite(armLED, HIGH);
}

void disarm()
{
  infoMessln();
  infoMessln("Disarmed");
  armed = LOW;
  digitalWrite(armLED, LOW);
}
