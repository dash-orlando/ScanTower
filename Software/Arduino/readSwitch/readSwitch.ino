/*
 * Read the switch
 * 
 * Fluvio L Lobo Fenoglietto
 * 02/07/2017
 */

#define dPin1  8
#define dPin2  9

void setup() {
  Serial.begin(9600);
  pinMode(dPin1, INPUT);
  pinMode(dPin2, INPUT);
}

void loop() {

  boolean status_dPin1 = digitalRead(dPin1);
  boolean status_dPin2 = digitalRead(dPin2);

  Serial.print( "Status of dPin1 = " );
  Serial.println(status_dPin1);
  Serial.print( "Status of dPin2 = " );
  Serial.println(status_dPin2);

  delay(500);

}
