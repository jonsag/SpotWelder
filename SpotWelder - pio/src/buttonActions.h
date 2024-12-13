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

    digitalWrite(ssrPin, HIGH);
}

void button4Action()
{
    infoMessln("Button 4 is pressed");
}