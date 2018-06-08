#include <TinyGPS++.h>
#include <SoftwareSerial.h>

static const int RXPin = 4, TXPin = 3;
static const uint32_t GPSBaud = 9600;
const int sensorpin=0;
const int threshold=200;

// The TinyGPS++ object
TinyGPSPlus gps;

// The serial connection to the GPS device
SoftwareSerial ss(RXPin, TXPin);

void setup(){
  Serial.begin(9600);
  pinMode(sensorpin,INPUT);
  ss.begin(GPSBaud);
}

void loop(){
 
  // This sketch displays information every time a new sentence is correctly encoded.
  while (ss.available() > 0){
    gps.encode(ss.read());
    if (gps.location.isUpdated()){
      Serial.print("Latitude= "); 
      Serial.print(gps.location.lat(), 6);
      Serial.print(" Longitude= "); 
      Serial.println(gps.location.lng(), 6);
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
    }
  }
  
}
