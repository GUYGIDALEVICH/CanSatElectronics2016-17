void setupPitot(){

  pinMode(powerPitot, OUTPUT);
  
}


void pitotTube() {
  //declarations
  int sensorValue = 0; 
  float Vout=0;
  float P=0;
  float Pa;
  float rho;
    int i=0;
    int sum=0;
    int offset=0;

    digitalWrite(powerPitot, HIGH);

    delay(25);
    
    //Serial.println("init...");
    for(i=0;i<10;i++)
    {
         sensorValue = analogRead(pitotPin)-512;
         sum+=sensorValue;
    }
    offset=sum/10.0;
    //Serial.println("Ok");

       sensorValue = analogRead(pitotPin)-offset; 
       Vout=(5*sensorValue)/1024.0;
       P=Vout-2.5;  
       Pa= -P*1000;         
      // Serial.print("Presure = " );                       
      // Serial.print(Pa); 
      // Serial.println("Pa");
      // rho=(P)/(RT)

      rho= TeleArray[TelePressure]/(287*(TeleArray[TeleTemp]+273.15));
      
      
      // Serial.println(" Velocity= ");
       //bernoulli
       //Serial.println(sqrt((2*Pa)/ rho));
  
       //Serial.print(" m/s");
       TeleArray[TeleSpeed]= sqrt((2*Pa)/ rho);

       
       digitalWrite(powerPitot, LOW);   
    
}
