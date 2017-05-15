void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(10, OUTPUT);
  digitalWrite(10, LOW);
  
}
unsigned long bTime;
unsigned long bStart;
void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){

    char sRead = Serial.read();
    
    if (sRead== '*'){
      digitalWrite(10, HIGH);
      bStart = millis();
      Serial.println("Burn Start");
      
    }

    if (sRead == '-'){
      digitalWrite(10, LOW);
      bTime = millis() - bStart;
      Serial.print("Burn End     Time: ");
      Serial.println(bTime / 1000.0);
      Serial.println("*************************");
    }
  }
  
  delay(10);
}
