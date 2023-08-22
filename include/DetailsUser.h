#include <Arduino.h>

// Including Guards 
#ifndef DetailsUser
#define DetailsUser

void Details_user();


/// Global variables  @brief 
//declaring the existence of the variable but haven’t brought in actual existence by defining it,
extern const char *ssid;      // For storing WIFI name 
extern const char *password;  // For Storing WIFI password 
extern const char *mqttBroker;// For Storing MqttBroker 
extern String options;       //For storing End User's input 

#endif 
