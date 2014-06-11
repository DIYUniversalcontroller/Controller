/* By R. Plag, December 2009
*/

#include <DS18B20.h>

/* Create and initialize the list of DS18B20 sensors. 
*/
DS18B20_List ds18b20(10); // pin 10

/* Selecting sensors by 'id':
   
   If you have really bad luck, you can have two sensors with
   the same id in your array, since there are only 65535 ids and 
   billions of serial numbers. In such a case, replace the 'bad'
   sensor or access it via get_temp_by_no().
   
   If you use the 'id' instead of the 'no' to select a 
   sensor, you no longer depend on the 
   the index of the sensor in the list which may
   change if you add, remove or exchange a sensor.   
   
   You will obtain T=85.0 if the sensor is not present.
*/
#define ID_OUTSIDE 0xABC5 // use an id of one of your sensors here



/* Nothing special needed here...
*/
void setup(void) {
  Serial.begin(9600);

  Serial.print("Sensors found: ");
  Serial.println(ds18b20.count,DEC);
}



void loop(void) {
  
  Serial.println();

  /* Here we wait for the conversion to finish.
     You may do some other things with your Arduino here.
     Since this demo program doesn't do anything else 
     and a temperature conversion takes approx one second,
     we simple do a:
  */
  delay(1000);

  /* Read temperature values and start next conversion.
     You can call this as often as you like. You will,
     however, get new values only once per second. 
     If the previous conversion has not yet finished, the 
     function will return without doing anything.
  */
  ds18b20.update(); 
  
  /* print temperature and id of all sensors. The order
     of the list may change if you add, remove, or exchange
     as sensor.
  */
  for (int i=0;i<ds18b20.count;i++)
    {
    Serial.print("Sensor ");
    Serial.print(i,DEC);
    Serial.print(", id=0x");
    Serial.print(ds18b20.get_id(i),HEX);
    Serial.print(", T=");
    print_temperature(ds18b20.get_temp(i));
    Serial.println("C");
    }
    
  /* Print temperature of a unique sensor using its id. The id
     will not change if you add, remove or exchange a sensor, but
     it requires that you know the ids of your sensors, e.g. from 
     the output above. You receive T=85.0 if the id is not known.
  */
  float T_outside=ds18b20.get_temp_by_id(ID_OUTSIDE);
  Serial.print("Outside temperature: ");
  print_temperature(T_outside);
  Serial.println("C");
  
  return;

}
