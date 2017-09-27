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
        //int currentValue = analogRead(_pin);
        moistureValues[i] = analogRead(_pin); 
    }

    // Combine array into one average value.
    int avgMoisture = ((moistureValues[0] + moistureValues[1] + moistureValues[2] +
                      moistureValues[3] + moistureValues[4]) / 5);

    return avgMoisture;
}

void SoilMoisture::printReading(int soilMoisture)
// Take in value from 'readSoil' to print raw data to serial monitor
{
    Serial.print("Soil Moisture: ");
    Serial.print(soilMoisture);
    Serial.print("\n");
}

float SoilMoisture::getFormattedValue(int avgMoisture)
/*
    Accept value obtained from 'readSoil' to format as an easier-to-understand value
    Returns a rounded answer. One number in initial operation needs to be a
    float in order to get an answer back from the division.
 */
{
    const int minValue{0};
    const float analogMax{1023};
    const int formattedMax{100}; // New values will be between 0 and 100

    float formattedValue = (avgMoisture / analogMax) * formattedMax;
    return round(formattedValue);

}

bool SoilMoisture::moistureInterval(unsigned long soilCheckPeriod, unsigned long currentTime,
                unsigned long previousTime)
/* 
    Takes in values recorded in sketch to determine if enough time has passed
    to measure the soil moisture again. All inputs are divided by the 
    soilCheckPeriod to bring the numbers down to a more sensible scale.
    i.e. one day: 86,400,00 ms is 1 day.
*/
{
    int soilCheck = (soilCheckPeriod / soilCheckPeriod);
    float currentT = (currentTime / soilCheckPeriod);
    float previousT = (previousTime / soilCheckPeriod);

    // First logic check tests if the value for time has overflowed back to 0
    // which would give currentTime a lower value than previousTime.
    // The second checks if the appropriate time has passed.
    if ((currentTime > previousTime) && (currentTime - previousTime >= soilCheckPeriod))
    {
        return true;
    }
    else
    {
        return false;
    }
}
