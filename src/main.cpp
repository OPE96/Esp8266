#include <iostream>
#include <cstring>
#include <Arduino.h>
#include <DetailsUser.h> // Include DetailsUser.h file for End User input
#include <Wificonnect.h>// Include Wifi.h file for connection to the Wifi
#include <MY_BME.h> // Include setup for BME SENSOR
#include <My_Mqtt.h> // include mqtt connect file 
#include <Pub_myMqtt.h> // include publish sensor data over mqtt


void setup()
{
  Serial.begin(115200);
  Details_user();
  // Setup the wifi
  setup_wifi();
  // setup bme280
  setupBME280();
  // setup the mqtt server and callback
  client.setServer(mqttBroker, mqttPort);
  client.setCallback(callback);
}

void loop()
{
  // Listen for mqtt message and reconnect if disconnected
  if (!client.connected())
  {
    reconnect();
    
  }
  client.loop();

  // publish BME280 sensor readings periodically
  pub_data();

 
}