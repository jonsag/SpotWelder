#include "buttonActions.h" // makes buttons do something

/*******************************
  Buttons
*******************************/

void onPinActivated(int pinNr)
{
    infoMessln();
    infoMess("Pin activated: ");
    infoMessln(pinNr);

    switch (pinNr)
    {
    case triggerPin:
        weld();
        break;
    case armPin:
        arm();
        break;
    }
}

void onPinDeactivated(int pinNr)
{
    infoMessln("Button is released");
    /*Serial.println();
      Serial.print("Pin deactivated: ");
      Serial.println(pinNr);
    */

    switch (pinNr)
    {
    case armPin:
        disarm();
        break;
    }
}

void readButtons()
{
    rotate = rotary.rotate();
    push = rotary.push();

    /*******************************
      Rotary encoder
    *******************************/
    if (rotate != 0 || push != 0) // button was manipulated
    {

        infoMessln();
        infoMess("Rotary encoder: ");

        if (push) // left button pressed
        {
            infoMessln("Button pressed");

            button4Action();
        }
        else
        {
            switch (rotate) // left knob
            {
            case 1: // clockwise rotation
                infoMessln("CW");
                newPulseLength = pulseLength + pulseStep;
                break;

            default: // case 2: // counter clockwise rotation
                infoMessln("CCW");
                if (pulseLength - pulseStep >= 1)
                {
                    newPulseLength = pulseLength - pulseStep;
                }
                break;
            }
        }
    }
}