#include <SoftwareSerial.h>

//Declare variable
SoftwareSerial bluetoothSerial(2, 3);

char c = ' ';
boolean NL = true;

void setup()
{
    Serial.begin(9600);
    bluetoothSerial.begin(38400);
    Serial.println("Test started - Enter something to send to computer or Android phone");
    bluetoothSerial.println("Test started - Enter something to send to Serial Monitor Window");
}

void loop()
{
    if (bluetoothSerial.available())
    {
        c = bluetoothSerial.read();
        Serial.write(c);
    }
    // Read from the Serial Monitor and send to the Bluetooth module
    if (Serial.available())
    {
        c = Serial.read();
        bluetoothSerial.write(c);

        // Echo the user input to the main window. The ">" character indicates the user entered text.
        if (NL)
        {
            Serial.print(">HAHA ");
            NL = false;
        }
        Serial.write(c);
        if (c == 10)
            NL = true; // char '10' is the newline character
    }
}