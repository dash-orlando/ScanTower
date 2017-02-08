/*
 * Read the switch
 * 
 * Fluvio L Lobo Fenoglietto
 * 02/07/2017
 */

#define dPin1 2
#define dPin2 3

void setup()
{
  Serial.begin( 115200 );
  Serial1.begin( 115200 );

  pinMode(dPin1, INPUT);
  pinMode(dPin2, INPUT);
  
}

void loop()
{

  if ( digitalRead(dPin1) == 1 )
  {
    Serial.println("G0 X100 Y-100 Z100");
    Serial1.println("G0 X100 Y-100 Z100");
  }

  if ( digitalRead(dPin2) == 1 )
  {
    Serial.println("G0 X-100 Y100 Z-100");
    Serial1.println("G0 X-100 Y100 Z-100");
  }
    
  delay(500);

}
