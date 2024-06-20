const int trigPin1 = 2; // trigger pin ultrasonic sensor 1 
const int echoPin1 = 3; // echo pin ultrasonic sensor 1
const int trigPin2 = 4; // trigger pin ultrasonic sensor 2
const int echoPin2 = 5; // echo pin ultrasonic sensor 2
const int trigPin3 = 6; // trigger pin ultrasonic sensor 3
const int echoPin3 = 7; // echo pin ultrasonic sensor 3
int irpin =8; // ir sensor

long duration1;
long duration2;
long duration3;
int distanceleft;
int distancefront;
int distanceright; 

int a=0;
void setup() {
  Serial.begin(9600);
  pinMode(trigPin1, OUTPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(trigPin3, OUTPUT);// Sets the trigPin as an Output
  pinMode(echoPin1, INPUT); // Sets the echoPin as an Input
  pinMode(echoPin2, INPUT);
  pinMode(echoPin3, INPUT);
  pinMode(irpin, INPUT);
  pinMode(9, OUTPUT);  // pin 9 is wheel motor 1 positive
  pinMode(10, OUTPUT); // pin 10 is wheel motor 1 negative 
  pinMode(11, OUTPUT); // pin 11 is wheel motor 2 positive  
  pinMode(12, OUTPUT); // pin 12 is wheel motor 2 negative
  pinMode(0, OUTPUT);  // pin 0 is broom motor positive 
  pinMode(13, OUTPUT); // pin 13 is broom motor negative
  pinMode(A0, OUTPUT); // pin A0 is mop motor positive 
  pinMode(A1, OUTPUT); // pin A1 is mop motor positive 
}
void loop() {
  digitalWrite(trigPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);
  duration1 = pulseIn(echoPin1, HIGH);
  distanceleft = duration1 * 0.034 / 2;
  Serial.print("Distance1: ");
  Serial.println(distanceleft);
  digitalWrite(trigPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);
  duration2 = pulseIn(echoPin2, HIGH);
  distancefront = duration2 * 0.034 / 2;
  Serial.print("Distance2: ");
  Serial.println(distancefront);
  digitalWrite(trigPin3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);
  duration3 = pulseIn(echoPin3, HIGH);
  distanceright = duration3 * 0.034 / 2;
  Serial.print("Distance3: ");
  Serial.println(distanceright);
  int s = digitalRead(irpin);
  if(s==HIGH)
  { 
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(0, HIGH);
    digitalWrite(13 ,LOW);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    delay(1000);
    a=1;
    }
  if ((a==0)&&(s==LOW)&&(distanceleft <= 15 && distancefront > 15 && distanceright <= 15) || (a==0)&&(s==LOW)&&(distanceleft > 15 && distancefront > 15 && distanceright > 15))
  {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, HIGH);
    digitalWrite(12,LOW);
    digitalWrite(0, HIGH);
    digitalWrite(13 ,LOW);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
  }
  if ((a==1)&&(s==LOW)||(s==LOW)&&(distanceleft <= 15 && distancefront <= 15 && distanceright > 15)||(s==LOW)&&(distanceleft <= 15 && distancefront <= 15 && distanceright > 15)||(s==LOW)&& (distanceleft <= 15 && distancefront > 15 && distanceright > 15)||(distanceleft <= 15 && distancefront > 15 && distanceright > 15))
  {
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(0, HIGH);
    digitalWrite(13 ,LOW);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
    delay(100);
    a=0;
  }
  if ((s==LOW)&&(distanceleft > 15 && distancefront <= 15 && distanceright <= 15) ||(s==LOW)&& (distanceleft > 15 && distancefront > 15 && distanceright <= 15) ||(s==LOW)&& (distanceleft > 15 && distancefront <= 15 && distanceright > 15) )
  {
    digitalWrite(9, LOW);
    digitalWrite(10, HIGH);
    digitalWrite(11, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(0, HIGH);
    digitalWrite(13 ,LOW);
    digitalWrite(A0, LOW);
    digitalWrite(A1, HIGH);
  }
}
