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
#define CAN (char)0x18    // ^x - Cancel, abort

#define RESET_PIN 9

char grblOutput[50];

int strLen;

void setup() {
  Serial.begin( 115200 );
  grblBoard.begin( 115200 );

  pinMode( UP,   INPUT );
  pinMode( DOWN, INPUT );

  grblBoard.println( "$RST=$" );
  grblBoard.println( "$21=1" );                       // Activates hard limits (physical sensors)
  //grblBoard.println("$22=1");
  while ( grblBoard.available() ) {
    Serial.write( grblBoard.read() );
  }

}

void loop() {
  if ( digitalRead( UP ) ) {
    Serial.println( "Sending:  G91 G0 X25 Y-25 Z25" );
    Serial.println( "grblBoard Output: " );
    grblBoard.println( "G91 G0 X25 Y-25 Z25" );

    while ( grblBoard.available() ) {
      for ( int i = 0; i < 50; i++ ) {
        grblOutput[i] = grblBoard.read();

        if ( !grblBoard.available() ) {
          strLen = i;
          break;
        }
      }
    }

    for ( int i = 0; i < strLen; i++) {
      Serial.print( grblOutput[i] );
    } Serial.print( "\n" );
    for (int i = 0; i < strLen; i++) {
      if (grblOutput [i] == 'A') {
        Serial.println("Resetting");
        grblBoard.println( "$RST=$" );
      }
    }
  }


  else if ( digitalRead( DOWN ) ) {
    Serial.println( "Sending:  G91 G0 X-25 Y25 Z-25" );
    Serial.println( "grblBoard Output: " );
    grblBoard.println( "G91 G0 X-25 Y25 Z-25" );

    while ( grblBoard.available() ) {
      for ( int i = 0; i < 50; i++ ) {
        grblOutput[i] = grblBoard.read();

        if ( !grblBoard.available() ) {
          strLen = i;
          break;
        }
      }
    }

    for ( int i = 0; i < strLen; i++) {
      Serial.print( grblOutput[i] );
    } Serial.print( "\n" );
    for (int i = 0; i < strLen; i++) {
      if (grblOutput [i] == 'A') {
        Serial.println("Resetting");
        grblBoard.println( "$RST=$" );
      }
    }
  } delay( 250 );

}
