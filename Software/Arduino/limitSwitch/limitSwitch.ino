/*
 * Read the switch
 * 
 * Fluvio L Lobo Fenoglietto
 * 02/07/2017
 */

#define dPin1       2
#define dPin2       3
#define limitPin1   8

void setup()
{
  Serial.begin( 115200 );
  Serial1.begin( 115200 );

  pinMode(dPin1,     INPUT);
  pinMode(dPin2,     INPUT);
  pinMode(limitPin1, INPUT);
  
}

void loop()
{

  // Down
  if ( digitalRead(dPin1) == 1 && digitalRead(limitPin1) == 0 )
  {
    Serial.println("G91 G0 X25 Y-25 Z25");
    Serial1.println("G91 G0 X25 Y-25 Z25");
  }

  // Up
  if ( digitalRead(dPin2) == 1 )
  {
    Serial.println("G91 G0 X-25 Y25 Z-25");
    Serial1.println("G91 G0 X-25 Y25 Z-25");
  }

  // Limit
  if ( digitalRead(limitPin1) == 1 )
  {
    Serial.println("SWITCH HIGH"); 
  }
    
  delay(500);

}
