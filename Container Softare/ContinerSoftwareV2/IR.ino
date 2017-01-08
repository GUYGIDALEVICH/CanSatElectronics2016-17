void setupIR(){
  pinMode(irPin,INPUT);
   
}

boolean deployed(){
   int dist = sharp.distance();
    
    if (dist > 30){
      return true;
    } else{
      return false;
    }
}

void callIR(){
  TeleArray[TeleDeployed] = deployed();
}

