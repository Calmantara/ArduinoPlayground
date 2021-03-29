//include all libraries needed
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Make sure to update this for your own WiFi network!
const char *ssid = "SSID";
const char *wifi_password = "password";

// MQTT Broker using HiveMQ
const char *mqtt_server = "192.168.100.191";
const char *mqtt_topic = "test/esp8266";

//client unique id so can easy to parse
const char *clientID = "ESP8266_1";

// Initialise the WiFi and MQTT Client objects
WiFiClient wifiClient;
PubSubClient client(mqtt_server, 1883, wifiClient);

void setup()
{
    // Connect to the WiFi
    WiFi.begin(ssid, wifi_password);

    // Wait until the connection has been confirmed before continuing
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }
}

void loop()
{
    //connect to client
    client.connect(clientID);
    delay(10);
    //generate value
    float rand = random(10, 1000);
    String randString = String(rand);
    client.publish(mqtt_topic, randString);
    delay(1000);
}