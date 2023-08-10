#include <iostream>
#include <cstring>
// Including Guards 
#ifndef DetailsUser
#define DetailsUser

/// Global variables  @brief 
const char *ssid;      // For storing WIFI name 
const char *password;  // For Storing WIFI password 
const char *mqttBroker;// For Storing MqttBroker 
String options;        //For storing End User's input 

//Function for read end user input
static void serial_read(){
  Serial.print("Base: ");
  while (options.length() == 0){
  options = Serial.readStringUntil('\n');
  Serial.println(options);
  }

}
//Function for  serial printing 
static void serial_printdetails(){
  Serial.println("-------------------------");  
  Serial.print("YOUR WIFI NAME:");  
  Serial.println(ssid);
  Serial.print("YOUR Pass:");  
  Serial.println(password);
  Serial.print("YOUR Broker IP:");  
  Serial.println(mqttBroker);
  Serial.println("");
}

//Function for untilising end user details 
void Details_user()
{
  String opt_1 =  "WIFI";
  String opt_2 = "PHONE";
 
  serial_read();
  int result_1 = options.compareTo(opt_1); 
  int result_2 = options.compareTo(opt_2); 

  if (result_1 == 0 ){
    Serial.println("Using WI-FI");
    ssid = "SKYRCAXI";
    password = "ZgjBBKazUi1k";
    mqttBroker = "192.168.0.19";
    serial_printdetails();
  }
  if(result_2 == 0){
    Serial.println("Using Andriod");
    ssid = "Ope";
    password = "Turd1996";
    mqttBroker = "192.168.43.110";
    serial_printdetails();
  }
  delay(100);  
}
#endif 
