void TransmitSegment(){
  //Check to see if new picture has been taken
  if (lastPicNum != latestPicNum){
    //resets segment count
    segment = 1;
    transLength_2 = transLength_1;
  }

  //Selects file to transmit
  strcpy(readName, fileName);


  //Opens File Segment
  File readFile;
  readFile = SD.open(readName);

  //if the file segment exists
  if (readFile){
    //Prints the current segment and the number of segments
    Serial.print(segment, DEC);
    Serial.print(",");
    Serial.print(numSegments, DEC);
    Serial.print(",");
    //while there is data remaining in segment

    /////////////////////////////////////////
    transStartBit = (segment - 1) * imgPacketSize;
    int pl = min (imgPacketSize, transLength_2);
    transEndBit = transStartBit + pl;
    
    readFile.seek(transStartBit);
   for ( int b = transStartBit; b < transEndBit ; b++) {
      Serial.print(readFile.read(), HEX);
   }
   transLength_2 -= imgPacketSize;
    //////////////////////////////////////////
    Serial.print("\n");
    //closes the file
    readFile.close();
  }

  //iterates/loops the segment number
  if (segment == numSegments){
    segment = 1;
  } else {
    segment++;
  }
  
}

