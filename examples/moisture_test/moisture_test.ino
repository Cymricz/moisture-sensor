/*
 * Test sketch for reading values from Phantom YoYo soil
 * moisture sensors. This code would probably work with any 
 * similar sensor. This is an analog 3-pin sensor with VCC, GND, 
 * and 1 analog output pin. Sensor readings vary based on depth in
 * soil, so make sure to keep it in the same spot to get consistent 
 * readings. 
 */
#include "SoilMoisture.h"

SoilMoisture sensorOne(A0);
//SoilMoisture sensorTwo(A1);

void setup() 
{
  Serial.begin(9600);
  Serial.println("Soil Moisture test values!");
  
}

void loop() 
{
  delay(1000); // Delay between reading sensor(s).
  int soilMoistureA = sensorOne.readSoil();
  //int soilMoistureB = sensorTwo.readSoil();
  
  sensorOne.printReading(soilMoistureA);
  int x = sensorOne.getFormattedValue(soilMoistureA);
  Serial.print(x);
  
}
