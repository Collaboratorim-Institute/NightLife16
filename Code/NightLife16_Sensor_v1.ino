/************************
 * Company | Collaboratorium Institute
 * Partiner | Academy of Science
 * Project | Night Life
 * Name | William Felker and Adam Lukasik
 * Build | Version 1.0
 * *********************/


// DEFINE VARABLES //
int boardLed = D7;
int snsrMicrophone = A1;
int DELAY = 100;

#define myID

void setup() {
  pinMode(boardLed,OUTPUT);
  pinMode(snsrMicrophone,INPUT);
  Serial.begin(9600);
}

void loop() {
    digitalWrite(boardLed,HIGH);
    //String noiseLevel = analogRead(snsrMicrophone); // store temp in "noiseLevel" string
    Particle.publish("nl", String(analogRead(snsrMicrophone)), PUBLIC); // publish to cloud
    digitalWrite(boardLed,LOW);
    delay(500);
}
