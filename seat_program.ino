const int sensorpin=0;
const int threshold=200;
void setup() {
  Serial.begin(9600);
  pinMode(sensorpin,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  int val= analogRead(sensorpin);
if (val >= threshold)
{
  Serial.println("Seat is not vacant");
  Serial.println(val);
  delay(3000);
}
else
Serial.println("seat is vacant");
Serial.println(val);
delay(3000);
  // put your main code here, to run repeatedly:

}
