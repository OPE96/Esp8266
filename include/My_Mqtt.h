#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <Adafruit_Sensor.h>
#include <ArduinoJson.h>

// Including Guards 
 #ifndef My_Mqtt
 #define My_Mqtt
const int mqttPort = 1883;
// MQTT topics
const char *publishTopic = "sensorReadings";
const char *subscribeTopic = "sampletopic";

//Declare an instance of  PubSubClient which will act as my interface to my MQTT broker. 
WiFiClient espClient;
PubSubClient client(espClient);


// Callback function whenever an MQTT message is received
void callback(char *topic, byte *payload, unsigned int length)
{
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String message;
  for (int i = 0; i < length; i++)
  {
    Serial.print(message += (char)payload[i]);
  }
  Serial.println();
}

void reconnect()
{
  // Loop until we're reconnected
  while (!client.connected())
  {
    Serial.print("Attempting MQTT connection...");

    // Create a random client ID
    String clientId = "ESP32Client-";
    clientId += String(random(0xffff), HEX);

    // Attempt to connect
    if (client.connect(clientId.c_str()))
    {
      Serial.println("connected");

    }
    else
    {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}
#endif 
