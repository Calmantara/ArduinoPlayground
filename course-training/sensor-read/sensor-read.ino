//Constants:
const int ledPin = 7;
const int potPin = A0;
const int btnPin = 9;

//Variables:
int value = 0;
bool ledState = false;

void setup()
{
    //Input or output
    pinMode(ledPin, OUTPUT);
    pinMode(potPin, INPUT);
    pinMode(btnPin, INPUT_PULLUP);
}

void loop()
{
    //process value
    value = analogRead(potPin);
    value = map(value, 0, 1023, 0, 255);

    bool btnState = digitalRead(btnPin);

    // delay condition depends on value
    int delayValue = (value > 200 && value <= 255) || !btnState ? 500
                     : (value > 100 && value <= 200)            ? 2000
                                                                : 4000;
    // int delayValue = 0;
    // if ((value > 200 && value <= 255) || btnState == false)
    // {
    //     delayValue = 500;
    // }
    // else if (value > 100 && value <= 200)
    // {
    //     delayValue = 2000;
    // }
    // else
    // {
    //     delayValue = 4000;
    // }

    digitalWrite(ledPin, ledState);
    delay(delayValue);

    //update state value
    ledState = !ledState;
}
