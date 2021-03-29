#include <SoftwareSerial.h>
SoftwareSerial BTserial(13, 12); // RX | TX
// SoftwareSerial BTserial(7, 6); // RX | TX

//AT+CON882583F024EA

//AT+CON882583F02805

// const long baudRate = 38400;
char c = ' ';
boolean NL = true;

void setup()
{
    Serial.begin(38400);
    BTserial.begin(38400);

    while (BTserial.available())
    {
        Serial.write(BTserial.read());
    }
}

void loop()
{

    // Read from the Bluetooth module and send to the Arduino Serial Monitor
    if (BTserial.available())
    {
        c = BTserial.read();
        Serial.println(c);
    }

    // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available())
    {
        c = Serial.read();
        BTserial.write(c);

        // Echo the user input to the main window. The ">" character indicates the user entered text.
        if (NL)
        {
            Serial.print(">");
            NL = false;
        }
        Serial.write(c);
        if (c == 10)
        {
            NL = true;
        }
    }
}