#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <My_Mqtt.h> // include mqtt connect file 

 #ifndef Pub_myMqtt
 #define Pub_myMqtt
//have set the read cycle time to 3000ms or 3 seconds 
//which means that read from BME 280 sensor values every 3 seconds and publish it to our MQTT broker
extern unsigned long lastMsg;
extern const int READ_CYCLE_TIME;


void pub_data();
#endif