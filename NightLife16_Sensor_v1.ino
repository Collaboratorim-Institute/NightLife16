/************************
 * Company | Collaboratorium Institute
 * Department | Academy of Science
 * Project | Night Life
 * Name | William Felker and Adam Lukasik
 * Build | Version 1.0
 * *********************/


// DEFINE VARABLES //
int boardLed = D7;
int snsrMicrophone = A*;
int DELAY = 100;

#define myID

void setup() {
  pinMode(boardLed,OUTPUT);
  pinMode(snsrMicrophone,INPUT);

  Serial.begin(9600);
  while(!Serial.available()) Particle.process();

  Serial.println(myID);
  String myID = System.deviceID();
}

void loop() {


  checkSensor();
  //troubleshoot();
}


// FUNCTIONS //
void checkSensor(){

  String noiseLevel = analogRead(snsrMicrophone); // store temp in "noiseLevel" string
    Particle.publish("Noise Level", noiseLevel, PRIVATE); // publish to cloud
    delay(5000);

/*
      Particle.publish("Noise Level", analogRead(snsrMicrophone);, PRIVATE);
      delay(5000); // 5 second delay
*/
/*
    String temperature = String(fahrenheit); // store temp in "temperature" string
      Particle.publish("Noise Level", temperature, PRIVATE); // publish to cloud
      delay(5000); // 5 second delay
*/
}

void troubleshoot(){

}
