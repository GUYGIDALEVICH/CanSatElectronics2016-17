void UpdateStaging (){
  #ifdef USE_EXTEEPROM
  EEPROM.get(EEPROM_StageAdress, StageNumber);
  #endif
  
  switch (StageNumber){
      //.STAGE 1.Boot/Ascent stage:: Stage tasks: Do nothing
    case(1):
      if (pre>ReleaseAltitude && abs(pre-ReleaseAltitude)>AltitudeFilterOffset){
        ++StageNumber;
      }
    break;

    
    //.STAGE 2. second Below 400m again ,Released stage
    case(2): 
      //Transition condition, If altitude ever exceeds release altitude
      if (abs(pre) < GroundAproximationAltitude ){
        ++StageNumber;
      }
    break;

    // .STAGE 3. Landed stage
    case(3): 
      //No transition
    break;
    
    default: 
      StageNumber = 0;
    break;
  }
  #ifdef USE_EXTEEPROM
  EEPROM.update(EEPROM_StageAdress, StageNumber); //Save stage back
  #endif USE_EXTEEPROM
}

