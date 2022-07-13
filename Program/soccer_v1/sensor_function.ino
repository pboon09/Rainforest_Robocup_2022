void ir() {
  InfraredResult InfraredBall = InfraredSeeker::ReadAC();
  Serial.print("DIR: ");
  Serial.print(InfraredBall.Direction);
  Serial.print("\t");
  Serial.print("SIR: ");
  Serial.println(InfraredBall.Strength);
}

void cp() {
  a = Compass.GetHeadingDegrees();
  Serial.print("Compass: ");
  Serial.print(a);
  Serial.println("\t");
}

void lg() {
  val1 = analogRead(A8);
  val2 = analogRead(A9);
  val3 = analogRead(A10);
  val4 = analogRead(A11);
  val5 = analogRead(A12);
  val6 = analogRead(A13);
  val7 = analogRead(A14);
  val8 = analogRead(A15);
  Serial.print(val1);
  Serial.print("\t");
  Serial.print(val2);
  Serial.print("\t");
  Serial.print(val3);
  Serial.print("\t");
  Serial.print(val4);
  Serial.print("\t");
  Serial.print(val5);
  Serial.print("\t");
  Serial.print(val6);
  Serial.print("\t");
  Serial.print(val7);
  Serial.print("\t");
  Serial.print(val8);
  Serial.println("\t");
}

void button() {
  Serial.print(digitalRead(red));
  Serial.print("\t");
  Serial.print(digitalRead(green));
  Serial.print("\t");
  Serial.print(digitalRead(blue));
  Serial.print("\t");
  Serial.println();
}

void ser() {
  ms.write(0);
  delay(1000);
  ms.write(180);
  delay(1000);
}

void motor() {
  motor1(255);
  delay(1000);
  ao();
  motor2(255);
  delay(1000);
  ao();
  motor3(255);
  delay(1000);
  ao();
  motor4(255);
  delay(1000);
  ao();
}
