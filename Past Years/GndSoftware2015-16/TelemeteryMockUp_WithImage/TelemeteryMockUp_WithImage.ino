#include <SPI.h>
#include <SD.h>

File myFile;
int packet = 0;

void setup() {
   // Open serial communications and wait for port to open:
  Serial.begin(19200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
 // Serial.println("Initializing SD card...");
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }

  myFile = SD.open("IMAGE01.JPG");
  if (myFile) {
    //Serial.println("IMAGE");


    for (int g=0; g<10; ++g){
   Serial.print ("1086,");
   Serial.print (++packet);
   Serial.println (",21.1,33.5,434,66,4.33,22,344,34,53,24,5,55,542,4,44,3,");
      delay (1000);
      }

   
   
    int seq = -1;
    // read from the file until there's nothing else in it:
    while (myFile.available()) {
   Serial.print ("1086,");
   Serial.print (++packet);
   Serial.print (",21.1,33.5,434,66,4.33,22,344,34,53,24,5,55,542,4,44,3,");
      for (int c = 0; c<ceil(myFile.size()/14); ++c){
        if (myFile.available()){
        byte data = myFile.read();
        if (data < 16){Serial.print(0);}
        Serial.print(data, HEX);
        }
      }
      Serial.println ("");
    }
    myFile.close();
  } else {
    Serial.println("error opening test.txt");
  }
}

void loop() {
   Serial.print ("1086,");
   Serial.print (++packet);
   Serial.println (",21.1,33.5,434,66,4.33,22,344,34,53,24,5,55,542,4,44,3,");
      delay (1000);
      
}


