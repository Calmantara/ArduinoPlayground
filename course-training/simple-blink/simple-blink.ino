//define all pins needed
#define PLED1 8
#define PLED2 11
#define PBTN1 9
#define PBTN2 10

//initiate led state and button state
// bool ledState1 = false;
// bool ledState2 = false;
bool ledState = false;
bool btnState1 = false;
bool btnState2 = false;

void setup()
{
    /*
    * setup all pin mode
    * PBTN -> INPUT
    * PLED -> OUTPUT
    */
    pinMode(PBTN1, INPUT_PULLUP);
    pinMode(PBTN2, INPUT_PULLUP);
    pinMode(PLED1, OUTPUT);
    pinMode(PLED2, OUTPUT);

    // Serial.begin(9600);
}

void loop()
{
    //read button state
    btnState1 = digitalRead(PBTN1); // pushed -> false/LOW/0
    btnState2 = digitalRead(PBTN2); // pushed -> false/LOW/0

    //print state for debugging
    // Serial.print("button 1 state:");
    // Serial.println(btnState1);
    // Serial.print("button 2 state:");
    // Serial.println(btnState2);

    if (!btnState1)
    {
        //condition 1
        digitalWrite(PLED1, ledState); // if false will be turning off
        digitalWrite(PLED2, !ledState);
        delay(1000);
        // ledState1 = !ledState1;
        // ledState2 = !ledState2;
        ledState = !ledState;

        // if (ledState1 == true)
        // {
        //     ledState1 = false;
        // }
        // else if (ledState1 == false)
        // {
        //     ledState1 = true;
        // }

        // if (ledState2 == true)
        // {
        //     ledState2 = false;
        // }
        // else if (ledState2 == false)
        // {
        //     ledState2 = true;
        // }
    }
    else if (!btnState2)
    {
        //condition 2
        digitalWrite(PLED1, ledState);
        digitalWrite(PLED2, ledState);
        delay(1000);
        // ledState1 = !ledState1;
        // ledState2 = !ledState2;
        ledState = !ledState;
    }
    else
    {
        //default condition
        //all leds will switch off
        // ledState1 = false;
        // ledState2 = false;
        ledState = false;
        digitalWrite(PLED1, ledState);
        digitalWrite(PLED2, ledState);
    }
}