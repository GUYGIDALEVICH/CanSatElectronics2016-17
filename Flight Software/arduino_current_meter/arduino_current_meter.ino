
#define R 13.75

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
}

unsigned long t;

void loop() {
  // put your main code here, to run repeatedly:
  
  t = millis();
  
  double V = ( analogRead(A0) - analogRead(A1) ) * 5.0 / 1023.0;

  double mI = V/R * 1000;

  while ( (millis() - t) < 10){}
  Serial.println(mI);
  
}
