/*
   Read the switch

   Fluvio L Lobo Fenoglietto
   02/07/2017
*/

// Search for this within the buffer and re-enable the mototrs once its found
//ALARM: Hard limit


#define UP 2
#define DOWN 3

#define grblBoard Serial1

char grblOutput[50];
int strLen;

void setup()
{
  Serial.begin( 115200 );
  grblBoard.begin( 115200 );

  pinMode(UP, INPUT);
  pinMode(DOWN, INPUT);

  grblBoard.println("$21=1"); // Activates hard limits (physical sensors)
  while (grblBoard.available()) {
    Serial.write(grblBoard.read());
  }

}

void loop() {

  if (digitalRead(UP)) {
    Serial.println("G91 G0 X23 Y-23 Z23");
    Serial.println("M119");
    Serial.println("grblBoard Output: ");
    grblBoard.println("G91 G0 X24 Y-24 Z24");
    while (grblBoard.available()) {
      for (int i = 0; i < 50; i++) {
        grblOutput[i] = grblBoard.read();
        if (!grblBoard.available()){
          strLen = i;
          break;
        }
      }
    }
    for (int i=0; i<strLen; i++){
      Serial.print(grblOutput[i]);
    }
    Serial.print("\n");
  }


  else if (digitalRead(DOWN))
  {
    Serial.println("G91 G0 X-25 Y25 Z-25");
    Serial.println("M119");
    Serial.println("grblBoard Output: ");
    grblBoard.println("G91 G0 X-24 Y24 Z-24");
    while (grblBoard.available()) {
      for (int i = 0; i < 50; i++) {
        grblOutput[i] = grblBoard.read();
        if (!grblBoard.available()){
          strLen = i;
          break;
        }
      }
    }
    for (int i=0; i<strLen; i++){
      Serial.print(grblOutput[i]);
    }
    Serial.print("\n");
  }

  delay( 250 );

}
