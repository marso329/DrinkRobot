/*
Simple protocol for setting digital ports low and high and reading analog ports
 */
 //will only receive single bytes
int incomingByte = 0;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  //for testing
  pinMode(22, OUTPUT);
pinMode(23, OUTPUT);
pinMode(24, OUTPUT);
pinMode(25, OUTPUT);
pinMode(26, OUTPUT);
pinMode(27, OUTPUT);
pinMode(28, OUTPUT);
pinMode(29, OUTPUT);
pinMode(30, OUTPUT);
pinMode(31, OUTPUT);
pinMode(32, OUTPUT);
pinMode(33, OUTPUT);
digitalWrite(22, HIGH);
digitalWrite(23, HIGH);
digitalWrite(24, HIGH);
digitalWrite(25, HIGH);
digitalWrite(26, HIGH);
digitalWrite(27, HIGH);
digitalWrite(28, HIGH);
digitalWrite(29, HIGH);
digitalWrite(30, HIGH);
digitalWrite(31, HIGH);
digitalWrite(32, HIGH);
digitalWrite(33, HIGH);

//pwm
pinMode(2, OUTPUT); 
pwm25kHzBegin();
pwmDuty(39);

}

void pwm25kHzBegin() {
  TCCR2A = 0;                               // TC2 Control Register A
  TCCR2B = 0;                               // TC2 Control Register B
  TIMSK2 = 0;                               // TC2 Interrupt Mask Register
  TIFR2 = 0;                                // TC2 Interrupt Flag Register
  TCCR2A |= (1 << COM2B1) | (1 << WGM21) | (1 << WGM20);  // OC2B cleared/set on match when up/down counting, fast PWM
  TCCR2B |= (1 << WGM22) | (1 << CS21);     // prescaler 8
  OCR2A = 79;                               // TOP overflow value (Hz)
  OCR2B = 0;
}
void pwmDuty(byte ocrb) {
  OCR2B = ocrb;                             // PWM Width (duty)
}

// the loop routine runs over and over again forever:
void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    if(incomingByte>=97 && incomingByte<=108){
      digitalWrite((int) incomingByte-75, LOW);
    }
    if(incomingByte>=65 && incomingByte<=76){
      digitalWrite((int) incomingByte-43, HIGH);
    }
    if(incomingByte>=48&&incomingByte<=57){
      short unsigned sensorValue = (short unsigned)analogRead(A0+int(incomingByte-48));
      unsigned char bytes[2];
      bytes[1] = (sensorValue >> 8) & 0xFF;
      bytes[0] = sensorValue & 0xFF;
      Serial.write(bytes,2);
    }         
  }
}
