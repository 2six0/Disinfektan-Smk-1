#define infra 7
#define echoPin 5 //Echo Pin
#define trigPin 6 //Trigger Pin
const int relay_1 = 2;

int maximumRange = 200; //kebutuhan akan maksimal range
int minimumRange = 00; //kebutuhan akan minimal range
long duration, distance;

void setup() {
  Serial.begin(9600);
  pinMode(infra, INPUT);
  pinMode(relay_1, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  //perhitungan untuk dijadikan jarak
  distance = duration / 58.2;

  if(distance >= maximumRange || distance <= minimumRange){
    digitalWrite(relay_1,LOW);
  }
  else {
    digitalWrite(relay_1,HIGH);
  }
  Serial.println(distance);
}
