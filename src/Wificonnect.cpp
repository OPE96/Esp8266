#include <DetailsUser.h> // Include DetailsUser.h file for End User input
#include <Arduino.h>
#include <ESP8266WiFi.h>
// Function Connect to Wifi
void setup_wifi()
{
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED)
  {

    Serial.println("Initial Wi-Fi not available, attempting to connect to alternate Wi-Fi");
    delay(500);
    Serial.print(".");
  }

  randomSeed(micros());

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}