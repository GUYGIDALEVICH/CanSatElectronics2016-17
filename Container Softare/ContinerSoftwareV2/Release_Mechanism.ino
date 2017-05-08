void deploy(){
  pinMode(7, OUTPUT);
  if(trigger){
    digitalWrite(7, HIGH);
  }else{
    digitalWrite(7,LOW);
  }
}
