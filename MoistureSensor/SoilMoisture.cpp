/*
    Soil.cpp - Library for reading Phantom YoYo soil moisture sensor
    Copyright (C) 2017 Cymric Cramer
    Released under the GNU General Public License, the full license
    can be found in LICENSE.txt in this library's directory.
*/

#include "Arduino.h"
#include "SoilMoisture.h"


SoilMoisture::SoilMoisture(int pin)
{
    pinMode(pin, INPUT);
    _pin = pin;
}

int SoilMoisture::readSoil()
// Read values from moisture sensor and average readings over a period.
{
    int moistureValues[5];

    for(int i = 0; i < 5; i++) // Fill an array with values read from sensor.
    {
        delay(500); // Delay in miliseconds between readings for average.
        moistureValues[i] = analogRead(_pin); 
    }

    // Combine array into one average value.
    int avgMoisture = ((moistureValues[0] + moistureValues[1] + moistureValues[2] +
                      moistureValues[3] + moistureValues[4]) / 5);

    return avgMoisture;
}

void SoilMoisture::printReading(int soilMoisture)
// Take in value from 'readSoil' as argument to print to serial monitor
{
    Serial.print("Soil Moisture: ");
    Serial.print(soilMoisture);
    Serial.print("\n");
}

