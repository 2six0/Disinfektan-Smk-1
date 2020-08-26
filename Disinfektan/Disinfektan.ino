#define infra 7
const int relay_1 = 2;


void setup(){
  Serial.begin(9600);
  pinMode(infra,INPUT);
  pinMode(relay_1,OUTPUT);
}

void loop() {
  int v = digitalRead(infra);
  Serial.println(v);
  if(v == 1)//Tergantung Trigger dari infra atau sensor
  {
    digitalWrite(relay_1,HIGH);
  }
  else
  {
    digitalWrite(relay_1,LOW);
  }
}
