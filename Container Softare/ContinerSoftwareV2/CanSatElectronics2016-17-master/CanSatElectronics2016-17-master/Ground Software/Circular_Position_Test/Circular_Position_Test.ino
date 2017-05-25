void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

int velocity = 1;
int heading = 0;


void loop() {
  // put your main code here, to run repeatedly:
  Serial.print(velocity, DEC);
  Serial.print(',');
  Serial.print(heading, DEC);
  Serial.println(',');

  heading = heading + 36;

  delay(1000);
}
