# moisture-sensor
Arduino library for a soil moisture sensor

Just a basic library for working with an analog soil moisture sensor on the Arduino. 
As of the initial release there is a function for reading the raw output from the sensor and printing that output to the serial monitor.
I'll be adding to the functionality for the time being, and adding all updates here. This is my first time writing a library for Arduino or anything, so all feedback is most welcome.

If anybody has any questions or comments, please let me know.

Thanks  

SoilMoisture::readSoil()  
  Takes 5 readings from the moisture sensor with 1/2 second delay between readings. The function returns the average of those 5  measurements.  
  
SoilMoisture::printReading(int soilMoisture)
  Takes an integer value as an argument to print to the serial monitor.  
  
SoilMoisture::getFormattedValue(int avgMoisture)
  Takes an integer value (i.e raw data from readSoil()) and returns it as a rounded number between 0 and 100. This function returns a float.  
  
