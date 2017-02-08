/*
 * Read the switch
 * 
 * Fluvio L Lobo Fenoglietto
 * 02/07/2017
 */

void setup()
{
  Serial.begin( 115200 );
  Serial1.begin( 115200 );
  
}

void loop()
{

  Serial.println("G0 X100");
  Serial1.println("G0 X100");  
  delay(500);

  Serial.println("G0 X-100");
  Serial1.println("G0 X-100");  
  delay(500);

}
