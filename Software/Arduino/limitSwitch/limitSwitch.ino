/*
 * Read the switch
 * 
 * Fluvio L Lobo Fenoglietto
 * 02/07/2017
 */

#define dPin1             2
#define dPin2             3
#define limitPinBOTTOM    8
#define resetPin          9
#define estopPin          10
#define limitPinTOP       11

void setup()
{
  Serial.begin( 115200 );
  Serial1.begin( 115200 );

  pinMode(dPin1,          INPUT);
  pinMode(dPin2,          INPUT);
  pinMode(limitPinBOTTOM, INPUT);
  pinMode(limitPinTOP,    INPUT);
  pinMode(estopPin,       OUTPUT);
  
}

void loop()
{

  // Down
  if ( digitalRead(dPin1) == 1 && digitalRead(limitPinBOTTOM) == 0 )
  {
    Serial.println("G91 G0 X15 Y-15 Z15");
    Serial1.println("G91 G0 X15 Y-15 Z15");
  }

  // Up
  else if ( digitalRead(dPin2) == 1 && digitalRead(limitPinTOP) == 0 )
  {
    Serial.println("G91 G0 X-15 Y15 Z-15");
    Serial1.println("G91 G0 X-15 Y15 Z-15");
  }

  // Down Limit
  if ( digitalRead(limitPinBOTTOM) == 1 )
  {
    digitalWrite(estopPin, HIGH);
    //delay(50);
    digitalWrite(estopPin, LOW);
    Serial.println("G91 G0 X-25 Y25 Z-25");
    Serial1.println("G91 G0 X-25 Y25 Z-25");
  }

  // Up Limit
  else if ( digitalRead(limitPinTOP) == 1 )
  {
    digitalWrite(estopPin, HIGH);
    //delay(50);
    digitalWrite(estopPin, LOW);
    Serial.println("G91 G0 X25 Y-25 Z25");
    Serial1.println("G91 G0 X25 Y-25 Z25");
  }
    
  delay(150);

}
