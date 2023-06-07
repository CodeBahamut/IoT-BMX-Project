#include "DHTesp.h"

DHTesp dht;
const int RecordTime = 3; //Define Measuring Time (Seconds)
const int SensorPin = 3;  //Define Interrupt Pin (2 or 3 @ Arduino Uno)
const int DHTPin = 7;    //Define DHT Pin
int InterruptCounter;
float WindSpeed;

void measure() {
  InterruptCounter = 0;
  attachInterrupt(digitalPinToInterrupt(SensorPin), countup, RISING);
  delay(1000 * RecordTime);
  detachInterrupt(digitalPinToInterrupt(SensorPin));
  WindSpeed = (float)InterruptCounter / (float)RecordTime * 2.4;
}

void countup() {
  InterruptCounter++;
}

void wind_direction(){
    // read the input on analog pin 0:
    int sensorValue = analogRead(A0);
    float voltage = sensorValue*5/1023.0;
    int direction = map(sensorValue, 0, 1023, 0, 360);
    // print out the value you read:
    // Serial.print("ADC : ");
    // Serial.println(sensorValue);
    // Serial.print("Voltage : ");
    // Serial.println(voltage);
    Serial.print("Direction : ");
    Serial.print(direction);
    Serial.println("°");
}


void setup() {
    Serial.begin(9600);
    dht.setup(DHTPin, DHTesp::DHT22);
}

void loop() {
    wind_direction();
    delay(10);
    
    float h = dht.getHumidity();
    float t = dht.getTemperature();
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print("% - ");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println("*C");
    delay(10);


    measure();
    Serial.print("Wind Speed: ");
    Serial.print(WindSpeed);       //Speed in km/h
    Serial.print(" km/h - ");
    Serial.print(WindSpeed / 3.6); //Speed in m/s
    Serial.println(" m/s");
    delay(10);
    
    delay(3000);
}
