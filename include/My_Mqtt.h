#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <ArduinoJson.h>

// Including Guards 
 #ifndef My_Mqtt
 #define My_Mqtt
extern const int mqttPort;
// MQTT topics
extern const char *publishTopic ;
extern const char *subscribeTopic;

//Declare an instance of  PubSubClient which will act as my interface to my MQTT broker. 
extern WiFiClient espClient;
extern PubSubClient client;
void callback(char *topic, byte *payload, unsigned int length);
void reconnect();
#endif 
