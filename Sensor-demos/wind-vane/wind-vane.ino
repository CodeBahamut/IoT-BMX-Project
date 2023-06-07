void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  float voltage = sensorValue*5/1023.0;
  int direction = map(sensorValue, 0, 1023, 0, 360);
  // print out the value you read:
  Serial.print("ADC : ");
  Serial.println(sensorValue);
  Serial.print("Voltage : ");
  Serial.println(voltage);
  Serial.print("Direction : ");
  Serial.println(direction);
  delay(300); 
}