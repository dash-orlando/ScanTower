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
    Serial.println("G91 G20 X0.25 Y-0.25 Z0.25");
    Serial1.println("G91 G20 X0.25 Y-0.25 Z0.25");
    delay(5);
  }

  // Up
  else if ( digitalRead(dPin2) == 1 && digitalRead(limitPinTOP) == 0 )
  {
    Serial.println("G91 G20 X-0.25 Y0.25 Z-0.25");
    Serial1.println("G91 G20 X-0.25 Y0.25 Z-0.25");
    delay(5);
  }

  // Down Limit
  if ( digitalRead(limitPinBOTTOM) == 1 )
  {
    digitalWrite(estopPin, HIGH);
    digitalWrite(estopPin, LOW);
    Serial.println("G91 G20 X-0.5 Y0.5 Z-0.5");
    Serial1.println("G91 G20 X-0.5 Y0.5 Z-0.5");
  }

  // Up Limit
  else if ( digitalRead(limitPinTOP) == 1 )
  {
    digitalWrite(estopPin, HIGH);
    digitalWrite(estopPin, LOW);
    Serial.println("G91 G20 X0.5 Y-0.5 Z0.5");
    Serial1.println("G91 G20 X0.5 Y-0.5 Z0.5");
  }
    
  delay(60);

}
