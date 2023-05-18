float signal;
float referenceVoltage = 0;

void setup()
{
Serial.begin(115200);
}

void loop()
{
signal = analogRead(A2);
float convert2volt = (signal/1023)*5;

Serial.print("EMG:");
Serial.print(convert2volt);
Serial.print(",");
Serial.print("Ground:");
Serial.println(referenceVoltage);
delay(1);
}