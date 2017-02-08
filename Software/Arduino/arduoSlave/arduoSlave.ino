/*
 * Ardu Slave
 */

void setup() {
  Serial.begin(9600);

}

void loop() {
  if ( Serial.available() > 0 )
  {
    String inString = Serial.readString();
    Serial.println(inString); 
  }
}
