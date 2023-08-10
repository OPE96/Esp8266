#include <ArduinoJson.h>
#include <PubSubClient.h>
#include <My_Mqtt.h> // include mqtt connect file 


//have set the read cycle time to 3000ms or 3 seconds 
//which means that read from BME 280 sensor values every 3 seconds and publish it to our MQTT broker
unsigned long lastMsg = 0;
const int READ_CYCLE_TIME = 3000;


void pub_data()
{
     // publish BME280 sensor readings periodically
  unsigned long now = millis();
  if (now - lastMsg > READ_CYCLE_TIME)
  {
    lastMsg = now;

    //  Publish MQTT messages
    char buffer[256];
    StaticJsonDocument<96> doc;
    doc["temperature"] = bme.readTemperature();
    doc["humidity"] = bme.readHumidity();
    doc["pressure"] = bme.readPressure() / 100.0F;
    doc["Light"] = analogRead(A0);
    size_t n = serializeJson(doc, buffer);
    client.publish(publishTopic, buffer, n);
  }
}