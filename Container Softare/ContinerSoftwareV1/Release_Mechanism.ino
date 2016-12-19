#define deployPin 7; // <-- change this to whatever pin the wire burning the string will be connected to.

void deloy(){
  digitalWrite(deployPin, HIGH);
  //delay(100);  //<-- find out how long it takes for the wire to burn through
  //digitalWrite(deployPin, LOW); //<-- turns off the wire
}
