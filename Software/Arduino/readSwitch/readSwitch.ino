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
    Serial.println("G91 G0 X50 Y-50 Z50");
    Serial1.println("G91 G0 X50 Y-50 Z50");
  }

  if ( digitalRead(dPin2) == 1 )
  {
    Serial.println("G91 G0 X-50 Y50 Z-50");
    Serial1.println("G91 G0 X-50 Y50 Z-50");
  }
    
  delay(500);

}
