#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#include <Arduino.h>

#ifndef MY_BME
#define MY_BME

extern Adafruit_BME280 bme; // I2C

void setupBME280();
#endif 
