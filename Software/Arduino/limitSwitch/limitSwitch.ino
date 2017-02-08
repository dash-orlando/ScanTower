/*
 * Read the switch
 * 
 * Fluvio L Lobo Fenoglietto
 * 02/07/2017
 */

#define dPin1       2
#define dPin2       3
#define limitPin1   8
#define resetPin    9
#define estopPin    10

void setup()
{
  Serial.begin( 115200 );
  Serial1.begin( 115200 );

  pinMode(dPin1,     INPUT);
  pinMode(dPin2,     INPUT);
  pinMode(limitPin1, INPUT);
  pinMode(resetPin, OUTPUT);
  pinMode(estopPin, OUTPUT);
  
}

void loop()
{

  // Down
  if ( digitalRead(dPin1) == 1 && digitalRead(limitPin1) == 0 )
  {
    Serial.println("G91 G0 X5 Y-5 Z5");
    Serial1.println("G91 G0 X5 Y-5 Z5");
  }

  // Up
  if ( digitalRead(dPin2) == 1 )
  {
    Serial.println("G91 G0 X-5 Y5 Z-5");
    Serial1.println("G91 G0 X-5 Y5 Z-5");
  }

  // Down Limit
  if ( digitalRead(limitPin1) == 1 )
  {
    digitalWrite(estopPin, HIGH);
    //delay(50);
    digitalWrite(estopPin, LOW);
    //delay(50);
    digitalWrite(resetPin, HIGH);
    //delay(50);
    digitalWrite(resetPin, HIGH);
    //delay(50);
    Serial.println("G91 G0 X-25 Y25 Z-25");
    Serial1.println("G91 G0 X-25 Y25 Z-25");
  }
    
  delay(100);

}
