#define deployPin 7; // <-- change this to whatever pin the wire burning the string will be connected to.

void deloy(){
  digitalWrite(deployPin, HIGH);
  //delay(100);  //<-- add delay to turn off burning wire?
  //digitalWrite(deployPin, LOW); //<-- turns off the wire
}


