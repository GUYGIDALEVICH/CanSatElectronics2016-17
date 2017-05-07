void setupSD(){
  Serial.println("Initializing SD card...");
  if(!SD.begin(chipSelect)){
    Serial.println("Card not found");
    return;
  }
  Serial.println("Card initialized");
}

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

void deleteFile(String FileName){
  if(SD.exists(FileName)){
    SD.remove(FileName);
  }else{
    Serial.println("Can't find file");
  }
}

