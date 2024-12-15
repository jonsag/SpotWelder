#include "buttonActions.h" // makes buttons do something

/*******************************
  Buttons
*******************************/
void readInputs()
{
    armState = digitalRead(armPin);
    if ((armState == HIGH) && (armed == LOW))
    {
        arm();
    }
    else if ((armState == LOW) && (armed == HIGH))
    {
        disarm();
    }

    triggerState = digitalRead(triggerPin);
    if (triggerState != oldTriggerState)
    {
        if (triggerState == HIGH)
        {
            infoMessln();
            infoMessln("Trigger is pushed");
            if (armed == HIGH)
            {
                weld();
            }
        }
        else
        {
            infoMessln();
            infoMessln("Trigger is released");
        }

        oldTriggerState = triggerState;
    }
}

/*******************************
  Rotary Encoder
*******************************/
void readRotary()
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