void setupCamera(){
if (cam.begin()) {
    //Serial.println("Camera Found:");
  } else {
    //Serial.println("No camera found?");
    return;
  }
  
  //Set Image Size
  cam.setImageSize(VC0706_640x480);     
}

void takeSnap(){

  cam.resumeVideo();
  cam.takePicture(); //if not 
    //Serial.println("Failed to snap!");
  //else 
    //Serial.println("Picture taken!");

  //Create image filename
  char IMGfilename[13];
  strcpy(IMGfilename, "IMAGE00.JPG");
  for (int i = 0; i < 100; i++) {
    IMGfilename[5] = '0' + i/10;
    IMGfilename[6] = '0' + i%10;
    // create if does not exist, do not open existing, write, sync after write
    if (! SD.exists(IMGfilename)) {
      break;
    }
  }


  


  
}

