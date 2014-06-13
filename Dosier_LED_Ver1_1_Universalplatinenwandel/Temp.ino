/*|||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||  D E F I N E  :  T E M P E R A T U R |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||*/

void requestTemperature(DeviceAddress deviceAddress)
{
  // DS18B20 display
  sensors.requestTemperatures(); // Send the command to get temperatures

    tempLampe1 = sensors.getTempC(lampeThermometer1);
    tempLampe2 = sensors.getTempC(lampeThermometer2);
    tempWasser = sensors.getTempC(wasserThermometer);
    tempRaum = sensors.getTempC(raumThermometer);

}

