//Initilize setup of SD Card which really just lets us know if it works sort of like a "hello world"
void setupSD(){
  Serial.println("Initializing SD card...");
  if(!SD.begin(chipSelect)){
    Serial.println("Card not found");
    return;
  }
  Serial.println("Card initialized");
}

//Writes any string data to SD card
void writeToSD(String dataString, String FileName){
  File file;
  if(SD.exists(FileName)){
    file = SD.open(FileName, FILE_WRITE);
  }else{
    Serial.println("No such file found");
    return;
  }
  file.println(dataString);
  file.close();
}

//Reads any data from any file on the SD card
String readData(String FileName){
    File file;
    String data;
    if(SD.exists(FileName)){
      file = SD.open(FileName, FILE_READ);
    }
    while (file.available()) {
      data = file.read();
    }
    return data;
}

//Creates any file on SD Card
void createFile(String FileName){
  File newFile;
  if(!SD.exists(FileName)){
    newFile = SD.open(FileName, FILE_WRITE);
  }else{
    Serial.println("FILE ALREADY CREATED");
    return;
  }
  newFile.close();
}

//Deletes any file on SD Card (Again a little bit unecessary so might be removed for more memory)(Could a command for this)
void deleteFile(String FileName){
  if(SD.exists(FileName)){
    SD.remove(FileName);
  }else{
    Serial.println("Can't find file");
  }
}

